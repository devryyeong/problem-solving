//#50] 영지(territory) 선택 : (small)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	freopen("input.txt","rt",stdin);
	int h, w, hs_h, hs_w, sum=0, max=-2147000000;
	scanf("%d %d", &h, &w); 
	vector<vector<int> > total(h+1, vector<int>(w+1));
	
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			scanf("%d", &total[i][j]);
		}
	}
	scanf("%d %d", &hs_h, &hs_w);
	
	for(int i=1; i<=h-hs_h+1; i++){
		for(int j=1; j<=w-hs_w+1; j++){
			sum=0;
			for(int k=i; k<i+hs_h; k++){
				for(int l=j; l<j+hs_w; l++){
					sum+=total[k][l];
				}
			}
			if(sum>max){
				max=sum;
			}
		}	
	}
	printf("%d", max);
	
	return 0;
}
