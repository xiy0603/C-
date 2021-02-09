#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d,m,n;
	printf("输入一元二次方程的三个系数a,b,c:");
	scanf("%f%f%f",&a,&b,&c);
	printf("\n");
	if(a==0)
	{
		if(b==0) printf("此方程无意义！\n");
		else printf("x=%f\n",-c/b);
	}
	else
	{
		d=b*b-4*a*c;
		if(d>=0)
		{
			m=-b/(2*a);
			n=sqrt(d)/(2*a);
			printf("x1=%f\n",m+n);
			printf("x2=%f\n",m-n);
		}
		else
		{
			m=-b/(2*a);
			n=sqrt(-d)/(2*a);
			printf("x1=%f+%f\n",m,n);
			printf("x2=%f-%f\n",m,n);
		}
	}
	return 0;
}
