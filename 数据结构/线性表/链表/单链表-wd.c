#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//初始化单链表
bool InitList(LinkList *L){
	(*L)=(LNode *)malloc(sizeof(LNode));
	if(L==NULL)return false;
	(*L)->next =NULL;
	return true;
}

bool InitList2(LinkList *L){
	(*L)=NULL;
	return true;
}

bool InsertNextNode (LNode *p,ElemType e){		//指定节点后插操作 
	if(p==NULL)return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data =e;
	s->next =p->next ;
	p->next =s;
	return true;
}

bool InsertPriorNode(LNode *p,LNode *s){		//指定节点前插操作 

	if(p==NULL ||s==NULL)return false;
	s->next=p->next ;
	p->next =s;
	ElemType temp=p->data;
	p->data =s->data ;
	s->data =temp;
	return true;
//前插操作：在原节点后创建新节点，将原节点内容放到新节点内，原节点内容改为的新内容，从而实现前插 
}


//查找节点 (带头节点)
LNode * GetElem(LinkList L,int i){		//按位查找，返回第i个元素 O(n)
	if(i<1)return NULL;
	int j=1;
	LNode *p=L->next ;//指向第1个节点，L为第0个节点 
	while (p!=NULL && j<i){
		p=p->next;
		j++;
	}
	return p;
}
LNode * LocateElem(LinkList L,ElemType e){//按值查找，找到数据域==e的节点 O(n) 
	LNode *p=L->next;
	while(p !=NULL &&p->data !=e){
		p=p->next;
	}
	return p;
}


//按位序插入 
bool ListInsert(LinkList L,int i,ElemType e){		//带头节点 
	if(i<1){
		printf("位置错误");
		return false;	
	}
	
	//LinkList p=L;
	int j=0;
	while(L !=NULL && j<i-1){
		L=L->next;
		j++;
	} 
	if(L==NULL)return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data =e;
	s->next =L->next;
	L->next =s;
	return true;
}
bool ListInsert2(LinkList L,int i,ElemType e){		//不带头结点 
	if(i<1)return 0;
	if(i==1){
		LNode *s=(LNode *)malloc(sizeof(LNode));
		s->data =e;
		s->next =L;
		L=s;
		return 1;
	}
	LNode *p =GetElem(L,i-1);//按位查找 
	return InsertNextNode(p,e);//后插操作 
}


//删除 
bool ListDelete(LinkList L,int i,ElemType *e){		//按位删除并返回被删元素（带头节点） 
	if(i<1)return false;
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i-1){
		p=p->next ;
		j++;
	}
	if (p==NULL)return false;
	if (p->next ==NULL)return false;//i-1个节点后无节点
	LNode *q=p;
	*e=q->data ;
	p->next =q->next ;
	free(q);
	return true;
}
bool DeleteNode(LNode *p){		//指定节点删除 （带头节点） 
	if(p==NULL)return false;
	LNode *q=p->next ;
	p->data =p->next->data ;
	p->next =q->next ;
	free(q);
	return true; 

//法1.传入头指针，循环找p的前驱节点.O(n) 
//法2.将指定节点的内容改为后继节点内容 ，指定节点的指针指向后继节点的后继节点，并释放后继节点.O(1)
//此处用法2，在删除最后一个节点时会出错 
} 


//求表长（带头节点） O(n)
int Length(LinkList L){
	int len=0;
	LNode *p=L;
	while (p->next !=NULL){
		p=p->next;
		len++;
	}
	return len;
}


//打印 
void PrintList(LinkList L){		//打印 (带头节点) 
	L=L->next;//使L指向第一个节点 
	while (L !=NULL ){
		printf("%d ",L->data );
		L=L->next;
	}
}
void PrintList2(LinkList L){	//打印 (不带头节点）
	while (L !=NULL){
		printf("%d ",L->data );
		L=L->next;
	}
}


//建立单链表 
LinkList List_TailInsert(){		//尾插法建立单链表 (带头节点)
	int x;
	LinkList L=(LinkList)malloc(sizeof(LNode));
	LNode *s;
	LNode *r=L;
	scanf("%d",&x);
	while (x!=9999){
		s=(LNode *)malloc(sizeof(LNode));
		s->data =x;
		r->next =s;
		r=s;
		scanf("%d",&x);
	}
	r->next =NULL;
	return L ;
	
}
LinkList List_HeadInsert(){		//头插法 ->逆序 (带头节点)
	LNode *s;
	int x;
	LinkList L=(LNode *)malloc(sizeof(LNode));
	L->next =NULL;
	scanf("%d",&x);
	while (x !=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data =x;
		s->next =L->next;
		L->next =s;
		
		scanf("%d",&x);
	}
	
	return L;
} 

LinkList List_TailInsert2(){	//尾插法 (不带头节点)
	LinkList L=NULL;
	int x;
	scanf("%d",&x);
	if (x == 9999)return L;//返回指向NULL的头指针L 
	
	L=(LNode *)malloc(sizeof(LNode));//头指针指向第一个节点
	L->data =x;
	LinkList s=L;
	LinkList r=L;
	
	scanf("%d",&x);
	while (x !=9999){
		
		s=(LNode *)malloc(sizeof(LNode));
		s->data =x;
		r->next =s;
		r=s;
		scanf("%d",&x);
	}
	r->next =NULL;
	return L;
} 
LinkList List_HeadInsert2(){	//头插法 (不带头节点) 
	LinkList L= NULL;
	int x;
	scanf("%d",&x);
	if (x== 9999)return L;
	L=(LNode *)malloc(sizeof(LNode));
	L->data =x;
	L->next =NULL;
	
	LinkList s=L;
	scanf("%d",&x);
	while (x !=9999){
		L=(LNode *)malloc(sizeof(LNode));
		L->data =x;
		L->next =s;
		s=L;
		scanf("%d",&x);
	}
	
	return L;
}


//倒序链表 
LinkList ListInvert(LinkList L){	//(带头节点)
	LinkList s=(LNode *)malloc(sizeof(LNode));
	s->next =NULL;
	
	L=L->next;
	while (L !=NULL){
		LinkList r=(LNode*)malloc(sizeof(LNode));
		r->data =L->data;
		r->next =s->next;
		s->next =r;
		L=L->next;	
	}
	
	return s;
}
LinkList ListInvert2(LinkList L){	//(不带头节点)
	LinkList s=NULL;
	
	while (L !=NULL){
		LinkList r=(LNode *)malloc(sizeof(LNode));
		r->data =L->data;
		r->next =s;
		s=r;
		L=L->next;
		
	}
	return s;
}


int main(){
	LinkList l;
	l=List_TailInsert2();
	l=ListInvert2(l);
	PrintList2(l);
	return 0;
}
