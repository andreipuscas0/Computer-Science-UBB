import turtle

t = turtle.Pen()


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

# twohouses()
