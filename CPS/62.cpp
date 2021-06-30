//62] 병합정렬 (Merge Sort) -후위순회 
#include <iostream>
using namespace std;
int n, sorted[101], a[101]; //sorted[]: 임시정렬배열, a{]: 실제배열 
void merge(int a[], int lt, int middle, int rt){
	//point변수-m: 시작점, middle: 중간점, n: 끝점
	int i=lt;
	int j=middle+1;
	int k=lt;
	
	//오름차순으로 (작은 조각들을) 배열에 삽입
	while(i<=middle && j<=rt){
		if(a[i]<=a[j]){
			sorted[k]=a[i];
			i++;
		}else{
			sorted[k]=a[j];
			j++;
		}
		k++;
	}
	
	//작은쪽배열을 먼저 다 넣었다면 나머지 데이터도 삽입
	if(i>middle){ //i쪽이 작아서 먼저 끝나면 남은 j를 rt까지 모두 넣음 
		for(int l=j; l<=rt; l++){
			sorted[k]=a[l];
			k++;
		}
	} else{ ////j쪽이 작아서 먼저 끝나면 남은 i를 middle까지 모두 넣음
		for(int l=i; l<=middle; l++){
			sorted[k]=a[l];
			k++;
		}
	}
	
	//마지막 정렬된 결과 삽입 
	for(int t=lt; t<=rt; t++){
		a[t]=sorted[t];
	}
}

void mergeSort(int a[], int lt, int rt){
	//크기가 1보다 큰 경우
	if(lt<rt){
		int middle=(lt+rt)/2; //중앙잡고, 
		mergeSort(a, lt, middle); //왼쪽 병합정렬 ,
		mergeSort(a, middle+1, rt); //오른쪽 병합정렬, 
		merge(a, lt, middle, rt); //정렬된 배열을 "나중에" 합침 
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	mergeSort(a, 0, n-1);
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	return 0;
}

