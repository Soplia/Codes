// DLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "DLL.h"


// ���ǵ���������һ��ʾ��
DLL_API int nDLL=0;

// ���ǵ���������һ��ʾ����
DLL_API int fnDLL(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� DLL.h
CDLL::CDLL()
{
	return;
}
