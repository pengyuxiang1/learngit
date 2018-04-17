#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

//˳��ջ(���������)                                                                                                �ص㣺����Ҫ��̬������Ūһ����������������϶����Ը㶨�� 
Status initStack(SqStack *s,int sizes)  //��ʼ������
{
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));                                                                 //��������s->elem��sizes�� 
	if(NULL==s->elem)
		return ERROR;
	s->top=-1;
	s->size=sizes;
	return OK;
}


Status isEmptyStack(SqStack *s)   //�ж������Ƿ�Ϊ��
{
	if(NULL==s)
		return OK;
	return (-1==s->top?OK:ERROR);                                                                                   
}


Status getTopStack(SqStack *s,ElemType *e)   //�õ�����ͷԪ��
{
	if(s==NULL||s->top==-1)
		return ERROR;
	else 
		*e=s->elem[s->top];                                                                  
	return OK;
}


Status clearStack(SqStack *s)   //�������
{
	if(NULL==s)
		return ERROR;
	while(s->top!=-1){
		s->elem[s->top]=0;
		s->top--;
	}
	return OK; 
}


Status destoryStack(SqStack *s)  //��������
{
	if(NULL==s)
		return ERROR;
	free(s->elem); 
	return OK; 
}


Status stackLength(SqStack *s,int length)   //���������                                                           //ȷ��������ָ�Ļ�������� 
{
	if(s==NULL||s->top==-1){
		printf("ջΪ�գ�����Ϊ��\n"); 
		return ERROR;
	} 
 length=s->top+1;
	printf("������Ϊ%d\n",length); 
	return OK;
}

Status pushStack(SqStack *s,ElemType datas)  //��ջ
{
	if(NULL==s||s->top>=s->size-1)
		return ERROR; 
	s->top++;
	s->elem[s->top]=datas;
	return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //��ջ
{

	if(s==NULL||s->top==-1)
		return ERROR;
	*datas=s->elem[s->top];                                                                        
	s->top--; 
	return OK;
}

//��ջ     �ص㣺�´���һ��ջ��ȴ������Ϊ�˿�ͷ�ڵ㣬�����Ϳ��Բ���������ָ������סͷ�ڵ��� 
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top=NULL;
	s->count=0;
	return OK;
}

