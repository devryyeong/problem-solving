#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//��� ����(?)�� ������ٰ� ���� �������� �����ߴ���?!(if-else ���� �̿�) 
void recursion(int x){
	if(x==0){ //��������->���̻� ȣ������ �ʰ� �Լ� ����! 
		return;
	}else{ //STACK �ڷᱸ�� ���. 
		recursion(x/2);
		
		printf("%d", x%2);
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	int n;
	scanf("%d", &n); //11
	recursion(n);
	
	return 0;
}
