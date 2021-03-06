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

#ifndef __AICPU_TASK_STRUCT_H__
#define __AICPU_TASK_STRUCT_H__

#include <cstdint>

namespace aicpu {

struct AicpuParamHead {
  uint32_t length;     // Total length: include cunstom message
  uint32_t ioAddrNum;  // Input and output address number
} __attribute__((packed));

}  // end  namespace aicpu
#endif  //__AICPU_TASK_STRUCT_H__
