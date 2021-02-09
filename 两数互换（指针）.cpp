#include<stdio.h>
void huhuan(int * p,int * q)
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}
int main()
{
	int a=3,b=5;
	huhuan(&a,&b);
	printf("a=%d,b=%d",a,b);
}
