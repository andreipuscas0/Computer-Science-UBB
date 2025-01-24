def longest_word(filename):
    f = open(filename, 'r')
    result = []

    for line in f:
        words = line.split(' ')
        max_length = 0

        for word in words:
            if len(word) > max_length:
                max_length = len(word)

        result.append(max_length)

    f.close()
    return result