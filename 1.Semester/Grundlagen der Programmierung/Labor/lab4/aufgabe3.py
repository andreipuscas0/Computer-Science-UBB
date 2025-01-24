import random


def main():
    print("Willkommen bei Stein-Papier-Schere!")

    choices = ["Stein", "Papier", "Schere"]

    computer_wins = 0
    user_wins = 0

    for i in range(3):
        computer_choice = random.choice(choices)
        user_choice = input("Wähle deinen Charakter (Stein, Papier, oder Schere): ")

        if user_choice not in choices:
            print("Ungültige Auswahl. Der Computer gewinnt standardmäßig.")
            computer_wins += 1
        else:
            print(f"Der Computer wählt {computer_choice}.")

            if (computer_choice == "Stein" and user_choice == "Schere") or \
                    (computer_choice == "Schere" and user_choice == "Papier") or \
                    (computer_choice == "Papier" and user_choice == "Stein"):
                print("Der Computer gewinnt!")
                computer_wins += 1
            elif computer_choice == user_choice:
                print("Es ist Gleichheit!")
            else:
                print("Du gewinnst!")
                user_wins += 1

    print("\nSpiel vorbei!")
    if computer_wins > user_wins:
        print("Der Computer gewinnt die Best-of-Three-Serie.")
    elif computer_wins < user_wins:
        print("Sie gewinnen die Best-of-Three-Serie.")
    else:
        print("Es ist Gleichheit!")


main()
