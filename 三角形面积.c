#include<stdio.h>
#include<math.h> 
int main()
{
	float a,b,c,q,s;
	printf("输入三角形的三个边长: ");
	scanf("%f%f%f",&a,&b,&c);
	q=(a+b+c)/2;
	s=sqrt(q*(q-a)*(q-b)*(q-c));
	if(a+b>c&&a+c>b&&b+c>a)
	{
		printf("三角形面积为: %f\n",s);
	}
	else
		{
			printf("无法构成三角形");  
		}
	return 0;
}
 
