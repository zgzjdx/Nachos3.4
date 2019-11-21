# Lab3: Programming with Threads

## 实现EventBarrier原语

使用Nachos同步原语, 以构建`EventBarrier`类, 使得允许一组线程等待并相应一个事件. 如果事件已由信号(signal)响应, 等待(wait)会立即返回. 与条件变量和信号量不同的是, 一个已由信号响应的(signaled)`EventBarrier`会继续保持信号响应状态(signaled state), 直到所有的线程都响应了该信号它才会转换为`unsignaled state`. 为确保所有线程都有机会相应信号, 我们需要创建一个`barrier`以阻塞那些正在发出信号(signaling)和正在相应(responding)的线程, 知道所有正在参与的线程都完成了对该事件的相应. 这使得`EventBarrier`在线程同步方面十分有力

以下是`EventBarrier`的接口说明

```
void Wait() -- Wait 直到事件 signaled. 如果已经在 signaled 状态, 这立即返回
void Signal() -- 对事件发出 Signal 并进入阻塞队列, 直到所有正等待该事件的线程都已响应(才解除阻塞). 当`Signal()`返回, EventBarrier需要重新恢复成初始态(unsignaled state)
void Complete() -- 表明调用线程已经完成对事件的相应, 并进行阻塞, 直到其他所有等待该事件的线程也都响应为止.
int Waiters() -- 返回正在等待事件, 或尚未对事件响应的线程数目.
```

## 实现闹钟原语

要求实现`AlarmClock`类. 线程调用`Alarm::Pause(int howLong)`会在一段时间后进入休眠. alarm clock使用计时器(Timer)进行模拟(timer.h). 当`Timer`中断关闭, `system.cc`中的`Timer`中断处理句柄必须唤醒*任何一个在暂停时间已经到了的`Alarm::Pause`中休眠的线程*. 这里并不要求被唤醒的线程在暂停时间到了之后立即运行起来, 只需要在它等待一段时间后(`howLong`), 将它放入准备队列(ready queue)即可. 我们还没有给`Alarm`创建头文件, 因此你可以根据你需要定义其他类成员. 
