# Usage {#mainpage}

```cpp
namespace paths {
    // Gets the path of the current executable file
    std::string filepath();

    // Gets the name of the current executable file
    std::string filename();

    // Gets the path of the directory of the current executable file
    std::string dirpath();

    // Gets the name of the directory of the current executable file
    std::string dirname();

    // Normalises a path
    //
    // Python equivalent:
    //   os.path.normpath(path)
    //
    // Usage:
    //   normpath("a/../a/b/c") -> "a/b/c"
    std::string normpath(const std::string &path);

    // Checks if a path is normalised
    //
    // Usage:
    //   normalised("a/b/c") -> true
    //   normalised("a/../a/b/c") -> false
    bool normalised(const std::string &path);

    // Gets the absolute path of a file
    //
    // Python equivalent:
    //   os.path.abspath(path)
    std::string abspath(const std::string &path);

    // Checks if a path is absolute
    //
    // Python equivalent:
    //   os.path.isabs(path)
    //
    // Usage:
    //   absolute("/a") -> true
    //   absolute("a") -> false
    bool absolute(const std::string &path);

    // Finds the relative path from a source to a target
    //
    // Python equivalent:
    //   os.path.relpath(target, source)
    //
    // Usage:
    //   relpath("a/b", "a/c") -> "../c"
    std::string relpath(const std::string &source, const std::string &target);

    // Checks if a path is relative
    //
    // Python equivalent:
    //   not os.path.isabs(path)
    //
    // Usage:
    //   relative("a") -> true
    //   relative("/a") -> false
    bool relative(const std::string &path);

    // Gets a path's drive
    //
    // Python equivalent:
    //   os.path.splitdrive(path)[0]
    //
    // Usage [Windows]:
    //   drive("C:/a/b") -> "C:"
    //   drive("//a/b/c") -> "//a/b"
    //
    // Usage [Otherwise]:
    //   drive("C:/a/b") -> ""
    //   drive("//a/b/c") -> ""
    std::string drive(const std::string &path);

    // Gets a path's head
    //
    // Python equivalent:
    //   os.path.split(os.path.normpath(path))[1]
    //
    // Usage:
    //   head("a") -> "a"
    //   head("a/b") -> "b"
    //   head("a/b.ext") -> "b.ext"
    std::string head(const std::string &path);

    // Gets a path's tail
    //
    // Python equivalent:
    //   os.path.split(os.path.normpath(path))[0]
    //
    // Usage:
    //   tail("a/b") -> "a"
    //   tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // Gets a path's root
    //
    // Python equivalent:
    //   os.path.split(os.path.splitext(path)[0])[0]
    //
    // Usage:
    //   root("a/b.ext") -> "b"
    std::string root(const std::string &path);

    // Gets a path's extension
    //
    // Python equivalent:
    //   os.path.splitext(path)[1]
    //
    // Usage:
    //   extension("a/b.ext") -> ".ext"
    //   extension("a/b.ext1.ext2") -> ".ext1.ext2"
    //   extension("a/b") -> ""
    std::string extension(const std::string &path);

    // Determines if a path starts with a prefix
    //
    // Usage:
    //   starts_with("abc", "a") -> true
    bool starts_with(const std::string &str, char prefix);

    // Determines if a path starts with a prefix
    //
    // Usage:
    //   starts_with("abc", "a") -> true
    bool starts_with(const std::string &str, const std::string &prefix);

    // Determines if a path ends with a prefix
    //
    // Usage:
    //   ends_with("abc", "c") -> true
    bool ends_with(const std::string &str, char suffix);

    // Determines if a path ends with a prefix
    //
    // Usage:
    //   ends_with("abc", "c") -> true
    bool ends_with(const std::string &str, const std::string &suffix);

    // Joins strings with a delimeter
    //
    // Usage:
    //   join({"a", "b", "c"}, ',') -> "a,b,c"
    std::string join(const std::vector<std::string> &strs, char delimiter);

    // Joins strings with a delimeter
    //
    // Usage:
    //   join({"a", "b", "c"}, ",") -> "a,b,c"
    std::string join(
        const std::vector<std::string> &strs,
        const std::string              &delimiter = ", "
    );

    // Splits a string at each occurrence of a delimeter
    //
    // Usage:
    //   split("a,b,c", ',') -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);

    // Splits a string at each occurrence of a delimeter
    //
    // Usage:
    //   split("a,b,c", ",") -> {"a", "b", "c"}
    std::vector<std::string> split(
        const std::string &str,
        const std::string &delimiter = " "
    );

    // Joins and normalises path segments
    //
    // Python equivalent:
    //   os.path.normpath(os.path.join(*paths))
    //
    // Usage:
    //   resolve("a", "b", "c") -> "a/b/c"
    std::string resolve(const std::vector<std::string> &paths);

    // Normalises and splits a path into segments
    //
    // Python equivalent:
    //   os.path.normpath(path).split(os.path.sep)
    //
    // Usage:
    //   segments("a/b/c") -> {"a", "b", "c"}
    std::vector<std::string> segments(const std::string &path);

    constexpr char unix_sep    = '/';
    constexpr char windows_sep = '\\';

    // Converts a Windows path to a Unix path
    //
    // Usage:
    //   unix_path("a\b\c") -> "a/b/c"
    //   unix_path: {"C:\a\b\c", "/a/b/c" },
    std::string unix_path(const std::string &path);

    // Converts a Unix path to a Windows path
    //
    // Usage:
    //   windows_path("a/b/c") -> "a\b\c"
    //   windows_path("C:/a/b/c") -> "C:\a\b\c"
    std::string windows_path(const std::string &path);

    // Converts a path to a Windows path in a Windows
    // environment and Unix path in a Unix environment
    //
    // Usage [Windows]:
    //   platform_path("a/b") -> "a\\b"
    //   platform_path("a\\b") -> "a\\b"
    //
    // Usage [Otherwise]:
    //   platform_path("a/b") -> "a/b"
    //   platform_path("a\\b") -> "a/b"
    std::string platform_path(const std::string &path);
} // namespace paths
```
