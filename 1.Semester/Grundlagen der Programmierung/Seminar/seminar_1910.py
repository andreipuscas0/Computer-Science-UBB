def find_sum(numbers, sum):
    for i in range(len(numbers) - 1):
        for j in range(i + 1, len(numbers)):
            if sum - numbers[i] in numbers:
                return True
    return False


def test_find_sum():
    assert find_sum([1, 2, 9], 3) == True
    assert find_sum([1, 2, 9], 12) == False


def generate_multiple(number, count):
    multi = [number]

    for i in range(2, count + 1):
        multi.append(number * i)

    return multi


def test_generate():
    assert generate_multiple(3, 4) == [3, 6, 9, 12]
    assert generate_multiple(2, 2) == [2, 4]


def big_sum(a, b):
    s = 0
    t = 0

    for i in range(len(a) - 1, -1, -1):
        sum = int(a[i]) + int(b[i]) + t

        if sum > 9:
            t = 1
        else:
            t = 0

        s = p * (sum % 10) + s
        p *= 10

    if t == 1:
        s = p + s
    return str(s)


def test_big_sum():
    assert big_sum('123', '123') == '246'
    assert big_sum('123', '129') == '252'
    assert big_sum('999', '101') == '1100'


def reverse(word):
    vok = 'aeiou'
    vok_in_word = []
    new_word = ''

    for ch in word:
        if ch in vok:
            vok_in_word.append(ch)

    i = 1
    for ch in word:
        if ch not in vok:
            new_word += ch
        else:
            new_word += vok_in_word[-i]
            i += 1

    return new_word


def test_reverse():
    assert reverse('Terminator') == 'Torminater'
