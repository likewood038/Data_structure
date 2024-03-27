#include <stdio.h>
#include <stdbool.h>


#define MaxSize 10
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;//栈顶指针->数组下标 
}SqStack; 

typedef struct{
	ElemType data[MaxSize];
	int top0;
	int top1;
}ShStack; 

//初始化
void Init(SqStack *s){
	s->top =-1;
}
void Init2(ShStack s){
	s.top0 =-1;
	s.top1 =MaxSize;
}
//销毁栈

//进栈，若栈S未满，则将x加入使之成为新栈顶 
bool push(SqStack *s,ElemType x){
	if ((*s).top ==MaxSize-1)return false;
	(*s).top +=1;
	(*s).data [(*s).top]=x;
	return true;
}

//出栈，若栈S非空，则弹出栈顶元素，并用x返回
bool pop(SqStack *s,ElemType *x){
	if((*s).top ==-1)return false;
	*x =(*s).data [(*s).top--];
	return false;
}

//读栈顶元素，若非空，则用x返回栈顶元素 
bool gettop(SqStack s,ElemType *x){
	if(s.top ==-1)return false;
	*x =s.data [s.top];
	return true;
}

//判空 
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

