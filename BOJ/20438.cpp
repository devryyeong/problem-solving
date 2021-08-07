//20438] �⼮üũ 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sleep[5004], ch[5004];
 	
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt", stdin);
	int n; //�л��� �� 
	int k; //���� �ִ� �л��� �� 
	int q; //��ȯ�̰� �⼮ �ڵ带 ���� �л��� �� 
	int m; //�־��� ������ ��
	int x, a, b;
	int add=0; //������
	vector<int> sum;

	cin >> n >> k >> q >> m;
	sum.resize(n+3, 0); //size�� n+3��ŭ 0���� �ʱ�ȭ 
	
	while(k--){ //�����ִ� �л����� Ȯ�� 
		cin >> x;
		sleep[x]=1;
	}
	
	while(q--){
		cin >> x; //�⼮�ڵ� �Է¹ް� 
		if(sleep[x]) continue; //�⼮�ڵ� �޾Ƶ� �����ִ� �л��̸� �Ѿ 
		add=x; //�⼮�ڵ带 ���� �л� ���� ��ȣ 
		
		while(x<=n+2){
			if(sleep[x]){ //�߰��� �����ִ� ����� ������ 
				x+=add; //�⼮üũX 
				continue;
			}
			ch[x]=1, //�ƴϸ� �⼮�ڵ带 ���� �л� ������ ch�迭�� ���� 
			x+=add; //�� ����� �⼮�ϴ� �л� 
		}
	}
	
	for(int i=3; i<=n+2; i++){ //�⼮���� ���� �л� �� ��� 
		int attendX;
		if(ch[i]==0){
			attendX=1;
		}else{
			attendX=0;
		}
		sum[i]=sum[i-1]+attendX;
	}
	
	for(int i=0; i<m; i++){ //���� �� ��ŭ 
		cin >> a >> b; //���� �Է¹ް� 
		cout << sum[b] - sum[a - 1]<< '\n';//�� ������ �ش��ϴ�(=�⼮�� ���� �ʴ� �л� ��) ��� 
	}
	
	return 0;
}
