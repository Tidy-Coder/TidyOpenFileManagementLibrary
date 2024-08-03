#include <stdio.h>

enum TidyBoolean{
  FALSE = 0,
  TRUE = 1
};
typedef enum TidyBoolean TidyBoolean;
struct TidyFileAndBoolean{
  FILE* file,
  char* typeOfFopen,
  TidyBoolean error
};
typedef struct TidyFileAndBoolean TidyFileAndBoolean;


# this function check if the file exists or don't exists.
TidyFileAndBoolean tidyFg_exists(char[] tidyFilename){
  FILE* tidyFile = fopen(tidyFilename, "r")
  TidyFileAndBoolean resultHere;
  resultHere.file = tidyFile;
  resultHere.typeOfFopen = "r";
  if (tidyFile){
    resultHere.error = FALSE;
  }
  else{
    resultHere.error = TRUE;
  }
  return resultHere;
}
