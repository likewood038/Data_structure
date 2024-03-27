#include <stdio.h>
#include <time.h> 

int f(int n[],int len){
	int i;
	int thissum=0;
	int sum=0;
	for(i=0;i<len;i++){
		thissum +=n[i];
		if (thissum >sum){
			sum=thissum;
				
		}else if(thissum<0){
			thissum=0;
		}
		
	}
	return sum;
	
}





int main(void){
	int a[8]={4,-3,5,-2,-1,2,6,-2};
	printf("%d",f(a,8));
	return 0;
}

