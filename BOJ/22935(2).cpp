//22935] ÀÌÁø µþ±â  
#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	string strawberryGame[28]={
		"0001", "0010", "0011","0100", 
		"0101", "0110", "0111","1000", 
		"1001", "1010", "1011","1100", 
		"1101", "1110", "1111","1110", 
		"1101", "1100", "1011","1010", 
		"1001","1000","0111","0110", 
		"0101", "0100", "0011","0010"
	};
	string res;
	int n, tc; 
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &tc);
		res=strawberryGame[(tc-1) % 28];
		
		//Ãâ·Â
		for(int j=0; j<res.size(); j++){
			if(res[j]=='0') printf("V");
			else printf("µþ±â");
		} 
		puts("");
	}
	
	return 0;
}
