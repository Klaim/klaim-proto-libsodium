#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include <libsodium/version.h>
#include <libsodium/sodium.h>

int main ()
{
  char b[256];

  // Basics.
  //
  {
    FILE *o = fmemopen (b, sizeof (b), "w");
    assert (say_hello (o, "World") > 0);
    fclose (o);
    assert (strcmp (b, "Hello, World!\n") == 0);
  }

  // Empty name.
  //
  {
    FILE *o = fmemopen (b, sizeof (b), "w");
    assert (say_hello (o, "") < 0 && errno == EINVAL);
    fclose (o);
  }

  return 0;
}
