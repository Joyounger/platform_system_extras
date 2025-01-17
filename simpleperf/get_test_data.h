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

#ifndef SIMPLE_PERF_GET_TEST_DATA_H_
#define SIMPLE_PERF_GET_TEST_DATA_H_

#include <string>

#include "build_id.h"

std::string GetTestData(const std::string& filename);
const std::string& GetTestDataDir();

// The source code of elf and elf_with_mini_debug_info is testdata/elf_file_source.cpp.
static const std::string ELF_FILE = "elf";
static const std::string ELF_FILE_WITH_MINI_DEBUG_INFO = "elf_with_mini_debug_info";
// perf.data is generated by sampling on three processes running different
// executables: elf, t1, t2 (all generated by elf_file_source.cpp, but with different
// executable name).
static const std::string PERF_DATA = "perf.data";

// perf_with_multiple_pids_and_tids.data is generated by sampling on two processes, each
// process running two threads.
static const std::string PERF_DATA_WITH_MULTIPLE_PIDS_AND_TIDS = "perf_with_multiple_pids_and_tids.data";

// perf_g_fp.data is generated by sampling on one process running elf using --call-graph fp option.
static const std::string CALLGRAPH_FP_PERF_DATA = "perf_g_fp.data";
// perf_b.data is generated by sampling on one process running elf using -b option.
static const std::string BRANCH_PERF_DATA = "perf_b.data";
// perf_with_mini_debug_info.data is generated by sampling on one process running
// elf_with_mini_debug_info.
static const std::string PERF_DATA_WITH_MINI_DEBUG_INFO = "perf_with_mini_debug_info.data";

static BuildId elf_file_build_id("0b12a384a9f4a3f3659b7171ca615dbec3a81f71");


// To generate apk supporting execution on shared libraries in apk:
// 1. Add android:extractNativeLibs=false in AndroidManifest.xml.
// 2. Use `zip -0` to store native libraries in apk without compression.
// 3. Use `zipalign -p 4096` to make native libraries in apk start at page boundaries.
//
// The logical in libhello-jni.so is as below:
//  volatile int GlobalVar;
//
//  while (true) {
//    GlobalFunc() -> Func1() -> Func2()
//  }
// And most time is spent in Func2().
static const std::string APK_FILE = "data/app/com.example.hellojni-1/base.apk";
static const std::string NATIVELIB_IN_APK = "lib/arm64-v8a/libhello-jni.so";
// has_embedded_native_libs_apk_perf.data is generated by sampling on one process running
// APK_FILE using -g --no-unwind option.
static const std::string NATIVELIB_IN_APK_PERF_DATA = "has_embedded_native_libs_apk_perf.data";
// The offset and size info are extracted from the generated apk file to run read_apk tests.
constexpr size_t NATIVELIB_OFFSET_IN_APK = 0x639000;
constexpr size_t NATIVELIB_SIZE_IN_APK = 0x1678;

static BuildId native_lib_build_id("8ed5755a7fdc07586ca228b8ee21621bce2c7a97");

// perf_with_two_event_types.data is generated by sampling using -e cpu-cycles,cpu-clock option.
static const std::string PERF_DATA_WITH_TWO_EVENT_TYPES = "perf_with_two_event_types.data";

// perf_with_kernel_symbol.data is generated by `sudo simpleperf record ls -l`.
static const std::string PERF_DATA_WITH_KERNEL_SYMBOL = "perf_with_kernel_symbol.data";

// perf_with_symbols.data is generated by `sudo simpleperf record` a process calling func2(int,int).
static const std::string PERF_DATA_WITH_SYMBOLS = "perf_with_symbols.data";
// perf_with_symbols.data is generated by `sudo simpleperf record` a process using
// a binary having non zero min virtual address.
static const std::string PERF_DATA_WITH_SYMBOLS_FOR_NONZERO_MINVADDR_DSO =
    "perf_with_symbols_for_nonzero_minvaddr_dso.data";

// perf_kmem_slab_callgraph.data is generated by `simpleperf kmem record --slab --call-graph fp -f 100 sleep 0.0001`.
static const std::string PERF_DATA_WITH_KMEM_SLAB_CALLGRAPH_RECORD = "perf_with_kmem_slab_callgraph.data";


// perf_for_build_id_check.data is generated by recording a process running
// testdata/data/correct_symfs_for_build_id_check/elf_for_build_id_check.
static const std::string PERF_DATA_FOR_BUILD_ID_CHECK = "perf_for_build_id_check.data";
static const std::string CORRECT_SYMFS_FOR_BUILD_ID_CHECK = "data/correct_symfs_for_build_id_check";
static const std::string WRONG_SYMFS_FOR_BUILD_ID_CHECK = "data/wrong_symfs_for_build_id_check";

static const std::string SYMFS_FOR_NO_SYMBOL_TABLE_WARNING = "data/symfs_for_no_symbol_table_warning";
static const std::string SYMFS_FOR_READ_ELF_FILE_WARNING = "data/symfs_for_read_elf_file_warning";

// generated_by_linux_perf.data is generated by `perf record -F 1 -a -g -- sleep 0.1`.
static const std::string PERF_DATA_GENERATED_BY_LINUX_PERF = "generated_by_linux_perf.data";

// generated by `simpleperf record -g ls`.
static const std::string PERF_DATA_MAX_STACK_AND_PERCENT_LIMIT = "perf_test_max_stack_and_percent_limit.data";

// generated by `dd if=/dev/zero of=invalid_perf.data bs=1024 count=1`.
static const std::string INVALID_PERF_DATA = "invalid_perf.data";

// generated by recording an app.
static const std::string PERF_DATA_WITH_WRONG_IP_IN_CALLCHAIN = "wrong_ip_callchain_perf.data";

// generated by `simpleperf record --trace-offcpu --duration 2 -g ./simpleperf_runtest_run_and_sleep64`.
static const std::string PERF_DATA_WITH_TRACE_OFFCPU = "perf_with_trace_offcpu.data";

// generated by `simpleperf record -g --log debug sleep 1`.
static const std::string PERF_DATA_WITH_CALLCHAIN_RECORD = "perf_with_callchain_record.data";

#endif  // SIMPLE_PERF_GET_TEST_DATA_H_
