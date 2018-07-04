@echo off
set /p sec=请输入时间限制（单位：秒）:
set /p mem=请输入内存限制（单位：MB）:
set /a mem=%mem%*1024
mkdir "Input"
mkdir "Output"
copy *.in Input
copy *.out Output

::写数据个数
dir /B/A-D .\input\*.in|find /v /c "" >>config.ini

::写config.ini
for /f "delims=" %%a in ('dir /b/a-d *.in') do echo %%a^|%%~na.out^|%sec%^|10^|%mem%^| >>config.ini

::压缩并删除原文件
7z a -sdel -tzip data.zip input
7z a -sdel -tzip data.zip output
7z a -sdel -tzip data.zip config.ini
::pause