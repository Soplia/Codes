#include <stdio.h>
#include <windows.h>

DWORD WINAPI ThreadHelloWorld(LPVOID arg)
{
		printf("Hello World\n");
		return 0;
}

int main()
{
	HANDLE hThread = CreateThread(NULL,0,ThreadHelloWorld,NULL,0,NULL);
	WaitForSingleObject(hThread,5000);
	return 0;
}


