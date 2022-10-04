# Usage {#mainpage}

```cpp
namespace paths {
    // Gets the path of the current executable file
    std::string filename();

    // Gets the dirname of the current executable file
    std::string dirname();

    // Gets the absolute path of a file
    std::string abspath(const std::string &path);

    // Normalises a path
    // Usage: normpath("a/../a/b/c") -> "a/b/c"
    std::string normpath(const std::string &path);

    // Finds the relative path from a source to a target
    // Usage: relpath("a/b", "a/c") -> "../c"
    std::string relpath(const std::string &source, const std::string &target);

    // Checks if a path is absolute
    bool absolute(const std::string &path);

    // Checks if a path is normalised
    bool normalised(const std::string &path);

    // Checks if a path is relative
    bool relative(const std::string &path);

    // Gets a path's head
    // Python equivalent: os.path.split(os.path.normpath(path))[1]
    // Usage: head("a/b/c") -> "c"
    std::string head(const std::string &path);

    // Gets a path's tail
    // Python equivalent: os.path.split(os.path.normpath(path))[0]
    // Usage: tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // Gets a path's drive
    // Python equivalent: os.path.splitdrive(path)[0]
    // Usage: drive("C:\a\b\c") -> "C:"
    std::string drive(const std::string &path);

    // Determines if a path starts with a prefix
    bool starts_with(const std::string &str, char prefix);

    // Determines if a path starts with a prefix
    bool starts_with(const std::string &str, const std::string &prefix);

    // Determines if a path ends with a suffix
    bool ends_with(const std::string &str, char suffix);

    // Determines if a path ends with a suffix
    bool ends_with(const std::string &str, const std::string &suffix);

    // Joins strings with a delimeter
    // Usage: join({"a", "b", "c"}, ',') -> "a,b,c"
    std::string join(const std::vector<std::string> &strs, char delimiter);

    // Joins strings with a delimeter
    // Usage: join({"a", "b", "c"}, ", ") -> "a, b, c"
    std::string join(
        const std::vector<std::string> &strs,
        const std::string              &delimiter = ", "
    );

    // Splits a string at each occurrence of a delimeter
    // Usage: split("a,b,c", ',') -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);

    // Splits a string at each occurrence of a delimeter
    // Usage: split("a, b, c", ", ") -> {"a", "b", "c"}
    std::vector<std::string> split(
        const std::string &str,
        const std::string &delimiter = " "
    );

    // Joins and normalises path segments
    // Python equivalent: os.path.normpath(os.path.join(*paths))
    // Usage: resolve("a", "b", "c") -> "a/b/c"
    std::string resolve(const std::vector<std::string> &paths);

    // Normalises and splits a path into segments
    // Python equivalent: os.path.normpath(path).split(os.path.sep)
    // Usage: segments("a/b/c") -> {"a", "b", "c"}
    std::vector<std::string> segments(const std::string &path);

    constexpr char unix_sep    = '/';
    constexpr char windows_sep = '\\';

    // Converts a Windows path to a Unix path
    // Usage: unix_path("a\b\c") -> "a/b/c"
    std::string unix_path(const std::string &path);

    // Converts a Unix path to a Windows path
    // Usage: windows_path("a/b/c") -> "a\b\c"
    std::string windows_path(const std::string &path);

    // Converts a path to a Windows path in a Windows
    // environment and Unix path in a Unix environment
    std::string platform_path(const std::string &path);
} // namespace paths
```
