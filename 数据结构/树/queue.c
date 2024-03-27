#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#define MaxSize 10

//typedef struct Node{
//	void *data;
//	struct Node *next;
//}LinkNode;
//typedef struct LinkQueue{
//	LinkNode *front;
//	LinkNode *rear;
//}LinkQueue;


//��ʼ��  
void InitQueue(LinkQueue *q){		//��ͷ�ڵ�
	q->front=q->rear =(LinkNode *)malloc(sizeof(LinkNode));
	q->front ->next=NULL;
}
void InitQueue2(LinkQueue *q){		//����ͷ�ڵ� 
	q->front=q->rear=NULL;
} 

//�п�
bool IsEmpty(LinkQueue q){
	if(q.front ==q.rear)return true;
	else return false;//��ͷ�ڵ�ָ��NULL 
} 
bool IsEmpty2(LinkQueue q){
	if(q.front ==NULL)return true;
	else return false;
}

//���
void EnQueue(LinkQueue *q,void *x){	//��ͷ�ڵ� 
	LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
	s->data =x;
	s->next =NULL;
	q->rear ->next=s;
	q->rear =s;
}
void EnQueue2(LinkQueue *q,void *x){
	LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
	s->data =x;
	s->next =NULL;
	if (q->front ==NULL){	//�ն��� 
		q->front =s;
		q->rear =s;
	}else{
		q->rear ->next=s;
		q->rear =s;
	}
}


//���Ӳ�����ɾ��ֵ 
int* DeQueue(LinkQueue *q){
	if(q->front ==q->rear)return 0;
	LinkNode *p=q->front->next;
	int *x=p->data;
	q->front ->next=p->next;
	if(q->rear ==p)q->rear=q->front ;//���ɾ�����һ��Ԫ�أ�Ҫ����βָ��λ�� 
	free(p);
	return x;
}
bool DeQueue2(LinkQueue *q,void *x){
	if(q->front ==NULL)return false;//�ն���
	LinkNode *s=q->front;
	x=s->data;
	q->front =s ->next;
	if(q->rear==s)q->rear=NULL;	//ֻ��һ��Ԫ�صĶ��� 
	free(s);
	return true;
}

//��ӡ
static void printqueue(LinkQueue q){
	q.front =q.front ->next;
	while (q.front !=NULL){
		printf("%d ",q.front ->data);
		q.front =q.front ->next;
	}
}
void printqueue2(LinkQueue q){
	while(q.front !=NULL){
		printf("%d ",q.front->data );
		q.front =q.front ->next;
	}
}


