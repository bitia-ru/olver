# Microsoft Developer Studio Project File - Name="cterm" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=cterm - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cterm.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cterm.mak" CFG="cterm - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cterm - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "cterm - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cterm - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "NDEBUG" /D "_CONSOLE" /D "WIN32" /D "_MBCS" /D "IO_TERM_LOCAL_MAIN" /YX /FD /c
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ts.lib utils.lib atl.lib  tracer.lib /nologo /subsystem:console /machine:I386 /libpath:"$(CTESK_HOME)\lib\win32"

!ELSEIF  "$(CFG)" == "cterm - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "cterm___Win32_Debug"
# PROP BASE Intermediate_Dir "cterm___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "cterm___Win32_Debug"
# PROP Intermediate_Dir "cterm___Win32_Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "../../.." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "_CONSOLE" /D "IO_TERM_LOCAL_MAIN" /D "WIN32" /D "_MBCS" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ws2_32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ts.lib utils.lib atl.lib  tracer.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"$(CTESK_HOME)\lib\win32"

!ENDIF 

# Begin Target

# Name "cterm - Win32 Release"
# Name "cterm - Win32 Debug"
# Begin Group "SEC Files"

# PROP Default_Filter "sec"
# Begin Source File

SOURCE=.\cterm_scenario.sec

!IF  "$(CFG)" == "cterm - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=.\cterm_scenario.sec
InputName=cterm_scenario

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "NDEBUG" /D "_CONSOLE" /D "WIN32" /D "_MBCS" /D "IO_TERM_LOCAL_MAIN" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "./cterm_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "cterm - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=.\cterm_scenario.sec
InputName=cterm_scenario

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "../../.." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "_CONSOLE" /D "IO_TERM_LOCAL_MAIN" /D "WIN32" /D "_MBCS" /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "./cterm_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\file\file_config.c
# End Source File
# Begin Source File

SOURCE=..\term_config.c
# End Source File
# Begin Source File

SOURCE=..\term_media.sec

!IF  "$(CFG)" == "cterm - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\term_media.sec
InputName=term_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "NDEBUG" /D "_CONSOLE" /D "WIN32" /D "_MBCS" /D "IO_TERM_LOCAL_MAIN" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../term_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "cterm - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\term_media.sec
InputName=term_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "../../.." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "_CONSOLE" /D "IO_TERM_LOCAL_MAIN" /D "WIN32" /D "_MBCS" /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../term_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\term_model.sec

!IF  "$(CFG)" == "cterm - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\term_model.sec
InputName=term_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "NDEBUG" /D "_CONSOLE" /D "WIN32" /D "_MBCS" /D "IO_TERM_LOCAL_MAIN" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../term_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "cterm - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\term_model.sec
InputName=term_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "../../.." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "_CONSOLE" /D "IO_TERM_LOCAL_MAIN" /D "WIN32" /D "_MBCS" /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../term_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "SEH Files"

# PROP Default_Filter "seh"
# Begin Source File

SOURCE=.\cterm_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\term_media.seh
# End Source File
# Begin Source File

SOURCE=..\term_model.seh
# End Source File
# End Group
# Begin Group "Generated"

# PROP Default_Filter "c"
# Begin Source File

SOURCE=.\~cterm_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~file_config.c
# End Source File
# Begin Source File

SOURCE=.\~term_config.c
# End Source File
# Begin Source File

SOURCE=.\~term_media.c
# End Source File
# Begin Source File

SOURCE=.\~term_model.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\trace.xml
# End Source File
# End Target
# End Project
