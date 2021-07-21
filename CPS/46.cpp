//#46] 멀티태스킹 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	freopen("input.txt","rt",stdin);
	int n, k, pos=0, cnt=0, sum=0; 
	scanf("%d", &n); //n=3개의 작업 
	vector<int> a(n+1);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]); 
		sum+=a[i];
	}
	scanf("%d", &k); //k=5초 후 정전
	
	if(sum==k){
		printf("-1");
		return 0;
	}
	
	while(1){
		pos++;
		if(pos>n){
			pos=1;
		}
		if(a[pos]!=0){
			a[pos]--;
			cnt++;
		}
		
		if(cnt==k){
			break;
		}	
	} //마지막 작업이 pos
	
	
	while(1){
		pos++;
		if(pos>n){
			pos=1;
		}
		if(a[pos]!=0){
			break;
		}
	}
	printf("%d", pos);

	return 0;
}
