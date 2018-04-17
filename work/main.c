#include <stdio.h>
#include <stdlib.h> 
#include "stack.c"
#include "stack.h"

 
int main(void)
{
	//两个栈的函数声明 
	extern void ArrayStack (void);
	extern void _LinkStack(void);
	char choose;
	
	do{
		printf("请选择模式：\n");
		printf("__________________________________________\n");
		printf("|                 菜单                   |\n"); 
		printf("|________________________________________|\n");	
		printf("|          A.数组栈                      |\n");
		printf("|          B.链栈                        |\n");
		printf("|          C.退出                        |\n");
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
				printf("再见\n"); 
				break;
			}
			default :printf("请输入A,B,C中的一个选项。\n");
		}
	}while(choose!='C');
	return 0;
}
	
