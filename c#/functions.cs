using System;
using System.IO;

namespace UtilityLibraries{
  class TidyFileManagement{
    bool exists(string tidyPath){
      if(Directory.Exists(tidyPath) || File.Exists(tidyPath)){
        return true;
      }
      else{
        return false;
      }
    }
    bool isFolder(string tidyPath){
      return Directory.Exists(string tidyPath);
    }
    bool isFile(string tidyPath){
      return File.Exists(tidyPath);
    }
  }
}
