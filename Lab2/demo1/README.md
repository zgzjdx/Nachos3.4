# 3.2 Lab 2: Threads and Synchronization

在本节实验中, 你将通过添加锁(互斥锁), 条件变量以完善`Nachos`线程系统, 并为之后的实验创建一些同步数据结构. 当然本实验还是有额外的任务, 你可以修改`Nachos`的默认调度行为以实现一个非抢占式的优先调度程序.

与`lab1`相同, 这次实验也要求你引入一个或多个你自己的文件进工程里. 和之前一样, 你需要将这些文件添加到`makefile`宏定义中的合适位置并更新`makefile`的依赖项. 要注意, 本实验的后半部分要求你使用前半部分实现的同步功能. 因此请在你执行实验的后半部分前, 确保你的互斥锁和条件变量都已正确实现. 


你的新`class`文件需要基于课程目录(aux子目录)/课程网站提供的头文件进行编写. 这些头文件包含有类的初始化定义以及一些方法的声明. 你应该将这些头文件引入到你的源文件中并扩写那些未实现的方法. 你可以根据自己需要随意添加`方法/定义/类`, 但请不要修改已经定义好的接口. 


## 3.2.1 实现互斥锁和条件变量 (60 分)

互斥锁和条件变量的公共接口有在`synch.h`中定义, 该头文件含有对原语的重要语义注释. 条件变量接口在某些方面会显得笨拙, 但还是请按照`synch.h`了的定义实现它. 你的第一个任务就是在`synch.h`中为这些类定义私有数据, 并在`synch.cc`中实现相关接口. 你可以查看`SynchList`中示例的互斥锁和条件变量的同步原语是如何使用的. 你需要编写两个版本的`synch.h`和`synch.cc`文件, 两个版本各实现不同的同步原语. 你应该设置开关能从一个版本切换到另一个版本, 当然最差的情况就是直接将这些文件移动到`Nachos`内重新编译. 本实验中两个版本的同步原语实现均占30分.

这里有详细的具体步骤和要求:

1. [X] 使用原语`sleep/wakeup`(`Thread::Sleep`和`Scheduler::ReadyToRun`原语)来实现lock锁和条件变量. 有必要在关键点暂时禁用中断, 以避免发生`不合时的中断`和`非自愿上下文切换`. 需要特别指出, `Thread::Sleep`要求你在调用之前禁用中断, 然而, 如果你在不必要的情况下还在保持中断禁用, 你就会失分. 中断禁用十分危险, 除非必要, 否则不要使用

2. [X] 只使用`semaphores`这一个同步原语来实现你的lock锁和条件变量. 这次无需在代码中禁用中断: `semaphores`原语根据需要禁用中断, 以实现`semaphore`的抽象方法, 你完全可以使用该方法来完成同步操作. 
    
    警告: 这部分任务虽然看起来很轻松, 但它实际上是最微妙也是最困难的. 特别是你在实现条件变量时, 应保证一个信号不会影响后续的等待.
3. [X] 修改`lab1`中你实现的`DLList`类, 以便它使用同步原语来确保`DLList`在被多线程使用使用时也能始终如一地进行更新. 你可能需要去查看`SynchList`类(在`threads/synchlist.h`和`threads/synchlist.cc`里), 以了解如何完成该操作. 为了演示你代码的运行效果, 如`lab1`那样, 请创建一个类似于`threadtest.cc`的驱动文件, 在该驱动文件里调用同步版本的`DLList`类. 修改`threads/main.cc`, 以便使用`nachos`命令来执行驱动文件在的程序, 而非原来的`threadtest.cc`里的`ThreadTest`函数. 然后使用同步版本的`DLList`来测试你两个版本的lock锁和条件变量的代码实现. 

## 3.2.2 实现一个多线程表 (20 分)

实现一个线程安全的`Table`类, 该类存储一个由整型范围[0..size-1]索引的无类型对象指针. 在稍后的实验中你可能需要使用`Table`来实现`进程`, `线程`, `内存页帧`, `打开文件`等的内部操作系统表. 

`Table`有以下方法, 在课程目录(`aux`子目录)提供的头文件`Table.h`中有相关定义.

``` c++
Table(int size) -- Create a table to hold at most size entries.
int Alloc (void* object) -- Allocate a table slot for object, returning index of the allocated entry.
Return an error (-1) if no free table slots are available.
void* Get (int index) -- Retrieve the object from table slot at index, or NULL if not allocated.
void Release (int index) -- Free the table slot at index.
```

## 3.2.3 实现一个有界缓冲区 (20 分)

我们将解决一个经典同步问题叫做`有界 生产者/消费者`问题. 请基于`*/aux/BoundedBuffer.h`中的定义, 实现一个线程安全的`BoundedBuffer`类. 

``` c++
BoundedBuffer(int maxsize) -- Create a bounded buffer to hold at most maxsize bytes.
void Read (void* data, int size) -- Read size bytes from the buffer, blocking until enough bytes are
available to completely satisfy the request. Copy the bytes into memory starting at address data
void Write (void* data, int size) -- Write size bytes into the buffer, blocking until enough space is
available to completely satisfy the request. Copy the bytes from memory starting at address data .
```

在`lab5`实现管道的时候会再次用到`BoundedBffer`, 管道是Unix系统基本的进程间通信(IPC)机制. 我们解决`生产者/消费者`问题的基本思路是: 使用管道或`BoundedBuffer`将数据从生产者线程(调用`Write`)传递给消费者线程(调用`Read`). 消费者使用`Read`来接收放置在缓冲区中的字节, 顺序跟生产者`Write`的字节顺序相同. 如果生产者产出的数据速度太快(即缓冲区溢出最大字节), 那么`Write`会使生产者进入休眠状态, 直到消费者能够赶上并从缓冲区中读取一些数据, 释放出空间. 如果是消费者读取数据的速度太快(即缓冲区已经空了), 那么`Read`就会使消费者进入休眠状态, 知道生产者赶上并产出更多的字节. 

