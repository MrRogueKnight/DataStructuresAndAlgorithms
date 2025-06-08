import sys
import heapq

def solve():
    N = int(sys.stdin.readline())
    customers = []
    for _ in range(N):
        T_i, L_i = map(int, sys.stdin.readline().split())
        customers.append((T_i, L_i))
    customers.sort()
    
    heap = []
    current_time = 0
    total_waiting_time = 0
    index = 0
    
    while index < N or heap:
        while index < N and customers[index][0] <= current_time:
            T_i, L_i = customers[index]
            heapq.heappush(heap, (L_i, T_i))
            index += 1
        
        if heap:
            L_i, T_i = heapq.heappop(heap)
            current_time += L_i
            total_waiting_time += current_time - T_i
        else:
            if index < N:
                current_time = customers[index][0]
    
    average_waiting_time = total_waiting_time // N
    print(average_waiting_time)

solve()