@echo off
set /p sec=������ʱ�����ƣ���λ���룩:
set /p mem=�������ڴ����ƣ���λ��MB��:
set /a mem=%mem%*1024
mkdir "Input"
mkdir "Output"
copy *.in Input
copy *.out Output

::д���ݸ���
dir /B/A-D .\input\*.in|find /v /c "" >>config.ini

::дconfig.ini
for /f "delims=" %%a in ('dir /b/a-d *.in') do echo %%a^|%%~na.out^|%sec%^|10^|%mem%^| >>config.ini

::ѹ����ɾ��ԭ�ļ�
7z a -sdel -tzip data.zip input
7z a -sdel -tzip data.zip output
7z a -sdel -tzip data.zip config.ini
::pause