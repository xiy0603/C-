#include<stdio.h>
#include<string.h>
#define maxn 1005
int a[maxn];
int main()
{
	int n,k,i,j;
	memset(a,0,sizeof(a));  //初始化数组a，将0赋给a中所有的值 
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++) //每个人来一次
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
