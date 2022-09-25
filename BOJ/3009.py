# 3009] 네 번째 점

x, y = [0,0,0], [0,0,0]
for i in range(0,3):
  x[i], y[i] = map(int, input().split())

if(x[0]==x[1]):
  ansX=x[2]
elif(x[0]==x[2]):
  ansX=x[1]
else:
  ansX=x[0]

if(y[0]==y[1]):
  ansY=y[2]
elif(y[0]==y[2]):
  ansY=y[1]
else:
  ansY=y[0]

print(ansX, ansY)