//�������� ���� �ѽ��� �̷궧, ����ü�� vector�� �̿��� ���ϴ� �� 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Location ����ü ���� 
struct Loc{
	int x,y,z;
	//����ü ������
	Loc (int a, int b, int c){
		x=a;
		y=b;
		z=c;
	}
	//������ �����ε�(��ü�� ũ��񱳸� ����) 
	//���⼭ ���ı����� ������. 
	//&b�� ����ü�� "�ּ�"�� ����. 
	//��� ����Լ�: ������� ���� �ٲ� �� ������. 
	bool operator<(const Loc &b)const{  
		//return x < b.x; //x�� �������� �������� 
		
		//x���� ������ y�� ��������, y���� ������ z�� ��������! 
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		if(z!=b.z) return z<b.z; 
	}
};

int main() {
    vector<Loc> XY;
    //���� ���� �� ����ü�� �����ڸ� ȣ���ؼ� ����ü��ü�� ����� ����.
	XY.push_back(Loc(2,3,5));
	XY.push_back(Loc(3,6,7));
	XY.push_back(Loc(2,3,1));
	XY.push_back(Loc(5,2,3));
	XY.push_back(Loc(3,1,6));
	
	//Range-based for loops
	for(const auto& pos: XY){
		cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;
	}
	cout<<"�ѤѤ�\n";
	
	//����
	sort(XY.begin(), XY.end()) ;
	for(const auto& pos: XY){
		cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;
	}

    return 0;
}
