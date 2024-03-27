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
//1.���
int length(List PtrL){
	List p=PtrL;
	int j=0;
	while (p !=NULL){
		p=p->next;
		j++;
	}
	return j;
}


//2.����
List FindKth(int K,List PtrL){		//����Ų��� 
	List p =PtrL;
	int i=1;
	while (p !=NULL &&i<K){
		p=p->next;
		i++;
	}
	if (i==K)return p;
	else return NULL;
}
List Find(ElementType x,List PtrL){		//��ֵ���� 
	List p=PtrL;
	while (p !=NULL && p->data !=x){
		p=p->next;
	}
	return p;
}


//3.���� �ڵ�i��λ�ò���һ��ֵΪx���½ڵ� 
List Insert(ElementType x,int i,List PtrL){
//(1)�ȹ���һ���½�㣬��sָ��;
//(2)���ҵ�����ĵ�i-1����㣬��pָ��;
//(3)Ȼ���޸�ָ�룬������(p֮������½����s)
	List p,s;
	if(i==1){
		s=(List)malloc(sizeof(struct LNode));
		s->data =x;
		s->next =PtrL;//ͷָ�뷢���仯 
		return s;
	}
	p=FindKth(i-1,PtrL);
	if (p==NULL){
		printf("����i����");
		return NULL;
	}else{
		s=(List)malloc(sizeof(struct LNode));
		s->data =x;
		s->next =p->next;
		p->next =s;
		return PtrL;
	}
}

//4.ɾ��
List Delete(int i,List PtrL){
	List p,s;
	if (i==1){
		s=PtrL;
		if (PtrL !=NULL) PtrL=PtrL->next;   //����s��PtrL���� 
		else return NULL;
		free(s);
		return PtrL;
	}
	p=FindKth(i-1,PtrL);//�ҵ�i-1��
	if (p==NULL || p->next ==NULL){
		printf("�ڵ㲻����");
		return NULL;
	}else{
		s=p->next;
		p->next =s->next;
		free(s);
		return PtrL;
	}
//(1�����ҵ�����ĵ�i-1����㣬��pָ��;
//(2������ָ��sָ��Ҫ��ɾ���Ľ�㣨p����һ�����)
//(3��Ȼ���޸�ָ�룬ɾ��s��ָ���;
//(4) ����ͷ�s��ָ���Ŀռ䡣	
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
