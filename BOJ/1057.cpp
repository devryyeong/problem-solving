//1057] ��ʸ�Ʈ
//���尡 �ö� ������ �ڽ��� ��ȣ�� (�ڽ��� ��ȣ+1)/2
//���� �λ�� ��� 2�� �������� �� �Ȱ��� ��ġ�� �ִٸ� �ش� ���忡�� ���� 
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, kim, lim, round=0;
	scanf("%d %d %d", &n, &kim, &lim);
	
	while(kim!=lim){
		round++;
		
		kim=(kim+1)/2;
		lim=(lim+1)/2;
			
	}
	printf("%d", round);

	return 0;
}

