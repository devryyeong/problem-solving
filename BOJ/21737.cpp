//21737] SMUPC °è»ê±â 
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, num, ans;
	bool isC=false;
	char c;
	
	scanf("%d %d", &n, &ans);
	while(n--){
		scanf("%c", &c);
		if(c=='C'){
			printf("%d ", ans);
			isC=true;
		}else{
			scanf("%d", &num);
			if(c=='S'){
				ans-=num;
			}else if(c=='M'){
				ans*=num;
			}else if(c=='U'){
				ans/=num;
			}else if(c=='P'){
				ans+=num;
			}
		}
	}
	
	if(!isC){
		printf("NO OUTPUT");
	}
	return 0;
}

