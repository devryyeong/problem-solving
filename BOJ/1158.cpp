#include <iostream>
#include <string>
#include <stack>
using namespace std;

//stack���� �����ؾ� �ڴ�!
int main() {
    int k; //k���� ������ �־���.
    int num; //�ԷµǴ� ����
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

    //�� ���
    for (int i = 0; !st.empty(); i++) {
        sum += st.top();
        st.pop();
    }
    cout << sum << '\n';

    return 0;
}