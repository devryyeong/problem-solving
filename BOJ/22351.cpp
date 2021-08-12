//22351] 수학은 체육과목 입니다 3 
//1자리, 2자리, 3자리수로 구분해서 연산 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
	
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt", stdin);
	string s;
	string tmp1, tmp2;
	int start, end, find;
	
	cin>>s;
	
	for(int i=1; i<=3; i++){
		tmp1=s.substr(0, i); //자릿수별로 자름 
		start=stoi(tmp1);
		find=start;
		end=start;
		
		string compStr=""; //string을 누적해나갈 빈 문자열 선언 (위치주의: for문 밖에서 하면 안됨) 
		for(int j=0; j<s.size(); j+=to_string(find).size(),find++){
			tmp2=s.substr(j, to_string(find).size()); //찾으려는 수의 size만큼 잘라서 tmp2에 저장 
			
			if(find!=stoi(tmp2)) break;
			
			compStr+=tmp2; //find와 같다면 찾은 tmp2를 compStr에 누적 
			end=find;
		}
		
		if(compStr==s){ //반복문 끝까지 돌고 처음 입력받은 s와 비교해서 똑같다면 답 출력 
			cout<<start<<' '<<end<<endl;
			return 0;
		} 
	}
	return 0;
}
