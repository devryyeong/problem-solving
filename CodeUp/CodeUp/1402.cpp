
#include <iostream>
#include <stack>
using namespace std;
int main() {
	stack<int> S;  
	int inputNum, number;
	cin >> inputNum;

	for (int i = 0; i < inputNum; i++) {
		cin >> number;
		S.push(number);
	}

	for (int i = 0; i < inputNum; i++) {
		cout << S.top()<<" ";
		S.pop();
	}

	return 0;
}
	/*
	S라는 이름의 int 요소들로 구성된 스택 선언
	S.push(값);  //스택 S에 값을 넣는다. 리턴 값이 없다.
	S.pop();  //스택 S의 top을 삭제한다. 리턴 값이 없다.
	S.top();  //스택 S의 top을 리턴한다. top은 삭제되지 않는다. (peek기능)
	S.size();  //스택 S의 크기(구성 요소 갯수)를 리턴한다.
	S.empty();  //스택 S가 비어있으면(요소가 없으면) 를 1(True)리턴하고 비어있지 않으면 0(False)를 리턴한다.
	*/
