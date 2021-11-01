//STL map
#include <iostream>
#include <map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt","rt", stdin);
  
  //<key, value>
  //접근하기 위한 반복자 필요함. like 포인터
  map<string, int> ch;
  map<string, int>:: iterator it;
  string s, res;
  int n, max=0;
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>s;
    ch[s]++;
  }

  for(it=ch.begin(); it!=ch.end(); it++){
    if(it->second > max){
      max=it->second;
      res=it->first;
    }
  }

  cout<<"res: "<<res<<"\n";
  cout<<"max: "<<max<<"\n";
	return 0;
}