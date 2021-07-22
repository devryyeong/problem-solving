//#44] ������ ���ϱ�
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int Count(int len, int a[]){ //len=mid
	int cnt=1, last_push=a[1];
	for(int j=2; j<=n; j++){ 
		if(a[j]-last_push>=len){ //�ӽ÷� ���� �亸�� ũ�� 
			cnt++; //���� ���� �� count 
			last_push=a[j]; //��� ���� ���� ��ġ ���� 
		}
	}
	return cnt; 
}

int main(){
	freopen("input.txt","rt",stdin);
	int c, start=1, mid, end, res; 
	scanf("%d %d", &n, &c); //5, 3
	int *a=new int[n+1]; //�޸� ���� �Ҵ� 
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	
	//(ù��° �������� �ּ�, ������ �������� �ּ�) 
	sort(a+1, a+n+1); //�迭�� 1������ �־����Ƿ�  

	end=a[n];
	//����Ž�� 
	while(start<=end){ 
		mid=(start+end)/2; //5
		if(Count(mid, a)>=c){ //�Էµ� c�������� ũ�ų� ������ 
			res=mid;
			start=mid+1; //���� �ָ� ����Ʈ������ ���� �� ū ���� �ɱ�? 
		}else{
			end=mid-1;
		}
	}
	printf("%d", res);	
	delete[] a; //�����Ҵ��� �޸� ���� 
	return 0;
}
