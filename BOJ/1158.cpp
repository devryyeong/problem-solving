#include <iostream>
#include <string>
#include <stack>
using namespace std;

//stack으로 구현해야 겠다!
int main() {
    int k; //k개의 정수가 주어짐.
    int num; //입력되는 정수
    int sum = 0;
    stack<int> st;

    cin >> k; //4
    for (int i = 0; i < k; i++) {
        cin >> num;
        if (num != 0) {
            st.push(num);
        }
        else if (num == 0) {
            if (!st.empty()) {
                st.pop();
            }
        }
    }

    //합 출력
    for (int i = 0; !st.empty(); i++) {
        sum += st.top();
        st.pop();
    }
    cout << sum << '\n';

    return 0;
}