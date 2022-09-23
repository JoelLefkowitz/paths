// ʕ •ᴥ•ʔ Detect ʕ•ᴥ• ʔ
// A single header library to detect the OS at compile time.
// https://github.com/joellefkowitz/detect
// Version: 1.0.1
// License: MIT

#ifndef PLATFORM_DETECT_H
#define PLATFORM_DETECT_H

// Start at 1 since undefined macros evaluate to 0.
#define PLATFORM_LINUX 1
#define PLATFORM_DARWIN 2
#define PLATFORM_WINDOWS 3
#define PLATFORM_BSD 4
#define PLATFORM_SOLARIS 5
#define PLATFORM_IOS 6
#define PLATFORM_ANDROID 7

#ifdef __linux__
#define PLATFORM_DETECTED_OS PLATFORM_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE == 1
#define PLATFORM_DETECTED_OS PLATFORM_IOS
#elif TARGET_OS_MAC == 1
#define PLATFORM_DETECTED_OS PLATFORM_DARWIN
#endif

#elif defined(_WIN64) || defined(_WIN32)
#define PLATFORM_DETECTED_OS PLATFORM_WINDOWS
#elif defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
#include <sys/param.h>
#if defined(BSD)
#define PLATFORM_DETECTED_OS PLATFORM_BSD

#elif defined(__sun) && defined(__SVR4)
#define PLATFORM_DETECTED_OS PLATFORM_SOLARIS
#endif

#elif defined(__ANDROID__)
#define PLATFORM_DETECTED_OS PLATFORM_ANDROID
#endif

namespace platform {
    enum OS { Linux, Darwin, Windows, BSD, Solaris, IOS, Android };

#if PLATFORM_DETECTED_OS == PLATFORM_LINUX
    constexpr OS   os  = Linux;
    constexpr char sep = '/';
#elif PLATFORM_DETECTED_OS == PLATFORM_DARWIN
    constexpr OS   os  = Darwin;
    constexpr char sep = '/';
#elif PLATFORM_DETECTED_OS == PLATFORM_WINDOWS
    constexpr OS   os  = Windows;
    constexpr char sep = '\\';
#elif PLATFORM_DETECTED_OS == PLATFORM_BSD
    constexpr OS   os  = BSD;
    constexpr char sep = '/';
#elif PLATFORM_DETECTED_OS == PLATFORM_SOLARIS
    constexpr OS   os  = Solaris;
    constexpr char sep = '/';
#elif PLATFORM_DETECTED_OS == PLATFORM_IOS
    constexpr OS   os  = IOS;
    constexpr char sep = '/';
#elif PLATFORM_DETECTED_OS == PLATFORM_ANDROID
    constexpr OS   os  = Android;
    constexpr char sep = '/';
#else
#endif
} // namespace platform

#endif
