# Microsoft Developer Studio Project File - Name="common" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=common - Win32 Debug Single Threaded
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "win_common2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "win_common2.mak" CFG="common - Win32 Debug Single Threaded"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "common - Win32 Debug Single Threaded" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "TestSuite/src/model"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "common___Win32_Debug_Single_Threaded"
# PROP BASE Intermediate_Dir "common___Win32_Debug_Single_Threaded"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "common___Win32_Debug_Single_Threaded"
# PROP Intermediate_Dir "common___Win32_Debug_Single_Threaded"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ  /c
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Ws2_32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"$(CTESK_HOME)\lib\win32"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Ws2_32.lib ts.lib utils.lib atl.lib tracer.lib  ctesk.lib /nologo /subsystem:console /debug /machine:I386 /out:"bin/olver.exe" /pdbtype:sept /libpath:"$(CTESK_HOME)\lib\win32" /libpath:"$(CTESK_HOME)\lib\msvc6"
# Begin Target

# Name "common - Win32 Debug Single Threaded"
# Begin Group "generated"

# PROP Default_Filter ".c"
# Begin Source File

SOURCE=.\~~common_cbytearray.c
# End Source File
# Begin Source File

SOURCE=.\~~common_chtypearray.c
# End Source File
# Begin Source File

SOURCE=.\~~common_common_media.c
# End Source File
# Begin Source File

SOURCE=.\~~common_common_model.c
# End Source File
# Begin Source File

SOURCE=.\~~common_common_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~common_control_center.c
# End Source File
# Begin Source File

SOURCE=.\~~common_cstring.c
# End Source File
# Begin Source File

SOURCE=.\~~common_init.c
# End Source File
# Begin Source File

SOURCE=.\~~common_main.c
# End Source File
# Begin Source File

SOURCE=.\~~common_pointer.c
# End Source File
# Begin Source File

SOURCE=.\~~common_tree.c
# End Source File
# Begin Source File

SOURCE=.\~~common_tsstream.c
# End Source File
# Begin Source File

SOURCE=.\~~common_wchararray.c
# End Source File
# Begin Source File

SOURCE=.\~~common_wstring.c
# End Source File
# Begin Source File

SOURCE=.\~~config_config_loader.c
# End Source File
# Begin Source File

SOURCE=.\~~config_interpretation.c
# End Source File
# Begin Source File

SOURCE=.\~~config_pthread_config.c
# End Source File
# Begin Source File

SOURCE=.\~~config_system_config.c
# End Source File
# Begin Source File

SOURCE=.\~~config_type_config.c
# End Source File
# Begin Source File

SOURCE=.\~~core_core.c
# End Source File
# Begin Source File

SOURCE=.\~~data_basis.c
# End Source File
# Begin Source File

SOURCE=.\~~data_embed_model.c
# End Source File
# Begin Source File

SOURCE=.\~~data_signal_model.c
# End Source File
# Begin Source File

SOURCE=.\~~data_sys_time_model.c
# End Source File
# Begin Source File

SOURCE=.\~~data_sys_timeb_model.c
# End Source File
# Begin Source File

SOURCE=.\~~data_time_model.c
# End Source File
# Begin Source File

SOURCE=.\~~data_wchar_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_dir_dir_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_dir_dir_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_dir_tests_dir_main.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_dir_tests_dir_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_dir_tests_fs_dump.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_fifo_fifo_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_fifo_fifo_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_fifo_tests_fifo_main.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_fifo_tests_fifo_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_fs_fs_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_fs_fs_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_fs_tests_fs_main.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_fs_tests_fs_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_ftw_ftw_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_ftw_ftw_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_ftw_tests_ftw_main.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_ftw_tests_ftw_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_glob_glob_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_glob_glob_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_glob_tests_glob_main.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_glob_tests_glob_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_access_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_access_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_meta_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_meta_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_statvfs_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_statvfs_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_tests_access_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_tests_fs_meta_common_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_tests_meta_main.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_tests_meta_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_meta_tests_statvfs_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_name_name_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_name_name_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_name_tests_name_main.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_name_tests_name_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_symlink_symlink_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_symlink_symlink_model.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_symlink_tests_symlink_main.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_symlink_tests_symlink_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_tmpfile_tests_tmpfile_main.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_tmpfile_tests_tmpfile_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_tmpfile_tmpfile_media.c
# End Source File
# Begin Source File

SOURCE=.\~~fs_tmpfile_tmpfile_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_file_file_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_file_file_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_file_tests_file_lock_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_file_tests_file_main.c
# End Source File
# Begin Source File

SOURCE=.\~~io_file_tests_file_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_buffer_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_buffer_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_fstream_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_fstream_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_lock_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_lock_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_tests_buffer_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_tests_fstream_main.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_tests_fstream_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_tests_lock_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_tests_wstream_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_wstream_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_fstream_wstream_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_multiplex_multiplex_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_multiplex_multiplex_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_multiplex_tests_multiplex_main.c
# End Source File
# Begin Source File

SOURCE=.\~~io_multiplex_tests_multiplex_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_pipe_pipe_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_pipe_pipe_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_pipe_tests_pipe_main.c
# End Source File
# Begin Source File

SOURCE=.\~~io_pipe_tests_pipe_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_streams_streams_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_streams_streams_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_streams_tests_streams_main.c
# End Source File
# Begin Source File

SOURCE=.\~~io_streams_tests_streams_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_syslog_syslog_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_syslog_syslog_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_syslog_tests_syslog_main.c
# End Source File
# Begin Source File

SOURCE=.\~~io_syslog_tests_syslog_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_term_media.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_term_model.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_cf_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_cterm_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_open_tty_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_pt_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_rw_canon_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_rw_case_a_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_rw_case_b_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_rw_case_c_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_rw_case_d_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_tc_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_tcpgrp_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_term_main.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_term_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~io_term_tests_tty_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_collate_collate_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_collate_collate_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_collate_tests_collate_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_collate_tests_collate_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_ctrans_ctrans_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_ctrans_ctrans_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_ctrans_tests_ctrans_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_ctrans_tests_ctrans_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_ctype_ctype_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_ctype_ctype_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_ctype_tests_ctype_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_ctype_tests_ctype_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_iconv_iconv_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_iconv_iconv_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_iconv_tests_iconv_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_iconv_tests_iconv_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_locale_locale_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_locale_locale_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_locale_tests_locale_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_locale_tests_locale_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_messages_messages_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_messages_messages_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_messages_tests_messages_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_messages_tests_messages_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_nlcat_nlcat_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_nlcat_nlcat_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_nlcat_tests_nlcat_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_nlcat_tests_nlcat_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_textdomain_tests_textdomain_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_textdomain_textdomain_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_textdomain_textdomain_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wcollate_tests_wcollate_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wcollate_tests_wcollate_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wcollate_wcollate_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wcollate_wcollate_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wctrans_tests_wctrans_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wctrans_tests_wctrans_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wctrans_wctrans_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wctrans_wctrans_model.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wctype_tests_wctype_main.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wctype_tests_wctype_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wctype_wctype_media.c
# End Source File
# Begin Source File

SOURCE=.\~~locale_wctype_wctype_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_bessel_bessel_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_bessel_bessel_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_cexp_cexp_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_cexp_cexp_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_cexp_tests_cexp_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_cexp_tests_cexp_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_chyper_chyper_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_chyper_chyper_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_chyper_tests_chyper_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_chyper_tests_chyper_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_complex_complex_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_complex_complex_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_complex_tests_complex_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_complex_tests_complex_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_ctrig_ctrig_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_ctrig_ctrig_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_ctrig_tests_ctrig_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_ctrig_tests_ctrig_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_error_error_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_error_error_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_error_tests_error_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_error_tests_error_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_exp_exp_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_exp_exp_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_exp_tests_exp_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_exp_tests_exp_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_gamma_gamma_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_gamma_gamma_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_gamma_tests_gamma_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_gamma_tests_gamma_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_hyper_hyper_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_hyper_hyper_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_hyper_tests_hyper_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_hyper_tests_hyper_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_integer_integer_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_integer_integer_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_integer_tests_integer_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_integer_tests_integer_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_math_math_data.c
# End Source File
# Begin Source File

SOURCE=.\~~math_rand_rand_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_rand_rand_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_rand_tests_rand_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_rand_tests_rand_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_real_real_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_real_real_model.c
# End Source File
# Begin Source File

SOURCE=.\~~math_real_tests_real_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_real_tests_real_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_trig_tests_trig_main.c
# End Source File
# Begin Source File

SOURCE=.\~~math_trig_tests_trig_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~math_trig_trig_media.c
# End Source File
# Begin Source File

SOURCE=.\~~math_trig_trig_model.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_break_break_media.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_break_break_model.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_break_tests_break_main.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_break_tests_break_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_heap_heap_media.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_heap_heap_model.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_heap_tests_heap_main.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_heap_tests_heap_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_heap_tests_memory_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_mman_mman_media.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_mman_mman_model.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_mman_tests_mman_b1_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_mman_tests_mman_errors_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_mman_tests_mman_main.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_mman_tests_mman_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~memory_mman_tests_mman_usualuse_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_bkgd_bkgd_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_bkgd_bkgd_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_bkgd_tests_bkgd_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_bkgd_tests_bkgd_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_border_border_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_border_border_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_border_tests_border_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_border_tests_border_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_add_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_add_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_input_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_input_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_insert_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_insert_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_tests_add_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_tests_char_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_tests_input_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_char_tests_insert_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chgat_chgat_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chgat_chgat_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chgat_tests_chgat_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chgat_tests_chgat_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chstr_add_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chstr_add_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chstr_input_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chstr_input_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chstr_tests_add_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chstr_tests_chstr_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_chstr_tests_input_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_clear_clear_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_clear_clear_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_clear_tests_clear_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_clear_tests_clear_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_color_color_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_color_color_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_color_tests_color_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_color_tests_color_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_char_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_char_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_input_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_input_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_string_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_string_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_tests_char_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_tests_input_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_tests_input_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_tests_string_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_tests_timeout_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_timeout_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_input_timeout_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_line_line_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_line_line_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_line_tests_line_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_line_tests_line_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_misc_misc_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_misc_misc_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_misc_tests_misc_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_misc_tests_misc_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_mode_mode_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_mode_mode_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_mode_tests_mode_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_mode_tests_mode_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_move_move_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_move_move_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_move_tests_move_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_move_tests_move_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_ncurses_ncurses_data.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_ncurses_special_chars_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_screen_screen_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_screen_screen_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_screen_tests_screen_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_screen_tests_screen_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_slk_slk_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_slk_slk_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_slk_tests_slk_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_slk_tests_slk_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_add_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_add_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_input_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_input_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_insert_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_insert_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_printf_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_printf_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_scanf_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_scanf_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_tests_add_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_tests_input_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_tests_insert_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_tests_printf_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_tests_scanf_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_string_tests_string_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_control_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_control_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_termcap_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_termcap_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_terminal_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_terminal_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_terminfo_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_terminfo_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_tests_control_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_tests_control_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_tests_termcap_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_tests_termcap_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_tests_terminal_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_tests_terminal_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_terminal_tests_terminfo_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_attr_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_attr_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_pad_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_pad_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_refresh_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_refresh_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_scroll_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_scroll_model.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_tests_attr_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_tests_pad_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_tests_refresh_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_tests_scroll_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_tests_scroll_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_tests_window_main.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_tests_window_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_window_media.c
# End Source File
# Begin Source File

SOURCE=.\~~ncurses_window_window_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_context_context_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_context_context_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_context_tests_context_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_context_tests_context_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_environ_environ_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_environ_environ_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_environ_tests_environ_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_environ_tests_environ_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_fenv_fenv_common.c
# End Source File
# Begin Source File

SOURCE=.\~~process_fenv_fenv_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_fenv_fenv_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_fenv_tests_fenv_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_fenv_tests_fenv_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_goto_goto_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_goto_goto_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_goto_tests_goto_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_goto_tests_goto_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_ipc_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_ipc_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_msg_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_msg_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_sem_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_sem_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_shm_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_shm_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_tests_ipc_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_tests_ipc_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_tests_msg_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_tests_sem_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_ipc_tests_shm_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_fs_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_fs_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_meta_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_meta_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_nice_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_nice_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_tests_fs_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_tests_meta_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_tests_meta_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_tests_nice_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_tests_user_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_user_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_meta_user_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_pgroup_pgroup_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_pgroup_pgroup_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_pgroup_tests_pgroup_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_pgroup_tests_pgroup_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_process_process_common.c
# End Source File
# Begin Source File

SOURCE=.\~~process_process_process_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_process_process_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_process_tests_process_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_process_tests_process_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_resources_resources_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_resources_resources_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_resources_tests_resources_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_resources_tests_resources_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~process_scheduler_scheduler_media.c
# End Source File
# Begin Source File

SOURCE=.\~~process_scheduler_scheduler_model.c
# End Source File
# Begin Source File

SOURCE=.\~~process_scheduler_tests_scheduler_main.c
# End Source File
# Begin Source File

SOURCE=.\~~process_scheduler_tests_scheduler_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_attr_attr_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_attr_attr_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_attr_tests_attr_main.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_attr_tests_attr_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_cond_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_cond_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_condattr_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_condattr_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_tests_cond_error_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_tests_cond_init_destroy_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_tests_cond_main.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_tests_cond_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_tests_cond_single_cond_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_cond_tests_condattr_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_mutex_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_mutex_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_mutexattr_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_mutexattr_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_tests_mutex_main.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_tests_mutex_mixed_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_tests_mutex_mixed_types_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_tests_mutex_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_tests_mutex_simple_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_tests_mutex_static_init_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_mutex_tests_mutexattr_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_pthread_pthread_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_pthread_pthread_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_pthread_tests_pthread_cleanup_diff_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_pthread_tests_pthread_cleanup_simple_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_pthread_tests_pthread_create_cancel_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_pthread_tests_pthread_exit_join_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_pthread_tests_pthread_main.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_pthread_tests_pthread_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_rwlock_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_rwlock_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_rwlockattr_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_rwlockattr_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlock_deadlock_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlock_errors_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlock_init_destroy_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlock_main.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlock_N_rwlock_light_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlock_N_rwlock_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlock_repeated_lock_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlock_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlock_single_rwlock_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_rwlock_tests_rwlockattr_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_scheduler_scheduler_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_scheduler_scheduler_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_scheduler_tests_scheduler_main.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_scheduler_tests_scheduler_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_sem_sem_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_sem_sem_model.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_sem_tests_sem_complex_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_sem_tests_sem_error_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_sem_tests_sem_main.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_sem_tests_sem_open_close_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_sem_tests_sem_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_tls_tests_tls_main.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_tls_tests_tls_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_tls_tls_media.c
# End Source File
# Begin Source File

SOURCE=.\~~pthread_tls_tls_model.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigaction_sigaction_media.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigaction_sigaction_model.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigaction_tests_sigaction_main.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigaction_tests_sigaction_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigctrl_sigctrl_media.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigctrl_sigctrl_model.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigctrl_tests_sigctrl_main.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigctrl_tests_sigctrl_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigsend_sigsend_media.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigsend_sigsend_model.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigsend_tests_signal_specific_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigsend_tests_sigsend_additional_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigsend_tests_sigsend_main.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigsend_tests_sigsend_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigset_sigset_media.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigset_sigset_model.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigset_tests_sigset_automatic_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigset_tests_sigset_main.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigset_tests_sigset_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigset_tests_sigset_static_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigstr_sigstr_media.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigstr_sigstr_model.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigstr_tests_sigstr_main.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigstr_tests_sigstr_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigwait_sigwait_media.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigwait_sigwait_model.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigwait_tests_sigwait_main.c
# End Source File
# Begin Source File

SOURCE=.\~~signal_sigwait_tests_sigwait_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netdata_netdata_media.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netdata_netdata_model.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netdata_tests_netdata_main.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netdata_tests_netdata_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netdb_netdb_media.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netdb_netdb_model.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netdb_tests_netdb_main.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netdb_tests_netdb_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netif_netif_media.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netif_netif_model.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netif_tests_netif_main.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_netif_tests_netif_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_clnt_media.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_clnt_model.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_pmap_media.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_pmap_model.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_secure_media.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_secure_model.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_svc_media.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_svc_model.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_tests_pmap_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_tests_rpc_main.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_tests_secure_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_tests_svc_clnt_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_tests_xdr_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_xdr_media.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_rpc_xdr_model.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_socket_socket_media.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_socket_socket_model.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_socket_tests_socket_main.c
# End Source File
# Begin Source File

SOURCE=.\~~socket_socket_tests_socket_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~system_host_host_media.c
# End Source File
# Begin Source File

SOURCE=.\~~system_host_host_model.c
# End Source File
# Begin Source File

SOURCE=.\~~system_host_tests_host_main.c
# End Source File
# Begin Source File

SOURCE=.\~~system_host_tests_host_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~system_stat_stat_media.c
# End Source File
# Begin Source File

SOURCE=.\~~system_stat_stat_model.c
# End Source File
# Begin Source File

SOURCE=.\~~system_stat_tests_stat_main.c
# End Source File
# Begin Source File

SOURCE=.\~~system_stat_tests_stat_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~system_sysconf_sysconf_media.c
# End Source File
# Begin Source File

SOURCE=.\~~system_sysconf_sysconf_model.c
# End Source File
# Begin Source File

SOURCE=.\~~system_sysconf_tests_sysconf_main.c
# End Source File
# Begin Source File

SOURCE=.\~~system_sysconf_tests_sysconf_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~system_system_system_model.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_account_media.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_account_model.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_group_media.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_group_model.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_tests_account_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_tests_group_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_tests_user_main.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_tests_user_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_user_media.c
# End Source File
# Begin Source File

SOURCE=.\~~system_user_user_model.c
# End Source File
# Begin Source File

SOURCE=.\~~time_clock_clock_media.c
# End Source File
# Begin Source File

SOURCE=.\~~time_clock_clock_model.c
# End Source File
# Begin Source File

SOURCE=.\~~time_clock_tests_clock_main.c
# End Source File
# Begin Source File

SOURCE=.\~~time_clock_tests_clock_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~time_conversion_conversion_media.c
# End Source File
# Begin Source File

SOURCE=.\~~time_conversion_conversion_model.c
# End Source File
# Begin Source File

SOURCE=.\~~time_conversion_tests_conversion_main.c
# End Source File
# Begin Source File

SOURCE=.\~~time_conversion_tests_conversion_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~time_time_tests_time_main.c
# End Source File
# Begin Source File

SOURCE=.\~~time_time_tests_time_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~time_time_time_media.c
# End Source File
# Begin Source File

SOURCE=.\~~time_time_time_model.c
# End Source File
# Begin Source File

SOURCE=.\~~time_timer_tests_timer_main.c
# End Source File
# Begin Source File

SOURCE=.\~~time_timer_tests_timer_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~time_timer_timer_media.c
# End Source File
# Begin Source File

SOURCE=.\~~time_timer_timer_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_assert_assert_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_assert_assert_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_assert_tests_assert_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_assert_tests_assert_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_bit_bit_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_bit_bit_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_bit_tests_bit_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_bit_tests_bit_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_compress_compress_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_compress_compress_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_compress_tests_compress_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_compress_tests_compress_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_strint_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_strint_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_strreal_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_strreal_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_tests_conversion_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_tests_strint_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_tests_strreal_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_tests_token_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_tests_wchar_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_tests_wstrint_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_tests_wstrreal_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_tests_wtoken_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_token_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_token_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_util_conversion_common.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_wchar_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_wchar_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_wstrint_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_wstrint_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_wstrreal_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_wstrreal_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_wtoken_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_conversion_wtoken_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_crypt_crypt_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_crypt_crypt_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_crypt_tests_crypt_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_crypt_tests_crypt_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_dl_dl_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_dl_dl_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_dl_tests_dl_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_dl_tests_dl_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_dl_tests_dl_syms.c
# End Source File
# Begin Source File

SOURCE=.\~~util_float_float_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_float_float_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_float_tests_float_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_float_tests_float_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_fmtmsg_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_fmtmsg_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_money_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_money_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_printf_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_printf_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_scanf_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_scanf_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_fmtmsg_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_format_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_format_sheafs.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_money_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_printf_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_printf_scenario_data.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_scanf_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_scanf_scenario_data.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_time_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_wprintf_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_wprintf_scenario_data.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_wscanf_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_wscanf_scenario_data.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_tests_wtime_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_time_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_time_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_wprintf_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_wprintf_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_wscanf_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_wscanf_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_wtime_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_format_wtime_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_getopt_getopt.c
# End Source File
# Begin Source File

SOURCE=.\~~util_getopt_getopt_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_getopt_getopt_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_getopt_tests_getopt_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_getopt_tests_getopt_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_inet_inet_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_inet_inet_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_inet_tests_inet_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_inet_tests_inet_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_pam_pam_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_pam_pam_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_pam_tests_pam_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_pam_tests_pam_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_regex_regex_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_regex_regex_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_regex_tests_regex_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_regex_tests_regex_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_hash_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_hash_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_queue_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_queue_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_search_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_search_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_tests_hash_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_tests_queue_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_tests_search_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_tests_search_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_tests_tree_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_tree_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_search_tree_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_casecmp_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_casecmp_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_mem_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_mem_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_str_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_str_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_tests_casecmp_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_tests_mem_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_tests_str_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_tests_string_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_tests_wcasecmp_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_tests_wmem_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_tests_wstr_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_wcasecmp_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_wcasecmp_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_wmem_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_wmem_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_wstr_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_string_wstr_model.c
# End Source File
# Begin Source File

SOURCE=.\~~util_wordexp_tests_wordexp_main.c
# End Source File
# Begin Source File

SOURCE=.\~~util_wordexp_tests_wordexp_scenario.c
# End Source File
# Begin Source File

SOURCE=.\~~util_wordexp_wordexp_media.c
# End Source File
# Begin Source File

SOURCE=.\~~util_wordexp_wordexp_model.c
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Group "Common"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\common\bigint.c
# End Source File
# Begin Source File

SOURCE=..\common\cbytearray.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\cbytearray.sec
InputName=cbytearray

"~~common_cbytearray.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/cbytearray.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_cbytearray.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\chtypearray.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\chtypearray.sec
InputName=chtypearray

"~~common_chtypearray.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/chtypearray.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_chtypearray.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\common_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\common_media.sec
InputName=common_media

"~~common_common_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/common_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_common_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\common_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\common_model.sec
InputName=common_model

"~~common_common_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/common_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_common_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\common_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\common_scenario.sec
InputName=common_scenario

