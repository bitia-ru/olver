# Microsoft Developer Studio Project File - Name="pmap" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=pmap - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "pmap.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "pmap.mak" CFG="pmap - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pmap - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "pmap - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "TestSuite/src/model/socket"
# PROP Scc_LocalPath ".."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "pmap - Win32 Release"

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
# ADD CPP /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ts.lib utils.lib atl.lib  tracer.lib /nologo /subsystem:console /machine:I386 /libpath:"$(CTESK_HOME)\lib\win32"

!ELSEIF  "$(CFG)" == "pmap - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\..\.." /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOCKET_RPC_PMAP_LOCAL_MAIN" /YX /FD /GZ  /c
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

# Name "pmap - Win32 Release"
# Name "pmap - Win32 Debug"
# Begin Group "SEC Files"

# PROP Default_Filter "sec"
# Begin Group "other"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\netdata\netdata_media.sec

!IF  "$(CFG)" == "pmap - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\..\netdata\netdata_media.sec
InputName=netdata_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../../netdata/netdata_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "pmap - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\..\netdata\netdata_media.sec
InputName=netdata_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "..\..\.." /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOCKET_RPC_PMAP_LOCAL_MAIN" /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../../netdata/netdata_media.sec" > "$(InputName).sei" 
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

SOURCE=..\..\netdata\netdata_model.sec

!IF  "$(CFG)" == "pmap - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\..\netdata\netdata_model.sec
InputName=netdata_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../../netdata/netdata_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "pmap - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\..\netdata\netdata_model.sec
InputName=netdata_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "..\..\.." /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOCKET_RPC_PMAP_LOCAL_MAIN" /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../../netdata/netdata_model.sec" > "$(InputName).sei" 
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

SOURCE=..\..\socket\socket_config.c
# End Source File
# Begin Source File

SOURCE=..\..\socket\socket_media.sec

!IF  "$(CFG)" == "pmap - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\..\socket\socket_media.sec
InputName=socket_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../../socket/socket_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "pmap - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\..\socket\socket_media.sec
InputName=socket_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "..\..\.." /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOCKET_RPC_PMAP_LOCAL_MAIN" /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../../socket/socket_media.sec" > "$(InputName).sei" 
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

SOURCE=..\..\socket\socket_model.sec

!IF  "$(CFG)" == "pmap - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\..\socket\socket_model.sec
InputName=socket_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../../socket/socket_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "pmap - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\..\socket\socket_model.sec
InputName=socket_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "..\..\.." /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOCKET_RPC_PMAP_LOCAL_MAIN" /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../../socket/socket_model.sec" > "$(InputName).sei" 
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
# Begin Source File

SOURCE=..\pmap_media.sec

!IF  "$(CFG)" == "pmap - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pmap_media.sec
InputName=pmap_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pmap_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "pmap - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pmap_media.sec
InputName=pmap_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "..\..\.." /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOCKET_RPC_PMAP_LOCAL_MAIN" /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pmap_media.sec" > "$(InputName).sei" 
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

SOURCE=..\pmap_model.sec

!IF  "$(CFG)" == "pmap - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pmap_model.sec
InputName=pmap_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pmap_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "pmap - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pmap_model.sec
InputName=pmap_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "..\..\.." /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOCKET_RPC_PMAP_LOCAL_MAIN" /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pmap_model.sec" > "$(InputName).sei" 
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

SOURCE=.\pmap_scenario.sec

!IF  "$(CFG)" == "pmap - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=.\pmap_scenario.sec
InputName=pmap_scenario

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "./pmap_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "pmap - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=.\pmap_scenario.sec
InputName=pmap_scenario

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "..\..\.." /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "SOCKET_RPC_PMAP_LOCAL_MAIN" /YX /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "./pmap_scenario.sec" > "$(InputName).sei" 
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
# Begin Group "other headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\netdata\netdata_media.seh
# End Source File
# Begin Source File

SOURCE=..\..\netdata\netdata_model.seh
# End Source File
# Begin Source File

SOURCE=..\..\socket\socket_media.seh
# End Source File
# Begin Source File

SOURCE=..\..\socket\socket_model.seh
# End Source File
# End Group
# Begin Source File

SOURCE=..\pmap_media.seh
# End Source File
# Begin Source File

SOURCE=..\pmap_model.seh
# End Source File
# Begin Source File

SOURCE=.\pmap_scenario.seh
# End Source File
# End Group
# Begin Group "Generated"

# PROP Default_Filter "c"
# Begin Source File

SOURCE=.\~netdata_media.c
# End Source File
# Begin Source File

SOURCE=.\~netdata_model.c
# End Source File
# Begin Source File

SOURCE=.\~pmap_media.c
# End Source File
# Begin Source File

SOURCE=.\~pmap_model.c
# End Source File
# Begin Source File

SOURCE=.\~pmap_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~socket_config.c
# End Source File
# Begin Source File

SOURCE=.\~socket_media.c
# End Source File
# Begin Source File

SOURCE=.\~socket_model.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\trace.xml
# End Source File
# End Target
# End Project
