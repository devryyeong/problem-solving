//#47] ���츮 
#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std; 
//int arr[60][60]; //0~51���� �ڷᰡ ���� �� ������ �迭 �����ڸ��� 0���� �ѷ��ξ� �ϹǷ� �˳��ϰ� 60���� ����. 
int main(){
	freopen("input.txt","rt",stdin);
	int n, pos, lp, rp, count=0;
	int left, right, up, down; 
	scanf("%d", &n); //n=5
	vector<vector<int> > arr(n+2, vector<int>(n+2)); //2���� ���� 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(lp=1; lp<=n; lp++){
		for(rp=1; rp<=n; rp++){
			pos=arr[lp][rp]; //pos �Ƚ�
			up=arr[lp-1][rp];
			down=arr[lp+1][rp];
			left=arr[lp][rp-1];
			right=arr[lp][rp+1];

			if(pos>up && pos>down && pos>left && pos>right){
				count++;
			}
			
		}
	}
	printf("%d", count);
	
	return 0;
}
