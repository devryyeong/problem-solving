//21964] �������ͳݰ���б� ���� 
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, range;
	scanf("%d", &n); //12
	range=n-4; //8 (index 8~12���� ����ؾ� ��.)
	vector<char> ch(n+1);
	
	for(int i=0; i<=n; i++){
		scanf("%c", &ch[i]);
	}
	
	
	for(int j=range; j<=n; j++){
		printf("%c", ch[j]);
	}
	
	
	return 0;
}
