# 10872] 팩토리얼

r = int(input())

def factorial(r):
  if r==0: 
    return 1
  else:
    return r*factorial(r-1)
  
print(factorial(r))
