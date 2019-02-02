//输入：数组以及数组大小
//输出：最大和
//分析： 
//（1）sum用于记录经过一个数组元素之后的和
//（2）result用于记录先前的数组元素的和 
//（3）两者取最大值 
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

