# 2577] 숫자의 개수 

a = int(input())
b = int(input())
c = int(input())

m = a*b*c
list = [ int(i) for i in str(m)]

for i in range(10):
  print(list.count(i))
