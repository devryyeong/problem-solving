# 2562] 최댓값 

list = []
for _ in range(9):
  temp=int(input())
  list.append(temp)
  
m=max(list)
i=list.index(m)
print(f'{m}\n{i+1}')
