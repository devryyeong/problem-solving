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
	//������ ��� ������ ������ ������� ������ ��ȣ�� �Ұ��� 
	if(!s.empty()){
		printf("impossible");
		return 0;
	}
	
	//��� ��� 
	for(int i=0; i<res.size(); i++){
		printf("%c ", res[i]);
	}

	return 0;
}


