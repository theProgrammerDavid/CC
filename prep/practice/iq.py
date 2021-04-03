
T = int(input())
while(T):
    n=int(input())
    height = [int(i) for i in input().split()]
    iq = [int(i) for i in input().split()]
    # print(heightIq)
    count = 0
    maxval = 0
    for i in range(0, n-1):
        if(height[i] < height[i+1]) and (iq[i] > iq[i+1]):
            count +=1
        else:
            maxval = max(maxval, i)
            count = 0
    print(maxval)
    T-=1