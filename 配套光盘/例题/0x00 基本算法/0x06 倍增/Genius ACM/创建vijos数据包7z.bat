@echo off
mkdir "Input"
mkdir "Output"
copy *.in Input
copy *.out Output

::写数据个数
dir /B/A-D .\input\*.in|find /v /c "" >>config.ini

::写config.ini
for /f "delims=" %%a in ('dir /b/a-d *.in') do echo %%a^|%%~na.out^|1^|10^| >>config.ini

::压缩并删除原文件
7z a -sdel -tzip data.zip input
7z a -sdel -tzip data.zip output
7z a -sdel -tzip data.zip config.ini
::pause