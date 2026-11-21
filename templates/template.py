import sys
import threading
from collections import Counter, defaultdict, deque
from heapq import heapify, heappop, heappush
from bisect import bisect_left, bisect_right
from itertools import accumulate, combinations, permutations, product
from math import ceil, comb, gcd, inf, isqrt, lcm, log2

input = sys.stdin.readline


def ints():
    return list(map(int, input().split()))


def solve():
    pass


def main():
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    # big stack for deep recursion (DFS etc.)
    sys.setrecursionlimit(1 << 25)
    threading.stack_size(1 << 27)
    threading.Thread(target=main).start()
