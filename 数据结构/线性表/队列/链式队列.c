
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MaxSize 10
typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkNode;
typedef struct{
	LinkNode *front;
	LinkNode *rear;
}LinkQueue;


//��ʼ��  
void init(LinkQueue *q){		//��ͷ�ڵ�
	q->front=q->rear =(LinkNode *)malloc(sizeof(LinkNode));
	q->front ->next=NULL;
}
void init2(LinkQueue *q){		//����ͷ�ڵ� 
	q->front=q->rear=NULL;
} 

//�п�
bool empty(LinkQueue q){
	if(q.front ==q.rear)return true;
	else return false;//��ͷ�ڵ�ָ��NULL 
} 
bool empty2(LinkQueue q){
	if(q.front ==NULL)return true;
	else return false;
}

//���
void enqueue(LinkQueue *q,ElemType x){	//��ͷ�ڵ� 
	LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
	s->data =x;
	s->next =NULL;
	q->rear ->next=s;
	q->rear =s;
}
void enqueue2(LinkQueue *q,ElemType x){
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
bool dequeue(LinkQueue *q,ElemType *x){
	if(q->front ==q->rear)return false;
	LinkNode *p=q->front->next;
	*x=p->data; 
	q->front ->next=p->next;
	if(q->rear ==p)q->rear=q->front ;//���ɾ�����һ��Ԫ�أ�Ҫ����βָ��λ�� 
	free(p);
	return true;
}
bool dequeue2(LinkQueue *q,ElemType *x){
	if(q->front ==NULL)return false;//�ն���
	LinkNode *s=q->front;
	*x=s->data;
	q->front =s ->next;
	if(q->rear==s)q->rear=NULL;	//ֻ��һ��Ԫ�صĶ��� 
	free(s);
	return true;
}

//��ӡ
void printqueue(LinkQueue q){
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

 
int main (){
	LinkQueue q;
	init2(&q);
	enqueue2(&q,1);
	enqueue2(&q,22);
	enqueue2(&q,333);
	printqueue2(q);
	printf("\n");
	
	int x;
	dequeue2(&q,&x);
	enqueue2(&q,4444);
	printqueue2(q);
	return 0;
}
