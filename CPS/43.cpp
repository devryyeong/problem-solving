//#43] ��������
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1001], n;
//DVD �Ѱ��� �뷮�� mid��� ��� ��ȭ�ϴµ� �ʿ��� DVD ���� ���� 
int Count(int s){
	int cnt=1, sum=0;
	for(int j=1; j<=n; j++){ //��� ���� Ž���ϸ鼭 
		if(sum+a[j]>s){ //���� ����� �������� mid(s)���� ũ�� DVD���� ���ƾ���.(DVD���� cnt++; sum=a[i]�� �ʱ�ȭ 
			cnt++;
			sum=a[j]; //���� �� ������� ���� 
		}else{
			sum+=a[j];
		}
	}
	return cnt; //DVD ���� ���� 
}
int main(){
	freopen("input.txt","rt",stdin);
	int m, start=1, mid, end=0, res, max=-2147000000;
	scanf("%d %d", &n, &m); //9, 3
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		end=end+a[i]; //���� �ð� ����
		if(a[i]>max){
			max=a[i];
		}
	}

	//����Ž�� 
	while(start<=end){ //start, end �������� ������ �� 
		mid=(start+end)/2; //DVD �Ѱ��� �ּҿ뷮(���̶�� ����) 
		if(Count(mid)<=m && mid>=max){ //mid�� ���� ��(DVD �� ���� �뷮�� ���� �� ��ٴ� Ŀ����) 
			res=mid;
			end=mid-1;
		}else{ 
			start=mid+1;
		}
	}
	printf("%d", res);	
	return 0;
}
