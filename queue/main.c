#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define MAXQUEUE 10
#include"queue.c"
#include"queue.h"

int main(void)
{
	/*void InitAQueue(AQueue *Q);
	void DestoryAQueue(AQueue *Q);	
	Status IsEmptyAQueue(const AQueue *Q);
	Status IsFullAQueue(const AQueue *Q);
	Status GetHeadAQueue(AQueue *Q, void *e);
	int LengthAQueue(AQueue *Q);
	Status EnAQueue(AQueue *Q, void *data);
	Status DeAQueue(AQueue *Q);
	void ClearAQueue(AQueue *Q);
	void APrint(void *q);
	Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q));
	*/
	
	AQueue AQ;
	InitAQueue(&AQ);
	LQueue LQ;
	InitLQueue(&LQ);	
	void *e;
	int choose1,choose2,choose3;

	

	printf("\t选择循环队列还是链式队列\n");
 	printf("\t1.循环队列\n");
 	printf("\t2.链式队列\n");
 	printf("\t3.退出\n");
 	while(scanf("%d",&choose1)!=1){
		printf("输入错误，请重新输入\n");
	}
	do{
		if(choose1==1){
			printf("\t循环队列\n");
			printf("\t1.初始化队列\n");
			printf("\t2.销毁队列\n");
			printf("\t3.检查队列是否已满\n");
			printf("\t4.检查队列是否为空\n");
			printf("\t5.查看队头元素\n");
			printf("\t6.确定队列长度\n");
			printf("\t7.入队操作\n");
			printf("\t8.出队操作\n");
			printf("\t9.清空队列\n");	
			printf("\t10.遍历函数操作\n");
			printf("\t0. 退出\n");
			printf("\t请输入1~11号数字\n");
			while(scanf("%d",&choose2)!=1){
				printf("输入错误，请重新输入\n");
			}
			
			switch(choose2){
				case 1:{
					InitAQueue(&AQ);
					printf("初始化成功\n");
					break;
				}
				case 2:{
					DestoryAQueue(&AQ);
					printf("销毁成功\n");
					break;
				}
				case 3:{
					if(IsFullAQueue(&AQ)==TRUE){
						printf("队列满\n");
					}
					else printf("队列未满\n");
					break;
				}
				case 4:{
					if(IsEmptyAQueue(&AQ)==TRUE){
						printf("队列空\n");
					}
                	else printf("队列未空\n");
					break;
				}
				case 5:{
					if(GetHeadAQueue(&AQ,&e)==TRUE){
						APrint(&e);
					}
					else printf("队列为空\n");
					break;
				}
				case 6:{
					printf("队列长度为:%d\n",LengthAQueue(&AQ));
					break;
				}
				case 7:{
					my_scanf(&AQ);//自定义函数 
					break;
				}
				case 8:{
					if(DeAQueue(&AQ)==TRUE){
						printf("出队成功\n"); 
					}
					//else printf("队列11为空\n");
					break;
				}
				case 9:{
					ClearAQueue(&AQ);
					printf("已经清除\n"); 
					break;
				}
				case 10:{
					if(TraverseAQueue(&AQ,APrint)){
						printf("遍历完成\n");
					}
					break;
				}
				default :printf("输入0退出\n");//continue;
			}
		}
		
		
		if(choose1==2)
		{
			printf("\t循环队列\n");
			printf("\t1.初始化队列\n");
			printf("\t2.销毁队列\n");
			printf("\t3.检查队列是否为空\n");
			printf("\t4.查看队头元素\n");
			printf("\t5.确定队列长度\n");
			printf("\t6.入队操作\n");
			printf("\t7.出队操作\n");
			printf("\t8.清空队列\n");	
			printf("\t9.遍历函数并且输出数据操作\n");
			printf("\t0. 退出\n");
			printf("\t请输入1~11号数字\n");
			while(scanf("%d",&choose2)!=1){
				printf("输入错误，请重新输入\n");
			}
			switch(choose2){
				case 1:{
					printf("输入要输入的数据的类型\n1.int\t2.char\t3.float\n");
              		scanf("%d",&choose3);
              		switch(choose3)
              		{
                   		case 1:{
                   			LQ.data_size=sizeof(int);
                            break;
                        }
                    	case 2:
                        {
                        	LQ.data_size=sizeof(char);
                            break;
                        }
                    	case 3:
                        {
                        	LQ.data_size=sizeof(float);
                                break;
                        }
                    	default:printf("输入无效,回到功能界面\n");
                    }
					InitLQueue(&LQ);
					printf("初始化成功\n");
					break;
				}
				case 2:{
					DestoryLQueue(&LQ);
					printf("销毁成功\n");
					break;
				}
				case 3:{
					if(IsEmptyLQueue(&LQ)){
						printf("队列空\n");
					}
					else printf("队列未空\n");
					break;
				}
				case 4:{
					if(GetHeadLQueue(&LQ,&e)==TRUE){
						if(choose3==1){
							LPrint_int(e);	
						}
						if(choose3==2){
							LPrint_char(e);
						}
						if(choose3==3){
							LPrint_float(e);
						}
					}	
					else printf("队列为空\n");
					break;
					
				} 
				case 5:{
					printf("队列长度为:%d\n",LengthLQueue(&LQ));
					break;
				}
				case 6:{
					printf("请输入数据:\n");
					if(choose3==1){
						int a;
						scanf(" %d",&a);
						EnLQueue(&LQ,&a);
					} 
					if(choose3==2){
						char a;
						scanf(" %c",&a);
						EnLQueue(&LQ,&a);
					}
					if(choose3==3){
						float a;
						scanf(" %f",&a);
						EnLQueue(&LQ,&a);
					}
              		printf("入队成功\n");
                    break;
				}
				case 7:{
					if(DeLQueue(&LQ)){
						printf("出队成功\n");
					}
					else printf("出队失败\n"); 
					break;
				}
				case 8:{
					ClearLQueue(&LQ);
					printf("清楚完成\n");
					break;
				}
				case 9:{
					void (*foo)(void*q);
					if(choose3==1){
						foo=LPrint_int;	
					}
					if(choose3==2){
						foo=LPrint_char;
					}
					if(choose3==3){
						foo=LPrint_float;
					}
					if(TraverseLQueue(&LQ,foo)){
						printf("遍历成功\n");
					}
					else printf("遍历失败\n");
					break;
				} 
				default:printf("输入0退出程序\n");
			}
		}
	}while(choose2!=0);
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*	
	do{
		printf("首先，你可以选择一个存储方式\n");
		printf("1.int 2.float 3.char \n");
		scanf(" %d",&a);
		switch(a){
			case 1:{
				int *c=NULL;
				int d=0;
				printf("请输入数据：\n"); 
				scanf(" %d",&d);
				AQ.data_size=sizeof(int);
				c=&d;
				EnAQueue(&AQ,c);
				GetHeadAQueue(&AQ,e);
				printf("%d\n",*(int*)e);
				break;
			}
			case 2:{
				char *c=NULL;
				char d='a';
				AQ.data_size=sizeof(char);
				printf("请输入数据：\n"); 
				scanf("%c",&d); 
				c=&d;
				EnAQueue(&AQ,c);
				GetHeadAQueue(&AQ,e);
				printf("%d\n",e);		
				break;
			}
			default :printf("请输入1~6\n");
		}
	}while(a!=0);
	printf("bye\n");
	return 0;
} */

