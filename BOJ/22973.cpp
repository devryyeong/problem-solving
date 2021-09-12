//22973] 점프 숨바꼭질
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt","rt", stdin);
	int jump=1, cnt=0;
	long long hw=1, k;
	scanf("%lld", &k);
	
	//k가 음수라면 
	if(k<0){
		k=-k;
	}else if(k==0){ //현욱의 위치=현욱이 형의 위치 
		printf("0");
		return 0;
	}

	//k가 짝수라면 도달할 수 있는 방법이 없음. 
	if(k%2==0){
		printf("-1");
		return 0;
	}
	
	while(k>0){
		hw*=(hw*2)-1;
		k/=2;
		cnt++;
	}

	printf("%d", cnt);
	return 0;
}
