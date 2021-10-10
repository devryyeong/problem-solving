//1057] 토너먼트
//라운드가 올라갈 때마다 자신의 번호는 (자신의 번호+1)/2
//따라서 두사람 모두 2로 나누었을 때 똑같은 위치에 있다면 해당 라운드에서 경쟁 
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, kim, lim, round=0;
	scanf("%d %d %d", &n, &kim, &lim);
	
	while(kim!=lim){
		round++;
		
		kim=(kim+1)/2;
		lim=(lim+1)/2;
			
	}
	printf("%d", round);

	return 0;
}

