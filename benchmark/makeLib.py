import os
import platform

def nameOSType():
    return platform.system()

def Windows():
    moveToBenchmarkDir = 'cd benchmark'
    os.system(moveToBenchmarkDir)
    makeDirBuildAndChangeDir = 'mkdir build && cd build'
    os.system(makeDirBuildAndChangeDir)

gitVersion = "git --version"
os.system(gitVersion)
if not os.path.isdir('benchmark'):
    gitCloneBenchamrk = 'git clone https://github.com/google/benchmark.git'
    os.system(gitCloneBenchamrk)
    gitCloneGTest = 'git clone https://github.com/google/googletest.git benchmark/googletest'
    os.system(gitCloneGTest)
import pathlib
cdToBuild = 'cd benchmark && mkdir build '
moveToBenchmarkDir = cdToBuild + '&& cd build'
os.system(moveToBenchmarkDir)


make = cdToBuild + '&& cmake ../ -G "'
buildType = input() 
os.system(make+buildType+'"')
makeType = input()
os.system(cdToBuild + makeType)

