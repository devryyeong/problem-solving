//62] �������� (Merge Sort) -������ȸ 
#include <iostream>
using namespace std;
int n, sorted[101], a[101]; //sorted[]: �ӽ����Ĺ迭, a{]: �����迭 
void merge(int a[], int lt, int middle, int rt){
	//point����-m: ������, middle: �߰���, n: ����
	int i=lt;
	int j=middle+1;
	int k=lt;
	
	//������������ (���� ��������) �迭�� ����
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
	
	//�����ʹ迭�� ���� �� �־��ٸ� ������ �����͵� ����
	if(i>middle){ //i���� �۾Ƽ� ���� ������ ���� j�� rt���� ��� ���� 
		for(int l=j; l<=rt; l++){
			sorted[k]=a[l];
			k++;
		}
	} else{ ////j���� �۾Ƽ� ���� ������ ���� i�� middle���� ��� ����
		for(int l=i; l<=middle; l++){
			sorted[k]=a[l];
			k++;
		}
	}
	
	//������ ���ĵ� ��� ���� 
	for(int t=lt; t<=rt; t++){
		a[t]=sorted[t];
	}
}

void mergeSort(int a[], int lt, int rt){
	//ũ�Ⱑ 1���� ū ���
	if(lt<rt){
		int middle=(lt+rt)/2; //�߾����, 
		mergeSort(a, lt, middle); //���� �������� ,
		mergeSort(a, middle+1, rt); //������ ��������, 
		merge(a, lt, middle, rt); //���ĵ� �迭�� "���߿�" ��ħ 
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

