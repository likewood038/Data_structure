

#define SIZE 13
int UFSets[SIZE];	//集合元素数组 

void Inital(int s[]){
	int i;
	for (i=0;i<SIZE;i++)
		s[i]=-1;		//各项设为-1 
}

int Find(int s[],int x){	//查 根节点 
	while (s[x]>=0)
		s=s[x];
	return x;
}

void Union(int s[],int root1,int root2){	//将两个根 
	if(root1==root2)return;
	
	
	s[root2]=root1;		//将root2从-1改为root1的地址 
}
