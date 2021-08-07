//20438] 출석체크 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sleep[5004], ch[5004];
 	
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt", stdin);
	int n; //학생의 수 
	int k; //졸고 있는 학생의 수 
	int q; //지환이가 출석 코드를 보낼 학생의 수 
	int m; //주어질 구간의 수
	int x, a, b;
	int add=0; //누적합
	vector<int> sum;

	cin >> n >> k >> q >> m;
	sum.resize(n+3, 0); //size는 n+3만큼 0으로 초기화 
	
	while(k--){ //졸고있는 학생인지 확인 
		cin >> x;
		sleep[x]=1;
	}
	
	while(q--){
		cin >> x; //출석코드 입력받고 
		if(sleep[x]) continue; //출석코드 받아도 졸고있는 학생이면 넘어감 
		add=x; //출석코드를 받은 학생 입장 번호 
		
		while(x<=n+2){
			if(sleep[x]){ //중간에 졸고있는 사람이 있으면 
				x+=add; //출석체크X 
				continue;
			}
			ch[x]=1, //아니면 출석코드를 받을 학생 정보를 ch배열에 저장 
			x+=add; //그 배수라서 출석하는 학생 
		}
	}
	
	for(int i=3; i<=n+2; i++){ //출석되지 않은 학생 수 계산 
		int attendX;
		if(ch[i]==0){
			attendX=1;
		}else{
			attendX=0;
		}
		sum[i]=sum[i-1]+attendX;
	}
	
	for(int i=0; i<m; i++){ //구간 수 만큼 
		cin >> a >> b; //구간 입력받고 
		cout << sum[b] - sum[a - 1]<< '\n';//이 구간에 해당하는(=출석이 되지 않는 학생 수) 출력 
	}
	
	return 0;
}
