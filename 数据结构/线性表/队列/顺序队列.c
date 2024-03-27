//队尾指针指向队尾后一个 

#include <stdio.h>
#include <stdbool.h>

#define MaxSize 5
typedef int elemtype;
typedef struct{
	elemtype data[MaxSize];
	int front,rear;
}SqQueue;

//创销增删查 判空 
bool init(SqQueue *q){
	q-> rear =0;
	q-> front =0;
}
bool empty (SqQueue q){
	if (q.front ==q.rear )return true;
	else return false;
}
//入队 
bool enqueue (SqQueue *q,elemtype x){
	if((q-> rear+1)%MaxSize==q-> front)return false;//队列已满 
	(*q).data[q-> rear]=x;
	q-> rear=(q-> rear+1)%MaxSize;//循环队列 
	
}
//出队
bool dequeue(SqQueue *q,elemtype *x){
	if(q-> rear==q-> front)return false;	//队空
	(*x)=q->data [q->front];
	q-> front=(q-> front+1)%MaxSize;
	return true;	 
} 

//获得队头元素
bool gethead(SqQueue q,elemtype *x){
	if (q.rear =q.front )return false;
	*x=q.data [q.front];
	return true;
}

void printqueue(SqQueue s){
//	while(s.front%MaxSize !=s.rear){
//		printf("%d ",s.data[s.front]);
//		s.front=(s.front +1)%MaxSize;
//	}
	for (;s.front % MaxSize !=s.rear;s.front=(s.front +1)%MaxSize){
		printf("%d ",s.data[s.front]);
	}
}
int main(){
	SqQueue q;
	init(&q);
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,555);
	enqueue(&q,666);
	printqueue(q);
	
	printf("\n");
	int i;
	dequeue(&q,&i);
	dequeue(&q,&i);
	
	enqueue(&q,7);
	enqueue(&q,8);
	
	printqueue(q);
	
	
}
