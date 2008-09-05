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

#define SUT_PC_LINK_MAX            0
#define SUT_PC_MAX_CANON           1
#define SUT_PC_MAX_INPUT           2
#define SUT_PC_NAME_MAX            3
#define SUT_PC_PATH_MAX            4
#define SUT_PC_PIPE_BUF            5
#define SUT_PC_CHOWN_RESTRICTED    6
#define SUT_PC_NO_TRUNC            7
#define SUT_PC_VDISABLE            8
#define SUT_PC_SYNC_IO             9
#define SUT_PC_ASYNC_IO            10
#define SUT_PC_PRIO_IO             11
/* #define SUT_PC_SOCK_MAXBUF         12 /**/
#define SUT_PC_FILESIZEBITS        13
#define SUT_PC_REC_INCR_XFER_SIZE  14
#define SUT_PC_REC_MAX_XFER_SIZE   15
#define SUT_PC_REC_MIN_XFER_SIZE   16
#define SUT_PC_REC_XFER_ALIGN      17
#define SUT_PC_ALLOC_SIZE_MIN      18
#define SUT_PC_SYMLINK_MAX         19
#define SUT_PC_2_SYMLINKS          20


/* Values for the argument to `confstr'.  */
#define SUT_CS_PATH 0
#define SUT_CS_V6_WIDTH_RESTRICTED_ENVS 1
#define SUT_CS_GNU_LIBC_VERSION 2
#define SUT_CS_GNU_LIBPTHREAD_VERSION 3

#define SUT_CS_LFS_CFLAGS 1000
#define SUT_CS_LFS_LDFLAGS 1001
#define SUT_CS_LFS_LIBS 1002
#define SUT_CS_LFS_LINTFLAGS 1003
#define SUT_CS_LFS64_CFLAGS 1004
#define SUT_CS_LFS64_LDFLAGS 1005
#define SUT_CS_LFS64_LIBS 1006
#define SUT_CS_LFS64_LINTFLAGS 1007

#define SUT_CS_XBS5_ILP32_OFF32_CFLAGS 1100
#define SUT_CS_XBS5_ILP32_OFF32_LDFLAGS 1101
#define SUT_CS_XBS5_ILP32_OFF32_LIBS 1102
#define SUT_CS_XBS5_ILP32_OFF32_LINTFLAGS 1103
#define SUT_CS_XBS5_ILP32_OFFBIG_CFLAGS 1104
#define SUT_CS_XBS5_ILP32_OFFBIG_LDFLAGS 1105
#define SUT_CS_XBS5_ILP32_OFFBIG_LIBS 1106
#define SUT_CS_XBS5_ILP32_OFFBIG_LINTFLAGS 1107
#define SUT_CS_XBS5_LP64_OFF64_CFLAGS 1108
#define SUT_CS_XBS5_LP64_OFF64_LDFLAGS 1109
#define SUT_CS_XBS5_LP64_OFF64_LIBS 1110
#define SUT_CS_XBS5_LP64_OFF64_LINTFLAGS 1111
#define SUT_CS_XBS5_LPBIG_OFFBIG_CFLAGS 1112
#define SUT_CS_XBS5_LPBIG_OFFBIG_LDFLAGS 1113
#define SUT_CS_XBS5_LPBIG_OFFBIG_LIBS 1114
#define SUT_CS_XBS5_LPBIG_OFFBIG_LINTFLAGS 1115

#define SUT_CS_POSIX_V6_ILP32_OFF32_CFLAGS 1116
#define SUT_CS_POSIX_V6_ILP32_OFF32_LDFLAGS 1117
#define SUT_CS_POSIX_V6_ILP32_OFF32_LIBS 1118
#define SUT_CS_POSIX_V6_ILP32_OFF32_LINTFLAGS 1119
#define SUT_CS_POSIX_V6_ILP32_OFFBIG_CFLAGS 1120
#define SUT_CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS 1121
#define SUT_CS_POSIX_V6_ILP32_OFFBIG_LIBS 1122
#define SUT_CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS 1123
#define SUT_CS_POSIX_V6_LP64_OFF64_CFLAGS 1124
#define SUT_CS_POSIX_V6_LP64_OFF64_LDFLAGS 1125
#define SUT_CS_POSIX_V6_LP64_OFF64_LIBS 1126
#define SUT_CS_POSIX_V6_LP64_OFF64_LINTFLAGS 1127
#define SUT_CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS 1128
#define SUT_CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS 1129
#define SUT_CS_POSIX_V6_LPBIG_OFFBIG_LIBS 1130
#define SUT_CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS 1131
