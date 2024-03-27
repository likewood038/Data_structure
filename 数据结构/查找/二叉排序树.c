#include <stdio.h>
typedef struct BSTNode{
	int key;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//���ҳɹ����ؽ��ָ�룬ʧ�ܷ���null 
BSTNode *BST_Search(BSTree T,int key){
	while(T !=NULL &&key !=T->key){
		if(key<T->key) T=T->lchild;
		else T=T->rchild;
	}
}
//�ݹ�ʵ�� 
BSTNode *BSTSearch(BSTree T,int key){
	if(T==NULL)return NULL;	//ʧ��
	if(key ==T->key)return T;
	
	if(key<T->key )return BSTSearch(T->lchild,key);
	else return BSTSearch(T->rchild,key);
}

//����ڵ�
int BST_Insert(BSTree *T,int k){
	if(T==NULL){		//ԭ��Ϊ�գ��²�����ڵ� 
		(*T)=(BSTree)malloc(sizeof(BSTNode));
		T->key =k;
		T->lchild =T->rchild =NULL;
		return 1;
	}else if(k==T->key)return 0;	//������ͬ�ؼ��ֽڵ㣬����ʧ��
	else if (k<T->key)return BST_Insert(T->lchild,k);
	else return BST_Insert(T->rchild,k); 
}

//��str[]�йؼ������н�������������
void Creat_BST 



int main(){
	
	return 0;
}