"~~common_common_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/common_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_common_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\control_center.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\control_center.sec
InputName=control_center

"~~common_control_center.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/control_center.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_control_center.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\cstring.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\cstring.sec
InputName=cstring

"~~common_cstring.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/cstring.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_cstring.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\explicit_fsm.c
# End Source File
# Begin Source File

SOURCE=..\common\init.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\init.sec
InputName=init

"~~common_init.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/init.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_init.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\main.sec
InputName=main

"~~common_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\multiset.c
# End Source File
# Begin Source File

SOURCE=..\common\pointer.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\pointer.sec
InputName=pointer

"~~common_pointer.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/pointer.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_pointer.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\tree.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\tree.sec
InputName=tree

"~~common_tree.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/tree.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_tree.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\ts_socket.c
# End Source File
# Begin Source File

SOURCE=..\common\tsstream.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\tsstream.sec
InputName=tsstream

"~~common_tsstream.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/tsstream.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_tsstream.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\verbose.c
# End Source File
# Begin Source File

SOURCE=..\common\wchararray.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\wchararray.sec
InputName=wchararray

"~~common_wchararray.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/wchararray.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_wchararray.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\common\wstring.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\common\wstring.sec
InputName=wstring

"~~common_wstring.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../common/wstring.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~common_wstring.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Config"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\config\config_loader.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\config\config_loader.sec
InputName=config_loader

"~~config_config_loader.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../config/config_loader.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~config_config_loader.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\config\interpretation.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\config\interpretation.sec
InputName=interpretation

"~~config_interpretation.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../config/interpretation.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~config_interpretation.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\config\pthread_config.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\config\pthread_config.sec
InputName=pthread_config

"~~config_pthread_config.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../config/pthread_config.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~config_pthread_config.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\config\system_config.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\config\system_config.sec
InputName=system_config

"~~config_system_config.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../config/system_config.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~config_system_config.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\config\test_system_config.c
# End Source File
# Begin Source File

SOURCE=..\config\type_config.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\config\type_config.sec
InputName=type_config

"~~config_type_config.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../config/type_config.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~config_type_config.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Core"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\core\core.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\core\core.sec
InputName=core

"~~core_core.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../core/core.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~core_core.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Data"

# PROP Default_Filter ""
# Begin Group "Data.Netinet"

# PROP Default_Filter ""
# End Group
# Begin Group "Data.Sys"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\data\sys\time_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\data\sys\time_model.sec
InputName=time_model

"~~data_sys_time_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../data/sys/time_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~data_sys_time_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\data\sys\timeb_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\data\sys\timeb_model.sec
InputName=timeb_model

"~~data_sys_timeb_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../data/sys/timeb_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~data_sys_timeb_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Source File

SOURCE=..\data\basis.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\data\basis.sec
InputName=basis

"~~data_basis.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../data/basis.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~data_basis.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\data\embed_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\data\embed_model.sec
InputName=embed_model

"~~data_embed_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../data/embed_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~data_embed_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\data\errno_config.c
# End Source File
# Begin Source File

SOURCE=..\data\signal_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\data\signal_model.sec
InputName=signal_model

"~~data_signal_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../data/signal_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~data_signal_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\data\time_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\data\time_model.sec
InputName=time_model

"~~data_time_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../data/time_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~data_time_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\data\wchar_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\data\wchar_model.sec
InputName=wchar_model

"~~data_wchar_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../data/wchar_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~data_wchar_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Fs"

# PROP Default_Filter ""
# Begin Group "Fs.Dir"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\dir\dir_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\dir\tests\dir_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\dir\tests\dir_main.sec
InputName=dir_main

"~~fs_dir_tests_dir_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/dir/tests/dir_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_dir_tests_dir_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\dir\dir_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\dir\dir_media.sec
InputName=dir_media

"~~fs_dir_dir_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/dir/dir_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_dir_dir_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\dir\dir_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\dir\dir_model.sec
InputName=dir_model

"~~fs_dir_dir_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/dir/dir_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_dir_dir_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\dir\tests\dir_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\dir\tests\dir_scenario.sec
InputName=dir_scenario

"~~fs_dir_tests_dir_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/dir/tests/dir_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_dir_tests_dir_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\dir\tests\fs_dump.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\dir\tests\fs_dump.sec
InputName=fs_dump

"~~fs_dir_tests_fs_dump.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/dir/tests/fs_dump.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_dir_tests_fs_dump.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Fs.Fifo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\fifo\fifo_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\fifo\tests\fifo_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\fifo\tests\fifo_main.sec
InputName=fifo_main

"~~fs_fifo_tests_fifo_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/fifo/tests/fifo_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_fifo_tests_fifo_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\fifo\fifo_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\fifo\fifo_media.sec
InputName=fifo_media

"~~fs_fifo_fifo_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/fifo/fifo_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_fifo_fifo_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\fifo\fifo_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\fifo\fifo_model.sec
InputName=fifo_model

"~~fs_fifo_fifo_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/fifo/fifo_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_fifo_fifo_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\fifo\tests\fifo_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\fifo\tests\fifo_scenario.sec
InputName=fifo_scenario

"~~fs_fifo_tests_fifo_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/fifo/tests/fifo_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_fifo_tests_fifo_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Fs.Fs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\fs\fs_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\fs\tests\fs_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\fs\tests\fs_main.sec
InputName=fs_main

"~~fs_fs_tests_fs_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/fs/tests/fs_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_fs_tests_fs_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\fs\fs_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\fs\fs_media.sec
InputName=fs_media

"~~fs_fs_fs_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/fs/fs_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_fs_fs_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\fs\fs_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\fs\fs_model.sec
InputName=fs_model

"~~fs_fs_fs_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/fs/fs_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_fs_fs_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\fs\tests\fs_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\fs\tests\fs_scenario.sec
InputName=fs_scenario

"~~fs_fs_tests_fs_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/fs/tests/fs_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_fs_tests_fs_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Fs.Ftw"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\ftw\ftw_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\ftw\tests\ftw_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\ftw\tests\ftw_main.sec
InputName=ftw_main

"~~fs_ftw_tests_ftw_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/ftw/tests/ftw_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_ftw_tests_ftw_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\ftw\ftw_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\ftw\ftw_media.sec
InputName=ftw_media

"~~fs_ftw_ftw_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/ftw/ftw_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_ftw_ftw_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\ftw\ftw_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\ftw\ftw_model.sec
InputName=ftw_model

"~~fs_ftw_ftw_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/ftw/ftw_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_ftw_ftw_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\ftw\tests\ftw_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\ftw\tests\ftw_scenario.sec
InputName=ftw_scenario

"~~fs_ftw_tests_ftw_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/ftw/tests/ftw_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_ftw_tests_ftw_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Fs.Glob"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\glob\glob_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\glob\tests\glob_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\glob\tests\glob_main.sec
InputName=glob_main

"~~fs_glob_tests_glob_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/glob/tests/glob_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_glob_tests_glob_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\glob\glob_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\glob\glob_media.sec
InputName=glob_media

"~~fs_glob_glob_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/glob/glob_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_glob_glob_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\glob\glob_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\glob\glob_model.sec
InputName=glob_model

"~~fs_glob_glob_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/glob/glob_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_glob_glob_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\glob\tests\glob_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\glob\tests\glob_scenario.sec
InputName=glob_scenario

"~~fs_glob_tests_glob_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/glob/tests/glob_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_glob_tests_glob_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Fs.Meta"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\meta\access_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\meta\access_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\access_media.sec
InputName=access_media

"~~fs_meta_access_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/access_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_access_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\access_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\access_model.sec
InputName=access_model

"~~fs_meta_access_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/access_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_access_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\access_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\tests\access_scenario.sec
InputName=access_scenario

"~~fs_meta_tests_access_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/tests/access_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_tests_access_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\fs_meta_common_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\tests\fs_meta_common_scenario.sec
InputName=fs_meta_common_scenario

"~~fs_meta_tests_fs_meta_common_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/tests/fs_meta_common_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_tests_fs_meta_common_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\meta_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\meta_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\tests\meta_main.sec
InputName=meta_main

"~~fs_meta_tests_meta_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/tests/meta_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_tests_meta_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\meta_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\meta_media.sec
InputName=meta_media

"~~fs_meta_meta_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/meta_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_meta_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\meta_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\meta_model.sec
InputName=meta_model

"~~fs_meta_meta_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/meta_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_meta_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\meta_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\tests\meta_scenario.sec
InputName=meta_scenario

"~~fs_meta_tests_meta_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/tests/meta_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_tests_meta_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\statvfs_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\meta\statvfs_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\statvfs_media.sec
InputName=statvfs_media

"~~fs_meta_statvfs_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/statvfs_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_statvfs_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\statvfs_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\statvfs_model.sec
InputName=statvfs_model

"~~fs_meta_statvfs_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/statvfs_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_statvfs_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\statvfs_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\meta\tests\statvfs_scenario.sec
InputName=statvfs_scenario

"~~fs_meta_tests_statvfs_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/meta/tests/statvfs_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_meta_tests_statvfs_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Fs.Name"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\name\name_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\name\tests\name_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\name\tests\name_main.sec
InputName=name_main

"~~fs_name_tests_name_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/name/tests/name_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_name_tests_name_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\name\name_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\name\name_media.sec
InputName=name_media

"~~fs_name_name_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/name/name_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_name_name_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\name\name_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\name\name_model.sec
InputName=name_model

"~~fs_name_name_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/name/name_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_name_name_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\name\tests\name_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\name\tests\name_scenario.sec
InputName=name_scenario

"~~fs_name_tests_name_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/name/tests/name_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_name_tests_name_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Fs.Symlink"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\symlink\symlink_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\symlink\tests\symlink_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\symlink\tests\symlink_main.sec
InputName=symlink_main

"~~fs_symlink_tests_symlink_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/symlink/tests/symlink_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_symlink_tests_symlink_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\symlink\symlink_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\symlink\symlink_media.sec
InputName=symlink_media

"~~fs_symlink_symlink_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/symlink/symlink_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_symlink_symlink_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\symlink\symlink_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\symlink\symlink_model.sec
InputName=symlink_model

"~~fs_symlink_symlink_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/symlink/symlink_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_symlink_symlink_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\symlink\tests\symlink_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\symlink\tests\symlink_scenario.sec
InputName=symlink_scenario

"~~fs_symlink_tests_symlink_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/symlink/tests/symlink_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_symlink_tests_symlink_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Fs.Tmpfile"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\tmpfile\tmpfile_config.c
# End Source File
# Begin Source File

SOURCE=..\fs\tmpfile\tests\tmpfile_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\tmpfile\tests\tmpfile_main.sec
InputName=tmpfile_main

"~~fs_tmpfile_tests_tmpfile_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/tmpfile/tests/tmpfile_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_tmpfile_tests_tmpfile_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\tmpfile\tmpfile_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\tmpfile\tmpfile_media.sec
InputName=tmpfile_media

"~~fs_tmpfile_tmpfile_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/tmpfile/tmpfile_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_tmpfile_tmpfile_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\tmpfile\tmpfile_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\tmpfile\tmpfile_model.sec
InputName=tmpfile_model

"~~fs_tmpfile_tmpfile_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/tmpfile/tmpfile_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_tmpfile_tmpfile_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\fs\tmpfile\tests\tmpfile_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\fs\tmpfile\tests\tmpfile_scenario.sec
InputName=tmpfile_scenario

"~~fs_tmpfile_tests_tmpfile_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../fs/tmpfile/tests/tmpfile_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~fs_tmpfile_tests_tmpfile_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Io"

# PROP Default_Filter ""
# Begin Group "Io.File"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\file\file_config.c
# End Source File
# Begin Source File

SOURCE=..\io\file\tests\file_lock_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\file\tests\file_lock_scenario.sec
InputName=file_lock_scenario

"~~io_file_tests_file_lock_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/file/tests/file_lock_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_file_tests_file_lock_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\file\tests\file_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\file\tests\file_main.sec
InputName=file_main

"~~io_file_tests_file_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/file/tests/file_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_file_tests_file_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\file\file_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\file\file_media.sec
InputName=file_media

"~~io_file_file_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/file/file_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_file_file_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\file\file_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\file\file_model.sec
InputName=file_model

"~~io_file_file_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/file/file_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_file_file_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\file\tests\file_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\file\tests\file_scenario.sec
InputName=file_scenario

"~~io_file_tests_file_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/file/tests/file_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_file_tests_file_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Io.Fstream"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\fstream\buffer_config.c
# End Source File
# Begin Source File

SOURCE=..\io\fstream\buffer_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\buffer_media.sec
InputName=buffer_media

"~~io_fstream_buffer_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/buffer_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_buffer_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\buffer_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\buffer_model.sec
InputName=buffer_model

"~~io_fstream_buffer_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/buffer_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_buffer_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\buffer_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\tests\buffer_scenario.sec
InputName=buffer_scenario

"~~io_fstream_tests_buffer_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/tests/buffer_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_tests_buffer_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\fstream_config.c
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\fstream_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\tests\fstream_main.sec
InputName=fstream_main

"~~io_fstream_tests_fstream_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/tests/fstream_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_tests_fstream_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\fstream_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\fstream_media.sec
InputName=fstream_media

"~~io_fstream_fstream_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/fstream_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_fstream_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\fstream_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\fstream_model.sec
InputName=fstream_model

"~~io_fstream_fstream_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/fstream_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_fstream_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\fstream_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\tests\fstream_scenario.sec
InputName=fstream_scenario

"~~io_fstream_tests_fstream_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/tests/fstream_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_tests_fstream_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\lock_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\lock_media.sec
InputName=lock_media

"~~io_fstream_lock_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/lock_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_lock_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\lock_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\lock_model.sec
InputName=lock_model

"~~io_fstream_lock_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/lock_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_lock_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\lock_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\tests\lock_scenario.sec
InputName=lock_scenario

"~~io_fstream_tests_lock_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/tests/lock_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_tests_lock_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\wstream_config.c
# End Source File
# Begin Source File

SOURCE=..\io\fstream\wstream_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\wstream_media.sec
InputName=wstream_media

"~~io_fstream_wstream_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/wstream_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_wstream_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\wstream_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\wstream_model.sec
InputName=wstream_model

"~~io_fstream_wstream_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/wstream_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_wstream_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\wstream_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\fstream\tests\wstream_scenario.sec
InputName=wstream_scenario

"~~io_fstream_tests_wstream_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/fstream/tests/wstream_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_fstream_tests_wstream_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Io.Multiplex"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\multiplex\multiplex_config.c
# End Source File
# Begin Source File

SOURCE=..\io\multiplex\tests\multiplex_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\multiplex\tests\multiplex_main.sec
InputName=multiplex_main

"~~io_multiplex_tests_multiplex_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/multiplex/tests/multiplex_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_multiplex_tests_multiplex_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\multiplex\multiplex_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\multiplex\multiplex_media.sec
InputName=multiplex_media

"~~io_multiplex_multiplex_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/multiplex/multiplex_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_multiplex_multiplex_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\multiplex\multiplex_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\multiplex\multiplex_model.sec
InputName=multiplex_model

"~~io_multiplex_multiplex_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/multiplex/multiplex_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_multiplex_multiplex_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\multiplex\tests\multiplex_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\multiplex\tests\multiplex_scenario.sec
InputName=multiplex_scenario

"~~io_multiplex_tests_multiplex_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/multiplex/tests/multiplex_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_multiplex_tests_multiplex_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Io.Pipe"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\pipe\pipe_config.c
# End Source File
# Begin Source File

SOURCE=..\io\pipe\tests\pipe_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\pipe\tests\pipe_main.sec
InputName=pipe_main

"~~io_pipe_tests_pipe_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/pipe/tests/pipe_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_pipe_tests_pipe_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\pipe\pipe_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\pipe\pipe_media.sec
InputName=pipe_media

"~~io_pipe_pipe_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/pipe/pipe_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_pipe_pipe_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\pipe\pipe_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\pipe\pipe_model.sec
InputName=pipe_model

"~~io_pipe_pipe_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/pipe/pipe_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_pipe_pipe_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\pipe\tests\pipe_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\pipe\tests\pipe_scenario.sec
InputName=pipe_scenario

"~~io_pipe_tests_pipe_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/pipe/tests/pipe_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_pipe_tests_pipe_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Io.Streams"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\streams\tests\streams_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\streams\tests\streams_main.sec
InputName=streams_main

"~~io_streams_tests_streams_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/streams/tests/streams_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_streams_tests_streams_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\streams\streams_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\streams\streams_media.sec
InputName=streams_media

"~~io_streams_streams_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/streams/streams_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_streams_streams_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\streams\streams_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\streams\streams_model.sec
InputName=streams_model

"~~io_streams_streams_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/streams/streams_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_streams_streams_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\streams\tests\streams_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\streams\tests\streams_scenario.sec
InputName=streams_scenario

"~~io_streams_tests_streams_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/streams/tests/streams_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_streams_tests_streams_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Io.Syslog"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\syslog\tests\syslog_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\syslog\tests\syslog_main.sec
InputName=syslog_main

"~~io_syslog_tests_syslog_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/syslog/tests/syslog_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_syslog_tests_syslog_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\syslog\syslog_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\syslog\syslog_media.sec
InputName=syslog_media

"~~io_syslog_syslog_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/syslog/syslog_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_syslog_syslog_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\syslog\syslog_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\syslog\syslog_model.sec
InputName=syslog_model

"~~io_syslog_syslog_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/syslog/syslog_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_syslog_syslog_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\syslog\tests\syslog_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\syslog\tests\syslog_scenario.sec
InputName=syslog_scenario

"~~io_syslog_tests_syslog_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/syslog/tests/syslog_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_syslog_tests_syslog_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Io.Term"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\term\tests\cf_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\cf_scenario.sec
InputName=cf_scenario

"~~io_term_tests_cf_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/cf_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_cf_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\cterm_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\cterm_scenario.sec
InputName=cterm_scenario

"~~io_term_tests_cterm_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/cterm_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_cterm_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\open_tty_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\open_tty_scenario.sec
InputName=open_tty_scenario

"~~io_term_tests_open_tty_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/open_tty_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_open_tty_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\pt_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\pt_scenario.sec
InputName=pt_scenario

"~~io_term_tests_pt_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/pt_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_pt_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_canon_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\rw_canon_scenario.sec
InputName=rw_canon_scenario

"~~io_term_tests_rw_canon_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/rw_canon_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_rw_canon_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_case_a_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\rw_case_a_scenario.sec
InputName=rw_case_a_scenario

"~~io_term_tests_rw_case_a_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/rw_case_a_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_rw_case_a_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_case_b_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\rw_case_b_scenario.sec
InputName=rw_case_b_scenario

"~~io_term_tests_rw_case_b_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/rw_case_b_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_rw_case_b_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_case_c_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\rw_case_c_scenario.sec
InputName=rw_case_c_scenario

"~~io_term_tests_rw_case_c_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/rw_case_c_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_rw_case_c_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_case_d_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\rw_case_d_scenario.sec
InputName=rw_case_d_scenario

"~~io_term_tests_rw_case_d_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/rw_case_d_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_rw_case_d_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\tc_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\tc_scenario.sec
InputName=tc_scenario

"~~io_term_tests_tc_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/tc_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_tc_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\tcpgrp_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\tcpgrp_scenario.sec
InputName=tcpgrp_scenario

"~~io_term_tests_tcpgrp_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/tcpgrp_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_tcpgrp_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\term_config.c
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\term_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\term_main.sec
InputName=term_main

"~~io_term_tests_term_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/term_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_term_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\term_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\term_media.sec
InputName=term_media

"~~io_term_term_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/term_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_term_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\term_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\term_model.sec
InputName=term_model

"~~io_term_term_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/term_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_term_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\term_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\term_scenario.sec
InputName=term_scenario

"~~io_term_tests_term_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/term_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_term_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\tty_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\io\term\tests\tty_scenario.sec
InputName=tty_scenario

"~~io_term_tests_tty_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../io/term/tests/tty_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~io_term_tests_tty_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Locale"

# PROP Default_Filter ""
# Begin Group "Locale.Collate"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\collate\collate_config.c
# End Source File
# Begin Source File

SOURCE=..\locale\collate\tests\collate_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\collate\tests\collate_main.sec
InputName=collate_main

"~~locale_collate_tests_collate_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/collate/tests/collate_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_collate_tests_collate_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\collate\collate_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\collate\collate_media.sec
InputName=collate_media

"~~locale_collate_collate_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/collate/collate_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_collate_collate_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\collate\collate_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\collate\collate_model.sec
InputName=collate_model

"~~locale_collate_collate_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/collate/collate_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_collate_collate_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\collate\tests\collate_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\collate\tests\collate_scenario.sec
InputName=collate_scenario

"~~locale_collate_tests_collate_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/collate/tests/collate_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_collate_tests_collate_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Ctrans"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\ctrans\tests\ctrans_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\ctrans\tests\ctrans_main.sec
InputName=ctrans_main

"~~locale_ctrans_tests_ctrans_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/ctrans/tests/ctrans_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_ctrans_tests_ctrans_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\ctrans\ctrans_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\ctrans\ctrans_media.sec
InputName=ctrans_media

"~~locale_ctrans_ctrans_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/ctrans/ctrans_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_ctrans_ctrans_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\ctrans\ctrans_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\ctrans\ctrans_model.sec
InputName=ctrans_model

"~~locale_ctrans_ctrans_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/ctrans/ctrans_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_ctrans_ctrans_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\ctrans\tests\ctrans_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\ctrans\tests\ctrans_scenario.sec
InputName=ctrans_scenario

"~~locale_ctrans_tests_ctrans_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/ctrans/tests/ctrans_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_ctrans_tests_ctrans_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Ctype"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\ctype\tests\ctype_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\ctype\tests\ctype_main.sec
InputName=ctype_main

"~~locale_ctype_tests_ctype_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/ctype/tests/ctype_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_ctype_tests_ctype_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\ctype\ctype_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\ctype\ctype_media.sec
InputName=ctype_media

"~~locale_ctype_ctype_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/ctype/ctype_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_ctype_ctype_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\ctype\ctype_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\ctype\ctype_model.sec
InputName=ctype_model

"~~locale_ctype_ctype_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/ctype/ctype_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_ctype_ctype_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\ctype\tests\ctype_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\ctype\tests\ctype_scenario.sec
InputName=ctype_scenario

"~~locale_ctype_tests_ctype_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/ctype/tests/ctype_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_ctype_tests_ctype_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Iconv"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\iconv\iconv_config.c
# End Source File
# Begin Source File

