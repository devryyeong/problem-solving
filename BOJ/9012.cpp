#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool Vps(string str) {
    int len = (int)str.length(); //문자열 길이
    stack<char> cstack; //char type stack

    for (int i = 0; i < len; i++) {
        char c = str[i];

        if (c == '(') {
            cstack.push(str[i]);
        }
        else { //')'

            if (!cstack.empty()) { //비어있지 않으면 pop
                cstack.pop();
            }
            else { //비어있으면(여는 괄호 짝이 없음   char c=str[i];
                return false;
            }
        }
    }
    return cstack.empty(); //스택에 괄호가 남아있으면 false
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