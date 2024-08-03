#include <stdio.h>

enum TidyBoolean{
  FALSE = 0,
  TRUE = 1
};
typedef enum TidyBoolean TidyBoolean;
struct TidyFileAndBoolean{
  FILE* file,
  TidyBoolean error
}
typedef struct TidyFileAndBoolean TidyFileAndBoolean

TidyFileAndBoolean tidyFg_exists(char[] tidyFilename){
  FILE* tidyFile = fopen(tidyFilename, "r")
  if (tidyFile){
    TidyFileAndBoolean 
    return TRUE
  }
  else{
    return FALSE
  }
}
