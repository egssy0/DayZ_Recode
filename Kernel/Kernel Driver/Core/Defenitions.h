typedef unsigned int UINT;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef unsigned long DWORD;
typedef unsigned long long DWORD64;

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

typedef signed char        int_least8_t;
typedef short              int_least16_t;
typedef int                int_least32_t;
typedef long long          int_least64_t;
typedef unsigned char      uint_least8_t;
typedef unsigned short     uint_least16_t;
typedef unsigned int       uint_least32_t;
typedef unsigned long long uint_least64_t;

typedef signed char        int_fast8_t;
typedef int                int_fast16_t;
typedef int                int_fast32_t;
typedef long long          int_fast64_t;
typedef unsigned char      uint_fast8_t;
typedef unsigned int       uint_fast16_t;
typedef unsigned int       uint_fast32_t;
typedef unsigned long long uint_fast64_t;

typedef long long          intmax_t;
typedef unsigned long long uintmax_t;

typedef struct _DBGKD_DEBUG_DATA_HEADER64
{

	//
	// Link to other blocks
	//

	LIST_ENTRY64 List;

	//
	// This is a unique tag to identify the owner of the block.
	// If your component only uses one pool tag, use it for this, too.
	//

	ULONG           OwnerTag;

	//
	// This must be initialized to the size of the data block,
	// including this structure.
	//

	ULONG           Size;

} DBGKD_DEBUG_DATA_HEADER64, * PDBGKD_DEBUG_DATA_HEADER64;

