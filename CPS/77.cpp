//77] 친구인가? (Disjoint-set: Union&Find Algorithm) 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//1차원배열로 트리 구현
//(인덱스=학생번호, 값=집합의 번호 )
int unf[1001]; 

//넘어온 학생의 집합 번호 리턴 
int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]); //트리 경로를 압축하기 위해 Find의 리턴값을 다시 unf에 저장. (메모이제이션) 
}

//Find함수를 호출해서 unf의 인덱스와 값이 같은지 확인. 
int Union(int a, int b){ 
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt",stdin);
	int n, m, a, b;
	cin>>n>>m; //9,7

	for(int i=1; i<=n; i++){  
		unf[i]=i;
	}
	for(int j=1; j<=m; j++){
		cin>>a>>b;
		Union(a,b); //입력받아서 바로 Union함수 호출 
	}
	cin>>a>>b; //친구인지 확인하는 숫자쌍 
	
	a=Find(a);
	b=Find(b);
	if(a==b) cout<<"YES";
	else cout<<"NO"; 
		
    return 0;
}
