#include <stdio.h>
#include <stdbool.h>


typedef int ElemType;
typedef struct Node{
	ElemType data[MaxSize];
	struct Node *next;
}*LiStack; 

//推荐不带头节点 

//创 增 删 查 ，判空 判满 
