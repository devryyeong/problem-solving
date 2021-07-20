#include <iostream>

int main() {
    int n, m, sum=0;
    scanf("%d %d", &n, &m); 
    //vector<int> bus(n);
    int bus[101];
    int charge[101][101];

    for(int i=1; i<=m; i++){
      scanf("%d", &bus[i]);
    }
    
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        scanf("%d", &charge[i][j]);
      }
    }
    
    for(int i=1; i<m; i++){
    	sum+=charge[bus[i]][bus[i+1]];
	}
	printf("%d", sum);

    return 0;
}