SOURCE=..\locale\iconv\tests\iconv_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\iconv\tests\iconv_main.sec
InputName=iconv_main

"~~locale_iconv_tests_iconv_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/iconv/tests/iconv_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_iconv_tests_iconv_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\iconv\iconv_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\iconv\iconv_media.sec
InputName=iconv_media

"~~locale_iconv_iconv_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/iconv/iconv_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_iconv_iconv_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\iconv\iconv_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\iconv\iconv_model.sec
InputName=iconv_model

"~~locale_iconv_iconv_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/iconv/iconv_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_iconv_iconv_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\iconv\tests\iconv_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\iconv\tests\iconv_scenario.sec
InputName=iconv_scenario

"~~locale_iconv_tests_iconv_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/iconv/tests/iconv_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_iconv_tests_iconv_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Locale"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\locale\locale_config.c
# End Source File
# Begin Source File

SOURCE=..\locale\locale\tests\locale_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\locale\tests\locale_main.sec
InputName=locale_main

"~~locale_locale_tests_locale_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/locale/tests/locale_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_locale_tests_locale_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\locale\locale_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\locale\locale_media.sec
InputName=locale_media

"~~locale_locale_locale_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/locale/locale_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_locale_locale_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\locale\locale_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\locale\locale_model.sec
InputName=locale_model

"~~locale_locale_locale_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/locale/locale_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_locale_locale_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\locale\tests\locale_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\locale\tests\locale_scenario.sec
InputName=locale_scenario

"~~locale_locale_tests_locale_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/locale/tests/locale_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_locale_tests_locale_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Messages"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\messages\messages_config.c
# End Source File
# Begin Source File

SOURCE=..\locale\messages\tests\messages_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\messages\tests\messages_main.sec
InputName=messages_main

"~~locale_messages_tests_messages_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/messages/tests/messages_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_messages_tests_messages_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\messages\messages_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\messages\messages_media.sec
InputName=messages_media

"~~locale_messages_messages_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/messages/messages_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_messages_messages_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\messages\messages_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\messages\messages_model.sec
InputName=messages_model

"~~locale_messages_messages_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/messages/messages_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_messages_messages_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\messages\tests\messages_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\messages\tests\messages_scenario.sec
InputName=messages_scenario

"~~locale_messages_tests_messages_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/messages/tests/messages_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_messages_tests_messages_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Nlcat"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\nlcat\nlcat_config.c
# End Source File
# Begin Source File

SOURCE=..\locale\nlcat\tests\nlcat_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\nlcat\tests\nlcat_main.sec
InputName=nlcat_main

"~~locale_nlcat_tests_nlcat_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/nlcat/tests/nlcat_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_nlcat_tests_nlcat_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\nlcat\nlcat_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\nlcat\nlcat_media.sec
InputName=nlcat_media

"~~locale_nlcat_nlcat_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/nlcat/nlcat_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_nlcat_nlcat_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\nlcat\nlcat_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\nlcat\nlcat_model.sec
InputName=nlcat_model

"~~locale_nlcat_nlcat_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/nlcat/nlcat_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_nlcat_nlcat_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\nlcat\tests\nlcat_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\nlcat\tests\nlcat_scenario.sec
InputName=nlcat_scenario

"~~locale_nlcat_tests_nlcat_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/nlcat/tests/nlcat_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_nlcat_tests_nlcat_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Textdomain"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\textdomain\textdomain_config.c
# End Source File
# Begin Source File

SOURCE=..\locale\textdomain\textdomain_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\textdomain\textdomain_media.sec
InputName=textdomain_media

"~~locale_textdomain_textdomain_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/textdomain/textdomain_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_textdomain_textdomain_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\textdomain\textdomain_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\textdomain\textdomain_model.sec
InputName=textdomain_model

"~~locale_textdomain_textdomain_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/textdomain/textdomain_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_textdomain_textdomain_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\textdomain\tests\textdomain_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\textdomain\tests\textdomain_scenario.sec
InputName=textdomain_scenario

"~~locale_textdomain_tests_textdomain_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/textdomain/tests/textdomain_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_textdomain_tests_textdomain_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Wcollate"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\wcollate\wcollate_config.c
# End Source File
# Begin Source File

SOURCE=..\locale\wcollate\tests\wcollate_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wcollate\tests\wcollate_main.sec
InputName=wcollate_main

"~~locale_wcollate_tests_wcollate_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wcollate/tests/wcollate_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wcollate_tests_wcollate_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\wcollate\wcollate_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wcollate\wcollate_media.sec
InputName=wcollate_media

"~~locale_wcollate_wcollate_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wcollate/wcollate_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wcollate_wcollate_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\wcollate\wcollate_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wcollate\wcollate_model.sec
InputName=wcollate_model

"~~locale_wcollate_wcollate_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wcollate/wcollate_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wcollate_wcollate_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\wcollate\tests\wcollate_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wcollate\tests\wcollate_scenario.sec
InputName=wcollate_scenario

"~~locale_wcollate_tests_wcollate_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wcollate/tests/wcollate_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wcollate_tests_wcollate_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Wctrans"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\wctrans\wctrans_config.c
# End Source File
# Begin Source File

SOURCE=..\locale\wctrans\tests\wctrans_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wctrans\tests\wctrans_main.sec
InputName=wctrans_main

"~~locale_wctrans_tests_wctrans_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wctrans/tests/wctrans_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wctrans_tests_wctrans_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\wctrans\wctrans_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wctrans\wctrans_media.sec
InputName=wctrans_media

"~~locale_wctrans_wctrans_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wctrans/wctrans_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wctrans_wctrans_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\wctrans\wctrans_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wctrans\wctrans_model.sec
InputName=wctrans_model

"~~locale_wctrans_wctrans_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wctrans/wctrans_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wctrans_wctrans_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\wctrans\tests\wctrans_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wctrans\tests\wctrans_scenario.sec
InputName=wctrans_scenario

"~~locale_wctrans_tests_wctrans_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wctrans/tests/wctrans_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wctrans_tests_wctrans_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Locale.Wctype"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\wctype\tests\wctype_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wctype\tests\wctype_main.sec
InputName=wctype_main

"~~locale_wctype_tests_wctype_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wctype/tests/wctype_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wctype_tests_wctype_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\wctype\wctype_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wctype\wctype_media.sec
InputName=wctype_media

"~~locale_wctype_wctype_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wctype/wctype_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wctype_wctype_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\wctype\wctype_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wctype\wctype_model.sec
InputName=wctype_model

"~~locale_wctype_wctype_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wctype/wctype_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wctype_wctype_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\locale\wctype\tests\wctype_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\locale\wctype\tests\wctype_scenario.sec
InputName=wctype_scenario

"~~locale_wctype_tests_wctype_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../locale/wctype/tests/wctype_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~locale_wctype_tests_wctype_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Math"

# PROP Default_Filter ""
# Begin Group "Math.Cexp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\cexp\tests\cexp_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\cexp\tests\cexp_main.sec
InputName=cexp_main

"~~math_cexp_tests_cexp_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/cexp/tests/cexp_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_cexp_tests_cexp_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\cexp\cexp_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\cexp\cexp_media.sec
InputName=cexp_media

"~~math_cexp_cexp_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/cexp/cexp_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_cexp_cexp_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\cexp\cexp_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\cexp\cexp_model.sec
InputName=cexp_model

"~~math_cexp_cexp_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/cexp/cexp_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_cexp_cexp_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\cexp\tests\cexp_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\cexp\tests\cexp_scenario.sec
InputName=cexp_scenario

"~~math_cexp_tests_cexp_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/cexp/tests/cexp_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_cexp_tests_cexp_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Chyper"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\chyper\tests\chyper_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\chyper\tests\chyper_main.sec
InputName=chyper_main

"~~math_chyper_tests_chyper_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/chyper/tests/chyper_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_chyper_tests_chyper_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\chyper\chyper_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\chyper\chyper_media.sec
InputName=chyper_media

"~~math_chyper_chyper_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/chyper/chyper_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_chyper_chyper_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\chyper\chyper_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\chyper\chyper_model.sec
InputName=chyper_model

"~~math_chyper_chyper_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/chyper/chyper_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_chyper_chyper_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\chyper\tests\chyper_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\chyper\tests\chyper_scenario.sec
InputName=chyper_scenario

"~~math_chyper_tests_chyper_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/chyper/tests/chyper_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_chyper_tests_chyper_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Complex"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\complex\tests\complex_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\complex\tests\complex_main.sec
InputName=complex_main

"~~math_complex_tests_complex_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/complex/tests/complex_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_complex_tests_complex_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\complex\complex_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\complex\complex_media.sec
InputName=complex_media

"~~math_complex_complex_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/complex/complex_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_complex_complex_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\complex\complex_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\complex\complex_model.sec
InputName=complex_model

"~~math_complex_complex_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/complex/complex_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_complex_complex_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\complex\tests\complex_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\complex\tests\complex_scenario.sec
InputName=complex_scenario

"~~math_complex_tests_complex_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/complex/tests/complex_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_complex_tests_complex_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Ctrig"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\ctrig\tests\ctrig_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\ctrig\tests\ctrig_main.sec
InputName=ctrig_main

"~~math_ctrig_tests_ctrig_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/ctrig/tests/ctrig_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_ctrig_tests_ctrig_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\ctrig\ctrig_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\ctrig\ctrig_media.sec
InputName=ctrig_media

"~~math_ctrig_ctrig_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/ctrig/ctrig_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_ctrig_ctrig_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\ctrig\ctrig_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\ctrig\ctrig_model.sec
InputName=ctrig_model

"~~math_ctrig_ctrig_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/ctrig/ctrig_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_ctrig_ctrig_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\ctrig\tests\ctrig_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\ctrig\tests\ctrig_scenario.sec
InputName=ctrig_scenario

"~~math_ctrig_tests_ctrig_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/ctrig/tests/ctrig_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_ctrig_tests_ctrig_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Error"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\error\error_config.c
# End Source File
# Begin Source File

SOURCE=..\math\error\tests\error_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\error\tests\error_main.sec
InputName=error_main

"~~math_error_tests_error_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/error/tests/error_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_error_tests_error_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\error\error_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\error\error_media.sec
InputName=error_media

"~~math_error_error_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/error/error_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_error_error_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\error\error_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\error\error_model.sec
InputName=error_model

"~~math_error_error_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/error/error_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_error_error_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\error\tests\error_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\error\tests\error_scenario.sec
InputName=error_scenario

"~~math_error_tests_error_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/error/tests/error_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_error_tests_error_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Exp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\exp\exp_config.c
# End Source File
# Begin Source File

SOURCE=..\math\exp\tests\exp_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\exp\tests\exp_main.sec
InputName=exp_main

"~~math_exp_tests_exp_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/exp/tests/exp_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_exp_tests_exp_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\exp\exp_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\exp\exp_media.sec
InputName=exp_media

"~~math_exp_exp_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/exp/exp_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_exp_exp_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\exp\exp_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\exp\exp_model.sec
InputName=exp_model

"~~math_exp_exp_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/exp/exp_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_exp_exp_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\exp\tests\exp_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\exp\tests\exp_scenario.sec
InputName=exp_scenario

"~~math_exp_tests_exp_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/exp/tests/exp_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_exp_tests_exp_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Gamma"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\gamma\gamma_config.c
# End Source File
# Begin Source File

SOURCE=..\math\gamma\tests\gamma_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\gamma\tests\gamma_main.sec
InputName=gamma_main

"~~math_gamma_tests_gamma_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/gamma/tests/gamma_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_gamma_tests_gamma_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\gamma\gamma_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\gamma\gamma_media.sec
InputName=gamma_media

"~~math_gamma_gamma_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/gamma/gamma_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_gamma_gamma_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\gamma\gamma_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\gamma\gamma_model.sec
InputName=gamma_model

"~~math_gamma_gamma_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/gamma/gamma_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_gamma_gamma_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\gamma\tests\gamma_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\gamma\tests\gamma_scenario.sec
InputName=gamma_scenario

"~~math_gamma_tests_gamma_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/gamma/tests/gamma_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_gamma_tests_gamma_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Hyper"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\hyper\hyper_config.c
# End Source File
# Begin Source File

SOURCE=..\math\hyper\hyper_config.h
# End Source File
# Begin Source File

SOURCE=..\math\hyper\tests\hyper_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\hyper\tests\hyper_main.sec
InputName=hyper_main

"~~math_hyper_tests_hyper_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/hyper/tests/hyper_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_hyper_tests_hyper_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\hyper\hyper_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\hyper\hyper_media.sec
InputName=hyper_media

"~~math_hyper_hyper_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/hyper/hyper_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_hyper_hyper_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\hyper\hyper_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\hyper\hyper_model.sec
InputName=hyper_model

"~~math_hyper_hyper_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/hyper/hyper_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_hyper_hyper_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\hyper\tests\hyper_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\hyper\tests\hyper_scenario.sec
InputName=hyper_scenario

"~~math_hyper_tests_hyper_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/hyper/tests/hyper_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_hyper_tests_hyper_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Integer"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\integer\tests\integer_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\integer\tests\integer_main.sec
InputName=integer_main

"~~math_integer_tests_integer_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/integer/tests/integer_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_integer_tests_integer_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\integer\integer_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\integer\integer_media.sec
InputName=integer_media

"~~math_integer_integer_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/integer/integer_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_integer_integer_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\integer\integer_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\integer\integer_model.sec
InputName=integer_model

"~~math_integer_integer_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/integer/integer_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_integer_integer_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\integer\tests\integer_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\integer\tests\integer_scenario.sec
InputName=integer_scenario

"~~math_integer_tests_integer_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/integer/tests/integer_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_integer_tests_integer_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Math"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\math\math_data.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\math\math_data.sec
InputName=math_data

"~~math_math_math_data.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/math/math_data.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_math_math_data.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Rand"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\rand\tests\rand_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\rand\tests\rand_main.sec
InputName=rand_main

"~~math_rand_tests_rand_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/rand/tests/rand_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_rand_tests_rand_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\rand\rand_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\rand\rand_media.sec
InputName=rand_media

"~~math_rand_rand_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/rand/rand_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_rand_rand_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\rand\rand_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\rand\rand_model.sec
InputName=rand_model

"~~math_rand_rand_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/rand/rand_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_rand_rand_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\rand\tests\rand_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\rand\tests\rand_scenario.sec
InputName=rand_scenario

"~~math_rand_tests_rand_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/rand/tests/rand_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_rand_tests_rand_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Real"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\real\real_config.c
# End Source File
# Begin Source File

SOURCE=..\math\real\tests\real_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\real\tests\real_main.sec
InputName=real_main

"~~math_real_tests_real_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/real/tests/real_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_real_tests_real_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\real\real_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\real\real_media.sec
InputName=real_media

"~~math_real_real_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/real/real_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_real_real_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\real\real_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\real\real_model.sec
InputName=real_model

"~~math_real_real_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/real/real_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_real_real_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\real\tests\real_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\real\tests\real_scenario.sec
InputName=real_scenario

"~~math_real_tests_real_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/real/tests/real_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_real_tests_real_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Trig"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\trig\trig_config.c
# End Source File
# Begin Source File

SOURCE=..\math\trig\trig_config.seh
# End Source File
# Begin Source File

SOURCE=..\math\trig\tests\trig_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\trig\tests\trig_main.sec
InputName=trig_main

"~~math_trig_tests_trig_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/trig/tests/trig_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_trig_tests_trig_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\trig\trig_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\trig\trig_media.sec
InputName=trig_media

"~~math_trig_trig_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/trig/trig_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_trig_trig_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\trig\trig_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\trig\trig_model.sec
InputName=trig_model

"~~math_trig_trig_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/trig/trig_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_trig_trig_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\trig\tests\trig_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\trig\tests\trig_scenario.sec
InputName=trig_scenario

"~~math_trig_tests_trig_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/trig/tests/trig_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_trig_tests_trig_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Math.Bessel"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\bessel\bessel_config.c
# End Source File
# Begin Source File

SOURCE=..\math\bessel\bessel_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\bessel\bessel_media.sec
InputName=bessel_media

"~~math_bessel_bessel_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/bessel/bessel_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_bessel_bessel_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\math\bessel\bessel_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\math\bessel\bessel_model.sec
InputName=bessel_model

"~~math_bessel_bessel_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ  /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../math/bessel/bessel_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~math_bessel_bessel_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Source File

SOURCE=..\math\math\math_config.c
# End Source File
# End Group
# Begin Group "Memory"

# PROP Default_Filter ""
# Begin Group "Memory.break"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\memory\break\break_config.c
# End Source File
# Begin Source File

SOURCE=..\memory\break\tests\break_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\break\tests\break_main.sec
InputName=break_main

"~~memory_break_tests_break_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/break/tests/break_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_break_tests_break_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\break\break_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\break\break_media.sec
InputName=break_media

"~~memory_break_break_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/break/break_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_break_break_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\break\break_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\break\break_model.sec
InputName=break_model

"~~memory_break_break_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/break/break_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_break_break_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\break\tests\break_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\break\tests\break_scenario.sec
InputName=break_scenario

"~~memory_break_tests_break_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/break/tests/break_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_break_tests_break_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Memory.Heap"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\memory\heap\heap_config.c
# End Source File
# Begin Source File

SOURCE=..\memory\heap\tests\heap_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\heap\tests\heap_main.sec
InputName=heap_main

"~~memory_heap_tests_heap_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/heap/tests/heap_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_heap_tests_heap_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\heap\heap_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\heap\heap_media.sec
InputName=heap_media

"~~memory_heap_heap_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/heap/heap_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_heap_heap_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\heap\heap_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\heap\heap_model.sec
InputName=heap_model

"~~memory_heap_heap_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/heap/heap_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_heap_heap_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\heap\tests\heap_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\heap\tests\heap_scenario.sec
InputName=heap_scenario

"~~memory_heap_tests_heap_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/heap/tests/heap_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_heap_tests_heap_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\heap\tests\memory_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\heap\tests\memory_scenario.sec
InputName=memory_scenario

"~~memory_heap_tests_memory_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/heap/tests/memory_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_heap_tests_memory_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Memory.Mman"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\memory\mman\tests\mman_b1_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\mman\tests\mman_b1_scenario.sec
InputName=mman_b1_scenario

"~~memory_mman_tests_mman_b1_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/mman/tests/mman_b1_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_mman_tests_mman_b1_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\mman\mman_config.c
# End Source File
# Begin Source File

SOURCE=..\memory\mman\tests\mman_errors_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\mman\tests\mman_errors_scenario.sec
InputName=mman_errors_scenario

"~~memory_mman_tests_mman_errors_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/mman/tests/mman_errors_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_mman_tests_mman_errors_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\mman\tests\mman_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\mman\tests\mman_main.sec
InputName=mman_main

"~~memory_mman_tests_mman_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/mman/tests/mman_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_mman_tests_mman_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\mman\mman_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\mman\mman_media.sec
InputName=mman_media

"~~memory_mman_mman_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/mman/mman_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_mman_mman_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\mman\mman_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\mman\mman_model.sec
InputName=mman_model

"~~memory_mman_mman_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/mman/mman_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_mman_mman_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\mman\tests\mman_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\mman\tests\mman_scenario.sec
InputName=mman_scenario

"~~memory_mman_tests_mman_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/mman/tests/mman_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_mman_tests_mman_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\memory\mman\tests\mman_usualuse_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\memory\mman\tests\mman_usualuse_scenario.sec
InputName=mman_usualuse_scenario

"~~memory_mman_tests_mman_usualuse_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../memory/mman/tests/mman_usualuse_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~memory_mman_tests_mman_usualuse_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Ncurses"

# PROP Default_Filter ""
# Begin Group "Ncurses.Bkgd"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\bkgd\tests\bkgd_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\bkgd\tests\bkgd_main.sec
InputName=bkgd_main

"~~ncurses_bkgd_tests_bkgd_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/bkgd/tests/bkgd_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_bkgd_tests_bkgd_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\bkgd\bkgd_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\bkgd\bkgd_media.sec
InputName=bkgd_media

"~~ncurses_bkgd_bkgd_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/bkgd/bkgd_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_bkgd_bkgd_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\bkgd\bkgd_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\bkgd\bkgd_model.sec
InputName=bkgd_model

"~~ncurses_bkgd_bkgd_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/bkgd/bkgd_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_bkgd_bkgd_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\bkgd\tests\bkgd_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\bkgd\tests\bkgd_scenario.sec
InputName=bkgd_scenario

"~~ncurses_bkgd_tests_bkgd_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/bkgd/tests/bkgd_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_bkgd_tests_bkgd_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Border"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\border\tests\border_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\border\tests\border_main.sec
InputName=border_main

"~~ncurses_border_tests_border_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/border/tests/border_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_border_tests_border_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\border\border_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\border\border_media.sec
InputName=border_media

"~~ncurses_border_border_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/border/border_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_border_border_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\border\border_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\border\border_model.sec
InputName=border_model

"~~ncurses_border_border_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/border/border_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_border_border_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\border\tests\border_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\border\tests\border_scenario.sec
InputName=border_scenario

"~~ncurses_border_tests_border_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/border/tests/border_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_border_tests_border_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Char"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\char\add_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\add_media.sec
InputName=add_media

"~~ncurses_char_add_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/add_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_add_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\add_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\add_model.sec
InputName=add_model

"~~ncurses_char_add_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/add_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_add_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\tests\add_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\tests\add_scenario.sec
InputName=add_scenario

"~~ncurses_char_tests_add_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/tests/add_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_tests_add_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\tests\char_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\tests\char_main.sec
InputName=char_main

"~~ncurses_char_tests_char_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/tests/char_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_tests_char_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\input_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\input_media.sec
InputName=input_media

"~~ncurses_char_input_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/input_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_input_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\input_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\input_model.sec
InputName=input_model

"~~ncurses_char_input_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/input_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_input_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\tests\input_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\tests\input_scenario.sec
InputName=input_scenario

"~~ncurses_char_tests_input_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/tests/input_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_tests_input_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\insert_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\insert_media.sec
InputName=insert_media

"~~ncurses_char_insert_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/insert_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_insert_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\insert_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\insert_model.sec
InputName=insert_model

"~~ncurses_char_insert_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/insert_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_insert_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\tests\insert_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\char\tests\insert_scenario.sec
InputName=insert_scenario

"~~ncurses_char_tests_insert_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/char/tests/insert_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_char_tests_insert_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Chgat"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\chgat\tests\chgat_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chgat\tests\chgat_main.sec
InputName=chgat_main

