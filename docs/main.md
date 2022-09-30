# Usage {#mainpage}

OS specific path operations and executable path retrieval.

This package is inspired by [whereami][whereami] and [std::filesystem][std_filesystem] but with:

- Simple interfaces
- Readable sources
- C++11 compatability
- Exception handling

To separate the need to detect the operating system at runtime [detect][detect] is dropped in.

Since path manipulation is full of edge cases it is paramount to have an extensive set of unit tests. The test fixtures are verified to be consistent with python's standard library. To provide support to multiple platforms all test suites are verified against each target environment.

Test environments:

| Platform | Test environment | Status                                                |
| -------- | ---------------- | ----------------------------------------------------- |
| Linux    | Ubuntu 20.04     | ![test_ubuntu_20.04_shield][test_ubuntu_20.04_shield] |
| Darwin   | MacOS 12         | ![test_macos_12_shield][test_macos_12_shield]         |
| Windows  |                  |                                                       |
| BSD      |                  |                                                       |
| Solaris  |                  |                                                       |
| IOS      |                  |                                                       |
| Android  |                  |                                                       |

## Status

| Source     | Shields                                                                                                                           |
| ---------- | --------------------------------------------------------------------------------------------------------------------------------- |
| Project    | ![release][release_shield] ![license][license_shield]                                                                             |
| Health     | ![publish_docs][publish_docs_shield] ![review][review_shield] ![codacy][codacy_shield] ![codacy_coverage][codacy_coverage_shield] |
| Repository | ![issues][issues_shield] ![issues_closed][issues_closed_shield] ![pulls][pulls_shield] ![pulls_closed][pulls_closed_shield]       |
| Activity   | ![contributors][contributors_shield] ![monthly_commits][monthly_commits_shield] ![last_commit][last_commit_shield]                |

## Installation

### Conan

Not yet supported

### Sources

Copy the sources in place:

- Paths

  - [paths.cpp][paths_cpp]
  - [paths.hpp][paths_hpp]

- Runtime

  - [runtime.cpp][runtime_cpp]
  - [runtime.hpp][runtime_hpp]

- Strings

  - [strings.cpp][strings_cpp]
  - [strings.hpp][strings_hpp]

- Detect

  - [detect.hpp][detect_hpp]

## Usage

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

    // Converts a Windows path to a Unix path
    // Usage: unix_path("a\\b\\c") -> "a/b/c"
    std::string unix_path(const std::string &path);

    // Converts a Unix path to a Windows path
    // Usage: windows_path("a/b/c") -> "a\\b\\c"
    std::string windows_path(const std::string &path);

    constexpr char unix_sep    = '/';
    constexpr char windows_sep = '\\';
}
```

<!-- Raw links -->

[paths_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/paths.cpp
[paths_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/paths.hpp
[runtime_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/runtime.cpp
[runtime_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/runtime.hpp
[strings_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/strings.cpp
[strings_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/strings.hpp
[detect_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/detect.hpp

<!-- External links -->

[whereami]: https://github.com/gpakosz/whereami
[std_filesystem]: https://en.cppreference.com/w/cpp/filesystem
[detect]: https://github.com/JoelLefkowitz/detect

<!-- Test environment shields -->

[test_ubuntu_20.04_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Test%20on%20Ubuntu%2020.04?label=tests
[test_macos_12_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Test%20on%20MacOS%2012?label=tests

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
