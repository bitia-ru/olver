# Microsoft Developer Studio Project File - Name="ncurses" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=ncurses - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ncurses.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ncurses.mak" CFG="ncurses - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ncurses - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ncurses - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "TestSuite/src/model/ncurses"
# PROP Scc_LocalPath ".."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ncurses - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "../.." /I "$(CTESK_HOME)\include" /D "_LIB" /D "_DEBUG" /D "WIN32" /D "_MBCS" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "ncurses - Win32 Release"
# Name "ncurses - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Generated"

# PROP Default_Filter ""
# Begin Group "Excluded"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\~add_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~add_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~attr_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~attr_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~bkgd_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~bkgd_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~border_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~border_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~char_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~char_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~chgat_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~chgat_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~clear_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~clear_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~color_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~color_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~control_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~control_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~input_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~input_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~insert_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~insert_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~line_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~line_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~misc_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~misc_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~mode_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~mode_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~move_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~move_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~ncurses_data.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~pad_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~pad_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~printf_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~printf_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~refresh_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~refresh_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~scanf_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~scanf_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~screen_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~screen_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~scroll_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~scroll_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~slk_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~slk_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~string_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~string_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~termcap_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~termcap_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~terminal_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~terminal_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~terminfo_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~terminfo_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~timeout_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~timeout_model.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~window_media.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\~window_model.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Source File

SOURCE=..\char\tests\~add_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../char/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../char/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\chstr\tests\~add_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../chstr/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../chstr/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~add_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\char\tests\~add_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../char/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../char/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\chstr\tests\~add_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../chstr/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../chstr/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~add_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\tests\~attr_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\tests\~attr_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\bkgd\tests\~bkgd_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../bkgd/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../bkgd/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\bkgd\tests\~bkgd_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../bkgd/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../bkgd/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\border\tests\~border_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../border/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../border/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\border\tests\~border_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../border/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../border/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\tests\~char_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../input/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../input/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\tests\~char_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../input/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../input/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\chgat\tests\~chgat_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../chgat/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../chgat/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\chgat\tests\~chgat_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../chgat/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../chgat/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\clear\tests\~clear_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../clear/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../clear/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\clear\tests\~clear_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../clear/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../clear/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\color\tests\~color_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../color/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../color/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\color\tests\~color_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../color/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../color/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\tests\~control_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../terminal/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../terminal/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\tests\~control_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../terminal/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../terminal/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\char\tests\~input_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../char/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../char/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\chstr\tests\~input_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../chstr/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../chstr/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\tests\~input_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../input/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../input/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~input_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\char\tests\~input_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../char/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../char/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\chstr\tests\~input_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../chstr/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../chstr/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\tests\~input_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../input/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../input/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~input_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\char\tests\~insert_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../char/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../char/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~insert_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\char\tests\~insert_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../char/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../char/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~insert_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\line\tests\~line_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../line/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../line/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\line\tests\~line_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../line/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../line/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\misc\tests\~misc_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../misc/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../misc/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\misc\tests\~misc_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../misc/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../misc/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\mode\tests\~mode_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../mode/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../mode/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\mode\tests\~mode_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../mode/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../mode/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\move\tests\~move_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../move/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../move/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\move\tests\~move_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../move/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../move/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tests\~ncurses_data.c
# End Source File
# Begin Source File

