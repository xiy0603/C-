#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#define row 3
#define col 3

void menu()
{
	printf("**************************\n");
	printf("*****1.play   0.exit******\n");
	printf("**************************\n");
}

//��ʼ������ 
void InitBoard(char board[row][col],int Row,int Col)
{
	int i =0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			board[i][j] = ' ';	
		}	
	}	
}

//��ӡ����(ֻ�ܿ�����) 

//void DisplayBoard(char board[row][col],int Row,int Col)
//{
//	int i =0,j=0;
//	for(i=0;i<row;i++)
//	{
//		//1.��ӡһ������
//		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//		//2.��ӡ�ָ��� 
//		if(i<row -1)
//		printf("---|---|---\n");
//	}
//} 

//��ӡ���̣������к��У� 
void DisplayBoard(char board[row][col],int Row,int Col)
{
	int i =0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
//			   |   |   
//			---|---|---
//			   |   |   
//			---|---|---
//			   |   |   		
			//1.��ӡһ������
			printf(" %c ",board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		//2.��ӡ�ָ���
		if(i<row-1)
		{
			for(j=0;j<col;j++)
			{
				printf("---");
				if(j<col-1)
					printf("|");
			}
			printf("\n");
		} 	
	} 
}

//�������
void playerMove(char board[row][col],int Row,int Col)
{
	int x,y;
	printf("�����:>\n");
	while(1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d%d",&x,&y);
		//�ж�x,y�Ƿ�Ϸ� 
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã�\n");
			}
		}
		else 
		{
			printf("����Ƿ�,����������!\n");	
		}	 
	}
}


//��������
void comMove(char board[row][col],int Row,int Col)
{
	int x,y;
	printf("������:>\n");
	while(1)
	{
		//������� 
		x = rand() % row; //0 1 2
		y = rand() % col; //0 1 2
		if(board[x][y] == ' ')
		{
			board[x][y] = '#'; 
			break;
		}
	}
} 

//����1��ʾ�������� 
//����0��ʾû�� 
int IsFull(char board[row][col],int Row,int Col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
//��Ϸ������״̬
//1.���Ӯ  - '*'
//2.����Ӯ  - '#'
//3.ƽ��    - 'Q'
//4.����    - 'C'
char IsWin(char board[row][col],int Row,int Col)
{
	int i;
	//������ 
	for(i=0;i<row;i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//������ 
	for(i=0;i<col;i++)	
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}	
	}
	//�Խ���		
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1]!=' ') 
		return board[1][1];
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1]!=' ') 
		return board[1][1];
	//�ж��Ƿ�ƽ��
	if(1==IsFull(board,row,col)) 
	{
		return 'Q';
	}
	return 'C';
}
//��Ϸ��ʵ���㷨 
void game()
{  
	char ret = 0;
	char board[row][col] = {0};//ȫ���ǿո�
	//��ʼ������
	InitBoard(board,row,col); 
	//��ӡ���� 
	DisplayBoard(board,row,col);
	//����
	while(1)
	{
		//�������
		playerMove(board,row,col);
		//��ӡ����ߵ���
		DisplayBoard(board,row,col);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board,row,col);
		if(ret != 'C')
		{
			break;
		}
		//��������	
		comMove(board,row,col);
		//��ӡ�����ߵ���
		DisplayBoard(board,row,col);
    	//�жϵ����Ƿ�Ӯ 
    	ret = IsWin(board,row,col);
		if(ret != 'C')
		{
			break;
		}
	} 
	if(ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if(ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else printf("ƽ�֣�\n");
}

void test()
{
	int num = 0;
	srand((unsigned int)time(NULL));  //������������� 
	do{
		menu();
		printf("��ѡ��");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ!\n");
				break;
			default:
				printf("������ѡ��\n");
				break;
		}
	}while(num);
}

int main()
{
	test();
	return 0;
}
