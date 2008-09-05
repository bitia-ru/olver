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
 

/* [The number of data keys per process.] */
/* {_POSIX_THREAD_KEYS_MAX}
 *     [THR] 
 *     The number of data keys per process.
 *     Value: 128
 */
#define SUT_POSIX_THREAD_KEYS_MAX    128

/* [Controlling the iterations of destructors for thread-specific data] */
/* {_POSIX_THREAD_DESTRUCTOR_ITERATIONS}
 *     [THR] 
 *     The number of attempts made to destroy a thread's thread-specific data values on thread exit.
 *     Value: 4
 */
#define SUT_POSIX_THREAD_DESTRUCTOR_ITERATIONS    4

/* [The number of threads per process] */
/* {_POSIX_THREAD_THREADS_MAX}
 *     [THR] 
 *     The number of threads per process.
 *     Value: 64
 */
#define SUT_POSIX_THREAD_THREADS_MAX    64


/*
    {_POSIX_AIO_LISTIO_MAX}
        [AIO] 
        The number of I/O operations that can be specified in a list I/O call.
        Value: 2 
    {_POSIX_AIO_MAX}
        [AIO] 
        The number of outstanding asynchronous I/O operations.
        Value: 1 
    {_POSIX_ARG_MAX}
        Maximum length of argument to the exec functions including environment data.
        Value: 4 096
    {_POSIX_CHILD_MAX}
        Maximum number of simultaneous processes per real user ID.
        Value: 25
    {_POSIX_DELAYTIMER_MAX}
        [TMR] 
        The number of timer expiration overruns.
        Value: 32 
    {_POSIX_HOST_NAME_MAX}
        Maximum length of a host name (not including the terminating null) as returned from the gethostname() function.
        Value: 255
    {_POSIX_LINK_MAX}
        Maximum number of links to a single file.
        Value: 8
    {_POSIX_LOGIN_NAME_MAX}
        The size of the storage required for a login name, in bytes, including the terminating null.
        Value: 9
*/
/* [Minimum number of operations in one list I/O call] */
#define SUT_POSIX_AIO_LISTIO_MAX    2

/* [Minimal number of outstanding asynchronous I/O operations] */
#define SUT_POSIX_AIO_MAX        1

/* [Maximum length of arguments to `execve', including environment] */
#define    SUT_POSIX_ARG_MAX        4096

/* [Maximum simultaneous processes per real user ID] */
#define SUT_POSIX_CHILD_MAX    25

/* [Minimal number of timer expiration overruns] */
#define SUT_POSIX_DELAYTIMER_MAX    32

/* [Maximum length of a host name (not including the terminating null)
   as returned from the GETHOSTNAME function] */
#define SUT_POSIX_HOST_NAME_MAX    255

/* [Maximum link count of a file] */
#define    SUT_POSIX_LINK_MAX        8

/* [Maximum length of login name] */
#define    SUT_POSIX_LOGIN_NAME_MAX    9


