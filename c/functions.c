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

TidyBoolean tidyFg_exists(const char[] tidyPath){
#ifdef _WIN32
  DWORD tidyAttributes = GetFileAttributes(tidyPath);
  if(tidyAttributes != INVALID_FILE_ATTRIBUTES){
    return TRUE
  }
  else{
    return FALSE;
  }
#else
  if(access(tidyPath, F_OK) == 0){
    return TRUE;
  }
  else{
    return FALSE;
  }
#endif
}

# this function check if the path is a directory.
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
  return resultHere;
}
# this function check if the path is a file.
TidyResult tidyFg_isFile(const char[] tidyPath){
  TidyResult resultHere;
#ifdef _WIN32
  DWORD tidyAttributes = getFileAttributes(tidyPath);
  if(tidyAttributes == INVALIDE_FILE_ATTRIBUTES){
    resultHere.error = TRUE;
  }
  if(tidyAttributes & FILE_ATTRIBUTE_DIRECTORY){
    resultHere.error = FALSE;
    resultHere.result = FALSE;
  }
  else{
    resultHere.error = FALSE;
    resultHere.result = TRUE;
  }
#else
  struct stat tidyPathStat;
  if(stat(tidyPath, &tidyPathStat) != 0){
    resultHere.error = TRUE;
  }
  if(S_ISREG(tidyathStat.st_mode)){
    resultHere.error = FALSE;
    resultHere.result = TRUE;
  }
  else{
    resultHere.error = FALSE;
    resultHere.result = FALSE;
  }
#endif
  return resultHere;
}

TidyBoolean createDirectory(char[] tidyPath){
#ifdef _WIN32
  if(CreateDirectory(tidyPath, NULL)){
    return TRUE;
  }
  else{
    return FALSE;
  }
#else
  if(mkdir(tidyPath, 0755) == 0){
    return TRUE;
  }
  else{
    return FALSE;
  }
}
