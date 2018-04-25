#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"queue.h"

void InitAQueue(AQueue *Q)
{
	//Q->data[0]=malloc(Q->data_size);//问题1 
	int i;
	Q->front=0;
	Q->rear=0;
	for(i=0;i<MAXQUEUE;i++)
    {
        Q->data[i]=NULL;
    }
}

void DestoryAQueue(AQueue *Q)
{
	int i;
	for(i=0;i<MAXQUEUE;i++)
    {
        Q->data[i]=NULL;
    }
    Q->front=0;
    Q->rear=0;
    Q->data_size=0;
}

Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->rear==Q->front){
		return TRUE;
	}
	else return FALSE;
}//待会可以用于插入过程中判断是否满了，删除过程中判断是否空了 

Status IsFullAQueue(const AQueue *Q)
{
	
	if((Q->rear+1)%MAXQUEUE==Q->front){
		return TRUE;
	}
	else return FALSE;
}//同上 

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(IsEmptyAQueue(Q)){
		printf("现在队列空的，不好意思了。");
		return FALSE; 
	}
	else {
		memcpy(e,Q->data[(Q->front+1)%MAXQUEUE],Q->data_size); 
		return TRUE;
	}
} 

int LengthAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q)){
		return 0;
	} 
	else 
	{
		int t,f;
		t=Q->rear%MAXQUEUE;
		f=Q->front%MAXQUEUE;
		return t-f;//头节点指向的地方是空的，不存数据的 
	}
}

Status EnAQueue(AQueue *Q, void *data)   //添加参数 void *data,用来指示要入栈元素的地址 
{ 
	if(IsFullAQueue(Q)){
		printf("队列满了\n");
		return FALSE; 
	}
	Q->rear++;
	Q->data[Q->rear]=malloc(Q->data_size);
	memcpy(Q->data[Q->rear],data,Q->data_size);
	return TRUE;
}

Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q)){
		printf("队列空了，无法输出\n");
		return FALSE; 
	}
	Q->front++;
	Q->data[Q->front]=NULL;
	//不记住这个表头数据
	return TRUE; 
}

void ClearAQueue(AQueue *Q)
{
	Q->front=-1;
	Q->rear=-1;
} 

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	int i;
	if(IsEmptyAQueue(Q))
		return FALSE;
	for(i=Q->front;i!=Q->rear;i++){
		(*foo)(Q->data[i+1]);
		
	}
}

void APrint(void *q)
{
	int choose=0,flag=0;
    void*p=q;
    for(flag=1;flag!=0;)
    {
        printf("\n\t1:int\n\t2:float\n\t3:char\n\t请输入你的选择：");
        printf("（请正确选择队中头元素数据的类型）\n");
		scanf("%d",&choose);
        switch(choose)
        {
           	case 1:printf("%d\n",*(int*)p);
                flag=0;break;
            case 2:printf("%f\n",*(float*)p);
                flag=0;break;
            case 3:printf("%c\n",*(char*)p);
                flag=0;break;
            default:printf("无效选择，请重选\n");
        }
    }
}

void my_scanf(AQueue *AQ)
{	
	int a;
	void *e;
	int b;
	char c;
	float d; 
	
	//do{
		printf("首先，你可以选择一个输入的数据类型\n");
		printf("1.int 2.char 3.float 4.退出\n");
		scanf(" %d",&a);
		switch(a){
			case 1:{
				printf("请输入数据：\n"); 
				int *f=NULL;
				scanf(" %d",&b); 
				AQ->data_size=sizeof(int);
				f=&b;
				if(EnAQueue(AQ,f) )
					printf("入队成功\n");
				else printf("入队失败\n");
				break;
			}
			case 2:{
				printf("请输入数据：\n");
				char *f=NULL;
				AQ->data_size=sizeof(char);
				scanf(" %c",&c); 
				f=&c;
				if(EnAQueue(AQ,f) )
					printf("入队成功\n");
				else printf("入队失败\n");
				break;
			}
			case 3:{
				printf("请输入数据：\n");
				float *f;
				AQ->data_size=sizeof(float);
				scanf(" %f",&d);
				f=&d; 
				if(EnAQueue(AQ,f) )
					printf("入队成功\n");
				else printf("入队失败\n");
				break;
			}
			case 4:{
				printf("\n");
				break;
			}
			default :printf("请输入1~4\n");
		}
//	}while(a!=4);//暂时不循环了 
} 


//链式队列
void InitLQueue(LQueue *Q){
	Q->front=(Node*)malloc(Q->data_size);
	Q->front->next=NULL;
	Q->rear=Q->front;
}

 
void DestoryLQueue(LQueue *Q){
	Node *p1=NULL,*p2=NULL;
	p1=Q->front;
	for(;p1->next!=NULL;){
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	Q->front=p1;
}

Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front==Q->rear){
		return TRUE;
	} 
	else return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void **e){
	if(IsEmptyLQueue(Q)){
		return FALSE; 
	}
	*e=Q->front->data;
	return TRUE;
}                                     
//问题一 
//修改为双重指针void** 

int LengthLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)==TRUE){
		return 0;
	}
	int count=0;
	Node *p=Q->front;
	while(p->next!=NULL){
		p=p->next;
		count++;
	}
	return count;
}

Status EnLQueue(LQueue *Q, void *data){
	/*Node *p1=NULL;
	p1=(Node *)malloc(Q->data_size);
	printf("%d\n",*(int*)Q->front->data);
	if(Q->front==NULL){
		Q->front=p1;
		Q->rear=p1;
		p1->data=data;
		p1->next=NULL;
		return TRUE;
	}//插入第一个结点时 
	Q->rear->next=p1;
	p1->data=data;
	p1->next=NULL;
	Q->rear=p1;
	return TRUE;*/ //另一种实现方式，用于头节点有数据 
	Q->rear->next=(Node *)malloc(Q->data_size);
	Q->rear->data=data;
	Q->rear=Q->rear->next;
	Q->rear->next=NULL;//尾节点无数据； 
}


Status DeLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	Node *p1;
	p1=Q->front;
	Q->front=Q->front->next;
	free(p1);
	return TRUE;
} 


void ClearLQueue(LQueue *Q){
	Node *p1=NULL,*p2=NULL;
	p1=Q->front;
	while(p1->next!=NULL){
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	Q->front=p1;
} 
//ok还可以优化为使用出队函数； 

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(IsEmptyLQueue(Q)==TRUE){
		printf("空队\n");
		return FALSE;
	}
	Node *p=Q->front;
	while(p->next!=NULL){
		(*foo)(p->data);
		p=p->next;
	}
	return TRUE;
}
//LPrint用了三个针对不同队列 
void LPrint_int(void *q){
	printf("%d\n",*(int*)q);
}
void LPrint_float(void *q){
	printf("%f\n",*(float*)q);
}void LPrint_char(void *q){
	printf("%c\n",*(char*)q);
}


