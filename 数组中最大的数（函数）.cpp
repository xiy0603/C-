#include<stdio.h>
int main()
{   int max(int x,int y);
	int i,a[10],m,n;
	for(i=0;i<9;i++)
	scanf("%d",&a[i]);
	m=a[0];
	for(i=0;i<9;i++)
	if(max(m,a[i])>m)
		m=max(m,a[i]);
		printf("Max number is:%d\n",m);
	return 0;
}
int max(int x,int y)
{    
	int z; 
	if(x>y)  z= x;
	else z = y;
	return z;
} 