"~~ncurses_chgat_tests_chgat_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chgat/tests/chgat_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chgat_tests_chgat_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\chgat\chgat_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chgat\chgat_media.sec
InputName=chgat_media

"~~ncurses_chgat_chgat_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chgat/chgat_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chgat_chgat_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\chgat\chgat_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chgat\chgat_model.sec
InputName=chgat_model

"~~ncurses_chgat_chgat_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chgat/chgat_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chgat_chgat_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\chgat\tests\chgat_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chgat\tests\chgat_scenario.sec
InputName=chgat_scenario

"~~ncurses_chgat_tests_chgat_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chgat/tests/chgat_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chgat_tests_chgat_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Chstr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\chstr\add_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chstr\add_media.sec
InputName=add_media

"~~ncurses_chstr_add_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chstr/add_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chstr_add_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\add_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chstr\add_model.sec
InputName=add_model

"~~ncurses_chstr_add_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chstr/add_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chstr_add_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\tests\add_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chstr\tests\add_scenario.sec
InputName=add_scenario

"~~ncurses_chstr_tests_add_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chstr/tests/add_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chstr_tests_add_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\tests\chstr_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chstr\tests\chstr_main.sec
InputName=chstr_main

"~~ncurses_chstr_tests_chstr_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chstr/tests/chstr_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chstr_tests_chstr_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\input_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chstr\input_media.sec
InputName=input_media

"~~ncurses_chstr_input_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chstr/input_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chstr_input_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\input_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chstr\input_model.sec
InputName=input_model

"~~ncurses_chstr_input_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chstr/input_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chstr_input_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\tests\input_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\chstr\tests\input_scenario.sec
InputName=input_scenario

"~~ncurses_chstr_tests_input_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/chstr/tests/input_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_chstr_tests_input_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Clear"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\clear\tests\clear_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\clear\tests\clear_main.sec
InputName=clear_main

"~~ncurses_clear_tests_clear_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/clear/tests/clear_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_clear_tests_clear_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\clear\clear_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\clear\clear_media.sec
InputName=clear_media

"~~ncurses_clear_clear_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/clear/clear_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_clear_clear_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\clear\clear_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\clear\clear_model.sec
InputName=clear_model

"~~ncurses_clear_clear_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/clear/clear_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_clear_clear_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\clear\tests\clear_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\clear\tests\clear_scenario.sec
InputName=clear_scenario

"~~ncurses_clear_tests_clear_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/clear/tests/clear_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_clear_tests_clear_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Color"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\color\tests\color_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\color\tests\color_main.sec
InputName=color_main

"~~ncurses_color_tests_color_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/color/tests/color_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_color_tests_color_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\color\color_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\color\color_media.sec
InputName=color_media

"~~ncurses_color_color_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/color/color_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_color_color_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\color\color_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\color\color_model.sec
InputName=color_model

"~~ncurses_color_color_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/color/color_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_color_color_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\color\tests\color_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\color\tests\color_scenario.sec
InputName=color_scenario

"~~ncurses_color_tests_color_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/color/tests/color_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_color_tests_color_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Input"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\input\char_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\char_media.sec
InputName=char_media

"~~ncurses_input_char_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/char_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_char_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\char_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\char_model.sec
InputName=char_model

"~~ncurses_input_char_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/char_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_char_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\char_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\tests\char_scenario.sec
InputName=char_scenario

"~~ncurses_input_tests_char_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/tests/char_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_tests_char_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\input_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\tests\input_main.sec
InputName=input_main

"~~ncurses_input_tests_input_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/tests/input_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_tests_input_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\input_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\input_media.sec
InputName=input_media

"~~ncurses_input_input_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/input_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_input_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\input_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\input_model.sec
InputName=input_model

"~~ncurses_input_input_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/input_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_input_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\input_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\tests\input_scenario.sec
InputName=input_scenario

"~~ncurses_input_tests_input_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/tests/input_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_tests_input_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\string_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\string_media.sec
InputName=string_media

"~~ncurses_input_string_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/string_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_string_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\string_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\string_model.sec
InputName=string_model

"~~ncurses_input_string_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/string_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_string_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\string_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\tests\string_scenario.sec
InputName=string_scenario

"~~ncurses_input_tests_string_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/tests/string_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_tests_string_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\timeout_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\timeout_media.sec
InputName=timeout_media

"~~ncurses_input_timeout_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/timeout_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_timeout_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\timeout_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\timeout_model.sec
InputName=timeout_model

"~~ncurses_input_timeout_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/timeout_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_timeout_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\timeout_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\input\tests\timeout_scenario.sec
InputName=timeout_scenario

"~~ncurses_input_tests_timeout_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/input/tests/timeout_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_input_tests_timeout_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Line"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\line\tests\line_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\line\tests\line_main.sec
InputName=line_main

"~~ncurses_line_tests_line_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/line/tests/line_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_line_tests_line_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\line\line_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\line\line_media.sec
InputName=line_media

"~~ncurses_line_line_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/line/line_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_line_line_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\line\line_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\line\line_model.sec
InputName=line_model

"~~ncurses_line_line_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/line/line_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_line_line_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\line\tests\line_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\line\tests\line_scenario.sec
InputName=line_scenario

"~~ncurses_line_tests_line_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/line/tests/line_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_line_tests_line_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Misc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\misc\tests\misc_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\misc\tests\misc_main.sec
InputName=misc_main

"~~ncurses_misc_tests_misc_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/misc/tests/misc_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_misc_tests_misc_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\misc\misc_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\misc\misc_media.sec
InputName=misc_media

"~~ncurses_misc_misc_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/misc/misc_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_misc_misc_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\misc\misc_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\misc\misc_model.sec
InputName=misc_model

"~~ncurses_misc_misc_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/misc/misc_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_misc_misc_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\misc\tests\misc_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\misc\tests\misc_scenario.sec
InputName=misc_scenario

"~~ncurses_misc_tests_misc_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/misc/tests/misc_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_misc_tests_misc_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Mode"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\mode\tests\mode_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\mode\tests\mode_main.sec
InputName=mode_main

"~~ncurses_mode_tests_mode_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/mode/tests/mode_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_mode_tests_mode_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\mode\mode_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\mode\mode_media.sec
InputName=mode_media

"~~ncurses_mode_mode_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/mode/mode_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_mode_mode_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\mode\mode_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\mode\mode_model.sec
InputName=mode_model

"~~ncurses_mode_mode_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/mode/mode_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_mode_mode_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\mode\tests\mode_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\mode\tests\mode_scenario.sec
InputName=mode_scenario

"~~ncurses_mode_tests_mode_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/mode/tests/mode_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_mode_tests_mode_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Move"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\move\tests\move_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\move\tests\move_main.sec
InputName=move_main

"~~ncurses_move_tests_move_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/move/tests/move_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_move_tests_move_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\move\move_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\move\move_media.sec
InputName=move_media

"~~ncurses_move_move_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/move/move_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_move_move_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\move\move_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\move\move_model.sec
InputName=move_model

"~~ncurses_move_move_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/move/move_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_move_move_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\move\tests\move_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\move\tests\move_scenario.sec
InputName=move_scenario

"~~ncurses_move_tests_move_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/move/tests/move_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_move_tests_move_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Ncurses"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\ncurses\ncurses_config.c
# End Source File
# Begin Source File

SOURCE=..\ncurses\ncurses\ncurses_data.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\ncurses\ncurses_data.sec
InputName=ncurses_data

"~~ncurses_ncurses_ncurses_data.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/ncurses/ncurses_data.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_ncurses_ncurses_data.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\ncurses\special_chars_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\ncurses\special_chars_scenario.sec
InputName=special_chars_scenario

"~~ncurses_ncurses_special_chars_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/ncurses/special_chars_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_ncurses_special_chars_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Screen"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\screen\tests\screen_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\screen\tests\screen_main.sec
InputName=screen_main

"~~ncurses_screen_tests_screen_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/screen/tests/screen_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_screen_tests_screen_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\screen\screen_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\screen\screen_media.sec
InputName=screen_media

"~~ncurses_screen_screen_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/screen/screen_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_screen_screen_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\screen\screen_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\screen\screen_model.sec
InputName=screen_model

"~~ncurses_screen_screen_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/screen/screen_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_screen_screen_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\screen\tests\screen_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\screen\tests\screen_scenario.sec
InputName=screen_scenario

"~~ncurses_screen_tests_screen_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/screen/tests/screen_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_screen_tests_screen_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Slk"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\slk\tests\slk_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\slk\tests\slk_main.sec
InputName=slk_main

"~~ncurses_slk_tests_slk_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/slk/tests/slk_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_slk_tests_slk_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\slk\slk_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\slk\slk_media.sec
InputName=slk_media

"~~ncurses_slk_slk_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/slk/slk_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_slk_slk_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\slk\slk_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\slk\slk_model.sec
InputName=slk_model

"~~ncurses_slk_slk_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/slk/slk_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_slk_slk_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\slk\tests\slk_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\slk\tests\slk_scenario.sec
InputName=slk_scenario

"~~ncurses_slk_tests_slk_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/slk/tests/slk_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_slk_tests_slk_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.Terminal"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\terminal\tests\control_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\tests\control_main.sec
InputName=control_main

"~~ncurses_terminal_tests_control_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/tests/control_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_tests_control_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\control_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\control_media.sec
InputName=control_media

"~~ncurses_terminal_control_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/control_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_control_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\control_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\control_model.sec
InputName=control_model

"~~ncurses_terminal_control_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/control_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_control_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\control_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\tests\control_scenario.sec
InputName=control_scenario

"~~ncurses_terminal_tests_control_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/tests/control_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_tests_control_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\termcap_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\tests\termcap_main.sec
InputName=termcap_main

"~~ncurses_terminal_tests_termcap_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/tests/termcap_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_tests_termcap_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\termcap_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\termcap_media.sec
InputName=termcap_media

"~~ncurses_terminal_termcap_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/termcap_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_termcap_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\termcap_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\termcap_model.sec
InputName=termcap_model

"~~ncurses_terminal_termcap_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/termcap_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_termcap_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\termcap_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\tests\termcap_scenario.sec
InputName=termcap_scenario

"~~ncurses_terminal_tests_termcap_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/tests/termcap_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_tests_termcap_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\terminal_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\tests\terminal_main.sec
InputName=terminal_main

"~~ncurses_terminal_tests_terminal_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/tests/terminal_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_tests_terminal_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\terminal_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\terminal_media.sec
InputName=terminal_media

"~~ncurses_terminal_terminal_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/terminal_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_terminal_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\terminal_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\terminal_model.sec
InputName=terminal_model

"~~ncurses_terminal_terminal_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/terminal_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_terminal_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\terminal_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\tests\terminal_scenario.sec
InputName=terminal_scenario

"~~ncurses_terminal_tests_terminal_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/tests/terminal_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_tests_terminal_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\terminfo_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\terminfo_media.sec
InputName=terminfo_media

"~~ncurses_terminal_terminfo_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/terminfo_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_terminfo_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\terminfo_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\terminfo_model.sec
InputName=terminfo_model

"~~ncurses_terminal_terminfo_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/terminfo_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_terminfo_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\terminfo_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\terminal\tests\terminfo_scenario.sec
InputName=terminfo_scenario

"~~ncurses_terminal_tests_terminfo_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/terminal/tests/terminfo_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_terminal_tests_terminfo_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "NcursesWindow"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\window\attr_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\attr_media.sec
InputName=attr_media

"~~ncurses_window_attr_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/attr_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_attr_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\attr_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\attr_model.sec
InputName=attr_model

"~~ncurses_window_attr_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/attr_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_attr_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\attr_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\tests\attr_scenario.sec
InputName=attr_scenario

"~~ncurses_window_tests_attr_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/tests/attr_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_tests_attr_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\pad_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\pad_media.sec
InputName=pad_media

"~~ncurses_window_pad_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/pad_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_pad_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\pad_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\pad_model.sec
InputName=pad_model

"~~ncurses_window_pad_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/pad_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_pad_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\pad_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\tests\pad_scenario.sec
InputName=pad_scenario

"~~ncurses_window_tests_pad_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/tests/pad_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_tests_pad_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\refresh_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\refresh_media.sec
InputName=refresh_media

"~~ncurses_window_refresh_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/refresh_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_refresh_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\refresh_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\refresh_model.sec
InputName=refresh_model

"~~ncurses_window_refresh_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/refresh_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_refresh_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\refresh_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\tests\refresh_scenario.sec
InputName=refresh_scenario

"~~ncurses_window_tests_refresh_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/tests/refresh_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_tests_refresh_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\scroll_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\tests\scroll_main.sec
InputName=scroll_main

"~~ncurses_window_tests_scroll_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/tests/scroll_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_tests_scroll_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\scroll_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\scroll_media.sec
InputName=scroll_media

"~~ncurses_window_scroll_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/scroll_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_scroll_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\scroll_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\scroll_model.sec
InputName=scroll_model

"~~ncurses_window_scroll_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/scroll_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_scroll_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\scroll_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\tests\scroll_scenario.sec
InputName=scroll_scenario

"~~ncurses_window_tests_scroll_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/tests/scroll_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_tests_scroll_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\window_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\tests\window_main.sec
InputName=window_main

"~~ncurses_window_tests_window_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/tests/window_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_tests_window_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\window_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\window_media.sec
InputName=window_media

"~~ncurses_window_window_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/window_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_window_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\window_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\window_model.sec
InputName=window_model

"~~ncurses_window_window_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/window_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_window_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\window_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\window\tests\window_scenario.sec
InputName=window_scenario

"~~ncurses_window_tests_window_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/window/tests/window_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_window_tests_window_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Ncurses.String"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\string\add_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\add_media.sec
InputName=add_media

"~~ncurses_string_add_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/add_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_add_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\add_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\add_model.sec
InputName=add_model

"~~ncurses_string_add_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/add_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_add_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\add_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\tests\add_scenario.sec
InputName=add_scenario

"~~ncurses_string_tests_add_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/tests/add_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_tests_add_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\input_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\input_media.sec
InputName=input_media

"~~ncurses_string_input_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/input_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_input_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\input_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\input_model.sec
InputName=input_model

"~~ncurses_string_input_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/input_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_input_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\input_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\tests\input_scenario.sec
InputName=input_scenario

"~~ncurses_string_tests_input_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/tests/input_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_tests_input_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\insert_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\insert_media.sec
InputName=insert_media

"~~ncurses_string_insert_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/insert_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_insert_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\insert_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\insert_model.sec
InputName=insert_model

"~~ncurses_string_insert_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/insert_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_insert_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\insert_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\tests\insert_scenario.sec
InputName=insert_scenario

"~~ncurses_string_tests_insert_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/tests/insert_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_tests_insert_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\printf_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\printf_media.sec
InputName=printf_media

"~~ncurses_string_printf_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/printf_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_printf_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\printf_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\printf_model.sec
InputName=printf_model

"~~ncurses_string_printf_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/printf_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_printf_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\printf_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\tests\printf_scenario.sec
InputName=printf_scenario

"~~ncurses_string_tests_printf_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/tests/printf_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_tests_printf_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\scanf_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\scanf_media.sec
InputName=scanf_media

"~~ncurses_string_scanf_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/scanf_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_scanf_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\scanf_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\scanf_model.sec
InputName=scanf_model

"~~ncurses_string_scanf_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/scanf_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_scanf_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\scanf_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\tests\scanf_scenario.sec
InputName=scanf_scenario

"~~ncurses_string_tests_scanf_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/tests/scanf_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_tests_scanf_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\string_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\ncurses\string\tests\string_main.sec
InputName=string_main

"~~ncurses_string_tests_string_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../ncurses/string/tests/string_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~ncurses_string_tests_string_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Process"

# PROP Default_Filter ""
# Begin Group "Process.Context"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\context\context_config.c
# End Source File
# Begin Source File

SOURCE=..\process\context\tests\context_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\context\tests\context_main.sec
InputName=context_main

"~~process_context_tests_context_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/context/tests/context_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_context_tests_context_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\context\context_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\context\context_media.sec
InputName=context_media

"~~process_context_context_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/context/context_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_context_context_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\context\context_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\context\context_model.sec
InputName=context_model

"~~process_context_context_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/context/context_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_context_context_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\context\tests\context_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\context\tests\context_scenario.sec
InputName=context_scenario

"~~process_context_tests_context_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/context/tests/context_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_context_tests_context_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Process.Environ"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\environ\environ_config.c
# End Source File
# Begin Source File

SOURCE=..\process\environ\tests\environ_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\environ\tests\environ_main.sec
InputName=environ_main

"~~process_environ_tests_environ_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/environ/tests/environ_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_environ_tests_environ_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\environ\environ_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\environ\environ_media.sec
InputName=environ_media

"~~process_environ_environ_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/environ/environ_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_environ_environ_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\environ\environ_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\environ\environ_model.sec
InputName=environ_model

"~~process_environ_environ_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/environ/environ_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_environ_environ_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\environ\tests\environ_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\environ\tests\environ_scenario.sec
InputName=environ_scenario

"~~process_environ_tests_environ_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/environ/tests/environ_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_environ_tests_environ_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Process.Fenv"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\fenv\fenv_common.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\fenv\fenv_common.sec
InputName=fenv_common

"~~process_fenv_fenv_common.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/fenv/fenv_common.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_fenv_fenv_common.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\fenv\fenv_config.c
# End Source File
# Begin Source File

SOURCE=..\process\fenv\tests\fenv_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\fenv\tests\fenv_main.sec
InputName=fenv_main

"~~process_fenv_tests_fenv_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/fenv/tests/fenv_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_fenv_tests_fenv_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\fenv\fenv_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\fenv\fenv_media.sec
InputName=fenv_media

"~~process_fenv_fenv_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/fenv/fenv_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_fenv_fenv_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\fenv\fenv_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\fenv\fenv_model.sec
InputName=fenv_model

"~~process_fenv_fenv_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/fenv/fenv_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_fenv_fenv_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\fenv\tests\fenv_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\fenv\tests\fenv_scenario.sec
InputName=fenv_scenario

"~~process_fenv_tests_fenv_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/fenv/tests/fenv_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_fenv_tests_fenv_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Process.Goto"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\goto\tests\goto_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\goto\tests\goto_main.sec
InputName=goto_main

"~~process_goto_tests_goto_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/goto/tests/goto_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_goto_tests_goto_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\goto\goto_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\goto\goto_media.sec
InputName=goto_media

"~~process_goto_goto_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/goto/goto_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_goto_goto_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\goto\goto_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\goto\goto_model.sec
InputName=goto_model

"~~process_goto_goto_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/goto/goto_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_goto_goto_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\goto\tests\goto_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\goto\tests\goto_scenario.sec
InputName=goto_scenario

"~~process_goto_tests_goto_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/goto/tests/goto_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_goto_tests_goto_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Process.Meta"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\meta\fs_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\fs_media.sec
InputName=fs_media

"~~process_meta_fs_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/fs_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_fs_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\fs_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\fs_model.sec
InputName=fs_model

"~~process_meta_fs_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/fs_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_fs_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\fs_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\tests\fs_scenario.sec
InputName=fs_scenario

"~~process_meta_tests_fs_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/tests/fs_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_tests_fs_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\meta_fs_config.c
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\meta_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\tests\meta_main.sec
InputName=meta_main

"~~process_meta_tests_meta_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/tests/meta_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_tests_meta_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\meta_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\meta_media.sec
InputName=meta_media

"~~process_meta_meta_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/meta_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_meta_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\meta_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\meta_model.sec
InputName=meta_model

"~~process_meta_meta_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/meta_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_meta_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\meta_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\tests\meta_scenario.sec
InputName=meta_scenario

"~~process_meta_tests_meta_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/tests/meta_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_tests_meta_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\meta_user_config.c
# End Source File
# Begin Source File

SOURCE=..\process\meta\nice_config.c
# End Source File
# Begin Source File

SOURCE=..\process\meta\nice_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\nice_media.sec
InputName=nice_media

"~~process_meta_nice_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/nice_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_nice_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\nice_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\nice_model.sec
InputName=nice_model

"~~process_meta_nice_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/nice_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_nice_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\nice_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\tests\nice_scenario.sec
InputName=nice_scenario

"~~process_meta_tests_nice_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/tests/nice_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_tests_nice_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\user_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\user_media.sec
InputName=user_media

"~~process_meta_user_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/user_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_user_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\user_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\user_model.sec
InputName=user_model

"~~process_meta_user_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/user_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_user_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\user_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\meta\tests\user_scenario.sec
InputName=user_scenario

"~~process_meta_tests_user_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/meta/tests/user_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_meta_tests_user_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Process.Pgroup"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\pgroup\pgroup_config.c
# End Source File
# Begin Source File

SOURCE=..\process\pgroup\tests\pgroup_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\pgroup\tests\pgroup_main.sec
InputName=pgroup_main

"~~process_pgroup_tests_pgroup_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/pgroup/tests/pgroup_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_pgroup_tests_pgroup_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\pgroup\pgroup_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\pgroup\pgroup_media.sec
InputName=pgroup_media

"~~process_pgroup_pgroup_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/pgroup/pgroup_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_pgroup_pgroup_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\pgroup\pgroup_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\pgroup\pgroup_model.sec
InputName=pgroup_model

"~~process_pgroup_pgroup_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/pgroup/pgroup_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_pgroup_pgroup_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\pgroup\tests\pgroup_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\pgroup\tests\pgroup_scenario.sec
InputName=pgroup_scenario

"~~process_pgroup_tests_pgroup_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/pgroup/tests/pgroup_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_pgroup_tests_pgroup_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Process.Process"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\process\process_common.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\process\process_common.sec
InputName=process_common

"~~process_process_process_common.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/process/process_common.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_process_process_common.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\process\process_config.c
# End Source File
# Begin Source File

SOURCE=..\process\process\tests\process_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\process\tests\process_main.sec
InputName=process_main

"~~process_process_tests_process_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/process/tests/process_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_process_tests_process_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\process\process_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\process\process_media.sec
InputName=process_media

"~~process_process_process_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/process/process_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_process_process_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\process\process_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\process\process_model.sec
InputName=process_model

"~~process_process_process_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/process/process_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_process_process_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\process\tests\process_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\process\tests\process_scenario.sec
InputName=process_scenario

"~~process_process_tests_process_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/process/tests/process_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_process_tests_process_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Process.Resources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\resources\resources_config.c
# End Source File
# Begin Source File

SOURCE=..\process\resources\tests\resources_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\resources\tests\resources_main.sec
InputName=resources_main

