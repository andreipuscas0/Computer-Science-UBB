from Aufgabe1.aufgabe1 import draw
from Aufgabe2.aufgabe2 import heart
from Aufgabe3.aufgabe3 import twohouses


def menu():
    print("[1] Aufgabe 1")
    print("[2] Aufgabe 2")
    print("[3] Aufgabe 3")
    print("[0] Exit")


option = int(input("Enter your option: "))

while option != 0:
    if option == 1:
        draw()
        break
    elif option == 2:
        heart()
        break
    elif option == 3:
        twohouses()
        break
    else:
        break
