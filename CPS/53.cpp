//#53] K���� ��� (STL stack ����)
#include <iostream>
#include <algorithm>
#include <vector>
//#include <stack> //push, pop ���� ����
int stack[100], top=-1; 
using namespace std; 
void push(int x){
	stack[++top]=x; //top�� ���� ������ �� x�� ����. 
}
int pop(){
	return stack[top--];
}

int main(){
	freopen("input.txt","rt",stdin);
	int n, k;
	char str[20]="0123456789ABCDEF"; //16������ 
	scanf("%d %d", &n, &k); //n=11�� k=2������ 
	
	while(n>0){
		push(n%k);
		n=n/k;
	}

	//���
	while(top!=-1){
		printf("%c", str[pop()]);
	}
	return 0;
}
