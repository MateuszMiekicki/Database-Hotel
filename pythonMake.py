import glob, os, shutil

cd = ["cd build"]
cmake = ["cmake .. -G \"MinGW Makefiles\""]
make = ["mingw32-make"]

cmd = cd + cmake + make
cmd = "&&".join(cmd)
os.system(cmd)

copyAFile = "copy build\*.a test\module"
os.system(copyAFile)
