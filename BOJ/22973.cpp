//22973] ���� ���ٲ���
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt","rt", stdin);
	int jump=1, cnt=0;
	long long hw=1, k;
	scanf("%lld", &k);
	
	//k�� ������� 
	if(k<0){
		k=-k;
	}else if(k==0){ //������ ��ġ=������ ���� ��ġ 
		printf("0");
		return 0;
	}

	//k�� ¦����� ������ �� �ִ� ����� ����. 
	if(k%2==0){
		printf("-1");
		return 0;
	}
	
	while(k>0){
		hw*=(hw*2)-1;
		k/=2;
		cnt++;
	}

	printf("%d", cnt);
	return 0;
}
