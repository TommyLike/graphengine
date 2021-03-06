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

 #ifndef GE_OP_CLIP_BOXES_H
 #define GE_OP_CLIP_BOXES_H

 #include "graph/operator_reg.h"

 namespace ge {


 REG_OP(ClipBoxes)
     .INPUT(boxes_input, TensorType({DT_FLOAT16}))
     .OUTPUT(boxes_output, TensorType({DT_FLOAT16}))
     .REQUIRED_ATTR(img_w, Float)
     .REQUIRED_ATTR(img_h, Float)
     .OP_END_FACTORY_REG(ClipBoxes)

 } // namespace ge

 #endif // GE_OP_CLIP_BOXES_H
