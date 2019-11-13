#include "synch.h"

#ifndef BOUNDED_BUFFER_H
#define BOUNDED_BUFFER_H
class BoundedBuffer {
   public:
     // create a bounded buffer with a limit of 'maxsize' bytes
     BoundedBuffer(int maxsize);
     ~BoundedBuffer();
     // read 'size' bytes from the bounded buffer, storing into 'data'.
     // ('size' may be greater than 'maxsize')
     void Read(void *data, int size);
     
     // write 'size' bytes from 'data' into the bounded buffer.
     // ('size' may be greater than 'maxsize')
     void Write(void *data, int size);
   private:
    Lock * monitor_lock; 
    Condition *not_full;
    Condition *not_empty; 
    int readFrom;
    int writeTo;
    int hasCount;
    int maxSize;
    int* buffer;
};

#endif // BOUNDED_BUFFER_H
