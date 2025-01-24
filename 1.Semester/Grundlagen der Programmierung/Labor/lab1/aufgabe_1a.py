# problema 1 a)

n = 36
check = 1
numbers = list(range(1, n + 1))
primes = []
print("Primzahlen zwischen 1 und", n, "sind: ")

for num in numbers:
    if num == 2:
        primes.append(2)
    if num > 2:
        for i in range(2, num):
            if (num % i) == 0:
                check = 0
            if check == 1:
                primes.append(num)
                break
        check = 1

print(primes)
