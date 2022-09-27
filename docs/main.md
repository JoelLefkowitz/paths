# Usage {#mainpage}

```cpp
namespace paths {
    // Gets the path of the current executable file
    std::string filename();

    // Gets the dirname of the current executable file
    std::string dirname();

    // Normalises the path
    // Python equivalent: os.path.normpath(path)
    // Usage: normpath("a/../a/b/c") -> "a/b/c"
    std::string normpath(const std::string &path);

    // Gets the path's head
    // Python equivalent: os.path.split(os.path.normpath(path))[1]
    // Usage: head("a/b/c") -> "c"
    std::string head(const std::string &path);

    // Gets the path's tail
    // Python equivalent: os.path.split(os.path.normpath(path))[0]
    // Usage: tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // Joins and normalises the path segments
    // Python equivalent: os.path.normpath(os.path.join(*paths))
    // Usage: resolve("a", "b", "c") -> "a/b/c"
    std::string resolve(const std::vector<std::string> &paths);

    // Normalises and splits the path into segments
    // Python equivalent: os.path.normpath(path).split(os.path.sep)
    // Usage: segments("a/b/c") -> {"a", "b", "c"}
    std::vector<std::string> segments(const std::string &path);

    // Determines if the path starts with the prefix
    // Python equivalent: str.startswith(prefix)
    // Usage: starts_with("a/b/c", "a/") -> true
    bool starts_with(const std::string &str, char prefix);
    bool starts_with(const std::string &str, const std::string &prefix);

    // Determines if the path ends with the suffix
    // Python equivalent: str.endswith(suffix)
    // Usage: ends_with("a/b/c", "/c") -> true
    bool ends_with(const std::string &str, char suffix);
    bool ends_with(const std::string &str, const std::string &suffix);

    // Joins the strings with the delimeter
    // Python equivalent: delimeter.join(strs)
    // Usage: join({"a", "b", "c"}, ", ") -> "a, b, c"
    std::string join(const std::vector<std::string> &strs, char delimiter);
    std::string join(const std::vector<std::string> &strs, const std::string &delimiter = ", ");

    // Splits the string at the delimeter
    // Python equivalent: str.split(delimeter)
    // Usage: split("a, b, c", ", ") -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);
    std::vector<std::string> split(const std::string &str, const std::string &delimiter = " ");
}
```
