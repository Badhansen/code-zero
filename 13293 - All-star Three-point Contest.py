#!/usr/bin/python3

from operator import itemgetter, attrgetter

class Node:
    def __init__(self, score, name, original_name):
        self.score = score
        self.name = name
        self.original_name = original_name
    def __repr__(self):
        return self.original_name + " " + str(self.score)

case = 1

while True:
    lst = []

    try:
        p = int(input())
    except EOFError:
        break

    for i in range(p):
        name, a, b, c, d, e = str(input()).split(";")
        
        original_name = name
        name = name.lower()

        def valueOf(point):
            res = 0
            for p in point[:-1]:
                if p == '1':
                    res += 1
            if point[8] == '1':
                res += 2
            return res
        
        res = 0
        res += valueOf(a) + valueOf(b) + valueOf(c) + valueOf(d) + valueOf(e)

        lst.append(Node(res, name, original_name))

    lst = sorted(lst, key=attrgetter('score'), reverse=True)
    lst = sorted(lst, key=attrgetter('name'))

    print("Case {}:\n".format(case), end="")

    for i in range(len(lst)):
        print(lst[i])

    case += 1




