//42]이분검색(Binary Search)
//시간복잡도: O(logN) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	freopen("input.txt","rt",stdin);
	int n, m, start, mid, end, tmp;
	scanf("%d %d", &n, &m); 
	vector <int> v;
	for(int i=0; i<n; i++){
		//scanf("%d",&v[i]);
        scanf("%d",&tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	start=0;
	end=n-1;
	while(start<=end){
		mid=(start+end)/2;
		if(v[mid]>m){
			end=mid-1;
		}else if(v[mid]<m){
			start=mid+1;
		}else if(v[mid]==m){
			printf("%d", mid+1);
			return 0;
		}
	}
		
	return 0;
}
