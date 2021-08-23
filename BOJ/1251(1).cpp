//1251] 단어 나누기
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	string s;
	string result="{";
	
	cin>>s;
	
	for(int i=0; i<s.size()-2; i++){
		for(int j=i+1; j<s.size()-1; j++){
			
			string val;
			
			for(int k=i; k>=0; k--){
				val+=s[k];
			}

			for(int k=j; k>i; k--){
				val+=s[k];
			}
			
			for(int k=s.size()-1; k>j; k--){
				val+=s[k];
			}
			
			
			if(result>val){
				result=val;
			}
		}
	}
	cout<<result;
	return 0;
}