Status isEmptyLStack(LinkStack *s)  //�ж������Ƿ�Ϊ��
{
	if(s==NULL)
		return ERROR; 
	return (NULL==s->top?OK:ERROR);  
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�����ͷԪ��
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

Status clearLStack(LinkStack *s)   //�������
{
	if(s==NULL)
		return ERROR;
	LinkStackPtr p;
	while(s->count!=0){
		p=s->top;
		s->top=p->next;
		s->count--;
		free(p);
	}                                                        //���ܵ����⣺�ص���ʼ����ʱ�򣿣����� 
	return OK;
}

Status destoryLStack(LinkStack *s)   //��������
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

Status LStackLength(LinkStack *s,int *length)    //���������
{
	if(s==NULL)
		return ERROR;
	if(isEmptyLStack(s))
		return ERROR;
	*length=s->count;
	return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //��ջ
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

Status popLStack(LinkStack *s,ElemType *datas)   //��ջ
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
	//����ջҪ�ĺ������� 
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
	printf("|                 �˵�                   |\n"); 
	printf("__________________________________________\n");	
	printf("|          1.��ʼ��ջ                    |\n");
	printf("|          2.ѹ������                    |\n");
	printf("|          3.ѹ��ջ��                    |\n");
	printf("|          4.���ջ����                  |\n");
	printf("|          5.���ջ��Ԫ��                |\n");
	printf("|          6.���ջ                      |\n");
	printf("|          7.�ж��Ƿ�Ϊ��                |\n");   
	printf("|          8.����                        |\n");   
	printf("|          9.�˳�                        |\n");  
	printf("|________________________________________|\n");		
	
	//����ѡ�� 
	do{
		printf("\n������Ĳ�������������9�˳�\n"); 
		scanf(" %c",&cs); 
		switch(cs){
			case '1':{
				printf("\n###########��ʼ��ջ###########\n");                            
				sqs=&q; 
				printf("������ջ������ĳ��ȣ�");
				scanf("%d",&sizes);
				initStack(sqs,sizes);
				printf("��ʼ���ɹ�\n");
				printf("----------------------------------");  	
				break;
			}
			case '2':{
				printf("\n###########ѹ�����###########\n");
				printf("������Ҫѹ������ݣ�");
				scanf("%d",datas);
				if(pushStack(sqs,*datas))
					printf("ѹ��ɹ�\n");
				else printf("ջδ��ʼ��,���߳��ȳ�������\n"); 
				break;
			}
			case '3':{
				printf("\n###########ѹ������###########\n");
				if(popStack(sqs,datas))
					printf("ջ������: %d ��ѹ��.\n",*datas);
				else printf("ջδ��ʼ���������Ѿ�Ϊ��ջ\n");
				break;
			}
			case '4':{
				printf("\n#########���Գ��Ȳ���#########\n");
				if(stackLength(sqs,length))
					printf("�������\n");
				else printf("���ʼ������ѹ������\n"); 
				break;
			}
			case '5':{
				printf("\n#########ȡջ��������#########\n");
				if(getTopStack(sqs,e) )	
					printf("��ʱջ������Ϊ��%d\n",*e);
				else printf("ջΪ��,����δ��ʼ��\n");
				break;
			}
			case '6':{
				printf("\n###########�������###########\n");
				if(clearStack(sqs)==OK)
					printf("ջ�������Ѿ����\n");
				else  printf("ջδ��ʼ��\n");
				break;
			}
			case '7':{
				printf("\n###########�ж��Ƿ�Ϊ�ղ���###########\n");
				if(isEmptyStack(sqs))
					printf("ջΪ�ա�����δ��ʼ����\n");
				else printf("ջ��Ϊ��.\n");
				break;
			}
			case '8':{
				printf("\n###########���ٲ���###########\n");
				if(destoryStack(sqs)){
					sqs=NULL;                                                                             
					printf("�������\n");
				}
				else printf("ջδ��ʼ������������\n");
				break;
			}
			case '9':{
				printf("�ټ�\n");
				break;
			}
			default:printf("please enter 1~10.Thank you!\n"); 
		}
	}while(cs!='9');	
}

void _LinkStack(void){
	//��ջ�������� 
	Status initLStack(LinkStack *s);
	Status isEmptyLStack(LinkStack *s);
	Status getTopLStack(LinkStack *s,ElemType *e);
	Status clearLStack(LinkStack *s);
	Status destoryLStack(LinkStack *s);
	Status LStackLength(LinkStack *s,int *length);
	Status pushLStack(LinkStack *s,ElemType datas);
	Status popLStack(LinkStack *s,ElemType *datas);
	
	//ʹ�ñ�������
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
	
	//�˵�����	
	printf("__________________________________________\n");
	printf("|                 �˵�                   |\n"); 
	printf("__________________________________________\n");	
	printf("|          1.��ʼ��ջ                    |\n");
	printf("|          2.ѹ������                    |\n");
	printf("|          3.ѹ��ջ��                    |\n");
	printf("|          4.���ջ����                  |\n");
	printf("|          5.���ջ��Ԫ��                |\n");
	printf("|          6.���                        |\n");
	printf("|          7.�ж��Ƿ�Ϊ��                |\n");   
	printf("|          8.����                        |\n");   
	printf("|          9.�˳�                        |\n");  
	printf("|________________________________________|\n");		
	
	do{
		printf("\n������Ĳ�������������9�˳�\n"); 
		scanf(" %c",&cs); 
		switch(cs){
			case '1':{
				printf("\n###########��ʼ��ջ###########\n");                                        //��/ȴû��n�ͻ����/312�Ĵ��� 
				ls=&ls1; 
				initLStack(ls);
				printf("��ʼ���ɹ�\n");
				printf("----------------------------------");  	
				break;
			}
			case '2':{
				printf("\n###########��ջ����###########\n");
				printf("������Ҫ��ջ�����ݣ�");
				scanf("%d",&datas);
				if(pushLStack(ls,datas))
					printf("ѹ��ɹ�\n");
				else printf("ջ���\n"); 
				break;
			}
			case '3':{
				printf("\n###########��ջ����###########\n");
				if(popLStack(ls,datas1))
					printf("ջ������: %d ��ѹ��.\n",*datas1);
				else printf("ջΪ��ջ\n");
				break;
			}
			case '4':{
				printf("\n#########���Գ��Ȳ���#########\n");
				if(LStackLength(ls,length))
					printf("ջ����Ϊ��%d\n",*length);
				else printf("��ջ\n"); 
				break;
			}
			case '5':{
				printf("\n#########ȡջ��Ԫ�ز���#########\n");
				if(getTopLStack(ls,e))	
					printf("��ʱջ������Ϊ��%d\n",*e);
				else printf("ջΪ��\n");
				break;
			}
			case '6':{
				printf("\n###########�������###########\n");
				if(clearLStack(ls)==OK)
					printf("ջ�������Ѿ����\n");
				else  printf("ջΪ��ջ\n");
				break;
			}
			case '7':{
				printf("\n###########�ж��Ƿ�Ϊ�ղ���###########\n");
				if(isEmptyLStack(ls))
					printf("ջΪ�ա�����δ��ʼ����\n");
				else printf("ջ��Ϊ��.\n");
				break;
			}
			case '8':{
				printf("\n###########���ٲ���###########\n");
				if(destoryLStack(ls)){
					ls=NULL;                                                                      
					printf("�������\n");
				}
				else printf("ջδ��ʼ������������\n");
				break;
			}
			case '9':{
				printf("�ټ�\n");
				break;
			}
			default:printf("please enter 1~10.Thank you!\n"); 
		}
	}while(cs!='9');	 
} 
