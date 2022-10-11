# Paths

OS specific path operations and executable path retrieval.

This package is inspired by [whereami][whereami] and [std::filesystem][std_filesystem] but with:

- Simple functions
- Readable sources
- C++11 compatability
- Sensible exception handling

To separate the need to detect the operating system at runtime [detect][detect] is dropped in.

Since path manipulation is full of edge cases it is paramount to have an extensive set of unit tests. The function implementations and test fixtures are verified to be consistent with python's standard library. To provide support to multiple platforms all test suites are verified against each multiple target environments.

Test environments:

| Platform | Test environment | Status                                                |
| -------- | ---------------- | ----------------------------------------------------- |
| Linux    | Ubuntu 20.04     | ![test_ubuntu_20.04_shield][test_ubuntu_20.04_shield] |
| Darwin   | MacOS 12         | ![test_macos_12_shield][test_macos_12_shield]         |
| Windows  | Windows 2022     | ![test_windows_2022_shield][test_windows_2022_shield] |

## Status

| Source     | Shields                                                                                                                           |
| ---------- | --------------------------------------------------------------------------------------------------------------------------------- |
| Project    | ![release][release_shield] ![license][license_shield]                                                                             |
| Health     | ![publish_docs][publish_docs_shield] ![review][review_shield] ![codacy][codacy_shield] ![codacy_coverage][codacy_coverage_shield] |
| Repository | ![issues][issues_shield] ![issues_closed][issues_closed_shield] ![pulls][pulls_shield] ![pulls_closed][pulls_closed_shield]       |
| Activity   | ![contributors][contributors_shield] ![monthly_commits][monthly_commits_shield] ![last_commit][last_commit_shield]                |

## Installation

### Sources

Download the [sources][sources].

## Usage

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
    //   os.path.normpath(path).split(os.path.sep)
    //
    // Usage:
    //   segments("a/b/c") -> {"a", "b", "c"}
    //   segments("a/b/../c") -> {"a", "c"}
    std::vector<std::string> segments(const std::string &path);

    // Normalises path chunks
    //
    // Usage:
    //   normalise({"a", ".", "b"}) -> {"a", "b"}
    //   normalise({"a", "..", "b"}) -> {"b"}
    std::vector<std::string> normalise(const std::vector<std::string> &paths);

    // Normalises a path
    //
    // Complies with its python equivalent:
    //   os.path.normpath(path)
    //
    // Usage:
    //   normpath("a/../b/c") -> "a/c"
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
    // Complies with its python equivalent:
    //   os.path.split(os.path.normpath(path))[1]
    //
    // Usage:
    //   head("a") -> "a"
    //   head("a/b") -> "b"
    //   head("a/b.ext") -> "b.ext"
    std::string head(const std::string &path);

    // Gets a path's tail
    //
    // Complies with its python equivalent:
    //   os.path.split(os.path.normpath(path))[0]
    //
    // Usage:
    //   tail("a/b") -> "a"
    //   tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // Gets a path's root
    //
    // Complies with its python equivalent:
    //   os.path.split(os.path.splitext(path)[0])[0]
    //
    // Usage:
    //   root("a/b.ext") -> "b"
    std::string root(const std::string &path);

    // Gets a path's extension
    //
    // Complies with its python equivalent:
    //   os.path.splitext(path)[1]
    //
    // Usage:
    //   extension("a/b.ext") -> ".ext"
    //   extension("a/b.ext1.ext2") -> ".ext1.ext2"
    //   extension("a/b") -> ""
    std::string extension(const std::string &path);

    constexpr char unix_sep    = '/';
    constexpr char windows_sep = '\\';

    // Converts a Windows path to a Unix path
    //
    // Usage:
    //   unix_path("a\b\c") -> "a/b/c"
    //   unix_path("C:\a\b\c") -> "/a/b/c"
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

    // Joins strings with a delimeter
    //
    // Usage:
    //   join({"a", "b", "c"}, ',') -> "a,b,c"
    std::string join(const std::vector<std::string> &strs, char delimiter);

    // Joins strings with a delimeter
    //
    // Usage:
    //   join({"a", "b", "c"}, ",") -> "a,b,c"
    std::string join(const std::vector<std::string> &strs, const std::string &delimiter);

    // Splits a string at each occurrence of a delimeter
    //
    // Usage:
    //   split("a,b,c", ',') -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);

    // Splits a string at each occurrence of a delimeter
    //
    // Usage:
    //   split("a,b,c", ",") -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, const std::string &delimiter);

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

