#include<stdio.h>
#include"stack.c"
#include"stack.h" 
#include<string.h>

int main()  
{  
	//函数声明 
	Status syminitStack(symStack *s,int sizes);
	Status sympushStack(symStack *s,char datas);
	Status popsysStack(SqStack *s,char *ch);
	Status compare(symStack *sym1 , char ch);
	Status initStack(SqStack *s,int sizes);
	Status pushStack(SqStack *s,ElemType datas);
	Status popStack(SqStack *s,ElemType *datas);
	int deal_date(symStack *sym1 ,SqStack *s); 
	//变量声明
    int datas=0;
	char* temp=NULL;                                                  
    char dest[100];                                
    int num = 0;
    char choose; 
	//初始化数组栈和符号栈 
	SqStack sqs;
	symStack sys;
	syminitStack(&sys,20);
	initStack(&sqs,20);
	 
	do{	
    	char *str = (char *) malloc (sizeof(char) * 100);               //获取表达式(不带＝)  	
		printf("请输入你的算式：\n");
		printf("（注：请用英文输入括号，不支持浮点数运算,不用输入等号）\n"); 
		scanf("%s",str);                                               
		
		//不知道为什么，一加上括号，就是会多出几个循环，所以只好出此下策，手动添加\0了 
	
		int c;
		c=strlen(str);
		str[c+1]='\0'; 
	
	
    	int i = 0;                                        
    	while(*str != '\0')                           //遍历表达式 
    	{  
    	    temp = dest;  
  		
    	    while(*str >= '0' && *str <= '9')           //判断是否是数据
    	    {  
    	        *temp = *str;              
    	        str ++;                    
    	        temp ++;	                  
    	    }                                          //遇到符号退出  
  		
    	    if(*str != '(' && *(temp - 1) != '\0')      /*判断符号是否为'('*/  
    	    {
    	    	*temp ='\0';            
       	    	 num = atoi(dest);                                 /*将字符串转为数字*/  
        	    pushStack(&sqs,num);                              /*将数据压入数据栈*/  //用push 
			}
		
			//printf(" %d\n",sqs.elem[0]);   观察最终值的变化
		 
	        while(1)  
	        {
    	        i = compare(&sys,*str);      //判断操作符优先级
    	        if(i == 0)  
    	        {  
    	            sympushStack(&sys,*str);                             //压入操作符
    	            break;  
    	        }  
    	        else if(i == 1)                         //判断括号内的表达式是否结束
    	        { 
    	            str++;  
    	        }  
    	        else if(i == -1)                        //运算 
    	        {  
    	            deal_date(&sys,&sqs);    
    	        }  
    	     }  
    	    str ++;               //指向下一个字符 
    	}  
		
		printf("答案 = %d\n",sqs.elem[0]);       //结果
		printf("(输入E可退出,输入C继续)\n");
		scanf(" %c",&choose); 
	}while(choose!='E');
	
	system("pause");
	return 0;                      
}  
