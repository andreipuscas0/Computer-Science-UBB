import turtle

t = turtle.Pen()


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


# heart()
