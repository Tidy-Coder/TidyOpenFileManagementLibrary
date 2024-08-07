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
TidyBoolean tidyFML_exists(const char tidyPath[]){
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

TidyResult tidyFML_isFolder(const char tidyPath[]){
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
  if(S_ISDIR(tidyPathStat.st_mode)){
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

TidyResult tidyFML_isFile(const char tidyPath[]){
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
  if(S_ISREG(tidyPathStat.st_mode)){
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

TidyBoolean tidyFML_createFolder(const char tidyPath[]){
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
#endif
}

TidyBoolean tidyFML_delete(const char tidyPath[]){
  TidyResult tidyIsFile = tidyFML_isFile(tidyPath);
  TidyResult tidyIsDirectory = tidyFML_isFolder(tidyPath);
  if(tidyIsFile.error == FALSE && tidyIsFile.result == TRUE){
#ifdef _WIN32
    if(DeleteFile(tidyPath)){
      return TRUE;
    }
    else{
      return FALSE;
    }
#else
    if(remove(tidyPath) == 0){
      return TRUE;
    }
    else{
      return FALSE;
    }
#endif
  }
  if(tidyIsDirectory.error == FALSE && tidyIsDirectory.result == TRUE){
#ifdef _WIN32
    if(RemoveDirectory(tidyPath)){
      return TRUE;
    }
    else{
      return FALSE;
    }
#else
    if(rmdir(tidyPath) == 0){
      return TRUE;
    }
    else{
      return FALSE;
    }
#endif
  }
}

TidyBoolean tidyFML_createFile(const char tidyPath[]){
  FILE* fileHere  = fopen(tidyPath, "w");
  if(fileHere == NULL){
    return FALSE;
  }
  if(fclose(fileHere) != 0){
    return FALSE;
  }
  return TRUE;
}

TidyBoolean tidyFML_clear(const char tidyPath[]){
  if(tidyFML_delete(tidyPath) == FALSE){
    return FALSE;
  }
  
  TidyResult tidyIsFile = tidyFML_isFile(tidyPath);
  if(tidyIsFile.error == TRUE){
    return FALSE;
  }
  else if(tidyIsFile.result == TRUE){
    if(tidyFML_createFile(tidyPath) == TRUE){
      return TRUE;
    }
    else{
      return FALSE;
    }
  }
  
  TidyResult tidyIsFolder = tidyFML_isFolder(tidyPath);
  if(tidyIsFolder.error == TRUE){
    return FALSE;
  }
  else if(tidyIsFolder.result == TRUE){
    if(tidyFML_createFolder(tidyPath) == TRUE){
      return TRUE;
    }
    else{
      return FALSE;
    }
  }
  return FALSE;
}
