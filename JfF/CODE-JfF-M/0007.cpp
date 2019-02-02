//���룺�����Լ������С
//����������� 
//������
//��1������һ������Ϊn������A[0...n-1],���ǿ��Խ�����Ϊ��������Ϊn/2������L[0...n1]=A[0...n/2]��R[0...n2]=A[n/2+1...n-1]
//��2���ܵ������=L�е������+R�е������+L��R�������
//��3����L�ź��򣬽�RҲ�ź�����ʱ��L��R�ǲ��ֵ�����Ը�������ı䣬������ΪL��R�Ƿֿ���
int Divide(int*ARR, int n)
{ 
	return Merge(ARR, 0, n - 1);
}
int Merge (int *ARR, int p, int r)
{
    if (p>=r)
         return 0;
    int i, j, k,mid,n1,n2, reversArrtions = 0;
    mid = (p + r) >> 1;
    int count= Merge (ARR, p, mid) + Merge (ARR, mid + 1, r);
    n1 = mid - p + 1;
    n2 = r - mid;
    int *Right = new int[n2 + 1];
    int *Left = new int[n1 + 1];
    for (i = 0; i < n1; i++)
         Left[i] = ARR[i + p];
    for (j = 0; j < n2; j++)
         Right[j] = ARR[j + mid + 1];
    Left[n1] = Right[n2] = MAX_VALUE; //����Ϊ���ֵ�������ڱ�
    i = j = 0;
    for (k = p; k <= r; k++)
	{
        if (Left[i]>Right[j])
		{
            reversArrtions +=n1-i;
            ARR[k] = Right[j++];
     	}
	    else
	        ARR[k] = Left[i++];
	}
    delete[]Right, Left;
    return reversArrtions + count;
}

