#include"game.h"
void menu()
{
	printf("**********************************\n");
	printf("*************��Ϸ�˵�*************\n");
	printf("*********ѡ������Ϸ������1 *******\n");
	printf("**********�˳���Ϸ������0 ********\n");
	printf("**********************************\n");
}
void game()
{
	//���úõ��׵���Ϣ
	char mine[ROWS][COLS];//11*11�ĸ���
	//�Ų�õ��׵���Ϣ
	char show[ROWS][COLS];//11*11�ĸ���
	//��ʼ��
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//��ӡ����
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show,ROW,COL);
	//������
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine,ROW,COL);//���Ǵ�ӡ�����Ĳ��úõ��׵�����
	//ɨ��
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
		printf("ɨ����Ϸ��ʼ\n");
		game();
	}
	else if(input==0)
	{
		printf("��Ϸ�˳�\n");
		break;
	}
	else
	{
		printf("��������ȷ����\n");	
	}
	}while(input);
}
int main()
{
	test();
	return 0;
}