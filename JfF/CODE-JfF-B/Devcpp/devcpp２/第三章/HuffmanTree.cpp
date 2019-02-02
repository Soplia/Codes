/*
	Subject:HuffmanTree
    Compiler:Devcpp
	Description:ʹ�ñ�׼ģ�庯�����еı�׼�⺯�� 
	Author:JiaruiXie
	Id:3-2-1
	Date_Begin:09/01/17 10:28
	Date_End:09/01/17 10:34
*/
#include <stdio.h>
#include <queue>
using namespace std;
 
int main()
{
	priority_queue<int , vector<int>, greater<int> > q;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans=0;
		while(!q.empty())
			q.pop();
			
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			q.push(x);
		}
		while(q.size()>1)
		{
			int a=q.top();
			q.pop();
			int b=q.top();
			q.pop();
			ans+=a+b;
			q.push(a+b);
		}
		printf("%d",ans);
	}
	return 0;
}
/*
��������
  5 
  1 2 2 5 9
*/

