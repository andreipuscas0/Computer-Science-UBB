# problema 3 b)
# Wir verwenden den Algorithmus "Sieb des Eratosthenes"

numbers = (1, 2, 4, 6, 7, 11, 13, 17, 20)
n = len(numbers)

N = 99999


def sieveoferatosthenes(prime, p_size):
    prime[0] = False
    prime[1] = False

    p = 2

    while p * p <= p_size:
        if prime[p]:
            for i in range(p * 2, p_size + 1, p):
                prime[i] = False

        p += 1


def longestprimesubsequence(numbers, n):
    prime = [True] * (N + 1)

    sieveoferatosthenes(prime, N)

    answer = 0

    for i in range(n):
        if prime[numbers[i]]:
            answer += 1

    return answer


print(longestprimesubsequence(numbers, n - 1))
