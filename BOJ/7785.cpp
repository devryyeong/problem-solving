//7785] ȸ�翡 �ִ� ��� 
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt","rt", stdin);
	
	int n;
	string name, el;
	set<string> s;
		
	cin>>n;
	
	for(int i=0; i<n; i++){
    	cin>>name>>el;
    	if(el=="enter"){
	    	s.insert(name);
	    } else{
	      s.erase(name);
	    }
	}
	
	//������ ���� ���
	for(auto iter=s.rbegin(); iter!=s.rend(); iter++){
		cout<<*iter<<"\n";
	}
	
	return 0;
}
