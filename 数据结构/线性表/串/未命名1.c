#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#define MAXLEN 255
typedef struct{
	char ch[MAXLEN];
	int length;
}sstring;//������˳��洢 

typedef struct{
	char *ch;
	int length;
}hstring;//��̬����ʵ�� �ѷ���洢 
//hstring s;s.ch=(char *)malloc(sizeof(char));

typedef struct stringnode{
	char ch[4];
	struct stringnode *next;
}stringnode,*string;

//��ֵ
bool StrAssign(sstring *t,char ch[]){
	printf("%d\n",sizeof(ch));
	
}
//����
//�п�
//����
int StrLength(sstring s){
	return s.length;
}
//���
//����
//������
//���Ӵ�
bool SubString(sstring *sub,sstring s,int pos,int len){
	if(pos +len-1 >s.length)return false;//�Ӵ���ΧԽ��
	int i;
	for (i=pos;i<pos+len;i++) {
		sub->ch [i-pos+1]=s.ch[i];
	}
	sub->length =len;
	return true;
}

//�Ƚϲ��� ��s>t,�򷵻�ֵ>0 
int StrCompare(sstring s,sstring t){
	int i;
	for(i=1;i<=s.length && i<t.length;i++){
		if(s.ch[i] !=t.ch[i])return s.ch[i] - t.ch[i];
	}
	return s.length-t.length; 
}
//��λ����
int stringindex(sstring s,sstring t){	//����ģʽƥ���㷨 
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
