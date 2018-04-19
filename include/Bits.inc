ifndef __REQUIRED_RPCNDR_H_VERSION__
__REQUIRED_RPCNDR_H_VERSION__ equ 500
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
ifndef __bits_h__
__bits_h__ equ 1
.xlist

ifndef __IBackgroundCopyFile_FWD_DEFINED__
__IBackgroundCopyFile_FWD_DEFINED__ equ 1
endif
ifndef __IEnumBackgroundCopyFiles_FWD_DEFINED__
__IEnumBackgroundCopyFiles_FWD_DEFINED__ equ 1
endif
ifndef __IBackgroundCopyError_FWD_DEFINED__
__IBackgroundCopyError_FWD_DEFINED__ equ 1
endif
ifndef __IBackgroundCopyJob_FWD_DEFINED__
__IBackgroundCopyJob_FWD_DEFINED__ equ 1
endif
ifndef __IEnumBackgroundCopyJobs_FWD_DEFINED__
__IEnumBackgroundCopyJobs_FWD_DEFINED__ equ 1
endif
ifndef __IBackgroundCopyCallback_FWD_DEFINED__
__IBackgroundCopyCallback_FWD_DEFINED__ equ 1
endif
ifndef __AsyncIBackgroundCopyCallback_FWD_DEFINED__
__AsyncIBackgroundCopyCallback_FWD_DEFINED__ equ 1
endif
ifndef __IBackgroundCopyManager_FWD_DEFINED__
__IBackgroundCopyManager_FWD_DEFINED__ equ 1
endif
ifndef __BackgroundCopyManager_FWD_DEFINED__
__BackgroundCopyManager_FWD_DEFINED__ equ 1
BackgroundCopyManager	typedef BackgroundCopyManager
endif
ifndef __IBackgroundCopyCallback_FWD_DEFINED__
__IBackgroundCopyCallback_FWD_DEFINED__ equ 1
endif

include unknwn.inc
include bitsmsg.inc
.xlist

BG_SIZE_UNKNOWN		equ (-1)

externdef		__MIDL_itf_bits_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
externdef		__MIDL_itf_bits_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE

ifndef __IBackgroundCopyFile_INTERFACE_DEFINED__
__IBackgroundCopyFile_INTERFACE_DEFINED__ equ 1

BG_FILE_PROGRESS	STRUC
BytesTotal		UINT64 ?
BytesTransferred	UINT64 ?
Completed		BOOL ?
BG_FILE_PROGRESS	ENDS

externdef		IID_IBackgroundCopyFile:IID

.comdef IBackgroundCopyFile

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    GetRemoteName	proc :ptr
    GetLocalName	proc :ptr
    GetProgress		proc :ptr
    .ends

endif

ifndef __IEnumBackgroundCopyFiles_INTERFACE_DEFINED__
__IEnumBackgroundCopyFiles_INTERFACE_DEFINED__ equ 1

externdef		IID_IEnumBackgroundCopyFiles:IID

.comdef IEnumBackgroundCopyFiles

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    Next		proc :ULONG, :ptr, :ptr
    Skip		proc :ULONG
    Reset		proc
    Clone		proc :ptr
    GetCount		proc :ptr
    .ends

endif

ifndef __IBackgroundCopyError_INTERFACE_DEFINED__
__IBackgroundCopyError_INTERFACE_DEFINED__ equ 1

_MIDL_IBackgroundCopyError_0001 typedef SDWORD
BG_ERROR_CONTEXT_NONE	equ 0
BG_ERROR_CONTEXT_UNKNOWN equ 1
BG_ERROR_CONTEXT_GENERAL_QUEUE_MANAGER equ 2
BG_ERROR_CONTEXT_QUEUE_MANAGER_NOTIFICATION equ 3
BG_ERROR_CONTEXT_LOCAL_FILE equ 4
BG_ERROR_CONTEXT_REMOTE_FILE equ 5
BG_ERROR_CONTEXT_GENERAL_TRANSPORT equ 6
BG_ERROR_CONTEXT_REMOTE_APPLICATION equ 7

externdef		IID_IBackgroundCopyError:IID

