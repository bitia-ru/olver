# Microsoft Developer Studio Project File - Name="deptree" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=deptree - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "deptree.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "deptree.mak" CFG="deptree - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "deptree - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "deptree - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "TestSuite/config"
# PROP Scc_LocalPath ".."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "deptree - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin\Release"
# PROP Intermediate_Dir "objs\deptree\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DEPTREE_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\external\PCCTS\h" /I "..\external\stl" /I "..\src" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DEPTREE_EXPORTS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /machine:I386 /out:"..\bin\Release/handbook.exe"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "deptree - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin\Debug"
# PROP Intermediate_Dir "objs\deptree\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DEPTREE_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\external\PCCTS\h" /I "..\external\stl" /I "..\src" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DEPTREE_EXPORTS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\bin\Debug/handbook.exe" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "deptree - Win32 Release"
# Name "deptree - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "parser"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\deptree\DDLGLexer.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\src\deptree\deptreegrammar.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\src\deptree\DepTreeParser.cpp
# End Source File
# End Group
# Begin Group "handbook"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\handbook\CmdLineOptions.cpp
# End Source File
# Begin Source File

SOURCE=..\src\handbook\handbook.cpp
# End Source File
# End Group
# Begin Group "configuration"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\configuration\ConfigFile.cpp
# End Source File
# Begin Source File

SOURCE=..\src\configuration\ConfigReader.cpp
# End Source File
# Begin Source File

SOURCE=..\src\configuration\ConfigWriter.cpp
# End Source File
# End Group
# Begin Group "testplan"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\testplan\TestPlan.cpp
# End Source File
# Begin Source File

SOURCE=..\src\testplan\TestPlanReader.cpp
# End Source File
# End Group
# Begin Group "deptree"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\deptree\DepTree.cpp
# End Source File
# Begin Source File

SOURCE=..\src\deptree\deptreecommon.cpp
# ADD CPP /Yc"deptreecommon.h"
# End Source File
# Begin Source File

SOURCE=..\src\deptree\DepTreeParserExt.cpp
# End Source File
# Begin Source File

SOURCE=..\src\deptree\DepTreeReader.cpp
# End Source File
# Begin Source File

SOURCE=..\src\deptree\DepTreeXMLWriter.cpp
# End Source File
# End Group
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "parser_"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\deptree\DDLGLexer.h
# End Source File
# Begin Source File

SOURCE=..\src\deptree\deptreegrammar.g

!IF  "$(CFG)" == "deptree - Win32 Release"

# Begin Custom Build
ProjDir=.
InputPath=..\src\deptree\deptreegrammar.g

BuildCmds= \
	..\external\PCCTS\bin\antlr.exe -CC $(ProjDir)\..\src\deptree\deptreegrammar.g -o $(ProjDir)\..\src\deptree -ft dtokens.h -nopurify \
	..\external\PCCTS\bin\dlg.exe -CC -C1 -i -ci $(ProjDir)\..\src\deptree\parser.dlg -o $(ProjDir)\..\src\deptree -cl DDlgLexer \
	

"$(ProjDir)\..\src\deptree\deptreegrammar.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\DepTreeParser.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\DDlgLexer.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\DepTreeParser.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\DDLGLexer.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\dtokens.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\parser.dlg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "deptree - Win32 Debug"

# Begin Custom Build
ProjDir=.
InputPath=..\src\deptree\deptreegrammar.g

BuildCmds= \
	..\external\PCCTS\bin\antlr.exe -CC $(ProjDir)\..\src\deptree\deptreegrammar.g -o $(ProjDir)\..\src\deptree -ft dtokens.h -nopurify \
	..\external\PCCTS\bin\dlg.exe -CC -C1 -i -ci $(ProjDir)\..\src\deptree\parser.dlg -o $(ProjDir)\..\src\deptree -cl DDlgLexer \
	

"$(ProjDir)\..\src\deptree\deptreegrammar.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\DepTreeParser.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\DDlgLexer.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\DepTreeParser.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\DDLGLexer.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\dtokens.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(ProjDir)\..\src\deptree\parser.dlg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\src\deptree\DepTreeParser.h
# End Source File
# End Group
# Begin Group "handbook headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\handbook\CmdLineOptions.h
# End Source File
# End Group
# Begin Group "configuration headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\configuration\ConfigFile.h
# End Source File
# Begin Source File

SOURCE=..\src\configuration\ConfigReader.h
# End Source File
# Begin Source File

SOURCE=..\src\configuration\ConfigWriter.h
# End Source File
# End Group
# Begin Group "testplan headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\testplan\TestPlan.h
# End Source File
# Begin Source File

SOURCE=..\src\testplan\testplancommon.h
# End Source File
# Begin Source File

SOURCE=..\src\testplan\TestPlanReader.h
# End Source File
# End Group
# Begin Group "deptree headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\deptree\DepTree.h
# End Source File
# Begin Source File

SOURCE=..\src\deptree\deptreecommon.h
# End Source File
# Begin Source File

SOURCE=..\src\deptree\deptreegrammar.h
# End Source File
# Begin Source File

SOURCE=..\src\deptree\deptreelib.h
# End Source File
# Begin Source File

SOURCE=..\src\deptree\DepTreeParserExt.h
# End Source File
# Begin Source File

SOURCE=..\src\deptree\DepTreeReader.h
# End Source File
# Begin Source File

SOURCE=..\src\deptree\DepTreeXMLWriter.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\src\configuration\configcommon.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=..\olver.tree
# End Source File
# End Target
# End Project
