//22114] â���̿� ����
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, k, answer=0;
	scanf("%d %d", &n, &k); //7,3 
	vector<int> v(n+1);
	
	for(int i=0; i<n-1; i++){
		scanf("%d", &v[i]);
	}


	for(int i=0; i<n-1; i++){
		int tmp=1, jump=1;
		
		for(int j=i; j<n-1; j++){
			//k���� �۰� �ǳ� �� ���� ��
			if(v[j]<=k){
				tmp++;
			}else{
				if(jump>0){ //k���� ũ���� jump �� �� ���� ��  
					tmp++;
					jump=0;
				}else{ //jump�� �Ұ����� ���  
					break;
				} 
			}
		}
		
		//�ִ� �� 
		if(tmp>answer){
			answer=tmp;
		}
	}
	
	
	printf("%d", answer);	
	
	return 0;
}
