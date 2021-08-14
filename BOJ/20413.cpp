//20413] MVP 다이아몬드 (Easy)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
	
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt", stdin);
	int n, res=0;
	cin>>n;
	vector<int> cutline(4);
	vector<char> rank(n);
	vector<int> sum(n+1);
	
	for(int i=0; i<4; i++){
		cin>>cutline[i];
	}
	for(int i=1; i<=n; i++){
		cin>>rank[i];
	}
	
	for(int i=1; i<=n; i++){
		if(rank[i]=='B'){
			sum[i]=cutline[0]-1-sum[i-1];
			
		}else if(rank[i]=='S'){
			sum[i]=cutline[1]-1-sum[i-1];
			
		}else if(rank[i]=='G'){
			sum[i]=cutline[2]-1-sum[i-1];
			
		}else if(rank[i]=='P'){
			sum[i]=cutline[3]-1-sum[i-1];
			
		}else if(rank[i]=='D'){
			sum[i]=cutline[3];
		}
	}
	
	for(int i=0; i<=n; i++){
		res+=sum[i];
	}
	cout<<res;
	return 0;
}
