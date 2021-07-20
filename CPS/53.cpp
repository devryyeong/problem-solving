//#53] K진수 출력 (STL stack 구현)
#include <iostream>
#include <algorithm>
#include <vector>
//#include <stack> //push, pop 직접 구현
int stack[100], top=-1; 
using namespace std; 
void push(int x){
	stack[++top]=x; //top을 먼저 증가한 후 x를 넣음. 
}
int pop(){
	return stack[top--];
}

int main(){
	freopen("input.txt","rt",stdin);
	int n, k;
	char str[20]="0123456789ABCDEF"; //16진수용 
	scanf("%d %d", &n, &k); //n=11을 k=2진수로 
	
	while(n>0){
		push(n%k);
		n=n/k;
	}

	//출력
	while(top!=-1){
		printf("%c", str[pop()]);
	}
	return 0;
}
