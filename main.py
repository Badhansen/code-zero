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
        p = input()
    except EOFError:
        break
    
    p = int(p)
    
    for i in range(p):
        name, a, b, c, d, e = str(input()).split(";")
        
        original_name = name
        name = name.lower()

        def value(point):
            res = 0
            for p in point[:-1]:
                if p == '1':
                    res += 1
            if point[8] == '1':
                res += 2
            return res
        
        res = 0
        res += value(a) + value(b) + value(c) + value(d) + value(e)

        lst.append(Node(res, name, original_name))

    lst = sorted(lst, key=attrgetter('score', 'name'))
    lst.reverse()
    print("Case {}:\n".format(case), end="")

    for i in range(len(lst)):
        print(lst[i])

    case += 1
