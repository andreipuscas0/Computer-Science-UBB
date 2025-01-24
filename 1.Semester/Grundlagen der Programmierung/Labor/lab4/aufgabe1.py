import turtle

t = turtle.Pen()


def draw_character(instructions):
    for instruction in instructions:
        if instruction == 'W':
            t.forward(10)
        elif instruction == 'S':
            t.back(10)
        elif instruction == 'D':
            t.right(45)
        elif instruction == 'A':
            t.left(45)
        elif instruction == 'F':
            t.up()
        elif instruction == 'G':
            t.down()
