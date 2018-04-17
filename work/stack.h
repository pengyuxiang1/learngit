#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
    ERROR = 0,OK = 1
}Status;

typedef int ElemType;

typedef struct SqStack{
       ElemType	*elem;
       int top;      //用于栈顶指针
       int size;
}SqStack;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;	  //栈顶指针                     一个指向末尾节点的指针 
	int	count;  //栈中元素个数
}LinkStack;


Status initStack(SqStack *s,int sizes);
Status isEmptyStack(SqStack *s);
Status getTopStack(SqStack *s,ElemType *e);
Status clearStack(SqStack *s);
Status destoryStack(SqStack *s);
Status stackLength(SqStack *s,int length);
Status pushStack(SqStack *s,ElemType datas);
Status popStack(SqStack *s,ElemType *datas);


Status initLStack(LinkStack *s);                       //传入一个链栈指针 ,即可生成一个链表的栈  然后注意top指向的应该是最后一个栈，不是第一个，一个linkstack，通过linkstack。top指向一个node，然后node和node相连接生成一个链栈。 
Status isEmptyLStack(LinkStack *s);                    // 看count就可以知道 
Status getTopLStack(LinkStack *s,ElemType *e);           //得到以后还要通过*e输出值，输出的应该是data的值，实现应该是通过一路下去的链栈找它（或者有更好的方法，比如已经记住了最后一个栈的地址，就像数组栈一样，应为是地址传递，所以在函数所做的修改还是有的，就像top的值得以保留） 
Status clearLStack(LinkStack *s);                     //从头指针开始，一个一个开始删除，这样的话，和上面的想法违背了，top指针不是用来指向最后一个的，不然无法遍历指针。。。除非我外面用一个指针记住了它。 
Status destoryLStack(LinkStack *s);                    //free，还是要遍历，参考链表的销毁 
Status LStackLength(LinkStack *s,int *length);             //长度要输出，然后，用count就好了吧 
Status pushLStack(LinkStack *s,ElemType datas);               //参考数组栈 
Status popLStack(LinkStack *s,ElemType *datas);               //参考数组栈 


#endif // STACK_H_INCLUDED
