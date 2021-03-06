ifndef __REQUIRED_RPCNDR_H_VERSION__
__REQUIRED_RPCNDR_H_VERSION__ equ 475
endif
ifndef __REQUIRED_RPCSAL_H_VERSION__
__REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
 .err <this stub requires an updated version of rpcndr.h>
endif
ifndef COM_NO_WINDOWS_H
include windows.inc
include ole2.inc
endif
ifndef __activprof_h__
__activprof_h__ equ <>
.pragma list(push, 0)

ifndef __IActiveScriptProfilerControl_FWD_DEFINED__
__IActiveScriptProfilerControl_FWD_DEFINED__ equ 1
endif
ifndef __IActiveScriptProfilerCallback_FWD_DEFINED__
__IActiveScriptProfilerCallback_FWD_DEFINED__ equ 1
endif
include unknwn.inc

ACTIVPROF_E_PROFILER_PRESENT	   equ MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0200)
ACTIVPROF_E_PROFILER_ABSENT	   equ MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0201)
ACTIVPROF_E_UNABLE_TO_APPLY_ACTION equ MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0202)

ifndef __ActivProf_h
__ActivProf_h equ <>

PROFILER_SCRIPT_TYPE typedef SDWORD
PROFILER_SCRIPT_TYPE_USER equ 0
PROFILER_SCRIPT_TYPE_DYNAMIC equ ( PROFILER_SCRIPT_TYPE_USER + 1 )
PROFILER_SCRIPT_TYPE_NATIVE equ ( PROFILER_SCRIPT_TYPE_DYNAMIC + 1 )

PROFILER_EVENT_MASK typedef SDWORD
PROFILER_EVENT_MASK_TRACE_SCRIPT_FUNCTION_CALL equ 0x1
PROFILER_EVENT_MASK_TRACE_NATIVE_FUNCTION_CALL equ 0x2
PROFILER_EVENT_MASK_TRACE_ALL equ ( PROFILER_EVENT_MASK_TRACE_SCRIPT_FUNCTION_CALL | PROFILER_EVENT_MASK_TRACE_NATIVE_FUNCTION_CALL )

PROFILER_TOKEN typedef LONG

externdef __MIDL_itf_activprof_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
externdef __MIDL_itf_activprof_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE

ifndef __IActiveScriptProfilerControl_INTERFACE_DEFINED__
__IActiveScriptProfilerControl_INTERFACE_DEFINED__ equ <>

externdef IID_IActiveScriptProfilerControl:IID

.comdef IActiveScriptProfilerControl

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    StartProfiling	proc :REFCLSID, :DWORD, :DWORD
    SetProfilerEventMask proc :DWORD
    StopProfiling	proc :HRESULT
    .ends

endif

ifndef __IActiveScriptProfilerCallback_INTERFACE_DEFINED__
__IActiveScriptProfilerCallback_INTERFACE_DEFINED__ equ 1

externdef IID_IActiveScriptProfilerCallback:IID

.comdef IActiveScriptProfilerCallback

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    Initialize		proc :DWORD
    Shutdown		proc :HRESULT
    ScriptCompiled	proc :PROFILER_TOKEN, :PROFILER_SCRIPT_TYPE, :ptr
    FunctionCompiled	proc :PROFILER_TOKEN, :PROFILER_TOKEN, :ptr, :ptr, :ptr
    OnFunctionEnter	proc :PROFILER_TOKEN, :PROFILER_TOKEN
    OnFunctionExit	proc :PROFILER_TOKEN, :PROFILER_TOKEN
    .ends

endif
endif

externdef __MIDL_itf_activprof_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
externdef __MIDL_itf_activprof_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE

.pragma list(pop)
endif
