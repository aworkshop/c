#include<pthread.h>
#include<stdio.h>

void *thread(void *ptr) {
    int *i = (int*)ptr;
    // cast to proper type
    fprintf(stderr,"Thread - %d\n", *i);
    *i += 41;
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    int a = 1;
    int b = 2;

    pthread_create(&thread1, NULL, *thread, (void *) &a);
    pthread_create(&thread2, NULL, *thread, (void *) &b);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    fprintf(stderr,"Result a - %d\n",a);
    fprintf(stderr,"Result b - %d\n",b);
    return 0;
}
