//#45] ���� ���ϱ� (�似Ǫ��-vector�� ���) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	freopen("input.txt","rt",stdin);
	int n, k, pos=0, cnt=0, breakpoint=0; 
	scanf("%d %d", &n, &k); //8, 3
	vector<int> check(n+1);
	while(1){
		pos++;
		if(pos>n){ //n���� Ŀ���� �ٽ� 1�� ���ư� 
			pos=1;
		}
		if(check[pos]==0){
			cnt++; //k��°���� count
			if(cnt==k){
				check[pos]=1;
				breakpoint++; //n-1�� �Ǹ� break�ؾ� �� 
				cnt=0; //�ٽ� 0���� k���� count 
			}
		}
		
		if(breakpoint==n-1){
			break;
		}
	}
	
	for(int i=1; i<=n; i++){
		if(check[i]==0){
			printf("%d", i);
		}
	}

	return 0;
}
