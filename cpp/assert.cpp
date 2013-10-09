/*!
    http://www.cplusplus.com/reference/cassert/assert/
  
  Standard C++ Library.
  -------------------------------------------------
  assert is intended to be used 
  FOR   : Programmer                NOT USER 
  PHASE: debugging and testing.     NOT RELEASE
  -------------------------------------------------
 If the argument expression of this macro with funcitonal form
 compares equal to zero, a message is written to the standard error
 device and abort is called, trminating the program exection.

 THe specifics of the message shown depend on the particular library
 implementation, but it shall at least include:
 the expression whose assetion failed, the name of the source file,
 and the line number where it happened. 
 A usual expression format is:

 This macro is disabled if, at the moment of including <assert.h>,
 a macro with the name NDEBUG has already been defined.
 This allows for a coder to include as many assert calls as needed in a 
 source code while debgging the program and then disable all of them
 for the production version by simply including a line like:
 #define NDEBUG

 Therefore, this macro is designed to capture programming errors,
 NOT USER or RUN-TIME ERRORS, since it is generally diabled 
 after a program exits its debugging phase.
*/
#include<assert.h>
#include <stdio.h>


int main() {

    assert(false);
    printf("Hi");
}
