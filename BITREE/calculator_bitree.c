#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdlib.h>

typedef char TElemType;     // 假设二叉树结点的元素类型为字符

typedef struct {
 	TElemType *elem;     // 0号单元闲置
 	int lastIndex;          // 二叉树最后一个结点的编号
	int tog;
} SqBiTree;    // 顺序存储的二叉树

typedef struct BiTNode {
    TElemType      data;     // 数据域
    struct BiTNode  *lchild,*rchild;  // 左、右孩子指针
} BiTNode,*BiTree;   // 二叉链表


 typedef enum Status
{
	SUCCESS,
	ERROR
}Status;

typedef struct LinkQueueNode//链队列类型定义
{
	BiTNode *data;
	struct LinkQueueNode *next;
}LKQueNode;

typedef struct LKQueue
{
	LKQueNode *front, *rear;
}LKQue;


BiTNode* GetHead(LKQue *LQ)//取队列首元素
{
	BiTNode *q = NULL;
	if (EmptyQueue(LQ))
		return q;
	else 
	{
		return LQ->front->next->data;
	}
}


void InitQueue(LKQue *LQ)//初始化队列
{
	LKQueNode *p;
	p = (LKQueNode*)malloc(sizeof(LKQueNode));
	LQ->front = p;
	LQ->rear = p;
	(LQ->front)->next = NULL;
}

void EnQueue(LKQue *LQ, BiTree x)//入队列
{
	LKQueNode *p;
	p = (LKQueNode*)malloc(sizeof(LKQueNode));
	p->data = x;
	p->next = NULL;
	(LQ->rear)->next = p;
	LQ->rear = p;
}

int OutQueue(LKQue *LQ)//出队列
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

int EmptyQueue(LKQue *LQ)//判断队列是否为空
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
	//按先序次序输入二叉树中结点的值（一个字符），
	//空格字符表示空树，构造二叉链表表示的二叉树T。
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
{ /* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
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

Status LevelOrderTraverse(BiTree bt, Status (*visit)(TElemType))          //层序遍历
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
	if (T->lchild == NULL && T->rchild == NULL)  //叶子节点
		return T->data - '0';    //叶子节点直接返回节点值，结点中保存的数字用的是字符形式，所以要-'0'
	v1 = Value(T->lchild); //先计算左子树
	v2 = Value(T->rchild); //再计算右子树
	switch (T->data)     //将左、右子树运算的结果再进行运算，运用的是后序遍历的思路
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
		printf("****************菜单******************\n");
		printf("\t1.按定义构造二叉树\n");
		printf("\t2.对二叉树进行四则运算\n");
		printf("\t0:退出\n");
		printf("**************************************\n");
		choice = getchar();
		char ch; 
		while ((ch = getchar()) != '\n' && ch != EOF);
		system("cls");
		switch (choice)
		{
			case '1':
			{
				printf("请按前序次序输入各结点的值，以#表示空树(例如：+2##*3##4##为2+3*4的前缀表达式)\n");
				sta = CreateBiTree(&T);
				char ch;
				while ((ch = getchar()) != '\n' && ch != EOF);
				if (sta == SUCCESS) printf("构造成功\n");
				else printf("错误\n");
				system("pause"); break;
		    }
		    case '2':
		    {
				sta = Value(T);
				printf("表达式的值:%lf\n", Value(T));
				system("pause"); break;
		    }
		    case '0':flag = 0; break;
		    default:printf("错误，请重输\n"); system("pause");
		}
	  }
	  return 0;
}  

