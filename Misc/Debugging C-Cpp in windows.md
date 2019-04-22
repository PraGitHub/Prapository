Windbg related:

    *http://www.debuginfo.com/articles/easywindbg.html



Deadlock detection :

    *https://confluence.efi.com/display/FX/DeadLock+Detection*
    https://stackoverflow.com/questions/26573238/windbg-how-to-read-the-locks-output
    http://www.dbgtech.net/windbghelp/hh/debugger/t13_advanced_cc933b2b-4388-4b51-9950-d62953991b10.xml.htm



Useful commands (WinDbg related):


.sympath c:\MyRegularSymbols;srv*c:\MyServerSymbols*https://msdl.microsoft.com/download/symbols

.reload

~* kp   //show all threads

lm   // all the loaded dlls

.symfix

.symopt+ 0x40

dv  // to see the value of all local variable.

ld modulename //to see if dll loaded


kPn  //to see call stack.

!runaway //lists all threads with IDs

!locks //locked critical sections


!locks -v -f // all critical sections


Hang analysis : !analyze -hang -v

Exception analysis : !analyze -v -f








