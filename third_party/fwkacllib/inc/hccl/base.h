/**
 * Copyright 2019-2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __HCCL_BASE_H__
#define __HCCL_BASE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef enum tagHcclResult {
  HCCL_SUCCESS = 0,              /**< success */
  HCCL_E_PARA = 1,               /**< parameter error */
  HCCL_E_PTR = 2,                /**< empty pointer */
  HCCL_E_MEMORY = 3,             /**< memory error */
  HCCL_E_INTERNAL = 4,           /**< internal error */
  HCCL_E_NOT_SUPPORT = 5,        /**< not support feature */
  HCCL_E_NOT_FOUND = 6,          /**< not found specific resource */
  HCCL_E_UNAVAIL = 7,            /**< resource unavailable */
  HCCL_E_SYSCALL = 8,            /**< call system interface error */
  HCCL_E_TIMEOUT = 9,            /**< timeout */
  HCCL_E_OPEN_FILE_FAILURE = 10, /**< open file fail */
  HCCL_E_TCP_CONNECT = 11,       /**< tcp connect fail */
  HCCL_E_ROCE_CONNECT = 12,      /**< roce connect fail */
  HCCL_E_TCP_TRANSFER = 13,      /**< tcp transfer fail */
  HCCL_E_ROCE_TRANSFER = 14,     /**< roce transfer fail */
  HCCL_E_RUNTIME = 15,           /**< call runtime api fail */
  HCCL_E_DRV = 16,               /**< call driver api fail */
  HCCL_E_PROFILING = 17,         /**< call profiling api fail */
  HCCL_E_CCE = 18,               /**< call cce api fail */
  HCCL_E_NETWORK = 19,           /**< call network api fail */
  HCCL_E_RESERVED                /**< reserved */
} hcclResult_t;

/* handle to communicator */
typedef void *hcclComm_t;

typedef enum tagHcclRedOp {
  HCCL_REP_OP_SUM = 0,  /**< sum */
  HCCL_REP_OP_PROD = 1, /**< prod */
  HCCL_REP_OP_MAX = 2,  /**< max */
  HCCL_REP_OP_MIN = 3,  /**< min */
  HCCL_REP_OP_RESERVED  /**< reserved */
} hcclRedOp_t;

typedef enum tagHcclDataType {
  HCCL_DATA_TYPE_INT8 = 0,  /**< int8 */
  HCCL_DATA_TYPE_INT = 1,   /**< int32 */
  HCCL_DATA_TYPE_HALF = 2,  /**< fp16 */
  HCCL_DATA_TYPE_FLOAT = 3, /**< fp32 */
  HCCL_DATA_TYPE_RESERVED   /**< reserved */
} hcclDataType_t;

const s32 HCCL_TAG_ANY = -1;
const u32 BASE_UNIQUE_ID_BYTES = 27;
#define HCCL_UNIQUE_ID_BYTES (BASE_UNIQUE_ID_BYTES + 5 + 16 + 128)
typedef struct {
  char internal[HCCL_UNIQUE_ID_BYTES];
} hcclUniqueId;

const u32 HCCL_MAX_SEGMENT_NUM = 8;

struct model_feature {
  const char *model_name;
  u32 gradient_num;
  float *gradient_size;
  float *gradient_time;
};

/**
 * @brief stream handle.
 */
typedef void *rtStream_t;

/**
 * @brief model handle.
 */
typedef void *rtModel_t;
#ifdef __cplusplus
}
#endif

#endif  // __HCCL_BASE_H__
