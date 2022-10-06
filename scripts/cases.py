import os
import itertools


def alphbetise(arr):
    """
    Replace all occurances of "x" with "a", then "b" and so on.
    Example: alphbetise("x/x/y/x") -> "a/b/y/c"
    """
    replacements = ["a", "b", "c", "d"][: arr.count("x")]

    for i in replacements:
        arr[arr.index("x")] = i

    return arr


def sequences(length=3):
    """
    Generate sequences of ["", ".", "..", "x"] tokens joined wih "/"
    """
    return [
        "/".join(i)
        for i in [
            alphbetise(list(x))
            for n in range(1, length + 1)
            for x in itertools.product(["", ".", "..", "x"], repeat=n)
        ]
    ]


if __name__ == "__main__":
    expected = os.path.normpath
    cases = ["".join(['    {"', i, '", "', expected(i), '"},']) for i in sequences(3)]
    print("\n".join(["{", *cases, "}"]))
