#include <stdio.h>
#include <stdlib.h>

#define Max_Size 10
typedef struct{		//SqList静态数组顺序表 
	int data[Max_Size];		//静态数组 
	int length;		//顺序表当前长度 
}SqList;


//初始化表
void InitList(SqList *L){	
	L->length =0;
}


//销毁

//插入操作
int ListInsert(SqList *p,int i,int x){
		if(i<1 || i>p->length +1){		//非法插入位置 
		printf("非法插入位置");
		return 0;	
	}	
	if(p->length >=Max_Size){		//数组溢出 
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
int ListDelete(SqList *L,int i,int *e){
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
int LocateElem(SqList L,int e){
	int i;
	for(i=0;i<L.length;i++){
		if(L.data[i]==e)return i+1;
	}
	return 0;
}

//按位查找 
int GetElem(SqList L,int i){
	return L.data [i-1];
}
//求表长
//输出操作
void ListPrint(SqList l){
	if (l.length <1)printf("无有效数据\n");
	
	int i;
	for(i=0;i<l.length;i++ ){
		printf("%d",l.data [i]);
		if (i==l.length -1)printf("\n");
		else printf(" ");
	}
}
//判空操作 


//main
int main(){
	SqList l;
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
	printf("%d",l.length);
		
}


