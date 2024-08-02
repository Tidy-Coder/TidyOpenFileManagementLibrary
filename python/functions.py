import os
import shutil
class TidyFileGestion():
  def exists(self, tidyPath):
    if os.path.exists(tidyPath):
      return True
    else:
      return False
  def isFile(self, tidyPath):
    if os.path.isfile(tidyPath):
      return True
    else:
      return False
  def isFolder(self, tidyPath):
    if os.path.isdir(tidyPath):
      return True
    else:
      return False
  def delete(self, tidyPath):
    if self.exists(tidyPath):
      if self.isFile(tidyPath):
        os.remove(tidyPath)
        return True
      else:
        shutil.rmtree(tidyPath)
        return True
    else:
      return False
  def clear(self, tidyPath):
    if self.exists(tidyPath):
      
    else:
      return False
