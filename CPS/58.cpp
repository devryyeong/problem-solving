#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
void Preorder(int v){ //전위순회 
	if(v>7) return; ///v:Vertex
	else{
		printf("%d ",v);
		Preorder(v*2); //왼쪽 자식노드 호출
		Preorder(v*2+1); //오른쪽 자식노드 호출
	}
}
void Inorder(int v){ //중위순회 
	if(v>7) return;
	else{
		Inorder(v*2); //왼쪽 자식노드 호출
		printf("%d ",v);
		Inorder(v*2+1); //오른쪽 자식노드 호출
	}
}
void Postorder(int v){ //후위순회 
	if(v>7) return;
	else{
		Postorder(v*2); //왼쪽 자식노드 호출
		Postorder(v*2+1); //오른쪽 자식노드 호출
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
