import java.io.file;

public class TidyOpenFileManagementLibrary(){
  public boolean exists(String tidyPath){
    return (new File(tidyPath)).exists();
  }
  public boolean isFolder(String tidyPath){
    return (new File(tidyPath)).isDirectory();
  }
  public boolean isFile(String tidyPath){
    return (new File(tidyPath)).isFile();
  }
  public boolean createFolder(String tidyPath){
    return (new File(tidyPath)).mkdir(tidyPath);
  }
  public boolean delete(String tidyPath){
    return (new File(tidyPath)).delete(tidyPath);
  }
  public boolean createFile(String tidyPath){
    return (new File(tidyPath)).createNewFile();
  }
  public long size(String tidyPath){
    return (new File(tidyPath)).length();
  }
  public boolean clear(String tidyPath){
    if(this.isFile(tidyPath)){
      this.delete(tidyPath);
      this.createFile(tidyPath);
      return true;
    }
    else if(this.isFolder(tidyPath)){
      this.delete(tidyPath);
      this.createFolder(tidyPath);
      return true;
    }
    return false;
  }
}
