#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



#define MaxVertexNum 20
typedef int VertexType;	//������������ 
typedef bool EdgeType;		//Ȩֵ�������� 

//�ڽӾ��� MGraph
typedef struct{
	VertexType Vex[MaxVertexNum];				//����� 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];	//�ڽӾ��� 
	int vexnum,arcnum;							//ͼ��ǰ�������ͻ��� 
}MGraph;

//�ڽӱ� ALGraph
typedef struct ArcNode{		//�߱�ڵ� 
	int adjvex;				//�߱�ڵ�ļ�¼��λ�� 
	struct ArcNode *next;	//�߱�ڵ��¼��ָ�� 
	//infotype info			//��Ȩֵ 
}ArcNode;
typedef struct VNode{		//�����ڵ� 
	VertexType data;		//�������� 
	ArcNode *first;			//ָ���һ���߱�ڵ�
}VNode,AdjList[MaxVertexNum];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;


//Adjacent(G,x,y)�ж�ͼG�Ƿ����<x,y>
int a(int x,int y){
	return x+y;
}
double a(double x,double y){
	return x+y;
}

//Neighbors(G,x)
//InsertVertex(G,x)
//DeleteVertex(G,x) 
//AddEdge(G,x,y)
//RemoveEdge(G,x,y)
//FirstNeighbor(G,x)
//NextNeighbor(G,x,y)
//Get_edge_value(G,x,y)
//Set_edge_value(G,x,y,v)

int main(){
	int x=1;
	int y=2;
	int z=a(x,y);
	printf("%d",z);
}



/*


bool visited[max_vertex_num];	//���ʱ������ 

void BFSTraverse(Graph G){
	for (i=0;i<G.vexnum;++i)visited[i]=FALSE;
	InitQueue(Q);
	for(i=0;i<G.vexnum;++i)
		if(!visited[i])BFS(G,i);
	
}
void BFS(Graph G,int v){	//�Ӷ���v������������ȱ���ͼ G 
	visit(v);
	visit[v]=TRUE;
	Enqueue(Q,v);	//����v�����Q 
	while (! isEmpty(Q)){
		DeQueue(Q,v);	//����v����
		for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
			if(!visited[w]){
				visit(w);
				visited[w]=TRUE;
				EnQueue(Q,w);
			} 
	}
}


void DFSTraverse(Graph G){
	for (v=0;v<G.vexnum;++v)visited[v]=FALSE;
	
	for(v=0;v<G.vexnum;++v)
		if(!visited[v])DFS(G,v);
}
void DFS(Graph G,int v){
	visit(v);
	visited[v]=TRUE;
	for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
		if(!visited[w]){
			DFS(G,w);
		}
}


//BFS�󶥵�u��������������·��->��Ȩͼ 
void BFS_MIN_Distance(Graph G,int u){
	//d[i]��ʾ��u��i�ڵ�����·��
	for (i=0;i<G.vexnum;++i){
		d[i]=��//��ʼ��·������ 
		path[i]=-1	
	}
	d[u]=0;
	visited[u]=TRUE;
	EnQueue(Q,u);
	while(!isEmpty(Q)){
		DeQueue(Q,u)
		for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w)){
			if(!visited[w]){		//wΪu��δ���ʵ��ڽӶ��� 
				d[w]=d[u]+1;		//·�����ȼ�1 
				path[w]=u;			//���·����u��w (ֱ��ǰ��)���ڱ������������� 
				visited[w]=TRUE;	
				EnQueue(Q,w);		//����w��� 
			}
		}
	} 
} 

//Dijkstra�Ͻ�˹�����㷨




*/













 


