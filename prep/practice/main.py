T = int(input())
while(T):
    n = int(input())
    words = input().split()

    started = False
    error = False

    for word in words:
        if word == "start" or word=="restart":
            started = True
        if word=="stop":
            if not started:
                error = True
            else:
                started = False
    
    if error:
        print(404)
    else:
        print(200)
    T-=1
