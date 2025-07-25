/*
 * Copyright (c) 2025 EdgeImpulse Inc.
 *
 * Generated by Edge Impulse and licensed under the applicable Edge Impulse
 * Terms of Service. Community and Professional Terms of Service
 * (https://edgeimpulse.com/legal/terms-of-service) or Enterprise Terms of
 * Service (https://edgeimpulse.com/legal/enterprise-terms-of-service),
 * according to your product plan subscription (the “License”).
 *
 * This software, documentation and other associated files (collectively referred
 * to as the “Software”) is a single SDK variation generated by the Edge Impulse
 * platform and requires an active paid Edge Impulse subscription to use this
 * Software for any purpose.
 *
 * You may NOT use this Software unless you have an active Edge Impulse subscription
 * that meets the eligibility requirements for the applicable License, subject to
 * your full and continued compliance with the terms and conditions of the License,
 * including without limitation any usage restrictions under the applicable License.
 *
 * If you do not have an active Edge Impulse product plan subscription, or if use
 * of this Software exceeds the usage limitations of your Edge Impulse product plan
 * subscription, you are not permitted to use this Software and must immediately
 * delete and erase all copies of this Software within your control or possession.
 * Edge Impulse reserves all rights and remedies available to enforce its rights.
 *
 * Unless required by applicable law or agreed to in writing, the Software is
 * distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing
 * permissions, disclaimers and limitations under the License.
 */
// Generated on: 05.06.2025 23:46:52

#include <stdio.h>
#include <stdlib.h>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)

#if defined (__GNUC__)  /* GNU compiler */
#define ALIGN(X) __attribute__((aligned(X)))
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (_MSC_VER)
#define ALIGN(X) __declspec(align(X))
#elif defined (__TASKING__) /* TASKING Compiler */
#define ALIGN(X) __align(X)
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (__ARMCC_VERSION) /* Arm Compiler */
#define ALIGN(X) __ALIGNED(x)
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (__ICCARM__) /* IAR Compiler */
#define ALIGN(x) __attribute__((aligned(x)))
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (__clang__) /* LLVM/Clang Compiler */
#define ALIGN(X) __ALIGNED(x)
#define DEFINE_SECTION(x) __attribute__((section(x)))
#endif

#if defined(EI_MODEL_SECTION) && (defined(__GNUC__) || defined(__clang__))
#define MODEL_SECTION(X) __attribute__((section(STRINGIZE_VALUE_OF(X))))
#else
#define MODEL_SECTION(X)
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#ifndef CONFIG_IDF_TARGET_ESP32S3
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#else
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#endif // CONFIG_IDF_TARGET_ESP32S3
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace tflite {
namespace ops {
namespace micro {
}  // namespace micro
}  // namespace ops
}  // namespace tflite

namespace {

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX) || defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
constexpr int kTensorArenaSize = 1360;
#else
constexpr int kTensorArenaSize = 336;
#endif

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
#if defined (EI_TENSOR_ARENA_LOCATION)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) DEFINE_SECTION(STRINGIZE_VALUE_OF(EI_TENSOR_ARENA_LOCATION));
#else
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#endif
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};

enum used_operators_e {
  OP_TreeEnsembleClassifier, OP_NEG, OP_EXP, OP_RESHAPE, OP_ADD, OP_DIV, OP_SUB, OP_CONCATENATION,  OP_LAST
};

struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
};

typedef struct {
  TfLiteTensor tensor;
  int16_t index;
} TfLiteTensorWithIndex;

typedef struct {
  TfLiteEvalTensor tensor;
  int16_t index;
} TfLiteEvalTensorWithIndex;

TfLiteContext ctx{};
static const int MAX_TFL_TENSOR_COUNT = 3;
static TfLiteTensorWithIndex tflTensors[MAX_TFL_TENSOR_COUNT];
static const int MAX_TFL_EVAL_COUNT = 3;
static TfLiteEvalTensorWithIndex tflEvalTensors[MAX_TFL_EVAL_COUNT];
TfLiteRegistration registrations[OP_LAST];

