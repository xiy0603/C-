#include<stdio.h>
#include<math.h> 
int main()
{
	float a,b,c,q,s;
	printf("���������ε������߳�: ");
	scanf("%f%f%f",&a,&b,&c);
	q=(a+b+c)/2;
	s=sqrt(q*(q-a)*(q-b)*(q-c));
	if(a+b>c&&a+c>b&&b+c>a)
	{
		printf("���������Ϊ: %f\n",s);
	}
	else
		{
			printf("�޷�����������");  
		}
	return 0;
}
 
