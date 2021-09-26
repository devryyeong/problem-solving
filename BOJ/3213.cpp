//3213] 피자 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt","rt", stdin);
	
	int n, res=0, h=0, q1=0, q3=0;
	string s;
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>s;
		if(s=="1/4") q1++;
		else if(s=="1/2") h++;
		else if(s=="3/4") q3++;			
	}
	
	//1/4와 3/4를 서로 짝지어서 피자 한판 
	while(q1>0 && q3>0){
		q1--;
		q3--;
		res++;
	}
	
	//3/4조각은 다른 조각과 합칠 수 없으므로 res++; 
	while(q3>=1){
		q3--;
		res++;
	}
	
	//1/2 계산
	res+=h/2;
	h-=(h/2*2);

	//1/2조각과 1/4조각이 남았을 경우 피자 한판 
	while(h>=1 && q1>=2){
		h--;
		q1-=2;
		res++;
	}
	
	//남은 1/4조각이 4개이상이라면 피자 한판 
	while(q1>=4){
		q1-=4;
		res++;
	}
  
  //2/1조각과 1/4조각으로 한판이 만들어진다면
  while(h>0){
    if(q1>=2){
      h--;
      q1-=2;
      res++;
    }else{
      break;
    }
  }
  //그래도 남는 조각이 있다면
  if(h>0 || q1>0) res++;

	cout<<res;
	return 0;
}