//14501] ���
#include <iostream>
#include <vector>
using namespace std;

vector<int> T, P;
int n, res=-2147000000;

void DFS(int L, int sum){ //L: �������ϴ� ��¥ 
	if(L>=n+1){
		if(sum>res) res=sum;
	}else{
		if(L+T[L]<=n+1){ //����� �Ѵ� 
			DFS(L+T[L], sum+P[L]);
		}
		DFS(L+1, sum); //����� ���Ѵ� 	
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt", stdin);
	int a, b;
	cin>>n;
	
	T.push_back(0); //�ε���1���� ���� ���� 
	P.push_back(0);
	
	for(int i=0; i<n; i++){
		cin>>a>>b;
		T.push_back(a);
		P.push_back(b);
	}
	
	DFS(1, 0);
	cout<<res;
	
	return 0;
}
