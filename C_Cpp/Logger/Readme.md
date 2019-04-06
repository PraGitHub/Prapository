Logger library is a 64 bit library which can be linked with any application (only for windows as of commit date of this file).
It provides a 'Logger' class whose instance can be created by providing 'module'/'function' name as input.
An application can create any number of instances of "Logger" class. 

"logger.h" has a macro => LOGGING_INTERVAL which determines the logging interval.
Logging interval is the time interval between two successive flushes.
This can be controlled by passing required logging interval value while creating the first instance of "Logger" class.

There are various logging levels.
      Critical, 
      Error, 
      Info, 
      Debug, and 
      Verbose

Whenever an object of "Logger" is created, required logging level has to be passed. By default, it will be set to Info i.e., all log statements with labels "Critical", "Error" and "Info" will be logged and "Debug" and "Verbose" will be ignored.
Let's take another example. If the logging level is set to "Debug" then only log statements with "Verbose" is ignored and log statements with rest of the labels will be logged.
If an application wants to set a specific value for logging level then it has to make sure that it is passed when the first instance of "Logger" class is created.

The log file will be reopened when the object of logger is destroyed if the process is still on.

LoggerTest.exe is a sample app which uses this library. It shows how to use this library.
Take a look into \LoggerTestExe\src\main.cpp which shows the usage of this library.

Debug build has a problem as of 26 Jan 2019. Need to fix it. 
