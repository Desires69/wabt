/*
 * Copyright 2016 WebAssembly Community Group participants
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

#ifndef WASM_BINARY_READER_OBJDUMP_H_
#define WASM_BINARY_READER_OBJDUMP_H_

#include "common.h"
#include "stream.h"
#include "vector.h"

struct WasmAllocator;
struct WasmModule;
struct WasmReadBinaryOptions;

typedef struct WasmReloc {
  WasmRelocType type;
  size_t offset;
} WasmReloc;
WASM_DEFINE_VECTOR(reloc, WasmReloc);

WASM_DEFINE_VECTOR(string_slice, WasmStringSlice);

typedef enum WasmObjdumpMode {
  WASM_DUMP_PREPASS,
  WASM_DUMP_HEADERS,
  WASM_DUMP_DETAILS,
  WASM_DUMP_DISASSEMBLE,
  WASM_DUMP_RAW_DATA,
} WasmObjdumpMode;

typedef struct WasmObjdumpOptions {
  WasmBool headers;
  WasmBool details;
  WasmBool raw;
  WasmBool disassemble;
  WasmBool debug;
  WasmBool relocs;
  WasmObjdumpMode mode;
  const char* infile;
  const char* section_name;
  WasmBool print_header;
  WasmStringSliceVector function_names;
  WasmRelocVector code_relocations;
} WasmObjdumpOptions;

WASM_EXTERN_C_BEGIN

WasmResult wasm_read_binary_objdump(struct WasmAllocator* allocator,
                                    const uint8_t* data,
                                    size_t size,
                                    WasmObjdumpOptions* options);

WASM_EXTERN_C_END

#endif /* WASM_BINARY_READER_OBJDUMP_H_ */
