/*
 * 版权所有 (c) 华为技术有限公司 2017-2021
 * 功能说明: 指令流引擎定义的函数以及返回值
 */

#ifndef INSTRUCTION_ENGINE_H
#define INSTRUCTION_ENGINE_H

#include <cstdint>

enum VMIMsgType : uint8_t {
    INVALID,
    HEARTBEAT,
    GL,
    AUDIO,
    TOUCH_INPUT,
    NAVBAR_INPUT,
    END
};

enum VmiInstructionEngineRetCode : uint32_t {
    VMI_SUCCESS = 0,
    VMI_INSTRUCTION_ENGINE_INVALID_PARAM = 1,
    VMI_INSTRUCTION_ENGINE_UNINIT_SOCK = 2,
    VMI_INSTRUCTION_ENGINE_SEND_ALLOC_FAILED = 3,
    VMI_INSTRUCTION_ENGINE_SEND_MEMSET_FAILED = 4,
    VMI_INSTRUCTION_ENGINE_SEND_MEMCPY_FAILED = 5,
    VMI_INSTRUCTION_ENGINE_SEND_FAIL = 6,
    VMI_INSTRUCTION_ENGINE_HOOK_REGISTER_FAIL = 7,
    VMI_INSTRUCTION_CLIENT_INVALID_PARAM = 0x0A050001,
    VMI_INSTRUCTION_CLIENT_START_FAIL = 0x0A050002,
    VMI_INSTRUCTION_CLIENT_ALREADY_STARTED = 0x0A050003,
    VMI_INSTRUCTION_CLIENT_STOP_FAIL = 0x0A050004,
    VMI_INSTRUCTION_CLIENT_SEND_HOOK_REGISTER_FAIL = 0x0A050005,
    VMI_INSTRUCTION_CLIENT_SEND_FAIL = 0x0A050006,
    VMI_INSTRUCTION_CLIENT_SEND_AGAIN = 0x0A050007,
    VMI_INSTRUCTION_CLIENT_INITIALIZE_FAIL = 0x0A050008
};

enum VmiInstructionEngineEvent {
    VMI_INSTRUCTION_ENGINE_EVENT_SOCK_DISCONN   = -2,   // 连接断开
    VMI_INSTRUCTION_ENGINE_EVENT_PKG_BROKEN     = -3,   // 数据包损坏
    VMI_INSTRUCTION_ENGINE_EVENT_VERSION_ERROR  = -4,   // 服务端和客户端的版本不匹配
    VMI_INSTRUCTION_ENGINE_EVENT_READY = -5,            // 引擎渲染第一帧画面成功
    VMI_INSTRUCTION_ENGINE_EVENT_ORIENTATION_CHANGED = -6, // 服务端方向转屏事件
};

typedef struct EngineEvent {
    int event;
    int reserved[4];
} EngineEvent;

// 参数值event是什么事件
using OnVmiInstructionEngineEvent = void (*)(EngineEvent event);
#endif
