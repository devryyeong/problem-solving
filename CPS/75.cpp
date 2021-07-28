#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//����ü ���� 
struct Schedule{
	int m,d;
	//����ü ������
	Schedule (int a, int b){
		m=a;
		d=b;
	}
	//������ �����ε�(��ü�� ũ��񱳸� ����) 
	//���⼭ ���ı����� ������. 
	//&b�� ����ü�� "�ּ�"�� ����. 
	//��� ����Լ�: ������� ���� �ٲ� �� ������. 
	bool operator<(const Schedule &s)const{  
		if(d!=s.d) return d>s.d; //��������
	}
};

int main() {
	freopen("input.txt","rt",stdin);
	int n; //n���� ������� ��û�� ������, 
	int m,d; //d�� �ȿ� ���� m��ŭ�� ������
	int max=-2147000000, res=0;
	vector<Schedule> SCD;
	priority_queue<int>pQ;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d %d", &m, &d);
		SCD.push_back(Schedule(m,d));
		if(d>max) max=d;
	}
    
	//����
	sort(SCD.begin(), SCD.end());
	
	int flag=0;
	//max���� �Ųٷ� �׳� �����Ḧ ����
	for(int i=max; i>=1; i--){
		while(flag<n){
			if(SCD[flag].d<i){ //i��¥���� ������ break 
				break;
			}else { //i��¥�� �� �� �ִ� �����̸� pQ�� push
				pQ.push(SCD[flag].m);
			}
			flag++; 
		}
		
		if(!pQ.empty()){ //pQ�� �� ���� ������������� 
			res+=pQ.top();
			pQ.pop();
		}	
	} 

	printf("%d", res);	
    return 0;
}
