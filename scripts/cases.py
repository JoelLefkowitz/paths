import os
import itertools


def alphabetise(arr):
    """
    Replace all occurrences of "x" with "a", then "b" and so on.
    Example: alphabetise(["x", "x", "y", "x"]) -> ["a", "b", "y", "c"]
    """
    replacements = ["a", "b", "c", "d", "e"][: arr.count("x")]

    for i in replacements:
        arr[arr.index("x")] = i

    return arr


def sequences(length):
    """
    Generate sequences of ["", ".", "..", "x"] tokens joined wih "/"
    """
    return [
        alphabetise(list(x))
        for n in range(1, length + 1)
        for x in itertools.product(["", ".", "..", "x"], repeat=n)
    ]


def fmt(x):
    return (
        "{" + ", ".join([f'"{i}"' for i in x]) + "}"
        if isinstance(x, list)
        else f'"{x}"'
    )


if __name__ == "__main__":
    paths = lambda x: os.path.join(*x)
    expected = lambda x: os.path.isabs(os.path.join(*x))

    cases = {
        "".join(
            [
                "    {",
                fmt(paths(i)),
                ", ",
                "true" if expected(i) else "false",
                "},",
            ]
        ): None
        for i in sequences(5)
    }

    print("\n".join(["{", *cases.keys(), "}"]))
