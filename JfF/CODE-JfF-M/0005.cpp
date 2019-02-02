#include <iostream>  
using namespace std;  
 
int findMidValue(int *lhs, int *rhs, int size)  
{  
    if (lhs == NULL || rhs == NULL || size <= 0)  
        return -1;  
  
    int lhsBegin = 0;  
    int rhsBegin = 0;  
    int lhsEnd = size - 1;  
    int rhsEnd = size - 1;  
    int result;  
  
    while (lhsBegin < lhsEnd && rhsBegin < rhsEnd)  
    {  
        if (lhsBegin == lhsEnd - 1 && rhsBegin == rhsEnd - 1)  
            break;  
        int lhsMid = (lhsBegin + lhsEnd) >> 1;  
        int rhsMid = (rhsBegin + rhsEnd) >> 1;  
          
        if (lhs[lhsMid] == rhs[rhsMid])  
        {  
            result = lhs[lhsMid];  
            break;  
        }  
        else if (lhs[lhsMid] < rhs[rhsMid])  
        {  
            lhsBegin = lhsMid;  
            rhsEnd = rhsMid;  
        } else  
        {  
            lhsEnd = lhsMid;  
            rhsBegin = rhsMid;  
        }  
    }  
  
    if (lhsBegin == lhsEnd && rhsBegin == rhsEnd)  
        result = min(lhs[lhsBegin], rhs[rhsBegin]); 
		 
    else if (lhsBegin == lhsEnd - 1 && rhsBegin == rhsEnd - 1)  
    {  
        if (lhs[lhsBegin] < rhs[rhsBegin])  
        {  
            result = min(lhs[lhsEnd], rhs[rhsBegin]);  
        }  
        else  
        {  
            result = min(lhs[lhsBegin], rhs[rhsEnd]);  
        }  
    }  
  
    return result;  
}  
  
int main()  
{  
    int lhs[] = {1, 2, 3, 4};  
    int rhs[] = {0, 2, 3, 4};  
    const int size = sizeof lhs / sizeof *lhs;  
    int result = findMidValue(lhs, rhs, size);  
    cout << "mid value = " << result << endl;  
}  
