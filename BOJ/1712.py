# 1712] 손익분기점
# 총수입이 T라고 한다면, T=A/(C-B)

a, b, c = map(int, input().split())
if(b>=c):
  print(-1)
else:
  print(a//(c-b) + 1)