"~~process_resources_tests_resources_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/resources/tests/resources_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_resources_tests_resources_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\resources\resources_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\resources\resources_media.sec
InputName=resources_media

"~~process_resources_resources_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/resources/resources_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_resources_resources_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\resources\resources_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\resources\resources_model.sec
InputName=resources_model

"~~process_resources_resources_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/resources/resources_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_resources_resources_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\resources\tests\resources_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\resources\tests\resources_scenario.sec
InputName=resources_scenario

"~~process_resources_tests_resources_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/resources/tests/resources_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_resources_tests_resources_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Process.Scheduler"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\scheduler\process_scheduler_config.c
# End Source File
# Begin Source File

SOURCE=..\process\scheduler\tests\scheduler_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\scheduler\tests\scheduler_main.sec
InputName=scheduler_main

"~~process_scheduler_tests_scheduler_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/scheduler/tests/scheduler_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_scheduler_tests_scheduler_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\scheduler\scheduler_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\scheduler\scheduler_media.sec
InputName=scheduler_media

"~~process_scheduler_scheduler_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/scheduler/scheduler_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_scheduler_scheduler_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\scheduler\scheduler_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\scheduler\scheduler_model.sec
InputName=scheduler_model

"~~process_scheduler_scheduler_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/scheduler/scheduler_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_scheduler_scheduler_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\scheduler\tests\scheduler_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\scheduler\tests\scheduler_scenario.sec
InputName=scheduler_scenario

"~~process_scheduler_tests_scheduler_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/scheduler/tests/scheduler_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_scheduler_tests_scheduler_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Process.Ipc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\ipc\ipc_config.c
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\ipc_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\tests\ipc_main.sec
InputName=ipc_main

"~~process_ipc_tests_ipc_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/tests/ipc_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_tests_ipc_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\ipc_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\ipc_media.sec
InputName=ipc_media

"~~process_ipc_ipc_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/ipc_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_ipc_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\ipc_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\ipc_model.sec
InputName=ipc_model

"~~process_ipc_ipc_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/ipc_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_ipc_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\ipc_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\tests\ipc_scenario.sec
InputName=ipc_scenario

"~~process_ipc_tests_ipc_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/tests/ipc_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_tests_ipc_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\msg_config.c
# End Source File
# Begin Source File

SOURCE=..\process\ipc\msg_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\msg_media.sec
InputName=msg_media

"~~process_ipc_msg_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/msg_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_msg_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\msg_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\msg_model.sec
InputName=msg_model

"~~process_ipc_msg_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/msg_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_msg_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\msg_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\tests\msg_scenario.sec
InputName=msg_scenario

"~~process_ipc_tests_msg_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/tests/msg_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_tests_msg_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\sem_config.c
# End Source File
# Begin Source File

SOURCE=..\process\ipc\sem_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\sem_media.sec
InputName=sem_media

"~~process_ipc_sem_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/sem_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_sem_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\sem_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\sem_model.sec
InputName=sem_model

"~~process_ipc_sem_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/sem_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_sem_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\sem_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\tests\sem_scenario.sec
InputName=sem_scenario

"~~process_ipc_tests_sem_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/tests/sem_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_tests_sem_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\shm_config.c
# End Source File
# Begin Source File

SOURCE=..\process\ipc\shm_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\shm_media.sec
InputName=shm_media

"~~process_ipc_shm_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/shm_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_shm_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\shm_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\shm_model.sec
InputName=shm_model

"~~process_ipc_shm_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/shm_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_shm_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\shm_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\process\ipc\tests\shm_scenario.sec
InputName=shm_scenario

"~~process_ipc_tests_shm_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../process/ipc/tests/shm_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~process_ipc_tests_shm_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Pthread"

# PROP Default_Filter ""
# Begin Group "Pthread.Attr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\attr\attr_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\attr\tests\attr_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\attr\tests\attr_main.sec
InputName=attr_main

"~~pthread_attr_tests_attr_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/attr/tests/attr_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_attr_tests_attr_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\attr\attr_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\attr\attr_media.sec
InputName=attr_media

"~~pthread_attr_attr_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/attr/attr_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_attr_attr_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\attr\attr_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\attr\attr_model.sec
InputName=attr_model

"~~pthread_attr_attr_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/attr/attr_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_attr_attr_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\attr\tests\attr_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\attr\tests\attr_scenario.sec
InputName=attr_scenario

"~~pthread_attr_tests_attr_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/attr/tests/attr_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_attr_tests_attr_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Pthread.Cond"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\cond\cond_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\tests\cond_error_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\tests\cond_error_scenario.sec
InputName=cond_error_scenario

"~~pthread_cond_tests_cond_error_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/tests/cond_error_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_tests_cond_error_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\tests\cond_init_destroy_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\tests\cond_init_destroy_scenario.sec
InputName=cond_init_destroy_scenario

"~~pthread_cond_tests_cond_init_destroy_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/tests/cond_init_destroy_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_tests_cond_init_destroy_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\tests\cond_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\tests\cond_main.sec
InputName=cond_main

"~~pthread_cond_tests_cond_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/tests/cond_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_tests_cond_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\cond_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\cond_media.sec
InputName=cond_media

"~~pthread_cond_cond_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/cond_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_cond_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\cond_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\cond_model.sec
InputName=cond_model

"~~pthread_cond_cond_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/cond_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_cond_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\tests\cond_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\tests\cond_scenario.sec
InputName=cond_scenario

"~~pthread_cond_tests_cond_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/tests/cond_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_tests_cond_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\tests\cond_single_cond_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\tests\cond_single_cond_scenario.sec
InputName=cond_single_cond_scenario

"~~pthread_cond_tests_cond_single_cond_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/tests/cond_single_cond_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_tests_cond_single_cond_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\condattr_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\condattr_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\condattr_media.sec
InputName=condattr_media

"~~pthread_cond_condattr_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/condattr_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_condattr_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\condattr_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\condattr_model.sec
InputName=condattr_model

"~~pthread_cond_condattr_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/condattr_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_condattr_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\tests\condattr_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\cond\tests\condattr_scenario.sec
InputName=condattr_scenario

"~~pthread_cond_tests_condattr_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/cond/tests/condattr_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_cond_tests_condattr_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Pthread.Mutex"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\mutex\mutex_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutex_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\tests\mutex_main.sec
InputName=mutex_main

"~~pthread_mutex_tests_mutex_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/tests/mutex_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_tests_mutex_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutex_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\mutex_media.sec
InputName=mutex_media

"~~pthread_mutex_mutex_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/mutex_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_mutex_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutex_mixed_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\tests\mutex_mixed_scenario.sec
InputName=mutex_mixed_scenario

"~~pthread_mutex_tests_mutex_mixed_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/tests/mutex_mixed_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_tests_mutex_mixed_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutex_mixed_types_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\tests\mutex_mixed_types_scenario.sec
InputName=mutex_mixed_types_scenario

"~~pthread_mutex_tests_mutex_mixed_types_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/tests/mutex_mixed_types_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_tests_mutex_mixed_types_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutex_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\mutex_model.sec
InputName=mutex_model

"~~pthread_mutex_mutex_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/mutex_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_mutex_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutex_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\tests\mutex_scenario.sec
InputName=mutex_scenario

"~~pthread_mutex_tests_mutex_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/tests/mutex_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_tests_mutex_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutex_simple_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\tests\mutex_simple_scenario.sec
InputName=mutex_simple_scenario

"~~pthread_mutex_tests_mutex_simple_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/tests/mutex_simple_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_tests_mutex_simple_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutex_static_init_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\tests\mutex_static_init_scenario.sec
InputName=mutex_static_init_scenario

"~~pthread_mutex_tests_mutex_static_init_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/tests/mutex_static_init_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_tests_mutex_static_init_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutexattr_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutexattr_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\mutexattr_media.sec
InputName=mutexattr_media

"~~pthread_mutex_mutexattr_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/mutexattr_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_mutexattr_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutexattr_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\mutexattr_model.sec
InputName=mutexattr_model

"~~pthread_mutex_mutexattr_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/mutexattr_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_mutexattr_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutexattr_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\mutex\tests\mutexattr_scenario.sec
InputName=mutexattr_scenario

"~~pthread_mutex_tests_mutexattr_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/mutex/tests/mutexattr_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_mutex_tests_mutexattr_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Pthread.Pthread"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\pthread\tests\pthread_cleanup_diff_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\pthread\tests\pthread_cleanup_diff_scenario.sec
InputName=pthread_cleanup_diff_scenario

"~~pthread_pthread_tests_pthread_cleanup_diff_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/pthread/tests/pthread_cleanup_diff_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_pthread_tests_pthread_cleanup_diff_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\tests\pthread_cleanup_simple_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\pthread\tests\pthread_cleanup_simple_scenario.sec
InputName=pthread_cleanup_simple_scenario

"~~pthread_pthread_tests_pthread_cleanup_simple_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/pthread/tests/pthread_cleanup_simple_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_pthread_tests_pthread_cleanup_simple_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\tests\pthread_create_cancel_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\pthread\tests\pthread_create_cancel_scenario.sec
InputName=pthread_create_cancel_scenario

"~~pthread_pthread_tests_pthread_create_cancel_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/pthread/tests/pthread_create_cancel_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_pthread_tests_pthread_create_cancel_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\tests\pthread_exit_join_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\pthread\tests\pthread_exit_join_scenario.sec
InputName=pthread_exit_join_scenario

"~~pthread_pthread_tests_pthread_exit_join_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/pthread/tests/pthread_exit_join_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_pthread_tests_pthread_exit_join_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\tests\pthread_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\pthread\tests\pthread_main.sec
InputName=pthread_main

"~~pthread_pthread_tests_pthread_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/pthread/tests/pthread_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_pthread_tests_pthread_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\pthread_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\pthread\pthread_media.sec
InputName=pthread_media

"~~pthread_pthread_pthread_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/pthread/pthread_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_pthread_pthread_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\pthread_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\pthread\pthread_model.sec
InputName=pthread_model

"~~pthread_pthread_pthread_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/pthread/pthread_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_pthread_pthread_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\pthread_pthread_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\tests\pthread_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\pthread\tests\pthread_scenario.sec
InputName=pthread_scenario

"~~pthread_pthread_tests_pthread_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/pthread/tests/pthread_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_pthread_tests_pthread_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Pthread.Rwlock"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\rwlock\rwlock_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_deadlock_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlock_deadlock_scenario.sec
InputName=rwlock_deadlock_scenario

"~~pthread_rwlock_tests_rwlock_deadlock_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlock_deadlock_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlock_deadlock_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_errors_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlock_errors_scenario.sec
InputName=rwlock_errors_scenario

"~~pthread_rwlock_tests_rwlock_errors_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlock_errors_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlock_errors_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_init_destroy_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlock_init_destroy_scenario.sec
InputName=rwlock_init_destroy_scenario

"~~pthread_rwlock_tests_rwlock_init_destroy_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlock_init_destroy_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlock_init_destroy_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlock_main.sec
InputName=rwlock_main

"~~pthread_rwlock_tests_rwlock_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlock_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlock_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlock_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\rwlock_media.sec
InputName=rwlock_media

"~~pthread_rwlock_rwlock_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/rwlock_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_rwlock_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlock_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\rwlock_model.sec
InputName=rwlock_model

"~~pthread_rwlock_rwlock_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/rwlock_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_rwlock_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_N_rwlock_light_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlock_N_rwlock_light_scenario.sec
InputName=rwlock_N_rwlock_light_scenario

"~~pthread_rwlock_tests_rwlock_N_rwlock_light_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlock_N_rwlock_light_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlock_N_rwlock_light_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_N_rwlock_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlock_N_rwlock_scenario.sec
InputName=rwlock_N_rwlock_scenario

"~~pthread_rwlock_tests_rwlock_N_rwlock_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlock_N_rwlock_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlock_N_rwlock_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_repeated_lock_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlock_repeated_lock_scenario.sec
InputName=rwlock_repeated_lock_scenario

"~~pthread_rwlock_tests_rwlock_repeated_lock_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlock_repeated_lock_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlock_repeated_lock_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlock_scenario.sec
InputName=rwlock_scenario

"~~pthread_rwlock_tests_rwlock_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlock_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlock_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_single_rwlock_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlock_single_rwlock_scenario.sec
InputName=rwlock_single_rwlock_scenario

"~~pthread_rwlock_tests_rwlock_single_rwlock_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlock_single_rwlock_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlock_single_rwlock_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlockattr_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlockattr_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\rwlockattr_media.sec
InputName=rwlockattr_media

"~~pthread_rwlock_rwlockattr_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/rwlockattr_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_rwlockattr_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlockattr_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\rwlockattr_model.sec
InputName=rwlockattr_model

"~~pthread_rwlock_rwlockattr_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/rwlockattr_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_rwlockattr_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlockattr_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\rwlock\tests\rwlockattr_scenario.sec
InputName=rwlockattr_scenario

"~~pthread_rwlock_tests_rwlockattr_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/rwlock/tests/rwlockattr_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_rwlock_tests_rwlockattr_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Pthread.Scheduler"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\scheduler\scheduler_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\scheduler\tests\scheduler_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\scheduler\tests\scheduler_main.sec
InputName=scheduler_main

"~~pthread_scheduler_tests_scheduler_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/scheduler/tests/scheduler_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_scheduler_tests_scheduler_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\scheduler\scheduler_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\scheduler\scheduler_media.sec
InputName=scheduler_media

"~~pthread_scheduler_scheduler_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/scheduler/scheduler_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_scheduler_scheduler_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\scheduler\scheduler_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\scheduler\scheduler_model.sec
InputName=scheduler_model

"~~pthread_scheduler_scheduler_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/scheduler/scheduler_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_scheduler_scheduler_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\scheduler\tests\scheduler_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\scheduler\tests\scheduler_scenario.sec
InputName=scheduler_scenario

"~~pthread_scheduler_tests_scheduler_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/scheduler/tests/scheduler_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_scheduler_tests_scheduler_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Pthread.Sem"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\sem\pthread_sem_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\tests\sem_complex_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\sem\tests\sem_complex_scenario.sec
InputName=sem_complex_scenario

"~~pthread_sem_tests_sem_complex_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/sem/tests/sem_complex_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_sem_tests_sem_complex_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\tests\sem_error_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\sem\tests\sem_error_scenario.sec
InputName=sem_error_scenario

"~~pthread_sem_tests_sem_error_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/sem/tests/sem_error_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_sem_tests_sem_error_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\tests\sem_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\sem\tests\sem_main.sec
InputName=sem_main

"~~pthread_sem_tests_sem_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/sem/tests/sem_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_sem_tests_sem_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\sem_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\sem\sem_media.sec
InputName=sem_media

"~~pthread_sem_sem_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/sem/sem_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_sem_sem_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\sem_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\sem\sem_model.sec
InputName=sem_model

"~~pthread_sem_sem_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/sem/sem_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_sem_sem_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\tests\sem_open_close_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\sem\tests\sem_open_close_scenario.sec
InputName=sem_open_close_scenario

"~~pthread_sem_tests_sem_open_close_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/sem/tests/sem_open_close_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_sem_tests_sem_open_close_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\tests\sem_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\sem\tests\sem_scenario.sec
InputName=sem_scenario

"~~pthread_sem_tests_sem_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/sem/tests/sem_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_sem_tests_sem_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Pthread.Tls"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\tls\tls_config.c
# End Source File
# Begin Source File

SOURCE=..\pthread\tls\tests\tls_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\tls\tests\tls_main.sec
InputName=tls_main

"~~pthread_tls_tests_tls_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/tls/tests/tls_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_tls_tests_tls_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\tls\tls_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\tls\tls_media.sec
InputName=tls_media

"~~pthread_tls_tls_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/tls/tls_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_tls_tls_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\tls\tls_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\tls\tls_model.sec
InputName=tls_model

"~~pthread_tls_tls_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/tls/tls_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_tls_tls_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\pthread\tls\tests\tls_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\pthread\tls\tests\tls_scenario.sec
InputName=tls_scenario

"~~pthread_tls_tests_tls_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../pthread/tls/tests/tls_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~pthread_tls_tests_tls_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Signal"

# PROP Default_Filter ""
# Begin Group "Signal.Sigaction"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigaction\sigaction_config.c
# End Source File
# Begin Source File

SOURCE=..\signal\sigaction\tests\sigaction_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigaction\tests\sigaction_main.sec
InputName=sigaction_main

"~~signal_sigaction_tests_sigaction_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigaction/tests/sigaction_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigaction_tests_sigaction_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigaction\sigaction_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigaction\sigaction_media.sec
InputName=sigaction_media

"~~signal_sigaction_sigaction_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigaction/sigaction_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigaction_sigaction_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigaction\sigaction_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigaction\sigaction_model.sec
InputName=sigaction_model

"~~signal_sigaction_sigaction_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigaction/sigaction_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigaction_sigaction_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigaction\tests\sigaction_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigaction\tests\sigaction_scenario.sec
InputName=sigaction_scenario

"~~signal_sigaction_tests_sigaction_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigaction/tests/sigaction_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigaction_tests_sigaction_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Signal.Sigctrl"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigctrl\sigctrl_config.c
# End Source File
# Begin Source File

SOURCE=..\signal\sigctrl\tests\sigctrl_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigctrl\tests\sigctrl_main.sec
InputName=sigctrl_main

"~~signal_sigctrl_tests_sigctrl_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigctrl/tests/sigctrl_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigctrl_tests_sigctrl_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigctrl\sigctrl_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigctrl\sigctrl_media.sec
InputName=sigctrl_media

"~~signal_sigctrl_sigctrl_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigctrl/sigctrl_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigctrl_sigctrl_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigctrl\sigctrl_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigctrl\sigctrl_model.sec
InputName=sigctrl_model

"~~signal_sigctrl_sigctrl_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigctrl/sigctrl_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigctrl_sigctrl_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigctrl\tests\sigctrl_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigctrl\tests\sigctrl_scenario.sec
InputName=sigctrl_scenario

"~~signal_sigctrl_tests_sigctrl_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigctrl/tests/sigctrl_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigctrl_tests_sigctrl_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Signal.Sigsend"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigsend\tests\signal_specific_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigsend\tests\signal_specific_scenario.sec
InputName=signal_specific_scenario

"~~signal_sigsend_tests_signal_specific_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigsend/tests/signal_specific_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigsend_tests_signal_specific_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\tests\sigsend_additional_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigsend\tests\sigsend_additional_scenario.sec
InputName=sigsend_additional_scenario

"~~signal_sigsend_tests_sigsend_additional_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigsend/tests/sigsend_additional_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigsend_tests_sigsend_additional_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\sigsend_config.c
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\tests\sigsend_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigsend\tests\sigsend_main.sec
InputName=sigsend_main

"~~signal_sigsend_tests_sigsend_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigsend/tests/sigsend_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigsend_tests_sigsend_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\sigsend_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigsend\sigsend_media.sec
InputName=sigsend_media

"~~signal_sigsend_sigsend_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigsend/sigsend_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigsend_sigsend_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\sigsend_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigsend\sigsend_model.sec
InputName=sigsend_model

"~~signal_sigsend_sigsend_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigsend/sigsend_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigsend_sigsend_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\tests\sigsend_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigsend\tests\sigsend_scenario.sec
InputName=sigsend_scenario

"~~signal_sigsend_tests_sigsend_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigsend/tests/sigsend_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigsend_tests_sigsend_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Signal.Sigset"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigset\tests\sigset_automatic_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigset\tests\sigset_automatic_scenario.sec
InputName=sigset_automatic_scenario

"~~signal_sigset_tests_sigset_automatic_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigset/tests/sigset_automatic_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigset_tests_sigset_automatic_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\sigset_config.c
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\tests\sigset_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigset\tests\sigset_main.sec
InputName=sigset_main

"~~signal_sigset_tests_sigset_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigset/tests/sigset_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigset_tests_sigset_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\sigset_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigset\sigset_media.sec
InputName=sigset_media

"~~signal_sigset_sigset_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigset/sigset_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigset_sigset_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\sigset_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigset\sigset_model.sec
InputName=sigset_model

"~~signal_sigset_sigset_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigset/sigset_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigset_sigset_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\tests\sigset_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigset\tests\sigset_scenario.sec
InputName=sigset_scenario

"~~signal_sigset_tests_sigset_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigset/tests/sigset_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigset_tests_sigset_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\tests\sigset_static_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigset\tests\sigset_static_scenario.sec
InputName=sigset_static_scenario

"~~signal_sigset_tests_sigset_static_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigset/tests/sigset_static_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigset_tests_sigset_static_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Signal.Sigstr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigstr\tests\sigstr_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigstr\tests\sigstr_main.sec
InputName=sigstr_main

"~~signal_sigstr_tests_sigstr_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigstr/tests/sigstr_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigstr_tests_sigstr_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigstr\sigstr_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigstr\sigstr_media.sec
InputName=sigstr_media

"~~signal_sigstr_sigstr_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigstr/sigstr_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigstr_sigstr_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigstr\sigstr_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigstr\sigstr_model.sec
InputName=sigstr_model

"~~signal_sigstr_sigstr_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigstr/sigstr_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigstr_sigstr_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigstr\tests\sigstr_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigstr\tests\sigstr_scenario.sec
InputName=sigstr_scenario

"~~signal_sigstr_tests_sigstr_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigstr/tests/sigstr_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigstr_tests_sigstr_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Signal.Sigwait"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigwait\sigwait_config.c
# End Source File
# Begin Source File

SOURCE=..\signal\sigwait\tests\sigwait_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigwait\tests\sigwait_main.sec
InputName=sigwait_main

"~~signal_sigwait_tests_sigwait_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigwait/tests/sigwait_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigwait_tests_sigwait_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigwait\sigwait_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigwait\sigwait_media.sec
InputName=sigwait_media

"~~signal_sigwait_sigwait_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigwait/sigwait_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigwait_sigwait_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigwait\sigwait_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigwait\sigwait_model.sec
InputName=sigwait_model

"~~signal_sigwait_sigwait_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigwait/sigwait_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigwait_sigwait_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\signal\sigwait\tests\sigwait_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\signal\sigwait\tests\sigwait_scenario.sec
InputName=sigwait_scenario

"~~signal_sigwait_tests_sigwait_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../signal/sigwait/tests/sigwait_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~signal_sigwait_tests_sigwait_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Socket"

# PROP Default_Filter ""
# Begin Group "Socket.Netdata"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\netdata\tests\netdata_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netdata\tests\netdata_main.sec
InputName=netdata_main

"~~socket_netdata_tests_netdata_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netdata/tests/netdata_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netdata_tests_netdata_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\netdata\netdata_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netdata\netdata_media.sec
InputName=netdata_media