typedef struct _KDDEBUGGER_DATA64
{

	DBGKD_DEBUG_DATA_HEADER64 Header;
	ULONG64   KernBase;

	ULONG64   BreakpointWithStatus;       // address of breakpoint
	ULONG64   SavedContext;
	USHORT  ThCallbackStack;            // offset in thread data
	USHORT  NextCallback;               // saved pointer to next callback frame
	USHORT  FramePointer;               // saved frame pointer
	USHORT  PaeEnabled;
	ULONG64   KiCallUserMode;             // kernel routine
	ULONG64   KeUserCallbackDispatcher;   // address in ntdll
	ULONG64   PsLoadedModuleList;
	ULONG64   PsActiveProcessHead;
	ULONG64   PspCidTable;

	ULONG64   ExpSystemResourcesList;
	ULONG64   ExpPagedPoolDescriptor;
	ULONG64   ExpNumberOfPagedPools;

	ULONG64   KeTimeIncrement;
	ULONG64   KeBugCheckCallbackListHead;
	ULONG64   KiBugcheckData;

	ULONG64   IopErrorLogListHead;

	ULONG64   ObpRootDirectoryObject;
	ULONG64   ObpTypeObjectType;

	ULONG64   MmSystemCacheStart;
	ULONG64   MmSystemCacheEnd;
	ULONG64   MmSystemCacheWs;

	ULONG64   MmPfnDatabase;
	ULONG64   MmSystemPtesStart;
	ULONG64   MmSystemPtesEnd;
	ULONG64   MmSubsectionBase;
	ULONG64   MmNumberOfPagingFiles;

	ULONG64   MmLowestPhysicalPage;
	ULONG64   MmHighestPhysicalPage;
	ULONG64   MmNumberOfPhysicalPages;

	ULONG64   MmMaximumNonPagedPoolInBytes;
	ULONG64   MmNonPagedSystemStart;
	ULONG64   MmNonPagedPoolStart;
	ULONG64   MmNonPagedPoolEnd;

	ULONG64   MmPagedPoolStart;
	ULONG64   MmPagedPoolEnd;
	ULONG64   MmPagedPoolInformation;
	ULONG64   MmPageSize;

	ULONG64   MmSizeOfPagedPoolInBytes;

	ULONG64   MmTotalCommitLimit;
	ULONG64   MmTotalCommittedPages;
	ULONG64   MmSharedCommit;
	ULONG64   MmDriverCommit;
	ULONG64   MmProcessCommit;
	ULONG64   MmPagedPoolCommit;
	ULONG64   MmExtendedCommit;

	ULONG64   MmZeroedPageListHead;
	ULONG64   MmFreePageListHead;
	ULONG64   MmStandbyPageListHead;
	ULONG64   MmModifiedPageListHead;
	ULONG64   MmModifiedNoWritePageListHead;
	ULONG64   MmAvailablePages;
	ULONG64   MmResidentAvailablePages;

	ULONG64   PoolTrackTable;
	ULONG64   NonPagedPoolDescriptor;

	ULONG64   MmHighestUserAddress;
	ULONG64   MmSystemRangeStart;
	ULONG64   MmUserProbeAddress;

	ULONG64   KdPrintCircularBuffer;
	ULONG64   KdPrintCircularBufferEnd;
	ULONG64   KdPrintWritePointer;
	ULONG64   KdPrintRolloverCount;

	ULONG64   MmLoadedUserImageList;

	// NT 5.1 Addition

	ULONG64   NtBuildLab;
	ULONG64   KiNormalSystemCall;

	// NT 5.0 hotfix addition

	ULONG64   KiProcessorBlock;
	ULONG64   MmUnloadedDrivers;
	ULONG64   MmLastUnloadedDriver;
	ULONG64   MmTriageActionTaken;
	ULONG64   MmSpecialPoolTag;
	ULONG64   KernelVerifier;
	ULONG64   MmVerifierData;
	ULONG64   MmAllocatedNonPagedPool;
	ULONG64   MmPeakCommitment;
	ULONG64   MmTotalCommitLimitMaximum;
	ULONG64   CmNtCSDVersion;

	// NT 5.1 Addition

	ULONG64   MmPhysicalMemoryBlock;
	ULONG64   MmSessionBase;
	ULONG64   MmSessionSize;
	ULONG64   MmSystemParentTablePage;

	// Server 2003 addition

	ULONG64   MmVirtualTranslationBase;

	USHORT    OffsetKThreadNextProcessor;
	USHORT    OffsetKThreadTeb;
	USHORT    OffsetKThreadKernelStack;
	USHORT    OffsetKThreadInitialStack;

	USHORT    OffsetKThreadApcProcess;
	USHORT    OffsetKThreadState;
	USHORT    OffsetKThreadBStore;
	USHORT    OffsetKThreadBStoreLimit;

	USHORT    SizeEProcess;
	USHORT    OffsetEprocessPeb;
	USHORT    OffsetEprocessParentCID;
	USHORT    OffsetEprocessDirectoryTableBase;

	USHORT    SizePrcb;
	USHORT    OffsetPrcbDpcRoutine;
	USHORT    OffsetPrcbCurrentThread;
	USHORT    OffsetPrcbMhz;

	USHORT    OffsetPrcbCpuType;
	USHORT    OffsetPrcbVendorString;
	USHORT    OffsetPrcbProcStateContext;
	USHORT    OffsetPrcbNumber;

	USHORT    SizeEThread;

	ULONG64   KdPrintCircularBufferPtr;
	ULONG64   KdPrintBufferSize;

	ULONG64   KeLoaderBlock;

	USHORT    SizePcr;
	USHORT    OffsetPcrSelfPcr;
	USHORT    OffsetPcrCurrentPrcb;
	USHORT    OffsetPcrContainedPrcb;

	USHORT    OffsetPcrInitialBStore;
	USHORT    OffsetPcrBStoreLimit;
	USHORT    OffsetPcrInitialStack;
	USHORT    OffsetPcrStackLimit;

	USHORT    OffsetPrcbPcrPage;
	USHORT    OffsetPrcbProcStateSpecialReg;
	USHORT    GdtR0Code;
	USHORT    GdtR0Data;

	USHORT    GdtR0Pcr;
	USHORT    GdtR3Code;
	USHORT    GdtR3Data;
	USHORT    GdtR3Teb;

	USHORT    GdtLdt;
	USHORT    GdtTss;
	USHORT    Gdt64R3CmCode;
	USHORT    Gdt64R3CmTeb;

	ULONG64   IopNumTriageDumpDataBlocks;
	ULONG64   IopTriageDumpDataBlocks;

	// Longhorn addition

	ULONG64   VfCrashDataBlock;
	ULONG64   MmBadPagesDetected;
	ULONG64   MmZeroedPageSingleBitErrorsDetected;

	// Windows 7 addition

	ULONG64   EtwpDebuggerData;
	USHORT    OffsetPrcbContext;

	// Windows 8 addition

	USHORT    OffsetPrcbMaxBreakpoints;
	USHORT    OffsetPrcbMaxWatchpoints;

	ULONG     OffsetKThreadStackLimit;
	ULONG     OffsetKThreadStackBase;
	ULONG     OffsetKThreadQueueListEntry;
	ULONG     OffsetEThreadIrpList;

	USHORT    OffsetPrcbIdleThread;
	USHORT    OffsetPrcbNormalDpcState;
	USHORT    OffsetPrcbDpcStack;
	USHORT    OffsetPrcbIsrStack;

	USHORT    SizeKDPC_STACK_FRAME;

	// Windows 8.1 Addition

	USHORT    OffsetKPriQueueThreadListHead;
	USHORT    OffsetKThreadWaitReason;

	// Windows 10 RS1 Addition

	USHORT    Padding;
	ULONG64   PteBase;

	// Windows 10 RS5 Addition

	ULONG64 RetpolineStubFunctionTable;
	ULONG RetpolineStubFunctionTableSize;
	ULONG RetpolineStubOffset;
	ULONG RetpolineStubSize;

} KDDEBUGGER_DATA64, * PKDDEBUGGER_DATA64;

typedef struct _DUMP_HEADER
{
	ULONG Signature;
	ULONG ValidDump;
	ULONG MajorVersion;
	ULONG MinorVersion;
	ULONG_PTR DirectoryTableBase;
	ULONG_PTR PfnDataBase;
	PLIST_ENTRY PsLoadedModuleList;
	PLIST_ENTRY PsActiveProcessHead;
	ULONG MachineImageType;
	ULONG NumberProcessors;
	ULONG BugCheckCode;
	ULONG_PTR BugCheckParameter1;
	ULONG_PTR BugCheckParameter2;
	ULONG_PTR BugCheckParameter3;
	ULONG_PTR BugCheckParameter4;
	CHAR VersionUser[32];
	struct _KDDEBUGGER_DATA64* KdDebuggerDataBlock;
} DUMP_HEADER, * PDUMP_HEADER;

