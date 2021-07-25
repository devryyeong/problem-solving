//22114] 창영이와 점프
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, k, answer=0;
	scanf("%d %d", &n, &k); //7,3 
	vector<int> v(n+1);
	
	for(int i=0; i<n-1; i++){
		scanf("%d", &v[i]);
	}


	for(int i=0; i<n-1; i++){
		int tmp=1, jump=1;
		
		for(int j=i; j<n-1; j++){
			//k보다 작고 건널 수 있을 때
			if(v[j]<=k){
				tmp++;
			}else{
				if(jump>0){ //k보다 크지만 jump 할 수 있을 때  
					tmp++;
					jump=0;
				}else{ //jump가 불가능할 경우  
					break;
				} 
			}
		}
		
		//최댓값 비교 
		if(tmp>answer){
			answer=tmp;
		}
	}
	
	
	printf("%d", answer);	
	
	return 0;
}
