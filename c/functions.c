#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#include <unistd.h>
#endif

enum TidyBoolean{
  FALSE = 0,
  TRUE = 1
};
typedef enum TidyBoolean TidyBoolean;

struct TidyResult{
  TidyBoolean result;
  TidyBoolean error;
};
typedef struct TidyResult TidyResult;

# this function check if the file exists or don't exists.
TidyResult tidyFg_isDirectory(const char[] tidyPath){
  TidyResult resultHere;
#ifdef _WIN32
  DWORD tidyAttributes = getFileAttributes(tidyPath);
  if(tidyAttributes == INVALIDE_FILE_ATTRIBUTES){
    resultHere.error = TRUE;
  }
  if(tidyAttributes & FILE_ATTRIBUTE_DIRECTORY){
    resultHere.error = FALSE;
    resultHere.result = TRUE;
  }
  else{
    resultHere.error = FALSE;
    resultHere.result = FALSE;
  }
  return resultHere;
#else
  struct stat tidyPathStat;
  if(stat(tidyPath, &tidyPathStat) != 0){
    resultHere.error = TRUE;
  }
  if(S_ISDIR(tidyathStat.st_mode)){
    resultHere.error = FALSE;
    resultHere.result = TRUE;
  }
  else{
    resultHere.error = FALSE;
    resultHere.result = FALSE;
  }
#endif
}
