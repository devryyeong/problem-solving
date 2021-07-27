//여러개의 값이 한쌍을 이룰때, 구조체와 vector를 이용해 비교하는 법 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Location 구조체 정의 
struct Loc{
	int x,y,z;
	//구조체 생성자
	Loc (int a, int b, int c){
		x=a;
		y=b;
		z=c;
	}
	//연산자 오버로딩(객체의 크기비교를 위해) 
	//여기서 정렬기준을 정해줌. 
	//&b로 구조체의 "주소"를 받음. 
	//상수 멤버함수: 멤버변수 값을 바꿀 수 없도록. 
	bool operator<(const Loc &b)const{  
		//return x < b.x; //x값 기준으로 오름차순 
		
		//x값이 같으면 y값 기준으로, y값이 같으면 z값 기준으로! 
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		if(z!=b.z) return z<b.z; 
	}
};

int main() {
    vector<Loc> XY;
    //값을 넣을 땐 구조체의 생성자를 호출해서 구조체객체를 만들어 넣음.
	XY.push_back(Loc(2,3,5));
	XY.push_back(Loc(3,6,7));
	XY.push_back(Loc(2,3,1));
	XY.push_back(Loc(5,2,3));
	XY.push_back(Loc(3,1,6));
	
	//Range-based for loops
	for(const auto& pos: XY){
		cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;
	}
	cout<<"ㅡㅡㅡ\n";
	
	//정렬
	sort(XY.begin(), XY.end()) ;
	for(const auto& pos: XY){
		cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;
	}

    return 0;
}
