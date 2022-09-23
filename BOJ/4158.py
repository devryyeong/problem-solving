# 4158] CD

import sys
# input의 type은 str
input = sys.stdin.readline

while True:
  n, m = map(int, input().split())
  if n==0 and m==0:
    break

  a = set()
  for _ in range(n):
    a.add(input())

  b = set()
  for _ in range(m):
    b.add(input())

  print(len(a & b))


