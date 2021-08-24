//1251] 단어 나누기
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	string s;
	string res="{";
	string part1, part2, part3;
	cin>>s;
	
	for(int i=1; i<s.size()-1; i++){
		for(int j=1; j<s.size()-i; j++){ //i-for문에서 자르고 남은 만큼 반복 
			
			//3가지 파트로 자르기
			part1=s.substr(0,i); //0~i-1
			part2=s.substr(i,j); //i~j-1
			part3=s.substr(i+j); //(i+j)~end
			
			reverse(part1.begin(), part1.end());
			reverse(part2.begin(), part2.end());
			reverse(part3.begin(), part3.end());
			
			if(res==""){
				res=part1+part2+part3;
			}
			else if(res>part1+part2+part3){
				res=part1+part2+part3;
			}
		}
	}
	
	cout<<res;
	return 0;
}
