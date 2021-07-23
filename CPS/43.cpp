//#43] 뮤직비디오
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1001], n;
//DVD 한개의 용량이 mid라면 모두 녹화하는데 필요한 DVD 개수 리턴 
int Count(int s){
	int cnt=1, sum=0;
	for(int j=1; j<=n; j++){ //모든 곡을 탐색하면서 
		if(sum+a[j]>s){ //다음 곡까지 더했을때 mid(s)보다 크면 DVD새로 갈아야함.(DVD개수 cnt++; sum=a[i]로 초기화 
			cnt++;
			sum=a[j]; //곡이 총 몇분인지 저장 
		}else{
			sum+=a[j];
		}
	}
	return cnt; //DVD 개수 리턴 
}
int main(){
	freopen("input.txt","rt",stdin);
	int m, start=1, mid, end=0, res, max=-2147000000;
	scanf("%d %d", &n, &m); //9, 3
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		end=end+a[i]; //영상 시간 총합
		if(a[i]>max){
			max=a[i];
		}
	}

	//이진탐색 
	while(start<=end){ //start, end 엇갈리면 끝나야 함 
		mid=(start+end)/2; //DVD 한개의 최소용량(답이라고 가정) 
		if(Count(mid)<=m && mid>=max){ //mid가 답일 때(DVD 한 개의 용량은 가장 긴 곡보다는 커야함) 
			res=mid;
			end=mid-1;
		}else{ 
			start=mid+1;
		}
	}
	printf("%d", res);	
	return 0;
}