struct _MMPTE_HARDWARE
{
	ULONGLONG Valid : 1;                                                      //0x0
	ULONGLONG Dirty1 : 1;                                                     //0x0
	ULONGLONG Owner : 1;                                                      //0x0
	ULONGLONG WriteThrough : 1;                                               //0x0
	ULONGLONG CacheDisable : 1;                                               //0x0
	ULONGLONG Accessed : 1;                                                   //0x0
	ULONGLONG Dirty : 1;                                                      //0x0
	ULONGLONG LargePage : 1;                                                  //0x0
	ULONGLONG Global : 1;                                                     //0x0
	ULONGLONG CopyOnWrite : 1;                                                //0x0
	ULONGLONG Unused : 1;                                                     //0x0
	ULONGLONG Write : 1;                                                      //0x0
	ULONGLONG PageFrameNumber : 36;                                           //0x0
	ULONGLONG ReservedForHardware : 4;                                        //0x0
	ULONGLONG ReservedForSoftware : 4;                                        //0x0
	ULONGLONG WsleAge : 4;                                                    //0x0
	ULONGLONG WsleProtection : 3;                                             //0x0
	ULONGLONG NoExecute : 1;                                                  //0x0
};

typedef struct _MMPTE
{
	union
	{
		ULONGLONG Long;                                                     //0x0
		volatile ULONGLONG VolatileLong;                                    //0x0
		struct _MMPTE_HARDWARE Hard;                                        //0x0
	//	struct _MMPTE_PROTOTYPE Proto;                                      //0x0
	//	struct _MMPTE_SOFTWARE Soft;                                        //0x0
	//	struct _MMPTE_TIMESTAMP TimeStamp;                                  //0x0
	//	struct _MMPTE_TRANSITION Trans;                                     //0x0
	//	struct _MMPTE_SUBSECTION Subsect;                                   //0x0
	//	struct _MMPTE_LIST List;                                            //0x0
	} u;                                                                    //0x0
}  MMPTE, * PMMPTE;

typedef struct _LDR_DATA_TABLE_ENTRY32
{
	LIST_ENTRY32 InLoadOrderLinks;
	LIST_ENTRY32 InMemoryOrderLinks;
	LIST_ENTRY32 InInitializationOrderLinks;
	ULONG DllBase;
	ULONG EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING32 FullDllName;
	UNICODE_STRING32 BaseDllName;
	ULONG Flags;
	USHORT LoadCount;
	USHORT TlsIndex;
	LIST_ENTRY32 HashLinks;
	ULONG TimeDateStamp;
} LDR_DATA_TABLE_ENTRY32, * PLDR_DATA_TABLE_ENTRY32;
typedef struct _LDR_DATA_TABLE_ENTRY
{
	LIST_ENTRY InLoadOrderLinks;
	LIST_ENTRY InMemoryOrderLinks;
	LIST_ENTRY InInitializationOrderLinks;
	PVOID DllBase;
	PVOID EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	ULONG Flags;
	USHORT LoadCount;
	USHORT TlsIndex;
	LIST_ENTRY HashLinks;
	ULONG TimeDateStamp;
} LDR_DATA_TABLE_ENTRY, * PLDR_DATA_TABLE_ENTRY;
typedef struct _PEB_LDR_DATA32
{
	ULONG Length;
	UCHAR Initialized;
	ULONG SsHandle;
	LIST_ENTRY32 InLoadOrderModuleList;
	LIST_ENTRY32 InMemoryOrderModuleList;
	LIST_ENTRY32 InInitializationOrderModuleList;
} PEB_LDR_DATA32, * PPEB_LDR_DATA32;
typedef struct _PEB_LDR_DATA
{
	ULONG Length;
	UCHAR Initialized;
	PVOID SsHandle;
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
} PEB_LDR_DATA, * PPEB_LDR_DATA;
typedef struct _PEB32
{
	UCHAR InheritedAddressSpace;
	UCHAR ReadImageFileExecOptions;
	UCHAR BeingDebugged;
	UCHAR BitField;
	ULONG Mutant;
	ULONG ImageBaseAddress;
	ULONG Ldr;
	ULONG ProcessParameters;
	ULONG SubSystemData;
	ULONG ProcessHeap;
	ULONG FastPebLock;
	ULONG AtlThunkSListPtr;
	ULONG IFEOKey;
	ULONG CrossProcessFlags;
	ULONG UserSharedInfoPtr;
	ULONG SystemReserved;
	ULONG AtlThunkSListPtr32;
	ULONG ApiSetMap;
} PEB32, * PPEB32;
typedef struct _PEB
{
	UCHAR InheritedAddressSpace;
	UCHAR ReadImageFileExecOptions;
	UCHAR BeingDebugged;
	UCHAR BitField;
	PVOID Mutant;
	PVOID ImageBaseAddress;
	PPEB_LDR_DATA Ldr;
	PVOID ProcessParameters;
	PVOID SubSystemData;
	PVOID ProcessHeap;
	PVOID FastPebLock;
	PVOID AtlThunkSListPtr;
	PVOID IFEOKey;
	PVOID CrossProcessFlags;
	PVOID KernelCallbackTable;
	ULONG SystemReserved;
	ULONG AtlThunkSListPtr32;
	PVOID ApiSetMap;
} PEB, * PPEB;

