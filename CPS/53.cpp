#include <iostream>
#include <algorithm>
#include <stack>
using namespace std; 
int main(){
	//freopen("input.txt","rt",stdin);
	stack<char> s;
	char n[50];
	int flag=1;
	scanf("%s", &n);
	for(int i=0; n[i]!='\0'; i++){
		if(n[i]=='('){
			s.push(n[i]);
		}else{ //')'
			if(s.empty()){ 
				printf("NO");
				flag=0;
				break; 
			}else{ 
				s.pop();
			}
		}
	}
	
	//')(' 경우도 올바른 괄호!! 
	if(s.empty() && flag==1){
		printf("YES");
	}else if(!s.empty() && flag==1){
		printf("NO");
	}
	
	return 0;
}
