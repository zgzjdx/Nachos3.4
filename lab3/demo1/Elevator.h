
#include "EventBarrier.h"
#include "system.h"
#include <assert.h>
#include <math.h>

#ifndef ELEVATOR_H
#define EVEVATOR_H

// 到每一层需要花费的滴答时间
#define _TICKPERFLOOR 100

class Building;

class Elevator {
   public:
     Elevator(char *debugName, int numFloors, int myID);
     ~Elevator();
     char *getName() { return name; }
   
     // 电梯控制接口: 由控制电梯的线程调用
     void OpenDoors();                //   开启电梯门, 离开者先出电梯, 而后在本层且运行方向跟电梯一致的乘客进入电梯
     void CloseDoors();               //   在 离开者离开电梯 且 进入者进入电梯 后关闭电梯门
     void VisitFloor(int floor);      //   电梯前往指定楼层
   
     // 电梯乘客接口(part 1): 由乘客线程调用
     bool Enter();                    //   进入电梯
     void Exit();                     //   离开电梯(如果已经到达目的楼层)
     void RequestFloor(int floor);    //   请求电梯前往指定楼层
     
   
     // insert your methods here, if needed
     int  getCurrentFloor() { return currentfloor; }
     int  getOccupancy() { return occupancy; }
     int  getDirection() { return direction; }
     void changeDirection() { direction = 1 - direction; }
     void setBuilding(Building *building) { b = building; }
     bool *isRequestFloor; // 乘客请求到达的楼层数组
                           // 比如 isRequestFloor[8] = True 
                           // 表示第8层是用户请求前往的楼层

   private:
     char *name;
   
     int currentfloor;           // 当前停靠的楼层
     int occupancy;              // 当前搭载的乘客数量
   
     // insert your data structures here, if needed
     int capacity;              // 电梯容量
     int numFloors;             // 电梯可到达的最高层
     int id;                    // 电梯号
     int isFree;                // 电梯是否空闲, 空闲则为1, 忙碌则为0
     int direction;             // 电梯此时的上下方向, 上行为1, 下行为0
    //  int closeDoorNum;
     Lock *elevator_lock;
     Condition *closeDoor_cond; // 关门条件变量
     EventBarrier *arrived_floor; // 电梯到达指定楼层, 触发事件
                                  // 比如 arrived_floor[9].signal()
                                  // 表示 电梯到达第9层, 发出信号
     Building *b;               // 指定电梯所在的大楼
};

class Floor{
public:
    EventBarrier *e;
    Floor()  { e = new EventBarrier[2]; } // 每一层都有一个上行/下行事件栅栏
                                          // 等待电梯到达
    ~Floor() { delete[] e; }
};
   
class Building {
   public:
     Building(char *debugname, int numFloors, int numElevators);
     ~Building();
     char *getName() { return name; }
   
     // 电梯乘客接口(part 2): 由乘客线程调用
     void CallUp(int fromFloor);      // 在某层按上行按钮
     void CallDown(int fromFloor);    // 在某层按下行按钮
     Elevator *AwaitUp(int fromFloor); // 在某层等待上行电梯
     Elevator *AwaitDown(int fromFloor); // 在某层等待下行电梯
   
     Floor *getFloors() { return floors; }
     bool *getRiderRequestUp() { return isRiderRequestUp; }
     bool *getRiderRequestDown() { return isRiderRequestDown; }
     Lock *getLock() { return building_lock; }

   private:
     char *name;
     Elevator *elevator;         // 建筑物里的各个电梯(数组)y)
   
     // insert your data structures here, if needed
    int floorNum;       // 大楼的总楼层数
    Floor *floors;      // 大楼的各个楼层(总数为floorNum)
    bool *isRiderRequestUp; // 表示某层的乘客是否请求上行
                            // 比如 isRiderRequestUp[5]
                            // 表示第5层乘客正请求上行
    bool *isRiderRequestDown; // 表示某层的乘客是否请求下行
                              // 比如 isRiderRequestUp[4]
                              // 表示第4层乘客正请求下行
    Lock  *building_lock;
};

   // here's a sample portion of a rider thread body showing how we
   // expect things to be called.
   //
   // void rider(int id, int srcFloor, int dstFloor) {
   //    Elevator *e;
   //  
   //    if (srcFloor == dstFloor)
   //       return;
   //  
   //    DEBUG('t',"Rider %d travelling from %d to %d\n",id,srcFloor,dstFloor);
   //    do {
   //       if (srcFloor < dstFloor) {
   //          DEBUG('t', "Rider %d CallUp(%d)\n", id, srcFloor);
   //          building->CallUp(srcFloor);
   //          DEBUG('t', "Rider %d AwaitUp(%d)\n", id, srcFloor);
   //          e = building->AwaitUp(srcFloor);
   //       } else {
   //          DEBUG('t', "Rider %d CallDown(%d)\n", id, srcFloor);
   //          building->CallDown(srcFloor);
   //          DEBUG('t', "Rider %d AwaitDown(%d)\n", id, srcFloor);
   //          e = building->AwaitDown(srcFloor);
   //       }
   //       DEBUG('t', "Rider %d Enter()\n", id);
   //    } while (!e->Enter()); // elevator might be full!
   //  
   //    DEBUG('t', "Rider %d RequestFloor(%d)\n", id, dstFloor);
   //    e->RequestFloor(dstFloor); // doesn't return until arrival
   //    DEBUG('t', "Rider %d Exit()\n", id);
   //    e->Exit();
   //    DEBUG('t', "Rider %d finished\n", id);
   // }


#endif