SOURCE=..\window\tests\~pad_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\tests\~pad_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~printf_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~printf_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\tests\~refresh_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\tests\~refresh_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~scanf_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\tests\~scanf_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../string/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../string/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\screen\tests\~screen_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../screen/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../screen/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\screen\tests\~screen_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../screen/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../screen/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\tests\~scroll_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\tests\~scroll_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\slk\tests\~slk_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../slk/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../slk/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\slk\tests\~slk_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../slk/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../slk/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\tests\~string_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../input/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../input/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\tests\~string_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../input/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../input/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\tests\~termcap_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../terminal/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../terminal/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\tests\~termcap_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../terminal/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../terminal/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\tests\~terminal_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../terminal/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../terminal/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\tests\~terminal_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../terminal/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../terminal/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\tests\~terminfo_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../terminal/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../terminal/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\tests\~terminfo_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../terminal/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../terminal/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\tests\~timeout_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../input/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../input/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\tests\~timeout_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../input/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../input/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\tests\~window_media.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\tests\~window_model.c

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "../window/tests/Release"

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "../window/tests/Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Bkgd"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\bkgd\bkgd_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Intermediate_Dir "Release"
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\bkgd
InputPath=..\bkgd\bkgd_media.sec
InputName=bkgd_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../bkgd/bkgd_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Intermediate_Dir "Debug"
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\bkgd
InputPath=..\bkgd\bkgd_media.sec
InputName=bkgd_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../bkgd/bkgd_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\bkgd\bkgd_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\bkgd
InputPath=..\bkgd\bkgd_model.sec
InputName=bkgd_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../bkgd/bkgd_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\bkgd
InputPath=..\bkgd\bkgd_model.sec
InputName=bkgd_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../bkgd/bkgd_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Border"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\border\border_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\border
InputPath=..\border\border_media.sec
InputName=border_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../border/border_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\border
InputPath=..\border\border_media.sec
InputName=border_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../border/border_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\border\border_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\border
InputPath=..\border\border_model.sec
InputName=border_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../border/border_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\border
InputPath=..\border\border_model.sec
InputName=border_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../border/border_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Char"

# PROP Default_Filter ""
# Begin Group "Char.Add"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\char\add_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\add_media.sec
InputName=add_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/add_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\add_media.sec
InputName=add_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/add_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\char\add_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\add_model.sec
InputName=add_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/add_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\add_model.sec
InputName=add_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/add_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Char.Input"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\char\input_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\input_media.sec
InputName=input_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/input_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\input_media.sec
InputName=input_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/input_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\char\input_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\input_model.sec
InputName=input_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/input_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\input_model.sec
InputName=input_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/input_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Char.Insert"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\char\insert_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\insert_media.sec
InputName=insert_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/insert_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\insert_media.sec
InputName=insert_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/insert_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\char\insert_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\insert_model.sec
InputName=insert_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/insert_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\char
InputPath=..\char\insert_model.sec
InputName=insert_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../char/insert_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Group "Chgat"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\chgat\chgat_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chgat
InputPath=..\chgat\chgat_media.sec
InputName=chgat_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chgat/chgat_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chgat
InputPath=..\chgat\chgat_media.sec
InputName=chgat_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chgat/chgat_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\chgat\chgat_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chgat
InputPath=..\chgat\chgat_model.sec
InputName=chgat_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chgat/chgat_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chgat
InputPath=..\chgat\chgat_model.sec
InputName=chgat_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chgat/chgat_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Chstr"

# PROP Default_Filter ""
# Begin Group "Chstr.Add"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\chstr\add_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chstr
InputPath=..\chstr\add_media.sec
InputName=add_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chstr/add_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chstr
InputPath=..\chstr\add_media.sec
InputName=add_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chstr/add_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\chstr\add_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chstr
InputPath=..\chstr\add_model.sec
InputName=add_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chstr/add_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chstr
InputPath=..\chstr\add_model.sec
InputName=add_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chstr/add_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Chstr.Input"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\chstr\input_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chstr
InputPath=..\chstr\input_media.sec
InputName=input_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chstr/input_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chstr
InputPath=..\chstr\input_media.sec
InputName=input_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chstr/input_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\chstr\input_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chstr
InputPath=..\chstr\input_model.sec
InputName=input_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chstr/input_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\chstr
InputPath=..\chstr\input_model.sec
InputName=input_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../chstr/input_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Group "Clear"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\clear\clear_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\clear
InputPath=..\clear\clear_media.sec
InputName=clear_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../clear/clear_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\clear
InputPath=..\clear\clear_media.sec
InputName=clear_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../clear/clear_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\clear\clear_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\clear
InputPath=..\clear\clear_model.sec
InputName=clear_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../clear/clear_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\clear
InputPath=..\clear\clear_model.sec
InputName=clear_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../clear/clear_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Color"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\color\color_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\color
InputPath=..\color\color_media.sec
InputName=color_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../color/color_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\color
InputPath=..\color\color_media.sec
InputName=color_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../color/color_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\color\color_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\color
InputPath=..\color\color_model.sec
InputName=color_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../color/color_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\color
InputPath=..\color\color_model.sec
InputName=color_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../color/color_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Input"