typedef enum _SYSTEM_INFORMATION_CLASS
{
	SystemBasicInformation = 0x0,
	SystemProcessorInformation = 0x1,
	SystemPerformanceInformation = 0x2,
	SystemTimeOfDayInformation = 0x3,
	SystemPathInformation = 0x4,
	SystemProcessInformation = 0x5,
	SystemCallCountInformation = 0x6,
	SystemDeviceInformation = 0x7,
	SystemProcessorPerformanceInformation = 0x8,
	SystemFlagsInformation = 0x9,
	SystemCallTimeInformation = 0xa,
	SystemModuleInformation = 0xb,
	SystemLocksInformation = 0xc,
	SystemStackTraceInformation = 0xd,
	SystemPagedPoolInformation = 0xe,
	SystemNonPagedPoolInformation = 0xf,
	SystemHandleInformation = 0x10,
	SystemObjectInformation = 0x11,
	SystemPageFileInformation = 0x12,
	SystemVdmInstemulInformation = 0x13,
	SystemVdmBopInformation = 0x14,
	SystemFileCacheInformation = 0x15,
	SystemPoolTagInformation = 0x16,
	SystemInterruptInformation = 0x17,
	SystemDpcBehaviorInformation = 0x18,
	SystemFullMemoryInformation = 0x19,
	SystemLoadGdiDriverInformation = 0x1a,
	SystemUnloadGdiDriverInformation = 0x1b,
	SystemTimeAdjustmentInformation = 0x1c,
	SystemSummaryMemoryInformation = 0x1d,
	SystemMirrorMemoryInformation = 0x1e,
	SystemPerformanceTraceInformation = 0x1f,
	SystemObsolete0 = 0x20,
	SystemExceptionInformation = 0x21,
	SystemCrashDumpStateInformation = 0x22,
	SystemKernelDebuggerInformation = 0x23,
	SystemContextSwitchInformation = 0x24,
	SystemRegistryQuotaInformation = 0x25,
	SystemExtendServiceTableInformation = 0x26,
	SystemPrioritySeperation = 0x27,
	SystemVerifierAddDriverInformation = 0x28,
	SystemVerifierRemoveDriverInformation = 0x29,
	SystemProcessorIdleInformation = 0x2a,
	SystemLegacyDriverInformation = 0x2b,
	SystemCurrentTimeZoneInformation = 0x2c,
	SystemLookasideInformation = 0x2d,
	SystemTimeSlipNotification = 0x2e,
	SystemSessionCreate = 0x2f,
	SystemSessionDetach = 0x30,
	SystemSessionInformation = 0x31,
	SystemRangeStartInformation = 0x32,
	SystemVerifierInformation = 0x33,
	SystemVerifierThunkExtend = 0x34,
	SystemSessionProcessInformation = 0x35,
	SystemLoadGdiDriverInSystemSpace = 0x36,
	SystemNumaProcessorMap = 0x37,
	SystemPrefetcherInformation = 0x38,
	SystemExtendedProcessInformation = 0x39,
	SystemRecommendedSharedDataAlignment = 0x3a,
	SystemComPlusPackage = 0x3b,
	SystemNumaAvailableMemory = 0x3c,
	SystemProcessorPowerInformation = 0x3d,
	SystemEmulationBasicInformation = 0x3e,
	SystemEmulationProcessorInformation = 0x3f,
	SystemExtendedHandleInformation = 0x40,
	SystemLostDelayedWriteInformation = 0x41,
	SystemBigPoolInformation = 0x42,
	SystemSessionPoolTagInformation = 0x43,
	SystemSessionMappedViewInformation = 0x44,
	SystemHotpatchInformation = 0x45,
	SystemObjectSecurityMode = 0x46,
	SystemWatchdogTimerHandler = 0x47,
	SystemWatchdogTimerInformation = 0x48,
	SystemLogicalProcessorInformation = 0x49,
	SystemWow64SharedInformationObsolete = 0x4a,
	SystemRegisterFirmwareTableInformationHandler = 0x4b,
	SystemFirmwareTableInformation = 0x4c,
	SystemModuleInformationEx = 0x4d,
	SystemVerifierTriageInformation = 0x4e,
	SystemSuperfetchInformation = 0x4f,
	SystemMemoryListInformation = 0x50,
	SystemFileCacheInformationEx = 0x51,
	SystemThreadPriorityClientIdInformation = 0x52,
	SystemProcessorIdleCycleTimeInformation = 0x53,
	SystemVerifierCancellationInformation = 0x54,
	SystemProcessorPowerInformationEx = 0x55,
	SystemRefTraceInformation = 0x56,
	SystemSpecialPoolInformation = 0x57,
	SystemProcessIdInformation = 0x58,
	SystemErrorPortInformation = 0x59,
	SystemBootEnvironmentInformation = 0x5a,
	SystemHypervisorInformation = 0x5b,
	SystemVerifierInformationEx = 0x5c,
	SystemTimeZoneInformation = 0x5d,
	SystemImageFileExecutionOptionsInformation = 0x5e,
	SystemCoverageInformation = 0x5f,
	SystemPrefetchPatchInformation = 0x60,
	SystemVerifierFaultsInformation = 0x61,
	SystemSystemPartitionInformation = 0x62,
	SystemSystemDiskInformation = 0x63,
	SystemProcessorPerformanceDistribution = 0x64,
	SystemNumaProximityNodeInformation = 0x65,
	SystemDynamicTimeZoneInformation = 0x66,
	SystemCodeIntegrityInformation = 0x67,
	SystemProcessorMicrocodeUpdateInformation = 0x68,
	SystemProcessorBrandString = 0x69,
	SystemVirtualAddressInformation = 0x6a,
	SystemLogicalProcessorAndGroupInformation = 0x6b,
	SystemProcessorCycleTimeInformation = 0x6c,
	SystemStoreInformation = 0x6d,
	SystemRegistryAppendString = 0x6e,
	SystemAitSamplingValue = 0x6f,
	SystemVhdBootInformation = 0x70,
	SystemCpuQuotaInformation = 0x71,
	SystemNativeBasicInformation = 0x72,
	SystemErrorPortTimeouts = 0x73,
	SystemLowPriorityIoInformation = 0x74,
	SystemBootEntropyInformation = 0x75,
	SystemVerifierCountersInformation = 0x76,
	SystemPagedPoolInformationEx = 0x77,
	SystemSystemPtesInformationEx = 0x78,
	SystemNodeDistanceInformation = 0x79,
	SystemAcpiAuditInformation = 0x7a,
	SystemBasicPerformanceInformation = 0x7b,
	SystemQueryPerformanceCounterInformation = 0x7c,
	SystemSessionBigPoolInformation = 0x7d,
	SystemBootGraphicsInformation = 0x7e,
	SystemScrubPhysicalMemoryInformation = 0x7f,
	SystemBadPageInformation = 0x80,
	SystemProcessorProfileControlArea = 0x81,
	SystemCombinePhysicalMemoryInformation = 0x82,
	SystemEntropyInterruptTimingInformation = 0x83,
	SystemConsoleInformation = 0x84,
	SystemPlatformBinaryInformation = 0x85,
	SystemThrottleNotificationInformation = 0x86,
	SystemHypervisorProcessorCountInformation = 0x87,
	SystemDeviceDataInformation = 0x88,
	SystemDeviceDataEnumerationInformation = 0x89,
	SystemMemoryTopologyInformation = 0x8a,
	SystemMemoryChannelInformation = 0x8b,
	SystemBootLogoInformation = 0x8c,
	SystemProcessorPerformanceInformationEx = 0x8d,
	SystemSpare0 = 0x8e,
	SystemSecureBootPolicyInformation = 0x8f,
	SystemPageFileInformationEx = 0x90,
	SystemSecureBootInformation = 0x91,
	SystemEntropyInterruptTimingRawInformation = 0x92,
	SystemPortableWorkspaceEfiLauncherInformation = 0x93,
	SystemFullProcessInformation = 0x94,
	SystemKernelDebuggerInformationEx = 0x95,
	SystemBootMetadataInformation = 0x96,
	SystemSoftRebootInformation = 0x97,
	SystemElamCertificateInformation = 0x98,
	SystemOfflineDumpConfigInformation = 0x99,
	SystemProcessorFeaturesInformation = 0x9a,
	SystemRegistryReconciliationInformation = 0x9b,
	MaxSystemInfoClass = 0x9c,
} SYSTEM_INFORMATION_CLASS;

