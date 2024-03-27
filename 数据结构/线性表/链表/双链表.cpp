#include <stdio.h>
#include <stdlib.h> 

typedef int ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;

bool InitList(DLinkList *L){	//带头节点 
	(*L)=(DNode *)malloc(sizeof(DNode));
	if ((*L)==NULL)return false;//内存不足分配失败 
	(*L)->prior=NULL;
	(*L)->next=NULL;
	return true;
}

bool InsetNextDNode(DNode *p,DNode *s){	//在p后插入s 
	s->next =p->next ;
	s->prior =p;
	p->next =s;
	if (s->next !=NULL)s->next ->prior=s;//当插在表尾时会出错 
	
}
bool DeleteNextDNode(DNode *p){
	if (p==NULL)return false;
	DNode *q=p->next ;
	if (q==NULL)return false;
	p->next =q->next;
	if (q->next !=NULL)q->next->prior =p;
	free(q);
	return true;
}
void DestoryList(DLinkList L){
	while(L->next !=NULL){
		DeleteNextDNode(L);
	}
	free(L);
	L=NULL;
}
int main(){
	
}
