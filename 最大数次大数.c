#include<stdio.h>
main()
{
	int i,k[5],max,secondmax=0;
	max=k[0];
	printf("ÊäÈë5¸öÊı:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&k[i]);
	 	if(max<=k[i])
	 	{
			secondmax=max;
			max=k[i];		
     	} 
    	 else if(secondmax<=k[i])
			{
			 	secondmax=k[i];
			}
	} 
   printf("%d %d",max,secondmax); 
}
