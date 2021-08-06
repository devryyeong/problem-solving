//20363] 당근 키우기 
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int res=0;
	int x, y;
	
	scanf("%d %d", &x, &y);
	
	res+=x;
	res+=y;
	if(x>y){
		res+=y/10;	
	}else{
		res+=x/10;
	}
	
	printf("%d", res);
	return 0;
}

