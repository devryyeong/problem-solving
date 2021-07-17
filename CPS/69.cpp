//69] 이진트리 넓이우선탐색(BFS) (QUEUE 직접구현) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Q[100];
int front=-1; //Q에서 뺄 때는 front 
int rear=-1; //Q에서 넣을 때는 rear(back) 
int ch[10]; //무방향이므로 ch[] 필요. 
vector<int> map[10];

int main(){
	freopen("input.txt", "rt", stdin);
	int a, b, x;
	for(int i=1; i<=6; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b); //무방향 
		map[b].push_back(a); //무방향 
	}
	
	Q[++rear]=1;
	ch[1]=1;
	
	while(front<rear){ //front가 더 작으면 값이 들어있음.
		x=Q[++front]; //x라는 변수에 Q의 자료를 하나 꺼내서 넣음. 
		printf("%d ", x);
		for(int i=0; i<map[x].size(); i++){
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q[++rear]=map[x][i]; //Q에 넣음. 
			}
		}
	}
	
	return 0;
}
