#include<stdio.h>
#include<malloc.h>
struct Student 
{
	char name[100];
	int age;
	float score;		
}; 
int main()
{
	int len,i,j;
	struct Student t; 
	struct Student *arr;
	printf("输入学生的个数:\n");
	printf("len=");
	scanf("%d",&len);
	//构造动态一维数组 
	arr=(struct Student *)malloc(len* sizeof(struct Student));
	for(i=0;i<len;i++)
	{
		printf("输入第%d个学生的信息: \n",i+1);
		printf("name = ");
		scanf("%s",arr[i].name);
		
		printf("age = ");
		scanf("%d",&arr[i].age);
		
		printf("score = ");
		scanf("%f",&arr[i].score); 
	}
	
	//成绩升序排序
	
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-1-i;j++)
		{
			if(arr[j].score > arr[j+1].score)
			t = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = t; 
		}
	}
	
	
	//输出
	printf("\n\n学生的信息如下"); 
	printf("\n"); 
	for(i=0;i<len;i++)
	{
		printf("第%d个学生的信息是: \n",i+1);
		printf("name = %s\n",arr[i].name);
		printf("age = %d\n",arr[i].age);
		printf("score = %0.2f\n",arr[i].score);
		
		printf("\n");
	}
	return 0;	
}
