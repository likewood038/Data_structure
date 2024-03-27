#include <stdio.h>
#include <stdlib.h>

#define InitSize 10		//˳����ʼ���� 
typedef struct{		//SeqList ��̬����˳��� 
	int *data;
	int MaxSize; 
	int length;
}SeqList;

//���Ӷ�̬����ĳ���
void IncreaseSize(SeqList *L,int len){
	int *p=L->data;
	L->data=(int *)malloc(sizeof(int)*(L->length +len));//ָ�������� ��СΪԭ��С���´�С 
	
	int i;
	for (i=0;i<L->length ;i++){
		L->data [i]=p[i];
	}
	L->MaxSize =L->MaxSize +len;
	free(p);
}
//��ʼ����
void InitList(SeqList *L){
	L->data =(int *)malloc(sizeof(int)*InitSize); 
	L->length =0;
	L->MaxSize =InitSize;
}

//����

//�������
int ListInsert(SeqList *p,int i,int x){
	if(i<1 || i>p->length +1){		//�Ƿ�����λ�� 
		printf("�Ƿ�����λ��");
		return 0;	
	}	
	if(p->length >=p->MaxSize){		//������� 
		printf("�������");
		return 0;		
	}
	int j;
	for(j=(p->length);j>=i;j--){
		p->data [j]=p->data [j-1];
	}
	p->data [i-1]=x;
	p->length +=1;
	return 1;
}

//ɾ������ 
int ListDelete(SeqList *L,int i,int *e){
	if(i<1 || i>L->length ){
		printf("�Ƿ�λ��");
		return 0;
	}
	*e = L->data [i-1];
	
	int j;
	for(j=i;j<L->length;j++){
		L->data [j-1]=L->data [j];
	}
	L->length --;
	return 1;
	
}

//��ֵ����
int LocateElem(SeqList L,int e){
	int i;
	for(i=0;i<L.length;i++){
		if(L.data[i]==e)return i+1;
	}
	return 0;
}
//��λ����
int GetElem(SeqList L,int i){
	return L.data [i-1];
}
//���
//�������
void ListPrint(SeqList l){
	if (l.length <1)printf("����Ч����\n");
	int i;
	for(i=0;i<l.length;i++ ){
		printf("%d ",l.data [i]);
		if (i==l.length -1)printf("\n");
		else printf(" ");
	}
}
//�пղ��� 

int main(){
	
	SeqList l;
	InitList (&l);

	int i;
	for(i=1;i<10;i++){
		ListInsert(&l,i,i);
	}
	int e=-1;
	
	ListInsert(&l,2,15);
	
	ListPrint(l);
	ListDelete(&l,2,&e);
	ListPrint(l);
	printf("%d\n",LocateElem(l,9));
	
		
}