# PROP Default_Filter ""
# Begin Group "Input.Char"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\input\char_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\char_media.sec
InputName=char_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/char_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\char_media.sec
InputName=char_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/char_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\char_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\char_model.sec
InputName=char_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/char_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\char_model.sec
InputName=char_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/char_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Input.Input"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\input\input_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\input_media.sec
InputName=input_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/input_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\input_media.sec
InputName=input_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/input_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\input_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\input_model.sec
InputName=input_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/input_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\input_model.sec
InputName=input_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/input_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Input.String"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\input\string_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\string_media.sec
InputName=string_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/string_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\string_media.sec
InputName=string_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/string_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\string_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\string_model.sec
InputName=string_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/string_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\string_model.sec
InputName=string_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/string_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Input.Timeout"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\input\timeout_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\timeout_media.sec
InputName=timeout_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/timeout_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\timeout_media.sec
InputName=timeout_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/timeout_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\input\timeout_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\timeout_model.sec
InputName=timeout_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/timeout_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\input
InputPath=..\input\timeout_model.sec
InputName=timeout_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../input/timeout_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Group "Line"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\line\line_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\line
InputPath=..\line\line_media.sec
InputName=line_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../line/line_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\line
InputPath=..\line\line_media.sec
InputName=line_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../line/line_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\line\line_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\line
InputPath=..\line\line_model.sec
InputName=line_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../line/line_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\line
InputPath=..\line\line_model.sec
InputName=line_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../line/line_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Misc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\misc\misc_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\misc
InputPath=..\misc\misc_media.sec
InputName=misc_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../misc/misc_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\misc
InputPath=..\misc\misc_media.sec
InputName=misc_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../misc/misc_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\misc\misc_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\misc
InputPath=..\misc\misc_model.sec
InputName=misc_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../misc/misc_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\misc
InputPath=..\misc\misc_model.sec
InputName=misc_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../misc/misc_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Mode"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\mode\mode_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\mode
InputPath=..\mode\mode_media.sec
InputName=mode_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../mode/mode_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\mode
InputPath=..\mode\mode_media.sec
InputName=mode_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../mode/mode_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\mode\mode_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\mode
InputPath=..\mode\mode_model.sec
InputName=mode_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../mode/mode_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\mode
InputPath=..\mode\mode_model.sec
InputName=mode_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../mode/mode_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Move"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\move\move_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\move
InputPath=..\move\move_media.sec
InputName=move_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../move/move_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\move
InputPath=..\move\move_media.sec
InputName=move_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../move/move_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\move\move_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\move
InputPath=..\move\move_model.sec
InputName=move_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../move/move_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\move
InputPath=..\move\move_model.sec
InputName=move_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../move/move_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Screen"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\screen\screen_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\screen
InputPath=..\screen\screen_media.sec
InputName=screen_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../screen/screen_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\screen
InputPath=..\screen\screen_media.sec
InputName=screen_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../screen/screen_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\screen\screen_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\screen
InputPath=..\screen\screen_model.sec
InputName=screen_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../screen/screen_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\screen
InputPath=..\screen\screen_model.sec
InputName=screen_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../screen/screen_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Slk"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\slk\slk_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\slk
InputPath=..\slk\slk_media.sec
InputName=slk_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../slk/slk_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\slk
InputPath=..\slk\slk_media.sec
InputName=slk_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../slk/slk_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\slk\slk_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\slk
InputPath=..\slk\slk_model.sec
InputName=slk_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../slk/slk_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\slk
InputPath=..\slk\slk_model.sec
InputName=slk_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../slk/slk_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "String"

