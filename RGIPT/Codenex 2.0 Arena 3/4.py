import sys

def solve():
    N = int(sys.stdin.readline())
    S = int(sys.stdin.readline())

    commands = []
    for _ in range(S):
        a, b, d = map(int, sys.stdin.readline().split())
        commands.append((a, b, d))

    L = int(sys.stdin.readline())

    queries = []
    for _ in range(L):
        queries.append(int(sys.stdin.readline()))

    results = []
    for w_j in queries:
        current_row = w_j // N + 1
        current_col = w_j % N + 1

        for i in range(S):
            a_i, b_i, d_i = commands[i]

            if (a_i <= current_row <= a_i + d_i and
                b_i <= current_col <= b_i + d_i):
                
                temp_row = a_i + (current_col - b_i)
                temp_col = b_i + (d_i - (current_row - a_i))
                
                current_row = temp_row
                current_col = temp_col
            else:
                break
        
        results.append(f"{current_row} {current_col}")
    
    sys.stdout.write("\n".join(results) + "\n")

solve()