.comdef IBackgroundCopyError

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    GetError		proc :ptr, :ptr
    GetFile		proc :ptr
    GetErrorDescription proc :DWORD, :ptr
    GetErrorContextDescription proc :DWORD, :ptr
    GetProtocol		proc :ptr
    .ends
endif

ifndef __IBackgroundCopyJob_INTERFACE_DEFINED__
__IBackgroundCopyJob_INTERFACE_DEFINED__ equ 1

BG_FILE_INFO		STRUC
RemoteName		LPWSTR ?
LocalName		LPWSTR ?
BG_FILE_INFO		ENDS

BG_JOB_PROGRESS		STRUC
BytesTotal		UINT64 ?
BytesTransferred	UINT64 ?
FilesTotal		ULONG ?
FilesTransferred	ULONG ?
BG_JOB_PROGRESS		ENDS

BG_JOB_TIMES		STRUC
CreationTime		FILETIME <>
ModificationTime	FILETIME <>
TransferCompletionTime	FILETIME <>
BG_JOB_TIMES		ENDS

BG_JOB_PRIORITY typedef SDWORD
BG_JOB_PRIORITY_FOREGROUND equ 0
BG_JOB_PRIORITY_HIGH	equ ( BG_JOB_PRIORITY_FOREGROUND + 1 )
BG_JOB_PRIORITY_NORMAL	equ ( BG_JOB_PRIORITY_HIGH + 1 )
BG_JOB_PRIORITY_LOW	equ ( BG_JOB_PRIORITY_NORMAL + 1 )

BG_JOB_STATE typedef SDWORD
BG_JOB_STATE_QUEUED	equ 0
BG_JOB_STATE_CONNECTING equ ( BG_JOB_STATE_QUEUED + 1 )
BG_JOB_STATE_TRANSFERRING equ ( BG_JOB_STATE_CONNECTING + 1 )
BG_JOB_STATE_SUSPENDED	equ ( BG_JOB_STATE_TRANSFERRING + 1 )
BG_JOB_STATE_ERROR	equ ( BG_JOB_STATE_SUSPENDED + 1 )
BG_JOB_STATE_TRANSIENT_ERROR equ ( BG_JOB_STATE_ERROR + 1 )
BG_JOB_STATE_TRANSFERRED equ ( BG_JOB_STATE_TRANSIENT_ERROR + 1 )
BG_JOB_STATE_ACKNOWLEDGED equ ( BG_JOB_STATE_TRANSFERRED + 1 )
BG_JOB_STATE_CANCELLED	equ ( BG_JOB_STATE_ACKNOWLEDGED + 1 )

BG_JOB_TYPE typedef SDWORD
BG_JOB_TYPE_DOWNLOAD	equ 0
BG_JOB_TYPE_UPLOAD	equ ( BG_JOB_TYPE_DOWNLOAD + 1 )
BG_JOB_TYPE_UPLOAD_REPLY equ ( BG_JOB_TYPE_UPLOAD + 1 )

BG_JOB_PROXY_USAGE typedef SDWORD
BG_JOB_PROXY_USAGE_PRECONFIG equ 0
BG_JOB_PROXY_USAGE_NO_PROXY equ ( BG_JOB_PROXY_USAGE_PRECONFIG + 1 )
BG_JOB_PROXY_USAGE_OVERRIDE equ ( BG_JOB_PROXY_USAGE_NO_PROXY + 1 )
BG_JOB_PROXY_USAGE_AUTODETECT equ ( BG_JOB_PROXY_USAGE_OVERRIDE + 1 )

externdef		IID_IBackgroundCopyJob:IID

