#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>



#define NUM_OF_THREADS 10



/* function prototype */
void *print_hello_world(void *tid);



void *print_hello_world(void *tid) {
	/* this function prints the thread's identifier and then exits. */
	printf("HEllo World. Greetings from thread %d0\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	/* The main program creates 10 threads and then exits. */
	pthread_t threads[NUM_OF_THREADS];
	int status, i;

	for(i = 0; i < NUM_OF_THREADS; i++) {
		printf("Main here. Creating thread %d0\n", i);
		status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
		
		if (status != 0) {
			printf("Oops. pthread_create returned error code %d0\n", status);
			exit(-1);
		}
	}
	
	exit(0);
}
