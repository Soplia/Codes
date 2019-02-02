//���룺�������顢�����С��������Ŀ֪��������Ĵ�С����ͬ�ģ�
//�������λ��
//������ 
//��1��ÿ�����鶼��һ����ʼ�ͽ�����־��ͨ���Ƚ����������������λ���Ĵ�С
//��2��������ȥ���ұߵ����ݣ�����ȥ����ߵ�����
//��3����ȷ����Ҫȥ��������֮�󣬸ı�����Ŀ�ʼ������λ�õ��±ꡣ
//��4���ı䷽ʽ���ǽ���λ����λ���±���и�ֵ���Ӷ�����С��Χ
//��5������������Ŀ�ʼ����С�ڽ����±�ʱ����ѭ��
// 
 
int GetMedian(int *leftArr, int *rightArr, int size)  
{  
	//�쳣��� 
    if (leftArr == NULL || rightArr == NULL || size <= 0)  
        return -1;  
    //��ʼ��
	int leftArrBegin = 0;  
    int rightArrBegin = 0;  
    int leftArrEnd = size - 1;  
    int rightArrEnd = size - 1;  
    int pos; 
  	//����ȡ���ߵ���λ������O(1)ʱ�临�Ӷ��������
	//���С��λ�����������Ԫ�غͽϴ���λ���ұߵ�����Ԫ��ȫ��ȥ����
	//����ȥ����Ԫ��ռ����Ԫ�ص�һ�룬���Ը��Ӷ�ΪO(logn)��
    while (leftArrBegin < leftArrEnd && rightArrBegin < rightArrEnd)  
    { 
        if ((leftArrBegin == leftArrEnd - 1 && rightArrBegin == rightArrEnd - 1))  
            break;  
            
    	//�������������м��±� 
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

