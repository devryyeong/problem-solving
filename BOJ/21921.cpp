//21921] 블로그
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, x, num, periodNum=1;
	long long maxSum;

	scanf("%d %d",&n, &x);
	vector<long long> sum(n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &num);
		
		//sum벡터에 누적합 저장 
		if(i==0){
			sum[i]=num;
			continue;
		}
		sum[i]=sum[i-1]+num;
	}
	//sum: 1 5 7 12 13
	
	//최대 방문자 수가 0명이 아니라면 최대 방문자 수 구하기 
	maxSum=sum[x-1];

	for(int i=x; i<n; i++){
		if(maxSum<sum[i]-sum[i-x]){
			maxSum=sum[i]-sum[i-x];
			periodNum=1;
		}else if(maxSum==sum[i]-sum[i-x]){
			periodNum++;
		}
  	}
  	
  	//최대 방문자 수가 0명이라면 
  	if(maxSum==0) printf("SAD");
	else printf("%lld\n%d", maxSum, periodNum);
	
	return 0;
}
