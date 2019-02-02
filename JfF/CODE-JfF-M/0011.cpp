#include <iostream> 
#include <windows.h>  
using namespace std;  
  

void StartProgress()  
{  
    string csCommandLine;  
    char chWindowsDir[MAX_PATH];  
    string chCommandLine;  
    DWORD dwExitCode;  
    PROCESS_INFORMATION pi;  
  
    STARTUPINFO     si;//用于指定新进程的主窗口特性的一个结构  
    memset(&si, 0, sizeof(si));  
    si.cb = sizeof(STARTUPINFO);  
    si.dwFlags = STARTF_USESHOWWINDOW;  
    si.wShowWindow = SW_SHOW;//SW_HIDE隐藏窗口  
  
    //得到windows目录  
    GetWindowsDirectory(chWindowsDir, MAX_PATH);  
  
    //启动“记事本”程序的命令行  
    csCommandLine = string(chWindowsDir) + "\\NotePad.exe";  
    ::strcpy(chCommandLine, csCommandLine);  
  
    //启动“记事本”作为子进程  
    BOOL ret = CreateProcess(NULL, chCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);  
    if (ret)  
    {  
        //关闭子进程的主线程句柄  
        CloseHandle(pi.hThread);  
  
        //等待子进程的退出  
        WaitForSingleObject(pi.hProcess, INFINITE);  
  
        //获取子进程的退出码  
        GetExitCodeProcess(pi.hProcess, &dwExitCode);  
  
        //关闭子进程句柄  
        CloseHandle(pi.hProcess);  
  
    }  
  
  
}  


int main(int argc, char* argv[])  
{  
	StartProgress() ;
	return 0;
}



















