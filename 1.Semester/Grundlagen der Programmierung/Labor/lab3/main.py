import turtle

t = turtle.Pen()


def bigrtk():
    t.reset()
    t.forward(200)
    t.left(90)
    t.forward(100)
    t.left(90)
    t.forward(200)
    t.left(90)
    t.forward(100)
    t.up()


def smallrtk():
    t.right(90)
    t.forward(50)
    t.left(90)
    t.forward(25)
    t.left(90)
    t.forward(50)
    t.left(90)
    t.forward(25)


def draw():
    bigrtk()
    t.left(90)
    t.forward(75)
    t.left(90)
    t.forward(30)
    t.down()
    smallrtk()


def curve():
    for i in range(200):
        t.right(1)
        t.forward(1)


def heart():
    t.left(140)
    t.forward(113)

    curve()
    t.left(120)

    curve()

    t.forward(112)


def square():
    t.forward(200)
    t.left(90)
    t.forward(200)
    t.left(90)
    t.forward(200)
    t.left(90)
    t.forward(200)
    t.left(90)


def door():
    t.forward(80)
    t.right(90)
    t.forward(50)
    t.right(90)
    t.forward(80)


def window():
    t.forward(40)
    t.right(90)
    t.forward(40)
    t.right(90)
    t.forward(40)
    t.right(90)
    t.forward(40)


def roof():
    t.forward(200)
    t.right(120)
    t.forward(200)


def house():
    square()
    t.up()
    t.forward(50)
    t.down()
    t.left(90)
    door()
    t.up()
    t.left(90)
    t.forward(20)
    t.left(90)
    t.forward(60)
    t.down()
    window()
    t.up()
    t.right(90)
    t.forward(140)
    t.left(90)
    t.forward(120)
    t.right(120)
    t.down()
    roof()


def twohouses():
    location()
    house()
    t.up()
    t.right(30)
    t.forward(200)
    t.right(90)
    t.forward(500)
    t.right(180)
    t.down()
    house()


def location():
    t.up()
    t.right(90)
    t.forward(150)
    t.left(90)
    t.down()


def menu():
    print("[1] Aufgabe1")
    print("[2] Aufgabe2")
    print("[3] Aufgabe3")
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
