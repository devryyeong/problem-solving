//22114] 창영이와 점프
//입력으로 주어지는 수와 출력해야 하는 정답이 매우 크기 때문에 
//64비트 자료형(long long, %lld로 출력) 사용.
#include <iostream>
#include <vector>
using namespace std;

//double type으로 리턴해주는 pow함수 대체 
unsigned long long my_pow(unsigned long long base, int exp){ 
	unsigned long long res = 1; 
	while(exp){ 
		if (exp & 1){
			res *= base;
		}
		exp >>= 1;
		base *= base;		
	}
	return res; 
}



int main() {
	freopen("input.txt","rt", stdin);
	
	int t; //"선린의 터"의 개수
	scanf("%d", &t); //3
	
	long long input[1001]; //찾아야 하는 선린의 터에 대한 정보
	int binary[1001];
	
	for(int i=0; i<t; i++){
		scanf("%lld", &input[i]);
	}
	
	for(int i=0; i<t; i++){
		int cnt=0; //2진법이 몇자리 수인지 count
		long long answer=0;
		
		long long num=input[i];
		
		//binary vector에 2진법 저장 
		while(num!=0){
			binary[cnt]=num%2;
			cnt++;
			num/=2;	
		}

		//3진법으로 변환
		for(int j=0; j<cnt; j++){
			answer+= my_pow(3, j)*binary[j];
		}
		
		//출력
		printf("%lld\n", answer); 
	}
	return 0;
}
