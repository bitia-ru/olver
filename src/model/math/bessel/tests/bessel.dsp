# Microsoft Developer Studio Project File - Name="bessel" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=bessel - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "bessel.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "bessel.mak" CFG="bessel - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "bessel - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "bessel - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "TestSuite/src/model"
# PROP Scc_LocalPath "..\..\.."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "bessel - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /YX /FD /c
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Ws2_32.lib "../../.." "NDEBUG" "WIN32" "_CONSOLE" "_MBCS" "MATH_CONVERSION_bessel_LOCAL_MAIN" ts.lib utils.lib atl.lib  tracer.lib /nologo /subsystem:console /machine:I386 /libpath:"$(CTESK_HOME)\lib\win32" /W3 /GX /O2 /I /D /D /D /D /D /YX /FD /c

!ELSEIF  "$(CFG)" == "bessel - Win32 Debug"

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
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "../../.." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "MATH_BESSEL_LOCAL_MAIN" /FR /YX /FD /GZ  /c
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Ws2_32.lib ts.lib utils.lib atl.lib  tracer.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"$(CTESK_HOME)\lib\win32"

!ENDIF 

# Begin Target

# Name "bessel - Win32 Release"
# Name "bessel - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Generated"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\~bessel_media.c
# End Source File
# Begin Source File

SOURCE=.\~bessel_model.c
# End Source File
# Begin Source File

SOURCE=.\~bessel_scenario.c
# End Source File
# End Group
# Begin Source File

SOURCE=..\bessel_config.c
# End Source File
# Begin Source File

SOURCE=..\bessel_media.sec

!IF  "$(CFG)" == "bessel - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\bessel_media.sec
InputName=bessel_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "../../.." /I "$(CTESK_HOME)\include" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "MATH_BESSEL_LOCAL_MAIN" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../bessel_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "bessel - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\bessel_media.sec
InputName=bessel_media

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "../../.." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "MATH_BESSEL_LOCAL_MAIN" /FR /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../bessel_media.sec" > "$(InputName).sei" 
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

SOURCE=..\bessel_model.sec

!IF  "$(CFG)" == "bessel - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\bessel_model.sec
InputName=bessel_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "../../.." /I "$(CTESK_HOME)\include" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "MATH_BESSEL_LOCAL_MAIN" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../bessel_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "bessel - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\bessel_model.sec
InputName=bessel_model

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "../../.." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "MATH_BESSEL_LOCAL_MAIN" /FR /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../bessel_model.sec" > "$(InputName).sei" 
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

SOURCE=.\bessel_scenario.sec

!IF  "$(CFG)" == "bessel - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=.\bessel_scenario.sec
InputName=bessel_scenario

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "../../.." /I "$(CTESK_HOME)\include" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "MATH_BESSEL_LOCAL_MAIN" /YX /FD /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "./bessel_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "bessel - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=.\bessel_scenario.sec
InputName=bessel_scenario

"~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "../../.." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "MATH_BESSEL_LOCAL_MAIN" /FR /YX /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "./bessel_scenario.sec" > "$(InputName).sei" 
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
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\bessel_config.h
# End Source File
# Begin Source File

SOURCE=..\bessel_media.seh
# End Source File
# Begin Source File

SOURCE=..\bessel_model.seh
# End Source File
# Begin Source File

SOURCE=.\bessel_scenario.seh
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\trace.xml
# End Source File
# End Target
# End Project