.comdef IBackgroundCopyJob

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    AddFileSet		proc :ULONG, :ptr
    AddFile		proc :LPCWSTR, :LPCWSTR
    EnumFiles		proc :ptr
    Suspend		proc
    Resume		proc
    Cancel		proc
    Complete		proc
    GetId		proc :ptr
    GetType		proc :ptr
    GetProgress		proc :ptr
    GetTimes		proc :ptr
    GetState		proc :ptr
    GetError		proc :ptr
    GetOwner		proc :ptr
    SetDisplayName	proc :LPCWSTR
    GetDisplayName	proc :ptr
    SetDescription	proc :LPCWSTR
    GetDescription	proc :ptr
    SetPriority		proc :BG_JOB_PRIORITY
    GetPriority		proc :ptr
    SetNotifyFlags	proc :ULONG
    GetNotifyFlags	proc :ptr
    SetNotifyInterface	proc :ptr
    GetNotifyInterface	proc :ptr
    SetMinimumRetryDelay proc :ULONG
    GetMinimumRetryDelay proc :ptr
    SetNoProgressTimeout proc :ULONG
    GetNoProgressTimeout proc :ptr
    GetErrorCount	proc :ptr
    SetProxySettings	proc :BG_JOB_PROXY_USAGE, :ptr, :ptr
    GetProxySettings	proc :ptr, :ptr, :ptr
    TakeOwnership	proc
    .ends

endif

ifndef __IEnumBackgroundCopyJobs_INTERFACE_DEFINED__
__IEnumBackgroundCopyJobs_INTERFACE_DEFINED__ equ 1

externdef		IID_IEnumBackgroundCopyJobs:IID

.comdef IEnumBackgroundCopyJobs

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    Next		proc :ULONG, :ptr, :ptr
    Skip		proc :ULONG
    Reset		proc
    Clone		proc :ptr
    GetCount		proc :ptr
    .ends

endif

BG_NOTIFY_JOB_TRANSFERRED equ 0x0001
BG_NOTIFY_JOB_ERROR	equ 0x0002
BG_NOTIFY_DISABLE	equ 0x0004
BG_NOTIFY_JOB_MODIFICATION equ 0x0008
BG_NOTIFY_FILE_TRANSFERRED equ 0x0010

externdef __MIDL_itf_bits_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
externdef __MIDL_itf_bits_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE

ifndef __IBackgroundCopyCallback_INTERFACE_DEFINED__
__IBackgroundCopyCallback_INTERFACE_DEFINED__ equ 1

externdef		IID_IBackgroundCopyCallback:IID

.comdef IBackgroundCopyCallback

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    JobTransferred	proc :ptr
    JobError		proc :ptr, :ptr
    JobModification	proc :ptr, :DWORD
    .ends

endif

ifndef __AsyncIBackgroundCopyCallback_INTERFACE_DEFINED__
__AsyncIBackgroundCopyCallback_INTERFACE_DEFINED__ equ 1

externdef		IID_AsyncIBackgroundCopyCallback:IID

.comdef AsyncIBackgroundCopyCallback

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    Begin_JobTransferred proc :ptr
    Finish_JobTransferred proc
    Begin_JobError	proc :ptr, :ptr
    Finish_JobError	proc
    Begin_JobModification proc :ptr, :DWORD
    Finish_JobModification proc
    .ends

endif

ifndef __IBackgroundCopyManager_INTERFACE_DEFINED__
__IBackgroundCopyManager_INTERFACE_DEFINED__ equ 1

BG_JOB_ENUM_ALL_USERS	equ 0x0001

externdef		IID_IBackgroundCopyManager:IID

.comdef IBackgroundCopyManager

    QueryInterface	proc :REFIID, :ptr
    AddRef		proc
    Release		proc
    CreateJob		proc :LPCWSTR, :BG_JOB_TYPE, :ptr, :ptr
    GetJob		proc :REFGUID, :ptr
    EnumJobs		proc :DWORD, :ptr
    GetErrorDescription proc :HRESULT, :DWORD, :ptr
    .ends

endif

ifndef __BackgroundCopyManager_LIBRARY_DEFINED__
__BackgroundCopyManager_LIBRARY_DEFINED__ equ 1

externdef		LIBID_BackgroundCopyManager:IID
externdef		CLSID_BackgroundCopyManager:CLSID
ifdef __cplusplus
DECLSPEC_UUID("4991d34b-80a1-4291-83b6-3328366b9097")
endif
endif

include bits1_5.inc

externdef __MIDL_itf_bits_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
externdef __MIDL_itf_bits_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE

.list
endif