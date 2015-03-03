@echo off
SET file = %1
@echo #ifndef PROBLEMS_H > %1
@echo #define PROBLEMS_H >> %1
@echo. >> %1 
for /F %%i in ('dir /ad /b %2') do (
	echo // Problems in %%i >> %1
	for /F %%j in ('dir /a /b %2\%%i\*.h') do (
		echo #include "%%i/%%j" >> %1
	)
	@echo. >> %1 
)
@echo #endif // PROBLEMS >> %1

fc %1 %2\problems.h > nul
if errorlevel 1 copy %1 %2\problems.h
