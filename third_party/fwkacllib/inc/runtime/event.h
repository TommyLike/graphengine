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

#ifndef __CCE_RUNTIME_EVENT_H__
#define __CCE_RUNTIME_EVENT_H__

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup dvrt_event
 * @brief create event instance
 * @param [in|out] event   created event
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_RESOURCE_HANDLE for error input handle
 */
RTS_API rtError_t rtEventCreate(rtEvent_t *event);

/**
 * @ingroup dvrt_event
 * @brief destroy event instance
 * @param [in] event   event to destroy
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_RESOURCE_HANDLE for error input handle
 */
RTS_API rtError_t rtEventDestroy(rtEvent_t event);

/**
 * @ingroup dvrt_event
 * @brief event record
 * @param [int] event   event to record
 * @param [int] stream   stream handle
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_RESOURCE_HANDLE for error input handle
 */
RTS_API rtError_t rtEventRecord(rtEvent_t event, rtStream_t stream);

/**
 * @ingroup dvrt_event
 * @brief event reset
 * @param [int] event   event to reset
 * @param [int] stream   stream handle
 * @return RT_ERROR_NONE for ok
 */
RTS_API rtError_t rtEventReset(rtEvent_t event, rtStream_t stream);

/**
 * @ingroup dvrt_event
 * @brief wait event to be complete
 * @param [in] event   event to wait
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_RESOURCE_HANDLE for error input handle
 */
RTS_API rtError_t rtEventSynchronize(rtEvent_t event);

/**
 * @ingroup dvrt_event
 * @brief Queries an event's status
 * @param [in] event   event to query
 * @return RT_ERROR_NONE for complete
 * @return RT_ERROR_NOT_READY for not complete
 */
RTS_API rtError_t rtEventQuery(rtEvent_t event);

/**
 * @ingroup dvrt_event
 * @brief computes the elapsed time between events.
 * @param [in] time   time between start and end in ms
 * @param [in] start  starting event
 * @param [in] end  ending event
 * @return RT_ERROR_NONE for ok, errno for failed
 */
RTS_API rtError_t rtEventElapsedTime(float *time, rtEvent_t start, rtEvent_t end);

/**
 * @ingroup dvrt_event
 * @brief get the elapsed time from a event after event recorded.
 * @param [in] time   time in ms
 * @param [in] event  event handle
 * @return RT_ERROR_NONE for ok, errno for failed
 */
RTS_API rtError_t rtEventGetTimeStamp(uint64_t *time, rtEvent_t event);

/**
 * @ingroup dvrt_event
 * @brief name an event
 * @param [in] event_  event to be named
 * @param [in] name  identification name
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input of event, name
 * @return RT_ERROR_DRV_ERR for driver error
 */
RTS_API rtError_t rtNameEvent(rtEvent_t event_, const char *name);

/**
 * @ingroup dvrt_event
 * @brief make event shared interprocess and assigned a name
 * @param [in] event  event to be shared
 * @param [in] name   identification name
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 * @return RT_ERROR_INVALID_RESOURCE_HANDLE for invalid resource handle
 */
RTS_API rtError_t rtIpcSetEventName(rtEvent_t event, char *name, uint32_t len);

/**
 * @ingroup dvrt_event
 * @brief open a interprocess shared event
 * @param [in|out] event    event to be opened
 * @param [in] name   identification name
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input of ptr, name
 * @return RT_ERROR_DRV_ERR for driver error
 */
RTS_API rtError_t rtIpcOpenEvent(rtEvent_t *event, const char *name);

/**
 * @ingroup dvrt_event
 * @brief Create a notify
 * @param [in] device_id  device id
 * @param [in|out] notify_   notify to be created
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 * @return RT_ERROR_INVALID_RESOURCE_HANDLE for invalid resource handle
 */
RTS_API rtError_t rtNotifyCreate(int32_t device_id, rtNotify_t *notify_);

/**
 * @ingroup dvrt_event
 * @brief Destroy a notify
 * @param [in] notify_   notify to be destroyed
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 * @return RT_ERROR_DRV_ERR for driver error
 */
RTS_API rtError_t rtNotifyDestroy(rtNotify_t notify_);

/**
 * @ingroup dvrt_event
 * @brief Record a notify
 * @param [in] notify_ notify to be recorded
 * @param [in] stream_  input stream
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 * @return RT_ERROR_INVALID_RESOURCE_HANDLE for invalid resource handle
 * @return RT_ERROR_INVALID_DEVICE for stream is not in current ctx
 */
RTS_API rtError_t rtNotifyRecord(rtNotify_t notify_, rtStream_t stream_);

/**
 * @ingroup dvrt_event
 * @brief Wait for a notify
 * @param [in] notify_ notify to be wait
 * @param [in] stream_  input stream
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 * @return RT_ERROR_INVALID_RESOURCE_HANDLE for invalid resource handle
 * @return RT_ERROR_INVALID_DEVICE for stream is not in current ctx
 */
RTS_API rtError_t rtNotifyWait(rtNotify_t notify_, rtStream_t stream_);

/**
 * @ingroup dvrt_event
 * @brief Name a notify
 * @param [in] notify_ notify to be named
 * @param [in|out] name   identification name
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 */
RTS_API rtError_t rtNameNotify(rtNotify_t notify_, const char *name);

/**
 * @ingroup dvrt_event
 * @brief get notify id
 * @param [in] notify_ notify to be get
 * @param [in|out] notify_id   notify id
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 */
RTS_API rtError_t rtGetNotifyID(rtNotify_t notify_, uint32_t *notify_id);

/**
 * @ingroup dvrt_event
 * @brief Set a notify to IPC notify
 * @param [in] notify_ notify to be set to IPC notify
 * @param [in] name   identification name
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input of
 */
RTS_API rtError_t rtIpcSetNotifyName(rtNotify_t notify, char *name, uint32_t len);

/**
 * @ingroup dvrt_event
 * @brief Open IPC notify
 * @param [in] notify notify to be opened
 * @param [in] name   identification name
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 * @return RT_ERROR_INVALID_RESOURCE_HANDLE for invalid resource handle
 */
RTS_API rtError_t rtIpcOpenNotify(rtNotify_t *notify, const char *name);

/**
 * @ingroup dvrt_event
 * @brief Get the physical address corresponding to notify
 * @param [in] notify notify to be queried
 * @param [in] devAddrOffset  device physical address offset
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 * @return RT_ERROR_DRV_ERR for driver error
 */
RTS_API rtError_t rtNotifyGetAddrOffset(rtNotify_t notify, uint64_t *devAddrOffset);

/**
 * @ingroup dvrt_event
 * @brief Ipc set notify pid
 * @param [in] name name to be queried
 * @param [in] pid  process id
 * @param [in] num  length of pid[]
 * @return RT_ERROR_NONE for ok
 * @return RT_ERROR_INVALID_VALUE for error input
 * @return RT_ERROR_DRV_ERR for driver error
 */
RTS_API rtError_t rtSetIpcNotifyPid(const char *name, int32_t pid[], int num);

#ifdef __cplusplus
}
#endif

#endif  // __CCE_RUNTIME_EVENT_H__
