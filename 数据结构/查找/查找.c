

//ÕÛ°ë²éÕÒ ->ÓÐÐòË³Ðò±í 
int Binary_Search(SSTable L,ElemType key){
	int low=0,high=L.TableLen-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(l.elem[mid]==key) return mid;
		else if (L.elem[mid]>key) high = mid-1;
		else low = mid+1;
	}
	return -1;
	
}

