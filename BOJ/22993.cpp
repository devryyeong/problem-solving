//22993] 서든어택 3 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n;
	long long jw=0, a;
	scanf("%d", &n);
	vector<long long> v;
	
	scanf("%lld", &jw);
	
	for(int i=0; i<n-1; i++){
		scanf("%lld", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	for(int i=0; i<n-1; i++){
		if(jw>v[i]){
			jw+=v[i];
		}else{
			printf("No");
			return 0;
		}
	}
	
	printf("Yes");
	return 0;
}
