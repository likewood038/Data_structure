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


//初始化  
void InitQueue(LinkQueue *q){		//带头节点
	q->front=q->rear =(LinkNode *)malloc(sizeof(LinkNode));
	q->front ->next=NULL;
}
void InitQueue2(LinkQueue *q){		//不带头节点 
	q->front=q->rear=NULL;
} 

//判空
bool IsEmpty(LinkQueue q){
	if(q.front ==q.rear)return true;
	else return false;//或头节点指向NULL 
} 
bool IsEmpty2(LinkQueue q){
	if(q.front ==NULL)return true;
	else return false;
}

//入队
void EnQueue(LinkQueue *q,void *x){	//带头节点 
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
	if (q->front ==NULL){	//空队列 
		q->front =s;
		q->rear =s;
	}else{
		q->rear ->next=s;
		q->rear =s;
	}
}


//出队并返回删除值 
int* DeQueue(LinkQueue *q){
	if(q->front ==q->rear)return 0;
	LinkNode *p=q->front->next;
	int *x=p->data;
	q->front ->next=p->next;
	if(q->rear ==p)q->rear=q->front ;//如果删除最后一个元素，要调整尾指针位置 
	free(p);
	return x;
}
bool DeQueue2(LinkQueue *q,void *x){
	if(q->front ==NULL)return false;//空队列
	LinkNode *s=q->front;
	x=s->data;
	q->front =s ->next;
	if(q->rear==s)q->rear=NULL;	//只有一个元素的队列 
	free(s);
	return true;
}

//打印
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


