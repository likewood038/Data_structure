

#define SIZE 13
int UFSets[SIZE];	//����Ԫ������ 

void Inital(int s[]){
	int i;
	for (i=0;i<SIZE;i++)
		s[i]=-1;		//������Ϊ-1 
}

int Find(int s[],int x){	//�� ���ڵ� 
	while (s[x]>=0)
		s=s[x];
	return x;
}

void Union(int s[],int root1,int root2){	//�������� 
	if(root1==root2)return;
	
	
	s[root2]=root1;		//��root2��-1��Ϊroot1�ĵ�ַ 
}
