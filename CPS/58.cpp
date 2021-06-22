#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
void Preorder(int v){ //������ȸ 
	if(v>7) return; ///v:Vertex
	else{
		printf("%d ",v);
		Preorder(v*2); //���� �ڽĳ�� ȣ��
		Preorder(v*2+1); //������ �ڽĳ�� ȣ��
	}
}
void Inorder(int v){ //������ȸ 
	if(v>7) return;
	else{
		Inorder(v*2); //���� �ڽĳ�� ȣ��
		printf("%d ",v);
		Inorder(v*2+1); //������ �ڽĳ�� ȣ��
	}
}
void Postorder(int v){ //������ȸ 
	if(v>7) return;
	else{
		Postorder(v*2); //���� �ڽĳ�� ȣ��
		Postorder(v*2+1); //������ �ڽĳ�� ȣ��
		printf("%d ",v);
	}
}
int main(){
	freopen("input.txt","rt",stdin);
	Preorder(1);
	printf("\n");
	Inorder(1);
	printf("\n");
	Postorder(1);
	
	return 0;
}
