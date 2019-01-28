Logger library is a 64 bit library which can be linked with any application (windows as of 28 jan 2019).
It provides a 'Logger' class whose instance can be created by providing 'module'/'function' name as input.

"logger.h" has a macro => LOGGING_INTERVAL which determines the logging interval
Logging interval is the time interval between two successive write operations (fprintf)
The log file will be reopened when the object of logger is destroyed if the process is still on.

LoggerTest.exe is a sample app which uses this library. It shows how to use this library.
Take a look into \LoggerTestExe\src\main.cpp which tells the usage of this library.

Debug build has a problem as of 26 Jan 2019. Need to fix it. 
