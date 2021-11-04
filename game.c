#include"game.h"
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)//初始化数组
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			board[i][j]=set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS],int row,int col)
{
	int i,j;
	//打印列号
	for(i=0;i<=col;i++)
		printf("%d ",i);
	printf("\n");
	for(i=1;i<=row;i++)
	{
		printf("%d ",i);
		for(j=1;j<=col;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS],int row,int col)
{
	int count=EASY_COUNT;
	while(count)
	{
		int x=rand()%row+1;//1-9
		int y=rand()%col+1;
		if(board[x][y]=='0')
		{
			board[x][y]='1';
			count--;
		}	
	}
}
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int get_mine_count(char mine[ROWS][COLS],int x,int y);
	int x;
	int y;
	int win=0;
	printf("请输入排查雷的坐标\n");
	scanf("%d%d",&x,&y);
	while(win<row*col-EASY_COUNT)
	{
	if(x>=1&&x<=row&&y>=1&&y<=col)
	{
	//坐标合法
		//1.踩到雷了
		if(mine[x][y]=='1')
		{
			printf("很遗憾，你被炸死了\n");
			DisplayBoard(mine,ROW,COL);
			break;
		}
		//没踩到雷
		else
		{
			//计算x,y周围有几个雷
			int count=get_mine_count(mine,x,y);
			show[x][y]=count+'0';
			DisplayBoard(show,row,col);
			win++;
		}
	}
	else
		printf("坐标不合法，请重新输入\n");
	}
	if(win=row*col-EASY_COUNT)
	{
	printf("恭喜你游戏成功\n");
	DisplayBoard(mine,row,col);
	}
	
}
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	//'0'-'0'=0 '1'-'0'=1 (字符数字x-字符数字0等于数值数字x)
	return mine[x-1][y]+
	mine[x-1][y-1]+
	mine[x][y-1]+
	mine[x+1][y-1]+
	mine[x+1][y]+
	mine[x+1][y+1]+
	mine[x][y+1]+
	mine[x-1][y+1]-8*'0';//这里的8*'0'和8*0是不一样的 ‘0’=48
}