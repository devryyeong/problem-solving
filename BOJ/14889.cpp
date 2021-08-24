//14889] ��ŸƮ�� ��ũ 
//start���� �ְų�, link���� �ְų�. ->���  
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ability[21][21];
int startSum, linkSum;
int start_first, start_second, link_first, link_second;
int n, res=2147000000;
vector<int> start, link;

void DFS(int x){
	if(x==n+1){ //��� �������� ���� ��ġ���� �� 
		if(start.size()==n/2 && link.size()==n/2){ //�� ���� ũ�Ⱑ ���� n/2�� �� 
			
			//���� ������ ���� �ʱ�ȭ 
			startSum=0;
			linkSum=0;
			
			//2�� �ݺ������� �� ���� ���� ����
			for(int i=0; i<n/2; i++){
				for(int j=i+1; j<n/2; j++){
					if(i==j) continue;
					
					//start�� 2�� ��� 
					start_first=start[i];
					start_second=start[j];
					//start�� ���� ���
					startSum+=ability[start_first][start_second] + ability[start_second][start_first];
				
					//link�� 2�� ��� 
					link_first=link[i];
					link_second=link[j];
					//link�� ���� ���
					linkSum+=ability[link_first][link_second] + ability[link_second][link_first];
				}
			}
			
			//���� ���ؼ� �ּڰ� ���� 
			res=min(res, abs(startSum-linkSum));
		}
		return;
	}
	
	//x�� ������ ����
	//1) start���̰ų�
	start.push_back(x);
	DFS(x+1);
	start.pop_back();
	
	//2) link���̰ų�
	link.push_back(x);
	DFS(x+1);
	link.pop_back();
}

int main() {
	freopen("input.txt","rt", stdin);
	scanf("%d", &n); //(4<=n<=20)
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &ability[i][j]);
		}
	}
	
	DFS(1);
	printf("%d", res);	
	return 0;
}
