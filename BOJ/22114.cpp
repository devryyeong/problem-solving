//22114] â���̿� ����
//�Է����� �־����� ���� ����ؾ� �ϴ� ������ �ſ� ũ�� ������ 
//64��Ʈ �ڷ���(long long, %lld�� ���) ���.
#include <iostream>
#include <vector>
using namespace std;

//double type���� �������ִ� pow�Լ� ��ü 
unsigned long long my_pow(unsigned long long base, int exp){ 
	unsigned long long res = 1; 
	while(exp){ 
		if (exp & 1){
			res *= base;
		}
		exp >>= 1;
		base *= base;		
	}
	return res; 
}



int main() {
	freopen("input.txt","rt", stdin);
	
	int t; //"������ ��"�� ����
	scanf("%d", &t); //3
	
	long long input[1001]; //ã�ƾ� �ϴ� ������ �Ϳ� ���� ����
	int binary[1001];
	
	for(int i=0; i<t; i++){
		scanf("%lld", &input[i]);
	}
	
	for(int i=0; i<t; i++){
		int cnt=0; //2������ ���ڸ� ������ count
		long long answer=0;
		
		long long num=input[i];
		
		//binary vector�� 2���� ���� 
		while(num!=0){
			binary[cnt]=num%2;
			cnt++;
			num/=2;	
		}

		//3�������� ��ȯ
		for(int j=0; j<cnt; j++){
			answer+= my_pow(3, j)*binary[j];
		}
		
		//���
		printf("%lld\n", answer); 
	}
	return 0;
}
