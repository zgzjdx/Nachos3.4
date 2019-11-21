#include "synch-sem.h"


// implementation of BoundedBuffer with lock and condition variable
class BoundedBuffer {
   public:
     // create a bounded buffer with a limit of 'maxsize' bytes
     BoundedBuffer(int maxsize);
     
     // destory bounded buffer
     ~BoundedBuffer();

     // Thread which read 'size' bytes from the bounded buffer, storing into 'data'.
     // ('size' may be greater than 'maxsize')
     void Read(void *data, int size, int which);
     
     // Thread which write 'size' bytes from 'data' into the bounded buffer.
     // ('size' may be greater than 'maxsize')
     void Write(void *data, int size, int which);
   private:
     // pointer to bounded buffer
     void *buffer;

     // max size of bounded buffer
     int maxSize;

     // buffer pointers
     int nextin, nextout;

     // current size of bounded buffer
     int count;

     // condition variables for synchronization
     Condition *notfull, *notempty;

     // condition lock
     Lock *lock;
};


// implementation of BoundedBuffer with semaphore
class semBoundedBuffer {
	public:
	  // create a bounded buffer with a limit of 'maxsize' bytes
      semBoundedBuffer(int maxsize);
     
      // destory bounded buffer
      ~semBoundedBuffer();

      // Thread which read 'size' bytes from the bounded buffer, storing into 'data'.
      // ('size' may be greater than 'maxsize')
      void semRead(void *data, int size, int which);
     
      // Thread which write 'size' bytes from 'data' into the bounded buffer.
      // ('size' may be greater than 'maxsize')
      void semWrite(void *data, int size, int which);
    private:
      // pointer to bounded buffer
      void *sembuffer;

      //max size of bounded buffer
      int semmaxSize;

      // buffer pointers
      int semnextin, semnextout;

      Semaphore *n, *e;

      Lock *s;
};
