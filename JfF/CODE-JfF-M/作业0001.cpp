//输入：数据数组、数组大小（根据题目知两个数组的大小是相同的）
//输出：中位数
//分析： 
//（1）每个数组都有一个开始和结束标志，通过比较两个输入数组的中位数的大小
//（2）决定是去掉右边的数据，还是去掉左边的数据
//（3）当确定好要去掉的数据之后，改变数组的开始、结束位置的下标。
//（4）改变方式就是将中位数的位置下标进行赋值，从而逐步缩小范围
//（5）当两个数组的开始不再小于结束下标时结束循环
// 
 
int GetMedian(int *leftArr, int *rightArr, int size)  
{  
	//异常检查 
    if (leftArr == NULL || rightArr == NULL || size <= 0)  
        return -1;  
    //初始化
	int leftArrBegin = 0;  
    int rightArrBegin = 0;  
    int leftArrEnd = size - 1;  
    int rightArrEnd = size - 1;  
    int pos; 
  	//首先取二者的中位数，在O(1)时间复杂度内求出，
	//则较小中位数的左边所有元素和较大中位数右边的所有元素全部去掉，
	//由于去掉的元素占所有元素的一半，所以复杂度为O(logn)。
    while (leftArrBegin < leftArrEnd && rightArrBegin < rightArrEnd)  
    { 
        if ((leftArrBegin == leftArrEnd - 1 && rightArrBegin == rightArrEnd - 1))  
            break;  
            
    	//求得两个数组的中间下标 
        int leftArrMid = (leftArrBegin + leftArrEnd) >> 1;  
        int rightArrMid = (rightArrBegin + rightArrEnd) >> 1;  
          
        if (leftArr[leftArrMid] == rightArr[rightArrMid])  
        {  
            pos = leftArr[leftArrMid];  
            break;  
        }  
        else if (leftArr[leftArrMid] < rightArr[rightArrMid])  
        {  
            leftArrBegin = leftArrMid;  
            rightArrEnd = rightArrMid;  
        } else  
        {  
            leftArrEnd = leftArrMid;  
            rightArrBegin = rightArrMid;  
        }  
    }  
  
    if (leftArrBegin == leftArrEnd && rightArrBegin == rightArrEnd)  
        pos = min(leftArr[leftArrBegin], rightArr[rightArrBegin]);  
    else if (leftArrBegin == leftArrEnd - 1 && rightArrBegin == rightArrEnd - 1)  
    {  
        if (leftArr[leftArrBegin] < rightArr[rightArrBegin])  
        {  
            pos = min(leftArr[leftArrEnd], rightArr[rightArrBegin]);  
        }  
        else  
        {  
            pos = min(leftArr[leftArrBegin], rightArr[rightArrEnd]);  
        }  
    }  
  
    return pos;  
}  

