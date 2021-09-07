//86] ���� ��� �Ÿ� (DFS Ȱ��) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int> > pz; //pizza
vector<pair<int,int> > hs; //house
int m, res=2147000000, dis, sum;
int ch[20]; //������ ���ҵ��� ���� �迭 

void DFS(int L, int s){
	if(L==m){ //m�� ���ڷ� ������ ���� �ϳ��� �ϼ��� �Ǹ� 
		sum=0;
		for(int i=0; i<hs.size(); i++){
			//�� �Ѱ��� �����ϰ� 
			int x1=hs[i].first;
			int y1=hs[i].second;
			
			
			//��-������ �Ÿ� ���ϱ� 
			dis=2147000000;
			for(int j=0; j<m; j++){
				int x2=pz[ch[j]].first;
				int y2=pz[ch[j]].second;
				
				//�Ÿ� �ּڰ�
				dis=min(dis, abs(x1-x2)+abs(y1-y2));
			}
			sum+=dis; //sum: ������ ���ڹ�ްŸ� 
		}
		if(sum<res) res=sum; //res: ������ �ּ� ���ڹ�ްŸ� 
		  
	}else{ 
		for(int i=s; i<pz.size(); i++){ //0���� ����, pz.size()���� 
			ch[L]=i; //L�� index control�ϸ鼭 ���ڵ��� �ϳ��� �־ 
			DFS(i+1, L+1);
		} 
	}
	
}
int main() {
	freopen("input.txt","rt", stdin);
	int n, a;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
 		for(int j=1; j<=n; j++){
			 scanf("%d", &a);
			 if(a==1) hs.push_back(make_pair(i,j));
			 else if(a==2) pz.push_back(make_pair(i,j));
		}
	}
	DFS(0,0);
	printf("%d", res);
	return 0;
}
