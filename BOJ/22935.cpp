//22935] 이진 딸기
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, num;
	long long N; //(1 ≤ N ≤ 1,000,000,000)
	string s1, s2;
	string s[16];
	scanf("%d", &T);
	
	//1~15를 이진수로 바꿔서 string 배열(s)에 저장 
	for(int i=1; i<=15; i++){
		num=i;
		int res=0;
		for(int j=1; num>0; j*=10){
			res=res+(num%2)*j;
			num/=2;
		}	
		s[i]=to_string(res);
	}
	
	//4자리로 채우기 위한 노가다 
	for(int i=1; i<=7; i++){
		if(s[i].size()==1) s[i]="000"+s[i];
		else if(s[i].size()==2) s[i]="00"+s[i];
		else if(s[i].size()==3) s[i]="0"+s[i];
	}
	
	//0->'V', 1->'딸기' 변환 
	for(int i=1; i<=15; i++){
		s2="";
		for(int j=0; j<s[i].size(); j++){
			if(s[i].substr(j,1).compare("0")==0){
				s2+="V";
			}else{
				s2+="딸기";
			}
		}
		s[i]=s2;
	}

	//N이 15이하라면 배열에서 N번째를 바로 출력 
	//16이상이라면 14->1로 내려가고 2-> 15로 올라가면서 14개씩 반복
	//14로 나눈 몫이 짝수면 내려가는 구간, 홀수면 올라가는 구간 
	for(int i=0; i<T; i++){
		scanf("%d", &N); //3
		if(N<=15){ 
			cout<<s[N]<<'\n';
		}else{ 
			int N2=N-16;
			int a=N2/14;
			int b=N2%14;
			
			if(a%2==0){
				cout<<s[14-b]<<'\n';
			}else{
				cout<<s[b+2]<<'\n';
			}
		}
	}
	
	return 0;
}