namespace g0 {
const TfArray<2, int> tensor_dimension0 = { 2, { 1,8 } };
const MODEL_SECTION(EI_MODEL_SECTION) ALIGN(8) int32_t tensor_data1[2] = { 1, 2, };
const TfArray<1, int> tensor_dimension1 = { 1, { 2 } };
const MODEL_SECTION(EI_MODEL_SECTION) ALIGN(8) int32_t tensor_data2[2] = { 1, 1, };
const float tensor_data3[1] = { 1 };
const int tensor_dimension3 = 0; /* empty TfLiteIntArray */
const TfArray<2, int> tensor_dimension4 = { 2, { 1,1 } };
const TfArray<2, int> tensor_dimension11 = { 2, { 2,1 } };
const TfArray<2, int> tensor_dimension12 = { 2, { 1,2 } };
const uint8_t ALIGN(4) opdata0[2449] = { 118, 101, 114, 115, 105, 111, 110, 0, 116, 114, 101, 101, 95, 105, 110, 100, 101, 120, 95, 116, 121, 112, 101, 0, 6, 117, 105, 110, 116, 49, 54, 0, 99, 108, 97, 115, 115, 95, 105, 110, 100, 101, 120, 95, 116, 121, 112, 101, 0, 5, 117, 105, 110, 116, 56, 0, 110, 111, 100, 101, 95, 118, 97, 108, 117, 101, 95, 116, 121, 112, 101, 0, 7, 102, 108, 111, 97, 116, 51, 50, 0, 101, 113, 117, 97, 108, 105, 116, 121, 95, 111, 112, 101, 114, 97, 116, 111, 114, 0, 3, 108, 101, 113, 0, 110, 117, 109, 95, 108, 101, 97, 102, 95, 110, 111, 100, 101, 115, 0, 110, 117, 109, 95, 105, 110, 116, 101, 114, 110, 97, 108, 95, 110, 111, 100, 101, 115, 0, 110, 117, 109, 95, 116, 114, 101, 101, 115, 0, 99, 108, 97, 115, 115, 95, 119, 101, 105, 103, 104, 116, 95, 116, 121, 112, 101, 0, 7, 102, 108, 111, 97, 116, 51, 50, 0, 110, 111, 100, 101, 115, 95, 102, 101, 97, 116, 117, 114, 101, 105, 100, 115, 0, 133, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 6, 0, 6, 0, 1, 0, 4, 0, 4, 0, 2, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 2, 0, 6, 0, 6, 0, 4, 0, 3, 0, 0, 0, 4, 0, 4, 0, 2, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 2, 0, 6, 0, 6, 0, 4, 0, 3, 0, 0, 0, 5, 0, 4, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 2, 0, 7, 0, 0, 0, 1, 0, 1, 0, 6, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 4, 0, 4, 0, 6, 0, 0, 0, 0, 0, 2, 0, 1, 0, 1, 0, 3, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 0, 5, 0, 6, 0, 1, 0, 3, 0, 0, 0, 4, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 0, 5, 0, 6, 0, 1, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 2, 0, 2, 0, 6, 0, 4, 0, 3, 0, 4, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 6, 0, 0, 0, 110, 111, 100, 101, 115, 95, 118, 97, 108, 117, 101, 115, 0, 133, 38, 77, 13, 76, 158, 133, 20, 74, 227, 94, 17, 74, 190, 31, 4, 74, 162, 206, 170, 75, 232, 238, 104, 74, 94, 168, 76, 74, 72, 60, 212, 73, 212, 159, 94, 75, 15, 118, 85, 74, 86, 218, 174, 75, 174, 185, 233, 75, 134, 231, 241, 75, 180, 14, 23, 76, 180, 254, 43, 76, 38, 77, 13, 76, 246, 76, 199, 73, 162, 206, 170, 75, 232, 238, 104, 74, 94, 154, 75, 74, 241, 244, 224, 73, 52, 56, 8, 75, 212, 159, 94, 75, 15, 118, 85, 74, 86, 218, 174, 75, 174, 185, 233, 75, 134, 231, 241, 75, 180, 14, 23, 76, 180, 254, 43, 76, 38, 77, 13, 76, 246, 76, 199, 73, 162, 206, 170, 75, 232, 238, 104, 74, 94, 154, 75, 74, 241, 244, 224, 73, 52, 56, 8, 75, 213, 243, 111, 75, 15, 118, 85, 74, 54, 119, 186, 75, 174, 185, 233, 75, 134, 231, 241, 75, 180, 14, 23, 76, 180, 254, 43, 76, 38, 77, 13, 76, 246, 76, 199, 73, 158, 189, 185, 75, 32, 147, 206, 75, 171, 106, 108, 75, 158, 184, 145, 74, 180, 14, 23, 76, 180, 254, 43, 76, 38, 77, 13, 76, 56, 248, 202, 73, 128, 215, 202, 75, 32, 147, 206, 75, 250, 94, 72, 75, 158, 184, 145, 74, 171, 106, 108, 75, 104, 226, 3, 76, 180, 14, 23, 76, 180, 254, 43, 76, 38, 77, 13, 76, 246, 76, 199, 73, 30, 123, 95, 74, 56, 248, 202, 73, 241, 244, 224, 73, 213, 165, 242, 73, 154, 134, 131, 74, 54, 78, 142, 74, 255, 82, 1, 75, 195, 33, 108, 74, 212, 159, 94, 75, 128, 215, 202, 75, 180, 14, 23, 76, 180, 254, 43, 76, 32, 147, 206, 75, 246, 76, 199, 73, 250, 94, 72, 75, 158, 184, 145, 74, 30, 123, 95, 74, 56, 248, 202, 73, 38, 252, 3, 74, 86, 210, 153, 75, 171, 106, 108, 75, 180, 14, 163, 75, 57, 136, 0, 76, 38, 77, 13, 76, 180, 14, 23, 76, 180, 254, 43, 76, 32, 147, 206, 75, 56, 248, 202, 73, 30, 123, 95, 74, 177, 107, 64, 74, 162, 140, 37, 74, 208, 159, 13, 74, 171, 106, 108, 75, 54, 78, 142, 74, 255, 82, 1, 75, 245, 106, 164, 75, 57, 136, 0, 76, 38, 77, 13, 76, 180, 14, 23, 76, 180, 254, 43, 76, 32, 147, 206, 75, 56, 248, 202, 73, 30, 123, 95, 74, 177, 107, 64, 74, 162, 140, 37, 74, 208, 159, 13, 74, 250, 94, 72, 75, 54, 78, 142, 74, 255, 82, 1, 75, 86, 210, 153, 75, 54, 119, 186, 75, 16, 170, 199, 75, 57, 136, 0, 76, 38, 77, 13, 76, 180, 14, 23, 76, 180, 254, 43, 76, 32, 147, 206, 75, 246, 76, 199, 73, 125, 20, 168, 74, 232, 238, 104, 74, 94, 154, 75, 74, 241, 244, 224, 73, 186, 211, 131, 75, 255, 82, 1, 75, 250, 94, 72, 75, 65, 55, 1, 76, 57, 136, 0, 76, 38, 77, 13, 76, 180, 14, 23, 76, 180, 254, 43, 76, 110, 111, 100, 101, 115, 95, 116, 114, 117, 101, 110, 111, 100, 101, 105, 100, 115, 0, 133, 1, 0, 2, 0, 133, 0, 134, 0, 5, 0, 6, 0, 7, 0, 136, 0, 9, 0, 139, 0, 141, 0, 143, 0, 144, 0, 14, 0, 146, 0, 16, 0, 149, 0, 18, 0, 19, 0, 20, 0, 150, 0, 152, 0, 23, 0, 154, 0, 156, 0, 158, 0, 159, 0, 28, 0, 161, 0, 30, 0, 164, 0, 32, 0, 33, 0, 34, 0, 165, 0, 167, 0, 37, 0, 169, 0, 171, 0, 173, 0, 174, 0, 42, 0, 176, 0, 44, 0, 179, 0, 46, 0, 47, 0, 48, 0, 180, 0, 50, 0, 185, 0, 52, 0, 188, 0, 54, 0, 55, 0, 56, 0, 189, 0, 191, 0, 193, 0, 60, 0, 196, 0, 62, 0, 199, 0, 64, 0, 200, 0, 66, 0, 201, 0, 203, 0, 69, 0, 70, 0, 205, 0, 208, 0, 209, 0, 74, 0, 211, 0, 76, 0, 214, 0, 78, 0, 79, 0, 80, 0, 215, 0, 217, 0, 219, 0, 84, 0, 221, 0, 224, 0, 225, 0, 88, 0, 226, 0, 90, 0, 229, 0, 92, 0, 93, 0, 94, 0, 230, 0, 96, 0, 97, 0, 234, 0, 236, 0, 239, 0, 240, 0, 102, 0, 241, 0, 104, 0, 244, 0, 106, 0, 107, 0, 108, 0, 245, 0, 110, 0, 111, 0, 249, 0, 251, 0, 253, 0, 254, 0, 0, 1, 1, 1, 118, 0, 2, 1, 120, 0, 5, 1, 122, 0, 123, 0, 124, 0, 6, 1, 126, 0, 10, 1, 11, 1, 13, 1, 15, 1, 16, 1, 132, 0, 17, 1, 110, 111, 100, 101, 115, 95, 102, 97, 108, 115, 101, 110, 111, 100, 101, 105, 100, 115, 0, 133, 13, 0, 4, 0, 3, 0, 135, 0, 11, 0, 8, 0, 138, 0, 137, 0, 10, 0, 140, 0, 142, 0, 12, 0, 145, 0, 148, 0, 147, 0, 27, 0, 17, 0, 25, 0, 22, 0, 21, 0, 151, 0, 153, 0, 24, 0, 155, 0, 157, 0, 26, 0, 160, 0, 163, 0, 162, 0, 41, 0, 31, 0, 39, 0, 36, 0, 35, 0, 166, 0, 168, 0, 38, 0, 170, 0, 172, 0, 40, 0, 175, 0, 178, 0, 177, 0, 49, 0, 45, 0, 184, 0, 183, 0, 182, 0, 181, 0, 187, 0, 186, 0, 59, 0, 53, 0, 195, 0, 58, 0, 57, 0, 190, 0, 192, 0, 194, 0, 198, 0, 197, 0, 73, 0, 63, 0, 68, 0, 65, 0, 67, 0, 202, 0, 204, 0, 71, 0, 207, 0, 206, 0, 72, 0, 210, 0, 213, 0, 212, 0, 85, 0, 77, 0, 83, 0, 82, 0, 81, 0, 216, 0, 218, 0, 220, 0, 223, 0, 222, 0, 86, 0, 87, 0, 228, 0, 227, 0, 99, 0, 91, 0, 95, 0, 233, 0, 232, 0, 231, 0, 238, 0, 98, 0, 235, 0, 237, 0, 100, 0, 101, 0, 243, 0, 242, 0, 115, 0, 105, 0, 109, 0, 248, 0, 247, 0, 246, 0, 113, 0, 112, 0, 250, 0, 252, 0, 114, 0, 255, 0, 116, 0, 117, 0, 4, 1, 3, 1, 129, 0, 121, 0, 125, 0, 9, 1, 8, 1, 7, 1, 128, 0, 127, 0, 12, 1, 14, 1, 130, 0, 131, 0, 19, 1, 18, 1, 110, 111, 100, 101, 115, 95, 119, 101, 105, 103, 104, 116, 115, 0, 143, 137, 136, 8, 63, 144, 194, 245, 189, 144, 194, 245, 61, 144, 194, 245, 61, 206, 204, 204, 190, 236, 234, 234, 62, 144, 194, 245, 61, 240, 238, 238, 190, 154, 153, 153, 62, 206, 204, 204, 190, 32, 248, 1, 63, 59, 168, 131, 190, 154, 153, 153, 62, 175, 71, 225, 190, 154, 153, 153, 62, 180, 11, 8, 191, 49, 152, 221, 62, 191, 173, 182, 61, 92, 218, 171, 190, 186, 177, 203, 62, 79, 205, 198, 189, 186, 50, 231, 61, 152, 252, 184, 190, 163, 160, 114, 62, 175, 194, 168, 190, 112, 167, 202, 62, 243, 67, 103, 190, 75, 50, 132, 62, 108, 201, 182, 190, 75, 50, 132, 62, 33, 61, 214, 190, 79, 238, 189, 62, 50, 209, 157, 61, 33, 60, 147, 190, 212, 98, 173, 62, 149, 35, 188, 189, 77, 219, 217, 61, 116, 74, 149, 190, 252, 91, 158, 62, 100, 230, 135, 190, 180, 173, 170, 62, 189, 226, 77, 190, 238, 54, 104, 62, 3, 108, 156, 190, 238, 54, 104, 62, 144, 145, 183, 190, 201, 241, 169, 62, 164, 99, 147, 61, 57, 178, 119, 190, 212, 204, 164, 62, 233, 70, 179, 190, 220, 68, 166, 62, 67, 180, 137, 190, 77, 228, 78, 62, 14, 154, 163, 190, 131, 170, 157, 62, 142, 144, 82, 61, 201, 87, 158, 190, 30, 106, 151, 61, 79, 144, 149, 62, 74, 186, 158, 190, 233, 96, 58, 61, 142, 214, 154, 62, 105, 99, 118, 190, 215, 66, 58, 62, 233, 197, 148, 190, 118, 108, 145, 62, 30, 126, 31, 62, 207, 30, 48, 190, 228, 253, 20, 62, 117, 10, 153, 190, 142, 136, 189, 189, 255, 46, 151, 61, 3, 68, 183, 62, 133, 173, 43, 189, 242, 2, 133, 190, 60, 191, 35, 61, 164, 92, 140, 62, 252, 140, 94, 190, 111, 4, 41, 62, 197, 169, 136, 190, 140, 16, 135, 62, 105, 61, 18, 62, 118, 141, 51, 190, 191, 61, 120, 189, 72, 244, 144, 62, 141, 161, 135, 190, 10, 70, 179, 61, 156, 152, 42, 62, 153, 209, 3, 190, 150, 48, 137, 62, 207, 242, 142, 190, 12, 0, 105, 62, 96, 61, 74, 190, 22, 85, 26, 62, 202, 49, 124, 190, 63, 101, 126, 62, 112, 84, 82, 60, 26, 61, 66, 190, 9, 27, 33, 62, 165, 162, 107, 190, 15, 232, 128, 62, 22, 252, 6, 189, 134, 39, 58, 190, 27, 134, 245, 61, 104, 93, 123, 62, 132, 80, 129, 190, 46, 93, 85, 62, 138, 141, 56, 190, 113, 167, 13, 62, 93, 253, 104, 190, 133, 4, 108, 62, 212, 183, 50, 60, 66, 90, 48, 190, 122, 139, 19, 62, 100, 174, 85, 190, 70, 60, 95, 62, 127, 112, 3, 189, 116, 235, 93, 190, 219, 36, 158, 61, 15, 202, 120, 62, 214, 153, 225, 189, 226, 50, 3, 62, 58, 213, 106, 190, 176, 180, 67, 62, 203, 246, 40, 190, 146, 152, 2, 62, 151, 45, 87, 190, 180, 49, 91, 62, 202, 144, 21, 61, 255, 77, 64, 190, 113, 118, 76, 62, 95, 156, 108, 190, 53, 228, 102, 62, 183, 37, 57, 190, 246, 100, 119, 61, 82, 162, 98, 62, 25, 189, 225, 188, 174, 194, 85, 190, 50, 186, 51, 62, 90, 35, 27, 190, 53, 192, 241, 61, 21, 143, 70, 190, 110, 111, 100, 101, 115, 95, 99, 108, 97, 115, 115, 105, 100, 115, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 116, 114, 101, 101, 95, 114, 111, 111, 116, 95, 105, 100, 115, 0, 10, 0, 0, 15, 0, 29, 0, 43, 0, 51, 0, 61, 0, 75, 0, 89, 0, 103, 0, 119, 0, 0, 16, 0, 24, 9, 166, 8, 235, 8, 6, 9, 205, 0, 56, 4, 149, 8, 89, 5, 125, 7, 34, 3, 213, 8, 230, 8, 198, 8, 74, 9, 66, 0, 86, 9, 32, 0, 2, 0, 16, 0, 44, 9, 185, 8, 254, 8, 27, 9, 227, 0, 74, 4, 169, 8, 108, 5, 149, 7, 57, 3, 133, 0, 143, 0, 10, 0, 95, 9, 89, 0, 1, 0, 20, 20, 20, 20, 100, 100, 100, 100, 100, 100, 9, 9, 9, 20, 100, 9, 48, 37, 1,  }; /* custom_initial_data */
const TfArray<1, int> inputs0 = { 1, { 0 } };
const TfArray<1, int> outputs0 = { 1, { 4 } };
const TfArray<1, int> inputs1 = { 1, { 4 } };
const TfArray<1, int> outputs1 = { 1, { 5 } };
const TfArray<1, int> inputs2 = { 1, { 5 } };
const TfArray<1, int> outputs2 = { 1, { 6 } };
const TfLiteReshapeParams opdata3 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs3 = { 2, { 6,2 } };
const TfArray<1, int> outputs3 = { 1, { 7 } };
const TfLiteAddParams opdata4 = { kTfLiteActNone };
const TfArray<2, int> inputs4 = { 2, { 7,3 } };
const TfArray<1, int> outputs4 = { 1, { 8 } };
const ALIGN(4) uint8_t opdata5[4] = { 0, 0, 0, 0,  }; /* op type 42=DIV */
const TfArray<2, int> inputs5 = { 2, { 3,8 } };
const TfArray<1, int> outputs5 = { 1, { 9 } };
const TfLiteSubParams opdata6 = { kTfLiteActNone };
const TfArray<2, int> inputs6 = { 2, { 3,9 } };
const TfArray<1, int> outputs6 = { 1, { 10 } };
const TfLiteConcatenationParams opdata7 = { 0, kTfLiteActNone };
const TfArray<2, int> inputs7 = { 2, { 10,9 } };
const TfArray<1, int> outputs7 = { 1, { 11 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 11,1 } };
const TfArray<1, int> outputs8 = { 1, { 12 } };
};

