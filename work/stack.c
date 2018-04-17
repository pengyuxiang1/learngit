#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

//顺序栈(基于数组的)                                                                                                特点：不需要动态创建，弄一个数组出来，基本上都可以搞定了 
Status initStack(SqStack *s,int sizes)  //初始化链表
{
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));                                                                 //创建数组s->elem【sizes】 
	if(NULL==s->elem)
		return ERROR;
	s->top=-1;
	s->size=sizes;
	return OK;
}


Status isEmptyStack(SqStack *s)   //判断链表是否为空
{
	if(NULL==s)
		return OK;
	return (-1==s->top?OK:ERROR);                                                                                   
}


Status getTopStack(SqStack *s,ElemType *e)   //得到链表头元素
{
	if(s==NULL||s->top==-1)
		return ERROR;
	else 
		*e=s->elem[s->top];                                                                  
	return OK;
}


Status clearStack(SqStack *s)   //清空链表
{
	if(NULL==s)
		return ERROR;
	while(s->top!=-1){
		s->elem[s->top]=0;
		s->top--;
	}
	return OK; 
}


Status destoryStack(SqStack *s)  //销毁链表
{
	if(NULL==s)
		return ERROR;
	free(s->elem); 
	return OK; 
}


Status stackLength(SqStack *s,int length)   //检测链表长度                                                           //确定是链表？指的还是数组吧 
{
	if(s==NULL||s->top==-1){
		printf("栈为空，长度为零\n"); 
		return ERROR;
	} 
 length=s->top+1;
	printf("链表长度为%d\n",length); 
	return OK;
}

