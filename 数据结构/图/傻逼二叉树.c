#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



#define MaxVertexNum 20
typedef int VertexType;	//顶点数据类型 
typedef bool EdgeType;		//权值数据类型 

//邻接矩阵 MGraph
typedef struct{
	VertexType Vex[MaxVertexNum];				//顶点表 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵 
	int vexnum,arcnum;							//图当前顶点数和弧数 
}MGraph;

//邻接表 ALGraph
typedef struct ArcNode{		//边表节点 
	int adjvex;				//边表节点的记录的位置 
	struct ArcNode *next;	//边表节点记录的指针 
	//infotype info			//边权值 
}ArcNode;
typedef struct VNode{		//顶点表节点 
	VertexType data;		//顶点数据 
	ArcNode *first;			//指向第一个边表节点
}VNode,AdjList[MaxVertexNum];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;


//Adjacent(G,x,y)判断图G是否存在<x,y>
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


bool visited[max_vertex_num];	//访问标记数组 

void BFSTraverse(Graph G){
	for (i=0;i<G.vexnum;++i)visited[i]=FALSE;
	InitQueue(Q);
	for(i=0;i<G.vexnum;++i)
		if(!visited[i])BFS(G,i);
	
}
void BFS(Graph G,int v){	//从顶点v出发，广度优先遍历图 G 
	visit(v);
	visit[v]=TRUE;
	Enqueue(Q,v);	//顶点v入队列Q 
	while (! isEmpty(Q)){
		DeQueue(Q,v);	//顶点v出列
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


//BFS求顶点u到其他顶点的最短路径->无权图 
void BFS_MIN_Distance(Graph G,int u){
	//d[i]表示从u到i节点的最短路径
	for (i=0;i<G.vexnum;++i){
		d[i]=∞//初始化路径长度 
		path[i]=-1	
	}
	d[u]=0;
	visited[u]=TRUE;
	EnQueue(Q,u);
	while(!isEmpty(Q)){
		DeQueue(Q,u)
		for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w)){
			if(!visited[w]){		//w为u尚未访问的邻接顶点 
				d[w]=d[u]+1;		//路径长度加1 
				path[w]=u;			//最短路径从u到w (直接前驱)用于保存广度优先序列 
				visited[w]=TRUE;	
				EnQueue(Q,w);		//顶点w入队 
			}
		}
	} 
} 

//Dijkstra迪杰斯特拉算法




*/













 


