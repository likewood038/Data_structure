#include <stdio.h>
typedef struct BSTNode{
	int key;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//查找成功返回结点指针，失败返回null 
BSTNode *BST_Search(BSTree T,int key){
	while(T !=NULL &&key !=T->key){
		if(key<T->key) T=T->lchild;
		else T=T->rchild;
	}
}
//递归实现 
BSTNode *BSTSearch(BSTree T,int key){
	if(T==NULL)return NULL;	//失败
	if(key ==T->key)return T;
	
	if(key<T->key )return BSTSearch(T->lchild,key);
	else return BSTSearch(T->rchild,key);
}

//插入节点
int BST_Insert(BSTree *T,int k){
	if(T==NULL){		//原树为空，新插入根节点 
		(*T)=(BSTree)malloc(sizeof(BSTNode));
		T->key =k;
		T->lchild =T->rchild =NULL;
		return 1;
	}else if(k==T->key)return 0;	//存在相同关键字节点，插入失败
	else if (k<T->key)return BST_Insert(T->lchild,k);
	else return BST_Insert(T->rchild,k); 
}

//按str[]中关键字序列建立二叉排序树
void Creat_BST 



int main(){
	
	return 0;
}
