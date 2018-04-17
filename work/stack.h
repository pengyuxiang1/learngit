#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
    ERROR = 0,OK = 1
}Status;

typedef int ElemType;

typedef struct SqStack{
       ElemType	*elem;
       int top;      //����ջ��ָ��
       int size;
}SqStack;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;	  //ջ��ָ��                     һ��ָ��ĩβ�ڵ��ָ�� 
	int	count;  //ջ��Ԫ�ظ���
}LinkStack;


Status initStack(SqStack *s,int sizes);
Status isEmptyStack(SqStack *s);
Status getTopStack(SqStack *s,ElemType *e);
Status clearStack(SqStack *s);
Status destoryStack(SqStack *s);
Status stackLength(SqStack *s,int length);
Status pushStack(SqStack *s,ElemType datas);
Status popStack(SqStack *s,ElemType *datas);


Status initLStack(LinkStack *s);                       //����һ����ջָ�� ,��������һ�������ջ  Ȼ��ע��topָ���Ӧ�������һ��ջ�����ǵ�һ����һ��linkstack��ͨ��linkstack��topָ��һ��node��Ȼ��node��node����������һ����ջ�� 
Status isEmptyLStack(LinkStack *s);                    // ��count�Ϳ���֪�� 
Status getTopLStack(LinkStack *s,ElemType *e);           //�õ��Ժ�Ҫͨ��*e���ֵ�������Ӧ����data��ֵ��ʵ��Ӧ����ͨ��һ·��ȥ����ջ�����������и��õķ����������Ѿ���ס�����һ��ջ�ĵ�ַ����������ջһ����ӦΪ�ǵ�ַ���ݣ������ں����������޸Ļ����еģ�����top��ֵ���Ա����� 
Status clearLStack(LinkStack *s);                     //��ͷָ�뿪ʼ��һ��һ����ʼɾ���������Ļ�����������뷨Υ���ˣ�topָ�벻������ָ�����һ���ģ���Ȼ�޷�����ָ�롣����������������һ��ָ���ס������ 
Status destoryLStack(LinkStack *s);                    //free������Ҫ�������ο���������� 
Status LStackLength(LinkStack *s,int *length);             //����Ҫ�����Ȼ����count�ͺ��˰� 
Status pushLStack(LinkStack *s,ElemType datas);               //�ο�����ջ 
Status popLStack(LinkStack *s,ElemType *datas);               //�ο�����ջ 


#endif // STACK_H_INCLUDED
