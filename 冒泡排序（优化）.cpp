#include<stdio.h>
int bubble_sort(int *arr,int len)
{
	int i,j,t;
	for(i=0;i<len-1;i++)
	{
		int flag = 1;//������һ������������Ѿ����� 
		for(j=0;j<len-1-i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
				flag = 0;//����ȫ���� 
			}
		}
		if(flag == 1)
		{
			break;
		}
	}
}

int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,9,8};
	int i;
	int len = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,len);
	for(i=0;i<len;i++)
	{
		printf("%d ",arr[i]);	
	}	
	return 0;
} 
