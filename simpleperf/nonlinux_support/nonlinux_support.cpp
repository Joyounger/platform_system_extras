/*
 * Copyright (C) 2015 The Android Open Source Project
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

// Add fake functions to build successfully on darwin.
#include <android-base/logging.h>

#include "environment.h"
#include "OfflineUnwinder.h"

namespace simpleperf {
bool OfflineUnwinder::UnwindCallChain(int, const ThreadEntry&, const RegSet&, const char*, size_t,
                     std::vector<uint64_t>*, std::vector<uint64_t>*) {
  return false;
}
}  // namespace simpleperf

bool GetKernelBuildId(BuildId*) {
  return false;
}

bool CanRecordRawData() {
  return false;
}
