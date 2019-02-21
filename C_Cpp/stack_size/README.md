stack_size.exe tries to allocate 1GB of memory 

if command line arg is 1, it tries to allocate in stack. this is not going to happen.

if command line arg is 2. it tries to allocate in heap. this will work.

in cpp, every thread it creates is os threads which will get a fixed stack size of 1MB. 
if we try to allocate beyond that then it raises stack overflow exception and the application will crash.

this is why we will create object in 'heap' using 'new' operator.

one should not forget to free the memory allocated in 'heap' using 'delete' operator once it is not longer required to be used.
