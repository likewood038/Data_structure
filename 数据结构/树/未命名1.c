#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "queue.c"

typedef int elemtype;
typedef struct BiTNode{
	elemtype data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct ThreadNode{		//�������������
	elemtype data;
	struct ThreadNode *lchild,*rchild;
	int ltag ,rtag;		//����������־
}ThreadNode,*ThreadTree;



void visit(BiTree T){
	printf("%d ",T->data);
}

void PreOrder(BiTree T){		//������� S(n)=O(h+1)
	if (T !=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree T){			//������� 
	if (T !=NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
void PostOrder(BiTree T){		//�������� 
	if (T !=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
int treeDepth(BiTree T){		//���������(�����㷨�ı���) 
	if(T==NULL)return 0;
	else{
		int l=treeDepth(T->lchild);
		int r=treeDepth(T->rchild);
		return l>r? l+1:r+1;	//�������=Max(���������,���������)+1 
	}
}

void LevelOrder(BiTree T){		//�������
	LinkQueue Q;
	InitQueue(&Q);
	
	BiTNode *p;
	EnQueue(&Q,T);	//���ڵ����

	while(!IsEmpty(Q)){
		p=(BiTNode *)DeQueue(&Q);
		visit(p);
		if(p->lchild !=NULL)EnQueue(&Q,p->lchild);
		if(p->rchild !=NULL)EnQueue(&Q,p->rchild);
	}
}

void AddNode(BiTree *parent,elemtype x){	//��ӽڵ� 
	(*parent)=(BiTNode *)malloc(sizeof(BiTNode));
	(*parent)->data=x;
	(*parent)->lchild=NULL;
	(*parent)->rchild=NULL;
} 

int main(){
	BiTree t;
	AddNode(&t,1);
	AddNode(&(t->lchild),2);
	AddNode(&(t->rchild),3);
	AddNode(&(t->lchild->lchild),114);
	AddNode(&(t->lchild->rchild),4);

	LevelOrder(t);
	return 0;
}
