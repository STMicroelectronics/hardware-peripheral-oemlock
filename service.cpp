/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "android.hardware.oemlock@1.0-service.stm32mpu"

#include <hidl/HidlTransportSupport.h>
#include "OemLock.h"

using android::sp;

// libhwbinder:
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

// Generated HIDL files
using android::hardware::oemlock::V1_0::IOemLock;
using android::hardware::oemlock::V1_0::implementation::OemLock;

using android::OK;
using android::status_t;

int main() {
  android::sp<IOemLock> service = new OemLock();

  configureRpcThreadpool(1, true /*callerWillJoin*/);
  status_t status = service->registerAsService();

  if (status != OK) {
    ALOGE("Cannot register OemLock HAL service");
    return 1;
  }

  ALOGI("OemLock HAL Ready.");
  joinRpcThreadpool();
  // Under noraml cases, execution will not reach this line.
  ALOGI("OemLock HAL failed to join thread pool.");
  return 1;
}
