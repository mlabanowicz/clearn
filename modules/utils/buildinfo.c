
#include <utils.h>

#ifdef __cplusplus
extern "C" {
#endif

void UTILS_BuildInfo(FILE * stream) {
  fputs("Program build date: " __DATE__ " / " __TIME__ "\n", stream);
}

#ifdef __cplusplus
}
#endif
