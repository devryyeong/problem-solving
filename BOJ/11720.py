# 11720] 숫자의 합

sum=0
n = int(input())
tmp = int(input())
list = [int(i) for i in str(tmp)]

for i in list:
  sum+=i

print(sum)