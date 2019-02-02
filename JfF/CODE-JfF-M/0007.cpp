//输入：数组以及数组大小
//输出：逆序数 
//分析：
//（1）对于一个长度为n的数组A[0...n-1],我们可以将它分为两个长度为n/2子数组L[0...n1]=A[0...n/2]和R[0...n2]=A[n/2+1...n-1]
//（2）总的逆序对=L中的逆序对+R中的逆序对+L和R的逆序对
//（3）将L排好序，将R也排好序，这时候L和R那部分的逆序对个数不会改变，这是因为L与R是分开的
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
    Left[n1] = Right[n2] = MAX_VALUE; //设置为最大值，当做哨兵
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

