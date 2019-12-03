/* test for exec syscall
    the system calls are defined in processmanager.h instead of syscall.h
*/

#include "syscall.h"

#define M 5 
#define N 2

int 
main()
{   
    int i, j, k, tmp;

    for (i = 0; i < M; i++) {
        for (k = 0; k < N*i; k++){
	    tmp = Exec("../test/run");
	    //for (j = 0; j < N; j++)
                Join(tmp);
        }
    }

    return 0;
}