TensorInfo_t tensorData[] = {
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension0, 32, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data1, (TfLiteIntArray*)&g0::tensor_dimension1, 8, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data2, (TfLiteIntArray*)&g0::tensor_dimension1, 8, },
{ kTfLiteMmapRo, kTfLiteFloat32, (int32_t*)g0::tensor_data3, (TfLiteIntArray*)&g0::tensor_dimension3, 4, },
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 32), (TfLiteIntArray*)&g0::tensor_dimension4, 4, },
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 16), (TfLiteIntArray*)&g0::tensor_dimension4, 4, },
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension4, 4, },
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 16), (TfLiteIntArray*)&g0::tensor_dimension4, 4, },
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension4, 4, },
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 32), (TfLiteIntArray*)&g0::tensor_dimension4, 4, },
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension4, 4, },
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 16), (TfLiteIntArray*)&g0::tensor_dimension11, 8, },
{ kTfLiteArenaRw, kTfLiteFloat32, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension12, 8, },
};

#ifndef TF_LITE_STATIC_MEMORY
TfLiteNode tflNodes[9] = {
{ (TfLiteIntArray*)&g0::inputs0, (TfLiteIntArray*)&g0::outputs0, (TfLiteIntArray*)&g0::inputs0, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata0)), const_cast<void*>(static_cast<const void*>(&g0::opdata0)), 2449, },
{ (TfLiteIntArray*)&g0::inputs1, (TfLiteIntArray*)&g0::outputs1, (TfLiteIntArray*)&g0::inputs1, nullptr, nullptr, nullptr, nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs2, (TfLiteIntArray*)&g0::outputs2, (TfLiteIntArray*)&g0::inputs2, nullptr, nullptr, nullptr, nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs3, (TfLiteIntArray*)&g0::outputs3, (TfLiteIntArray*)&g0::inputs3, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata3)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs4, (TfLiteIntArray*)&g0::outputs4, (TfLiteIntArray*)&g0::inputs4, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata4)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs5, (TfLiteIntArray*)&g0::outputs5, (TfLiteIntArray*)&g0::inputs5, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata5)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs6, (TfLiteIntArray*)&g0::outputs6, (TfLiteIntArray*)&g0::inputs6, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata6)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs7, (TfLiteIntArray*)&g0::outputs7, (TfLiteIntArray*)&g0::inputs7, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata7)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs8, (TfLiteIntArray*)&g0::outputs8, (TfLiteIntArray*)&g0::inputs8, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata8)), nullptr, 0, },
};
#else
TfLiteNode tflNodes[9] = {
{ (TfLiteIntArray*)&g0::inputs0, (TfLiteIntArray*)&g0::outputs0, (TfLiteIntArray*)&g0::inputs0, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata0)), const_cast<void*>(static_cast<const void*>(&g0::opdata0)), 2449, },
{ (TfLiteIntArray*)&g0::inputs1, (TfLiteIntArray*)&g0::outputs1, (TfLiteIntArray*)&g0::inputs1, nullptr, nullptr, nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs2, (TfLiteIntArray*)&g0::outputs2, (TfLiteIntArray*)&g0::inputs2, nullptr, nullptr, nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs3, (TfLiteIntArray*)&g0::outputs3, (TfLiteIntArray*)&g0::inputs3, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata3)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs4, (TfLiteIntArray*)&g0::outputs4, (TfLiteIntArray*)&g0::inputs4, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata4)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs5, (TfLiteIntArray*)&g0::outputs5, (TfLiteIntArray*)&g0::inputs5, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata5)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs6, (TfLiteIntArray*)&g0::outputs6, (TfLiteIntArray*)&g0::inputs6, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata6)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs7, (TfLiteIntArray*)&g0::outputs7, (TfLiteIntArray*)&g0::inputs7, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata7)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs8, (TfLiteIntArray*)&g0::outputs8, (TfLiteIntArray*)&g0::inputs8, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata8)), nullptr, 0, },
};
#endif

