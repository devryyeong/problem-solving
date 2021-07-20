//#48] 각 행의 평균과 가장 가까운 값
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
		//(정수)/(정수)=(정수)이므로 9.0으로 나눠야 함. 
		//(sum/9.0)이 float형으로 들어와서 0.5 더한다음 int로 받으면 반올림. 
		avg=(sum/9.0)+0.5;
		
		for(int i=0; i<NUM; i++){ //가장 가까운 값 찾기 
			diff=abs(avg-arr[i]);
			if(diff<min_diff){
				min_diff=diff;
				nearest=arr[i];
			}else if(diff==min_diff){ //평균과 가까운 값이 두 개이면 그 중 큰 값 출력
				if(nearest<arr[i]){
					nearest=arr[i];
				}
			}
		}
		 
		printf("%.0d %.0d\n", avg, nearest);
		
		//변수 초기화
		sum=0;
		min_diff=99; 
	}
	
	return 0;
}
