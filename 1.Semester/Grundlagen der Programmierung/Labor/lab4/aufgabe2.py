def replace_words(file_path, word_to_replace, new_word):
    # Citește conținutul fișierului
    with open(file_path, 'r') as file:
        content = file.read()

    # Schimbă cuvântul vechi cu cel nou
    replaced_content = content.replace(word_to_replace, new_word)

    # Rescrie textul în fișier
    with open(file_path, 'w') as file:
        file.write(replaced_content)

    # Calculează de câte ori a fost schimbat cuvântul
    contor = content.count(word_to_replace)

    return contor


def main():
    file_path = "file.txt"
    word_to_replace = "Krankenwagen"
    new_word = "katze"

    num_replacements = replace_words(file_path, word_to_replace, new_word)

    if num_replacements == 0:
        print(f"No replacements were made in {file_path}.")
    else:
        print(f"Replaced '{word_to_replace}' with '{new_word}' in {file_path} {num_replacements} times.")


main()
