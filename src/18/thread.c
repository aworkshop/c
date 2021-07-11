#include<pthread.h>
#include<stdio.h>

// usage: thread(int*)
void *thread(void *ptr) {
    int *i = (int*)ptr;
    // cast to proper type
    fprintf(stderr,"Thread - %d\n", *i);
    *i += 41; // change the value
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    int a = 1;
    int b = 2;

    // splits off and start threads
    pthread_create(&thread1, NULL, *thread, (void *) &a);
    pthread_create(&thread2, NULL, *thread, (void *) &b);

    // main and thread1 and thread2 are now running
    // ...

    // joins the treads together back to main
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // in this case, variables are changed within the thread
    fprintf(stderr, "Result a - %d\n", a);
    fprintf(stderr, "Result b - %d\n", b);
    return 0;
}
