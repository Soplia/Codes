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
  
    STARTUPINFO     si;//����ָ���½��̵����������Ե�һ���ṹ  
    memset(&si, 0, sizeof(si));  
    si.cb = sizeof(STARTUPINFO);  
    si.dwFlags = STARTF_USESHOWWINDOW;  
    si.wShowWindow = SW_SHOW;//SW_HIDE���ش���  
  
    //�õ�windowsĿ¼  
    GetWindowsDirectory(chWindowsDir, MAX_PATH);  
  
    //���������±��������������  
    csCommandLine = string(chWindowsDir) + "\\NotePad.exe";  
    ::strcpy(chCommandLine, csCommandLine);  
  
    //���������±�����Ϊ�ӽ���  
    BOOL ret = CreateProcess(NULL, chCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);  
    if (ret)  
    {  
        //�ر��ӽ��̵����߳̾��  
        CloseHandle(pi.hThread);  
  
        //�ȴ��ӽ��̵��˳�  
        WaitForSingleObject(pi.hProcess, INFINITE);  
  
        //��ȡ�ӽ��̵��˳���  
        GetExitCodeProcess(pi.hProcess, &dwExitCode);  
  
        //�ر��ӽ��̾��  
        CloseHandle(pi.hProcess);  
  
    }  
  
  
}  


int main(int argc, char* argv[])  
{  
	StartProgress() ;
	return 0;
}



















