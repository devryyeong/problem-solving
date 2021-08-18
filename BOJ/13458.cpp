//13458] 시험 감독 
#include <iostream>
using namespace std;
int a[1000001];

int main() {
	freopen("input.txt","rt", stdin);
	int n, b, c;
	long long res=0;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	scanf("%d %d", &b, &c); 
	
	for(int i=0; i<n; i++){
		a[i]-=b; //총 감독관의 수 
		res++;
		
		if(a[i]>0){ //남은 응시생이 있다면 
			res+=a[i]/c; //부 감독관의 수 
			
			if(a[i]%c>0){ //나머지가 있다면 부 감독관 수 +1 
				res++;
			}
		}	
	}

	printf("%ld", res);
	return 0;
}
