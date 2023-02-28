# Paths

Cross platform OS path operations and executable path retrieval.

This package is inspired by [whereami](https://github.com/gpakosz/whereami) and [std::filesystem](https://en.cppreference.com/w/cpp/filesystem) but with:

- Simple functions
- Readable sources
- C++11 compatibility
- Sensible exception handling

To separate the need to detect the operating system at runtime [detect](https://github.com/JoelLefkowitz/detect) is dropped in.

Since path manipulation is full of edge cases it is paramount to have an extensive set of unit tests. The function implementations and test fixtures are verified to be consistent with python's standard library. To provide support to multiple platforms all test suites are verified against each multiple target environments.

Test environments:

| Platform | Test environment | Status               |
| -------- | ---------------- | -------------------- |
| Linux    | Ubuntu 20.04     | ![test_ubuntu_20.04] |
| Darwin   | MacOS 12         | ![test_macos_12]     |
| Windows  | Windows 2022     | ![test_windows_2022] |

## Status

| Source     | Shields                                                                |
| ---------- | ---------------------------------------------------------------------- |
| Project    | ![latest_release] ![license] ![line_count] ![language_count]           |
| Health     | ![documentation] ![review_action] ![codacy_quality] ![codacy_coverage] |
| Publishers | ![conan_version]                                                       |
| Repository | ![open_issues] ![closed_issues] ![open_pulls] ![closed_pulls]          |
| Activity   | ![contributors] ![monthly_commits] ![last_commit]                      |

## Installation

```bash
conan install paths
```

You can also download the [sources](https://download-directory.github.io?url=https://github.com/joellefkowitz/paths/tree/master/src).

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

In this library the implementation of `normpath` instead calls `normalise` to do most of the heavy lifting. This design allows other functions that act on path chunks such as `resolve` and `segments` to use `normalise` where calling `normpath` would require joining the chunks beforehand and then spliting the normalised result.

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

For more details read the [documentation](https://JoelLefkowitz.github.io/paths).

## Tests

To compile the test suites:

```bash
clang++ -std=c++11 $(find src tests -name "*.cpp") -lpthread -lgtest
```

For more flexible local development and to compile the test suites in parallel install `scons` and the `SConstruct.py` script's dependencies:

```bash
pip install emoji psutil scons
```

To compile the test suites with `scons`:

```bash
scons
```

The runtime tests use environment variables to confirm they retrieve the executable path of the tests binary. For example, if the tests binary is at `dist/test`:

```bash
export FILEPATH=$PWD/dist/test
export FILENAME=test
export DIRPATH=$PWD/dist
export DIRNAME=dist
export ABSPATH=$PWD/dist/a/b/c
```

## Documentation

This repository's documentation is hosted on [Github Pages](https://JoelLefkowitz.github.io/paths).

To generate the documentation locally:

```bash
doxygen
```

## Linters

To run linters:

```bash
nps lint
```

## Formatters

To run formatters:

```bash
nps format
```

## Continuous integration

This repository uses GitHub Actions to lint and test each commit. Each commit should be formatted and its corresponding documentation should be updated.

## Versioning

This repository adheres to semantic versioning standards. For more information on semantic versioning visit [semver](https://semver.org).

Bump2version is used to version and tag changes. For example:

```bash
bump2version patch
```

## Changelog

Please read this repository's [changelog](CHANGELOG.md) for details on changes that have been made.

## Contributing

Please read this repository's guidelines on [contributing](CONTRIBUTING.md) for details on the process for submitting pull requests. Moreover, our [code of conduct](CODE_OF_CONDUCT.md) declares our collaboration standards.

## Contributors

- [Joel Lefkowitz](https://github.com/joellefkowitz) - Initial work

## Remarks

Lots of love to the open source community!

<p align='center'>
    <img width=200 height=200 src='https://media.giphy.com/media/osAcIGTSyeovPq6Xph/giphy.gif' alt='Be kind to your mind' />
    <img width=200 height=200 src='https://media.giphy.com/media/KEAAbQ5clGWJwuJuZB/giphy.gif' alt='Love each other' />
    <img width=200 height=200 src='https://media.giphy.com/media/WRWykrFkxJA6JJuTvc/giphy.gif' alt="It's ok to have a bad day" />
</p>

[test_ubuntu_20.04]: https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/paths/test_ubuntu_20.04.yml "Review action"
[test_macos_12 ]: https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/paths/test_macos_12.yml "Review action"
[test_windows_2022]: https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/paths/test_windows_2022.yml "Review action"
[latest_release]: https://img.shields.io/github/v/tag/joellefkowitz/paths "Latest release"
[license]: https://img.shields.io/github/license/joellefkowitz/paths "License"
[line_count]: https://img.shields.io/tokei/lines/github/joellefkowitz/paths "Line count"
[language_count]: https://img.shields.io/github/languages/count/joellefkowitz/paths "Language count"
[documentation]: https://img.shields.io/readthedocs/paths "Documentation"
[review_action]: https://img.shields.io/github/actions/workflow/status/JoelLefkowitz/paths/review.yml "Review action"
[codacy_quality]: https://img.shields.io/codacy/grade/61e4785a984c42bbbdf1554f025d0f7a "Codacy quality"
[codacy_coverage]: https://img.shields.io/codacy/coverage/61e4785a984c42bbbdf1554f025d0f7a "Codacy coverage"
[conan_version]: https://img.shields.io/conan/v/paths "Conan Version"
[open_issues]: https://img.shields.io/github/issues/joellefkowitz/paths "Open issues"
[closed_issues]: https://img.shields.io/github/issues-closed/joellefkowitz/paths "Closed issues"
[open_pulls]: https://img.shields.io/github/issues-pr/joellefkowitz/paths "Open pull requests"
[closed_pulls]: https://img.shields.io/github/issues-pr-closed/joellefkowitz/paths "Closed pull requests"
[contributors]: https://img.shields.io/github/contributors/joellefkowitz/paths "Contributors"
[monthly_commits]: https://img.shields.io/github/commit-activity/m/joellefkowitz/paths "Monthly commits"
[last_commit]: https://img.shields.io/github/last-commit/joellefkowitz/paths "Last commit"
