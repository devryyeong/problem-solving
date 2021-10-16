//21921] ��α�
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
		
		//sum���Ϳ� ������ ���� 
		if(i==0){
			sum[i]=num;
			continue;
		}
		sum[i]=sum[i-1]+num;
	}
	//sum: 1 5 7 12 13
	
	//�ִ� �湮�� ���� 0���� �ƴ϶�� �ִ� �湮�� �� ���ϱ� 
	maxSum=sum[x-1];

	for(int i=x; i<n; i++){
		if(maxSum<sum[i]-sum[i-x]){
			maxSum=sum[i]-sum[i-x];
			periodNum=1;
		}else if(maxSum==sum[i]-sum[i-x]){
			periodNum++;
		}
  	}
  	
  	//�ִ� �湮�� ���� 0���̶�� 
  	if(maxSum==0) printf("SAD");
	else printf("%lld\n%d", maxSum, periodNum);
	
	return 0;
}
