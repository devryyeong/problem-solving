
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
	S��� �̸��� int ��ҵ�� ������ ���� ����
	S.push(��);  //���� S�� ���� �ִ´�. ���� ���� ����.
	S.pop();  //���� S�� top�� �����Ѵ�. ���� ���� ����.
	S.top();  //���� S�� top�� �����Ѵ�. top�� �������� �ʴ´�. (peek���)
	S.size();  //���� S�� ũ��(���� ��� ����)�� �����Ѵ�.
	S.empty();  //���� S�� ���������(��Ұ� ������) �� 1(True)�����ϰ� ������� ������ 0(False)�� �����Ѵ�.
	*/
