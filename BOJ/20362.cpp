//20362] ���ϴ��� ����� 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string> 
using namespace std;

int main() {
	freopen("input.txt","rt", stdin);
	int n, cnt=0, flag;
	string nick, ans, s1, s2;
	
	scanf("%d", &n); //ä�ð��� 
	vector<pair<string, string> > chat;
	
	cin>>nick; //�������� �г��� 
	
	for(int i=0; i<n; i++){
		cin>>s1>>s2;
		chat.push_back(pair<string, string> (s1,s2));
		if(chat[i].first==nick){
			ans=chat[i].second;
			flag=i;
		}
	}
	
	for(int j=0; j<flag; j++){
		if(chat[j].second==ans){
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
	return 0;
}

