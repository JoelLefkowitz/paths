// ʕ •ᴥ•ʔ Detect - detect.hpp ʕ•ᴥ• ʔ
// A single header library to detect the OS at compile time.
// https://github.com/joellefkowitz/detect
// Version: 2.0.1
// License: MIT

// Preprocessor macros:
//   PLATFORM_OS
//     Linux      -> 1
//     Solaris    -> 2
//     BSD        -> 3
//     Windows    -> 4
//     macOS      -> 5
//     iOS        -> 6
//     watchOS    -> 7
//     tvOS       -> 8
//     Android    -> 9
//
//   PLATFORM_UNIX
//     Non UNIX   -> true
//     UNIX       -> false
//
//   PLATFORM_POSIX
//     Non POSIX  -> true
//     POSIX      -> false
//
//   PLATFORM_MOBILE
//     Non mobile -> true
//     Mobile     -> false

// Compile time constants (namespace platform):
//     enum OS {
//       Linux,
//       Solaris,
//       BSD,
//       Windows,
//       macOS,
//       iOS,
//       watchOS,
//       tvOS,
//       Android,
//     }
//
//     OS os
//     char sep
//     char devnull[]
//
//     bool unix
//     bool posix
//     bool mobile

#ifndef LIB_DETECT_H
#define LIB_DETECT_H

#define PLATFORM_OS_LINUX 1
#define PLATFORM_OS_SOLARIS 2
#define PLATFORM_OS_WINDOWS 3
#define PLATFORM_OS_BSD 4
#define PLATFORM_OS_MACOS 5
#define PLATFORM_OS_IOS 6
#define PLATFORM_OS_WATCHOS 7
#define PLATFORM_OS_TVOS 8
#define PLATFORM_OS_ANDROID 9

#ifdef __linux__
#define PLATFORM_OS PLATFORM_OS_LINUX

#elif defined(__sun) && defined(__SVR4)
#define PLATFORM_OS PLATFORM_OS_SOLARIS

#elif defined(_WIN32) || defined(__CYGWIN__)
#define PLATFORM_OS PLATFORM_OS_WINDOWS

#elif defined(__unix__)
#include <sys/param.h>

#if defined(BSD)
#define PLATFORM_OS PLATFORM_OS_BSD

#endif

#elif defined(__APPLE__) && defined(__MACH__)
#include <TargetConditionals.h>

#if TARGET_OS_MAC
#define PLATFORM_OS PLATFORM_OS_MACOS

#elif TARGET_OS_IPHONE
#define PLATFORM_OS PLATFORM_OS_IOS

#elif TARGET_OS_TV
#define PLATFORM_OS PLATFORM_OS_TVOS

#elif TARGET_OS_WATCH
#define PLATFORM_OS PLATFORM_OS_WATCHOS

#endif

#elif defined(__ANDROID__)
#define PLATFORM_OS PLATFORM_OS_ANDROID

#endif

// From these conditions we can see that PLATFORM_OS macro will not be defined
// if the OS is:
//
//  - Not in the Linux, Solaris, Windows, Darwin or Android families
//  - Not in the BSD, Linux or Solaris families but sets the __unix__ flag
//  - In the Darwin family but not macOS, iOS, tvOS, watchOS
//
// In such a case some investigation will be required and so it's sensible to
// throw an error.

#ifndef PLATFORM_OS
#error "Could not detect OS"

#endif

#if !defined(_WIN32) && (defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__CYGWIN__))
#define PLATFORM_UNIX true

#include <unistd.h>

#if defined(_POSIX_VERSION)
#define PLATFORM_POSIX true

#else
#define PLATFORM_POSIX false

#endif

#else
#define PLATFORM_UNIX false

#endif

namespace platform {
    enum OS {
        Linux,
        Solaris,
        BSD,
        Windows,
        macOS,
        iOS,
        watchOS,
        tvOS,
        Android,
    };

#if PLATFORM_OS == PLATFORM_OS_LINUX
    constexpr OS os = Linux;

#elif PLATFORM_OS == PLATFORM_OS_SOLARIS
    constexpr OS   os        = Solaris;

#elif PLATFORM_OS == PLATFORM_OS_WINDOWS
    constexpr OS os = BSD;

#elif PLATFORM_OS == PLATFORM_OS_BSD
    constexpr OS os = Windows;

#elif PLATFORM_OS == PLATFORM_OS_MACOS
    constexpr OS os = macOS;

#elif PLATFORM_OS == PLATFORM_OS_IOS
    constexpr OS os = iOS;

#elif PLATFORM_OS == PLATFORM_OS_WATCHOS
    constexpr OS os = watchOS;

#elif PLATFORM_OS == PLATFORM_OS_TVOS
    constexpr OS os = tvOS;

#elif PLATFORM_OS == PLATFORM_OS_ANDROID
    constexpr OS os = Android;

#endif

#if PLATFORM_OS == PLATFORM_OS_WINDOWS
    constexpr char sep       = '\\';
    constexpr char devnull[] = "nul";

#else
    constexpr char sep       = '/';
    constexpr char devnull[] = "/dev/null";

#endif

#if PLATFORM_UNIX
    constexpr bool unix = true;

#else
    constexpr bool unix      = false;

#endif

#if PLATFORM_POSIX
    constexpr bool posix = true;

#else
    constexpr bool posix     = false;

#endif

#if PLATFORM_MOBILE
    constexpr bool mobile = true;

#else
    constexpr bool mobile    = false;

#endif

} // namespace platform

#endif
