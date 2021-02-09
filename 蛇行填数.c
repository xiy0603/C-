#include<stdio.h>
//#include<string.h>
#define maxn 10
int a[maxn][maxn];
int main()
{
	int n,x,y,t=0;
	scanf("%d",&n);
	t=a[x=0][y=n-1]=1;
	while(t<n*n)
	{
		while(x+1<n && a[x+1][y]==0) a[++x ][y]=++t;
		while(y-1>=0 && a[x][y-1]==0) a[x][--y]=++t;
		while(x-1>=0 && !a[x-1][y]) a[--x][y]=++t;
		while(y+1<n && !a[x][y+1]) a[x][++y]=++t;
	}
	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)
		printf("%3d",a[x][y]);
		printf("\n");
	}
	return 0;
}
