# 2444] 별 찍기 - 7

n = int(input())
for i in range(n):
  print(" "*(n-i-1) + "*"*(i*2+1))

for i in range(n,1,-1):
  print(" "*(n-i+1) + "*"*(i*2-3))
