#ifndef STRINGLINKEDLIST_CCOM3034_H
#define STRINGLINKEDLIST_CCOM3034_H

#if defined(WIN32)
#include <windows.h>
#endif


// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
totalAssertions++; \
if (!(chk)) \
printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
else { \
printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
passedAssertions++; \
}
#define assertionReport() { \
printf("==========================================\n"); \
printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
printf("\n"); \
}
//*******************************************************


#endif //STRINGLINKEDLIST_CCOM3034_H
