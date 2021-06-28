#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n; //n���� ���� �Է� ����.
    int number; //�Է¹��� ����.
    int s = 1; //�ӽ� ����

    stack<int> st;
    queue<int> que;
    vector<char> result; //'-'�� '+'�� ����ϱ� ���� ���� 

    cin >> n; //8

    //stack, queue�� �� ����.
    for (int i = 0; i < n; i++) {
        cin >> number;
        que.push(number);
    }

    while (que.size()) {
        if (s <= que.front()) {
            while (s <= que.front()) {
                st.push(s++);
                result.push_back('+');
            }
        }
        else if (que.front() == st.top()) {
            if (st.size()) {
                st.pop();
                que.pop();
                result.push_back('-');
            }
        }
        else {
            cout << "NO" << "\n";
            return 0;
        }
    }

    for (auto c : result) {
        cout << c << '\n';
    }
    return 0;
}