//#48] �� ���� ��հ� ���� ����� ��
#include <iostream>
#include <algorithm>
#include <cmath> //abs() for float, double
#define NUM 9
using namespace std;
int main(){
	freopen("input.txt","rt",stdin);
	int arr[NUM], sum=0, avg, nearest, diff, min_diff=99;
	
	for(int j=0; j<NUM; j++){
		for(int i=0; i<NUM; i++){
			scanf("%d", &arr[i]);
			sum+=arr[i];
		}
		//(����)/(����)=(����)�̹Ƿ� 9.0���� ������ ��. 
		//(sum/9.0)�� float������ ���ͼ� 0.5 ���Ѵ��� int�� ������ �ݿø�. 
		avg=(sum/9.0)+0.5;
		
		for(int i=0; i<NUM; i++){ //���� ����� �� ã�� 
			diff=abs(avg-arr[i]);
			if(diff<min_diff){
				min_diff=diff;
				nearest=arr[i];
			}else if(diff==min_diff){ //��հ� ����� ���� �� ���̸� �� �� ū �� ���
				if(nearest<arr[i]){
					nearest=arr[i];
				}
			}
		}
		 
		printf("%.0d %.0d\n", avg, nearest);
		
		//���� �ʱ�ȭ
		sum=0;
		min_diff=99; 
	}
	
	return 0;
}
