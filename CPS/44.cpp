//#44] 마구간 정하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int Count(int len, int a[]){ //len=mid
	int cnt=1, last_push=a[1];
	for(int j=2; j<=n; j++){ 
		if(a[j]-last_push>=len){ //임시로 정한 답보다 크면 
			cnt++; //넣은 말의 수 count 
			last_push=a[j]; //방금 말을 넣은 위치 저장 
		}
	}
	return cnt; 
}

int main(){
	freopen("input.txt","rt",stdin);
	int c, start=1, mid, end, res; 
	scanf("%d %d", &n, &c); //5, 3
	int *a=new int[n+1]; //메모리 동적 할당 
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	
	//(첫번째 데이터의 주소, 마지막 데이터의 주소) 
	sort(a+1, a+n+1); //배열의 1번부터 넣었으므로  

	end=a[n];
	//이진탐색 
	while(start<=end){ 
		mid=(start+end)/2; //5
		if(Count(mid, a)>=c){ //입력된 c마리보다 크거나 같을때 
			res=mid;
			start=mid+1; //제일 멀리 떨어트려놓기 위해 더 큰 수도 될까? 
		}else{
			end=mid-1;
		}
	}
	printf("%d", res);	
	delete[] a; //동적할당한 메모리 해제 
	return 0;
}
