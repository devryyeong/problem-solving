//22351] ������ ü������ �Դϴ� 3 
//1�ڸ�, 2�ڸ�, 3�ڸ����� �����ؼ� ���� 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
	
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt", stdin);
	string s;
	string tmp1, tmp2;
	int start, end, find;
	
	cin>>s;
	
	for(int i=1; i<=3; i++){
		tmp1=s.substr(0, i); //�ڸ������� �ڸ� 
		start=stoi(tmp1);
		find=start;
		end=start;
		
		string compStr=""; //string�� �����س��� �� ���ڿ� ���� (��ġ����: for�� �ۿ��� �ϸ� �ȵ�) 
		for(int j=0; j<s.size(); j+=to_string(find).size(),find++){
			tmp2=s.substr(j, to_string(find).size()); //ã������ ���� size��ŭ �߶� tmp2�� ���� 
			
			if(find!=stoi(tmp2)) break;
			
			compStr+=tmp2; //find�� ���ٸ� ã�� tmp2�� compStr�� ���� 
			end=find;
		}
		
		if(compStr==s){ //�ݺ��� ������ ���� ó�� �Է¹��� s�� ���ؼ� �Ȱ��ٸ� �� ��� 
			cout<<start<<' '<<end<<endl;
			return 0;
		} 
	}
	return 0;
}