typedef struct _IMAGE_DOS_HEADER
{
	USHORT e_magic;
	USHORT e_cblp;
	USHORT e_cp;
	USHORT e_crlc;
	USHORT e_cparhdr;
	USHORT e_minalloc;
	USHORT e_maxalloc;
	USHORT e_ss;
	USHORT e_sp;
	USHORT e_csum;
	USHORT e_ip;
	USHORT e_cs;
	USHORT e_lfarlc;
	USHORT e_ovno;
	USHORT e_res[4];
	USHORT e_oemid;
	USHORT e_oeminfo;
	USHORT e_res2[10];
	LONG e_lfanew;
} IMAGE_DOS_HEADER, * PIMAGE_DOS_HEADER;

typedef struct _IMAGE_FILE_HEADER
{
	USHORT Machine;
	USHORT NumberOfSections;
	ULONG TimeDateStamp;
	ULONG PointerToSymbolTable;
	ULONG NumberOfSymbols;
	USHORT SizeOfOptionalHeader;
	USHORT Characteristics;
} IMAGE_FILE_HEADER, * PIMAGE_FILE_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY
{
	ULONG VirtualAddress;
	ULONG Size;
} IMAGE_DATA_DIRECTORY, * PIMAGE_DATA_DIRECTORY;

typedef struct _IMAGE_OPTIONAL_HEADER64
{
	USHORT Magic;
	UCHAR MajorLinkerVersion;
	UCHAR MinorLinkerVersion;
	ULONG SizeOfCode;
	ULONG SizeOfInitializedData;
	ULONG SizeOfUninitializedData;
	ULONG AddressOfEntryPoint;
	ULONG BaseOfCode;
	ULONGLONG ImageBase;
	ULONG SectionAlignment;
	ULONG FileAlignment;
	USHORT MajorOperatingSystemVersion;
	USHORT MinorOperatingSystemVersion;
	USHORT MajorImageVersion;
	USHORT MinorImageVersion;
	USHORT MajorSubsystemVersion;
	USHORT MinorSubsystemVersion;
	ULONG Win32VersionValue;
	ULONG SizeOfImage;
	ULONG SizeOfHeaders;
	ULONG CheckSum;
	USHORT Subsystem;
	USHORT DllCharacteristics;
	ULONGLONG SizeOfStackReserve;
	ULONGLONG SizeOfStackCommit;
	ULONGLONG SizeOfHeapReserve;
	ULONGLONG SizeOfHeapCommit;
	ULONG LoaderFlags;
	ULONG NumberOfRvaAndSizes;
	struct _IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER64, * PIMAGE_OPTIONAL_HEADER64;

typedef struct _IMAGE_NT_HEADERS64
{
	ULONG Signature;
	struct _IMAGE_FILE_HEADER FileHeader;
	struct _IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64, * PIMAGE_NT_HEADERS64;

typedef struct _IMAGE_SECTION_HEADER
{
	UCHAR  Name[8];
	union
	{
		ULONG PhysicalAddress;
		ULONG VirtualSize;
	} Misc;
	ULONG VirtualAddress;
	ULONG SizeOfRawData;
	ULONG PointerToRawData;
	ULONG PointerToRelocations;
	ULONG PointerToLinenumbers;
	USHORT  NumberOfRelocations;
	USHORT  NumberOfLinenumbers;
	ULONG Characteristics;
} IMAGE_SECTION_HEADER, * PIMAGE_SECTION_HEADER;

typedef struct _IMAGE_EXPORT_DIRECTORY
{
	ULONG   Characteristics;
	ULONG   TimeDateStamp;
	USHORT  MajorVersion;
	USHORT  MinorVersion;
	ULONG   Name;
	ULONG   Base;
	ULONG   NumberOfFunctions;
	ULONG   NumberOfNames;
	ULONG   AddressOfFunctions;
	ULONG   AddressOfNames;
	ULONG   AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY, * PIMAGE_EXPORT_DIRECTORY;


typedef struct _MM_AVL_NODE // Size=24
{
	struct _MM_AVL_NODE* LeftChild; // Size=8 Offset=0
	struct _MM_AVL_NODE* RightChild; // Size=8 Offset=8

	union ___unnamed1666 // Size=8
	{
		struct
		{
			__int64 Balance : 2; // Size=8 Offset=0 BitOffset=0 BitCount=2
		};
		struct _MM_AVL_NODE* Parent; // Size=8 Offset=0
	} u1;
} MM_AVL_NODE, * PMM_AVL_NODE, * PMMADDRESS_NODE;

typedef struct _RTL_AVL_TREE // Size=8
{
	PMM_AVL_NODE BalancedRoot;
	void* NodeHint;
	unsigned __int64 NumberGenericTableElements;
} RTL_AVL_TREE, * PRTL_AVL_TREE, MM_AVL_TABLE, * PMM_AVL_TABLE;

union _EX_PUSH_LOCK // Size=8
{
	struct
	{
		unsigned __int64 Locked : 1; // Size=8 Offset=0 BitOffset=0 BitCount=1
		unsigned __int64 Waiting : 1; // Size=8 Offset=0 BitOffset=1 BitCount=1
		unsigned __int64 Waking : 1; // Size=8 Offset=0 BitOffset=2 BitCount=1
		unsigned __int64 MultipleShared : 1; // Size=8 Offset=0 BitOffset=3 BitCount=1
		unsigned __int64 Shared : 60; // Size=8 Offset=0 BitOffset=4 BitCount=60
	};
	unsigned __int64 Value; // Size=8 Offset=0
	void* Ptr; // Size=8 Offset=0
};

struct _MMVAD_FLAGS // Size=4 // PRE 19H1
{
	unsigned long VadType : 3; // Size=4 Offset=0 BitOffset=0 BitCount=3
	unsigned long Protection : 5; // Size=4 Offset=0 BitOffset=3 BitCount=5
	unsigned long PreferredNode : 6; // Size=4 Offset=0 BitOffset=8 BitCount=6
	unsigned long NoChange : 1; // Size=4 Offset=0 BitOffset=14 BitCount=1
	unsigned long PrivateMemory : 1; // Size=4 Offset=0 BitOffset=15 BitCount=1
	unsigned long Teb : 1; // Size=4 Offset=0 BitOffset=16 BitCount=1
	unsigned long PrivateFixup : 1; // Size=4 Offset=0 BitOffset=17 BitCount=1
	unsigned long ManySubsections : 1; // Size=4 Offset=0 BitOffset=18 BitCount=1
	unsigned long Spare : 12; // Size=4 Offset=0 BitOffset=19 BitCount=12
	unsigned long DeleteInProgress : 1; // Size=4 Offset=0 BitOffset=31 BitCount=1
};

struct _MMVAD_FLAGS_19H1
{
	unsigned long Lock : 1;
	unsigned long LockContended : 1;
	unsigned long DeleteInProgress : 1;
	unsigned long NoChange : 1;
	unsigned long VadType : 3;
	unsigned long Protection : 5;
	unsigned long PreferredNode : 6;
	unsigned long PageSize : 2;
	unsigned long PrivateMemory : 1;
};

struct _MMVAD_FLAGS1 // Size=4
{
	unsigned long CommitCharge : 31; // Size=4 Offset=0 BitOffset=0 BitCount=31
	unsigned long MemCommit : 1; // Size=4 Offset=0 BitOffset=31 BitCount=1
};

struct _MMVAD_FLAGS2 // Size=4 // PRE 19H1
{
	unsigned long FileOffset : 24; // Size=4 Offset=0 BitOffset=0 BitCount=24
	unsigned long Large : 1; // Size=4 Offset=0 BitOffset=24 BitCount=1
	unsigned long TrimBehind : 1; // Size=4 Offset=0 BitOffset=25 BitCount=1
	unsigned long Inherit : 1; // Size=4 Offset=0 BitOffset=26 BitCount=1
	unsigned long CopyOnWrite : 1; // Size=4 Offset=0 BitOffset=27 BitCount=1
	unsigned long NoValidationNeeded : 1; // Size=4 Offset=0 BitOffset=28 BitCount=1
	unsigned long Spare : 3; // Size=4 Offset=0 BitOffset=29 BitCount=3
};

struct _MMVAD_FLAGS2_19H1
{
	unsigned long FileOffset : 24;
	unsigned long Large : 1;
	unsigned long TrimBehind : 1;
	unsigned long Inherit : 1;
	unsigned long NoValidationNeeded : 1;
	unsigned long PrivateDemandZero : 1;
	unsigned long Spare : 3;
};

struct _MI_VAD_SEQUENTIAL_INFO // Size=8
{
	unsigned __int64 Length : 12; // Size=8 Offset=0 BitOffset=0 BitCount=12
	unsigned __int64 Vpn : 52; // Size=8 Offset=0 BitOffset=12 BitCount=52
};

union ___unnamed1951 // Size=4
{
	unsigned long LongFlags; // Size=4 Offset=0
	struct _MMVAD_FLAGS VadFlags; // Size=4 Offset=0
};

union ___unnamed1952 // Size=4
{
	unsigned long LongFlags1; // Size=4 Offset=0
	struct _MMVAD_FLAGS1 VadFlags1; // Size=4 Offset=0
};

union ___unnamed2047 // Size=4
{
	unsigned long LongFlags2; // Size=4 Offset=0
	union
	{
		struct _MMVAD_FLAGS2 VadFlags2; // Size=4 Offset=0 // PRE 19H1
		struct _MMVAD_FLAGS2_19H1 VadFlags219H1; // Size=4 Offset=0
	};
};

union ___unnamed2048 // Size=8
{
	struct _MI_VAD_SEQUENTIAL_INFO SequentialVa; // Size=8 Offset=0
	struct _MMEXTEND_INFO* ExtendedInfo; // Size=8 Offset=0
};

typedef struct _MM_PRIVATE_VAD_FLAGS
{
	/* 0x0000 */ unsigned long Lock : 1; /* bit position: 0 */
	/* 0x0000 */ unsigned long LockContended : 1; /* bit position: 1 */
	/* 0x0000 */ unsigned long DeleteInProgress : 1; /* bit position: 2 */
	/* 0x0000 */ unsigned long NoChange : 1; /* bit position: 3 */
	/* 0x0000 */ unsigned long VadType : 3; /* bit position: 4 */
	/* 0x0000 */ unsigned long Protection : 5; /* bit position: 7 */
	/* 0x0000 */ unsigned long PreferredNode : 6; /* bit position: 12 */
	/* 0x0000 */ unsigned long PageSize : 2; /* bit position: 18 */
	/* 0x0000 */ unsigned long PrivateMemoryAlwaysSet : 1; /* bit position: 20 */
	/* 0x0000 */ unsigned long WriteWatch : 1; /* bit position: 21 */
	/* 0x0000 */ unsigned long FixedLargePageSize : 1; /* bit position: 22 */
	/* 0x0000 */ unsigned long ZeroFillPagesOptional : 1; /* bit position: 23 */
	/* 0x0000 */ unsigned long Graphics : 1; /* bit position: 24 */
	/* 0x0000 */ unsigned long Enclave : 1; /* bit position: 25 */
	/* 0x0000 */ unsigned long ShadowStack : 1; /* bit position: 26 */
} MM_PRIVATE_VAD_FLAGS, * PMM_PRIVATE_VAD_FLAGS; /* size: 0x0004 */

typedef struct _MM_GRAPHICS_VAD_FLAGS
{
	/* 0x0000 */ unsigned long Lock : 1; /* bit position: 0 */
	/* 0x0000 */ unsigned long LockContended : 1; /* bit position: 1 */
	/* 0x0000 */ unsigned long DeleteInProgress : 1; /* bit position: 2 */
	/* 0x0000 */ unsigned long NoChange : 1; /* bit position: 3 */
	/* 0x0000 */ unsigned long VadType : 3; /* bit position: 4 */
	/* 0x0000 */ unsigned long Protection : 5; /* bit position: 7 */
	/* 0x0000 */ unsigned long PreferredNode : 6; /* bit position: 12 */
	/* 0x0000 */ unsigned long PageSize : 2; /* bit position: 18 */
	/* 0x0000 */ unsigned long PrivateMemoryAlwaysSet : 1; /* bit position: 20 */
	/* 0x0000 */ unsigned long WriteWatch : 1; /* bit position: 21 */
	/* 0x0000 */ unsigned long FixedLargePageSize : 1; /* bit position: 22 */
	/* 0x0000 */ unsigned long ZeroFillPagesOptional : 1; /* bit position: 23 */
	/* 0x0000 */ unsigned long GraphicsAlwaysSet : 1; /* bit position: 24 */
	/* 0x0000 */ unsigned long GraphicsUseCoherentBus : 1; /* bit position: 25 */
	/* 0x0000 */ unsigned long GraphicsPageProtection : 3; /* bit position: 26 */
} MM_GRAPHICS_VAD_FLAGS, * PMM_GRAPHICS_VAD_FLAGS; /* size: 0x0004 */

typedef struct _MM_SHARED_VAD_FLAGS
{
	/* 0x0000 */ unsigned long Lock : 1; /* bit position: 0 */
	/* 0x0000 */ unsigned long LockContended : 1; /* bit position: 1 */
	/* 0x0000 */ unsigned long DeleteInProgress : 1; /* bit position: 2 */
	/* 0x0000 */ unsigned long NoChange : 1; /* bit position: 3 */
	/* 0x0000 */ unsigned long VadType : 3; /* bit position: 4 */
	/* 0x0000 */ unsigned long Protection : 5; /* bit position: 7 */
	/* 0x0000 */ unsigned long PreferredNode : 6; /* bit position: 12 */
	/* 0x0000 */ unsigned long PageSize : 2; /* bit position: 18 */
	/* 0x0000 */ unsigned long PrivateMemoryAlwaysClear : 1; /* bit position: 20 */
	/* 0x0000 */ unsigned long PrivateFixup : 1; /* bit position: 21 */
	/* 0x0000 */ unsigned long HotPatchAllowed : 1; /* bit position: 22 */
} MM_SHARED_VAD_FLAGS, * PMM_SHARED_VAD_FLAGS; /* size: 0x0004 */

typedef struct _MMVAD_SHORT // Size=64
{
	union
	{
		struct _RTL_BALANCED_NODE VadNode; // Size=24 Offset=0
		struct _MMVAD_SHORT* NextVad; // Size=8 Offset=0
	};
	unsigned long StartingVpn; // Size=4 Offset=24
	unsigned long EndingVpn; // Size=4 Offset=28
	unsigned char StartingVpnHigh; // Size=1 Offset=32
	unsigned char EndingVpnHigh; // Size=1 Offset=33
	unsigned char CommitChargeHigh; // Size=1 Offset=34
	unsigned char SpareNT64VadUChar; // Size=1 Offset=35
	long ReferenceCount; // Size=4 Offset=36
	union _EX_PUSH_LOCK PushLock; // Size=8 Offset=40
	union ___unnamed1951 u; // Size=4 Offset=48
	union ___unnamed1952 u1; // Size=4 Offset=52
	struct _MI_VAD_EVENT_BLOCK* EventList; // Size=8 Offset=56
} MMVAD_SHORT, * PMMVAD_SHORT;

typedef union _EX_FAST_REF // Size=8
{
	void* Object;
	struct
	{
		unsigned __int64 RefCnt : 4;
	};
	unsigned __int64 Value;
} EX_FAST_REF, * PEX_FAST_REF;

typedef struct _CONTROL_AREA // Size=120
{
	struct _SEGMENT* Segment;
	struct _LIST_ENTRY ListHead;
	unsigned __int64 NumberOfSectionReferences;
	unsigned __int64 NumberOfPfnReferences;
	unsigned __int64 NumberOfMappedViews;
	unsigned __int64 NumberOfUserReferences;
	unsigned long f1;
	unsigned long f2;
	EX_FAST_REF FilePointer;
	// Other fields
} CONTROL_AREA, * PCONTROL_AREA;

typedef struct _SUBSECTION // Size=56
{
	PCONTROL_AREA ControlArea;
	// Other fields
} SUBSECTION, * PSUBSECTION;

typedef struct _MMVAD // Size=128
{
	struct _MMVAD_SHORT Core; // Size=64 Offset=0
	union ___unnamed2047 u2; // Size=4 Offset=64
	unsigned long pad0;  // Size=4 Offset=68
	struct _SUBSECTION* Subsection; // Size=8 Offset=72
	struct _MMPTE* FirstPrototypePte; // Size=8 Offset=80
	struct _MMPTE* LastContiguousPte; // Size=8 Offset=88
	struct _LIST_ENTRY ViewLinks; // Size=16 Offset=96
	struct _EPROCESS* VadsProcess; // Size=8 Offset=112
	union ___unnamed2048 u4; // Size=8 Offset=120
	struct _FILE_OBJECT* FileObject; // Size=8 Offset=128
} MMVAD, * PMMVAD;
#pragma pack(pop)

typedef struct _HANDLE_TABLE
{
	ULONG NextHandleNeedingPool;
	long ExtraInfoPages;
	LONG_PTR TableCode;
	PEPROCESS QuotaProcess;
	LIST_ENTRY HandleTableList;
	ULONG UniqueProcessId;
	ULONG Flags;
	EX_PUSH_LOCK HandleContentionEvent;
	EX_PUSH_LOCK HandleTableLock;
	// More fields here...
} HANDLE_TABLE, * PHANDLE_TABLE;

#pragma warning(default : 4214 4201)


typedef enum _MI_VAD_TYPE
{
	VadNone = 0,
	VadDevicePhysicalMemory = 1,
	VadImageMap = 2,
	VadAwe = 3,
	VadWriteWatch = 4,
	VadLargePages = 5,
	VadRotatePhysical = 6,
	VadLargePageSection = 7
} MI_VAD_TYPE;

#define GET_VAD_ROOT(Table) Table->BalancedRoot