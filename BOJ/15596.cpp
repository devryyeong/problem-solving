#include <vector>
using namespace std;

long long sum(vector <int> &a){
  long long result=0;

  for(vector<int>::iterator iter= a.begin(); iter<a.end(); iter++){
    result+=*iter; //iter 쓸때 {*} 까먹지말자
  }
  
  return result;
}