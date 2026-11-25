@echo off
rem build_injector.bat - MSVC build of the synthetic input injector
setlocal
cd /d "%~dp0"
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
cl /nologo /O2 /utf-8 /Fe:injector.exe injector.c /link user32.lib winmm.lib
if errorlevel 1 exit /b 1
del /q injector.obj 2>nul
echo === injector.exe OK ===