/*
    {_POSIX_MAX_CANON}
        Maximum number of bytes in a terminal canonical input queue.
        Value: 255
    {_POSIX_MAX_INPUT}
        Maximum number of bytes allowed in a terminal input queue.
        Value: 255
    {_POSIX_MQ_OPEN_MAX}
        [MSG] 
        The number of message queues that can be open for a single process.
        Value: 8 
    {_POSIX_MQ_PRIO_MAX}
        [MSG] 
        The maximum number of message priorities supported by the implementation.
        Value: 32 
    {_POSIX_NAME_MAX}
        Maximum number of bytes in a filename (not including terminating null).
        Value: 14
    {_POSIX_NGROUPS_MAX}
        Maximum number of simultaneous supplementary group IDs per process.
        Value: 8
    {_POSIX_OPEN_MAX}
        Maximum number of files that one process can have open at any one time.
        Value: 20
    {_POSIX_PATH_MAX}
        Maximum number of bytes in a pathname.
        Value: 256
    {_POSIX_PIPE_BUF}
        Maximum number of bytes that is guaranteed to be atomic when writing to a pipe.
        Value: 512
    {_POSIX_RE_DUP_MAX}
        The number of repeated occurrences of a BRE permitted by the regexec() and regcomp() functions when using the interval notation {\(m,n\}; see BREs Matching Multiple Characters.
        Value: 255
    {_POSIX_RTSIG_MAX}
        [RTS] 
        The number of realtime signal numbers reserved for application use.
        Value: 8 
    {_POSIX_SEM_NSEMS_MAX}
        [SEM] 
        The number of semaphores that a process may have.
        Value: 256 
    {_POSIX_SEM_VALUE_MAX}
        [SEM] 
        The maximum value a semaphore may have.
        Value: 32 767 
    {_POSIX_SIGQUEUE_MAX}
        [RTS] 
        The number of queued signals that a process may send and have pending at the receiver(s) at any time.
        Value: 32 
    {_POSIX_SSIZE_MAX}
        The value that can be stored in an object of type ssize_t.
        Value: 32 767
    {_POSIX_STREAM_MAX}
        The number of streams that one process can have open at one time.
        Value: 8
    {_POSIX_SS_REPL_MAX}
        [SS|TSP] 
        The number of replenishment operations that may be simultaneously pending for a particular sporadic server scheduler.
        Value: 4 
    {_POSIX_SYMLINK_MAX}
        The number of bytes in a symbolic link.
        Value: 255
    {_POSIX_SYMLOOP_MAX}
        The number of symbolic links that can be traversed in the resolution of a pathname in the absence of a loop.
        Value: 8
*/
/* [Number of bytes in a terminal canonical input queue] */
#define    SUT_POSIX_MAX_CANON    255

/* [Number of bytes for which space will be
   available in a terminal input queue] */
#define    SUT_POSIX_MAX_INPUT    255

/* [Maximum number of message queues open for a process] */
#define SUT_POSIX_MQ_OPEN_MAX    8

/* [Maximum number of supported message priorities] */
#define SUT_POSIX_MQ_PRIO_MAX    32

/* [Number of bytes in a filename] */
#define    SUT_POSIX_NAME_MAX        14

/* [Number of simultaneous supplementary group IDs per process] */
#define SUT_POSIX_NGROUPS_MAX    8

/* [Number of files one process can have open at once] */
#define SUT_POSIX_OPEN_MAX    20

/* [Number of bytes in a pathname] */
#define    SUT_POSIX_PATH_MAX        256

/* [Number of bytes than can be written atomically to a pipe] */
#define    SUT_POSIX_PIPE_BUF        512

/* [The number of repeated occurrences of a BRE permitted by the
   REGEXEC and REGCOMP functions when using the interval notation] */
#define SUT_POSIX_RE_DUP_MAX    255

/* [Minimal number of realtime signals reserved for the application] */
#define SUT_POSIX_RTSIG_MAX    8

/* [Number of semaphores a process can have] */
#define SUT_POSIX_SEM_NSEMS_MAX    256

/* [Maximal value of a semaphore] */
#define SUT_POSIX_SEM_VALUE_MAX    32767

/* [Number of pending realtime signals] */
#define SUT_POSIX_SIGQUEUE_MAX    32

/* [Largest value of a `ssize_t'] */
#define    SUT_POSIX_SSIZE_MAX    32767

/* [Number of streams a process can have open at once] */
#define    SUT_POSIX_STREAM_MAX    8

/* [The number of replenishment operations that may be simultaneously 
 * pending for a particular sporadic server scheduler] */
#define SUT_POSIX_SS_REPL_MAX 4

/* [The number of bytes in a symbolic link] */
#define SUT_POSIX_SYMLINK_MAX    255

/* [The number of symbolic links that can be traversed in the
   resolution of a pathname in the absence of a loop] */
