#include"game.h"
void menu()
{
	printf("**********************************\n");
	printf("*************游戏菜单*************\n");
	printf("*********选择玩游戏请输入1 *******\n");
	printf("**********退出游戏请输入0 ********\n");
	printf("**********************************\n");
}
void game()
{
	//布置好的雷的信息
	char mine[ROWS][COLS];//11*11的格子
	//排查好的雷的信息
	char show[ROWS][COLS];//11*11的格子
	//初始化
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//打印棋盘
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show,ROW,COL);
	//布置雷
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine,ROW,COL);//这是打印出来的布置好的雷的棋盘
	//扫雷
	FindMine(mine,show,ROW,COL);

}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do{
	menu();
	scanf("%d",&input);
	if(input==1)
	{
		printf("扫雷游戏开始\n");
		game();
	}
	else if(input==0)
	{
		printf("游戏退出\n");
		break;
	}
	else
	{
		printf("请重新正确输入\n");	
	}
	}while(input);
}
int main()
{
	test();
	return 0;
}