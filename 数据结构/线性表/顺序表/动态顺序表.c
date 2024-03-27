#include <stdio.h>
#include <stdlib.h>

#define InitSize 10		//顺序表初始长度 
typedef struct{		//SeqList 动态数组顺序表 
	int *data;
	int MaxSize; 
	int length;
}SeqList;

//增加动态数组的长度
void IncreaseSize(SeqList *L,int len){
	int *p=L->data;
	L->data=(int *)malloc(sizeof(int)*(L->length +len));//指向新区域 大小为原大小加新大小 
	
	int i;
	for (i=0;i<L->length ;i++){
		L->data [i]=p[i];
	}
	L->MaxSize =L->MaxSize +len;
	free(p);
}
//初始化表
void InitList(SeqList *L){
	L->data =(int *)malloc(sizeof(int)*InitSize); 
	L->length =0;
	L->MaxSize =InitSize;
}

//销毁

//插入操作
int ListInsert(SeqList *p,int i,int x){
	if(i<1 || i>p->length +1){		//非法插入位置 
		printf("非法插入位置");
		return 0;	
	}	
	if(p->length >=p->MaxSize){		//数组溢出 
		printf("数组溢出");
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

//删除操作 
int ListDelete(SeqList *L,int i,int *e){
	if(i<1 || i>L->length ){
		printf("非法位置");
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

//按值查找
int LocateElem(SeqList L,int e){
	int i;
	for(i=0;i<L.length;i++){
		if(L.data[i]==e)return i+1;
	}
	return 0;
}
//按位查找
int GetElem(SeqList L,int i){
	return L.data [i-1];
}
//求表长
//输出操作
void ListPrint(SeqList l){
	if (l.length <1)printf("无有效数据\n");
	int i;
	for(i=0;i<l.length;i++ ){
		printf("%d ",l.data [i]);
		if (i==l.length -1)printf("\n");
		else printf(" ");
	}
}
//判空操作 

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


