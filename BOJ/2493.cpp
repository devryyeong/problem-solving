//2493] 탑
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, k;
    stack<pair<int, int> > s; //<인덱스번호,탑의 높이>

    scanf("%d", &n);
    vector<int> res(n+1);

    for(int i=1; i<=n; i++){
		scanf("%d", &k);
    
    	//입력받은 탑높이와 stack top의 탑높이 비교
	    while(!s.empty()){
	      //입력받은 탑높이가 작으면 //stack top의 탑이 수신하는 탑
	      if(k < s.top().second){
		  	res[i]=s.top().first;
	        break;
	      }
	      s.pop();
	    }

	    //스택이 비어있다면 수신하는 탑이 없음.
	    if(s.empty()){
	      res[i]=0;
	    }
	
	    //현재 탑을 스택에 push
	    s.push(make_pair(i, k));

  	}

	//출력
	for(int i=1; i<=n; i++){
	    printf("%d ",res[i]);
	}
	
	return 0;
}

