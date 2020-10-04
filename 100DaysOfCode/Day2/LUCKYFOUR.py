# cook your dish here
try:
    T=int(input())
    for _ in range(T):
        x = input()
        count=0
        for i in x:
            if i=='4':
                count+=1
        print(count)
        
except:
    pass
