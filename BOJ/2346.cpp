//2346] 풍선 터뜨리기
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<pair<int,int>> v;
    
    for(int i=1;i<=N;i++){ // 풍선 번호는 1번부터 시작  
        int num;
        cin>>num;
        
        v.push_back(make_pair(i,num));       
    }    
    while(v.empty()!=true){ //벡터가 비어있지 않다면 반복 
        
        cout << v.front().first << " ";
        int a=v.front().second;
        v.erase(v.begin());
        
        
        if (a<0){ //음수? 맨 뒤를 맨 앞으로 
            for(int j=0;j<abs(a);j++){
                v.insert(v.begin(),v.back());
                v.erase(v.end());
            } 
        }else{// 양수? 맨 앞을 맨 뒤로 
            for(int j=0;j<a-1;j++){
                v.push_back(v.front());
                v.erase(v.begin());
            }
        }
    }
    return 0;
}
