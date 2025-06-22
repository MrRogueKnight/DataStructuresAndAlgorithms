import re

def matchingStrings(stringList, queries):
    counts = {}
    for s in stringList:
        counts[s] = counts.get(s, 0) + 1
    
    res = []
    for q in queries:
        res.append(counts.get(q, 0))
    
    return res

def solve():
    n = int(input())
    arr = []
    for _ in range(n):
        arr.append(input())
    
    q = int(input())
    qry = []
    for _ in range(q):
        qry.append(input())
    
    ans = matchingStrings(arr, qry)
    
    for val in ans:
        print(val)

solve()