//20551] Sort 마스터 배지훈의 후계자 
//Binary Search
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, m, tmp, res;
	scanf("%d %d", &n, &m);
	vector<int> v;
	
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	for(int j=0; j<m; j++){
		scanf("%d", &tmp);

		//반환형이 Iterator이므로 iterator에서 v.begin()을 빼야함.
		res=lower_bound(v.begin(), v.end(), tmp)-v.begin();
		
		if(v[res]==tmp && res!=n){
			printf("%d\n",res);
		}else{
			printf("-1\n");
		}
		
	}
	
	/* 시간좀 생각해^^ 
	for(int i=0; i<m; i++){
		scanf("%d", &tmp);
		auto it=find(v.begin(), v.end(), tmp);
		if(it==v.end()){
			printf("-1\n");
		}else{
			printf("%d\n", it-v.begin());
		}		
	}
	*/
	return 0;
}
