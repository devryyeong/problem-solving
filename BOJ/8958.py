# 8958] OX퀴즈

t = int(input())

for i in range(t):
  s = input()
  ans=0
  score=0
  for j in s:
    if j=='O':
      score+=1
    else:
      score=0
    ans+=score
  print(ans)
  

