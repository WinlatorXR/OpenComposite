echo off
echo Starting with an empty build directory
rmdir /S /Q build
mkdir build
cd build

echo Creating 32bit build
mkdir 32bit
cd 32bit
cmake ../.. -G "Visual Studio 17 2022" -A Win32
cmake --build . --config Release
cd ..

echo Creating 64bit build
mkdir 64bit
cd 64bit
cmake ../.. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
cd ..

echo Copying created DLLs
copy 32bit\bin\Release\vrclient.dll .
copy 64bit\bin\Release\vrclient_x64.dll .
cd ..
pause