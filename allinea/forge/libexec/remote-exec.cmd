@ECHO OFF

REM This script is used by Allinea tools to start remote processes.
REM It should accept the arguments HOSTNAME PROGRAM_NAME ARG1 ARG2 ARGN
REM Before using attach in DDT you should test this script manually
REM e.g. remote-exec.bat comp01 hostname
REM The command must run without prompting for a password.

REM if the user has a remote-exec script, use that one

SET basedir=%~dp0

IF EXIST "%USERPROFILE%\.allinea\remote-exec.cmd" (
   "%USERPROFILE%\.allinea\remote-exec.cmd" %*
) ELSE (
  "%basedir%plink.exe" %*
)