To increase this library's ease of use there are some notable differences with python's standard library:

Names:

- The functions to join and split path chunks are called `resolve` and `segments` whereas `join` and `split` act on strings and have a delimeter parameter.

Behaviour:

- `resolve`, `segments`, `head`, and `tail`, normalise paths
- `resolve` takes a vector of paths strings rather than being variadic

Parameters:

- `relpath` can take an empty source parameter
- `split` can take an empty delimeter parameter

For more details read the [documentation][pages].

## Tests

To compile the test suites:

```bash
clang++ -std=c++11 $(find src test -name "*.cpp") -lpthread -lgtest
```

For more flexible local development and to compile the test suites in parallel install `scons`:

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

## Docs

Documentation is hosted on [GitHub Pages][pages].

## Tooling

### Lint

```bash
grunt lint
```

### Format

```bash
grunt format
```

## Continuous integration

This repository uses github actions to lint and test each commit. Formatting tasks and writing/generating documentation must be done before committing new code.

## Versioning

This repository adheres to semantic versioning standards.
For more information on semantic versioning visit [SemVer][semver].

Bump2version is used to version and tag changes.
For example:

```bash
bump2version patch
```

## Changelog

Please read this repository's [changelog](CHANGELOG.md) for details on changes that have been made.

## Contributing

Please read this repository's guidelines on [contributing](CONTRIBUTING.md) for details on the process for submitting pull requests. Moreover, our [code of conduct](CODE_OF_CONDUCT.md) declares our collaboration standards.

## Contributors

- **Joel Lefkowitz** - _Initial work_ - [Joel Lefkowitz][author]

[![Buy Me A Coffee][coffee_button]][author_coffee]

## Remarks

Lots of love to the open source community!

![Be kind][be_kind]

<!-- Project links -->

[pages]: https://JoelLefkowitz.github.io/paths
[sources]: https://download-directory.github.io?url=https://github.com/joellefkowitz/paths/tree/master/src

<!-- External links -->

[be_kind]: https://media.giphy.com/media/osAcIGTSyeovPq6Xph/giphy.gif
[detect]: https://github.com/JoelLefkowitz/detect
[semver]: http://semver.org/
[std_filesystem]: https://en.cppreference.com/w/cpp/filesystem
[whereami]: https://github.com/gpakosz/whereami

<!-- Contributor links -->

[author]: https://github.com/JoelLefkowitz
[author_coffee]: https://www.buymeacoffee.com/JoelLefkowitz
[coffee_button]: https://cdn.buymeacoffee.com/buttons/default-blue.png

<!-- Test environment shields -->

[test_ubuntu_20.04_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Test%20on%20Ubuntu%2020.04?label=tests
[test_macos_12_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Test%20on%20MacOS%2012?label=tests
[test_windows_2022_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Test%20on%20Windows%202022?label=tests

<!-- Project shields -->

[release_shield]: https://img.shields.io/github/v/tag/JoelLefkowitz/paths
[license_shield]: https://img.shields.io/github/license/JoelLefkowitz/paths

<!-- Health shields -->

[publish_docs_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Publish%20documentation?label=docs
[review_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Review?label=review
[codacy_shield]: https://img.shields.io/codacy/grade/61e4785a984c42bbbdf1554f025d0f7a
[codacy_coverage_shield]: https://img.shields.io/codacy/coverage/61e4785a984c42bbbdf1554f025d0f7a

<!-- Repository shields -->

[issues_shield]: https://img.shields.io/github/issues/JoelLefkowitz/paths
[issues_closed_shield]: https://img.shields.io/github/issues-closed/JoelLefkowitz/paths
[pulls_shield]: https://img.shields.io/github/issues-pr/JoelLefkowitz/paths
[pulls_closed_shield]: https://img.shields.io/github/issues-pr-closed/JoelLefkowitz/paths

<!-- Activity shields -->

[contributors_shield]: https://img.shields.io/github/contributors/JoelLefkowitz/paths
[monthly_commits_shield]: https://img.shields.io/github/commit-activity/m/JoelLefkowitz/paths
[last_commit_shield]: https://img.shields.io/github/last-commit/JoelLefkowitz/paths