需要注意的是, 我们没有限制哪些线程调用`Read`哪些调用`Write`. 你在代码实现时不应该假设只有两个线程, 或是调用的线程固定地扮演生产者和消费者. 

如果一个给定的`BoundedBuffer`被多个线程使用, 那么你应该注意保留读写请求的原子性. 也就是说, 由`Write`写入的数据传送给的`reader`, 不应该再跟其他`Write`操作数据有交错. 即使`writer`和/或`reader`因为缓冲区填满/情况而被强制停止, 这个不变量依旧要保持不变. (// Note: 这里的"不变量"指代不是很清楚, 我的理解是`Write`写入的数据)


## 3.2.4 (额外任务) 实现一个优先调度器 (20 分)

跟踪调试`threads/thread.cc`, `threads/scheduler.h`和`threads/scheduler.cc`, 以了解`nachos`默认调度器是如何选择下一个要运行的线程(当一个线程让步CPU, 或是当时间片完成时). 为了实现一个非抢占式的优先调度器, 你需要修改原有的线程调度器, 使得始终返回最高优先级的线程. 你可以创建`scheduler.h`和`scheduler.cc`的副本并在副本中进行修改. 你还需要为`Thread`创建一个新的构造函数. 以获取新参数 - 线程优先级. 请保留旧的构造函数, 因为你需要它来保证向后兼容. 你可以假设有一定数量的优先级 - 不过在本实验中你只需要2个就行. 

你可以通过使用你的调度器来运行你的有界缓冲区, 以测试你的调度器是否被正确实现. 改变生产者线程和消费者线程的相对优先级会对输出有什么影响呢? 例如, 两个生产者和一个消费者, 其中一个生产者比另一个生产者有更高的优先级, 会发生什么呢? 如果两个生产者的优先级相同, 但是消费者有更高的优先级, 又会造成怎样的影响? 要想使得产生你想要的行为, 请确保你在生产者和消费者代码(仅仅是用于实验的这一部分)中调用`Thread::Yield`. 

## 3.2.5 关于lab2的注意事项

你在实现lock锁和条件变量时, 应使用2.2节(请参考`Tracing and Debugging Nachos Programs`节)中所述的`ASSERT`断言来检查强制产生正确行为所需的使用约束. 例如, 每个对`Signal`和`Wait`的调用都会传递一个关联的互斥锁, 如果给定的变量和多个互斥锁一起使用, 会出现什么问题? 如果锁的持有线程试图再次获得已经持有的锁, 又会出现什么问题? 如果一个线程试图释放它根本不具有的锁, 又该怎么办? 这些`ASSERT`断言是值得的, 它们会在以后的实验中为你节省麻烦. 

你还需要考虑其他使用问题. 例如, 如果调用者试图在线程阻塞的情况下删除互斥锁或条件变量对象, 你的代码要如何解决该问题.

你要能解释清楚为什么你的实现是正确的(例如, 我们的X线让步于Y线), 并在各种使用场景下评价它的行为(公平, 饿死).

警告: `Nachos`条件变量接口十分笨拙, 因为它在每次调用`Wait`和`Signal`时传递关联的互斥量, 而不是在条件变量构造时就绑定互斥量. 这意味着你必须添加相关代码才能在第一次调用`Wait`或`Signal`时记住互斥锁, 这样你才能在后续调用中验证正确的用法. 但请不要误解: 就如`synch.h`里所述的那样, 每个条件变量只能与一个互斥锁一起使用. 请务必明白为什么这是如此重要. 

警告: `semaphores`的定义不能确保在`V`中唤醒的线程会有机会在另一个线程调用`P`之前运行. 特别是, `Nachos`原本对`semaphores`就不能保证这种行为. 也就是说, 如果计数值从`0`变为`1`, `V`会增加计数并唤醒被阻塞的线程. 但是被唤醒的线程有责任在唤醒`P`之后再次减少计数. 如果另一个线程先调用`P`, 那么它可能会消耗"原本为被唤醒线程所准备"的计数值, 这将导致被唤醒的线程再次回到睡眠状态并等待另一个`V`

注意: 为方便调试, 你可以使用`-s`调试标志. 但是, 在目前的`DEBUG`语句中是没有`s`调试标志的. 因此你需要在代码中添加一些语句. 请参见2.2节(请参见`Tracing and Debugging Nachos Programs`节)


## 3.2.6 建议步骤

1. [X] 思考锁`Lock`的类定义里应该包含哪些成员变量(可参考已在`synch.cc`提供的`Semaphore`的类定义);
2. [X] 实现简单的`Lock::isHeldByCurrentThread`函数(提示:在`Lock`的定义中添加适当的成员变量,则函数体内一个语句足矣);
3. [X] 思考上锁的步骤并实现`Lock::Acquire`函数(某些步骤可参考`Semaphore::P`函数的实现);
4. [X] 思考开锁的步骤并实现`Lock::Release`函数。
5. [X] 测试该锁是否正确实现

1. [X] 以"sleep+中断禁止与启用"实现条件变量并用实验一实现的双向链表测试其是否正确实现; 
2. [X] 以"Semaphore"实现锁和条件变量并用实验一实现的双向链表测试其是否正确实现;
3. [X] 选用一种同步机制实现一个线程安全的表结构, 并设计程序测试验证;
4. [X] 选用一种同步机制实现一个大小受限的缓冲区, 并设计程序测试验证; 