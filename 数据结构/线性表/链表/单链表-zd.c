#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode * List;
typedef int ElementType;

struct LNode{
	ElementType data;
	List next;
};

List Init(List PtrL){
	return NULL;	
}
//1.求表长
int length(List PtrL){
	List p=PtrL;
	int j=0;
	while (p !=NULL){
		p=p->next;
		j++;
	}
	return j;
}


//2.查找
List FindKth(int K,List PtrL){		//按序号查找 
	List p =PtrL;
	int i=1;
	while (p !=NULL &&i<K){
		p=p->next;
		i++;
	}
	if (i==K)return p;
	else return NULL;
}
List Find(ElementType x,List PtrL){		//按值查找 
	List p=PtrL;
	while (p !=NULL && p->data !=x){
		p=p->next;
	}
	return p;
}


//3.插入 在第i个位置插入一个值为x的新节点 
List Insert(ElementType x,int i,List PtrL){
//(1)先构造一个新结点，用s指向;
//(2)再找到链表的第i-1个结点，用p指向;
//(3)然后修改指针，插入结点(p之后插入新结点是s)
	List p,s;
	if(i==1){
		s=(List)malloc(sizeof(struct LNode));
		s->data =x;
		s->next =PtrL;//头指针发生变化 
		return s;
	}
	p=FindKth(i-1,PtrL);
	if (p==NULL){
		printf("参数i错误");
		return NULL;
	}else{
		s=(List)malloc(sizeof(struct LNode));
		s->data =x;
		s->next =p->next;
		p->next =s;
		return PtrL;
	}
}

//4.删除
List Delete(int i,List PtrL){
	List p,s;
	if (i==1){
		s=PtrL;
		if (PtrL !=NULL) PtrL=PtrL->next;   //？？s与PtrL互换 
		else return NULL;
		free(s);
		return PtrL;
	}
	p=FindKth(i-1,PtrL);//找第i-1个
	if (p==NULL || p->next ==NULL){
		printf("节点不存在");
		return NULL;
	}else{
		s=p->next;
		p->next =s->next;
		free(s);
		return PtrL;
	}
//(1）先找到链表的第i-1个结点，用p指向;
//(2）再用指针s指向要被删除的结点（p的下一个结点)
//(3）然后修改指针，删除s所指结点;
//(4) 最后释放s所指结点的空间。	
}

void printlist(List PtrL){
	List s=PtrL;
	while (s !=NULL){
		printf("%d ",s->data);
		s=s->next;
	}
}

 
int main(){
	List l;
	l=Init(l);
	l=Insert(1,1,l);
	l=Insert(2,2,l);
	l=Insert(3,2,l);
	l=Insert(4,2,l);
	printlist(l);
	return 1;
} 
