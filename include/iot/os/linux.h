//
// Copyright (c) 2020 IOTech Ltd
//
// SPDX-License-Identifier: Apache-2.0
//

#ifndef _IOT_OS_LINUX_H_
#define _IOT_OS_LINUX_H_

/**
 * @file
 * @brief IOTech Linux API
 */

#include <sched.h>
#include <unistd.h>

#ifndef _REDHAT_SEAWOLF_
#ifndef __LIBMUSL__
#define IOT_HAS_CPU_AFFINITY
#define IOT_HAS_PTHREAD_MUTEXATTR_SETPROTOCOL
#endif
#define IOT_HAS_PR_GET_NAME
#endif

#endif
