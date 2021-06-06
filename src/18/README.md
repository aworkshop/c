## 18/thread.c

This source is discussed in fragments.

```
#include<pthread.h>
```

This header file declares the thread functions. 
On some systems, compile this with `-lpthreads` (not on osx), 
to *link* it with pthreads.

```
void *thread(void *ptr) {
    int *i = (int*)ptr;
```

This function has a specific signature, so it can be run as
a separate thread. It accepts and returns a void pointer.
The `void *` arg is first cast to the proper type, `int *`.

```
    fprintf(stderr,"Thread - %d\n", *i);
    *i += 41;
    return NULL;
}
```

The value at i is printed and then 41 is added to the value at i.
And `NULL` is a predefined null pointer.


```
int main(void) {
    pthread_t thread1, thread2;
    int a = 1;
    int b = 2;
```
Two pthread_t types are used, this is used to store
information about both threads.

```
    pthread_create(&thread1, NULL, *thread, (void *) &a);
    pthread_create(&thread2, NULL, *thread, (void *) &b);
```
Both threads are created, params;
- address of the pthread_t structure
- NULL = null pointer since arg is not used
- the function to be run in the thread
- void pointer to the address of the data to pass to the function

https://man7.org/linux/man-pages/man3/pthread_create.3.html


```
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
```
Before `main()` continues, join (=wait for the thread to finish).
Otherwise the `main()` could even finish before the sub thread 
is finished.


```
    fprintf(stderr,"Result a - %d\n",a);
    fprintf(stderr,"Result b - %d\n",b);
    return 0;
}
```
Because we waited for the threads, now the a and b values
are as we can expect. 

## link pthreads

On OSX this library does not have to be linked.
```
$ gcc thread.c -lpthreads -o thread
ld: library not found for -lpthreads
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```