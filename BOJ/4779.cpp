//4779] ĭ��� ����
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void recursion(int num){
	if(num==1){ //��� 
		printf("-");
	}else{  
		recursion(num/3);
		//��� ���ڿ� ����ó��
		for(int i=1; i<=num/3; i++){
			printf(" ");
		}
		recursion(num/3);
	}	
}

int main() {
	//freopen("input.txt","rt", stdin);
	int n;
	
	while((scanf("%d",&n))!=EOF){
		n=pow(3,n);
		recursion(n);
		printf("\n");
	}
	
	return 0;
}
