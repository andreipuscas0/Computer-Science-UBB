from math import gcd


def simplify(a):
    d = gcd(a[0], a[1])

    return a[0] // d, a[1] // d


def test_simplify():
    assert simplify((2, 2)) == (1, 1)


def add(a, b):
    return simplify((a[0] * b[1] + a[1] * b[0] + a[1] * b[1]))


def test_add


def menu():
    return """
        1 - add frac
        2 - sum fracs
        0 - 


test_simplify()
test_sum_fracs()
test_add()
main()






    fracs = []