"~~socket_netdata_netdata_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netdata/netdata_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netdata_netdata_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\netdata\netdata_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netdata\netdata_model.sec
InputName=netdata_model

"~~socket_netdata_netdata_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netdata/netdata_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netdata_netdata_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\netdata\tests\netdata_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netdata\tests\netdata_scenario.sec
InputName=netdata_scenario

"~~socket_netdata_tests_netdata_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netdata/tests/netdata_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netdata_tests_netdata_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Socket.Netdb"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\netdb\netdb_config.c
# End Source File
# Begin Source File

SOURCE=..\socket\netdb\tests\netdb_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netdb\tests\netdb_main.sec
InputName=netdb_main

"~~socket_netdb_tests_netdb_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netdb/tests/netdb_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netdb_tests_netdb_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\netdb\netdb_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netdb\netdb_media.sec
InputName=netdb_media

"~~socket_netdb_netdb_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netdb/netdb_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netdb_netdb_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\netdb\netdb_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netdb\netdb_model.sec
InputName=netdb_model

"~~socket_netdb_netdb_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netdb/netdb_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netdb_netdb_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\netdb\tests\netdb_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netdb\tests\netdb_scenario.sec
InputName=netdb_scenario

"~~socket_netdb_tests_netdb_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netdb/tests/netdb_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netdb_tests_netdb_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Socket.Netif"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\netif\tests\netif_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netif\tests\netif_main.sec
InputName=netif_main

"~~socket_netif_tests_netif_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netif/tests/netif_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netif_tests_netif_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\netif\netif_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netif\netif_media.sec
InputName=netif_media

"~~socket_netif_netif_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netif/netif_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netif_netif_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\netif\netif_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netif\netif_model.sec
InputName=netif_model

"~~socket_netif_netif_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netif/netif_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netif_netif_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\netif\tests\netif_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\netif\tests\netif_scenario.sec
InputName=netif_scenario

"~~socket_netif_tests_netif_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/netif/tests/netif_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_netif_tests_netif_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Socket.Rpc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\rpc\clnt_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\clnt_media.sec
InputName=clnt_media

"~~socket_rpc_clnt_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/clnt_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_clnt_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\clnt_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\clnt_model.sec
InputName=clnt_model

"~~socket_rpc_clnt_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/clnt_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_clnt_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\pmap_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\pmap_media.sec
InputName=pmap_media

"~~socket_rpc_pmap_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/pmap_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_pmap_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\pmap_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\pmap_model.sec
InputName=pmap_model

"~~socket_rpc_pmap_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/pmap_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_pmap_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\pmap_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\tests\pmap_scenario.sec
InputName=pmap_scenario

"~~socket_rpc_tests_pmap_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/tests/pmap_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_tests_pmap_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\rpc_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\tests\rpc_main.sec
InputName=rpc_main

"~~socket_rpc_tests_rpc_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/tests/rpc_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_tests_rpc_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\secure_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\secure_media.sec
InputName=secure_media

"~~socket_rpc_secure_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/secure_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_secure_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\secure_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\secure_model.sec
InputName=secure_model

"~~socket_rpc_secure_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/secure_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_secure_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\secure_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\tests\secure_scenario.sec
InputName=secure_scenario

"~~socket_rpc_tests_secure_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/tests/secure_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_tests_secure_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\svc_clnt_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\tests\svc_clnt_scenario.sec
InputName=svc_clnt_scenario

"~~socket_rpc_tests_svc_clnt_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/tests/svc_clnt_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_tests_svc_clnt_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\svc_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\svc_media.sec
InputName=svc_media

"~~socket_rpc_svc_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/svc_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_svc_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\svc_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\svc_model.sec
InputName=svc_model

"~~socket_rpc_svc_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/svc_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_svc_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\xdr_config.c
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\xdr_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\xdr_media.sec
InputName=xdr_media

"~~socket_rpc_xdr_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/xdr_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_xdr_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\xdr_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\xdr_model.sec
InputName=xdr_model

"~~socket_rpc_xdr_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/xdr_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_xdr_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\xdr_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\rpc\tests\xdr_scenario.sec
InputName=xdr_scenario

"~~socket_rpc_tests_xdr_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/rpc/tests/xdr_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_rpc_tests_xdr_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Socket.Socket"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\socket\socket_config.c
# End Source File
# Begin Source File

SOURCE=..\socket\socket\tests\socket_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\socket\tests\socket_main.sec
InputName=socket_main

"~~socket_socket_tests_socket_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/socket/tests/socket_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_socket_tests_socket_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\socket\socket_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\socket\socket_media.sec
InputName=socket_media

"~~socket_socket_socket_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/socket/socket_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_socket_socket_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\socket\socket_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\socket\socket_model.sec
InputName=socket_model

"~~socket_socket_socket_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/socket/socket_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_socket_socket_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\socket\socket\tests\socket_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\socket\socket\tests\socket_scenario.sec
InputName=socket_scenario

"~~socket_socket_tests_socket_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../socket/socket/tests/socket_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~socket_socket_tests_socket_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "System"

# PROP Default_Filter ""
# Begin Group "System.Host"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\host\host_config.c
# End Source File
# Begin Source File

SOURCE=..\system\host\tests\host_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\host\tests\host_main.sec
InputName=host_main

"~~system_host_tests_host_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/host/tests/host_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_host_tests_host_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\host\host_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\host\host_media.sec
InputName=host_media

"~~system_host_host_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/host/host_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_host_host_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\host\host_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\host\host_model.sec
InputName=host_model

"~~system_host_host_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/host/host_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_host_host_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\host\tests\host_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\host\tests\host_scenario.sec
InputName=host_scenario

"~~system_host_tests_host_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/host/tests/host_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_host_tests_host_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "System.Stat"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\stat\stat_config.c
# End Source File
# Begin Source File

SOURCE=..\system\stat\tests\stat_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\stat\tests\stat_main.sec
InputName=stat_main

"~~system_stat_tests_stat_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/stat/tests/stat_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_stat_tests_stat_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\stat\stat_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\stat\stat_media.sec
InputName=stat_media

"~~system_stat_stat_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/stat/stat_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_stat_stat_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\stat\stat_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\stat\stat_model.sec
InputName=stat_model

"~~system_stat_stat_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/stat/stat_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_stat_stat_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\stat\tests\stat_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\stat\tests\stat_scenario.sec
InputName=stat_scenario

"~~system_stat_tests_stat_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/stat/tests/stat_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_stat_tests_stat_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "System.Sysconf"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\sysconf\sysconf_config.c
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\tests\sysconf_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\sysconf\tests\sysconf_main.sec
InputName=sysconf_main

"~~system_sysconf_tests_sysconf_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/sysconf/tests/sysconf_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_sysconf_tests_sysconf_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\sysconf_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\sysconf\sysconf_media.sec
InputName=sysconf_media

"~~system_sysconf_sysconf_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/sysconf/sysconf_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_sysconf_sysconf_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\sysconf_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\sysconf\sysconf_model.sec
InputName=sysconf_model

"~~system_sysconf_sysconf_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/sysconf/sysconf_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_sysconf_sysconf_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\tests\sysconf_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\sysconf\tests\sysconf_scenario.sec
InputName=sysconf_scenario

"~~system_sysconf_tests_sysconf_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/sysconf/tests/sysconf_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_sysconf_tests_sysconf_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "System.System"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\system\system_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\system\system_model.sec
InputName=system_model

"~~system_system_system_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/system/system_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_system_system_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "System.User"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\user\account_config.c
# End Source File
# Begin Source File

SOURCE=..\system\user\account_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\account_media.sec
InputName=account_media

"~~system_user_account_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/account_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_account_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\user\account_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\account_model.sec
InputName=account_model

"~~system_user_account_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/account_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_account_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\user\tests\account_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\tests\account_scenario.sec
InputName=account_scenario

"~~system_user_tests_account_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/tests/account_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_tests_account_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\user\group_config.c
# End Source File
# Begin Source File

SOURCE=..\system\user\group_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\group_media.sec
InputName=group_media

"~~system_user_group_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/group_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_group_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\user\group_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\group_model.sec
InputName=group_model

"~~system_user_group_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/group_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_group_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\user\tests\group_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\tests\group_scenario.sec
InputName=group_scenario

"~~system_user_tests_group_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/tests/group_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_tests_group_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\user\system_user_config.c
# End Source File
# Begin Source File

SOURCE=..\system\user\user_config.c
# End Source File
# Begin Source File

SOURCE=..\system\user\tests\user_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\tests\user_main.sec
InputName=user_main

"~~system_user_tests_user_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/tests/user_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_tests_user_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\user\user_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\user_media.sec
InputName=user_media

"~~system_user_user_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/user_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_user_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\user\user_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\user_model.sec
InputName=user_model

"~~system_user_user_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/user_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_user_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\system\user\tests\user_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\system\user\tests\user_scenario.sec
InputName=user_scenario

"~~system_user_tests_user_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../system/user/tests/user_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~system_user_tests_user_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Time"

# PROP Default_Filter ""
# Begin Group "Time.Clock"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\time\clock\clock_config.c
# End Source File
# Begin Source File

SOURCE=..\time\clock\tests\clock_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\clock\tests\clock_main.sec
InputName=clock_main

"~~time_clock_tests_clock_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/clock/tests/clock_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_clock_tests_clock_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\clock\clock_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\clock\clock_media.sec
InputName=clock_media

"~~time_clock_clock_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/clock/clock_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_clock_clock_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\clock\clock_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\clock\clock_model.sec
InputName=clock_model

"~~time_clock_clock_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/clock/clock_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_clock_clock_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\clock\tests\clock_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\clock\tests\clock_scenario.sec
InputName=clock_scenario

"~~time_clock_tests_clock_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/clock/tests/clock_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_clock_tests_clock_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Time.Conversion"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\time\conversion\conversion_config.c
# End Source File
# Begin Source File

SOURCE=..\time\conversion\tests\conversion_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\conversion\tests\conversion_main.sec
InputName=conversion_main

"~~time_conversion_tests_conversion_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/conversion/tests/conversion_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_conversion_tests_conversion_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\conversion\conversion_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\conversion\conversion_media.sec
InputName=conversion_media

"~~time_conversion_conversion_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/conversion/conversion_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_conversion_conversion_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\conversion\conversion_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\conversion\conversion_model.sec
InputName=conversion_model

"~~time_conversion_conversion_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/conversion/conversion_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_conversion_conversion_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\conversion\tests\conversion_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\conversion\tests\conversion_scenario.sec
InputName=conversion_scenario

"~~time_conversion_tests_conversion_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/conversion/tests/conversion_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_conversion_tests_conversion_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\conversion\convertionAlgorithms.c
# End Source File
# End Group
# Begin Group "Time.Time"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\time\time\time_config.c
# End Source File
# Begin Source File

SOURCE=..\time\time\tests\time_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\time\tests\time_main.sec
InputName=time_main

"~~time_time_tests_time_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/time/tests/time_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_time_tests_time_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\time\time_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\time\time_media.sec
InputName=time_media

"~~time_time_time_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/time/time_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_time_time_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\time\time_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\time\time_model.sec
InputName=time_model

"~~time_time_time_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/time/time_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_time_time_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\time\tests\time_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\time\tests\time_scenario.sec
InputName=time_scenario

"~~time_time_tests_time_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/time/tests/time_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_time_tests_time_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Time.Timer"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\time\timer\timer_config.c
# End Source File
# Begin Source File

SOURCE=..\time\timer\tests\timer_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\timer\tests\timer_main.sec
InputName=timer_main

"~~time_timer_tests_timer_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/timer/tests/timer_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_timer_tests_timer_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\timer\timer_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\timer\timer_media.sec
InputName=timer_media

"~~time_timer_timer_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/timer/timer_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_timer_timer_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\timer\timer_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\timer\timer_model.sec
InputName=timer_model

"~~time_timer_timer_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/timer/timer_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_timer_timer_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\time\timer\tests\timer_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\time\timer\tests\timer_scenario.sec
InputName=timer_scenario

"~~time_timer_tests_timer_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../time/timer/tests/timer_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~time_timer_tests_timer_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# Begin Group "Util"

# PROP Default_Filter ""
# Begin Group "Util.Assert"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\assert\tests\assert_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\assert\tests\assert_main.sec
InputName=assert_main

"~~util_assert_tests_assert_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/assert/tests/assert_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_assert_tests_assert_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\assert\assert_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\assert\assert_media.sec
InputName=assert_media

"~~util_assert_assert_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/assert/assert_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_assert_assert_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\assert\assert_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\assert\assert_model.sec
InputName=assert_model

"~~util_assert_assert_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/assert/assert_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_assert_assert_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\assert\tests\assert_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\assert\tests\assert_scenario.sec
InputName=assert_scenario

"~~util_assert_tests_assert_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/assert/tests/assert_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_assert_tests_assert_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Bit"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\bit\tests\bit_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\bit\tests\bit_main.sec
InputName=bit_main

"~~util_bit_tests_bit_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/bit/tests/bit_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_bit_tests_bit_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\bit\bit_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\bit\bit_media.sec
InputName=bit_media

"~~util_bit_bit_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/bit/bit_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_bit_bit_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\bit\bit_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\bit\bit_model.sec
InputName=bit_model

"~~util_bit_bit_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/bit/bit_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_bit_bit_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\bit\tests\bit_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\bit\tests\bit_scenario.sec
InputName=bit_scenario

"~~util_bit_tests_bit_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/bit/tests/bit_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_bit_tests_bit_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Compress"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\compress\compress_config.c
# End Source File
# Begin Source File

SOURCE=..\util\compress\tests\compress_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\compress\tests\compress_main.sec
InputName=compress_main

"~~util_compress_tests_compress_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/compress/tests/compress_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_compress_tests_compress_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\compress\compress_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\compress\compress_media.sec
InputName=compress_media

"~~util_compress_compress_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/compress/compress_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_compress_compress_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\compress\compress_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\compress\compress_model.sec
InputName=compress_model

"~~util_compress_compress_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/compress/compress_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_compress_compress_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\compress\tests\compress_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\compress\tests\compress_scenario.sec
InputName=compress_scenario

"~~util_compress_tests_compress_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/compress/tests/compress_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_compress_tests_compress_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Conversion"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\conversion\tests\conversion_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\tests\conversion_main.sec
InputName=conversion_main

"~~util_conversion_tests_conversion_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/tests/conversion_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_tests_conversion_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strint_config.c
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strint_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\strint_media.sec
InputName=strint_media

"~~util_conversion_strint_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/strint_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_strint_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strint_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\strint_model.sec
InputName=strint_model

"~~util_conversion_strint_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/strint_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_strint_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\strint_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\tests\strint_scenario.sec
InputName=strint_scenario

"~~util_conversion_tests_strint_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/tests/strint_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_tests_strint_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strreal_config.c
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strreal_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\strreal_media.sec
InputName=strreal_media

"~~util_conversion_strreal_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/strreal_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_strreal_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strreal_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\strreal_model.sec
InputName=strreal_model

"~~util_conversion_strreal_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/strreal_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_strreal_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\strreal_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\tests\strreal_scenario.sec
InputName=strreal_scenario

"~~util_conversion_tests_strreal_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/tests/strreal_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_tests_strreal_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\token_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\token_media.sec
InputName=token_media

"~~util_conversion_token_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/token_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_token_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\token_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\token_model.sec
InputName=token_model

"~~util_conversion_token_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/token_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_token_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\token_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\tests\token_scenario.sec
InputName=token_scenario

"~~util_conversion_tests_token_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/tests/token_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_tests_token_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\util_conversion_common.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\util_conversion_common.sec
InputName=util_conversion_common

"~~util_conversion_util_conversion_common.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/util_conversion_common.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_util_conversion_common.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wchar_config.c
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wchar_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\wchar_media.sec
InputName=wchar_media

"~~util_conversion_wchar_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/wchar_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_wchar_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wchar_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\wchar_model.sec
InputName=wchar_model

"~~util_conversion_wchar_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/wchar_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_wchar_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\wchar_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\tests\wchar_scenario.sec
InputName=wchar_scenario

"~~util_conversion_tests_wchar_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/tests/wchar_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_tests_wchar_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrint_config.c
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrint_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\wstrint_media.sec
InputName=wstrint_media

"~~util_conversion_wstrint_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/wstrint_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_wstrint_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrint_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\wstrint_model.sec
InputName=wstrint_model

"~~util_conversion_wstrint_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/wstrint_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_wstrint_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\wstrint_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\tests\wstrint_scenario.sec
InputName=wstrint_scenario

"~~util_conversion_tests_wstrint_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/tests/wstrint_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_tests_wstrint_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrreal_config.c
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrreal_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\wstrreal_media.sec
InputName=wstrreal_media

"~~util_conversion_wstrreal_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/wstrreal_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_wstrreal_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrreal_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\wstrreal_model.sec
InputName=wstrreal_model

"~~util_conversion_wstrreal_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/wstrreal_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_wstrreal_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\wstrreal_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\tests\wstrreal_scenario.sec
InputName=wstrreal_scenario

"~~util_conversion_tests_wstrreal_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/tests/wstrreal_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_tests_wstrreal_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wtoken_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\wtoken_media.sec
InputName=wtoken_media

"~~util_conversion_wtoken_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/wtoken_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_wtoken_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wtoken_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\wtoken_model.sec
InputName=wtoken_model

"~~util_conversion_wtoken_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/wtoken_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_wtoken_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\wtoken_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\conversion\tests\wtoken_scenario.sec
InputName=wtoken_scenario

"~~util_conversion_tests_wtoken_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/conversion/tests/wtoken_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_conversion_tests_wtoken_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Crypt"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\crypt\crypt_config.c
# End Source File
# Begin Source File

SOURCE=..\util\crypt\tests\crypt_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\crypt\tests\crypt_main.sec
InputName=crypt_main

"~~util_crypt_tests_crypt_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/crypt/tests/crypt_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_crypt_tests_crypt_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\crypt\crypt_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\crypt\crypt_media.sec
InputName=crypt_media

"~~util_crypt_crypt_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/crypt/crypt_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_crypt_crypt_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\crypt\crypt_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\crypt\crypt_model.sec
InputName=crypt_model

"~~util_crypt_crypt_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/crypt/crypt_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_crypt_crypt_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\crypt\tests\crypt_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\crypt\tests\crypt_scenario.sec
InputName=crypt_scenario

"~~util_crypt_tests_crypt_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/crypt/tests/crypt_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_crypt_tests_crypt_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Dl"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\dl\dl_config.c
# End Source File
# Begin Source File

SOURCE=..\util\dl\tests\dl_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\dl\tests\dl_main.sec
InputName=dl_main

"~~util_dl_tests_dl_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/dl/tests/dl_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_dl_tests_dl_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\dl\dl_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\dl\dl_media.sec
InputName=dl_media

"~~util_dl_dl_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/dl/dl_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_dl_dl_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\dl\dl_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\dl\dl_model.sec
InputName=dl_model

"~~util_dl_dl_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/dl/dl_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_dl_dl_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\dl\tests\dl_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\dl\tests\dl_scenario.sec
InputName=dl_scenario

"~~util_dl_tests_dl_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/dl/tests/dl_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_dl_tests_dl_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\dl\tests\dl_syms.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\dl\tests\dl_syms.sec
InputName=dl_syms

"~~util_dl_tests_dl_syms.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/dl/tests/dl_syms.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_dl_tests_dl_syms.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Float"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\float\float_config.c
# End Source File
# Begin Source File

SOURCE=..\util\float\tests\float_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\float\tests\float_main.sec
InputName=float_main

"~~util_float_tests_float_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/float/tests/float_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_float_tests_float_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\float\float_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\float\float_media.sec
InputName=float_media

"~~util_float_float_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/float/float_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_float_float_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\float\float_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\float\float_model.sec
InputName=float_model

"~~util_float_float_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/float/float_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_float_float_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\float\tests\float_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\float\tests\float_scenario.sec
InputName=float_scenario

"~~util_float_tests_float_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/float/tests/float_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_float_tests_float_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Format"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\format\fmtmsg_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\fmtmsg_media.sec
InputName=fmtmsg_media

"~~util_format_fmtmsg_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/fmtmsg_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_fmtmsg_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\fmtmsg_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\fmtmsg_model.sec
InputName=fmtmsg_model

"~~util_format_fmtmsg_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/fmtmsg_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_fmtmsg_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\fmtmsg_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\fmtmsg_scenario.sec
InputName=fmtmsg_scenario

"~~util_format_tests_fmtmsg_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/fmtmsg_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_fmtmsg_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\format_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\format_main.sec
InputName=format_main

"~~util_format_tests_format_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/format_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_format_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\format_sheafs.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\format_sheafs.sec
InputName=format_sheafs

"~~util_format_tests_format_sheafs.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/format_sheafs.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_format_sheafs.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\money_config.c
# End Source File
# Begin Source File

SOURCE=..\util\format\money_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\money_media.sec
InputName=money_media

"~~util_format_money_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/money_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_money_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\money_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\money_model.sec
InputName=money_model

"~~util_format_money_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/money_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_money_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\money_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\money_scenario.sec
InputName=money_scenario

"~~util_format_tests_money_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/money_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_money_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\printf_config.c
# End Source File
# Begin Source File

SOURCE=..\util\format\printf_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\printf_media.sec
InputName=printf_media

"~~util_format_printf_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/printf_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_printf_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\printf_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\printf_model.sec
InputName=printf_model

"~~util_format_printf_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/printf_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_printf_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\printf_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\printf_scenario.sec
InputName=printf_scenario

"~~util_format_tests_printf_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/printf_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_printf_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\printf_scenario_data.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\printf_scenario_data.sec
InputName=printf_scenario_data

"~~util_format_tests_printf_scenario_data.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/printf_scenario_data.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_printf_scenario_data.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\scanf_config.c
# End Source File
# Begin Source File

SOURCE=..\util\format\scanf_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\scanf_media.sec
InputName=scanf_media

"~~util_format_scanf_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/scanf_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_scanf_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\scanf_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\scanf_model.sec
InputName=scanf_model

"~~util_format_scanf_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/scanf_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_scanf_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\scanf_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\scanf_scenario.sec
InputName=scanf_scenario

"~~util_format_tests_scanf_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/scanf_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_scanf_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\scanf_scenario_data.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\scanf_scenario_data.sec
InputName=scanf_scenario_data

"~~util_format_tests_scanf_scenario_data.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/scanf_scenario_data.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_scanf_scenario_data.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\time_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\time_media.sec
InputName=time_media

