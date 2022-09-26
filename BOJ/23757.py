# 23757] 아이들과 선물 상자

from heapq import heappush, heappop

n, m = map(int, input().split())
max_heap = []

for c in map(int, input().split()):
  # max_heap에 -c추가 (최대힙으로 사용하기 위해)
  heappush(max_heap, -c) 


ans = 1
for w in map(int, input().split()):
  # max_heap에서 root에 있는 원소 삭제
  # 선물 상자중 가장 큰 것
  gift = -heappop(max_heap)
  # 상자에 자신이 원하는 것보다 적은 개수의 선물이 들어있다면
  if w > gift:
    ans = 0
    break
  # 정상적인 경우라면 가져가고 남은 개수로 업데이트
  else:
    heappush(max_heap, -(gift - w))

print(ans)
