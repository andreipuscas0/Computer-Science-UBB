# problema 5 (lab 2)

n = 45
db = 0

badnums = '1235689'
lsgood = []

for i in range(0, n + 1):
    numbers = [int(j) for j in str(i)]
    for j in numbers:
        if str(j) in badnums:
            break
    else:
        lsgood.append(i)
        db += 1


print(lsgood, "Anzahl der Elemente =" , db)
