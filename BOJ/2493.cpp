//2493] ž
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, k;
    stack<pair<int, int> > s; //<�ε�����ȣ,ž�� ����>

    scanf("%d", &n);
    vector<int> res(n+1);

    for(int i=1; i<=n; i++){
		scanf("%d", &k);
    
    	//�Է¹��� ž���̿� stack top�� ž���� ��
	    while(!s.empty()){
	      //�Է¹��� ž���̰� ������ //stack top�� ž�� �����ϴ� ž
	      if(k < s.top().second){
		  	res[i]=s.top().first;
	        break;
	      }
	      s.pop();
	    }

	    //������ ����ִٸ� �����ϴ� ž�� ����.
	    if(s.empty()){
	      res[i]=0;
	    }
	
	    //���� ž�� ���ÿ� push
	    s.push(make_pair(i, k));

  	}

	//���
	for(int i=1; i<=n; i++){
	    printf("%d ",res[i]);
	}
	
	return 0;
}