# PROP Default_Filter ""
# Begin Group "String.Add"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\add_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\add_media.sec
InputName=add_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/add_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\add_media.sec
InputName=add_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/add_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\add_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\add_model.sec
InputName=add_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/add_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\add_model.sec
InputName=add_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/add_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "String.Input"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\input_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\input_media.sec
InputName=input_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/input_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\input_media.sec
InputName=input_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/input_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\input_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\input_model.sec
InputName=input_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/input_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\input_model.sec
InputName=input_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/input_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "String.Insert"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\insert_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\insert_media.sec
InputName=insert_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/insert_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\insert_media.sec
InputName=insert_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/insert_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\insert_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\insert_model.sec
InputName=insert_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/insert_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\insert_model.sec
InputName=insert_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/insert_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "String.Printf"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\printf_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\printf_media.sec
InputName=printf_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/printf_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\printf_media.sec
InputName=printf_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/printf_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\printf_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\printf_model.sec
InputName=printf_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/printf_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\printf_model.sec
InputName=printf_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/printf_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "String.Scanf"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\scanf_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\scanf_media.sec
InputName=scanf_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/scanf_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\scanf_media.sec
InputName=scanf_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/scanf_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\string\scanf_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\scanf_model.sec
InputName=scanf_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/scanf_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\string
InputPath=..\string\scanf_model.sec
InputName=scanf_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../string/scanf_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Group "Terminal"

# PROP Default_Filter ""
# Begin Group "Terminal.Control"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\terminal\control_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\control_media.sec
InputName=control_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/control_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\control_media.sec
InputName=control_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/control_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\control_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\control_model.sec
InputName=control_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/control_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\control_model.sec
InputName=control_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/control_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Terminal.Termcap"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\terminal\termcap_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\termcap_media.sec
InputName=termcap_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/termcap_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\termcap_media.sec
InputName=termcap_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/termcap_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\termcap_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\termcap_model.sec
InputName=termcap_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/termcap_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\termcap_model.sec
InputName=termcap_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/termcap_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Terminal.Terminal"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\terminal\terminal_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\terminal_media.sec
InputName=terminal_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/terminal_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\terminal_media.sec
InputName=terminal_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/terminal_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\terminal_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\terminal_model.sec
InputName=terminal_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/terminal_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\terminal_model.sec
InputName=terminal_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/terminal_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Terminal.Terminfo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\terminal\terminfo_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\terminfo_media.sec
InputName=terminfo_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/terminfo_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\terminfo_media.sec
InputName=terminfo_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/terminfo_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\terminal\terminfo_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\terminfo_model.sec
InputName=terminfo_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/terminfo_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\terminal
InputPath=..\terminal\terminfo_model.sec
InputName=terminfo_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../terminal/terminfo_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Group "Window"

# PROP Default_Filter ""
# Begin Group "Window.Attr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\attr_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\attr_media.sec
InputName=attr_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/attr_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\attr_media.sec
InputName=attr_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/attr_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\attr_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\attr_model.sec
InputName=attr_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/attr_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\attr_model.sec
InputName=attr_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/attr_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Window.Pad"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\pad_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\pad_media.sec
InputName=pad_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/pad_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\pad_media.sec
InputName=pad_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/pad_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\pad_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\pad_model.sec
InputName=pad_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/pad_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\pad_model.sec
InputName=pad_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/pad_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Window.Refresh"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\refresh_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\refresh_media.sec
InputName=refresh_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/refresh_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\refresh_media.sec
InputName=refresh_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/refresh_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\refresh_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\refresh_model.sec
InputName=refresh_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/refresh_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\refresh_model.sec
InputName=refresh_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/refresh_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Window.Scroll"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\scroll_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\scroll_media.sec
InputName=scroll_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/scroll_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\scroll_media.sec
InputName=scroll_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/scroll_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\scroll_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\scroll_model.sec
InputName=scroll_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/scroll_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\scroll_model.sec
InputName=scroll_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/scroll_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Window.Window"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\window_media.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\window_media.sec
InputName=window_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/window_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\window_media.sec
InputName=window_media

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/window_media.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\window\window_model.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\window_model.sec
InputName=window_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /I "$(CTESK_HOME)\include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/window_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=\Ivanov\LinuxTest\Prim\TestSuite\src\model\ncurses\window
InputPath=..\window\window_model.sec
InputName=window_model

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "$(CTESK_HOME)\include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../window/window_model.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=..\ncurses\ncurses_config.c
# End Source File
# Begin Source File

SOURCE=.\ncurses_data.sec

