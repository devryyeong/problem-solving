#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//재귀 가지(?)를 뻗어나가다가 최종 목적지에 도착했는지?!(if-else 형태 이용) 
void recursion(int x){
	if(x==0){ //종료지점->더이상 호출하지 않고 함수 종료! 
		return;
	}else{ //STACK 자료구조 사용. 
		recursion(x/2);
		
		printf("%d", x%2);
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	int n;
	scanf("%d", &n); //11
	recursion(n);
	
	return 0;
}
