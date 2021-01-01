def isok(m, n):
    if(m*m + m < 2*(n+1)):
        return True
    else:
        return False

def binary_search(n):
    ng = 1000000001000000000
    ok = 0
    while(abs(ok - ng) > 1):
        mid = (int)((ok + ng)/2)
        if(isok(mid, n)):
            ok = mid
        else :
            ng = mid
    return ok

n = int(input())
ans = binary_search(n+1)
print(n - ans + 1)