Status pushStack(SqStack *s,ElemType datas)  //入栈
{
	if(NULL==s||s->top>=s->size-1)
		return ERROR; 
	s->top++;
	s->elem[s->top]=datas;
	return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //出栈
{

	if(s==NULL||s->top==-1)
		return ERROR;
	*datas=s->elem[s->top];                                                                        
	s->top--; 
	return OK;
}

//链栈     特点：新创立一个栈，却让它成为了开头节点，这样就可以不用有其他指针来记住头节点了 
Status initLStack(LinkStack *s)   //初始化
{
	s->top=NULL;
	s->count=0;
	return OK;
}

Status isEmptyLStack(LinkStack *s)  //判断链表是否为空
{
	if(s==NULL)
		return ERROR; 
	return (NULL==s->top?OK:ERROR);  
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到链表头元素
{
	if(s==NULL)
		return ERROR;
	if(isEmptyLStack(s))
		return ERROR;
	else{
		*e=s->top->data;
		return OK;
	} 
}

Status clearLStack(LinkStack *s)   //清空链表
{
	if(s==NULL)
		return ERROR;
	LinkStackPtr p;
	while(s->count!=0){
		p=s->top;
		s->top=p->next;
		s->count--;
		free(p);
	}                                                        //可能的问题：回到初始化的时候？？？？ 
	return OK;
}

Status destoryLStack(LinkStack *s)   //销毁链表
{
	if(s==NULL)
		return ERROR;
	LinkStackPtr p;
	while(s->count!=0){
		p=s->top;
		s->top=p->next;
		s->count--;
		free(p);
	}                                                     
	return OK; 
}

Status LStackLength(LinkStack *s,int *length)    //检测链表长度
{
	if(s==NULL)
		return ERROR;
	if(isEmptyLStack(s))
		return ERROR;
	*length=s->count;
	return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //入栈
{
	if(s==NULL)
		return ERROR;
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	if(p==NULL)
		return ERROR;
	else{
		p->data=datas;
		p->next=s->top;
		s->top=p;
		s->count++;
		return OK;
	} 
}

Status popLStack(LinkStack *s,ElemType *datas)   //出栈
{
	if(s==NULL)
		return ERROR;
	LinkStackPtr p;
	if(isEmptyLStack(s))
		return ERROR;
	else{
		p=s->top;
		*datas=s->top->data;
		s->top=p->next;
		s->count--;
		free(p);
		return OK;
	}
}
	
void ArrayStack (void){
	//数组栈要的函数声明 
	Status initStack(SqStack *s,int sizes);
	Status isEmptyStack(SqStack *s);
	Status getTopStack(SqStack *s,ElemType *e);
	Status clearStack(SqStack *s);
	Status destoryStack(SqStack *s);
	Status stackLength(SqStack *s,int length);
	Status pushStack(SqStack *s,ElemType datas);
	Status popStack(SqStack *s,ElemType *datas);
	
	int sizes=0,length=0,i=0,j=0;;
	int *datas;
	ElemType *e;
	SqStack q;
	SqStack *sqs=NULL;
	e=&j;
	datas=&j;
	char cs; 
	
	printf("__________________________________________\n");
	printf("|                 菜单                   |\n"); 
	printf("__________________________________________\n");	
	printf("|          1.初始化栈                    |\n");
	printf("|          2.压入新项                    |\n");
	printf("|          3.压出栈顶                    |\n");
	printf("|          4.输出栈长度                  |\n");
	printf("|          5.输出栈顶元素                |\n");
	printf("|          6.清空栈                      |\n");
	printf("|          7.判断是否为空                |\n");   
	printf("|          8.销毁                        |\n");   
	printf("|          9.退出                        |\n");  
	printf("|________________________________________|\n");		
	
	//做出选择 
	do{
		printf("\n输入你的操作，或者输入9退出\n"); 
		scanf(" %c",&cs); 
		switch(cs){
			case '1':{
				printf("\n###########初始化栈###########\n");                            
				sqs=&q; 
				printf("请输入栈中数组的长度：");
				scanf("%d",&sizes);
				initStack(sqs,sizes);
				printf("初始化成功\n");
				printf("----------------------------------");  	
				break;
			}
			case '2':{
				printf("\n###########压入操作###########\n");
				printf("请输入要压入的数据：");
				scanf("%d",datas);
				if(pushStack(sqs,*datas))
					printf("压入成功\n");
				else printf("栈未初始化,或者长度超出限制\n"); 
				break;
			}
			case '3':{
				printf("\n###########压出操作###########\n");
				if(popStack(sqs,datas))
					printf("栈顶数据: %d 已压出.\n",*datas);
				else printf("栈未初始化，或者已经为空栈\n");
				break;
			}
			case '4':{
				printf("\n#########测试长度操作#########\n");
				if(stackLength(sqs,length))
					printf("测试完成\n");
				else printf("请初始化或者压入数据\n"); 
				break;
			}
			case '5':{
				printf("\n#########取栈顶数操作#########\n");
				if(getTopStack(sqs,e) )	
					printf("此时栈顶数据为：%d\n",*e);
				else printf("栈为空,或者未初始化\n");
				break;
			}
			case '6':{
				printf("\n###########清除操作###########\n");
				if(clearStack(sqs)==OK)
					printf("栈内数据已经清除\n");
				else  printf("栈未初始化\n");
				break;
			}
			case '7':{
				printf("\n###########判断是否为空操作###########\n");
				if(isEmptyStack(sqs))
					printf("栈为空。（或未初始化）\n");
				else printf("栈不为空.\n");
				break;
			}
			case '8':{
				printf("\n###########销毁操作###########\n");
				if(destoryStack(sqs)){
					sqs=NULL;                                                                             
					printf("销毁完成\n");
				}
				else printf("栈未初始化，不能销毁\n");
				break;
			}
			case '9':{
				printf("再见\n");
				break;
			}
			default:printf("please enter 1~10.Thank you!\n"); 
		}
	}while(cs!='9');	
}

void _LinkStack(void){
	//链栈函数声明 
	Status initLStack(LinkStack *s);
	Status isEmptyLStack(LinkStack *s);
	Status getTopLStack(LinkStack *s,ElemType *e);
	Status clearLStack(LinkStack *s);
	Status destoryLStack(LinkStack *s);
	Status LStackLength(LinkStack *s,int *length);
	Status pushLStack(LinkStack *s,ElemType datas);
	Status popLStack(LinkStack *s,ElemType *datas);
	
	//使用变量声明
	char cs;
	LinkStack *ls=NULL;
	LinkStack ls1;
	int *length;
	int a=0,datas=0,b=0,c=0;
	length=&a;
	int *datas1;
	int *e;
	datas1=&b;
	e=&c; 
	
	//菜单生成	
	printf("__________________________________________\n");
	printf("|                 菜单                   |\n"); 
	printf("__________________________________________\n");	
	printf("|          1.初始化栈                    |\n");
	printf("|          2.压入新项                    |\n");
	printf("|          3.压出栈顶                    |\n");
	printf("|          4.输出栈长度                  |\n");
	printf("|          5.输出栈顶元素                |\n");
	printf("|          6.清空                        |\n");
	printf("|          7.判断是否为空                |\n");   
	printf("|          8.销毁                        |\n");   
	printf("|          9.退出                        |\n");  
	printf("|________________________________________|\n");		
	
	do{
		printf("\n输入你的操作，或者输入9退出\n"); 
		scanf(" %c",&cs); 
		switch(cs){
			case '1':{
				printf("\n###########初始化栈###########\n");                                        //光/却没有n就会出现/312的错误 
				ls=&ls1; 
				initLStack(ls);
				printf("初始化成功\n");
				printf("----------------------------------");  	
				break;
			}
			case '2':{
				printf("\n###########入栈操作###########\n");
				printf("请输入要入栈的数据：");
				scanf("%d",&datas);
				if(pushLStack(ls,datas))
					printf("压入成功\n");
				else printf("栈溢出\n"); 
				break;
			}
			case '3':{
				printf("\n###########出栈操作###########\n");
				if(popLStack(ls,datas1))
					printf("栈顶数据: %d 已压出.\n",*datas1);
				else printf("栈为空栈\n");
				break;
			}
			case '4':{
				printf("\n#########测试长度操作#########\n");
				if(LStackLength(ls,length))
					printf("栈长度为：%d\n",*length);
				else printf("空栈\n"); 
				break;
			}
			case '5':{
				printf("\n#########取栈顶元素操作#########\n");
				if(getTopLStack(ls,e))	
					printf("此时栈顶数据为：%d\n",*e);
				else printf("栈为空\n");
				break;
			}
			case '6':{
				printf("\n###########清除操作###########\n");
				if(clearLStack(ls)==OK)
					printf("栈内数据已经清除\n");
				else  printf("栈为空栈\n");
				break;
			}
			case '7':{
				printf("\n###########判断是否为空操作###########\n");
				if(isEmptyLStack(ls))
					printf("栈为空。（或未初始化）\n");
				else printf("栈不为空.\n");
				break;
			}
			case '8':{
				printf("\n###########销毁操作###########\n");
				if(destoryLStack(ls)){
					ls=NULL;                                                                      
					printf("销毁完成\n");
				}
				else printf("栈未初始化，不能销毁\n");
				break;
			}
			case '9':{
				printf("再见\n");
				break;
			}
			default:printf("please enter 1~10.Thank you!\n"); 
		}
	}while(cs!='9');	 
} 
