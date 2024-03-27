#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//��ʼ��������
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

bool InsertNextNode (LNode *p,ElemType e){		//ָ���ڵ������ 
	if(p==NULL)return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->data =e;
	s->next =p->next ;
	p->next =s;
	return true;
}

bool InsertPriorNode(LNode *p,LNode *s){		//ָ���ڵ�ǰ����� 

	if(p==NULL ||s==NULL)return false;
	s->next=p->next ;
	p->next =s;
	ElemType temp=p->data;
	p->data =s->data ;
	s->data =temp;
	return true;
//ǰ���������ԭ�ڵ�󴴽��½ڵ㣬��ԭ�ڵ����ݷŵ��½ڵ��ڣ�ԭ�ڵ����ݸ�Ϊ�������ݣ��Ӷ�ʵ��ǰ�� 
}


//���ҽڵ� (��ͷ�ڵ�)
LNode * GetElem(LinkList L,int i){		//��λ���ң����ص�i��Ԫ�� O(n)
	if(i<1)return NULL;
	int j=1;
	LNode *p=L->next ;//ָ���1���ڵ㣬LΪ��0���ڵ� 
	while (p!=NULL && j<i){
		p=p->next;
		j++;
	}
	return p;
}
LNode * LocateElem(LinkList L,ElemType e){//��ֵ���ң��ҵ�������==e�Ľڵ� O(n) 
	LNode *p=L->next;
	while(p !=NULL &&p->data !=e){
		p=p->next;
	}
	return p;
}


//��λ����� 
bool ListInsert(LinkList L,int i,ElemType e){		//��ͷ�ڵ� 
	if(i<1){
		printf("λ�ô���");
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
bool ListInsert2(LinkList L,int i,ElemType e){		//����ͷ��� 
	if(i<1)return 0;
	if(i==1){
		LNode *s=(LNode *)malloc(sizeof(LNode));
		s->data =e;
		s->next =L;
		L=s;
		return 1;
	}
	LNode *p =GetElem(L,i-1);//��λ���� 
	return InsertNextNode(p,e);//������ 
}


//ɾ�� 
bool ListDelete(LinkList L,int i,ElemType *e){		//��λɾ�������ر�ɾԪ�أ���ͷ�ڵ㣩 
	if(i<1)return false;
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i-1){
		p=p->next ;
		j++;
	}
	if (p==NULL)return false;
	if (p->next ==NULL)return false;//i-1���ڵ���޽ڵ�
	LNode *q=p;
	*e=q->data ;
	p->next =q->next ;
	free(q);
	return true;
}
bool DeleteNode(LNode *p){		//ָ���ڵ�ɾ�� ����ͷ�ڵ㣩 
	if(p==NULL)return false;
	LNode *q=p->next ;
	p->data =p->next->data ;
	p->next =q->next ;
	free(q);
	return true; 

//��1.����ͷָ�룬ѭ����p��ǰ���ڵ�.O(n) 
//��2.��ָ���ڵ�����ݸ�Ϊ��̽ڵ����� ��ָ���ڵ��ָ��ָ���̽ڵ�ĺ�̽ڵ㣬���ͷź�̽ڵ�.O(1)
//�˴��÷�2����ɾ�����һ���ڵ�ʱ����� 
} 


//�������ͷ�ڵ㣩 O(n)
int Length(LinkList L){
	int len=0;
	LNode *p=L;
	while (p->next !=NULL){
		p=p->next;
		len++;
	}
	return len;
}


//��ӡ 
void PrintList(LinkList L){		//��ӡ (��ͷ�ڵ�) 
	L=L->next;//ʹLָ���һ���ڵ� 
	while (L !=NULL ){
		printf("%d ",L->data );
		L=L->next;
	}
}
void PrintList2(LinkList L){	//��ӡ (����ͷ�ڵ㣩
	while (L !=NULL){
		printf("%d ",L->data );
		L=L->next;
	}
}


//���������� 
LinkList List_TailInsert(){		//β�巨���������� (��ͷ�ڵ�)
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
LinkList List_HeadInsert(){		//ͷ�巨 ->���� (��ͷ�ڵ�)
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

LinkList List_TailInsert2(){	//β�巨 (����ͷ�ڵ�)
	LinkList L=NULL;
	int x;
	scanf("%d",&x);
	if (x == 9999)return L;//����ָ��NULL��ͷָ��L 
	
	L=(LNode *)malloc(sizeof(LNode));//ͷָ��ָ���һ���ڵ�
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
LinkList List_HeadInsert2(){	//ͷ�巨 (����ͷ�ڵ�) 
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


//�������� 
LinkList ListInvert(LinkList L){	//(��ͷ�ڵ�)
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
LinkList ListInvert2(LinkList L){	//(����ͷ�ڵ�)
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
