#pragma once

#include <stdio.h>

#include <libsodium/export.h>

// Print a greeting for the specified name into the specified
// stream. On success, return the number of character printed.
// On failure, set errno and return a negative value.
//
LIBSODIUM_SYMEXPORT int
say_hello (FILE *, const char *name);
