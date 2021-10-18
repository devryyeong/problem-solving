//2490] 윷놀이
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, yut;
	
	for(int j=0; j<3; j++){
		yut=0;
		
		for(int i=0; i<4; i++){
			scanf("%d", &n);
			if(n==0) yut++;
		}
				
		switch(yut){
			case 0:
				printf("E\n");
				break;
			case 1:
				printf("A\n");
				break;
			case 2:
				printf("B\n");
				break;
			case 3:
				printf("C\n");
				break;
			case 4:
				printf("D\n");
				break;
		}
	}
	
	return 0;
}
