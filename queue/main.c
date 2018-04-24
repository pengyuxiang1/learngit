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

	

	printf("\tѡ��ѭ�����л�����ʽ����\n");
 	printf("\t1.ѭ������\n");
 	printf("\t2.��ʽ����\n");
 	printf("\t3.�˳�\n");
 	while(scanf("%d",&choose1)!=1){
		printf("�����������������\n");
	}
	do{
		if(choose1==1){
			printf("\tѭ������\n");
			printf("\t1.��ʼ������\n");
			printf("\t2.���ٶ���\n");
			printf("\t3.�������Ƿ�����\n");
			printf("\t4.�������Ƿ�Ϊ��\n");
			printf("\t5.�鿴��ͷԪ��\n");
			printf("\t6.ȷ�����г���\n");
			printf("\t7.��Ӳ���\n");
			printf("\t8.���Ӳ���\n");
			printf("\t9.��ն���\n");	
			printf("\t10.������������\n");
			printf("\t0. �˳�\n");
			printf("\t������1~11������\n");
			while(scanf("%d",&choose2)!=1){
				printf("�����������������\n");
			}
			
			switch(choose2){
				case 1:{
					InitAQueue(&AQ);
					printf("��ʼ���ɹ�\n");
					break;
				}
				case 2:{
					DestoryAQueue(&AQ);
					printf("���ٳɹ�\n");
					break;
				}
				case 3:{
					if(IsFullAQueue(&AQ)==TRUE){
						printf("������\n");
					}
					else printf("����δ��\n");
					break;
				}
				case 4:{
					if(IsEmptyAQueue(&AQ)==TRUE){
						printf("���п�\n");
					}
                	else printf("����δ��\n");
					break;
				}
				case 5:{
					if(GetHeadAQueue(&AQ,&e)==TRUE){
						APrint(&e);
					}
					else printf("����Ϊ��\n");
					break;
				}
				case 6:{
					printf("���г���Ϊ:%d\n",LengthAQueue(&AQ));
					break;
				}
				case 7:{
					my_scanf(&AQ);//�Զ��庯�� 
					break;
				}
				case 8:{
					if(DeAQueue(&AQ)==TRUE){
						printf("���ӳɹ�\n"); 
					}
					//else printf("����11Ϊ��\n");
					break;
				}
				case 9:{
					ClearAQueue(&AQ);
					printf("�Ѿ����\n"); 
					break;
				}
				case 10:{
					if(TraverseAQueue(&AQ,APrint)){
						printf("�������\n");
					}
					break;
				}
				default :printf("����0�˳�\n");//continue;
			}
		}
		
		
		if(choose1==2)
		{
			printf("\tѭ������\n");
			printf("\t1.��ʼ������\n");
			printf("\t2.���ٶ���\n");
			printf("\t3.�������Ƿ�Ϊ��\n");
			printf("\t4.�鿴��ͷԪ��\n");
			printf("\t5.ȷ�����г���\n");
			printf("\t6.��Ӳ���\n");
			printf("\t7.���Ӳ���\n");
			printf("\t8.��ն���\n");	
			printf("\t9.������������������ݲ���\n");
			printf("\t0. �˳�\n");
			printf("\t������1~11������\n");
			while(scanf("%d",&choose2)!=1){
				printf("�����������������\n");
			}
			switch(choose2){
				case 1:{
					printf("����Ҫ��������ݵ�����\n1.int\t2.char\t3.float\n");
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
                    	default:printf("������Ч,�ص����ܽ���\n");
                    }
					InitLQueue(&LQ);
					printf("��ʼ���ɹ�\n");
					break;
				}
				case 2:{
					DestoryLQueue(&LQ);
					printf("���ٳɹ�\n");
					break;
				}
				case 3:{
					if(IsEmptyLQueue(&LQ)){
						printf("���п�\n");
					}
					else printf("����δ��\n");
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
					else printf("����Ϊ��\n");
					break;
					
				} 
				case 5:{
					printf("���г���Ϊ:%d\n",LengthLQueue(&LQ));
					break;
				}
				case 6:{
					printf("����������:\n");
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
              		printf("��ӳɹ�\n");
                    break;
				}
				case 7:{
					if(DeLQueue(&LQ)){
						printf("���ӳɹ�\n");
					}
					else printf("����ʧ��\n"); 
					break;
				}
				case 8:{
					ClearLQueue(&LQ);
					printf("������\n");
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
						printf("�����ɹ�\n");
					}
					else printf("����ʧ��\n");
					break;
				} 
				default:printf("����0�˳�����\n");
			}
		}
	}while(choose2!=0);
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*	
	do{
		printf("���ȣ������ѡ��һ���洢��ʽ\n");
		printf("1.int 2.float 3.char \n");
		scanf(" %d",&a);
		switch(a){
			case 1:{
				int *c=NULL;
				int d=0;
				printf("���������ݣ�\n"); 
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
				printf("���������ݣ�\n"); 
				scanf("%c",&d); 
				c=&d;
				EnAQueue(&AQ,c);
				GetHeadAQueue(&AQ,e);
				printf("%d\n",e);		
				break;
			}
			default :printf("������1~6\n");
		}
	}while(a!=0);
	printf("bye\n");
	return 0;
} */

