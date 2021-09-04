//22970] 문제 재탕  
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[5001];
int main() {
	freopen("input.txt","rt", stdin);
	int n, ans=0, tmp=1;
	 
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	//길이가 1인 수열이면 바로 1 출력 후 종료
	if(n==1){
		printf("1"); 
		return 0;
	}
	
	for(int i=1; i<n; i++){
		if(arr[i-1]>arr[i] && arr[i+1]>arr[i]){
			//산이 끝나는 지점 ex)1 2 3 2 "1" 2 
			ans=max(ans, tmp+1);
			tmp=1;
			continue;
		}else if(arr[i-1]<arr[i] && arr[i+1]<arr[i]){
			//최고점 ex)1 2 "3" 2 1 2
			tmp++; 
		}else if(arr[i-1]<arr[i] || arr[i-1]>arr[i]){
			//높이가 증가하거나 감소할 때 
			tmp++;
		}else if(arr[i-1]==arr[i]){
			//높이가 같으면 산도 끝남
			tmp=1; 
		}
		
		ans=max(ans,tmp);
	}
	
	printf("%d", ans);
	return 0;
}
