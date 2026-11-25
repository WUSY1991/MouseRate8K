@echo off
set JAVA_HOME=D:\Tools\jdk21\jdk-21.0.12.1+1
set PATH=%JAVA_HOME%\bin;%PATH%
set GHIDRA=D:\Tools\ghidra_11.2.1_PUBLIC\support\analyzeHeadless.bat
set SRC=D:\12-AI\0-rea\exe2c\Areson Mouse Test  2.023.exe
set PROJ=D:\12-AI\0-rea\pollrate\analysis\ghidra_proj
set OUT=D:\12-AI\0-rea\pollrate\analysis\decompiled
call "%GHIDRA%" "%PROJ%" AresonProj -import "%SRC%" -scriptPath D:\12-AI\0-rea\lib2c\scripts -postScript DecompAll.py "%OUT%"
