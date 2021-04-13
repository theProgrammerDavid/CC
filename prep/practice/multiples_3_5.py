import numpy as np
n = int(input())
x = np.arange(1, n)
# find  multiple of 3 or 5
n= x[(x % 3 == 0) | (x % 5 == 0)]
# print(n[:1000])
# print sum the numbers
print(n.sum())