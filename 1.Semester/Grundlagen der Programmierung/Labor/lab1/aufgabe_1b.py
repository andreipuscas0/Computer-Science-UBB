# problema 1 b)

numbers = (12, 13, 14, 15, 14, 13, 14, 15, 16, 17, 18)

def lis(numbers):
    n = len(numbers)
    lis = [1] * n

    for i in range(1, n):
        for j in range(0, i):
            if numbers[i] > numbers[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    maximum = 0

    for i in range(n):
        maximum = max(maximum, lis[i])

    return maximum

print("Die  laengste Teilfolge ist:", lis(numbers) - 1)