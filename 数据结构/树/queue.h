#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Node{
	void *data;
	struct Node *next;
}LinkNode;
typedef struct LinkQueue{
	LinkNode *front;
	LinkNode *rear;
}LinkQueue;



void InitQueue(LinkQueue *q);
void InitQueue2(LinkQueue *q);


bool IsEmpty(LinkQueue q);
bool IsEmpty2(LinkQueue q);


void EnQueue(LinkQueue *q,void *x);
void EnQueue2(LinkQueue *q,void *x);

int* DeQueue(LinkQueue *q);
bool DeQueue2(LinkQueue *q,void *x);


#endif
