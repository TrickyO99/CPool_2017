@echo off
setlocal
cd /d "%~dp0"

:menu
cls
echo CPool_2017 - 2-week C piscine, one entry per day
echo (Some days are loose reimplemented-libc functions with no main() of
echo  their own, or shell-scripting exercises tied to Epitech's grading
echo  account paths - those just open their folder instead of "running".)
echo.
echo   1.  Day01 - shell scripting exercises        (opens folder)
echo   2.  Day02 - shell scripting exercises        (opens folder)
echo   3.  Day03 - libc reimplementations, no main  (opens folder)
echo   4.  Day04 - libc reimplementations, no main  (opens folder)
echo   5.  Day05 - math functions, no main          (opens folder)
echo   6.  Day06 - string functions, no main        (opens folder)
echo   7.  Day07 - task04: print argv (BUILD + RUN)
echo   8.  Day08 - word-array helpers, no main      (opens folder)
echo   9.  Day09 - params-to-array helper, no main  (opens folder)
echo  10.  Day10 - do_op.c is an empty stub, nothing to run
echo  11.  Day11 - linked-list helpers, no main     (opens folder)
echo  12.  Day12 - cat clone (BUILD + RUN)
echo  13.  Day13 - task01: open an SFML window (BUILD + RUN)
echo  14.  bistro-matic - main.c missing from repo, cannot build
echo  15.  evalexpr - infinadd (BUILD + RUN)
echo  16.  Quit
echo.
set /p choice="Choose 1-16: "

if "%choice%"=="1" start "" "%cd%\CPool_Day01_2017"
if "%choice%"=="2" start "" "%cd%\CPool_Day02_2017"
if "%choice%"=="3" start "" "%cd%\CPool_Day03_2017"
if "%choice%"=="4" start "" "%cd%\CPool_Day04_2017"
if "%choice%"=="5" start "" "%cd%\CPool_Day05_2017"
if "%choice%"=="6" start "" "%cd%\CPool_Day06_2017"
if "%choice%"=="8" start "" "%cd%\CPool_Day08_2017"
if "%choice%"=="9" start "" "%cd%\CPool_Day09_2017"
if "%choice%"=="11" start "" "%cd%\CPool_Day11_2017"
if "%choice%"=="14" echo bistro-matic's src\main.c was never committed to this repo - it has never been buildable. & pause
if "%choice%"=="16" exit /b 0

if "%choice%"=="7" (
    cd /d "%~dp0CPool_Day07_2017\task04"
    rem The bundled libmy.a is a Linux ELF archive, unusable on Windows -
    rem link the real my_putstr.c/my_strlen.c source from Day04 instead.
    gcc -fpermissive -D"my_putchar(c)=putchar(c)" -o my_print_params.exe my_print_params.c "%~dp0CPool_Day04_2017\my_putstr.c" "%~dp0CPool_Day04_2017\my_strlen.c"
    if exist my_print_params.exe (
        my_print_params.exe hello from CPool Day07
    ) else (
        echo Build failed - see errors above.
    )
    cd /d "%~dp0"
    pause
)

if "%choice%"=="10" (
    echo Day10's do_op.c is an empty stub - it was never finished, nothing to build or run.
    pause
)

if "%choice%"=="12" (
    cd /d "%~dp0CPool_Day12_2017\cat"
    mingw32-make
    if exist cat.exe (
        echo hello CPool > tmp_catdemo.txt
        cat.exe tmp_catdemo.txt
        del tmp_catdemo.txt
    ) else (
        echo Build failed - see errors above.
    )
    cd /d "%~dp0"
    pause
)

if "%choice%"=="13" (
    cd /d "%~dp0CPool_Day13_2017"
    gcc -o task01.exe task01.c -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
    if exist task01.exe (
        echo Opening an SFML window - close it to continue.
        start "" task01.exe
    ) else (
        echo Build failed - see errors above.
        pause
    )
    cd /d "%~dp0"
)

if "%choice%"=="15" (
    cd /d "%~dp0CPool_evalexpr_2017"
    rem -fpermissive downgrades a genuine pointer/int type-mismatch bug in
    rem infinadd.c's original source from a hard error to a warning.
    gcc -fpermissive -o infinadd.exe infinadd.c
    if exist infinadd.exe (
        infinadd.exe 999999999999999999 1
    ) else (
        echo Build failed - see errors above.
    )
    cd /d "%~dp0"
    pause
)

goto menu
