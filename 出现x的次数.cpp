#include<stdio.h>
int q_cs(int,int);
int qcs(int,int); 
int main(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	printf("%d\n",q_cs(n,x));
	return 0;
}

int qcs(int n,int x)
{
	int cs = 0;
	while( n > 0)
	{
		if(n % 10 == x)
		{
			cs++;
		}
		n /= 10;	
	}
	return cs;
}

int q_cs(int n,int x)
{
	int cs = 0;
	while(n > 0)
	{
		cs += qcs(n--,x); 
	}
	return cs;
}
