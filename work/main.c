#include <stdio.h>
#include <stdlib.h> 
#include "stack.c"
#include "stack.h"

 
int main(void)
{
	//����ջ�ĺ������� 
	extern void ArrayStack (void);
	extern void _LinkStack(void);
	char choose;
	
	do{
		printf("��ѡ��ģʽ��\n");
		printf("__________________________________________\n");
		printf("|                 �˵�                   |\n"); 
		printf("|________________________________________|\n");	
		printf("|          A.����ջ                      |\n");
		printf("|          B.��ջ                        |\n");
		printf("|          C.�˳�                        |\n");
		printf("|________________________________________|\n");	
		scanf(" %c",&choose);
		switch(choose){
			case 'A':{
				ArrayStack();
				break;
			}
			case 'B':{
				_LinkStack();
				break;
			}
			case 'C':{
				printf("�ټ�\n"); 
				break;
			}
			default :printf("������A,B,C�е�һ��ѡ�\n");
		}
	}while(choose!='C');
	return 0;
}
	
