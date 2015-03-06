@echo off
set hFile=%1\problem%2.h
@echo #ifndef PROBLEM%2_H > %hFile%
@echo #define PROBLEM%2_H >> %hFile%
@echo. >> %hFile%
@echo #include "../../baserunnable.h" >> %hFile%
@echo. >> %hFile%
@echo class Problem%2 : public BaseRunnable >> %hFile%
@echo { >> %hFile%
@echo public: >> %hFile%
@echo     Problem%2(); >> %hFile%
@echo }; >> %hFile%
@echo. >> %hFile%
@echo #endif // PROBLEM%2_H >> %hFile%

set cppFile=%1\problem%2.cpp
@echo #include "problem%2.h" > %cppFile%
@echo. >> %cppFile%
@echo #include "../../log.h" >> %cppFile%
@echo. >> %cppFile%
@echo namespace >> %cppFile%
@echo { >> %cppFile%
@echo. >> %cppFile%
@echo uint64_t Function() >> %cppFile%
@echo { >> %cppFile%
@echo     return 0; >> %cppFile%
@echo } >> %cppFile%
@echo. >> %cppFile%
@echo }  // namespace >> %cppFile%
@echo. >> %cppFile%
@echo Problem%2::Problem%2() : BaseRunnable(Function()) {} >> %cppFile%
