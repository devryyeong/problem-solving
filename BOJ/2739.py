# [2739 - 구구단]
# O(10)-> O(1) (N과 상관없이 무조건 10번 반복하므로)
N = int(input())
for i in range(1,10):
  print(f'{N} * {i} = {N*i}')