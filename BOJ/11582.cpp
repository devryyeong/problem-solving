//11582] 치킨 TOP N
#include <iostream>
using namespace std;

int n, k;
int num[1049000], res[1049000];

void divide(int lt, int rt){
  int mid, p1, p2, p3;

  //Merge sort 트리구조: 후위(왼-오-자신)
  if(lt<rt){
    mid=(lt+rt)/2; //1.중간값 구하기
    divide(lt, mid); //2.왼쪽부분
    divide(mid+1, rt); //3.오른쪽부분

    //break point
    if((rt-lt)>(n/k)) return;

    //Merge//
    p1=lt;
    p2=mid+1;
    p3=lt;
    while(p1<=mid && p2<=rt){
      if(num[p1]<num[p2]) res[p3++]=num[p1++];
      else res[p3++]=num[p2++];
    }

    //남아있는게 있으면 그대로 res에 넣음
    while(p1<=mid) res[p3++]=num[p1++];
    while(p2<=rt) res[p3++]=num[p2++];

    //num배열 업데이트
    for(int i=lt; i<=rt; i++){
      num[i]=res[i];
    }
  }
  
  
}

int main(){
  freopen("input.txt","rt",stdin);
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &num[i]);
  }
  scanf("%d", &k);

  //1부터 n까지 정렬
  divide(1, n);

  for(int i=1; i<=n; i++){
    printf("%d ", num[i]);
  }
  return 0;
}
