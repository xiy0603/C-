#include<stdio.h>
#include<string.h>
#define maxn 1005
int a[maxn];
int main()
{
	int n,k,i,j;
	memset(a,0,sizeof(a));  //��ʼ������a����0����a�����е�ֵ 
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++) //ÿ������һ��
	{
		for(j=1;j<=n;j++)
		{ 
			if(j%i==0)
		    {
		    	a[j]=!a[j];	
			}
		}	
	}
	for(j=1;j<=n;j++)
	{
		if(a[j]==1)
		printf("%d ",j);	
	} 
	printf("\n");
	return 0;
}
