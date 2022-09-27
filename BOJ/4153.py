# 4153] 직각삼각형 

while True:
  a,b,c = map(int, input().split())
  if a==0:
    break;
  else:
    m=max(a,b,c)
    if(pow(a,2) + pow(b,2) == pow(m,2)):
      print('right')
    elif(pow(b,2) + pow(c,2) == pow(m,2)):
      print('right')
    elif(pow(a,2) + pow(c,2) == pow(m,2)):
      print('right')
    else:
      print('wrong')
