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

//初始化棋盘 
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

//打印棋盘(只能控制行) 

//void DisplayBoard(char board[row][col],int Row,int Col)
//{
//	int i =0,j=0;
//	for(i=0;i<row;i++)
//	{
//		//1.打印一行数据
//		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//		//2.打印分隔行 
//		if(i<row -1)
//		printf("---|---|---\n");
//	}
//} 

//打印棋盘（控制行和列） 
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
			//1.打印一行数据
			printf(" %c ",board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		//2.打印分隔行
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

//玩家下棋
void playerMove(char board[row][col],int Row,int Col)
{
	int x,y;
	printf("玩家走:>\n");
	while(1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d",&x,&y);
		//判断x,y是否合法 
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用！\n");
			}
		}
		else 
		{
			printf("坐标非法,请重新输入!\n");	
		}	 
	}
}


//电脑下棋
void comMove(char board[row][col],int Row,int Col)
{
	int x,y;
	printf("电脑走:>\n");
	while(1)
	{
		//电脑随机 
		x = rand() % row; //0 1 2
		y = rand() % col; //0 1 2
		if(board[x][y] == ' ')
		{
			board[x][y] = '#'; 
			break;
		}
	}
} 

//返回1表示棋盘满了 
//返回0表示没满 
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
//游戏的四种状态
//1.玩家赢  - '*'
//2.电脑赢  - '#'
//3.平局    - 'Q'
//4.继续    - 'C'
char IsWin(char board[row][col],int Row,int Col)
{
	int i;
	//横三行 
	for(i=0;i<row;i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三列 
	for(i=0;i<col;i++)	
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}	
	}
	//对角线		
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1]!=' ') 
		return board[1][1];
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1]!=' ') 
		return board[1][1];
	//判断是否平局
	if(1==IsFull(board,row,col)) 
	{
		return 'Q';
	}
	return 'C';
}
//游戏的实现算法 
void game()
{  
	char ret = 0;
	char board[row][col] = {0};//全部是空格
	//初始化棋盘
	InitBoard(board,row,col); 
	//打印棋盘 
	DisplayBoard(board,row,col);
	//下棋
	while(1)
	{
		//玩家下棋
		playerMove(board,row,col);
		//打印玩家走的棋
		DisplayBoard(board,row,col);
		//判断玩家是否赢
		ret = IsWin(board,row,col);
		if(ret != 'C')
		{
			break;
		}
		//电脑下棋	
		comMove(board,row,col);
		//打印电脑走的棋
		DisplayBoard(board,row,col);
    	//判断电脑是否赢 
    	ret = IsWin(board,row,col);
		if(ret != 'C')
		{
			break;
		}
	} 
	if(ret == '*')
	{
		printf("玩家赢！\n");
	}
	else if(ret == '#')
	{
		printf("电脑赢！\n");
	}
	else printf("平局！\n");
}

void test()
{
	int num = 0;
	srand((unsigned int)time(NULL));  //设置随机数种子 
	do{
		menu();
		printf("请选择！");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏!\n");
				break;
			default:
				printf("请重新选择！\n");
				break;
		}
	}while(num);
}

int main()
{
	test();
	return 0;
}
