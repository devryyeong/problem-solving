//22353] ����īī�� 
#include <iostream>
using namespace std;

int main(){
	freopen("input.txt","rt",stdin);
	int a, count=1; //count:���Ƚ�� 
	double d, k, lose=1, res=0;
	cin>>a>>d>>k;
	d/=100;
	k/=100;
	k+=1;
	
	while(d<=1){
		//���� ��⿡�� ��Ȯ��* �̹� ��⿡�� �̱�Ȯ��*���Ƚ�� 
		res+= lose * d * count; 
		lose*=(1-d); //���� ����� ����� ���� ��Ȯ�� ��� 
		d=d*k;
		count++;
		
	}
	res+=lose*count; //1�� ������ ������ res�� ����(�̱�Ȯ��(1) ����)
	
	printf("%.7f",res*a);
}
