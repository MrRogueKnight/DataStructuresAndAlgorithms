def twoArrays(k, A, B):
    A.sort()
    B.sort(reverse=True)
    
    for i in range(len(A)):
        if A[i] + B[i] < k:
            return "NO"
            
    return "YES"

def solve():
    q = int(input())
    for _ in range(q):
        n, k = map(int, input().split())
        A = list(map(int, input().split()))
        B = list(map(int, input().split()))
        
        res = twoArrays(k, A, B)
        print(res)

solve()