!IF  "$(CFG)" == "ncurses - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=.
InputPath=.\ncurses_data.sec
InputName=ncurses_data

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "./ncurses_data.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "ncurses - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputDir=.
InputPath=.\ncurses_data.sec
InputName=ncurses_data

"$(InputDir)\tests\~$(InputName).c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c /D __SEC__ /I "../.." /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "./ncurses_data.sec" > "$(InputDir)\$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "C:$(InputDir)\$(InputName).sei" "C:$(InputDir)\tests\~$(InputName).c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputDir)\$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\~~bkgd_bkgd_media.c
# End Source File
# Begin Source File

SOURCE=.\~~bkgd_bkgd_model.c
# End Source File
# Begin Source File

SOURCE=.\~~border_border_media.c
# End Source File
# Begin Source File

SOURCE=.\~~border_border_model.c
# End Source File
# Begin Source File

SOURCE=.\~~char_add_media.c
# End Source File
# Begin Source File

SOURCE=.\~~char_add_model.c
# End Source File
# Begin Source File

SOURCE=.\~~char_input_media.c
# End Source File
# Begin Source File

SOURCE=.\~~char_input_model.c
# End Source File
# Begin Source File

SOURCE=.\~~char_insert_media.c
# End Source File
# Begin Source File

SOURCE=.\~~char_insert_model.c
# End Source File
# Begin Source File

SOURCE=.\~~chgat_chgat_media.c
# End Source File
# Begin Source File

SOURCE=.\~~chgat_chgat_model.c
# End Source File
# Begin Source File

SOURCE=.\~~chstr_add_media.c
# End Source File
# Begin Source File

SOURCE=.\~~chstr_add_model.c
# End Source File
# Begin Source File

SOURCE=.\~~chstr_input_media.c
# End Source File
# Begin Source File

SOURCE=.\~~chstr_input_model.c
# End Source File
# Begin Source File

SOURCE=.\~~clear_clear_media.c
# End Source File
# Begin Source File

SOURCE=.\~~clear_clear_model.c
# End Source File
# Begin Source File

SOURCE=.\~~color_color_media.c
# End Source File
# Begin Source File

SOURCE=.\~~color_color_model.c
# End Source File
# Begin Source File

SOURCE=.\~~input_char_media.c
# End Source File
# Begin Source File

SOURCE=.\~~input_char_model.c
# End Source File
# Begin Source File

SOURCE=.\~~input_input_media.c
# End Source File
# Begin Source File

SOURCE=.\~~input_input_model.c
# End Source File
# Begin Source File

SOURCE=.\~~input_string_media.c
# End Source File
# Begin Source File

SOURCE=.\~~input_string_model.c
# End Source File
# Begin Source File

SOURCE=.\~~input_timeout_media.c
# End Source File
# Begin Source File

SOURCE=.\~~input_timeout_model.c
# End Source File
# Begin Source File

SOURCE=.\~~line_line_media.c
# End Source File
# Begin Source File

SOURCE=.\~~line_line_model.c
# End Source File
# Begin Source File

SOURCE=.\~~misc_misc_media.c
# End Source File
# Begin Source File

SOURCE=.\~~misc_misc_model.c
# End Source File
# Begin Source File

SOURCE=.\~~mode_mode_media.c
# End Source File
# Begin Source File

SOURCE=.\~~mode_mode_model.c
# End Source File
# Begin Source File

SOURCE=.\~~move_move_media.c
# End Source File
# Begin Source File

SOURCE=.\~~move_move_model.c
# End Source File
# Begin Source File

SOURCE=.\~~screen_screen_media.c
# End Source File
# Begin Source File

SOURCE=.\~~screen_screen_model.c
# End Source File
# Begin Source File

SOURCE=.\~~slk_slk_media.c
# End Source File
# Begin Source File

SOURCE=.\~~slk_slk_model.c
# End Source File
# Begin Source File

SOURCE=.\~~string_add_media.c
# End Source File
# Begin Source File

SOURCE=.\~~string_add_model.c
# End Source File
# Begin Source File

SOURCE=.\~~string_input_media.c
# End Source File
# Begin Source File

SOURCE=.\~~string_input_model.c
# End Source File
# Begin Source File

