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
	printf("����ѧ���ĸ���:\n");
	printf("len=");
	scanf("%d",&len);
	//���춯̬һά���� 
	arr=(struct Student *)malloc(len* sizeof(struct Student));
	for(i=0;i<len;i++)
	{
		printf("�����%d��ѧ������Ϣ: \n",i+1);
		printf("name = ");
		scanf("%s",arr[i].name);
		
		printf("age = ");
		scanf("%d",&arr[i].age);
		
		printf("score = ");
		scanf("%f",&arr[i].score); 
	}
	
	//�ɼ���������
	
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
	
	
	//���
	printf("\n\nѧ������Ϣ����"); 
	printf("\n"); 
	for(i=0;i<len;i++)
	{
		printf("��%d��ѧ������Ϣ��: \n",i+1);
		printf("name = %s\n",arr[i].name);
		printf("age = %d\n",arr[i].age);
		printf("score = %0.2f\n",arr[i].score);
		
		printf("\n");
	}
	return 0;	
}
