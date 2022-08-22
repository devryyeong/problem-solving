# 3052] 나머지

list=[]

for i in range(10):
  n=int(input())
  if(n%42 not in list):
    list.append(n%42)

print(len(list))
