# problema 2 (lab 2)

pairs = [(2, 5), (7, 3), (5, 2), (14, 8), (10, 6), (8, 14)]

def findpairs(pairs):

    s = set()

    for (x, y) in pairs:
        s.add((x, y))
        if (y, x) in s:
            print((x, y), "und", (y, x))

findpairs(pairs)