//#52] Ugly Numbers
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
int main(){
	freopen("input.txt","rt",stdin);
	int n, tmp, p2=1, p3=1, p5=1, min=2147000000;
	scanf("%d", &n); //n��° ugly number
	vector<int> v(n+1);
	v[1]=1; //�ε���1������ 1 ����. 
	
	for(int i=2; i<=n; i++){
		//p2*2, p3*3, p5*5 �� ���� �ּڰ� ã�� 
		if(v[p2]*2<v[p3]*3) min=v[p2]*2;
		else min=v[p3]*3;
		if(v[p5]*5<min) min=v[p5]*5;
		
		//�ּڰ��� ����Ʈ����+1 
		if(v[p2]*2==min) p2++;
		if(v[p3]*3==min) p3++;
		if(v[p5]*5==min) p5++;
		v[i]=min;
	}
	printf("%d", v[n]);
	
	return 0;
}
