#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//��� ����(?)�� ������ٰ� ���� �������� �����ߴ���?!(if-else ���� �̿�) 
void recursion(int x){
	if(x==0){ //��������->���̻� ȣ������ �ʰ� �Լ� ����! 
		return;
	}else{ //STACK �ڷᱸ�� ���. 
		recursion(x-1);
		printf("%d ", x);
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	int n;
	scanf("%d", &n);
	recursion(n);
	
	return 0;
}
