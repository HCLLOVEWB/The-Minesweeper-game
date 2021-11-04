#include"game.h"
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)//��ʼ������
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
	//��ӡ�к�
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
	printf("�������Ų��׵�����\n");
	scanf("%d%d",&x,&y);
	while(win<row*col-EASY_COUNT)
	{
	if(x>=1&&x<=row&&y>=1&&y<=col)
	{
	//����Ϸ�
		//1.�ȵ�����
		if(mine[x][y]=='1')
		{
			printf("���ź����㱻ը����\n");
			DisplayBoard(mine,ROW,COL);
			break;
		}
		//û�ȵ���
		else
		{
			//����x,y��Χ�м�����
			int count=get_mine_count(mine,x,y);
			show[x][y]=count+'0';
			DisplayBoard(show,row,col);
			win++;
		}
	}
	else
		printf("���겻�Ϸ�������������\n");
	}
	if(win=row*col-EASY_COUNT)
	{
	printf("��ϲ����Ϸ�ɹ�\n");
	DisplayBoard(mine,row,col);
	}
	
}
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	//'0'-'0'=0 '1'-'0'=1 (�ַ�����x-�ַ�����0������ֵ����x)
	return mine[x-1][y]+
	mine[x-1][y-1]+
	mine[x][y-1]+
	mine[x+1][y-1]+
	mine[x+1][y]+
	mine[x+1][y+1]+
	mine[x][y+1]+
	mine[x-1][y+1]-8*'0';//�����8*'0'��8*0�ǲ�һ���� ��0��=48
}