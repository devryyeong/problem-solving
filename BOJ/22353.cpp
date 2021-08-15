//22353] 헤이카카오 
#include <iostream>
using namespace std;

int main(){
	freopen("input.txt","rt",stdin);
	int a, count=1; //count:게임횟수 
	double d, k, lose=1, res=0;
	cin>>a>>d>>k;
	d/=100;
	k/=100;
	k+=1;
	
	while(d<=1){
		//이전판은 모두 질확률* 현재판에서 이길확률*경기횟수 
		res+= lose * d * count;
		
		//현재 판은 이기고 이전 판들은 모두 진 경우의 확률 구하기
		lose*=(1-d); //이전 판들은 모두 질확률 
		d=d*k; //현재 판은 이길 확률
		count++; //진행판수 +1
		
	}
	res+=lose*count; //1이 넘으면 마지막 res값 더함(이길확률(1) 생략)
	
	printf("%.7f",res*a);
}
