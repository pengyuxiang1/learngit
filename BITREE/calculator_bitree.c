#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdlib.h>

typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct {
 	TElemType *elem;     // 0�ŵ�Ԫ����
 	int lastIndex;          // ���������һ�����ı��
	int tog;
} SqBiTree;    // ˳��洢�Ķ�����

typedef struct BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������


 typedef enum Status
{
	SUCCESS,
	ERROR
}Status;

typedef struct LinkQueueNode//���������Ͷ���
{
	BiTNode *data;
	struct LinkQueueNode *next;
}LKQueNode;

typedef struct LKQueue
{
	LKQueNode *front, *rear;
}LKQue;


BiTNode* GetHead(LKQue *LQ)//ȡ������Ԫ��
{
	BiTNode *q = NULL;
	if (EmptyQueue(LQ))
		return q;
	else 
	{
		return LQ->front->next->data;
	}
}


void InitQueue(LKQue *LQ)//��ʼ������
{
	LKQueNode *p;
	p = (LKQueNode*)malloc(sizeof(LKQueNode));
	LQ->front = p;
	LQ->rear = p;
	(LQ->front)->next = NULL;
}

void EnQueue(LKQue *LQ, BiTree x)//�����
{
	LKQueNode *p;
	p = (LKQueNode*)malloc(sizeof(LKQueNode));
	p->data = x;
	p->next = NULL;
	(LQ->rear)->next = p;
	LQ->rear = p;
}

int OutQueue(LKQue *LQ)//������
{
	LKQueNode *s;
	if (EmptyQueue(LQ))
	{
		exit(0); return 0;
	}
	else
	{
		s = (LQ->front)->next;
		(LQ->front)->next = s->next;
		if (s->next == NULL)
			LQ->rear = LQ->front;
		free(s);
		return 1;
	}
}

int EmptyQueue(LKQue *LQ)//�ж϶����Ƿ�Ϊ��
{
	if (LQ->front == LQ->rear)
		return 1;
	else return 0;
}
Status InitBiTree(BiTree T){
	T=NULL;
}

Status CreateBiTree(BiTree*T)
{ 
	//�������������������н���ֵ��һ���ַ�����
	//�ո��ַ���ʾ������������������ʾ�Ķ�����T��
	char n;
	n = getchar();
	if (n == '#')  *T = NULL;
	else if (n == '\n') return;
	else
	{
		(*T) = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = n;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
	return SUCCESS;
}


Status DestroyBiTree(BiTree T)
{ /* ��ʼ����: ������T���ڡ��������: ���ٶ�����T */
	if (T) 
	{
		if (T->lchild)
		{
			DestroyBiTree(T->lchild);
		}
		if (T->rchild) 
		{
			DestroyBiTree(T->rchild);
		}
		free(T);
		T = NULL;
		return SUCCESS;
	}
	else return SUCCESS;
}


Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType)){
	if(T==NULL){
		return ERROR;
	}
	visit(T->data);
	PreOrderTraverse(T->rchild,visit);
	PreOrderTraverse(T->lchild,visit);
	return SUCCESS;
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType)){
	if(T==NULL){
		return ERROR;
	}
	PreOrderTraverse(T->rchild,visit);
	visit(T->data);
	PreOrderTraverse(T->lchild,visit);
	return SUCCESS;
}

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType)){
	if(T==NULL){
		return ERROR;
	}
	PreOrderTraverse(T->rchild,visit);
	PreOrderTraverse(T->lchild,visit);
	visit(T->data);
	return SUCCESS;
}

Status LevelOrderTraverse(BiTree bt, Status (*visit)(TElemType))          //�������
{
	LKQue Q; 
	BiTree p=NULL;
	InitQueue(&Q);
	if (bt != NULL)
	{
		EnQueue(&Q, bt);
		while (!EmptyQueue(&Q))
		{
			p=GetHead(&Q);
			OutQueue(&Q);
			visit(p->data);
			if (p->lchild != NULL)  EnQueue(&Q, p->lchild);
			if (p->rchild != NULL)  EnQueue(&Q, p->rchild);
		}
		return SUCCESS;
	}
	else return ERROR;
}


Status visit(TElemType e)
{
	printf("%c", e);
	return SUCCESS;
}

double Value(BiTree T)
{
	double v1, v2;
	if (T== NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)  //Ҷ�ӽڵ�
		return T->data - '0';    //Ҷ�ӽڵ�ֱ�ӷ��ؽڵ�ֵ������б���������õ����ַ���ʽ������Ҫ-'0'
	v1 = Value(T->lchild); //�ȼ���������
	v2 = Value(T->rchild); //�ټ���������
	switch (T->data)     //��������������Ľ���ٽ������㣬���õ��Ǻ��������˼·
	{
	case '+':
		return v1 + v2;
	case '-':
		return v1 - v2;
	case '*':
		return v1 * v2;
	case '/':
		if (v2 != 0)
			return v1 / v2;
		else
			abort();
	}

}

 int main()
{
	BiTree T=NULL;
	int flag;
	Status sta;
	char  choice = '\0';
	for (flag = 1; flag != 0;)
	{
		system("cls");
		printf("****************�˵�******************\n");
		printf("\t1.�����幹�������\n");
		printf("\t2.�Զ�����������������\n");
		printf("\t0:�˳�\n");
		printf("**************************************\n");
		choice = getchar();
		char ch; 
		while ((ch = getchar()) != '\n' && ch != EOF);
		system("cls");
		switch (choice)
		{
			case '1':
			{
				printf("�밴ǰ��������������ֵ����#��ʾ����(���磺+2##*3##4##Ϊ2+3*4��ǰ׺���ʽ)\n");
				sta = CreateBiTree(&T);
				char ch;
				while ((ch = getchar()) != '\n' && ch != EOF);
				if (sta == SUCCESS) printf("����ɹ�\n");
				else printf("����\n");
				system("pause"); break;
		    }
		    case '2':
		    {
				sta = Value(T);
				printf("���ʽ��ֵ:%lf\n", Value(T));
				system("pause"); break;
		    }
		    case '0':flag = 0; break;
		    default:printf("����������\n"); system("pause");
		}
	  }
	  return 0;
}  

