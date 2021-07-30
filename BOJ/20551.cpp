//20551] Sort ������ �������� �İ��� 
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

		//��ȯ���� Iterator�̹Ƿ� iterator���� v.begin()�� ������.
		res=lower_bound(v.begin(), v.end(), tmp)-v.begin();
		
		if(v[res]==tmp && res!=n){
			printf("%d\n",res);
		}else{
			printf("-1\n");
		}
		
	}
	
	/* �ð��� ������^^ 
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
