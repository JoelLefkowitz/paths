# Usage {#mainpage}

Copy the sources in place:

- [runtime.cpp][runtime_cpp]
- [runtime.hpp][runtime_hpp]

- [strings.cpp][strings_cpp]
- [strings.hpp][strings_hpp]

- [detect.hpp][detect_hpp]

```cpp
namespace paths {
    // filename() -> "Path to the current executable file"
    std::string filename();

    // dirname() -> "Directory of the current executable file"
    std::string dirname();

    // join({"a", "b", "c"}, ", ") -> "a, b, c"
    std::string join(const std::vector<std::string> &strs, char delimiter);
    std::string join(const std::vector<std::string> &strs, const std::string &delimiter = ", ");

    // split("a, b, c", ", ") -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);
    std::vector<std::string> split(const std::string &str, const std::string &delimiter = " ");

    // head("a/b/c") -> "c"
    std::string head(const std::string &path);

    // tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // resolve("a", "b", "c") -> "a/b/c"
    std::string resolve(const std::vector<std::string> &paths);

    // segments("a/b/c") -> {"a", "b", "c"}
    std::vector<std::string> segments(const std::string &path);
}
```

Edge cases for splitting strings are handled the same way as the python standard library:

```cpp
split("", "/") -> {""}
split("/", "/") -> {"", ""}
split("//", "/") -> {"", "", ""}
split("///", "/") -> {"", "", "", ""}
```

```cpp
split("/a", "/") -> {"", "a"}
split("a/", "/") -> {"a", ""}
split("/a/", "/") -> {"", "a", ""}
```

<!-- Raw links -->

[runtime_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/dirname/master/src/runtime.cpp
[runtime_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/dirname/master/src/runtime.hpp
[strings_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/dirname/master/src/strings.cpp
[strings_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/dirname/master/src/strings.hpp
[detect_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/dirname/master/src/detect.hpp
