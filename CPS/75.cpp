#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//구조체 정의 
struct Schedule{
	int m,d;
	//구조체 생성자
	Schedule (int a, int b){
		m=a;
		d=b;
	}
	//연산자 오버로딩(객체의 크기비교를 위해) 
	//여기서 정렬기준을 정해줌. 
	//&b로 구조체의 "주소"를 받음. 
	//상수 멤버함수: 멤버변수 값을 바꿀 수 없도록. 
	bool operator<(const Schedule &s)const{  
		if(d!=s.d) return d>s.d; //오름차순
	}
};

int main() {
	freopen("input.txt","rt",stdin);
	int n; //n개의 기업에서 요청이 들어오고, 
	int m,d; //d일 안에 오면 m만큼의 강연료
	int max=-2147000000, res=0;
	vector<Schedule> SCD;
	priority_queue<int>pQ;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d %d", &m, &d);
		SCD.push_back(Schedule(m,d));
		if(d>max) max=d;
	}
    
	//정렬
	sort(SCD.begin(), SCD.end());
	
	int flag=0;
	//max부터 거꾸로 그날 강연료를 넣음
	for(int i=max; i>=1; i--){
		while(flag<n){
			if(SCD[flag].d<i){ //i날짜보다 작으면 break 
				break;
			}else { //i날짜에 할 수 있는 강연이면 pQ에 push
				pQ.push(SCD[flag].m);
			}
			flag++; 
		}
		
		if(!pQ.empty()){ //pQ에 잘 들어가서 비어있지않으면 
			res+=pQ.top();
			pQ.pop();
		}	
	} 

	printf("%d", res);	
    return 0;
}
