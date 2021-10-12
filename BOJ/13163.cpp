//13163] 닉네임에 갓 붙이기
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, idx;
	string name;
	
	cin>>n;
	cin.ignore(100, '\n');
		
	for(int j=0; j<n; j++){
		
		getline(cin, name);

		for(int i=0; i<name.length(); i++){
			if(name[i]==' '){
				idx=i;
				break;
			}
		}
	
		cout<<"god";
		for(int i=idx+1; i<name.length(); i++){
			if(name[i]==' '){
				continue;
			}else{
				cout<<name[i];
			}	
		}
		puts("");
	}

	return 0;
}

