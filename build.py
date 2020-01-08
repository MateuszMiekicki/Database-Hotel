import os
if os.path.isdir("build"):
    os.system("cd build && cmake .. -G \"MinGW Makefiles\" && mingw32-make")
else:
   os.system("mkdir build && cd build && cmake .. -G \"MinGW Makefiles\" && mingw32-make")

if os.path.isdir("test/module"):
    os.system("copy build/*.o test/module")
else:
    os.system("cd test && mkdir module && cd .. && copy build/*.o test/module")

if os.path.isdir("test/build"):
    os.system("cd test && cd build && cmake .. -G \"MinGW Makefiles\" && mingw32-make")
else:
    os.system("cd test && mkdir build && cd build && cmake .. -G \"MinGW Makefiles\" && mingw32-make")