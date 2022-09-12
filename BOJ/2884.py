# 2884] 알람 시계

a, b = map(int, input().split())
if(a>=0 and b>=45):
  b-=45
elif(a>=1 and b<45):
  a-=1
  b=b+15
elif(a<1 and b<45):
  a=23
  b=b+15
print(f'{a} {b}')