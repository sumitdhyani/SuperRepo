mkdir build
cd build
cmake ..
msbuild SuperRepo.sln /p:Configuration=Release
msbuild SuperRepo.sln /p:Configuration=Debug
pause
