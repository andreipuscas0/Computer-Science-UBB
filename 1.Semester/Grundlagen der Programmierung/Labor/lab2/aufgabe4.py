# problema 4 (lab 2)

lst = ['A', '1', 'B', '2', 'C', '3', 'D', '4']


def encrypt_list(lst):
    key = lst[0]
    encrypted_list = []

    for item in lst:
        if not isinstance(item, str):
            encrypted_list.append(item)
            continue

        encrypted_item = ""

        for char in item:
            if char.isupper():
                encrypted_item += chr(ord(char))
            elif char.islower():
                encrypted_item += chr(ord(char))
            else:
                encrypted_item += char
        encrypted_list.append(encrypted_item)

    return encrypted_list


print(encrypt_list(lst))