used_operators_e used_ops[] =
{OP_TreeEnsembleClassifier, OP_NEG, OP_EXP, OP_RESHAPE, OP_ADD, OP_DIV, OP_SUB, OP_CONCATENATION, OP_RESHAPE, };


// Indices into tflTensors and tflNodes for subgraphs
const size_t tflTensors_subgraph_index[] = {0, 13, };
const size_t tflNodes_subgraph_index[] = {0, 9, };

// Input/output tensors
static const int in_tensor_indices[] = {
  0, 
};

static const int out_tensor_indices[] = {
  12, 
};


size_t current_subgraph_index = 0;

static void init_tflite_tensor(size_t i, TfLiteTensor *tensor) {
  tensor->type = tensorData[i].type;
  tensor->is_variable = false;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  tensor->allocation_type = tensorData[i].allocation_type;
#else
  tensor->allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
  tensor->bytes = tensorData[i].bytes;
  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  if(tensor->allocation_type == kTfLiteArenaRw){
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
      tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
  tensor->quantization.type = kTfLiteNoQuantization;

}

static void init_tflite_eval_tensor(int i, TfLiteEvalTensor *tensor) {

  tensor->type = tensorData[i].type;

  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  auto allocation_type = tensorData[i].allocation_type;
  if(allocation_type == kTfLiteArenaRw) {
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
    tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
}

static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBufferImpl(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  uint32_t align_bytes = (bytes % 16) ? 16 - (bytes % 16) : 0;

  if (current_location - (bytes + align_bytes) < tensor_boundary) {
    if (overflow_buffers_ix > EI_MAX_OVERFLOW_BUFFER_COUNT - 1) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d, does not fit in tensor arena and reached EI_MAX_OVERFLOW_BUFFER_COUNT\n",
        (int)bytes);
      return NULL;
    }

    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers[overflow_buffers_ix++] = ptr;
    return ptr;
  }

  current_location -= bytes;

  // align to the left aligned boundary of 16 bytes
  current_location -= 15; // for alignment
  current_location += 16 - ((uintptr_t)(current_location) & 15);

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}

typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;

static scratch_buffer_t scratch_buffers[EI_MAX_SCRATCH_BUFFER_COUNT];
static size_t scratch_buffers_ix = 0;

static TfLiteStatus RequestScratchBufferInArenaImpl(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBufferImpl(ctx, b.bytes);
  if (!b.ptr) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffers[scratch_buffers_ix] = b;
  *buffer_idx = scratch_buffers_ix;

  scratch_buffers_ix++;

  return kTfLiteOk;
}

static void* GetScratchBufferImpl(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static const uint16_t TENSOR_IX_UNUSED = 0x7FFF;

static void ResetTensors() {
  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    tflTensors[ix].index = TENSOR_IX_UNUSED;
  }
  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    tflEvalTensors[ix].index = TENSOR_IX_UNUSED;
  }
}

static TfLiteTensor* GetTensorImpl(const struct TfLiteContext* context,
                               int tensor_idx) {

  tensor_idx = tflTensors_subgraph_index[current_subgraph_index] + tensor_idx;

  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    // already used? OK!
    if (tflTensors[ix].index == tensor_idx) {
      return &tflTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_tensor(tensor_idx, &tflTensors[ix].tensor);
      tflTensors[ix].index = tensor_idx;
      return &tflTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_TENSOR_COUNT (%d)\n", MAX_TFL_TENSOR_COUNT);
  return nullptr;
}

static TfLiteEvalTensor* GetEvalTensorImpl(const struct TfLiteContext* context,
                                       int tensor_idx) {

  tensor_idx = tflTensors_subgraph_index[current_subgraph_index] + tensor_idx;

  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    // already used? OK!
    if (tflEvalTensors[ix].index == tensor_idx) {
      return &tflEvalTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflEvalTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_eval_tensor(tensor_idx, &tflEvalTensors[ix].tensor);
      tflEvalTensors[ix].index = tensor_idx;
      return &tflEvalTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_EVAL_COUNT (%d)\n", (int)MAX_TFL_EVAL_COUNT);
  return nullptr;
}

class EonMicroContext : public MicroContext {
 public:
 
  EonMicroContext(): MicroContext(nullptr, nullptr, nullptr) { }

  void* AllocatePersistentBuffer(size_t bytes) {
    return AllocatePersistentBufferImpl(nullptr, bytes);
  }

  TfLiteStatus RequestScratchBufferInArena(size_t bytes,
                                           int* buffer_index) {
  return RequestScratchBufferInArenaImpl(nullptr, bytes, buffer_index);
  }

  void* GetScratchBuffer(int buffer_index) {
    return GetScratchBufferImpl(nullptr, buffer_index);
  }
 
  TfLiteTensor* AllocateTempTfLiteTensor(int tensor_index) {
    return GetTensorImpl(nullptr, tensor_index);
  }

  void DeallocateTempTfLiteTensor(TfLiteTensor* tensor) {
    return;
  }

  bool IsAllTempTfLiteTensorDeallocated() {
    return true;
  }

  TfLiteEvalTensor* GetEvalTensor(int tensor_index) {
    return GetEvalTensorImpl(nullptr, tensor_index);
  }

};


} // namespace

TfLiteStatus tflite_learn_4_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    ei_printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;

  EonMicroContext micro_context_;
  
  // Set microcontext as the context ptr
  ctx.impl_ = static_cast<void*>(&micro_context_);
  // Setup tflitecontext functions
  ctx.AllocatePersistentBuffer = &AllocatePersistentBufferImpl;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArenaImpl;
  ctx.GetScratchBuffer = &GetScratchBufferImpl;
  ctx.GetTensor = &GetTensorImpl;
  ctx.GetEvalTensor = &GetEvalTensorImpl;
  ctx.ReportError = &MicroContextReportOpError;

  ctx.tensors_size = 13;
  for (size_t i = 0; i < 13; ++i) {
    TfLiteTensor tensor;
    init_tflite_tensor(i, &tensor);
    if (tensor.allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tensor.data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }

  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }

  registrations[OP_TreeEnsembleClassifier] = *Register_TreeEnsembleClassifier();
  registrations[OP_NEG] = Register_NEG();
  registrations[OP_EXP] = Register_EXP();
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_ADD] = Register_ADD();
  registrations[OP_DIV] = Register_DIV();
  registrations[OP_SUB] = Register_SUB();
  registrations[OP_CONCATENATION] = Register_CONCATENATION();

  for (size_t g = 0; g < 1; ++g) {
    current_subgraph_index = g;
    for(size_t i = tflNodes_subgraph_index[g]; i < tflNodes_subgraph_index[g+1]; ++i) {
      if (registrations[used_ops[i]].init) {
        tflNodes[i].user_data = registrations[used_ops[i]].init(&ctx, (const char*)tflNodes[i].builtin_data, tflNodes[i].custom_initial_data_size);
      }
    }
  }
  current_subgraph_index = 0;

  for(size_t g = 0; g < 1; ++g) {
    current_subgraph_index = g;
    for(size_t i = tflNodes_subgraph_index[g]; i < tflNodes_subgraph_index[g+1]; ++i) {
      if (registrations[used_ops[i]].prepare) {
        ResetTensors();
        TfLiteStatus status = registrations[used_ops[i]].prepare(&ctx, &tflNodes[i]);
        if (status != kTfLiteOk) {
          return status;
        }
      }
    }
  }
  current_subgraph_index = 0;

  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_input(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(in_tensor_indices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_output(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(out_tensor_indices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_invoke() {
  for (size_t i = 0; i < 9; ++i) {
    ResetTensors();

    TfLiteStatus status = registrations[used_ops[i]].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif

  // scratch buffers are allocated within the arena, so just reset the counter so memory can be reused
  scratch_buffers_ix = 0;

  // overflow buffers are on the heap, so free them first
  for (size_t ix = 0; ix < overflow_buffers_ix; ix++) {
    ei_free(overflow_buffers[ix]);
  }
  overflow_buffers_ix = 0;
  return kTfLiteOk;
}
