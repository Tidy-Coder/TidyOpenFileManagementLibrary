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
    bool delete(string tidyPath){
      if(this.isFolder(tidyPath)){
        try{
          Directory.Delete(tidyPath, true);
          return true;
        }
        catch(Exception e){
          return false;
        }
      }
      else if(this.isFile(tidyPath)){
        try{
          File.Delete(tidyPath);
          return true;
        }
        catch(Exception z){
          return false;
        }
      }
      return false;
    }
    bool createFile(string tidyPath){
      try{
        File.Create(tidyPath);
        return true;
      }
      catch(Exception e){
        return false;
      }
    }
    bool createFolder(string tidyPath){
      try{
        Directory.CreateDirectory(tidyPath);
        return true;
      }
      catch(Exception e){
        return false;
      }
    }
    bool clear(string tidyPath){
      if(this.isFolder(tidyPath)){
        try{
          Directory.Delete(tidyPath, true);
          Directory.CreateDirectory(tidyPath);
          return true;
        }
        catch(Exception e){
          return false;
        }
      }
      else if(this.isFile(tidyPath)){
        try{
          File.Delete(tidyPath);
          File.Create(tidyPath);
          return true;
        }
        catch(Exception e){
          return false;
        }
      }
      return false;
    }
    long sizeDirectory(DirectoryInfo tidyInfoHere){
      long tidyNumReturn = 0;
      
      foreach(FileInfo f in tidyInfoHere.GetFiles()){
        tidyNumReturn += f.Length;
      }
      foreach(DirectoryInfo infoIsHere in tidyInfoHere.GetDirectories()){
        tidyNumReturn += this.sizeDirectory(infoIsHere)
      }
      return tidyNumReturn
    }
    long size(string tidyPath){
      if(this.isFile(tidyPath)){
        return (new FileInfo(tidyPath)).Length;
      }
      else if(this.isFolder(tidyPath)){
        return this.sizeDirectory(new DirectoryInfo(tidyPath));
      }
      else{
        return -1;
      }
    }
  }
}
