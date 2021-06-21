#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int main(){
	freopen("input.txt","rt",stdin);
	stack<int> s;
	int n, next=1;
	scanf("%d", &n);
	vector<int> v(n);
	vector<char> res;
	
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	
	for(int i=0; i<n; i++){
		s.push(v[i]);
		res.push_back('P');
		
		while(!s.empty()){
			if(next==s.top()){
				s.pop();
				res.push_back('O');
				next++;	
			}else{
				break;
			}
		}	
	}
	//과정이 모두 끝나도 스택이 비어있지 않으면 번호순 불가능 
	if(!s.empty()){
		printf("impossible");
		return 0;
	}
	
	//결과 출력 
	for(int i=0; i<res.size(); i++){
		printf("%c ", res[i]);
	}

	return 0;
}


