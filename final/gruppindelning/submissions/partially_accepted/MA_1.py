#!/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan  2 21:56:59 2020

@author: Mattias Akke
"""

inp = input().split()
n,m = int(inp[0]), int(inp[1])
m_lista = [-1 for _ in range(n)]
for i in range(m):
    inp = input().split()
    m_lista[int(inp[0])-1] = int(inp[1])-1
    m_lista[int(inp[1])-1] = int(inp[0])-1
if n <= 15:
    bit = 0
    while bit <= 2**(n)-1:
        check = 0
        val = 0
        for j in range(n):
            i = n - j - 1
            val = 2**i
            if bit & val == val:
                check += 1
            else:
                check -= 1
            if abs(check) > 1 or (m_lista[i] != -1 and ((bit & 2**(j) > 0) != (bit & 2**(n - 1 - m_lista[i]) > 0))):
                check = 10
                break
        if check != 10:
            string = ''
            for i in range(n):
                val = 2**i
                if bit & val == val:
                    string += '2'
                else:
                    string += '1'
            print(string[::-1])
            break
        bit += 1
    if bit == 2**(n):
        print(-1)
else:
    print(1)
