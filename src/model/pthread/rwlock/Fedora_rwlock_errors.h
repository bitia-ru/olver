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
// Possible error constant values for Fedora Core 4 (2.6.11-1.1369_FC4)

#define POSIX_RWLOCK_RDLOCK_DETECTS_WRITE_DEADLOCK 1
#define POSIX_RWLOCK_WRLOCK_DETECTS_READ_DEADLOCK 0
#define POSIX_RWLOCK_WRLOCK_DETECTS_WRITE_DEADLOCK 1
#define POSIX_RWLOCK_DESTROY_FAILS_ON_EBUSY 0
#define POSIX_RWLOCK_DESTROY_FAILS_ON_EINVAL 0
#define POSIX_RWLOCK_INIT_FAILS_ON_EBUSY 0
#define POSIX_RWLOCK_INIT_FAILS_ON_EINVAL 0
#define POSIX_RWLOCK_RDLOCK_FAILS_ON_EINVAL 0
#define POSIX_RWLOCK_WRLOCK_FAILS_ON_EINVAL 0
#define POSIX_RWLOCK_TIMEDRDLOCK_FAILS_ON_EINVAL_BAD_RWLOCK 0
#define POSIX_RWLOCK_TIMEDRDLOCK_FAILS_ON_EINVAL_BAD_TIMEOUT_FREE_LOCK 0
#define POSIX_RWLOCK_TIMEDRDLOCK_FAILS_ON_EINVAL_BAD_TIMEOUT_BUSY_LOCK 1
#define POSIX_RWLOCK_TIMEDRDLOCK_DETECTS_WRITE_DEADLOCK 1
#define POSIX_RWLOCK_TIMEDWRLOCK_FAILS_ON_EINVAL_BAD_RWLOCK 0
#define POSIX_RWLOCK_TIMEDWRLOCK_FAILS_ON_EINVAL_BAD_TIMEOUT_FREE_LOCK 0
#define POSIX_RWLOCK_TIMEDWRLOCK_FAILS_ON_EINVAL_BAD_TIMEOUT_BUSY_LOCK 1
#define POSIX_RWLOCK_TIMEDWRLOCK_DETECTS_READ_DEADLOCK 0
#define POSIX_RWLOCK_TIMEDWRLOCK_DETECTS_WRITE_DEADLOCK 1
#define POSIX_RWLOCK_UNLOCK_FAILS_ON_EINVAL 0
#define POSIX_RWLOCK_UNLOCK_FAILS_ON_EPERM 0
