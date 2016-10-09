// use set tabstop=2
// demo collision using global variable .. pthread_mutex_lock()

// http://www.sbin.org/doc/glibc/libc_34.html

#define NUMTHREADS 5
#define ITERS 3
#define TRIES 2

#define THREAD "Thread #"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <malloc.h>

void *fn();
int  counter = 0;

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;

int main()
{
	int i=0;
	char *str[NUMTHREADS];
  int retval[NUMTHREADS];
	
  pthread_t t[NUMTHREADS];

	while	(i<NUMTHREADS) {
	 str[i]=malloc(50); 
	 sprintf(str[i],"%s%d",THREAD,i);
   if( (retval[i]=pthread_create( &t[i], NULL, &fn, str[i])) ) 
      printf("Thread creation failed: %d\n", retval[i]);

	 i+=1;
	}
	
	i=0;
	while	(i<NUMTHREADS) {
   pthread_join(t[i],NULL);
	 free(str[i]);

	 i+=1;
	}

	// destroys a mutex object, freeing the resources it might hold.
	pthread_mutex_destroy(&m1); // needed in some implementations

  exit(0);
}

void *fn(void *str)
{
	int i=0;

  printf("%s:Inside fn(): Thread '%d' Counter value: %d.\n",
			str, pthread_self(),counter);

	while (i++<ITERS) {
		
	 	sleep(i*i);			// sleep some arbitrary time to induce collisions
		
   	printf("%s:'%d' Trying to Acquire Mutex:Thread '%d':Counter value: %d.\n",
			str,i,pthread_self(),counter);

   	pthread_mutex_lock(&m1);

		// begin CS
   	counter++;
  	printf("%s: .. Acquired Mutex in fn().\n",str);
	 	sleep(i);			// sleep some additional arbitrary time to induce collisions
		// end CS
	
   	pthread_mutex_unlock(&m1);
  	printf("%s: .. Released Mutex in fn().\n",str);
	}

  printf("%s: .. done with fn().\n",str);
	return 0;
}
