//10655] ������1
//�ִ�� ���� �� �ִ� üũ����Ʈ�� ã�ƾ� ��. 
//üũ����Ʈ �ǳʶٰ� �� �ķ� ���� �Ÿ��� �������� ����. 
//�ǳʶ��� ���� ��ü �Ÿ� ��-üũ����Ʈ �ǳʶٰ� ������ �Ÿ� �ִ밪 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int dist(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int main() {
	freopen("input.txt","rt", stdin);
	int n, x, y, res, skip=0, xx, yy;
	int total=0;
	
	scanf("%d", &n);
	vector<pair<int,int> > dis;
	
	for(int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		dis.push_back(pair<int,int>(x, y));
	}
	
	//�ǳʶ��� ���� ��ü �Ÿ� ��
	for(int i=0; i<n-1; i++){
		xx=abs(dis[i+1].first-dis[i].first);
		yy=abs(dis[i+1].second-dis[i].second);
		
		total+=xx+yy;	
	}
	
	//skip �ε��� ��ȣ �����ϰ� ���
	pair<int, int> pre, cur, next;
	
	for(int i=1; i<n-1; i++){
		pre=dis[i-1];
		cur=dis[i];
		next=dis[i+1];
		
		int df=dist(pre,cur) + dist(cur, next);
		int straight=dist(pre, next); //�ǳʶپ��� �� 

		//�ִ�� ���� �� �ִ� üũ����Ʈ
		skip=max(skip, df-straight);
		
		//�ǳʶ��� ���� ��ü �Ÿ� ��-üũ����Ʈ �ǳʶٰ� ������ �Ÿ� �ִ밪 
		res=total-skip;
	}
	
	printf("%d", res);
	return 0;
}
