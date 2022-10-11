import os


def extract(path, start, end):
    """
    Pick out lines in a file between the start and end line
    """
    with open(path) as stream:
        lines = stream.read().split("\n")
        lower = lines.index(start) + 1 if start in lines else len(lines)
        upper = lines.index(end) if end in lines else 0
        return "\n".join(lines[lower:upper])


start = "namespace paths {"
end = "} // namespace paths"

src = os.path.normpath(os.path.join(__file__, "..", "..", "src"))


order = [
    "runtime.hpp",
    "resolve.hpp",
    "normalise.hpp",
    "absolute.hpp",
    "relative.hpp",
    "components.hpp",
    "convert.hpp",
    "chunks.hpp",
    "words.hpp",
]

headers = map(
    lambda x: os.path.join(src, x),
    sorted(
        filter(lambda x: x.endswith(".hpp"), os.listdir(src)),
        key=lambda x: order.index(x) if x in order else len(order),
    ),
)

namespace = "\n\n".join(
    filter(lambda x: x != "", map(lambda x: extract(x, start, end), headers))
)

print("```cpp\n" + "\n".join([start, namespace, end]) + "\n```")
