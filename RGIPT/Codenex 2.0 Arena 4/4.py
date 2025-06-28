import bisect

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    N, M = map(int, data[idx:idx+2])
    idx +=2
    
    A = []
    B = []
    for _ in range(N):
        a, b = map(int, data[idx:idx+2])
        A.append(a)
        B.append(b)
        idx +=2
    
    C = []
    D = []
    for _ in range(M):
        c, d = map(int, data[idx:idx+2])
        C.append(c)
        D.append(d)
        idx +=2
    
    # Sort A and B arrays
    A_sorted = sorted(A)
    B_sorted = sorted(B)
    
    total = 0
    
    for c, d in zip(C, D):
        # Number of A_i <= d
        count_A = bisect.bisect_right(A_sorted, d)
        # Number of B_i < c
        count_B = bisect.bisect_left(B_sorted, c)
        # The valid shots is count_A - count_B
        total += (count_A - count_B)
    
    print(total)

solve()