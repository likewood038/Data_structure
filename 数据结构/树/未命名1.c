#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "queue.c"

typedef int elemtype;
typedef struct BiTNode{
	elemtype data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct ThreadNode{		//线索二叉树结点
	elemtype data;
	struct ThreadNode *lchild,*rchild;
	int ltag ,rtag;		//左、右线索标志
}ThreadNode,*ThreadTree;



void visit(BiTree T){
	printf("%d ",T->data);
}

void PreOrder(BiTree T){		//先序遍历 S(n)=O(h+1)
	if (T !=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree T){			//中序遍历 
	if (T !=NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
void PostOrder(BiTree T){		//后续遍历 
	if (T !=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
int treeDepth(BiTree T){		//求树的深度(遍历算法的变种) 
	if(T==NULL)return 0;
	else{
		int l=treeDepth(T->lchild);
		int r=treeDepth(T->rchild);
		return l>r? l+1:r+1;	//树的深度=Max(左子树深度,右子树深度)+1 
	}
}

void LevelOrder(BiTree T){		//层序遍历
	LinkQueue Q;
	InitQueue(&Q);
	
	BiTNode *p;
	EnQueue(&Q,T);	//根节点入队

	while(!IsEmpty(Q)){
		p=(BiTNode *)DeQueue(&Q);
		visit(p);
		if(p->lchild !=NULL)EnQueue(&Q,p->lchild);
		if(p->rchild !=NULL)EnQueue(&Q,p->rchild);
	}
}

void AddNode(BiTree *parent,elemtype x){	//添加节点 
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
