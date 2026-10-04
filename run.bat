@echo off
REM Quick compile and run
REM Usage: run.bat solution.cpp

if "%1"=="" (
    echo Usage: run.bat solution.cpp
    exit /b 1
)

set name=%~n1
g++ -std=c++20 -O2 -Wall -Wextra -o %name%.exe %1

if %errorlevel%==0 (
    if exist input.txt (
        %name%.exe < input.txt
    ) else (
        %name%.exe
    )
    del %name%.exe 2>nul
) else (
    echo Compilation failed!
)
