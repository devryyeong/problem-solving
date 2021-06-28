#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool Vps(string str) {
    int len = (int)str.length(); //���ڿ� ����
    stack<char> cstack; //char type stack

    for (int i = 0; i < len; i++) {
        char c = str[i];

        if (c == '(') {
            cstack.push(str[i]);
        }
        else { //')'

            if (!cstack.empty()) { //������� ������ pop
                cstack.pop();
            }
            else { //���������(���� ��ȣ ¦�� ����   char c=str[i];
                return false;
            }
        }
    }
    return cstack.empty(); //���ÿ� ��ȣ�� ���������� false
}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (Vps(str)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}