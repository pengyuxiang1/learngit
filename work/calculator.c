#include<stdio.h>
#include"stack.c"
#include"stack.h" 
#include<string.h>

int main()  
{  
	//�������� 
	Status syminitStack(symStack *s,int sizes);
	Status sympushStack(symStack *s,char datas);
	Status popsysStack(SqStack *s,char *ch);
	Status compare(symStack *sym1 , char ch);
	Status initStack(SqStack *s,int sizes);
	Status pushStack(SqStack *s,ElemType datas);
	Status popStack(SqStack *s,ElemType *datas);
	int deal_date(symStack *sym1 ,SqStack *s); 
	//��������
    int datas=0;
	char* temp=NULL;                                                  
    char dest[100];                                
    int num = 0;
    char choose; 
	//��ʼ������ջ�ͷ���ջ 
	SqStack sqs;
	symStack sys;
	syminitStack(&sys,20);
	initStack(&sqs,20);
	 
	do{	
    	char *str = (char *) malloc (sizeof(char) * 100);               //��ȡ���ʽ(������)  	
		printf("�����������ʽ��\n");
		printf("��ע������Ӣ���������ţ���֧�ָ���������,��������Ⱥţ�\n"); 
		scanf("%s",str);                                               
		
		//��֪��Ϊʲô��һ�������ţ����ǻ�������ѭ��������ֻ�ó����²ߣ��ֶ����\0�� 
	
		int c;
		c=strlen(str);
		str[c+1]='\0'; 
	
	
    	int i = 0;                                        
    	while(*str != '\0')                           //�������ʽ 
    	{  
    	    temp = dest;  
  		
    	    while(*str >= '0' && *str <= '9')           //�ж��Ƿ�������
    	    {  
    	        *temp = *str;              
    	        str ++;                    
    	        temp ++;	                  
    	    }                                          //���������˳�  
  		
    	    if(*str != '(' && *(temp - 1) != '\0')      /*�жϷ����Ƿ�Ϊ'('*/  
    	    {
    	    	*temp ='\0';            
       	    	 num = atoi(dest);                                 /*���ַ���תΪ����*/  
        	    pushStack(&sqs,num);                              /*������ѹ������ջ*/  //��push 
			}
		
			//printf(" %d\n",sqs.elem[0]);   �۲�����ֵ�ı仯
		 
	        while(1)  
	        {
    	        i = compare(&sys,*str);      //�жϲ��������ȼ�
    	        if(i == 0)  
    	        {  
    	            sympushStack(&sys,*str);                             //ѹ�������
    	            break;  
    	        }  
    	        else if(i == 1)                         //�ж������ڵı��ʽ�Ƿ����
    	        { 
    	            str++;  
    	        }  
    	        else if(i == -1)                        //���� 
    	        {  
    	            deal_date(&sys,&sqs);    
    	        }  
    	     }  
    	    str ++;               //ָ����һ���ַ� 
    	}  
		
		printf("�� = %d\n",sqs.elem[0]);       //���
		printf("(����E���˳�,����C����)\n");
		scanf(" %c",&choose); 
	}while(choose!='E');
	
	system("pause");
	return 0;                      
}  
