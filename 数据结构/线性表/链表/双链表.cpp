#include <stdio.h>
#include <stdlib.h> 

typedef int ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;

bool InitList(DLinkList *L){	//��ͷ�ڵ� 
	(*L)=(DNode *)malloc(sizeof(DNode));
	if ((*L)==NULL)return false;//�ڴ治�����ʧ�� 
	(*L)->prior=NULL;
	(*L)->next=NULL;
	return true;
}

bool InsetNextDNode(DNode *p,DNode *s){	//��p�����s 
	s->next =p->next ;
	s->prior =p;
	p->next =s;
	if (s->next !=NULL)s->next ->prior=s;//�����ڱ�βʱ����� 
	
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
