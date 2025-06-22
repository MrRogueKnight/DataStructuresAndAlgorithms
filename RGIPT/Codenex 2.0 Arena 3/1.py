import re

def solve():
    n = int(input())
    for _ in range(n):
        s = input()
        
        pat = r"^[_.]\d+[a-zA-Z]*_?$"
        
        if re.fullmatch(pat, s):
            print("VALID")
        else:
            print("INVALID")

solve()