# problema 6 (lab 2)

numbers = [10, 33, 45, 54, 41, 78, 33, 87, 99]


def domino(numbers):
    current_sub = []
    longest_sub = []

    for i in range(len(numbers) - 1):
        if numbers[i] % 10 == numbers[i + 1] // 10:
            current_sub.append(numbers[i])
        else:
            current_sub.append(numbers[i])
            if len(current_sub) > len(longest_sub):
                longest_sub = current_sub.copy()
            current_sub = []

    current_sub.append(numbers[-1])

    if len(current_sub) > len(longest_sub):
        longest_sub = current_sub

    return longest_sub


result = domino(numbers)
print("Longest consecutive subsequence is:", result)
