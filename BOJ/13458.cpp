//13458] ���� ���� 
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
		a[i]-=b; //�� �������� �� 
		res++;
		
		if(a[i]>0){ //���� ���û��� �ִٸ� 
			res+=a[i]/c; //�� �������� �� 
			
			if(a[i]%c>0){ //�������� �ִٸ� �� ������ �� +1 
				res++;
			}
		}	
	}

	printf("%ld", res);
	return 0;
}
