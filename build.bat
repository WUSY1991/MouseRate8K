@echo off
rem build.bat - MSVC x64 single-exe build with static CRT (/MT)
setlocal
cd /d "%~dp0"

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
if errorlevel 1 (
  echo [ERROR] vcvars64 not found
  exit /b 1
)

rc /nologo /fo app.res app.rc
if errorlevel 1 exit /b 1

cl /nologo /W4 /O2 /MT /utf-8 /std:c++17 /EHsc /DUNICODE /D_UNICODE ^
   /DWIN32_LEAN_AND_MEAN /DNOMINMAX /D_CRT_SECURE_NO_WARNINGS ^
   main.cpp rawinput_engine.cpp chart.cpp csvlog.cpp app.res ^
   /Fe:MouseRate8K.exe ^
   /link /SUBSYSTEM:WINDOWS /MANIFEST:NO /OPT:REF /OPT:ICF ^
   user32.lib gdi32.lib comctl32.lib hid.lib setupapi.lib
if errorlevel 1 exit /b 1

del /q *.obj 2>nul
echo.
echo === BUILD OK: MouseRate8K.exe ===