SOURCE=.\~~string_insert_media.c
# End Source File
# Begin Source File

SOURCE=.\~~string_insert_model.c
# End Source File
# Begin Source File

SOURCE=.\~~string_printf_media.c
# End Source File
# Begin Source File

SOURCE=.\~~string_printf_model.c
# End Source File
# Begin Source File

SOURCE=.\~~string_scanf_media.c
# End Source File
# Begin Source File

SOURCE=.\~~string_scanf_model.c
# End Source File
# Begin Source File

SOURCE=.\~~terminal_control_media.c
# End Source File
# Begin Source File

SOURCE=.\~~terminal_control_model.c
# End Source File
# Begin Source File

SOURCE=.\~~terminal_termcap_media.c
# End Source File
# Begin Source File

SOURCE=.\~~terminal_termcap_model.c
# End Source File
# Begin Source File

SOURCE=.\~~terminal_terminal_media.c
# End Source File
# Begin Source File

SOURCE=.\~~terminal_terminal_model.c
# End Source File
# Begin Source File

SOURCE=.\~~terminal_terminfo_media.c
# End Source File
# Begin Source File

SOURCE=.\~~terminal_terminfo_model.c
# End Source File
# Begin Source File

SOURCE=.\~~window_attr_media.c
# End Source File
# Begin Source File

SOURCE=.\~~window_attr_model.c
# End Source File
# Begin Source File

SOURCE=.\~~window_pad_media.c
# End Source File
# Begin Source File

SOURCE=.\~~window_pad_model.c
# End Source File
# Begin Source File

SOURCE=.\~~window_refresh_media.c
# End Source File
# Begin Source File

SOURCE=.\~~window_refresh_model.c
# End Source File
# Begin Source File

SOURCE=.\~~window_scroll_media.c
# End Source File
# Begin Source File

SOURCE=.\~~window_scroll_model.c
# End Source File
# Begin Source File

SOURCE=.\~~window_window_media.c
# End Source File
# Begin Source File

SOURCE=.\~~window_window_model.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Bkgd Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\bkgd\bkgd_media.seh
# End Source File
# Begin Source File

SOURCE=..\bkgd\bkgd_model.seh
# End Source File
# End Group
# Begin Group "Border Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\border\border_media.seh
# End Source File
# Begin Source File

SOURCE=..\border\border_model.seh
# End Source File
# End Group
# Begin Group "Char Headers"

# PROP Default_Filter ""
# Begin Group "Char.Add Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\char\add_media.seh
# End Source File
# Begin Source File

SOURCE=..\char\add_model.seh
# End Source File
# End Group
# Begin Group "Char.Input Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\char\input_media.seh
# End Source File
# Begin Source File

SOURCE=..\char\input_model.seh
# End Source File
# End Group
# Begin Group "Char.Insert Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\char\insert_media.seh
# End Source File
# Begin Source File

SOURCE=..\char\insert_model.seh
# End Source File
# End Group
# End Group
# Begin Group "Chgat Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\chgat\chgat_media.seh
# End Source File
# Begin Source File

SOURCE=..\chgat\chgat_model.seh
# End Source File
# End Group
# Begin Group "Chstr Headers"

# PROP Default_Filter ""
# Begin Group "Chstr.Add Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\chstr\add_media.seh
# End Source File
# Begin Source File

SOURCE=..\chstr\add_model.seh
# End Source File
# End Group
# Begin Group "Chstr.Input Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\chstr\input_media.seh
# End Source File
# Begin Source File

SOURCE=..\chstr\input_model.seh
# End Source File
# End Group
# End Group
# Begin Group "Clear Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\clear\clear_media.seh
# End Source File
# Begin Source File

SOURCE=..\clear\clear_model.seh
# End Source File
# End Group
# Begin Group "Color Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\color\color_media.seh
# End Source File
# Begin Source File

SOURCE=..\color\color_model.seh
# End Source File
# End Group
# Begin Group "Input Headers"

# PROP Default_Filter ""
# Begin Group "Input.Char Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\input\char_media.seh
# End Source File
# Begin Source File

SOURCE=..\input\char_model.seh
# End Source File
# End Group
# Begin Group "Input.Input Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\input\input_media.seh
# End Source File
# Begin Source File

