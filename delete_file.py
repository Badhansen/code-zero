import os
import glob

entries_o_files = glob.glob("D:\code-zero\*.o")
entries_exe_files = glob.glob("D:\code-zero\*.exe")

entries = []
entries.append(entries_o_files)
entries.append(entries_exe_files)


