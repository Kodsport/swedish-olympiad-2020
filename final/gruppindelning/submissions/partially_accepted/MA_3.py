#!/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan  2 21:03:10 2020

@author: Mattias Akke
"""

inp = input().split()
n,m = int(inp[0]), int(inp[1])
m_lista = [-1 for _ in range(n)]
for i in range(m):
    inp = input().split()
    m_lista[int(inp[0])-1] = int(inp[1])-1
    m_lista[int(inp[1])-1] = int(inp[0])-1

solution = ""
check = 1
for i in range(0,n,2):
    j = i + 1
    now = 1
    if m_lista[i] != -1 and m_lista[i] == i -1:
        now = int(solution[-1])
    if m_lista[i] != -1 and m_lista[i] == j:
        print(-1)
        check = -1
        break
    solution += str(now)
    if j < n:
        solution += str(now % 2 + 1)
if check != -1:
    print(solution)
            
