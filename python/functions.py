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
  def createDirectory(self, tidyPath):
    if not self.exists(tidyPath):
      os.mkdir(tidyPath)
      return True
    else:
      return False
  def createFile(self, tidyPath):
    if not self.exists(tidyPath):
      open(tidyPath, "x").close()
      return True
    else:
      return False
  def size(self, tidyPath):
    if os.path.exists(tidyPath):
      return os.path.getsize(tidyPath)
    else:
      return None
  def clear(self, tidyPath):
    if self.exists(tidyPath):
      if os.path.isdir(tidyPath):
        shutil.rmtree(tidyPath)
        os.mkdir(tidyPath)
      else:
        os.remove(tidyPath)
        open(tidyPath, "x").close()
      return True
    else:
      return False
