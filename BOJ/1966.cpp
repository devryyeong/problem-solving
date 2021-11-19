//1966] 프린터 큐
#include<iostream>
#include<queue>
using namespace std;

int main(){
  freopen("input.txt","rt",stdin);
  int t, n, m;
  scanf("%d", &t);
  while(t--){
    queue<pair<int, int> > Q;
    priority_queue<int> PQ;
    int cnt=0;

    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
      int ipt; //ipt:중요도
      scanf("%d", &ipt);
      Q.push(make_pair(i,ipt));
      PQ.push(ipt); //중요도만 우선순위 큐에 따로 넣음
    }
    
    while(!Q.empty()){
      //현재 위치의 인덱스와 중요도
      int nowIdx=Q.front().first;
      int nowVal=Q.front().second;
      Q.pop();

      //일치하면 앞으로 빼고
      //1.2.7.4.7->7.7.4.2.1
      if(PQ.top()==nowVal){
        PQ.pop();
        cnt++;
        //몇 번째로 인쇄되는지 궁금한게 현재가 되면
        if(nowIdx==m){ 
          printf("%d\n", cnt);
          break;
        }
      }else{
        Q.push(make_pair(nowIdx, nowVal));
      }
    }
  }
  return 0;
}
