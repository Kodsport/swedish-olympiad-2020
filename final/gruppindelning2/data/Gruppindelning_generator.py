#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jan  1 15:33:28 2020

@author: Mattias Akke
"""

#from gen_common import *
import random
import collections
import sys

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg('m'))
    arg = cmdlinearg('arg')

    par = []

    if arg=='line' or arg=='line_inp':
        ms = random.sample(range(n//2 - 1),k=m)
        if arg=='line_inp':
            par = [[i*2, i*2+1] for i in ms]
        else:
            par = [[i*2+1, i*2+2] for i in ms]
    if arg == 'random':
        ms = random.sample(range(n), k=m*2)
        par = [[ms[i],ms[i+1]] for i in range(0,m*2,2)]
    if arg == 'solvable':
        solution = []
        for i in range(0,n,2):
            frst = random.choice([1,2])
            scnd = frst % 2 + 1
            solution.append(frst)
            solution.append(scnd)
        ms = random.sample(range(n), n)
        q = collections.deque()
        for i in ms:
            q.append(i)
        m_it = m
        while(m_it > 0):
            frst = q.popleft()
            scnd = q.popleft()
            while solution[frst] != solution[scnd]:
                q.append(scnd)
                scnd = q.popleft()
                if len(q) == 1 and solution[frst] != solution[scnd]:
                    q.append(frst)
                    frst = q.popleft()
            par.append([frst, scnd])
            m_it -= 1

    string = ''
    string += str(n) + ' ' + str(m)
    for i in range(m):
        string += '\n'
        string += str(par[i][0] + 1) + ' ' + str(par[i][1] + 1)
    print(string)


def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    #return default[name]

if __name__ == "__main__":
    main()
