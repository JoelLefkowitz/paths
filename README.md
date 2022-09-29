# Paths

OS specific path operations and executable path retrieval.

This package is inspired by [whereami][whereami] and [std::filesystem][std_filesystem] but with:

- Simple interfaces
- Readable sources
- C++11 compatability
- Exception handling

To separate the need to detect the operating system at runtime [detect][detect] is dropped in. Having a comprehensive set of tests is paramount and all suites are verified against each target environment.

## Status

| Source     | Shields                                                                                                                                                       |
| ---------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Project    | ![release][release_shield] ![license][license_shield]                                                                                                         |
| Health     | ![github_publish_docs][github_publish_docs_shield] ![github_review][github_review_shield] ![codacy][codacy_shield] ![codacy_coverage][codacy_coverage_shield] |
| Repository | ![issues][issues_shield] ![issues_closed][issues_closed_shield] ![pulls][pulls_shield] ![pulls_closed][pulls_closed_shield]                                   |
| Activity   | ![contributors][contributors_shield] ![monthly_commits][monthly_commits_shield] ![last_commit][last_commit_shield]                                            |

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
}
```

For more details read the [documentation][pages].

## Installation

### Conan

Not yet supported

### Copying sources

Copy the sources in place:

- [paths.cpp][paths_cpp]
- [paths.hpp][paths_hpp]

- [runtime.cpp][runtime_cpp]
- [runtime.hpp][runtime_hpp]

- [strings.cpp][strings_cpp]
- [strings.hpp][strings_hpp]

- [detect.hpp][detect_hpp]

## Tests

```bash
clang++ -std=c++11 $(find src test -name "*.cpp") -lpthread -lgtest -o dist/test
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

<!-- Raw links -->

[paths_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/paths.cpp
[paths_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/paths.hpp
[runtime_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/runtime.cpp
[runtime_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/runtime.hpp
[strings_cpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/strings.cpp
[strings_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/strings.hpp
[detect_hpp]: https://raw.githubusercontent.com/JoelLefkowitz/paths/master/src/detect.hpp

<!-- External links -->

[pages]: https://JoelLefkowitz.github.io/paths
[whereami]: https://github.com/gpakosz/whereami
[std_filesystem]: https://en.cppreference.com/w/cpp/filesystem
[detect]: https://github.com/JoelLefkowitz/detect
[semver]: http://semver.org/
[be_kind]: https://media.giphy.com/media/osAcIGTSyeovPq6Xph/giphy.gif

<!-- Contributor links -->

[author]: https://github.com/JoelLefkowitz
[author_coffee]: https://www.buymeacoffee.com/JoelLefkowitz
[coffee_button]: https://cdn.buymeacoffee.com/buttons/default-blue.png

<!-- Project shields -->

[release_shield]: https://img.shields.io/github/v/tag/JoelLefkowitz/paths
[license_shield]: https://img.shields.io/github/license/JoelLefkowitz/paths

<!-- Health shields -->

[github_publish_docs_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Publish%20documentation?label=docs
[github_review_shield]: https://img.shields.io/github/workflow/status/JoelLefkowitz/paths/Review
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
