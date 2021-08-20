//1026] 보물 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> //greater함수 
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, tmp, sum=0;
	
	scanf("%d", &n);
	vector<int> a;
	vector<int> b;
	
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	sort(a.begin(), a.end()); //오름차순 
	
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		b.push_back(tmp);
	}
	sort(b.begin(), b.end(), greater<int>()); //내림차순 

	for(int i=0; i<n; i++){
		sum+=a[i]*b[i];
	}
	
	printf("%d", sum);
	return 0;
}