#define SUT_POSIX_SYMLOOP_MAX    8


/* {_POSIX_TIMER_MAX}
        [TMR] 
        The per-process number of timers.
        Value: 32
 */
/* [Number of timer for a process] */
#define SUT_POSIX_TIMER_MAX    32

/*
    {_POSIX_TTY_NAME_MAX}
        The size of the storage required for a terminal device name, in bytes, including the terminating null.
        Value: 9
    {_POSIX_TZNAME_MAX}
        Maximum number of bytes supported for the name of a timezone (not of the TZ variable).
        Value: 6
*/
/* [Maximum number of characters in a tty name] */
#define    SUT_POSIX_TTY_NAME_MAX    9

/* [Maximum length of a timezone name (element of `tzname')] */
#define    SUT_POSIX_TZNAME_MAX    6


/*
    {_POSIX2_BC_BASE_MAX}
        Maximum obase values allowed by the bc utility.
        Value: 99
    {_POSIX2_BC_DIM_MAX}
        Maximum number of elements permitted in an array by the bc utility.
        Value: 2 048
    {_POSIX2_BC_SCALE_MAX}
        Maximum scale value allowed by the bc utility.
        Value: 99
    {_POSIX2_BC_STRING_MAX}
        Maximum length of a string constant accepted by the bc utility.
        Value: 1 000
    {_POSIX2_CHARCLASS_NAME_MAX}
        Maximum number of bytes in a character class name.
        Value: 14
    {_POSIX2_COLL_WEIGHTS_MAX}
        Maximum number of weights that can be assigned to an entry of the LC_COLLATE order keyword in the locale definition file; see Locale.
        Value: 2
    {_POSIX2_EXPR_NEST_MAX}
        Maximum number of expressions that can be nested within parentheses by the expr utility.
        Value: 32
    {_POSIX2_LINE_MAX}
        Unless otherwise noted, the maximum length, in bytes, of a utility's input line (either standard input or another file), when the utility is described as processing text files. The length includes room for the trailing <newline>.
        Value: 2 048
    {_POSIX2_RE_DUP_MAX]
        Maximum number of repeated occurrences of a regular expression permitted when using the interval notation \{m,n\}; see Regular Expressions.
        Value: 255
    {_XOPEN_IOV_MAX}
        [XSI] 
        Maximum number of iovec structures that one process has available for use with readv() or writev().
        Value: 16        
 */
/* [The maximum `ibase' and `obase' values allowed by the `bc' utility] */
#define    SUT_POSIX2_BC_BASE_MAX        99

/* [The maximum number of elements allowed in an array by the `bc' utility] */
#define    SUT_POSIX2_BC_DIM_MAX        2048

/* [The maximum `scale' value allowed by the `bc' utility] */
#define    SUT_POSIX2_BC_SCALE_MAX        99

/* [The maximum length of a string constant accepted by the `bc' utility] */
#define    SUT_POSIX2_BC_STRING_MAX        1000

/* [The maximum number of bytes in a character class name.  We have no
   fixed limit, 2048 is a high number] */
#define SUT_POSIX2_CHARCLASS_NAME_MAX 14

/* [The maximum number of weights that can be assigned to an entry of
   the LC_COLLATE `order' keyword in the locale definition file] */
#define    SUT_POSIX2_COLL_WEIGHTS_MAX    2

/* [The maximum number of expressions that can be nested
   within parentheses by the `expr' utility] */
#define    SUT_POSIX2_EXPR_NEST_MAX        32

/* [The maximum length, in bytes, of an input line] */
#define    SUT_POSIX2_LINE_MAX        2048

/* [The maximum number of repeated occurrences of a regular expression
   permitted when using the interval notation `\{M,N\}'] */
#define    SUT_POSIX2_RE_DUP_MAX        255

/* [Maximum number of `iovec' structures that one process has available
   for use with `readv' or writev'] */
#define    SUT_XOPEN_IOV_MAX    16
