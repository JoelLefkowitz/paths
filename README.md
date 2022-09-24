# Paths

OS specific path manipulation including retrieving the executable's path.

This package is inspired by [whereami][whereami] and [std::filesystem][std_filesystem] but with an easier to use interface, a simpler source and is compatable with C++11. Moreover, exceptions are thrown if errors occur at runtime. To separate the need to detect the operating system at runtime [detect][detect] is dropped in.

## Status

| Source     | Shields                                                                                                                     |
| ---------- | --------------------------------------------------------------------------------------------------------------------------- |
| Project    | ![release][release_shield] ![license][license_shield]                                                                       |
| Health     | ![readthedocs][readthedocs_shield] ![github_review][github_review_shield]                                                   |
| Repository | ![issues][issues_shield] ![issues_closed][issues_closed_shield] ![pulls][pulls_shield] ![pulls_closed][pulls_closed_shield] |
| Activity   | ![contributors][contributors_shield] ![monthly_commits][monthly_commits_shield] ![last_commit][last_commit_shield]          |

## Usage

Copy the sources in place:

- [paths.cpp][paths_cpp]
- [paths.hpp][paths_hpp]

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

    // normpath("a/../a/b/c") -> "a/b/c"
    std::string normpath(const std::string &path);

    // head("a/b/c") -> "c"
    std::string head(const std::string &path);

    // tail("a/b/c") -> "a/b"
    std::string tail(const std::string &path);

    // resolve("a", "b", "c") -> "a/b/c"
    std::string resolve(const std::vector<std::string> &paths);

    // segments("a/b/c") -> {"a", "b", "c"}
    std::vector<std::string> segments(const std::string &path);

    // starts_with("a/b/c", "a/") -> true
    bool starts_with(const std::string &str, char prefix);
    bool starts_with(const std::string &str, const std::string &prefix);

    // ends_with("a/b/c", "/c") -> true
    bool ends_with(const std::string &str, char suffix);
    bool ends_with(const std::string &str, const std::string &suffix);

    // join({"a", "b", "c"}, ", ") -> "a, b, c"
    std::string join(const std::vector<std::string> &strs, char delimiter);
    std::string join(const std::vector<std::string> &strs, const std::string &delimiter = ", ");

    // split("a, b, c", ", ") -> {"a", "b", "c"}
    std::vector<std::string> split(const std::string &str, char delimiter);
    std::vector<std::string> split(const std::string &str, const std::string &delimiter = " ");
}
```

Edge cases for splitting strings and manipulating paths are handled the same way as the python standard library:

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

For ease of use `paths::resolve`, `paths::segments`, `paths::head` and `paths::tail` normalise paths:

```cpp
resolve({"a", "..", "a", "b", "c"}) -> "a/b/c"
segments("a/../a/b/c") -> {"a", "b", "c"}

head("a/../a/b/c/.") -> "c"
tail("a/../a/b/c/.") -> "a/b"
```

For more details read the [documentation][pages].

## Tooling

### Lint

```bash
grunt lint
```

### Format

```bash
grunt format
```

### Test

```bash
clang++ -std=c++11 -lgtest -o test $(find . -name "*.cpp")
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

<!-- Raw links -->

[paths_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/paths.cpp
[paths_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/paths.hpp
[runtime_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/runtime.cpp
[runtime_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/runtime.hpp
[strings_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/strings.cpp
[strings_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/strings.hpp
[detect_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/detect.hpp

<!-- External links -->

[pages]: https://joellefkowitz.github.io/paths
[whereami]: https://github.com/gpakosz/whereami
[std_filesystem]: https://en.cppreference.com/w/cpp/filesystem
[detect]: https://github.com/joellefkowitz/detect
[semver]: http://semver.org/
[be_kind]: https://media.giphy.com/media/osAcIGTSyeovPq6Xph/giphy.gif

<!-- Contributor links -->

[author]: https://github.com/joellefkowitz
[author_coffee]: https://www.buymeacoffee.com/joellefkowitz
[coffee_button]: https://cdn.buymeacoffee.com/buttons/default-blue.png

<!-- Project shields -->

[release_shield]: https://img.shields.io/github/v/tag/joellefkowitz/paths
[license_shield]: https://img.shields.io/github/license/joellefkowitz/paths

<!-- Health shields -->

[readthedocs_shield]: https://img.shields.io/readthedocs/paths
[github_review_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Review

<!-- Repository shields -->

[issues_shield]: https://img.shields.io/github/issues/joellefkowitz/paths
[issues_closed_shield]: https://img.shields.io/github/issues-closed/joellefkowitz/paths
[pulls_shield]: https://img.shields.io/github/issues-pr/joellefkowitz/paths
[pulls_closed_shield]: https://img.shields.io/github/issues-pr-closed/joellefkowitz/paths

<!-- Activity shields -->

[contributors_shield]: https://img.shields.io/github/contributors/joellefkowitz/paths
[monthly_commits_shield]: https://img.shields.io/github/commit-activity/m/joellefkowitz/paths
[last_commit_shield]: https://img.shields.io/github/last-commit/joellefkowitz/paths