"~~util_format_time_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/time_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_time_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\time_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\time_model.sec
InputName=time_model

"~~util_format_time_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/time_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_time_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\time_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\time_scenario.sec
InputName=time_scenario

"~~util_format_tests_time_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/time_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_time_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\wprintf_config.c
# End Source File
# Begin Source File

SOURCE=..\util\format\wprintf_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\wprintf_media.sec
InputName=wprintf_media

"~~util_format_wprintf_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/wprintf_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_wprintf_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\wprintf_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\wprintf_model.sec
InputName=wprintf_model

"~~util_format_wprintf_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/wprintf_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_wprintf_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\wprintf_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\wprintf_scenario.sec
InputName=wprintf_scenario

"~~util_format_tests_wprintf_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/wprintf_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_wprintf_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\wprintf_scenario_data.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\wprintf_scenario_data.sec
InputName=wprintf_scenario_data

"~~util_format_tests_wprintf_scenario_data.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/wprintf_scenario_data.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_wprintf_scenario_data.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\wscanf_config.c
# End Source File
# Begin Source File

SOURCE=..\util\format\wscanf_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\wscanf_media.sec
InputName=wscanf_media

"~~util_format_wscanf_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/wscanf_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_wscanf_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\wscanf_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\wscanf_model.sec
InputName=wscanf_model

"~~util_format_wscanf_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/wscanf_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_wscanf_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\wscanf_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\wscanf_scenario.sec
InputName=wscanf_scenario

"~~util_format_tests_wscanf_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/wscanf_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_wscanf_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\wscanf_scenario_data.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\wscanf_scenario_data.sec
InputName=wscanf_scenario_data

"~~util_format_tests_wscanf_scenario_data.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/wscanf_scenario_data.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_wscanf_scenario_data.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\wtime_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\wtime_media.sec
InputName=wtime_media

"~~util_format_wtime_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/wtime_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_wtime_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\wtime_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\wtime_model.sec
InputName=wtime_model

"~~util_format_wtime_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/wtime_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_wtime_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\wtime_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\format\tests\wtime_scenario.sec
InputName=wtime_scenario

"~~util_format_tests_wtime_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/format/tests/wtime_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_format_tests_wtime_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Getopt"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\getopt\getopt.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\getopt\getopt.sec
InputName=getopt

"~~util_getopt_getopt.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/getopt/getopt.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_getopt_getopt.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\getopt\tests\getopt_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\getopt\tests\getopt_main.sec
InputName=getopt_main

"~~util_getopt_tests_getopt_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/getopt/tests/getopt_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_getopt_tests_getopt_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\getopt\getopt_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\getopt\getopt_media.sec
InputName=getopt_media

"~~util_getopt_getopt_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/getopt/getopt_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_getopt_getopt_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\getopt\getopt_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\getopt\getopt_model.sec
InputName=getopt_model

"~~util_getopt_getopt_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/getopt/getopt_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_getopt_getopt_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\getopt\tests\getopt_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\getopt\tests\getopt_scenario.sec
InputName=getopt_scenario

"~~util_getopt_tests_getopt_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/getopt/tests/getopt_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_getopt_tests_getopt_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Inet"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\inet\inet_config.c
# End Source File
# Begin Source File

SOURCE=..\util\inet\tests\inet_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\inet\tests\inet_main.sec
InputName=inet_main

"~~util_inet_tests_inet_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/inet/tests/inet_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_inet_tests_inet_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\inet\inet_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\inet\inet_media.sec
InputName=inet_media

"~~util_inet_inet_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/inet/inet_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_inet_inet_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\inet\inet_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\inet\inet_model.sec
InputName=inet_model

"~~util_inet_inet_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/inet/inet_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_inet_inet_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\inet\tests\inet_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\inet\tests\inet_scenario.sec
InputName=inet_scenario

"~~util_inet_tests_inet_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/inet/tests/inet_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_inet_tests_inet_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Pam"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\pam\pam_config.c
# End Source File
# Begin Source File

SOURCE=..\util\pam\tests\pam_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\pam\tests\pam_main.sec
InputName=pam_main

"~~util_pam_tests_pam_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/pam/tests/pam_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_pam_tests_pam_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\pam\pam_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\pam\pam_media.sec
InputName=pam_media

"~~util_pam_pam_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/pam/pam_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_pam_pam_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\pam\pam_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\pam\pam_model.sec
InputName=pam_model

"~~util_pam_pam_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/pam/pam_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_pam_pam_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\pam\tests\pam_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\pam\tests\pam_scenario.sec
InputName=pam_scenario

"~~util_pam_tests_pam_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/pam/tests/pam_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_pam_tests_pam_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Regex"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\regex\tests\regex_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\regex\tests\regex_main.sec
InputName=regex_main

"~~util_regex_tests_regex_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/regex/tests/regex_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_regex_tests_regex_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\regex\regex_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\regex\regex_media.sec
InputName=regex_media

"~~util_regex_regex_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/regex/regex_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_regex_regex_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\regex\regex_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\regex\regex_model.sec
InputName=regex_model

"~~util_regex_regex_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/regex/regex_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_regex_regex_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\regex\tests\regex_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\regex\tests\regex_scenario.sec
InputName=regex_scenario

"~~util_regex_tests_regex_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/regex/tests/regex_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_regex_tests_regex_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Search"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\search\hash_config.c
# End Source File
# Begin Source File

SOURCE=..\util\search\hash_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\hash_media.sec
InputName=hash_media

"~~util_search_hash_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/hash_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_hash_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\hash_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\hash_model.sec
InputName=hash_model

"~~util_search_hash_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/hash_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_hash_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\hash_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\tests\hash_scenario.sec
InputName=hash_scenario

"~~util_search_tests_hash_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/tests/hash_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_tests_hash_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\queue_config.c
# End Source File
# Begin Source File

SOURCE=..\util\search\queue_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\queue_media.sec
InputName=queue_media

"~~util_search_queue_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/queue_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_queue_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\queue_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\queue_model.sec
InputName=queue_model

"~~util_search_queue_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/queue_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_queue_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\queue_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\tests\queue_scenario.sec
InputName=queue_scenario

"~~util_search_tests_queue_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/tests/queue_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_tests_queue_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\search_config.c
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\search_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\tests\search_main.sec
InputName=search_main

"~~util_search_tests_search_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/tests/search_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_tests_search_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\search_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\search_media.sec
InputName=search_media

"~~util_search_search_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/search_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_search_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\search_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\search_model.sec
InputName=search_model

"~~util_search_search_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/search_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_search_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\search_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\tests\search_scenario.sec
InputName=search_scenario

"~~util_search_tests_search_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/tests/search_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_tests_search_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\tree_config.c
# End Source File
# Begin Source File

SOURCE=..\util\search\tree_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\tree_media.sec
InputName=tree_media

"~~util_search_tree_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/tree_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_tree_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\tree_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\tree_model.sec
InputName=tree_model

"~~util_search_tree_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/tree_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_tree_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\tree_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\search\tests\tree_scenario.sec
InputName=tree_scenario

"~~util_search_tests_tree_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/search/tests/tree_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_search_tests_tree_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.String"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\string\casecmp_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\casecmp_media.sec
InputName=casecmp_media

"~~util_string_casecmp_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/casecmp_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_casecmp_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\casecmp_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\casecmp_model.sec
InputName=casecmp_model

"~~util_string_casecmp_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/casecmp_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_casecmp_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\casecmp_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\tests\casecmp_scenario.sec
InputName=casecmp_scenario

"~~util_string_tests_casecmp_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/tests/casecmp_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_tests_casecmp_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\mem_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\mem_media.sec
InputName=mem_media

"~~util_string_mem_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/mem_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_mem_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\mem_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\mem_model.sec
InputName=mem_model

"~~util_string_mem_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/mem_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_mem_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\mem_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\tests\mem_scenario.sec
InputName=mem_scenario

"~~util_string_tests_mem_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/tests/mem_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_tests_mem_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\str_config.c
# End Source File
# Begin Source File

SOURCE=..\util\string\str_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\str_media.sec
InputName=str_media

"~~util_string_str_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/str_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_str_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\str_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\str_model.sec
InputName=str_model

"~~util_string_str_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/str_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_str_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\str_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\tests\str_scenario.sec
InputName=str_scenario

"~~util_string_tests_str_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/tests/str_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_tests_str_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\string_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\tests\string_main.sec
InputName=string_main

"~~util_string_tests_string_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/tests/string_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_tests_string_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\wcasecmp_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\wcasecmp_media.sec
InputName=wcasecmp_media

"~~util_string_wcasecmp_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/wcasecmp_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_wcasecmp_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\wcasecmp_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\wcasecmp_model.sec
InputName=wcasecmp_model

"~~util_string_wcasecmp_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/wcasecmp_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_wcasecmp_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\wcasecmp_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\tests\wcasecmp_scenario.sec
InputName=wcasecmp_scenario

"~~util_string_tests_wcasecmp_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/tests/wcasecmp_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_tests_wcasecmp_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\wmem_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\wmem_media.sec
InputName=wmem_media

"~~util_string_wmem_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/wmem_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_wmem_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\wmem_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\wmem_model.sec
InputName=wmem_model

"~~util_string_wmem_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/wmem_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_wmem_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\wmem_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\tests\wmem_scenario.sec
InputName=wmem_scenario

"~~util_string_tests_wmem_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/tests/wmem_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_tests_wmem_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\wstr_config.c
# End Source File
# Begin Source File

SOURCE=..\util\string\wstr_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\wstr_media.sec
InputName=wstr_media

"~~util_string_wstr_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/wstr_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_wstr_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\wstr_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\wstr_model.sec
InputName=wstr_model

"~~util_string_wstr_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/wstr_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_wstr_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\wstr_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\string\tests\wstr_scenario.sec
InputName=wstr_scenario

"~~util_string_tests_wstr_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/string/tests/wstr_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_string_tests_wstr_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# Begin Group "Util.Wordexp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\wordexp\wordexp_config.c
# End Source File
# Begin Source File

SOURCE=..\util\wordexp\tests\wordexp_main.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\wordexp\tests\wordexp_main.sec
InputName=wordexp_main

"~~util_wordexp_tests_wordexp_main.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/wordexp/tests/wordexp_main.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_wordexp_tests_wordexp_main.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\wordexp\wordexp_media.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\wordexp\wordexp_media.sec
InputName=wordexp_media

"~~util_wordexp_wordexp_media.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/wordexp/wordexp_media.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_wordexp_wordexp_media.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\wordexp\wordexp_model.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\wordexp\wordexp_model.sec
InputName=wordexp_model

"~~util_wordexp_wordexp_model.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/wordexp/wordexp_model.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_wordexp_wordexp_model.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# Begin Source File

SOURCE=..\util\wordexp\tests\wordexp_scenario.sec
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Translate $(InputName).sec ...
InputPath=..\util\wordexp\tests\wordexp_scenario.sec
InputName=wordexp_scenario

"~~util_wordexp_tests_wordexp_scenario.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "$(CTESK_HOME)\include" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c /D __SEC__ /I "$(CTESK_HOME)/include" /FI ts/ts.h /E /Tc "../util/wordexp/tests/wordexp_scenario.sec" > "$(InputName).sei" 
	set R=%ERRORLEVEL% 
	if _%R%_==_0_ set SEC_PROPERTIES=$(CTESK_HOME)\etc\.sec.vs6.properties 
	if _%R%_==_0_ call "$(CTESK_HOME)\bin\sec-c.bat" "$(InputName).sei" "~~util_wordexp_tests_wordexp_scenario.c" 
	if _%R%_==_0_ set R=%ERRORLEVEL% 
	del "$(InputName).sei" > NUL 
	exit %R% 
	
# End Custom Build
# End Source File
# End Group
# End Group
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Group "Common.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\common\array.h
# End Source File
# Begin Source File

SOURCE=..\common\bigint.h
# End Source File
# Begin Source File

SOURCE=..\common\cbytearray.seh
# End Source File
# Begin Source File

SOURCE=..\common\chtypearray.seh
# End Source File
# Begin Source File

SOURCE=..\common\common_media.seh
# End Source File
# Begin Source File

SOURCE=..\common\common_model.seh
# End Source File
# Begin Source File

SOURCE=..\common\common_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\common\control_center.seh
# End Source File
# Begin Source File

SOURCE=..\common\cstring.seh
# End Source File
# Begin Source File

SOURCE=..\common\embed.h
# End Source File
# Begin Source File

SOURCE=..\common\explicit_fsm.h
# End Source File
# Begin Source File

SOURCE=..\common\init.seh
# End Source File
# Begin Source File

SOURCE=..\common\multiset.h
# End Source File
# Begin Source File

SOURCE=..\common\object_int.h
# End Source File
# Begin Source File

SOURCE=..\common\pointer.seh
# End Source File
# Begin Source File

SOURCE=..\common\scenario_decl.inl
# End Source File
# Begin Source File

SOURCE=..\common\scenario_table.inl
# End Source File
# Begin Source File

SOURCE=..\common\tree.seh
# End Source File
# Begin Source File

SOURCE=..\common\ts_socket.h
# End Source File
# Begin Source File

SOURCE=..\common\tsstream.seh
# End Source File
# Begin Source File

SOURCE=..\common\verbose.h
# End Source File
# Begin Source File

SOURCE=..\common\wchararray.seh
# End Source File
# Begin Source File

SOURCE=..\common\wstring.seh
# End Source File
# End Group
# Begin Group "Config.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\config\config_loader.seh
# End Source File
# Begin Source File

SOURCE=..\config\config_loader_gen.h
# End Source File
# Begin Source File

SOURCE=..\config\interpretation.seh
# End Source File
# Begin Source File

SOURCE=..\config\lsb_config.seh
# End Source File
# Begin Source File

SOURCE=..\config\model_config.seh
# End Source File
# Begin Source File

SOURCE=..\config\options.seh
# End Source File
# Begin Source File

SOURCE=..\config\platform_config.seh
# End Source File
# Begin Source File

SOURCE=..\config\system_config.seh
# End Source File
# Begin Source File

SOURCE=..\config\type_config.seh
# End Source File
# End Group
# Begin Group "Core.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\core\core.seh
# End Source File
# End Group
# Begin Group "Data.headers"

# PROP Default_Filter ""
# Begin Group "Data.Netinet.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\data\netinet\in_model.seh
# End Source File
# End Group
# Begin Group "Data.Sys.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\data\sys\resource_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\sys\socket_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\sys\time_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\sys\timeb_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\sys\types_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\sys\wait_model.seh
# End Source File
# End Group
# Begin Source File

SOURCE=..\data\basis.seh
# End Source File
# Begin Source File

SOURCE=..\data\dl_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\embed_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\errno_config.h
# End Source File
# Begin Source File

SOURCE=..\data\errno_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\inttypes_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\ncurses_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\sched_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\signal_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\stdlib_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\syslog_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\time_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\wchar_model.seh
# End Source File
# Begin Source File

SOURCE=..\data\wctype_model.seh
# End Source File
# End Group
# Begin Group "Fs.headers"

# PROP Default_Filter ""
# Begin Group "Fs.Dir.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\dir\dir_config.seh
# End Source File
# Begin Source File

SOURCE=..\fs\dir\dir_interpretation.seh
# End Source File
# Begin Source File

SOURCE=..\fs\dir\tests\dir_main.seh
# End Source File
# Begin Source File

SOURCE=..\fs\dir\dir_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\dir\dir_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\dir\tests\dir_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\fs\dir\tests\fs_dump.seh
# End Source File
# End Group
# Begin Group "Fs.Fifo.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\fifo\fifo_config.seh
# End Source File
# Begin Source File

SOURCE=..\fs\fifo\tests\fifo_main.seh
# End Source File
# Begin Source File

SOURCE=..\fs\fifo\fifo_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\fifo\fifo_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\fifo\tests\fifo_scenario.seh
# End Source File
# End Group
# Begin Group "Fs.Fs.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\fs\fs_interpretation.seh
# End Source File
# Begin Source File

SOURCE=..\fs\fs\tests\fs_main.seh
# End Source File
# Begin Source File

SOURCE=..\fs\fs\fs_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\fs\fs_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\fs\tests\fs_scenario.seh
# End Source File
# End Group
# Begin Group "Fs.Ftw.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\ftw\ftw_config.seh
# End Source File
# Begin Source File

SOURCE=..\fs\ftw\tests\ftw_main.seh
# End Source File
# Begin Source File

SOURCE=..\fs\ftw\ftw_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\ftw\ftw_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\ftw\tests\ftw_scenario.seh
# End Source File
# End Group
# Begin Group "Fs.Glob.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\glob\glob_config.seh
# End Source File
# Begin Source File

SOURCE=..\fs\glob\tests\glob_main.seh
# End Source File
# Begin Source File

SOURCE=..\fs\glob\glob_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\glob\glob_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\glob\tests\glob_scenario.seh
# End Source File
# End Group
# Begin Group "Fs.Meta.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\meta\access_config.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\access_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\access_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\access_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\fs_meta_common_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\meta_config.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\meta_main.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\meta_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\meta_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\meta_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\statvfs_config.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\statvfs_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\statvfs_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\meta\tests\statvfs_scenario.seh
# End Source File
# End Group
# Begin Group "Fs.Name.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\name\name_config.seh
# End Source File
# Begin Source File

SOURCE=..\fs\name\tests\name_main.seh
# End Source File
# Begin Source File

SOURCE=..\fs\name\name_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\name\name_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\name\tests\name_scenario.seh
# End Source File
# End Group
# Begin Group "Fs.Symlink.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\symlink\symlink_config.seh
# End Source File
# Begin Source File

SOURCE=..\fs\symlink\tests\symlink_main.seh
# End Source File
# Begin Source File

SOURCE=..\fs\symlink\symlink_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\symlink\symlink_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\symlink\tests\symlink_scenario.seh
# End Source File
# End Group
# Begin Group "Fs.Tmpfile.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\fs\tmpfile\tests\tmpfile_main.seh
# End Source File
# Begin Source File

SOURCE=..\fs\tmpfile\tmpfile_media.seh
# End Source File
# Begin Source File

SOURCE=..\fs\tmpfile\tmpfile_model.seh
# End Source File
# Begin Source File

SOURCE=..\fs\tmpfile\tests\tmpfile_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Io.headers"

# PROP Default_Filter ""
# Begin Group "Io.File.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\file\file_config.seh
# End Source File
# Begin Source File

SOURCE=..\io\file\tests\file_main.seh
# End Source File
# Begin Source File

SOURCE=..\io\file\file_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\file\file_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\file\tests\file_scenario.seh
# End Source File
# End Group
# Begin Group "Io.Fstream.Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\fstream\buffer_config.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\buffer_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\buffer_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\buffer_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\fstream_config.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\fstream_main.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\fstream_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\fstream_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\fstream_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\lock_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\lock_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\lock_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\wstream_config.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\wstream_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\wstream_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\fstream\tests\wstream_scenario.seh
# End Source File
# End Group
# Begin Group "Io.Multiplex.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\multiplex\multiplex_config.seh
# End Source File
# Begin Source File

SOURCE=..\io\multiplex\tests\multiplex_main.seh
# End Source File
# Begin Source File

SOURCE=..\io\multiplex\multiplex_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\multiplex\multiplex_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\multiplex\tests\multiplex_scenario.seh
# End Source File
# End Group
# Begin Group "Io.Pipe.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\pipe\pipe_config.seh
# End Source File
# Begin Source File

SOURCE=..\io\pipe\tests\pipe_main.seh
# End Source File
# Begin Source File

SOURCE=..\io\pipe\pipe_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\pipe\pipe_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\pipe\tests\pipe_scenario.seh
# End Source File
# End Group
# Begin Group "Io.Streams.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\streams\tests\streams_main.seh
# End Source File
# Begin Source File

SOURCE=..\io\streams\streams_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\streams\streams_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\streams\tests\streams_scenario.seh
# End Source File
# End Group
# Begin Group "Io.Syslog.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\syslog\tests\syslog_main.seh
# End Source File
# Begin Source File

SOURCE=..\io\syslog\syslog_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\syslog\syslog_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\syslog\tests\syslog_scenario.seh
# End Source File
# End Group
# Begin Group "Io.Term.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\io\term\tests\cf_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\cterm_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\open_tty_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\pt_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_canon_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_case_a_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_case_b_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_case_c_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\rw_case_d_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\tc_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\tcpgrp_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\term_config.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\term_main.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\term_media.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\term_model.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\term_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\io\term\tests\tty_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Locale.headers"

# PROP Default_Filter ""
# Begin Group "Locale.Collate.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\collate\collate_config.seh
# End Source File
# Begin Source File

SOURCE=..\locale\collate\tests\collate_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\collate\collate_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\collate\collate_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\collate\tests\collate_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Ctrans.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\ctrans\tests\ctrans_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\ctrans\ctrans_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\ctrans\ctrans_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\ctrans\tests\ctrans_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Ctype.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\ctype\tests\ctype_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\ctype\ctype_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\ctype\ctype_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\ctype\tests\ctype_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Iconv.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\iconv\iconv_config.seh
# End Source File
# Begin Source File

SOURCE=..\locale\iconv\tests\iconv_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\iconv\iconv_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\iconv\iconv_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\iconv\tests\iconv_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Locale.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\locale\locale_config.seh
# End Source File
# Begin Source File

SOURCE=..\locale\locale\tests\locale_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\locale\locale_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\locale\locale_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\locale\tests\locale_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Messages.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\messages\tests\messages_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\messages\messages_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\messages\messages_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\messages\tests\messages_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Nlcat.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\nlcat\tests\nlcat_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\nlcat\nlcat_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\nlcat\nlcat_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\nlcat\tests\nlcat_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Textdomain.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\textdomain\textdomain_config.h
# End Source File
# Begin Source File

SOURCE=..\locale\textdomain\textdomain_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\textdomain\textdomain_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\textdomain\tests\textdomain_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Wcollate.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\wcollate\wcollate_config.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wcollate\tests\wcollate_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wcollate\wcollate_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wcollate\wcollate_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wcollate\tests\wcollate_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Wctrans.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\wctrans\wctrans_config.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wctrans\tests\wctrans_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wctrans\wctrans_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wctrans\wctrans_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wctrans\tests\wctrans_scenario.seh
# End Source File
# End Group
# Begin Group "Locale.Wctype.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\locale\wctype\tests\wctype_main.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wctype\wctype_media.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wctype\wctype_model.seh
# End Source File
# Begin Source File

SOURCE=..\locale\wctype\tests\wctype_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Math.headers"

