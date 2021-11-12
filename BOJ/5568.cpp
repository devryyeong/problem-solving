//5568] 카드 놓기
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, k, ch[11];
string s;
vector<string> num;
vector<string> tmp;
set<string> numSet;

void DFS(int L){
  if(L==k){ //k개 선택했으면 문자열을 set에 저장
    for(int i=0; i<k; i++){
      string ss;
      for(auto t: tmp) ss+=t; //문자열붙히기
      numSet.insert(ss);
      return;
    }
  }else{ //k개 선택하기
    for(int i=0; i<n; i++){
      if(!ch[i]){
        ch[i]=1;
        tmp.push_back(num[i]);
        DFS(L+1);
        tmp.pop_back(); //pop!!!!
        ch[i]=0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  freopen("input.txt","rt",stdin);
  cin>>n>>k;
  for(int i=0; i<n; i++){
    cin>>s;
    num.push_back(s);
  }
  DFS(0);
  cout<<numSet.size();
  return 0;
}
