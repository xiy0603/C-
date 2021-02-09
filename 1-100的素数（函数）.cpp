#include<stdio.h>
bool IsPrime(int i)
{   
	int j;
	for(j=2;j<i;j++)
    {
    	if(i % j == 0)
	    break;
	}
	if(i==j) return true;
	else return false;	
}
void Traverse(int var)
{
	int i;
	for(i=2;i<=var;i++)
	{
		if(IsPrime(i))
		printf("%d\n",i);
	}
	return;
}
int main()
{
	int var;
	scanf("%d",&var);
	Traverse(var);
	return 0;
}
