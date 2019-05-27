#pragma once

#if defined(LIBSODIUM_STATIC)         // Using static.
#  define LIBSODIUM_SYMEXPORT
#elif defined(LIBSODIUM_STATIC_BUILD) // Building static.
#  define LIBSODIUM_SYMEXPORT
#elif defined(LIBSODIUM_SHARED)       // Using shared.
#  ifdef _WIN32
#    define LIBSODIUM_SYMEXPORT __declspec(dllimport)
#  else
#    define LIBSODIUM_SYMEXPORT
#  endif
#elif defined(LIBSODIUM_SHARED_BUILD) // Building shared.
#  ifdef _WIN32
#    define LIBSODIUM_SYMEXPORT __declspec(dllexport)
#  else
#    define LIBSODIUM_SYMEXPORT
#  endif
#else
// If none of the above macros are defined, then we assume we are being used
// by some third-party build system that cannot/doesn't signal the library
// type. Note that this fallback works for both static and shared but in case
// of shared will be sub-optimal compared to having dllimport.
//
#  define LIBSODIUM_SYMEXPORT         // Using static or shared.
#endif
