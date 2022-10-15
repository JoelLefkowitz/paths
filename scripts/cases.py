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


def sequences(length, tokens=["", ".", "..", "x"]):
    """
    Generate sequences of ["", ".", "..", "x"] tokens joined wih "/"
    """
    return [
        alphabetise(list(x))
        for n in range(1, length + 1)
        for x in itertools.product(tokens, repeat=n)
    ]


def fmt(x):
    if isinstance(x, list):
        return "{" + ", ".join([f'"{i}"' for i in x]) + "}"

    if isinstance(x, bool):
        return "true" if x else "false"

    return f'"{x}"'


if __name__ == "__main__":
    # path = lambda x: os.sep.join(x)
    # expected = lambda x: os.path.split(os.path.normpath(x))[0]

    # cases = {
    #     "".join(
    #         [
    #             "    {",
    #             fmt(path(i)),
    #             ", ",
    #             fmt(expected(path(i))),
    #             "},",
    #         ]
    #     ): None
    #     for i in sequences(4)
    # }

    # print("\n".join(["{", *cases.keys(), "}"]))


    print(os.path.splitext("")[1])
    print(os.path.splitext(".")[1])
    print(os.path.splitext(".x")[1])
    print(os.path.splitext("a")[1])
    print(os.path.splitext("a.x")[1])
    print(os.path.splitext("..")[1])
    print(os.path.splitext("..x")[1])
    print(os.path.splitext("...")[1])
    print(os.path.splitext("...x")[1])
    print(os.path.splitext("a/b")[1])
    print(os.path.splitext("a/b.x")[1])
    print(os.path.splitext("a/b.x.y")[1])