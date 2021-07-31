//77] ģ���ΰ�? (Disjoint-set: Union&Find Algorithm) 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//1�����迭�� Ʈ�� ����
//(�ε���=�л���ȣ, ��=������ ��ȣ )
int unf[1001]; 

//�Ѿ�� �л��� ���� ��ȣ ���� 
int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]); //Ʈ�� ��θ� �����ϱ� ���� Find�� ���ϰ��� �ٽ� unf�� ����. (�޸������̼�) 
}

//Find�Լ��� ȣ���ؼ� unf�� �ε����� ���� ������ Ȯ��. 
int Union(int a, int b){ 
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt",stdin);
	int n, m, a, b;
	cin>>n>>m; //9,7

	for(int i=1; i<=n; i++){  
		unf[i]=i;
	}
	for(int j=1; j<=m; j++){
		cin>>a>>b;
		Union(a,b); //�Է¹޾Ƽ� �ٷ� Union�Լ� ȣ�� 
	}
	cin>>a>>b; //ģ������ Ȯ���ϴ� ���ڽ� 
	
	a=Find(a);
	b=Find(b);
	if(a==b) cout<<"YES";
	else cout<<"NO"; 
		
    return 0;
}
