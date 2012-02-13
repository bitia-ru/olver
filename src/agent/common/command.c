/*
 * Copyright (c) 2005-2006 Institute for System Programming
 * Russian Academy of Sciences
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "common/command.h"
#include "common/agent.h"
#include "common/system.h"

// 'fs' agents
// 'fs.fs' agents
#include "fs/fs/fs_agent.h"

// 'io' agents
// 'io.file' agents
#include "io/file/file_agent.h"

// 'io.syslog' agents
#include "io/syslog/syslog_agent.h"

// 'io.term' agents
#include "io/term/term_agent.h"

// 'memory' agents
// 'memory.heap' agents
#include "memory/heap/heap_agent.h"

// 'memory.break' agents
#include "memory/break/break_agent.h"

// 'pthread' agents
// 'pthread.mutex' agents
#include "pthread/mutex/mutexattr_agent.h"
#include "pthread/mutex/mutex_agent.h"

// 'pthread.pthread' agents
#include "pthread/pthread/pthread_agent.h"

// 'pthread.rwlock' agents
#include "pthread/rwlock/rwlockattr_agent.h"
#include "pthread/rwlock/rwlock_agent.h"

// 'pthread.cond' agents
#include "pthread/cond/condattr_agent.h"
#include "pthread/cond/cond_agent.h"

// 'pthread.tls' agents
#include "pthread/tls/tls_agent.h"

// 'pthread.attr' agents
#include "pthread/attr/attr_agent.h"

// 'pthread.scheduler' agents
#include "pthread/scheduler/scheduler_agent.h"

// 'pthread.sem' agents
#include "pthread/sem/sem_agent.h"

// 'process' agents
// 'process.context' agents
#include "process/context/context_agent.h"

// 'process.environ' agents
#include "process/environ/environ_agent.h"

// 'process.goto' agents
#include "process/goto/goto_agent.h"

// 'process.meta.fs' agents
#include "process/meta/fs_agent.h"

// 'process.meta.meta' agents
#include "process/meta/meta_agent.h"

// 'process.meta.nice' agents
#include "process/meta/nice_agent.h"

// 'process.meta.user' agents
#include "process/meta/user_agent.h"

// 'process.pgroup' agents
#include "process/pgroup/pgroup_agent.h"

// 'process.process' agents
#include "process/process/process_agent.h"

// 'process.resources' agents
#include "process/resources/resources_agent.h"

// 'process.scheduler' agents
#include "process/scheduler/scheduler_agent.h"

// 'system.user' agents
#include "system/user/user_agent.h"
#include "system/user/group_agent.h"
#include "system/user/account_agent.h"

// 'system.sysconf' agents
#include "system/sysconf/sysconf_agent.h"

// 'system.host' agents
#include "system/host/host_agent.h"

// 'time.clock' agents
#include "time/clock/clock_agent.h"

// 'time.conversion' agents
#include "time/conversion/conversion_agent.h"

// 'time.time' agents
#include "time/time/time_agent.h"

// 'time.timer' agents
#include "time/timer/timer_agent.h"

// 'util' agents
// 'util.assert' agents
#include "util/assert/assert_agent.h"

// 'util.bit' agents
#include "util/bit/bit_agent.h"

// 'util.compress' agents
#include "util/compress/compress_agent.h"

// 'util.crypt' agents
#include "util/crypt/crypt_agent.h"

// 'util.format' agents
#include "util/format/money_agent.h"

// 'util.format.printf' agents
#include "util/format/printf_agent.h"

// 'util.format.scanf' agents
#include "util/format/scanf_agent.h"

// 'util.format.wprintf' agents
#include "util/format/wprintf_agent.h"

// 'util.format.wscanf' agents
#include "util/format/wscanf_agent.h"

// 'util.getopt' agents
#include "util/getopt/getopt_agent.h"

// 'util.pam' agents
#include "util/pam/pam_agent.h"

// 'util.string' agents
#include "util/string/mem_agent.h"
#include "util/string/str_agent.h"
#include "util/string/wmem_agent.h"
#include "util/string/wstr_agent.h"

// 'util.search' agents
#include "util/search/hash_agent.h"
#include "util/search/tree_agent.h"
#include "util/search/queue_agent.h"
#include "util/search/search_agent.h"

// 'util.inet' agents
#include "util/inet/inet_agent.h"

// 'util.conversion' agents
#include "util/conversion/token_agent.h"
#include "util/conversion/wtoken_agent.h"
#include "util/conversion/wchar_agent.h"
#include "util/conversion/wstrint_agent.h"
#include "util/conversion/strint_agent.h"
#include "util/conversion/wstrreal_agent.h"

// 'util.dl' agents
#include "util/dl/dl_agent.h"

// 'util.wordexp' agents
#include "util/wordexp/wordexp_agent.h"

// 'math.integer' agents
#include "math/integer/integer_agent.h"

// 'math.math' agents
#include "math/math/math_agent.h"

//'math.real' agents
#include "math/real/real_agent.h"

//'math.bessel' agents
#include "math/bessel/bessel_agent.h"

//'math.complex' agents
#include "math/complex/complex_agent.h"

//'math.chyper' agents
#include "math/chyper/chyper_agent.h"

//'math.rand' agents
#include "math/rand/rand_agent.h"

//'math.gamma' agents
#include "math/gamma/gamma_agent.h"

//'math.error' agents
#include "math/error/error_agent.h"

//'math.trig' agents
#include "math/trig/trig_agent.h"

//'math.exp' agents
#include "math/exp/exp_agent.h"

// 'math.ctrig' agents
#include "math/ctrig/ctrig_agent.h"

// 'math.cexp' agents
#include "math/cexp/cexp_agent.h"

// 'math.hyper' agent agents
#include "math/hyper/hyper_agent.h"

// 'memory.mman' agents
#include "memory/mman/mman_agent.h"

// 'signal.sigset' agents
#include "signal/sigset/sigset_agent.h"

// 'signal.sigaction' agents
#include "signal/sigaction/sigaction_agent.h"

// 'signal.sigctrl' agents
#include "signal/sigctrl/sigctrl_agent.h"

// 'signal.sigsend' agents
#include "signal/sigsend/sigsend_agent.h"

// 'signal.sigstr' agents
#include "signal/sigstr/sigstr_agent.h"

// 'signal.sigwait' agents
#include "signal/sigwait/sigwait_agent.h"

// 'fs.name' agents
#include "fs/name/name_agent.h"

// 'fs.glob' agents
#include "fs/glob/glob_agent.h"

// 'fs.dir' agents
#include "fs/dir/dir_agent.h"

// 'fs.ftw' agents
#include "fs/ftw/ftw_agent.h"

// 'process.fenv' agents
#include "process/fenv/fenv_agent.h"

// 'fs.meta.meta' agents
#include "fs/meta/meta_agent.h"

// 'fs.meta.statvfs' agents
#include "fs/meta/statvfs_agent.h"

// 'fs.meta.statvfs' agents
#include "fs/meta/access_agent.h"

// 'fs.symlink' agents
#include "fs/symlink/symlink_agent.h"

// 'io.file' agents
#include "io/file/file_agent.h"

// 'locale.collate' agents
#include "locale/collate/collate_agent.h"

// 'locale.ctrans' agents
#include "locale/ctrans/ctrans_agent.h"

// 'locale.ctype' agents
#include "locale/ctype/ctype_agent.h"

// 'locale.iconv' agents
#include "locale/iconv/iconv_agent.h"

// 'locale.locale' agents
#include "locale/locale/locale_agent.h"

// 'locale.textdomain' agents
#include "locale/textdomain/textdomain_agent.h"

// 'locale.wcollate' agents
#include "locale/wcollate/wcollate_agent.h"

// 'locale.wctrans' agents
#include "locale/wctrans/wctrans_agent.h"

// 'locale.wctype' agents
#include "locale/wctype/wctype_agent.h"

// 'locale.messages' agents
#include "locale/messages/messages_agent.h"

// 'locale.nlcat' agents
#include "locale/nlcat/nlcat_agent.h"

// 'io.pipe' agents
#include "io/pipe/pipe_agent.h"

// 'fs.fifo' agents
#include "fs/fifo/fifo_agent.h"

// 'socket.netdata' agents
#include "socket/netdata/netdata_agent.h"

// 'socket.netdb' agents
#include "socket/netdb/netdb_agent.h"

// 'socket.netif' agents
#include "socket/netif/netif_agent.h"

// 'io.fstream.fstream' agents
#include "io/fstream/fstream_agent.h"

// 'io.fstream.buffer' agents
#include "io/fstream/buffer_agent.h"

// 'io.fstream.wstream' agents
#include "io/fstream/wstream_agent.h"

// 'io.fstream.lock' agents
#include "io/fstream/lock_agent.h"

// 'ncurses.terminal.terminal' agents
#include "ncurses/terminal/terminal_agent.h"

// 'ncurses.input.char' agents
#include "ncurses/input/char_agent.h"

// 'ncurses.input.input' agents
#include "ncurses/input/input_agent.h"

// 'ncurses.input.string' agents
#include "ncurses/input/string_agent.h"

// 'ncurses.input.timeout' agents
#include "ncurses/input/timeout_agent.h"

// 'ncurses.bkgd' commands
#include "ncurses/bkgd/bkgd_agent.h"

// 'ncurses.border' commands
#include "ncurses/border/border_agent.h"

// 'ncurses.mode' commands
#include "ncurses/mode/mode_agent.h"

// 'ncurses.char.add' commands
#include "ncurses/char/add_agent.h"

// 'ncurses.char.input' commands
#include "ncurses/char/input_agent.h"

// 'ncurses.char.insert' commands
#include "ncurses/char/insert_agent.h"

// 'ncurses.window.pad' commands
#include "ncurses/window/pad_agent.h"

// 'ncurses.window.scroll' commands
#include "ncurses/window/scroll_agent.h"

// 'ncurses.window.refresh' commands
#include "ncurses/window/refresh_agent.h"

// 'ncurses.window.window' commands
#include "ncurses/window/window_agent.h"

// 'ncurses.clear agents
#include "ncurses/clear/clear_agent.h"

// 'ncurses.color agents
#include "ncurses/color/color_agent.h"

// 'ncurses.chstr,add' commands
#include "ncurses/chstr/add_agent.h"

// 'ncurses.chstr,input' commands
#include "ncurses/chstr/input_agent.h"

// 'ncurses.line' commands
#include "ncurses/line/line_agent.h"

// 'ncurses.chgat' commands
#include "ncurses/chgat/chgat_agent.h"

// 'ncurses.move agents
#include "ncurses/move/move_agent.h"

// 'ncurses.misc agents
#include "ncurses/misc/misc_agent.h"

// 'ncurses.screen agents
#include "ncurses/screen/screen_agent.h"

// 'ncurses.string.add' commands
#include "ncurses/string/add_agent.h"

// 'ncurses.string.input' commands
#include "ncurses/string/input_agent.h"

// 'ncurses.string.insert' commands
#include "ncurses/string/insert_agent.h"

// 'ncurses.string.printf' commands
#include "ncurses/string/printf_agent.h"

// 'ncurses.string.scanf' commands
#include "ncurses/string/scanf_agent.h"

// 'ncurses.window.attr' commands
#include "ncurses/window/attr_agent.h"

// 'ncurses.terminal.terminfo' commands
#include "ncurses/terminal/terminfo_agent.h"

// 'ncurses.terminal.termcap' commands
#include "ncurses/terminal/termcap_agent.h"

// 'ncurses.terminal.control' agents
#include "ncurses/terminal/control_agent.h"

// 'ncurses.slk' agents
#include "ncurses/slk/slk_agent.h"

// 'socket.socket' agents
#include "socket/socket/socket_agent.h"

// 'socket.rpc.xdr' agents
#include "socket/rpc/xdr_agent.h"

// 'socket.rpc.pmap' agents
#include "socket/rpc/pmap_agent.h"

// 'socket.rpc.clnt' agents
#include "socket/rpc/clnt_agent.h"

// 'socket.rpc.svc' agents
#include "socket/rpc/svc_agent.h"

// 'util.float' agents
#include "util/float/float_agent.h"

// 'process.ipc.ipc' agents
#include "process/ipc/ipc_agent.h"

// 'process.ipc.msg' agents
#include "process/ipc/msg_agent.h"

// 'process.ipc.sem' agents
#include "process/ipc/sem_agent.h"

// 'process.ipc.shm' agents
#include "process/ipc/shm_agent.h"

// 'fs.tmpfile' agents
#include "fs/tmpfile/tmpfile_agent.h"

// 'util.regex' agents
#include "util/regex/regex_agent.h"

// 'system.stat' agents
#include "system/stat/stat_agent.h"

// 'io.multiplex' agents
#include "io/multiplex/multiplex_agent.h"

// 'util.format.time' agents
#include "util/format/time_agent.h"

// 'util.conversion.strreal' agents
#include "util/conversion/strreal_agent.h"

// 'util.string.casecmp' agents
#include "util/string/casecmp_agent.h"

// 'util.format.fmtmsg' agents
#include "util/format/fmtmsg_agent.h"

// util.string.wcasecmp
#include "util/string/wcasecmp_agent.h"

// util.format.wtime
#include "util/format/wtime_agent.h"

// socket.rpc.secure
#include "socket/rpc/secure_agent.h"

/********************************************************************/
/**                  Test Agent Commands Registration              **/
/********************************************************************/
void ta_register_commands(void)
{
  // System commands
  register_system_commands();

  // 'fs' commands
  // 'fs.fs' commands
  register_fs_fs_commands();

  // 'io' commands
  // 'io.file' commands
  register_io_file_commands();
  // 'io.term' commands
  register_io_term_commands();

  // 'memory' commands
  // 'memory.heap' commands
  register_memory_heap_commands();

  // 'pthread' commands
  // 'pthread.mutex' commands
  register_pthread_mutex_mutexattr_commands();
  register_pthread_mutex_mutex_commands();

  // 'pthread.pthread' commands
  register_pthread_pthread_commands();

  // 'pthread.rwlock' agents
  register_pthread_rwlock_rwlockattr_commands();
  register_pthread_rwlock_rwlock_commands();

  // 'pthread.cond' agents
  register_pthread_cond_condattr_commands();
  register_pthread_cond_cond_commands();

  // 'pthread.sem' agents
  register_pthread_sem_commands();

  // 'pthread.tls' agents
  register_pthread_tls_commands();

  // 'pthread.attr' agents
  register_pthread_attr_commands();

  // 'pthread.scheduler' agents
  register_pthread_scheduler_commands();

  // 'process' commands
  // 'process.context' commands
  register_process_context_commands();

  // 'process.environ' commands
  register_process_environ_commands();

  // 'process.fenv' commands
  register_process_fenv_commands();

  // 'process.goto' commands
  register_process_goto_commands();

  // 'process.meta.fs' commands
  register_process_meta_fs_commands();

  // 'process.meta.meta' commands
  register_process_meta_meta_commands();

  // 'process.meta.nice' commands
  register_process_meta_nice_commands();

  // 'process.meta.user' commands
  register_process_meta_user_commands();

  // 'process.pgroup' commands
  register_process_pgroup_commands();

  // 'process.process' commands
  register_process_process_commands();

  // 'process.resources' commands
  register_process_resources_commands();

  // 'process.scheduler' commands
  register_process_scheduler_commands();

  // 'system.user' commands
  register_system_user_user_commands();
  register_system_user_group_commands();
  register_system_user_account_commands();

  // 'system.sysconf' commands
  register_system_sysconf_commands();

  // 'system.host' commands
  register_system_host_commands();

  // 'time.clock' commands
  register_time_clock_commands();

  // 'time.conversion' commands
  register_time_conversion_commands();

  // 'time.time' commands
  register_time_time_commands();

  // 'time.timer' commands
  register_time_timer_commands();

  // 'util' commands
  // 'util.assert' commands
  register_util_assert_commands();

  // 'util.bit' commands
  register_util_bit_commands();

  // 'util.bit' commands
  register_util_format_money_commands();

  // 'util.getopt' commands
  register_util_getopt_commands();

  // 'util.crypt' commands
  register_util_crypt_commands();

  // 'util.compress' commands
  register_util_compress_commands();

  // 'util.format.printf' commands
  register_util_format_printf_commands();

  // 'util.format.scanf' commands
  register_util_format_scanf_commands();

  // 'util.format.wprintf' commands
  register_util_format_wprintf_commands();

  // 'util.format.wscanf' commands
  register_util_format_wscanf_commands();

  // 'util.pam' commands
  register_util_pam_commands();

  // 'util.string' commands
  register_util_string_mem_commands();
  register_util_string_str_commands();
  register_util_string_wmem_commands();
  register_util_string_wstr_commands();

  // 'util.search' commands
  register_util_search_hash_commands();
  register_util_search_tree_commands();
  register_util_search_queue_commands();
  register_util_search_search_commands();

  // 'util.inet' commands
  register_util_inet_commands();

  // 'util.conversion' commands
  register_util_conversion_token_commands();
  register_util_conversion_wtoken_commands();
  register_util_conversion_wstrint_commands();
  register_util_conversion_strint_commands();
  register_util_conversion_wchar_commands();

  register_util_conversion_wstrreal_commands();

  // 'util.wordexp' commands
  register_util_wordexp_commands();

  // 'util.dl' commands
  register_util_dl_commands();

  // 'math.integer' commands
  register_math_integer_commands();

  // 'math.math' commands
  register_math_math_commands();

  // 'memory.mman' commands
  register_memory_mman_commands();

  // 'memory.break' commands
  register_memory_break_commands();

  // 'signal.sigset' commands
  register_signal_sigset_commands();

  // 'signal.sigaction' commands
  register_signal_sigaction_commands();

  // 'signal.sigctrl' commands
  register_signal_sigctrl_commands();

  // 'signal.sigsend' commands
  register_signal_sigsend_commands();

  // 'signal.sigstr' commands
  register_signal_sigstr_commands();

  // 'signal.sigwait' commands
  register_signal_sigwait_commands();

  // 'fs.name' commands
  register_fs_name_commands();

  // 'fs.meta_meta' commands
  register_fs_meta_meta_commands();

  // 'fs.meta_statvfs' commands
  register_fs_meta_statvfs_commands();

  // 'fs.meta.access' commands
  register_fs_meta_access_commands();

  // 'fs.dir' commands
  register_fs_dir_commands();

  // 'fs.glob' commands
  register_fs_glob_commands();

  // 'fs.ftw' commands
  register_fs_ftw_commands();

  // 'fs.symlink' commands
  register_fs_symlink_commands();

  // 'io.file' commands
  register_io_file_commands();

  // 'locale.collate' commands
  register_locale_collate_commands();

  // 'locale.ctrans' commands
  register_locale_ctrans_commands();

  // 'locale.ctype' commands
  register_locale_ctype_commands();

  // 'locale.iconv' commands
  register_locale_iconv_commands();

  // 'locale.locale' commands
  register_locale_locale_commands();

  // 'locale.textdomain' commands
  register_locale_textdomain_commands();

  // 'locale.wcollate' commands
  register_locale_wcollate_commands();

  // 'locale.wctrans' commands
  register_locale_wctrans_commands();

  // 'locale.wctype' commands
  register_locale_wctype_commands();

  // 'locale.messages' commands
  register_locale_messages_commands();

  // 'locale.nlcat' commands
  register_locale_nlcat_commands();

  // 'io.pipe' commands
  register_io_pipe_commands();

  // 'fs.fifo' commands
  register_fs_fifo_commands();

  // 'socket' commands
  // 'socket.netdata' commands
  register_socket_netdata_commands();

  // 'socket.netdb' commands
  register_socket_netdb_commands();

  // 'socket.netif' commands
  register_socket_netif_commands();

  // 'io.fstream.fstream' commands
  register_io_fstream_fstream_commands();

  // 'io.fstream.buffer' commands
  register_io_fstream_buffer_commands();

  // 'io.fstream.wstream' commands
  register_io_fstream_wstream_commands();

  // 'io.fstream.lock' commands
  register_io_fstream_lock_commands();

  // 'io.syslog' commands
  register_io_syslog_commands();

  // 'ncurses.terminal.terminal' commands
  register_ncurses_terminal_terminal_commands();

  // 'ncurses.input.char' commands
  register_ncurses_input_char_commands();

  // 'ncurses.input.input' commands
  register_ncurses_input_input_commands();

  // 'ncurses.input.string' commands
  register_ncurses_input_string_commands();

  // 'ncurses.input.timeout' commands
  register_ncurses_input_timeout_commands();

  // 'ncurses.bkgd' commands
  register_ncurses_bkgd_commands();

  // 'ncurses.border' commands
  register_ncurses_border_commands();

  // 'ncurses.char.add' commands
  register_ncurses_char_add_commands();

  // 'ncurses.char.input' commands
  register_ncurses_char_input_commands();

  // 'ncurses.char.insert' commands
  register_ncurses_char_insert_commands();

  // 'ncurses.window.pad' commands
  register_ncurses_window_pad_commands();

  // 'ncurses.window.scroll' commands
  register_ncurses_window_scroll_commands();

  // 'ncurses.window.refresh' commands
  register_ncurses_window_refresh_commands();

  // 'ncurses.mode.refresh' commands
  register_ncurses_mode_commands();

  // 'ncurses.window.window' commands
  register_ncurses_window_window_commands();

  // 'ncurses.clear' commands
  register_ncurses_clear_commands();

  // 'ncurses.color' commands
  register_ncurses_color_commands();

  // 'ncurses.chstr,add' commands
  register_ncurses_chstr_add_commands();

  // 'ncurses.chstr,input' commands
  register_ncurses_chstr_input_commands();

  // 'ncurses.line' commands
  register_ncurses_line_commands();

  // 'ncurses.chgat' commands
  register_ncurses_chgat_commands();

  // 'ncurses.move' commands
  register_ncurses_move_commands();

  // 'ncurses.misc' commands
  register_ncurses_misc_commands();

  // 'ncurses.screen' commands
  register_ncurses_screen_commands();

  // 'ncurses.string.add' commands
  register_ncurses_string_add_commands();

  // 'ncurses.string.add' commands
  register_ncurses_string_input_commands();

  // 'ncurses.string.insert' commands
  register_ncurses_string_insert_commands();

  // 'ncurses.string.printf' commands
  register_ncurses_string_printf_commands();

  // 'ncurses.string.scanf' commands
  register_ncurses_string_scanf_commands();

  // 'ncurses.window.attr' commands
  register_ncurses_window_attr_commands();

  // 'ncurses.terminal.terminfo' commands
  register_ncurses_terminal_terminfo_commands();

  // 'ncurses.terminal.termcap' commands
  register_ncurses_terminal_termcap_commands();

  // 'ncurses.terminal.control' commands
  register_ncurses_terminal_control_commands();

  // 'ncurses.slk' commands
  register_ncurses_slk_commands();

  // 'socket.socket' commands
  register_socket_socket_commands();

  // 'socket.rpc.xdr' commands
  register_socket_rpc_xdr_commands();

  // 'socket.rpc.pmap' commands
  register_socket_rpc_pmap_commands();

  // 'socket.rpc.clnt' commands
  register_socket_rpc_clnt_commands();

  // 'socket.rpc.svc' commands
  register_socket_rpc_svc_commands();

  //'math.real' commands
  register_math_real_commands();

  //'math.bessel' commands
  register_math_bessel_commands();

  //'math.complex' commands
  register_math_complex_commands();

  //'math.chyper' commands
  register_math_chyper_commands();

  //'math.rand' commands
  register_math_rand_commands();

  //'math.gamma' commands
  register_math_gamma_commands();

  //'math.error' commands
  register_math_error_commands();

  //'math.trig' commands
  register_math_trig_commands();

  //'math.exp' commands
  register_math_exp_commands();

  // 'math.ctrig' commands
  register_math_ctrig_commands();

  // 'math.cexp' commands
  register_math_cexp_commands();

  // 'math.hyper' commands
  register_math_hyper_commands();

  //'util.float' commands
  register_util_float_commands();

  // 'process.ipc.ipc' agents
  register_process_ipc_ipc_commands();

  // 'process.ipc.msg' agents
  register_process_ipc_msg_commands();

  // 'process.ipc.sem' agents
  register_process_ipc_sem_commands();

  // 'process.ipc.shm' agents
  register_process_ipc_shm_commands();

  // 'fs.tmpfile' agents
  register_fs_tmpfile_commands();

  // 'util.regex' agents
  register_util_regex_commands();

  // 'system.stat' agents
  register_system_stat_commands();

  // 'io.multiplex' agents
  register_io_multiplex_commands();

  // 'util.format.time' agents
  register_util_format_time_commands();

  // 'util.conversion.strreal' agents
  register_util_conversion_strreal_commands();

  // 'util.string.casecmp' agents
  register_util_string_casecmp_commands();

  // 'util.format.fmtmsg' agents
  register_util_format_fmtmsg_commands();

  // util.string.wcasecmp
  register_util_string_wcasecmp_commands();

  // util.format.wtime
  register_util_format_wtime_commands();

  // socket.rpc.secure
  register_socket_rpc_secure_commands();


}
