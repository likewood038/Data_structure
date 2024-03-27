#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#define MAXLEN 255
typedef struct{
	char ch[MAXLEN];
	int length;
}sstring;//定长的顺序存储 

typedef struct{
	char *ch;
	int length;
}hstring;//动态数组实现 堆分配存储 
//hstring s;s.ch=(char *)malloc(sizeof(char));

typedef struct stringnode{
	char ch[4];
	struct stringnode *next;
}stringnode,*string;

//赋值
bool StrAssign(sstring *t,char ch[]){
	printf("%d\n",sizeof(ch));
	
}
//复制
//判空
//串长
int StrLength(sstring s){
	return s.length;
}
//清空
//销毁
//串联接
//求子串
bool SubString(sstring *sub,sstring s,int pos,int len){
	if(pos +len-1 >s.length)return false;//子串范围越界
	int i;
	for (i=pos;i<pos+len;i++) {
		sub->ch [i-pos+1]=s.ch[i];
	}
	sub->length =len;
	return true;
}

//比较操作 若s>t,则返回值>0 
int StrCompare(sstring s,sstring t){
	int i;
	for(i=1;i<=s.length && i<t.length;i++){
		if(s.ch[i] !=t.ch[i])return s.ch[i] - t.ch[i];
	}
	return s.length-t.length; 
}
//定位操作
int stringindex(sstring s,sstring t){	//朴素模式匹配算法 
	int i=1,n=StrLength(s),m=StrLength(t);
	sstring sub;
	while(i<n-m+1){
		SubString(&sub,s,i,m);
		if(StrCompare(sub,t) !=0) ++i;
		else return i;
	}
	return 0;
	
}

bool test(char ch[]){
	printf("%d\n",sizeof(ch));
}

int main(){
	test("123hello!");
	
	char ch[]="123hello!";
	printf("%d\n",sizeof(ch));

	return 0;
}
