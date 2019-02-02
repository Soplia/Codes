//���룺�����Լ������С
//���������
//������ 
//��1��sum���ڼ�¼����һ������Ԫ��֮��ĺ�
//��2��result���ڼ�¼��ǰ������Ԫ�صĺ� 
//��3������ȡ���ֵ 
int SubArrMaxSum(const int* arr, int size)  
{  
    if (!arr || (size <= 0))  
        return 0;  
  
    int sum = arr[0];  
    int result = sum;  
    
    for (int i = 1; i < size; i++)  
    {  
        if (sum > 0)  
            sum += arr[i];  
        else  
            sum = arr[i]; 
            
        result = max(sum, result);  
    }  
    
    return result;  
}  

