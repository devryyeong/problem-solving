//1935] 후위 표기식2
//숫자면 push, 연산자면 숫자 두개 pop한 후 연산 결과 push
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int val[30]; //피연산자 값
int main() {
  cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
  freopen("input.txt","rt", stdin);
  int n;
  double a, b; //2개의 피연산자를 꺼내서 저장할 변수
  double res;
  string str;
  stack <double> s;

  cin>>n;
  cin>>str;
  for(int i=0; i<n; i++){
    cin>>val[i];
  }
  
  for(int i=0; i<str.length(); i++){
    if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
      a=s.top();
      s.pop();
      b=s.top();
      s.pop();

      switch(str[i]){
        case '+':
          s.push(b+a);
          break;
        case '-':
          s.push(b-a);
          break;
        case '*':
          s.push(b*a);
          break;
        case '/':
          s.push(b/a);
          break;
      }
    }else{
      s.push(val[str[i]-'A']);
    }
  }

  //소수점 둘째자리까지 출력
  res=s.top();
  cout<<fixed;
  cout.precision(2);
  cout<<res;
	return 0;
}