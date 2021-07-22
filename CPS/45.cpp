//#45] 공주 구하기 (요세푸스-vector만 사용) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	freopen("input.txt","rt",stdin);
	int n, k, pos=0, cnt=0, breakpoint=0; 
	scanf("%d %d", &n, &k); //8, 3
	vector<int> check(n+1);
	while(1){
		pos++;
		if(pos>n){ //n보다 커지면 다시 1로 돌아감 
			pos=1;
		}
		if(check[pos]==0){
			cnt++; //k번째인지 count
			if(cnt==k){
				check[pos]=1;
				breakpoint++; //n-1이 되면 break해야 함 
				cnt=0; //다시 0부터 k까지 count 
			}
		}
		
		if(breakpoint==n-1){
			break;
		}
	}
	
	for(int i=1; i<=n; i++){
		if(check[i]==0){
			printf("%d", i);
		}
	}

	return 0;
}
