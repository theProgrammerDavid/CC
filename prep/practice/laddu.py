def findLaddu(arr, N, K): 
	arr.sort() 
	res = 99999999999999999999

	for i in range((N - K) + 1): 
		x = arr[i + K - 1] - arr[i] 
		res = min(res, x) 
	
	return res 

T = int(input())
while(T):
    n,k = [int(i) for i in input().split()]
    sizes = [int(i) for i in input().split()]
    
    print(findLaddu(sizes, n,k))

    T-=1