# PROP Default_Filter ""
# Begin Group "Math.Cexp.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\cexp\tests\cexp_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\cexp\cexp_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\cexp\cexp_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\cexp\tests\cexp_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Chyper.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\chyper\tests\chyper_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\chyper\chyper_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\chyper\chyper_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\chyper\tests\chyper_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Complex.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\complex\tests\complex_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\complex\complex_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\complex\complex_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\complex\tests\complex_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Ctrig.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\ctrig\tests\ctrig_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\ctrig\ctrig_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\ctrig\ctrig_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\ctrig\tests\ctrig_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Error.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\error\error_config.h
# End Source File
# Begin Source File

SOURCE=..\math\error\tests\error_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\error\error_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\error\error_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\error\tests\error_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Exp.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\exp\tests\exp_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\exp\exp_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\exp\exp_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\exp\tests\exp_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Gamma.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\gamma\gamma_config.h
# End Source File
# Begin Source File

SOURCE=..\math\gamma\tests\gamma_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\gamma\gamma_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\gamma\gamma_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\gamma\tests\gamma_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Hyper.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\hyper\tests\hyper_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\hyper\hyper_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\hyper\hyper_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\hyper\tests\hyper_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Integer.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\integer\tests\integer_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\integer\integer_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\integer\integer_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\integer\tests\integer_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Math.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\math\math_data.seh
# End Source File
# End Group
# Begin Group "Math.Rand.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\rand\tests\rand_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\rand\rand_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\rand\rand_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\rand\tests\rand_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Real.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\real\real_config.seh
# End Source File
# Begin Source File

SOURCE=..\math\real\tests\real_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\real\real_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\real\real_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\real\tests\real_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Trig.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\trig\tests\trig_main.seh
# End Source File
# Begin Source File

SOURCE=..\math\trig\trig_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\trig\trig_model.seh
# End Source File
# Begin Source File

SOURCE=..\math\trig\tests\trig_scenario.seh
# End Source File
# End Group
# Begin Group "Math.Bessel.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\math\bessel\bessel_config.h
# End Source File
# Begin Source File

SOURCE=..\math\bessel\bessel_media.seh
# End Source File
# Begin Source File

SOURCE=..\math\bessel\bessel_model.seh
# End Source File
# End Group
# End Group
# Begin Group "Memory.headers"

# PROP Default_Filter ""
# Begin Group "Memory.Heap.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\memory\heap\heap_config.seh
# End Source File
# Begin Source File

SOURCE=..\memory\heap\tests\heap_main.seh
# End Source File
# Begin Source File

SOURCE=..\memory\heap\heap_media.seh
# End Source File
# Begin Source File

SOURCE=..\memory\heap\heap_model.seh
# End Source File
# Begin Source File

SOURCE=..\memory\heap\tests\heap_scenario.seh
# End Source File
# End Group
# Begin Group "Memory.Break.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\memory\break\break_config.seh
# End Source File
# Begin Source File

SOURCE=..\memory\break\tests\break_main.seh
# End Source File
# Begin Source File

SOURCE=..\memory\break\break_media.seh
# End Source File
# Begin Source File

SOURCE=..\memory\break\break_model.seh
# End Source File
# Begin Source File

SOURCE=..\memory\break\tests\break_scenario.seh
# End Source File
# End Group
# Begin Group "Memory.Mman.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\memory\mman\mman_config.seh
# End Source File
# Begin Source File

SOURCE=..\memory\mman\tests\mman_main.seh
# End Source File
# Begin Source File

SOURCE=..\memory\mman\mman_media.seh
# End Source File
# Begin Source File

SOURCE=..\memory\mman\mman_model.seh
# End Source File
# Begin Source File

SOURCE=..\memory\mman\tests\mman_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Ncurses.headers"

# PROP Default_Filter ""
# Begin Group "Ncurses.Bkgd.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\bkgd\tests\bkgd_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\bkgd\bkgd_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\bkgd\bkgd_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\bkgd\tests\bkgd_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Border.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\border\tests\border_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\border\border_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\border\border_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\border\tests\border_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Char.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\char\add_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\add_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\tests\add_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\tests\char_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\input_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\input_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\tests\input_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\insert_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\insert_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\char\tests\insert_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Chgat.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\chgat\tests\chgat_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\chgat\chgat_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\chgat\chgat_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\chgat\tests\chgat_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Chstr.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\chstr\add_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\add_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\tests\add_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\tests\chstr_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\input_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\input_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\chstr\tests\input_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Clear.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\clear\tests\clear_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\clear\clear_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\clear\clear_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\clear\tests\clear_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Color.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\color\tests\color_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\color\color_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\color\color_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\color\tests\color_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Input.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\input\char_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\char_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\char_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\input_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\input_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\input_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\input_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\string_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\string_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\string_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\timeout_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\timeout_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\input\tests\timeout_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Line.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\line\tests\line_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\line\line_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\line\line_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\line\tests\line_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Misc.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\misc\tests\misc_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\misc\misc_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\misc\misc_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\misc\tests\misc_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Mode.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\mode\tests\mode_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\mode\mode_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\mode\mode_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\mode\tests\mode_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Move.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\move\tests\move_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\move\move_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\move\move_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\move\tests\move_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Ncurses.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\ncurses\ncurses_config.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\ncurses\ncurses_data.seh
# End Source File
# End Group
# Begin Group "Ncurses.Screen.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\screen\tests\screen_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\screen\screen_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\screen\screen_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\screen\tests\screen_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Slk.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\slk\tests\slk_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\slk\slk_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\slk\slk_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\slk\tests\slk_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.String.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\string\add_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\add_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\add_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\input_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\input_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\input_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\insert_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\insert_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\insert_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\printf_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\printf_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\printf_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\scanf_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\scanf_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\scanf_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\string\tests\string_main.seh
# End Source File
# End Group
# Begin Group "Ncurses.Terminal.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\terminal\tests\control_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\control_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\control_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\control_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\termcap_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\termcap_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\termcap_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\termcap_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\terminal_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\terminal_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\terminal_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\terminal_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\terminfo_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\terminfo_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\terminal\tests\terminfo_scenario.seh
# End Source File
# End Group
# Begin Group "Ncurses.Window.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ncurses\window\attr_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\attr_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\attr_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\pad_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\pad_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\pad_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\refresh_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\refresh_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\refresh_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\scroll_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\scroll_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\scroll_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\scroll_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\window_main.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\window_media.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\window_model.seh
# End Source File
# Begin Source File

SOURCE=..\ncurses\window\tests\window_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Process.headers"

# PROP Default_Filter ""
# Begin Group "Process.Context.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\context\context_config.seh
# End Source File
# Begin Source File

SOURCE=..\process\context\tests\context_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\context\context_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\context\context_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\context\tests\context_scenario.seh
# End Source File
# End Group
# Begin Group "Process.Environ.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\environ\environ_config.seh
# End Source File
# Begin Source File

SOURCE=..\process\environ\tests\environ_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\environ\environ_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\environ\environ_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\environ\tests\environ_scenario.seh
# End Source File
# End Group
# Begin Group "Process.Fenv.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\fenv\fenv_common.seh
# End Source File
# Begin Source File

SOURCE=..\process\fenv\fenv_config.seh
# End Source File
# Begin Source File

SOURCE=..\process\fenv\tests\fenv_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\fenv\fenv_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\fenv\fenv_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\fenv\tests\fenv_scenario.seh
# End Source File
# End Group
# Begin Group "Process.Goto.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\goto\tests\goto_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\goto\goto_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\goto\goto_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\goto\tests\goto_scenario.seh
# End Source File
# End Group
# Begin Group "Process.Ipc.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\ipc\ipc_config.h
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\ipc_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\ipc_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\ipc_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\ipc_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\msg_config.h
# End Source File
# Begin Source File

SOURCE=..\process\ipc\msg_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\msg_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\msg_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\sem_config.h
# End Source File
# Begin Source File

SOURCE=..\process\ipc\sem_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\sem_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\sem_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\shm_config.h
# End Source File
# Begin Source File

SOURCE=..\process\ipc\shm_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\shm_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\ipc\tests\shm_scenario.seh
# End Source File
# End Group
# Begin Group "Process.Meta.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\meta\fs_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\fs_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\fs_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\meta_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\meta_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\meta_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\meta_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\meta_user_config.h
# End Source File
# Begin Source File

SOURCE=..\process\meta\nice_config.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\nice_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\nice_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\nice_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\user_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\user_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\meta\tests\user_scenario.seh
# End Source File
# End Group
# Begin Group "Process.Pgroup.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\pgroup\pgroup_config.seh
# End Source File
# Begin Source File

SOURCE=..\process\pgroup\tests\pgroup_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\pgroup\pgroup_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\pgroup\pgroup_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\pgroup\tests\pgroup_scenario.seh
# End Source File
# End Group
# Begin Group "Process.Process.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\process\process_common.seh
# End Source File
# Begin Source File

SOURCE=..\process\process\process_config.seh
# End Source File
# Begin Source File

SOURCE=..\process\process\tests\process_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\process\process_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\process\process_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\process\tests\process_scenario.seh
# End Source File
# End Group
# Begin Group "Process.Resources.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\resources\resources_config.seh
# End Source File
# Begin Source File

SOURCE=..\process\resources\tests\resources_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\resources\resources_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\resources\resources_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\resources\tests\resources_scenario.seh
# End Source File
# End Group
# Begin Group "Process.Scheduler.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\process\scheduler\tests\scheduler_main.seh
# End Source File
# Begin Source File

SOURCE=..\process\scheduler\scheduler_media.seh
# End Source File
# Begin Source File

SOURCE=..\process\scheduler\scheduler_model.seh
# End Source File
# Begin Source File

SOURCE=..\process\scheduler\tests\scheduler_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Pthread.headers"

# PROP Default_Filter ""
# Begin Group "Pthread.Attr.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\attr\attr_config.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\attr\tests\attr_main.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\attr\attr_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\attr\attr_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\attr\tests\attr_scenario.seh
# End Source File
# End Group
# Begin Group "Pthread.Cond.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\cond\cond_config.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\tests\cond_main.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\cond_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\cond_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\tests\cond_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\condattr_config.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\condattr_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\condattr_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\cond\tests\condattr_scenario.seh
# End Source File
# End Group
# Begin Group "Pthread.Mutex.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\mutex\mutex_config.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutex_main.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutex_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutex_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutex_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutexattr_config.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutexattr_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\mutexattr_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\mutex\tests\mutexattr_scenario.seh
# End Source File
# End Group
# Begin Group "Pthread.Pthread.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\pthread\tests\pthread_main.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\pthread_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\pthread_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\pthread\tests\pthread_scenario.seh
# End Source File
# End Group
# Begin Group "Pthread.Rwlock.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\rwlock\Fedora_rwlock_errors.h
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlock_config.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_main.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlock_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlock_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlock_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlockattr_config.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlockattr_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\rwlockattr_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\rwlock\tests\rwlockattr_scenario.seh
# End Source File
# End Group
# Begin Group "Pthread.Scheduler.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\scheduler\scheduler_config.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\scheduler\tests\scheduler_main.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\scheduler\scheduler_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\scheduler\scheduler_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\scheduler\tests\scheduler_scenario.seh
# End Source File
# End Group
# Begin Group "Pthread.Sem.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\sem\pthread_sem_config.h
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\tests\sem_main.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\sem_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\sem_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\sem\tests\sem_scenario.seh
# End Source File
# End Group
# Begin Group "Pthread.Tls.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\pthread\tls\tls_config.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\tls\tests\tls_main.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\tls\tls_media.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\tls\tls_model.seh
# End Source File
# Begin Source File

SOURCE=..\pthread\tls\tests\tls_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Signal.headers"

# PROP Default_Filter ""
# Begin Group "Signal.Sigaction.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigaction\sigaction_config.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigaction\tests\sigaction_main.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigaction\sigaction_media.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigaction\sigaction_model.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigaction\tests\sigaction_scenario.seh
# End Source File
# End Group
# Begin Group "Signal.Sigctrl.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigctrl\sigctrl_config.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigctrl\tests\sigctrl_main.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigctrl\sigctrl_media.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigctrl\sigctrl_model.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigctrl\tests\sigctrl_scenario.seh
# End Source File
# End Group
# Begin Group "Signal.Sigsend.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigsend\tests\signal_specific_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\sigsend_config.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\tests\sigsend_main.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\sigsend_media.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\sigsend_model.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigsend\tests\sigsend_scenario.seh
# End Source File
# End Group
# Begin Group "Signal.Sigset.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigset\sigset_config.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\tests\sigset_main.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\sigset_media.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\sigset_model.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigset\tests\sigset_scenario.seh
# End Source File
# End Group
# Begin Group "Signal.Sigstr.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigstr\tests\sigstr_main.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigstr\sigstr_media.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigstr\sigstr_model.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigstr\tests\sigstr_scenario.seh
# End Source File
# End Group
# Begin Group "Signal.Sigwait.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\signal\sigwait\sigwait_config.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigwait\tests\sigwait_main.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigwait\sigwait_media.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigwait\sigwait_model.seh
# End Source File
# Begin Source File

SOURCE=..\signal\sigwait\tests\sigwait_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Socket.headers"

# PROP Default_Filter ""
# Begin Group "Socket.Netdata.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\netdata\tests\netdata_main.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netdata\netdata_media.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netdata\netdata_model.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netdata\tests\netdata_scenario.seh
# End Source File
# End Group
# Begin Group "Scoket.Netdb.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\netdb\netdb_config.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netdb\tests\netdb_main.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netdb\netdb_media.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netdb\netdb_model.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netdb\tests\netdb_scenario.seh
# End Source File
# End Group
# Begin Group "Socket.Netif.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\netif\tests\netif_main.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netif\netif_media.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netif\netif_model.seh
# End Source File
# Begin Source File

SOURCE=..\socket\netif\tests\netif_scenario.seh
# End Source File
# End Group
# Begin Group "Socket.Rpc.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\rpc\clnt_media.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\clnt_model.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\pmap_media.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\pmap_model.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\pmap_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\rpc_main.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\secure_media.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\secure_model.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\secure_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\svc_clnt_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\svc_media.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\svc_model.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\xdr_media.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\xdr_model.seh
# End Source File
# Begin Source File

SOURCE=..\socket\rpc\tests\xdr_scenario.seh
# End Source File
# End Group
# Begin Group "Socket.Socket.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\socket\socket\socket_config.seh
# End Source File
# Begin Source File

SOURCE=..\socket\socket\tests\socket_main.seh
# End Source File
# Begin Source File

SOURCE=..\socket\socket\socket_media.seh
# End Source File
# Begin Source File

SOURCE=..\socket\socket\socket_model.seh
# End Source File
# Begin Source File

SOURCE=..\socket\socket\tests\socket_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "System.headers"

# PROP Default_Filter ""
# Begin Group "System.Host.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\host\host_config.seh
# End Source File
# Begin Source File

SOURCE=..\system\host\tests\host_main.seh
# End Source File
# Begin Source File

SOURCE=..\system\host\host_media.seh
# End Source File
# Begin Source File

SOURCE=..\system\host\host_model.seh
# End Source File
# Begin Source File

SOURCE=..\system\host\tests\host_scenario.seh
# End Source File
# End Group
# Begin Group "System.Stat.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\stat\tests\stat_main.seh
# End Source File
# Begin Source File

SOURCE=..\system\stat\stat_media.seh
# End Source File
# Begin Source File

SOURCE=..\system\stat\stat_model.seh
# End Source File
# Begin Source File

SOURCE=..\system\stat\tests\stat_scenario.seh
# End Source File
# End Group
# Begin Group "System.Sysconf.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\sysconf\confname.h
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\local_lim.h
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\sysconf_config.seh
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\tests\sysconf_main.seh
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\sysconf_media.seh
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\sysconf_model.seh
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\tests\sysconf_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\system\sysconf\sysconf_spec.seh
# End Source File
# End Group
# Begin Group "Ssytem.System.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\system\system_model.seh
# End Source File
# End Group
# Begin Group "Ssytem.User.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\system\user\account_config.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\account_media.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\account_model.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\tests\account_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\group_config.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\group_media.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\group_model.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\tests\group_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\system_user_config.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\user_config.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\tests\user_main.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\user_media.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\user_model.seh
# End Source File
# Begin Source File

SOURCE=..\system\user\tests\user_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Time.headers"

# PROP Default_Filter ""
# Begin Group "Time.Clock.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\time\clock\clock_config.seh
# End Source File
# Begin Source File

SOURCE=..\time\clock\tests\clock_main.seh
# End Source File
# Begin Source File

SOURCE=..\time\clock\clock_media.seh
# End Source File
# Begin Source File

SOURCE=..\time\clock\clock_model.seh
# End Source File
# Begin Source File

SOURCE=..\time\clock\tests\clock_scenario.seh
# End Source File
# End Group
# Begin Group "Time.Conversion.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\time\conversion\conversion_config.seh
# End Source File
# Begin Source File

SOURCE=..\time\conversion\tests\conversion_main.seh
# End Source File
# Begin Source File

SOURCE=..\time\conversion\conversion_media.seh
# End Source File
# Begin Source File

SOURCE=..\time\conversion\conversion_model.seh
# End Source File
# Begin Source File

SOURCE=..\time\conversion\tests\conversion_scenario.seh
# End Source File
# End Group
# Begin Group "Time.Time.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\time\time\time_config.seh
# End Source File
# Begin Source File

SOURCE=..\time\time\tests\time_main.seh
# End Source File
# Begin Source File

SOURCE=..\time\time\time_media.seh
# End Source File
# Begin Source File

SOURCE=..\time\time\time_model.seh
# End Source File
# Begin Source File

SOURCE=..\time\time\tests\time_scenario.seh
# End Source File
# End Group
# Begin Group "Time.Timer.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\time\timer\timer_config.seh
# End Source File
# Begin Source File

SOURCE=..\time\timer\tests\timer_main.seh
# End Source File
# Begin Source File

SOURCE=..\time\timer\timer_media.seh
# End Source File
# Begin Source File

SOURCE=..\time\timer\timer_model.seh
# End Source File
# Begin Source File

SOURCE=..\time\timer\tests\timer_scenario.seh
# End Source File
# End Group
# End Group
# Begin Group "Util.headers"

# PROP Default_Filter ""
# Begin Group "Util.Assert.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\assert\tests\assert_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\assert\assert_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\assert\assert_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\assert\tests\assert_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Bit.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\bit\tests\bit_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\bit\bit_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\bit\bit_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\bit\tests\bit_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Compress.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\compress\compress_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\compress\tests\compress_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\compress\compress_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\compress\compress_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\compress\tests\compress_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\compress\compress_zlib.seh
# End Source File
# End Group
# Begin Group "Util.Conversion.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\conversion\ato_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\ato_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\ato_scen.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\ato_spec.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\conversion_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strint.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strint_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strint_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strint_mediators.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strint_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\strint_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strreal_config.h
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strreal_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strreal_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\strreal_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strto_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strto_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\strto_scen.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\strto_spec.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\token_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\token_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\token_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\token_spec.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\util_conversion_common.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wchar_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wchar_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wchar_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\wchar_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wcsto_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrint.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrint_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrint_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrint_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\wstrint_scen.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\wstrint_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrreal_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wstrreal_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\wstrreal_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wtoken_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\wtoken_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\conversion\tests\wtoken_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Crypt.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\crypt\crypt_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\crypt\tests\crypt_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\crypt\crypt_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\crypt\crypt_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\crypt\tests\crypt_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Dl.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\dl\tests\dl_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\dl\dl_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\dl\dl_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\dl\tests\dl_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\dl\tests\dl_syms.seh
# End Source File
# End Group
# Begin Group "Util.Float.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\float\float_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\float\tests\float_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\float\float_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\float\float_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\float\tests\float_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Format.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\format\fmtmsg_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\fmtmsg_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\fmtmsg_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\format_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\money_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\money_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\money_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\money_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\printf_config.h
# End Source File
# Begin Source File

SOURCE=..\util\format\printf_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\printf_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\printf_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\scanf_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\scanf_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\scanf_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\time_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\time_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\time_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\wprintf_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\wprintf_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\wprintf_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\wscanf_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\wscanf_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\wscanf_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\wtime_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\wtime_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\format\tests\wtime_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Getopt.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\getopt\getopt.seh
# End Source File
# Begin Source File

SOURCE=..\util\getopt\tests\getopt_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\getopt\getopt_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\getopt\getopt_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\getopt\tests\getopt_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Inet.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\inet\inet_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\inet\tests\inet_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\inet\inet_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\inet\inet_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\inet\tests\inet_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Pam.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\pam\libpam_definitions.seh
# End Source File
# Begin Source File

SOURCE=..\util\pam\tests\pam_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\pam\pam_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\pam\pam_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\pam\tests\pam_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Regex.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\regex\tests\regex_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\regex\regex_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\regex\regex_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\regex\tests\regex_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Search.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\search\hash_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\hash_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\hash_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\hash_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\queue_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\queue_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\queue_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\search_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\search_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\search_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\search_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\search_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\tree_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\tree_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\tree_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\search\tests\tree_scenario.seh
# End Source File
# End Group
# Begin Group "Util.String.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\string\casecmp_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\casecmp_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\casecmp_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\mem_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\mem_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\mem_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\str_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\str_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\str_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\str_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\string_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\wcasecmp_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\wcasecmp_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\wcasecmp_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\wmem_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\wmem_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\wmem_scenario.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\wstr_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\wstr_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\wstr_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\string\tests\wstr_scenario.seh
# End Source File
# End Group
# Begin Group "Util.Wordexp.headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\util\wordexp\wordexp_config.seh
# End Source File
# Begin Source File

SOURCE=..\util\wordexp\tests\wordexp_main.seh
# End Source File
# Begin Source File

SOURCE=..\util\wordexp\wordexp_media.seh
# End Source File
# Begin Source File

SOURCE=..\util\wordexp\wordexp_model.seh
# End Source File
# Begin Source File

SOURCE=..\util\wordexp\tests\wordexp_scenario.seh
# End Source File
# End Group
# End Group
# End Group
# Begin Source File

SOURCE=..\..\..\config\olver.tree
# Begin Custom Build
InputPath=..\..\..\config\olver.tree

"..\..\..\config\control.txt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	call ..\..\..\config\bin\Release\handbook.exe -o ../../../config/olver.tree -d ../../../config/default.conf -g -h .. 
	if errorlevel 0 echo 1 > ..\..\..\config\control.txt 
	
# End Custom Build
# End Source File
# End Target
# End Project
