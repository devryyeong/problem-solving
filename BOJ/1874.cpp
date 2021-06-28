#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n; //n개의 수를 입력 받음.
    int number; //입력받을 정수.
    int s = 1; //임시 수열

    stack<int> st;
    queue<int> que;
    vector<char> result; //'-'와 '+'를 출력하기 위한 벡터 

    cin >> n; //8

    //stack, queue에 다 넣음.
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