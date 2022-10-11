import os
import itertools


def alphabetise(arr):
    """
    Replace all occurrences of "x" with "a", then "b" and so on.
    Example: alphabetise("x/x/y/x") -> "a/b/y/c"
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
        alphabetise(list(x))
        for n in range(1, length + 1)
        for x in itertools.product(["", ".", "..", "x"], repeat=n)
    ]


def fmt_arr(items):
    return "{" + ", ".join([f'"{i}"' for i in items]) + "}"


if __name__ == "__main__":

    cases = [
        "".join(
            [
                " " * 4,
                "{",
                fmt_arr(i),
                ", ",
                fmt_arr(os.path.normpath("/".join(i)).split("/")),
                "}",
                ",",
            ]
        )
        for i in sequences(3)
    ]
    print("\n".join(["{", *cases, "}"]))
