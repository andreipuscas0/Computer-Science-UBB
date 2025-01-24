import turtle

t = turtle.Turtle()

# Folosim t.goto(-30, 50) pentru a porni din centrul ecranului


def letter_a():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(65)
    t.forward(100)

    t.goto(-30, 50)
    t.right(50)
    t.forward(100)

    t.up()
    t.goto(-5, -10)
    t.right(65)
    t.down()
    t.forward(60)


def letter_b():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(90)
    t.forward(150)

    t.up()
    t.goto(-30, 50)
    t.down()
    t.right(-90)
    t.circle(-37.5, 180)

    t.up()
    t.goto(-30, -25)
    t.down()
    t.right(180)
    t.circle(-37.5, 180)


def letter_c():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.circle(50, -180)


def letter_d():
    t.penup()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.left(90)
    t.forward(100)
    t.up()
    t.goto(-30, 50)
    t.right(90)
    t.down()
    t.circle(50, 180)


def letter_e():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.left(90)
    t.down()
    t.forward(100)
    t.right(90)
    t.forward(40)
    t.penup()

    t.goto(-30, 50)
    t.down()
    t.left(90)
    t.forward(50)
    t.right(90)
    t.forward(40)
    t.up()

    t.goto(-30, 50)
    t.down()
    t.forward(40)


def letter_f():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.left(90)
    t.down()
    t.forward(100)
    t.right(90)
    t.forward(40)
    t.up()

    t.goto(-30, 50)
    t.left(90)
    t.forward(50)
    t.right(90)
    t.down()
    t.forward(40)


def letter_g():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(180)
    t.circle(50, 270)
    t.left(90)
    t.forward(50)


def letter_h():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.right(90)
    t.down()
    t.forward(100)
    t.up()

    t.back(50)
    t.left(90)
    t.down()
    t.forward(50)
    t.up()

    t.left(90)
    t.forward(50)
    t.right(180)
    t.down()
    t.forward(100)


def letter_i():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(90)
    t.forward(100)


def letter_j():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.forward(30)
    t.right(90)
    t.forward(150)
    t.circle(-30, 180)


def letter_k():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(90)
    t.forward(150)
    t.up()

    t.down()
    t.goto(-30, -20)
    t.left(45)
    t.forward(100)
    t.up()

    t.down()
    t.goto(-30, -20)
    t.left(90)
    t.forward(100)


def letter_l():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(90)
    t.forward(150)
    t.up()

    t.down()
    t.right(-90)
    t.forward(70)


def letter_m():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(90)
    t.forward(150)

    t.goto(-30, 50)
    t.goto(20, -20)
    t.goto(65, 50)
    t.goto(65, -100)


def letter_n():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(90)
    t.forward(150)

    t.goto(-30, 50)
    t.goto(50, -90)
    t.goto(50, 50)


def letter_o():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)
    t.down()
    t.circle(50, None, 50)


def letter_p():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(90)
    t.forward(150)
    t.up()

    t.goto(-30, -30)
    t.left(90)
    t.down()
    t.circle(40, 180)


def letter_q():
    t.penup()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.circle(50, None, 50)
    t.up()
    t.goto(-20, 60)
    t.down()
    t.right(45)
    t.forward(40)


def letter_r():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.right(90)
    t.down()
    t.forward(150)
    t.goto(-30, 50)
    t.right(-90)
    t.circle(-45, 180, 50)
    t.up()

    t.goto(-30, -40)
    t.left(135)
    t.down()
    t.forward(75)


# def letter_s():


def letter_t():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.forward(100)
    t.goto(20, 50)
    t.right(90)
    t.forward(100)


def letter_u():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(90)
    t.forward(100)
    t.circle(50, 180, 50)
    t.forward(100)


def letter_v():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(65)
    t.forward(100)
    t.left(130)
    t.forward(100)


def letter_w():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(65)
    t.forward(100)
    t.left(130)
    t.forward(100)

    t.right(120)
    t.forward(100)
    t.left(130)
    t.forward(100)


def letter_x():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(50)
    t.forward(155)
    t.up()

    t.goto(50, 50)
    t.right(70)
    t.down()
    t.forward(150)


def letter_y():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.right(65)
    t.forward(100)
    t.left(130)
    t.forward(100)

    t.up()
    t.goto(13, -43)
    t.left(25)
    t.down()
    t.back(100)


def letter_z():
    t.up()
    t.goto(-30, 50)
    t.pensize(3)

    t.down()
    t.forward(100)
    t.right(130)
    t.forward(130)
    t.left(130)
    t.forward(100)


letter_h()
