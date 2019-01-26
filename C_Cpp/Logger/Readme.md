This is a c++ library. 
The aim is to implement a logging mechanism.


Logger library can be linked with any application.
It provides a 'Logger' class whose instance can be created by providing 'module'/'function' name as input.

"logger.h" has a macro => LOGGING_INTERVAL which determines the logging interval
Logging interval is the time interval between two successive write operations (fprintf)
The log file will be reopened when the object of logger is destroyed if the process is still on
