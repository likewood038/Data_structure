#include <stdio.h>
#include <stdbool.h>


#define MaxSize 10
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;//ջ��ָ��->�����±� 
}SqStack; 

typedef struct{
	ElemType data[MaxSize];
	int top0;
	int top1;
}ShStack; 

//��ʼ��
void Init(SqStack *s){
	s->top =-1;
}
void Init2(ShStack s){
	s.top0 =-1;
	s.top1 =MaxSize;
}
//����ջ

//��ջ����ջSδ������x����ʹ֮��Ϊ��ջ�� 
bool push(SqStack *s,ElemType x){
	if ((*s).top ==MaxSize-1)return false;
	(*s).top +=1;
	(*s).data [(*s).top]=x;
	return true;
}

//��ջ����ջS�ǿգ��򵯳�ջ��Ԫ�أ�����x����
bool pop(SqStack *s,ElemType *x){
	if((*s).top ==-1)return false;
	*x =(*s).data [(*s).top--];
	return false;
}

//��ջ��Ԫ�أ����ǿգ�����x����ջ��Ԫ�� 
bool gettop(SqStack s,ElemType *x){
	if(s.top ==-1)return false;
	*x =s.data [s.top];
	return true;
}

//�п� 
bool empty(SqStack s){
	if (s.top ==0)return true;
	return false;
}

void printstack(SqStack s){
	int x;
	for (x=s.top;x>-1;x--){
		printf("%d ",s.data [x]);
		}
}


int main (){
	int x;
	SqStack s;
	Init(&s);
	push(&s,12);
	push(&s,13);
	push(&s,16);
	printstack(s);
	pop(&s,&x);
	printstack(s);
	
}