SOURCE=..\input\input_model.seh
# End Source File
# End Group
# Begin Group "Input.String Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\input\string_media.seh
# End Source File
# Begin Source File

SOURCE=..\input\string_model.seh
# End Source File
# End Group
# Begin Group "Input.Timeout Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\input\timeout_media.seh
# End Source File
# Begin Source File

SOURCE=..\input\timeout_model.seh
# End Source File
# End Group
# End Group
# Begin Group "Line Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\line\line_media.seh
# End Source File
# Begin Source File

SOURCE=..\line\line_model.seh
# End Source File
# End Group
# Begin Group "Misc Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\misc\misc_media.seh
# End Source File
# Begin Source File

SOURCE=..\misc\misc_model.seh
# End Source File
# End Group
# Begin Group "Mode Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\mode\mode_media.seh
# End Source File
# Begin Source File

SOURCE=..\mode\mode_model.seh
# End Source File
# End Group
# Begin Group "Move Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\move\move_media.seh
# End Source File
# Begin Source File

SOURCE=..\move\move_model.seh
# End Source File
# End Group
# Begin Group "Screen Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\screen\screen_media.seh
# End Source File
# Begin Source File

SOURCE=..\screen\screen_model.seh
# End Source File
# End Group
# Begin Group "Slk Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\slk\slk_media.seh
# End Source File
# Begin Source File

SOURCE=..\slk\slk_model.seh
# End Source File
# End Group
# Begin Group "String Headers"

# PROP Default_Filter ""
# Begin Group "String.Add Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\add_media.seh
# End Source File
# Begin Source File

SOURCE=..\string\add_model.seh
# End Source File
# End Group
# Begin Group "String.Input Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\input_media.seh
# End Source File
# Begin Source File

SOURCE=..\string\input_model.seh
# End Source File
# End Group
# Begin Group "String.Insert Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\insert_media.seh
# End Source File
# Begin Source File

SOURCE=..\string\insert_model.seh
# End Source File
# End Group
# Begin Group "String.Printf Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\printf_media.seh
# End Source File
# Begin Source File

SOURCE=..\string\printf_model.seh
# End Source File
# End Group
# Begin Group "String.Scanf Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\string\scanf_media.seh
# End Source File
# Begin Source File

SOURCE=..\string\scanf_model.seh
# End Source File
# End Group
# End Group
# Begin Group "Terminal Headers"

# PROP Default_Filter ""
# Begin Group "Terminal.Control Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\terminal\control_media.seh
# End Source File
# Begin Source File

SOURCE=..\terminal\control_model.seh
# End Source File
# End Group
# Begin Group "Terminal.Termcap Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\terminal\termcap_media.seh
# End Source File
# Begin Source File

SOURCE=..\terminal\termcap_model.seh
# End Source File
# End Group
# Begin Group "Terminal.Terminal Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\terminal\terminal_media.seh
# End Source File
# Begin Source File

SOURCE=..\terminal\terminal_model.seh
# End Source File
# End Group
# Begin Group "Terminal.Terminfo Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\terminal\terminfo_media.seh
# End Source File
# Begin Source File

SOURCE=..\terminal\terminfo_model.seh
# End Source File
# End Group
# End Group
# Begin Group "Window Headers"

# PROP Default_Filter ""
# Begin Group "Window.Attr Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\attr_media.seh
# End Source File
# Begin Source File

SOURCE=..\window\attr_model.seh
# End Source File
# End Group
# Begin Group "Window.Pad Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\pad_media.seh
# End Source File
# Begin Source File

SOURCE=..\window\pad_model.seh
# End Source File
# End Group
# Begin Group "Window.Refresh Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\refresh_media.seh
# End Source File
# Begin Source File

SOURCE=..\window\refresh_model.seh
# End Source File
# End Group
# Begin Group "Window.Scroll Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\scroll_media.seh
# End Source File
# Begin Source File

SOURCE=..\window\scroll_model.seh
# End Source File
# End Group
# Begin Group "Window.Window Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\window\window_media.seh
# End Source File
# Begin Source File

SOURCE=..\window\window_model.seh
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\ncurses_data.seh
# End Source File
# End Group
# End Target
# End Project
