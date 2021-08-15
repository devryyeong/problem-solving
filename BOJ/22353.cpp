//22353] 헤이카카오 
#include <iostream>
using namespace std;

int main(){
	freopen("input.txt","rt",stdin);
	int a, count=1; //count:경기횟수 
	double d, k, lose=1, res=0;
	cin>>a>>d>>k;
	d/=100;
	k/=100;
	k+=1;
	
	while(d<=1){
		//이전 경기에서 질확률* 이번 경기에서 이길확률*경기횟수 
		res+= lose * d * count; 
		lose*=(1-d); //다음 결과값 계산을 위한 질확률 계산 
		d=d*k;
		count++;
		
	}
	res+=lose*count; //1이 넘으면 마지막 res값 더함(이길확률(1) 생략)
	
	printf("%.7f",res*a);
}
