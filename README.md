# Paths

Cross platform OS path operations and executable path retrieval.

![Review](https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/paths/review.yml)
![Quality](https://img.shields.io/codacy/grade/61e4785a984c42bbbdf1554f025d0f7a)
![Coverage](https://img.shields.io/codacy/coverage/61e4785a984c42bbbdf1554f025d0f7a)

This package is inspired by [whereami](https://github.com/gpakosz/whereami) and [std::filesystem](https://en.cppreference.com/w/cpp/filesystem) but with:

- Simple functions
- Readable sources
- C++11 compatibility
- Sensible exception handling

To separate the need to detect the operating system at runtime [detect](https://github.com/JoelLefkowitz/detect) is dropped in.

Since path manipulation is full of edge cases it is paramount to have an extensive set of unit tests. The function implementations and test fixtures are verified to be consistent with python's standard library. To provide support to multiple platforms all test suites are verified against each multiple target environments.

Test environments:

| Test environment | Status                                                                                                      |
| ---------------- | ----------------------------------------------------------------------------------------------------------- |
| Ubuntu 20.04     | ![Linux](https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/paths/test_ubuntu_20.04.yml)   |
| MacOS 12         | ![Darwin](https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/paths/test_macos_12.yml)      |
| Windows 2022     | ![Windows](https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/paths/test_windows_2022.yml) |

## Installation

```bash
conan install paths
```

You can also download the [sources](https://download-directory.github.io?url=https://github.com/joellefkowitz/paths/tree/master/src).

## Documentation

Documentation and more detailed examples are hosted on [Github Pages](https://joellefkowitz.github.io/paths).

## Usage

```cpp
namespace paths {
    // Gets the path of the current executable file
    std::string filepath();

    // Gets the name of the current executable file
    std::string filename();

    // Gets the path of the directory of the current
    // executable file
    std::string dirpath();

    // Gets the name of the directory of the current
    // executable file
    std::string dirname();

    // Joins and normalises path chunks
    //
    // Complies with its python equivalent:
    //   os.path.normpath(os.path.join(*paths))
    //
    // Usage:
    //   resolve({"a", "b", "c"}) -> "a/b/c"
    //   resolve({"a", "b", "..", "c"}) -> "a/c"
    std::string resolve(const std::vector<std::string> &paths);

    // Splits a path into normalised segments
    //
    // Complies with its python equivalent:
    //   [i for i in os.path.normpath(path).split(os.sep) if i != ""]
    //
    // Usage:
    //   segments("") -> {"."}
    //   segments(".") -> {"."}
    //   segments("/") -> {}
    //   segments("a/b") -> {"a", "b"}
    //   segments("/a/b") -> {"a", "b"}
    //   segments("a/b/../c") -> {"a", "c"}
    //
    // [Windows]
    //   segments("C:/a/b") -> {"a", "b"}
    //   segments("//a/b/c") -> {"c"}
    //
    // [Otherwise]
    //   segments("C:/a/b") -> {"C:", "a", "b"}
    //   segments("//a/b/c") -> {"a", "b", "c"}
    std::vector<std::string> segments(const std::string &path);

    // Normalises path chunks
    //
    // Complies with its python equivalent:
    //   os.path.normpath(os.path.join(*paths)).split(os.sep)
    //
    // Usage:
    //   normalise({}) -> {"."}
    //   normalise({""}) -> {"."}
    //   normalise({"a", ".", "b"}) -> {"a", "b"}
    //   normalise({"a", "..", "b"}) -> {"b"}
    std::vector<std::string> normalise(const std::vector<std::string> &paths);

    // Normalises a path
    //
    // Complies with its python equivalent:
    //   os.path.normpath(path)
    //
    // Usage:
    //   normpath("") -> "."
    //   normpath("/..") -> "/"
    //   normpath("a/./b") -> "a/b"
    //   normpath("a/../b/c") -> "a/c"
    //
    // [Windows]
    //   normpath("C:/..") -> "C:"
    //   normpath("//a/b/..") -> "//a/b"
    //
    // [Otherwise]
    //   normpath("C:/..") -> ""
    //   normpath("//a/b") -> "//a/b"
    //   normpath("//a/b/..") -> "//a"
    //   normpath("///a/b") -> "/a/b"
    std::string normpath(const std::string &path);

    // Gets the absolute path of a file using the
    // current executable's directory as a base.
    //
    // Complies with its python equivalent:
    //   os.path.abspath(path)
    //
    // Usage:
    //   abspath("a/b/c") -> <current executable's directory>/a/b/c
    std::string abspath(const std::string &path);

    // Checks if a path is absolute
    //
    // Complies with its python equivalent:
    //   os.path.isabs(path)
    //
    // Usage:
    //   absolute("/a") -> true
    //   absolute("a") -> false
    bool absolute(const std::string &path);

    // Finds the relative path from a source to a target
    //
    // Complies with its python equivalent:
    //   os.path.relpath(target, source)
    //
    // Usage:
    //   relpath("a/b", "a/c") -> "../c"
    std::string relpath(const std::string &source, const std::string &target);

    // Checks if a path is relative
    //
    // Complies with its python equivalent:
    //   not os.path.isabs(path)
    //
    // Usage:
    //   relative("a") -> true
    //   relative("/a") -> false
    bool relative(const std::string &path);

    // Gets a path's drive
    //
    // Complies with its python equivalent:
    //   os.path.splitdrive(path)[0]
    //
    // Usage:
    // [Windows]
    //   drive("C:/a/b") -> "C:"
    //   drive("//a/b/c") -> "//a/b"
    //
    // [Otherwise]
    //   drive("C:/a/b") -> ""
    //   drive("//a/b/c") -> ""
    std::string drive(const std::string &path);

    // Gets a path's head
    //
    // Complies with its python equivalent:
    //   os.path.split(os.path.normpath(path))[1]
    //
    // Usage:
    //   head("") -> "."
    //   head(".") -> "."
    //   head("a") -> "a"
    //   head("a/b") -> "b"
    //
    // [Windows]
    //   head("C:") -> ""
    //   head("//a/b") -> "b"
    //
    // [Otherwise]
    //   head("C:") -> "C:"
    //   head("//a/b") -> "b"
    std::string head(const std::string &path);

    // Gets a path's tail
    //
    // Complies with its python equivalent:
    //   os.path.split(os.path.normpath(path))[0]
    //
    // Usage:
    //   tail("") -> ""
    //   tail(".") -> ""
    //   tail("a") -> ""
    //   tail("/a") -> "/"
    //   tail("a/b") -> "a"
    //   tail("a/b/c") -> "a/b"
    //
    // [Windows]
    //   tail("C:") -> ""
    //   tail("//a/b") -> "//a/b"
    //   tail("//a/b/c") -> "//a/b"
    //
    // [Otherwise]
    //   tail("C:") -> ""
    //   tail("//a/b") -> "//a"
    //   tail("//a/b/c") -> "//a/b"
    std::string tail(const std::string &path);

    // Gets a path's extension
    //
    // Complies with its python equivalent:
    //   os.path.splitext(path)[1]
    //
    // Usage:
    //   extension("a") -> ""
    //   extension("a/b") -> ""
    //   extension("a/b.x") -> ".x"
    //   extension("a/b.x.y") -> ".y"
    std::string extension(const std::string &path);

    constexpr char posix_sep   = '/';
    constexpr char windows_sep = '\\';

    // Converts a Windows path to a Posix path
    //
    // Usage:
    //   posix_path("") -> ""
    //   posix_path(".") -> "."
    //   posix_path("a\b\c") -> "a/b/c"
    //   posix_path("C:\a\b\c") -> "/a/b/c"
    //   posix_path("\\a\b\c") -> "//a/b/c"
    std::string posix_path(const std::string &path);

    // Converts a Posix path to a Windows path
    //
    // Usage:
    //   windows_path("") -> ""
    //   windows_path(".") -> "."
    //   windows_path("a/b/c") -> "a\b\c"
    //   windows_path("C:/a/b/c") -> "C:\a\b\c"
    //   windows_path("//a/b/c") -> "\\a\b\c"
    std::string windows_path(const std::string &path);

    // Converts a path to a Windows path in a Windows
    // environment and Posix path in a Posix environment
    //
    // Usage:
    // platform_path("") -> ""
    // platform_path(".") -> "."
    //
    // [Windows]
    //   platform_path("a/b") -> "a\b"
    //   platform_path("a\b") -> "a\b"
    //
    // [Otherwise]
    //   platform_path("a/b") -> "a/b"
    //   platform_path("a\b") -> "a/b"
    std::string platform_path(const std::string &path);

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
        const std::string              &delimiter
    );

    // Splits a string at each occurrence of a delimeter
    //
    // Usage:
    //   split("abc", '') -> {"a", "b", "c"}
    //   split("a,b,c", ',') -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);

    // Splits a string at each occurrence of a delimeter
    //
    // Usage:
    //   split("abc", "") -> {"a", "b", "c"}
    //   split("a,b,c", ",") -> {"a", "b", "c"}
    std::vector<std::string> split(
        const std::string &str,
        const std::string &delimiter
    );

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
} // namespace paths
```

## Commentary

### Terminology

Effort has been made to use consistent terminology in this library's source. These terms appear frequently as variable names and in docstrings:

- `segments`: Normalised path chunks
- `components`: Parts of a path such as its head and tail
- `chunks`: Substrings

### Notes

Cross platform support for file discovery and iteration can be added in a future release:

- `exists`
- `lexists`
- `isfile`
- `islink`
- `isdir`
- `listdir`
- `iterdir`

To increase this library's ease of use there are some notable differences with python's standard library:

Names:

- The functions to join and split path chunks are called `resolve` and `segments` whereas `join` and `split` act on strings and have a delimeter parameter.

Behaviour:

- `resolve`, `segments`, `head`, and `tail`, normalise paths
- `resolve` takes a vector of paths strings rather than being variadic

Parameters:

- `relpath` can take an empty source parameter
- `split` can take an empty delimeter parameter

Internals:

The docstring for `normalise` says:

```cpp
// Complies with its python equivalent:
//   os.path.normpath(os.path.join(*paths)).split(os.sep)
```

In this library the implementation of `normpath` instead calls `normalise` to do most of the heavy lifting. This design allows other functions that act on path chunks such as `resolve` and `segments` to use `normalise` where calling `normpath` would require joining the chunks beforehand and then splitting the normalised result.

The docstring for `tail` says:

```cpp
// Complies with its python equivalent:
//   os.path.split(os.path.normpath(path))[0]
//
// ...
//
//   tail("//a/b/c") -> "//a/b"
```

However its python equivalent produces a different and unexpected result which this library deviates from in the interest of consistency:

```py
os.path.split(os.path.normpath("//a/b/c"))[0] -> "//a/b/"
```

## Tooling
 
Set the `CPPPATH` and `LIBPATH` environment variables:

```bash
export CPPPATH="/usr/include"
export LIBPATH="/usr/lib"
```

### Tests

To run tests:

```bash
scons
```

```bash
./dist/tests
```

The runtime tests use environment variables to confirm they retrieve the executable path of the tests binary. For example, if the tests binary is at `dist/test`:

```bash
export DIRNAME=dist
export FILENAME=tests
export DIRPATH=$PWD/$DIRNAME
export ABSPATH=$PWD/$DIRNAME/a/b/c
export FILEPATH=$PWD/$DIRNAME/$FILENAME
```

### Documentation

To generate the documentation locally:

```sh
doxygen
```

### Linters

To run linters:

```sh
cspell . --dot
cppclean . --include-path $CPPPATH
cppcheck **/*.*pp -q --enable=all --suppressions-list=.cppcheck
scons --typecheck
```

### Formatters

To run formatters:

```sh
prettier . --write
clang-format -i **/*.*pp
```

## Contributing

Please read this repository's [Code of Conduct](CODE_OF_CONDUCT.md) which outlines our collaboration standards and the [Changelog](CHANGELOG.md) for details on breaking changes that have been made.

This repository adheres to semantic versioning standards. For more information on semantic versioning visit [SemVer](https://semver.org).

Bump2version is used to version and tag changes. For example:

```bash
bump2version patch
```

### Contributors

- [Joel Lefkowitz](https://github.com/joellefkowitz) - Initial work

## Remarks

Lots of love to the open source community!

<p align='center'>
    <img width=200 height=200 src='https://media.giphy.com/media/osAcIGTSyeovPq6Xph/giphy.gif' alt='Be kind to your mind' />
    <img width=200 height=200 src='https://media.giphy.com/media/KEAAbQ5clGWJwuJuZB/giphy.gif' alt='Love each other' />
    <img width=200 height=200 src='https://media.giphy.com/media/WRWykrFkxJA6JJuTvc/giphy.gif' alt="It's ok to have a bad day" />
</p>
