//////////////////////////////////////////////////////////////////////////////
//
//  Detours Test Program (_win32.cpp of traceapi.dll)
//
//  Microsoft Research Detours Package
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <winternl.h>
#include <detours/detours.h>

///////////////////////////////////////////////////////////////// Trampolines.
//
int(__stdcall* Real_AbortDoc)(HDC a0)
= AbortDoc;

BOOL(__stdcall* Real_AbortPath)(HDC a0)
= AbortPath;

HKL(__stdcall* Real_ActivateKeyboardLayout)(HKL a0,
    UINT a1)
    = ActivateKeyboardLayout;

ATOM(__stdcall* Real_AddAtomA)(LPCSTR a0)
= AddAtomA;

ATOM(__stdcall* Real_AddAtomW)(LPCWSTR a0)
= AddAtomW;

int(__stdcall* Real_AddFontResourceA)(LPCSTR a0)
= AddFontResourceA;

int(__stdcall* Real_AddFontResourceW)(LPCWSTR a0)
= AddFontResourceW;

BOOL(__stdcall* Real_AdjustWindowRect)(LPRECT a0,
    DWORD a1,
    BOOL a2)
    = AdjustWindowRect;

BOOL(__stdcall* Real_AdjustWindowRectEx)(LPRECT a0,
    DWORD a1,
    BOOL a2,
    DWORD a3)
    = AdjustWindowRectEx;

BOOL(__stdcall* Real_AllocConsole)(void)
= AllocConsole;

BOOL(__stdcall* Real_AngleArc)(HDC a0,
    int a1,
    int a2,
    DWORD a3,
    FLOAT a4,
    FLOAT a5)
    = AngleArc;

BOOL(__stdcall* Real_AnimatePalette)(HPALETTE a0,
    UINT a1,
    UINT a2,
    CONST PALETTEENTRY* a3)
    = AnimatePalette;

BOOL(__stdcall* Real_AnyPopup)(void)
= AnyPopup;

BOOL(__stdcall* Real_AppendMenuA)(HMENU a0,
    UINT a1,
    UINT_PTR a2,
    LPCSTR a3)
    = AppendMenuA;

BOOL(__stdcall* Real_AppendMenuW)(HMENU a0,
    UINT a1,
    UINT_PTR a2,
    LPCWSTR a3)
    = AppendMenuW;

BOOL(__stdcall* Real_Arc)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
    = Arc;

BOOL(__stdcall* Real_ArcTo)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
    = ArcTo;

BOOL(__stdcall* Real_AreFileApisANSI)(void)
= AreFileApisANSI;

UINT(__stdcall* Real_ArrangeIconicWindows)(HWND a0)
= ArrangeIconicWindows;

BOOL(__stdcall* Real_AttachThreadInput)(DWORD a0,
    DWORD a1,
    BOOL a2)
    = AttachThreadInput;

BOOL(__stdcall* Real_BackupRead)(HANDLE a0,
    LPBYTE a1,
    DWORD a2,
    LPDWORD a3,
    BOOL a4,
    BOOL a5,
    LPVOID* a6)
    = BackupRead;

BOOL(__stdcall* Real_BackupSeek)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPVOID* a5)
    = BackupSeek;

BOOL(__stdcall* Real_BackupWrite)(HANDLE a0,
    LPBYTE a1,
    DWORD a2,
    LPDWORD a3,
    BOOL a4,
    BOOL a5,
    LPVOID* a6)
    = BackupWrite;

BOOL(__stdcall* Real_Beep)(DWORD a0,
    DWORD a1)
    = Beep;

HDWP(__stdcall* Real_BeginDeferWindowPos)(int a0)
= BeginDeferWindowPos;

HDC(__stdcall* Real_BeginPaint)(HWND a0,
    LPPAINTSTRUCT a1)
    = BeginPaint;

BOOL(__stdcall* Real_BeginPath)(HDC a0)
= BeginPath;

HANDLE(__stdcall* Real_BeginUpdateResourceA)(LPCSTR a0,
    BOOL a1)
    = BeginUpdateResourceA;

HANDLE(__stdcall* Real_BeginUpdateResourceW)(LPCWSTR a0,
    BOOL a1)
    = BeginUpdateResourceW;

HRESULT(__stdcall* Real_BindMoniker)(IMoniker* a0,
    DWORD a1,
    CONST IID& a2,
    LPVOID* a3)
    = BindMoniker;

BOOL(__stdcall* Real_BitBlt)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    HDC a5,
    int a6,
    int a7,
    DWORD a8)
    = BitBlt;

BOOL(__stdcall* Real_BringWindowToTop)(HWND a0)
= BringWindowToTop;

long(__stdcall* Real_BroadcastSystemMessageA)(DWORD a0,
    LPDWORD a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
    = BroadcastSystemMessageA;

long(__stdcall* Real_BroadcastSystemMessageW)(DWORD a0,
    LPDWORD a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
    = BroadcastSystemMessageW;

BOOL(__stdcall* Real_BuildCommDCBA)(LPCSTR a0,
    LPDCB a1)
    = BuildCommDCBA;

BOOL(__stdcall* Real_BuildCommDCBAndTimeoutsA)(LPCSTR a0,
    LPDCB a1,
    LPCOMMTIMEOUTS a2)
    = BuildCommDCBAndTimeoutsA;

BOOL(__stdcall* Real_BuildCommDCBAndTimeoutsW)(LPCWSTR a0,
    LPDCB a1,
    LPCOMMTIMEOUTS a2)
    = BuildCommDCBAndTimeoutsW;

BOOL(__stdcall* Real_BuildCommDCBW)(LPCWSTR a0,
    LPDCB a1)
    = BuildCommDCBW;

HRESULT(__stdcall* Real_CLSIDFromProgID)(LPCOLESTR a0,
    LPGUID a1)
    = CLSIDFromProgID;

#ifdef _WIN32_WINNT_WIN7
HRESULT(__stdcall* Real_CLSIDFromString)(LPCOLESTR a0,
    LPGUID a1)
    = CLSIDFromString;
#else
HRESULT(__stdcall* Real_CLSIDFromString)(LPOLESTR a0,
    LPGUID a1)
    = CLSIDFromString;
#endif

BOOL(__stdcall* Real_CallMsgFilterA)(LPMSG a0,
    int a1)
    = CallMsgFilterA;

BOOL(__stdcall* Real_CallMsgFilterW)(LPMSG a0,
    int a1)
    = CallMsgFilterW;

BOOL(__stdcall* Real_CallNamedPipeA)(LPCSTR a0,
    LPVOID a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4,
    LPDWORD a5,
    DWORD a6)
    = CallNamedPipeA;

BOOL(__stdcall* Real_CallNamedPipeW)(LPCWSTR a0,
    LPVOID a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4,
    LPDWORD a5,
    DWORD a6)
    = CallNamedPipeW;

LRESULT(__stdcall* Real_CallNextHookEx)(HHOOK a0,
    int a1,
    WPARAM a2,
    LPARAM a3)
    = CallNextHookEx;

LRESULT(__stdcall* Real_CallWindowProcA)(WNDPROC a0,
    HWND a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
    = CallWindowProcA;

LRESULT(__stdcall* Real_CallWindowProcW)(WNDPROC a0,
    HWND a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
    = CallWindowProcW;

BOOL(__stdcall* Real_CancelDC)(HDC a0)
= CancelDC;

BOOL(__stdcall* Real_CancelIo)(HANDLE a0)
= CancelIo;

BOOL(__stdcall* Real_CancelWaitableTimer)(HANDLE a0)
= CancelWaitableTimer;

WORD(__stdcall* Real_CascadeWindows)(HWND a0,
    UINT a1,
    CONST RECT* a2,
    UINT a3,
    CONST HWND* a4)
    = CascadeWindows;

BOOL(__stdcall* Real_ChangeClipboardChain)(HWND a0,
    HWND a1)
    = ChangeClipboardChain;

LONG(__stdcall* Real_ChangeDisplaySettingsA)(LPDEVMODEA a0,
    DWORD a1)
    = ChangeDisplaySettingsA;

LONG(__stdcall* Real_ChangeDisplaySettingsExA)(LPCSTR a0,
    LPDEVMODEA a1,
    HWND a2,
    DWORD a3,
    LPVOID a4)
    = ChangeDisplaySettingsExA;

LONG(__stdcall* Real_ChangeDisplaySettingsExW)(LPCWSTR a0,
    LPDEVMODEW a1,
    HWND a2,
    DWORD a3,
    LPVOID a4)
    = ChangeDisplaySettingsExW;

LONG(__stdcall* Real_ChangeDisplaySettingsW)(LPDEVMODEW a0,
    DWORD a1)
    = ChangeDisplaySettingsW;

BOOL(__stdcall* Real_ChangeMenuA)(HMENU a0,
    UINT a1,
    LPCSTR a2,
    UINT a3,
    UINT a4)
    = ChangeMenuA;

BOOL(__stdcall* Real_ChangeMenuW)(HMENU a0,
    UINT a1,
    LPCWSTR a2,
    UINT a3,
    UINT a4)
    = ChangeMenuW;

LPSTR(__stdcall* Real_CharLowerA)(LPSTR a0)
= CharLowerA;

DWORD(__stdcall* Real_CharLowerBuffA)(LPSTR a0,
    DWORD a1)
    = CharLowerBuffA;

DWORD(__stdcall* Real_CharLowerBuffW)(LPWSTR a0,
    DWORD a1)
    = CharLowerBuffW;

LPWSTR(__stdcall* Real_CharLowerW)(LPWSTR a0)
= CharLowerW;

LPSTR(__stdcall* Real_CharNextA)(LPCSTR a0)
= CharNextA;

LPSTR(__stdcall* Real_CharNextExA)(WORD a0,
    LPCSTR a1,
    DWORD a2)
    = CharNextExA;

LPWSTR(__stdcall* Real_CharNextW)(LPCWSTR a0)
= CharNextW;

LPSTR(__stdcall* Real_CharPrevA)(LPCSTR a0,
    LPCSTR a1)
    = CharPrevA;

LPSTR(__stdcall* Real_CharPrevExA)(WORD a0,
    LPCSTR a1,
    LPCSTR a2,
    DWORD a3)
    = CharPrevExA;

LPWSTR(__stdcall* Real_CharPrevW)(LPCWSTR a0,
    LPCWSTR a1)
    = CharPrevW;

BOOL(__stdcall* Real_CharToOemA)(LPCSTR a0,
    LPSTR a1)
    = CharToOemA;

BOOL(__stdcall* Real_CharToOemBuffA)(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
    = CharToOemBuffA;

BOOL(__stdcall* Real_CharToOemBuffW)(LPCWSTR a0,
    LPSTR a1,
    DWORD a2)
    = CharToOemBuffW;

BOOL(__stdcall* Real_CharToOemW)(LPCWSTR a0,
    LPSTR a1)
    = CharToOemW;

LPSTR(__stdcall* Real_CharUpperA)(LPSTR a0)
= CharUpperA;

DWORD(__stdcall* Real_CharUpperBuffA)(LPSTR a0,
    DWORD a1)
    = CharUpperBuffA;

DWORD(__stdcall* Real_CharUpperBuffW)(LPWSTR a0,
    DWORD a1)
    = CharUpperBuffW;

LPWSTR(__stdcall* Real_CharUpperW)(LPWSTR a0)
= CharUpperW;

BOOL(__stdcall* Real_CheckColorsInGamut)(
    HDC a0,
#ifdef GDIPLUS_TS_QUERYVER
    LPRGBTRIPLE a1,
#else
    LPVOID a1,
#endif
    LPVOID a2,
    DWORD a3
    )
    = CheckColorsInGamut;

BOOL(__stdcall* Real_CheckDlgButton)(HWND a0,
    int a1,
    UINT a2)
    = CheckDlgButton;

DWORD(__stdcall* Real_CheckMenuItem)(HMENU a0,
    UINT a1,
    UINT a2)
    = CheckMenuItem;

BOOL(__stdcall* Real_CheckMenuRadioItem)(HMENU a0,
    UINT a1,
    UINT a2,
    UINT a3,
    UINT a4)
    = CheckMenuRadioItem;

BOOL(__stdcall* Real_CheckRadioButton)(HWND a0,
    int a1,
    int a2,
    int a3)
    = CheckRadioButton;

HWND(__stdcall* Real_ChildWindowFromPoint)(HWND a0,
    POINT a1)
    = ChildWindowFromPoint;

HWND(__stdcall* Real_ChildWindowFromPointEx)(HWND a0,
    POINT a1,
    UINT a2)
    = ChildWindowFromPointEx;

int(__stdcall* Real_ChoosePixelFormat)(HDC a0,
    CONST PIXELFORMATDESCRIPTOR* a1)
    = ChoosePixelFormat;

BOOL(__stdcall* Real_Chord)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
    = Chord;

BOOL(__stdcall* Real_ClearCommBreak)(HANDLE a0)
= ClearCommBreak;

BOOL(__stdcall* Real_ClearCommError)(HANDLE a0,
    LPDWORD a1,
    LPCOMSTAT a2)
    = ClearCommError;

BOOL(__stdcall* Real_ClientToScreen)(HWND a0,
    LPPOINT a1)
    = ClientToScreen;

BOOL(__stdcall* Real_ClipCursor)(CONST RECT* a0)
= ClipCursor;

BOOL(__stdcall* Real_CloseClipboard)(void)
= CloseClipboard;

BOOL(__stdcall* Real_CloseDesktop)(HDESK a0)
= CloseDesktop;

HENHMETAFILE(__stdcall* Real_CloseEnhMetaFile)(HDC a0)
= CloseEnhMetaFile;

BOOL(__stdcall* Real_CloseFigure)(HDC a0)
= CloseFigure;

BOOL(__stdcall* Real_CloseHandle)(HANDLE a0)
= CloseHandle;

HMETAFILE(__stdcall* Real_CloseMetaFile)(HDC a0)
= CloseMetaFile;

BOOL(__stdcall* Real_CloseWindow)(HWND a0)
= CloseWindow;

BOOL(__stdcall* Real_CloseWindowStation)(HWINSTA a0)
= CloseWindowStation;

ULONG(__stdcall* Real_CoAddRefServerProcess)(void)
= CoAddRefServerProcess;

DWORD(__stdcall* Real_CoBuildVersion)(void)
= CoBuildVersion;

HRESULT(__stdcall* Real_CoCopyProxy)(IUnknown* a0,
    IUnknown** a1)
    = CoCopyProxy;

HRESULT(__stdcall* Real_CoCreateFreeThreadedMarshaler)(LPUNKNOWN a0,
    LPUNKNOWN* a1)
    = CoCreateFreeThreadedMarshaler;

HRESULT(__stdcall* Real_CoCreateGuid)(GUID* a0)
= CoCreateGuid;

HRESULT(__stdcall* Real_CoCreateInstance)(CONST IID& a0,
    LPUNKNOWN a1,
    DWORD a2,
    CONST IID& a3,
    LPVOID* a4)
    = CoCreateInstance;

HRESULT(__stdcall* Real_CoCreateInstanceEx)(CONST IID& a0,
    IUnknown* a1,
    DWORD a2,
    COSERVERINFO* a3,
    DWORD a4,
    MULTI_QI* a5)
    = CoCreateInstanceEx;

HRESULT(__stdcall* Real_CoDisconnectObject)(LPUNKNOWN a0,
    DWORD a1)
    = CoDisconnectObject;

BOOL(__stdcall* Real_CoDosDateTimeToFileTime)(WORD a0,
    WORD a1,
    FILETIME* a2)
    = CoDosDateTimeToFileTime;

HRESULT(__stdcall* Real_CoFileTimeNow)(FILETIME* a0)
= CoFileTimeNow;

BOOL(__stdcall* Real_CoFileTimeToDosDateTime)(FILETIME* a0,
    LPWORD a1,
    LPWORD a2)
    = CoFileTimeToDosDateTime;

void(__stdcall* Real_CoFreeAllLibraries)(void)
= CoFreeAllLibraries;

void(__stdcall* Real_CoFreeLibrary)(HINSTANCE a0)
= CoFreeLibrary;

void(__stdcall* Real_CoFreeUnusedLibraries)(void)
= CoFreeUnusedLibraries;

HRESULT(__stdcall* Real_CoGetCallContext)(CONST IID& a0,
    void** a1)
    = CoGetCallContext;

HRESULT(__stdcall* Real_CoGetClassObject)(CONST IID& a0,
    DWORD a1,
    LPVOID a2,
    CONST IID& a3,
    LPVOID* a4)
    = CoGetClassObject;

DWORD(__stdcall* Real_CoGetCurrentProcess)(void)
= CoGetCurrentProcess;

HRESULT(__stdcall* Real_CoGetInstanceFromFile)(COSERVERINFO* a0,
    CLSID* a1,
    IUnknown* a2,
    DWORD a3,
    DWORD a4,
    OLECHAR* a5,
    DWORD a6,
    MULTI_QI* a7)
    = CoGetInstanceFromFile;

HRESULT(__stdcall* Real_CoGetInstanceFromIStorage)(COSERVERINFO* a0,
    CLSID* a1,
    IUnknown* a2,
    DWORD a3,
    IStorage* a4,
    DWORD a5,
    MULTI_QI* a6)
    = CoGetInstanceFromIStorage;

HRESULT(__stdcall* Real_CoGetInterfaceAndReleaseStream)(LPSTREAM a0,
    CONST IID& a1,
    LPVOID* a2)
    = CoGetInterfaceAndReleaseStream;

HRESULT(__stdcall* Real_CoGetMalloc)(DWORD a0,
    IMalloc** a1)
    = CoGetMalloc;

HRESULT(__stdcall* Real_CoGetMarshalSizeMax)(ULONG* a0,
    CONST IID& a1,
    LPUNKNOWN a2,
    DWORD a3,
    LPVOID a4,
    DWORD a5)
    = CoGetMarshalSizeMax;

HRESULT(__stdcall* Real_CoGetObject)(LPCWSTR a0,
    BIND_OPTS* a1,
    CONST IID& a2,
    void** a3)
    = CoGetObject;

HRESULT(__stdcall* Real_CoGetPSClsid)(CONST IID& a0,
    CLSID* a1)
    = CoGetPSClsid;

HRESULT(__stdcall* Real_CoGetStandardMarshal)(CONST IID& a0,
    LPUNKNOWN a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4,
    IMarshal** a5)
    = CoGetStandardMarshal;

HRESULT(__stdcall* Real_CoGetStdMarshalEx)(LPUNKNOWN a0,
    DWORD a1,
    LPUNKNOWN* a2)
    = CoGetStdMarshalEx;

HRESULT(__stdcall* Real_CoGetTreatAsClass)(CONST IID& a0,
    LPGUID a1)
    = CoGetTreatAsClass;

HRESULT(__stdcall* Real_CoImpersonateClient)(void)
= CoImpersonateClient;

HRESULT(__stdcall* Real_CoInitialize)(LPVOID a0)
= CoInitialize;

HRESULT(__stdcall* Real_CoInitializeEx)(LPVOID a0,
    DWORD a1)
    = CoInitializeEx;

HRESULT(__stdcall* Real_CoInitializeSecurity)(PSECURITY_DESCRIPTOR a0,
    LONG a1,
    SOLE_AUTHENTICATION_SERVICE* a2,
    void* a3,
    DWORD a4,
    DWORD a5,
    void* a6,
    DWORD a7,
    void* a8)
    = CoInitializeSecurity;

BOOL(__stdcall* Real_CoIsHandlerConnected)(LPUNKNOWN a0)
= CoIsHandlerConnected;

BOOL(__stdcall* Real_CoIsOle1Class)(CONST IID& a0)
= CoIsOle1Class;

HINSTANCE(__stdcall* Real_CoLoadLibrary)(LPOLESTR a0,
    BOOL a1)
    = CoLoadLibrary;

HRESULT(__stdcall* Real_CoLockObjectExternal)(LPUNKNOWN a0,
    BOOL a1,
    BOOL a2)
    = CoLockObjectExternal;

HRESULT(__stdcall* Real_CoMarshalHresult)(LPSTREAM a0,
    HRESULT a1)
    = CoMarshalHresult;

HRESULT(__stdcall* Real_CoMarshalInterThreadInterfaceInStream)(CONST IID& a0,
    LPUNKNOWN a1,
    LPSTREAM* a2)
    = CoMarshalInterThreadInterfaceInStream;

HRESULT(__stdcall* Real_CoMarshalInterface)(LPSTREAM a0,
    CONST IID& a1,
    LPUNKNOWN a2,
    DWORD a3,
    LPVOID a4,
    DWORD a5)
    = CoMarshalInterface;

HRESULT(__stdcall* Real_CoQueryAuthenticationServices)(DWORD* a0,
    SOLE_AUTHENTICATION_SERVICE** a1)
    = CoQueryAuthenticationServices;

HRESULT(__stdcall* Real_CoQueryClientBlanket)(DWORD* a0,
    DWORD* a1,
    OLECHAR** a2,
    DWORD* a3,
    DWORD* a4,
    RPC_AUTHZ_HANDLE* a5,
    DWORD* a6)
    = CoQueryClientBlanket;

HRESULT(__stdcall* Real_CoQueryProxyBlanket)(IUnknown* a0,
    DWORD* a1,
    DWORD* a2,
    OLECHAR** a3,
    DWORD* a4,
    DWORD* a5,
    RPC_AUTH_IDENTITY_HANDLE* a6,
    DWORD* a7)
    = CoQueryProxyBlanket;

HRESULT(__stdcall* Real_CoRegisterChannelHook)(CONST GUID& a0,
    IChannelHook* a1)
    = CoRegisterChannelHook;

HRESULT(__stdcall* Real_CoRegisterClassObject)(CONST IID& a0,
    LPUNKNOWN a1,
    DWORD a2,
    DWORD a3,
    LPDWORD a4)
    = CoRegisterClassObject;

HRESULT(__stdcall* Real_CoRegisterMallocSpy)(IMallocSpy* a0)
= CoRegisterMallocSpy;

HRESULT(__stdcall* Real_CoRegisterMessageFilter)(LPMESSAGEFILTER a0,
    LPMESSAGEFILTER* a1)
    = CoRegisterMessageFilter;

HRESULT(__stdcall* Real_CoRegisterPSClsid)(CONST IID& a0,
    CONST IID& a1)
    = CoRegisterPSClsid;

HRESULT(__stdcall* Real_CoRegisterSurrogate)(LPSURROGATE a0)
= CoRegisterSurrogate;

HRESULT(__stdcall* Real_CoReleaseMarshalData)(LPSTREAM a0)
= CoReleaseMarshalData;

ULONG(__stdcall* Real_CoReleaseServerProcess)(void)
= CoReleaseServerProcess;

HRESULT(__stdcall* Real_CoResumeClassObjects)(void)
= CoResumeClassObjects;

HRESULT(__stdcall* Real_CoRevertToSelf)(void)
= CoRevertToSelf;

HRESULT(__stdcall* Real_CoRevokeClassObject)(DWORD a0)
= CoRevokeClassObject;

HRESULT(__stdcall* Real_CoRevokeMallocSpy)(void)
= CoRevokeMallocSpy;

HRESULT(__stdcall* Real_CoSetProxyBlanket)(IUnknown* a0,
    DWORD a1,
    DWORD a2,
    OLECHAR* a3,
    DWORD a4,
    DWORD a5,
    RPC_AUTH_IDENTITY_HANDLE a6,
    DWORD a7)
    = CoSetProxyBlanket;

HRESULT(__stdcall* Real_CoSuspendClassObjects)(void)
= CoSuspendClassObjects;

HRESULT(__stdcall* Real_CoSwitchCallContext)(IUnknown* a0,
    IUnknown** a1)
    = CoSwitchCallContext;

LPVOID(__stdcall* Real_CoTaskMemAlloc)(SIZE_T a0)
= CoTaskMemAlloc;

void(__stdcall* Real_CoTaskMemFree)(LPVOID a0)
= CoTaskMemFree;

LPVOID(__stdcall* Real_CoTaskMemRealloc)(LPVOID a0,
    SIZE_T a1)
    = CoTaskMemRealloc;

HRESULT(__stdcall* Real_CoTreatAsClass)(CONST IID& a0,
    CONST IID& a1)
    = CoTreatAsClass;

void(__stdcall* Real_CoUninitialize)(void)
= CoUninitialize;

HRESULT(__stdcall* Real_CoUnmarshalHresult)(LPSTREAM a0,
    HRESULT* a1)
    = CoUnmarshalHresult;

HRESULT(__stdcall* Real_CoUnmarshalInterface)(LPSTREAM a0,
    CONST IID& a1,
    LPVOID* a2)
    = CoUnmarshalInterface;

BOOL(__stdcall* Real_ColorMatchToTarget)(HDC a0,
    HDC a1,
    DWORD a2)
    = ColorMatchToTarget;

int(__stdcall* Real_CombineRgn)(HRGN a0,
    HRGN a1,
    HRGN a2,
    int a3)
    = CombineRgn;

BOOL(__stdcall* Real_CombineTransform)(LPXFORM a0,
    CONST XFORM* a1,
    CONST XFORM* a2)
    = CombineTransform;

BOOL(__stdcall* Real_CommConfigDialogA)(LPCSTR a0,
    HWND a1,
    LPCOMMCONFIG a2)
    = CommConfigDialogA;

BOOL(__stdcall* Real_CommConfigDialogW)(LPCWSTR a0,
    HWND a1,
    LPCOMMCONFIG a2)
    = CommConfigDialogW;

LONG(__stdcall* Real_CompareFileTime)(CONST FILETIME* a0,
    CONST FILETIME* a1)
    = CompareFileTime;

int(__stdcall* Real_CompareStringA)(LCID a0,
    DWORD a1,
    LPCSTR a2,
    int a3,
    LPCSTR a4,
    int a5)
    = CompareStringA;

int(__stdcall* Real_CompareStringW)(LCID a0,
    DWORD a1,
    LPCWSTR a2,
    int a3,
    LPCWSTR a4,
    int a5)
    = CompareStringW;

BOOL(__stdcall* Real_ConnectNamedPipe)(HANDLE a0,
    LPOVERLAPPED a1)
    = ConnectNamedPipe;

#if !defined(DETOURS_ARM)
BOOL(__stdcall* Real_ContinueDebugEvent)(DWORD a0,
    DWORD a1,
    DWORD a2)
    = ContinueDebugEvent;
#endif // !DETOURS_ARM

LCID(__stdcall* Real_ConvertDefaultLocale)(LCID a0)
= ConvertDefaultLocale;

LPVOID(__stdcall* Real_ConvertThreadToFiber)(LPVOID a0)
= ConvertThreadToFiber;

int(__stdcall* Real_CopyAcceleratorTableA)(HACCEL a0,
    LPACCEL a1,
    int a2)
    = CopyAcceleratorTableA;

int(__stdcall* Real_CopyAcceleratorTableW)(HACCEL a0,
    LPACCEL a1,
    int a2)
    = CopyAcceleratorTableW;

HENHMETAFILE(__stdcall* Real_CopyEnhMetaFileA)(HENHMETAFILE a0,
    LPCSTR a1)
    = CopyEnhMetaFileA;

HENHMETAFILE(__stdcall* Real_CopyEnhMetaFileW)(HENHMETAFILE a0,
    LPCWSTR a1)
    = CopyEnhMetaFileW;

BOOL(__stdcall* Real_CopyFileA)(LPCSTR a0,
    LPCSTR a1,
    BOOL a2)
    = CopyFileA;

BOOL(__stdcall* Real_CopyFileExA)(LPCSTR a0,
    LPCSTR a1,
    LPPROGRESS_ROUTINE a2,
    LPVOID a3,
    LPBOOL a4,
    DWORD a5)
    = CopyFileExA;

BOOL(__stdcall* Real_CopyFileExW)(LPCWSTR a0,
    LPCWSTR a1,
    LPPROGRESS_ROUTINE a2,
    LPVOID a3,
    LPBOOL a4,
    DWORD a5)
    = CopyFileExW;

BOOL(__stdcall* Real_CopyFileW)(LPCWSTR a0,
    LPCWSTR a1,
    BOOL a2)
    = CopyFileW;

HICON(__stdcall* Real_CopyIcon)(HICON a0)
= CopyIcon;

HANDLE(__stdcall* Real_CopyImage)(HANDLE a0,
    UINT a1,
    int a2,
    int a3,
    UINT a4)
    = CopyImage;

HMETAFILE(__stdcall* Real_CopyMetaFileA)(HMETAFILE a0,
    LPCSTR a1)
    = CopyMetaFileA;

HMETAFILE(__stdcall* Real_CopyMetaFileW)(HMETAFILE a0,
    LPCWSTR a1)
    = CopyMetaFileW;

BOOL(__stdcall* Real_CopyRect)(LPRECT a0,
    CONST RECT* a1)
    = CopyRect;

int(__stdcall* Real_CountClipboardFormats)(void)
= CountClipboardFormats;

HACCEL(__stdcall* Real_CreateAcceleratorTableA)(LPACCEL a0,
    int a1)
    = CreateAcceleratorTableA;

HACCEL(__stdcall* Real_CreateAcceleratorTableW)(LPACCEL a0,
    int a1)
    = CreateAcceleratorTableW;

HRESULT(__stdcall* Real_CreateAntiMoniker)(IMoniker** a0)
= CreateAntiMoniker;

HRESULT(__stdcall* Real_CreateBindCtx)(DWORD a0,
    IBindCtx** a1)
    = CreateBindCtx;

HBITMAP(__stdcall* Real_CreateBitmap)(int a0,
    int a1,
    UINT a2,
    UINT a3,
    CONST void* a4)
    = CreateBitmap;

HBITMAP(__stdcall* Real_CreateBitmapIndirect)(CONST BITMAP* a0)
= CreateBitmapIndirect;

HBRUSH(__stdcall* Real_CreateBrushIndirect)(CONST LOGBRUSH* a0)
= CreateBrushIndirect;

BOOL(__stdcall* Real_CreateCaret)(HWND a0,
    HBITMAP a1,
    int a2,
    int a3)
    = CreateCaret;

HRESULT(__stdcall* Real_CreateClassMoniker)(CONST IID& a0,
    IMoniker** a1)
    = CreateClassMoniker;

HCOLORSPACE(__stdcall* Real_CreateColorSpaceA)(LPLOGCOLORSPACEA a0)
= CreateColorSpaceA;

HCOLORSPACE(__stdcall* Real_CreateColorSpaceW)(LPLOGCOLORSPACEW a0)
= CreateColorSpaceW;

HBITMAP(__stdcall* Real_CreateCompatibleBitmap)(HDC a0,
    int a1,
    int a2)
    = CreateCompatibleBitmap;

HDC(__stdcall* Real_CreateCompatibleDC)(HDC a0)
= CreateCompatibleDC;

HANDLE(__stdcall* Real_CreateConsoleScreenBuffer)(DWORD a0,
    DWORD a1,
    CONST SECURITY_ATTRIBUTES* a2,
    DWORD a3,
    LPVOID a4)
    = CreateConsoleScreenBuffer;

HCURSOR(__stdcall* Real_CreateCursor)(HINSTANCE a0,
    int a1,
    int a2,
    int a3,
    int a4,
    CONST void* a5,
    CONST void* a6)
    = CreateCursor;

HDC(__stdcall* Real_CreateDCA)(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    CONST DEVMODEA* a3)
    = CreateDCA;

HDC(__stdcall* Real_CreateDCW)(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    CONST DEVMODEW* a3)
    = CreateDCW;

HBRUSH(__stdcall* Real_CreateDIBPatternBrush)(HGLOBAL a0,
    UINT a1)
    = CreateDIBPatternBrush;

HBRUSH(__stdcall* Real_CreateDIBPatternBrushPt)(CONST void* a0,
    UINT a1)
    = CreateDIBPatternBrushPt;

HBITMAP(__stdcall* Real_CreateDIBSection)(HDC a0,
    CONST BITMAPINFO* a1,
    UINT a2,
    void** a3,
    HANDLE a4,
    DWORD a5)
    = CreateDIBSection;

HBITMAP(__stdcall* Real_CreateDIBitmap)(HDC a0,
    CONST BITMAPINFOHEADER* a1,
    DWORD a2,
    CONST void* a3,
    CONST BITMAPINFO* a4,
    UINT a5)
    = CreateDIBitmap;

HRESULT(__stdcall* Real_CreateDataAdviseHolder)(LPDATAADVISEHOLDER* a0)
= CreateDataAdviseHolder;

HRESULT(__stdcall* Real_CreateDataCache)(LPUNKNOWN a0,
    CONST IID& a1,
    CONST IID& a2,
    LPVOID* a3)
    = CreateDataCache;

#if _MSC_VER < 1300
HDESK(__stdcall* Real_CreateDesktopA)(LPSTR a0,
    LPSTR a1,
    LPDEVMODEA a2,
    DWORD a3,
    ACCESS_MASK a4,
    LPSECURITY_ATTRIBUTES a5)
    = CreateDesktopA;
#else
HDESK(__stdcall* Real_CreateDesktopA)(LPCSTR a0,
    LPCSTR a1,
    LPDEVMODEA a2,
    DWORD a3,
    ACCESS_MASK a4,
    LPSECURITY_ATTRIBUTES a5)
    = CreateDesktopA;

#endif

#if _MSC_VER < 1300
HDESK(__stdcall* Real_CreateDesktopW)(LPWSTR a0,
    LPWSTR a1,
    LPDEVMODEW a2,
    DWORD a3,
    ACCESS_MASK a4,
    LPSECURITY_ATTRIBUTES a5)
    = CreateDesktopW;
#else
HDESK(__stdcall* Real_CreateDesktopW)(LPCWSTR a0,
    LPCWSTR a1,
    LPDEVMODEW a2,
    DWORD a3,
    ACCESS_MASK a4,
    LPSECURITY_ATTRIBUTES a5)
    = CreateDesktopW;
#endif

HWND(__stdcall* Real_CreateDialogIndirectParamA)(HINSTANCE a0,
    LPCDLGTEMPLATEA a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
    = CreateDialogIndirectParamA;

HWND(__stdcall* Real_CreateDialogIndirectParamW)(HINSTANCE a0,
    LPCDLGTEMPLATEW a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
    = CreateDialogIndirectParamW;

HWND(__stdcall* Real_CreateDialogParamA)(HINSTANCE a0,
    LPCSTR a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
    = CreateDialogParamA;

HWND(__stdcall* Real_CreateDialogParamW)(HINSTANCE a0,
    LPCWSTR a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
    = CreateDialogParamW;

BOOL(__stdcall* Real_CreateDirectoryA)(LPCSTR a0,
    LPSECURITY_ATTRIBUTES a1)
    = CreateDirectoryA;

BOOL(__stdcall* Real_CreateDirectoryExA)(LPCSTR a0,
    LPCSTR a1,
    LPSECURITY_ATTRIBUTES a2)
    = CreateDirectoryExA;

BOOL(__stdcall* Real_CreateDirectoryExW)(LPCWSTR a0,
    LPCWSTR a1,
    LPSECURITY_ATTRIBUTES a2)
    = CreateDirectoryExW;

BOOL(__stdcall* Real_CreateDirectoryW)(LPCWSTR a0,
    LPSECURITY_ATTRIBUTES a1)
    = CreateDirectoryW;

HBITMAP(__stdcall* Real_CreateDiscardableBitmap)(HDC a0,
    int a1,
    int a2)
    = CreateDiscardableBitmap;

HRGN(__stdcall* Real_CreateEllipticRgn)(int a0,
    int a1,
    int a2,
    int a3)
    = CreateEllipticRgn;

HRGN(__stdcall* Real_CreateEllipticRgnIndirect)(CONST RECT* a0)
= CreateEllipticRgnIndirect;

HDC(__stdcall* Real_CreateEnhMetaFileA)(HDC a0,
    LPCSTR a1,
    CONST RECT* a2,
    LPCSTR a3)
    = CreateEnhMetaFileA;

HDC(__stdcall* Real_CreateEnhMetaFileW)(HDC a0,
    LPCWSTR a1,
    CONST RECT* a2,
    LPCWSTR a3)
    = CreateEnhMetaFileW;

HANDLE(__stdcall* Real_CreateEventA)(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    BOOL a2,
    LPCSTR a3)
    = CreateEventA;

HANDLE(__stdcall* Real_CreateEventW)(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    BOOL a2,
    LPCWSTR a3)
    = CreateEventW;

LPVOID(__stdcall* Real_CreateFiber)(ULONG_PTR a0,
    LPFIBER_START_ROUTINE a1,
    LPVOID a2)
    = CreateFiber;

HANDLE(__stdcall* Real_CreateFileA)(LPCSTR a0,
    DWORD a1,
    DWORD a2,
    LPSECURITY_ATTRIBUTES a3,
    DWORD a4,
    DWORD a5,
    HANDLE a6)
    = CreateFileA;

HANDLE(__stdcall* Real_CreateFileMappingA)(HANDLE a0,
    LPSECURITY_ATTRIBUTES a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    LPCSTR a5)
    = CreateFileMappingA;

HANDLE(__stdcall* Real_CreateFileMappingW)(HANDLE a0,
    LPSECURITY_ATTRIBUTES a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    LPCWSTR a5)
    = CreateFileMappingW;

HRESULT(__stdcall* Real_CreateFileMoniker)(LPCOLESTR a0,
    IMoniker** a1)
    = CreateFileMoniker;

HANDLE(__stdcall* Real_CreateFileW)(LPCWSTR a0,
    DWORD a1,
    DWORD a2,
    LPSECURITY_ATTRIBUTES a3,
    DWORD a4,
    DWORD a5,
    HANDLE a6)
    = CreateFileW;

HFONT(__stdcall* Real_CreateFontA)(int a0,
    int a1,
    int a2,
    int a3,
    int a4,
    DWORD a5,
    DWORD a6,
    DWORD a7,
    DWORD a8,
    DWORD a9,
    DWORD a10,
    DWORD a11,
    DWORD a12,
    LPCSTR a13)
    = CreateFontA;

HFONT(__stdcall* Real_CreateFontIndirectA)(CONST LOGFONTA* a0)
= CreateFontIndirectA;

HFONT(__stdcall* Real_CreateFontIndirectW)(CONST LOGFONTW* a0)
= CreateFontIndirectW;

HFONT(__stdcall* Real_CreateFontW)(int a0,
    int a1,
    int a2,
    int a3,
    int a4,
    DWORD a5,
    DWORD a6,
    DWORD a7,
    DWORD a8,
    DWORD a9,
    DWORD a10,
    DWORD a11,
    DWORD a12,
    LPCWSTR a13)
    = CreateFontW;

HRESULT(__stdcall* Real_CreateGenericComposite)(IMoniker* a0,
    IMoniker* a1,
    IMoniker** a2)
    = CreateGenericComposite;

HPALETTE(__stdcall* Real_CreateHalftonePalette)(HDC a0)
= CreateHalftonePalette;

HBRUSH(__stdcall* Real_CreateHatchBrush)(int a0,
    COLORREF a1)
    = CreateHatchBrush;

HDC(__stdcall* Real_CreateICA)(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    CONST DEVMODEA* a3)
    = CreateICA;

HDC(__stdcall* Real_CreateICW)(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    CONST DEVMODEW* a3)
    = CreateICW;

HRESULT(__stdcall* Real_CreateILockBytesOnHGlobal)(HGLOBAL a0,
    BOOL a1,
    ILockBytes** a2)
    = CreateILockBytesOnHGlobal;

HICON(__stdcall* Real_CreateIcon)(HINSTANCE a0,
    int a1,
    int a2,
    BYTE a3,
    BYTE a4,
    CONST BYTE* a5,
    CONST BYTE* a6)
    = CreateIcon;

HICON(__stdcall* Real_CreateIconFromResource)(PBYTE a0,
    DWORD a1,
    BOOL a2,
    DWORD a3)
    = CreateIconFromResource;

HICON(__stdcall* Real_CreateIconFromResourceEx)(PBYTE a0,
    DWORD a1,
    BOOL a2,
    DWORD a3,
    int a4,
    int a5,
    UINT a6)
    = CreateIconFromResourceEx;

HICON(__stdcall* Real_CreateIconIndirect)(PICONINFO a0)
= CreateIconIndirect;

HANDLE(__stdcall* Real_CreateIoCompletionPort)(HANDLE a0,
    HANDLE a1,
    ULONG_PTR a2,
    DWORD a3)
    = CreateIoCompletionPort;

HRESULT(__stdcall* Real_CreateItemMoniker)(LPCOLESTR a0,
    LPCOLESTR a1,
    IMoniker** a2)
    = CreateItemMoniker;

#if _MSC_VER < 1300
HWND(__stdcall* Real_CreateMDIWindowA)(LPSTR a0,
    LPSTR a1,
    DWORD a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HWND a7,
    HINSTANCE a8,
    LPARAM a9)
    = CreateMDIWindowA;
#else
HWND(__stdcall* Real_CreateMDIWindowA)(LPCSTR a0,
    LPCSTR a1,
    DWORD a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HWND a7,
    HINSTANCE a8,
    LPARAM a9)
    = CreateMDIWindowA;
#endif

#if _MSC_VER < 1300
HWND(__stdcall* Real_CreateMDIWindowW)(LPWSTR a0,
    LPWSTR a1,
    DWORD a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HWND a7,
    HINSTANCE a8,
    LPARAM a9)
    = CreateMDIWindowW;
#else
HWND(__stdcall* Real_CreateMDIWindowW)(LPCWSTR a0,
    LPCWSTR a1,
    DWORD a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HWND a7,
    HINSTANCE a8,
    LPARAM a9)
    = CreateMDIWindowW;
#endif

HANDLE(__stdcall* Real_CreateMailslotA)(LPCSTR a0,
    DWORD a1,
    DWORD a2,
    LPSECURITY_ATTRIBUTES a3)
    = CreateMailslotA;

HANDLE(__stdcall* Real_CreateMailslotW)(LPCWSTR a0,
    DWORD a1,
    DWORD a2,
    LPSECURITY_ATTRIBUTES a3)
    = CreateMailslotW;

HMENU(__stdcall* Real_CreateMenu)(void)
= CreateMenu;

HDC(__stdcall* Real_CreateMetaFileA)(LPCSTR a0)
= CreateMetaFileA;

HDC(__stdcall* Real_CreateMetaFileW)(LPCWSTR a0)
= CreateMetaFileW;

HANDLE(__stdcall* Real_CreateMutexA)(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    LPCSTR a2)
    = CreateMutexA;

HANDLE(__stdcall* Real_CreateMutexW)(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    LPCWSTR a2)
    = CreateMutexW;

HANDLE(__stdcall* Real_CreateNamedPipeA)(LPCSTR a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    DWORD a5,
    DWORD a6,
    LPSECURITY_ATTRIBUTES a7)
    = CreateNamedPipeA;

HANDLE(__stdcall* Real_CreateNamedPipeW)(LPCWSTR a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    DWORD a5,
    DWORD a6,
    LPSECURITY_ATTRIBUTES a7)
    = CreateNamedPipeW;

HRESULT(__stdcall* Real_CreateOleAdviseHolder)(LPOLEADVISEHOLDER* a0)
= CreateOleAdviseHolder;

HPALETTE(__stdcall* Real_CreatePalette)(CONST LOGPALETTE* a0)
= CreatePalette;

HBRUSH(__stdcall* Real_CreatePatternBrush)(HBITMAP a0)
= CreatePatternBrush;

HPEN(__stdcall* Real_CreatePen)(int a0,
    int a1,
    COLORREF a2)
    = CreatePen;

HPEN(__stdcall* Real_CreatePenIndirect)(CONST LOGPEN* a0)
= CreatePenIndirect;

BOOL(__stdcall* Real_CreatePipe)(PHANDLE a0,
    PHANDLE a1,
    LPSECURITY_ATTRIBUTES a2,
    DWORD a3)
    = CreatePipe;

HRESULT(__stdcall* Real_CreatePointerMoniker)(LPUNKNOWN a0,
    IMoniker** a1)
    = CreatePointerMoniker;

HRGN(__stdcall* Real_CreatePolyPolygonRgn)(CONST POINT* a0,
    CONST INT* a1,
    int a2,
    int a3)
    = CreatePolyPolygonRgn;

HRGN(__stdcall* Real_CreatePolygonRgn)(CONST POINT* a0,
    int a1,
    int a2)
    = CreatePolygonRgn;

HMENU(__stdcall* Real_CreatePopupMenu)(void)
= CreatePopupMenu;

BOOL(__stdcall* Real_CreateProcessA)(LPCSTR a0,
    LPSTR a1,
    LPSECURITY_ATTRIBUTES a2,
    LPSECURITY_ATTRIBUTES a3,
    BOOL a4,
    DWORD a5,
    LPVOID a6,
    LPCSTR a7,
    LPSTARTUPINFOA a8,
    LPPROCESS_INFORMATION a9)
    = CreateProcessA;

BOOL(__stdcall* Real_CreateProcessW)(LPCWSTR a0,
    LPWSTR a1,
    LPSECURITY_ATTRIBUTES a2,
    LPSECURITY_ATTRIBUTES a3,
    BOOL a4,
    DWORD a5,
    LPVOID a6,
    LPCWSTR a7,
    LPSTARTUPINFOW a8,
    LPPROCESS_INFORMATION a9)
    = CreateProcessW;

BOOL(__stdcall* Real_CreateProcessAsUserA)(
    __in_opt     HANDLE hToken,
    __in_opt     LPCSTR lpApplicationName,
    __inout_opt  LPSTR lpCommandLine,
    __in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
    __in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
    __in         BOOL bInheritHandles,
    __in         DWORD dwCreationFlags,
    __in_opt     LPVOID lpEnvironment,
    __in_opt     LPCSTR lpCurrentDirectory,
    __in         LPSTARTUPINFOA lpStartupInfo,
    __out        LPPROCESS_INFORMATION lpProcessInformation
    ) = CreateProcessAsUserA;

BOOL(__stdcall* Real_CreateProcessAsUserW)(
    __in_opt     HANDLE hToken,
    __in_opt     LPCWSTR lpApplicationName,
    __inout_opt  LPWSTR lpCommandLine,
    __in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
    __in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
    __in         BOOL bInheritHandles,
    __in         DWORD dwCreationFlags,
    __in_opt     LPVOID lpEnvironment,
    __in_opt     LPCWSTR lpCurrentDirectory,
    __in         LPSTARTUPINFOW lpStartupInfo,
    __out        LPPROCESS_INFORMATION lpProcessInformation
    ) = CreateProcessAsUserW;

#if(_WIN32_WINNT >= 0x0500)

BOOL(WINAPI* Real_CreateProcessWithLogonW)(
    __in         LPCWSTR lpUsername,
    __in_opt     LPCWSTR lpDomain,
    __in         LPCWSTR lpPassword,
    __in         DWORD dwLogonFlags,
    __in_opt     LPCWSTR lpApplicationName,
    __inout_opt  LPWSTR lpCommandLine,
    __in         DWORD dwCreationFlags,
    __in_opt     LPVOID lpEnvironment,
    __in_opt     LPCWSTR lpCurrentDirectory,
    __in         LPSTARTUPINFOW lpStartupInfo,
    __out        LPPROCESS_INFORMATION lpProcessInfo
    ) = CreateProcessWithLogonW;

BOOL(WINAPI* Real_CreateProcessWithTokenW)(
    __in         HANDLE hToken,
    __in         DWORD dwLogonFlags,
    __in_opt     LPCWSTR lpApplicationName,
    __inout_opt  LPWSTR lpCommandLine,
    __in         DWORD dwCreationFlags,
    __in_opt     LPVOID lpEnvironment,
    __in_opt     LPCWSTR lpCurrentDirectory,
    __in         LPSTARTUPINFOW lpStartupInfo,
    __out        LPPROCESS_INFORMATION lpProcessInfo
    ) = CreateProcessWithTokenW;
#endif

HRGN(__stdcall* Real_CreateRectRgn)(int a0,
    int a1,
    int a2,
    int a3)
    = CreateRectRgn;

HRGN(__stdcall* Real_CreateRectRgnIndirect)(CONST RECT* a0)
= CreateRectRgnIndirect;

HANDLE(__stdcall* Real_CreateRemoteThread)(HANDLE a0,
    LPSECURITY_ATTRIBUTES a1,
    ULONG_PTR a2,
    LPTHREAD_START_ROUTINE a3,
    LPVOID a4,
    DWORD a5,
    LPDWORD a6)
    = CreateRemoteThread;

HRGN(__stdcall* Real_CreateRoundRectRgn)(int a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5)
    = CreateRoundRectRgn;

BOOL(__stdcall* Real_CreateScalableFontResourceA)(DWORD a0,
    LPCSTR a1,
    LPCSTR a2,
    LPCSTR a3)
    = CreateScalableFontResourceA;

BOOL(__stdcall* Real_CreateScalableFontResourceW)(DWORD a0,
    LPCWSTR a1,
    LPCWSTR a2,
    LPCWSTR a3)
    = CreateScalableFontResourceW;

HANDLE(__stdcall* Real_CreateSemaphoreA)(LPSECURITY_ATTRIBUTES a0,
    LONG a1,
    LONG a2,
    LPCSTR a3)
    = CreateSemaphoreA;

HANDLE(__stdcall* Real_CreateSemaphoreW)(LPSECURITY_ATTRIBUTES a0,
    LONG a1,
    LONG a2,
    LPCWSTR a3)
    = CreateSemaphoreW;

HBRUSH(__stdcall* Real_CreateSolidBrush)(COLORREF a0)
= CreateSolidBrush;

HRESULT(__stdcall* Real_CreateStdProgressIndicator)(HWND a0,
    LPCOLESTR a1,
    IBindStatusCallback* a2,
    IBindStatusCallback** a3)
    = CreateStdProgressIndicator;

HRESULT(__stdcall* Real_CreateStreamOnHGlobal)(HGLOBAL a0,
    BOOL a1,
    LPSTREAM* a2)
    = CreateStreamOnHGlobal;

DWORD(__stdcall* Real_CreateTapePartition)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3)
    = CreateTapePartition;

HANDLE(__stdcall* Real_CreateThread)(LPSECURITY_ATTRIBUTES a0,
    ULONG_PTR a1,
    LPTHREAD_START_ROUTINE a2,
    LPVOID a3,
    DWORD a4,
    LPDWORD a5)
    = CreateThread;

HANDLE(__stdcall* Real_CreateWaitableTimerA)(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    LPCSTR a2)
    = CreateWaitableTimerA;

HANDLE(__stdcall* Real_CreateWaitableTimerW)(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    LPCWSTR a2)
    = CreateWaitableTimerW;

HWND(__stdcall* Real_CreateWindowExA)(DWORD a0,
    LPCSTR a1,
    LPCSTR a2,
    DWORD a3,
    int a4,
    int a5,
    int a6,
    int a7,
    HWND a8,
    HMENU a9,
    HINSTANCE a10,
    LPVOID a11)
    = CreateWindowExA;

HWND(__stdcall* Real_CreateWindowExW)(DWORD a0,
    LPCWSTR a1,
    LPCWSTR a2,
    DWORD a3,
    int a4,
    int a5,
    int a6,
    int a7,
    HWND a8,
    HMENU a9,
    HINSTANCE a10,
    LPVOID a11)
    = CreateWindowExW;

#if _MSC_VER < 1300
HWINSTA(__stdcall* Real_CreateWindowStationA)(LPSTR a0,
    DWORD a1,
    ACCESS_MASK a2,
    LPSECURITY_ATTRIBUTES a3)
    = CreateWindowStationA;
#else
HWINSTA(__stdcall* Real_CreateWindowStationA)(LPCSTR a0,
    DWORD a1,
    ACCESS_MASK a2,
    LPSECURITY_ATTRIBUTES a3)
    = CreateWindowStationA;
#endif

#if _MSC_VER < 1300
HWINSTA(__stdcall* Real_CreateWindowStationW)(LPWSTR a0,
    DWORD a1,
    ACCESS_MASK a2,
    LPSECURITY_ATTRIBUTES a3)
    = CreateWindowStationW;
#else
HWINSTA(__stdcall* Real_CreateWindowStationW)(LPCWSTR a0,
    DWORD a1,
    ACCESS_MASK a2,
    LPSECURITY_ATTRIBUTES a3)
    = CreateWindowStationW;
#endif

BOOL(__stdcall* Real_DPtoLP)(HDC a0,
    POINT* a1,
    int a2)
    = DPtoLP;

BOOL(__stdcall* Real_DdeAbandonTransaction)(DWORD a0,
    HCONV a1,
    DWORD a2)
    = DdeAbandonTransaction;

LPBYTE(__stdcall* Real_DdeAccessData)(HDDEDATA a0,
    LPDWORD a1)
    = DdeAccessData;

HDDEDATA(__stdcall* Real_DdeAddData)(HDDEDATA a0,
    LPBYTE a1,
    DWORD a2,
    DWORD a3)
    = DdeAddData;

HDDEDATA(__stdcall* Real_DdeClientTransaction)(LPBYTE a0,
    DWORD a1,
    HCONV a2,
    HSZ a3,
    UINT a4,
    UINT a5,
    DWORD a6,
    LPDWORD a7)
    = DdeClientTransaction;

int(__stdcall* Real_DdeCmpStringHandles)(HSZ a0,
    HSZ a1)
    = DdeCmpStringHandles;

HCONV(__stdcall* Real_DdeConnect)(DWORD a0,
    HSZ a1,
    HSZ a2,
    PCONVCONTEXT a3)
    = DdeConnect;

HCONVLIST(__stdcall* Real_DdeConnectList)(DWORD a0,
    HSZ a1,
    HSZ a2,
    HCONVLIST a3,
    PCONVCONTEXT a4)
    = DdeConnectList;

HDDEDATA(__stdcall* Real_DdeCreateDataHandle)(DWORD a0,
    LPBYTE a1,
    DWORD a2,
    DWORD a3,
    HSZ a4,
    UINT a5,
    UINT a6)
    = DdeCreateDataHandle;

HSZ(__stdcall* Real_DdeCreateStringHandleA)(DWORD a0,
    LPCSTR a1,
    int a2)
    = DdeCreateStringHandleA;

HSZ(__stdcall* Real_DdeCreateStringHandleW)(DWORD a0,
    LPCWSTR a1,
    int a2)
    = DdeCreateStringHandleW;

BOOL(__stdcall* Real_DdeDisconnect)(HCONV a0)
= DdeDisconnect;

BOOL(__stdcall* Real_DdeDisconnectList)(HCONVLIST a0)
= DdeDisconnectList;

BOOL(__stdcall* Real_DdeEnableCallback)(DWORD a0,
    HCONV a1,
    UINT a2)
    = DdeEnableCallback;

BOOL(__stdcall* Real_DdeFreeDataHandle)(HDDEDATA a0)
= DdeFreeDataHandle;

BOOL(__stdcall* Real_DdeFreeStringHandle)(DWORD a0,
    HSZ a1)
    = DdeFreeStringHandle;

DWORD(__stdcall* Real_DdeGetData)(HDDEDATA a0,
    LPBYTE a1,
    DWORD a2,
    DWORD a3)
    = DdeGetData;

UINT(__stdcall* Real_DdeGetLastError)(DWORD a0)
= DdeGetLastError;

BOOL(__stdcall* Real_DdeImpersonateClient)(HCONV a0)
= DdeImpersonateClient;

BOOL(__stdcall* Real_DdeKeepStringHandle)(DWORD a0,
    HSZ a1)
    = DdeKeepStringHandle;

HDDEDATA(__stdcall* Real_DdeNameService)(DWORD a0,
    HSZ a1,
    HSZ a2,
    UINT a3)
    = DdeNameService;

BOOL(__stdcall* Real_DdePostAdvise)(DWORD a0,
    HSZ a1,
    HSZ a2)
    = DdePostAdvise;

UINT(__stdcall* Real_DdeQueryConvInfo)(HCONV a0,
    DWORD a1,
    CONVINFO* a2)
    = DdeQueryConvInfo;

HCONV(__stdcall* Real_DdeQueryNextServer)(HCONVLIST a0,
    HCONV a1)
    = DdeQueryNextServer;

DWORD(__stdcall* Real_DdeQueryStringA)(DWORD a0,
    HSZ a1,
    LPSTR a2,
    DWORD a3,
    int a4)
    = DdeQueryStringA;

DWORD(__stdcall* Real_DdeQueryStringW)(DWORD a0,
    HSZ a1,
    LPWSTR a2,
    DWORD a3,
    int a4)
    = DdeQueryStringW;

HCONV(__stdcall* Real_DdeReconnect)(HCONV a0)
= DdeReconnect;

BOOL(__stdcall* Real_DdeSetQualityOfService)(HWND a0,
    CONST SECURITY_QUALITY_OF_SERVICE* a1,
    PSECURITY_QUALITY_OF_SERVICE a2)
    = DdeSetQualityOfService;

BOOL(__stdcall* Real_DdeSetUserHandle)(HCONV a0,
    DWORD a1,
    ULONG_PTR a2)
    = DdeSetUserHandle;

BOOL(__stdcall* Real_DdeUnaccessData)(HDDEDATA a0)
= DdeUnaccessData;

BOOL(__stdcall* Real_DdeUninitialize)(DWORD a0)
= DdeUninitialize;

BOOL(__stdcall* Real_DebugActiveProcess)(DWORD a0)
= DebugActiveProcess;

BOOL(__stdcall* Real_DebugActiveProcessStop)(DWORD a0)
= DebugActiveProcessStop;

void(__stdcall* Real_DebugBreak)(void)
= DebugBreak;

LRESULT(__stdcall* Real_DefDlgProcA)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = DefDlgProcA;

LRESULT(__stdcall* Real_DefDlgProcW)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = DefDlgProcW;

LRESULT(__stdcall* Real_DefFrameProcA)(HWND a0,
    HWND a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
    = DefFrameProcA;

LRESULT(__stdcall* Real_DefFrameProcW)(HWND a0,
    HWND a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
    = DefFrameProcW;

LRESULT(__stdcall* Real_DefMDIChildProcA)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = DefMDIChildProcA;

LRESULT(__stdcall* Real_DefMDIChildProcW)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = DefMDIChildProcW;

LRESULT(__stdcall* Real_DefWindowProcA)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = DefWindowProcA;

LRESULT(__stdcall* Real_DefWindowProcW)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = DefWindowProcW;

HDWP(__stdcall* Real_DeferWindowPos)(HDWP a0,
    HWND a1,
    HWND a2,
    int a3,
    int a4,
    int a5,
    int a6,
    UINT a7)
    = DeferWindowPos;

BOOL(__stdcall* Real_DefineDosDeviceA)(DWORD a0,
    LPCSTR a1,
    LPCSTR a2)
    = DefineDosDeviceA;

BOOL(__stdcall* Real_DefineDosDeviceW)(DWORD a0,
    LPCWSTR a1,
    LPCWSTR a2)
    = DefineDosDeviceW;

ATOM(__stdcall* Real_DeleteAtom)(ATOM a0)
= DeleteAtom;

BOOL(__stdcall* Real_DeleteColorSpace)(HCOLORSPACE a0)
= DeleteColorSpace;

BOOL(__stdcall* Real_DeleteDC)(HDC a0)
= DeleteDC;

BOOL(__stdcall* Real_DeleteEnhMetaFile)(HENHMETAFILE a0)
= DeleteEnhMetaFile;

void(__stdcall* Real_DeleteFiber)(LPVOID a0)
= DeleteFiber;

BOOL(__stdcall* Real_DeleteFileA)(LPCSTR a0)
= DeleteFileA;

BOOL(__stdcall* Real_DeleteFileW)(LPCWSTR a0)
= DeleteFileW;

BOOL(__stdcall* Real_DeleteMenu)(HMENU a0,
    UINT a1,
    UINT a2)
    = DeleteMenu;

BOOL(__stdcall* Real_DeleteMetaFile)(HMETAFILE a0)
= DeleteMetaFile;

BOOL(__stdcall* Real_DeleteObject)(HGDIOBJ a0)
= DeleteObject;

int(__stdcall* Real_DescribePixelFormat)(HDC a0,
    int a1,
    UINT a2,
    PIXELFORMATDESCRIPTOR* a3)
    = DescribePixelFormat;

BOOL(__stdcall* Real_DestroyAcceleratorTable)(HACCEL a0)
= DestroyAcceleratorTable;

BOOL(__stdcall* Real_DestroyCaret)(void)
= DestroyCaret;

BOOL(__stdcall* Real_DestroyCursor)(HCURSOR a0)
= DestroyCursor;

BOOL(__stdcall* Real_DestroyIcon)(HICON a0)
= DestroyIcon;

BOOL(__stdcall* Real_DestroyMenu)(HMENU a0)
= DestroyMenu;

BOOL(__stdcall* Real_DestroyWindow)(HWND a0)
= DestroyWindow;

BOOL(__stdcall* Real_DeviceIoControl)(HANDLE a0,
    DWORD a1,
    LPVOID a2,
    DWORD a3,
    LPVOID a4,
    DWORD a5,
    LPDWORD a6,
    LPOVERLAPPED a7)
    = DeviceIoControl;

INT_PTR(__stdcall* Real_DialogBoxIndirectParamA)(HINSTANCE a0,
    LPCDLGTEMPLATEA a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
    = DialogBoxIndirectParamA;

INT_PTR(__stdcall* Real_DialogBoxIndirectParamW)(HINSTANCE a0,
    LPCDLGTEMPLATEW a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
    = DialogBoxIndirectParamW;

INT_PTR(__stdcall* Real_DialogBoxParamA)(HINSTANCE a0,
    LPCSTR a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
    = DialogBoxParamA;

INT_PTR(__stdcall* Real_DialogBoxParamW)(HINSTANCE a0,
    LPCWSTR a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
    = DialogBoxParamW;

BOOL(__stdcall* Real_DisableThreadLibraryCalls)(HMODULE a0)
= DisableThreadLibraryCalls;

BOOL(__stdcall* Real_DisconnectNamedPipe)(HANDLE a0)
= DisconnectNamedPipe;

LRESULT(__stdcall* Real_DispatchMessageA)(CONST MSG* a0)
= DispatchMessageA;

LRESULT(__stdcall* Real_DispatchMessageW)(CONST MSG* a0)
= DispatchMessageW;

int(__stdcall* Real_DlgDirListA)(HWND a0,
    LPSTR a1,
    int a2,
    int a3,
    UINT a4)
    = DlgDirListA;

int(__stdcall* Real_DlgDirListComboBoxA)(HWND a0,
    LPSTR a1,
    int a2,
    int a3,
    UINT a4)
    = DlgDirListComboBoxA;

int(__stdcall* Real_DlgDirListComboBoxW)(HWND a0,
    LPWSTR a1,
    int a2,
    int a3,
    UINT a4)
    = DlgDirListComboBoxW;

int(__stdcall* Real_DlgDirListW)(HWND a0,
    LPWSTR a1,
    int a2,
    int a3,
    UINT a4)
    = DlgDirListW;

BOOL(__stdcall* Real_DlgDirSelectComboBoxExA)(HWND a0,
    LPSTR a1,
    int a2,
    int a3)
    = DlgDirSelectComboBoxExA;

BOOL(__stdcall* Real_DlgDirSelectComboBoxExW)(HWND a0,
    LPWSTR a1,
    int a2,
    int a3)
    = DlgDirSelectComboBoxExW;

BOOL(__stdcall* Real_DlgDirSelectExA)(HWND a0,
    LPSTR a1,
    int a2,
    int a3)
    = DlgDirSelectExA;

BOOL(__stdcall* Real_DlgDirSelectExW)(HWND a0,
    LPWSTR a1,
    int a2,
    int a3)
    = DlgDirSelectExW;

HRESULT(__stdcall* Real_DoDragDrop)(IDataObject* a0,
    IDropSource* a1,
    DWORD a2,
    LPDWORD a3)
    = DoDragDrop;

BOOL(__stdcall* Real_DosDateTimeToFileTime)(WORD a0,
    WORD a1,
    LPFILETIME a2)
    = DosDateTimeToFileTime;

BOOL(__stdcall* Real_DragDetect)(HWND a0,
    POINT a1)
    = DragDetect;

DWORD(__stdcall* Real_DragObject)(HWND a0,
    HWND a1,
    UINT a2,
    ULONG_PTR a3,
    HCURSOR a4)
    = DragObject;

BOOL(__stdcall* Real_DrawAnimatedRects)(HWND a0,
    int a1,
    CONST RECT* a2,
    CONST RECT* a3)
    = DrawAnimatedRects;

BOOL(__stdcall* Real_DrawCaption)(HWND a0,
    HDC a1,
    CONST RECT* a2,
    UINT a3)
    = DrawCaption;

BOOL(__stdcall* Real_DrawEdge)(HDC a0,
    LPRECT a1,
    UINT a2,
    UINT a3)
    = DrawEdge;

int(__stdcall* Real_DrawEscape)(HDC a0,
    int a1,
    int a2,
    LPCSTR a3)
    = DrawEscape;

BOOL(__stdcall* Real_DrawFocusRect)(HDC a0,
    CONST RECT* a1)
    = DrawFocusRect;

BOOL(__stdcall* Real_DrawFrameControl)(HDC a0,
    LPRECT a1,
    UINT a2,
    UINT a3)
    = DrawFrameControl;

BOOL(__stdcall* Real_DrawIcon)(HDC a0,
    int a1,
    int a2,
    HICON a3)
    = DrawIcon;

BOOL(__stdcall* Real_DrawIconEx)(HDC a0,
    int a1,
    int a2,
    HICON a3,
    int a4,
    int a5,
    UINT a6,
    HBRUSH a7,
    UINT a8)
    = DrawIconEx;

BOOL(__stdcall* Real_DrawMenuBar)(HWND a0)
= DrawMenuBar;

BOOL(__stdcall* Real_DrawStateA)(HDC a0,
    HBRUSH a1,
    DRAWSTATEPROC a2,
    LPARAM a3,
    WPARAM a4,
    int a5,
    int a6,
    int a7,
    int a8,
    UINT a9)
    = DrawStateA;

BOOL(__stdcall* Real_DrawStateW)(HDC a0,
    HBRUSH a1,
    DRAWSTATEPROC a2,
    LPARAM a3,
    WPARAM a4,
    int a5,
    int a6,
    int a7,
    int a8,
    UINT a9)
    = DrawStateW;

int(__stdcall* Real_DrawTextA)(HDC a0,
    LPCSTR a1,
    int a2,
    LPRECT a3,
    UINT a4)
    = DrawTextA;

int(__stdcall* Real_DrawTextExA)(HDC a0,
    LPSTR a1,
    int a2,
    LPRECT a3,
    UINT a4,
    LPDRAWTEXTPARAMS a5)
    = DrawTextExA;

int(__stdcall* Real_DrawTextExW)(HDC a0,
    LPWSTR a1,
    int a2,
    LPRECT a3,
    UINT a4,
    LPDRAWTEXTPARAMS a5)
    = DrawTextExW;

int(__stdcall* Real_DrawTextW)(HDC a0,
    LPCWSTR a1,
    int a2,
    LPRECT a3,
    UINT a4)
    = DrawTextW;

BOOL(__stdcall* Real_DuplicateHandle)(HANDLE a0,
    HANDLE a1,
    HANDLE a2,
    LPHANDLE a3,
    DWORD a4,
    BOOL a5,
    DWORD a6)
    = DuplicateHandle;

BOOL(__stdcall* Real_Ellipse)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4)
    = Ellipse;

BOOL(__stdcall* Real_EmptyClipboard)(void)
= EmptyClipboard;

BOOL(__stdcall* Real_EnableMenuItem)(HMENU a0,
    UINT a1,
    UINT a2)
    = EnableMenuItem;

BOOL(__stdcall* Real_EnableScrollBar)(HWND a0,
    UINT a1,
    UINT a2)
    = EnableScrollBar;

BOOL(__stdcall* Real_EnableWindow)(HWND a0,
    BOOL a1)
    = EnableWindow;

BOOL(__stdcall* Real_EndDeferWindowPos)(HDWP a0)
= EndDeferWindowPos;

BOOL(__stdcall* Real_EndDialog)(HWND a0,
    INT_PTR a1)
    = EndDialog;

int(__stdcall* Real_EndDoc)(HDC a0)
= EndDoc;

int(__stdcall* Real_EndPage)(HDC a0)
= EndPage;

BOOL(__stdcall* Real_EndPaint)(HWND a0,
    CONST PAINTSTRUCT* a1)
    = EndPaint;

BOOL(__stdcall* Real_EndPath)(HDC a0)
= EndPath;

BOOL(__stdcall* Real_EndUpdateResourceA)(HANDLE a0,
    BOOL a1)
    = EndUpdateResourceA;

BOOL(__stdcall* Real_EndUpdateResourceW)(HANDLE a0,
    BOOL a1)
    = EndUpdateResourceW;

BOOL(__stdcall* Real_EnumCalendarInfoA)(CALINFO_ENUMPROCA a0,
    LCID a1,
    CALID a2,
    CALTYPE a3)
    = EnumCalendarInfoA;

BOOL(__stdcall* Real_EnumCalendarInfoW)(CALINFO_ENUMPROCW a0,
    LCID a1,
    CALID a2,
    CALTYPE a3)
    = EnumCalendarInfoW;

BOOL(__stdcall* Real_EnumChildWindows)(HWND a0,
    WNDENUMPROC a1,
    LPARAM a2)
    = EnumChildWindows;

UINT(__stdcall* Real_EnumClipboardFormats)(UINT a0)
= EnumClipboardFormats;

BOOL(__stdcall* Real_EnumDateFormatsA)(DATEFMT_ENUMPROCA a0,
    LCID a1,
    DWORD a2)
    = EnumDateFormatsA;

BOOL(__stdcall* Real_EnumDateFormatsW)(DATEFMT_ENUMPROCW a0,
    LCID a1,
    DWORD a2)
    = EnumDateFormatsW;

BOOL(__stdcall* Real_EnumDesktopWindows)(HDESK a0,
    WNDENUMPROC a1,
    LPARAM a2)
    = EnumDesktopWindows;

BOOL(__stdcall* Real_EnumDesktopsA)(HWINSTA a0,
    DESKTOPENUMPROCA a1,
    LPARAM a2)
    = EnumDesktopsA;

BOOL(__stdcall* Real_EnumDesktopsW)(HWINSTA a0,
    DESKTOPENUMPROCW a1,
    LPARAM a2)
    = EnumDesktopsW;

BOOL(__stdcall* Real_EnumDisplaySettingsA)(LPCSTR a0,
    DWORD a1,
    LPDEVMODEA a2)
    = EnumDisplaySettingsA;

BOOL(__stdcall* Real_EnumDisplaySettingsW)(LPCWSTR a0,
    DWORD a1,
    LPDEVMODEW a2)
    = EnumDisplaySettingsW;

BOOL(__stdcall* Real_EnumEnhMetaFile)(HDC a0,
    HENHMETAFILE a1,
    ENHMFENUMPROC a2,
    LPVOID a3,
    CONST RECT* a4)
    = EnumEnhMetaFile;

int(__stdcall* Real_EnumFontFamiliesA)(HDC a0,
    LPCSTR a1,
    FONTENUMPROCA a2,
    LPARAM a3)
    = EnumFontFamiliesA;

int(__stdcall* Real_EnumFontFamiliesExA)(HDC a0,
    LPLOGFONTA a1,
    FONTENUMPROCA a2,
    LPARAM a3,
    DWORD a4)
    = EnumFontFamiliesExA;

int(__stdcall* Real_EnumFontFamiliesExW)(HDC a0,
    LPLOGFONTW a1,
    FONTENUMPROCW a2,
    LPARAM a3,
    DWORD a4)
    = EnumFontFamiliesExW;

int(__stdcall* Real_EnumFontFamiliesW)(HDC a0,
    LPCWSTR a1,
    FONTENUMPROCW a2,
    LPARAM a3)
    = EnumFontFamiliesW;

int(__stdcall* Real_EnumFontsA)(HDC a0,
    LPCSTR a1,
    FONTENUMPROCA a2,
    LPARAM a3)
    = EnumFontsA;

int(__stdcall* Real_EnumFontsW)(HDC a0,
    LPCWSTR a1,
    FONTENUMPROCW a2,
    LPARAM a3)
    = EnumFontsW;

int(__stdcall* Real_EnumICMProfilesA)(HDC a0,
    ICMENUMPROCA a1,
    LPARAM a2)
    = EnumICMProfilesA;

int(__stdcall* Real_EnumICMProfilesW)(HDC a0,
    ICMENUMPROCW a1,
    LPARAM a2)
    = EnumICMProfilesW;

BOOL(__stdcall* Real_EnumMetaFile)(HDC a0,
    HMETAFILE a1,
    MFENUMPROC a2,
    LPARAM a3)
    = EnumMetaFile;

int(__stdcall* Real_EnumObjects)(HDC a0,
    int a1,
    GOBJENUMPROC a2,
    LPARAM a3)
    = EnumObjects;

int(__stdcall* Real_EnumPropsA)(HWND a0,
    PROPENUMPROCA a1)
    = EnumPropsA;

int(__stdcall* Real_EnumPropsExA)(HWND a0,
    PROPENUMPROCEXA a1,
    LPARAM a2)
    = EnumPropsExA;

int(__stdcall* Real_EnumPropsExW)(HWND a0,
    PROPENUMPROCEXW a1,
    LPARAM a2)
    = EnumPropsExW;

int(__stdcall* Real_EnumPropsW)(HWND a0,
    PROPENUMPROCW a1)
    = EnumPropsW;

#if _MSC_VER < 1300
BOOL(__stdcall* Real_EnumResourceLanguagesA)(HMODULE a0,
    LPCSTR a1,
    LPCSTR a2,
    ENUMRESLANGPROC a3,
    LONG a4)
    = EnumResourceLanguagesA;
#else
BOOL(__stdcall* Real_EnumResourceLanguagesA)(HMODULE a0,
    LPCSTR a1,
    LPCSTR a2,
    ENUMRESLANGPROCA a3,
    LONG_PTR a4)
    = EnumResourceLanguagesA;
#endif

#if _MSC_VER < 1300
BOOL(__stdcall* Real_EnumResourceLanguagesW)(HMODULE a0,
    LPCWSTR a1,
    LPCWSTR a2,
    ENUMRESLANGPROC a3,
    LONG a4)
    = EnumResourceLanguagesW;
#else
BOOL(__stdcall* Real_EnumResourceLanguagesW)(HMODULE a0,
    LPCWSTR a1,
    LPCWSTR a2,
    ENUMRESLANGPROCW a3,
    LONG_PTR a4)
    = EnumResourceLanguagesW;
#endif

#if _MSC_VER < 1300
BOOL(__stdcall* Real_EnumResourceNamesA)(HMODULE a0,
    LPCSTR a1,
    ENUMRESNAMEPROC a2,
    LONG a3)
    = EnumResourceNamesA;
#else
BOOL(__stdcall* Real_EnumResourceNamesA)(HMODULE a0,
    LPCSTR a1,
    ENUMRESNAMEPROCA a2,
    LONG_PTR a3)
    = EnumResourceNamesA;
#endif

#if _MSC_VER < 1300
BOOL(__stdcall* Real_EnumResourceNamesW)(HMODULE a0,
    LPCWSTR a1,
    ENUMRESNAMEPROC a2,
    LONG a3)
    = EnumResourceNamesW;
#else
BOOL(__stdcall* Real_EnumResourceNamesW)(HMODULE a0,
    LPCWSTR a1,
    ENUMRESNAMEPROCW a2,
    LONG_PTR a3)
    = EnumResourceNamesW;
#endif

#if _MSC_VER < 1300
BOOL(__stdcall* Real_EnumResourceTypesA)(HMODULE a0,
    ENUMRESTYPEPROC a1,
    LONG a2)
    = EnumResourceTypesA;
#else
BOOL(__stdcall* Real_EnumResourceTypesA)(HMODULE a0,
    ENUMRESTYPEPROCA a1,
    LONG_PTR a2)
    = EnumResourceTypesA;
#endif

#if _MSC_VER < 1300
BOOL(__stdcall* Real_EnumResourceTypesW)(HMODULE a0,
    ENUMRESTYPEPROC a1,
    LONG a2)
    = EnumResourceTypesW;
#else
BOOL(__stdcall* Real_EnumResourceTypesW)(HMODULE a0,
    ENUMRESTYPEPROCW a1,
    LONG_PTR a2)
    = EnumResourceTypesW;
#endif

BOOL(__stdcall* Real_EnumSystemCodePagesA)(CODEPAGE_ENUMPROCA a0,
    DWORD a1)
    = EnumSystemCodePagesA;

BOOL(__stdcall* Real_EnumSystemCodePagesW)(CODEPAGE_ENUMPROCW a0,
    DWORD a1)
    = EnumSystemCodePagesW;

#if(WINVER >= 0x0500)
BOOL(__stdcall* Real_EnumSystemLocalesA)(LOCALE_ENUMPROCA a0,
    DWORD a1)
    = EnumSystemLocalesA;

BOOL(__stdcall* Real_EnumSystemLocalesW)(LOCALE_ENUMPROCW a0,
    DWORD a1)
    = EnumSystemLocalesW;
#endif // (WINVER >= 0x0500)

BOOL(__stdcall* Real_EnumThreadWindows)(DWORD a0,
    WNDENUMPROC a1,
    LPARAM a2)
    = EnumThreadWindows;

BOOL(__stdcall* Real_EnumTimeFormatsA)(TIMEFMT_ENUMPROCA a0,
    LCID a1,
    DWORD a2)
    = EnumTimeFormatsA;

BOOL(__stdcall* Real_EnumTimeFormatsW)(TIMEFMT_ENUMPROCW a0,
    LCID a1,
    DWORD a2)
    = EnumTimeFormatsW;

BOOL(__stdcall* Real_EnumWindowStationsA)(WINSTAENUMPROCA a0,
    LPARAM a1)
    = EnumWindowStationsA;

BOOL(__stdcall* Real_EnumWindowStationsW)(WINSTAENUMPROCW a0,
    LPARAM a1)
    = EnumWindowStationsW;

BOOL(__stdcall* Real_EnumWindows)(WNDENUMPROC a0,
    LPARAM a1)
    = EnumWindows;

BOOL(__stdcall* Real_EqualRect)(CONST RECT* a0,
    CONST RECT* a1)
    = EqualRect;

BOOL(__stdcall* Real_EqualRgn)(HRGN a0,
    HRGN a1)
    = EqualRgn;

DWORD(__stdcall* Real_EraseTape)(HANDLE a0,
    DWORD a1,
    BOOL a2)
    = EraseTape;

int(__stdcall* Real_Escape)(HDC a0,
    int a1,
    int a2,
    LPCSTR a3,
    LPVOID a4)
    = Escape;

BOOL(__stdcall* Real_EscapeCommFunction)(HANDLE a0,
    DWORD a1)
    = EscapeCommFunction;

int(__stdcall* Real_ExcludeClipRect)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4)
    = ExcludeClipRect;

int(__stdcall* Real_ExcludeUpdateRgn)(HDC a0,
    HWND a1)
    = ExcludeUpdateRgn;

void(__stdcall* Real_ExitProcess)(UINT a0)
= ExitProcess;

void(__stdcall* Real_ExitThread)(DWORD a0)
= ExitThread;

BOOL(__stdcall* Real_ExitWindowsEx)(UINT a0,
    DWORD a1)
    = ExitWindowsEx;

DWORD(__stdcall* Real_ExpandEnvironmentStringsA)(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
    = ExpandEnvironmentStringsA;

DWORD(__stdcall* Real_ExpandEnvironmentStringsW)(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
    = ExpandEnvironmentStringsW;

HPEN(__stdcall* Real_ExtCreatePen)(DWORD a0,
    DWORD a1,
    CONST LOGBRUSH* a2,
    DWORD a3,
    CONST DWORD* a4)
    = ExtCreatePen;

HRGN(__stdcall* Real_ExtCreateRegion)(CONST XFORM* a0,
    DWORD a1,
    CONST RGNDATA* a2)
    = ExtCreateRegion;

int(__stdcall* Real_ExtEscape)(HDC a0,
    int a1,
    int a2,
    LPCSTR a3,
    int a4,
    LPSTR a5)
    = ExtEscape;

BOOL(__stdcall* Real_ExtFloodFill)(HDC a0,
    int a1,
    int a2,
    COLORREF a3,
    UINT a4)
    = ExtFloodFill;

int(__stdcall* Real_ExtSelectClipRgn)(HDC a0,
    HRGN a1,
    int a2)
    = ExtSelectClipRgn;

BOOL(__stdcall* Real_ExtTextOutA)(HDC a0,
    int a1,
    int a2,
    UINT a3,
    CONST RECT* a4,
    LPCSTR a5,
    UINT a6,
    CONST INT* a7)
    = ExtTextOutA;

BOOL(__stdcall* Real_ExtTextOutW)(HDC a0,
    int a1,
    int a2,
    UINT a3,
    CONST RECT* a4,
    LPCWSTR a5,
    UINT a6,
    CONST INT* a7)
    = ExtTextOutW;

void(__stdcall* Real_FatalAppExitA)(UINT a0,
    LPCSTR a1)
    = FatalAppExitA;

void(__stdcall* Real_FatalAppExitW)(UINT a0,
    LPCWSTR a1)
    = FatalAppExitW;

void(__stdcall* Real_FatalExit)(int a0)
= FatalExit;

BOOL(__stdcall* Real_FileTimeToDosDateTime)(CONST FILETIME* a0,
    LPWORD a1,
    LPWORD a2)
    = FileTimeToDosDateTime;

BOOL(__stdcall* Real_FileTimeToLocalFileTime)(CONST FILETIME* a0,
    LPFILETIME a1)
    = FileTimeToLocalFileTime;

BOOL(__stdcall* Real_FileTimeToSystemTime)(CONST FILETIME* a0,
    LPSYSTEMTIME a1)
    = FileTimeToSystemTime;

BOOL(__stdcall* Real_FillConsoleOutputAttribute)(HANDLE a0,
    WORD a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
    = FillConsoleOutputAttribute;

BOOL(__stdcall* Real_FillConsoleOutputCharacterA)(HANDLE a0,
    CHAR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
    = FillConsoleOutputCharacterA;

BOOL(__stdcall* Real_FillConsoleOutputCharacterW)(HANDLE a0,
    WCHAR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
    = FillConsoleOutputCharacterW;

BOOL(__stdcall* Real_FillPath)(HDC a0)
= FillPath;

int(__stdcall* Real_FillRect)(HDC a0,
    CONST RECT* a1,
    HBRUSH a2)
    = FillRect;

BOOL(__stdcall* Real_FillRgn)(HDC a0,
    HRGN a1,
    HBRUSH a2)
    = FillRgn;

ATOM(__stdcall* Real_FindAtomA)(LPCSTR a0)
= FindAtomA;

ATOM(__stdcall* Real_FindAtomW)(LPCWSTR a0)
= FindAtomW;

BOOL(__stdcall* Real_FindClose)(HANDLE a0)
= FindClose;

BOOL(__stdcall* Real_FindCloseChangeNotification)(HANDLE a0)
= FindCloseChangeNotification;

HANDLE(__stdcall* Real_FindFirstChangeNotificationA)(LPCSTR a0,
    BOOL a1,
    DWORD a2)
    = FindFirstChangeNotificationA;

HANDLE(__stdcall* Real_FindFirstChangeNotificationW)(LPCWSTR a0,
    BOOL a1,
    DWORD a2)
    = FindFirstChangeNotificationW;

HANDLE(__stdcall* Real_FindFirstFileA)(LPCSTR a0,
    LPWIN32_FIND_DATAA a1)
    = FindFirstFileA;

HANDLE(__stdcall* Real_FindFirstFileExA)(LPCSTR a0,
    FINDEX_INFO_LEVELS a1,
    LPVOID a2,
    FINDEX_SEARCH_OPS a3,
    LPVOID a4,
    DWORD a5)
    = FindFirstFileExA;

HANDLE(__stdcall* Real_FindFirstFileExW)(LPCWSTR a0,
    FINDEX_INFO_LEVELS a1,
    LPVOID a2,
    FINDEX_SEARCH_OPS a3,
    LPVOID a4,
    DWORD a5)
    = FindFirstFileExW;

HANDLE(__stdcall* Real_FindFirstFileW)(LPCWSTR a0,
    LPWIN32_FIND_DATAW a1)
    = FindFirstFileW;

BOOL(__stdcall* Real_FindNextChangeNotification)(HANDLE a0)
= FindNextChangeNotification;

BOOL(__stdcall* Real_FindNextFileA)(HANDLE a0,
    LPWIN32_FIND_DATAA a1)
    = FindNextFileA;

BOOL(__stdcall* Real_FindNextFileW)(HANDLE a0,
    LPWIN32_FIND_DATAW a1)
    = FindNextFileW;

HRSRC(__stdcall* Real_FindResourceA)(HMODULE a0,
    LPCSTR a1,
    LPCSTR a2)
    = FindResourceA;

HRSRC(__stdcall* Real_FindResourceExA)(HMODULE a0,
    LPCSTR a1,
    LPCSTR a2,
    WORD a3)
    = FindResourceExA;

HRSRC(__stdcall* Real_FindResourceExW)(HMODULE a0,
    LPCWSTR a1,
    LPCWSTR a2,
    WORD a3)
    = FindResourceExW;

HRSRC(__stdcall* Real_FindResourceW)(HMODULE a0,
    LPCWSTR a1,
    LPCWSTR a2)
    = FindResourceW;

HWND(__stdcall* Real_FindWindowA)(LPCSTR a0,
    LPCSTR a1)
    = FindWindowA;

HWND(__stdcall* Real_FindWindowExA)(HWND a0,
    HWND a1,
    LPCSTR a2,
    LPCSTR a3)
    = FindWindowExA;

HWND(__stdcall* Real_FindWindowExW)(HWND a0,
    HWND a1,
    LPCWSTR a2,
    LPCWSTR a3)
    = FindWindowExW;

HWND(__stdcall* Real_FindWindowW)(LPCWSTR a0,
    LPCWSTR a1)
    = FindWindowW;

BOOL(__stdcall* Real_FixBrushOrgEx)(HDC a0,
    int a1,
    int a2,
    POINT* a3)
    = FixBrushOrgEx;

BOOL(__stdcall* Real_FlashWindow)(HWND a0,
    BOOL a1)
    = FlashWindow;

BOOL(__stdcall* Real_FlattenPath)(HDC a0)
= FlattenPath;

BOOL(__stdcall* Real_FloodFill)(HDC a0,
    int a1,
    int a2,
    COLORREF a3)
    = FloodFill;

BOOL(__stdcall* Real_FlushConsoleInputBuffer)(HANDLE a0)
= FlushConsoleInputBuffer;

BOOL(__stdcall* Real_FlushFileBuffers)(HANDLE a0)
= FlushFileBuffers;

BOOL(__stdcall* Real_FlushViewOfFile)(LPCVOID a0,
    SIZE_T a1)
    = FlushViewOfFile;

HRESULT(__stdcall* Real_FmtIdToPropStgName)(CONST FMTID* a0,
    LPOLESTR a1)
    = FmtIdToPropStgName;

int(__stdcall* Real_FoldStringA)(DWORD a0,
    LPCSTR a1,
    int a2,
    LPSTR a3,
    int a4)
    = FoldStringA;

int(__stdcall* Real_FoldStringW)(DWORD a0,
    LPCWSTR a1,
    int a2,
    LPWSTR a3,
    int a4)
    = FoldStringW;

DWORD(__stdcall* Real_FormatMessageA)(DWORD a0,
    LPCVOID a1,
    DWORD a2,
    DWORD a3,
    LPSTR a4,
    DWORD a5,
    va_list* a6)
    = FormatMessageA;

DWORD(__stdcall* Real_FormatMessageW)(DWORD a0,
    LPCVOID a1,
    DWORD a2,
    DWORD a3,
    LPWSTR a4,
    DWORD a5,
    va_list* a6)
    = FormatMessageW;

int(__stdcall* Real_FrameRect)(HDC a0,
    CONST RECT* a1,
    HBRUSH a2)
    = FrameRect;

BOOL(__stdcall* Real_FrameRgn)(HDC a0,
    HRGN a1,
    HBRUSH a2,
    int a3,
    int a4)
    = FrameRgn;

BOOL(__stdcall* Real_FreeConsole)(void)
= FreeConsole;

BOOL(__stdcall* Real_FreeDDElParam)(UINT a0,
    LPARAM a1)
    = FreeDDElParam;

BOOL(__stdcall* Real_FreeEnvironmentStringsA)(LPSTR a0)
= FreeEnvironmentStringsA;

BOOL(__stdcall* Real_FreeEnvironmentStringsW)(LPWSTR a0)
= FreeEnvironmentStringsW;

BOOL(__stdcall* Real_FreeLibrary)(HMODULE a0)
= FreeLibrary;

void(__stdcall* Real_FreeLibraryAndExitThread)(HMODULE a0,
    DWORD a1)
    = FreeLibraryAndExitThread;

HRESULT(__stdcall* Real_FreePropVariantArray)(ULONG a0,
    PROPVARIANT* a1)
    = FreePropVariantArray;

BOOL(__stdcall* Real_FreeResource)(HGLOBAL a0)
= FreeResource;

BOOL(__stdcall* Real_GdiComment)(HDC a0,
    UINT a1,
    CONST BYTE* a2)
    = GdiComment;

BOOL(__stdcall* Real_GdiFlush)(void)
= GdiFlush;

DWORD(__stdcall* Real_GdiGetBatchLimit)(void)
= GdiGetBatchLimit;

DWORD(__stdcall* Real_GdiSetBatchLimit)(DWORD a0)
= GdiSetBatchLimit;

BOOL(__stdcall* Real_GenerateConsoleCtrlEvent)(DWORD a0,
    DWORD a1)
    = GenerateConsoleCtrlEvent;

UINT(__stdcall* Real_GetACP)(void)
= GetACP;

HWND(__stdcall* Real_GetActiveWindow)(void)
= GetActiveWindow;

int(__stdcall* Real_GetArcDirection)(HDC a0)
= GetArcDirection;

BOOL(__stdcall* Real_GetAspectRatioFilterEx)(HDC a0,
    SIZE* a1)
    = GetAspectRatioFilterEx;

SHORT(__stdcall* Real_GetAsyncKeyState)(int a0)
= GetAsyncKeyState;

UINT(__stdcall* Real_GetAtomNameA)(ATOM a0,
    LPSTR a1,
    int a2)
    = GetAtomNameA;

UINT(__stdcall* Real_GetAtomNameW)(ATOM a0,
    LPWSTR a1,
    int a2)
    = GetAtomNameW;

BOOL(__stdcall* Real_GetBinaryTypeA)(LPCSTR a0,
    LPDWORD a1)
    = GetBinaryTypeA;

BOOL(__stdcall* Real_GetBinaryTypeW)(LPCWSTR a0,
    LPDWORD a1)
    = GetBinaryTypeW;

LONG(__stdcall* Real_GetBitmapBits)(HBITMAP a0,
    LONG a1,
    LPVOID a2)
    = GetBitmapBits;

BOOL(__stdcall* Real_GetBitmapDimensionEx)(HBITMAP a0,
    SIZE* a1)
    = GetBitmapDimensionEx;

COLORREF(__stdcall* Real_GetBkColor)(HDC a0)
= GetBkColor;

int(__stdcall* Real_GetBkMode)(HDC a0)
= GetBkMode;

UINT(__stdcall* Real_GetBoundsRect)(HDC a0,
    LPRECT a1,
    UINT a2)
    = GetBoundsRect;

BOOL(__stdcall* Real_GetBrushOrgEx)(HDC a0,
    POINT* a1)
    = GetBrushOrgEx;

BOOL(__stdcall* Real_GetCPInfo)(UINT a0,
    LPCPINFO a1)
    = GetCPInfo;

HWND(__stdcall* Real_GetCapture)(void)
= GetCapture;

UINT(__stdcall* Real_GetCaretBlinkTime)(void)
= GetCaretBlinkTime;

BOOL(__stdcall* Real_GetCaretPos)(POINT* a0)
= GetCaretPos;

BOOL(__stdcall* Real_GetCharABCWidthsA)(HDC a0,
    UINT a1,
    UINT a2,
    LPABC a3)
    = GetCharABCWidthsA;

BOOL(__stdcall* Real_GetCharABCWidthsFloatA)(HDC a0,
    UINT a1,
    UINT a2,
    LPABCFLOAT a3)
    = GetCharABCWidthsFloatA;

BOOL(__stdcall* Real_GetCharABCWidthsFloatW)(HDC a0,
    UINT a1,
    UINT a2,
    LPABCFLOAT a3)
    = GetCharABCWidthsFloatW;

BOOL(__stdcall* Real_GetCharABCWidthsW)(HDC a0,
    UINT a1,
    UINT a2,
    LPABC a3)
    = GetCharABCWidthsW;

BOOL(__stdcall* Real_GetCharWidth32A)(HDC a0,
    UINT a1,
    UINT a2,
    LPINT a3)
    = GetCharWidth32A;

BOOL(__stdcall* Real_GetCharWidth32W)(HDC a0,
    UINT a1,
    UINT a2,
    LPINT a3)
    = GetCharWidth32W;

BOOL(__stdcall* Real_GetCharWidthA)(HDC a0,
    UINT a1,
    UINT a2,
    LPINT a3)
    = GetCharWidthA;

BOOL(__stdcall* Real_GetCharWidthFloatA)(HDC a0,
    UINT a1,
    UINT a2,
    PFLOAT a3)
    = GetCharWidthFloatA;

BOOL(__stdcall* Real_GetCharWidthFloatW)(HDC a0,
    UINT a1,
    UINT a2,
    PFLOAT a3)
    = GetCharWidthFloatW;

BOOL(__stdcall* Real_GetCharWidthW)(HDC a0,
    UINT a1,
    UINT a2,
    LPINT a3)
    = GetCharWidthW;

DWORD(__stdcall* Real_GetCharacterPlacementA)(HDC a0,
    LPCSTR a1,
    int a2,
    int a3,
    LPGCP_RESULTSA a4,
    DWORD a5)
    = GetCharacterPlacementA;

DWORD(__stdcall* Real_GetCharacterPlacementW)(HDC a0,
    LPCWSTR a1,
    int a2,
    int a3,
    LPGCP_RESULTSW a4,
    DWORD a5)
    = GetCharacterPlacementW;

HRESULT(__stdcall* Real_GetClassFile)(LPCOLESTR a0,
    CLSID* a1)
    = GetClassFile;

BOOL(__stdcall* Real_GetClassInfoA)(HINSTANCE a0,
    LPCSTR a1,
    LPWNDCLASSA a2)
    = GetClassInfoA;

BOOL(__stdcall* Real_GetClassInfoExA)(HINSTANCE a0,
    LPCSTR a1,
    LPWNDCLASSEXA a2)
    = GetClassInfoExA;

BOOL(__stdcall* Real_GetClassInfoExW)(HINSTANCE a0,
    LPCWSTR a1,
    LPWNDCLASSEXW a2)
    = GetClassInfoExW;

BOOL(__stdcall* Real_GetClassInfoW)(HINSTANCE a0,
    LPCWSTR a1,
    LPWNDCLASSW a2)
    = GetClassInfoW;

DWORD(__stdcall* Real_GetClassLongA)(HWND a0,
    int a1)
    = GetClassLongA;

DWORD(__stdcall* Real_GetClassLongW)(HWND a0,
    int a1)
    = GetClassLongW;

int(__stdcall* Real_GetClassNameA)(HWND a0,
    LPSTR a1,
    int a2)
    = GetClassNameA;

int(__stdcall* Real_GetClassNameW)(HWND a0,
    LPWSTR a1,
    int a2)
    = GetClassNameW;

WORD(__stdcall* Real_GetClassWord)(HWND a0,
    int a1)
    = GetClassWord;

BOOL(__stdcall* Real_GetClientRect)(HWND a0,
    LPRECT a1)
    = GetClientRect;

int(__stdcall* Real_GetClipBox)(HDC a0,
    LPRECT a1)
    = GetClipBox;

BOOL(__stdcall* Real_GetClipCursor)(LPRECT a0)
= GetClipCursor;

int(__stdcall* Real_GetClipRgn)(HDC a0,
    HRGN a1)
    = GetClipRgn;

HANDLE(__stdcall* Real_GetClipboardData)(UINT a0)
= GetClipboardData;

int(__stdcall* Real_GetClipboardFormatNameA)(UINT a0,
    LPSTR a1,
    int a2)
    = GetClipboardFormatNameA;

int(__stdcall* Real_GetClipboardFormatNameW)(UINT a0,
    LPWSTR a1,
    int a2)
    = GetClipboardFormatNameW;

HWND(__stdcall* Real_GetClipboardOwner)(void)
= GetClipboardOwner;

HWND(__stdcall* Real_GetClipboardViewer)(void)
= GetClipboardViewer;

BOOL(__stdcall* Real_GetColorAdjustment)(HDC a0,
    LPCOLORADJUSTMENT a1)
    = GetColorAdjustment;

HCOLORSPACE(__stdcall* Real_GetColorSpace)(HDC a0)
= GetColorSpace;

BOOL(__stdcall* Real_GetCommConfig)(HANDLE a0,
    LPCOMMCONFIG a1,
    LPDWORD a2)
    = GetCommConfig;

BOOL(__stdcall* Real_GetCommMask)(HANDLE a0,
    LPDWORD a1)
    = GetCommMask;

BOOL(__stdcall* Real_GetCommModemStatus)(HANDLE a0,
    LPDWORD a1)
    = GetCommModemStatus;

BOOL(__stdcall* Real_GetCommProperties)(HANDLE a0,
    LPCOMMPROP a1)
    = GetCommProperties;

BOOL(__stdcall* Real_GetCommState)(HANDLE a0,
    LPDCB a1)
    = GetCommState;

BOOL(__stdcall* Real_GetCommTimeouts)(HANDLE a0,
    LPCOMMTIMEOUTS a1)
    = GetCommTimeouts;

LPSTR(__stdcall* Real_GetCommandLineA)(void)
= GetCommandLineA;

LPWSTR(__stdcall* Real_GetCommandLineW)(void)
= GetCommandLineW;

BOOL(__stdcall* Real_GetComputerNameA)(LPSTR a0,
    LPDWORD a1)
    = GetComputerNameA;

BOOL(__stdcall* Real_GetComputerNameW)(LPWSTR a0,
    LPDWORD a1)
    = GetComputerNameW;

UINT(__stdcall* Real_GetConsoleCP)(void)
= GetConsoleCP;

BOOL(__stdcall* Real_GetConsoleCursorInfo)(HANDLE a0,
    PCONSOLE_CURSOR_INFO a1)
    = GetConsoleCursorInfo;

BOOL(__stdcall* Real_GetConsoleMode)(HANDLE a0,
    LPDWORD a1)
    = GetConsoleMode;

UINT(__stdcall* Real_GetConsoleOutputCP)(void)
= GetConsoleOutputCP;

BOOL(__stdcall* Real_GetConsoleScreenBufferInfo)(HANDLE a0,
    PCONSOLE_SCREEN_BUFFER_INFO a1)
    = GetConsoleScreenBufferInfo;

DWORD(__stdcall* Real_GetConsoleTitleA)(LPSTR a0,
    DWORD a1)
    = GetConsoleTitleA;

DWORD(__stdcall* Real_GetConsoleTitleW)(LPWSTR a0,
    DWORD a1)
    = GetConsoleTitleW;

HRESULT(__stdcall* Real_GetConvertStg)(IStorage* a0)
= GetConvertStg;

int(__stdcall* Real_GetCurrencyFormatA)(LCID a0,
    DWORD a1,
    LPCSTR a2,
    CONST CURRENCYFMTA* a3,
    LPSTR a4,
    int a5)
    = GetCurrencyFormatA;

int(__stdcall* Real_GetCurrencyFormatW)(LCID a0,
    DWORD a1,
    LPCWSTR a2,
    CONST CURRENCYFMTW* a3,
    LPWSTR a4,
    int a5)
    = GetCurrencyFormatW;

DWORD(__stdcall* Real_GetCurrentDirectoryA)(DWORD a0,
    LPSTR a1)
    = GetCurrentDirectoryA;

DWORD(__stdcall* Real_GetCurrentDirectoryW)(DWORD a0,
    LPWSTR a1)
    = GetCurrentDirectoryW;

HGDIOBJ(__stdcall* Real_GetCurrentObject)(HDC a0,
    UINT a1)
    = GetCurrentObject;

BOOL(__stdcall* Real_GetCurrentPositionEx)(HDC a0,
    POINT* a1)
    = GetCurrentPositionEx;

HANDLE(__stdcall* Real_GetCurrentProcess)(void)
= GetCurrentProcess;

DWORD(__stdcall* Real_GetCurrentProcessId)(void)
= GetCurrentProcessId;

DWORD(__stdcall* Real_GetCurrentThreadId)(void)
= GetCurrentThreadId;

HCURSOR(__stdcall* Real_GetCursor)(void)
= GetCursor;

BOOL(__stdcall* Real_GetCursorPos)(POINT* a0)
= GetCursorPos;

HDC(__stdcall* Real_GetDC)(HWND a0)
= GetDC;

HDC(__stdcall* Real_GetDCEx)(HWND a0,
    HRGN a1,
    DWORD a2)
    = GetDCEx;

BOOL(__stdcall* Real_GetDCOrgEx)(HDC a0,
    POINT* a1)
    = GetDCOrgEx;

UINT(__stdcall* Real_GetDIBColorTable)(HDC a0,
    UINT a1,
    UINT a2,
    RGBQUAD* a3)
    = GetDIBColorTable;

int(__stdcall* Real_GetDIBits)(HDC a0,
    HBITMAP a1,
    UINT a2,
    UINT a3,
    LPVOID a4,
    LPBITMAPINFO a5,
    UINT a6)
    = GetDIBits;

int(__stdcall* Real_GetDateFormatA)(LCID a0,
    DWORD a1,
    CONST SYSTEMTIME* a2,
    LPCSTR a3,
    LPSTR a4,
    int a5)
    = GetDateFormatA;

int(__stdcall* Real_GetDateFormatW)(LCID a0,
    DWORD a1,
    CONST SYSTEMTIME* a2,
    LPCWSTR a3,
    LPWSTR a4,
    int a5)
    = GetDateFormatW;

BOOL(__stdcall* Real_GetDefaultCommConfigA)(LPCSTR a0,
    LPCOMMCONFIG a1,
    LPDWORD a2)
    = GetDefaultCommConfigA;

BOOL(__stdcall* Real_GetDefaultCommConfigW)(LPCWSTR a0,
    LPCOMMCONFIG a1,
    LPDWORD a2)
    = GetDefaultCommConfigW;

HWND(__stdcall* Real_GetDesktopWindow)(void)
= GetDesktopWindow;

int(__stdcall* Real_GetDeviceCaps)(HDC a0,
    int a1)
    = GetDeviceCaps;

BOOL(__stdcall* Real_GetDeviceGammaRamp)(HDC a0,
    LPVOID a1)
    = GetDeviceGammaRamp;

long(__stdcall* Real_GetDialogBaseUnits)(void)
= GetDialogBaseUnits;

BOOL(__stdcall* Real_GetDiskFreeSpaceA)(LPCSTR a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
    = GetDiskFreeSpaceA;

BOOL(__stdcall* Real_GetDiskFreeSpaceExA)(LPCSTR a0,
    union _ULARGE_INTEGER* a1,
    union _ULARGE_INTEGER* a2,
    union _ULARGE_INTEGER* a3)
    = GetDiskFreeSpaceExA;

BOOL(__stdcall* Real_GetDiskFreeSpaceExW)(LPCWSTR a0,
    union _ULARGE_INTEGER* a1,
    union _ULARGE_INTEGER* a2,
    union _ULARGE_INTEGER* a3)
    = GetDiskFreeSpaceExW;

BOOL(__stdcall* Real_GetDiskFreeSpaceW)(LPCWSTR a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
    = GetDiskFreeSpaceW;

int(__stdcall* Real_GetDlgCtrlID)(HWND a0)
= GetDlgCtrlID;

HWND(__stdcall* Real_GetDlgItem)(HWND a0,
    int a1)
    = GetDlgItem;

UINT(__stdcall* Real_GetDlgItemInt)(HWND a0,
    int a1,
    BOOL* a2,
    BOOL a3)
    = GetDlgItemInt;

UINT(__stdcall* Real_GetDlgItemTextA)(HWND a0,
    int a1,
    LPSTR a2,
    int a3)
    = GetDlgItemTextA;

UINT(__stdcall* Real_GetDlgItemTextW)(HWND a0,
    int a1,
    LPWSTR a2,
    int a3)
    = GetDlgItemTextW;

UINT(__stdcall* Real_GetDoubleClickTime)(void)
= GetDoubleClickTime;

UINT(__stdcall* Real_GetDriveTypeA)(LPCSTR a0)
= GetDriveTypeA;

UINT(__stdcall* Real_GetDriveTypeW)(LPCWSTR a0)
= GetDriveTypeW;

HENHMETAFILE(__stdcall* Real_GetEnhMetaFileA)(LPCSTR a0)
= GetEnhMetaFileA;

UINT(__stdcall* Real_GetEnhMetaFileBits)(HENHMETAFILE a0,
    UINT a1,
    LPBYTE a2)
    = GetEnhMetaFileBits;

UINT(__stdcall* Real_GetEnhMetaFileDescriptionA)(HENHMETAFILE a0,
    UINT a1,
    LPSTR a2)
    = GetEnhMetaFileDescriptionA;

UINT(__stdcall* Real_GetEnhMetaFileDescriptionW)(HENHMETAFILE a0,
    UINT a1,
    LPWSTR a2)
    = GetEnhMetaFileDescriptionW;

UINT(__stdcall* Real_GetEnhMetaFileHeader)(HENHMETAFILE a0,
    UINT a1,
    ENHMETAHEADER* a2)
    = GetEnhMetaFileHeader;

UINT(__stdcall* Real_GetEnhMetaFilePaletteEntries)(HENHMETAFILE a0,
    UINT a1,
    PALETTEENTRY* a2)
    = GetEnhMetaFilePaletteEntries;

UINT(__stdcall* Real_GetEnhMetaFilePixelFormat)(HENHMETAFILE a0,
    UINT a1,
    PIXELFORMATDESCRIPTOR* a2)
    = GetEnhMetaFilePixelFormat;

HENHMETAFILE(__stdcall* Real_GetEnhMetaFileW)(LPCWSTR a0)
= GetEnhMetaFileW;

#undef GetEnvironmentStrings

LPSTR(__stdcall* Real_GetEnvironmentStrings)(void)
= GetEnvironmentStrings;

LPWSTR(__stdcall* Real_GetEnvironmentStringsW)(void)
= GetEnvironmentStringsW;

DWORD(__stdcall* Real_GetEnvironmentVariableA)(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
    = GetEnvironmentVariableA;

DWORD(__stdcall* Real_GetEnvironmentVariableW)(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
    = GetEnvironmentVariableW;

BOOL(__stdcall* Real_GetExitCodeProcess)(HANDLE a0,
    LPDWORD a1)
    = GetExitCodeProcess;

BOOL(__stdcall* Real_GetExitCodeThread)(HANDLE a0,
    LPDWORD a1)
    = GetExitCodeThread;

DWORD(__stdcall* Real_GetFileAttributesA)(LPCSTR a0)
= GetFileAttributesA;

BOOL(__stdcall* Real_GetFileAttributesExA)(LPCSTR a0,
    enum _GET_FILEEX_INFO_LEVELS a1,
    LPVOID a2)
    = GetFileAttributesExA;

BOOL(__stdcall* Real_GetFileAttributesExW)(LPCWSTR a0,
    enum _GET_FILEEX_INFO_LEVELS a1,
    LPVOID a2)
    = GetFileAttributesExW;

DWORD(__stdcall* Real_GetFileAttributesW)(LPCWSTR a0)
= GetFileAttributesW;

BOOL(__stdcall* Real_GetFileInformationByHandle)(HANDLE a0,
    LPBY_HANDLE_FILE_INFORMATION a1)
    = GetFileInformationByHandle;

DWORD(__stdcall* Real_GetFileSize)(HANDLE a0,
    LPDWORD a1)
    = GetFileSize;

BOOL(__stdcall* Real_GetFileTime)(HANDLE a0,
    LPFILETIME a1,
    LPFILETIME a2,
    LPFILETIME a3)
    = GetFileTime;

DWORD(__stdcall* Real_GetFileType)(HANDLE a0)
= GetFileType;

HWND(__stdcall* Real_GetFocus)(void)
= GetFocus;

DWORD(__stdcall* Real_GetFontData)(HDC a0,
    DWORD a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4)
    = GetFontData;

DWORD(__stdcall* Real_GetFontLanguageInfo)(HDC a0)
= GetFontLanguageInfo;

HWND(__stdcall* Real_GetForegroundWindow)(void)
= GetForegroundWindow;

DWORD(__stdcall* Real_GetFullPathNameA)(LPCSTR a0,
    DWORD a1,
    LPSTR a2,
    LPSTR* a3)
    = GetFullPathNameA;

DWORD(__stdcall* Real_GetFullPathNameW)(LPCWSTR a0,
    DWORD a1,
    LPWSTR a2,
    LPWSTR* a3)
    = GetFullPathNameW;

DWORD(__stdcall* Real_GetGlyphOutlineA)(HDC a0,
    UINT a1,
    UINT a2,
    LPGLYPHMETRICS a3,
    DWORD a4,
    LPVOID a5,
    CONST MAT2* a6)
    = GetGlyphOutlineA;

DWORD(__stdcall* Real_GetGlyphOutlineW)(HDC a0,
    UINT a1,
    UINT a2,
    LPGLYPHMETRICS a3,
    DWORD a4,
    LPVOID a5,
    CONST MAT2* a6)
    = GetGlyphOutlineW;

int(__stdcall* Real_GetGraphicsMode)(HDC a0)
= GetGraphicsMode;

HRESULT(__stdcall* Real_GetHGlobalFromILockBytes)(ILockBytes* a0,
    HGLOBAL* a1)
    = GetHGlobalFromILockBytes;

HRESULT(__stdcall* Real_GetHGlobalFromStream)(LPSTREAM a0,
    HGLOBAL* a1)
    = GetHGlobalFromStream;

BOOL(__stdcall* Real_GetHandleInformation)(HANDLE a0,
    LPDWORD a1)
    = GetHandleInformation;

BOOL(__stdcall* Real_GetICMProfileA)(HDC a0,
    LPDWORD a1,
    LPSTR a2)
    = GetICMProfileA;

BOOL(__stdcall* Real_GetICMProfileW)(HDC a0,
    LPDWORD a1,
    LPWSTR a2)
    = GetICMProfileW;

BOOL(__stdcall* Real_GetIconInfo)(HICON a0,
    PICONINFO a1)
    = GetIconInfo;

BOOL(__stdcall* Real_GetInputState)(void)
= GetInputState;

UINT(__stdcall* Real_GetKBCodePage)(void)
= GetKBCodePage;

DWORD(__stdcall* Real_GetKerningPairsA)(HDC a0,
    DWORD a1,
    KERNINGPAIR* a2)
    = GetKerningPairsA;

DWORD(__stdcall* Real_GetKerningPairsW)(HDC a0,
    DWORD a1,
    KERNINGPAIR* a2)
    = GetKerningPairsW;

int(__stdcall* Real_GetKeyNameTextA)(LONG a0,
    LPSTR a1,
    int a2)
    = GetKeyNameTextA;

int(__stdcall* Real_GetKeyNameTextW)(LONG a0,
    LPWSTR a1,
    int a2)
    = GetKeyNameTextW;

SHORT(__stdcall* Real_GetKeyState)(int a0)
= GetKeyState;

HKL(__stdcall* Real_GetKeyboardLayout)(DWORD a0)
= GetKeyboardLayout;

int(__stdcall* Real_GetKeyboardLayoutList)(int a0,
    HKL* a1)
    = GetKeyboardLayoutList;

BOOL(__stdcall* Real_GetKeyboardLayoutNameA)(LPSTR a0)
= GetKeyboardLayoutNameA;

BOOL(__stdcall* Real_GetKeyboardLayoutNameW)(LPWSTR a0)
= GetKeyboardLayoutNameW;

BOOL(__stdcall* Real_GetKeyboardState)(PBYTE a0)
= GetKeyboardState;

int(__stdcall* Real_GetKeyboardType)(int a0)
= GetKeyboardType;

HWND(__stdcall* Real_GetLastActivePopup)(HWND a0)
= GetLastActivePopup;

void(__stdcall* Real_GetLocalTime)(LPSYSTEMTIME a0)
= GetLocalTime;

int(__stdcall* Real_GetLocaleInfoA)(LCID a0,
    LCTYPE a1,
    LPSTR a2,
    int a3)
    = GetLocaleInfoA;

int(__stdcall* Real_GetLocaleInfoW)(LCID a0,
    LCTYPE a1,
    LPWSTR a2,
    int a3)
    = GetLocaleInfoW;

BOOL(__stdcall* Real_GetLogColorSpaceA)(HCOLORSPACE a0,
    LOGCOLORSPACEA* a1,
    DWORD a2)
    = GetLogColorSpaceA;

BOOL(__stdcall* Real_GetLogColorSpaceW)(HCOLORSPACE a0,
    LOGCOLORSPACEW* a1,
    DWORD a2)
    = GetLogColorSpaceW;

DWORD(__stdcall* Real_GetLogicalDriveStringsA)(DWORD a0,
    LPSTR a1)
    = GetLogicalDriveStringsA;

DWORD(__stdcall* Real_GetLogicalDriveStringsW)(DWORD a0,
    LPWSTR a1)
    = GetLogicalDriveStringsW;

DWORD(__stdcall* Real_GetLogicalDrives)(void)
= GetLogicalDrives;

BOOL(__stdcall* Real_GetMailslotInfo)(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
    = GetMailslotInfo;

int(__stdcall* Real_GetMapMode)(HDC a0)
= GetMapMode;

HMENU(__stdcall* Real_GetMenu)(HWND a0)
= GetMenu;

LONG(__stdcall* Real_GetMenuCheckMarkDimensions)(void)
= GetMenuCheckMarkDimensions;

DWORD(__stdcall* Real_GetMenuContextHelpId)(HMENU a0)
= GetMenuContextHelpId;

UINT(__stdcall* Real_GetMenuDefaultItem)(HMENU a0,
    UINT a1,
    UINT a2)
    = GetMenuDefaultItem;

int(__stdcall* Real_GetMenuItemCount)(HMENU a0)
= GetMenuItemCount;

UINT(__stdcall* Real_GetMenuItemID)(HMENU a0,
    int a1)
    = GetMenuItemID;

BOOL(__stdcall* Real_GetMenuItemInfoA)(HMENU a0,
    UINT a1,
    BOOL a2,
    LPMENUITEMINFOA a3)
    = GetMenuItemInfoA;

BOOL(__stdcall* Real_GetMenuItemInfoW)(HMENU a0,
    UINT a1,
    BOOL a2,
    LPMENUITEMINFOW a3)
    = GetMenuItemInfoW;

BOOL(__stdcall* Real_GetMenuItemRect)(HWND a0,
    HMENU a1,
    UINT a2,
    LPRECT a3)
    = GetMenuItemRect;

UINT(__stdcall* Real_GetMenuState)(HMENU a0,
    UINT a1,
    UINT a2)
    = GetMenuState;

int(__stdcall* Real_GetMenuStringA)(HMENU a0,
    UINT a1,
    LPSTR a2,
    int a3,
    UINT a4)
    = GetMenuStringA;

int(__stdcall* Real_GetMenuStringW)(HMENU a0,
    UINT a1,
    LPWSTR a2,
    int a3,
    UINT a4)
    = GetMenuStringW;

BOOL(__stdcall* Real_GetMessageA)(LPMSG a0,
    HWND a1,
    UINT a2,
    UINT a3)
    = GetMessageA;

LPARAM(__stdcall* Real_GetMessageExtraInfo)(void)
= GetMessageExtraInfo;

DWORD(__stdcall* Real_GetMessagePos)(void)
= GetMessagePos;

LONG(__stdcall* Real_GetMessageTime)(void)
= GetMessageTime;

BOOL(__stdcall* Real_GetMessageW)(LPMSG a0,
    HWND a1,
    UINT a2,
    UINT a3)
    = GetMessageW;

HMETAFILE(__stdcall* Real_GetMetaFileA)(LPCSTR a0)
= GetMetaFileA;

UINT(__stdcall* Real_GetMetaFileBitsEx)(HMETAFILE a0,
    UINT a1,
    LPVOID a2)
    = GetMetaFileBitsEx;

HMETAFILE(__stdcall* Real_GetMetaFileW)(LPCWSTR a0)
= GetMetaFileW;

int(__stdcall* Real_GetMetaRgn)(HDC a0,
    HRGN a1)
    = GetMetaRgn;

BOOL(__stdcall* Real_GetMiterLimit)(HDC a0,
    PFLOAT a1)
    = GetMiterLimit;

DWORD(__stdcall* Real_GetModuleFileNameA)(HMODULE a0,
    LPSTR a1,
    DWORD a2)
    = GetModuleFileNameA;

DWORD(__stdcall* Real_GetModuleFileNameW)(HMODULE a0,
    LPWSTR a1,
    DWORD a2)
    = GetModuleFileNameW;

HMODULE(__stdcall* Real_GetModuleHandleA)(LPCSTR a0)
= GetModuleHandleA;

HMODULE(__stdcall* Real_GetModuleHandleW)(LPCWSTR a0)
= GetModuleHandleW;

BOOL(__stdcall* Real_GetNamedPipeHandleStateA)(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPSTR a5,
    DWORD a6)
    = GetNamedPipeHandleStateA;

BOOL(__stdcall* Real_GetNamedPipeHandleStateW)(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPWSTR a5,
    DWORD a6)
    = GetNamedPipeHandleStateW;

BOOL(__stdcall* Real_GetNamedPipeInfo)(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
    = GetNamedPipeInfo;

COLORREF(__stdcall* Real_GetNearestColor)(HDC a0,
    COLORREF a1)
    = GetNearestColor;

UINT(__stdcall* Real_GetNearestPaletteIndex)(HPALETTE a0,
    COLORREF a1)
    = GetNearestPaletteIndex;

HWND(__stdcall* Real_GetNextDlgGroupItem)(HWND a0,
    HWND a1,
    BOOL a2)
    = GetNextDlgGroupItem;

HWND(__stdcall* Real_GetNextDlgTabItem)(HWND a0,
    HWND a1,
    BOOL a2)
    = GetNextDlgTabItem;

int(__stdcall* Real_GetNumberFormatA)(LCID a0,
    DWORD a1,
    LPCSTR a2,
    CONST NUMBERFMTA* a3,
    LPSTR a4,
    int a5)
    = GetNumberFormatA;

int(__stdcall* Real_GetNumberFormatW)(LCID a0,
    DWORD a1,
    LPCWSTR a2,
    CONST NUMBERFMTW* a3,
    LPWSTR a4,
    int a5)
    = GetNumberFormatW;

BOOL(__stdcall* Real_GetNumberOfConsoleInputEvents)(HANDLE a0,
    LPDWORD a1)
    = GetNumberOfConsoleInputEvents;

BOOL(__stdcall* Real_GetNumberOfConsoleMouseButtons)(LPDWORD a0)
= GetNumberOfConsoleMouseButtons;

UINT(__stdcall* Real_GetOEMCP)(void)
= GetOEMCP;

int(__stdcall* Real_GetObjectA)(HGDIOBJ a0,
    int a1,
    LPVOID a2)
    = GetObjectA;

DWORD(__stdcall* Real_GetObjectType)(HGDIOBJ a0)
= GetObjectType;

int(__stdcall* Real_GetObjectW)(HGDIOBJ a0,
    int a1,
    LPVOID a2)
    = GetObjectW;

HWND(__stdcall* Real_GetOpenClipboardWindow)(void)
= GetOpenClipboardWindow;

UINT(__stdcall* Real_GetOutlineTextMetricsA)(HDC a0,
    UINT a1,
    LPOUTLINETEXTMETRICA a2)
    = GetOutlineTextMetricsA;

UINT(__stdcall* Real_GetOutlineTextMetricsW)(HDC a0,
    UINT a1,
    LPOUTLINETEXTMETRICW a2)
    = GetOutlineTextMetricsW;

BOOL(__stdcall* Real_GetOverlappedResult)(HANDLE a0,
    LPOVERLAPPED a1,
    LPDWORD a2,
    BOOL a3)
    = GetOverlappedResult;

UINT(__stdcall* Real_GetPaletteEntries)(HPALETTE a0,
    UINT a1,
    UINT a2,
    PALETTEENTRY* a3)
    = GetPaletteEntries;

HWND(__stdcall* Real_GetParent)(HWND a0)
= GetParent;

int(__stdcall* Real_GetPath)(HDC a0,
    POINT* a1,
    LPBYTE a2,
    int a3)
    = GetPath;

COLORREF(__stdcall* Real_GetPixel)(HDC a0,
    int a1,
    int a2)
    = GetPixel;

int(__stdcall* Real_GetPixelFormat)(HDC a0)
= GetPixelFormat;

int(__stdcall* Real_GetPolyFillMode)(HDC a0)
= GetPolyFillMode;

DWORD(__stdcall* Real_GetPriorityClass)(HANDLE a0)
= GetPriorityClass;

int(__stdcall* Real_GetPriorityClipboardFormat)(UINT* a0,
    int a1)
    = GetPriorityClipboardFormat;

UINT(__stdcall* Real_GetPrivateProfileIntA)(LPCSTR a0,
    LPCSTR a1,
    INT a2,
    LPCSTR a3)
    = GetPrivateProfileIntA;

UINT(__stdcall* Real_GetPrivateProfileIntW)(LPCWSTR a0,
    LPCWSTR a1,
    INT a2,
    LPCWSTR a3)
    = GetPrivateProfileIntW;

DWORD(__stdcall* Real_GetPrivateProfileSectionA)(LPCSTR a0,
    LPSTR a1,
    DWORD a2,
    LPCSTR a3)
    = GetPrivateProfileSectionA;

DWORD(__stdcall* Real_GetPrivateProfileSectionNamesA)(LPSTR a0,
    DWORD a1,
    LPCSTR a2)
    = GetPrivateProfileSectionNamesA;

DWORD(__stdcall* Real_GetPrivateProfileSectionNamesW)(LPWSTR a0,
    DWORD a1,
    LPCWSTR a2)
    = GetPrivateProfileSectionNamesW;

DWORD(__stdcall* Real_GetPrivateProfileSectionW)(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2,
    LPCWSTR a3)
    = GetPrivateProfileSectionW;

DWORD(__stdcall* Real_GetPrivateProfileStringA)(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    LPSTR a3,
    DWORD a4,
    LPCSTR a5)
    = GetPrivateProfileStringA;

DWORD(__stdcall* Real_GetPrivateProfileStringW)(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    LPWSTR a3,
    DWORD a4,
    LPCWSTR a5)
    = GetPrivateProfileStringW;

BOOL(__stdcall* Real_GetPrivateProfileStructA)(LPCSTR a0,
    LPCSTR a1,
    LPVOID a2,
    UINT a3,
    LPCSTR a4)
    = GetPrivateProfileStructA;

BOOL(__stdcall* Real_GetPrivateProfileStructW)(LPCWSTR a0,
    LPCWSTR a1,
    LPVOID a2,
    UINT a3,
    LPCWSTR a4)
    = GetPrivateProfileStructW;

FARPROC(__stdcall* Real_GetProcAddress)(HMODULE a0,
    LPCSTR a1)
    = GetProcAddress;

BOOL(__stdcall* Real_GetProcessAffinityMask)(HANDLE a0,
    PDWORD_PTR a1,
    PDWORD_PTR a2)
    = GetProcessAffinityMask;

DWORD(__stdcall* Real_GetProcessHeaps)(DWORD a0,
    PHANDLE a1)
    = GetProcessHeaps;

BOOL(__stdcall* Real_GetProcessShutdownParameters)(LPDWORD a0,
    LPDWORD a1)
    = GetProcessShutdownParameters;

BOOL(__stdcall* Real_GetProcessTimes)(HANDLE a0,
    LPFILETIME a1,
    LPFILETIME a2,
    LPFILETIME a3,
    LPFILETIME a4)
    = GetProcessTimes;

DWORD(__stdcall* Real_GetProcessVersion)(DWORD a0)
= GetProcessVersion;

HWINSTA(__stdcall* Real_GetProcessWindowStation)(void)
= GetProcessWindowStation;

BOOL(__stdcall* Real_GetProcessWorkingSetSize)(HANDLE a0,
    PSIZE_T a1,
    PSIZE_T a2)
    = GetProcessWorkingSetSize;

UINT(__stdcall* Real_GetProfileIntA)(LPCSTR a0,
    LPCSTR a1,
    INT a2)
    = GetProfileIntA;

UINT(__stdcall* Real_GetProfileIntW)(LPCWSTR a0,
    LPCWSTR a1,
    INT a2)
    = GetProfileIntW;

DWORD(__stdcall* Real_GetProfileSectionA)(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
    = GetProfileSectionA;

DWORD(__stdcall* Real_GetProfileSectionW)(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
    = GetProfileSectionW;

DWORD(__stdcall* Real_GetProfileStringA)(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    LPSTR a3,
    DWORD a4)
    = GetProfileStringA;

DWORD(__stdcall* Real_GetProfileStringW)(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    LPWSTR a3,
    DWORD a4)
    = GetProfileStringW;

HANDLE(__stdcall* Real_GetPropA)(HWND a0,
    LPCSTR a1)
    = GetPropA;

HANDLE(__stdcall* Real_GetPropW)(HWND a0,
    LPCWSTR a1)
    = GetPropW;

DWORD(__stdcall* Real_GetQueueStatus)(UINT a0)
= GetQueueStatus;

BOOL(__stdcall* Real_GetQueuedCompletionStatus)(HANDLE a0,
    LPDWORD a1,
    PULONG_PTR a2,
    LPOVERLAPPED* a3,
    DWORD a4)
    = GetQueuedCompletionStatus;

int(__stdcall* Real_GetROP2)(HDC a0)
= GetROP2;

BOOL(__stdcall* Real_GetRasterizerCaps)(LPRASTERIZER_STATUS a0,
    UINT a1)
    = GetRasterizerCaps;

DWORD(__stdcall* Real_GetRegionData)(HRGN a0,
    DWORD a1,
    LPRGNDATA a2)
    = GetRegionData;

int(__stdcall* Real_GetRgnBox)(HRGN a0,
    LPRECT a1)
    = GetRgnBox;

HRESULT(__stdcall* Real_GetRunningObjectTable)(DWORD a0,
    LPRUNNINGOBJECTTABLE* a1)
    = GetRunningObjectTable;

BOOL(__stdcall* Real_GetScrollInfo)(HWND a0,
    int a1,
    LPSCROLLINFO a2)
    = GetScrollInfo;

int(__stdcall* Real_GetScrollPos)(HWND a0,
    int a1)
    = GetScrollPos;

BOOL(__stdcall* Real_GetScrollRange)(HWND a0,
    int a1,
    LPINT a2,
    LPINT a3)
    = GetScrollRange;

DWORD(__stdcall* Real_GetShortPathNameA)(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
    = GetShortPathNameA;

DWORD(__stdcall* Real_GetShortPathNameW)(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
    = GetShortPathNameW;

void(__stdcall* Real_GetStartupInfoA)(LPSTARTUPINFOA a0)
= GetStartupInfoA;

void(__stdcall* Real_GetStartupInfoW)(LPSTARTUPINFOW a0)
= GetStartupInfoW;

HANDLE(__stdcall* Real_GetStdHandle)(DWORD a0)
= GetStdHandle;

HGDIOBJ(__stdcall* Real_GetStockObject)(int a0)
= GetStockObject;

int(__stdcall* Real_GetStretchBltMode)(HDC a0)
= GetStretchBltMode;

HMENU(__stdcall* Real_GetSubMenu)(HMENU a0,
    int a1)
    = GetSubMenu;

DWORD(__stdcall* Real_GetSysColor)(int a0)
= GetSysColor;

HBRUSH(__stdcall* Real_GetSysColorBrush)(int a0)
= GetSysColorBrush;

LCID(__stdcall* Real_GetSystemDefaultLCID)(void)
= GetSystemDefaultLCID;

LANGID(__stdcall* Real_GetSystemDefaultLangID)(void)
= GetSystemDefaultLangID;

UINT(__stdcall* Real_GetSystemDirectoryA)(LPSTR a0,
    UINT a1)
    = GetSystemDirectoryA;

UINT(__stdcall* Real_GetSystemDirectoryW)(LPWSTR a0,
    UINT a1)
    = GetSystemDirectoryW;

void(__stdcall* Real_GetSystemInfo)(LPSYSTEM_INFO a0)
= GetSystemInfo;

HMENU(__stdcall* Real_GetSystemMenu)(HWND a0,
    BOOL a1)
    = GetSystemMenu;

int(__stdcall* Real_GetSystemMetrics)(int a0)
= GetSystemMetrics;

UINT(__stdcall* Real_GetSystemPaletteEntries)(HDC a0,
    UINT a1,
    UINT a2,
    PALETTEENTRY* a3)
    = GetSystemPaletteEntries;

UINT(__stdcall* Real_GetSystemPaletteUse)(HDC a0)
= GetSystemPaletteUse;

BOOL(__stdcall* Real_GetSystemPowerStatus)(LPSYSTEM_POWER_STATUS a0)
= GetSystemPowerStatus;

void(__stdcall* Real_GetSystemTime)(LPSYSTEMTIME a0)
= GetSystemTime;

BOOL(__stdcall* Real_GetSystemTimeAdjustment)(PDWORD a0,
    PDWORD a1,
    PBOOL a2)
    = GetSystemTimeAdjustment;

void(__stdcall* Real_GetSystemTimeAsFileTime)(LPFILETIME a0)
= GetSystemTimeAsFileTime;

#if _MSC_VER < 1300
DWORD(__stdcall* Real_GetTabbedTextExtentA)(HDC a0,
    LPCSTR a1,
    int a2,
    int a3,
    INT* a4)
    = GetTabbedTextExtentA;
#else
DWORD(__stdcall* Real_GetTabbedTextExtentA)(HDC a0,
    LPCSTR a1,
    int a2,
    int a3,
    CONST INT* a4)
    = GetTabbedTextExtentA;
#endif

#if _MSC_VER < 1300
DWORD(__stdcall* Real_GetTabbedTextExtentW)(HDC a0,
    LPCWSTR a1,
    int a2,
    int a3,
    INT* a4)
    = GetTabbedTextExtentW;
#else
DWORD(__stdcall* Real_GetTabbedTextExtentW)(HDC a0,
    LPCWSTR a1,
    int a2,
    int a3,
    CONST INT* a4)
    = GetTabbedTextExtentW;
#endif

DWORD(__stdcall* Real_GetTapeParameters)(HANDLE a0,
    DWORD a1,
    LPDWORD a2,
    LPVOID a3)
    = GetTapeParameters;

DWORD(__stdcall* Real_GetTapePosition)(HANDLE a0,
    DWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
    = GetTapePosition;

DWORD(__stdcall* Real_GetTapeStatus)(HANDLE a0)
= GetTapeStatus;

UINT(__stdcall* Real_GetTempFileNameA)(LPCSTR a0,
    LPCSTR a1,
    UINT a2,
    LPSTR a3)
    = GetTempFileNameA;

UINT(__stdcall* Real_GetTempFileNameW)(LPCWSTR a0,
    LPCWSTR a1,
    UINT a2,
    LPWSTR a3)
    = GetTempFileNameW;

DWORD(__stdcall* Real_GetTempPathA)(DWORD a0,
    LPSTR a1)
    = GetTempPathA;

DWORD(__stdcall* Real_GetTempPathW)(DWORD a0,
    LPWSTR a1)
    = GetTempPathW;

UINT(__stdcall* Real_GetTextAlign)(HDC a0)
= GetTextAlign;

int(__stdcall* Real_GetTextCharacterExtra)(HDC a0)
= GetTextCharacterExtra;

int(__stdcall* Real_GetTextCharset)(HDC a0)
= GetTextCharset;

int(__stdcall* Real_GetTextCharsetInfo)(HDC a0,
    LPFONTSIGNATURE a1,
    DWORD a2)
    = GetTextCharsetInfo;

COLORREF(__stdcall* Real_GetTextColor)(HDC a0)
= GetTextColor;

BOOL(__stdcall* Real_GetTextExtentExPointA)(HDC a0,
    LPCSTR a1,
    int a2,
    int a3,
    LPINT a4,
    LPINT a5,
    SIZE* a6)
    = GetTextExtentExPointA;

BOOL(__stdcall* Real_GetTextExtentExPointW)(HDC a0,
    LPCWSTR a1,
    int a2,
    int a3,
    LPINT a4,
    LPINT a5,
    SIZE* a6)
    = GetTextExtentExPointW;

BOOL(__stdcall* Real_GetTextExtentPoint32A)(HDC a0,
    LPCSTR a1,
    int a2,
    SIZE* a3)
    = GetTextExtentPoint32A;

BOOL(__stdcall* Real_GetTextExtentPoint32W)(HDC a0,
    LPCWSTR a1,
    int a2,
    SIZE* a3)
    = GetTextExtentPoint32W;

BOOL(__stdcall* Real_GetTextExtentPointA)(HDC a0,
    LPCSTR a1,
    int a2,
    SIZE* a3)
    = GetTextExtentPointA;

BOOL(__stdcall* Real_GetTextExtentPointW)(HDC a0,
    LPCWSTR a1,
    int a2,
    SIZE* a3)
    = GetTextExtentPointW;

int(__stdcall* Real_GetTextFaceA)(HDC a0,
    int a1,
    LPSTR a2)
    = GetTextFaceA;

int(__stdcall* Real_GetTextFaceW)(HDC a0,
    int a1,
    LPWSTR a2)
    = GetTextFaceW;

BOOL(__stdcall* Real_GetTextMetricsA)(HDC a0,
    LPTEXTMETRICA a1)
    = GetTextMetricsA;

BOOL(__stdcall* Real_GetTextMetricsW)(HDC a0,
    LPTEXTMETRICW a1)
    = GetTextMetricsW;

BOOL(__stdcall* Real_GetThreadContext)(HANDLE a0,
    LPCONTEXT a1)
    = GetThreadContext;

HDESK(__stdcall* Real_GetThreadDesktop)(DWORD a0)
= GetThreadDesktop;

#if(WINVER >= 0x0500)
LCID(__stdcall* Real_GetThreadLocale)(void)
= GetThreadLocale;
#endif // (WINVER >= 0x0500)

int(__stdcall* Real_GetThreadPriority)(HANDLE a0)
= GetThreadPriority;

BOOL(__stdcall* Real_GetThreadPriorityBoost)(HANDLE a0,
    PBOOL a1)
    = GetThreadPriorityBoost;

BOOL(__stdcall* Real_GetThreadSelectorEntry)(HANDLE a0,
    DWORD a1,
    LPLDT_ENTRY a2)
    = GetThreadSelectorEntry;

BOOL(__stdcall* Real_GetThreadTimes)(HANDLE a0,
    LPFILETIME a1,
    LPFILETIME a2,
    LPFILETIME a3,
    LPFILETIME a4)
    = GetThreadTimes;

DWORD(__stdcall* Real_GetTickCount)(void)
= GetTickCount;

int(__stdcall* Real_GetTimeFormatA)(LCID a0,
    DWORD a1,
    CONST SYSTEMTIME* a2,
    LPCSTR a3,
    LPSTR a4,
    int a5)
    = GetTimeFormatA;

int(__stdcall* Real_GetTimeFormatW)(LCID a0,
    DWORD a1,
    CONST SYSTEMTIME* a2,
    LPCWSTR a3,
    LPWSTR a4,
    int a5)
    = GetTimeFormatW;

DWORD(__stdcall* Real_GetTimeZoneInformation)(LPTIME_ZONE_INFORMATION a0)
= GetTimeZoneInformation;

HWND(__stdcall* Real_GetTopWindow)(HWND a0)
= GetTopWindow;

BOOL(__stdcall* Real_GetUpdateRect)(HWND a0,
    LPRECT a1,
    BOOL a2)
    = GetUpdateRect;

int(__stdcall* Real_GetUpdateRgn)(HWND a0,
    HRGN a1,
    BOOL a2)
    = GetUpdateRgn;

LCID(__stdcall* Real_GetUserDefaultLCID)(void)
= GetUserDefaultLCID;

LANGID(__stdcall* Real_GetUserDefaultLangID)(void)
= GetUserDefaultLangID;

BOOL(__stdcall* Real_GetUserObjectInformationA)(HANDLE a0,
    int a1,
    PVOID a2,
    DWORD a3,
    LPDWORD a4)
    = GetUserObjectInformationA;

BOOL(__stdcall* Real_GetUserObjectInformationW)(HANDLE a0,
    int a1,
    PVOID a2,
    DWORD a3,
    LPDWORD a4)
    = GetUserObjectInformationW;

BOOL(__stdcall* Real_GetUserObjectSecurity)(HANDLE a0,
    PSECURITY_INFORMATION a1,
    PSECURITY_DESCRIPTOR a2,
    DWORD a3,
    LPDWORD a4)
    = GetUserObjectSecurity;

DWORD(__stdcall* Real_GetVersion)(void)
= GetVersion;

BOOL(__stdcall* Real_GetVersionExA)(LPOSVERSIONINFOA a0)
= GetVersionExA;

BOOL(__stdcall* Real_GetVersionExW)(LPOSVERSIONINFOW a0)
= GetVersionExW;

BOOL(__stdcall* Real_GetViewportExtEx)(HDC a0,
    SIZE* a1)
    = GetViewportExtEx;

BOOL(__stdcall* Real_GetViewportOrgEx)(HDC a0,
    POINT* a1)
    = GetViewportOrgEx;

BOOL(__stdcall* Real_GetVolumeInformationA)(LPCSTR a0,
    LPSTR a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPDWORD a5,
    LPSTR a6,
    DWORD a7)
    = GetVolumeInformationA;

BOOL(__stdcall* Real_GetVolumeInformationW)(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPDWORD a5,
    LPWSTR a6,
    DWORD a7)
    = GetVolumeInformationW;

UINT(__stdcall* Real_GetWinMetaFileBits)(HENHMETAFILE a0,
    UINT a1,
    LPBYTE a2,
    INT a3,
    HDC a4)
    = GetWinMetaFileBits;

HWND(__stdcall* Real_GetWindow)(HWND a0,
    UINT a1)
    = GetWindow;

DWORD(__stdcall* Real_GetWindowContextHelpId)(HWND a0)
= GetWindowContextHelpId;

HDC(__stdcall* Real_GetWindowDC)(HWND a0)
= GetWindowDC;

BOOL(__stdcall* Real_GetWindowExtEx)(HDC a0,
    SIZE* a1)
    = GetWindowExtEx;

LONG(__stdcall* Real_GetWindowLongA)(HWND a0,
    int a1)
    = GetWindowLongA;

LONG(__stdcall* Real_GetWindowLongW)(HWND a0,
    int a1)
    = GetWindowLongW;

BOOL(__stdcall* Real_GetWindowOrgEx)(HDC a0,
    POINT* a1)
    = GetWindowOrgEx;

BOOL(__stdcall* Real_GetWindowPlacement)(HWND a0,
    WINDOWPLACEMENT* a1)
    = GetWindowPlacement;

BOOL(__stdcall* Real_GetWindowRect)(HWND a0,
    LPRECT a1)
    = GetWindowRect;

int(__stdcall* Real_GetWindowRgn)(HWND a0,
    HRGN a1)
    = GetWindowRgn;

int(__stdcall* Real_GetWindowTextA)(HWND a0,
    LPSTR a1,
    int a2)
    = GetWindowTextA;

int(__stdcall* Real_GetWindowTextLengthA)(HWND a0)
= GetWindowTextLengthA;

int(__stdcall* Real_GetWindowTextLengthW)(HWND a0)
= GetWindowTextLengthW;

int(__stdcall* Real_GetWindowTextW)(HWND a0,
    LPWSTR a1,
    int a2)
    = GetWindowTextW;

DWORD(__stdcall* Real_GetWindowThreadProcessId)(HWND a0,
    LPDWORD a1)
    = GetWindowThreadProcessId;

WORD(__stdcall* Real_GetWindowWord)(HWND a0,
    int a1)
    = GetWindowWord;

UINT(__stdcall* Real_GetWindowsDirectoryA)(LPSTR a0,
    UINT a1)
    = GetWindowsDirectoryA;

UINT(__stdcall* Real_GetWindowsDirectoryW)(LPWSTR a0,
    UINT a1)
    = GetWindowsDirectoryW;

BOOL(__stdcall* Real_GetWorldTransform)(HDC a0,
    XFORM* a1)
    = GetWorldTransform;

ATOM(__stdcall* Real_GlobalAddAtomA)(LPCSTR a0)
= GlobalAddAtomA;

ATOM(__stdcall* Real_GlobalAddAtomW)(LPCWSTR a0)
= GlobalAddAtomW;

HGLOBAL(__stdcall* Real_GlobalAlloc)(UINT a0,
    SIZE_T a1)
    = GlobalAlloc;

#if _MSC_VER < 1300
UINT(__stdcall* Real_GlobalCompact)(DWORD a0)
= GlobalCompact;
#else
SIZE_T(__stdcall* Real_GlobalCompact)(DWORD a0)
= GlobalCompact;
#endif

ATOM(__stdcall* Real_GlobalDeleteAtom)(ATOM a0)
= GlobalDeleteAtom;

ATOM(__stdcall* Real_GlobalFindAtomA)(LPCSTR a0)
= GlobalFindAtomA;

ATOM(__stdcall* Real_GlobalFindAtomW)(LPCWSTR a0)
= GlobalFindAtomW;

void(__stdcall* Real_GlobalFix)(HGLOBAL a0)
= GlobalFix;

UINT(__stdcall* Real_GlobalFlags)(HGLOBAL a0)
= GlobalFlags;

HGLOBAL(__stdcall* Real_GlobalFree)(HGLOBAL a0)
= GlobalFree;

UINT(__stdcall* Real_GlobalGetAtomNameA)(ATOM a0,
    LPSTR a1,
    int a2)
    = GlobalGetAtomNameA;

UINT(__stdcall* Real_GlobalGetAtomNameW)(ATOM a0,
    LPWSTR a1,
    int a2)
    = GlobalGetAtomNameW;

HGLOBAL(__stdcall* Real_GlobalHandle)(LPCVOID a0)
= GlobalHandle;

LPVOID(__stdcall* Real_GlobalLock)(HGLOBAL a0)
= GlobalLock;

void(__stdcall* Real_GlobalMemoryStatus)(LPMEMORYSTATUS a0)
= GlobalMemoryStatus;

HGLOBAL(__stdcall* Real_GlobalReAlloc)(HGLOBAL a0,
    SIZE_T a1,
    UINT a2)
    = GlobalReAlloc;

SIZE_T(__stdcall* Real_GlobalSize)(HGLOBAL a0)
= GlobalSize;

BOOL(__stdcall* Real_GlobalUnWire)(HGLOBAL a0)
= GlobalUnWire;

void(__stdcall* Real_GlobalUnfix)(HGLOBAL a0)
= GlobalUnfix;

BOOL(__stdcall* Real_GlobalUnlock)(HGLOBAL a0)
= GlobalUnlock;

LPVOID(__stdcall* Real_GlobalWire)(HGLOBAL a0)
= GlobalWire;

BOOL(__stdcall* Real_GrayStringA)(HDC a0,
    HBRUSH a1,
    GRAYSTRINGPROC a2,
    LPARAM a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
    = GrayStringA;

BOOL(__stdcall* Real_GrayStringW)(HDC a0,
    HBRUSH a1,
    GRAYSTRINGPROC a2,
    LPARAM a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
    = GrayStringW;

BOOL(__stdcall* Real_HeapLock)(HANDLE a0)
= HeapLock;

BOOL(__stdcall* Real_HeapUnlock)(HANDLE a0)
= HeapUnlock;

BOOL(__stdcall* Real_HideCaret)(HWND a0)
= HideCaret;

BOOL(__stdcall* Real_HiliteMenuItem)(HWND a0,
    HMENU a1,
    UINT a2,
    UINT a3)
    = HiliteMenuItem;

#ifdef _WIN32_WINNT_WIN7
HRESULT(__stdcall* Real_IIDFromString)(LPCOLESTR a0,
    LPGUID a1)
    = IIDFromString;
#else
HRESULT(__stdcall* Real_IIDFromString)(LPOLESTR a0,
    LPGUID a1)
    = IIDFromString;
#endif

BOOL(__stdcall* Real_ImpersonateDdeClientWindow)(HWND a0,
    HWND a1)
    = ImpersonateDdeClientWindow;

BOOL(__stdcall* Real_InSendMessage)(void)
= InSendMessage;

BOOL(__stdcall* Real_InflateRect)(LPRECT a0,
    int a1,
    int a2)
    = InflateRect;

BOOL(__stdcall* Real_InitAtomTable)(DWORD a0)
= InitAtomTable;

BOOL(__stdcall* Real_InsertMenuA)(HMENU a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    LPCSTR a4)
    = InsertMenuA;

BOOL(__stdcall* Real_InsertMenuW)(HMENU a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    LPCWSTR a4)
    = InsertMenuW;

BOOL(__stdcall* Real_InsertMenuItemA)(HMENU a0,
    UINT a1,
    BOOL a2,
    LPCMENUITEMINFOA a3)
    = InsertMenuItemA;

BOOL(__stdcall* Real_InsertMenuItemW)(HMENU a0,
    UINT a1,
    BOOL a2,
    LPCMENUITEMINFOW a3)
    = InsertMenuItemW;

int(__stdcall* Real_IntersectClipRect)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4)
    = IntersectClipRect;

BOOL(__stdcall* Real_IntersectRect)(LPRECT a0,
    CONST RECT* a1,
    CONST RECT* a2)
    = IntersectRect;

BOOL(__stdcall* Real_InvalidateRect)(HWND a0,
    CONST RECT* a1,
    BOOL a2)
    = InvalidateRect;

BOOL(__stdcall* Real_InvalidateRgn)(HWND a0,
    HRGN a1,
    BOOL a2)
    = InvalidateRgn;

BOOL(__stdcall* Real_InvertRect)(HDC a0,
    CONST RECT* a1)
    = InvertRect;

BOOL(__stdcall* Real_InvertRgn)(HDC a0,
    HRGN a1)
    = InvertRgn;

BOOL(__stdcall* Real_IsAccelerator)(HACCEL a0,
    int a1,
    LPMSG a2,
    WORD* a3)
    = IsAccelerator;

BOOL(__stdcall* Real_IsBadCodePtr)(FARPROC a0)
= IsBadCodePtr;

BOOL(__stdcall* Real_IsBadHugeReadPtr)(CONST void* a0,
    UINT_PTR a1)
    = IsBadHugeReadPtr;

BOOL(__stdcall* Real_IsBadHugeWritePtr)(LPVOID a0,
    UINT_PTR a1)
    = IsBadHugeWritePtr;

BOOL(__stdcall* Real_IsBadReadPtr)(CONST void* a0,
    UINT_PTR a1)
    = IsBadReadPtr;

BOOL(__stdcall* Real_IsBadStringPtrA)(LPCSTR a0,
    UINT_PTR a1)
    = IsBadStringPtrA;

BOOL(__stdcall* Real_IsBadStringPtrW)(LPCWSTR a0,
    UINT_PTR a1)
    = IsBadStringPtrW;

BOOL(__stdcall* Real_IsBadWritePtr)(LPVOID a0,
    UINT_PTR a1)
    = IsBadWritePtr;

BOOL(__stdcall* Real_IsCharAlphaA)(CHAR a0)
= IsCharAlphaA;

BOOL(__stdcall* Real_IsCharAlphaNumericA)(CHAR a0)
= IsCharAlphaNumericA;

BOOL(__stdcall* Real_IsCharAlphaNumericW)(WCHAR a0)
= IsCharAlphaNumericW;

BOOL(__stdcall* Real_IsCharAlphaW)(WCHAR a0)
= IsCharAlphaW;

BOOL(__stdcall* Real_IsCharLowerA)(CHAR a0)
= IsCharLowerA;

BOOL(__stdcall* Real_IsCharLowerW)(WCHAR a0)
= IsCharLowerW;

BOOL(__stdcall* Real_IsCharUpperA)(CHAR a0)
= IsCharUpperA;

BOOL(__stdcall* Real_IsCharUpperW)(WCHAR a0)
= IsCharUpperW;

BOOL(__stdcall* Real_IsChild)(HWND a0,
    HWND a1)
    = IsChild;

BOOL(__stdcall* Real_IsClipboardFormatAvailable)(UINT a0)
= IsClipboardFormatAvailable;

BOOL(__stdcall* Real_IsDBCSLeadByte)(BYTE a0)
= IsDBCSLeadByte;

BOOL(__stdcall* Real_IsDBCSLeadByteEx)(UINT a0,
    BYTE a1)
    = IsDBCSLeadByteEx;

BOOL(__stdcall* Real_IsDebuggerPresent)(void)
= IsDebuggerPresent;

BOOL(__stdcall* Real_IsDialogMessageA)(HWND a0,
    LPMSG a1)
    = IsDialogMessageA;

BOOL(__stdcall* Real_IsDialogMessageW)(HWND a0,
    LPMSG a1)
    = IsDialogMessageW;

UINT(__stdcall* Real_IsDlgButtonChecked)(HWND a0,
    int a1)
    = IsDlgButtonChecked;

BOOL(__stdcall* Real_IsIconic)(HWND a0)
= IsIconic;

BOOL(__stdcall* Real_IsMenu)(HMENU a0)
= IsMenu;

#if !defined(DETOURS_ARM)
BOOL(__stdcall* Real_IsProcessorFeaturePresent)(DWORD a0)
= IsProcessorFeaturePresent;
#endif // !DETOURS_ARM

BOOL(__stdcall* Real_IsRectEmpty)(CONST RECT* a0)
= IsRectEmpty;

BOOL(__stdcall* Real_IsValidCodePage)(UINT a0)
= IsValidCodePage;

BOOL(__stdcall* Real_IsValidLocale)(LCID a0,
    DWORD a1)
    = IsValidLocale;

BOOL(__stdcall* Real_IsWindow)(HWND a0)
= IsWindow;

BOOL(__stdcall* Real_IsWindowEnabled)(HWND a0)
= IsWindowEnabled;

BOOL(__stdcall* Real_IsWindowUnicode)(HWND a0)
= IsWindowUnicode;

BOOL(__stdcall* Real_IsWindowVisible)(HWND a0)
= IsWindowVisible;

BOOL(__stdcall* Real_IsZoomed)(HWND a0)
= IsZoomed;

BOOL(__stdcall* Real_KillTimer)(HWND a0,
    UINT_PTR a1)
    = KillTimer;

BOOL(__stdcall* Real_LPtoDP)(HDC a0,
    POINT* a1,
    int a2)
    = LPtoDP;

BOOL(__stdcall* Real_LineDDA)(int a0,
    int a1,
    int a2,
    int a3,
    LINEDDAPROC a4,
    LPARAM a5)
    = LineDDA;

BOOL(__stdcall* Real_LineTo)(HDC a0,
    int a1,
    int a2)
    = LineTo;

HACCEL(__stdcall* Real_LoadAcceleratorsA)(HINSTANCE a0,
    LPCSTR a1)
    = LoadAcceleratorsA;

HACCEL(__stdcall* Real_LoadAcceleratorsW)(HINSTANCE a0,
    LPCWSTR a1)
    = LoadAcceleratorsW;

HBITMAP(__stdcall* Real_LoadBitmapA)(HINSTANCE a0,
    LPCSTR a1)
    = LoadBitmapA;

HBITMAP(__stdcall* Real_LoadBitmapW)(HINSTANCE a0,
    LPCWSTR a1)
    = LoadBitmapW;

HCURSOR(__stdcall* Real_LoadCursorA)(HINSTANCE a0,
    LPCSTR a1)
    = LoadCursorA;

HCURSOR(__stdcall* Real_LoadCursorFromFileA)(LPCSTR a0)
= LoadCursorFromFileA;

HCURSOR(__stdcall* Real_LoadCursorFromFileW)(LPCWSTR a0)
= LoadCursorFromFileW;

HCURSOR(__stdcall* Real_LoadCursorW)(HINSTANCE a0,
    LPCWSTR a1)
    = LoadCursorW;

HICON(__stdcall* Real_LoadIconA)(HINSTANCE a0,
    LPCSTR a1)
    = LoadIconA;

HICON(__stdcall* Real_LoadIconW)(HINSTANCE a0,
    LPCWSTR a1)
    = LoadIconW;

HANDLE(__stdcall* Real_LoadImageA)(HINSTANCE a0,
    LPCSTR a1,
    UINT a2,
    int a3,
    int a4,
    UINT a5)
    = LoadImageA;

HANDLE(__stdcall* Real_LoadImageW)(HINSTANCE a0,
    LPCWSTR a1,
    UINT a2,
    int a3,
    int a4,
    UINT a5)
    = LoadImageW;

HKL(__stdcall* Real_LoadKeyboardLayoutA)(LPCSTR a0,
    UINT a1)
    = LoadKeyboardLayoutA;

HKL(__stdcall* Real_LoadKeyboardLayoutW)(LPCWSTR a0,
    UINT a1)
    = LoadKeyboardLayoutW;

HMODULE(__stdcall* Real_LoadLibraryA)(LPCSTR a0)
= LoadLibraryA;

HMODULE(__stdcall* Real_LoadLibraryExA)(LPCSTR a0,
    HANDLE a1,
    DWORD a2)
    = LoadLibraryExA;

HMODULE(__stdcall* Real_LoadLibraryExW)(LPCWSTR a0,
    HANDLE a1,
    DWORD a2)
    = LoadLibraryExW;

HMODULE(__stdcall* Real_LoadLibraryW)(LPCWSTR a0)
= LoadLibraryW;

HMENU(__stdcall* Real_LoadMenuA)(HINSTANCE a0,
    LPCSTR a1)
    = LoadMenuA;

HMENU(__stdcall* Real_LoadMenuIndirectA)(CONST MENUTEMPLATEA* a0)
= LoadMenuIndirectA;

HMENU(__stdcall* Real_LoadMenuIndirectW)(CONST MENUTEMPLATEW* a0)
= LoadMenuIndirectW;

HMENU(__stdcall* Real_LoadMenuW)(HINSTANCE a0,
    LPCWSTR a1)
    = LoadMenuW;

DWORD(__stdcall* Real_LoadModule)(LPCSTR a0,
    LPVOID a1)
    = LoadModule;

HGLOBAL(__stdcall* Real_LoadResource)(HMODULE a0,
    HRSRC a1)
    = LoadResource;

int(__stdcall* Real_LoadStringA)(HINSTANCE a0,
    UINT a1,
    LPSTR a2,
    int a3)
    = LoadStringA;

int(__stdcall* Real_LoadStringW)(HINSTANCE a0,
    UINT a1,
    LPWSTR a2,
    int a3)
    = LoadStringW;

#if _MSC_VER < 1300
HLOCAL(__stdcall* Real_LocalAlloc)(UINT a0,
    UINT a1)
    = LocalAlloc;
#else
HLOCAL(__stdcall* Real_LocalAlloc)(UINT a0,
    SIZE_T a1)
    = LocalAlloc;
#endif

#if _MSC_VER < 1300
UINT(__stdcall* Real_LocalCompact)(UINT a0)
= LocalCompact;
#else
SIZE_T(__stdcall* Real_LocalCompact)(UINT a0)
= LocalCompact;
#endif

BOOL(__stdcall* Real_LocalFileTimeToFileTime)(CONST FILETIME* a0,
    LPFILETIME a1)
    = LocalFileTimeToFileTime;

UINT(__stdcall* Real_LocalFlags)(HLOCAL a0)
= LocalFlags;

HLOCAL(__stdcall* Real_LocalFree)(HLOCAL a0)
= LocalFree;

HLOCAL(__stdcall* Real_LocalHandle)(LPCVOID a0)
= LocalHandle;

LPVOID(__stdcall* Real_LocalLock)(HLOCAL a0)
= LocalLock;

#if _MSC_VER < 1300
HLOCAL(__stdcall* Real_LocalReAlloc)(HLOCAL a0,
    UINT a1,
    UINT a2)
    = LocalReAlloc;
#else
HLOCAL(__stdcall* Real_LocalReAlloc)(HLOCAL a0,
    SIZE_T a1,
    UINT a2)
    = LocalReAlloc;
#endif

#if _MSC_VER < 1300
UINT(__stdcall* Real_LocalShrink)(HLOCAL a0,
    UINT a1)
    = LocalShrink;
#else
SIZE_T(__stdcall* Real_LocalShrink)(HLOCAL a0,
    UINT a1)
    = LocalShrink;
#endif

#if _MSC_VER < 1300
UINT(__stdcall* Real_LocalSize)(HLOCAL a0)
= LocalSize;
#else
SIZE_T(__stdcall* Real_LocalSize)(HLOCAL a0)
= LocalSize;
#endif

BOOL(__stdcall* Real_LocalUnlock)(HLOCAL a0)
= LocalUnlock;

BOOL(__stdcall* Real_LockFile)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4)
    = LockFile;

BOOL(__stdcall* Real_LockFileEx)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    LPOVERLAPPED a5)
    = LockFileEx;

LPVOID(__stdcall* Real_LockResource)(HGLOBAL a0)
= LockResource;

BOOL(__stdcall* Real_LockWindowUpdate)(HWND a0)
= LockWindowUpdate;

int(__stdcall* Real_LookupIconIdFromDirectory)(PBYTE a0,
    BOOL a1)
    = LookupIconIdFromDirectory;

int(__stdcall* Real_LookupIconIdFromDirectoryEx)(PBYTE a0,
    BOOL a1,
    int a2,
    int a3,
    UINT a4)
    = LookupIconIdFromDirectoryEx;

BOOL(__stdcall* Real_MapDialogRect)(HWND a0,
    LPRECT a1)
    = MapDialogRect;

LPVOID(__stdcall* Real_MapViewOfFile)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    SIZE_T a4)
    = MapViewOfFile;

LPVOID(__stdcall* Real_MapViewOfFileEx)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    SIZE_T a4,
    LPVOID a5)
    = MapViewOfFileEx;

UINT(__stdcall* Real_MapVirtualKeyA)(UINT a0,
    UINT a1)
    = MapVirtualKeyA;

UINT(__stdcall* Real_MapVirtualKeyExA)(UINT a0,
    UINT a1,
    HKL a2)
    = MapVirtualKeyExA;

UINT(__stdcall* Real_MapVirtualKeyExW)(UINT a0,
    UINT a1,
    HKL a2)
    = MapVirtualKeyExW;

UINT(__stdcall* Real_MapVirtualKeyW)(UINT a0,
    UINT a1)
    = MapVirtualKeyW;

int(__stdcall* Real_MapWindowPoints)(HWND a0,
    HWND a1,
    POINT* a2,
    UINT a3)
    = MapWindowPoints;

BOOL(__stdcall* Real_MaskBlt)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    HDC a5,
    int a6,
    int a7,
    HBITMAP a8,
    int a9,
    int a10,
    DWORD a11)
    = MaskBlt;

int(__stdcall* Real_MenuItemFromPoint)(HWND a0,
    HMENU a1,
    POINT a2)
    = MenuItemFromPoint;

BOOL(__stdcall* Real_MessageBeep)(UINT a0)
= MessageBeep;

int(__stdcall* Real_MessageBoxA)(HWND a0,
    LPCSTR a1,
    LPCSTR a2,
    UINT a3)
    = MessageBoxA;

int(__stdcall* Real_MessageBoxExA)(HWND a0,
    LPCSTR a1,
    LPCSTR a2,
    UINT a3,
    WORD a4)
    = MessageBoxExA;

int(__stdcall* Real_MessageBoxExW)(HWND a0,
    LPCWSTR a1,
    LPCWSTR a2,
    UINT a3,
    WORD a4)
    = MessageBoxExW;

#if _MSC_VER < 1300
int(__stdcall* Real_MessageBoxIndirectA)(MSGBOXPARAMSA* a0)
= MessageBoxIndirectA;
#else
int(__stdcall* Real_MessageBoxIndirectA)(CONST MSGBOXPARAMSA* a0)
= MessageBoxIndirectA;
#endif

#if _MSC_VER < 1300
int(__stdcall* Real_MessageBoxIndirectW)(MSGBOXPARAMSW* a0)
= MessageBoxIndirectW;
#else
int(__stdcall* Real_MessageBoxIndirectW)(CONST MSGBOXPARAMSW* a0)
= MessageBoxIndirectW;
#endif

int(__stdcall* Real_MessageBoxW)(HWND a0,
    LPCWSTR a1,
    LPCWSTR a2,
    UINT a3)
    = MessageBoxW;

HRESULT(__stdcall* Real_MkParseDisplayName)(IBindCtx* a0,
    LPCOLESTR a1,
    ULONG* a2,
    IMoniker** a3)
    = MkParseDisplayName;

BOOL(__stdcall* Real_ModifyMenuA)(HMENU a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    LPCSTR a4)
    = ModifyMenuA;

BOOL(__stdcall* Real_ModifyMenuW)(HMENU a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    LPCWSTR a4)
    = ModifyMenuW;

BOOL(__stdcall* Real_ModifyWorldTransform)(HDC a0,
    CONST XFORM* a1,
    DWORD a2)
    = ModifyWorldTransform;

HRESULT(__stdcall* Real_MonikerCommonPrefixWith)(IMoniker* a0,
    IMoniker* a1,
    IMoniker** a2)
    = MonikerCommonPrefixWith;

HRESULT(__stdcall* Real_MonikerRelativePathTo)(IMoniker* a0,
    IMoniker* a1,
    IMoniker** a2,
    BOOL a3)
    = MonikerRelativePathTo;

BOOL(__stdcall* Real_MoveFileA)(LPCSTR a0,
    LPCSTR a1)
    = MoveFileA;

BOOL(__stdcall* Real_MoveFileExA)(LPCSTR a0,
    LPCSTR a1,
    DWORD a2)
    = MoveFileExA;

BOOL(__stdcall* Real_MoveFileExW)(LPCWSTR a0,
    LPCWSTR a1,
    DWORD a2)
    = MoveFileExW;

BOOL(__stdcall* Real_MoveFileW)(LPCWSTR a0,
    LPCWSTR a1)
    = MoveFileW;

BOOL(__stdcall* Real_MoveToEx)(HDC a0,
    int a1,
    int a2,
    POINT* a3)
    = MoveToEx;

BOOL(__stdcall* Real_MoveWindow)(HWND a0,
    int a1,
    int a2,
    int a3,
    int a4,
    BOOL a5)
    = MoveWindow;

#if _MSC_VER < 1300
DWORD(__stdcall* Real_MsgWaitForMultipleObjects)(DWORD a0,
    HANDLE* a1,
    BOOL a2,
    DWORD a3,
    DWORD a4)
    = MsgWaitForMultipleObjects;
#else
DWORD(__stdcall* Real_MsgWaitForMultipleObjects)(DWORD a0,
    CONST HANDLE* a1,
    BOOL a2,
    DWORD a3,
    DWORD a4)
    = MsgWaitForMultipleObjects;
#endif

#if _MSC_VER < 1300
DWORD(__stdcall* Real_MsgWaitForMultipleObjectsEx)(DWORD a0,
    HANDLE* a1,
    DWORD a2,
    DWORD a3,
    DWORD a4)
    = MsgWaitForMultipleObjectsEx;
#else
DWORD(__stdcall* Real_MsgWaitForMultipleObjectsEx)(DWORD a0,
    CONST HANDLE* a1,
    DWORD a2,
    DWORD a3,
    DWORD a4)
    = MsgWaitForMultipleObjectsEx;
#endif

int(__stdcall* Real_MulDiv)(int a0,
    int a1,
    int a2)
    = MulDiv;

DWORD(__stdcall* Real_OemKeyScan)(WORD a0)
= OemKeyScan;

BOOL(__stdcall* Real_OemToCharA)(LPCSTR a0,
    LPSTR a1)
    = OemToCharA;

BOOL(__stdcall* Real_OemToCharBuffA)(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
    = OemToCharBuffA;

BOOL(__stdcall* Real_OemToCharBuffW)(LPCSTR a0,
    LPWSTR a1,
    DWORD a2)
    = OemToCharBuffW;

BOOL(__stdcall* Real_OemToCharW)(LPCSTR a0,
    LPWSTR a1)
    = OemToCharW;

int(__stdcall* Real_OffsetClipRgn)(HDC a0,
    int a1,
    int a2)
    = OffsetClipRgn;

BOOL(__stdcall* Real_OffsetRect)(LPRECT a0,
    int a1,
    int a2)
    = OffsetRect;

int(__stdcall* Real_OffsetRgn)(HRGN a0,
    int a1,
    int a2)
    = OffsetRgn;

BOOL(__stdcall* Real_OffsetViewportOrgEx)(HDC a0,
    int a1,
    int a2,
    POINT* a3)
    = OffsetViewportOrgEx;

BOOL(__stdcall* Real_OffsetWindowOrgEx)(HDC a0,
    int a1,
    int a2,
    POINT* a3)
    = OffsetWindowOrgEx;

DWORD(__stdcall* Real_OleBuildVersion)(void)
= OleBuildVersion;

HRESULT(__stdcall* Real_OleConvertIStorageToOLESTREAM)(IStorage* a0,
    LPOLESTREAM a1)
    = OleConvertIStorageToOLESTREAM;

HRESULT(__stdcall* Real_OleConvertIStorageToOLESTREAMEx)(IStorage* a0,
    CLIPFORMAT a1,
    LONG a2,
    LONG a3,
    DWORD a4,
    LPSTGMEDIUM a5,
    LPOLESTREAM a6)
    = OleConvertIStorageToOLESTREAMEx;

HRESULT(__stdcall* Real_OleConvertOLESTREAMToIStorage)(LPOLESTREAM a0,
    LPSTORAGE a1,
    CONST DVTARGETDEVICE* a2)
    = OleConvertOLESTREAMToIStorage;

HRESULT(__stdcall* Real_OleConvertOLESTREAMToIStorageEx)(LPOLESTREAM a0,
    LPSTORAGE a1,
    CLIPFORMAT* a2,
    LONG* a3,
    LONG* a4,
    DWORD* a5,
    LPSTGMEDIUM a6)
    = OleConvertOLESTREAMToIStorageEx;

HRESULT(__stdcall* Real_OleCreate)(CONST IID& a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
    = OleCreate;

HRESULT(__stdcall* Real_OleCreateDefaultHandler)(CONST IID& a0,
    LPUNKNOWN a1,
    CONST IID& a2,
    LPVOID* a3)
    = OleCreateDefaultHandler;

HRESULT(__stdcall* Real_OleCreateEmbeddingHelper)(CONST IID& a0,
    LPUNKNOWN a1,
    DWORD a2,
    LPCLASSFACTORY a3,
    CONST IID& a4,
    LPVOID* a5)
    = OleCreateEmbeddingHelper;

HRESULT(__stdcall* Real_OleCreateEx)(CONST IID& a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
    = OleCreateEx;

HRESULT(__stdcall* Real_OleCreateFromData)(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
    = OleCreateFromData;

HRESULT(__stdcall* Real_OleCreateFromDataEx)(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
    = OleCreateFromDataEx;

HRESULT(__stdcall* Real_OleCreateFromFile)(CONST IID& a0,
    LPCOLESTR a1,
    CONST IID& a2,
    DWORD a3,
    LPFORMATETC a4,
    LPOLECLIENTSITE a5,
    LPSTORAGE a6,
    LPVOID* a7)
    = OleCreateFromFile;

HRESULT(__stdcall* Real_OleCreateFromFileEx)(CONST IID& a0,
    LPCOLESTR a1,
    CONST IID& a2,
    DWORD a3,
    DWORD a4,
    ULONG a5,
    DWORD* a6,
    LPFORMATETC a7,
    IAdviseSink* a8,
    DWORD* a9,
    LPOLECLIENTSITE a10,
    LPSTORAGE a11,
    LPVOID* a12)
    = OleCreateFromFileEx;

HRESULT(__stdcall* Real_OleCreateLink)(IMoniker* a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
    = OleCreateLink;

HRESULT(__stdcall* Real_OleCreateLinkEx)(IMoniker* a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
    = OleCreateLinkEx;

HRESULT(__stdcall* Real_OleCreateLinkFromData)(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
    = OleCreateLinkFromData;

HRESULT(__stdcall* Real_OleCreateLinkFromDataEx)(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
    = OleCreateLinkFromDataEx;

HRESULT(__stdcall* Real_OleCreateLinkToFile)(LPCOLESTR a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
    = OleCreateLinkToFile;

HRESULT(__stdcall* Real_OleCreateLinkToFileEx)(LPCOLESTR a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
    = OleCreateLinkToFileEx;

HOLEMENU(__stdcall* Real_OleCreateMenuDescriptor)(HMENU a0,
    LPOLEMENUGROUPWIDTHS a1)
    = OleCreateMenuDescriptor;

HRESULT(__stdcall* Real_OleCreateStaticFromData)(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
    = OleCreateStaticFromData;

HRESULT(__stdcall* Real_OleDestroyMenuDescriptor)(HOLEMENU a0)
= OleDestroyMenuDescriptor;

HRESULT(__stdcall* Real_OleDoAutoConvert)(LPSTORAGE a0,
    LPGUID a1)
    = OleDoAutoConvert;

HRESULT(__stdcall* Real_OleDraw)(LPUNKNOWN a0,
    DWORD a1,
    HDC a2,
    LPCRECT a3)
    = OleDraw;

HANDLE(__stdcall* Real_OleDuplicateData)(HANDLE a0,
    CLIPFORMAT a1,
    UINT a2)
    = OleDuplicateData;

HRESULT(__stdcall* Real_OleFlushClipboard)(void)
= OleFlushClipboard;

HRESULT(__stdcall* Real_OleGetAutoConvert)(CONST IID& a0,
    LPGUID a1)
    = OleGetAutoConvert;

HRESULT(__stdcall* Real_OleGetClipboard)(IDataObject** a0)
= OleGetClipboard;

HGLOBAL(__stdcall* Real_OleGetIconOfClass)(CONST IID& a0,
    LPOLESTR a1,
    BOOL a2)
    = OleGetIconOfClass;

HGLOBAL(__stdcall* Real_OleGetIconOfFile)(LPOLESTR a0,
    BOOL a1)
    = OleGetIconOfFile;

HRESULT(__stdcall* Real_OleInitialize)(LPVOID a0)
= OleInitialize;

HRESULT(__stdcall* Real_OleIsCurrentClipboard)(IDataObject* a0)
= OleIsCurrentClipboard;

BOOL(__stdcall* Real_OleIsRunning)(IOleObject* a0)
= OleIsRunning;

HRESULT(__stdcall* Real_OleLoad)(LPSTORAGE a0,
    CONST IID& a1,
    LPOLECLIENTSITE a2,
    LPVOID* a3)
    = OleLoad;

HRESULT(__stdcall* Real_OleLoadFromStream)(LPSTREAM a0,
    CONST IID& a1,
    LPVOID* a2)
    = OleLoadFromStream;

HRESULT(__stdcall* Real_OleLockRunning)(LPUNKNOWN a0,
    BOOL a1,
    BOOL a2)
    = OleLockRunning;

HGLOBAL(__stdcall* Real_OleMetafilePictFromIconAndLabel)(HICON a0,
    LPOLESTR a1,
    LPOLESTR a2,
    UINT a3)
    = OleMetafilePictFromIconAndLabel;

HRESULT(__stdcall* Real_OleNoteObjectVisible)(LPUNKNOWN a0,
    BOOL a1)
    = OleNoteObjectVisible;

HRESULT(__stdcall* Real_OleQueryCreateFromData)(IDataObject* a0)
= OleQueryCreateFromData;

HRESULT(__stdcall* Real_OleQueryLinkFromData)(IDataObject* a0)
= OleQueryLinkFromData;

HRESULT(__stdcall* Real_OleRegEnumFormatEtc)(CONST IID& a0,
    DWORD a1,
    IEnumFORMATETC** a2)
    = OleRegEnumFormatEtc;

HRESULT(__stdcall* Real_OleRegEnumVerbs)(CONST IID& a0,
    IEnumOLEVERB** a1)
    = OleRegEnumVerbs;

HRESULT(__stdcall* Real_OleRegGetMiscStatus)(CONST IID& a0,
    DWORD a1,
    DWORD* a2)
    = OleRegGetMiscStatus;

HRESULT(__stdcall* Real_OleRegGetUserType)(CONST IID& a0,
    DWORD a1,
    LPOLESTR* a2)
    = OleRegGetUserType;

HRESULT(__stdcall* Real_OleRun)(LPUNKNOWN a0)
= OleRun;

HRESULT(__stdcall* Real_OleSave)(LPPERSISTSTORAGE a0,
    LPSTORAGE a1,
    BOOL a2)
    = OleSave;

HRESULT(__stdcall* Real_OleSaveToStream)(IPersistStream* a0,
    LPSTREAM a1)
    = OleSaveToStream;

HRESULT(__stdcall* Real_OleSetAutoConvert)(CONST IID& a0,
    CONST IID& a1)
    = OleSetAutoConvert;

HRESULT(__stdcall* Real_OleSetClipboard)(IDataObject* a0)
= OleSetClipboard;

HRESULT(__stdcall* Real_OleSetContainedObject)(LPUNKNOWN a0,
    BOOL a1)
    = OleSetContainedObject;

HRESULT(__stdcall* Real_OleSetMenuDescriptor)(HOLEMENU a0,
    HWND a1,
    HWND a2,
    LPOLEINPLACEFRAME a3,
    LPOLEINPLACEACTIVEOBJECT a4)
    = OleSetMenuDescriptor;

HRESULT(__stdcall* Real_OleTranslateAccelerator)(LPOLEINPLACEFRAME a0,
    LPOLEINPLACEFRAMEINFO a1,
    LPMSG a2)
    = OleTranslateAccelerator;

void(__stdcall* Real_OleUninitialize)(void)
= OleUninitialize;

BOOL(__stdcall* Real_OpenClipboard)(HWND a0)
= OpenClipboard;

#if _MSC_VER < 1300
HDESK(__stdcall* Real_OpenDesktopA)(LPSTR a0,
    DWORD a1,
    BOOL a2,
    ACCESS_MASK a3)
    = OpenDesktopA;
#else
HDESK(__stdcall* Real_OpenDesktopA)(LPCSTR a0,
    DWORD a1,
    BOOL a2,
    ACCESS_MASK a3)
    = OpenDesktopA;
#endif

#if _MSC_VER < 1300
HDESK(__stdcall* Real_OpenDesktopW)(LPWSTR a0,
    DWORD a1,
    BOOL a2,
    ACCESS_MASK a3)
    = OpenDesktopW;
#else
HDESK(__stdcall* Real_OpenDesktopW)(LPCWSTR a0,
    DWORD a1,
    BOOL a2,
    ACCESS_MASK a3)
    = OpenDesktopW;
#endif

HANDLE(__stdcall* Real_OpenEventA)(DWORD a0,
    BOOL a1,
    LPCSTR a2)
    = OpenEventA;

HANDLE(__stdcall* Real_OpenEventW)(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
    = OpenEventW;

HFILE(__stdcall* Real_OpenFile)(LPCSTR a0,
    LPOFSTRUCT a1,
    UINT a2)
    = OpenFile;

HANDLE(__stdcall* Real_OpenFileMappingA)(DWORD a0,
    BOOL a1,
    LPCSTR a2)
    = OpenFileMappingA;

HANDLE(__stdcall* Real_OpenFileMappingW)(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
    = OpenFileMappingW;

BOOL(__stdcall* Real_OpenIcon)(HWND a0)
= OpenIcon;

HDESK(__stdcall* Real_OpenInputDesktop)(DWORD a0,
    BOOL a1,
    ACCESS_MASK a2)
    = OpenInputDesktop;

HANDLE(__stdcall* Real_OpenMutexA)(DWORD a0,
    BOOL a1,
    LPCSTR a2)
    = OpenMutexA;

HANDLE(__stdcall* Real_OpenMutexW)(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
    = OpenMutexW;

HANDLE(__stdcall* Real_OpenProcess)(DWORD a0,
    BOOL a1,
    DWORD pid)
    = OpenProcess;

BOOL(__stdcall* Real_OpenProcessToken)(__in   HANDLE ProcessHandle,
    __in   DWORD DesiredAccess,
    __out  PHANDLE TokenHandle
    )
    = OpenProcessToken;

HANDLE(__stdcall* Real_OpenSemaphoreA)(DWORD a0,
    BOOL a1,
    LPCSTR a2)
    = OpenSemaphoreA;

HANDLE(__stdcall* Real_OpenSemaphoreW)(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
    = OpenSemaphoreW;

HANDLE(__stdcall* Real_OpenWaitableTimerA)(DWORD a0,
    BOOL a1,
    LPCSTR a2)
    = OpenWaitableTimerA;

HANDLE(__stdcall* Real_OpenWaitableTimerW)(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
    = OpenWaitableTimerW;

#if _MSC_VER < 1300
HWINSTA(__stdcall* Real_OpenWindowStationA)(LPSTR a0,
    BOOL a1,
    ACCESS_MASK a2)
    = OpenWindowStationA;
#else
HWINSTA(__stdcall* Real_OpenWindowStationA)(LPCSTR a0,
    BOOL a1,
    ACCESS_MASK a2)
    = OpenWindowStationA;
#endif

#if _MSC_VER < 1300
HWINSTA(__stdcall* Real_OpenWindowStationW)(LPWSTR a0,
    BOOL a1,
    ACCESS_MASK a2)
    = OpenWindowStationW;
#else
HWINSTA(__stdcall* Real_OpenWindowStationW)(LPCWSTR a0,
    BOOL a1,
    ACCESS_MASK a2)
    = OpenWindowStationW;
#endif

void(__stdcall* Real_OutputDebugStringA)(LPCSTR a0)
= OutputDebugStringA;

void(__stdcall* Real_OutputDebugStringW)(LPCWSTR a0)
= OutputDebugStringW;

LPARAM(__stdcall* Real_PackDDElParam)(UINT a0,
    UINT_PTR a1,
    UINT_PTR a2)
    = PackDDElParam;

BOOL(__stdcall* Real_PaintDesktop)(HDC a0)
= PaintDesktop;

BOOL(__stdcall* Real_PaintRgn)(HDC a0,
    HRGN a1)
    = PaintRgn;

BOOL(__stdcall* Real_PatBlt)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    DWORD a5)
    = PatBlt;

HRGN(__stdcall* Real_PathToRegion)(HDC a0)
= PathToRegion;

BOOL(__stdcall* Real_PeekConsoleInputA)(HANDLE a0,
    PINPUT_RECORD a1,
    DWORD a2,
    LPDWORD a3)
    = PeekConsoleInputA;

BOOL(__stdcall* Real_PeekConsoleInputW)(HANDLE a0,
    PINPUT_RECORD a1,
    DWORD a2,
    LPDWORD a3)
    = PeekConsoleInputW;

BOOL(__stdcall* Real_PeekMessageA)(LPMSG a0,
    HWND a1,
    UINT a2,
    UINT a3,
    UINT a4)
    = PeekMessageA;

BOOL(__stdcall* Real_PeekMessageW)(LPMSG a0,
    HWND a1,
    UINT a2,
    UINT a3,
    UINT a4)
    = PeekMessageW;

BOOL(__stdcall* Real_PeekNamedPipe)(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPDWORD a5)
    = PeekNamedPipe;

BOOL(__stdcall* Real_Pie)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
    = Pie;

BOOL(__stdcall* Real_PlayEnhMetaFile)(HDC a0,
    HENHMETAFILE a1,
    CONST RECT* a2)
    = PlayEnhMetaFile;

BOOL(__stdcall* Real_PlayEnhMetaFileRecord)(HDC a0,
    LPHANDLETABLE a1,
    CONST ENHMETARECORD* a2,
    UINT a3)
    = PlayEnhMetaFileRecord;

BOOL(__stdcall* Real_PlayMetaFile)(HDC a0,
    HMETAFILE a1)
    = PlayMetaFile;

BOOL(__stdcall* Real_PlayMetaFileRecord)(HDC a0,
    LPHANDLETABLE a1,
    LPMETARECORD a2,
    UINT a3)
    = PlayMetaFileRecord;

BOOL(__stdcall* Real_PlgBlt)(HDC a0,
    CONST POINT* a1,
    HDC a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HBITMAP a7,
    int a8,
    int a9)
    = PlgBlt;

BOOL(__stdcall* Real_PolyBezier)(HDC a0,
    CONST POINT* a1,
    DWORD a2)
    = PolyBezier;

BOOL(__stdcall* Real_PolyBezierTo)(HDC a0,
    CONST POINT* a1,
    DWORD a2)
    = PolyBezierTo;

BOOL(__stdcall* Real_PolyDraw)(HDC a0,
    CONST POINT* a1,
    CONST BYTE* a2,
    int a3)
    = PolyDraw;

BOOL(__stdcall* Real_PolyPolygon)(HDC a0,
    CONST POINT* a1,
    CONST INT* a2,
    int a3)
    = PolyPolygon;

BOOL(__stdcall* Real_PolyPolyline)(HDC a0,
    CONST POINT* a1,
    CONST DWORD* a2,
    DWORD a3)
    = PolyPolyline;

BOOL(__stdcall* Real_PolyTextOutA)(HDC a0,
    CONST POLYTEXTA* a1,
    int a2)
    = PolyTextOutA;

BOOL(__stdcall* Real_PolyTextOutW)(HDC a0,
    CONST POLYTEXTW* a1,
    int a2)
    = PolyTextOutW;

BOOL(__stdcall* Real_Polygon)(HDC a0,
    CONST POINT* a1,
    int a2)
    = Polygon;

BOOL(__stdcall* Real_Polyline)(HDC a0,
    CONST POINT* a1,
    int a2)
    = Polyline;

BOOL(__stdcall* Real_PolylineTo)(HDC a0,
    CONST POINT* a1,
    DWORD a2)
    = PolylineTo;

BOOL(__stdcall* Real_PostMessageA)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = PostMessageA;

BOOL(__stdcall* Real_PostMessageW)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = PostMessageW;

BOOL(__stdcall* Real_PostQueuedCompletionStatus)(HANDLE a0,
    DWORD a1,
    ULONG_PTR a2,
    LPOVERLAPPED a3)
    = PostQueuedCompletionStatus;

void(__stdcall* Real_PostQuitMessage)(int a0)
= PostQuitMessage;

BOOL(__stdcall* Real_PostThreadMessageA)(DWORD a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = PostThreadMessageA;

BOOL(__stdcall* Real_PostThreadMessageW)(DWORD a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = PostThreadMessageW;

DWORD(__stdcall* Real_PrepareTape)(HANDLE a0,
    DWORD a1,
    BOOL a2)
    = PrepareTape;

HRESULT(__stdcall* Real_ProgIDFromCLSID)(CONST IID& a0,
    LPOLESTR* a1)
    = ProgIDFromCLSID;

HRESULT(__stdcall* Real_PropVariantClear)(PROPVARIANT* a0)
= PropVariantClear;

HRESULT(__stdcall* Real_PropVariantCopy)(PROPVARIANT* a0,
    CONST PROPVARIANT* a1)
    = PropVariantCopy;

BOOL(__stdcall* Real_PtInRect)(CONST RECT* a0,
    POINT a1)
    = PtInRect;

BOOL(__stdcall* Real_PtInRegion)(HRGN a0,
    int a1,
    int a2)
    = PtInRegion;

BOOL(__stdcall* Real_PtVisible)(HDC a0,
    int a1,
    int a2)
    = PtVisible;

BOOL(__stdcall* Real_PulseEvent)(HANDLE a0)
= PulseEvent;

BOOL(__stdcall* Real_PurgeComm)(HANDLE a0,
    DWORD a1)
    = PurgeComm;

DWORD(__stdcall* Real_QueryDosDeviceA)(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
    = QueryDosDeviceA;

DWORD(__stdcall* Real_QueryDosDeviceW)(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
    = QueryDosDeviceW;

BOOL(__stdcall* Real_QueryPerformanceCounter)(LARGE_INTEGER* a0)
= QueryPerformanceCounter;

BOOL(__stdcall* Real_QueryPerformanceFrequency)(LARGE_INTEGER* a0)
= QueryPerformanceFrequency;

DWORD(__stdcall* Real_QueueUserAPC)(PAPCFUNC a0,
    HANDLE a1,
    ULONG_PTR a2)
    = QueueUserAPC;

void(__stdcall* Real_RaiseException)(DWORD a0,
    DWORD a1,
    DWORD a2,
    CONST ULONG_PTR* a3)
    = RaiseException;

HRESULT(__stdcall* Real_ReadClassStg)(LPSTORAGE a0,
    CLSID* a1)
    = ReadClassStg;

HRESULT(__stdcall* Real_ReadClassStm)(LPSTREAM a0,
    CLSID* a1)
    = ReadClassStm;

BOOL(__stdcall* Real_ReadConsoleA)(
    HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPDWORD a3,
#ifdef ENABLE_INSERT_MODE
    PCONSOLE_READCONSOLE_CONTROL a4
#else
    LPVOID a4
#endif
    )
    = ReadConsoleA;

BOOL(__stdcall* Real_ReadConsoleInputA)(HANDLE a0,
    PINPUT_RECORD a1,
    DWORD a2,
    LPDWORD a3)
    = ReadConsoleInputA;

BOOL(__stdcall* Real_ReadConsoleInputW)(HANDLE a0,
    PINPUT_RECORD a1,
    DWORD a2,
    LPDWORD a3)
    = ReadConsoleInputW;

BOOL(__stdcall* Real_ReadConsoleOutputA)(HANDLE a0,
    PCHAR_INFO a1,
    COORD a2,
    COORD a3,
    PSMALL_RECT a4)
    = ReadConsoleOutputA;

BOOL(__stdcall* Real_ReadConsoleOutputAttribute)(HANDLE a0,
    LPWORD a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
    = ReadConsoleOutputAttribute;

BOOL(__stdcall* Real_ReadConsoleOutputCharacterA)(HANDLE a0,
    LPSTR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
    = ReadConsoleOutputCharacterA;

BOOL(__stdcall* Real_ReadConsoleOutputCharacterW)(HANDLE a0,
    LPWSTR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
    = ReadConsoleOutputCharacterW;

BOOL(__stdcall* Real_ReadConsoleOutputW)(HANDLE a0,
    PCHAR_INFO a1,
    COORD a2,
    COORD a3,
    PSMALL_RECT a4)
    = ReadConsoleOutputW;

BOOL(__stdcall* Real_ReadConsoleW)(
    HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPDWORD a3,
#ifdef ENABLE_INSERT_MODE
    PCONSOLE_READCONSOLE_CONTROL a4
#else
    LPVOID a4
#endif
    )
    = ReadConsoleW;

BOOL(__stdcall* Real_ReadDirectoryChangesW)(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    BOOL a3,
    DWORD a4,
    LPDWORD a5,
    LPOVERLAPPED a6,
    LPOVERLAPPED_COMPLETION_ROUTINE a7)
    = ReadDirectoryChangesW;

BOOL(__stdcall* Real_ReadFile)(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPDWORD a3,
    LPOVERLAPPED a4)
    = ReadFile;

BOOL(__stdcall* Real_ReadFileEx)(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPOVERLAPPED a3,
    LPOVERLAPPED_COMPLETION_ROUTINE a4)
    = ReadFileEx;

HRESULT(__stdcall* Real_ReadFmtUserTypeStg)(LPSTORAGE a0,
    CLIPFORMAT* a1,
    LPOLESTR* a2)
    = ReadFmtUserTypeStg;

BOOL(__stdcall* Real_ReadProcessMemory)(HANDLE a0,
    LPCVOID a1,
    LPVOID a2,
    DWORD_PTR a3,
    PDWORD_PTR a4)
    = ReadProcessMemory;

UINT(__stdcall* Real_RealizePalette)(HDC a0)
= RealizePalette;

BOOL(__stdcall* Real_RectInRegion)(HRGN a0,
    CONST RECT* a1)
    = RectInRegion;

BOOL(__stdcall* Real_RectVisible)(HDC a0,
    CONST RECT* a1)
    = RectVisible;

BOOL(__stdcall* Real_Rectangle)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4)
    = Rectangle;

BOOL(__stdcall* Real_RedrawWindow)(HWND a0,
    CONST RECT* a1,
    HRGN a2,
    UINT a3)
    = RedrawWindow;

ATOM(__stdcall* Real_RegisterClassA)(CONST WNDCLASSA* a0)
= RegisterClassA;

ATOM(__stdcall* Real_RegisterClassExA)(CONST WNDCLASSEXA* a0)
= RegisterClassExA;

ATOM(__stdcall* Real_RegisterClassExW)(CONST WNDCLASSEXW* a0)
= RegisterClassExW;

ATOM(__stdcall* Real_RegisterClassW)(CONST WNDCLASSW* a0)
= RegisterClassW;

UINT(__stdcall* Real_RegisterClipboardFormatA)(LPCSTR a0)
= RegisterClipboardFormatA;

UINT(__stdcall* Real_RegisterClipboardFormatW)(LPCWSTR a0)
= RegisterClipboardFormatW;

HRESULT(__stdcall* Real_RegisterDragDrop)(HWND a0,
    IDropTarget* a1)
    = RegisterDragDrop;

BOOL(__stdcall* Real_RegisterHotKey)(HWND a0,
    int a1,
    UINT a2,
    UINT a3)
    = RegisterHotKey;

UINT(__stdcall* Real_RegisterWindowMessageA)(LPCSTR a0)
= RegisterWindowMessageA;

UINT(__stdcall* Real_RegisterWindowMessageW)(LPCWSTR a0)
= RegisterWindowMessageW;

BOOL(__stdcall* Real_ReleaseCapture)(void)
= ReleaseCapture;

int(__stdcall* Real_ReleaseDC)(HWND a0,
    HDC a1)
    = ReleaseDC;

BOOL(__stdcall* Real_ReleaseMutex)(HANDLE a0)
= ReleaseMutex;

BOOL(__stdcall* Real_ReleaseSemaphore)(HANDLE a0,
    LONG a1,
    LPLONG a2)
    = ReleaseSemaphore;

void(__stdcall* Real_ReleaseStgMedium)(LPSTGMEDIUM a0)
= ReleaseStgMedium;

BOOL(__stdcall* Real_RemoveDirectoryA)(LPCSTR a0)
= RemoveDirectoryA;

BOOL(__stdcall* Real_RemoveDirectoryW)(LPCWSTR a0)
= RemoveDirectoryW;

BOOL(__stdcall* Real_RemoveFontResourceA)(LPCSTR a0)
= RemoveFontResourceA;

BOOL(__stdcall* Real_RemoveFontResourceW)(LPCWSTR a0)
= RemoveFontResourceW;

BOOL(__stdcall* Real_RemoveMenu)(HMENU a0,
    UINT a1,
    UINT a2)
    = RemoveMenu;

HANDLE(__stdcall* Real_RemovePropA)(HWND a0,
    LPCSTR a1)
    = RemovePropA;

HANDLE(__stdcall* Real_RemovePropW)(HWND a0,
    LPCWSTR a1)
    = RemovePropW;

BOOL(__stdcall* Real_ReplyMessage)(LRESULT a0)
= ReplyMessage;

HDC(__stdcall* Real_ResetDCA)(HDC a0,
    CONST DEVMODEA* a1)
    = ResetDCA;

HDC(__stdcall* Real_ResetDCW)(HDC a0,
    CONST DEVMODEW* a1)
    = ResetDCW;

BOOL(__stdcall* Real_ResetEvent)(HANDLE a0)
= ResetEvent;

BOOL(__stdcall* Real_ResizePalette)(HPALETTE a0,
    UINT a1)
    = ResizePalette;

BOOL(__stdcall* Real_RestoreDC)(HDC a0,
    int a1)
    = RestoreDC;

DWORD(__stdcall* Real_ResumeThread)(HANDLE a0)
= ResumeThread;

LPARAM(__stdcall* Real_ReuseDDElParam)(LPARAM a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    UINT_PTR a4)
    = ReuseDDElParam;

HRESULT(__stdcall* Real_RevokeDragDrop)(HWND a0)
= RevokeDragDrop;

BOOL(__stdcall* Real_RoundRect)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6)
    = RoundRect;

int(__stdcall* Real_SaveDC)(HDC a0)
= SaveDC;

BOOL(__stdcall* Real_ScaleViewportExtEx)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    SIZE* a5)
    = ScaleViewportExtEx;

BOOL(__stdcall* Real_ScaleWindowExtEx)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    SIZE* a5)
    = ScaleWindowExtEx;

BOOL(__stdcall* Real_ScreenToClient)(HWND a0,
    POINT* a1)
    = ScreenToClient;

BOOL(__stdcall* Real_ScrollConsoleScreenBufferA)(HANDLE a0,
    CONST SMALL_RECT* a1,
    CONST SMALL_RECT* a2,
    COORD a3,
    CONST CHAR_INFO* a4)
    = ScrollConsoleScreenBufferA;

BOOL(__stdcall* Real_ScrollConsoleScreenBufferW)(HANDLE a0,
    CONST SMALL_RECT* a1,
    CONST SMALL_RECT* a2,
    COORD a3,
    CONST CHAR_INFO* a4)
    = ScrollConsoleScreenBufferW;

BOOL(__stdcall* Real_ScrollDC)(HDC a0,
    int a1,
    int a2,
    CONST RECT* a3,
    CONST RECT* a4,
    HRGN a5,
    LPRECT a6)
    = ScrollDC;

BOOL(__stdcall* Real_ScrollWindow)(HWND a0,
    int a1,
    int a2,
    CONST RECT* a3,
    CONST RECT* a4)
    = ScrollWindow;

int(__stdcall* Real_ScrollWindowEx)(HWND a0,
    int a1,
    int a2,
    CONST RECT* a3,
    CONST RECT* a4,
    HRGN a5,
    LPRECT a6,
    UINT a7)
    = ScrollWindowEx;

DWORD(__stdcall* Real_SearchPathA)(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    DWORD a3,
    LPSTR a4,
    LPSTR* a5)
    = SearchPathA;

DWORD(__stdcall* Real_SearchPathW)(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    DWORD a3,
    LPWSTR a4,
    LPWSTR* a5)
    = SearchPathW;

BOOL(__stdcall* Real_SelectClipPath)(HDC a0,
    int a1)
    = SelectClipPath;

int(__stdcall* Real_SelectClipRgn)(HDC a0,
    HRGN a1)
    = SelectClipRgn;

HGDIOBJ(__stdcall* Real_SelectObject)(HDC a0,
    HGDIOBJ a1)
    = SelectObject;

HPALETTE(__stdcall* Real_SelectPalette)(HDC a0,
    HPALETTE a1,
    BOOL a2)
    = SelectPalette;

LRESULT(__stdcall* Real_SendDlgItemMessageA)(HWND a0,
    int a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
    = SendDlgItemMessageA;

LRESULT(__stdcall* Real_SendDlgItemMessageW)(HWND a0,
    int a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
    = SendDlgItemMessageW;

LRESULT(__stdcall* Real_SendMessageA)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = SendMessageA;

BOOL(__stdcall* Real_SendMessageCallbackA)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3,
    SENDASYNCPROC a4,
    ULONG_PTR a5)
    = SendMessageCallbackA;

BOOL(__stdcall* Real_SendMessageCallbackW)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3,
    SENDASYNCPROC a4,
    ULONG_PTR a5)
    = SendMessageCallbackW;

LRESULT(__stdcall* Real_SendMessageTimeoutA)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3,
    UINT a4,
    UINT a5,
    PULONG_PTR a6)
    = SendMessageTimeoutA;

LRESULT(__stdcall* Real_SendMessageTimeoutW)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3,
    UINT a4,
    UINT a5,
    PULONG_PTR a6)
    = SendMessageTimeoutW;

LRESULT(__stdcall* Real_SendMessageW)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = SendMessageW;

BOOL(__stdcall* Real_SendNotifyMessageA)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = SendNotifyMessageA;

BOOL(__stdcall* Real_SendNotifyMessageW)(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
    = SendNotifyMessageW;

int(__stdcall* Real_SetAbortProc)(HDC a0,
    ABORTPROC a1)
    = SetAbortProc;

HWND(__stdcall* Real_SetActiveWindow)(HWND a0)
= SetActiveWindow;

int(__stdcall* Real_SetArcDirection)(HDC a0,
    int a1)
    = SetArcDirection;

LONG(__stdcall* Real_SetBitmapBits)(HBITMAP a0,
    DWORD a1,
    CONST void* a2)
    = SetBitmapBits;

BOOL(__stdcall* Real_SetBitmapDimensionEx)(HBITMAP a0,
    int a1,
    int a2,
    SIZE* a3)
    = SetBitmapDimensionEx;

COLORREF(__stdcall* Real_SetBkColor)(HDC a0,
    COLORREF a1)
    = SetBkColor;

int(__stdcall* Real_SetBkMode)(HDC a0,
    int a1)
    = SetBkMode;

UINT(__stdcall* Real_SetBoundsRect)(HDC a0,
    CONST RECT* a1,
    UINT a2)
    = SetBoundsRect;

BOOL(__stdcall* Real_SetBrushOrgEx)(HDC a0,
    int a1,
    int a2,
    POINT* a3)
    = SetBrushOrgEx;

HWND(__stdcall* Real_SetCapture)(HWND a0)
= SetCapture;

BOOL(__stdcall* Real_SetCaretBlinkTime)(UINT a0)
= SetCaretBlinkTime;

BOOL(__stdcall* Real_SetCaretPos)(int a0,
    int a1)
    = SetCaretPos;

DWORD(__stdcall* Real_SetClassLongA)(HWND a0,
    int a1,
    LONG a2)
    = SetClassLongA;

DWORD(__stdcall* Real_SetClassLongW)(HWND a0,
    int a1,
    LONG a2)
    = SetClassLongW;

WORD(__stdcall* Real_SetClassWord)(HWND a0,
    int a1,
    WORD a2)
    = SetClassWord;

HANDLE(__stdcall* Real_SetClipboardData)(UINT a0,
    HANDLE a1)
    = SetClipboardData;

HWND(__stdcall* Real_SetClipboardViewer)(HWND a0)
= SetClipboardViewer;

BOOL(__stdcall* Real_SetColorAdjustment)(HDC a0,
    CONST COLORADJUSTMENT* a1)
    = SetColorAdjustment;

HCOLORSPACE(__stdcall* Real_SetColorSpace)(HDC a0,
    HCOLORSPACE a1)
    = SetColorSpace;

BOOL(__stdcall* Real_SetCommBreak)(HANDLE a0)
= SetCommBreak;

BOOL(__stdcall* Real_SetCommConfig)(HANDLE a0,
    LPCOMMCONFIG a1,
    DWORD a2)
    = SetCommConfig;

BOOL(__stdcall* Real_SetCommMask)(HANDLE a0,
    DWORD a1)
    = SetCommMask;

BOOL(__stdcall* Real_SetCommState)(HANDLE a0,
    LPDCB a1)
    = SetCommState;

BOOL(__stdcall* Real_SetCommTimeouts)(HANDLE a0,
    LPCOMMTIMEOUTS a1)
    = SetCommTimeouts;

BOOL(__stdcall* Real_SetComputerNameA)(LPCSTR a0)
= SetComputerNameA;

BOOL(__stdcall* Real_SetComputerNameW)(LPCWSTR a0)
= SetComputerNameW;

BOOL(__stdcall* Real_SetConsoleActiveScreenBuffer)(HANDLE a0)
= SetConsoleActiveScreenBuffer;

BOOL(__stdcall* Real_SetConsoleCP)(UINT a0)
= SetConsoleCP;

BOOL(__stdcall* Real_SetConsoleCtrlHandler)(PHANDLER_ROUTINE a0,
    BOOL a1)
    = SetConsoleCtrlHandler;

BOOL(__stdcall* Real_SetConsoleCursorInfo)(HANDLE a0,
    CONST CONSOLE_CURSOR_INFO* a1)
    = SetConsoleCursorInfo;

BOOL(__stdcall* Real_SetConsoleCursorPosition)(HANDLE a0,
    COORD a1)
    = SetConsoleCursorPosition;

BOOL(__stdcall* Real_SetConsoleMode)(HANDLE a0,
    DWORD a1)
    = SetConsoleMode;

BOOL(__stdcall* Real_SetConsoleOutputCP)(UINT a0)
= SetConsoleOutputCP;

BOOL(__stdcall* Real_SetConsoleScreenBufferSize)(HANDLE a0,
    COORD a1)
    = SetConsoleScreenBufferSize;

BOOL(__stdcall* Real_SetConsoleTextAttribute)(HANDLE a0,
    WORD a1)
    = SetConsoleTextAttribute;

BOOL(__stdcall* Real_SetConsoleTitleA)(LPCSTR a0)
= SetConsoleTitleA;

BOOL(__stdcall* Real_SetConsoleTitleW)(LPCWSTR a0)
= SetConsoleTitleW;

BOOL(__stdcall* Real_SetConsoleWindowInfo)(HANDLE a0,
    BOOL a1,
    CONST SMALL_RECT* a2)
    = SetConsoleWindowInfo;

HRESULT(__stdcall* Real_SetConvertStg)(LPSTORAGE a0,
    BOOL a1)
    = SetConvertStg;

BOOL(__stdcall* Real_SetCurrentDirectoryA)(LPCSTR a0)
= SetCurrentDirectoryA;

BOOL(__stdcall* Real_SetCurrentDirectoryW)(LPCWSTR a0)
= SetCurrentDirectoryW;

HCURSOR(__stdcall* Real_SetCursor)(HCURSOR a0)
= SetCursor;

BOOL(__stdcall* Real_SetCursorPos)(int a0,
    int a1)
    = SetCursorPos;

UINT(__stdcall* Real_SetDIBColorTable)(HDC a0,
    UINT a1,
    UINT a2,
    CONST RGBQUAD* a3)
    = SetDIBColorTable;

int(__stdcall* Real_SetDIBits)(HDC a0,
    HBITMAP a1,
    UINT a2,
    UINT a3,
    CONST void* a4,
    CONST BITMAPINFO* a5,
    UINT a6)
    = SetDIBits;

int(__stdcall* Real_SetDIBitsToDevice)(HDC a0,
    int a1,
    int a2,
    DWORD a3,
    DWORD a4,
    int a5,
    int a6,
    UINT a7,
    UINT a8,
    CONST void* a9,
    CONST BITMAPINFO* a10,
    UINT a11)
    = SetDIBitsToDevice;

BOOL(__stdcall* Real_SetDefaultCommConfigA)(LPCSTR a0,
    LPCOMMCONFIG a1,
    DWORD a2)
    = SetDefaultCommConfigA;

BOOL(__stdcall* Real_SetDefaultCommConfigW)(LPCWSTR a0,
    LPCOMMCONFIG a1,
    DWORD a2)
    = SetDefaultCommConfigW;

BOOL(__stdcall* Real_SetDeviceGammaRamp)(HDC a0,
    LPVOID a1)
    = SetDeviceGammaRamp;

BOOL(__stdcall* Real_SetDlgItemInt)(HWND a0,
    int a1,
    UINT a2,
    BOOL a3)
    = SetDlgItemInt;

BOOL(__stdcall* Real_SetDlgItemTextA)(HWND a0,
    int a1,
    LPCSTR a2)
    = SetDlgItemTextA;

BOOL(__stdcall* Real_SetDlgItemTextW)(HWND a0,
    int a1,
    LPCWSTR a2)
    = SetDlgItemTextW;

BOOL(__stdcall* Real_SetDoubleClickTime)(UINT a0)
= SetDoubleClickTime;

BOOL(__stdcall* Real_SetEndOfFile)(HANDLE a0)
= SetEndOfFile;

HENHMETAFILE(__stdcall* Real_SetEnhMetaFileBits)(UINT a0,
    CONST BYTE* a1)
    = SetEnhMetaFileBits;

BOOL(__stdcall* Real_SetEnvironmentVariableA)(LPCSTR a0,
    LPCSTR a1)
    = SetEnvironmentVariableA;

BOOL(__stdcall* Real_SetEnvironmentVariableW)(LPCWSTR a0,
    LPCWSTR a1)
    = SetEnvironmentVariableW;

UINT(__stdcall* Real_SetErrorMode)(UINT a0)
= SetErrorMode;

BOOL(__stdcall* Real_SetEvent)(HANDLE a0)
= SetEvent;

void(__stdcall* Real_SetFileApisToANSI)(void)
= SetFileApisToANSI;

void(__stdcall* Real_SetFileApisToOEM)(void)
= SetFileApisToOEM;

BOOL(__stdcall* Real_SetFileAttributesA)(LPCSTR a0,
    DWORD a1)
    = SetFileAttributesA;

BOOL(__stdcall* Real_SetFileAttributesW)(LPCWSTR a0,
    DWORD a1)
    = SetFileAttributesW;

DWORD(__stdcall* Real_SetFilePointer)(HANDLE a0,
    LONG a1,
    PLONG a2,
    DWORD a3)
    = SetFilePointer;

BOOL(__stdcall* Real_SetFileTime)(HANDLE a0,
    CONST FILETIME* a1,
    CONST FILETIME* a2,
    CONST FILETIME* a3)
    = SetFileTime;

HWND(__stdcall* Real_SetFocus)(HWND a0)
= SetFocus;

BOOL(__stdcall* Real_SetForegroundWindow)(HWND a0)
= SetForegroundWindow;

int(__stdcall* Real_SetGraphicsMode)(HDC a0,
    int a1)
    = SetGraphicsMode;

UINT(__stdcall* Real_SetHandleCount)(UINT a0)
= SetHandleCount;

BOOL(__stdcall* Real_SetHandleInformation)(HANDLE a0,
    DWORD a1,
    DWORD a2)
    = SetHandleInformation;

int(__stdcall* Real_SetICMMode)(HDC a0,
    int a1)
    = SetICMMode;

BOOL(__stdcall* Real_SetICMProfileA)(HDC a0,
    LPSTR a1)
    = SetICMProfileA;

BOOL(__stdcall* Real_SetICMProfileW)(HDC a0,
    LPWSTR a1)
    = SetICMProfileW;

BOOL(__stdcall* Real_SetKeyboardState)(LPBYTE a0)
= SetKeyboardState;

BOOL(__stdcall* Real_SetLocalTime)(CONST SYSTEMTIME* a0)
= SetLocalTime;

BOOL(__stdcall* Real_SetLocaleInfoA)(LCID a0,
    LCTYPE a1,
    LPCSTR a2)
    = SetLocaleInfoA;

BOOL(__stdcall* Real_SetLocaleInfoW)(LCID a0,
    LCTYPE a1,
    LPCWSTR a2)
    = SetLocaleInfoW;

BOOL(__stdcall* Real_SetMailslotInfo)(HANDLE a0,
    DWORD a1)
    = SetMailslotInfo;

int(__stdcall* Real_SetMapMode)(HDC a0,
    int a1)
    = SetMapMode;

DWORD(__stdcall* Real_SetMapperFlags)(HDC a0,
    DWORD a1)
    = SetMapperFlags;

BOOL(__stdcall* Real_SetMenu)(HWND a0,
    HMENU a1)
    = SetMenu;

BOOL(__stdcall* Real_SetMenuContextHelpId)(HMENU a0,
    DWORD a1)
    = SetMenuContextHelpId;

BOOL(__stdcall* Real_SetMenuDefaultItem)(HMENU a0,
    UINT a1,
    UINT a2)
    = SetMenuDefaultItem;

BOOL(__stdcall* Real_SetMenuItemBitmaps)(HMENU a0,
    UINT a1,
    UINT a2,
    HBITMAP a3,
    HBITMAP a4)
    = SetMenuItemBitmaps;

BOOL(__stdcall* Real_SetMenuItemInfoA)(HMENU a0,
    UINT a1,
    BOOL a2,
    CONST MENUITEMINFOA* a3)
    = SetMenuItemInfoA;

BOOL(__stdcall* Real_SetMenuItemInfoW)(HMENU a0,
    UINT a1,
    BOOL a2,
    CONST MENUITEMINFOW* a3)
    = SetMenuItemInfoW;

LPARAM(__stdcall* Real_SetMessageExtraInfo)(LPARAM a0)
= SetMessageExtraInfo;

BOOL(__stdcall* Real_SetMessageQueue)(int a0)
= SetMessageQueue;

HMETAFILE(__stdcall* Real_SetMetaFileBitsEx)(UINT a0,
    CONST BYTE* a1)
    = SetMetaFileBitsEx;

int(__stdcall* Real_SetMetaRgn)(HDC a0)
= SetMetaRgn;

BOOL(__stdcall* Real_SetMiterLimit)(HDC a0,
    FLOAT a1,
    PFLOAT a2)
    = SetMiterLimit;

BOOL(__stdcall* Real_SetNamedPipeHandleState)(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3)
    = SetNamedPipeHandleState;

UINT(__stdcall* Real_SetPaletteEntries)(HPALETTE a0,
    UINT a1,
    UINT a2,
    CONST PALETTEENTRY* a3)
    = SetPaletteEntries;

HWND(__stdcall* Real_SetParent)(HWND a0,
    HWND a1)
    = SetParent;

COLORREF(__stdcall* Real_SetPixel)(HDC a0,
    int a1,
    int a2,
    COLORREF a3)
    = SetPixel;

BOOL(__stdcall* Real_SetPixelFormat)(HDC a0,
    int a1,
    CONST PIXELFORMATDESCRIPTOR* a2)
    = SetPixelFormat;

BOOL(__stdcall* Real_SetPixelV)(HDC a0,
    int a1,
    int a2,
    COLORREF a3)
    = SetPixelV;

int(__stdcall* Real_SetPolyFillMode)(HDC a0,
    int a1)
    = SetPolyFillMode;

BOOL(__stdcall* Real_SetPriorityClass)(HANDLE a0,
    DWORD a1)
    = SetPriorityClass;

BOOL(__stdcall* Real_SetProcessAffinityMask)(HANDLE a0,
    DWORD_PTR a1)
    = SetProcessAffinityMask;

BOOL(__stdcall* Real_SetProcessShutdownParameters)(DWORD a0,
    DWORD a1)
    = SetProcessShutdownParameters;

BOOL(__stdcall* Real_SetProcessWindowStation)(HWINSTA a0)
= SetProcessWindowStation;

BOOL(__stdcall* Real_SetProcessWorkingSetSize)(HANDLE a0,
    SIZE_T a1,
    SIZE_T a2)
    = SetProcessWorkingSetSize;

BOOL(__stdcall* Real_SetPropA)(HWND a0,
    LPCSTR a1,
    HANDLE a2)
    = SetPropA;

BOOL(__stdcall* Real_SetPropW)(HWND a0,
    LPCWSTR a1,
    HANDLE a2)
    = SetPropW;

int(__stdcall* Real_SetROP2)(HDC a0,
    int a1)
    = SetROP2;

BOOL(__stdcall* Real_SetRect)(LPRECT a0,
    int a1,
    int a2,
    int a3,
    int a4)
    = SetRect;

BOOL(__stdcall* Real_SetRectEmpty)(LPRECT a0)
= SetRectEmpty;

BOOL(__stdcall* Real_SetRectRgn)(HRGN a0,
    int a1,
    int a2,
    int a3,
    int a4)
    = SetRectRgn;

int(__stdcall* Real_SetScrollInfo)(HWND a0,
    int a1,
    LPCSCROLLINFO a2,
    BOOL a3)
    = SetScrollInfo;

int(__stdcall* Real_SetScrollPos)(HWND a0,
    int a1,
    int a2,
    BOOL a3)
    = SetScrollPos;

BOOL(__stdcall* Real_SetScrollRange)(HWND a0,
    int a1,
    int a2,
    int a3,
    BOOL a4)
    = SetScrollRange;

BOOL(__stdcall* Real_SetStdHandle)(DWORD a0,
    HANDLE a1)
    = SetStdHandle;

int(__stdcall* Real_SetStretchBltMode)(HDC a0,
    int a1)
    = SetStretchBltMode;

BOOL(__stdcall* Real_SetSysColors)(int a0,
    CONST INT* a1,
    CONST COLORREF* a2)
    = SetSysColors;

BOOL(__stdcall* Real_SetSystemCursor)(HCURSOR a0,
    DWORD a1)
    = SetSystemCursor;

UINT(__stdcall* Real_SetSystemPaletteUse)(HDC a0,
    UINT a1)
    = SetSystemPaletteUse;

BOOL(__stdcall* Real_SetSystemPowerState)(BOOL a0,
    BOOL a1)
    = SetSystemPowerState;

BOOL(__stdcall* Real_SetSystemTime)(CONST SYSTEMTIME* a0)
= SetSystemTime;

BOOL(__stdcall* Real_SetSystemTimeAdjustment)(DWORD a0,
    BOOL a1)
    = SetSystemTimeAdjustment;

DWORD(__stdcall* Real_SetTapeParameters)(HANDLE a0,
    DWORD a1,
    LPVOID a2)
    = SetTapeParameters;

DWORD(__stdcall* Real_SetTapePosition)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    BOOL a5)
    = SetTapePosition;

UINT(__stdcall* Real_SetTextAlign)(HDC a0,
    UINT a1)
    = SetTextAlign;

int(__stdcall* Real_SetTextCharacterExtra)(HDC a0,
    int a1)
    = SetTextCharacterExtra;

COLORREF(__stdcall* Real_SetTextColor)(HDC a0,
    COLORREF a1)
    = SetTextColor;

BOOL(__stdcall* Real_SetTextJustification)(HDC a0,
    int a1,
    int a2)
    = SetTextJustification;

DWORD_PTR(__stdcall* Real_SetThreadAffinityMask)(HANDLE a0,
    DWORD_PTR a1)
    = SetThreadAffinityMask;

BOOL(__stdcall* Real_SetThreadContext)(HANDLE a0,
    CONST CONTEXT* a1)
    = SetThreadContext;

BOOL(__stdcall* Real_SetThreadDesktop)(HDESK a0)
= SetThreadDesktop;

DWORD(__stdcall* Real_SetThreadIdealProcessor)(HANDLE a0,
    DWORD a1)
    = SetThreadIdealProcessor;

#if(WINVER >= 0x0500)
BOOL(__stdcall* Real_SetThreadLocale)(LCID a0)
= SetThreadLocale;
#endif // (WINVER >= 0x0500)

BOOL(__stdcall* Real_SetThreadPriority)(HANDLE a0,
    int a1)
    = SetThreadPriority;

BOOL(__stdcall* Real_SetThreadPriorityBoost)(HANDLE a0,
    BOOL a1)
    = SetThreadPriorityBoost;

BOOL(__stdcall* Real_SetTimeZoneInformation)(CONST TIME_ZONE_INFORMATION* a0)
= SetTimeZoneInformation;

UINT_PTR(__stdcall* Real_SetTimer)(HWND a0,
    UINT_PTR a1,
    UINT a2,
    TIMERPROC a3)
    = SetTimer;

LPTOP_LEVEL_EXCEPTION_FILTER(__stdcall* Real_SetUnhandledExceptionFilter)(LPTOP_LEVEL_EXCEPTION_FILTER a0)
= SetUnhandledExceptionFilter;

BOOL(__stdcall* Real_SetUserObjectInformationA)(HANDLE a0,
    int a1,
    PVOID a2,
    DWORD a3)
    = SetUserObjectInformationA;

BOOL(__stdcall* Real_SetUserObjectInformationW)(HANDLE a0,
    int a1,
    PVOID a2,
    DWORD a3)
    = SetUserObjectInformationW;

BOOL(__stdcall* Real_SetUserObjectSecurity)(HANDLE a0,
    PSECURITY_INFORMATION a1,
    PSECURITY_DESCRIPTOR a2)
    = SetUserObjectSecurity;

BOOL(__stdcall* Real_SetViewportExtEx)(HDC a0,
    int a1,
    int a2,
    SIZE* a3)
    = SetViewportExtEx;

BOOL(__stdcall* Real_SetViewportOrgEx)(HDC a0,
    int a1,
    int a2,
    POINT* a3)
    = SetViewportOrgEx;

BOOL(__stdcall* Real_SetVolumeLabelA)(LPCSTR a0,
    LPCSTR a1)
    = SetVolumeLabelA;

BOOL(__stdcall* Real_SetVolumeLabelW)(LPCWSTR a0,
    LPCWSTR a1)
    = SetVolumeLabelW;

BOOL(__stdcall* Real_SetWaitableTimer)(HANDLE a0,
    CONST LARGE_INTEGER* a1,
    LONG a2,
    PTIMERAPCROUTINE a3,
    LPVOID a4,
    BOOL a5)
    = SetWaitableTimer;

HENHMETAFILE(__stdcall* Real_SetWinMetaFileBits)(UINT a0,
    CONST BYTE* a1,
    HDC a2,
    CONST METAFILEPICT* a3)
    = SetWinMetaFileBits;

BOOL(__stdcall* Real_SetWindowContextHelpId)(HWND a0,
    DWORD a1)
    = SetWindowContextHelpId;

BOOL(__stdcall* Real_SetWindowExtEx)(HDC a0,
    int a1,
    int a2,
    SIZE* a3)
    = SetWindowExtEx;

LONG(__stdcall* Real_SetWindowLongA)(HWND a0,
    int a1,
    LONG a2)
    = SetWindowLongA;

LONG(__stdcall* Real_SetWindowLongW)(HWND a0,
    int a1,
    LONG a2)
    = SetWindowLongW;

BOOL(__stdcall* Real_SetWindowOrgEx)(HDC a0,
    int a1,
    int a2,
    POINT* a3)
    = SetWindowOrgEx;

BOOL(__stdcall* Real_SetWindowPlacement)(HWND a0,
    CONST WINDOWPLACEMENT* a1)
    = SetWindowPlacement;

BOOL(__stdcall* Real_SetWindowPos)(HWND a0,
    HWND a1,
    int a2,
    int a3,
    int a4,
    int a5,
    UINT a6)
    = SetWindowPos;

int(__stdcall* Real_SetWindowRgn)(HWND a0,
    HRGN a1,
    BOOL a2)
    = SetWindowRgn;

BOOL(__stdcall* Real_SetWindowTextA)(HWND a0,
    LPCSTR a1)
    = SetWindowTextA;

BOOL(__stdcall* Real_SetWindowTextW)(HWND a0,
    LPCWSTR a1)
    = SetWindowTextW;

WORD(__stdcall* Real_SetWindowWord)(HWND a0,
    int a1,
    WORD a2)
    = SetWindowWord;

HHOOK(__stdcall* Real_SetWindowsHookA)(int a0,
    HOOKPROC a1)
    = SetWindowsHookA;

HHOOK(__stdcall* Real_SetWindowsHookExA)(int a0,
    HOOKPROC a1,
    HINSTANCE a2,
    DWORD a3)
    = SetWindowsHookExA;

HHOOK(__stdcall* Real_SetWindowsHookExW)(int a0,
    HOOKPROC a1,
    HINSTANCE a2,
    DWORD a3)
    = SetWindowsHookExW;

HHOOK(__stdcall* Real_SetWindowsHookW)(int a0,
    HOOKPROC a1)
    = SetWindowsHookW;

BOOL(__stdcall* Real_SetWorldTransform)(HDC a0,
    CONST XFORM* a1)
    = SetWorldTransform;

BOOL(__stdcall* Real_SetupComm)(HANDLE a0,
    DWORD a1,
    DWORD a2)
    = SetupComm;

BOOL(__stdcall* Real_ShowCaret)(HWND a0)
= ShowCaret;

int(__stdcall* Real_ShowCursor)(BOOL a0)
= ShowCursor;

BOOL(__stdcall* Real_ShowOwnedPopups)(HWND a0,
    BOOL a1)
    = ShowOwnedPopups;

BOOL(__stdcall* Real_ShowScrollBar)(HWND a0,
    int a1,
    BOOL a2)
    = ShowScrollBar;

BOOL(__stdcall* Real_ShowWindow)(HWND a0,
    int a1)
    = ShowWindow;

BOOL(__stdcall* Real_ShowWindowAsync)(HWND a0,
    int a1)
    = ShowWindowAsync;

DWORD(__stdcall* Real_SignalObjectAndWait)(HANDLE a0,
    HANDLE a1,
    DWORD a2,
    BOOL a3)
    = SignalObjectAndWait;

DWORD(__stdcall* Real_SizeofResource)(HMODULE a0,
    HRSRC a1)
    = SizeofResource;

DWORD(__stdcall* Real_SleepEx)(DWORD a0,
    BOOL a1)
    = SleepEx;

int(__stdcall* Real_StartDocA)(HDC a0,
    CONST DOCINFOA* a1)
    = StartDocA;

int(__stdcall* Real_StartDocW)(HDC a0,
    CONST DOCINFOW* a1)
    = StartDocW;

int(__stdcall* Real_StartPage)(HDC a0)
= StartPage;

HRESULT(__stdcall* Real_StgCreateDocfile)(CONST OLECHAR* a0,
    DWORD a1,
    DWORD a2,
    IStorage** a3)
    = StgCreateDocfile;

HRESULT(__stdcall* Real_StgCreateDocfileOnILockBytes)(ILockBytes* a0,
    DWORD a1,
    DWORD a2,
    IStorage** a3)
    = StgCreateDocfileOnILockBytes;

HRESULT(__stdcall* Real_StgCreatePropSetStg)(IStorage* a0,
    DWORD a1,
    IPropertySetStorage** a2)
    = StgCreatePropSetStg;

HRESULT(__stdcall* Real_StgCreatePropStg)(IUnknown* a0,
    CONST IID& a1,
    CONST CLSID* a2,
    DWORD a3,
    DWORD a4,
    IPropertyStorage** a5)
    = StgCreatePropStg;

#if _MSC_VER < 1300
HRESULT(__stdcall* Real_StgCreateStorageEx)(CONST WCHAR* a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    void* a4,
    void* a5,
    CONST IID& a6,
    void** a7)
    = StgCreateStorageEx;
#else
HRESULT(__stdcall* Real_StgCreateStorageEx)(CONST WCHAR* a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    STGOPTIONS* a4,
    void* a5,
    CONST IID& a6,
    void** a7)
    = StgCreateStorageEx;
#endif

HRESULT(__stdcall* Real_StgGetIFillLockBytesOnFile)(CONST OLECHAR* a0,
    IFillLockBytes** a1)
    = StgGetIFillLockBytesOnFile;

HRESULT(__stdcall* Real_StgGetIFillLockBytesOnILockBytes)(ILockBytes* a0,
    IFillLockBytes** a1)
    = StgGetIFillLockBytesOnILockBytes;

HRESULT(__stdcall* Real_StgIsStorageFile)(CONST OLECHAR* a0)
= StgIsStorageFile;

HRESULT(__stdcall* Real_StgIsStorageILockBytes)(ILockBytes* a0)
= StgIsStorageILockBytes;

HRESULT(__stdcall* Real_StgOpenAsyncDocfileOnIFillLockBytes)(IFillLockBytes* a0,
    DWORD a1,
    DWORD a2,
    IStorage** a3)
    = StgOpenAsyncDocfileOnIFillLockBytes;

HRESULT(__stdcall* Real_StgOpenPropStg)(IUnknown* a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    IPropertyStorage** a4)
    = StgOpenPropStg;

HRESULT(__stdcall* Real_StgOpenStorage)(CONST OLECHAR* a0,
    IStorage* a1,
    DWORD a2,
    SNB a3,
    DWORD a4,
    IStorage** a5)
    = StgOpenStorage;

#if _MSC_VER < 1300
HRESULT(__stdcall* Real_StgOpenStorageEx)(CONST WCHAR* a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    void* a4,
    void* a5,
    CONST IID& a6,
    void** a7)
    = StgOpenStorageEx;
#else
HRESULT(__stdcall* Real_StgOpenStorageEx)(CONST WCHAR* a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    STGOPTIONS* a4,
    void* a5,
    CONST IID& a6,
    void** a7)
    = StgOpenStorageEx;
#endif

HRESULT(__stdcall* Real_StgOpenStorageOnILockBytes)(ILockBytes* a0,
    IStorage* a1,
    DWORD a2,
    SNB a3,
    DWORD a4,
    IStorage** a5)
    = StgOpenStorageOnILockBytes;

HRESULT(__stdcall* Real_StgSetTimes)(CONST OLECHAR* a0,
    CONST FILETIME* a1,
    CONST FILETIME* a2,
    CONST FILETIME* a3)
    = StgSetTimes;

BOOL(__stdcall* Real_StretchBlt)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    HDC a5,
    int a6,
    int a7,
    int a8,
    int a9,
    DWORD a10)
    = StretchBlt;

int(__stdcall* Real_StretchDIBits)(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8,
    CONST void* a9,
    CONST BITMAPINFO* a10,
    UINT a11,
    DWORD a12)
    = StretchDIBits;

HRESULT(__stdcall* Real_StringFromCLSID)(CONST IID& a0,
    LPOLESTR* a1)
    = StringFromCLSID;

int(__stdcall* Real_StringFromGUID2)(CONST GUID& a0,
    LPOLESTR a1,
    int a2)
    = StringFromGUID2;

HRESULT(__stdcall* Real_StringFromIID)(CONST IID& a0,
    LPOLESTR* a1)
    = StringFromIID;

BOOL(__stdcall* Real_StrokeAndFillPath)(HDC a0)
= StrokeAndFillPath;

BOOL(__stdcall* Real_StrokePath)(HDC a0)
= StrokePath;

BOOL(__stdcall* Real_SubtractRect)(LPRECT a0,
    CONST RECT* a1,
    CONST RECT* a2)
    = SubtractRect;

DWORD(__stdcall* Real_SuspendThread)(HANDLE a0)
= SuspendThread;

BOOL(__stdcall* Real_SwapBuffers)(HDC a0)
= SwapBuffers;

BOOL(__stdcall* Real_SwapMouseButton)(BOOL a0)
= SwapMouseButton;

BOOL(__stdcall* Real_SwitchDesktop)(HDESK a0)
= SwitchDesktop;

void(__stdcall* Real_SwitchToFiber)(LPVOID a0)
= SwitchToFiber;

BOOL(__stdcall* Real_SwitchToThread)(void)
= SwitchToThread;

BOOL(__stdcall* Real_SystemParametersInfoA)(UINT a0,
    UINT a1,
    PVOID a2,
    UINT a3)
    = SystemParametersInfoA;

BOOL(__stdcall* Real_SystemParametersInfoW)(UINT a0,
    UINT a1,
    PVOID a2,
    UINT a3)
    = SystemParametersInfoW;

BOOL(__stdcall* Real_SystemTimeToFileTime)(CONST SYSTEMTIME* a0,
    LPFILETIME a1)
    = SystemTimeToFileTime;

BOOL(__stdcall* Real_SystemTimeToTzSpecificLocalTime)(
#ifdef PIPE_ACCEPT_REMOTE_CLIENTS
    const TIME_ZONE_INFORMATION* a0,
    const SYSTEMTIME* a1,
#else
    LPTIME_ZONE_INFORMATION a0,
    LPSYSTEMTIME a1,
#endif
    LPSYSTEMTIME a2
    )
    = SystemTimeToTzSpecificLocalTime;

#if _MSC_VER < 1300
LONG(__stdcall* Real_TabbedTextOutA)(HDC a0,
    int a1,
    int a2,
    LPCSTR a3,
    int a4,
    int a5,
    INT* a6,
    int a7)
    = TabbedTextOutA;
#else
LONG(__stdcall* Real_TabbedTextOutA)(HDC a0,
    int a1,
    int a2,
    LPCSTR a3,
    int a4,
    int a5,
    CONST INT* a6,
    int a7)
    = TabbedTextOutA;
#endif

#if _MSC_VER < 1300
LONG(__stdcall* Real_TabbedTextOutW)(HDC a0,
    int a1,
    int a2,
    LPCWSTR a3,
    int a4,
    int a5,
    INT* a6,
    int a7)
    = TabbedTextOutW;
#else
LONG(__stdcall* Real_TabbedTextOutW)(HDC a0,
    int a1,
    int a2,
    LPCWSTR a3,
    int a4,
    int a5,
    CONST INT* a6,
    int a7)
    = TabbedTextOutW;
#endif

BOOL(__stdcall* Real_TerminateProcess)(HANDLE a0,
    UINT a1)
    = TerminateProcess;

BOOL(__stdcall* Real_TerminateThread)(HANDLE a0,
    DWORD a1)
    = TerminateThread;

BOOL(__stdcall* Real_TextOutA)(HDC a0,
    int a1,
    int a2,
    LPCSTR a3,
    int a4)
    = TextOutA;

BOOL(__stdcall* Real_TextOutW)(HDC a0,
    int a1,
    int a2,
    LPCWSTR a3,
    int a4)
    = TextOutW;

WORD(__stdcall* Real_TileWindows)(HWND a0,
    UINT a1,
    CONST RECT* a2,
    UINT a3,
    CONST HWND* a4)
    = TileWindows;

#if _MSC_VER < 1300
int(__stdcall* Real_ToAscii)(UINT a0,
    UINT a1,
    BYTE* a2,
    LPWORD a3,
    UINT a4)
    = ToAscii;
#else
int(__stdcall* Real_ToAscii)(UINT a0,
    UINT a1,
    CONST BYTE* a2,
    LPWORD a3,
    UINT a4)
    = ToAscii;
#endif

#if _MSC_VER < 1300
int(__stdcall* Real_ToAsciiEx)(UINT a0,
    UINT a1,
    BYTE* a2,
    LPWORD a3,
    UINT a4,
    HKL a5)
    = ToAsciiEx;
#else
int(__stdcall* Real_ToAsciiEx)(UINT a0,
    UINT a1,
    CONST BYTE* a2,
    LPWORD a3,
    UINT a4,
    HKL a5)
    = ToAsciiEx;
#endif

#if _MSC_VER < 1300
int(__stdcall* Real_ToUnicode)(UINT a0,
    UINT a1,
    BYTE* a2,
    LPWSTR a3,
    int a4,
    UINT a5)
    = ToUnicode;
#else
int(__stdcall* Real_ToUnicode)(UINT a0,
    UINT a1,
    CONST BYTE* a2,
    LPWSTR a3,
    int a4,
    UINT a5)
    = ToUnicode;
#endif

#if _MSC_VER < 1300
int(__stdcall* Real_ToUnicodeEx)(UINT a0,
    UINT a1,
    BYTE* a2,
    LPWSTR a3,
    int a4,
    UINT a5,
    HKL a6)
    = ToUnicodeEx;
#else
int(__stdcall* Real_ToUnicodeEx)(UINT a0,
    UINT a1,
    CONST BYTE* a2,
    LPWSTR a3,
    int a4,
    UINT a5,
    HKL a6)
    = ToUnicodeEx;
#endif

BOOL(__stdcall* Real_TrackMouseEvent)(TRACKMOUSEEVENT* a0)
= TrackMouseEvent;

BOOL(__stdcall* Real_TrackPopupMenu)(HMENU a0,
    UINT a1,
    int a2,
    int a3,
    int a4,
    HWND a5,
    CONST RECT* a6)
    = TrackPopupMenu;

BOOL(__stdcall* Real_TrackPopupMenuEx)(HMENU a0,
    UINT a1,
    int a2,
    int a3,
    HWND a4,
    LPTPMPARAMS a5)
    = TrackPopupMenuEx;

BOOL(__stdcall* Real_TransactNamedPipe)(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4,
    LPDWORD a5,
    LPOVERLAPPED a6)
    = TransactNamedPipe;

int(__stdcall* Real_TranslateAcceleratorA)(HWND a0,
    HACCEL a1,
    LPMSG a2)
    = TranslateAcceleratorA;

int(__stdcall* Real_TranslateAcceleratorW)(HWND a0,
    HACCEL a1,
    LPMSG a2)
    = TranslateAcceleratorW;

BOOL(__stdcall* Real_TranslateCharsetInfo)(DWORD* a0,
    CHARSETINFO* a1,
    DWORD a2)
    = TranslateCharsetInfo;

BOOL(__stdcall* Real_TranslateMDISysAccel)(HWND a0,
    LPMSG a1)
    = TranslateMDISysAccel;

BOOL(__stdcall* Real_TranslateMessage)(CONST MSG* a0)
= TranslateMessage;

BOOL(__stdcall* Real_TransmitCommChar)(HANDLE a0,
    char a1)
    = TransmitCommChar;

#if DETOUR_TryEnterCriticalSection_EVEN_IF_IT_EXERCISES_A_BUG_IN_RtlLookupFunctionTable
BOOL(__stdcall* Real_TryEnterCriticalSection)(LPCRITICAL_SECTION a0)
= TryEnterCriticalSection;
#endif

BOOL(__stdcall* Real_UnhookWindowsHook)(int a0,
    HOOKPROC a1)
    = UnhookWindowsHook;

BOOL(__stdcall* Real_UnhookWindowsHookEx)(HHOOK a0)
= UnhookWindowsHookEx;

BOOL(__stdcall* Real_UnionRect)(LPRECT a0,
    CONST RECT* a1,
    CONST RECT* a2)
    = UnionRect;

BOOL(__stdcall* Real_UnloadKeyboardLayout)(HKL a0)
= UnloadKeyboardLayout;

BOOL(__stdcall* Real_UnlockFile)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4)
    = UnlockFile;

BOOL(__stdcall* Real_UnlockFileEx)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    LPOVERLAPPED a4)
    = UnlockFileEx;

BOOL(__stdcall* Real_UnmapViewOfFile)(LPCVOID a0)
= UnmapViewOfFile;

BOOL(__stdcall* Real_UnpackDDElParam)(UINT a0,
    LPARAM a1,
    PUINT_PTR a2,
    PUINT_PTR a3)
    = UnpackDDElParam;

BOOL(__stdcall* Real_UnrealizeObject)(HGDIOBJ a0)
= UnrealizeObject;

BOOL(__stdcall* Real_UnregisterClassA)(LPCSTR a0,
    HINSTANCE a1)
    = UnregisterClassA;

BOOL(__stdcall* Real_UnregisterClassW)(LPCWSTR a0,
    HINSTANCE a1)
    = UnregisterClassW;

BOOL(__stdcall* Real_UnregisterHotKey)(HWND a0,
    int a1)
    = UnregisterHotKey;

BOOL(__stdcall* Real_UpdateColors)(HDC a0)
= UpdateColors;

BOOL(__stdcall* Real_UpdateResourceA)(HANDLE a0,
    LPCSTR a1,
    LPCSTR a2,
    WORD a3,
    LPVOID a4,
    DWORD a5)
    = UpdateResourceA;

BOOL(__stdcall* Real_UpdateResourceW)(HANDLE a0,
    LPCWSTR a1,
    LPCWSTR a2,
    WORD a3,
    LPVOID a4,
    DWORD a5)
    = UpdateResourceW;

BOOL(__stdcall* Real_UpdateWindow)(HWND a0)
= UpdateWindow;

BOOL(__stdcall* Real_ValidateRect)(HWND a0,
    CONST RECT* a1)
    = ValidateRect;

BOOL(__stdcall* Real_ValidateRgn)(HWND a0,
    HRGN a1)
    = ValidateRgn;

DWORD(__stdcall* Real_VerLanguageNameA)(DWORD a0,
    LPSTR a1,
    DWORD a2)
    = VerLanguageNameA;

DWORD(__stdcall* Real_VerLanguageNameW)(DWORD a0,
    LPWSTR a1,
    DWORD a2)
    = VerLanguageNameW;

LPVOID(__stdcall* Real_VirtualAllocEx)(HANDLE a0,
    LPVOID a1,
    SIZE_T a2,
    DWORD a3,
    DWORD a4)
    = VirtualAllocEx;

BOOL(__stdcall* Real_VirtualFreeEx)(HANDLE a0,
    LPVOID a1,
    SIZE_T a2,
    DWORD a3)
    = VirtualFreeEx;

BOOL(__stdcall* Real_VirtualProtectEx)(HANDLE a0,
    LPVOID a1,
    SIZE_T a2,
    DWORD a3,
    PDWORD a4)
    = VirtualProtectEx;

DWORD_PTR(__stdcall* Real_VirtualQueryEx)(HANDLE a0,
    LPCVOID a1,
    PMEMORY_BASIC_INFORMATION a2,
    DWORD_PTR a3)
    = VirtualQueryEx;

SHORT(__stdcall* Real_VkKeyScanA)(CHAR a0)
= VkKeyScanA;

SHORT(__stdcall* Real_VkKeyScanExA)(CHAR a0,
    HKL a1)
    = VkKeyScanExA;

SHORT(__stdcall* Real_VkKeyScanExW)(WCHAR a0,
    HKL a1)
    = VkKeyScanExW;

SHORT(__stdcall* Real_VkKeyScanW)(WCHAR a0)
= VkKeyScanW;

SOCKET(__stdcall* Real_WSAAccept)(SOCKET a0,
    sockaddr* a1,
    LPINT a2,
    LPCONDITIONPROC a3,
    DWORD_PTR a4)
    = WSAAccept;

INT(__stdcall* Real_WSAAddressToStringA)(LPSOCKADDR a0,
    DWORD a1,
    LPWSAPROTOCOL_INFOA a2,
    LPSTR a3,
    LPDWORD a4)
    = WSAAddressToStringA;

INT(__stdcall* Real_WSAAddressToStringW)(LPSOCKADDR a0,
    DWORD a1,
    LPWSAPROTOCOL_INFOW a2,
    LPWSTR a3,
    LPDWORD a4)
    = WSAAddressToStringW;

HANDLE(__stdcall* Real_WSAAsyncGetHostByAddr)(HWND a0,
    u_int a1,
    CONST char* a2,
    int a3,
    int a4,
    char* a5,
    int a6)
    = WSAAsyncGetHostByAddr;

HANDLE(__stdcall* Real_WSAAsyncGetHostByName)(HWND a0,
    u_int a1,
    CONST char* a2,
    char* a3,
    int a4)
    = WSAAsyncGetHostByName;

HANDLE(__stdcall* Real_WSAAsyncGetProtoByName)(HWND a0,
    u_int a1,
    CONST char* a2,
    char* a3,
    int a4)
    = WSAAsyncGetProtoByName;

HANDLE(__stdcall* Real_WSAAsyncGetProtoByNumber)(HWND a0,
    u_int a1,
    int a2,
    char* a3,
    int a4)
    = WSAAsyncGetProtoByNumber;

HANDLE(__stdcall* Real_WSAAsyncGetServByName)(HWND a0,
    u_int a1,
    CONST char* a2,
    CONST char* a3,
    char* a4,
    int a5)
    = WSAAsyncGetServByName;

HANDLE(__stdcall* Real_WSAAsyncGetServByPort)(HWND a0,
    u_int a1,
    int a2,
    CONST char* a3,
    char* a4,
    int a5)
    = WSAAsyncGetServByPort;

int(__stdcall* Real_WSAAsyncSelect)(SOCKET a0,
    HWND a1,
    u_int a2,
    long a3)
    = WSAAsyncSelect;

int(__stdcall* Real_WSACancelAsyncRequest)(HANDLE a0)
= WSACancelAsyncRequest;

int(__stdcall* Real_WSACancelBlockingCall)(void)
= WSACancelBlockingCall;

int(__stdcall* Real_WSACleanup)(void)
= WSACleanup;

BOOL(__stdcall* Real_WSACloseEvent)(HANDLE a0)
= WSACloseEvent;

int(__stdcall* Real_WSAConnect)(SOCKET a0,
    CONST sockaddr* a1,
    int a2,
    LPWSABUF a3,
    LPWSABUF a4,
    LPQOS a5,
    LPQOS a6)
    = WSAConnect;

HANDLE(__stdcall* Real_WSACreateEvent)(void)
= WSACreateEvent;

int(__stdcall* Real_WSADuplicateSocketA)(SOCKET a0,
    DWORD a1,
    LPWSAPROTOCOL_INFOA a2)
    = WSADuplicateSocketA;

int(__stdcall* Real_WSADuplicateSocketW)(SOCKET a0,
    DWORD a1,
    LPWSAPROTOCOL_INFOW a2)
    = WSADuplicateSocketW;

INT(__stdcall* Real_WSAEnumNameSpaceProvidersA)(LPDWORD a0,
    LPWSANAMESPACE_INFOA a1)
    = WSAEnumNameSpaceProvidersA;

INT(__stdcall* Real_WSAEnumNameSpaceProvidersW)(LPDWORD a0,
    LPWSANAMESPACE_INFOW a1)
    = WSAEnumNameSpaceProvidersW;

int(__stdcall* Real_WSAEnumNetworkEvents)(SOCKET a0,
    HANDLE a1,
    LPWSANETWORKEVENTS a2)
    = WSAEnumNetworkEvents;

int(__stdcall* Real_WSAEnumProtocolsA)(LPINT a0,
    LPWSAPROTOCOL_INFOA a1,
    LPDWORD a2)
    = WSAEnumProtocolsA;

int(__stdcall* Real_WSAEnumProtocolsW)(LPINT a0,
    LPWSAPROTOCOL_INFOW a1,
    LPDWORD a2)
    = WSAEnumProtocolsW;

int(__stdcall* Real_WSAEventSelect)(SOCKET a0,
    HANDLE a1,
    long a2)
    = WSAEventSelect;

BOOL(__stdcall* Real_WSAGetOverlappedResult)(SOCKET a0,
    LPWSAOVERLAPPED a1,
    LPDWORD a2,
    BOOL a3,
    LPDWORD a4)
    = WSAGetOverlappedResult;

BOOL(__stdcall* Real_WSAGetQOSByName)(SOCKET a0,
    LPWSABUF a1,
    LPQOS a2)
    = WSAGetQOSByName;

INT(__stdcall* Real_WSAGetServiceClassInfoA)(LPGUID a0,
    LPGUID a1,
    LPDWORD a2,
    LPWSASERVICECLASSINFOA a3)
    = WSAGetServiceClassInfoA;

INT(__stdcall* Real_WSAGetServiceClassInfoW)(LPGUID a0,
    LPGUID a1,
    LPDWORD a2,
    LPWSASERVICECLASSINFOW a3)
    = WSAGetServiceClassInfoW;

INT(__stdcall* Real_WSAGetServiceClassNameByClassIdA)(LPGUID a0,
    LPSTR a1,
    LPDWORD a2)
    = WSAGetServiceClassNameByClassIdA;

INT(__stdcall* Real_WSAGetServiceClassNameByClassIdW)(LPGUID a0,
    LPWSTR a1,
    LPDWORD a2)
    = WSAGetServiceClassNameByClassIdW;

int(__stdcall* Real_WSAHtonl)(SOCKET a0,
    u_long a1,
    u_long* a2)
    = WSAHtonl;

int(__stdcall* Real_WSAHtons)(SOCKET a0,
    u_short a1,
    u_short* a2)
    = WSAHtons;

INT(__stdcall* Real_WSAInstallServiceClassA)(LPWSASERVICECLASSINFOA a0)
= WSAInstallServiceClassA;

INT(__stdcall* Real_WSAInstallServiceClassW)(LPWSASERVICECLASSINFOW a0)
= WSAInstallServiceClassW;

int(__stdcall* Real_WSAIoctl)(SOCKET a0,
    DWORD a1,
    LPVOID a2,
    DWORD a3,
    LPVOID a4,
    DWORD a5,
    LPDWORD a6,
    LPWSAOVERLAPPED a7,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a8)
    = WSAIoctl;

BOOL(__stdcall* Real_WSAIsBlocking)(void)
= WSAIsBlocking;

SOCKET(__stdcall* Real_WSAJoinLeaf)(SOCKET a0,
    CONST sockaddr* a1,
    int a2,
    LPWSABUF a3,
    LPWSABUF a4,
    LPQOS a5,
    LPQOS a6,
    DWORD a7)
    = WSAJoinLeaf;

INT(__stdcall* Real_WSALookupServiceBeginA)(LPWSAQUERYSETA a0,
    DWORD a1,
    LPHANDLE a2)
    = WSALookupServiceBeginA;

INT(__stdcall* Real_WSALookupServiceBeginW)(LPWSAQUERYSETW a0,
    DWORD a1,
    LPHANDLE a2)
    = WSALookupServiceBeginW;

INT(__stdcall* Real_WSALookupServiceEnd)(HANDLE a0)
= WSALookupServiceEnd;

INT(__stdcall* Real_WSALookupServiceNextA)(HANDLE a0,
    DWORD a1,
    LPDWORD a2,
    LPWSAQUERYSETA a3)
    = WSALookupServiceNextA;

INT(__stdcall* Real_WSALookupServiceNextW)(HANDLE a0,
    DWORD a1,
    LPDWORD a2,
    LPWSAQUERYSETW a3)
    = WSALookupServiceNextW;

int(__stdcall* Real_WSANtohl)(SOCKET a0,
    u_long a1,
    u_long* a2)
    = WSANtohl;

int(__stdcall* Real_WSANtohs)(SOCKET a0,
    u_short a1,
    u_short* a2)
    = WSANtohs;

INT(__stdcall* Real_WSAProviderConfigChange)(LPHANDLE a0,
    LPWSAOVERLAPPED a1,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a2)
    = WSAProviderConfigChange;

int(__stdcall* Real_WSARecv)(SOCKET a0,
    LPWSABUF a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPWSAOVERLAPPED a5,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a6)
    = WSARecv;

int(__stdcall* Real_WSARecvDisconnect)(SOCKET a0,
    LPWSABUF a1)
    = WSARecvDisconnect;

int(__stdcall* Real_WSARecvFrom)(SOCKET a0,
    LPWSABUF a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    sockaddr* a5,
    LPINT a6,
    LPWSAOVERLAPPED a7,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a8)
    = WSARecvFrom;

INT(__stdcall* Real_WSARemoveServiceClass)(LPGUID a0)
= WSARemoveServiceClass;

BOOL(__stdcall* Real_WSAResetEvent)(HANDLE a0)
= WSAResetEvent;

int(__stdcall* Real_WSASend)(SOCKET a0,
    LPWSABUF a1,
    DWORD a2,
    LPDWORD a3,
    DWORD a4,
    LPWSAOVERLAPPED a5,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a6)
    = WSASend;

int(__stdcall* Real_WSASendDisconnect)(SOCKET a0,
    LPWSABUF a1)
    = WSASendDisconnect;

int(__stdcall* Real_WSASendTo)(SOCKET a0,
    LPWSABUF a1,
    DWORD a2,
    LPDWORD a3,
    DWORD a4,
    CONST sockaddr* a5,
    int a6,
    LPWSAOVERLAPPED a7,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a8)
    = WSASendTo;

FARPROC(__stdcall* Real_WSASetBlockingHook)(FARPROC a0)
= WSASetBlockingHook;

BOOL(__stdcall* Real_WSASetEvent)(HANDLE a0)
= WSASetEvent;

INT(__stdcall* Real_WSASetServiceA)(LPWSAQUERYSETA a0,
    WSAESETSERVICEOP a1,
    DWORD a2)
    = WSASetServiceA;

INT(__stdcall* Real_WSASetServiceW)(LPWSAQUERYSETW a0,
    WSAESETSERVICEOP a1,
    DWORD a2)
    = WSASetServiceW;

SOCKET(__stdcall* Real_WSASocketA)(int a0,
    int a1,
    int a2,
    LPWSAPROTOCOL_INFOA a3,
    GROUP a4,
    DWORD a5)
    = WSASocketA;

SOCKET(__stdcall* Real_WSASocketW)(int a0,
    int a1,
    int a2,
    LPWSAPROTOCOL_INFOW a3,
    GROUP a4,
    DWORD a5)
    = WSASocketW;

int(__stdcall* Real_WSAStartup)(WORD a0,
    LPWSADATA a1)
    = WSAStartup;

INT(__stdcall* Real_WSAStringToAddressA)(LPSTR a0,
    INT a1,
    LPWSAPROTOCOL_INFOA a2,
    LPSOCKADDR a3,
    LPINT a4)
    = WSAStringToAddressA;

INT(__stdcall* Real_WSAStringToAddressW)(LPWSTR a0,
    INT a1,
    LPWSAPROTOCOL_INFOW a2,
    LPSOCKADDR a3,
    LPINT a4)
    = WSAStringToAddressW;

int(__stdcall* Real_WSAUnhookBlockingHook)(void)
= WSAUnhookBlockingHook;

DWORD(__stdcall* Real_WSAWaitForMultipleEvents)(DWORD a0,
    CONST HANDLE* a1,
    BOOL a2,
    DWORD a3,
    BOOL a4)
    = WSAWaitForMultipleEvents;

BOOL(__stdcall* Real_WaitCommEvent)(HANDLE a0,
    LPDWORD a1,
    LPOVERLAPPED a2)
    = WaitCommEvent;

#if !defined(DETOURS_ARM)
BOOL(__stdcall* Real_WaitForDebugEvent)(LPDEBUG_EVENT a0,
    DWORD a1)
    = WaitForDebugEvent;
#endif // !DETOUR_ARM

DWORD(__stdcall* Real_WaitForInputIdle)(HANDLE a0,
    DWORD a1)
    = WaitForInputIdle;

DWORD(__stdcall* Real_WaitForMultipleObjects)(DWORD a0,
    CONST HANDLE* a1,
    BOOL a2,
    DWORD a3)
    = WaitForMultipleObjects;

DWORD(__stdcall* Real_WaitForMultipleObjectsEx)(DWORD a0,
    CONST HANDLE* a1,
    BOOL a2,
    DWORD a3,
    BOOL a4)
    = WaitForMultipleObjectsEx;

DWORD(__stdcall* Real_WaitForSingleObject)(HANDLE a0,
    DWORD a1)
    = WaitForSingleObject;

DWORD(__stdcall* Real_WaitForSingleObjectEx)(HANDLE a0,
    DWORD a1,
    BOOL a2)
    = WaitForSingleObjectEx;

BOOL(__stdcall* Real_WaitMessage)(void)
= WaitMessage;

BOOL(__stdcall* Real_WaitNamedPipeA)(LPCSTR a0,
    DWORD a1)
    = WaitNamedPipeA;

BOOL(__stdcall* Real_WaitNamedPipeW)(LPCWSTR a0,
    DWORD a1)
    = WaitNamedPipeW;

BOOL(__stdcall* Real_WidenPath)(HDC a0)
= WidenPath;

UINT(__stdcall* Real_WinExec)(LPCSTR a0,
    UINT a1)
    = WinExec;

BOOL(__stdcall* Real_WinHelpA)(HWND a0,
    LPCSTR a1,
    UINT a2,
    ULONG_PTR a3)
    = WinHelpA;

BOOL(__stdcall* Real_WinHelpW)(HWND a0,
    LPCWSTR a1,
    UINT a2,
    ULONG_PTR a3)
    = WinHelpW;

HWND(__stdcall* Real_WindowFromDC)(HDC a0)
= WindowFromDC;

HWND(__stdcall* Real_WindowFromPoint)(POINT a0)
= WindowFromPoint;

HRESULT(__stdcall* Real_WriteClassStg)(LPSTORAGE a0,
    CONST IID& a1)
    = WriteClassStg;

HRESULT(__stdcall* Real_WriteClassStm)(LPSTREAM a0,
    CONST IID& a1)
    = WriteClassStm;

BOOL(__stdcall* Real_WriteConsoleA)(HANDLE a0,
    CONST void* a1,
    DWORD a2,
    LPDWORD a3,
    LPVOID a4)
    = WriteConsoleA;

BOOL(__stdcall* Real_WriteConsoleInputA)(HANDLE a0,
    CONST INPUT_RECORD* a1,
    DWORD a2,
    LPDWORD a3)
    = WriteConsoleInputA;

BOOL(__stdcall* Real_WriteConsoleInputW)(HANDLE a0,
    CONST INPUT_RECORD* a1,
    DWORD a2,
    LPDWORD a3)
    = WriteConsoleInputW;

BOOL(__stdcall* Real_WriteConsoleOutputA)(HANDLE a0,
    CONST CHAR_INFO* a1,
    COORD a2,
    COORD a3,
    PSMALL_RECT a4)
    = WriteConsoleOutputA;

BOOL(__stdcall* Real_WriteConsoleOutputAttribute)(HANDLE a0,
    CONST WORD* a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
    = WriteConsoleOutputAttribute;

BOOL(__stdcall* Real_WriteConsoleOutputCharacterA)(HANDLE a0,
    LPCSTR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
    = WriteConsoleOutputCharacterA;

BOOL(__stdcall* Real_WriteConsoleOutputCharacterW)(HANDLE a0,
    LPCWSTR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
    = WriteConsoleOutputCharacterW;

BOOL(__stdcall* Real_WriteConsoleOutputW)(HANDLE a0,
    CONST CHAR_INFO* a1,
    COORD a2,
    COORD a3,
    PSMALL_RECT a4)
    = WriteConsoleOutputW;

BOOL(__stdcall* Real_WriteConsoleW)(HANDLE a0,
    CONST void* a1,
    DWORD a2,
    LPDWORD a3,
    LPVOID a4)
    = WriteConsoleW;

BOOL(__stdcall* Real_WriteFile)(HANDLE a0,
    LPCVOID a1,
    DWORD a2,
    LPDWORD a3,
    LPOVERLAPPED a4)
    = WriteFile;

BOOL(__stdcall* Real_WriteFileEx)(HANDLE a0,
    LPCVOID a1,
    DWORD a2,
    LPOVERLAPPED a3,
    LPOVERLAPPED_COMPLETION_ROUTINE a4)
    = WriteFileEx;

HRESULT(__stdcall* Real_WriteFmtUserTypeStg)(LPSTORAGE a0,
    CLIPFORMAT a1,
    LPOLESTR a2)
    = WriteFmtUserTypeStg;

BOOL(__stdcall* Real_WritePrivateProfileSectionA)(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2)
    = WritePrivateProfileSectionA;

BOOL(__stdcall* Real_WritePrivateProfileSectionW)(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2)
    = WritePrivateProfileSectionW;

BOOL(__stdcall* Real_WritePrivateProfileStringA)(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    LPCSTR a3)
    = WritePrivateProfileStringA;

BOOL(__stdcall* Real_WritePrivateProfileStringW)(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    LPCWSTR a3)
    = WritePrivateProfileStringW;

BOOL(__stdcall* Real_WritePrivateProfileStructA)(LPCSTR a0,
    LPCSTR a1,
    LPVOID a2,
    UINT a3,
    LPCSTR a4)
    = WritePrivateProfileStructA;

BOOL(__stdcall* Real_WritePrivateProfileStructW)(LPCWSTR a0,
    LPCWSTR a1,
    LPVOID a2,
    UINT a3,
    LPCWSTR a4)
    = WritePrivateProfileStructW;

#if _MSC_VER < 1300
BOOL(__stdcall* Real_WriteProcessMemory)(HANDLE a0,
    LPVOID a1,
    LPVOID a2,
    DWORD_PTR a3,
    PDWORD_PTR a4)
    = WriteProcessMemory;
#else
BOOL(__stdcall* Real_WriteProcessMemory)(HANDLE a0,
    LPVOID a1,
    LPCVOID a2,
    DWORD_PTR a3,
    PDWORD_PTR a4)
    = WriteProcessMemory;
#endif

BOOL(__stdcall* Real_WriteProfileSectionA)(LPCSTR a0,
    LPCSTR a1)
    = WriteProfileSectionA;

BOOL(__stdcall* Real_WriteProfileSectionW)(LPCWSTR a0,
    LPCWSTR a1)
    = WriteProfileSectionW;

BOOL(__stdcall* Real_WriteProfileStringA)(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2)
    = WriteProfileStringA;

BOOL(__stdcall* Real_WriteProfileStringW)(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2)
    = WriteProfileStringW;

DWORD(__stdcall* Real_WriteTapemark)(HANDLE a0,
    DWORD a1,
    DWORD a2,
    BOOL a3)
    = WriteTapemark;

int(__stdcall* Real___WSAFDIsSet)(SOCKET a0,
    fd_set* a1)
    = __WSAFDIsSet;

long(__stdcall* Real__hread)(HFILE a0,
    LPVOID a1,
    long a2)
    = _hread;

long(__stdcall* Real__hwrite)(HFILE a0,
    LPCSTR a1,
    long a2)
    = _hwrite;

HFILE(__stdcall* Real__lclose)(HFILE a0)
= _lclose;

HFILE(__stdcall* Real__lcreat)(LPCSTR a0,
    int a1)
    = _lcreat;

LONG(__stdcall* Real__llseek)(HFILE a0,
    LONG a1,
    int a2)
    = _llseek;

HFILE(__stdcall* Real__lopen)(LPCSTR a0,
    int a1)
    = _lopen;

UINT(__stdcall* Real__lread)(HFILE a0,
    LPVOID a1,
    UINT a2)
    = _lread;

UINT(__stdcall* Real__lwrite)(HFILE a0,
    LPCSTR a1,
    UINT a2)
    = _lwrite;

SOCKET(__stdcall* Real_accept)(SOCKET a0,
    sockaddr* a1,
    int* a2)
    = accept;

int(__stdcall* Real_bind)(SOCKET a0,
    CONST sockaddr* a1,
    int a2)
    = bind;

int(__stdcall* Real_closesocket)(SOCKET a0)
= closesocket;

int(__stdcall* Real_connect)(SOCKET a0,
    CONST sockaddr* a1,
    int a2)
    = connect;

hostent* (__stdcall* Real_gethostbyaddr)(CONST char* a0,
    int a1,
    int a2)
    = gethostbyaddr;

hostent* (__stdcall* Real_gethostbyname)(CONST char* a0)
= gethostbyname;

int(__stdcall* Real_gethostname)(char* a0,
    int a1)
    = gethostname;

int(__stdcall* Real_getpeername)(SOCKET a0,
    sockaddr* a1,
    int* a2)
    = getpeername;

protoent* (__stdcall* Real_getprotobyname)(CONST char* a0)
= getprotobyname;

protoent* (__stdcall* Real_getprotobynumber)(int a0)
= getprotobynumber;

servent* (__stdcall* Real_getservbyname)(CONST char* a0,
    CONST char* a1)
    = getservbyname;

servent* (__stdcall* Real_getservbyport)(int a0,
    CONST char* a1)
    = getservbyport;

int(__stdcall* Real_getsockname)(SOCKET a0,
    sockaddr* a1,
    int* a2)
    = getsockname;

int(__stdcall* Real_getsockopt)(SOCKET a0,
    int a1,
    int a2,
    char* a3,
    int* a4)
    = getsockopt;

u_long(__stdcall* Real_htonl)(u_long a0)
= htonl;

u_short(__stdcall* Real_htons)(u_short a0)
= htons;

unsigned long(__stdcall* Real_inet_addr)(CONST char* a0)
= inet_addr;

char* (__stdcall* Real_inet_ntoa)(in_addr a0)
= inet_ntoa;

int(__stdcall* Real_ioctlsocket)(SOCKET a0,
    long a1,
    u_long* a2)
    = ioctlsocket;

void(__stdcall* Real_keybd_event)(BYTE a0,
    BYTE a1,
    DWORD a2,
    ULONG_PTR a3)
    = keybd_event;

int(__stdcall* Real_listen)(SOCKET a0,
    int a1)
    = listen;

void(__stdcall* Real_mouse_event)(DWORD a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    ULONG_PTR a4)
    = mouse_event;

u_long(__stdcall* Real_ntohl)(u_long a0)
= ntohl;

u_short(__stdcall* Real_ntohs)(u_short a0)
= ntohs;

int(__stdcall* Real_recv)(SOCKET a0,
    char* a1,
    int a2,
    int a3)
    = recv;

int(__stdcall* Real_recvfrom)(SOCKET a0,
    char* a1,
    int a2,
    int a3,
    sockaddr* a4,
    int* a5)
    = recvfrom;

int(__stdcall* Real_select)(int a0,
    fd_set* a1,
    fd_set* a2,
    fd_set* a3,
    CONST timeval* a4)
    = select;

int(__stdcall* Real_send)(SOCKET a0,
    CONST char* a1,
    int a2,
    int a3)
    = send;

int(__stdcall* Real_sendto)(SOCKET a0,
    CONST char* a1,
    int a2,
    int a3,
    CONST sockaddr* a4,
    int a5)
    = sendto;

int(__stdcall* Real_setsockopt)(SOCKET a0,
    int a1,
    int a2,
    CONST char* a3,
    int a4)
    = setsockopt;

int(__stdcall* Real_shutdown)(SOCKET a0,
    int a1)
    = shutdown;

SOCKET(__stdcall* Real_socket)(int a0,
    int a1,
    int a2)
    = socket;

///////////////////////////////////////////////////////////////////// Detours.
//

int __stdcall Mine_AbortDoc(HDC a0)
{
    _PrintEnter("AbortDoc(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_AbortDoc(a0);
    }
    __finally {
        _PrintExit("AbortDoc() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AbortPath(HDC a0)
{
    _PrintEnter("AbortPath(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_AbortPath(a0);
    }
    __finally {
        _PrintExit("AbortPath() -> %x\n", rv);
    };
    return rv;
}

HKL __stdcall Mine_ActivateKeyboardLayout(HKL a0,
    UINT a1)
{
    _PrintEnter("ActivateKeyboardLayout(%p,%p)\n", a0, a1);

    HKL rv = 0;
    __try {
        rv = Real_ActivateKeyboardLayout(a0, a1);
    }
    __finally {
        _PrintExit("ActivateKeyboardLayout(,) -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_AddAtomA(LPCSTR a0)
{
    _PrintEnter("AddAtomA(%hs)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_AddAtomA(a0);
    }
    __finally {
        _PrintExit("AddAtomA() -> %x\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_AddAtomW(LPCWSTR a0)
{
    _PrintEnter("AddAtomW(%ls)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_AddAtomW(a0);
    }
    __finally {
        _PrintExit("AddAtomW() -> %x\n", rv);
    };
    return rv;
}

int __stdcall Mine_AddFontResourceA(LPCSTR a0)
{
    _PrintEnter("AddFontResourceA(%hs)\n", a0);

    int rv = 0;
    __try {
        rv = Real_AddFontResourceA(a0);
    }
    __finally {
        _PrintExit("AddFontResourceA() -> %x\n", rv);
    };
    return rv;
}

int __stdcall Mine_AddFontResourceW(LPCWSTR a0)
{
    _PrintEnter("AddFontResourceW(%ls)\n", a0);

    int rv = 0;
    __try {
        rv = Real_AddFontResourceW(a0);
    }
    __finally {
        _PrintExit("AddFontResourceW() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AdjustWindowRect(LPRECT a0,
    DWORD a1,
    BOOL a2)
{
    _PrintEnter("AdjustWindowRect(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_AdjustWindowRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("AdjustWindowRect(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AdjustWindowRectEx(LPRECT a0,
    DWORD a1,
    BOOL a2,
    DWORD a3)
{
    _PrintEnter("AdjustWindowRectEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_AdjustWindowRectEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("AdjustWindowRectEx(,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AllocConsole(void)
{
    _PrintEnter("AllocConsole()\n");

    BOOL rv = 0;
    __try {
        rv = Real_AllocConsole();
    }
    __finally {
        _PrintExit("AllocConsole() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AngleArc(HDC a0,
    int a1,
    int a2,
    DWORD a3,
    FLOAT a4,
    FLOAT a5)
{
    _PrintEnter("AngleArc(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_AngleArc(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("AngleArc(,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AnimatePalette(HPALETTE a0,
    UINT a1,
    UINT a2,
    PALETTEENTRY* a3)
{
    _PrintEnter("AnimatePalette(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_AnimatePalette(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("AnimatePalette(,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AnyPopup(void)
{
    _PrintEnter("AnyPopup()\n");

    BOOL rv = 0;
    __try {
        rv = Real_AnyPopup();
    }
    __finally {
        _PrintExit("AnyPopup() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AppendMenuA(HMENU a0,
    UINT a1,
    UINT_PTR a2,
    LPCSTR a3)
{
    _PrintEnter("AppendMenuA(%p,%p,%p,%hs)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_AppendMenuA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("AppendMenuA(,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AppendMenuW(HMENU a0,
    UINT a1,
    UINT_PTR a2,
    LPCWSTR a3)
{
    _PrintEnter("AppendMenuW(%p,%p,%p,%ls)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_AppendMenuW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("AppendMenuW(,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_Arc(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
{
    _PrintEnter("Arc(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    BOOL rv = 0;
    __try {
        rv = Real_Arc(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("Arc(,,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ArcTo(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
{
    _PrintEnter("ArcTo(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    BOOL rv = 0;
    __try {
        rv = Real_ArcTo(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("ArcTo(,,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AreFileApisANSI(void)
{
    _PrintEnter("AreFileApisANSI()\n");

    BOOL rv = 0;
    __try {
        rv = Real_AreFileApisANSI();
    }
    __finally {
        _PrintExit("AreFileApisANSI() -> %x\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_ArrangeIconicWindows(HWND a0)
{
    _PrintEnter("ArrangeIconicWindows(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_ArrangeIconicWindows(a0);
    }
    __finally {
        _PrintExit("ArrangeIconicWindows() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_AttachThreadInput(DWORD a0,
    DWORD a1,
    BOOL a2)
{
    _PrintEnter("AttachThreadInput(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_AttachThreadInput(a0, a1, a2);
    }
    __finally {
        _PrintExit("AttachThreadInput(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BackupRead(HANDLE a0,
    LPBYTE a1,
    DWORD a2,
    LPDWORD a3,
    BOOL a4,
    BOOL a5,
    LPVOID* a6)
{
    _PrintEnter("BackupRead(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_BackupRead(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("BackupRead(,,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BackupSeek(HANDLE a0,
    DWORD a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPVOID* a5)
{
    _PrintEnter("BackupSeek(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_BackupSeek(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("BackupSeek(,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BackupWrite(HANDLE a0,
    LPBYTE a1,
    DWORD a2,
    LPDWORD a3,
    BOOL a4,
    BOOL a5,
    LPVOID* a6)
{
    _PrintEnter("BackupWrite(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_BackupWrite(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("BackupWrite(,,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_Beep(DWORD a0,
    DWORD a1)
{
    _PrintEnter("Beep(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_Beep(a0, a1);
    }
    __finally {
        _PrintExit("Beep(,) -> %x\n", rv);
    };
    return rv;
}

HDWP __stdcall Mine_BeginDeferWindowPos(int a0)
{
    _PrintEnter("BeginDeferWindowPos(%p)\n", a0);

    HDWP rv = 0;
    __try {
        rv = Real_BeginDeferWindowPos(a0);
    }
    __finally {
        _PrintExit("BeginDeferWindowPos() -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_BeginPaint(HWND a0,
    LPPAINTSTRUCT a1)
{
    _PrintEnter("BeginPaint(%p,%p)\n", a0, a1);

    HDC rv = 0;
    __try {
        rv = Real_BeginPaint(a0, a1);
    }
    __finally {
        _PrintExit("BeginPaint(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BeginPath(HDC a0)
{
    _PrintEnter("BeginPath(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_BeginPath(a0);
    }
    __finally {
        _PrintExit("BeginPath() -> %x\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_BeginUpdateResourceA(LPCSTR a0,
    BOOL a1)
{
    _PrintEnter("BeginUpdateResourceA(%hs,%p)\n", a0, a1);

    HANDLE rv = 0;
    __try {
        rv = Real_BeginUpdateResourceA(a0, a1);
    }
    __finally {
        _PrintExit("BeginUpdateResourceA(,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_BeginUpdateResourceW(LPCWSTR a0,
    BOOL a1)
{
    _PrintEnter("BeginUpdateResourceW(%ls,%p)\n", a0, a1);

    HANDLE rv = 0;
    __try {
        rv = Real_BeginUpdateResourceW(a0, a1);
    }
    __finally {
        _PrintExit("BeginUpdateResourceW(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_BindMoniker(IMoniker* a0,
    DWORD a1,
    CONST IID& a2,
    LPVOID* a3)
{
    _PrintEnter("BindMoniker(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_BindMoniker(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("BindMoniker(,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BitBlt(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    HDC a5,
    int a6,
    int a7,
    DWORD a8)
{
    _PrintEnter("BitBlt(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    BOOL rv = 0;
    __try {
        rv = Real_BitBlt(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("BitBlt(,,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BringWindowToTop(HWND a0)
{
    _PrintEnter("BringWindowToTop(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_BringWindowToTop(a0);
    }
    __finally {
        _PrintExit("BringWindowToTop() -> %x\n", rv);
    };
    return rv;
}

long __stdcall Mine_BroadcastSystemMessageA(DWORD a0,
    LPDWORD a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
{
    _PrintEnter("BroadcastSystemMessageA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    long rv = 0;
    __try {
        rv = Real_BroadcastSystemMessageA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("BroadcastSystemMessageA(,,,,) -> %x\n", rv);
    };
    return rv;
}

long __stdcall Mine_BroadcastSystemMessageW(DWORD a0,
    LPDWORD a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
{
    _PrintEnter("BroadcastSystemMessageW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    long rv = 0;
    __try {
        rv = Real_BroadcastSystemMessageW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("BroadcastSystemMessageW(,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BuildCommDCBA(LPCSTR a0,
    LPDCB a1)
{
    _PrintEnter("BuildCommDCBA(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_BuildCommDCBA(a0, a1);
    }
    __finally {
        _PrintExit("BuildCommDCBA(,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BuildCommDCBAndTimeoutsA(LPCSTR a0,
    LPDCB a1,
    LPCOMMTIMEOUTS a2)
{
    _PrintEnter("BuildCommDCBAndTimeoutsA(%hs,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_BuildCommDCBAndTimeoutsA(a0, a1, a2);
    }
    __finally {
        _PrintExit("BuildCommDCBAndTimeoutsA(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BuildCommDCBAndTimeoutsW(LPCWSTR a0,
    LPDCB a1,
    LPCOMMTIMEOUTS a2)
{
    _PrintEnter("BuildCommDCBAndTimeoutsW(%ls,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_BuildCommDCBAndTimeoutsW(a0, a1, a2);
    }
    __finally {
        _PrintExit("BuildCommDCBAndTimeoutsW(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_BuildCommDCBW(LPCWSTR a0,
    LPDCB a1)
{
    _PrintEnter("BuildCommDCBW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_BuildCommDCBW(a0, a1);
    }
    __finally {
        _PrintExit("BuildCommDCBW(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CLSIDFromProgID(LPCOLESTR a0,
    LPGUID a1)
{
    _PrintEnter("CLSIDFromProgID(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CLSIDFromProgID(a0, a1);
    }
    __finally {
        _PrintExit("CLSIDFromProgID(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CLSIDFromString(LPOLESTR a0,
    LPGUID a1)
{
    _PrintEnter("CLSIDFromString(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CLSIDFromString(a0, a1);
    }
    __finally {
        _PrintExit("CLSIDFromString(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CallMsgFilterA(LPMSG a0,
    int a1)
{
    _PrintEnter("CallMsgFilterA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_CallMsgFilterA(a0, a1);
    }
    __finally {
        _PrintExit("CallMsgFilterA(,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CallMsgFilterW(LPMSG a0,
    int a1)
{
    _PrintEnter("CallMsgFilterW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_CallMsgFilterW(a0, a1);
    }
    __finally {
        _PrintExit("CallMsgFilterW(,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CallNamedPipeA(LPCSTR a0,
    LPVOID a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4,
    LPDWORD a5,
    DWORD a6)
{
    _PrintEnter("CallNamedPipeA(%hs,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_CallNamedPipeA(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CallNamedPipeA(,,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CallNamedPipeW(LPCWSTR a0,
    LPVOID a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4,
    LPDWORD a5,
    DWORD a6)
{
    _PrintEnter("CallNamedPipeW(%ls,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_CallNamedPipeW(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CallNamedPipeW(,,,,,,) -> %x\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_CallNextHookEx(HHOOK a0,
    int a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("CallNextHookEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    LRESULT rv = 0;
    __try {
        rv = Real_CallNextHookEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CallNextHookEx(,,,) -> %x\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_CallWindowProcA(WNDPROC a0,
    HWND a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
{
    _PrintEnter("CallWindowProcA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LRESULT rv = 0;
    __try {
        rv = Real_CallWindowProcA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CallWindowProcA(,,,,) -> %x\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_CallWindowProcW(WNDPROC a0,
    HWND a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
{
    _PrintEnter("CallWindowProcW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LRESULT rv = 0;
    __try {
        rv = Real_CallWindowProcW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CallWindowProcW(,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CancelDC(HDC a0)
{
    _PrintEnter("CancelDC(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CancelDC(a0);
    }
    __finally {
        _PrintExit("CancelDC() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CancelIo(HANDLE a0)
{
    _PrintEnter("CancelIo(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CancelIo(a0);
    }
    __finally {
        _PrintExit("CancelIo() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CancelWaitableTimer(HANDLE a0)
{
    _PrintEnter("CancelWaitableTimer(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CancelWaitableTimer(a0);
    }
    __finally {
        _PrintExit("CancelWaitableTimer() -> %x\n", rv);
    };
    return rv;
}

WORD __stdcall Mine_CascadeWindows(HWND a0,
    UINT a1,
    RECT* a2,
    UINT a3,
    struct HWND__** a4)
{
    _PrintEnter("CascadeWindows(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    WORD rv = 0;
    __try {
        rv = Real_CascadeWindows(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CascadeWindows(,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ChangeClipboardChain(HWND a0,
    HWND a1)
{
    _PrintEnter("ChangeClipboardChain(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ChangeClipboardChain(a0, a1);
    }
    __finally {
        _PrintExit("ChangeClipboardChain(,) -> %x\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_ChangeDisplaySettingsA(LPDEVMODEA a0,
    DWORD a1)
{
    _PrintEnter("ChangeDisplaySettingsA(%p,%p)\n", a0, a1);

    LONG rv = 0;
    __try {
        rv = Real_ChangeDisplaySettingsA(a0, a1);
    }
    __finally {
        _PrintExit("ChangeDisplaySettingsA(,) -> %x\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_ChangeDisplaySettingsExA(LPCSTR a0,
    LPDEVMODEA a1,
    HWND a2,
    DWORD a3,
    LPVOID a4)
{
    _PrintEnter("ChangeDisplaySettingsExA(%hs,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LONG rv = 0;
    __try {
        rv = Real_ChangeDisplaySettingsExA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ChangeDisplaySettingsExA(,,,,) -> %x\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_ChangeDisplaySettingsExW(LPCWSTR a0,
    LPDEVMODEW a1,
    HWND a2,
    DWORD a3,
    LPVOID a4)
{
    _PrintEnter("ChangeDisplaySettingsExW(%ls,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LONG rv = 0;
    __try {
        rv = Real_ChangeDisplaySettingsExW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ChangeDisplaySettingsExW(,,,,) -> %x\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_ChangeDisplaySettingsW(LPDEVMODEW a0,
    DWORD a1)
{
    _PrintEnter("ChangeDisplaySettingsW(%p,%p)\n", a0, a1);

    LONG rv = 0;
    __try {
        rv = Real_ChangeDisplaySettingsW(a0, a1);
    }
    __finally {
        _PrintExit("ChangeDisplaySettingsW(,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ChangeMenuA(HMENU a0,
    UINT a1,
    LPCSTR a2,
    UINT a3,
    UINT a4)
{
    _PrintEnter("ChangeMenuA(%p,%p,%hs,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ChangeMenuA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ChangeMenuA(,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ChangeMenuW(HMENU a0,
    UINT a1,
    LPCWSTR a2,
    UINT a3,
    UINT a4)
{
    _PrintEnter("ChangeMenuW(%p,%p,%ls,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ChangeMenuW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ChangeMenuW(,,,,) -> %x\n", rv);
    };
    return rv;
}

LPSTR __stdcall Mine_CharLowerA(LPSTR a0)
{
    _PrintEnter("CharLowerA(%hs)\n", a0);

    LPSTR rv = 0;
    __try {
        rv = Real_CharLowerA(a0);
    }
    __finally {
        _PrintExit("CharLowerA(%hs) -> %hs\n", a0, rv);
    };
    return rv;
}

DWORD __stdcall Mine_CharLowerBuffA(LPSTR a0,
    DWORD a1)
{
    _PrintEnter("CharLowerBuffA(%hs,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_CharLowerBuffA(a0, a1);
    }
    __finally {
        _PrintExit("CharLowerBuffA(%hs,) -> %x\n", a0, rv);
    };
    return rv;
}

DWORD __stdcall Mine_CharLowerBuffW(LPWSTR a0,
    DWORD a1)
{
    _PrintEnter("CharLowerBuffW(%ls,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_CharLowerBuffW(a0, a1);
    }
    __finally {
        _PrintExit("CharLowerBuffW(%ls,) -> %x\n", a0, rv);
    };
    return rv;
}

LPWSTR __stdcall Mine_CharLowerW(LPWSTR a0)
{
    _PrintEnter("CharLowerW(%ls)\n", a0);

    LPWSTR rv = 0;
    __try {
        rv = Real_CharLowerW(a0);
    }
    __finally {
        _PrintExit("CharLowerW(%ls) -> %ls\n", a0, rv);
    };
    return rv;
}

LPSTR __stdcall Mine_CharNextA(LPCSTR a0)
{
    _PrintEnter("CharNextA(%hs)\n", a0);

    LPSTR rv = 0;
    __try {
        rv = Real_CharNextA(a0);
    }
    __finally {
        _PrintExit("CharNextA() -> %hs\n", rv);
    };
    return rv;
}

LPSTR __stdcall Mine_CharNextExA(WORD a0,
    LPCSTR a1,
    DWORD a2)
{
    _PrintEnter("CharNextExA(%p,%hs,%p)\n", a0, a1, a2);

    LPSTR rv = 0;
    __try {
        rv = Real_CharNextExA(a0, a1, a2);
    }
    __finally {
        _PrintExit("CharNextExA(,,) -> %hs\n", rv);
    };
    return rv;
}

LPWSTR __stdcall Mine_CharNextW(LPCWSTR a0)
{
    _PrintEnter("CharNextW(%ls)\n", a0);

    LPWSTR rv = 0;
    __try {
        rv = Real_CharNextW(a0);
    }
    __finally {
        _PrintExit("CharNextW() -> %ls\n", rv);
    };
    return rv;
}

LPSTR __stdcall Mine_CharPrevA(LPCSTR a0,
    LPCSTR a1)
{
    _PrintEnter("CharPrevA(%hs,%hs)\n", a0, a1);

    LPSTR rv = 0;
    __try {
        rv = Real_CharPrevA(a0, a1);
    }
    __finally {
        _PrintExit("CharPrevA(,) -> %hs\n", rv);
    };
    return rv;
}

LPSTR __stdcall Mine_CharPrevExA(WORD a0,
    LPCSTR a1,
    LPCSTR a2,
    DWORD a3)
{
    _PrintEnter("CharPrevExA(%p,%hs,%hs,%p)\n", a0, a1, a2, a3);

    LPSTR rv = 0;
    __try {
        rv = Real_CharPrevExA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CharPrevExA(,,,) -> %hs\n", rv);
    };
    return rv;
}

LPWSTR __stdcall Mine_CharPrevW(LPCWSTR a0,
    LPCWSTR a1)
{
    _PrintEnter("CharPrevW(%ls,%ls)\n", a0, a1);

    LPWSTR rv = 0;
    __try {
        rv = Real_CharPrevW(a0, a1);
    }
    __finally {
        _PrintExit("CharPrevW(,) -> %ls\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CharToOemA(LPCSTR a0,
    LPSTR a1)
{
    _PrintEnter("CharToOemA(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_CharToOemA(a0, a1);
    }
    __finally {
        _PrintExit("CharToOemA(,%hs) -> %x\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_CharToOemBuffA(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("CharToOemBuffA(%hs,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CharToOemBuffA(a0, a1, a2);
    }
    __finally {
        _PrintExit("CharToOemBuffA(,%hs,) -> %x\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_CharToOemBuffW(LPCWSTR a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("CharToOemBuffW(%ls,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CharToOemBuffW(a0, a1, a2);
    }
    __finally {
        _PrintExit("CharToOemBuffW(,%hs,) -> %x\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_CharToOemW(LPCWSTR a0,
    LPSTR a1)
{
    _PrintEnter("CharToOemW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_CharToOemW(a0, a1);
    }
    __finally {
        _PrintExit("CharToOemW(,%hs) -> %x\n", a1, rv);
    };
    return rv;
}

LPSTR __stdcall Mine_CharUpperA(LPSTR a0)
{
    _PrintEnter("CharUpperA(%hs)\n", a0);

    LPSTR rv = 0;
    __try {
        rv = Real_CharUpperA(a0);
    }
    __finally {
        _PrintExit("CharUpperA(%hs) -> %hs\n", a0, rv);
    };
    return rv;
}

DWORD __stdcall Mine_CharUpperBuffA(LPSTR a0,
    DWORD a1)
{
    _PrintEnter("CharUpperBuffA(%hs,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_CharUpperBuffA(a0, a1);
    }
    __finally {
        _PrintExit("CharUpperBuffA(%hs,) -> %x\n", a0, rv);
    };
    return rv;
}

DWORD __stdcall Mine_CharUpperBuffW(LPWSTR a0,
    DWORD a1)
{
    _PrintEnter("CharUpperBuffW(%ls,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_CharUpperBuffW(a0, a1);
    }
    __finally {
        _PrintExit("CharUpperBuffW(%ls,) -> %x\n", a0, rv);
    };
    return rv;
}

LPWSTR __stdcall Mine_CharUpperW(LPWSTR a0)
{
    _PrintEnter("CharUpperW(%ls)\n", a0);

    LPWSTR rv = 0;
    __try {
        rv = Real_CharUpperW(a0);
    }
    __finally {
        _PrintExit("CharUpperW(%ls) -> %ls\n", a0, rv);
    };
    return rv;
}

BOOL __stdcall Mine_CheckColorsInGamut(
    HDC a0,
#ifdef GDIPLUS_TS_QUERYVER
    LPRGBTRIPLE a1,
#else
    LPVOID a1,
#endif
    LPVOID a2,
    DWORD a3
)
{
    _PrintEnter("CheckColorsInGamut(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_CheckColorsInGamut(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CheckColorsInGamut(,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CheckDlgButton(HWND a0,
    int a1,
    UINT a2)
{
    _PrintEnter("CheckDlgButton(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CheckDlgButton(a0, a1, a2);
    }
    __finally {
        _PrintExit("CheckDlgButton(,,) -> %x\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_CheckMenuItem(HMENU a0,
    UINT a1,
    UINT a2)
{
    _PrintEnter("CheckMenuItem(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_CheckMenuItem(a0, a1, a2);
    }
    __finally {
        _PrintExit("CheckMenuItem(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CheckMenuRadioItem(HMENU a0,
    UINT a1,
    UINT a2,
    UINT a3,
    UINT a4)
{
    _PrintEnter("CheckMenuRadioItem(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_CheckMenuRadioItem(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CheckMenuRadioItem(,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CheckRadioButton(HWND a0,
    int a1,
    int a2,
    int a3)
{
    _PrintEnter("CheckRadioButton(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_CheckRadioButton(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CheckRadioButton(,,,) -> %x\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_ChildWindowFromPoint(HWND a0,
    POINT a1)
{
    _PrintEnter("ChildWindowFromPoint(%p,%p)\n", a0, a1);

    HWND rv = 0;
    __try {
        rv = Real_ChildWindowFromPoint(a0, a1);
    }
    __finally {
        _PrintExit("ChildWindowFromPoint(,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_ChildWindowFromPointEx(HWND a0,
    POINT a1,
    UINT a2)
{
    _PrintEnter("ChildWindowFromPointEx(%p,%p,%p)\n", a0, a1, a2);

    HWND rv = 0;
    __try {
        rv = Real_ChildWindowFromPointEx(a0, a1, a2);
    }
    __finally {
        _PrintExit("ChildWindowFromPointEx(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ChoosePixelFormat(HDC a0,
    PIXELFORMATDESCRIPTOR* a1)
{
    _PrintEnter("ChoosePixelFormat(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_ChoosePixelFormat(a0, a1);
    }
    __finally {
        _PrintExit("ChoosePixelFormat(,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_Chord(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
{
    _PrintEnter("Chord(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    BOOL rv = 0;
    __try {
        rv = Real_Chord(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("Chord(,,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ClearCommBreak(HANDLE a0)
{
    _PrintEnter("ClearCommBreak(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_ClearCommBreak(a0);
    }
    __finally {
        _PrintExit("ClearCommBreak() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ClearCommError(HANDLE a0,
    LPDWORD a1,
    LPCOMSTAT a2)
{
    _PrintEnter("ClearCommError(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_ClearCommError(a0, a1, a2);
    }
    __finally {
        _PrintExit("ClearCommError(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ClientToScreen(HWND a0,
    POINT* a1)
{
    _PrintEnter("ClientToScreen(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ClientToScreen(a0, a1);
    }
    __finally {
        _PrintExit("ClientToScreen(,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ClipCursor(RECT* a0)
{
    _PrintEnter("ClipCursor(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_ClipCursor(a0);
    }
    __finally {
        _PrintExit("ClipCursor() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CloseClipboard(void)
{
    _PrintEnter("CloseClipboard()\n");

    BOOL rv = 0;
    __try {
        rv = Real_CloseClipboard();
    }
    __finally {
        _PrintExit("CloseClipboard() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CloseDesktop(HDESK a0)
{
    _PrintEnter("CloseDesktop(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CloseDesktop(a0);
    }
    __finally {
        _PrintExit("CloseDesktop() -> %x\n", rv);
    };
    return rv;
}

HENHMETAFILE __stdcall Mine_CloseEnhMetaFile(HDC a0)
{
    _PrintEnter("CloseEnhMetaFile(%p)\n", a0);

    HENHMETAFILE rv = 0;
    __try {
        rv = Real_CloseEnhMetaFile(a0);
    }
    __finally {
        _PrintExit("CloseEnhMetaFile() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CloseFigure(HDC a0)
{
    _PrintEnter("CloseFigure(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CloseFigure(a0);
    }
    __finally {
        _PrintExit("CloseFigure() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CloseHandle(HANDLE a0)
{
    _PrintEnter("CloseHandle(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CloseHandle(a0);
    }
    __finally {
        _PrintExit("CloseHandle() -> %x\n", rv);
    };
    return rv;
}

HMETAFILE __stdcall Mine_CloseMetaFile(HDC a0)
{
    _PrintEnter("CloseMetaFile(%p)\n", a0);

    HMETAFILE rv = 0;
    __try {
        rv = Real_CloseMetaFile(a0);
    }
    __finally {
        _PrintExit("CloseMetaFile() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CloseWindow(HWND a0)
{
    _PrintEnter("CloseWindow(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CloseWindow(a0);
    }
    __finally {
        _PrintExit("CloseWindow() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CloseWindowStation(HWINSTA a0)
{
    _PrintEnter("CloseWindowStation(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CloseWindowStation(a0);
    }
    __finally {
        _PrintExit("CloseWindowStation() -> %x\n", rv);
    };
    return rv;
}

ULONG __stdcall Mine_CoAddRefServerProcess(void)
{
    _PrintEnter("CoAddRefServerProcess()\n");

    ULONG rv = 0;
    __try {
        rv = Real_CoAddRefServerProcess();
    }
    __finally {
        _PrintExit("CoAddRefServerProcess() -> %x\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_CoBuildVersion(void)
{
    _PrintEnter("CoBuildVersion()\n");

    DWORD rv = 0;
    __try {
        rv = Real_CoBuildVersion();
    }
    __finally {
        _PrintExit("CoBuildVersion() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoCopyProxy(IUnknown* a0,
    IUnknown** a1)
{
    _PrintEnter("CoCopyProxy(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoCopyProxy(a0, a1);
    }
    __finally {
        _PrintExit("CoCopyProxy(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoCreateFreeThreadedMarshaler(LPUNKNOWN a0,
    LPUNKNOWN* a1)
{
    _PrintEnter("CoCreateFreeThreadedMarshaler(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoCreateFreeThreadedMarshaler(a0, a1);
    }
    __finally {
        _PrintExit("CoCreateFreeThreadedMarshaler(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoCreateGuid(GUID* a0)
{
    _PrintEnter("CoCreateGuid(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CoCreateGuid(a0);
    }
    __finally {
        _PrintExit("CoCreateGuid() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoCreateInstance(CONST IID& a0,
    LPUNKNOWN a1,
    DWORD a2,
    CONST IID& a3,
    LPVOID* a4)
{
    _PrintEnter("CoCreateInstance(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HRESULT rv = 0;
    __try {
        rv = Real_CoCreateInstance(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CoCreateInstance(,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoCreateInstanceEx(CONST IID& a0,
    IUnknown* a1,
    DWORD a2,
    COSERVERINFO* a3,
    DWORD a4,
    MULTI_QI* a5)
{
    _PrintEnter("CoCreateInstanceEx(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HRESULT rv = 0;
    __try {
        rv = Real_CoCreateInstanceEx(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CoCreateInstanceEx(,,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoDisconnectObject(LPUNKNOWN a0,
    DWORD a1)
{
    _PrintEnter("CoDisconnectObject(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoDisconnectObject(a0, a1);
    }
    __finally {
        _PrintExit("CoDisconnectObject(,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CoDosDateTimeToFileTime(WORD a0,
    WORD a1,
    FILETIME* a2)
{
    _PrintEnter("CoDosDateTimeToFileTime(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CoDosDateTimeToFileTime(a0, a1, a2);
    }
    __finally {
        _PrintExit("CoDosDateTimeToFileTime(,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoFileTimeNow(FILETIME* a0)
{
    _PrintEnter("CoFileTimeNow(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CoFileTimeNow(a0);
    }
    __finally {
        _PrintExit("CoFileTimeNow() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CoFileTimeToDosDateTime(FILETIME* a0,
    LPWORD a1,
    LPWORD a2)
{
    _PrintEnter("CoFileTimeToDosDateTime(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CoFileTimeToDosDateTime(a0, a1, a2);
    }
    __finally {
        _PrintExit("CoFileTimeToDosDateTime(,,) -> %x\n", rv);
    };
    return rv;
}

void __stdcall Mine_CoFreeAllLibraries(void)
{
    _PrintEnter("CoFreeAllLibraries()\n");

    __try {
        Real_CoFreeAllLibraries();
    }
    __finally {
        _PrintExit("CoFreeAllLibraries() ->\n");
    };
}

void __stdcall Mine_CoFreeLibrary(HINSTANCE a0)
{
    _PrintEnter("CoFreeLibrary(%p)\n", a0);

    __try {
        Real_CoFreeLibrary(a0);
    }
    __finally {
        _PrintExit("CoFreeLibrary() ->\n");
    };
}

void __stdcall Mine_CoFreeUnusedLibraries(void)
{
    _PrintEnter("CoFreeUnusedLibraries()\n");

    __try {
        Real_CoFreeUnusedLibraries();
    }
    __finally {
        _PrintExit("CoFreeUnusedLibraries() ->\n");
    };
}

HRESULT __stdcall Mine_CoGetCallContext(CONST IID& a0,
    void** a1)
{
    _PrintEnter("CoGetCallContext(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetCallContext(a0, a1);
    }
    __finally {
        _PrintExit("CoGetCallContext(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetClassObject(CONST IID& a0,
    DWORD a1,
    LPVOID a2,
    CONST IID& a3,
    LPVOID* a4)
{
    _PrintEnter("CoGetClassObject(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetClassObject(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CoGetClassObject(,,,,) -> %x\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_CoGetCurrentProcess(void)
{
    _PrintEnter("CoGetCurrentProcess()\n");

    DWORD rv = 0;
    __try {
        rv = Real_CoGetCurrentProcess();
    }
    __finally {
        _PrintExit("CoGetCurrentProcess() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetInstanceFromFile(COSERVERINFO* a0,
    CLSID* a1,
    IUnknown* a2,
    DWORD a3,
    DWORD a4,
    OLECHAR* a5,
    DWORD a6,
    MULTI_QI* a7)
{
    _PrintEnter("CoGetInstanceFromFile(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetInstanceFromFile(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("CoGetInstanceFromFile(,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetInstanceFromIStorage(COSERVERINFO* a0,
    CLSID* a1,
    IUnknown* a2,
    DWORD a3,
    IStorage* a4,
    DWORD a5,
    MULTI_QI* a6)
{
    _PrintEnter("CoGetInstanceFromIStorage(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetInstanceFromIStorage(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CoGetInstanceFromIStorage(,,,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetInterfaceAndReleaseStream(LPSTREAM a0,
    CONST IID& a1,
    LPVOID* a2)
{
    _PrintEnter("CoGetInterfaceAndReleaseStream(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetInterfaceAndReleaseStream(a0, a1, a2);
    }
    __finally {
        _PrintExit("CoGetInterfaceAndReleaseStream(,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetMalloc(DWORD a0,
    IMalloc** a1)
{
    _PrintEnter("CoGetMalloc(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetMalloc(a0, a1);
    }
    __finally {
        _PrintExit("CoGetMalloc(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetMarshalSizeMax(ULONG* a0,
    CONST IID& a1,
    LPUNKNOWN a2,
    DWORD a3,
    LPVOID a4,
    DWORD a5)
{
    _PrintEnter("CoGetMarshalSizeMax(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetMarshalSizeMax(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CoGetMarshalSizeMax(,,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetObject(LPCWSTR a0,
    BIND_OPTS* a1,
    CONST IID& a2,
    void** a3)
{
    _PrintEnter("CoGetObject(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetObject(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CoGetObject(,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetPSClsid(CONST IID& a0,
    CLSID* a1)
{
    _PrintEnter("CoGetPSClsid(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetPSClsid(a0, a1);
    }
    __finally {
        _PrintExit("CoGetPSClsid(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetStandardMarshal(CONST IID& a0,
    LPUNKNOWN a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4,
    IMarshal** a5)
{
    _PrintEnter("CoGetStandardMarshal(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetStandardMarshal(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CoGetStandardMarshal(,,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetStdMarshalEx(LPUNKNOWN a0,
    DWORD a1,
    LPUNKNOWN* a2)
{
    _PrintEnter("CoGetStdMarshalEx(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetStdMarshalEx(a0, a1, a2);
    }
    __finally {
        _PrintExit("CoGetStdMarshalEx(,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoGetTreatAsClass(CONST IID& a0,
    LPGUID a1)
{
    _PrintEnter("CoGetTreatAsClass(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoGetTreatAsClass(a0, a1);
    }
    __finally {
        _PrintExit("CoGetTreatAsClass(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoImpersonateClient(void)
{
    _PrintEnter("CoImpersonateClient()\n");

    HRESULT rv = 0;
    __try {
        rv = Real_CoImpersonateClient();
    }
    __finally {
        _PrintExit("CoImpersonateClient() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoInitialize(LPVOID a0)
{
    _PrintEnter("CoInitialize(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CoInitialize(a0);
    }
    __finally {
        _PrintExit("CoInitialize() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoInitializeEx(LPVOID a0,
    DWORD a1)
{
    _PrintEnter("CoInitializeEx(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoInitializeEx(a0, a1);
    }
    __finally {
        _PrintExit("CoInitializeEx(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoInitializeSecurity(PSECURITY_DESCRIPTOR a0,
    LONG a1,
    SOLE_AUTHENTICATION_SERVICE* a2,
    void* a3,
    DWORD a4,
    DWORD a5,
    void* a6,
    DWORD a7,
    void* a8)
{
    _PrintEnter("CoInitializeSecurity(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    HRESULT rv = 0;
    __try {
        rv = Real_CoInitializeSecurity(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("CoInitializeSecurity(,,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CoIsHandlerConnected(LPUNKNOWN a0)
{
    _PrintEnter("CoIsHandlerConnected(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CoIsHandlerConnected(a0);
    }
    __finally {
        _PrintExit("CoIsHandlerConnected() -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CoIsOle1Class(CONST IID& a0)
{
    _PrintEnter("CoIsOle1Class(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CoIsOle1Class(a0);
    }
    __finally {
        _PrintExit("CoIsOle1Class() -> %x\n", rv);
    };
    return rv;
}

HINSTANCE __stdcall Mine_CoLoadLibrary(LPOLESTR a0,
    BOOL a1)
{
    _PrintEnter("CoLoadLibrary(%p,%p)\n", a0, a1);

    HINSTANCE rv = 0;
    __try {
        rv = Real_CoLoadLibrary(a0, a1);
    }
    __finally {
        _PrintExit("CoLoadLibrary(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoLockObjectExternal(LPUNKNOWN a0,
    BOOL a1,
    BOOL a2)
{
    _PrintEnter("CoLockObjectExternal(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_CoLockObjectExternal(a0, a1, a2);
    }
    __finally {
        _PrintExit("CoLockObjectExternal(,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoMarshalHresult(LPSTREAM a0,
    HRESULT a1)
{
    _PrintEnter("CoMarshalHresult(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoMarshalHresult(a0, a1);
    }
    __finally {
        _PrintExit("CoMarshalHresult(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoMarshalInterThreadInterfaceInStream(CONST IID& a0,
    LPUNKNOWN a1,
    LPSTREAM* a2)
{
    _PrintEnter("CoMarshalInterThreadInterfaceInStream(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_CoMarshalInterThreadInterfaceInStream(a0, a1, a2);
    }
    __finally {
        _PrintExit("CoMarshalInterThreadInterfaceInStream(,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoMarshalInterface(LPSTREAM a0,
    CONST IID& a1,
    LPUNKNOWN a2,
    DWORD a3,
    LPVOID a4,
    DWORD a5)
{
    _PrintEnter("CoMarshalInterface(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HRESULT rv = 0;
    __try {
        rv = Real_CoMarshalInterface(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CoMarshalInterface(,,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoQueryAuthenticationServices(DWORD* a0,
    SOLE_AUTHENTICATION_SERVICE** a1)
{
    _PrintEnter("CoQueryAuthenticationServices(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoQueryAuthenticationServices(a0, a1);
    }
    __finally {
        _PrintExit("CoQueryAuthenticationServices(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoQueryClientBlanket(DWORD* a0,
    DWORD* a1,
    OLECHAR** a2,
    DWORD* a3,
    DWORD* a4,
    RPC_AUTHZ_HANDLE* a5,
    DWORD* a6)
{
    _PrintEnter("CoQueryClientBlanket(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_CoQueryClientBlanket(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CoQueryClientBlanket(,,,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoQueryProxyBlanket(IUnknown* a0,
    DWORD* a1,
    DWORD* a2,
    OLECHAR** a3,
    DWORD* a4,
    DWORD* a5,
    RPC_AUTH_IDENTITY_HANDLE* a6,
    DWORD* a7)
{
    _PrintEnter("CoQueryProxyBlanket(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HRESULT rv = 0;
    __try {
        rv = Real_CoQueryProxyBlanket(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("CoQueryProxyBlanket(,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoRegisterChannelHook(CONST GUID& a0,
    IChannelHook* a1)
{
    _PrintEnter("CoRegisterChannelHook(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoRegisterChannelHook(a0, a1);
    }
    __finally {
        _PrintExit("CoRegisterChannelHook(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoRegisterClassObject(CONST IID& a0,
    LPUNKNOWN a1,
    DWORD a2,
    DWORD a3,
    LPDWORD a4)
{
    _PrintEnter("CoRegisterClassObject(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HRESULT rv = 0;
    __try {
        rv = Real_CoRegisterClassObject(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CoRegisterClassObject(,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoRegisterMallocSpy(IMallocSpy* a0)
{
    _PrintEnter("CoRegisterMallocSpy(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CoRegisterMallocSpy(a0);
    }
    __finally {
        _PrintExit("CoRegisterMallocSpy() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoRegisterMessageFilter(LPMESSAGEFILTER a0,
    LPMESSAGEFILTER* a1)
{
    _PrintEnter("CoRegisterMessageFilter(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoRegisterMessageFilter(a0, a1);
    }
    __finally {
        _PrintExit("CoRegisterMessageFilter(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoRegisterPSClsid(CONST IID& a0,
    CONST IID& a1)
{
    _PrintEnter("CoRegisterPSClsid(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoRegisterPSClsid(a0, a1);
    }
    __finally {
        _PrintExit("CoRegisterPSClsid(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoRegisterSurrogate(LPSURROGATE a0)
{
    _PrintEnter("CoRegisterSurrogate(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CoRegisterSurrogate(a0);
    }
    __finally {
        _PrintExit("CoRegisterSurrogate() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoReleaseMarshalData(LPSTREAM a0)
{
    _PrintEnter("CoReleaseMarshalData(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CoReleaseMarshalData(a0);
    }
    __finally {
        _PrintExit("CoReleaseMarshalData() -> %x\n", rv);
    };
    return rv;
}

ULONG __stdcall Mine_CoReleaseServerProcess(void)
{
    _PrintEnter("CoReleaseServerProcess()\n");

    ULONG rv = 0;
    __try {
        rv = Real_CoReleaseServerProcess();
    }
    __finally {
        _PrintExit("CoReleaseServerProcess() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoResumeClassObjects(void)
{
    _PrintEnter("CoResumeClassObjects()\n");

    HRESULT rv = 0;
    __try {
        rv = Real_CoResumeClassObjects();
    }
    __finally {
        _PrintExit("CoResumeClassObjects() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoRevertToSelf(void)
{
    _PrintEnter("CoRevertToSelf()\n");

    HRESULT rv = 0;
    __try {
        rv = Real_CoRevertToSelf();
    }
    __finally {
        _PrintExit("CoRevertToSelf() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoRevokeClassObject(DWORD a0)
{
    _PrintEnter("CoRevokeClassObject(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CoRevokeClassObject(a0);
    }
    __finally {
        _PrintExit("CoRevokeClassObject() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoRevokeMallocSpy(void)
{
    _PrintEnter("CoRevokeMallocSpy()\n");

    HRESULT rv = 0;
    __try {
        rv = Real_CoRevokeMallocSpy();
    }
    __finally {
        _PrintExit("CoRevokeMallocSpy() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoSetProxyBlanket(IUnknown* a0,
    DWORD a1,
    DWORD a2,
    OLECHAR* a3,
    DWORD a4,
    DWORD a5,
    RPC_AUTH_IDENTITY_HANDLE a6,
    DWORD a7)
{
    _PrintEnter("CoSetProxyBlanket(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HRESULT rv = 0;
    __try {
        rv = Real_CoSetProxyBlanket(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("CoSetProxyBlanket(,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoSuspendClassObjects(void)
{
    _PrintEnter("CoSuspendClassObjects()\n");

    HRESULT rv = 0;
    __try {
        rv = Real_CoSuspendClassObjects();
    }
    __finally {
        _PrintExit("CoSuspendClassObjects() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoSwitchCallContext(IUnknown* a0,
    IUnknown** a1)
{
    _PrintEnter("CoSwitchCallContext(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoSwitchCallContext(a0, a1);
    }
    __finally {
        _PrintExit("CoSwitchCallContext(,) -> %x\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_CoTaskMemAlloc(SIZE_T a0)
{
    _PrintEnter("CoTaskMemAlloc(%p)\n", a0);

    LPVOID rv = 0;
    __try {
        rv = Real_CoTaskMemAlloc(a0);
    }
    __finally {
        _PrintExit("CoTaskMemAlloc() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_CoTaskMemFree(LPVOID a0)
{
    _PrintEnter("CoTaskMemFree(%p)\n", a0);

    __try {
        Real_CoTaskMemFree(a0);
    }
    __finally {
        _PrintExit("CoTaskMemFree() ->\n");
    };
}

LPVOID __stdcall Mine_CoTaskMemRealloc(LPVOID a0,
    SIZE_T a1)
{
    _PrintEnter("CoTaskMemRealloc(%p,%p)\n", a0, a1);

    LPVOID rv = 0;
    __try {
        rv = Real_CoTaskMemRealloc(a0, a1);
    }
    __finally {
        _PrintExit("CoTaskMemRealloc(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoTreatAsClass(CONST IID& a0,
    CONST IID& a1)
{
    _PrintEnter("CoTreatAsClass(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoTreatAsClass(a0, a1);
    }
    __finally {
        _PrintExit("CoTreatAsClass(,) -> %x\n", rv);
    };
    return rv;
}

void __stdcall Mine_CoUninitialize(void)
{
    _PrintEnter("CoUninitialize()\n");

    __try {
        Real_CoUninitialize();
    }
    __finally {
        _PrintExit("CoUninitialize() ->\n");
    };
}

HRESULT __stdcall Mine_CoUnmarshalHresult(LPSTREAM a0,
    HRESULT* a1)
{
    _PrintEnter("CoUnmarshalHresult(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CoUnmarshalHresult(a0, a1);
    }
    __finally {
        _PrintExit("CoUnmarshalHresult(,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CoUnmarshalInterface(LPSTREAM a0,
    CONST IID& a1,
    LPVOID* a2)
{
    _PrintEnter("CoUnmarshalInterface(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_CoUnmarshalInterface(a0, a1, a2);
    }
    __finally {
        _PrintExit("CoUnmarshalInterface(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ColorMatchToTarget(HDC a0,
    HDC a1,
    DWORD a2)
{
    _PrintEnter("ColorMatchToTarget(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_ColorMatchToTarget(a0, a1, a2);
    }
    __finally {
        _PrintExit("ColorMatchToTarget(,,) -> %x\n", rv);
    };
    return rv;
}

int __stdcall Mine_CombineRgn(HRGN a0,
    HRGN a1,
    HRGN a2,
    int a3)
{
    _PrintEnter("CombineRgn(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_CombineRgn(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CombineRgn(,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CombineTransform(XFORM* a0,
    XFORM* a1,
    XFORM* a2)
{
    _PrintEnter("CombineTransform(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CombineTransform(a0, a1, a2);
    }
    __finally {
        _PrintExit("CombineTransform(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CommConfigDialogA(LPCSTR a0,
    HWND a1,
    LPCOMMCONFIG a2)
{
    _PrintEnter("CommConfigDialogA(%hs,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CommConfigDialogA(a0, a1, a2);
    }
    __finally {
        _PrintExit("CommConfigDialogA(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CommConfigDialogW(LPCWSTR a0,
    HWND a1,
    LPCOMMCONFIG a2)
{
    _PrintEnter("CommConfigDialogW(%ls,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CommConfigDialogW(a0, a1, a2);
    }
    __finally {
        _PrintExit("CommConfigDialogW(,,) -> %x\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_CompareFileTime(FILETIME* a0,
    FILETIME* a1)
{
    _PrintEnter("CompareFileTime(%p,%p)\n", a0, a1);

    LONG rv = 0;
    __try {
        rv = Real_CompareFileTime(a0, a1);
    }
    __finally {
        _PrintExit("CompareFileTime(,) -> %x\n", rv);
    };
    return rv;
}

int __stdcall Mine_CompareStringA(LCID a0,
    DWORD a1,
    LPCSTR a2,
    int a3,
    LPCSTR a4,
    int a5)
{
    _PrintEnter("CompareStringA(%p,%p,%hs,%p,%hs,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_CompareStringA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CompareStringA(,,,,,) -> %x\n", rv);
    };
    return rv;
}

int __stdcall Mine_CompareStringW(LCID a0,
    DWORD a1,
    LPCWSTR a2,
    int a3,
    LPCWSTR a4,
    int a5)
{
    _PrintEnter("CompareStringW(%p,%p,%ls,%p,%ls,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_CompareStringW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CompareStringW(,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ConnectNamedPipe(HANDLE a0,
    LPOVERLAPPED a1)
{
    _PrintEnter("ConnectNamedPipe(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ConnectNamedPipe(a0, a1);
    }
    __finally {
        _PrintExit("ConnectNamedPipe(,) -> %x\n", rv);
    };
    return rv;
}

#if !defined(DETOURS_ARM)
BOOL __stdcall Mine_ContinueDebugEvent(DWORD a0,
    DWORD a1,
    DWORD a2)
{
    _PrintEnter("ContinueDebugEvent(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_ContinueDebugEvent(a0, a1, a2);
    }
    __finally {
        _PrintExit("ContinueDebugEvent(,,) -> %x\n", rv);
    };
    return rv;
}
#endif // !DETOURS_ARM

LCID __stdcall Mine_ConvertDefaultLocale(LCID a0)
{
    _PrintEnter("ConvertDefaultLocale(%p)\n", a0);

    LCID rv = 0;
    __try {
        rv = Real_ConvertDefaultLocale(a0);
    }
    __finally {
        _PrintExit("ConvertDefaultLocale() -> %x\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_ConvertThreadToFiber(LPVOID a0)
{
    _PrintEnter("ConvertThreadToFiber(%p)\n", a0);

    LPVOID rv = 0;
    __try {
        rv = Real_ConvertThreadToFiber(a0);
    }
    __finally {
        _PrintExit("ConvertThreadToFiber() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_CopyAcceleratorTableA(HACCEL a0,
    ACCEL* a1,
    int a2)
{
    _PrintEnter("CopyAcceleratorTableA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_CopyAcceleratorTableA(a0, a1, a2);
    }
    __finally {
        _PrintExit("CopyAcceleratorTableA(,,) -> %x\n", rv);
    };
    return rv;
}

int __stdcall Mine_CopyAcceleratorTableW(HACCEL a0,
    ACCEL* a1,
    int a2)
{
    _PrintEnter("CopyAcceleratorTableW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_CopyAcceleratorTableW(a0, a1, a2);
    }
    __finally {
        _PrintExit("CopyAcceleratorTableW(,,) -> %x\n", rv);
    };
    return rv;
}

HENHMETAFILE __stdcall Mine_CopyEnhMetaFileA(HENHMETAFILE a0,
    LPCSTR a1)
{
    _PrintEnter("CopyEnhMetaFileA(%p,%hs)\n", a0, a1);

    HENHMETAFILE rv = 0;
    __try {
        rv = Real_CopyEnhMetaFileA(a0, a1);
    }
    __finally {
        _PrintExit("CopyEnhMetaFileA(,) -> %p\n", rv);
    };
    return rv;
}

HENHMETAFILE __stdcall Mine_CopyEnhMetaFileW(HENHMETAFILE a0,
    LPCWSTR a1)
{
    _PrintEnter("CopyEnhMetaFileW(%p,%ls)\n", a0, a1);

    HENHMETAFILE rv = 0;
    __try {
        rv = Real_CopyEnhMetaFileW(a0, a1);
    }
    __finally {
        _PrintExit("CopyEnhMetaFileW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CopyFileA(LPCSTR a0,
    LPCSTR a1,
    BOOL a2)
{
    _PrintEnter("CopyFileA(%hs,%hs,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CopyFileA(a0, a1, a2);
    }
    __finally {
        _PrintExit("CopyFileA(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CopyFileExA(LPCSTR a0,
    LPCSTR a1,
    LPPROGRESS_ROUTINE a2,
    LPVOID a3,
    LPBOOL a4,
    DWORD a5)
{
    _PrintEnter("CopyFileExA(%hs,%hs,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_CopyFileExA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CopyFileExA(,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CopyFileExW(LPCWSTR a0,
    LPCWSTR a1,
    LPPROGRESS_ROUTINE a2,
    LPVOID a3,
    LPBOOL a4,
    DWORD a5)
{
    _PrintEnter("CopyFileExW(%ls,%ls,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_CopyFileExW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CopyFileExW(,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CopyFileW(LPCWSTR a0,
    LPCWSTR a1,
    BOOL a2)
{
    _PrintEnter("CopyFileW(%ls,%ls,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CopyFileW(a0, a1, a2);
    }
    __finally {
        _PrintExit("CopyFileW(,,) -> %x\n", rv);
    };
    return rv;
}

HICON __stdcall Mine_CopyIcon(HICON a0)
{
    _PrintEnter("CopyIcon(%p)\n", a0);

    HICON rv = 0;
    __try {
        rv = Real_CopyIcon(a0);
    }
    __finally {
        _PrintExit("CopyIcon() -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CopyImage(HANDLE a0,
    UINT a1,
    int a2,
    int a3,
    UINT a4)
{
    _PrintEnter("CopyImage(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HANDLE rv = 0;
    __try {
        rv = Real_CopyImage(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CopyImage(,,,,) -> %p\n", rv);
    };
    return rv;
}

HMETAFILE __stdcall Mine_CopyMetaFileA(HMETAFILE a0,
    LPCSTR a1)
{
    _PrintEnter("CopyMetaFileA(%p,%hs)\n", a0, a1);

    HMETAFILE rv = 0;
    __try {
        rv = Real_CopyMetaFileA(a0, a1);
    }
    __finally {
        _PrintExit("CopyMetaFileA(,) -> %p\n", rv);
    };
    return rv;
}

HMETAFILE __stdcall Mine_CopyMetaFileW(HMETAFILE a0,
    LPCWSTR a1)
{
    _PrintEnter("CopyMetaFileW(%p,%ls)\n", a0, a1);

    HMETAFILE rv = 0;
    __try {
        rv = Real_CopyMetaFileW(a0, a1);
    }
    __finally {
        _PrintExit("CopyMetaFileW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CopyRect(LPRECT a0,
    RECT* a1)
{
    _PrintEnter("CopyRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_CopyRect(a0, a1);
    }
    __finally {
        _PrintExit("CopyRect(,) -> %x\n", rv);
    };
    return rv;
}

int __stdcall Mine_CountClipboardFormats(void)
{
    _PrintEnter("CountClipboardFormats()\n");

    int rv = 0;
    __try {
        rv = Real_CountClipboardFormats();
    }
    __finally {
        _PrintExit("CountClipboardFormats() -> %x\n", rv);
    };
    return rv;
}

HACCEL __stdcall Mine_CreateAcceleratorTableA(ACCEL* a0,
    int a1)
{
    _PrintEnter("CreateAcceleratorTableA(%p,%p)\n", a0, a1);

    HACCEL rv = 0;
    __try {
        rv = Real_CreateAcceleratorTableA(a0, a1);
    }
    __finally {
        _PrintExit("CreateAcceleratorTableA(,) -> %p\n", rv);
    };
    return rv;
}

HACCEL __stdcall Mine_CreateAcceleratorTableW(ACCEL* a0,
    int a1)
{
    _PrintEnter("CreateAcceleratorTableW(%p,%p)\n", a0, a1);

    HACCEL rv = 0;
    __try {
        rv = Real_CreateAcceleratorTableW(a0, a1);
    }
    __finally {
        _PrintExit("CreateAcceleratorTableW(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateAntiMoniker(IMoniker** a0)
{
    _PrintEnter("CreateAntiMoniker(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateAntiMoniker(a0);
    }
    __finally {
        _PrintExit("CreateAntiMoniker() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateBindCtx(DWORD a0,
    IBindCtx** a1)
{
    _PrintEnter("CreateBindCtx(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateBindCtx(a0, a1);
    }
    __finally {
        _PrintExit("CreateBindCtx(,) -> %x\n", rv);
    };
    return rv;
}

HBITMAP __stdcall Mine_CreateBitmap(int a0,
    int a1,
    UINT a2,
    UINT a3,
    void* a4)
{
    _PrintEnter("CreateBitmap(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HBITMAP rv = 0;
    __try {
        rv = Real_CreateBitmap(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CreateBitmap(,,,,) -> %p\n", rv);
    };
    return rv;
}

HBITMAP __stdcall Mine_CreateBitmapIndirect(BITMAP* a0)
{
    _PrintEnter("CreateBitmapIndirect(%p)\n", a0);

    HBITMAP rv = 0;
    __try {
        rv = Real_CreateBitmapIndirect(a0);
    }
    __finally {
        _PrintExit("CreateBitmapIndirect() -> %p\n", rv);
    };
    return rv;
}

HBRUSH __stdcall Mine_CreateBrushIndirect(LOGBRUSH* a0)
{
    _PrintEnter("CreateBrushIndirect(%p)\n", a0);

    HBRUSH rv = 0;
    __try {
        rv = Real_CreateBrushIndirect(a0);
    }
    __finally {
        _PrintExit("CreateBrushIndirect() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CreateCaret(HWND a0,
    HBITMAP a1,
    int a2,
    int a3)
{
    _PrintEnter("CreateCaret(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_CreateCaret(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateCaret(,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateClassMoniker(CONST IID& a0,
    IMoniker** a1)
{
    _PrintEnter("CreateClassMoniker(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateClassMoniker(a0, a1);
    }
    __finally {
        _PrintExit("CreateClassMoniker(,) -> %x\n", rv);
    };
    return rv;
}

HCOLORSPACE __stdcall Mine_CreateColorSpaceA(LOGCOLORSPACEA* a0)
{
    _PrintEnter("CreateColorSpaceA(%p)\n", a0);

    HCOLORSPACE rv = 0;
    __try {
        rv = Real_CreateColorSpaceA(a0);
    }
    __finally {
        _PrintExit("CreateColorSpaceA() -> %p\n", rv);
    };
    return rv;
}

HCOLORSPACE __stdcall Mine_CreateColorSpaceW(LOGCOLORSPACEW* a0)
{
    _PrintEnter("CreateColorSpaceW(%p)\n", a0);

    HCOLORSPACE rv = 0;
    __try {
        rv = Real_CreateColorSpaceW(a0);
    }
    __finally {
        _PrintExit("CreateColorSpaceW() -> %p\n", rv);
    };
    return rv;
}

HBITMAP __stdcall Mine_CreateCompatibleBitmap(HDC a0,
    int a1,
    int a2)
{
    _PrintEnter("CreateCompatibleBitmap(%p,%p,%p)\n", a0, a1, a2);

    HBITMAP rv = 0;
    __try {
        rv = Real_CreateCompatibleBitmap(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateCompatibleBitmap(,,) -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_CreateCompatibleDC(HDC a0)
{
    _PrintEnter("CreateCompatibleDC(%p)\n", a0);

    HDC rv = 0;
    __try {
        rv = Real_CreateCompatibleDC(a0);
    }
    __finally {
        _PrintExit("CreateCompatibleDC() -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateConsoleScreenBuffer(DWORD a0,
    DWORD a1,
    SECURITY_ATTRIBUTES* a2,
    DWORD a3,
    LPVOID a4)
{
    _PrintEnter("CreateConsoleScreenBuffer(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateConsoleScreenBuffer(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CreateConsoleScreenBuffer(,,,,) -> %p\n", rv);
    };
    return rv;
}

HCURSOR __stdcall Mine_CreateCursor(HINSTANCE a0,
    int a1,
    int a2,
    int a3,
    int a4,
    void* a5,
    void* a6)
{
    _PrintEnter("CreateCursor(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HCURSOR rv = 0;
    __try {
        rv = Real_CreateCursor(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CreateCursor(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_CreateDCA(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    CONST DEVMODEA* a3)
{
    _PrintEnter("CreateDCA(%hs,%hs,%hs,%p)\n", a0, a1, a2, a3);

    HDC rv = 0;
    __try {
        rv = Real_CreateDCA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateDCA(,,,) -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_CreateDCW(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    CONST DEVMODEW* a3)
{
    _PrintEnter("CreateDCW(%ls,%ls,%ls,%p)\n", a0, a1, a2, a3);

    HDC rv = 0;
    __try {
        rv = Real_CreateDCW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateDCW(,,,) -> %p\n", rv);
    };
    return rv;
}

HBRUSH __stdcall Mine_CreateDIBPatternBrush(HGLOBAL a0,
    UINT a1)
{
    _PrintEnter("CreateDIBPatternBrush(%p,%p)\n", a0, a1);

    HBRUSH rv = 0;
    __try {
        rv = Real_CreateDIBPatternBrush(a0, a1);
    }
    __finally {
        _PrintExit("CreateDIBPatternBrush(,) -> %p\n", rv);
    };
    return rv;
}

HBRUSH __stdcall Mine_CreateDIBPatternBrushPt(void* a0,
    UINT a1)
{
    _PrintEnter("CreateDIBPatternBrushPt(%p,%p)\n", a0, a1);

    HBRUSH rv = 0;
    __try {
        rv = Real_CreateDIBPatternBrushPt(a0, a1);
    }
    __finally {
        _PrintExit("CreateDIBPatternBrushPt(,) -> %p\n", rv);
    };
    return rv;
}

HBITMAP __stdcall Mine_CreateDIBSection(HDC a0,
    BITMAPINFO* a1,
    UINT a2,
    void** a3,
    HANDLE a4,
    DWORD a5)
{
    _PrintEnter("CreateDIBSection(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HBITMAP rv = 0;
    __try {
        rv = Real_CreateDIBSection(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CreateDIBSection(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HBITMAP __stdcall Mine_CreateDIBitmap(HDC a0,
    BITMAPINFOHEADER* a1,
    DWORD a2,
    void* a3,
    BITMAPINFO* a4,
    UINT a5)
{
    _PrintEnter("CreateDIBitmap(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HBITMAP rv = 0;
    __try {
        rv = Real_CreateDIBitmap(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CreateDIBitmap(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateDataAdviseHolder(LPDATAADVISEHOLDER* a0)
{
    _PrintEnter("CreateDataAdviseHolder(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateDataAdviseHolder(a0);
    }
    __finally {
        _PrintExit("CreateDataAdviseHolder() -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateDataCache(LPUNKNOWN a0,
    CONST IID& a1,
    CONST IID& a2,
    LPVOID* a3)
{
    _PrintEnter("CreateDataCache(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateDataCache(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateDataCache(,,,) -> %x\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HDESK __stdcall Mine_CreateDesktopA(LPSTR a0,
    LPSTR a1,
    LPDEVMODEA a2,
    DWORD a3,
    ACCESS_MASK a4,
    LPSECURITY_ATTRIBUTES a5)
#else
HDESK __stdcall Mine_CreateDesktopA(LPCSTR a0,
    LPCSTR a1,
    LPDEVMODEA a2,
    DWORD a3,
    ACCESS_MASK a4,
    LPSECURITY_ATTRIBUTES a5)
#endif
{
    _PrintEnter("CreateDesktopA(%hs,%hs,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HDESK rv = 0;
    __try {
        rv = Real_CreateDesktopA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CreateDesktopA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HDESK __stdcall Mine_CreateDesktopW(LPWSTR a0, // NT 3.51 and older. NT4?
    LPWSTR a1, // NT 3.51 and older. NT4?
    LPDEVMODEW a2,
    DWORD a3,
    ACCESS_MASK a4,
    LPSECURITY_ATTRIBUTES a5)
#else
HDESK __stdcall Mine_CreateDesktopW(LPCWSTR a0, // Windows 2000 and newer; NT4?
    LPCWSTR a1, // Windows 2000 and newer; NT4?
    LPDEVMODEW a2,
    DWORD a3,
    ACCESS_MASK a4,
    LPSECURITY_ATTRIBUTES a5)
#endif
{
    _PrintEnter("CreateDesktopW(%ls,%ls,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HDESK rv = 0;
    __try {
        rv = Real_CreateDesktopW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CreateDesktopW(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_CreateDialogIndirectParamA(HINSTANCE a0,
    LPCDLGTEMPLATEA a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
{
    _PrintEnter("CreateDialogIndirectParamA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HWND rv = 0;
    __try {
        rv = Real_CreateDialogIndirectParamA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CreateDialogIndirectParamA(,,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_CreateDialogIndirectParamW(HINSTANCE a0,
    LPCDLGTEMPLATEW a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
{
    _PrintEnter("CreateDialogIndirectParamW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HWND rv = 0;
    __try {
        rv = Real_CreateDialogIndirectParamW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CreateDialogIndirectParamW(,,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_CreateDialogParamA(HINSTANCE a0,
    LPCSTR a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
{
    _PrintEnter("CreateDialogParamA(%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HWND rv = 0;
    __try {
        rv = Real_CreateDialogParamA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CreateDialogParamA(,,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_CreateDialogParamW(HINSTANCE a0,
    LPCWSTR a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
{
    _PrintEnter("CreateDialogParamW(%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HWND rv = 0;
    __try {
        rv = Real_CreateDialogParamW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("CreateDialogParamW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CreateDirectoryA(LPCSTR a0,
    LPSECURITY_ATTRIBUTES a1)
{
    _PrintEnter("CreateDirectoryA(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_CreateDirectoryA(a0, a1);
    }
    __finally {
        _PrintExit("CreateDirectoryA(,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CreateDirectoryExA(LPCSTR a0,
    LPCSTR a1,
    LPSECURITY_ATTRIBUTES a2)
{
    _PrintEnter("CreateDirectoryExA(%hs,%hs,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CreateDirectoryExA(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateDirectoryExA(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CreateDirectoryExW(LPCWSTR a0,
    LPCWSTR a1,
    LPSECURITY_ATTRIBUTES a2)
{
    _PrintEnter("CreateDirectoryExW(%ls,%ls,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CreateDirectoryExW(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateDirectoryExW(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CreateDirectoryW(LPCWSTR a0,
    LPSECURITY_ATTRIBUTES a1)
{
    _PrintEnter("CreateDirectoryW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_CreateDirectoryW(a0, a1);
    }
    __finally {
        _PrintExit("CreateDirectoryW(,) -> %x\n", rv);
    };
    return rv;
}

HBITMAP __stdcall Mine_CreateDiscardableBitmap(HDC a0,
    int a1,
    int a2)
{
    _PrintEnter("CreateDiscardableBitmap(%p,%p,%p)\n", a0, a1, a2);

    HBITMAP rv = 0;
    __try {
        rv = Real_CreateDiscardableBitmap(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateDiscardableBitmap(,,) -> %p\n", rv);
    };
    return rv;
}

HRGN __stdcall Mine_CreateEllipticRgn(int a0,
    int a1,
    int a2,
    int a3)
{
    _PrintEnter("CreateEllipticRgn(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRGN rv = 0;
    __try {
        rv = Real_CreateEllipticRgn(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateEllipticRgn(,,,) -> %p\n", rv);
    };
    return rv;
}

HRGN __stdcall Mine_CreateEllipticRgnIndirect(RECT* a0)
{
    _PrintEnter("CreateEllipticRgnIndirect(%p)\n", a0);

    HRGN rv = 0;
    __try {
        rv = Real_CreateEllipticRgnIndirect(a0);
    }
    __finally {
        _PrintExit("CreateEllipticRgnIndirect() -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_CreateEnhMetaFileA(HDC a0,
    LPCSTR a1,
    RECT* a2,
    LPCSTR a3)
{
    _PrintEnter("CreateEnhMetaFileA(%p,%hs,%p,%hs)\n", a0, a1, a2, a3);

    HDC rv = 0;
    __try {
        rv = Real_CreateEnhMetaFileA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateEnhMetaFileA(,,,) -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_CreateEnhMetaFileW(HDC a0,
    LPCWSTR a1,
    RECT* a2,
    LPCWSTR a3)
{
    _PrintEnter("CreateEnhMetaFileW(%p,%ls,%p,%ls)\n", a0, a1, a2, a3);

    HDC rv = 0;
    __try {
        rv = Real_CreateEnhMetaFileW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateEnhMetaFileW(,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateEventA(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    BOOL a2,
    LPCSTR a3)
{
    _PrintEnter("CreateEventA(%p,%p,%p,%hs)\n", a0, a1, a2, a3);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateEventA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateEventA(,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateEventW(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    BOOL a2,
    LPCWSTR a3)
{
    _PrintEnter("CreateEventW(%p,%p,%p,%ls)\n", a0, a1, a2, a3);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateEventW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateEventW(,,,) -> %p\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_CreateFiber(ULONG_PTR a0,
    LPFIBER_START_ROUTINE a1,
    LPVOID a2)
{
    _PrintEnter("CreateFiber(%p,%p,%p)\n", a0, a1, a2);

    LPVOID rv = 0;
    __try {
        rv = Real_CreateFiber(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateFiber(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateFileA(LPCSTR a0,
    DWORD a1,
    DWORD a2,
    LPSECURITY_ATTRIBUTES a3,
    DWORD a4,
    DWORD a5,
    HANDLE a6)
{
    _PrintEnter("CreateFileA(%hs,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateFileA(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CreateFileA(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateFileMappingA(HANDLE a0,
    LPSECURITY_ATTRIBUTES a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    LPCSTR a5)
{
    _PrintEnter("CreateFileMappingA(%p,%p,%p,%p,%p,%hs)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateFileMappingA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CreateFileMappingA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateFileMappingW(HANDLE a0,
    LPSECURITY_ATTRIBUTES a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    LPCWSTR a5)
{
    _PrintEnter("CreateFileMappingW(%p,%p,%p,%p,%p,%ls)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateFileMappingW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CreateFileMappingW(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateFileMoniker(LPCOLESTR a0,
    IMoniker** a1)
{
    _PrintEnter("CreateFileMoniker(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateFileMoniker(a0, a1);
    }
    __finally {
        _PrintExit("CreateFileMoniker(,) -> %x\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateFileW(LPCWSTR a0,
    DWORD a1,
    DWORD a2,
    LPSECURITY_ATTRIBUTES a3,
    DWORD a4,
    DWORD a5,
    HANDLE a6)
{
    _PrintEnter("CreateFileW(%ls,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateFileW(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CreateFileW(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HFONT __stdcall Mine_CreateFontA(int a0,
    int a1,
    int a2,
    int a3,
    int a4,
    DWORD a5,
    DWORD a6,
    DWORD a7,
    DWORD a8,
    DWORD a9,
    DWORD a10,
    DWORD a11,
    DWORD a12,
    LPCSTR a13)
{
    _PrintEnter("CreateFontA(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%hs)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);

    HFONT rv = 0;
    __try {
        rv = Real_CreateFontA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    }
    __finally {
        _PrintExit("CreateFontA(,,,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HFONT __stdcall Mine_CreateFontIndirectA(LOGFONTA* a0)
{
    _PrintEnter("CreateFontIndirectA(%p)\n", a0);

    HFONT rv = 0;
    __try {
        rv = Real_CreateFontIndirectA(a0);
    }
    __finally {
        _PrintExit("CreateFontIndirectA() -> %p\n", rv);
    };
    return rv;
}

HFONT __stdcall Mine_CreateFontIndirectW(LOGFONTW* a0)
{
    _PrintEnter("CreateFontIndirectW(%p)\n", a0);

    HFONT rv = 0;
    __try {
        rv = Real_CreateFontIndirectW(a0);
    }
    __finally {
        _PrintExit("CreateFontIndirectW() -> %p\n", rv);
    };
    return rv;
}

HFONT __stdcall Mine_CreateFontW(int a0,
    int a1,
    int a2,
    int a3,
    int a4,
    DWORD a5,
    DWORD a6,
    DWORD a7,
    DWORD a8,
    DWORD a9,
    DWORD a10,
    DWORD a11,
    DWORD a12,
    LPCWSTR a13)
{
    _PrintEnter("CreateFontW(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%ls)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);

    HFONT rv = 0;
    __try {
        rv = Real_CreateFontW(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    }
    __finally {
        _PrintExit("CreateFontW(,,,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateGenericComposite(IMoniker* a0,
    IMoniker* a1,
    IMoniker** a2)
{
    _PrintEnter("CreateGenericComposite(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateGenericComposite(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateGenericComposite(,,) -> %x\n", rv);
    };
    return rv;
}

HPALETTE __stdcall Mine_CreateHalftonePalette(HDC a0)
{
    _PrintEnter("CreateHalftonePalette(%p)\n", a0);

    HPALETTE rv = 0;
    __try {
        rv = Real_CreateHalftonePalette(a0);
    }
    __finally {
        _PrintExit("CreateHalftonePalette() -> %p\n", rv);
    };
    return rv;
}

HBRUSH __stdcall Mine_CreateHatchBrush(int a0,
    COLORREF a1)
{
    _PrintEnter("CreateHatchBrush(%p,%p)\n", a0, a1);

    HBRUSH rv = 0;
    __try {
        rv = Real_CreateHatchBrush(a0, a1);
    }
    __finally {
        _PrintExit("CreateHatchBrush(,) -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_CreateICA(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    CONST DEVMODEA* a3)
{
    _PrintEnter("CreateICA(%hs,%hs,%hs,%p)\n", a0, a1, a2, a3);

    HDC rv = 0;
    __try {
        rv = Real_CreateICA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateICA(,,,) -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_CreateICW(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    CONST DEVMODEW* a3)
{
    _PrintEnter("CreateICW(%ls,%ls,%ls,%p)\n", a0, a1, a2, a3);

    HDC rv = 0;
    __try {
        rv = Real_CreateICW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateICW(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateILockBytesOnHGlobal(HGLOBAL a0,
    BOOL a1,
    ILockBytes** a2)
{
    _PrintEnter("CreateILockBytesOnHGlobal(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateILockBytesOnHGlobal(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateILockBytesOnHGlobal(,,) -> %x\n", rv);
    };
    return rv;
}

HICON __stdcall Mine_CreateIcon(HINSTANCE a0,
    int a1,
    int a2,
    BYTE a3,
    BYTE a4,
    BYTE* a5,
    BYTE* a6)
{
    _PrintEnter("CreateIcon(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HICON rv = 0;
    __try {
        rv = Real_CreateIcon(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CreateIcon(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HICON __stdcall Mine_CreateIconFromResource(PBYTE a0,
    DWORD a1,
    BOOL a2,
    DWORD a3)
{
    _PrintEnter("CreateIconFromResource(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HICON rv = 0;
    __try {
        rv = Real_CreateIconFromResource(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateIconFromResource(,,,) -> %p\n", rv);
    };
    return rv;
}

HICON __stdcall Mine_CreateIconFromResourceEx(PBYTE a0,
    DWORD a1,
    BOOL a2,
    DWORD a3,
    int a4,
    int a5,
    UINT a6)
{
    _PrintEnter("CreateIconFromResourceEx(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HICON rv = 0;
    __try {
        rv = Real_CreateIconFromResourceEx(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CreateIconFromResourceEx(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HICON __stdcall Mine_CreateIconIndirect(PICONINFO a0)
{
    _PrintEnter("CreateIconIndirect(%p)\n", a0);

    HICON rv = 0;
    __try {
        rv = Real_CreateIconIndirect(a0);
    }
    __finally {
        _PrintExit("CreateIconIndirect() -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateIoCompletionPort(HANDLE a0,
    HANDLE a1,
    ULONG_PTR a2,
    DWORD a3)
{
    _PrintEnter("CreateIoCompletionPort(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateIoCompletionPort(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateIoCompletionPort(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateItemMoniker(LPCOLESTR a0,
    LPCOLESTR a1,
    IMoniker** a2)
{
    _PrintEnter("CreateItemMoniker(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateItemMoniker(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateItemMoniker(,,) -> %x\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HWND __stdcall Mine_CreateMDIWindowA(LPSTR a0, // NT 3.51 and older. NT4?
    LPSTR a1, // NT 3.51 and older. NT4?
    DWORD a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HWND a7,
    HINSTANCE a8,
    LPARAM a9)
#else
HWND __stdcall Mine_CreateMDIWindowA(LPCSTR a0, // Windows 2000 and newer; NT4?
    LPCSTR a1, // Windows 2000 and newer; NT4?
    DWORD a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HWND a7,
    HINSTANCE a8,
    LPARAM a9)
#endif
{
    _PrintEnter("CreateMDIWindowA(%hs,%hs,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);

    HWND rv = 0;
    __try {
        rv = Real_CreateMDIWindowA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
    __finally {
        _PrintExit("CreateMDIWindowA(,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HWND __stdcall Mine_CreateMDIWindowW(LPWSTR a0,
    LPWSTR a1,
    DWORD a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HWND a7,
    HINSTANCE a8,
    LPARAM a9)
#else
HWND __stdcall Mine_CreateMDIWindowW(LPCWSTR a0,
    LPCWSTR a1,
    DWORD a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HWND a7,
    HINSTANCE a8,
    LPARAM a9)
#endif
{
    _PrintEnter("CreateMDIWindowW(%ls,%ls,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);

    HWND rv = 0;
    __try {
        rv = Real_CreateMDIWindowW(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
    __finally {
        _PrintExit("CreateMDIWindowW(,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateMailslotA(LPCSTR a0,
    DWORD a1,
    DWORD a2,
    LPSECURITY_ATTRIBUTES a3)
{
    _PrintEnter("CreateMailslotA(%hs,%p,%p,%p)\n", a0, a1, a2, a3);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateMailslotA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateMailslotA(,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateMailslotW(LPCWSTR a0,
    DWORD a1,
    DWORD a2,
    LPSECURITY_ATTRIBUTES a3)
{
    _PrintEnter("CreateMailslotW(%ls,%p,%p,%p)\n", a0, a1, a2, a3);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateMailslotW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateMailslotW(,,,) -> %p\n", rv);
    };
    return rv;
}

HMENU __stdcall Mine_CreateMenu(void)
{
    _PrintEnter("CreateMenu()\n");

    HMENU rv = 0;
    __try {
        rv = Real_CreateMenu();
    }
    __finally {
        _PrintExit("CreateMenu() -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_CreateMetaFileA(LPCSTR a0)
{
    _PrintEnter("CreateMetaFileA(%hs)\n", a0);

    HDC rv = 0;
    __try {
        rv = Real_CreateMetaFileA(a0);
    }
    __finally {
        _PrintExit("CreateMetaFileA() -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_CreateMetaFileW(LPCWSTR a0)
{
    _PrintEnter("CreateMetaFileW(%ls)\n", a0);

    HDC rv = 0;
    __try {
        rv = Real_CreateMetaFileW(a0);
    }
    __finally {
        _PrintExit("CreateMetaFileW() -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateMutexA(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    LPCSTR a2)
{
    _PrintEnter("CreateMutexA(%p,%p,%hs)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateMutexA(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateMutexA(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateMutexW(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    LPCWSTR a2)
{
    _PrintEnter("CreateMutexW(%p,%p,%ls)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateMutexW(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateMutexW(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateNamedPipeA(LPCSTR a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    DWORD a5,
    DWORD a6,
    LPSECURITY_ATTRIBUTES a7)
{
    _PrintEnter("CreateNamedPipeA(%hs,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateNamedPipeA(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("CreateNamedPipeA(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateNamedPipeW(LPCWSTR a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    DWORD a5,
    DWORD a6,
    LPSECURITY_ATTRIBUTES a7)
{
    _PrintEnter("CreateNamedPipeW(%ls,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateNamedPipeW(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("CreateNamedPipeW(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateOleAdviseHolder(LPOLEADVISEHOLDER* a0)
{
    _PrintEnter("CreateOleAdviseHolder(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateOleAdviseHolder(a0);
    }
    __finally {
        _PrintExit("CreateOleAdviseHolder() -> %x\n", rv);
    };
    return rv;
}

HPALETTE __stdcall Mine_CreatePalette(LOGPALETTE* a0)
{
    _PrintEnter("CreatePalette(%p)\n", a0);

    HPALETTE rv = 0;
    __try {
        rv = Real_CreatePalette(a0);
    }
    __finally {
        _PrintExit("CreatePalette() -> %p\n", rv);
    };
    return rv;
}

HBRUSH __stdcall Mine_CreatePatternBrush(HBITMAP a0)
{
    _PrintEnter("CreatePatternBrush(%p)\n", a0);

    HBRUSH rv = 0;
    __try {
        rv = Real_CreatePatternBrush(a0);
    }
    __finally {
        _PrintExit("CreatePatternBrush() -> %p\n", rv);
    };
    return rv;
}

HPEN __stdcall Mine_CreatePen(int a0,
    int a1,
    COLORREF a2)
{
    _PrintEnter("CreatePen(%p,%p,%p)\n", a0, a1, a2);

    HPEN rv = 0;
    __try {
        rv = Real_CreatePen(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreatePen(,,) -> %p\n", rv);
    };
    return rv;
}

HPEN __stdcall Mine_CreatePenIndirect(LOGPEN* a0)
{
    _PrintEnter("CreatePenIndirect(%p)\n", a0);

    HPEN rv = 0;
    __try {
        rv = Real_CreatePenIndirect(a0);
    }
    __finally {
        _PrintExit("CreatePenIndirect() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CreatePipe(PHANDLE a0,
    PHANDLE a1,
    LPSECURITY_ATTRIBUTES a2,
    DWORD a3)
{
    _PrintEnter("CreatePipe(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_CreatePipe(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreatePipe(,,,) -> %x\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreatePointerMoniker(LPUNKNOWN a0,
    IMoniker** a1)
{
    _PrintEnter("CreatePointerMoniker(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_CreatePointerMoniker(a0, a1);
    }
    __finally {
        _PrintExit("CreatePointerMoniker(,) -> %x\n", rv);
    };
    return rv;
}

HRGN __stdcall Mine_CreatePolyPolygonRgn(POINT* a0,
    INT* a1,
    int a2,
    int a3)
{
    _PrintEnter("CreatePolyPolygonRgn(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRGN rv = 0;
    __try {
        rv = Real_CreatePolyPolygonRgn(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreatePolyPolygonRgn(,,,) -> %p\n", rv);
    };
    return rv;
}

HRGN __stdcall Mine_CreatePolygonRgn(POINT* a0,
    int a1,
    int a2)
{
    _PrintEnter("CreatePolygonRgn(%p,%p,%p)\n", a0, a1, a2);

    HRGN rv = 0;
    __try {
        rv = Real_CreatePolygonRgn(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreatePolygonRgn(,,) -> %p\n", rv);
    };
    return rv;
}

HMENU __stdcall Mine_CreatePopupMenu(void)
{
    _PrintEnter("CreatePopupMenu()\n");

    HMENU rv = 0;
    __try {
        rv = Real_CreatePopupMenu();
    }
    __finally {
        _PrintExit("CreatePopupMenu() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CreateProcessA(LPCSTR lpApplicationName,
    LPSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCSTR lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation)
{
    _PrintEnter("CreateProcessA(%hs,%hs,%p,%p,%p,%p,%p,%hs,%p,%p)\n",
        lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation);

    PROCESS_INFORMATION procInfo;
    if (lpProcessInformation == NULL) {
        lpProcessInformation = &procInfo;
        ZeroMemory(&procInfo, sizeof(procInfo));
    }

    BOOL rv = 0;
    __try {
        rv = DetourCreateProcessWithDllExA(lpApplicationName,
            lpCommandLine,
            lpProcessAttributes,
            lpThreadAttributes,
            bInheritHandles,
            dwCreationFlags,
            lpEnvironment,
            lpCurrentDirectory,
            lpStartupInfo,
            lpProcessInformation,
            s_szDllPath,
            Real_CreateProcessA);
    }
    __finally {
        _PrintExit("CreateProcessA(,,,,,,,,,) -> %x (proc:%d/%p, thrd:%d/%p\n", rv,
            lpProcessInformation->dwProcessId,
            lpProcessInformation->hProcess,
            lpProcessInformation->dwThreadId,
            lpProcessInformation->hThread);
    };
    return rv;
}

BOOL __stdcall Mine_CreateProcessW(LPCWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation)
{
    _PrintEnter("CreateProcessW(%ls,%ls,%p,%p,%p,%p,%p,%ls,%p,%p)\n",
        lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation);

    PROCESS_INFORMATION procInfo;
    if (lpProcessInformation == NULL) {
        lpProcessInformation = &procInfo;
        ZeroMemory(&procInfo, sizeof(procInfo));
    }

    BOOL rv = 0;
    __try {
        rv = DetourCreateProcessWithDllExW(lpApplicationName,
            lpCommandLine,
            lpProcessAttributes,
            lpThreadAttributes,
            bInheritHandles,
            dwCreationFlags,
            lpEnvironment,
            lpCurrentDirectory,
            lpStartupInfo,
            lpProcessInformation,
            s_szDllPath,
            Real_CreateProcessW);
    }
    __finally {
        _PrintExit("CreateProcessW(,,,,,,,,,) -> %x (proc:%d/%p, thrd:%d/%p\n", rv,
            lpProcessInformation->dwProcessId,
            lpProcessInformation->hProcess,
            lpProcessInformation->dwThreadId,
            lpProcessInformation->hThread);
    };
    return rv;
}

BOOL __stdcall Mine_CreateProcessAsUserA(
    __in_opt     HANDLE hToken,
    __in_opt     LPCSTR lpApplicationName,
    __inout_opt  LPSTR lpCommandLine,
    __in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
    __in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
    __in         BOOL bInheritHandles,
    __in         DWORD dwCreationFlags,
    __in_opt     LPVOID lpEnvironment,
    __in_opt     LPCSTR lpCurrentDirectory,
    __in         LPSTARTUPINFOA lpStartupInfo,
    __out        LPPROCESS_INFORMATION lpProcessInformation
)
{
    _PrintEnter("CreateProcessAsUserA(%ls,%ls,%p,%p,%p,%p,%p,%ls,%p,%p)\n",
        lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation);

    PROCESS_INFORMATION procInfo;
    if (lpProcessInformation == NULL) {
        lpProcessInformation = &procInfo;
        ZeroMemory(&procInfo, sizeof(procInfo));
    }

    BOOL rv = 0;
    __try {
        rv = Real_CreateProcessAsUserA(hToken,
            lpApplicationName,
            lpCommandLine,
            lpProcessAttributes,
            lpThreadAttributes,
            bInheritHandles,
            dwCreationFlags,
            lpEnvironment,
            lpCurrentDirectory,
            lpStartupInfo,
            lpProcessInformation);
    }
    __finally {
        _PrintExit("CreateProcessAsUserAW(,,,,,,,,,) -> %x (proc:%d/%p, thrd:%d/%p\n", rv,
            lpProcessInformation->dwProcessId,
            lpProcessInformation->hProcess,
            lpProcessInformation->dwThreadId,
            lpProcessInformation->hThread);
    };
    return rv;
}

BOOL __stdcall Mine_CreateProcessAsUserW(
    __in_opt     HANDLE hToken,
    __in_opt     LPCWSTR lpApplicationName,
    __inout_opt  LPWSTR lpCommandLine,
    __in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
    __in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
    __in         BOOL bInheritHandles,
    __in         DWORD dwCreationFlags,
    __in_opt     LPVOID lpEnvironment,
    __in_opt     LPCWSTR lpCurrentDirectory,
    __in         LPSTARTUPINFOW lpStartupInfo,
    __out        LPPROCESS_INFORMATION lpProcessInformation
)
{
    _PrintEnter("CreateProcessAsUserW(%ls,%ls,%p,%p,%p,%p,%p,%ls,%p,%p)\n",
        lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation);

    PROCESS_INFORMATION procInfo;
    if (lpProcessInformation == NULL) {
        lpProcessInformation = &procInfo;
        ZeroMemory(&procInfo, sizeof(procInfo));
    }

    BOOL rv = 0;
    __try {
        rv = Real_CreateProcessAsUserW(hToken,
            lpApplicationName,
            lpCommandLine,
            lpProcessAttributes,
            lpThreadAttributes,
            bInheritHandles,
            dwCreationFlags,
            lpEnvironment,
            lpCurrentDirectory,
            lpStartupInfo,
            lpProcessInformation);
    }
    __finally {
        _PrintExit("CreateProcessAsUserW(,,,,,,,,,) -> %x (proc:%d/%p, thrd:%d/%p\n", rv,
            lpProcessInformation->dwProcessId,
            lpProcessInformation->hProcess,
            lpProcessInformation->dwThreadId,
            lpProcessInformation->hThread);
    };
    return rv;
}

#if(_WIN32_WINNT >= 0x0500)
BOOL WINAPI Mine_CreateProcessWithLogonW(
    __in         LPCWSTR lpUsername,
    __in_opt     LPCWSTR lpDomain,
    __in         LPCWSTR lpPassword,
    __in         DWORD dwLogonFlags,
    __in_opt     LPCWSTR lpApplicationName,
    __inout_opt  LPWSTR lpCommandLine,
    __in         DWORD dwCreationFlags,
    __in_opt     LPVOID lpEnvironment,
    __in_opt     LPCWSTR lpCurrentDirectory,
    __in         LPSTARTUPINFOW lpStartupInfo,
    __out        LPPROCESS_INFORMATION lpProcessInfo
)
{
    _PrintEnter("CreateProcessWithLogonW(%ls,%ls,%ls,%d,%ls,%ls,%p,%p,%ls,%p,%p)\n",
        lpUsername,
        lpDomain,
        lpPassword,
        dwLogonFlags,
        lpApplicationName,
        lpCommandLine,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInfo);

    PROCESS_INFORMATION procInfo;
    if (lpProcessInfo == NULL) {
        lpProcessInfo = &procInfo;
        ZeroMemory(&procInfo, sizeof(procInfo));
    }

    BOOL rv = 0;
    __try {
        rv = Real_CreateProcessWithLogonW(
            lpUsername,
            lpDomain,
            lpPassword,
            dwLogonFlags,
            lpApplicationName,
            lpCommandLine,
            dwCreationFlags,
            lpEnvironment,
            lpCurrentDirectory,
            lpStartupInfo,
            lpProcessInfo);
    }
    __finally {
        _PrintExit("CreateProcessWithLogonW(,,,,,,,,,) -> %x (proc:%d/%p, thrd:%d/%p\n", rv,
            lpProcessInfo->dwProcessId,
            lpProcessInfo->hProcess,
            lpProcessInfo->dwThreadId,
            lpProcessInfo->hThread);
    };
    return rv;
}

BOOL WINAPI Mine_CreateProcessWithTokenW(
    __in         HANDLE hToken,
    __in         DWORD dwLogonFlags,
    __in_opt     LPCWSTR lpApplicationName,
    __inout_opt  LPWSTR lpCommandLine,
    __in         DWORD dwCreationFlags,
    __in_opt     LPVOID lpEnvironment,
    __in_opt     LPCWSTR lpCurrentDirectory,
    __in         LPSTARTUPINFOW lpStartupInfo,
    __out        LPPROCESS_INFORMATION lpProcessInfo
)
{
    _PrintEnter("CreateProcessWithTokenW(%ls,%ls,%p,%p,%ls,%p,%p)\n",
        lpApplicationName,
        lpCommandLine,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInfo);

    PROCESS_INFORMATION procInfo;
    if (lpProcessInfo == NULL) {
        lpProcessInfo = &procInfo;
        ZeroMemory(&procInfo, sizeof(procInfo));
    }

    BOOL rv = 0;
    __try {
        rv = Real_CreateProcessWithTokenW(hToken,
            dwLogonFlags,
            lpApplicationName,
            lpCommandLine,
            dwCreationFlags,
            lpEnvironment,
            lpCurrentDirectory,
            lpStartupInfo,
            lpProcessInfo);
    }
    __finally {
        _PrintExit("CreateProcessWithTokenW(,,,,,,,,,) -> %x (proc:%d/%p, thrd:%d/%p\n", rv,
            lpProcessInfo->dwProcessId,
            lpProcessInfo->hProcess,
            lpProcessInfo->dwThreadId,
            lpProcessInfo->hThread);
    };
    return rv;
}
#endif // (_WIN32_WINNT >= 0x0500)

HRGN __stdcall Mine_CreateRectRgn(int a0,
    int a1,
    int a2,
    int a3)
{
    _PrintEnter("CreateRectRgn(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRGN rv = 0;
    __try {
        rv = Real_CreateRectRgn(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateRectRgn(,,,) -> %p\n", rv);
    };
    return rv;
}

HRGN __stdcall Mine_CreateRectRgnIndirect(RECT* a0)
{
    _PrintEnter("CreateRectRgnIndirect(%p)\n", a0);

    HRGN rv = 0;
    __try {
        rv = Real_CreateRectRgnIndirect(a0);
    }
    __finally {
        _PrintExit("CreateRectRgnIndirect() -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateRemoteThread(HANDLE a0,
    LPSECURITY_ATTRIBUTES a1,
    ULONG_PTR a2,
    LPTHREAD_START_ROUTINE a3,
    LPVOID a4,
    DWORD a5,
    LPDWORD a6)
{
    _PrintEnter("CreateRemoteThread(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateRemoteThread(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("CreateRemoteThread(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRGN __stdcall Mine_CreateRoundRectRgn(int a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5)
{
    _PrintEnter("CreateRoundRectRgn(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HRGN rv = 0;
    __try {
        rv = Real_CreateRoundRectRgn(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CreateRoundRectRgn(,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CreateScalableFontResourceA(DWORD a0,
    LPCSTR a1,
    LPCSTR a2,
    LPCSTR a3)
{
    _PrintEnter("CreateScalableFontResourceA(%p,%hs,%hs,%hs)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_CreateScalableFontResourceA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateScalableFontResourceA(,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_CreateScalableFontResourceW(DWORD a0,
    LPCWSTR a1,
    LPCWSTR a2,
    LPCWSTR a3)
{
    _PrintEnter("CreateScalableFontResourceW(%p,%ls,%ls,%ls)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_CreateScalableFontResourceW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateScalableFontResourceW(,,,) -> %x\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateSemaphoreA(LPSECURITY_ATTRIBUTES a0,
    LONG a1,
    LONG a2,
    LPCSTR a3)
{
    _PrintEnter("CreateSemaphoreA(%p,%p,%p,%hs)\n", a0, a1, a2, a3);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateSemaphoreA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateSemaphoreA(,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateSemaphoreW(LPSECURITY_ATTRIBUTES a0,
    LONG a1,
    LONG a2,
    LPCWSTR a3)
{
    _PrintEnter("CreateSemaphoreW(%p,%p,%p,%ls)\n", a0, a1, a2, a3);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateSemaphoreW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateSemaphoreW(,,,) -> %p\n", rv);
    };
    return rv;
}

HBRUSH __stdcall Mine_CreateSolidBrush(COLORREF a0)
{
    _PrintEnter("CreateSolidBrush(%p)\n", a0);

    HBRUSH rv = 0;
    __try {
        rv = Real_CreateSolidBrush(a0);
    }
    __finally {
        _PrintExit("CreateSolidBrush() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateStdProgressIndicator(HWND a0,
    LPCOLESTR a1,
    IBindStatusCallback* a2,
    IBindStatusCallback** a3)
{
    _PrintEnter("CreateStdProgressIndicator(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateStdProgressIndicator(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateStdProgressIndicator(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_CreateStreamOnHGlobal(HGLOBAL a0,
    BOOL a1,
    LPSTREAM* a2)
{
    _PrintEnter("CreateStreamOnHGlobal(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_CreateStreamOnHGlobal(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateStreamOnHGlobal(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_CreateTapePartition(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3)
{
    _PrintEnter("CreateTapePartition(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_CreateTapePartition(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateTapePartition(,,,) -> %x\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateThread(LPSECURITY_ATTRIBUTES a0,
    ULONG_PTR a1,
    LPTHREAD_START_ROUTINE a2,
    LPVOID a3,
    DWORD a4,
    LPDWORD a5)
{
    _PrintEnter("CreateThread(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateThread(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("CreateThread(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateWaitableTimerA(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    LPCSTR a2)
{
    _PrintEnter("CreateWaitableTimerA(%p,%p,%hs)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateWaitableTimerA(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateWaitableTimerA(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_CreateWaitableTimerW(LPSECURITY_ATTRIBUTES a0,
    BOOL a1,
    LPCWSTR a2)
{
    _PrintEnter("CreateWaitableTimerW(%p,%p,%ls)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateWaitableTimerW(a0, a1, a2);
    }
    __finally {
        _PrintExit("CreateWaitableTimerW(,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_CreateWindowExA(DWORD a0,
    LPCSTR a1,
    LPCSTR a2,
    DWORD a3,
    int a4,
    int a5,
    int a6,
    int a7,
    HWND a8,
    HMENU a9,
    HINSTANCE a10,
    LPVOID a11)
{
    _PrintEnter("CreateWindowExA(%p,%hs,%hs,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    HWND rv = 0;
    __try {
        rv = Real_CreateWindowExA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    __finally {
        _PrintExit("CreateWindowExA(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_CreateWindowExW(DWORD a0,
    LPCWSTR a1,
    LPCWSTR a2,
    DWORD a3,
    int a4,
    int a5,
    int a6,
    int a7,
    HWND a8,
    HMENU a9,
    HINSTANCE a10,
    LPVOID a11)
{
    _PrintEnter("CreateWindowExW(%p,%ls,%ls,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    HWND rv = 0;
    __try {
        rv = Real_CreateWindowExW(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    __finally {
        _PrintExit("CreateWindowExW(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HWINSTA __stdcall Mine_CreateWindowStationA(LPSTR a0,
    DWORD a1,
    ACCESS_MASK a2,
    LPSECURITY_ATTRIBUTES a3)
#else
HWINSTA __stdcall Mine_CreateWindowStationA(LPCSTR a0,
    DWORD a1,
    ACCESS_MASK a2,
    LPSECURITY_ATTRIBUTES a3)
#endif
{
    _PrintEnter("CreateWindowStationA(%hs,%p,%p,%p)\n", a0, a1, a2, a3);

    HWINSTA rv = 0;
    __try {
        rv = Real_CreateWindowStationA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateWindowStationA(,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HWINSTA __stdcall Mine_CreateWindowStationW(LPWSTR a0,
    DWORD a1,
    ACCESS_MASK a2,
    LPSECURITY_ATTRIBUTES a3)
#else
HWINSTA __stdcall Mine_CreateWindowStationW(LPCWSTR a0,
    DWORD a1,
    ACCESS_MASK a2,
    LPSECURITY_ATTRIBUTES a3)
#endif
{
    _PrintEnter("CreateWindowStationW(%ls,%p,%p,%p)\n", a0, a1, a2, a3);

    HWINSTA rv = 0;
    __try {
        rv = Real_CreateWindowStationW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("CreateWindowStationW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DPtoLP(HDC a0,
    POINT* a1,
    int a2)
{
    _PrintEnter("DPtoLP(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DPtoLP(a0, a1, a2);
    }
    __finally {
        _PrintExit("DPtoLP(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeAbandonTransaction(DWORD a0,
    HCONV a1,
    DWORD a2)
{
    _PrintEnter("DdeAbandonTransaction(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DdeAbandonTransaction(a0, a1, a2);
    }
    __finally {
        _PrintExit("DdeAbandonTransaction(,,) -> %p\n", rv);
    };
    return rv;
}

LPBYTE __stdcall Mine_DdeAccessData(HDDEDATA a0,
    LPDWORD a1)
{
    _PrintEnter("DdeAccessData(%p,%p)\n", a0, a1);

    LPBYTE rv = 0;
    __try {
        rv = Real_DdeAccessData(a0, a1);
    }
    __finally {
        _PrintExit("DdeAccessData(,) -> %p\n", rv);
    };
    return rv;
}

HDDEDATA __stdcall Mine_DdeAddData(HDDEDATA a0,
    LPBYTE a1,
    DWORD a2,
    DWORD a3)
{
    _PrintEnter("DdeAddData(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HDDEDATA rv = 0;
    __try {
        rv = Real_DdeAddData(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DdeAddData(,,,) -> %p\n", rv);
    };
    return rv;
}

HDDEDATA __stdcall Mine_DdeClientTransaction(LPBYTE a0,
    DWORD a1,
    HCONV a2,
    HSZ a3,
    UINT a4,
    UINT a5,
    DWORD a6,
    LPDWORD a7)
{
    _PrintEnter("DdeClientTransaction(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HDDEDATA rv = 0;
    __try {
        rv = Real_DdeClientTransaction(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("DdeClientTransaction(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_DdeCmpStringHandles(HSZ a0,
    HSZ a1)
{
    _PrintEnter("DdeCmpStringHandles(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_DdeCmpStringHandles(a0, a1);
    }
    __finally {
        _PrintExit("DdeCmpStringHandles(,) -> %x\n", rv);
    };
    return rv;
}

HCONV __stdcall Mine_DdeConnect(DWORD a0,
    HSZ a1,
    HSZ a2,
    PCONVCONTEXT a3)
{
    _PrintEnter("DdeConnect(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HCONV rv = 0;
    __try {
        rv = Real_DdeConnect(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DdeConnect(,,,) -> %p\n", rv);
    };
    return rv;
}

HCONVLIST __stdcall Mine_DdeConnectList(DWORD a0,
    HSZ a1,
    HSZ a2,
    HCONVLIST a3,
    PCONVCONTEXT a4)
{
    _PrintEnter("DdeConnectList(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HCONVLIST rv = 0;
    __try {
        rv = Real_DdeConnectList(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DdeConnectList(,,,,) -> %p\n", rv);
    };
    return rv;
}

HDDEDATA __stdcall Mine_DdeCreateDataHandle(DWORD a0,
    LPBYTE a1,
    DWORD a2,
    DWORD a3,
    HSZ a4,
    UINT a5,
    UINT a6)
{
    _PrintEnter("DdeCreateDataHandle(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HDDEDATA rv = 0;
    __try {
        rv = Real_DdeCreateDataHandle(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("DdeCreateDataHandle(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HSZ __stdcall Mine_DdeCreateStringHandleA(DWORD a0,
    LPCSTR a1,
    int a2)
{
    _PrintEnter("DdeCreateStringHandleA(%p,%hs,%p)\n", a0, a1, a2);

    HSZ rv = 0;
    __try {
        rv = Real_DdeCreateStringHandleA(a0, a1, a2);
    }
    __finally {
        _PrintExit("DdeCreateStringHandleA(,,) -> %p\n", rv);
    };
    return rv;
}

HSZ __stdcall Mine_DdeCreateStringHandleW(DWORD a0,
    LPCWSTR a1,
    int a2)
{
    _PrintEnter("DdeCreateStringHandleW(%p,%ls,%p)\n", a0, a1, a2);

    HSZ rv = 0;
    __try {
        rv = Real_DdeCreateStringHandleW(a0, a1, a2);
    }
    __finally {
        _PrintExit("DdeCreateStringHandleW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeDisconnect(HCONV a0)
{
    _PrintEnter("DdeDisconnect(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DdeDisconnect(a0);
    }
    __finally {
        _PrintExit("DdeDisconnect() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeDisconnectList(HCONVLIST a0)
{
    _PrintEnter("DdeDisconnectList(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DdeDisconnectList(a0);
    }
    __finally {
        _PrintExit("DdeDisconnectList() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeEnableCallback(DWORD a0,
    HCONV a1,
    UINT a2)
{
    _PrintEnter("DdeEnableCallback(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DdeEnableCallback(a0, a1, a2);
    }
    __finally {
        _PrintExit("DdeEnableCallback(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeFreeDataHandle(HDDEDATA a0)
{
    _PrintEnter("DdeFreeDataHandle(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DdeFreeDataHandle(a0);
    }
    __finally {
        _PrintExit("DdeFreeDataHandle() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeFreeStringHandle(DWORD a0,
    HSZ a1)
{
    _PrintEnter("DdeFreeStringHandle(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_DdeFreeStringHandle(a0, a1);
    }
    __finally {
        _PrintExit("DdeFreeStringHandle(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_DdeGetData(HDDEDATA a0,
    LPBYTE a1,
    DWORD a2,
    DWORD a3)
{
    _PrintEnter("DdeGetData(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_DdeGetData(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DdeGetData(,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_DdeGetLastError(DWORD a0)
{
    _PrintEnter("DdeGetLastError(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_DdeGetLastError(a0);
    }
    __finally {
        _PrintExit("DdeGetLastError() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeImpersonateClient(HCONV a0)
{
    _PrintEnter("DdeImpersonateClient(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DdeImpersonateClient(a0);
    }
    __finally {
        _PrintExit("DdeImpersonateClient() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeKeepStringHandle(DWORD a0,
    HSZ a1)
{
    _PrintEnter("DdeKeepStringHandle(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_DdeKeepStringHandle(a0, a1);
    }
    __finally {
        _PrintExit("DdeKeepStringHandle(,) -> %p\n", rv);
    };
    return rv;
}

HDDEDATA __stdcall Mine_DdeNameService(DWORD a0,
    HSZ a1,
    HSZ a2,
    UINT a3)
{
    _PrintEnter("DdeNameService(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HDDEDATA rv = 0;
    __try {
        rv = Real_DdeNameService(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DdeNameService(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdePostAdvise(DWORD a0,
    HSZ a1,
    HSZ a2)
{
    _PrintEnter("DdePostAdvise(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DdePostAdvise(a0, a1, a2);
    }
    __finally {
        _PrintExit("DdePostAdvise(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_DdeQueryConvInfo(HCONV a0,
    DWORD a1,
    CONVINFO* a2)
{
    _PrintEnter("DdeQueryConvInfo(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_DdeQueryConvInfo(a0, a1, a2);
    }
    __finally {
        _PrintExit("DdeQueryConvInfo(,,) -> %p\n", rv);
    };
    return rv;
}

HCONV __stdcall Mine_DdeQueryNextServer(HCONVLIST a0,
    HCONV a1)
{
    _PrintEnter("DdeQueryNextServer(%p,%p)\n", a0, a1);

    HCONV rv = 0;
    __try {
        rv = Real_DdeQueryNextServer(a0, a1);
    }
    __finally {
        _PrintExit("DdeQueryNextServer(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_DdeQueryStringA(DWORD a0,
    HSZ a1,
    LPSTR a2,
    DWORD a3,
    int a4)
{
    _PrintEnter("DdeQueryStringA(%p,%p,%hs,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_DdeQueryStringA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DdeQueryStringA(,,%hs,,) -> %p\n", a2, rv);
    };
    return rv;
}

DWORD __stdcall Mine_DdeQueryStringW(DWORD a0,
    HSZ a1,
    LPWSTR a2,
    DWORD a3,
    int a4)
{
    _PrintEnter("DdeQueryStringW(%p,%p,%ls,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_DdeQueryStringW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DdeQueryStringW(,,%ls,,) -> %p\n", a2, rv);
    };
    return rv;
}

HCONV __stdcall Mine_DdeReconnect(HCONV a0)
{
    _PrintEnter("DdeReconnect(%p)\n", a0);

    HCONV rv = 0;
    __try {
        rv = Real_DdeReconnect(a0);
    }
    __finally {
        _PrintExit("DdeReconnect() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeSetQualityOfService(HWND a0,
    PSECURITY_QUALITY_OF_SERVICE a1,
    PSECURITY_QUALITY_OF_SERVICE a2)
{
    _PrintEnter("DdeSetQualityOfService(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DdeSetQualityOfService(a0, a1, a2);
    }
    __finally {
        _PrintExit("DdeSetQualityOfService(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeSetUserHandle(HCONV a0,
    DWORD a1,
    ULONG_PTR a2)
{
    _PrintEnter("DdeSetUserHandle(%p,%x,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DdeSetUserHandle(a0, a1, a2);
    }
    __finally {
        _PrintExit("DdeSetUserHandle(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeUnaccessData(HDDEDATA a0)
{
    _PrintEnter("DdeUnaccessData(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DdeUnaccessData(a0);
    }
    __finally {
        _PrintExit("DdeUnaccessData() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DdeUninitialize(DWORD a0)
{
    _PrintEnter("DdeUninitialize(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DdeUninitialize(a0);
    }
    __finally {
        _PrintExit("DdeUninitialize() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DebugActiveProcess(DWORD a0)
{
    _PrintEnter("DebugActiveProcess(pid=%d)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DebugActiveProcess(a0);
    }
    __finally {
        _PrintExit("DebugActiveProcess() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DebugActiveProcessStop(DWORD a0)
{
    _PrintEnter("DebugActiveProcessStop(pid=%d)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DebugActiveProcess(a0);
    }
    __finally {
        _PrintExit("DebugActiveProcessStop() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_DebugBreak(void)
{
    _PrintEnter("DebugBreak()\n");

    __try {
        Real_DebugBreak();
    }
    __finally {
        _PrintExit("DebugBreak() ->\n");
    };
}

LRESULT __stdcall Mine_DefDlgProcA(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("DefDlgProcA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    LRESULT rv = 0;
    __try {
        rv = Real_DefDlgProcA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DefDlgProcA(,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_DefDlgProcW(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("DefDlgProcW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    LRESULT rv = 0;
    __try {
        rv = Real_DefDlgProcW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DefDlgProcW(,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_DefFrameProcA(HWND a0,
    HWND a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
{
    _PrintEnter("DefFrameProcA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LRESULT rv = 0;
    __try {
        rv = Real_DefFrameProcA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DefFrameProcA(,,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_DefFrameProcW(HWND a0,
    HWND a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
{
    _PrintEnter("DefFrameProcW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LRESULT rv = 0;
    __try {
        rv = Real_DefFrameProcW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DefFrameProcW(,,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_DefMDIChildProcA(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("DefMDIChildProcA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    LRESULT rv = 0;
    __try {
        rv = Real_DefMDIChildProcA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DefMDIChildProcA(,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_DefMDIChildProcW(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("DefMDIChildProcW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    LRESULT rv = 0;
    __try {
        rv = Real_DefMDIChildProcW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DefMDIChildProcW(,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_DefWindowProcA(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("DefWindowProcA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    LRESULT rv = 0;
    __try {
        rv = Real_DefWindowProcA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DefWindowProcA(,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_DefWindowProcW(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("DefWindowProcW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    LRESULT rv = 0;
    __try {
        rv = Real_DefWindowProcW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DefWindowProcW(,,,) -> %p\n", rv);
    };
    return rv;
}

HDWP __stdcall Mine_DeferWindowPos(HDWP a0,
    HWND a1,
    HWND a2,
    int a3,
    int a4,
    int a5,
    int a6,
    UINT a7)
{
    _PrintEnter("DeferWindowPos(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HDWP rv = 0;
    __try {
        rv = Real_DeferWindowPos(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("DeferWindowPos(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DefineDosDeviceA(DWORD a0,
    LPCSTR a1,
    LPCSTR a2)
{
    _PrintEnter("DefineDosDeviceA(%p,%hs,%hs)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DefineDosDeviceA(a0, a1, a2);
    }
    __finally {
        _PrintExit("DefineDosDeviceA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DefineDosDeviceW(DWORD a0,
    LPCWSTR a1,
    LPCWSTR a2)
{
    _PrintEnter("DefineDosDeviceW(%p,%ls,%ls)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DefineDosDeviceW(a0, a1, a2);
    }
    __finally {
        _PrintExit("DefineDosDeviceW(,,) -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_DeleteAtom(ATOM a0)
{
    _PrintEnter("DeleteAtom(%p)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_DeleteAtom(a0);
    }
    __finally {
        _PrintExit("DeleteAtom() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DeleteColorSpace(HCOLORSPACE a0)
{
    _PrintEnter("DeleteColorSpace(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteColorSpace(a0);
    }
    __finally {
        _PrintExit("DeleteColorSpace() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DeleteDC(HDC a0)
{
    _PrintEnter("DeleteDC(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteDC(a0);
    }
    __finally {
        _PrintExit("DeleteDC() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DeleteEnhMetaFile(HENHMETAFILE a0)
{
    _PrintEnter("DeleteEnhMetaFile(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteEnhMetaFile(a0);
    }
    __finally {
        _PrintExit("DeleteEnhMetaFile() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_DeleteFiber(LPVOID a0)
{
    _PrintEnter("DeleteFiber(%p)\n", a0);

    __try {
        Real_DeleteFiber(a0);
    }
    __finally {
        _PrintExit("DeleteFiber() ->\n");
    };
}

BOOL __stdcall Mine_DeleteFileA(LPCSTR a0)
{
    _PrintEnter("DeleteFileA(%hs)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteFileA(a0);
    }
    __finally {
        _PrintExit("DeleteFileA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DeleteFileW(LPCWSTR a0)
{
    _PrintEnter("DeleteFileW(%ls)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteFileW(a0);
    }
    __finally {
        _PrintExit("DeleteFileW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DeleteMenu(HMENU a0,
    UINT a1,
    UINT a2)
{
    _PrintEnter("DeleteMenu(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteMenu(a0, a1, a2);
    }
    __finally {
        _PrintExit("DeleteMenu(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DeleteMetaFile(HMETAFILE a0)
{
    _PrintEnter("DeleteMetaFile(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteMetaFile(a0);
    }
    __finally {
        _PrintExit("DeleteMetaFile() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DeleteObject(HGDIOBJ a0)
{
    _PrintEnter("DeleteObject(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteObject(a0);
    }
    __finally {
        _PrintExit("DeleteObject() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_DescribePixelFormat(HDC a0,
    int a1,
    UINT a2,
    PIXELFORMATDESCRIPTOR* a3)
{
    _PrintEnter("DescribePixelFormat(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_DescribePixelFormat(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DescribePixelFormat(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DestroyAcceleratorTable(HACCEL a0)
{
    _PrintEnter("DestroyAcceleratorTable(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DestroyAcceleratorTable(a0);
    }
    __finally {
        _PrintExit("DestroyAcceleratorTable() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DestroyCaret(void)
{
    _PrintEnter("DestroyCaret()\n");

    BOOL rv = 0;
    __try {
        rv = Real_DestroyCaret();
    }
    __finally {
        _PrintExit("DestroyCaret() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DestroyCursor(HCURSOR a0)
{
    _PrintEnter("DestroyCursor(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DestroyCursor(a0);
    }
    __finally {
        _PrintExit("DestroyCursor() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DestroyIcon(HICON a0)
{
    _PrintEnter("DestroyIcon(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DestroyIcon(a0);
    }
    __finally {
        _PrintExit("DestroyIcon() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DestroyMenu(HMENU a0)
{
    _PrintEnter("DestroyMenu(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DestroyMenu(a0);
    }
    __finally {
        _PrintExit("DestroyMenu() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DestroyWindow(HWND a0)
{
    _PrintEnter("DestroyWindow(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DestroyWindow(a0);
    }
    __finally {
        _PrintExit("DestroyWindow() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DeviceIoControl(HANDLE a0,
    DWORD a1,
    LPVOID a2,
    DWORD a3,
    LPVOID a4,
    DWORD a5,
    LPDWORD a6,
    LPOVERLAPPED a7)
{
    _PrintEnter("DeviceIoControl(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    BOOL rv = 0;
    __try {
        rv = Real_DeviceIoControl(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("DeviceIoControl(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

INT_PTR __stdcall Mine_DialogBoxIndirectParamA(HINSTANCE a0,
    LPCDLGTEMPLATEA a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
{
    _PrintEnter("DialogBoxIndirectParamA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    INT_PTR rv = 0;
    __try {
        rv = Real_DialogBoxIndirectParamA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DialogBoxIndirectParamA(,,,,) -> %p\n", rv);
    };
    return rv;
}

INT_PTR __stdcall Mine_DialogBoxIndirectParamW(HINSTANCE a0,
    LPCDLGTEMPLATEW a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
{
    _PrintEnter("DialogBoxIndirectParamW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    INT_PTR rv = 0;
    __try {
        rv = Real_DialogBoxIndirectParamW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DialogBoxIndirectParamW(,,,,) -> %p\n", rv);
    };
    return rv;
}

INT_PTR __stdcall Mine_DialogBoxParamA(HINSTANCE a0,
    LPCSTR a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
{
    _PrintEnter("DialogBoxParamA(%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    INT_PTR rv = 0;
    __try {
        rv = Real_DialogBoxParamA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DialogBoxParamA(,,,,) -> %p\n", rv);
    };
    return rv;
}

INT_PTR __stdcall Mine_DialogBoxParamW(HINSTANCE a0,
    LPCWSTR a1,
    HWND a2,
    DLGPROC a3,
    LPARAM a4)
{
    _PrintEnter("DialogBoxParamW(%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    INT_PTR rv = 0;
    __try {
        rv = Real_DialogBoxParamW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DialogBoxParamW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DisableThreadLibraryCalls(HMODULE a0)
{
    _PrintEnter("DisableThreadLibraryCalls(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DisableThreadLibraryCalls(a0);
    }
    __finally {
        _PrintExit("DisableThreadLibraryCalls() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DisconnectNamedPipe(HANDLE a0)
{
    _PrintEnter("DisconnectNamedPipe(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DisconnectNamedPipe(a0);
    }
    __finally {
        _PrintExit("DisconnectNamedPipe() -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_DispatchMessageA(MSG* a0)
{
    _PrintEnter("DispatchMessageA(%p)\n", a0);

    LRESULT rv = 0;
    __try {
        rv = Real_DispatchMessageA(a0);
    }
    __finally {
        _PrintExit("DispatchMessageA() -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_DispatchMessageW(MSG* a0)
{
    _PrintEnter("DispatchMessageW(%p)\n", a0);

    LRESULT rv = 0;
    __try {
        rv = Real_DispatchMessageW(a0);
    }
    __finally {
        _PrintExit("DispatchMessageW() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_DlgDirListA(HWND a0,
    LPSTR a1,
    int a2,
    int a3,
    UINT a4)
{
    _PrintEnter("DlgDirListA(%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_DlgDirListA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DlgDirListA(,%hs,,,) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_DlgDirListComboBoxA(HWND a0,
    LPSTR a1,
    int a2,
    int a3,
    UINT a4)
{
    _PrintEnter("DlgDirListComboBoxA(%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_DlgDirListComboBoxA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DlgDirListComboBoxA(,%hs,,,) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_DlgDirListComboBoxW(HWND a0,
    LPWSTR a1,
    int a2,
    int a3,
    UINT a4)
{
    _PrintEnter("DlgDirListComboBoxW(%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_DlgDirListComboBoxW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DlgDirListComboBoxW(,%ls,,,) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_DlgDirListW(HWND a0,
    LPWSTR a1,
    int a2,
    int a3,
    UINT a4)
{
    _PrintEnter("DlgDirListW(%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_DlgDirListW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DlgDirListW(,%ls,,,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_DlgDirSelectComboBoxExA(HWND a0,
    LPSTR a1,
    int a2,
    int a3)
{
    _PrintEnter("DlgDirSelectComboBoxExA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_DlgDirSelectComboBoxExA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DlgDirSelectComboBoxExA(,%hs,,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_DlgDirSelectComboBoxExW(HWND a0,
    LPWSTR a1,
    int a2,
    int a3)
{
    _PrintEnter("DlgDirSelectComboBoxExW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_DlgDirSelectComboBoxExW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DlgDirSelectComboBoxExW(,%ls,,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_DlgDirSelectExA(HWND a0,
    LPSTR a1,
    int a2,
    int a3)
{
    _PrintEnter("DlgDirSelectExA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_DlgDirSelectExA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DlgDirSelectExA(,%hs,,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_DlgDirSelectExW(HWND a0,
    LPWSTR a1,
    int a2,
    int a3)
{
    _PrintEnter("DlgDirSelectExW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_DlgDirSelectExW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DlgDirSelectExW(,%ls,,) -> %p\n", a1, rv);
    };
    return rv;
}

HRESULT __stdcall Mine_DoDragDrop(IDataObject* a0,
    IDropSource* a1,
    DWORD a2,
    LPDWORD a3)
{
    _PrintEnter("DoDragDrop(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_DoDragDrop(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DoDragDrop(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DosDateTimeToFileTime(WORD a0,
    WORD a1,
    LPFILETIME a2)
{
    _PrintEnter("DosDateTimeToFileTime(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_DosDateTimeToFileTime(a0, a1, a2);
    }
    __finally {
        _PrintExit("DosDateTimeToFileTime(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DragDetect(HWND a0,
    POINT a1)
{
    _PrintEnter("DragDetect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_DragDetect(a0, a1);
    }
    __finally {
        _PrintExit("DragDetect(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_DragObject(HWND a0,
    HWND a1,
    UINT a2,
    ULONG_PTR a3,
    HCURSOR a4)
{
    _PrintEnter("DragObject(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_DragObject(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DragObject(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawAnimatedRects(HWND a0,
    int a1,
    RECT* a2,
    RECT* a3)
{
    _PrintEnter("DrawAnimatedRects(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_DrawAnimatedRects(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DrawAnimatedRects(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawCaption(HWND a0,
    HDC a1,
    RECT* a2,
    UINT a3)
{
    _PrintEnter("DrawCaption(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_DrawCaption(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DrawCaption(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawEdge(HDC a0,
    LPRECT a1,
    UINT a2,
    UINT a3)
{
    _PrintEnter("DrawEdge(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_DrawEdge(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DrawEdge(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_DrawEscape(HDC a0,
    int a1,
    int a2,
    LPCSTR a3)
{
    _PrintEnter("DrawEscape(%p,%p,%p,%hs)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_DrawEscape(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DrawEscape(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawFocusRect(HDC a0,
    RECT* a1)
{
    _PrintEnter("DrawFocusRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_DrawFocusRect(a0, a1);
    }
    __finally {
        _PrintExit("DrawFocusRect(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawFrameControl(HDC a0,
    LPRECT a1,
    UINT a2,
    UINT a3)
{
    _PrintEnter("DrawFrameControl(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_DrawFrameControl(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DrawFrameControl(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawIcon(HDC a0,
    int a1,
    int a2,
    HICON a3)
{
    _PrintEnter("DrawIcon(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_DrawIcon(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("DrawIcon(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawIconEx(HDC a0,
    int a1,
    int a2,
    HICON a3,
    int a4,
    int a5,
    UINT a6,
    HBRUSH a7,
    UINT a8)
{
    _PrintEnter("DrawIconEx(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    BOOL rv = 0;
    __try {
        rv = Real_DrawIconEx(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("DrawIconEx(,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawMenuBar(HWND a0)
{
    _PrintEnter("DrawMenuBar(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DrawMenuBar(a0);
    }
    __finally {
        _PrintExit("DrawMenuBar() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawStateA(HDC a0,
    HBRUSH a1,
    DRAWSTATEPROC a2,
    LPARAM a3,
    WPARAM a4,
    int a5,
    int a6,
    int a7,
    int a8,
    UINT a9)
{
    _PrintEnter("DrawStateA(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);

    BOOL rv = 0;
    __try {
        rv = Real_DrawStateA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
    __finally {
        _PrintExit("DrawStateA(,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DrawStateW(HDC a0,
    HBRUSH a1,
    DRAWSTATEPROC a2,
    LPARAM a3,
    WPARAM a4,
    int a5,
    int a6,
    int a7,
    int a8,
    UINT a9)
{
    _PrintEnter("DrawStateW(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);

    BOOL rv = 0;
    __try {
        rv = Real_DrawStateW(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
    __finally {
        _PrintExit("DrawStateW(,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_DrawTextA(HDC a0,
    LPCSTR a1,
    int a2,
    LPRECT a3,
    UINT a4)
{
    _PrintEnter("DrawTextA(%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_DrawTextA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DrawTextA(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_DrawTextExA(HDC a0,
    LPSTR a1,
    int a2,
    LPRECT a3,
    UINT a4,
    LPDRAWTEXTPARAMS a5)
{
    _PrintEnter("DrawTextExA(%p,%hs,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_DrawTextExA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("DrawTextExA(,%hs,,,,) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_DrawTextExW(HDC a0,
    LPWSTR a1,
    int a2,
    LPRECT a3,
    UINT a4,
    LPDRAWTEXTPARAMS a5)
{
    _PrintEnter("DrawTextExW(%p,%ls,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_DrawTextExW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("DrawTextExW(,%ls,,,,) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_DrawTextW(HDC a0,
    LPCWSTR a1,
    int a2,
    LPRECT a3,
    UINT a4)
{
    _PrintEnter("DrawTextW(%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_DrawTextW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("DrawTextW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_DuplicateHandle(HANDLE a0,
    HANDLE a1,
    HANDLE a2,
    LPHANDLE a3,
    DWORD a4,
    BOOL a5,
    DWORD a6)
{
    _PrintEnter("DuplicateHandle(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_DuplicateHandle(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("DuplicateHandle(,,,%p,,,) -> %p\n", a3 != NULL ? *a3 : NULL, rv);
    };
    return rv;
}

BOOL __stdcall Mine_Ellipse(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4)
{
    _PrintEnter("Ellipse(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_Ellipse(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("Ellipse(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EmptyClipboard(void)
{
    _PrintEnter("EmptyClipboard()\n");

    BOOL rv = 0;
    __try {
        rv = Real_EmptyClipboard();
    }
    __finally {
        _PrintExit("EmptyClipboard() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnableMenuItem(HMENU a0,
    UINT a1,
    UINT a2)
{
    _PrintEnter("EnableMenuItem(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnableMenuItem(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnableMenuItem(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnableScrollBar(HWND a0,
    UINT a1,
    UINT a2)
{
    _PrintEnter("EnableScrollBar(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnableScrollBar(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnableScrollBar(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnableWindow(HWND a0,
    BOOL a1)
{
    _PrintEnter("EnableWindow(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EnableWindow(a0, a1);
    }
    __finally {
        _PrintExit("EnableWindow(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EndDeferWindowPos(HDWP a0)
{
    _PrintEnter("EndDeferWindowPos(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_EndDeferWindowPos(a0);
    }
    __finally {
        _PrintExit("EndDeferWindowPos() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EndDialog(HWND a0,
    INT_PTR a1)
{
    _PrintEnter("EndDialog(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EndDialog(a0, a1);
    }
    __finally {
        _PrintExit("EndDialog(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EndDoc(HDC a0)
{
    _PrintEnter("EndDoc(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_EndDoc(a0);
    }
    __finally {
        _PrintExit("EndDoc() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EndPage(HDC a0)
{
    _PrintEnter("EndPage(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_EndPage(a0);
    }
    __finally {
        _PrintExit("EndPage() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EndPaint(HWND a0,
    PAINTSTRUCT* a1)
{
    _PrintEnter("EndPaint(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EndPaint(a0, a1);
    }
    __finally {
        _PrintExit("EndPaint(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EndPath(HDC a0)
{
    _PrintEnter("EndPath(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_EndPath(a0);
    }
    __finally {
        _PrintExit("EndPath() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EndUpdateResourceA(HANDLE a0,
    BOOL a1)
{
    _PrintEnter("EndUpdateResourceA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EndUpdateResourceA(a0, a1);
    }
    __finally {
        _PrintExit("EndUpdateResourceA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EndUpdateResourceW(HANDLE a0,
    BOOL a1)
{
    _PrintEnter("EndUpdateResourceW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EndUpdateResourceW(a0, a1);
    }
    __finally {
        _PrintExit("EndUpdateResourceW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumCalendarInfoA(CALINFO_ENUMPROCA a0,
    LCID a1,
    CALID a2,
    CALTYPE a3)
{
    _PrintEnter("EnumCalendarInfoA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_EnumCalendarInfoA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumCalendarInfoA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumCalendarInfoW(CALINFO_ENUMPROCW a0,
    LCID a1,
    CALID a2,
    CALTYPE a3)
{
    _PrintEnter("EnumCalendarInfoW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_EnumCalendarInfoW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumCalendarInfoW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumChildWindows(HWND a0,
    WNDENUMPROC a1,
    LPARAM a2)
{
    _PrintEnter("EnumChildWindows(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumChildWindows(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumChildWindows(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_EnumClipboardFormats(UINT a0)
{
    _PrintEnter("EnumClipboardFormats(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_EnumClipboardFormats(a0);
    }
    __finally {
        _PrintExit("EnumClipboardFormats() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumDateFormatsA(DATEFMT_ENUMPROCA a0,
    LCID a1,
    DWORD a2)
{
    _PrintEnter("EnumDateFormatsA(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumDateFormatsA(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumDateFormatsA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumDateFormatsW(DATEFMT_ENUMPROCW a0,
    LCID a1,
    DWORD a2)
{
    _PrintEnter("EnumDateFormatsW(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumDateFormatsW(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumDateFormatsW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumDesktopWindows(HDESK a0,
    WNDENUMPROC a1,
    LPARAM a2)
{
    _PrintEnter("EnumDesktopWindows(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumDesktopWindows(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumDesktopWindows(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumDesktopsA(HWINSTA a0,
    DESKTOPENUMPROCA a1,
    LPARAM a2)
{
    _PrintEnter("EnumDesktopsA(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumDesktopsA(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumDesktopsA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumDesktopsW(HWINSTA a0,
    DESKTOPENUMPROCW a1,
    LPARAM a2)
{
    _PrintEnter("EnumDesktopsW(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumDesktopsW(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumDesktopsW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumDisplaySettingsA(LPCSTR a0,
    DWORD a1,
    LPDEVMODEA a2)
{
    _PrintEnter("EnumDisplaySettingsA(%hs,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumDisplaySettingsA(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumDisplaySettingsA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumDisplaySettingsW(LPCWSTR a0,
    DWORD a1,
    LPDEVMODEW a2)
{
    _PrintEnter("EnumDisplaySettingsW(%ls,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumDisplaySettingsW(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumDisplaySettingsW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumEnhMetaFile(HDC a0,
    HENHMETAFILE a1,
    ENHMFENUMPROC a2,
    LPVOID a3,
    RECT* a4)
{
    _PrintEnter("EnumEnhMetaFile(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_EnumEnhMetaFile(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("EnumEnhMetaFile(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumFontFamiliesA(HDC a0,
    LPCSTR a1,
    FONTENUMPROCA a2,
    LPARAM a3)
{
    _PrintEnter("EnumFontFamiliesA(%p,%hs,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_EnumFontFamiliesA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumFontFamiliesA(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumFontFamiliesExA(HDC a0,
    LPLOGFONTA a1,
    FONTENUMPROCA a2,
    LPARAM a3,
    DWORD a4)
{
    _PrintEnter("EnumFontFamiliesExA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_EnumFontFamiliesExA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("EnumFontFamiliesExA(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumFontFamiliesExW(HDC a0,
    LPLOGFONTW a1,
    FONTENUMPROCW a2,
    LPARAM a3,
    DWORD a4)
{
    _PrintEnter("EnumFontFamiliesExW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_EnumFontFamiliesExW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("EnumFontFamiliesExW(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumFontFamiliesW(HDC a0,
    LPCWSTR a1,
    FONTENUMPROCW a2,
    LPARAM a3)
{
    _PrintEnter("EnumFontFamiliesW(%p,%ls,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_EnumFontFamiliesW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumFontFamiliesW(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumFontsA(HDC a0,
    LPCSTR a1,
    FONTENUMPROCA a2,
    LPARAM a3)
{
    _PrintEnter("EnumFontsA(%p,%hs,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_EnumFontsA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumFontsA(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumFontsW(HDC a0,
    LPCWSTR a1,
    FONTENUMPROCW a2,
    LPARAM a3)
{
    _PrintEnter("EnumFontsW(%p,%ls,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_EnumFontsW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumFontsW(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumICMProfilesA(HDC a0,
    ICMENUMPROCA a1,
    LPARAM a2)
{
    _PrintEnter("EnumICMProfilesA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_EnumICMProfilesA(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumICMProfilesA(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumICMProfilesW(HDC a0,
    ICMENUMPROCW a1,
    LPARAM a2)
{
    _PrintEnter("EnumICMProfilesW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_EnumICMProfilesW(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumICMProfilesW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumMetaFile(HDC a0,
    HMETAFILE a1,
    MFENUMPROC a2,
    LPARAM a3)
{
    _PrintEnter("EnumMetaFile(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_EnumMetaFile(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumMetaFile(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumObjects(HDC a0,
    int a1,
    GOBJENUMPROC a2,
    LPARAM a3)
{
    _PrintEnter("EnumObjects(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_EnumObjects(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumObjects(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumPropsA(HWND a0,
    PROPENUMPROCA a1)
{
    _PrintEnter("EnumPropsA(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_EnumPropsA(a0, a1);
    }
    __finally {
        _PrintExit("EnumPropsA(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumPropsExA(HWND a0,
    PROPENUMPROCEXA a1,
    LPARAM a2)
{
    _PrintEnter("EnumPropsExA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_EnumPropsExA(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumPropsExA(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumPropsExW(HWND a0,
    PROPENUMPROCEXW a1,
    LPARAM a2)
{
    _PrintEnter("EnumPropsExW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_EnumPropsExW(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumPropsExW(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_EnumPropsW(HWND a0,
    PROPENUMPROCW a1)
{
    _PrintEnter("EnumPropsW(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_EnumPropsW(a0, a1);
    }
    __finally {
        _PrintExit("EnumPropsW(,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
BOOL __stdcall Mine_EnumResourceLanguagesA(HMODULE a0,
    LPCSTR a1,
    LPCSTR a2,
    ENUMRESLANGPROC a3,
    LONG_PTR a4)
#else
BOOL __stdcall Mine_EnumResourceLanguagesA(HMODULE a0,
    LPCSTR a1,
    LPCSTR a2,
    ENUMRESLANGPROCA a3,
    LONG_PTR a4)
#endif
{
    _PrintEnter("EnumResourceLanguagesA(%p,%hs,%hs,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_EnumResourceLanguagesA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("EnumResourceLanguagesA(,,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
BOOL __stdcall Mine_EnumResourceLanguagesW(HMODULE a0,
    LPCWSTR a1,
    LPCWSTR a2,
    ENUMRESLANGPROC a3,
    LONG_PTR a4)
#else
BOOL __stdcall Mine_EnumResourceLanguagesW(HMODULE a0,
    LPCWSTR a1,
    LPCWSTR a2,
    ENUMRESLANGPROCW a3,
    LONG_PTR a4)
#endif
{
    _PrintEnter("EnumResourceLanguagesW(%p,%ls,%ls,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_EnumResourceLanguagesW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("EnumResourceLanguagesW(,,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
BOOL __stdcall Mine_EnumResourceNamesA(HMODULE a0,
    LPCSTR a1,
    ENUMRESNAMEPROC a2,
    LONG_PTR a3)
#else
BOOL __stdcall Mine_EnumResourceNamesA(HMODULE a0,
    LPCSTR a1,
    ENUMRESNAMEPROCA a2,
    LONG_PTR a3)
#endif
{
    _PrintEnter("EnumResourceNamesA(%p,%hs,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_EnumResourceNamesA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumResourceNamesA(,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
BOOL __stdcall Mine_EnumResourceNamesW(HMODULE a0,
    LPCWSTR a1,
    ENUMRESNAMEPROC a2,
    LONG_PTR a3)
#else
BOOL __stdcall Mine_EnumResourceNamesW(HMODULE a0,
    LPCWSTR a1,
    ENUMRESNAMEPROCW a2,
    LONG_PTR a3)
#endif
{
    _PrintEnter("EnumResourceNamesW(%p,%ls,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_EnumResourceNamesW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("EnumResourceNamesW(,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
BOOL __stdcall Mine_EnumResourceTypesA(HMODULE a0,
    ENUMRESTYPEPROC a1,
    LONG_PTR a2)
#else
BOOL __stdcall Mine_EnumResourceTypesA(HMODULE a0,
    ENUMRESTYPEPROCA a1,
    LONG_PTR a2)
#endif
{
    _PrintEnter("EnumResourceTypesA(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumResourceTypesA(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumResourceTypesA(,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
BOOL __stdcall Mine_EnumResourceTypesW(HMODULE a0,
    ENUMRESTYPEPROC a1,
    LONG_PTR a2)
#else
BOOL __stdcall Mine_EnumResourceTypesW(HMODULE a0,
    ENUMRESTYPEPROCW a1,
    LONG_PTR a2)
#endif
{
    _PrintEnter("EnumResourceTypesW(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumResourceTypesW(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumResourceTypesW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumSystemCodePagesA(CODEPAGE_ENUMPROCA a0,
    DWORD a1)
{
    _PrintEnter("EnumSystemCodePagesA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EnumSystemCodePagesA(a0, a1);
    }
    __finally {
        _PrintExit("EnumSystemCodePagesA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumSystemCodePagesW(CODEPAGE_ENUMPROCW a0,
    DWORD a1)
{
    _PrintEnter("EnumSystemCodePagesW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EnumSystemCodePagesW(a0, a1);
    }
    __finally {
        _PrintExit("EnumSystemCodePagesW(,) -> %p\n", rv);
    };
    return rv;
}

#if(WINVER >= 0x0500)
BOOL __stdcall Mine_EnumSystemLocalesA(LOCALE_ENUMPROCA a0,
    DWORD a1)
{
    _PrintEnter("EnumSystemLocalesA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EnumSystemLocalesA(a0, a1);
    }
    __finally {
        _PrintExit("EnumSystemLocalesA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumSystemLocalesW(LOCALE_ENUMPROCW a0,
    DWORD a1)
{
    _PrintEnter("EnumSystemLocalesW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EnumSystemLocalesW(a0, a1);
    }
    __finally {
        _PrintExit("EnumSystemLocalesW(,) -> %p\n", rv);
    };
    return rv;
}
#endif // (WINVER >= 0x0500)

BOOL __stdcall Mine_EnumThreadWindows(DWORD a0,
    WNDENUMPROC a1,
    LPARAM a2)
{
    _PrintEnter("EnumThreadWindows(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumThreadWindows(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumThreadWindows(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumTimeFormatsA(TIMEFMT_ENUMPROCA a0,
    LCID a1,
    DWORD a2)
{
    _PrintEnter("EnumTimeFormatsA(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumTimeFormatsA(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumTimeFormatsA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumTimeFormatsW(TIMEFMT_ENUMPROCW a0,
    LCID a1,
    DWORD a2)
{
    _PrintEnter("EnumTimeFormatsW(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_EnumTimeFormatsW(a0, a1, a2);
    }
    __finally {
        _PrintExit("EnumTimeFormatsW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumWindowStationsA(WINSTAENUMPROCA a0,
    LPARAM a1)
{
    _PrintEnter("EnumWindowStationsA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EnumWindowStationsA(a0, a1);
    }
    __finally {
        _PrintExit("EnumWindowStationsA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumWindowStationsW(WINSTAENUMPROCW a0,
    LPARAM a1)
{
    _PrintEnter("EnumWindowStationsW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EnumWindowStationsW(a0, a1);
    }
    __finally {
        _PrintExit("EnumWindowStationsW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EnumWindows(WNDENUMPROC a0,
    LPARAM a1)
{
    _PrintEnter("EnumWindows(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EnumWindows(a0, a1);
    }
    __finally {
        _PrintExit("EnumWindows(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EqualRect(RECT* a0,
    RECT* a1)
{
    _PrintEnter("EqualRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EqualRect(a0, a1);
    }
    __finally {
        _PrintExit("EqualRect(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EqualRgn(HRGN a0,
    HRGN a1)
{
    _PrintEnter("EqualRgn(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EqualRgn(a0, a1);
    }
    __finally {
        _PrintExit("EqualRgn(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_EraseTape(HANDLE a0,
    DWORD a1,
    BOOL a2)
{
    _PrintEnter("EraseTape(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_EraseTape(a0, a1, a2);
    }
    __finally {
        _PrintExit("EraseTape(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_Escape(HDC a0,
    int a1,
    int a2,
    LPCSTR a3,
    LPVOID a4)
{
    _PrintEnter("Escape(%p,%p,%p,%hs,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_Escape(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("Escape(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_EscapeCommFunction(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("EscapeCommFunction(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_EscapeCommFunction(a0, a1);
    }
    __finally {
        _PrintExit("EscapeCommFunction(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ExcludeClipRect(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4)
{
    _PrintEnter("ExcludeClipRect(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_ExcludeClipRect(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ExcludeClipRect(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ExcludeUpdateRgn(HDC a0,
    HWND a1)
{
    _PrintEnter("ExcludeUpdateRgn(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_ExcludeUpdateRgn(a0, a1);
    }
    __finally {
        _PrintExit("ExcludeUpdateRgn(,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_ExitProcess(UINT a0)
{
    _PrintEnter("ExitProcess(%p)\n", a0);

    __try {
        Real_ExitProcess(a0);
    }
    __finally {
        _PrintExit("ExitProcess() ->\n");
    };
}

void __stdcall Mine_ExitThread(DWORD a0)
{
    _PrintEnter("ExitThread(%p)\n", a0);

    __try {
        Real_ExitThread(a0);
    }
    __finally {
        _PrintExit("ExitThread() ->\n");
    };
}

BOOL __stdcall Mine_ExitWindowsEx(UINT a0,
    DWORD a1)
{
    _PrintEnter("ExitWindowsEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ExitWindowsEx(a0, a1);
    }
    __finally {
        _PrintExit("ExitWindowsEx(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_ExpandEnvironmentStringsA(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("ExpandEnvironmentStringsA(%hs,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_ExpandEnvironmentStringsA(a0, a1, a2);
    }
    __finally {
        _PrintExit("ExpandEnvironmentStringsA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_ExpandEnvironmentStringsW(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
{
    _PrintEnter("ExpandEnvironmentStringsW(%ls,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_ExpandEnvironmentStringsW(a0, a1, a2);
    }
    __finally {
        _PrintExit("ExpandEnvironmentStringsW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

HPEN __stdcall Mine_ExtCreatePen(DWORD a0,
    DWORD a1,
    LOGBRUSH* a2,
    DWORD a3,
    DWORD* a4)
{
    _PrintEnter("ExtCreatePen(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HPEN rv = 0;
    __try {
        rv = Real_ExtCreatePen(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ExtCreatePen(,,,,) -> %p\n", rv);
    };
    return rv;
}

HRGN __stdcall Mine_ExtCreateRegion(XFORM* a0,
    DWORD a1,
    RGNDATA* a2)
{
    _PrintEnter("ExtCreateRegion(%p,%p,%p)\n", a0, a1, a2);

    HRGN rv = 0;
    __try {
        rv = Real_ExtCreateRegion(a0, a1, a2);
    }
    __finally {
        _PrintExit("ExtCreateRegion(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ExtEscape(HDC a0,
    int a1,
    int a2,
    LPCSTR a3,
    int a4,
    LPSTR a5)
{
    _PrintEnter("ExtEscape(%p,%p,%p,%hs,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_ExtEscape(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("ExtEscape(,,,,,%hs) -> %p\n", a5, rv);
    };
    return rv;
}

BOOL __stdcall Mine_ExtFloodFill(HDC a0,
    int a1,
    int a2,
    COLORREF a3,
    UINT a4)
{
    _PrintEnter("ExtFloodFill(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ExtFloodFill(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ExtFloodFill(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ExtSelectClipRgn(HDC a0,
    HRGN a1,
    int a2)
{
    _PrintEnter("ExtSelectClipRgn(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_ExtSelectClipRgn(a0, a1, a2);
    }
    __finally {
        _PrintExit("ExtSelectClipRgn(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ExtTextOutA(HDC a0,
    int a1,
    int a2,
    UINT a3,
    RECT* a4,
    LPCSTR a5,
    UINT a6,
    INT* a7)
{
    _PrintEnter("ExtTextOutA(%p,%p,%p,%p,%p,%hs,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    BOOL rv = 0;
    __try {
        rv = Real_ExtTextOutA(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("ExtTextOutA(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ExtTextOutW(HDC a0,
    int a1,
    int a2,
    UINT a3,
    RECT* a4,
    LPCWSTR a5,
    UINT a6,
    INT* a7)
{
    _PrintEnter("ExtTextOutW(%p,%p,%p,%p,%p,%ls,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    BOOL rv = 0;
    __try {
        rv = Real_ExtTextOutW(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("ExtTextOutW(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_FatalAppExitA(UINT a0,
    LPCSTR a1)
{
    _PrintEnter("FatalAppExitA(%p,%hs)\n", a0, a1);

    __try {
        Real_FatalAppExitA(a0, a1);
    }
    __finally {
        _PrintExit("FatalAppExitA(,) ->\n");
    };
}

void __stdcall Mine_FatalAppExitW(UINT a0,
    LPCWSTR a1)
{
    _PrintEnter("FatalAppExitW(%p,%ls)\n", a0, a1);

    __try {
        Real_FatalAppExitW(a0, a1);
    }
    __finally {
        _PrintExit("FatalAppExitW(,) ->\n");
    };
}

void __stdcall Mine_FatalExit(int a0)
{
    _PrintEnter("FatalExit(%p)\n", a0);

    __try {
        Real_FatalExit(a0);
    }
    __finally {
        _PrintExit("FatalExit() ->\n");
    };
}

BOOL __stdcall Mine_FileTimeToDosDateTime(FILETIME* a0,
    LPWORD a1,
    LPWORD a2)
{
    _PrintEnter("FileTimeToDosDateTime(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_FileTimeToDosDateTime(a0, a1, a2);
    }
    __finally {
        _PrintExit("FileTimeToDosDateTime(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FileTimeToLocalFileTime(FILETIME* a0,
    LPFILETIME a1)
{
    _PrintEnter("FileTimeToLocalFileTime(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_FileTimeToLocalFileTime(a0, a1);
    }
    __finally {
        _PrintExit("FileTimeToLocalFileTime(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FileTimeToSystemTime(FILETIME* a0,
    LPSYSTEMTIME a1)
{
    _PrintEnter("FileTimeToSystemTime(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_FileTimeToSystemTime(a0, a1);
    }
    __finally {
        _PrintExit("FileTimeToSystemTime(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FillConsoleOutputAttribute(HANDLE a0,
    WORD a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
{
    _PrintEnter("FillConsoleOutputAttribute(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_FillConsoleOutputAttribute(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("FillConsoleOutputAttribute(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FillConsoleOutputCharacterA(HANDLE a0,
    CHAR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
{
    _PrintEnter("FillConsoleOutputCharacterA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_FillConsoleOutputCharacterA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("FillConsoleOutputCharacterA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FillConsoleOutputCharacterW(HANDLE a0,
    WCHAR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
{
    _PrintEnter("FillConsoleOutputCharacterW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_FillConsoleOutputCharacterW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("FillConsoleOutputCharacterW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FillPath(HDC a0)
{
    _PrintEnter("FillPath(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FillPath(a0);
    }
    __finally {
        _PrintExit("FillPath() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_FillRect(HDC a0,
    RECT* a1,
    HBRUSH a2)
{
    _PrintEnter("FillRect(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_FillRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("FillRect(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FillRgn(HDC a0,
    HRGN a1,
    HBRUSH a2)
{
    _PrintEnter("FillRgn(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_FillRgn(a0, a1, a2);
    }
    __finally {
        _PrintExit("FillRgn(,,) -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_FindAtomA(LPCSTR a0)
{
    _PrintEnter("FindAtomA(%hs)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_FindAtomA(a0);
    }
    __finally {
        _PrintExit("FindAtomA() -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_FindAtomW(LPCWSTR a0)
{
    _PrintEnter("FindAtomW(%ls)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_FindAtomW(a0);
    }
    __finally {
        _PrintExit("FindAtomW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FindClose(HANDLE a0)
{
    _PrintEnter("FindClose(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FindClose(a0);
    }
    __finally {
        _PrintExit("FindClose() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FindCloseChangeNotification(HANDLE a0)
{
    _PrintEnter("FindCloseChangeNotification(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FindCloseChangeNotification(a0);
    }
    __finally {
        _PrintExit("FindCloseChangeNotification() -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_FindFirstChangeNotificationA(LPCSTR a0,
    BOOL a1,
    DWORD a2)
{
    _PrintEnter("FindFirstChangeNotificationA(%hs,%p,%p)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_FindFirstChangeNotificationA(a0, a1, a2);
    }
    __finally {
        _PrintExit("FindFirstChangeNotificationA(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_FindFirstChangeNotificationW(LPCWSTR a0,
    BOOL a1,
    DWORD a2)
{
    _PrintEnter("FindFirstChangeNotificationW(%ls,%p,%p)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_FindFirstChangeNotificationW(a0, a1, a2);
    }
    __finally {
        _PrintExit("FindFirstChangeNotificationW(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_FindFirstFileA(LPCSTR a0,
    LPWIN32_FIND_DATAA a1)
{
    _PrintEnter("FindFirstFileA(%hs,%p)\n", a0, a1);

    HANDLE rv = 0;
    __try {
        rv = Real_FindFirstFileA(a0, a1);
    }
    __finally {
        _PrintExit("FindFirstFileA(,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_FindFirstFileExA(LPCSTR a0,
    FINDEX_INFO_LEVELS a1,
    LPVOID a2,
    FINDEX_SEARCH_OPS a3,
    LPVOID a4,
    DWORD a5)
{
    _PrintEnter("FindFirstFileExA(%hs,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_FindFirstFileExA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("FindFirstFileExA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_FindFirstFileExW(LPCWSTR a0,
    FINDEX_INFO_LEVELS a1,
    LPVOID a2,
    FINDEX_SEARCH_OPS a3,
    LPVOID a4,
    DWORD a5)
{
    _PrintEnter("FindFirstFileExW(%ls,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_FindFirstFileExW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("FindFirstFileExW(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_FindFirstFileW(LPCWSTR a0,
    LPWIN32_FIND_DATAW a1)
{
    _PrintEnter("FindFirstFileW(%ls,%p)\n", a0, a1);

    HANDLE rv = 0;
    __try {
        rv = Real_FindFirstFileW(a0, a1);
    }
    __finally {
        _PrintExit("FindFirstFileW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FindNextChangeNotification(HANDLE a0)
{
    _PrintEnter("FindNextChangeNotification(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FindNextChangeNotification(a0);
    }
    __finally {
        _PrintExit("FindNextChangeNotification() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FindNextFileA(HANDLE a0,
    LPWIN32_FIND_DATAA a1)
{
    _PrintEnter("FindNextFileA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_FindNextFileA(a0, a1);
    }
    __finally {
        _PrintExit("FindNextFileA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FindNextFileW(HANDLE a0,
    LPWIN32_FIND_DATAW a1)
{
    _PrintEnter("FindNextFileW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_FindNextFileW(a0, a1);
    }
    __finally {
        _PrintExit("FindNextFileW(,) -> %p\n", rv);
    };
    return rv;
}

HRSRC __stdcall Mine_FindResourceA(HMODULE a0,
    LPCSTR a1,
    LPCSTR a2)
{
    _PrintEnter("FindResourceA(%p,%hs,%hs)\n", a0, a1, a2);

    HRSRC rv = 0;
    __try {
        rv = Real_FindResourceA(a0, a1, a2);
    }
    __finally {
        _PrintExit("FindResourceA(,,) -> %p\n", rv);
    };
    return rv;
}

HRSRC __stdcall Mine_FindResourceExA(HMODULE a0,
    LPCSTR a1,
    LPCSTR a2,
    WORD a3)
{
    _PrintEnter("FindResourceExA(%p,%hs,%hs,%p)\n", a0, a1, a2, a3);

    HRSRC rv = 0;
    __try {
        rv = Real_FindResourceExA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("FindResourceExA(,,,) -> %p\n", rv);
    };
    return rv;
}

HRSRC __stdcall Mine_FindResourceExW(HMODULE a0,
    LPCWSTR a1,
    LPCWSTR a2,
    WORD a3)
{
    _PrintEnter("FindResourceExW(%p,%ls,%ls,%p)\n", a0, a1, a2, a3);

    HRSRC rv = 0;
    __try {
        rv = Real_FindResourceExW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("FindResourceExW(,,,) -> %p\n", rv);
    };
    return rv;
}

HRSRC __stdcall Mine_FindResourceW(HMODULE a0,
    LPCWSTR a1,
    LPCWSTR a2)
{
    _PrintEnter("FindResourceW(%p,%ls,%ls)\n", a0, a1, a2);

    HRSRC rv = 0;
    __try {
        rv = Real_FindResourceW(a0, a1, a2);
    }
    __finally {
        _PrintExit("FindResourceW(,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_FindWindowA(LPCSTR a0,
    LPCSTR a1)
{
    _PrintEnter("FindWindowA(%hs,%hs)\n", a0, a1);

    HWND rv = 0;
    __try {
        rv = Real_FindWindowA(a0, a1);
    }
    __finally {
        _PrintExit("FindWindowA(,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_FindWindowExA(HWND a0,
    HWND a1,
    LPCSTR a2,
    LPCSTR a3)
{
    _PrintEnter("FindWindowExA(%p,%p,%hs,%hs)\n", a0, a1, a2, a3);

    HWND rv = 0;
    __try {
        rv = Real_FindWindowExA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("FindWindowExA(,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_FindWindowExW(HWND a0,
    HWND a1,
    LPCWSTR a2,
    LPCWSTR a3)
{
    _PrintEnter("FindWindowExW(%p,%p,%ls,%ls)\n", a0, a1, a2, a3);

    HWND rv = 0;
    __try {
        rv = Real_FindWindowExW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("FindWindowExW(,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_FindWindowW(LPCWSTR a0,
    LPCWSTR a1)
{
    _PrintEnter("FindWindowW(%ls,%ls)\n", a0, a1);

    HWND rv = 0;
    __try {
        rv = Real_FindWindowW(a0, a1);
    }
    __finally {
        _PrintExit("FindWindowW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FixBrushOrgEx(HDC a0,
    int a1,
    int a2,
    POINT* a3)
{
    _PrintEnter("FixBrushOrgEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_FixBrushOrgEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("FixBrushOrgEx(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FlashWindow(HWND a0,
    BOOL a1)
{
    _PrintEnter("FlashWindow(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_FlashWindow(a0, a1);
    }
    __finally {
        _PrintExit("FlashWindow(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FlattenPath(HDC a0)
{
    _PrintEnter("FlattenPath(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FlattenPath(a0);
    }
    __finally {
        _PrintExit("FlattenPath() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FloodFill(HDC a0,
    int a1,
    int a2,
    COLORREF a3)
{
    _PrintEnter("FloodFill(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_FloodFill(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("FloodFill(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FlushConsoleInputBuffer(HANDLE a0)
{
    _PrintEnter("FlushConsoleInputBuffer(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FlushConsoleInputBuffer(a0);
    }
    __finally {
        _PrintExit("FlushConsoleInputBuffer() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FlushFileBuffers(HANDLE a0)
{
    _PrintEnter("FlushFileBuffers(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FlushFileBuffers(a0);
    }
    __finally {
        _PrintExit("FlushFileBuffers() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FlushViewOfFile(LPCVOID a0,
    SIZE_T a1)
{
    _PrintEnter("FlushViewOfFile(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_FlushViewOfFile(a0, a1);
    }
    __finally {
        _PrintExit("FlushViewOfFile(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_FmtIdToPropStgName(FMTID* a0,
    LPOLESTR a1)
{
    _PrintEnter("FmtIdToPropStgName(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_FmtIdToPropStgName(a0, a1);
    }
    __finally {
        _PrintExit("FmtIdToPropStgName(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_FoldStringA(DWORD a0,
    LPCSTR a1,
    int a2,
    LPSTR a3,
    int a4)
{
    _PrintEnter("FoldStringA(%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_FoldStringA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("FoldStringA(,,,%hs,) -> %p\n", a3, rv);
    };
    return rv;
}

int __stdcall Mine_FoldStringW(DWORD a0,
    LPCWSTR a1,
    int a2,
    LPWSTR a3,
    int a4)
{
    _PrintEnter("FoldStringW(%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_FoldStringW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("FoldStringW(,,,%ls,) -> %p\n", a3, rv);
    };
    return rv;
}

DWORD __stdcall Mine_FormatMessageA(DWORD a0,
    LPCVOID a1,
    DWORD a2,
    DWORD a3,
    LPSTR a4,
    DWORD a5,
    va_list* a6)
{
    _PrintEnter("FormatMessageA(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    DWORD rv = 0;
    __try {
        rv = Real_FormatMessageA(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("FormatMessageA(,,,,%hs,,) -> %p\n", a4, rv);
    };
    return rv;
}

DWORD __stdcall Mine_FormatMessageW(DWORD a0,
    LPCVOID a1,
    DWORD a2,
    DWORD a3,
    LPWSTR a4,
    DWORD a5,
    va_list* a6)
{
    _PrintEnter("FormatMessageW(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    DWORD rv = 0;
    __try {
        rv = Real_FormatMessageW(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("FormatMessageW(,,,,%ls,,) -> %p\n", a4, rv);
    };
    return rv;
}

int __stdcall Mine_FrameRect(HDC a0,
    RECT* a1,
    HBRUSH a2)
{
    _PrintEnter("FrameRect(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_FrameRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("FrameRect(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FrameRgn(HDC a0,
    HRGN a1,
    HBRUSH a2,
    int a3,
    int a4)
{
    _PrintEnter("FrameRgn(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_FrameRgn(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("FrameRgn(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FreeConsole(void)
{
    _PrintEnter("FreeConsole()\n");

    BOOL rv = 0;
    __try {
        rv = Real_FreeConsole();
    }
    __finally {
        _PrintExit("FreeConsole() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FreeDDElParam(UINT a0,
    LPARAM a1)
{
    _PrintEnter("FreeDDElParam(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_FreeDDElParam(a0, a1);
    }
    __finally {
        _PrintExit("FreeDDElParam(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FreeEnvironmentStringsA(LPSTR a0)
{
    _PrintEnter("FreeEnvironmentStringsA(%hs)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FreeEnvironmentStringsA(a0);
    }
    __finally {
        _PrintExit("FreeEnvironmentStringsA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FreeEnvironmentStringsW(LPWSTR a0)
{
    _PrintEnter("FreeEnvironmentStringsW(%ls)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FreeEnvironmentStringsW(a0);
    }
    __finally {
        _PrintExit("FreeEnvironmentStringsW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FreeLibrary(HMODULE a0)
{
    _PrintEnter("FreeLibrary(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FreeLibrary(a0);
    }
    __finally {
        _PrintExit("FreeLibrary() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_FreeLibraryAndExitThread(HMODULE a0,
    DWORD a1)
{
    _PrintEnter("FreeLibraryAndExitThread(%p,%p)\n", a0, a1);

    __try {
        Real_FreeLibraryAndExitThread(a0, a1);
    }
    __finally {
        _PrintExit("FreeLibraryAndExitThread(,) ->\n");
    };
}

HRESULT __stdcall Mine_FreePropVariantArray(ULONG a0,
    PROPVARIANT* a1)
{
    _PrintEnter("FreePropVariantArray(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_FreePropVariantArray(a0, a1);
    }
    __finally {
        _PrintExit("FreePropVariantArray(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_FreeResource(HGLOBAL a0)
{
    _PrintEnter("FreeResource(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FreeResource(a0);
    }
    __finally {
        _PrintExit("FreeResource() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GdiComment(HDC a0,
    UINT a1,
    BYTE* a2)
{
    _PrintEnter("GdiComment(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GdiComment(a0, a1, a2);
    }
    __finally {
        _PrintExit("GdiComment(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GdiFlush(void)
{
    _PrintEnter("GdiFlush()\n");

    BOOL rv = 0;
    __try {
        rv = Real_GdiFlush();
    }
    __finally {
        _PrintExit("GdiFlush() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GdiGetBatchLimit(void)
{
    _PrintEnter("GdiGetBatchLimit()\n");

    DWORD rv = 0;
    __try {
        rv = Real_GdiGetBatchLimit();
    }
    __finally {
        _PrintExit("GdiGetBatchLimit() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GdiSetBatchLimit(DWORD a0)
{
    _PrintEnter("GdiSetBatchLimit(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GdiSetBatchLimit(a0);
    }
    __finally {
        _PrintExit("GdiSetBatchLimit() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GenerateConsoleCtrlEvent(DWORD a0,
    DWORD a1)
{
    _PrintEnter("GenerateConsoleCtrlEvent(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GenerateConsoleCtrlEvent(a0, a1);
    }
    __finally {
        _PrintExit("GenerateConsoleCtrlEvent(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetACP(void)
{
    _PrintEnter("GetACP()\n");

    UINT rv = 0;
    __try {
        rv = Real_GetACP();
    }
    __finally {
        _PrintExit("GetACP() -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetActiveWindow(void)
{
    _PrintEnter("GetActiveWindow()\n");

    HWND rv = 0;
    __try {
        rv = Real_GetActiveWindow();
    }
    __finally {
        _PrintExit("GetActiveWindow() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetArcDirection(HDC a0)
{
    _PrintEnter("GetArcDirection(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetArcDirection(a0);
    }
    __finally {
        _PrintExit("GetArcDirection() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetAspectRatioFilterEx(HDC a0,
    SIZE* a1)
{
    _PrintEnter("GetAspectRatioFilterEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetAspectRatioFilterEx(a0, a1);
    }
    __finally {
        _PrintExit("GetAspectRatioFilterEx(,) -> %p\n", rv);
    };
    return rv;
}

SHORT __stdcall Mine_GetAsyncKeyState(int a0)
{
    _PrintEnter("GetAsyncKeyState(%p)\n", a0);

    SHORT rv = 0;
    __try {
        rv = Real_GetAsyncKeyState(a0);
    }
    __finally {
        _PrintExit("GetAsyncKeyState() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetAtomNameA(ATOM a0,
    LPSTR a1,
    int a2)
{
    _PrintEnter("GetAtomNameA(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetAtomNameA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetAtomNameA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetAtomNameW(ATOM a0,
    LPWSTR a1,
    int a2)
{
    _PrintEnter("GetAtomNameW(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetAtomNameW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetAtomNameW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetBinaryTypeA(LPCSTR a0,
    LPDWORD a1)
{
    _PrintEnter("GetBinaryTypeA(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetBinaryTypeA(a0, a1);
    }
    __finally {
        _PrintExit("GetBinaryTypeA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetBinaryTypeW(LPCWSTR a0,
    LPDWORD a1)
{
    _PrintEnter("GetBinaryTypeW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetBinaryTypeW(a0, a1);
    }
    __finally {
        _PrintExit("GetBinaryTypeW(,) -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_GetBitmapBits(HBITMAP a0,
    LONG a1,
    LPVOID a2)
{
    _PrintEnter("GetBitmapBits(%p,%p,%p)\n", a0, a1, a2);

    LONG rv = 0;
    __try {
        rv = Real_GetBitmapBits(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetBitmapBits(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetBitmapDimensionEx(HBITMAP a0,
    SIZE* a1)
{
    _PrintEnter("GetBitmapDimensionEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetBitmapDimensionEx(a0, a1);
    }
    __finally {
        _PrintExit("GetBitmapDimensionEx(,) -> %p\n", rv);
    };
    return rv;
}

COLORREF __stdcall Mine_GetBkColor(HDC a0)
{
    _PrintEnter("GetBkColor(%p)\n", a0);

    COLORREF rv = 0;
    __try {
        rv = Real_GetBkColor(a0);
    }
    __finally {
        _PrintExit("GetBkColor() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetBkMode(HDC a0)
{
    _PrintEnter("GetBkMode(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetBkMode(a0);
    }
    __finally {
        _PrintExit("GetBkMode() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetBoundsRect(HDC a0,
    LPRECT a1,
    UINT a2)
{
    _PrintEnter("GetBoundsRect(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetBoundsRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetBoundsRect(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetBrushOrgEx(HDC a0,
    POINT* a1)
{
    _PrintEnter("GetBrushOrgEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetBrushOrgEx(a0, a1);
    }
    __finally {
        _PrintExit("GetBrushOrgEx(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCPInfo(UINT a0,
    LPCPINFO a1)
{
    _PrintEnter("GetCPInfo(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetCPInfo(a0, a1);
    }
    __finally {
        _PrintExit("GetCPInfo(,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetCapture(void)
{
    _PrintEnter("GetCapture()\n");

    HWND rv = 0;
    __try {
        rv = Real_GetCapture();
    }
    __finally {
        _PrintExit("GetCapture() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetCaretBlinkTime(void)
{
    _PrintEnter("GetCaretBlinkTime()\n");

    UINT rv = 0;
    __try {
        rv = Real_GetCaretBlinkTime();
    }
    __finally {
        _PrintExit("GetCaretBlinkTime() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCaretPos(POINT* a0)
{
    _PrintEnter("GetCaretPos(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetCaretPos(a0);
    }
    __finally {
        _PrintExit("GetCaretPos() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharABCWidthsA(HDC a0,
    UINT a1,
    UINT a2,
    LPABC a3)
{
    _PrintEnter("GetCharABCWidthsA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharABCWidthsA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharABCWidthsA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharABCWidthsFloatA(HDC a0,
    UINT a1,
    UINT a2,
    LPABCFLOAT a3)
{
    _PrintEnter("GetCharABCWidthsFloatA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharABCWidthsFloatA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharABCWidthsFloatA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharABCWidthsFloatW(HDC a0,
    UINT a1,
    UINT a2,
    LPABCFLOAT a3)
{
    _PrintEnter("GetCharABCWidthsFloatW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharABCWidthsFloatW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharABCWidthsFloatW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharABCWidthsW(HDC a0,
    UINT a1,
    UINT a2,
    LPABC a3)
{
    _PrintEnter("GetCharABCWidthsW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharABCWidthsW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharABCWidthsW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharWidth32A(HDC a0,
    UINT a1,
    UINT a2,
    LPINT a3)
{
    _PrintEnter("GetCharWidth32A(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharWidth32A(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharWidth32A(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharWidth32W(HDC a0,
    UINT a1,
    UINT a2,
    LPINT a3)
{
    _PrintEnter("GetCharWidth32W(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharWidth32W(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharWidth32W(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharWidthA(HDC a0,
    UINT a1,
    UINT a2,
    LPINT a3)
{
    _PrintEnter("GetCharWidthA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharWidthA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharWidthA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharWidthFloatA(HDC a0,
    UINT a1,
    UINT a2,
    PFLOAT a3)
{
    _PrintEnter("GetCharWidthFloatA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharWidthFloatA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharWidthFloatA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharWidthFloatW(HDC a0,
    UINT a1,
    UINT a2,
    PFLOAT a3)
{
    _PrintEnter("GetCharWidthFloatW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharWidthFloatW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharWidthFloatW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCharWidthW(HDC a0,
    UINT a1,
    UINT a2,
    LPINT a3)
{
    _PrintEnter("GetCharWidthW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetCharWidthW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetCharWidthW(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetCharacterPlacementA(HDC a0,
    LPCSTR a1,
    int a2,
    int a3,
    LPGCP_RESULTSA a4,
    DWORD a5)
{
    _PrintEnter("GetCharacterPlacementA(%p,%hs,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    DWORD rv = 0;
    __try {
        rv = Real_GetCharacterPlacementA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetCharacterPlacementA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetCharacterPlacementW(HDC a0,
    LPCWSTR a1,
    int a2,
    int a3,
    LPGCP_RESULTSW a4,
    DWORD a5)
{
    _PrintEnter("GetCharacterPlacementW(%p,%ls,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    DWORD rv = 0;
    __try {
        rv = Real_GetCharacterPlacementW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetCharacterPlacementW(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_GetClassFile(LPCOLESTR a0,
    CLSID* a1)
{
    _PrintEnter("GetClassFile(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_GetClassFile(a0, a1);
    }
    __finally {
        _PrintExit("GetClassFile(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetClassInfoA(HINSTANCE a0,
    LPCSTR a1,
    LPWNDCLASSA a2)
{
    _PrintEnter("GetClassInfoA(%p,%hs,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetClassInfoA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetClassInfoA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetClassInfoExA(HINSTANCE a0,
    LPCSTR a1,
    LPWNDCLASSEXA a2)
{
    _PrintEnter("GetClassInfoExA(%p,%hs,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetClassInfoExA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetClassInfoExA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetClassInfoExW(HINSTANCE a0,
    LPCWSTR a1,
    LPWNDCLASSEXW a2)
{
    _PrintEnter("GetClassInfoExW(%p,%ls,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetClassInfoExW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetClassInfoExW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetClassInfoW(HINSTANCE a0,
    LPCWSTR a1,
    LPWNDCLASSW a2)
{
    _PrintEnter("GetClassInfoW(%p,%ls,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetClassInfoW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetClassInfoW(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetClassLongA(HWND a0,
    int a1)
{
    _PrintEnter("GetClassLongA(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetClassLongA(a0, a1);
    }
    __finally {
        _PrintExit("GetClassLongA(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetClassLongW(HWND a0,
    int a1)
{
    _PrintEnter("GetClassLongW(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetClassLongW(a0, a1);
    }
    __finally {
        _PrintExit("GetClassLongW(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetClassNameA(HWND a0,
    LPSTR a1,
    int a2)
{
    _PrintEnter("GetClassNameA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetClassNameA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetClassNameA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_GetClassNameW(HWND a0,
    LPWSTR a1,
    int a2)
{
    _PrintEnter("GetClassNameW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetClassNameW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetClassNameW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

WORD __stdcall Mine_GetClassWord(HWND a0,
    int a1)
{
    _PrintEnter("GetClassWord(%p,%p)\n", a0, a1);

    WORD rv = 0;
    __try {
        rv = Real_GetClassWord(a0, a1);
    }
    __finally {
        _PrintExit("GetClassWord(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetClientRect(HWND a0,
    LPRECT a1)
{
    _PrintEnter("GetClientRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetClientRect(a0, a1);
    }
    __finally {
        _PrintExit("GetClientRect(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetClipBox(HDC a0,
    LPRECT a1)
{
    _PrintEnter("GetClipBox(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetClipBox(a0, a1);
    }
    __finally {
        _PrintExit("GetClipBox(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetClipCursor(LPRECT a0)
{
    _PrintEnter("GetClipCursor(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetClipCursor(a0);
    }
    __finally {
        _PrintExit("GetClipCursor() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetClipRgn(HDC a0,
    HRGN a1)
{
    _PrintEnter("GetClipRgn(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetClipRgn(a0, a1);
    }
    __finally {
        _PrintExit("GetClipRgn(,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_GetClipboardData(UINT a0)
{
    _PrintEnter("GetClipboardData(%p)\n", a0);

    HANDLE rv = 0;
    __try {
        rv = Real_GetClipboardData(a0);
    }
    __finally {
        _PrintExit("GetClipboardData() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetClipboardFormatNameA(UINT a0,
    LPSTR a1,
    int a2)
{
    _PrintEnter("GetClipboardFormatNameA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetClipboardFormatNameA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetClipboardFormatNameA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_GetClipboardFormatNameW(UINT a0,
    LPWSTR a1,
    int a2)
{
    _PrintEnter("GetClipboardFormatNameW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetClipboardFormatNameW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetClipboardFormatNameW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

HWND __stdcall Mine_GetClipboardOwner(void)
{
    _PrintEnter("GetClipboardOwner()\n");

    HWND rv = 0;
    __try {
        rv = Real_GetClipboardOwner();
    }
    __finally {
        _PrintExit("GetClipboardOwner() -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetClipboardViewer(void)
{
    _PrintEnter("GetClipboardViewer()\n");

    HWND rv = 0;
    __try {
        rv = Real_GetClipboardViewer();
    }
    __finally {
        _PrintExit("GetClipboardViewer() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetColorAdjustment(HDC a0,
    LPCOLORADJUSTMENT a1)
{
    _PrintEnter("GetColorAdjustment(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetColorAdjustment(a0, a1);
    }
    __finally {
        _PrintExit("GetColorAdjustment(,) -> %p\n", rv);
    };
    return rv;
}

HCOLORSPACE __stdcall Mine_GetColorSpace(HDC a0)
{
    _PrintEnter("GetColorSpace(%p)\n", a0);

    HCOLORSPACE rv = 0;
    __try {
        rv = Real_GetColorSpace(a0);
    }
    __finally {
        _PrintExit("GetColorSpace() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCommConfig(HANDLE a0,
    LPCOMMCONFIG a1,
    LPDWORD a2)
{
    _PrintEnter("GetCommConfig(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetCommConfig(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetCommConfig(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCommMask(HANDLE a0,
    LPDWORD a1)
{
    _PrintEnter("GetCommMask(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetCommMask(a0, a1);
    }
    __finally {
        _PrintExit("GetCommMask(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCommModemStatus(HANDLE a0,
    LPDWORD a1)
{
    _PrintEnter("GetCommModemStatus(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetCommModemStatus(a0, a1);
    }
    __finally {
        _PrintExit("GetCommModemStatus(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCommProperties(HANDLE a0,
    LPCOMMPROP a1)
{
    _PrintEnter("GetCommProperties(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetCommProperties(a0, a1);
    }
    __finally {
        _PrintExit("GetCommProperties(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCommState(HANDLE a0,
    LPDCB a1)
{
    _PrintEnter("GetCommState(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetCommState(a0, a1);
    }
    __finally {
        _PrintExit("GetCommState(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCommTimeouts(HANDLE a0,
    LPCOMMTIMEOUTS a1)
{
    _PrintEnter("GetCommTimeouts(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetCommTimeouts(a0, a1);
    }
    __finally {
        _PrintExit("GetCommTimeouts(,) -> %p\n", rv);
    };
    return rv;
}

LPSTR __stdcall Mine_GetCommandLineA(void)
{
    _PrintEnter("GetCommandLineA()\n");

    LPSTR rv = 0;
    __try {
        rv = Real_GetCommandLineA();
    }
    __finally {
        _PrintExit("GetCommandLineA() -> %hs\n", rv);
    };
    return rv;
}

LPWSTR __stdcall Mine_GetCommandLineW(void)
{
    _PrintEnter("GetCommandLineW()\n");

    LPWSTR rv = 0;
    __try {
        rv = Real_GetCommandLineW();
    }
    __finally {
        _PrintExit("GetCommandLineW() -> %ls\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetComputerNameA(LPSTR a0,
    LPDWORD a1)
{
    _PrintEnter("GetComputerNameA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetComputerNameA(a0, a1);
    }
    __finally {
        _PrintExit("GetComputerNameA(%hs,) -> %p\n", a0, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetComputerNameW(LPWSTR a0,
    LPDWORD a1)
{
    _PrintEnter("GetComputerNameW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetComputerNameW(a0, a1);
    }
    __finally {
        _PrintExit("GetComputerNameW(%ls,) -> %p\n", a0, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetConsoleCP(void)
{
    _PrintEnter("GetConsoleCP()\n");

    UINT rv = 0;
    __try {
        rv = Real_GetConsoleCP();
    }
    __finally {
        _PrintExit("GetConsoleCP() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetConsoleCursorInfo(HANDLE a0,
    PCONSOLE_CURSOR_INFO a1)
{
    _PrintEnter("GetConsoleCursorInfo(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetConsoleCursorInfo(a0, a1);
    }
    __finally {
        _PrintExit("GetConsoleCursorInfo(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetConsoleMode(HANDLE a0,
    LPDWORD a1)
{
    _PrintEnter("GetConsoleMode(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetConsoleMode(a0, a1);
    }
    __finally {
        _PrintExit("GetConsoleMode(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetConsoleOutputCP(void)
{
    _PrintEnter("GetConsoleOutputCP()\n");

    UINT rv = 0;
    __try {
        rv = Real_GetConsoleOutputCP();
    }
    __finally {
        _PrintExit("GetConsoleOutputCP() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetConsoleScreenBufferInfo(HANDLE a0,
    PCONSOLE_SCREEN_BUFFER_INFO a1)
{
    _PrintEnter("GetConsoleScreenBufferInfo(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetConsoleScreenBufferInfo(a0, a1);
    }
    __finally {
        _PrintExit("GetConsoleScreenBufferInfo(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetConsoleTitleA(LPSTR a0,
    DWORD a1)
{
    _PrintEnter("GetConsoleTitleA(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetConsoleTitleA(a0, a1);
    }
    __finally {
        _PrintExit("GetConsoleTitleA(%hs,) -> %p\n", a0, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetConsoleTitleW(LPWSTR a0,
    DWORD a1)
{
    _PrintEnter("GetConsoleTitleW(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetConsoleTitleW(a0, a1);
    }
    __finally {
        _PrintExit("GetConsoleTitleW(%ls,) -> %p\n", a0, rv);
    };
    return rv;
}

HRESULT __stdcall Mine_GetConvertStg(LPSTORAGE a0)
{
    _PrintEnter("GetConvertStg(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_GetConvertStg(a0);
    }
    __finally {
        _PrintExit("GetConvertStg() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetCurrencyFormatA(LCID a0,
    DWORD a1,
    LPCSTR a2,
    CURRENCYFMTA* a3,
    LPSTR a4,
    int a5)
{
    _PrintEnter("GetCurrencyFormatA(%p,%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_GetCurrencyFormatA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetCurrencyFormatA(,,,,%hs,) -> %p\n", a4, rv);
    };
    return rv;
}

int __stdcall Mine_GetCurrencyFormatW(LCID a0,
    DWORD a1,
    LPCWSTR a2,
    CURRENCYFMTW* a3,
    LPWSTR a4,
    int a5)
{
    _PrintEnter("GetCurrencyFormatW(%p,%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_GetCurrencyFormatW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetCurrencyFormatW(,,,,%ls,) -> %p\n", a4, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetCurrentDirectoryA(DWORD a0,
    LPSTR a1)
{
    _PrintEnter("GetCurrentDirectoryA(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetCurrentDirectoryA(a0, a1);
    }
    __finally {
        _PrintExit("GetCurrentDirectoryA(,%hs) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetCurrentDirectoryW(DWORD a0,
    LPWSTR a1)
{
    _PrintEnter("GetCurrentDirectoryW(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetCurrentDirectoryW(a0, a1);
    }
    __finally {
        _PrintExit("GetCurrentDirectoryW(,%ls) -> %p\n", a1, rv);
    };
    return rv;
}

HGDIOBJ __stdcall Mine_GetCurrentObject(HDC a0,
    UINT a1)
{
    _PrintEnter("GetCurrentObject(%p,%p)\n", a0, a1);

    HGDIOBJ rv = 0;
    __try {
        rv = Real_GetCurrentObject(a0, a1);
    }
    __finally {
        _PrintExit("GetCurrentObject(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCurrentPositionEx(HDC a0,
    POINT* a1)
{
    _PrintEnter("GetCurrentPositionEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetCurrentPositionEx(a0, a1);
    }
    __finally {
        _PrintExit("GetCurrentPositionEx(,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_GetCurrentProcess(void)
{
    _PrintEnter("GetCurrentProcess()\n");

    HANDLE rv = 0;
    __try {
        rv = Real_GetCurrentProcess();
    }
    __finally {
        _PrintExit("GetCurrentProcess() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetCurrentProcessId(void)
{
    _PrintEnter("GetCurrentProcessId()\n");

    DWORD rv = 0;
    __try {
        rv = Real_GetCurrentProcessId();
    }
    __finally {
        _PrintExit("GetCurrentProcessId() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetCurrentThreadId(void)
{
    _PrintEnter("GetCurrentThreadId()\n");

    DWORD rv = 0;
    __try {
        rv = Real_GetCurrentThreadId();
    }
    __finally {
        _PrintExit("GetCurrentThreadId() -> %p\n", rv);
    };
    return rv;
}

HCURSOR __stdcall Mine_GetCursor(void)
{
    _PrintEnter("GetCursor()\n");

    HCURSOR rv = 0;
    __try {
        rv = Real_GetCursor();
    }
    __finally {
        _PrintExit("GetCursor() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetCursorPos(POINT* a0)
{
    _PrintEnter("GetCursorPos(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetCursorPos(a0);
    }
    __finally {
        _PrintExit("GetCursorPos() -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_GetDC(HWND a0)
{
    _PrintEnter("GetDC(%p)\n", a0);

    HDC rv = 0;
    __try {
        rv = Real_GetDC(a0);
    }
    __finally {
        _PrintExit("GetDC() -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_GetDCEx(HWND a0,
    HRGN a1,
    DWORD a2)
{
    _PrintEnter("GetDCEx(%p,%p,%p)\n", a0, a1, a2);

    HDC rv = 0;
    __try {
        rv = Real_GetDCEx(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetDCEx(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetDCOrgEx(HDC a0,
    POINT* a1)
{
    _PrintEnter("GetDCOrgEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetDCOrgEx(a0, a1);
    }
    __finally {
        _PrintExit("GetDCOrgEx(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetDIBColorTable(HDC a0,
    UINT a1,
    UINT a2,
    RGBQUAD* a3)
{
    _PrintEnter("GetDIBColorTable(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetDIBColorTable(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetDIBColorTable(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetDIBits(HDC a0,
    HBITMAP a1,
    UINT a2,
    UINT a3,
    LPVOID a4,
    LPBITMAPINFO a5,
    UINT a6)
{
    _PrintEnter("GetDIBits(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    int rv = 0;
    __try {
        rv = Real_GetDIBits(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("GetDIBits(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetDateFormatA(LCID a0,
    DWORD a1,
    SYSTEMTIME* a2,
    LPCSTR a3,
    LPSTR a4,
    int a5)
{
    _PrintEnter("GetDateFormatA(%p,%p,%p,%hs,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_GetDateFormatA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetDateFormatA(,,,,%hs,) -> %p\n", a4, rv);
    };
    return rv;
}

int __stdcall Mine_GetDateFormatW(LCID a0,
    DWORD a1,
    SYSTEMTIME* a2,
    LPCWSTR a3,
    LPWSTR a4,
    int a5)
{
    _PrintEnter("GetDateFormatW(%p,%p,%p,%ls,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_GetDateFormatW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetDateFormatW(,,,,%ls,) -> %p\n", a4, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetDefaultCommConfigA(LPCSTR a0,
    LPCOMMCONFIG a1,
    LPDWORD a2)
{
    _PrintEnter("GetDefaultCommConfigA(%hs,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetDefaultCommConfigA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetDefaultCommConfigA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetDefaultCommConfigW(LPCWSTR a0,
    LPCOMMCONFIG a1,
    LPDWORD a2)
{
    _PrintEnter("GetDefaultCommConfigW(%ls,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetDefaultCommConfigW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetDefaultCommConfigW(,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetDesktopWindow(void)
{
    _PrintEnter("GetDesktopWindow()\n");

    HWND rv = 0;
    __try {
        rv = Real_GetDesktopWindow();
    }
    __finally {
        _PrintExit("GetDesktopWindow() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetDeviceCaps(HDC a0,
    int a1)
{
    _PrintEnter("GetDeviceCaps(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetDeviceCaps(a0, a1);
    }
    __finally {
        _PrintExit("GetDeviceCaps(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetDeviceGammaRamp(HDC a0,
    LPVOID a1)
{
    _PrintEnter("GetDeviceGammaRamp(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetDeviceGammaRamp(a0, a1);
    }
    __finally {
        _PrintExit("GetDeviceGammaRamp(,) -> %p\n", rv);
    };
    return rv;
}

long __stdcall Mine_GetDialogBaseUnits(void)
{
    _PrintEnter("GetDialogBaseUnits()\n");

    long rv = 0;
    __try {
        rv = Real_GetDialogBaseUnits();
    }
    __finally {
        _PrintExit("GetDialogBaseUnits() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetDiskFreeSpaceA(LPCSTR a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
{
    _PrintEnter("GetDiskFreeSpaceA(%hs,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetDiskFreeSpaceA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetDiskFreeSpaceA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetDiskFreeSpaceExA(LPCSTR a0,
    union _ULARGE_INTEGER* a1,
    union _ULARGE_INTEGER* a2,
    union _ULARGE_INTEGER* a3)
{
    _PrintEnter("GetDiskFreeSpaceExA(%hs,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetDiskFreeSpaceExA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetDiskFreeSpaceExA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetDiskFreeSpaceExW(LPCWSTR a0,
    union _ULARGE_INTEGER* a1,
    union _ULARGE_INTEGER* a2,
    union _ULARGE_INTEGER* a3)
{
    _PrintEnter("GetDiskFreeSpaceExW(%ls,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetDiskFreeSpaceExW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetDiskFreeSpaceExW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetDiskFreeSpaceW(LPCWSTR a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
{
    _PrintEnter("GetDiskFreeSpaceW(%ls,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetDiskFreeSpaceW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetDiskFreeSpaceW(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetDlgCtrlID(HWND a0)
{
    _PrintEnter("GetDlgCtrlID(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetDlgCtrlID(a0);
    }
    __finally {
        _PrintExit("GetDlgCtrlID() -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetDlgItem(HWND a0,
    int a1)
{
    _PrintEnter("GetDlgItem(%p,%p)\n", a0, a1);

    HWND rv = 0;
    __try {
        rv = Real_GetDlgItem(a0, a1);
    }
    __finally {
        _PrintExit("GetDlgItem(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetDlgItemInt(HWND a0,
    int a1,
    BOOL* a2,
    BOOL a3)
{
    _PrintEnter("GetDlgItemInt(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetDlgItemInt(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetDlgItemInt(,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetDlgItemTextA(HWND a0,
    int a1,
    LPSTR a2,
    int a3)
{
    _PrintEnter("GetDlgItemTextA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetDlgItemTextA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetDlgItemTextA(,,%hs,) -> %p\n", a2, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetDlgItemTextW(HWND a0,
    int a1,
    LPWSTR a2,
    int a3)
{
    _PrintEnter("GetDlgItemTextW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetDlgItemTextW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetDlgItemTextW(,,%ls,) -> %p\n", a2, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetDoubleClickTime(void)
{
    _PrintEnter("GetDoubleClickTime()\n");

    UINT rv = 0;
    __try {
        rv = Real_GetDoubleClickTime();
    }
    __finally {
        _PrintExit("GetDoubleClickTime() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetDriveTypeA(LPCSTR a0)
{
    _PrintEnter("GetDriveTypeA(%hs)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_GetDriveTypeA(a0);
    }
    __finally {
        _PrintExit("GetDriveTypeA() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetDriveTypeW(LPCWSTR a0)
{
    _PrintEnter("GetDriveTypeW(%ls)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_GetDriveTypeW(a0);
    }
    __finally {
        _PrintExit("GetDriveTypeW() -> %p\n", rv);
    };
    return rv;
}

HENHMETAFILE __stdcall Mine_GetEnhMetaFileA(LPCSTR a0)
{
    _PrintEnter("GetEnhMetaFileA(%hs)\n", a0);

    HENHMETAFILE rv = 0;
    __try {
        rv = Real_GetEnhMetaFileA(a0);
    }
    __finally {
        _PrintExit("GetEnhMetaFileA() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetEnhMetaFileBits(HENHMETAFILE a0,
    UINT a1,
    LPBYTE a2)
{
    _PrintEnter("GetEnhMetaFileBits(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetEnhMetaFileBits(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetEnhMetaFileBits(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetEnhMetaFileDescriptionA(HENHMETAFILE a0,
    UINT a1,
    LPSTR a2)
{
    _PrintEnter("GetEnhMetaFileDescriptionA(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetEnhMetaFileDescriptionA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetEnhMetaFileDescriptionA(,,%hs) -> %p\n", a2, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetEnhMetaFileDescriptionW(HENHMETAFILE a0,
    UINT a1,
    LPWSTR a2)
{
    _PrintEnter("GetEnhMetaFileDescriptionW(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetEnhMetaFileDescriptionW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetEnhMetaFileDescriptionW(,,%ls) -> %p\n", a2, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetEnhMetaFileHeader(HENHMETAFILE a0,
    UINT a1,
    ENHMETAHEADER* a2)
{
    _PrintEnter("GetEnhMetaFileHeader(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetEnhMetaFileHeader(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetEnhMetaFileHeader(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetEnhMetaFilePaletteEntries(HENHMETAFILE a0,
    UINT a1,
    PALETTEENTRY* a2)
{
    _PrintEnter("GetEnhMetaFilePaletteEntries(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetEnhMetaFilePaletteEntries(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetEnhMetaFilePaletteEntries(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetEnhMetaFilePixelFormat(HENHMETAFILE a0,
    UINT a1,
    PIXELFORMATDESCRIPTOR* a2)
{
    _PrintEnter("GetEnhMetaFilePixelFormat(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetEnhMetaFilePixelFormat(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetEnhMetaFilePixelFormat(,,) -> %p\n", rv);
    };
    return rv;
}

HENHMETAFILE __stdcall Mine_GetEnhMetaFileW(LPCWSTR a0)
{
    _PrintEnter("GetEnhMetaFileW(%ls)\n", a0);

    HENHMETAFILE rv = 0;
    __try {
        rv = Real_GetEnhMetaFileW(a0);
    }
    __finally {
        _PrintExit("GetEnhMetaFileW() -> %p\n", rv);
    };
    return rv;
}

LPSTR __stdcall Mine_GetEnvironmentStrings(void)
{
    _PrintEnter("GetEnvironmentStrings()\n");

    LPSTR rv = 0;
    __try {
        rv = Real_GetEnvironmentStrings();
    }
    __finally {
        _PrintExit("GetEnvironmentStrings() -> %hs\n", rv);
    };
    return rv;
}

LPWSTR __stdcall Mine_GetEnvironmentStringsW(void)
{
    _PrintEnter("GetEnvironmentStringsW()\n");

    LPWSTR rv = 0;
    __try {
        rv = Real_GetEnvironmentStringsW();
    }
    __finally {
        _PrintExit("GetEnvironmentStringsW() -> %ls\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetEnvironmentVariableA(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("GetEnvironmentVariableA(%hs,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetEnvironmentVariableA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetEnvironmentVariableA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetEnvironmentVariableW(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
{
    _PrintEnter("GetEnvironmentVariableW(%ls,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetEnvironmentVariableW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetEnvironmentVariableW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetExitCodeProcess(HANDLE a0,
    LPDWORD a1)
{
    _PrintEnter("GetExitCodeProcess(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetExitCodeProcess(a0, a1);
    }
    __finally {
        _PrintExit("GetExitCodeProcess(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetExitCodeThread(HANDLE a0,
    LPDWORD a1)
{
    _PrintEnter("GetExitCodeThread(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetExitCodeThread(a0, a1);
    }
    __finally {
        _PrintExit("GetExitCodeThread(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetFileAttributesA(LPCSTR a0)
{
    _PrintEnter("GetFileAttributesA(%hs)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetFileAttributesA(a0);
    }
    __finally {
        _PrintExit("GetFileAttributesA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetFileAttributesExA(LPCSTR a0,
    enum _GET_FILEEX_INFO_LEVELS a1,
    LPVOID a2)
{
    _PrintEnter("GetFileAttributesExA(%hs,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetFileAttributesExA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetFileAttributesExA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetFileAttributesExW(LPCWSTR a0,
    enum _GET_FILEEX_INFO_LEVELS a1,
    LPVOID a2)
{
    _PrintEnter("GetFileAttributesExW(%ls,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetFileAttributesExW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetFileAttributesExW(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetFileAttributesW(LPCWSTR a0)
{
    _PrintEnter("GetFileAttributesW(%ls)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetFileAttributesW(a0);
    }
    __finally {
        _PrintExit("GetFileAttributesW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetFileInformationByHandle(HANDLE a0,
    LPBY_HANDLE_FILE_INFORMATION a1)
{
    _PrintEnter("GetFileInformationByHandle(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetFileInformationByHandle(a0, a1);
    }
    __finally {
        _PrintExit("GetFileInformationByHandle(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetFileSize(HANDLE a0,
    LPDWORD a1)
{
    _PrintEnter("GetFileSize(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetFileSize(a0, a1);
    }
    __finally {
        _PrintExit("GetFileSize(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetFileTime(HANDLE a0,
    LPFILETIME a1,
    LPFILETIME a2,
    LPFILETIME a3)
{
    _PrintEnter("GetFileTime(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetFileTime(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetFileTime(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetFileType(HANDLE a0)
{
    _PrintEnter("GetFileType(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetFileType(a0);
    }
    __finally {
        _PrintExit("GetFileType() -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetFocus(void)
{
    _PrintEnter("GetFocus()\n");

    HWND rv = 0;
    __try {
        rv = Real_GetFocus();
    }
    __finally {
        _PrintExit("GetFocus() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetFontData(HDC a0,
    DWORD a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4)
{
    _PrintEnter("GetFontData(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_GetFontData(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetFontData(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetFontLanguageInfo(HDC a0)
{
    _PrintEnter("GetFontLanguageInfo(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetFontLanguageInfo(a0);
    }
    __finally {
        _PrintExit("GetFontLanguageInfo() -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetForegroundWindow(void)
{
    _PrintEnter("GetForegroundWindow()\n");

    HWND rv = 0;
    __try {
        rv = Real_GetForegroundWindow();
    }
    __finally {
        _PrintExit("GetForegroundWindow() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetFullPathNameA(LPCSTR a0,
    DWORD a1,
    LPSTR a2,
    LPSTR* a3)
{
    _PrintEnter("GetFullPathNameA(%hs,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_GetFullPathNameA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetFullPathNameA(,,%hs,) -> %p\n", a2, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetFullPathNameW(LPCWSTR a0,
    DWORD a1,
    LPWSTR a2,
    LPWSTR* a3)
{
    _PrintEnter("GetFullPathNameW(%ls,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_GetFullPathNameW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetFullPathNameW(,,%ls,) -> %p\n", a2, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetGlyphOutlineA(HDC a0,
    UINT a1,
    UINT a2,
    LPGLYPHMETRICS a3,
    DWORD a4,
    LPVOID a5,
    MAT2* a6)
{
    _PrintEnter("GetGlyphOutlineA(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    DWORD rv = 0;
    __try {
        rv = Real_GetGlyphOutlineA(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("GetGlyphOutlineA(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetGlyphOutlineW(HDC a0,
    UINT a1,
    UINT a2,
    LPGLYPHMETRICS a3,
    DWORD a4,
    LPVOID a5,
    MAT2* a6)
{
    _PrintEnter("GetGlyphOutlineW(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    DWORD rv = 0;
    __try {
        rv = Real_GetGlyphOutlineW(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("GetGlyphOutlineW(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetGraphicsMode(HDC a0)
{
    _PrintEnter("GetGraphicsMode(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetGraphicsMode(a0);
    }
    __finally {
        _PrintExit("GetGraphicsMode() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_GetHGlobalFromILockBytes(ILockBytes* a0,
    HGLOBAL* a1)
{
    _PrintEnter("GetHGlobalFromILockBytes(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_GetHGlobalFromILockBytes(a0, a1);
    }
    __finally {
        _PrintExit("GetHGlobalFromILockBytes(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_GetHGlobalFromStream(LPSTREAM a0,
    HGLOBAL* a1)
{
    _PrintEnter("GetHGlobalFromStream(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_GetHGlobalFromStream(a0, a1);
    }
    __finally {
        _PrintExit("GetHGlobalFromStream(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetHandleInformation(HANDLE a0,
    LPDWORD a1)
{
    _PrintEnter("GetHandleInformation(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetHandleInformation(a0, a1);
    }
    __finally {
        _PrintExit("GetHandleInformation(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetICMProfileA(HDC a0,
    LPDWORD a1,
    LPSTR a2)
{
    _PrintEnter("GetICMProfileA(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetICMProfileA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetICMProfileA(,,%hs) -> %p\n", a2, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetICMProfileW(HDC a0,
    LPDWORD a1,
    LPWSTR a2)
{
    _PrintEnter("GetICMProfileW(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetICMProfileW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetICMProfileW(,,%ls) -> %p\n", a2, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetIconInfo(HICON a0,
    PICONINFO a1)
{
    _PrintEnter("GetIconInfo(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetIconInfo(a0, a1);
    }
    __finally {
        _PrintExit("GetIconInfo(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetInputState(void)
{
    _PrintEnter("GetInputState()\n");

    BOOL rv = 0;
    __try {
        rv = Real_GetInputState();
    }
    __finally {
        _PrintExit("GetInputState() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetKBCodePage(void)
{
    _PrintEnter("GetKBCodePage()\n");

    UINT rv = 0;
    __try {
        rv = Real_GetKBCodePage();
    }
    __finally {
        _PrintExit("GetKBCodePage() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetKerningPairsA(HDC a0,
    DWORD a1,
    KERNINGPAIR* a2)
{
    _PrintEnter("GetKerningPairsA(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetKerningPairsA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetKerningPairsA(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetKerningPairsW(HDC a0,
    DWORD a1,
    KERNINGPAIR* a2)
{
    _PrintEnter("GetKerningPairsW(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetKerningPairsW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetKerningPairsW(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetKeyNameTextA(LONG a0,
    LPSTR a1,
    int a2)
{
    _PrintEnter("GetKeyNameTextA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetKeyNameTextA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetKeyNameTextA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_GetKeyNameTextW(LONG a0,
    LPWSTR a1,
    int a2)
{
    _PrintEnter("GetKeyNameTextW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetKeyNameTextW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetKeyNameTextW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

SHORT __stdcall Mine_GetKeyState(int a0)
{
    _PrintEnter("GetKeyState(%p)\n", a0);

    SHORT rv = 0;
    __try {
        rv = Real_GetKeyState(a0);
    }
    __finally {
        _PrintExit("GetKeyState() -> %p\n", rv);
    };
    return rv;
}

HKL __stdcall Mine_GetKeyboardLayout(DWORD a0)
{
    _PrintEnter("GetKeyboardLayout(%p)\n", a0);

    HKL rv = 0;
    __try {
        rv = Real_GetKeyboardLayout(a0);
    }
    __finally {
        _PrintExit("GetKeyboardLayout() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetKeyboardLayoutList(int a0,
    HKL* a1)
{
    _PrintEnter("GetKeyboardLayoutList(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetKeyboardLayoutList(a0, a1);
    }
    __finally {
        _PrintExit("GetKeyboardLayoutList(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetKeyboardLayoutNameA(LPSTR a0)
{
    _PrintEnter("GetKeyboardLayoutNameA(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetKeyboardLayoutNameA(a0);
    }
    __finally {
        _PrintExit("GetKeyboardLayoutNameA(%hs) -> %p\n", a0, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetKeyboardLayoutNameW(LPWSTR a0)
{
    _PrintEnter("GetKeyboardLayoutNameW(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetKeyboardLayoutNameW(a0);
    }
    __finally {
        _PrintExit("GetKeyboardLayoutNameW(%ls) -> %p\n", a0, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetKeyboardState(PBYTE a0)
{
    _PrintEnter("GetKeyboardState(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetKeyboardState(a0);
    }
    __finally {
        _PrintExit("GetKeyboardState() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetKeyboardType(int a0)
{
    _PrintEnter("GetKeyboardType(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetKeyboardType(a0);
    }
    __finally {
        _PrintExit("GetKeyboardType() -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetLastActivePopup(HWND a0)
{
    _PrintEnter("GetLastActivePopup(%p)\n", a0);

    HWND rv = 0;
    __try {
        rv = Real_GetLastActivePopup(a0);
    }
    __finally {
        _PrintExit("GetLastActivePopup() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_GetLocalTime(LPSYSTEMTIME a0)
{
    _PrintEnter("GetLocalTime(%p)\n", a0);

    __try {
        Real_GetLocalTime(a0);
    }
    __finally {
        _PrintExit("GetLocalTime() ->\n");
    };
}

int __stdcall Mine_GetLocaleInfoA(LCID a0,
    LCTYPE a1,
    LPSTR a2,
    int a3)
{
    _PrintEnter("GetLocaleInfoA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_GetLocaleInfoA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetLocaleInfoA(,,%hs,) -> %p\n", a2, rv);
    };
    return rv;
}

int __stdcall Mine_GetLocaleInfoW(LCID a0,
    LCTYPE a1,
    LPWSTR a2,
    int a3)
{
    _PrintEnter("GetLocaleInfoW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_GetLocaleInfoW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetLocaleInfoW(,,%ls,) -> %p\n", a2, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetLogColorSpaceA(HCOLORSPACE a0,
    LOGCOLORSPACEA* a1,
    DWORD a2)
{
    _PrintEnter("GetLogColorSpaceA(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetLogColorSpaceA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetLogColorSpaceA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetLogColorSpaceW(HCOLORSPACE a0,
    LOGCOLORSPACEW* a1,
    DWORD a2)
{
    _PrintEnter("GetLogColorSpaceW(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetLogColorSpaceW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetLogColorSpaceW(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetLogicalDriveStringsA(DWORD a0,
    LPSTR a1)
{
    _PrintEnter("GetLogicalDriveStringsA(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetLogicalDriveStringsA(a0, a1);
    }
    __finally {
        _PrintExit("GetLogicalDriveStringsA(,%hs) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetLogicalDriveStringsW(DWORD a0,
    LPWSTR a1)
{
    _PrintEnter("GetLogicalDriveStringsW(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetLogicalDriveStringsW(a0, a1);
    }
    __finally {
        _PrintExit("GetLogicalDriveStringsW(,%ls) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetLogicalDrives(void)
{
    _PrintEnter("GetLogicalDrives()\n");

    DWORD rv = 0;
    __try {
        rv = Real_GetLogicalDrives();
    }
    __finally {
        _PrintExit("GetLogicalDrives() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetMailslotInfo(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
{
    _PrintEnter("GetMailslotInfo(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetMailslotInfo(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetMailslotInfo(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetMapMode(HDC a0)
{
    _PrintEnter("GetMapMode(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetMapMode(a0);
    }
    __finally {
        _PrintExit("GetMapMode() -> %p\n", rv);
    };
    return rv;
}

HMENU __stdcall Mine_GetMenu(HWND a0)
{
    _PrintEnter("GetMenu(%p)\n", a0);

    HMENU rv = 0;
    __try {
        rv = Real_GetMenu(a0);
    }
    __finally {
        _PrintExit("GetMenu() -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_GetMenuCheckMarkDimensions(void)
{
    _PrintEnter("GetMenuCheckMarkDimensions()\n");

    LONG rv = 0;
    __try {
        rv = Real_GetMenuCheckMarkDimensions();
    }
    __finally {
        _PrintExit("GetMenuCheckMarkDimensions() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetMenuContextHelpId(HMENU a0)
{
    _PrintEnter("GetMenuContextHelpId(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetMenuContextHelpId(a0);
    }
    __finally {
        _PrintExit("GetMenuContextHelpId() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetMenuDefaultItem(HMENU a0,
    UINT a1,
    UINT a2)
{
    _PrintEnter("GetMenuDefaultItem(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetMenuDefaultItem(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetMenuDefaultItem(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetMenuItemCount(HMENU a0)
{
    _PrintEnter("GetMenuItemCount(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetMenuItemCount(a0);
    }
    __finally {
        _PrintExit("GetMenuItemCount() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetMenuItemID(HMENU a0,
    int a1)
{
    _PrintEnter("GetMenuItemID(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetMenuItemID(a0, a1);
    }
    __finally {
        _PrintExit("GetMenuItemID(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetMenuItemInfoA(HMENU a0,
    UINT a1,
    BOOL a2,
    LPMENUITEMINFOA a3)
{
    _PrintEnter("GetMenuItemInfoA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetMenuItemInfoA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetMenuItemInfoA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetMenuItemInfoW(HMENU a0,
    UINT a1,
    BOOL a2,
    LPMENUITEMINFOW a3)
{
    _PrintEnter("GetMenuItemInfoW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetMenuItemInfoW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetMenuItemInfoW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetMenuItemRect(HWND a0,
    HMENU a1,
    UINT a2,
    LPRECT a3)
{
    _PrintEnter("GetMenuItemRect(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetMenuItemRect(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetMenuItemRect(,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetMenuState(HMENU a0,
    UINT a1,
    UINT a2)
{
    _PrintEnter("GetMenuState(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetMenuState(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetMenuState(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetMenuStringA(HMENU a0,
    UINT a1,
    LPSTR a2,
    int a3,
    UINT a4)
{
    _PrintEnter("GetMenuStringA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_GetMenuStringA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetMenuStringA(,,%hs,,) -> %p\n", a2, rv);
    };
    return rv;
}

int __stdcall Mine_GetMenuStringW(HMENU a0,
    UINT a1,
    LPWSTR a2,
    int a3,
    UINT a4)
{
    _PrintEnter("GetMenuStringW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_GetMenuStringW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetMenuStringW(,,%ls,,) -> %p\n", a2, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetMessageA(LPMSG a0,
    HWND a1,
    UINT a2,
    UINT a3)
{
    _PrintEnter("GetMessageA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetMessageA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetMessageA(,,,) -> %p\n", rv);
    };
    return rv;
}

LPARAM __stdcall Mine_GetMessageExtraInfo(void)
{
    _PrintEnter("GetMessageExtraInfo()\n");

    LPARAM rv = 0;
    __try {
        rv = Real_GetMessageExtraInfo();
    }
    __finally {
        _PrintExit("GetMessageExtraInfo() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetMessagePos(void)
{
    _PrintEnter("GetMessagePos()\n");

    DWORD rv = 0;
    __try {
        rv = Real_GetMessagePos();
    }
    __finally {
        _PrintExit("GetMessagePos() -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_GetMessageTime(void)
{
    _PrintEnter("GetMessageTime()\n");

    LONG rv = 0;
    __try {
        rv = Real_GetMessageTime();
    }
    __finally {
        _PrintExit("GetMessageTime() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetMessageW(LPMSG a0,
    HWND a1,
    UINT a2,
    UINT a3)
{
    _PrintEnter("GetMessageW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetMessageW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetMessageW(,,,) -> %p\n", rv);
    };
    return rv;
}

HMETAFILE __stdcall Mine_GetMetaFileA(LPCSTR a0)
{
    _PrintEnter("GetMetaFileA(%hs)\n", a0);

    HMETAFILE rv = 0;
    __try {
        rv = Real_GetMetaFileA(a0);
    }
    __finally {
        _PrintExit("GetMetaFileA() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetMetaFileBitsEx(HMETAFILE a0,
    UINT a1,
    LPVOID a2)
{
    _PrintEnter("GetMetaFileBitsEx(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetMetaFileBitsEx(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetMetaFileBitsEx(,,) -> %p\n", rv);
    };
    return rv;
}

HMETAFILE __stdcall Mine_GetMetaFileW(LPCWSTR a0)
{
    _PrintEnter("GetMetaFileW(%ls)\n", a0);

    HMETAFILE rv = 0;
    __try {
        rv = Real_GetMetaFileW(a0);
    }
    __finally {
        _PrintExit("GetMetaFileW() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetMetaRgn(HDC a0,
    HRGN a1)
{
    _PrintEnter("GetMetaRgn(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetMetaRgn(a0, a1);
    }
    __finally {
        _PrintExit("GetMetaRgn(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetMiterLimit(HDC a0,
    PFLOAT a1)
{
    _PrintEnter("GetMiterLimit(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetMiterLimit(a0, a1);
    }
    __finally {
        _PrintExit("GetMiterLimit(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetModuleFileNameA(HMODULE a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("GetModuleFileNameA(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetModuleFileNameA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetModuleFileNameA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetModuleFileNameW(HMODULE a0,
    LPWSTR a1,
    DWORD a2)
{
    _PrintEnter("GetModuleFileNameW(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetModuleFileNameW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetModuleFileNameW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

HMODULE __stdcall Mine_GetModuleHandleA(LPCSTR a0)
{
    _PrintEnter("GetModuleHandleA(%hs)\n", a0);

    HMODULE rv = 0;
    __try {
        rv = Real_GetModuleHandleA(a0);
    }
    __finally {
        _PrintExit("GetModuleHandleA() -> %p\n", rv);
    };
    return rv;
}

HMODULE __stdcall Mine_GetModuleHandleW(LPCWSTR a0)
{
    _PrintEnter("GetModuleHandleW(%ls)\n", a0);

    HMODULE rv = 0;
    __try {
        rv = Real_GetModuleHandleW(a0);
    }
    __finally {
        _PrintExit("GetModuleHandleW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetNamedPipeHandleStateA(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPSTR a5,
    DWORD a6)
{
    _PrintEnter("GetNamedPipeHandleStateA(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_GetNamedPipeHandleStateA(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("GetNamedPipeHandleStateA(,,,,,%hs,) -> %p\n", a5, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetNamedPipeHandleStateW(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPWSTR a5,
    DWORD a6)
{
    _PrintEnter("GetNamedPipeHandleStateW(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_GetNamedPipeHandleStateW(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("GetNamedPipeHandleStateW(,,,,,%ls,) -> %p\n", a5, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetNamedPipeInfo(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
{
    _PrintEnter("GetNamedPipeInfo(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetNamedPipeInfo(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetNamedPipeInfo(,,,,) -> %p\n", rv);
    };
    return rv;
}

COLORREF __stdcall Mine_GetNearestColor(HDC a0,
    COLORREF a1)
{
    _PrintEnter("GetNearestColor(%p,%p)\n", a0, a1);

    COLORREF rv = 0;
    __try {
        rv = Real_GetNearestColor(a0, a1);
    }
    __finally {
        _PrintExit("GetNearestColor(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetNearestPaletteIndex(HPALETTE a0,
    COLORREF a1)
{
    _PrintEnter("GetNearestPaletteIndex(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetNearestPaletteIndex(a0, a1);
    }
    __finally {
        _PrintExit("GetNearestPaletteIndex(,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetNextDlgGroupItem(HWND a0,
    HWND a1,
    BOOL a2)
{
    _PrintEnter("GetNextDlgGroupItem(%p,%p,%p)\n", a0, a1, a2);

    HWND rv = 0;
    __try {
        rv = Real_GetNextDlgGroupItem(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetNextDlgGroupItem(,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetNextDlgTabItem(HWND a0,
    HWND a1,
    BOOL a2)
{
    _PrintEnter("GetNextDlgTabItem(%p,%p,%p)\n", a0, a1, a2);

    HWND rv = 0;
    __try {
        rv = Real_GetNextDlgTabItem(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetNextDlgTabItem(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetNumberFormatA(LCID a0,
    DWORD a1,
    LPCSTR a2,
    NUMBERFMTA* a3,
    LPSTR a4,
    int a5)
{
    _PrintEnter("GetNumberFormatA(%p,%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_GetNumberFormatA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetNumberFormatA(,,,,%hs,) -> %p\n", a4, rv);
    };
    return rv;
}

int __stdcall Mine_GetNumberFormatW(LCID a0,
    DWORD a1,
    LPCWSTR a2,
    NUMBERFMTW* a3,
    LPWSTR a4,
    int a5)
{
    _PrintEnter("GetNumberFormatW(%p,%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_GetNumberFormatW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetNumberFormatW(,,,,%ls,) -> %p\n", a4, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetNumberOfConsoleInputEvents(HANDLE a0,
    LPDWORD a1)
{
    _PrintEnter("GetNumberOfConsoleInputEvents(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetNumberOfConsoleInputEvents(a0, a1);
    }
    __finally {
        _PrintExit("GetNumberOfConsoleInputEvents(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetNumberOfConsoleMouseButtons(LPDWORD a0)
{
    _PrintEnter("GetNumberOfConsoleMouseButtons(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetNumberOfConsoleMouseButtons(a0);
    }
    __finally {
        _PrintExit("GetNumberOfConsoleMouseButtons() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetOEMCP(void)
{
    _PrintEnter("GetOEMCP()\n");

    UINT rv = 0;
    __try {
        rv = Real_GetOEMCP();
    }
    __finally {
        _PrintExit("GetOEMCP() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetObjectA(HGDIOBJ a0,
    int a1,
    LPVOID a2)
{
    _PrintEnter("GetObjectA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetObjectA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetObjectA(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetObjectType(HGDIOBJ a0)
{
    _PrintEnter("GetObjectType(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetObjectType(a0);
    }
    __finally {
        _PrintExit("GetObjectType() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetObjectW(HGDIOBJ a0,
    int a1,
    LPVOID a2)
{
    _PrintEnter("GetObjectW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetObjectW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetObjectW(,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetOpenClipboardWindow(void)
{
    _PrintEnter("GetOpenClipboardWindow()\n");

    HWND rv = 0;
    __try {
        rv = Real_GetOpenClipboardWindow();
    }
    __finally {
        _PrintExit("GetOpenClipboardWindow() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetOutlineTextMetricsA(HDC a0,
    UINT a1,
    LPOUTLINETEXTMETRICA a2)
{
    _PrintEnter("GetOutlineTextMetricsA(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetOutlineTextMetricsA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetOutlineTextMetricsA(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetOutlineTextMetricsW(HDC a0,
    UINT a1,
    LPOUTLINETEXTMETRICW a2)
{
    _PrintEnter("GetOutlineTextMetricsW(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetOutlineTextMetricsW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetOutlineTextMetricsW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetOverlappedResult(HANDLE a0,
    LPOVERLAPPED a1,
    LPDWORD a2,
    BOOL a3)
{
    _PrintEnter("GetOverlappedResult(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetOverlappedResult(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetOverlappedResult(,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetPaletteEntries(HPALETTE a0,
    UINT a1,
    UINT a2,
    PALETTEENTRY* a3)
{
    _PrintEnter("GetPaletteEntries(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetPaletteEntries(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetPaletteEntries(,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetParent(HWND a0)
{
    _PrintEnter("GetParent(%p)\n", a0);

    HWND rv = 0;
    __try {
        rv = Real_GetParent(a0);
    }
    __finally {
        _PrintExit("GetParent() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetPath(HDC a0,
    POINT* a1,
    LPBYTE a2,
    int a3)
{
    _PrintEnter("GetPath(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_GetPath(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetPath(,,,) -> %p\n", rv);
    };
    return rv;
}

COLORREF __stdcall Mine_GetPixel(HDC a0,
    int a1,
    int a2)
{
    _PrintEnter("GetPixel(%p,%p,%p)\n", a0, a1, a2);

    COLORREF rv = 0;
    __try {
        rv = Real_GetPixel(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetPixel(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetPixelFormat(HDC a0)
{
    _PrintEnter("GetPixelFormat(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetPixelFormat(a0);
    }
    __finally {
        _PrintExit("GetPixelFormat() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetPolyFillMode(HDC a0)
{
    _PrintEnter("GetPolyFillMode(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetPolyFillMode(a0);
    }
    __finally {
        _PrintExit("GetPolyFillMode() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetPriorityClass(HANDLE a0)
{
    _PrintEnter("GetPriorityClass(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetPriorityClass(a0);
    }
    __finally {
        _PrintExit("GetPriorityClass() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetPriorityClipboardFormat(UINT* a0,
    int a1)
{
    _PrintEnter("GetPriorityClipboardFormat(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetPriorityClipboardFormat(a0, a1);
    }
    __finally {
        _PrintExit("GetPriorityClipboardFormat(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetPrivateProfileIntA(LPCSTR a0,
    LPCSTR a1,
    INT a2,
    LPCSTR a3)
{
    _PrintEnter("GetPrivateProfileIntA(%hs,%hs,%p,%hs)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetPrivateProfileIntA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetPrivateProfileIntA(,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetPrivateProfileIntW(LPCWSTR a0,
    LPCWSTR a1,
    INT a2,
    LPCWSTR a3)
{
    _PrintEnter("GetPrivateProfileIntW(%ls,%ls,%p,%ls)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetPrivateProfileIntW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetPrivateProfileIntW(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetPrivateProfileSectionA(LPCSTR a0,
    LPSTR a1,
    DWORD a2,
    LPCSTR a3)
{
    _PrintEnter("GetPrivateProfileSectionA(%hs,%p,%p,%hs)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_GetPrivateProfileSectionA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetPrivateProfileSectionA(,%hs,,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetPrivateProfileSectionNamesA(LPSTR a0,
    DWORD a1,
    LPCSTR a2)
{
    _PrintEnter("GetPrivateProfileSectionNamesA(%p,%p,%hs)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetPrivateProfileSectionNamesA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetPrivateProfileSectionNamesA(%hs,,) -> %p\n", a0, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetPrivateProfileSectionNamesW(LPWSTR a0,
    DWORD a1,
    LPCWSTR a2)
{
    _PrintEnter("GetPrivateProfileSectionNamesW(%p,%p,%ls)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetPrivateProfileSectionNamesW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetPrivateProfileSectionNamesW(%ls,,) -> %p\n", a0, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetPrivateProfileSectionW(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2,
    LPCWSTR a3)
{
    _PrintEnter("GetPrivateProfileSectionW(%ls,%p,%p,%ls)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_GetPrivateProfileSectionW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetPrivateProfileSectionW(,%ls,,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetPrivateProfileStringA(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    LPSTR a3,
    DWORD a4,
    LPCSTR a5)
{
    _PrintEnter("GetPrivateProfileStringA(%hs,%hs,%hs,%p,%p,%hs)\n", a0, a1, a2, a3, a4, a5);

    DWORD rv = 0;
    __try {
        rv = Real_GetPrivateProfileStringA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetPrivateProfileStringA(,,,%hs,,) -> %p\n", a3, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetPrivateProfileStringW(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    LPWSTR a3,
    DWORD a4,
    LPCWSTR a5)
{
    _PrintEnter("GetPrivateProfileStringW(%ls,%ls,%ls,%p,%p,%ls)\n", a0, a1, a2, a3, a4, a5);

    DWORD rv = 0;
    __try {
        rv = Real_GetPrivateProfileStringW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetPrivateProfileStringW(,,,%ls,,) -> %p\n", a3, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetPrivateProfileStructA(LPCSTR a0,
    LPCSTR a1,
    LPVOID a2,
    UINT a3,
    LPCSTR a4)
{
    _PrintEnter("GetPrivateProfileStructA(%hs,%hs,%p,%p,%hs)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetPrivateProfileStructA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetPrivateProfileStructA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetPrivateProfileStructW(LPCWSTR a0,
    LPCWSTR a1,
    LPVOID a2,
    UINT a3,
    LPCWSTR a4)
{
    _PrintEnter("GetPrivateProfileStructW(%ls,%ls,%p,%p,%ls)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetPrivateProfileStructW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetPrivateProfileStructW(,,,,) -> %p\n", rv);
    };
    return rv;
}

FARPROC __stdcall Mine_GetProcAddress(HMODULE a0,
    LPCSTR a1)
{
    _PrintEnter("GetProcAddress(%p,%hs)\n", a0, a1);

    FARPROC rv = 0;
    __try {
        rv = Real_GetProcAddress(a0, a1);
    }
    __finally {
        _PrintExit("GetProcAddress(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetProcessAffinityMask(HANDLE a0,
    PDWORD_PTR a1,
    PDWORD_PTR a2)
{
    _PrintEnter("GetProcessAffinityMask(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetProcessAffinityMask(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetProcessAffinityMask(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetProcessHeaps(DWORD a0,
    PHANDLE a1)
{
    _PrintEnter("GetProcessHeaps(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetProcessHeaps(a0, a1);
    }
    __finally {
        _PrintExit("GetProcessHeaps(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetProcessShutdownParameters(LPDWORD a0,
    LPDWORD a1)
{
    _PrintEnter("GetProcessShutdownParameters(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetProcessShutdownParameters(a0, a1);
    }
    __finally {
        _PrintExit("GetProcessShutdownParameters(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetProcessTimes(HANDLE a0,
    LPFILETIME a1,
    LPFILETIME a2,
    LPFILETIME a3,
    LPFILETIME a4)
{
    _PrintEnter("GetProcessTimes(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetProcessTimes(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetProcessTimes(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetProcessVersion(DWORD a0)
{
    _PrintEnter("GetProcessVersion(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetProcessVersion(a0);
    }
    __finally {
        _PrintExit("GetProcessVersion() -> %p\n", rv);
    };
    return rv;
}

HWINSTA __stdcall Mine_GetProcessWindowStation(void)
{
    _PrintEnter("GetProcessWindowStation()\n");

    HWINSTA rv = 0;
    __try {
        rv = Real_GetProcessWindowStation();
    }
    __finally {
        _PrintExit("GetProcessWindowStation() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetProcessWorkingSetSize(HANDLE a0,
    PSIZE_T a1,
    PSIZE_T a2)
{
    _PrintEnter("GetProcessWorkingSetSize(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetProcessWorkingSetSize(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetProcessWorkingSetSize(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetProfileIntA(LPCSTR a0,
    LPCSTR a1,
    INT a2)
{
    _PrintEnter("GetProfileIntA(%hs,%hs,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetProfileIntA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetProfileIntA(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetProfileIntW(LPCWSTR a0,
    LPCWSTR a1,
    INT a2)
{
    _PrintEnter("GetProfileIntW(%ls,%ls,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GetProfileIntW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetProfileIntW(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetProfileSectionA(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("GetProfileSectionA(%hs,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetProfileSectionA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetProfileSectionA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetProfileSectionW(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
{
    _PrintEnter("GetProfileSectionW(%ls,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetProfileSectionW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetProfileSectionW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetProfileStringA(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    LPSTR a3,
    DWORD a4)
{
    _PrintEnter("GetProfileStringA(%hs,%hs,%hs,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_GetProfileStringA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetProfileStringA(,,,%hs,) -> %p\n", a3, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetProfileStringW(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    LPWSTR a3,
    DWORD a4)
{
    _PrintEnter("GetProfileStringW(%ls,%ls,%ls,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_GetProfileStringW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetProfileStringW(,,,%ls,) -> %p\n", a3, rv);
    };
    return rv;
}

HANDLE __stdcall Mine_GetPropA(HWND a0,
    LPCSTR a1)
{
    _PrintEnter("GetPropA(%p,%hs)\n", a0, a1);

    HANDLE rv = 0;
    __try {
        rv = Real_GetPropA(a0, a1);
    }
    __finally {
        _PrintExit("GetPropA(,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_GetPropW(HWND a0,
    LPCWSTR a1)
{
    _PrintEnter("GetPropW(%p,%ls)\n", a0, a1);

    HANDLE rv = 0;
    __try {
        rv = Real_GetPropW(a0, a1);
    }
    __finally {
        _PrintExit("GetPropW(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetQueueStatus(UINT a0)
{
    _PrintEnter("GetQueueStatus(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetQueueStatus(a0);
    }
    __finally {
        _PrintExit("GetQueueStatus() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetQueuedCompletionStatus(HANDLE a0,
    LPDWORD a1,
    PULONG_PTR a2,
    LPOVERLAPPED* a3,
    DWORD a4)
{
    _PrintEnter("GetQueuedCompletionStatus(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetQueuedCompletionStatus(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetQueuedCompletionStatus(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetROP2(HDC a0)
{
    _PrintEnter("GetROP2(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetROP2(a0);
    }
    __finally {
        _PrintExit("GetROP2() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetRasterizerCaps(LPRASTERIZER_STATUS a0,
    UINT a1)
{
    _PrintEnter("GetRasterizerCaps(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetRasterizerCaps(a0, a1);
    }
    __finally {
        _PrintExit("GetRasterizerCaps(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetRegionData(HRGN a0,
    DWORD a1,
    LPRGNDATA a2)
{
    _PrintEnter("GetRegionData(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetRegionData(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetRegionData(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetRgnBox(HRGN a0,
    LPRECT a1)
{
    _PrintEnter("GetRgnBox(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetRgnBox(a0, a1);
    }
    __finally {
        _PrintExit("GetRgnBox(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_GetRunningObjectTable(DWORD a0,
    LPRUNNINGOBJECTTABLE* a1)
{
    _PrintEnter("GetRunningObjectTable(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_GetRunningObjectTable(a0, a1);
    }
    __finally {
        _PrintExit("GetRunningObjectTable(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetScrollInfo(HWND a0,
    int a1,
    LPSCROLLINFO a2)
{
    _PrintEnter("GetScrollInfo(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetScrollInfo(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetScrollInfo(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetScrollPos(HWND a0,
    int a1)
{
    _PrintEnter("GetScrollPos(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetScrollPos(a0, a1);
    }
    __finally {
        _PrintExit("GetScrollPos(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetScrollRange(HWND a0,
    int a1,
    LPINT a2,
    LPINT a3)
{
    _PrintEnter("GetScrollRange(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetScrollRange(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetScrollRange(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetShortPathNameA(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("GetShortPathNameA(%hs,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetShortPathNameA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetShortPathNameA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetShortPathNameW(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
{
    _PrintEnter("GetShortPathNameW(%ls,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetShortPathNameW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetShortPathNameW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

void __stdcall Mine_GetStartupInfoA(LPSTARTUPINFOA a0)
{
    _PrintEnter("GetStartupInfoA(%p)\n", a0);

    __try {
        Real_GetStartupInfoA(a0);
    }
    __finally {
        _PrintExit("GetStartupInfoA() ->\n");
    };
}

void __stdcall Mine_GetStartupInfoW(LPSTARTUPINFOW a0)
{
    _PrintEnter("GetStartupInfoW(%p)\n", a0);

    __try {
        Real_GetStartupInfoW(a0);
    }
    __finally {
        _PrintExit("GetStartupInfoW() ->\n");
    };
}

HANDLE __stdcall Mine_GetStdHandle(DWORD a0)
{
    _PrintEnter("GetStdHandle(%p)\n", a0);

    HANDLE rv = 0;
    __try {
        rv = Real_GetStdHandle(a0);
    }
    __finally {
        _PrintExit("GetStdHandle() -> %p\n", rv);
    };
    return rv;
}

HGDIOBJ __stdcall Mine_GetStockObject(int a0)
{
    _PrintEnter("GetStockObject(%p)\n", a0);

    HGDIOBJ rv = 0;
    __try {
        rv = Real_GetStockObject(a0);
    }
    __finally {
        _PrintExit("GetStockObject() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetStretchBltMode(HDC a0)
{
    _PrintEnter("GetStretchBltMode(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetStretchBltMode(a0);
    }
    __finally {
        _PrintExit("GetStretchBltMode() -> %p\n", rv);
    };
    return rv;
}

HMENU __stdcall Mine_GetSubMenu(HMENU a0,
    int a1)
{
    _PrintEnter("GetSubMenu(%p,%p)\n", a0, a1);

    HMENU rv = 0;
    __try {
        rv = Real_GetSubMenu(a0, a1);
    }
    __finally {
        _PrintExit("GetSubMenu(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetSysColor(int a0)
{
    _PrintEnter("GetSysColor(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetSysColor(a0);
    }
    __finally {
        _PrintExit("GetSysColor() -> %p\n", rv);
    };
    return rv;
}

HBRUSH __stdcall Mine_GetSysColorBrush(int a0)
{
    _PrintEnter("GetSysColorBrush(%p)\n", a0);

    HBRUSH rv = 0;
    __try {
        rv = Real_GetSysColorBrush(a0);
    }
    __finally {
        _PrintExit("GetSysColorBrush() -> %p\n", rv);
    };
    return rv;
}

LCID __stdcall Mine_GetSystemDefaultLCID(void)
{
    _PrintEnter("GetSystemDefaultLCID()\n");

    LCID rv = 0;
    __try {
        rv = Real_GetSystemDefaultLCID();
    }
    __finally {
        _PrintExit("GetSystemDefaultLCID() -> %p\n", rv);
    };
    return rv;
}

LANGID __stdcall Mine_GetSystemDefaultLangID(void)
{
    _PrintEnter("GetSystemDefaultLangID()\n");

    LANGID rv = 0;
    __try {
        rv = Real_GetSystemDefaultLangID();
    }
    __finally {
        _PrintExit("GetSystemDefaultLangID() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetSystemDirectoryA(LPSTR a0,
    UINT a1)
{
    _PrintEnter("GetSystemDirectoryA(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetSystemDirectoryA(a0, a1);
    }
    __finally {
        _PrintExit("GetSystemDirectoryA(%hs,) -> %p\n", a0, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetSystemDirectoryW(LPWSTR a0,
    UINT a1)
{
    _PrintEnter("GetSystemDirectoryW(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetSystemDirectoryW(a0, a1);
    }
    __finally {
        _PrintExit("GetSystemDirectoryW(%ls,) -> %p\n", a0, rv);
    };
    return rv;
}

void __stdcall Mine_GetSystemInfo(LPSYSTEM_INFO a0)
{
    _PrintEnter("GetSystemInfo(%p)\n", a0);

    __try {
        Real_GetSystemInfo(a0);
    }
    __finally {
        _PrintExit("GetSystemInfo() ->\n");
    };
}

HMENU __stdcall Mine_GetSystemMenu(HWND a0,
    BOOL a1)
{
    _PrintEnter("GetSystemMenu(%p,%p)\n", a0, a1);

    HMENU rv = 0;
    __try {
        rv = Real_GetSystemMenu(a0, a1);
    }
    __finally {
        _PrintExit("GetSystemMenu(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetSystemMetrics(int a0)
{
    _PrintEnter("GetSystemMetrics(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetSystemMetrics(a0);
    }
    __finally {
        _PrintExit("GetSystemMetrics() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetSystemPaletteEntries(HDC a0,
    UINT a1,
    UINT a2,
    PALETTEENTRY* a3)
{
    _PrintEnter("GetSystemPaletteEntries(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetSystemPaletteEntries(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetSystemPaletteEntries(,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetSystemPaletteUse(HDC a0)
{
    _PrintEnter("GetSystemPaletteUse(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_GetSystemPaletteUse(a0);
    }
    __finally {
        _PrintExit("GetSystemPaletteUse() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetSystemPowerStatus(LPSYSTEM_POWER_STATUS a0)
{
    _PrintEnter("GetSystemPowerStatus(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetSystemPowerStatus(a0);
    }
    __finally {
        _PrintExit("GetSystemPowerStatus() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_GetSystemTime(LPSYSTEMTIME a0)
{
    _PrintEnter("GetSystemTime(%p)\n", a0);

    __try {
        Real_GetSystemTime(a0);
    }
    __finally {
        _PrintExit("GetSystemTime() ->\n");
    };
}

BOOL __stdcall Mine_GetSystemTimeAdjustment(PDWORD a0,
    PDWORD a1,
    PBOOL a2)
{
    _PrintEnter("GetSystemTimeAdjustment(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetSystemTimeAdjustment(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetSystemTimeAdjustment(,,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_GetSystemTimeAsFileTime(LPFILETIME a0)
{
    _PrintEnter("GetSystemTimeAsFileTime(%p)\n", a0);

    __try {
        Real_GetSystemTimeAsFileTime(a0);
    }
    __finally {
        _PrintExit("GetSystemTimeAsFileTime() ->\n");
    };
}

DWORD __stdcall Mine_GetTabbedTextExtentA(HDC a0,
    LPCSTR a1,
    int a2,
    int a3,
    INT* a4)
{
    _PrintEnter("GetTabbedTextExtentA(%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_GetTabbedTextExtentA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetTabbedTextExtentA(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetTabbedTextExtentW(HDC a0,
    LPCWSTR a1,
    int a2,
    int a3,
    INT* a4)
{
    _PrintEnter("GetTabbedTextExtentW(%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_GetTabbedTextExtentW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetTabbedTextExtentW(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetTapeParameters(HANDLE a0,
    DWORD a1,
    LPDWORD a2,
    LPVOID a3)
{
    _PrintEnter("GetTapeParameters(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_GetTapeParameters(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetTapeParameters(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetTapePosition(HANDLE a0,
    DWORD a1,
    LPDWORD a2,
    LPDWORD a3,
    LPDWORD a4)
{
    _PrintEnter("GetTapePosition(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_GetTapePosition(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetTapePosition(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetTapeStatus(HANDLE a0)
{
    _PrintEnter("GetTapeStatus(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetTapeStatus(a0);
    }
    __finally {
        _PrintExit("GetTapeStatus() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetTempFileNameA(LPCSTR a0,
    LPCSTR a1,
    UINT a2,
    LPSTR a3)
{
    _PrintEnter("GetTempFileNameA(%hs,%hs,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetTempFileNameA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetTempFileNameA(,,,%hs) -> %p\n", a3, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetTempFileNameW(LPCWSTR a0,
    LPCWSTR a1,
    UINT a2,
    LPWSTR a3)
{
    _PrintEnter("GetTempFileNameW(%ls,%ls,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_GetTempFileNameW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetTempFileNameW(,,,%ls) -> %p\n", a3, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetTempPathA(DWORD a0,
    LPSTR a1)
{
    _PrintEnter("GetTempPathA(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetTempPathA(a0, a1);
    }
    __finally {
        _PrintExit("GetTempPathA(,%hs) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetTempPathW(DWORD a0,
    LPWSTR a1)
{
    _PrintEnter("GetTempPathW(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetTempPathW(a0, a1);
    }
    __finally {
        _PrintExit("GetTempPathW(,%ls) -> %p\n", a1, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetTextAlign(HDC a0)
{
    _PrintEnter("GetTextAlign(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_GetTextAlign(a0);
    }
    __finally {
        _PrintExit("GetTextAlign() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetTextCharacterExtra(HDC a0)
{
    _PrintEnter("GetTextCharacterExtra(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetTextCharacterExtra(a0);
    }
    __finally {
        _PrintExit("GetTextCharacterExtra() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetTextCharset(HDC a0)
{
    _PrintEnter("GetTextCharset(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetTextCharset(a0);
    }
    __finally {
        _PrintExit("GetTextCharset() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetTextCharsetInfo(HDC a0,
    LPFONTSIGNATURE a1,
    DWORD a2)
{
    _PrintEnter("GetTextCharsetInfo(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetTextCharsetInfo(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetTextCharsetInfo(,,) -> %p\n", rv);
    };
    return rv;
}

COLORREF __stdcall Mine_GetTextColor(HDC a0)
{
    _PrintEnter("GetTextColor(%p)\n", a0);

    COLORREF rv = 0;
    __try {
        rv = Real_GetTextColor(a0);
    }
    __finally {
        _PrintExit("GetTextColor() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetTextExtentExPointA(HDC a0,
    LPCSTR a1,
    int a2,
    int a3,
    LPINT a4,
    LPINT a5,
    SIZE* a6)
{
    _PrintEnter("GetTextExtentExPointA(%p,%hs,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_GetTextExtentExPointA(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("GetTextExtentExPointA(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetTextExtentExPointW(HDC a0,
    LPCWSTR a1,
    int a2,
    int a3,
    LPINT a4,
    LPINT a5,
    SIZE* a6)
{
    _PrintEnter("GetTextExtentExPointW(%p,%ls,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_GetTextExtentExPointW(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("GetTextExtentExPointW(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetTextExtentPoint32A(HDC a0,
    LPCSTR a1,
    int a2,
    SIZE* a3)
{
    _PrintEnter("GetTextExtentPoint32A(%p,%hs,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetTextExtentPoint32A(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetTextExtentPoint32A(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetTextExtentPoint32W(HDC a0,
    LPCWSTR a1,
    int a2,
    SIZE* a3)
{
    _PrintEnter("GetTextExtentPoint32W(%p,%ls,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetTextExtentPoint32W(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetTextExtentPoint32W(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetTextExtentPointA(HDC a0,
    LPCSTR a1,
    int a2,
    SIZE* a3)
{
    _PrintEnter("GetTextExtentPointA(%p,%hs,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetTextExtentPointA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetTextExtentPointA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetTextExtentPointW(HDC a0,
    LPCWSTR a1,
    int a2,
    SIZE* a3)
{
    _PrintEnter("GetTextExtentPointW(%p,%ls,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_GetTextExtentPointW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("GetTextExtentPointW(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetTextFaceA(HDC a0,
    int a1,
    LPSTR a2)
{
    _PrintEnter("GetTextFaceA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetTextFaceA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetTextFaceA(,,%hs) -> %p\n", a2, rv);
    };
    return rv;
}

int __stdcall Mine_GetTextFaceW(HDC a0,
    int a1,
    LPWSTR a2)
{
    _PrintEnter("GetTextFaceW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetTextFaceW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetTextFaceW(,,%ls) -> %p\n", a2, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetTextMetricsA(HDC a0,
    LPTEXTMETRICA a1)
{
    _PrintEnter("GetTextMetricsA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetTextMetricsA(a0, a1);
    }
    __finally {
        _PrintExit("GetTextMetricsA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetTextMetricsW(HDC a0,
    LPTEXTMETRICW a1)
{
    _PrintEnter("GetTextMetricsW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetTextMetricsW(a0, a1);
    }
    __finally {
        _PrintExit("GetTextMetricsW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetThreadContext(HANDLE a0,
    LPCONTEXT a1)
{
    _PrintEnter("GetThreadContext(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetThreadContext(a0, a1);
    }
    __finally {
        _PrintExit("GetThreadContext(,) -> %p\n", rv);
    };
    return rv;
}

HDESK __stdcall Mine_GetThreadDesktop(DWORD a0)
{
    _PrintEnter("GetThreadDesktop(%p)\n", a0);

    HDESK rv = 0;
    __try {
        rv = Real_GetThreadDesktop(a0);
    }
    __finally {
        _PrintExit("GetThreadDesktop() -> %p\n", rv);
    };
    return rv;
}

#if(WINVER >= 0x0500)
LCID __stdcall Mine_GetThreadLocale(void)
{
    _PrintEnter("GetThreadLocale()\n");

    LCID rv = 0;
    __try {
        rv = Real_GetThreadLocale();
    }
    __finally {
        _PrintExit("GetThreadLocale() -> %p\n", rv);
    };
    return rv;
}
#endif // (WINVER >= 0x0500)

int __stdcall Mine_GetThreadPriority(HANDLE a0)
{
    _PrintEnter("GetThreadPriority(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetThreadPriority(a0);
    }
    __finally {
        _PrintExit("GetThreadPriority() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetThreadPriorityBoost(HANDLE a0,
    PBOOL a1)
{
    _PrintEnter("GetThreadPriorityBoost(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetThreadPriorityBoost(a0, a1);
    }
    __finally {
        _PrintExit("GetThreadPriorityBoost(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetThreadSelectorEntry(HANDLE a0,
    DWORD a1,
    LPLDT_ENTRY a2)
{
    _PrintEnter("GetThreadSelectorEntry(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetThreadSelectorEntry(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetThreadSelectorEntry(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetThreadTimes(HANDLE a0,
    LPFILETIME a1,
    LPFILETIME a2,
    LPFILETIME a3,
    LPFILETIME a4)
{
    _PrintEnter("GetThreadTimes(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetThreadTimes(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetThreadTimes(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetTickCount(void)
{
    _PrintEnter("GetTickCount()\n");

    DWORD rv = 0;
    __try {
        rv = Real_GetTickCount();
    }
    __finally {
        _PrintExit("GetTickCount() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetTimeFormatA(LCID a0,
    DWORD a1,
    SYSTEMTIME* a2,
    LPCSTR a3,
    LPSTR a4,
    int a5)
{
    _PrintEnter("GetTimeFormatA(%p,%p,%p,%hs,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_GetTimeFormatA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetTimeFormatA(,,,,%hs,) -> %p\n", a4, rv);
    };
    return rv;
}

int __stdcall Mine_GetTimeFormatW(LCID a0,
    DWORD a1,
    SYSTEMTIME* a2,
    LPCWSTR a3,
    LPWSTR a4,
    int a5)
{
    _PrintEnter("GetTimeFormatW(%p,%p,%p,%ls,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_GetTimeFormatW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("GetTimeFormatW(,,,,%ls,) -> %p\n", a4, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetTimeZoneInformation(LPTIME_ZONE_INFORMATION a0)
{
    _PrintEnter("GetTimeZoneInformation(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetTimeZoneInformation(a0);
    }
    __finally {
        _PrintExit("GetTimeZoneInformation() -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetTopWindow(HWND a0)
{
    _PrintEnter("GetTopWindow(%p)\n", a0);

    HWND rv = 0;
    __try {
        rv = Real_GetTopWindow(a0);
    }
    __finally {
        _PrintExit("GetTopWindow() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetUpdateRect(HWND a0,
    LPRECT a1,
    BOOL a2)
{
    _PrintEnter("GetUpdateRect(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_GetUpdateRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetUpdateRect(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetUpdateRgn(HWND a0,
    HRGN a1,
    BOOL a2)
{
    _PrintEnter("GetUpdateRgn(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetUpdateRgn(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetUpdateRgn(,,) -> %p\n", rv);
    };
    return rv;
}

LCID __stdcall Mine_GetUserDefaultLCID(void)
{
    _PrintEnter("GetUserDefaultLCID()\n");

    LCID rv = 0;
    __try {
        rv = Real_GetUserDefaultLCID();
    }
    __finally {
        _PrintExit("GetUserDefaultLCID() -> %p\n", rv);
    };
    return rv;
}

LANGID __stdcall Mine_GetUserDefaultLangID(void)
{
    _PrintEnter("GetUserDefaultLangID()\n");

    LANGID rv = 0;
    __try {
        rv = Real_GetUserDefaultLangID();
    }
    __finally {
        _PrintExit("GetUserDefaultLangID() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetUserObjectInformationA(HANDLE a0,
    int a1,
    PVOID a2,
    DWORD a3,
    LPDWORD a4)
{
    _PrintEnter("GetUserObjectInformationA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetUserObjectInformationA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetUserObjectInformationA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetUserObjectInformationW(HANDLE a0,
    int a1,
    PVOID a2,
    DWORD a3,
    LPDWORD a4)
{
    _PrintEnter("GetUserObjectInformationW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetUserObjectInformationW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetUserObjectInformationW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetUserObjectSecurity(HANDLE a0,
    PSECURITY_INFORMATION a1,
    PSECURITY_DESCRIPTOR a2,
    DWORD a3,
    LPDWORD a4)
{
    _PrintEnter("GetUserObjectSecurity(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetUserObjectSecurity(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetUserObjectSecurity(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetVersion(void)
{
    _PrintEnter("GetVersion()\n");

    DWORD rv = 0;
    __try {
        rv = Real_GetVersion();
    }
    __finally {
        _PrintExit("GetVersion() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetVersionExA(LPOSVERSIONINFOA a0)
{
    _PrintEnter("GetVersionExA(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetVersionExA(a0);
    }
    __finally {
        _PrintExit("GetVersionExA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetVersionExW(LPOSVERSIONINFOW a0)
{
    _PrintEnter("GetVersionExW(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetVersionExW(a0);
    }
    __finally {
        _PrintExit("GetVersionExW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetViewportExtEx(HDC a0,
    SIZE* a1)
{
    _PrintEnter("GetViewportExtEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetViewportExtEx(a0, a1);
    }
    __finally {
        _PrintExit("GetViewportExtEx(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetViewportOrgEx(HDC a0,
    POINT* a1)
{
    _PrintEnter("GetViewportOrgEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetViewportOrgEx(a0, a1);
    }
    __finally {
        _PrintExit("GetViewportOrgEx(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetVolumeInformationA(LPCSTR a0,
    LPSTR a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPDWORD a5,
    LPSTR a6,
    DWORD a7)
{
    _PrintEnter("GetVolumeInformationA(%hs,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    BOOL rv = 0;
    __try {
        rv = Real_GetVolumeInformationA(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("GetVolumeInformationA(,%hs,,,,,%hs,) -> %p\n", a1, a6, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetVolumeInformationW(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPDWORD a5,
    LPWSTR a6,
    DWORD a7)
{
    _PrintEnter("GetVolumeInformationW(%ls,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    BOOL rv = 0;
    __try {
        rv = Real_GetVolumeInformationW(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("GetVolumeInformationW(,%ls,,,,,%ls,) -> %p\n", a1, a6, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetWinMetaFileBits(HENHMETAFILE a0,
    UINT a1,
    LPBYTE a2,
    INT a3,
    HDC a4)
{
    _PrintEnter("GetWinMetaFileBits(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    UINT rv = 0;
    __try {
        rv = Real_GetWinMetaFileBits(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("GetWinMetaFileBits(,,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_GetWindow(HWND a0,
    UINT a1)
{
    _PrintEnter("GetWindow(%p,%p)\n", a0, a1);

    HWND rv = 0;
    __try {
        rv = Real_GetWindow(a0, a1);
    }
    __finally {
        _PrintExit("GetWindow(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetWindowContextHelpId(HWND a0)
{
    _PrintEnter("GetWindowContextHelpId(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetWindowContextHelpId(a0);
    }
    __finally {
        _PrintExit("GetWindowContextHelpId() -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_GetWindowDC(HWND a0)
{
    _PrintEnter("GetWindowDC(%p)\n", a0);

    HDC rv = 0;
    __try {
        rv = Real_GetWindowDC(a0);
    }
    __finally {
        _PrintExit("GetWindowDC() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetWindowExtEx(HDC a0,
    SIZE* a1)
{
    _PrintEnter("GetWindowExtEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetWindowExtEx(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowExtEx(,) -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_GetWindowLongA(HWND a0,
    int a1)
{
    _PrintEnter("GetWindowLongA(%p,%p)\n", a0, a1);

    LONG rv = 0;
    __try {
        rv = Real_GetWindowLongA(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowLongA(,) -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_GetWindowLongW(HWND a0,
    int a1)
{
    _PrintEnter("GetWindowLongW(%p,%p)\n", a0, a1);

    LONG rv = 0;
    __try {
        rv = Real_GetWindowLongW(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowLongW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetWindowOrgEx(HDC a0,
    POINT* a1)
{
    _PrintEnter("GetWindowOrgEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetWindowOrgEx(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowOrgEx(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetWindowPlacement(HWND a0,
    WINDOWPLACEMENT* a1)
{
    _PrintEnter("GetWindowPlacement(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetWindowPlacement(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowPlacement(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetWindowRect(HWND a0,
    LPRECT a1)
{
    _PrintEnter("GetWindowRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetWindowRect(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowRect(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetWindowRgn(HWND a0,
    HRGN a1)
{
    _PrintEnter("GetWindowRgn(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetWindowRgn(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowRgn(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetWindowTextA(HWND a0,
    LPSTR a1,
    int a2)
{
    _PrintEnter("GetWindowTextA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetWindowTextA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetWindowTextA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_GetWindowTextLengthA(HWND a0)
{
    _PrintEnter("GetWindowTextLengthA(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetWindowTextLengthA(a0);
    }
    __finally {
        _PrintExit("GetWindowTextLengthA() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetWindowTextLengthW(HWND a0)
{
    _PrintEnter("GetWindowTextLengthW(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_GetWindowTextLengthW(a0);
    }
    __finally {
        _PrintExit("GetWindowTextLengthW() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_GetWindowTextW(HWND a0,
    LPWSTR a1,
    int a2)
{
    _PrintEnter("GetWindowTextW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_GetWindowTextW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GetWindowTextW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_GetWindowThreadProcessId(HWND a0,
    LPDWORD a1)
{
    _PrintEnter("GetWindowThreadProcessId(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetWindowThreadProcessId(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowThreadProcessId(,) -> %p\n", rv);
    };
    return rv;
}

WORD __stdcall Mine_GetWindowWord(HWND a0,
    int a1)
{
    _PrintEnter("GetWindowWord(%p,%p)\n", a0, a1);

    WORD rv = 0;
    __try {
        rv = Real_GetWindowWord(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowWord(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GetWindowsDirectoryA(LPSTR a0,
    UINT a1)
{
    _PrintEnter("GetWindowsDirectoryA(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetWindowsDirectoryA(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowsDirectoryA(%hs,) -> %p\n", a0, rv);
    };
    return rv;
}

UINT __stdcall Mine_GetWindowsDirectoryW(LPWSTR a0,
    UINT a1)
{
    _PrintEnter("GetWindowsDirectoryW(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetWindowsDirectoryW(a0, a1);
    }
    __finally {
        _PrintExit("GetWindowsDirectoryW(%ls,) -> %p\n", a0, rv);
    };
    return rv;
}

BOOL __stdcall Mine_GetWorldTransform(HDC a0,
    XFORM* a1)
{
    _PrintEnter("GetWorldTransform(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetWorldTransform(a0, a1);
    }
    __finally {
        _PrintExit("GetWorldTransform(,) -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_GlobalAddAtomA(LPCSTR a0)
{
    _PrintEnter("GlobalAddAtomA(%hs)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_GlobalAddAtomA(a0);
    }
    __finally {
        _PrintExit("GlobalAddAtomA() -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_GlobalAddAtomW(LPCWSTR a0)
{
    _PrintEnter("GlobalAddAtomW(%ls)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_GlobalAddAtomW(a0);
    }
    __finally {
        _PrintExit("GlobalAddAtomW() -> %p\n", rv);
    };
    return rv;
}

HGLOBAL __stdcall Mine_GlobalAlloc(UINT a0,
    SIZE_T a1)
{
    _PrintEnter("GlobalAlloc(%p,%p)\n", a0, a1);

    HGLOBAL rv = 0;
    __try {
        rv = Real_GlobalAlloc(a0, a1);
    }
    __finally {
        _PrintExit("GlobalAlloc(,) -> %p\n", rv);
    };
    return rv;
}

SIZE_T __stdcall Mine_GlobalCompact(DWORD a0)
{
    _PrintEnter("GlobalCompact(%p)\n", a0);

    SIZE_T rv = 0;
    __try {
        rv = Real_GlobalCompact(a0);
    }
    __finally {
        _PrintExit("GlobalCompact() -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_GlobalDeleteAtom(ATOM a0)
{
    _PrintEnter("GlobalDeleteAtom(%p)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_GlobalDeleteAtom(a0);
    }
    __finally {
        _PrintExit("GlobalDeleteAtom() -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_GlobalFindAtomA(LPCSTR a0)
{
    _PrintEnter("GlobalFindAtomA(%hs)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_GlobalFindAtomA(a0);
    }
    __finally {
        _PrintExit("GlobalFindAtomA() -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_GlobalFindAtomW(LPCWSTR a0)
{
    _PrintEnter("GlobalFindAtomW(%ls)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_GlobalFindAtomW(a0);
    }
    __finally {
        _PrintExit("GlobalFindAtomW() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_GlobalFix(HGLOBAL a0)
{
    _PrintEnter("GlobalFix(%p)\n", a0);

    __try {
        Real_GlobalFix(a0);
    }
    __finally {
        _PrintExit("GlobalFix() ->\n");
    };
}

UINT __stdcall Mine_GlobalFlags(HGLOBAL a0)
{
    _PrintEnter("GlobalFlags(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_GlobalFlags(a0);
    }
    __finally {
        _PrintExit("GlobalFlags() -> %p\n", rv);
    };
    return rv;
}

HGLOBAL __stdcall Mine_GlobalFree(HGLOBAL a0)
{
    _PrintEnter("GlobalFree(%p)\n", a0);

    HGLOBAL rv = 0;
    __try {
        rv = Real_GlobalFree(a0);
    }
    __finally {
        _PrintExit("GlobalFree() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_GlobalGetAtomNameA(ATOM a0,
    LPSTR a1,
    int a2)
{
    _PrintEnter("GlobalGetAtomNameA(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GlobalGetAtomNameA(a0, a1, a2);
    }
    __finally {
        _PrintExit("GlobalGetAtomNameA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

UINT __stdcall Mine_GlobalGetAtomNameW(ATOM a0,
    LPWSTR a1,
    int a2)
{
    _PrintEnter("GlobalGetAtomNameW(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_GlobalGetAtomNameW(a0, a1, a2);
    }
    __finally {
        _PrintExit("GlobalGetAtomNameW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

HGLOBAL __stdcall Mine_GlobalHandle(LPCVOID a0)
{
    _PrintEnter("GlobalHandle(%p)\n", a0);

    HGLOBAL rv = 0;
    __try {
        rv = Real_GlobalHandle(a0);
    }
    __finally {
        _PrintExit("GlobalHandle() -> %p\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_GlobalLock(HGLOBAL a0)
{
    _PrintEnter("GlobalLock(%p)\n", a0);

    LPVOID rv = 0;
    __try {
        rv = Real_GlobalLock(a0);
    }
    __finally {
        _PrintExit("GlobalLock() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_GlobalMemoryStatus(LPMEMORYSTATUS a0)
{
    _PrintEnter("GlobalMemoryStatus(%p)\n", a0);

    __try {
        Real_GlobalMemoryStatus(a0);
    }
    __finally {
        _PrintExit("GlobalMemoryStatus() ->\n");
    };
}

HGLOBAL __stdcall Mine_GlobalReAlloc(HGLOBAL a0,
    SIZE_T a1,
    UINT a2)
{
    _PrintEnter("GlobalReAlloc(%p,%p,%p)\n", a0, a1, a2);

    HGLOBAL rv = 0;
    __try {
        rv = Real_GlobalReAlloc(a0, a1, a2);
    }
    __finally {
        _PrintExit("GlobalReAlloc(,,) -> %p\n", rv);
    };
    return rv;
}

SIZE_T __stdcall Mine_GlobalSize(HGLOBAL a0)
{
    _PrintEnter("GlobalSize(%p)\n", a0);

    SIZE_T rv = 0;
    __try {
        rv = Real_GlobalSize(a0);
    }
    __finally {
        _PrintExit("GlobalSize() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GlobalUnWire(HGLOBAL a0)
{
    _PrintEnter("GlobalUnWire(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GlobalUnWire(a0);
    }
    __finally {
        _PrintExit("GlobalUnWire() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_GlobalUnfix(HGLOBAL a0)
{
    _PrintEnter("GlobalUnfix(%p)\n", a0);

    __try {
        Real_GlobalUnfix(a0);
    }
    __finally {
        _PrintExit("GlobalUnfix() ->\n");
    };
}

BOOL __stdcall Mine_GlobalUnlock(HGLOBAL a0)
{
    _PrintEnter("GlobalUnlock(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GlobalUnlock(a0);
    }
    __finally {
        _PrintExit("GlobalUnlock() -> %p\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_GlobalWire(HGLOBAL a0)
{
    _PrintEnter("GlobalWire(%p)\n", a0);

    LPVOID rv = 0;
    __try {
        rv = Real_GlobalWire(a0);
    }
    __finally {
        _PrintExit("GlobalWire() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GrayStringA(HDC a0,
    HBRUSH a1,
    GRAYSTRINGPROC a2,
    LPARAM a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
{
    _PrintEnter("GrayStringA(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    BOOL rv = 0;
    __try {
        rv = Real_GrayStringA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("GrayStringA(,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_GrayStringW(HDC a0,
    HBRUSH a1,
    GRAYSTRINGPROC a2,
    LPARAM a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
{
    _PrintEnter("GrayStringW(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    BOOL rv = 0;
    __try {
        rv = Real_GrayStringW(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("GrayStringW(,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_HeapLock(HANDLE a0)
{
    _PrintEnter("HeapLock(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_HeapLock(a0);
    }
    __finally {
        _PrintExit("HeapLock() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_HeapUnlock(HANDLE a0)
{
    _PrintEnter("HeapUnlock(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_HeapUnlock(a0);
    }
    __finally {
        _PrintExit("HeapUnlock() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_HideCaret(HWND a0)
{
    _PrintEnter("HideCaret(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_HideCaret(a0);
    }
    __finally {
        _PrintExit("HideCaret() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_HiliteMenuItem(HWND a0,
    HMENU a1,
    UINT a2,
    UINT a3)
{
    _PrintEnter("HiliteMenuItem(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_HiliteMenuItem(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("HiliteMenuItem(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_IIDFromString(LPOLESTR a0,
    LPGUID a1)
{
    _PrintEnter("IIDFromString(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_IIDFromString(a0, a1);
    }
    __finally {
        _PrintExit("IIDFromString(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ImpersonateDdeClientWindow(HWND a0,
    HWND a1)
{
    _PrintEnter("ImpersonateDdeClientWindow(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ImpersonateDdeClientWindow(a0, a1);
    }
    __finally {
        _PrintExit("ImpersonateDdeClientWindow(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InSendMessage(void)
{
    _PrintEnter("InSendMessage()\n");

    BOOL rv = 0;
    __try {
        rv = Real_InSendMessage();
    }
    __finally {
        _PrintExit("InSendMessage() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InflateRect(LPRECT a0,
    int a1,
    int a2)
{
    _PrintEnter("InflateRect(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_InflateRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("InflateRect(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InitAtomTable(DWORD a0)
{
    _PrintEnter("InitAtomTable(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_InitAtomTable(a0);
    }
    __finally {
        _PrintExit("InitAtomTable() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InsertMenuA(HMENU a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    LPCSTR a4)
{
    _PrintEnter("InsertMenuA(%p,%p,%p,%p,%hs)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_InsertMenuA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("InsertMenuA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InsertMenuItemA(HMENU a0,
    UINT a1,
    BOOL a2,
    MENUITEMINFOA* a3)
{
    _PrintEnter("InsertMenuItemA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_InsertMenuItemA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("InsertMenuItemA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InsertMenuItemW(HMENU a0,
    UINT a1,
    BOOL a2,
    MENUITEMINFOW* a3)
{
    _PrintEnter("InsertMenuItemW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_InsertMenuItemW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("InsertMenuItemW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InsertMenuW(HMENU a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    LPCWSTR a4)
{
    _PrintEnter("InsertMenuW(%p,%p,%p,%p,%ls)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_InsertMenuW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("InsertMenuW(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_IntersectClipRect(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4)
{
    _PrintEnter("IntersectClipRect(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_IntersectClipRect(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("IntersectClipRect(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IntersectRect(LPRECT a0,
    RECT* a1,
    RECT* a2)
{
    _PrintEnter("IntersectRect(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_IntersectRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("IntersectRect(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InvalidateRect(HWND a0,
    RECT* a1,
    BOOL a2)
{
    _PrintEnter("InvalidateRect(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_InvalidateRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("InvalidateRect(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InvalidateRgn(HWND a0,
    HRGN a1,
    BOOL a2)
{
    _PrintEnter("InvalidateRgn(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_InvalidateRgn(a0, a1, a2);
    }
    __finally {
        _PrintExit("InvalidateRgn(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InvertRect(HDC a0,
    RECT* a1)
{
    _PrintEnter("InvertRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_InvertRect(a0, a1);
    }
    __finally {
        _PrintExit("InvertRect(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_InvertRgn(HDC a0,
    HRGN a1)
{
    _PrintEnter("InvertRgn(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_InvertRgn(a0, a1);
    }
    __finally {
        _PrintExit("InvertRgn(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsAccelerator(HACCEL a0,
    int a1,
    LPMSG a2,
    WORD* a3)
{
    _PrintEnter("IsAccelerator(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_IsAccelerator(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("IsAccelerator(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsBadCodePtr(FARPROC a0)
{
    _PrintEnter("IsBadCodePtr(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsBadCodePtr(a0);
    }
    __finally {
        _PrintExit("IsBadCodePtr() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsBadHugeReadPtr(void* a0,
    UINT_PTR a1)
{
    _PrintEnter("IsBadHugeReadPtr(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsBadHugeReadPtr(a0, a1);
    }
    __finally {
        _PrintExit("IsBadHugeReadPtr(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsBadHugeWritePtr(LPVOID a0,
    UINT_PTR a1)
{
    _PrintEnter("IsBadHugeWritePtr(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsBadHugeWritePtr(a0, a1);
    }
    __finally {
        _PrintExit("IsBadHugeWritePtr(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsBadReadPtr(void* a0,
    UINT_PTR a1)
{
    _PrintEnter("IsBadReadPtr(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsBadReadPtr(a0, a1);
    }
    __finally {
        _PrintExit("IsBadReadPtr(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsBadStringPtrA(LPCSTR a0,
    UINT_PTR a1)
{
    _PrintEnter("IsBadStringPtrA(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsBadStringPtrA(a0, a1);
    }
    __finally {
        _PrintExit("IsBadStringPtrA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsBadStringPtrW(LPCWSTR a0,
    UINT_PTR a1)
{
    _PrintEnter("IsBadStringPtrW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsBadStringPtrW(a0, a1);
    }
    __finally {
        _PrintExit("IsBadStringPtrW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsBadWritePtr(LPVOID a0,
    UINT_PTR a1)
{
    _PrintEnter("IsBadWritePtr(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsBadWritePtr(a0, a1);
    }
    __finally {
        _PrintExit("IsBadWritePtr(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsCharAlphaA(CHAR a0)
{
    _PrintEnter("IsCharAlphaA(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsCharAlphaA(a0);
    }
    __finally {
        _PrintExit("IsCharAlphaA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsCharAlphaNumericA(CHAR a0)
{
    _PrintEnter("IsCharAlphaNumericA(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsCharAlphaNumericA(a0);
    }
    __finally {
        _PrintExit("IsCharAlphaNumericA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsCharAlphaNumericW(WCHAR a0)
{
    _PrintEnter("IsCharAlphaNumericW(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsCharAlphaNumericW(a0);
    }
    __finally {
        _PrintExit("IsCharAlphaNumericW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsCharAlphaW(WCHAR a0)
{
    _PrintEnter("IsCharAlphaW(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsCharAlphaW(a0);
    }
    __finally {
        _PrintExit("IsCharAlphaW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsCharLowerA(CHAR a0)
{
    _PrintEnter("IsCharLowerA(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsCharLowerA(a0);
    }
    __finally {
        _PrintExit("IsCharLowerA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsCharLowerW(WCHAR a0)
{
    _PrintEnter("IsCharLowerW(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsCharLowerW(a0);
    }
    __finally {
        _PrintExit("IsCharLowerW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsCharUpperA(CHAR a0)
{
    _PrintEnter("IsCharUpperA(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsCharUpperA(a0);
    }
    __finally {
        _PrintExit("IsCharUpperA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsCharUpperW(WCHAR a0)
{
    _PrintEnter("IsCharUpperW(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsCharUpperW(a0);
    }
    __finally {
        _PrintExit("IsCharUpperW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsChild(HWND a0,
    HWND a1)
{
    _PrintEnter("IsChild(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsChild(a0, a1);
    }
    __finally {
        _PrintExit("IsChild(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsClipboardFormatAvailable(UINT a0)
{
    _PrintEnter("IsClipboardFormatAvailable(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsClipboardFormatAvailable(a0);
    }
    __finally {
        _PrintExit("IsClipboardFormatAvailable() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsDBCSLeadByte(BYTE a0)
{
    _PrintEnter("IsDBCSLeadByte(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsDBCSLeadByte(a0);
    }
    __finally {
        _PrintExit("IsDBCSLeadByte() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsDBCSLeadByteEx(UINT a0,
    BYTE a1)
{
    _PrintEnter("IsDBCSLeadByteEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsDBCSLeadByteEx(a0, a1);
    }
    __finally {
        _PrintExit("IsDBCSLeadByteEx(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsDebuggerPresent(void)
{
    _PrintEnter("IsDebuggerPresent()\n");

    BOOL rv = 0;
    __try {
        rv = Real_IsDebuggerPresent();
    }
    __finally {
        _PrintExit("IsDebuggerPresent() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsDialogMessageA(HWND a0,
    LPMSG a1)
{
    _PrintEnter("IsDialogMessageA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsDialogMessageA(a0, a1);
    }
    __finally {
        _PrintExit("IsDialogMessageA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsDialogMessageW(HWND a0,
    LPMSG a1)
{
    _PrintEnter("IsDialogMessageW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsDialogMessageW(a0, a1);
    }
    __finally {
        _PrintExit("IsDialogMessageW(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_IsDlgButtonChecked(HWND a0,
    int a1)
{
    _PrintEnter("IsDlgButtonChecked(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_IsDlgButtonChecked(a0, a1);
    }
    __finally {
        _PrintExit("IsDlgButtonChecked(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsIconic(HWND a0)
{
    _PrintEnter("IsIconic(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsIconic(a0);
    }
    __finally {
        _PrintExit("IsIconic() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsMenu(HMENU a0)
{
    _PrintEnter("IsMenu(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsMenu(a0);
    }
    __finally {
        _PrintExit("IsMenu() -> %p\n", rv);
    };
    return rv;
}

#if !defined(DETOURS_ARM)
BOOL __stdcall Mine_IsProcessorFeaturePresent(DWORD a0)
{
    _PrintEnter("IsProcessorFeaturePresent(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsProcessorFeaturePresent(a0);
    }
    __finally {
        _PrintExit("IsProcessorFeaturePresent() -> %p\n", rv);
    };
    return rv;
}
#endif // !DETOURS_ARM

BOOL __stdcall Mine_IsRectEmpty(RECT* a0)
{
    _PrintEnter("IsRectEmpty(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsRectEmpty(a0);
    }
    __finally {
        _PrintExit("IsRectEmpty() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsValidCodePage(UINT a0)
{
    _PrintEnter("IsValidCodePage(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsValidCodePage(a0);
    }
    __finally {
        _PrintExit("IsValidCodePage() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsValidLocale(LCID a0,
    DWORD a1)
{
    _PrintEnter("IsValidLocale(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_IsValidLocale(a0, a1);
    }
    __finally {
        _PrintExit("IsValidLocale(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsWindow(HWND a0)
{
    _PrintEnter("IsWindow(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsWindow(a0);
    }
    __finally {
        _PrintExit("IsWindow() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsWindowEnabled(HWND a0)
{
    _PrintEnter("IsWindowEnabled(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsWindowEnabled(a0);
    }
    __finally {
        _PrintExit("IsWindowEnabled() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsWindowUnicode(HWND a0)
{
    _PrintEnter("IsWindowUnicode(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsWindowUnicode(a0);
    }
    __finally {
        _PrintExit("IsWindowUnicode() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsWindowVisible(HWND a0)
{
    _PrintEnter("IsWindowVisible(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsWindowVisible(a0);
    }
    __finally {
        _PrintExit("IsWindowVisible() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_IsZoomed(HWND a0)
{
    _PrintEnter("IsZoomed(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsZoomed(a0);
    }
    __finally {
        _PrintExit("IsZoomed() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_KillTimer(HWND a0,
    UINT_PTR a1)
{
    _PrintEnter("KillTimer(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_KillTimer(a0, a1);
    }
    __finally {
        _PrintExit("KillTimer(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_LPtoDP(HDC a0,
    POINT* a1,
    int a2)
{
    _PrintEnter("LPtoDP(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_LPtoDP(a0, a1, a2);
    }
    __finally {
        _PrintExit("LPtoDP(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_LineDDA(int a0,
    int a1,
    int a2,
    int a3,
    LINEDDAPROC a4,
    LPARAM a5)
{
    _PrintEnter("LineDDA(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_LineDDA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("LineDDA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_LineTo(HDC a0,
    int a1,
    int a2)
{
    _PrintEnter("LineTo(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_LineTo(a0, a1, a2);
    }
    __finally {
        _PrintExit("LineTo(,,) -> %p\n", rv);
    };
    return rv;
}

HACCEL __stdcall Mine_LoadAcceleratorsA(HINSTANCE a0,
    LPCSTR a1)
{
    _PrintEnter("LoadAcceleratorsA(%p,%hs)\n", a0, a1);

    HACCEL rv = 0;
    __try {
        rv = Real_LoadAcceleratorsA(a0, a1);
    }
    __finally {
        _PrintExit("LoadAcceleratorsA(,) -> %p\n", rv);
    };
    return rv;
}

HACCEL __stdcall Mine_LoadAcceleratorsW(HINSTANCE a0,
    LPCWSTR a1)
{
    _PrintEnter("LoadAcceleratorsW(%p,%ls)\n", a0, a1);

    HACCEL rv = 0;
    __try {
        rv = Real_LoadAcceleratorsW(a0, a1);
    }
    __finally {
        _PrintExit("LoadAcceleratorsW(,) -> %p\n", rv);
    };
    return rv;
}

HBITMAP __stdcall Mine_LoadBitmapA(HINSTANCE a0,
    LPCSTR a1)
{
    _PrintEnter("LoadBitmapA(%p,%hs)\n", a0, a1);

    HBITMAP rv = 0;
    __try {
        rv = Real_LoadBitmapA(a0, a1);
    }
    __finally {
        _PrintExit("LoadBitmapA(,) -> %p\n", rv);
    };
    return rv;
}

HBITMAP __stdcall Mine_LoadBitmapW(HINSTANCE a0,
    LPCWSTR a1)
{
    _PrintEnter("LoadBitmapW(%p,%ls)\n", a0, a1);

    HBITMAP rv = 0;
    __try {
        rv = Real_LoadBitmapW(a0, a1);
    }
    __finally {
        _PrintExit("LoadBitmapW(,) -> %p\n", rv);
    };
    return rv;
}

HCURSOR __stdcall Mine_LoadCursorA(HINSTANCE a0,
    LPCSTR a1)
{
    _PrintEnter("LoadCursorA(%p,%hs)\n", a0, a1);

    HCURSOR rv = 0;
    __try {
        rv = Real_LoadCursorA(a0, a1);
    }
    __finally {
        _PrintExit("LoadCursorA(,) -> %p\n", rv);
    };
    return rv;
}

HCURSOR __stdcall Mine_LoadCursorFromFileA(LPCSTR a0)
{
    _PrintEnter("LoadCursorFromFileA(%hs)\n", a0);

    HCURSOR rv = 0;
    __try {
        rv = Real_LoadCursorFromFileA(a0);
    }
    __finally {
        _PrintExit("LoadCursorFromFileA() -> %p\n", rv);
    };
    return rv;
}

HCURSOR __stdcall Mine_LoadCursorFromFileW(LPCWSTR a0)
{
    _PrintEnter("LoadCursorFromFileW(%ls)\n", a0);

    HCURSOR rv = 0;
    __try {
        rv = Real_LoadCursorFromFileW(a0);
    }
    __finally {
        _PrintExit("LoadCursorFromFileW() -> %p\n", rv);
    };
    return rv;
}

HCURSOR __stdcall Mine_LoadCursorW(HINSTANCE a0,
    LPCWSTR a1)
{
    _PrintEnter("LoadCursorW(%p,%ls)\n", a0, a1);

    HCURSOR rv = 0;
    __try {
        rv = Real_LoadCursorW(a0, a1);
    }
    __finally {
        _PrintExit("LoadCursorW(,) -> %p\n", rv);
    };
    return rv;
}

HICON __stdcall Mine_LoadIconA(HINSTANCE a0,
    LPCSTR a1)
{
    _PrintEnter("LoadIconA(%p,%hs)\n", a0, a1);

    HICON rv = 0;
    __try {
        rv = Real_LoadIconA(a0, a1);
    }
    __finally {
        _PrintExit("LoadIconA(,) -> %p\n", rv);
    };
    return rv;
}

HICON __stdcall Mine_LoadIconW(HINSTANCE a0,
    LPCWSTR a1)
{
    _PrintEnter("LoadIconW(%p,%ls)\n", a0, a1);

    HICON rv = 0;
    __try {
        rv = Real_LoadIconW(a0, a1);
    }
    __finally {
        _PrintExit("LoadIconW(,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_LoadImageA(HINSTANCE a0,
    LPCSTR a1,
    UINT a2,
    int a3,
    int a4,
    UINT a5)
{
    _PrintEnter("LoadImageA(%p,%hs,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_LoadImageA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("LoadImageA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_LoadImageW(HINSTANCE a0,
    LPCWSTR a1,
    UINT a2,
    int a3,
    int a4,
    UINT a5)
{
    _PrintEnter("LoadImageW(%p,%ls,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_LoadImageW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("LoadImageW(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HKL __stdcall Mine_LoadKeyboardLayoutA(LPCSTR a0,
    UINT a1)
{
    _PrintEnter("LoadKeyboardLayoutA(%hs,%p)\n", a0, a1);

    HKL rv = 0;
    __try {
        rv = Real_LoadKeyboardLayoutA(a0, a1);
    }
    __finally {
        _PrintExit("LoadKeyboardLayoutA(,) -> %p\n", rv);
    };
    return rv;
}

HKL __stdcall Mine_LoadKeyboardLayoutW(LPCWSTR a0,
    UINT a1)
{
    _PrintEnter("LoadKeyboardLayoutW(%ls,%p)\n", a0, a1);

    HKL rv = 0;
    __try {
        rv = Real_LoadKeyboardLayoutW(a0, a1);
    }
    __finally {
        _PrintExit("LoadKeyboardLayoutW(,) -> %p\n", rv);
    };
    return rv;
}

HMODULE __stdcall Mine_LoadLibraryA(LPCSTR a0)
{
    _PrintEnter("LoadLibraryA(%hs)\n", a0);

    HMODULE rv = 0;
    __try {
        rv = Real_LoadLibraryA(a0);
    }
    __finally {
        _PrintExit("LoadLibraryA() -> %p\n", rv);
    };
    return rv;
}

HMODULE __stdcall Mine_LoadLibraryExA(LPCSTR a0,
    HANDLE a1,
    DWORD a2)
{
    _PrintEnter("LoadLibraryExA(%hs,%p,%p)\n", a0, a1, a2);

    HMODULE rv = 0;
    __try {
        rv = Real_LoadLibraryExA(a0, a1, a2);
    }
    __finally {
        _PrintExit("LoadLibraryExA(,,) -> %p\n", rv);
    };
    return rv;
}

HMODULE __stdcall Mine_LoadLibraryExW(LPCWSTR a0,
    HANDLE a1,
    DWORD a2)
{
    _PrintEnter("LoadLibraryExW(%ls,%p,%p)\n", a0, a1, a2);

    HMODULE rv = 0;
    __try {
        rv = Real_LoadLibraryExW(a0, a1, a2);
    }
    __finally {
        _PrintExit("LoadLibraryExW(,,) -> %p\n", rv);
    };
    return rv;
}

HMODULE __stdcall Mine_LoadLibraryW(LPCWSTR a0)
{
    _PrintEnter("LoadLibraryW(%ls)\n", a0);

    HMODULE rv = 0;
    __try {
        rv = Real_LoadLibraryW(a0);
    }
    __finally {
        _PrintExit("LoadLibraryW() -> %p\n", rv);
    };
    return rv;
}

HMENU __stdcall Mine_LoadMenuA(HINSTANCE a0,
    LPCSTR a1)
{
    _PrintEnter("LoadMenuA(%p,%hs)\n", a0, a1);

    HMENU rv = 0;
    __try {
        rv = Real_LoadMenuA(a0, a1);
    }
    __finally {
        _PrintExit("LoadMenuA(,) -> %p\n", rv);
    };
    return rv;
}

HMENU __stdcall Mine_LoadMenuIndirectA(MENUTEMPLATEA* a0)
{
    _PrintEnter("LoadMenuIndirectA(%p)\n", a0);

    HMENU rv = 0;
    __try {
        rv = Real_LoadMenuIndirectA(a0);
    }
    __finally {
        _PrintExit("LoadMenuIndirectA() -> %p\n", rv);
    };
    return rv;
}

HMENU __stdcall Mine_LoadMenuIndirectW(MENUTEMPLATEW* a0)
{
    _PrintEnter("LoadMenuIndirectW(%p)\n", a0);

    HMENU rv = 0;
    __try {
        rv = Real_LoadMenuIndirectW(a0);
    }
    __finally {
        _PrintExit("LoadMenuIndirectW() -> %p\n", rv);
    };
    return rv;
}

HMENU __stdcall Mine_LoadMenuW(HINSTANCE a0,
    LPCWSTR a1)
{
    _PrintEnter("LoadMenuW(%p,%ls)\n", a0, a1);

    HMENU rv = 0;
    __try {
        rv = Real_LoadMenuW(a0, a1);
    }
    __finally {
        _PrintExit("LoadMenuW(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_LoadModule(LPCSTR a0,
    LPVOID a1)
{
    _PrintEnter("LoadModule(%hs,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_LoadModule(a0, a1);
    }
    __finally {
        _PrintExit("LoadModule(,) -> %p\n", rv);
    };
    return rv;
}

HGLOBAL __stdcall Mine_LoadResource(HMODULE a0,
    HRSRC a1)
{
    _PrintEnter("LoadResource(%p,%p)\n", a0, a1);

    HGLOBAL rv = 0;
    __try {
        rv = Real_LoadResource(a0, a1);
    }
    __finally {
        _PrintExit("LoadResource(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_LoadStringA(HINSTANCE a0,
    UINT a1,
    LPSTR a2,
    int a3)
{
    _PrintEnter("LoadStringA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_LoadStringA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("LoadStringA(,,%hs,) -> %p\n", a2, rv);
    };
    return rv;
}

int __stdcall Mine_LoadStringW(HINSTANCE a0,
    UINT a1,
    LPWSTR a2,
    int a3)
{
    _PrintEnter("LoadStringW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_LoadStringW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("LoadStringW(,,%ls,) -> %p\n", a2, rv);
    };
    return rv;
}

HLOCAL __stdcall Mine_LocalAlloc(UINT a0,
    SIZE_T a1)
{
    _PrintEnter("LocalAlloc(%p,%p)\n", a0, a1);

    HLOCAL rv = 0;
    __try {
        rv = Real_LocalAlloc(a0, a1);
    }
    __finally {
        _PrintExit("LocalAlloc(,) -> %p\n", rv);
    };
    return rv;
}

SIZE_T __stdcall Mine_LocalCompact(UINT a0)
{
    _PrintEnter("LocalCompact(%p)\n", a0);

    SIZE_T rv = 0;
    __try {
        rv = Real_LocalCompact(a0);
    }
    __finally {
        _PrintExit("LocalCompact() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_LocalFileTimeToFileTime(FILETIME* a0,
    LPFILETIME a1)
{
    _PrintEnter("LocalFileTimeToFileTime(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_LocalFileTimeToFileTime(a0, a1);
    }
    __finally {
        _PrintExit("LocalFileTimeToFileTime(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_LocalFlags(HLOCAL a0)
{
    _PrintEnter("LocalFlags(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_LocalFlags(a0);
    }
    __finally {
        _PrintExit("LocalFlags() -> %p\n", rv);
    };
    return rv;
}

HLOCAL __stdcall Mine_LocalFree(HLOCAL a0)
{
    _PrintEnter("LocalFree(%p)\n", a0);

    HLOCAL rv = 0;
    __try {
        rv = Real_LocalFree(a0);
    }
    __finally {
        _PrintExit("LocalFree() -> %p\n", rv);
    };
    return rv;
}

HLOCAL __stdcall Mine_LocalHandle(LPCVOID a0)
{
    _PrintEnter("LocalHandle(%p)\n", a0);

    HLOCAL rv = 0;
    __try {
        rv = Real_LocalHandle(a0);
    }
    __finally {
        _PrintExit("LocalHandle() -> %p\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_LocalLock(HLOCAL a0)
{
    _PrintEnter("LocalLock(%p)\n", a0);

    LPVOID rv = 0;
    __try {
        rv = Real_LocalLock(a0);
    }
    __finally {
        _PrintExit("LocalLock() -> %p\n", rv);
    };
    return rv;
}

HLOCAL __stdcall Mine_LocalReAlloc(HLOCAL a0,
    SIZE_T a1,
    UINT a2)
{
    _PrintEnter("LocalReAlloc(%p,%p,%p)\n", a0, a1, a2);

    HLOCAL rv = 0;
    __try {
        rv = Real_LocalReAlloc(a0, a1, a2);
    }
    __finally {
        _PrintExit("LocalReAlloc(,,) -> %p\n", rv);
    };
    return rv;
}

SIZE_T __stdcall Mine_LocalShrink(HLOCAL a0,
    UINT a1)
{
    _PrintEnter("LocalShrink(%p,%p)\n", a0, a1);

    SIZE_T rv = 0;
    __try {
        rv = Real_LocalShrink(a0, a1);
    }
    __finally {
        _PrintExit("LocalShrink(,) -> %p\n", rv);
    };
    return rv;
}

SIZE_T __stdcall Mine_LocalSize(HLOCAL a0)
{
    _PrintEnter("LocalSize(%p)\n", a0);

    SIZE_T rv = 0;
    __try {
        rv = Real_LocalSize(a0);
    }
    __finally {
        _PrintExit("LocalSize() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_LocalUnlock(HLOCAL a0)
{
    _PrintEnter("LocalUnlock(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_LocalUnlock(a0);
    }
    __finally {
        _PrintExit("LocalUnlock() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_LockFile(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4)
{
    _PrintEnter("LockFile(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_LockFile(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("LockFile(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_LockFileEx(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    LPOVERLAPPED a5)
{
    _PrintEnter("LockFileEx(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_LockFileEx(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("LockFileEx(,,,,,) -> %p\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_LockResource(HGLOBAL a0)
{
    _PrintEnter("LockResource(%p)\n", a0);

    LPVOID rv = 0;
    __try {
        rv = Real_LockResource(a0);
    }
    __finally {
        _PrintExit("LockResource() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_LockWindowUpdate(HWND a0)
{
    _PrintEnter("LockWindowUpdate(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_LockWindowUpdate(a0);
    }
    __finally {
        _PrintExit("LockWindowUpdate() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_LookupIconIdFromDirectory(PBYTE a0,
    BOOL a1)
{
    _PrintEnter("LookupIconIdFromDirectory(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_LookupIconIdFromDirectory(a0, a1);
    }
    __finally {
        _PrintExit("LookupIconIdFromDirectory(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_LookupIconIdFromDirectoryEx(PBYTE a0,
    BOOL a1,
    int a2,
    int a3,
    UINT a4)
{
    _PrintEnter("LookupIconIdFromDirectoryEx(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_LookupIconIdFromDirectoryEx(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("LookupIconIdFromDirectoryEx(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_MapDialogRect(HWND a0,
    LPRECT a1)
{
    _PrintEnter("MapDialogRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_MapDialogRect(a0, a1);
    }
    __finally {
        _PrintExit("MapDialogRect(,) -> %p\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_MapViewOfFile(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    SIZE_T a4)
{
    _PrintEnter("MapViewOfFile(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LPVOID rv = 0;
    __try {
        rv = Real_MapViewOfFile(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("MapViewOfFile(,,,,) -> %p\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_MapViewOfFileEx(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    SIZE_T a4,
    LPVOID a5)
{
    _PrintEnter("MapViewOfFileEx(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    LPVOID rv = 0;
    __try {
        rv = Real_MapViewOfFileEx(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("MapViewOfFileEx(,,,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_MapVirtualKeyA(UINT a0,
    UINT a1)
{
    _PrintEnter("MapVirtualKeyA(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_MapVirtualKeyA(a0, a1);
    }
    __finally {
        _PrintExit("MapVirtualKeyA(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_MapVirtualKeyExA(UINT a0,
    UINT a1,
    HKL a2)
{
    _PrintEnter("MapVirtualKeyExA(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_MapVirtualKeyExA(a0, a1, a2);
    }
    __finally {
        _PrintExit("MapVirtualKeyExA(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_MapVirtualKeyExW(UINT a0,
    UINT a1,
    HKL a2)
{
    _PrintEnter("MapVirtualKeyExW(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_MapVirtualKeyExW(a0, a1, a2);
    }
    __finally {
        _PrintExit("MapVirtualKeyExW(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_MapVirtualKeyW(UINT a0,
    UINT a1)
{
    _PrintEnter("MapVirtualKeyW(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_MapVirtualKeyW(a0, a1);
    }
    __finally {
        _PrintExit("MapVirtualKeyW(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_MapWindowPoints(HWND a0,
    HWND a1,
    POINT* a2,
    UINT a3)
{
    _PrintEnter("MapWindowPoints(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_MapWindowPoints(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("MapWindowPoints(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_MaskBlt(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    HDC a5,
    int a6,
    int a7,
    HBITMAP a8,
    int a9,
    int a10,
    DWORD a11)
{
    _PrintEnter("MaskBlt(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    BOOL rv = 0;
    __try {
        rv = Real_MaskBlt(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    __finally {
        _PrintExit("MaskBlt(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_MenuItemFromPoint(HWND a0,
    HMENU a1,
    POINT a2)
{
    _PrintEnter("MenuItemFromPoint(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_MenuItemFromPoint(a0, a1, a2);
    }
    __finally {
        _PrintExit("MenuItemFromPoint(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_MessageBeep(UINT a0)
{
    _PrintEnter("MessageBeep(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_MessageBeep(a0);
    }
    __finally {
        _PrintExit("MessageBeep() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_MessageBoxA(HWND a0,
    LPCSTR a1,
    LPCSTR a2,
    UINT a3)
{
    _PrintEnter("MessageBoxA(%p,%hs,%hs,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_MessageBoxA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("MessageBoxA(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_MessageBoxExA(HWND a0,
    LPCSTR a1,
    LPCSTR a2,
    UINT a3,
    WORD a4)
{
    _PrintEnter("MessageBoxExA(%p,%hs,%hs,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_MessageBoxExA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("MessageBoxExA(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_MessageBoxExW(HWND a0,
    LPCWSTR a1,
    LPCWSTR a2,
    UINT a3,
    WORD a4)
{
    _PrintEnter("MessageBoxExW(%p,%ls,%ls,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_MessageBoxExW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("MessageBoxExW(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_MessageBoxIndirectA(MSGBOXPARAMSA* a0)
{
    _PrintEnter("MessageBoxIndirectA(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_MessageBoxIndirectA(a0);
    }
    __finally {
        _PrintExit("MessageBoxIndirectA() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_MessageBoxIndirectW(MSGBOXPARAMSW* a0)
{
    _PrintEnter("MessageBoxIndirectW(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_MessageBoxIndirectW(a0);
    }
    __finally {
        _PrintExit("MessageBoxIndirectW() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_MessageBoxW(HWND a0,
    LPCWSTR a1,
    LPCWSTR a2,
    UINT a3)
{
    _PrintEnter("MessageBoxW(%p,%ls,%ls,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_MessageBoxW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("MessageBoxW(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_MkParseDisplayName(IBindCtx* a0,
    LPCOLESTR a1,
    ULONG* a2,
    IMoniker** a3)
{
    _PrintEnter("MkParseDisplayName(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_MkParseDisplayName(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("MkParseDisplayName(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ModifyMenuA(HMENU a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    LPCSTR a4)
{
    _PrintEnter("ModifyMenuA(%p,%p,%p,%p,%hs)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ModifyMenuA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ModifyMenuA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ModifyMenuW(HMENU a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    LPCWSTR a4)
{
    _PrintEnter("ModifyMenuW(%p,%p,%p,%p,%ls)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ModifyMenuW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ModifyMenuW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ModifyWorldTransform(HDC a0,
    XFORM* a1,
    DWORD a2)
{
    _PrintEnter("ModifyWorldTransform(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_ModifyWorldTransform(a0, a1, a2);
    }
    __finally {
        _PrintExit("ModifyWorldTransform(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_MonikerCommonPrefixWith(IMoniker* a0,
    IMoniker* a1,
    IMoniker** a2)
{
    _PrintEnter("MonikerCommonPrefixWith(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_MonikerCommonPrefixWith(a0, a1, a2);
    }
    __finally {
        _PrintExit("MonikerCommonPrefixWith(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_MonikerRelativePathTo(IMoniker* a0,
    IMoniker* a1,
    IMoniker** a2,
    BOOL a3)
{
    _PrintEnter("MonikerRelativePathTo(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_MonikerRelativePathTo(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("MonikerRelativePathTo(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_MoveFileA(LPCSTR a0,
    LPCSTR a1)
{
    _PrintEnter("MoveFileA(%hs,%hs)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_MoveFileA(a0, a1);
    }
    __finally {
        _PrintExit("MoveFileA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_MoveFileExA(LPCSTR a0,
    LPCSTR a1,
    DWORD a2)
{
    _PrintEnter("MoveFileExA(%hs,%hs,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_MoveFileExA(a0, a1, a2);
    }
    __finally {
        _PrintExit("MoveFileExA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_MoveFileExW(LPCWSTR a0,
    LPCWSTR a1,
    DWORD a2)
{
    _PrintEnter("MoveFileExW(%ls,%ls,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_MoveFileExW(a0, a1, a2);
    }
    __finally {
        _PrintExit("MoveFileExW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_MoveFileW(LPCWSTR a0,
    LPCWSTR a1)
{
    _PrintEnter("MoveFileW(%ls,%ls)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_MoveFileW(a0, a1);
    }
    __finally {
        _PrintExit("MoveFileW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_MoveToEx(HDC a0,
    int a1,
    int a2,
    POINT* a3)
{
    _PrintEnter("MoveToEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_MoveToEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("MoveToEx(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_MoveWindow(HWND a0,
    int a1,
    int a2,
    int a3,
    int a4,
    BOOL a5)
{
    _PrintEnter("MoveWindow(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_MoveWindow(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("MoveWindow(,,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_MsgWaitForMultipleObjects(DWORD a0,
    void** a1,
    BOOL a2,
    DWORD a3,
    DWORD a4)
{
    _PrintEnter("MsgWaitForMultipleObjects(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_MsgWaitForMultipleObjects(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("MsgWaitForMultipleObjects(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_MsgWaitForMultipleObjectsEx(DWORD a0,
    void** a1,
    DWORD a2,
    DWORD a3,
    DWORD a4)
{
    _PrintEnter("MsgWaitForMultipleObjectsEx(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_MsgWaitForMultipleObjectsEx(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("MsgWaitForMultipleObjectsEx(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_MulDiv(int a0,
    int a1,
    int a2)
{
    _PrintEnter("MulDiv(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_MulDiv(a0, a1, a2);
    }
    __finally {
        _PrintExit("MulDiv(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_OemKeyScan(WORD a0)
{
    _PrintEnter("OemKeyScan(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_OemKeyScan(a0);
    }
    __finally {
        _PrintExit("OemKeyScan() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_OemToCharA(LPCSTR a0,
    LPSTR a1)
{
    _PrintEnter("OemToCharA(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_OemToCharA(a0, a1);
    }
    __finally {
        _PrintExit("OemToCharA(,%hs) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_OemToCharBuffA(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("OemToCharBuffA(%hs,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_OemToCharBuffA(a0, a1, a2);
    }
    __finally {
        _PrintExit("OemToCharBuffA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_OemToCharBuffW(LPCSTR a0,
    LPWSTR a1,
    DWORD a2)
{
    _PrintEnter("OemToCharBuffW(%hs,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_OemToCharBuffW(a0, a1, a2);
    }
    __finally {
        _PrintExit("OemToCharBuffW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_OemToCharW(LPCSTR a0,
    LPWSTR a1)
{
    _PrintEnter("OemToCharW(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_OemToCharW(a0, a1);
    }
    __finally {
        _PrintExit("OemToCharW(,%ls) -> %p\n", a1, rv);
    };
    return rv;
}

int __stdcall Mine_OffsetClipRgn(HDC a0,
    int a1,
    int a2)
{
    _PrintEnter("OffsetClipRgn(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_OffsetClipRgn(a0, a1, a2);
    }
    __finally {
        _PrintExit("OffsetClipRgn(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_OffsetRect(LPRECT a0,
    int a1,
    int a2)
{
    _PrintEnter("OffsetRect(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_OffsetRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("OffsetRect(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_OffsetRgn(HRGN a0,
    int a1,
    int a2)
{
    _PrintEnter("OffsetRgn(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_OffsetRgn(a0, a1, a2);
    }
    __finally {
        _PrintExit("OffsetRgn(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_OffsetViewportOrgEx(HDC a0,
    int a1,
    int a2,
    POINT* a3)
{
    _PrintEnter("OffsetViewportOrgEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_OffsetViewportOrgEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("OffsetViewportOrgEx(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_OffsetWindowOrgEx(HDC a0,
    int a1,
    int a2,
    POINT* a3)
{
    _PrintEnter("OffsetWindowOrgEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_OffsetWindowOrgEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("OffsetWindowOrgEx(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_OleBuildVersion(void)
{
    _PrintEnter("OleBuildVersion()\n");

    DWORD rv = 0;
    __try {
        rv = Real_OleBuildVersion();
    }
    __finally {
        _PrintExit("OleBuildVersion() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleConvertIStorageToOLESTREAM(LPSTORAGE a0,
    LPOLESTREAM a1)
{
    _PrintEnter("OleConvertIStorageToOLESTREAM(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_OleConvertIStorageToOLESTREAM(a0, a1);
    }
    __finally {
        _PrintExit("OleConvertIStorageToOLESTREAM(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleConvertIStorageToOLESTREAMEx(LPSTORAGE a0,
    CLIPFORMAT a1,
    LONG a2,
    LONG a3,
    DWORD a4,
    LPSTGMEDIUM a5,
    LPOLESTREAM a6)
{
    _PrintEnter("OleConvertIStorageToOLESTREAMEx(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_OleConvertIStorageToOLESTREAMEx(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("OleConvertIStorageToOLESTREAMEx(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleConvertOLESTREAMToIStorage(LPOLESTREAM a0,
    LPSTORAGE a1,
    DVTARGETDEVICE* a2)
{
    _PrintEnter("OleConvertOLESTREAMToIStorage(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_OleConvertOLESTREAMToIStorage(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleConvertOLESTREAMToIStorage(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleConvertOLESTREAMToIStorageEx(LPOLESTREAM a0,
    LPSTORAGE a1,
    CLIPFORMAT* a2,
    LONG* a3,
    LONG* a4,
    DWORD* a5,
    LPSTGMEDIUM a6)
{
    _PrintEnter("OleConvertOLESTREAMToIStorageEx(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_OleConvertOLESTREAMToIStorageEx(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("OleConvertOLESTREAMToIStorageEx(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreate(CONST IID& a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
{
    _PrintEnter("OleCreate(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreate(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("OleCreate(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateDefaultHandler(CONST IID& a0,
    LPUNKNOWN a1,
    CONST IID& a2,
    LPVOID* a3)
{
    _PrintEnter("OleCreateDefaultHandler(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateDefaultHandler(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("OleCreateDefaultHandler(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateEmbeddingHelper(CONST IID& a0,
    LPUNKNOWN a1,
    DWORD a2,
    LPCLASSFACTORY a3,
    CONST IID& a4,
    LPVOID* a5)
{
    _PrintEnter("OleCreateEmbeddingHelper(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateEmbeddingHelper(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("OleCreateEmbeddingHelper(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateEx(CONST IID& a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
{
    _PrintEnter("OleCreateEx(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateEx(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    __finally {
        _PrintExit("OleCreateEx(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateFromData(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
{
    _PrintEnter("OleCreateFromData(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateFromData(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("OleCreateFromData(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateFromDataEx(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
{
    _PrintEnter("OleCreateFromDataEx(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateFromDataEx(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    __finally {
        _PrintExit("OleCreateFromDataEx(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateFromFile(CONST IID& a0,
    LPCOLESTR a1,
    CONST IID& a2,
    DWORD a3,
    LPFORMATETC a4,
    LPOLECLIENTSITE a5,
    LPSTORAGE a6,
    LPVOID* a7)
{
    _PrintEnter("OleCreateFromFile(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateFromFile(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("OleCreateFromFile(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateFromFileEx(CONST IID& a0,
    LPCOLESTR a1,
    CONST IID& a2,
    DWORD a3,
    DWORD a4,
    ULONG a5,
    DWORD* a6,
    LPFORMATETC a7,
    IAdviseSink* a8,
    DWORD* a9,
    LPOLECLIENTSITE a10,
    LPSTORAGE a11,
    LPVOID* a12)
{
    _PrintEnter("OleCreateFromFileEx(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateFromFileEx(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
    }
    __finally {
        _PrintExit("OleCreateFromFileEx(,,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateLink(IMoniker* a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
{
    _PrintEnter("OleCreateLink(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateLink(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("OleCreateLink(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateLinkEx(IMoniker* a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
{
    _PrintEnter("OleCreateLinkEx(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateLinkEx(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    __finally {
        _PrintExit("OleCreateLinkEx(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateLinkFromData(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
{
    _PrintEnter("OleCreateLinkFromData(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateLinkFromData(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("OleCreateLinkFromData(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateLinkFromDataEx(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
{
    _PrintEnter("OleCreateLinkFromDataEx(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateLinkFromDataEx(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    __finally {
        _PrintExit("OleCreateLinkFromDataEx(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateLinkToFile(LPCOLESTR a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
{
    _PrintEnter("OleCreateLinkToFile(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateLinkToFile(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("OleCreateLinkToFile(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateLinkToFileEx(LPCOLESTR a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    ULONG a4,
    DWORD* a5,
    LPFORMATETC a6,
    IAdviseSink* a7,
    DWORD* a8,
    LPOLECLIENTSITE a9,
    LPSTORAGE a10,
    LPVOID* a11)
{
    _PrintEnter("OleCreateLinkToFileEx(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateLinkToFileEx(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    __finally {
        _PrintExit("OleCreateLinkToFileEx(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HOLEMENU __stdcall Mine_OleCreateMenuDescriptor(HMENU a0,
    LPOLEMENUGROUPWIDTHS a1)
{
    _PrintEnter("OleCreateMenuDescriptor(%p,%p)\n", a0, a1);

    HOLEMENU rv = 0;
    __try {
        rv = Real_OleCreateMenuDescriptor(a0, a1);
    }
    __finally {
        _PrintExit("OleCreateMenuDescriptor(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleCreateStaticFromData(IDataObject* a0,
    CONST IID& a1,
    DWORD a2,
    LPFORMATETC a3,
    LPOLECLIENTSITE a4,
    LPSTORAGE a5,
    LPVOID* a6)
{
    _PrintEnter("OleCreateStaticFromData(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HRESULT rv = 0;
    __try {
        rv = Real_OleCreateStaticFromData(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("OleCreateStaticFromData(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleDestroyMenuDescriptor(HOLEMENU a0)
{
    _PrintEnter("OleDestroyMenuDescriptor(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_OleDestroyMenuDescriptor(a0);
    }
    __finally {
        _PrintExit("OleDestroyMenuDescriptor() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleDoAutoConvert(LPSTORAGE a0,
    LPGUID a1)
{
    _PrintEnter("OleDoAutoConvert(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_OleDoAutoConvert(a0, a1);
    }
    __finally {
        _PrintExit("OleDoAutoConvert(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleDraw(LPUNKNOWN a0,
    DWORD a1,
    HDC a2,
    LPCRECT a3)
{
    _PrintEnter("OleDraw(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_OleDraw(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("OleDraw(,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OleDuplicateData(HANDLE a0,
    CLIPFORMAT a1,
    UINT a2)
{
    _PrintEnter("OleDuplicateData(%p,%p,%p)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OleDuplicateData(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleDuplicateData(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleFlushClipboard(void)
{
    _PrintEnter("OleFlushClipboard()\n");

    HRESULT rv = 0;
    __try {
        rv = Real_OleFlushClipboard();
    }
    __finally {
        _PrintExit("OleFlushClipboard() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleGetAutoConvert(CONST IID& a0,
    LPGUID a1)
{
    _PrintEnter("OleGetAutoConvert(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_OleGetAutoConvert(a0, a1);
    }
    __finally {
        _PrintExit("OleGetAutoConvert(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleGetClipboard(IDataObject** a0)
{
    _PrintEnter("OleGetClipboard(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_OleGetClipboard(a0);
    }
    __finally {
        _PrintExit("OleGetClipboard() -> %p\n", rv);
    };
    return rv;
}

HGLOBAL __stdcall Mine_OleGetIconOfClass(CONST IID& a0,
    LPOLESTR a1,
    BOOL a2)
{
    _PrintEnter("OleGetIconOfClass(%p,%p,%p)\n", a0, a1, a2);

    HGLOBAL rv = 0;
    __try {
        rv = Real_OleGetIconOfClass(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleGetIconOfClass(,,) -> %p\n", rv);
    };
    return rv;
}

HGLOBAL __stdcall Mine_OleGetIconOfFile(LPOLESTR a0,
    BOOL a1)
{
    _PrintEnter("OleGetIconOfFile(%p,%p)\n", a0, a1);

    HGLOBAL rv = 0;
    __try {
        rv = Real_OleGetIconOfFile(a0, a1);
    }
    __finally {
        _PrintExit("OleGetIconOfFile(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleInitialize(LPVOID a0)
{
    _PrintEnter("OleInitialize(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_OleInitialize(a0);
    }
    __finally {
        _PrintExit("OleInitialize() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleIsCurrentClipboard(IDataObject* a0)
{
    _PrintEnter("OleIsCurrentClipboard(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_OleIsCurrentClipboard(a0);
    }
    __finally {
        _PrintExit("OleIsCurrentClipboard() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_OleIsRunning(IOleObject* a0)
{
    _PrintEnter("OleIsRunning(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_OleIsRunning(a0);
    }
    __finally {
        _PrintExit("OleIsRunning() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleLoad(LPSTORAGE a0,
    CONST IID& a1,
    LPOLECLIENTSITE a2,
    LPVOID* a3)
{
    _PrintEnter("OleLoad(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_OleLoad(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("OleLoad(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleLoadFromStream(LPSTREAM a0,
    CONST IID& a1,
    LPVOID* a2)
{
    _PrintEnter("OleLoadFromStream(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_OleLoadFromStream(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleLoadFromStream(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleLockRunning(LPUNKNOWN a0,
    BOOL a1,
    BOOL a2)
{
    _PrintEnter("OleLockRunning(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_OleLockRunning(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleLockRunning(,,) -> %p\n", rv);
    };
    return rv;
}

HGLOBAL __stdcall Mine_OleMetafilePictFromIconAndLabel(HICON a0,
    LPOLESTR a1,
    LPOLESTR a2,
    UINT a3)
{
    _PrintEnter("OleMetafilePictFromIconAndLabel(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HGLOBAL rv = 0;
    __try {
        rv = Real_OleMetafilePictFromIconAndLabel(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("OleMetafilePictFromIconAndLabel(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleNoteObjectVisible(LPUNKNOWN a0,
    BOOL a1)
{
    _PrintEnter("OleNoteObjectVisible(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_OleNoteObjectVisible(a0, a1);
    }
    __finally {
        _PrintExit("OleNoteObjectVisible(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleQueryCreateFromData(IDataObject* a0)
{
    _PrintEnter("OleQueryCreateFromData(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_OleQueryCreateFromData(a0);
    }
    __finally {
        _PrintExit("OleQueryCreateFromData() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleQueryLinkFromData(IDataObject* a0)
{
    _PrintEnter("OleQueryLinkFromData(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_OleQueryLinkFromData(a0);
    }
    __finally {
        _PrintExit("OleQueryLinkFromData() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleRegEnumFormatEtc(CONST IID& a0,
    DWORD a1,
    IEnumFORMATETC** a2)
{
    _PrintEnter("OleRegEnumFormatEtc(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_OleRegEnumFormatEtc(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleRegEnumFormatEtc(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleRegEnumVerbs(CONST IID& a0,
    IEnumOLEVERB** a1)
{
    _PrintEnter("OleRegEnumVerbs(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_OleRegEnumVerbs(a0, a1);
    }
    __finally {
        _PrintExit("OleRegEnumVerbs(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleRegGetMiscStatus(CONST IID& a0,
    DWORD a1,
    DWORD* a2)
{
    _PrintEnter("OleRegGetMiscStatus(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_OleRegGetMiscStatus(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleRegGetMiscStatus(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleRegGetUserType(CONST IID& a0,
    DWORD a1,
    LPOLESTR* a2)
{
    _PrintEnter("OleRegGetUserType(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_OleRegGetUserType(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleRegGetUserType(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleRun(LPUNKNOWN a0)
{
    _PrintEnter("OleRun(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_OleRun(a0);
    }
    __finally {
        _PrintExit("OleRun() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleSave(LPPERSISTSTORAGE a0,
    LPSTORAGE a1,
    BOOL a2)
{
    _PrintEnter("OleSave(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_OleSave(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleSave(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleSaveToStream(IPersistStream* a0,
    LPSTREAM a1)
{
    _PrintEnter("OleSaveToStream(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_OleSaveToStream(a0, a1);
    }
    __finally {
        _PrintExit("OleSaveToStream(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleSetAutoConvert(CONST IID& a0,
    CONST IID& a1)
{
    _PrintEnter("OleSetAutoConvert(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_OleSetAutoConvert(a0, a1);
    }
    __finally {
        _PrintExit("OleSetAutoConvert(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleSetClipboard(IDataObject* a0)
{
    _PrintEnter("OleSetClipboard(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_OleSetClipboard(a0);
    }
    __finally {
        _PrintExit("OleSetClipboard() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleSetContainedObject(LPUNKNOWN a0,
    BOOL a1)
{
    _PrintEnter("OleSetContainedObject(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_OleSetContainedObject(a0, a1);
    }
    __finally {
        _PrintExit("OleSetContainedObject(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleSetMenuDescriptor(HOLEMENU a0,
    HWND a1,
    HWND a2,
    LPOLEINPLACEFRAME a3,
    LPOLEINPLACEACTIVEOBJECT a4)
{
    _PrintEnter("OleSetMenuDescriptor(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HRESULT rv = 0;
    __try {
        rv = Real_OleSetMenuDescriptor(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("OleSetMenuDescriptor(,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_OleTranslateAccelerator(LPOLEINPLACEFRAME a0,
    LPOLEINPLACEFRAMEINFO a1,
    LPMSG a2)
{
    _PrintEnter("OleTranslateAccelerator(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_OleTranslateAccelerator(a0, a1, a2);
    }
    __finally {
        _PrintExit("OleTranslateAccelerator(,,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_OleUninitialize(void)
{
    _PrintEnter("OleUninitialize()\n");

    __try {
        Real_OleUninitialize();
    }
    __finally {
        _PrintExit("OleUninitialize() ->\n");
    };
}

BOOL __stdcall Mine_OpenClipboard(HWND a0)
{
    _PrintEnter("OpenClipboard(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_OpenClipboard(a0);
    }
    __finally {
        _PrintExit("OpenClipboard() -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HDESK __stdcall Mine_OpenDesktopA(LPSTR a0,
    DWORD a1,
    BOOL a2,
    ACCESS_MASK a3)
#else
HDESK __stdcall Mine_OpenDesktopA(LPCSTR a0,
    DWORD a1,
    BOOL a2,
    ACCESS_MASK a3)
#endif
{
    _PrintEnter("OpenDesktopA(%hs,%p,%p,%p)\n", a0, a1, a2, a3);

    HDESK rv = 0;
    __try {
        rv = Real_OpenDesktopA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("OpenDesktopA(,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HDESK __stdcall Mine_OpenDesktopW(LPWSTR a0,
    DWORD a1,
    BOOL a2,
    ACCESS_MASK a3)
#else
HDESK __stdcall Mine_OpenDesktopW(LPCWSTR a0,
    DWORD a1,
    BOOL a2,
    ACCESS_MASK a3)
#endif
{
    _PrintEnter("OpenDesktopW(%ls,%p,%p,%p)\n", a0, a1, a2, a3);

    HDESK rv = 0;
    __try {
        rv = Real_OpenDesktopW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("OpenDesktopW(,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenEventA(DWORD a0,
    BOOL a1,
    LPCSTR a2)
{
    _PrintEnter("OpenEventA(%p,%p,%hs)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenEventA(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenEventA(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenEventW(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
{
    _PrintEnter("OpenEventW(%p,%p,%ls)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenEventW(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenEventW(,,) -> %p\n", rv);
    };
    return rv;
}

HFILE __stdcall Mine_OpenFile(LPCSTR a0,
    LPOFSTRUCT a1,
    UINT a2)
{
    _PrintEnter("OpenFile(%hs,%p,%p)\n", a0, a1, a2);

    HFILE rv = 0;
    __try {
        rv = Real_OpenFile(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenFile(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenFileMappingA(DWORD a0,
    BOOL a1,
    LPCSTR a2)
{
    _PrintEnter("OpenFileMappingA(%p,%p,%hs)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenFileMappingA(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenFileMappingA(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenFileMappingW(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
{
    _PrintEnter("OpenFileMappingW(%p,%p,%ls)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenFileMappingW(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenFileMappingW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_OpenIcon(HWND a0)
{
    _PrintEnter("OpenIcon(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_OpenIcon(a0);
    }
    __finally {
        _PrintExit("OpenIcon() -> %p\n", rv);
    };
    return rv;
}

HDESK __stdcall Mine_OpenInputDesktop(DWORD a0,
    BOOL a1,
    ACCESS_MASK a2)
{
    _PrintEnter("OpenInputDesktop(%p,%p,%p)\n", a0, a1, a2);

    HDESK rv = 0;
    __try {
        rv = Real_OpenInputDesktop(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenInputDesktop(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenMutexA(DWORD a0,
    BOOL a1,
    LPCSTR a2)
{
    _PrintEnter("OpenMutexA(%p,%p,%hs)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenMutexA(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenMutexA(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenMutexW(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
{
    _PrintEnter("OpenMutexW(%p,%p,%ls)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenMutexW(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenMutexW(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenProcess(DWORD a0,
    BOOL a1,
    DWORD pid)
{
    _PrintEnter("OpenProcess(%p,%p,pid=%d)\n", a0, a1, pid);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenProcess(a0, a1, pid);
    }
    __finally {
        _PrintExit("OpenProcess(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_OpenProcessToken(__in   HANDLE ProcessHandle,
    __in   DWORD DesiredAccess,
    __out  PHANDLE TokenHandle
)
{
    _PrintEnter("OpenProcessToken(%p,%p,%p)\n",
        ProcessHandle,
        DesiredAccess,
        TokenHandle);

    BOOL rv = 0;
    __try {
        rv = Real_OpenProcessToken(ProcessHandle,
            DesiredAccess,
            TokenHandle);

    }
    __finally {
        _PrintExit("OpenProcessToken(,,%p) -> %p\n",
            TokenHandle != NULL ? *TokenHandle : 0,
            rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenSemaphoreA(DWORD a0,
    BOOL a1,
    LPCSTR a2)
{
    _PrintEnter("OpenSemaphoreA(%p,%p,%hs)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenSemaphoreA(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenSemaphoreA(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenSemaphoreW(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
{
    _PrintEnter("OpenSemaphoreW(%p,%p,%ls)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenSemaphoreW(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenSemaphoreW(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenWaitableTimerA(DWORD a0,
    BOOL a1,
    LPCSTR a2)
{
    _PrintEnter("OpenWaitableTimerA(%p,%p,%hs)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenWaitableTimerA(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenWaitableTimerA(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_OpenWaitableTimerW(DWORD a0,
    BOOL a1,
    LPCWSTR a2)
{
    _PrintEnter("OpenWaitableTimerW(%p,%p,%ls)\n", a0, a1, a2);

    HANDLE rv = 0;
    __try {
        rv = Real_OpenWaitableTimerW(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenWaitableTimerW(,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HWINSTA __stdcall Mine_OpenWindowStationA(LPSTR a0,
    BOOL a1,
    ACCESS_MASK a2)
#else
HWINSTA __stdcall Mine_OpenWindowStationA(LPCSTR a0,
    BOOL a1,
    ACCESS_MASK a2)
#endif
{
    _PrintEnter("OpenWindowStationA(%hs,%p,%p)\n", a0, a1, a2);

    HWINSTA rv = 0;
    __try {
        rv = Real_OpenWindowStationA(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenWindowStationA(,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HWINSTA __stdcall Mine_OpenWindowStationW(LPWSTR a0,
    BOOL a1,
    ACCESS_MASK a2)
#else
HWINSTA __stdcall Mine_OpenWindowStationW(LPCWSTR a0,
    BOOL a1,
    ACCESS_MASK a2)
#endif
{
    _PrintEnter("OpenWindowStationW(%ls,%p,%p)\n", a0, a1, a2);

    HWINSTA rv = 0;
    __try {
        rv = Real_OpenWindowStationW(a0, a1, a2);
    }
    __finally {
        _PrintExit("OpenWindowStationW(,,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_OutputDebugStringA(LPCSTR a0)
{
    _PrintEnter("OutputDebugStringA(%hs)\n", a0);

    __try {
        Real_OutputDebugStringA(a0);
    }
    __finally {
        _PrintExit("OutputDebugStringA() ->\n");
    };
}

void __stdcall Mine_OutputDebugStringW(LPCWSTR a0)
{
    _PrintEnter("OutputDebugStringW(%ls)\n", a0);

    __try {
        Real_OutputDebugStringW(a0);
    }
    __finally {
        _PrintExit("OutputDebugStringW() ->\n");
    };
}

LPARAM __stdcall Mine_PackDDElParam(UINT a0,
    UINT_PTR a1,
    UINT_PTR a2)
{
    _PrintEnter("PackDDElParam(%p,%p,%p)\n", a0, a1, a2);

    LPARAM rv = 0;
    __try {
        rv = Real_PackDDElParam(a0, a1, a2);
    }
    __finally {
        _PrintExit("PackDDElParam(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PaintDesktop(HDC a0)
{
    _PrintEnter("PaintDesktop(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_PaintDesktop(a0);
    }
    __finally {
        _PrintExit("PaintDesktop() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PaintRgn(HDC a0,
    HRGN a1)
{
    _PrintEnter("PaintRgn(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_PaintRgn(a0, a1);
    }
    __finally {
        _PrintExit("PaintRgn(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PatBlt(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    DWORD a5)
{
    _PrintEnter("PatBlt(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_PatBlt(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("PatBlt(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRGN __stdcall Mine_PathToRegion(HDC a0)
{
    _PrintEnter("PathToRegion(%p)\n", a0);

    HRGN rv = 0;
    __try {
        rv = Real_PathToRegion(a0);
    }
    __finally {
        _PrintExit("PathToRegion() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PeekConsoleInputA(HANDLE a0,
    PINPUT_RECORD a1,
    DWORD a2,
    LPDWORD a3)
{
    _PrintEnter("PeekConsoleInputA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PeekConsoleInputA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PeekConsoleInputA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PeekConsoleInputW(HANDLE a0,
    PINPUT_RECORD a1,
    DWORD a2,
    LPDWORD a3)
{
    _PrintEnter("PeekConsoleInputW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PeekConsoleInputW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PeekConsoleInputW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PeekMessageA(LPMSG a0,
    HWND a1,
    UINT a2,
    UINT a3,
    UINT a4)
{
    _PrintEnter("PeekMessageA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_PeekMessageA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("PeekMessageA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PeekMessageW(LPMSG a0,
    HWND a1,
    UINT a2,
    UINT a3,
    UINT a4)
{
    _PrintEnter("PeekMessageW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_PeekMessageW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("PeekMessageW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PeekNamedPipe(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPDWORD a5)
{
    _PrintEnter("PeekNamedPipe(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_PeekNamedPipe(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("PeekNamedPipe(,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_Pie(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
{
    _PrintEnter("Pie(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    BOOL rv = 0;
    __try {
        rv = Real_Pie(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("Pie(,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PlayEnhMetaFile(HDC a0,
    HENHMETAFILE a1,
    RECT* a2)
{
    _PrintEnter("PlayEnhMetaFile(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_PlayEnhMetaFile(a0, a1, a2);
    }
    __finally {
        _PrintExit("PlayEnhMetaFile(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PlayEnhMetaFileRecord(HDC a0,
    LPHANDLETABLE a1,
    ENHMETARECORD* a2,
    UINT a3)
{
    _PrintEnter("PlayEnhMetaFileRecord(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PlayEnhMetaFileRecord(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PlayEnhMetaFileRecord(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PlayMetaFile(HDC a0,
    HMETAFILE a1)
{
    _PrintEnter("PlayMetaFile(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_PlayMetaFile(a0, a1);
    }
    __finally {
        _PrintExit("PlayMetaFile(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PlayMetaFileRecord(HDC a0,
    LPHANDLETABLE a1,
    LPMETARECORD a2,
    UINT a3)
{
    _PrintEnter("PlayMetaFileRecord(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PlayMetaFileRecord(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PlayMetaFileRecord(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PlgBlt(HDC a0,
    POINT* a1,
    HDC a2,
    int a3,
    int a4,
    int a5,
    int a6,
    HBITMAP a7,
    int a8,
    int a9)
{
    _PrintEnter("PlgBlt(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);

    BOOL rv = 0;
    __try {
        rv = Real_PlgBlt(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
    __finally {
        _PrintExit("PlgBlt(,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PolyBezier(HDC a0,
    POINT* a1,
    DWORD a2)
{
    _PrintEnter("PolyBezier(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_PolyBezier(a0, a1, a2);
    }
    __finally {
        _PrintExit("PolyBezier(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PolyBezierTo(HDC a0,
    POINT* a1,
    DWORD a2)
{
    _PrintEnter("PolyBezierTo(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_PolyBezierTo(a0, a1, a2);
    }
    __finally {
        _PrintExit("PolyBezierTo(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PolyDraw(HDC a0,
    POINT* a1,
    BYTE* a2,
    int a3)
{
    _PrintEnter("PolyDraw(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PolyDraw(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PolyDraw(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PolyPolygon(HDC a0,
    POINT* a1,
    INT* a2,
    int a3)
{
    _PrintEnter("PolyPolygon(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PolyPolygon(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PolyPolygon(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PolyPolyline(HDC a0,
    POINT* a1,
    DWORD* a2,
    DWORD a3)
{
    _PrintEnter("PolyPolyline(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PolyPolyline(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PolyPolyline(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PolyTextOutA(HDC a0,
    POLYTEXTA* a1,
    int a2)
{
    _PrintEnter("PolyTextOutA(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_PolyTextOutA(a0, a1, a2);
    }
    __finally {
        _PrintExit("PolyTextOutA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PolyTextOutW(HDC a0,
    POLYTEXTW* a1,
    int a2)
{
    _PrintEnter("PolyTextOutW(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_PolyTextOutW(a0, a1, a2);
    }
    __finally {
        _PrintExit("PolyTextOutW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_Polygon(HDC a0,
    POINT* a1,
    int a2)
{
    _PrintEnter("Polygon(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_Polygon(a0, a1, a2);
    }
    __finally {
        _PrintExit("Polygon(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_Polyline(HDC a0,
    POINT* a1,
    int a2)
{
    _PrintEnter("Polyline(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_Polyline(a0, a1, a2);
    }
    __finally {
        _PrintExit("Polyline(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PolylineTo(HDC a0,
    POINT* a1,
    DWORD a2)
{
    _PrintEnter("PolylineTo(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_PolylineTo(a0, a1, a2);
    }
    __finally {
        _PrintExit("PolylineTo(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PostMessageA(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("PostMessageA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PostMessageA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PostMessageA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PostMessageW(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("PostMessageW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PostMessageW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PostMessageW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PostQueuedCompletionStatus(HANDLE a0,
    DWORD a1,
    ULONG_PTR a2,
    LPOVERLAPPED a3)
{
    _PrintEnter("PostQueuedCompletionStatus(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PostQueuedCompletionStatus(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PostQueuedCompletionStatus(,,,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_PostQuitMessage(int a0)
{
    _PrintEnter("PostQuitMessage(%p)\n", a0);

    __try {
        Real_PostQuitMessage(a0);
    }
    __finally {
        _PrintExit("PostQuitMessage() ->\n");
    };
}

BOOL __stdcall Mine_PostThreadMessageA(DWORD a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("PostThreadMessageA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PostThreadMessageA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PostThreadMessageA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PostThreadMessageW(DWORD a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("PostThreadMessageW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_PostThreadMessageW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("PostThreadMessageW(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_PrepareTape(HANDLE a0,
    DWORD a1,
    BOOL a2)
{
    _PrintEnter("PrepareTape(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_PrepareTape(a0, a1, a2);
    }
    __finally {
        _PrintExit("PrepareTape(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_ProgIDFromCLSID(CONST IID& a0,
    LPOLESTR* a1)
{
    _PrintEnter("ProgIDFromCLSID(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_ProgIDFromCLSID(a0, a1);
    }
    __finally {
        _PrintExit("ProgIDFromCLSID(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_PropVariantClear(PROPVARIANT* a0)
{
    _PrintEnter("PropVariantClear(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_PropVariantClear(a0);
    }
    __finally {
        _PrintExit("PropVariantClear() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_PropVariantCopy(PROPVARIANT* a0,
    PROPVARIANT* a1)
{
    _PrintEnter("PropVariantCopy(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_PropVariantCopy(a0, a1);
    }
    __finally {
        _PrintExit("PropVariantCopy(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PtInRect(RECT* a0,
    POINT a1)
{
    _PrintEnter("PtInRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_PtInRect(a0, a1);
    }
    __finally {
        _PrintExit("PtInRect(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PtInRegion(HRGN a0,
    int a1,
    int a2)
{
    _PrintEnter("PtInRegion(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_PtInRegion(a0, a1, a2);
    }
    __finally {
        _PrintExit("PtInRegion(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PtVisible(HDC a0,
    int a1,
    int a2)
{
    _PrintEnter("PtVisible(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_PtVisible(a0, a1, a2);
    }
    __finally {
        _PrintExit("PtVisible(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PulseEvent(HANDLE a0)
{
    _PrintEnter("PulseEvent(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_PulseEvent(a0);
    }
    __finally {
        _PrintExit("PulseEvent() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_PurgeComm(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("PurgeComm(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_PurgeComm(a0, a1);
    }
    __finally {
        _PrintExit("PurgeComm(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_QueryDosDeviceA(LPCSTR a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("QueryDosDeviceA(%hs,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_QueryDosDeviceA(a0, a1, a2);
    }
    __finally {
        _PrintExit("QueryDosDeviceA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD __stdcall Mine_QueryDosDeviceW(LPCWSTR a0,
    LPWSTR a1,
    DWORD a2)
{
    _PrintEnter("QueryDosDeviceW(%ls,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_QueryDosDeviceW(a0, a1, a2);
    }
    __finally {
        _PrintExit("QueryDosDeviceW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_QueryPerformanceCounter(LARGE_INTEGER* a0)
{
    _PrintEnter("QueryPerformanceCounter(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_QueryPerformanceCounter(a0);
    }
    __finally {
        _PrintExit("QueryPerformanceCounter() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_QueryPerformanceFrequency(LARGE_INTEGER* a0)
{
    _PrintEnter("QueryPerformanceFrequency(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_QueryPerformanceFrequency(a0);
    }
    __finally {
        _PrintExit("QueryPerformanceFrequency() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_QueueUserAPC(PAPCFUNC a0,
    HANDLE a1,
    ULONG_PTR a2)
{
    _PrintEnter("QueueUserAPC(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_QueueUserAPC(a0, a1, a2);
    }
    __finally {
        _PrintExit("QueueUserAPC(,,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_RaiseException(DWORD a0,
    DWORD a1,
    DWORD a2,
    ULONG_PTR* a3)
{
    _PrintEnter("RaiseException(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    __try {
        Real_RaiseException(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("RaiseException(,,,) ->\n");
    };
}

HRESULT __stdcall Mine_ReadClassStg(LPSTORAGE a0,
    CLSID* a1)
{
    _PrintEnter("ReadClassStg(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_ReadClassStg(a0, a1);
    }
    __finally {
        _PrintExit("ReadClassStg(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_ReadClassStm(LPSTREAM a0,
    CLSID* a1)
{
    _PrintEnter("ReadClassStm(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_ReadClassStm(a0, a1);
    }
    __finally {
        _PrintExit("ReadClassStm(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadConsoleA(
    HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPDWORD a3,
#ifdef ENABLE_INSERT_MODE
    PCONSOLE_READCONSOLE_CONTROL a4
#else
    LPVOID a4
#endif
)
{
    _PrintEnter("ReadConsoleA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadConsoleA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReadConsoleA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadConsoleInputA(HANDLE a0,
    PINPUT_RECORD a1,
    DWORD a2,
    LPDWORD a3)
{
    _PrintEnter("ReadConsoleInputA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_ReadConsoleInputA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("ReadConsoleInputA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadConsoleInputW(HANDLE a0,
    PINPUT_RECORD a1,
    DWORD a2,
    LPDWORD a3)
{
    _PrintEnter("ReadConsoleInputW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_ReadConsoleInputW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("ReadConsoleInputW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadConsoleOutputA(HANDLE a0,
    PCHAR_INFO a1,
    COORD a2,
    COORD a3,
    PSMALL_RECT a4)
{
    _PrintEnter("ReadConsoleOutputA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadConsoleOutputA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReadConsoleOutputA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadConsoleOutputAttribute(HANDLE a0,
    LPWORD a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
{
    _PrintEnter("ReadConsoleOutputAttribute(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadConsoleOutputAttribute(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReadConsoleOutputAttribute(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadConsoleOutputCharacterA(HANDLE a0,
    LPSTR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
{
    _PrintEnter("ReadConsoleOutputCharacterA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadConsoleOutputCharacterA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReadConsoleOutputCharacterA(,%hs,,,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadConsoleOutputCharacterW(HANDLE a0,
    LPWSTR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
{
    _PrintEnter("ReadConsoleOutputCharacterW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadConsoleOutputCharacterW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReadConsoleOutputCharacterW(,%ls,,,) -> %p\n", a1, rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadConsoleOutputW(HANDLE a0,
    PCHAR_INFO a1,
    COORD a2,
    COORD a3,
    PSMALL_RECT a4)
{
    _PrintEnter("ReadConsoleOutputW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadConsoleOutputW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReadConsoleOutputW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadConsoleW(
    HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPDWORD a3,
#ifdef ENABLE_INSERT_MODE
    PCONSOLE_READCONSOLE_CONTROL a4
#else
    LPVOID a4
#endif
)
{
    _PrintEnter("ReadConsoleW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadConsoleW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReadConsoleW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadDirectoryChangesW(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    BOOL a3,
    DWORD a4,
    LPDWORD a5,
    LPOVERLAPPED a6,
    LPOVERLAPPED_COMPLETION_ROUTINE a7)
{
    _PrintEnter("ReadDirectoryChangesW(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    BOOL rv = 0;
    __try {
        rv = Real_ReadDirectoryChangesW(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("ReadDirectoryChangesW(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadFile(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPDWORD a3,
    LPOVERLAPPED a4)
{
    _PrintEnter("ReadFile(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadFile(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReadFile(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadFileEx(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPOVERLAPPED a3,
    LPOVERLAPPED_COMPLETION_ROUTINE a4)
{
    _PrintEnter("ReadFileEx(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadFileEx(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReadFileEx(,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_ReadFmtUserTypeStg(LPSTORAGE a0,
    CLIPFORMAT* a1,
    LPOLESTR* a2)
{
    _PrintEnter("ReadFmtUserTypeStg(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_ReadFmtUserTypeStg(a0, a1, a2);
    }
    __finally {
        _PrintExit("ReadFmtUserTypeStg(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReadProcessMemory(HANDLE a0,
    LPCVOID lpBase,
    LPVOID lpBuf,
    DWORD_PTR nSize,
    PDWORD_PTR a4)
{
    _PrintEnter("ReadProcessMemory(%p,@%p..%p,%p,%p)\n",
        a0, lpBase,
        (PBYTE)lpBase + ((nSize > 0) ? nSize - 1 : 0),
        lpBuf, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ReadProcessMemory(a0, lpBase, lpBuf, nSize, a4);
    }
    __finally {
        _PrintExit("ReadProcessMemory(,,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_RealizePalette(HDC a0)
{
    _PrintEnter("RealizePalette(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_RealizePalette(a0);
    }
    __finally {
        _PrintExit("RealizePalette() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RectInRegion(HRGN a0,
    RECT* a1)
{
    _PrintEnter("RectInRegion(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_RectInRegion(a0, a1);
    }
    __finally {
        _PrintExit("RectInRegion(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RectVisible(HDC a0,
    RECT* a1)
{
    _PrintEnter("RectVisible(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_RectVisible(a0, a1);
    }
    __finally {
        _PrintExit("RectVisible(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_Rectangle(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4)
{
    _PrintEnter("Rectangle(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_Rectangle(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("Rectangle(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RedrawWindow(HWND a0,
    RECT* a1,
    HRGN a2,
    UINT a3)
{
    _PrintEnter("RedrawWindow(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_RedrawWindow(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("RedrawWindow(,,,) -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_RegisterClassA(WNDCLASSA* a0)
{
    _PrintEnter("RegisterClassA(%p)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_RegisterClassA(a0);
    }
    __finally {
        _PrintExit("RegisterClassA() -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_RegisterClassExA(WNDCLASSEXA* a0)
{
    _PrintEnter("RegisterClassExA(%p)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_RegisterClassExA(a0);
    }
    __finally {
        _PrintExit("RegisterClassExA() -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_RegisterClassExW(WNDCLASSEXW* a0)
{
    _PrintEnter("RegisterClassExW(%p)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_RegisterClassExW(a0);
    }
    __finally {
        _PrintExit("RegisterClassExW() -> %p\n", rv);
    };
    return rv;
}

ATOM __stdcall Mine_RegisterClassW(WNDCLASSW* a0)
{
    _PrintEnter("RegisterClassW(%p)\n", a0);

    ATOM rv = 0;
    __try {
        rv = Real_RegisterClassW(a0);
    }
    __finally {
        _PrintExit("RegisterClassW() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_RegisterClipboardFormatA(LPCSTR a0)
{
    _PrintEnter("RegisterClipboardFormatA(%hs)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_RegisterClipboardFormatA(a0);
    }
    __finally {
        _PrintExit("RegisterClipboardFormatA() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_RegisterClipboardFormatW(LPCWSTR a0)
{
    _PrintEnter("RegisterClipboardFormatW(%ls)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_RegisterClipboardFormatW(a0);
    }
    __finally {
        _PrintExit("RegisterClipboardFormatW() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_RegisterDragDrop(HWND a0,
    IDropTarget* a1)
{
    _PrintEnter("RegisterDragDrop(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_RegisterDragDrop(a0, a1);
    }
    __finally {
        _PrintExit("RegisterDragDrop(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RegisterHotKey(HWND a0,
    int a1,
    UINT a2,
    UINT a3)
{
    _PrintEnter("RegisterHotKey(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_RegisterHotKey(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("RegisterHotKey(,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_RegisterWindowMessageA(LPCSTR a0)
{
    _PrintEnter("RegisterWindowMessageA(%hs)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_RegisterWindowMessageA(a0);
    }
    __finally {
        _PrintExit("RegisterWindowMessageA() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_RegisterWindowMessageW(LPCWSTR a0)
{
    _PrintEnter("RegisterWindowMessageW(%ls)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_RegisterWindowMessageW(a0);
    }
    __finally {
        _PrintExit("RegisterWindowMessageW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReleaseCapture(void)
{
    _PrintEnter("ReleaseCapture()\n");

    BOOL rv = 0;
    __try {
        rv = Real_ReleaseCapture();
    }
    __finally {
        _PrintExit("ReleaseCapture() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ReleaseDC(HWND a0,
    HDC a1)
{
    _PrintEnter("ReleaseDC(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_ReleaseDC(a0, a1);
    }
    __finally {
        _PrintExit("ReleaseDC(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReleaseMutex(HANDLE a0)
{
    _PrintEnter("ReleaseMutex(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_ReleaseMutex(a0);
    }
    __finally {
        _PrintExit("ReleaseMutex() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReleaseSemaphore(HANDLE a0,
    LONG a1,
    LPLONG a2)
{
    _PrintEnter("ReleaseSemaphore(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_ReleaseSemaphore(a0, a1, a2);
    }
    __finally {
        _PrintExit("ReleaseSemaphore(,,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_ReleaseStgMedium(LPSTGMEDIUM a0)
{
    _PrintEnter("ReleaseStgMedium(%p)\n", a0);

    __try {
        Real_ReleaseStgMedium(a0);
    }
    __finally {
        _PrintExit("ReleaseStgMedium() ->\n");
    };
}

BOOL __stdcall Mine_RemoveDirectoryA(LPCSTR a0)
{
    _PrintEnter("RemoveDirectoryA(%hs)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_RemoveDirectoryA(a0);
    }
    __finally {
        _PrintExit("RemoveDirectoryA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RemoveDirectoryW(LPCWSTR a0)
{
    _PrintEnter("RemoveDirectoryW(%ls)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_RemoveDirectoryW(a0);
    }
    __finally {
        _PrintExit("RemoveDirectoryW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RemoveFontResourceA(LPCSTR a0)
{
    _PrintEnter("RemoveFontResourceA(%hs)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_RemoveFontResourceA(a0);
    }
    __finally {
        _PrintExit("RemoveFontResourceA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RemoveFontResourceW(LPCWSTR a0)
{
    _PrintEnter("RemoveFontResourceW(%ls)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_RemoveFontResourceW(a0);
    }
    __finally {
        _PrintExit("RemoveFontResourceW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RemoveMenu(HMENU a0,
    UINT a1,
    UINT a2)
{
    _PrintEnter("RemoveMenu(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_RemoveMenu(a0, a1, a2);
    }
    __finally {
        _PrintExit("RemoveMenu(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_RemovePropA(HWND a0,
    LPCSTR a1)
{
    _PrintEnter("RemovePropA(%p,%hs)\n", a0, a1);

    HANDLE rv = 0;
    __try {
        rv = Real_RemovePropA(a0, a1);
    }
    __finally {
        _PrintExit("RemovePropA(,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_RemovePropW(HWND a0,
    LPCWSTR a1)
{
    _PrintEnter("RemovePropW(%p,%ls)\n", a0, a1);

    HANDLE rv = 0;
    __try {
        rv = Real_RemovePropW(a0, a1);
    }
    __finally {
        _PrintExit("RemovePropW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ReplyMessage(LRESULT a0)
{
    _PrintEnter("ReplyMessage(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_ReplyMessage(a0);
    }
    __finally {
        _PrintExit("ReplyMessage() -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_ResetDCA(HDC a0,
    CONST DEVMODEA* a1)
{
    _PrintEnter("ResetDCA(%p,%p)\n", a0, a1);

    HDC rv = 0;
    __try {
        rv = Real_ResetDCA(a0, a1);
    }
    __finally {
        _PrintExit("ResetDCA(,) -> %p\n", rv);
    };
    return rv;
}

HDC __stdcall Mine_ResetDCW(HDC a0,
    CONST DEVMODEW* a1)
{
    _PrintEnter("ResetDCW(%p,%p)\n", a0, a1);

    HDC rv = 0;
    __try {
        rv = Real_ResetDCW(a0, a1);
    }
    __finally {
        _PrintExit("ResetDCW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ResetEvent(HANDLE a0)
{
    _PrintEnter("ResetEvent(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_ResetEvent(a0);
    }
    __finally {
        _PrintExit("ResetEvent() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ResizePalette(HPALETTE a0,
    UINT a1)
{
    _PrintEnter("ResizePalette(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ResizePalette(a0, a1);
    }
    __finally {
        _PrintExit("ResizePalette(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RestoreDC(HDC a0,
    int a1)
{
    _PrintEnter("RestoreDC(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_RestoreDC(a0, a1);
    }
    __finally {
        _PrintExit("RestoreDC(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_ResumeThread(HANDLE a0)
{
    _PrintEnter("ResumeThread(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_ResumeThread(a0);
    }
    __finally {
        _PrintExit("ResumeThread() -> %p\n", rv);
    };
    return rv;
}

LPARAM __stdcall Mine_ReuseDDElParam(LPARAM a0,
    UINT a1,
    UINT a2,
    UINT_PTR a3,
    UINT_PTR a4)
{
    _PrintEnter("ReuseDDElParam(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LPARAM rv = 0;
    __try {
        rv = Real_ReuseDDElParam(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ReuseDDElParam(,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_RevokeDragDrop(HWND a0)
{
    _PrintEnter("RevokeDragDrop(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_RevokeDragDrop(a0);
    }
    __finally {
        _PrintExit("RevokeDragDrop() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_RoundRect(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6)
{
    _PrintEnter("RoundRect(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_RoundRect(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("RoundRect(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SaveDC(HDC a0)
{
    _PrintEnter("SaveDC(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_SaveDC(a0);
    }
    __finally {
        _PrintExit("SaveDC() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ScaleViewportExtEx(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    SIZE* a5)
{
    _PrintEnter("ScaleViewportExtEx(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_ScaleViewportExtEx(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("ScaleViewportExtEx(,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ScaleWindowExtEx(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    SIZE* a5)
{
    _PrintEnter("ScaleWindowExtEx(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_ScaleWindowExtEx(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("ScaleWindowExtEx(,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ScreenToClient(HWND a0,
    POINT* a1)
{
    _PrintEnter("ScreenToClient(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ScreenToClient(a0, a1);
    }
    __finally {
        _PrintExit("ScreenToClient(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ScrollConsoleScreenBufferA(HANDLE a0,
    SMALL_RECT* a1,
    SMALL_RECT* a2,
    COORD a3,
    CHAR_INFO* a4)
{
    _PrintEnter("ScrollConsoleScreenBufferA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ScrollConsoleScreenBufferA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ScrollConsoleScreenBufferA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ScrollConsoleScreenBufferW(HANDLE a0,
    SMALL_RECT* a1,
    SMALL_RECT* a2,
    COORD a3,
    CHAR_INFO* a4)
{
    _PrintEnter("ScrollConsoleScreenBufferW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ScrollConsoleScreenBufferW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ScrollConsoleScreenBufferW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ScrollDC(HDC a0,
    int a1,
    int a2,
    RECT* a3,
    RECT* a4,
    HRGN a5,
    LPRECT a6)
{
    _PrintEnter("ScrollDC(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_ScrollDC(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("ScrollDC(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ScrollWindow(HWND a0,
    int a1,
    int a2,
    RECT* a3,
    RECT* a4)
{
    _PrintEnter("ScrollWindow(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_ScrollWindow(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ScrollWindow(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ScrollWindowEx(HWND a0,
    int a1,
    int a2,
    RECT* a3,
    RECT* a4,
    HRGN a5,
    LPRECT a6,
    UINT a7)
{
    _PrintEnter("ScrollWindowEx(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    int rv = 0;
    __try {
        rv = Real_ScrollWindowEx(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("ScrollWindowEx(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SearchPathA(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    DWORD a3,
    LPSTR a4,
    LPSTR* a5)
{
    _PrintEnter("SearchPathA(%hs,%hs,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    DWORD rv = 0;
    __try {
        rv = Real_SearchPathA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("SearchPathA(,,,,%hs,) -> %p\n", a4, rv);
    };
    return rv;
}

DWORD __stdcall Mine_SearchPathW(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    DWORD a3,
    LPWSTR a4,
    LPWSTR* a5)
{
    _PrintEnter("SearchPathW(%ls,%ls,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    DWORD rv = 0;
    __try {
        rv = Real_SearchPathW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("SearchPathW(,,,,%ls,) -> %p\n", a4, rv);
    };
    return rv;
}

BOOL __stdcall Mine_SelectClipPath(HDC a0,
    int a1)
{
    _PrintEnter("SelectClipPath(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SelectClipPath(a0, a1);
    }
    __finally {
        _PrintExit("SelectClipPath(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SelectClipRgn(HDC a0,
    HRGN a1)
{
    _PrintEnter("SelectClipRgn(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SelectClipRgn(a0, a1);
    }
    __finally {
        _PrintExit("SelectClipRgn(,) -> %p\n", rv);
    };
    return rv;
}

HGDIOBJ __stdcall Mine_SelectObject(HDC a0,
    HGDIOBJ a1)
{
    _PrintEnter("SelectObject(%p,%p)\n", a0, a1);

    HGDIOBJ rv = 0;
    __try {
        rv = Real_SelectObject(a0, a1);
    }
    __finally {
        _PrintExit("SelectObject(,) -> %p\n", rv);
    };
    return rv;
}

HPALETTE __stdcall Mine_SelectPalette(HDC a0,
    HPALETTE a1,
    BOOL a2)
{
    _PrintEnter("SelectPalette(%p,%p,%p)\n", a0, a1, a2);

    HPALETTE rv = 0;
    __try {
        rv = Real_SelectPalette(a0, a1, a2);
    }
    __finally {
        _PrintExit("SelectPalette(,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_SendDlgItemMessageA(HWND a0,
    int a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
{
    _PrintEnter("SendDlgItemMessageA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LRESULT rv = 0;
    __try {
        rv = Real_SendDlgItemMessageA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("SendDlgItemMessageA(,,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_SendDlgItemMessageW(HWND a0,
    int a1,
    UINT a2,
    WPARAM a3,
    LPARAM a4)
{
    _PrintEnter("SendDlgItemMessageW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LRESULT rv = 0;
    __try {
        rv = Real_SendDlgItemMessageW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("SendDlgItemMessageW(,,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_SendMessageA(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("SendMessageA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    LRESULT rv = 0;
    __try {
        rv = Real_SendMessageA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SendMessageA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SendMessageCallbackA(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3,
    SENDASYNCPROC a4,
    ULONG_PTR a5)
{
    _PrintEnter("SendMessageCallbackA(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_SendMessageCallbackA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("SendMessageCallbackA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SendMessageCallbackW(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3,
    SENDASYNCPROC a4,
    ULONG_PTR a5)
{
    _PrintEnter("SendMessageCallbackW(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_SendMessageCallbackW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("SendMessageCallbackW(,,,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_SendMessageTimeoutA(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3,
    UINT a4,
    UINT a5,
    PULONG_PTR a6)
{
    _PrintEnter("SendMessageTimeoutA(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    LRESULT rv = 0;
    __try {
        rv = Real_SendMessageTimeoutA(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("SendMessageTimeoutA(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_SendMessageTimeoutW(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3,
    UINT a4,
    UINT a5,
    PULONG_PTR a6)
{
    _PrintEnter("SendMessageTimeoutW(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    LRESULT rv = 0;
    __try {
        rv = Real_SendMessageTimeoutW(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("SendMessageTimeoutW(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

LRESULT __stdcall Mine_SendMessageW(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("SendMessageW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    LRESULT rv = 0;
    __try {
        rv = Real_SendMessageW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SendMessageW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SendNotifyMessageA(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("SendNotifyMessageA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SendNotifyMessageA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SendNotifyMessageA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SendNotifyMessageW(HWND a0,
    UINT a1,
    WPARAM a2,
    LPARAM a3)
{
    _PrintEnter("SendNotifyMessageW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SendNotifyMessageW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SendNotifyMessageW(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetAbortProc(HDC a0,
    ABORTPROC a1)
{
    _PrintEnter("SetAbortProc(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetAbortProc(a0, a1);
    }
    __finally {
        _PrintExit("SetAbortProc(,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_SetActiveWindow(HWND a0)
{
    _PrintEnter("SetActiveWindow(%p)\n", a0);

    HWND rv = 0;
    __try {
        rv = Real_SetActiveWindow(a0);
    }
    __finally {
        _PrintExit("SetActiveWindow() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetArcDirection(HDC a0,
    int a1)
{
    _PrintEnter("SetArcDirection(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetArcDirection(a0, a1);
    }
    __finally {
        _PrintExit("SetArcDirection(,) -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_SetBitmapBits(HBITMAP a0,
    DWORD a1,
    void* a2)
{
    _PrintEnter("SetBitmapBits(%p,%p,%p)\n", a0, a1, a2);

    LONG rv = 0;
    __try {
        rv = Real_SetBitmapBits(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetBitmapBits(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetBitmapDimensionEx(HBITMAP a0,
    int a1,
    int a2,
    SIZE* a3)
{
    _PrintEnter("SetBitmapDimensionEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetBitmapDimensionEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetBitmapDimensionEx(,,,) -> %p\n", rv);
    };
    return rv;
}

COLORREF __stdcall Mine_SetBkColor(HDC a0,
    COLORREF a1)
{
    _PrintEnter("SetBkColor(%p,%p)\n", a0, a1);

    COLORREF rv = 0;
    __try {
        rv = Real_SetBkColor(a0, a1);
    }
    __finally {
        _PrintExit("SetBkColor(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetBkMode(HDC a0,
    int a1)
{
    _PrintEnter("SetBkMode(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetBkMode(a0, a1);
    }
    __finally {
        _PrintExit("SetBkMode(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_SetBoundsRect(HDC a0,
    RECT* a1,
    UINT a2)
{
    _PrintEnter("SetBoundsRect(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real_SetBoundsRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetBoundsRect(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetBrushOrgEx(HDC a0,
    int a1,
    int a2,
    POINT* a3)
{
    _PrintEnter("SetBrushOrgEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetBrushOrgEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetBrushOrgEx(,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_SetCapture(HWND a0)
{
    _PrintEnter("SetCapture(%p)\n", a0);

    HWND rv = 0;
    __try {
        rv = Real_SetCapture(a0);
    }
    __finally {
        _PrintExit("SetCapture() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCaretBlinkTime(UINT a0)
{
    _PrintEnter("SetCaretBlinkTime(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetCaretBlinkTime(a0);
    }
    __finally {
        _PrintExit("SetCaretBlinkTime() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCaretPos(int a0,
    int a1)
{
    _PrintEnter("SetCaretPos(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetCaretPos(a0, a1);
    }
    __finally {
        _PrintExit("SetCaretPos(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SetClassLongA(HWND a0,
    int a1,
    LONG a2)
{
    _PrintEnter("SetClassLongA(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_SetClassLongA(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetClassLongA(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SetClassLongW(HWND a0,
    int a1,
    LONG a2)
{
    _PrintEnter("SetClassLongW(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_SetClassLongW(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetClassLongW(,,) -> %p\n", rv);
    };
    return rv;
}

WORD __stdcall Mine_SetClassWord(HWND a0,
    int a1,
    WORD a2)
{
    _PrintEnter("SetClassWord(%p,%p,%p)\n", a0, a1, a2);

    WORD rv = 0;
    __try {
        rv = Real_SetClassWord(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetClassWord(,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_SetClipboardData(UINT a0,
    HANDLE a1)
{
    _PrintEnter("SetClipboardData(%p,%p)\n", a0, a1);

    HANDLE rv = 0;
    __try {
        rv = Real_SetClipboardData(a0, a1);
    }
    __finally {
        _PrintExit("SetClipboardData(,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_SetClipboardViewer(HWND a0)
{
    _PrintEnter("SetClipboardViewer(%p)\n", a0);

    HWND rv = 0;
    __try {
        rv = Real_SetClipboardViewer(a0);
    }
    __finally {
        _PrintExit("SetClipboardViewer() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetColorAdjustment(HDC a0,
    COLORADJUSTMENT* a1)
{
    _PrintEnter("SetColorAdjustment(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetColorAdjustment(a0, a1);
    }
    __finally {
        _PrintExit("SetColorAdjustment(,) -> %p\n", rv);
    };
    return rv;
}

HCOLORSPACE __stdcall Mine_SetColorSpace(HDC a0,
    HCOLORSPACE a1)
{
    _PrintEnter("SetColorSpace(%p,%p)\n", a0, a1);

    HCOLORSPACE rv = 0;
    __try {
        rv = Real_SetColorSpace(a0, a1);
    }
    __finally {
        _PrintExit("SetColorSpace(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCommBreak(HANDLE a0)
{
    _PrintEnter("SetCommBreak(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetCommBreak(a0);
    }
    __finally {
        _PrintExit("SetCommBreak() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCommConfig(HANDLE a0,
    LPCOMMCONFIG a1,
    DWORD a2)
{
    _PrintEnter("SetCommConfig(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetCommConfig(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetCommConfig(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCommMask(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("SetCommMask(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetCommMask(a0, a1);
    }
    __finally {
        _PrintExit("SetCommMask(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCommState(HANDLE a0,
    LPDCB a1)
{
    _PrintEnter("SetCommState(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetCommState(a0, a1);
    }
    __finally {
        _PrintExit("SetCommState(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCommTimeouts(HANDLE a0,
    LPCOMMTIMEOUTS a1)
{
    _PrintEnter("SetCommTimeouts(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetCommTimeouts(a0, a1);
    }
    __finally {
        _PrintExit("SetCommTimeouts(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetComputerNameA(LPCSTR a0)
{
    _PrintEnter("SetComputerNameA(%hs)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetComputerNameA(a0);
    }
    __finally {
        _PrintExit("SetComputerNameA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetComputerNameW(LPCWSTR a0)
{
    _PrintEnter("SetComputerNameW(%ls)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetComputerNameW(a0);
    }
    __finally {
        _PrintExit("SetComputerNameW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleActiveScreenBuffer(HANDLE a0)
{
    _PrintEnter("SetConsoleActiveScreenBuffer(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleActiveScreenBuffer(a0);
    }
    __finally {
        _PrintExit("SetConsoleActiveScreenBuffer() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleCP(UINT a0)
{
    _PrintEnter("SetConsoleCP(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleCP(a0);
    }
    __finally {
        _PrintExit("SetConsoleCP() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleCtrlHandler(PHANDLER_ROUTINE a0,
    BOOL a1)
{
    _PrintEnter("SetConsoleCtrlHandler(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleCtrlHandler(a0, a1);
    }
    __finally {
        _PrintExit("SetConsoleCtrlHandler(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleCursorInfo(HANDLE a0,
    CONSOLE_CURSOR_INFO* a1)
{
    _PrintEnter("SetConsoleCursorInfo(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleCursorInfo(a0, a1);
    }
    __finally {
        _PrintExit("SetConsoleCursorInfo(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleCursorPosition(HANDLE a0,
    COORD a1)
{
    _PrintEnter("SetConsoleCursorPosition(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleCursorPosition(a0, a1);
    }
    __finally {
        _PrintExit("SetConsoleCursorPosition(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleMode(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("SetConsoleMode(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleMode(a0, a1);
    }
    __finally {
        _PrintExit("SetConsoleMode(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleOutputCP(UINT a0)
{
    _PrintEnter("SetConsoleOutputCP(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleOutputCP(a0);
    }
    __finally {
        _PrintExit("SetConsoleOutputCP() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleScreenBufferSize(HANDLE a0,
    COORD a1)
{
    _PrintEnter("SetConsoleScreenBufferSize(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleScreenBufferSize(a0, a1);
    }
    __finally {
        _PrintExit("SetConsoleScreenBufferSize(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleTextAttribute(HANDLE a0,
    WORD a1)
{
    _PrintEnter("SetConsoleTextAttribute(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleTextAttribute(a0, a1);
    }
    __finally {
        _PrintExit("SetConsoleTextAttribute(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleTitleA(LPCSTR a0)
{
    _PrintEnter("SetConsoleTitleA(%hs)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleTitleA(a0);
    }
    __finally {
        _PrintExit("SetConsoleTitleA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleTitleW(LPCWSTR a0)
{
    _PrintEnter("SetConsoleTitleW(%ls)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleTitleW(a0);
    }
    __finally {
        _PrintExit("SetConsoleTitleW() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetConsoleWindowInfo(HANDLE a0,
    BOOL a1,
    SMALL_RECT* a2)
{
    _PrintEnter("SetConsoleWindowInfo(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetConsoleWindowInfo(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetConsoleWindowInfo(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_SetConvertStg(LPSTORAGE a0,
    BOOL a1)
{
    _PrintEnter("SetConvertStg(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_SetConvertStg(a0, a1);
    }
    __finally {
        _PrintExit("SetConvertStg(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCurrentDirectoryA(LPCSTR a0)
{
    _PrintEnter("SetCurrentDirectoryA(%hs)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetCurrentDirectoryA(a0);
    }
    __finally {
        _PrintExit("SetCurrentDirectoryA() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCurrentDirectoryW(LPCWSTR a0)
{
    _PrintEnter("SetCurrentDirectoryW(%ls)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetCurrentDirectoryW(a0);
    }
    __finally {
        _PrintExit("SetCurrentDirectoryW() -> %p\n", rv);
    };
    return rv;
}

HCURSOR __stdcall Mine_SetCursor(HCURSOR a0)
{
    _PrintEnter("SetCursor(%p)\n", a0);

    HCURSOR rv = 0;
    __try {
        rv = Real_SetCursor(a0);
    }
    __finally {
        _PrintExit("SetCursor() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetCursorPos(int a0,
    int a1)
{
    _PrintEnter("SetCursorPos(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetCursorPos(a0, a1);
    }
    __finally {
        _PrintExit("SetCursorPos(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_SetDIBColorTable(HDC a0,
    UINT a1,
    UINT a2,
    RGBQUAD* a3)
{
    _PrintEnter("SetDIBColorTable(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_SetDIBColorTable(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetDIBColorTable(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetDIBits(HDC a0,
    HBITMAP a1,
    UINT a2,
    UINT a3,
    void* a4,
    BITMAPINFO* a5,
    UINT a6)
{
    _PrintEnter("SetDIBits(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    int rv = 0;
    __try {
        rv = Real_SetDIBits(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("SetDIBits(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetDIBitsToDevice(HDC a0,
    int a1,
    int a2,
    DWORD a3,
    DWORD a4,
    int a5,
    int a6,
    UINT a7,
    UINT a8,
    void* a9,
    BITMAPINFO* a10,
    UINT a11)
{
    _PrintEnter("SetDIBitsToDevice(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    int rv = 0;
    __try {
        rv = Real_SetDIBitsToDevice(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
    __finally {
        _PrintExit("SetDIBitsToDevice(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetDefaultCommConfigA(LPCSTR a0,
    LPCOMMCONFIG a1,
    DWORD a2)
{
    _PrintEnter("SetDefaultCommConfigA(%hs,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetDefaultCommConfigA(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetDefaultCommConfigA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetDefaultCommConfigW(LPCWSTR a0,
    LPCOMMCONFIG a1,
    DWORD a2)
{
    _PrintEnter("SetDefaultCommConfigW(%ls,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetDefaultCommConfigW(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetDefaultCommConfigW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetDeviceGammaRamp(HDC a0,
    LPVOID a1)
{
    _PrintEnter("SetDeviceGammaRamp(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetDeviceGammaRamp(a0, a1);
    }
    __finally {
        _PrintExit("SetDeviceGammaRamp(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetDlgItemInt(HWND a0,
    int a1,
    UINT a2,
    BOOL a3)
{
    _PrintEnter("SetDlgItemInt(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetDlgItemInt(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetDlgItemInt(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetDlgItemTextA(HWND a0,
    int a1,
    LPCSTR a2)
{
    _PrintEnter("SetDlgItemTextA(%p,%p,%hs)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetDlgItemTextA(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetDlgItemTextA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetDlgItemTextW(HWND a0,
    int a1,
    LPCWSTR a2)
{
    _PrintEnter("SetDlgItemTextW(%p,%p,%ls)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetDlgItemTextW(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetDlgItemTextW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetDoubleClickTime(UINT a0)
{
    _PrintEnter("SetDoubleClickTime(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetDoubleClickTime(a0);
    }
    __finally {
        _PrintExit("SetDoubleClickTime() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetEndOfFile(HANDLE a0)
{
    _PrintEnter("SetEndOfFile(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetEndOfFile(a0);
    }
    __finally {
        _PrintExit("SetEndOfFile() -> %p\n", rv);
    };
    return rv;
}

HENHMETAFILE __stdcall Mine_SetEnhMetaFileBits(UINT a0,
    BYTE* a1)
{
    _PrintEnter("SetEnhMetaFileBits(%p,%p)\n", a0, a1);

    HENHMETAFILE rv = 0;
    __try {
        rv = Real_SetEnhMetaFileBits(a0, a1);
    }
    __finally {
        _PrintExit("SetEnhMetaFileBits(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetEnvironmentVariableA(LPCSTR a0,
    LPCSTR a1)
{
    _PrintEnter("SetEnvironmentVariableA(%hs,%hs)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetEnvironmentVariableA(a0, a1);
    }
    __finally {
        _PrintExit("SetEnvironmentVariableA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetEnvironmentVariableW(LPCWSTR a0,
    LPCWSTR a1)
{
    _PrintEnter("SetEnvironmentVariableW(%ls,%ls)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetEnvironmentVariableW(a0, a1);
    }
    __finally {
        _PrintExit("SetEnvironmentVariableW(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_SetErrorMode(UINT a0)
{
    _PrintEnter("SetErrorMode(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_SetErrorMode(a0);
    }
    __finally {
        _PrintExit("SetErrorMode() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetEvent(HANDLE a0)
{
    _PrintEnter("SetEvent(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetEvent(a0);
    }
    __finally {
        _PrintExit("SetEvent() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_SetFileApisToANSI(void)
{
    _PrintEnter("SetFileApisToANSI()\n");

    __try {
        Real_SetFileApisToANSI();
    }
    __finally {
        _PrintExit("SetFileApisToANSI() ->\n");
    };
}

void __stdcall Mine_SetFileApisToOEM(void)
{
    _PrintEnter("SetFileApisToOEM()\n");

    __try {
        Real_SetFileApisToOEM();
    }
    __finally {
        _PrintExit("SetFileApisToOEM() ->\n");
    };
}

BOOL __stdcall Mine_SetFileAttributesA(LPCSTR a0,
    DWORD a1)
{
    _PrintEnter("SetFileAttributesA(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetFileAttributesA(a0, a1);
    }
    __finally {
        _PrintExit("SetFileAttributesA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetFileAttributesW(LPCWSTR a0,
    DWORD a1)
{
    _PrintEnter("SetFileAttributesW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetFileAttributesW(a0, a1);
    }
    __finally {
        _PrintExit("SetFileAttributesW(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SetFilePointer(HANDLE a0,
    LONG a1,
    PLONG a2,
    DWORD a3)
{
    _PrintEnter("SetFilePointer(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_SetFilePointer(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetFilePointer(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetFileTime(HANDLE a0,
    FILETIME* a1,
    FILETIME* a2,
    FILETIME* a3)
{
    _PrintEnter("SetFileTime(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetFileTime(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetFileTime(,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_SetFocus(HWND a0)
{
    _PrintEnter("SetFocus(%p)\n", a0);

    HWND rv = 0;
    __try {
        rv = Real_SetFocus(a0);
    }
    __finally {
        _PrintExit("SetFocus() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetForegroundWindow(HWND a0)
{
    _PrintEnter("SetForegroundWindow(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetForegroundWindow(a0);
    }
    __finally {
        _PrintExit("SetForegroundWindow() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetGraphicsMode(HDC a0,
    int a1)
{
    _PrintEnter("SetGraphicsMode(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetGraphicsMode(a0, a1);
    }
    __finally {
        _PrintExit("SetGraphicsMode(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_SetHandleCount(UINT a0)
{
    _PrintEnter("SetHandleCount(%p)\n", a0);

    UINT rv = 0;
    __try {
        rv = Real_SetHandleCount(a0);
    }
    __finally {
        _PrintExit("SetHandleCount() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetHandleInformation(HANDLE a0,
    DWORD a1,
    DWORD a2)
{
    _PrintEnter("SetHandleInformation(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetHandleInformation(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetHandleInformation(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetICMMode(HDC a0,
    int a1)
{
    _PrintEnter("SetICMMode(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetICMMode(a0, a1);
    }
    __finally {
        _PrintExit("SetICMMode(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetICMProfileA(HDC a0,
    LPSTR a1)
{
    _PrintEnter("SetICMProfileA(%p,%hs)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetICMProfileA(a0, a1);
    }
    __finally {
        _PrintExit("SetICMProfileA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetICMProfileW(HDC a0,
    LPWSTR a1)
{
    _PrintEnter("SetICMProfileW(%p,%ls)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetICMProfileW(a0, a1);
    }
    __finally {
        _PrintExit("SetICMProfileW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetKeyboardState(LPBYTE a0)
{
    _PrintEnter("SetKeyboardState(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetKeyboardState(a0);
    }
    __finally {
        _PrintExit("SetKeyboardState() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetLocalTime(SYSTEMTIME* a0)
{
    _PrintEnter("SetLocalTime(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetLocalTime(a0);
    }
    __finally {
        _PrintExit("SetLocalTime() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetLocaleInfoA(LCID a0,
    LCTYPE a1,
    LPCSTR a2)
{
    _PrintEnter("SetLocaleInfoA(%p,%p,%hs)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetLocaleInfoA(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetLocaleInfoA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetLocaleInfoW(LCID a0,
    LCTYPE a1,
    LPCWSTR a2)
{
    _PrintEnter("SetLocaleInfoW(%p,%p,%ls)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetLocaleInfoW(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetLocaleInfoW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetMailslotInfo(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("SetMailslotInfo(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetMailslotInfo(a0, a1);
    }
    __finally {
        _PrintExit("SetMailslotInfo(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetMapMode(HDC a0,
    int a1)
{
    _PrintEnter("SetMapMode(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetMapMode(a0, a1);
    }
    __finally {
        _PrintExit("SetMapMode(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SetMapperFlags(HDC a0,
    DWORD a1)
{
    _PrintEnter("SetMapperFlags(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_SetMapperFlags(a0, a1);
    }
    __finally {
        _PrintExit("SetMapperFlags(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetMenu(HWND a0,
    HMENU a1)
{
    _PrintEnter("SetMenu(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetMenu(a0, a1);
    }
    __finally {
        _PrintExit("SetMenu(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetMenuContextHelpId(HMENU a0,
    DWORD a1)
{
    _PrintEnter("SetMenuContextHelpId(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetMenuContextHelpId(a0, a1);
    }
    __finally {
        _PrintExit("SetMenuContextHelpId(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetMenuDefaultItem(HMENU a0,
    UINT a1,
    UINT a2)
{
    _PrintEnter("SetMenuDefaultItem(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetMenuDefaultItem(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetMenuDefaultItem(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetMenuItemBitmaps(HMENU a0,
    UINT a1,
    UINT a2,
    HBITMAP a3,
    HBITMAP a4)
{
    _PrintEnter("SetMenuItemBitmaps(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_SetMenuItemBitmaps(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("SetMenuItemBitmaps(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetMenuItemInfoA(HMENU a0,
    UINT a1,
    BOOL a2,
    MENUITEMINFOA* a3)
{
    _PrintEnter("SetMenuItemInfoA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetMenuItemInfoA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetMenuItemInfoA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetMenuItemInfoW(HMENU a0,
    UINT a1,
    BOOL a2,
    MENUITEMINFOW* a3)
{
    _PrintEnter("SetMenuItemInfoW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetMenuItemInfoW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetMenuItemInfoW(,,,) -> %p\n", rv);
    };
    return rv;
}

LPARAM __stdcall Mine_SetMessageExtraInfo(LPARAM a0)
{
    _PrintEnter("SetMessageExtraInfo(%p)\n", a0);

    LPARAM rv = 0;
    __try {
        rv = Real_SetMessageExtraInfo(a0);
    }
    __finally {
        _PrintExit("SetMessageExtraInfo() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetMessageQueue(int a0)
{
    _PrintEnter("SetMessageQueue(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetMessageQueue(a0);
    }
    __finally {
        _PrintExit("SetMessageQueue() -> %p\n", rv);
    };
    return rv;
}

HMETAFILE __stdcall Mine_SetMetaFileBitsEx(UINT a0,
    BYTE* a1)
{
    _PrintEnter("SetMetaFileBitsEx(%p,%p)\n", a0, a1);

    HMETAFILE rv = 0;
    __try {
        rv = Real_SetMetaFileBitsEx(a0, a1);
    }
    __finally {
        _PrintExit("SetMetaFileBitsEx(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetMetaRgn(HDC a0)
{
    _PrintEnter("SetMetaRgn(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_SetMetaRgn(a0);
    }
    __finally {
        _PrintExit("SetMetaRgn() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetMiterLimit(HDC a0,
    FLOAT a1,
    PFLOAT a2)
{
    _PrintEnter("SetMiterLimit(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetMiterLimit(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetMiterLimit(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetNamedPipeHandleState(HANDLE a0,
    LPDWORD a1,
    LPDWORD a2,
    LPDWORD a3)
{
    _PrintEnter("SetNamedPipeHandleState(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetNamedPipeHandleState(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetNamedPipeHandleState(,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_SetPaletteEntries(HPALETTE a0,
    UINT a1,
    UINT a2,
    PALETTEENTRY* a3)
{
    _PrintEnter("SetPaletteEntries(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    UINT rv = 0;
    __try {
        rv = Real_SetPaletteEntries(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetPaletteEntries(,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_SetParent(HWND a0,
    HWND a1)
{
    _PrintEnter("SetParent(%p,%p)\n", a0, a1);

    HWND rv = 0;
    __try {
        rv = Real_SetParent(a0, a1);
    }
    __finally {
        _PrintExit("SetParent(,) -> %p\n", rv);
    };
    return rv;
}

COLORREF __stdcall Mine_SetPixel(HDC a0,
    int a1,
    int a2,
    COLORREF a3)
{
    _PrintEnter("SetPixel(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    COLORREF rv = 0;
    __try {
        rv = Real_SetPixel(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetPixel(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetPixelFormat(HDC a0,
    int a1,
    PIXELFORMATDESCRIPTOR* a2)
{
    _PrintEnter("SetPixelFormat(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetPixelFormat(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetPixelFormat(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetPixelV(HDC a0,
    int a1,
    int a2,
    COLORREF a3)
{
    _PrintEnter("SetPixelV(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetPixelV(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetPixelV(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetPolyFillMode(HDC a0,
    int a1)
{
    _PrintEnter("SetPolyFillMode(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetPolyFillMode(a0, a1);
    }
    __finally {
        _PrintExit("SetPolyFillMode(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetPriorityClass(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("SetPriorityClass(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetPriorityClass(a0, a1);
    }
    __finally {
        _PrintExit("SetPriorityClass(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetProcessAffinityMask(HANDLE a0,
    DWORD_PTR a1)
{
    _PrintEnter("SetProcessAffinityMask(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetProcessAffinityMask(a0, a1);
    }
    __finally {
        _PrintExit("SetProcessAffinityMask(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetProcessShutdownParameters(DWORD a0,
    DWORD a1)
{
    _PrintEnter("SetProcessShutdownParameters(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetProcessShutdownParameters(a0, a1);
    }
    __finally {
        _PrintExit("SetProcessShutdownParameters(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetProcessWindowStation(HWINSTA a0)
{
    _PrintEnter("SetProcessWindowStation(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetProcessWindowStation(a0);
    }
    __finally {
        _PrintExit("SetProcessWindowStation() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetProcessWorkingSetSize(HANDLE a0,
    SIZE_T a1,
    SIZE_T a2)
{
    _PrintEnter("SetProcessWorkingSetSize(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetProcessWorkingSetSize(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetProcessWorkingSetSize(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetPropA(HWND a0,
    LPCSTR a1,
    HANDLE a2)
{
    _PrintEnter("SetPropA(%p,%hs,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetPropA(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetPropA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetPropW(HWND a0,
    LPCWSTR a1,
    HANDLE a2)
{
    _PrintEnter("SetPropW(%p,%ls,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetPropW(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetPropW(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetROP2(HDC a0,
    int a1)
{
    _PrintEnter("SetROP2(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetROP2(a0, a1);
    }
    __finally {
        _PrintExit("SetROP2(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetRect(LPRECT a0,
    int a1,
    int a2,
    int a3,
    int a4)
{
    _PrintEnter("SetRect(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_SetRect(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("SetRect(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetRectEmpty(LPRECT a0)
{
    _PrintEnter("SetRectEmpty(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetRectEmpty(a0);
    }
    __finally {
        _PrintExit("SetRectEmpty() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetRectRgn(HRGN a0,
    int a1,
    int a2,
    int a3,
    int a4)
{
    _PrintEnter("SetRectRgn(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_SetRectRgn(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("SetRectRgn(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetScrollInfo(HWND a0,
    int a1,
    LPCSCROLLINFO a2,
    BOOL a3)
{
    _PrintEnter("SetScrollInfo(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_SetScrollInfo(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetScrollInfo(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetScrollPos(HWND a0,
    int a1,
    int a2,
    BOOL a3)
{
    _PrintEnter("SetScrollPos(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_SetScrollPos(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetScrollPos(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetScrollRange(HWND a0,
    int a1,
    int a2,
    int a3,
    BOOL a4)
{
    _PrintEnter("SetScrollRange(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_SetScrollRange(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("SetScrollRange(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetStdHandle(DWORD a0,
    HANDLE a1)
{
    _PrintEnter("SetStdHandle(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetStdHandle(a0, a1);
    }
    __finally {
        _PrintExit("SetStdHandle(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetStretchBltMode(HDC a0,
    int a1)
{
    _PrintEnter("SetStretchBltMode(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetStretchBltMode(a0, a1);
    }
    __finally {
        _PrintExit("SetStretchBltMode(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetSysColors(int a0,
    INT* a1,
    COLORREF* a2)
{
    _PrintEnter("SetSysColors(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetSysColors(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetSysColors(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetSystemCursor(HCURSOR a0,
    DWORD a1)
{
    _PrintEnter("SetSystemCursor(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetSystemCursor(a0, a1);
    }
    __finally {
        _PrintExit("SetSystemCursor(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_SetSystemPaletteUse(HDC a0,
    UINT a1)
{
    _PrintEnter("SetSystemPaletteUse(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_SetSystemPaletteUse(a0, a1);
    }
    __finally {
        _PrintExit("SetSystemPaletteUse(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetSystemPowerState(BOOL a0,
    BOOL a1)
{
    _PrintEnter("SetSystemPowerState(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetSystemPowerState(a0, a1);
    }
    __finally {
        _PrintExit("SetSystemPowerState(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetSystemTime(SYSTEMTIME* a0)
{
    _PrintEnter("SetSystemTime(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetSystemTime(a0);
    }
    __finally {
        _PrintExit("SetSystemTime() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetSystemTimeAdjustment(DWORD a0,
    BOOL a1)
{
    _PrintEnter("SetSystemTimeAdjustment(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetSystemTimeAdjustment(a0, a1);
    }
    __finally {
        _PrintExit("SetSystemTimeAdjustment(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SetTapeParameters(HANDLE a0,
    DWORD a1,
    LPVOID a2)
{
    _PrintEnter("SetTapeParameters(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_SetTapeParameters(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetTapeParameters(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SetTapePosition(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4,
    BOOL a5)
{
    _PrintEnter("SetTapePosition(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    DWORD rv = 0;
    __try {
        rv = Real_SetTapePosition(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("SetTapePosition(,,,,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_SetTextAlign(HDC a0,
    UINT a1)
{
    _PrintEnter("SetTextAlign(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_SetTextAlign(a0, a1);
    }
    __finally {
        _PrintExit("SetTextAlign(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetTextCharacterExtra(HDC a0,
    int a1)
{
    _PrintEnter("SetTextCharacterExtra(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_SetTextCharacterExtra(a0, a1);
    }
    __finally {
        _PrintExit("SetTextCharacterExtra(,) -> %p\n", rv);
    };
    return rv;
}

COLORREF __stdcall Mine_SetTextColor(HDC a0,
    COLORREF a1)
{
    _PrintEnter("SetTextColor(%p,%p)\n", a0, a1);

    COLORREF rv = 0;
    __try {
        rv = Real_SetTextColor(a0, a1);
    }
    __finally {
        _PrintExit("SetTextColor(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetTextJustification(HDC a0,
    int a1,
    int a2)
{
    _PrintEnter("SetTextJustification(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetTextJustification(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetTextJustification(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD_PTR __stdcall Mine_SetThreadAffinityMask(HANDLE a0,
    DWORD_PTR a1)
{
    _PrintEnter("SetThreadAffinityMask(%p,%p)\n", a0, a1);

    DWORD_PTR rv = 0;
    __try {
        rv = Real_SetThreadAffinityMask(a0, a1);
    }
    __finally {
        _PrintExit("SetThreadAffinityMask(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetThreadContext(HANDLE a0,
    CONTEXT* a1)
{
    _PrintEnter("SetThreadContext(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetThreadContext(a0, a1);
    }
    __finally {
        _PrintExit("SetThreadContext(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetThreadDesktop(HDESK a0)
{
    _PrintEnter("SetThreadDesktop(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetThreadDesktop(a0);
    }
    __finally {
        _PrintExit("SetThreadDesktop() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SetThreadIdealProcessor(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("SetThreadIdealProcessor(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_SetThreadIdealProcessor(a0, a1);
    }
    __finally {
        _PrintExit("SetThreadIdealProcessor(,) -> %p\n", rv);
    };
    return rv;
}

#if(WINVER >= 0x0500)
BOOL __stdcall Mine_SetThreadLocale(LCID a0)
{
    _PrintEnter("SetThreadLocale(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetThreadLocale(a0);
    }
    __finally {
        _PrintExit("SetThreadLocale() -> %p\n", rv);
    };
    return rv;
}
#endif // (WINVER >= 0x0500)

BOOL __stdcall Mine_SetThreadPriority(HANDLE a0,
    int a1)
{
    _PrintEnter("SetThreadPriority(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetThreadPriority(a0, a1);
    }
    __finally {
        _PrintExit("SetThreadPriority(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetThreadPriorityBoost(HANDLE a0,
    BOOL a1)
{
    _PrintEnter("SetThreadPriorityBoost(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetThreadPriorityBoost(a0, a1);
    }
    __finally {
        _PrintExit("SetThreadPriorityBoost(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetTimeZoneInformation(TIME_ZONE_INFORMATION* a0)
{
    _PrintEnter("SetTimeZoneInformation(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SetTimeZoneInformation(a0);
    }
    __finally {
        _PrintExit("SetTimeZoneInformation() -> %p\n", rv);
    };
    return rv;
}

UINT_PTR __stdcall Mine_SetTimer(HWND a0,
    UINT_PTR a1,
    UINT a2,
    TIMERPROC a3)
{
    _PrintEnter("SetTimer(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    UINT_PTR rv = 0;
    __try {
        rv = Real_SetTimer(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetTimer(,,,) -> %p\n", rv);
    };
    return rv;
}

LPTOP_LEVEL_EXCEPTION_FILTER __stdcall Mine_SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER a0)
{
    _PrintEnter("SetUnhandledExceptionFilter(%p)\n", a0);

    LPTOP_LEVEL_EXCEPTION_FILTER rv = 0;
    __try {
        rv = Real_SetUnhandledExceptionFilter(a0);
    }
    __finally {
        _PrintExit("SetUnhandledExceptionFilter() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetUserObjectInformationA(HANDLE a0,
    int a1,
    PVOID a2,
    DWORD a3)
{
    _PrintEnter("SetUserObjectInformationA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetUserObjectInformationA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetUserObjectInformationA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetUserObjectInformationW(HANDLE a0,
    int a1,
    PVOID a2,
    DWORD a3)
{
    _PrintEnter("SetUserObjectInformationW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetUserObjectInformationW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetUserObjectInformationW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetUserObjectSecurity(HANDLE a0,
    PSECURITY_INFORMATION a1,
    PSECURITY_DESCRIPTOR a2)
{
    _PrintEnter("SetUserObjectSecurity(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetUserObjectSecurity(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetUserObjectSecurity(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetViewportExtEx(HDC a0,
    int a1,
    int a2,
    SIZE* a3)
{
    _PrintEnter("SetViewportExtEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetViewportExtEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetViewportExtEx(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetViewportOrgEx(HDC a0,
    int a1,
    int a2,
    POINT* a3)
{
    _PrintEnter("SetViewportOrgEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetViewportOrgEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetViewportOrgEx(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetVolumeLabelA(LPCSTR a0,
    LPCSTR a1)
{
    _PrintEnter("SetVolumeLabelA(%hs,%hs)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetVolumeLabelA(a0, a1);
    }
    __finally {
        _PrintExit("SetVolumeLabelA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetVolumeLabelW(LPCWSTR a0,
    LPCWSTR a1)
{
    _PrintEnter("SetVolumeLabelW(%ls,%ls)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetVolumeLabelW(a0, a1);
    }
    __finally {
        _PrintExit("SetVolumeLabelW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetWaitableTimer(HANDLE a0,
    LARGE_INTEGER* a1,
    LONG a2,
    PTIMERAPCROUTINE a3,
    LPVOID a4,
    BOOL a5)
{
    _PrintEnter("SetWaitableTimer(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_SetWaitableTimer(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("SetWaitableTimer(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HENHMETAFILE __stdcall Mine_SetWinMetaFileBits(UINT a0,
    BYTE* a1,
    HDC a2,
    METAFILEPICT* a3)
{
    _PrintEnter("SetWinMetaFileBits(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HENHMETAFILE rv = 0;
    __try {
        rv = Real_SetWinMetaFileBits(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetWinMetaFileBits(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetWindowContextHelpId(HWND a0,
    DWORD a1)
{
    _PrintEnter("SetWindowContextHelpId(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetWindowContextHelpId(a0, a1);
    }
    __finally {
        _PrintExit("SetWindowContextHelpId(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetWindowExtEx(HDC a0,
    int a1,
    int a2,
    SIZE* a3)
{
    _PrintEnter("SetWindowExtEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetWindowExtEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetWindowExtEx(,,,) -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_SetWindowLongA(HWND a0,
    int a1,
    LONG a2)
{
    _PrintEnter("SetWindowLongA(%p,%p,%p)\n", a0, a1, a2);

    LONG rv = 0;
    __try {
        rv = Real_SetWindowLongA(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetWindowLongA(,,) -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_SetWindowLongW(HWND a0,
    int a1,
    LONG a2)
{
    _PrintEnter("SetWindowLongW(%p,%p,%p)\n", a0, a1, a2);

    LONG rv = 0;
    __try {
        rv = Real_SetWindowLongW(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetWindowLongW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetWindowOrgEx(HDC a0,
    int a1,
    int a2,
    POINT* a3)
{
    _PrintEnter("SetWindowOrgEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetWindowOrgEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetWindowOrgEx(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetWindowPlacement(HWND a0,
    WINDOWPLACEMENT* a1)
{
    _PrintEnter("SetWindowPlacement(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetWindowPlacement(a0, a1);
    }
    __finally {
        _PrintExit("SetWindowPlacement(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetWindowPos(HWND a0,
    HWND a1,
    int a2,
    int a3,
    int a4,
    int a5,
    UINT a6)
{
    _PrintEnter("SetWindowPos(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_SetWindowPos(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("SetWindowPos(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_SetWindowRgn(HWND a0,
    HRGN a1,
    BOOL a2)
{
    _PrintEnter("SetWindowRgn(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_SetWindowRgn(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetWindowRgn(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetWindowTextA(HWND a0,
    LPCSTR a1)
{
    _PrintEnter("SetWindowTextA(%p,%hs)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetWindowTextA(a0, a1);
    }
    __finally {
        _PrintExit("SetWindowTextA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetWindowTextW(HWND a0,
    LPCWSTR a1)
{
    _PrintEnter("SetWindowTextW(%p,%ls)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetWindowTextW(a0, a1);
    }
    __finally {
        _PrintExit("SetWindowTextW(,) -> %p\n", rv);
    };
    return rv;
}

WORD __stdcall Mine_SetWindowWord(HWND a0,
    int a1,
    WORD a2)
{
    _PrintEnter("SetWindowWord(%p,%p,%p)\n", a0, a1, a2);

    WORD rv = 0;
    __try {
        rv = Real_SetWindowWord(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetWindowWord(,,) -> %p\n", rv);
    };
    return rv;
}

HHOOK __stdcall Mine_SetWindowsHookA(int a0,
    HOOKPROC a1)
{
    _PrintEnter("SetWindowsHookA(%p,%p)\n", a0, a1);

    HHOOK rv = 0;
    __try {
        rv = Real_SetWindowsHookA(a0, a1);
    }
    __finally {
        _PrintExit("SetWindowsHookA(,) -> %p\n", rv);
    };
    return rv;
}

HHOOK __stdcall Mine_SetWindowsHookExA(int a0,
    HOOKPROC a1,
    HINSTANCE a2,
    DWORD a3)
{
    _PrintEnter("SetWindowsHookExA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HHOOK rv = 0;
    __try {
        rv = Real_SetWindowsHookExA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetWindowsHookExA(,,,) -> %p\n", rv);
    };
    return rv;
}

HHOOK __stdcall Mine_SetWindowsHookExW(int a0,
    HOOKPROC a1,
    HINSTANCE a2,
    DWORD a3)
{
    _PrintEnter("SetWindowsHookExW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HHOOK rv = 0;
    __try {
        rv = Real_SetWindowsHookExW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SetWindowsHookExW(,,,) -> %p\n", rv);
    };
    return rv;
}

HHOOK __stdcall Mine_SetWindowsHookW(int a0,
    HOOKPROC a1)
{
    _PrintEnter("SetWindowsHookW(%p,%p)\n", a0, a1);

    HHOOK rv = 0;
    __try {
        rv = Real_SetWindowsHookW(a0, a1);
    }
    __finally {
        _PrintExit("SetWindowsHookW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetWorldTransform(HDC a0,
    XFORM* a1)
{
    _PrintEnter("SetWorldTransform(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SetWorldTransform(a0, a1);
    }
    __finally {
        _PrintExit("SetWorldTransform(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SetupComm(HANDLE a0,
    DWORD a1,
    DWORD a2)
{
    _PrintEnter("SetupComm(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SetupComm(a0, a1, a2);
    }
    __finally {
        _PrintExit("SetupComm(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ShowCaret(HWND a0)
{
    _PrintEnter("ShowCaret(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_ShowCaret(a0);
    }
    __finally {
        _PrintExit("ShowCaret() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ShowCursor(BOOL a0)
{
    _PrintEnter("ShowCursor(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_ShowCursor(a0);
    }
    __finally {
        _PrintExit("ShowCursor() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ShowOwnedPopups(HWND a0,
    BOOL a1)
{
    _PrintEnter("ShowOwnedPopups(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ShowOwnedPopups(a0, a1);
    }
    __finally {
        _PrintExit("ShowOwnedPopups(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ShowScrollBar(HWND a0,
    int a1,
    BOOL a2)
{
    _PrintEnter("ShowScrollBar(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_ShowScrollBar(a0, a1, a2);
    }
    __finally {
        _PrintExit("ShowScrollBar(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ShowWindow(HWND a0,
    int a1)
{
    _PrintEnter("ShowWindow(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ShowWindow(a0, a1);
    }
    __finally {
        _PrintExit("ShowWindow(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ShowWindowAsync(HWND a0,
    int a1)
{
    _PrintEnter("ShowWindowAsync(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ShowWindowAsync(a0, a1);
    }
    __finally {
        _PrintExit("ShowWindowAsync(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SignalObjectAndWait(HANDLE a0,
    HANDLE a1,
    DWORD a2,
    BOOL a3)
{
    _PrintEnter("SignalObjectAndWait(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_SignalObjectAndWait(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SignalObjectAndWait(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SizeofResource(HMODULE a0,
    HRSRC a1)
{
    _PrintEnter("SizeofResource(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_SizeofResource(a0, a1);
    }
    __finally {
        _PrintExit("SizeofResource(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SleepEx(DWORD a0,
    BOOL a1)
{
    _PrintEnter("SleepEx(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_SleepEx(a0, a1);
    }
    __finally {
        _PrintExit("SleepEx(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_StartDocA(HDC a0,
    DOCINFOA* a1)
{
    _PrintEnter("StartDocA(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_StartDocA(a0, a1);
    }
    __finally {
        _PrintExit("StartDocA(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_StartDocW(HDC a0,
    DOCINFOW* a1)
{
    _PrintEnter("StartDocW(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_StartDocW(a0, a1);
    }
    __finally {
        _PrintExit("StartDocW(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_StartPage(HDC a0)
{
    _PrintEnter("StartPage(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_StartPage(a0);
    }
    __finally {
        _PrintExit("StartPage() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgCreateDocfile(OLECHAR* a0,
    DWORD a1,
    DWORD a2,
    IStorage** a3)
{
    _PrintEnter("StgCreateDocfile(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_StgCreateDocfile(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("StgCreateDocfile(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgCreateDocfileOnILockBytes(ILockBytes* a0,
    DWORD a1,
    DWORD a2,
    IStorage** a3)
{
    _PrintEnter("StgCreateDocfileOnILockBytes(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_StgCreateDocfileOnILockBytes(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("StgCreateDocfileOnILockBytes(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgCreatePropSetStg(IStorage* a0,
    DWORD a1,
    IPropertySetStorage** a2)
{
    _PrintEnter("StgCreatePropSetStg(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_StgCreatePropSetStg(a0, a1, a2);
    }
    __finally {
        _PrintExit("StgCreatePropSetStg(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgCreatePropStg(IUnknown* a0,
    CONST IID& a1,
    CLSID* a2,
    DWORD a3,
    DWORD a4,
    IPropertyStorage** a5)
{
    _PrintEnter("StgCreatePropStg(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HRESULT rv = 0;
    __try {
        rv = Real_StgCreatePropStg(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("StgCreatePropStg(,,,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HRESULT __stdcall Mine_StgCreateStorageEx(WCHAR* a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    void* a4,
    void* a5,
    CONST IID& a6,
    void** a7)
#else
HRESULT __stdcall Mine_StgCreateStorageEx(WCHAR* a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    STGOPTIONS* a4,
    void* a5,
    CONST IID& a6,
    void** a7)
#endif
{
    _PrintEnter("StgCreateStorageEx(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HRESULT rv = 0;
    __try {
        rv = Real_StgCreateStorageEx(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("StgCreateStorageEx(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgGetIFillLockBytesOnFile(OLECHAR* a0,
    IFillLockBytes** a1)
{
    _PrintEnter("StgGetIFillLockBytesOnFile(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_StgGetIFillLockBytesOnFile(a0, a1);
    }
    __finally {
        _PrintExit("StgGetIFillLockBytesOnFile(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgGetIFillLockBytesOnILockBytes(ILockBytes* a0,
    IFillLockBytes** a1)
{
    _PrintEnter("StgGetIFillLockBytesOnILockBytes(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_StgGetIFillLockBytesOnILockBytes(a0, a1);
    }
    __finally {
        _PrintExit("StgGetIFillLockBytesOnILockBytes(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgIsStorageFile(OLECHAR* a0)
{
    _PrintEnter("StgIsStorageFile(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_StgIsStorageFile(a0);
    }
    __finally {
        _PrintExit("StgIsStorageFile() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgIsStorageILockBytes(ILockBytes* a0)
{
    _PrintEnter("StgIsStorageILockBytes(%p)\n", a0);

    HRESULT rv = 0;
    __try {
        rv = Real_StgIsStorageILockBytes(a0);
    }
    __finally {
        _PrintExit("StgIsStorageILockBytes() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgOpenAsyncDocfileOnIFillLockBytes(IFillLockBytes* a0,
    DWORD a1,
    DWORD a2,
    IStorage** a3)
{
    _PrintEnter("StgOpenAsyncDocfileOnIFillLockBytes(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_StgOpenAsyncDocfileOnIFillLockBytes(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("StgOpenAsyncDocfileOnIFillLockBytes(,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgOpenPropStg(IUnknown* a0,
    CONST IID& a1,
    DWORD a2,
    DWORD a3,
    IPropertyStorage** a4)
{
    _PrintEnter("StgOpenPropStg(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HRESULT rv = 0;
    __try {
        rv = Real_StgOpenPropStg(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("StgOpenPropStg(,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgOpenStorage(OLECHAR* a0,
    IStorage* a1,
    DWORD a2,
    SNB a3,
    DWORD a4,
    IStorage** a5)
{
    _PrintEnter("StgOpenStorage(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HRESULT rv = 0;
    __try {
        rv = Real_StgOpenStorage(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("StgOpenStorage(,,,,,) -> %p\n", rv);
    };
    return rv;
}

#if _MSC_VER < 1300
HRESULT __stdcall Mine_StgOpenStorageEx(WCHAR* a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    void* a4,
    void* a5,
    CONST IID& a6,
    void** a7)
#else
HRESULT __stdcall Mine_StgOpenStorageEx(WCHAR* a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    STGOPTIONS* a4,
    void* a5,
    CONST IID& a6,
    void** a7)
#endif
{
    _PrintEnter("StgOpenStorageEx(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    HRESULT rv = 0;
    __try {
        rv = Real_StgOpenStorageEx(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("StgOpenStorageEx(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgOpenStorageOnILockBytes(ILockBytes* a0,
    IStorage* a1,
    DWORD a2,
    SNB a3,
    DWORD a4,
    IStorage** a5)
{
    _PrintEnter("StgOpenStorageOnILockBytes(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HRESULT rv = 0;
    __try {
        rv = Real_StgOpenStorageOnILockBytes(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("StgOpenStorageOnILockBytes(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StgSetTimes(OLECHAR* a0,
    FILETIME* a1,
    FILETIME* a2,
    FILETIME* a3)
{
    _PrintEnter("StgSetTimes(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    HRESULT rv = 0;
    __try {
        rv = Real_StgSetTimes(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("StgSetTimes(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_StretchBlt(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    HDC a5,
    int a6,
    int a7,
    int a8,
    int a9,
    DWORD a10)
{
    _PrintEnter("StretchBlt(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);

    BOOL rv = 0;
    __try {
        rv = Real_StretchBlt(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }
    __finally {
        _PrintExit("StretchBlt(,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_StretchDIBits(HDC a0,
    int a1,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8,
    void* a9,
    BITMAPINFO* a10,
    UINT a11,
    DWORD a12)
{
    _PrintEnter("StretchDIBits(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);

    int rv = 0;
    __try {
        rv = Real_StretchDIBits(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
    }
    __finally {
        _PrintExit("StretchDIBits(,,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StringFromCLSID(CONST IID& a0,
    LPOLESTR* a1)
{
    _PrintEnter("StringFromCLSID(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_StringFromCLSID(a0, a1);
    }
    __finally {
        _PrintExit("StringFromCLSID(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_StringFromGUID2(CONST GUID& a0,
    LPOLESTR a1,
    int a2)
{
    _PrintEnter("StringFromGUID2(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_StringFromGUID2(a0, a1, a2);
    }
    __finally {
        _PrintExit("StringFromGUID2(,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_StringFromIID(CONST IID& a0,
    LPOLESTR* a1)
{
    _PrintEnter("StringFromIID(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_StringFromIID(a0, a1);
    }
    __finally {
        _PrintExit("StringFromIID(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_StrokeAndFillPath(HDC a0)
{
    _PrintEnter("StrokeAndFillPath(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_StrokeAndFillPath(a0);
    }
    __finally {
        _PrintExit("StrokeAndFillPath() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_StrokePath(HDC a0)
{
    _PrintEnter("StrokePath(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_StrokePath(a0);
    }
    __finally {
        _PrintExit("StrokePath() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SubtractRect(LPRECT a0,
    RECT* a1,
    RECT* a2)
{
    _PrintEnter("SubtractRect(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SubtractRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("SubtractRect(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_SuspendThread(HANDLE a0)
{
    _PrintEnter("SuspendThread(%p)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_SuspendThread(a0);
    }
    __finally {
        _PrintExit("SuspendThread() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SwapBuffers(HDC a0)
{
    _PrintEnter("SwapBuffers(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SwapBuffers(a0);
    }
    __finally {
        _PrintExit("SwapBuffers() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SwapMouseButton(BOOL a0)
{
    _PrintEnter("SwapMouseButton(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SwapMouseButton(a0);
    }
    __finally {
        _PrintExit("SwapMouseButton() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SwitchDesktop(HDESK a0)
{
    _PrintEnter("SwitchDesktop(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_SwitchDesktop(a0);
    }
    __finally {
        _PrintExit("SwitchDesktop() -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_SwitchToFiber(LPVOID a0)
{
    _PrintEnter("SwitchToFiber(%p)\n", a0);

    __try {
        Real_SwitchToFiber(a0);
    }
    __finally {
        _PrintExit("SwitchToFiber() ->\n");
    };
}

BOOL __stdcall Mine_SwitchToThread(void)
{
    _PrintEnter("SwitchToThread()\n");

    BOOL rv = 0;
    __try {
        rv = Real_SwitchToThread();
    }
    __finally {
        _PrintExit("SwitchToThread() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SystemParametersInfoA(UINT a0,
    UINT a1,
    PVOID a2,
    UINT a3)
{
    _PrintEnter("SystemParametersInfoA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SystemParametersInfoA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SystemParametersInfoA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SystemParametersInfoW(UINT a0,
    UINT a1,
    PVOID a2,
    UINT a3)
{
    _PrintEnter("SystemParametersInfoW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SystemParametersInfoW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("SystemParametersInfoW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SystemTimeToFileTime(SYSTEMTIME* a0,
    LPFILETIME a1)
{
    _PrintEnter("SystemTimeToFileTime(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_SystemTimeToFileTime(a0, a1);
    }
    __finally {
        _PrintExit("SystemTimeToFileTime(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_SystemTimeToTzSpecificLocalTime(
#ifdef PIPE_ACCEPT_REMOTE_CLIENTS
    const TIME_ZONE_INFORMATION* a0,
    const SYSTEMTIME* a1,
#else
    LPTIME_ZONE_INFORMATION a0,
    LPSYSTEMTIME a1,
#endif
    LPSYSTEMTIME a2
)
{
    _PrintEnter("SystemTimeToTzSpecificLocalTime(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_SystemTimeToTzSpecificLocalTime(a0, a1, a2);
    }
    __finally {
        _PrintExit("SystemTimeToTzSpecificLocalTime(,,) -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_TabbedTextOutA(HDC a0,
    int a1,
    int a2,
    LPCSTR a3,
    int a4,
    int a5,
    INT* a6,
    int a7)
{
    _PrintEnter("TabbedTextOutA(%p,%p,%p,%hs,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    LONG rv = 0;
    __try {
        rv = Real_TabbedTextOutA(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("TabbedTextOutA(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine_TabbedTextOutW(HDC a0,
    int a1,
    int a2,
    LPCWSTR a3,
    int a4,
    int a5,
    INT* a6,
    int a7)
{
    _PrintEnter("TabbedTextOutW(%p,%p,%p,%ls,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    LONG rv = 0;
    __try {
        rv = Real_TabbedTextOutW(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("TabbedTextOutW(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TerminateProcess(HANDLE a0,
    UINT a1)
{
    _PrintEnter("TerminateProcess(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_TerminateProcess(a0, a1);
    }
    __finally {
        _PrintExit("TerminateProcess(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TerminateThread(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("TerminateThread(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_TerminateThread(a0, a1);
    }
    __finally {
        _PrintExit("TerminateThread(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TextOutA(HDC a0,
    int a1,
    int a2,
    LPCSTR a3,
    int a4)
{
    _PrintEnter("TextOutA(%p,%p,%p,%hs,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_TextOutA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("TextOutA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TextOutW(HDC a0,
    int a1,
    int a2,
    LPCWSTR a3,
    int a4)
{
    _PrintEnter("TextOutW(%p,%p,%p,%ls,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_TextOutW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("TextOutW(,,,,) -> %p\n", rv);
    };
    return rv;
}

WORD __stdcall Mine_TileWindows(HWND a0,
    UINT a1,
    RECT* a2,
    UINT a3,
    struct HWND__** a4)
{
    _PrintEnter("TileWindows(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    WORD rv = 0;
    __try {
        rv = Real_TileWindows(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("TileWindows(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ToAscii(UINT a0,
    UINT a1,
    BYTE* a2,
    LPWORD a3,
    UINT a4)
{
    _PrintEnter("ToAscii(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_ToAscii(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("ToAscii(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ToAsciiEx(UINT a0,
    UINT a1,
    BYTE* a2,
    LPWORD a3,
    UINT a4,
    HKL a5)
{
    _PrintEnter("ToAsciiEx(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_ToAsciiEx(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("ToAsciiEx(,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ToUnicode(UINT a0,
    UINT a1,
    BYTE* a2,
    LPWSTR a3,
    int a4,
    UINT a5)
{
    _PrintEnter("ToUnicode(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_ToUnicode(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("ToUnicode(,,,%ls,,) -> %p\n", a3, rv);
    };
    return rv;
}

int __stdcall Mine_ToUnicodeEx(UINT a0,
    UINT a1,
    BYTE* a2,
    LPWSTR a3,
    int a4,
    UINT a5,
    HKL a6)
{
    _PrintEnter("ToUnicodeEx(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    int rv = 0;
    __try {
        rv = Real_ToUnicodeEx(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("ToUnicodeEx(,,,%ls,,,) -> %p\n", a3, rv);
    };
    return rv;
}

BOOL __stdcall Mine_TrackMouseEvent(TRACKMOUSEEVENT* a0)
{
    _PrintEnter("TrackMouseEvent(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_TrackMouseEvent(a0);
    }
    __finally {
        _PrintExit("TrackMouseEvent() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TrackPopupMenu(HMENU a0,
    UINT a1,
    int a2,
    int a3,
    int a4,
    HWND a5,
    RECT* a6)
{
    _PrintEnter("TrackPopupMenu(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_TrackPopupMenu(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("TrackPopupMenu(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TrackPopupMenuEx(HMENU a0,
    UINT a1,
    int a2,
    int a3,
    HWND a4,
    LPTPMPARAMS a5)
{
    _PrintEnter("TrackPopupMenuEx(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_TrackPopupMenuEx(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("TrackPopupMenuEx(,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TransactNamedPipe(HANDLE a0,
    LPVOID a1,
    DWORD a2,
    LPVOID a3,
    DWORD a4,
    LPDWORD a5,
    LPOVERLAPPED a6)
{
    _PrintEnter("TransactNamedPipe(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    BOOL rv = 0;
    __try {
        rv = Real_TransactNamedPipe(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("TransactNamedPipe(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_TranslateAcceleratorA(HWND a0,
    HACCEL a1,
    LPMSG a2)
{
    _PrintEnter("TranslateAcceleratorA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_TranslateAcceleratorA(a0, a1, a2);
    }
    __finally {
        _PrintExit("TranslateAcceleratorA(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_TranslateAcceleratorW(HWND a0,
    HACCEL a1,
    LPMSG a2)
{
    _PrintEnter("TranslateAcceleratorW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_TranslateAcceleratorW(a0, a1, a2);
    }
    __finally {
        _PrintExit("TranslateAcceleratorW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TranslateCharsetInfo(DWORD* a0,
    CHARSETINFO* a1,
    DWORD a2)
{
    _PrintEnter("TranslateCharsetInfo(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_TranslateCharsetInfo(a0, a1, a2);
    }
    __finally {
        _PrintExit("TranslateCharsetInfo(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TranslateMDISysAccel(HWND a0,
    LPMSG a1)
{
    _PrintEnter("TranslateMDISysAccel(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_TranslateMDISysAccel(a0, a1);
    }
    __finally {
        _PrintExit("TranslateMDISysAccel(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TranslateMessage(MSG* a0)
{
    _PrintEnter("TranslateMessage(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_TranslateMessage(a0);
    }
    __finally {
        _PrintExit("TranslateMessage() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_TransmitCommChar(HANDLE a0,
    char a1)
{
    _PrintEnter("TransmitCommChar(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_TransmitCommChar(a0, a1);
    }
    __finally {
        _PrintExit("TransmitCommChar(,) -> %p\n", rv);
    };
    return rv;
}

#if DETOUR_TryEnterCriticalSection_EVEN_IF_IT_EXERCISES_A_BUG_IN_RtlLookupFunctionTable
BOOL __stdcall Mine_TryEnterCriticalSection(LPCRITICAL_SECTION a0)
{
    _PrintEnter("TryEnterCriticalSection(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_TryEnterCriticalSection(a0);
    }
    __finally {
        _PrintExit("TryEnterCriticalSection() -> %p\n", rv);
    };
    return rv;
}
#endif

BOOL __stdcall Mine_UnhookWindowsHook(int a0,
    HOOKPROC a1)
{
    _PrintEnter("UnhookWindowsHook(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_UnhookWindowsHook(a0, a1);
    }
    __finally {
        _PrintExit("UnhookWindowsHook(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnhookWindowsHookEx(HHOOK a0)
{
    _PrintEnter("UnhookWindowsHookEx(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_UnhookWindowsHookEx(a0);
    }
    __finally {
        _PrintExit("UnhookWindowsHookEx() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnionRect(LPRECT a0,
    RECT* a1,
    RECT* a2)
{
    _PrintEnter("UnionRect(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_UnionRect(a0, a1, a2);
    }
    __finally {
        _PrintExit("UnionRect(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnloadKeyboardLayout(HKL a0)
{
    _PrintEnter("UnloadKeyboardLayout(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_UnloadKeyboardLayout(a0);
    }
    __finally {
        _PrintExit("UnloadKeyboardLayout() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnlockFile(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    DWORD a4)
{
    _PrintEnter("UnlockFile(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_UnlockFile(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("UnlockFile(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnlockFileEx(HANDLE a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    LPOVERLAPPED a4)
{
    _PrintEnter("UnlockFileEx(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_UnlockFileEx(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("UnlockFileEx(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnmapViewOfFile(LPCVOID a0)
{
    _PrintEnter("UnmapViewOfFile(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_UnmapViewOfFile(a0);
    }
    __finally {
        _PrintExit("UnmapViewOfFile() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnpackDDElParam(UINT a0,
    LPARAM a1,
    PUINT_PTR a2,
    PUINT_PTR a3)
{
    _PrintEnter("UnpackDDElParam(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_UnpackDDElParam(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("UnpackDDElParam(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnrealizeObject(HGDIOBJ a0)
{
    _PrintEnter("UnrealizeObject(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_UnrealizeObject(a0);
    }
    __finally {
        _PrintExit("UnrealizeObject() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnregisterClassA(LPCSTR a0,
    HINSTANCE a1)
{
    _PrintEnter("UnregisterClassA(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_UnregisterClassA(a0, a1);
    }
    __finally {
        _PrintExit("UnregisterClassA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnregisterClassW(LPCWSTR a0,
    HINSTANCE a1)
{
    _PrintEnter("UnregisterClassW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_UnregisterClassW(a0, a1);
    }
    __finally {
        _PrintExit("UnregisterClassW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UnregisterHotKey(HWND a0,
    int a1)
{
    _PrintEnter("UnregisterHotKey(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_UnregisterHotKey(a0, a1);
    }
    __finally {
        _PrintExit("UnregisterHotKey(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UpdateColors(HDC a0)
{
    _PrintEnter("UpdateColors(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_UpdateColors(a0);
    }
    __finally {
        _PrintExit("UpdateColors() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UpdateResourceA(HANDLE a0,
    LPCSTR a1,
    LPCSTR a2,
    WORD a3,
    LPVOID a4,
    DWORD a5)
{
    _PrintEnter("UpdateResourceA(%p,%hs,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_UpdateResourceA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("UpdateResourceA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UpdateResourceW(HANDLE a0,
    LPCWSTR a1,
    LPCWSTR a2,
    WORD a3,
    LPVOID a4,
    DWORD a5)
{
    _PrintEnter("UpdateResourceW(%p,%ls,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_UpdateResourceW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("UpdateResourceW(,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_UpdateWindow(HWND a0)
{
    _PrintEnter("UpdateWindow(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_UpdateWindow(a0);
    }
    __finally {
        _PrintExit("UpdateWindow() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ValidateRect(HWND a0,
    RECT* a1)
{
    _PrintEnter("ValidateRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ValidateRect(a0, a1);
    }
    __finally {
        _PrintExit("ValidateRect(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_ValidateRgn(HWND a0,
    HRGN a1)
{
    _PrintEnter("ValidateRgn(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_ValidateRgn(a0, a1);
    }
    __finally {
        _PrintExit("ValidateRgn(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_VerLanguageNameA(DWORD a0,
    LPSTR a1,
    DWORD a2)
{
    _PrintEnter("VerLanguageNameA(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_VerLanguageNameA(a0, a1, a2);
    }
    __finally {
        _PrintExit("VerLanguageNameA(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_VerLanguageNameW(DWORD a0,
    LPWSTR a1,
    DWORD a2)
{
    _PrintEnter("VerLanguageNameW(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_VerLanguageNameW(a0, a1, a2);
    }
    __finally {
        _PrintExit("VerLanguageNameW(,,) -> %p\n", rv);
    };
    return rv;
}

LPVOID __stdcall Mine_VirtualAllocEx(HANDLE a0,
    LPVOID a1,
    SIZE_T a2,
    DWORD a3,
    DWORD a4)
{
    _PrintEnter("VirtualAllocEx(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    LPVOID rv = 0;
    __try {
        rv = Real_VirtualAllocEx(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("VirtualAllocEx(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_VirtualFreeEx(HANDLE a0,
    LPVOID a1,
    SIZE_T a2,
    DWORD a3)
{
    _PrintEnter("VirtualFreeEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_VirtualFreeEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("VirtualFreeEx(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_VirtualProtectEx(HANDLE a0,
    LPVOID a1,
    SIZE_T a2,
    DWORD a3,
    PDWORD a4)
{
    _PrintEnter("VirtualProtectEx(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_VirtualProtectEx(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("VirtualProtectEx(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD_PTR __stdcall Mine_VirtualQueryEx(HANDLE a0,
    LPCVOID a1,
    PMEMORY_BASIC_INFORMATION a2,
    DWORD_PTR a3)
{
    _PrintEnter("VirtualQueryEx(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD_PTR rv = 0;
    __try {
        rv = Real_VirtualQueryEx(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("VirtualQueryEx(,,,) -> %p\n", rv);
    };
    return rv;
}

SHORT __stdcall Mine_VkKeyScanA(CHAR a0)
{
    _PrintEnter("VkKeyScanA(%p)\n", a0);

    SHORT rv = 0;
    __try {
        rv = Real_VkKeyScanA(a0);
    }
    __finally {
        _PrintExit("VkKeyScanA() -> %p\n", rv);
    };
    return rv;
}

SHORT __stdcall Mine_VkKeyScanExA(CHAR a0,
    HKL a1)
{
    _PrintEnter("VkKeyScanExA(%p,%p)\n", a0, a1);

    SHORT rv = 0;
    __try {
        rv = Real_VkKeyScanExA(a0, a1);
    }
    __finally {
        _PrintExit("VkKeyScanExA(,) -> %p\n", rv);
    };
    return rv;
}

SHORT __stdcall Mine_VkKeyScanExW(WCHAR a0,
    HKL a1)
{
    _PrintEnter("VkKeyScanExW(%p,%p)\n", a0, a1);

    SHORT rv = 0;
    __try {
        rv = Real_VkKeyScanExW(a0, a1);
    }
    __finally {
        _PrintExit("VkKeyScanExW(,) -> %p\n", rv);
    };
    return rv;
}

SHORT __stdcall Mine_VkKeyScanW(WCHAR a0)
{
    _PrintEnter("VkKeyScanW(%p)\n", a0);

    SHORT rv = 0;
    __try {
        rv = Real_VkKeyScanW(a0);
    }
    __finally {
        _PrintExit("VkKeyScanW() -> %p\n", rv);
    };
    return rv;
}

SOCKET __stdcall Mine_WSAAccept(SOCKET a0,
    sockaddr* a1,
    LPINT a2,
    LPCONDITIONPROC a3,
    DWORD_PTR a4)
{
    _PrintEnter("WSAAccept(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    SOCKET rv = 0;
    __try {
        rv = Real_WSAAccept(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAAccept(,,,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAAddressToStringA(LPSOCKADDR a0,
    DWORD a1,
    LPWSAPROTOCOL_INFOA a2,
    LPSTR a3,
    LPDWORD a4)
{
    _PrintEnter("WSAAddressToStringA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    INT rv = 0;
    __try {
        rv = Real_WSAAddressToStringA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAAddressToStringA(,,,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAAddressToStringW(LPSOCKADDR a0,
    DWORD a1,
    LPWSAPROTOCOL_INFOW a2,
    LPWSTR a3,
    LPDWORD a4)
{
    _PrintEnter("WSAAddressToStringW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    INT rv = 0;
    __try {
        rv = Real_WSAAddressToStringW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAAddressToStringW(,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_WSAAsyncGetHostByAddr(HWND a0,
    u_int a1,
    char* a2,
    int a3,
    int a4,
    char* a5,
    int a6)
{
    _PrintEnter("WSAAsyncGetHostByAddr(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HANDLE rv = 0;
    __try {
        rv = Real_WSAAsyncGetHostByAddr(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("WSAAsyncGetHostByAddr(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_WSAAsyncGetHostByName(HWND a0,
    u_int a1,
    char* a2,
    char* a3,
    int a4)
{
    _PrintEnter("WSAAsyncGetHostByName(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HANDLE rv = 0;
    __try {
        rv = Real_WSAAsyncGetHostByName(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAAsyncGetHostByName(,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_WSAAsyncGetProtoByName(HWND a0,
    u_int a1,
    char* a2,
    char* a3,
    int a4)
{
    _PrintEnter("WSAAsyncGetProtoByName(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HANDLE rv = 0;
    __try {
        rv = Real_WSAAsyncGetProtoByName(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAAsyncGetProtoByName(,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_WSAAsyncGetProtoByNumber(HWND a0,
    u_int a1,
    int a2,
    char* a3,
    int a4)
{
    _PrintEnter("WSAAsyncGetProtoByNumber(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    HANDLE rv = 0;
    __try {
        rv = Real_WSAAsyncGetProtoByNumber(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAAsyncGetProtoByNumber(,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_WSAAsyncGetServByName(HWND a0,
    u_int a1,
    char* a2,
    char* a3,
    char* a4,
    int a5)
{
    _PrintEnter("WSAAsyncGetServByName(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_WSAAsyncGetServByName(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("WSAAsyncGetServByName(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_WSAAsyncGetServByPort(HWND a0,
    u_int a1,
    int a2,
    char* a3,
    char* a4,
    int a5)
{
    _PrintEnter("WSAAsyncGetServByPort(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_WSAAsyncGetServByPort(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("WSAAsyncGetServByPort(,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAAsyncSelect(SOCKET a0,
    HWND a1,
    u_int a2,
    long a3)
{
    _PrintEnter("WSAAsyncSelect(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_WSAAsyncSelect(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WSAAsyncSelect(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSACancelAsyncRequest(HANDLE a0)
{
    _PrintEnter("WSACancelAsyncRequest(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_WSACancelAsyncRequest(a0);
    }
    __finally {
        _PrintExit("WSACancelAsyncRequest() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSACancelBlockingCall(void)
{
    _PrintEnter("WSACancelBlockingCall()\n");

    int rv = 0;
    __try {
        rv = Real_WSACancelBlockingCall();
    }
    __finally {
        _PrintExit("WSACancelBlockingCall() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSACleanup(void)
{
    _PrintEnter("WSACleanup()\n");

    int rv = 0;
    __try {
        rv = Real_WSACleanup();
    }
    __finally {
        _PrintExit("WSACleanup() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WSACloseEvent(HANDLE a0)
{
    _PrintEnter("WSACloseEvent(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_WSACloseEvent(a0);
    }
    __finally {
        _PrintExit("WSACloseEvent() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAConnect(SOCKET a0,
    sockaddr* a1,
    int a2,
    LPWSABUF a3,
    LPWSABUF a4,
    LPQOS a5,
    LPQOS a6)
{
    _PrintEnter("WSAConnect(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    int rv = 0;
    __try {
        rv = Real_WSAConnect(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("WSAConnect(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE __stdcall Mine_WSACreateEvent(void)
{
    _PrintEnter("WSACreateEvent()\n");

    HANDLE rv = 0;
    __try {
        rv = Real_WSACreateEvent();
    }
    __finally {
        _PrintExit("WSACreateEvent() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSADuplicateSocketA(SOCKET a0,
    DWORD a1,
    LPWSAPROTOCOL_INFOA a2)
{
    _PrintEnter("WSADuplicateSocketA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSADuplicateSocketA(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSADuplicateSocketA(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSADuplicateSocketW(SOCKET a0,
    DWORD a1,
    LPWSAPROTOCOL_INFOW a2)
{
    _PrintEnter("WSADuplicateSocketW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSADuplicateSocketW(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSADuplicateSocketW(,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAEnumNameSpaceProvidersA(LPDWORD a0,
    LPWSANAMESPACE_INFOA a1)
{
    _PrintEnter("WSAEnumNameSpaceProvidersA(%p,%p)\n", a0, a1);

    INT rv = 0;
    __try {
        rv = Real_WSAEnumNameSpaceProvidersA(a0, a1);
    }
    __finally {
        _PrintExit("WSAEnumNameSpaceProvidersA(,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAEnumNameSpaceProvidersW(LPDWORD a0,
    LPWSANAMESPACE_INFOW a1)
{
    _PrintEnter("WSAEnumNameSpaceProvidersW(%p,%p)\n", a0, a1);

    INT rv = 0;
    __try {
        rv = Real_WSAEnumNameSpaceProvidersW(a0, a1);
    }
    __finally {
        _PrintExit("WSAEnumNameSpaceProvidersW(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAEnumNetworkEvents(SOCKET a0,
    HANDLE a1,
    LPWSANETWORKEVENTS a2)
{
    _PrintEnter("WSAEnumNetworkEvents(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSAEnumNetworkEvents(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAEnumNetworkEvents(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAEnumProtocolsA(LPINT a0,
    LPWSAPROTOCOL_INFOA a1,
    LPDWORD a2)
{
    _PrintEnter("WSAEnumProtocolsA(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSAEnumProtocolsA(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAEnumProtocolsA(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAEnumProtocolsW(LPINT a0,
    LPWSAPROTOCOL_INFOW a1,
    LPDWORD a2)
{
    _PrintEnter("WSAEnumProtocolsW(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSAEnumProtocolsW(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAEnumProtocolsW(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAEventSelect(SOCKET a0,
    HANDLE a1,
    long a2)
{
    _PrintEnter("WSAEventSelect(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSAEventSelect(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAEventSelect(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WSAGetOverlappedResult(SOCKET a0,
    LPWSAOVERLAPPED a1,
    LPDWORD a2,
    BOOL a3,
    LPDWORD a4)
{
    _PrintEnter("WSAGetOverlappedResult(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WSAGetOverlappedResult(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAGetOverlappedResult(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WSAGetQOSByName(SOCKET a0,
    LPWSABUF a1,
    LPQOS a2)
{
    _PrintEnter("WSAGetQOSByName(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_WSAGetQOSByName(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAGetQOSByName(,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAGetServiceClassInfoA(LPGUID a0,
    LPGUID a1,
    LPDWORD a2,
    LPWSASERVICECLASSINFOA a3)
{
    _PrintEnter("WSAGetServiceClassInfoA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    INT rv = 0;
    __try {
        rv = Real_WSAGetServiceClassInfoA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WSAGetServiceClassInfoA(,,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAGetServiceClassInfoW(LPGUID a0,
    LPGUID a1,
    LPDWORD a2,
    LPWSASERVICECLASSINFOW a3)
{
    _PrintEnter("WSAGetServiceClassInfoW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    INT rv = 0;
    __try {
        rv = Real_WSAGetServiceClassInfoW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WSAGetServiceClassInfoW(,,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAGetServiceClassNameByClassIdA(LPGUID a0,
    LPSTR a1,
    LPDWORD a2)
{
    _PrintEnter("WSAGetServiceClassNameByClassIdA(%p,%p,%p)\n", a0, a1, a2);

    INT rv = 0;
    __try {
        rv = Real_WSAGetServiceClassNameByClassIdA(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAGetServiceClassNameByClassIdA(,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAGetServiceClassNameByClassIdW(LPGUID a0,
    LPWSTR a1,
    LPDWORD a2)
{
    _PrintEnter("WSAGetServiceClassNameByClassIdW(%p,%p,%p)\n", a0, a1, a2);

    INT rv = 0;
    __try {
        rv = Real_WSAGetServiceClassNameByClassIdW(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAGetServiceClassNameByClassIdW(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAHtonl(SOCKET a0,
    u_long a1,
    u_long* a2)
{
    _PrintEnter("WSAHtonl(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSAHtonl(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAHtonl(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAHtons(SOCKET a0,
    u_short a1,
    u_short* a2)
{
    _PrintEnter("WSAHtons(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSAHtons(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAHtons(,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAInstallServiceClassA(LPWSASERVICECLASSINFOA a0)
{
    _PrintEnter("WSAInstallServiceClassA(%p)\n", a0);

    INT rv = 0;
    __try {
        rv = Real_WSAInstallServiceClassA(a0);
    }
    __finally {
        _PrintExit("WSAInstallServiceClassA() -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAInstallServiceClassW(LPWSASERVICECLASSINFOW a0)
{
    _PrintEnter("WSAInstallServiceClassW(%p)\n", a0);

    INT rv = 0;
    __try {
        rv = Real_WSAInstallServiceClassW(a0);
    }
    __finally {
        _PrintExit("WSAInstallServiceClassW() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAIoctl(SOCKET a0,
    DWORD a1,
    LPVOID a2,
    DWORD a3,
    LPVOID a4,
    DWORD a5,
    LPDWORD a6,
    LPWSAOVERLAPPED a7,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a8)
{
    _PrintEnter("WSAIoctl(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    int rv = 0;
    __try {
        rv = Real_WSAIoctl(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("WSAIoctl(,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WSAIsBlocking(void)
{
    _PrintEnter("WSAIsBlocking()\n");

    BOOL rv = 0;
    __try {
        rv = Real_WSAIsBlocking();
    }
    __finally {
        _PrintExit("WSAIsBlocking() -> %p\n", rv);
    };
    return rv;
}

SOCKET __stdcall Mine_WSAJoinLeaf(SOCKET a0,
    sockaddr* a1,
    int a2,
    LPWSABUF a3,
    LPWSABUF a4,
    LPQOS a5,
    LPQOS a6,
    DWORD a7)
{
    _PrintEnter("WSAJoinLeaf(%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    SOCKET rv = 0;
    __try {
        rv = Real_WSAJoinLeaf(a0, a1, a2, a3, a4, a5, a6, a7);
    }
    __finally {
        _PrintExit("WSAJoinLeaf(,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSALookupServiceBeginA(LPWSAQUERYSETA a0,
    DWORD a1,
    LPHANDLE a2)
{
    _PrintEnter("WSALookupServiceBeginA(%p,%p,%p)\n", a0, a1, a2);

    INT rv = 0;
    __try {
        rv = Real_WSALookupServiceBeginA(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSALookupServiceBeginA(,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSALookupServiceBeginW(LPWSAQUERYSETW a0,
    DWORD a1,
    LPHANDLE a2)
{
    _PrintEnter("WSALookupServiceBeginW(%p,%p,%p)\n", a0, a1, a2);

    INT rv = 0;
    __try {
        rv = Real_WSALookupServiceBeginW(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSALookupServiceBeginW(,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSALookupServiceEnd(HANDLE a0)
{
    _PrintEnter("WSALookupServiceEnd(%p)\n", a0);

    INT rv = 0;
    __try {
        rv = Real_WSALookupServiceEnd(a0);
    }
    __finally {
        _PrintExit("WSALookupServiceEnd() -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSALookupServiceNextA(HANDLE a0,
    DWORD a1,
    LPDWORD a2,
    LPWSAQUERYSETA a3)
{
    _PrintEnter("WSALookupServiceNextA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    INT rv = 0;
    __try {
        rv = Real_WSALookupServiceNextA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WSALookupServiceNextA(,,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSALookupServiceNextW(HANDLE a0,
    DWORD a1,
    LPDWORD a2,
    LPWSAQUERYSETW a3)
{
    _PrintEnter("WSALookupServiceNextW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    INT rv = 0;
    __try {
        rv = Real_WSALookupServiceNextW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WSALookupServiceNextW(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSANtohl(SOCKET a0,
    u_long a1,
    u_long* a2)
{
    _PrintEnter("WSANtohl(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSANtohl(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSANtohl(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSANtohs(SOCKET a0,
    u_short a1,
    u_short* a2)
{
    _PrintEnter("WSANtohs(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_WSANtohs(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSANtohs(,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAProviderConfigChange(LPHANDLE a0,
    LPWSAOVERLAPPED a1,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a2)
{
    _PrintEnter("WSAProviderConfigChange(%p,%p,%p)\n", a0, a1, a2);

    INT rv = 0;
    __try {
        rv = Real_WSAProviderConfigChange(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSAProviderConfigChange(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSARecv(SOCKET a0,
    LPWSABUF a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    LPWSAOVERLAPPED a5,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a6)
{
    _PrintEnter("WSARecv(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    int rv = 0;
    __try {
        rv = Real_WSARecv(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("WSARecv(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSARecvDisconnect(SOCKET a0,
    LPWSABUF a1)
{
    _PrintEnter("WSARecvDisconnect(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_WSARecvDisconnect(a0, a1);
    }
    __finally {
        _PrintExit("WSARecvDisconnect(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSARecvFrom(SOCKET a0,
    LPWSABUF a1,
    DWORD a2,
    LPDWORD a3,
    LPDWORD a4,
    sockaddr* a5,
    LPINT a6,
    LPWSAOVERLAPPED a7,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a8)
{
    _PrintEnter("WSARecvFrom(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    int rv = 0;
    __try {
        rv = Real_WSARecvFrom(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("WSARecvFrom(,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSARemoveServiceClass(LPGUID a0)
{
    _PrintEnter("WSARemoveServiceClass(%p)\n", a0);

    INT rv = 0;
    __try {
        rv = Real_WSARemoveServiceClass(a0);
    }
    __finally {
        _PrintExit("WSARemoveServiceClass() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WSAResetEvent(HANDLE a0)
{
    _PrintEnter("WSAResetEvent(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_WSAResetEvent(a0);
    }
    __finally {
        _PrintExit("WSAResetEvent() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSASend(SOCKET a0,
    LPWSABUF a1,
    DWORD a2,
    LPDWORD a3,
    DWORD a4,
    LPWSAOVERLAPPED a5,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a6)
{
    _PrintEnter("WSASend(%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    int rv = 0;
    __try {
        rv = Real_WSASend(a0, a1, a2, a3, a4, a5, a6);
    }
    __finally {
        _PrintExit("WSASend(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSASendDisconnect(SOCKET a0,
    LPWSABUF a1)
{
    _PrintEnter("WSASendDisconnect(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_WSASendDisconnect(a0, a1);
    }
    __finally {
        _PrintExit("WSASendDisconnect(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSASendTo(SOCKET a0,
    LPWSABUF a1,
    DWORD a2,
    LPDWORD a3,
    DWORD a4,
    sockaddr* a5,
    int a6,
    LPWSAOVERLAPPED a7,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE a8)
{
    _PrintEnter("WSASendTo(%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    int rv = 0;
    __try {
        rv = Real_WSASendTo(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
    __finally {
        _PrintExit("WSASendTo(,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

FARPROC __stdcall Mine_WSASetBlockingHook(FARPROC a0)
{
    _PrintEnter("WSASetBlockingHook(%p)\n", a0);

    FARPROC rv = 0;
    __try {
        rv = Real_WSASetBlockingHook(a0);
    }
    __finally {
        _PrintExit("WSASetBlockingHook() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WSASetEvent(HANDLE a0)
{
    _PrintEnter("WSASetEvent(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_WSASetEvent(a0);
    }
    __finally {
        _PrintExit("WSASetEvent() -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSASetServiceA(LPWSAQUERYSETA a0,
    WSAESETSERVICEOP a1,
    DWORD a2)
{
    _PrintEnter("WSASetServiceA(%p,%p,%p)\n", a0, a1, a2);

    INT rv = 0;
    __try {
        rv = Real_WSASetServiceA(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSASetServiceA(,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSASetServiceW(LPWSAQUERYSETW a0,
    WSAESETSERVICEOP a1,
    DWORD a2)
{
    _PrintEnter("WSASetServiceW(%p,%p,%p)\n", a0, a1, a2);

    INT rv = 0;
    __try {
        rv = Real_WSASetServiceW(a0, a1, a2);
    }
    __finally {
        _PrintExit("WSASetServiceW(,,) -> %p\n", rv);
    };
    return rv;
}

SOCKET __stdcall Mine_WSASocketA(int a0,
    int a1,
    int a2,
    LPWSAPROTOCOL_INFOA a3,
    GROUP a4,
    DWORD a5)
{
    _PrintEnter("WSASocketA(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    SOCKET rv = 0;
    __try {
        rv = Real_WSASocketA(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("WSASocketA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

SOCKET __stdcall Mine_WSASocketW(int a0,
    int a1,
    int a2,
    LPWSAPROTOCOL_INFOW a3,
    GROUP a4,
    DWORD a5)
{
    _PrintEnter("WSASocketW(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    SOCKET rv = 0;
    __try {
        rv = Real_WSASocketW(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("WSASocketW(,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAStartup(WORD a0,
    LPWSADATA a1)
{
    _PrintEnter("WSAStartup(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_WSAStartup(a0, a1);
    }
    __finally {
        _PrintExit("WSAStartup(,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAStringToAddressA(LPSTR a0,
    INT a1,
    LPWSAPROTOCOL_INFOA a2,
    LPSOCKADDR a3,
    LPINT a4)
{
    _PrintEnter("WSAStringToAddressA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    INT rv = 0;
    __try {
        rv = Real_WSAStringToAddressA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAStringToAddressA(,,,,) -> %p\n", rv);
    };
    return rv;
}

INT __stdcall Mine_WSAStringToAddressW(LPWSTR a0,
    INT a1,
    LPWSAPROTOCOL_INFOW a2,
    LPSOCKADDR a3,
    LPINT a4)
{
    _PrintEnter("WSAStringToAddressW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    INT rv = 0;
    __try {
        rv = Real_WSAStringToAddressW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAStringToAddressW(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_WSAUnhookBlockingHook(void)
{
    _PrintEnter("WSAUnhookBlockingHook()\n");

    int rv = 0;
    __try {
        rv = Real_WSAUnhookBlockingHook();
    }
    __finally {
        _PrintExit("WSAUnhookBlockingHook() -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_WSAWaitForMultipleEvents(DWORD a0,
    void** a1,
    BOOL a2,
    DWORD a3,
    BOOL a4)
{
    _PrintEnter("WSAWaitForMultipleEvents(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_WSAWaitForMultipleEvents(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WSAWaitForMultipleEvents(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WaitCommEvent(HANDLE a0,
    LPDWORD a1,
    LPOVERLAPPED a2)
{
    _PrintEnter("WaitCommEvent(%p,%p,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_WaitCommEvent(a0, a1, a2);
    }
    __finally {
        _PrintExit("WaitCommEvent(,,) -> %p\n", rv);
    };
    return rv;
}

#if !defined(DETOURS_ARM)
BOOL __stdcall Mine_WaitForDebugEvent(LPDEBUG_EVENT a0,
    DWORD a1)
{
    _PrintEnter("WaitForDebugEvent(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_WaitForDebugEvent(a0, a1);
    }
    __finally {
        if (rv) {
            _PrintExit("WaitForDebugEvent(%d,) -> %p\n", a0->dwDebugEventCode, rv);
        }
        else {
            _PrintExit("WaitForDebugEvent(,) -> %p\n", rv);
        }
    };
    return rv;
}
#endif // !DETOURS_ARM

DWORD __stdcall Mine_WaitForInputIdle(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("WaitForInputIdle(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_WaitForInputIdle(a0, a1);
    }
    __finally {
        _PrintExit("WaitForInputIdle(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_WaitForMultipleObjects(DWORD a0,
    void** a1,
    BOOL a2,
    DWORD a3)
{
    _PrintEnter("WaitForMultipleObjects(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_WaitForMultipleObjects(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WaitForMultipleObjects(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_WaitForMultipleObjectsEx(DWORD a0,
    void** a1,
    BOOL a2,
    DWORD a3,
    BOOL a4)
{
    _PrintEnter("WaitForMultipleObjectsEx(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    DWORD rv = 0;
    __try {
        rv = Real_WaitForMultipleObjectsEx(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WaitForMultipleObjectsEx(,,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_WaitForSingleObject(HANDLE a0,
    DWORD a1)
{
    _PrintEnter("WaitForSingleObject(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_WaitForSingleObject(a0, a1);
    }
    __finally {
        _PrintExit("WaitForSingleObject(,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_WaitForSingleObjectEx(HANDLE a0,
    DWORD a1,
    BOOL a2)
{
    _PrintEnter("WaitForSingleObjectEx(%p,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_WaitForSingleObjectEx(a0, a1, a2);
    }
    __finally {
        _PrintExit("WaitForSingleObjectEx(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WaitMessage(void)
{
    _PrintEnter("WaitMessage()\n");

    BOOL rv = 0;
    __try {
        rv = Real_WaitMessage();
    }
    __finally {
        _PrintExit("WaitMessage() -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WaitNamedPipeA(LPCSTR a0,
    DWORD a1)
{
    _PrintEnter("WaitNamedPipeA(%hs,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_WaitNamedPipeA(a0, a1);
    }
    __finally {
        _PrintExit("WaitNamedPipeA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WaitNamedPipeW(LPCWSTR a0,
    DWORD a1)
{
    _PrintEnter("WaitNamedPipeW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_WaitNamedPipeW(a0, a1);
    }
    __finally {
        _PrintExit("WaitNamedPipeW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WidenPath(HDC a0)
{
    _PrintEnter("WidenPath(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_WidenPath(a0);
    }
    __finally {
        _PrintExit("WidenPath() -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine_WinExec(LPCSTR a0,
    UINT a1)
{
    _PrintEnter("WinExec(%hs,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_WinExec(a0, a1);
    }
    __finally {
        _PrintExit("WinExec(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WinHelpA(HWND a0,
    LPCSTR a1,
    UINT a2,
    ULONG_PTR a3)
{
    _PrintEnter("WinHelpA(%p,%hs,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_WinHelpA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WinHelpA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WinHelpW(HWND a0,
    LPCWSTR a1,
    UINT a2,
    ULONG_PTR a3)
{
    _PrintEnter("WinHelpW(%p,%ls,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_WinHelpW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WinHelpW(,,,) -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_WindowFromDC(HDC a0)
{
    _PrintEnter("WindowFromDC(%p)\n", a0);

    HWND rv = 0;
    __try {
        rv = Real_WindowFromDC(a0);
    }
    __finally {
        _PrintExit("WindowFromDC() -> %p\n", rv);
    };
    return rv;
}

HWND __stdcall Mine_WindowFromPoint(POINT a0)
{
    _PrintEnter("WindowFromPoint(%p)\n", a0);

    HWND rv = 0;
    __try {
        rv = Real_WindowFromPoint(a0);
    }
    __finally {
        _PrintExit("WindowFromPoint() -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_WriteClassStg(LPSTORAGE a0,
    CONST IID& a1)
{
    _PrintEnter("WriteClassStg(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_WriteClassStg(a0, a1);
    }
    __finally {
        _PrintExit("WriteClassStg(,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_WriteClassStm(LPSTREAM a0,
    CONST IID& a1)
{
    _PrintEnter("WriteClassStm(%p,%p)\n", a0, a1);

    HRESULT rv = 0;
    __try {
        rv = Real_WriteClassStm(a0, a1);
    }
    __finally {
        _PrintExit("WriteClassStm(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteConsoleA(HANDLE a0,
    void* a1,
    DWORD a2,
    LPDWORD a3,
    LPVOID a4)
{
    _PrintEnter("WriteConsoleA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteConsoleA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WriteConsoleA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteConsoleInputA(HANDLE a0,
    INPUT_RECORD* a1,
    DWORD a2,
    LPDWORD a3)
{
    _PrintEnter("WriteConsoleInputA(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_WriteConsoleInputA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WriteConsoleInputA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteConsoleInputW(HANDLE a0,
    INPUT_RECORD* a1,
    DWORD a2,
    LPDWORD a3)
{
    _PrintEnter("WriteConsoleInputW(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_WriteConsoleInputW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WriteConsoleInputW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteConsoleOutputA(HANDLE a0,
    CHAR_INFO* a1,
    COORD a2,
    COORD a3,
    PSMALL_RECT a4)
{
    _PrintEnter("WriteConsoleOutputA(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteConsoleOutputA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WriteConsoleOutputA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteConsoleOutputAttribute(HANDLE a0,
    WORD* a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
{
    _PrintEnter("WriteConsoleOutputAttribute(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteConsoleOutputAttribute(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WriteConsoleOutputAttribute(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteConsoleOutputCharacterA(HANDLE a0,
    LPCSTR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
{
    _PrintEnter("WriteConsoleOutputCharacterA(%p,%hs,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteConsoleOutputCharacterA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WriteConsoleOutputCharacterA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteConsoleOutputCharacterW(HANDLE a0,
    LPCWSTR a1,
    DWORD a2,
    COORD a3,
    LPDWORD a4)
{
    _PrintEnter("WriteConsoleOutputCharacterW(%p,%ls,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteConsoleOutputCharacterW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WriteConsoleOutputCharacterW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteConsoleOutputW(HANDLE a0,
    CHAR_INFO* a1,
    COORD a2,
    COORD a3,
    PSMALL_RECT a4)
{
    _PrintEnter("WriteConsoleOutputW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteConsoleOutputW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WriteConsoleOutputW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteConsoleW(HANDLE a0,
    void* a1,
    DWORD a2,
    LPDWORD a3,
    LPVOID a4)
{
    _PrintEnter("WriteConsoleW(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteConsoleW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WriteConsoleW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteFile(HANDLE a0,
    LPCVOID a1,
    DWORD a2,
    LPDWORD a3,
    LPOVERLAPPED a4)
{
    _PrintEnter("WriteFile(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteFile(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WriteFile(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteFileEx(HANDLE a0,
    LPCVOID a1,
    DWORD a2,
    LPOVERLAPPED a3,
    LPOVERLAPPED_COMPLETION_ROUTINE a4)
{
    _PrintEnter("WriteFileEx(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteFileEx(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WriteFileEx(,,,,) -> %p\n", rv);
    };
    return rv;
}

HRESULT __stdcall Mine_WriteFmtUserTypeStg(LPSTORAGE a0,
    CLIPFORMAT a1,
    LPOLESTR a2)
{
    _PrintEnter("WriteFmtUserTypeStg(%p,%p,%p)\n", a0, a1, a2);

    HRESULT rv = 0;
    __try {
        rv = Real_WriteFmtUserTypeStg(a0, a1, a2);
    }
    __finally {
        _PrintExit("WriteFmtUserTypeStg(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WritePrivateProfileSectionA(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2)
{
    _PrintEnter("WritePrivateProfileSectionA(%hs,%hs,%hs)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_WritePrivateProfileSectionA(a0, a1, a2);
    }
    __finally {
        _PrintExit("WritePrivateProfileSectionA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WritePrivateProfileSectionW(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2)
{
    _PrintEnter("WritePrivateProfileSectionW(%ls,%ls,%ls)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_WritePrivateProfileSectionW(a0, a1, a2);
    }
    __finally {
        _PrintExit("WritePrivateProfileSectionW(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WritePrivateProfileStringA(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2,
    LPCSTR a3)
{
    _PrintEnter("WritePrivateProfileStringA(%hs,%hs,%hs,%hs)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_WritePrivateProfileStringA(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WritePrivateProfileStringA(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WritePrivateProfileStringW(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2,
    LPCWSTR a3)
{
    _PrintEnter("WritePrivateProfileStringW(%ls,%ls,%ls,%ls)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_WritePrivateProfileStringW(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WritePrivateProfileStringW(,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WritePrivateProfileStructA(LPCSTR a0,
    LPCSTR a1,
    LPVOID a2,
    UINT a3,
    LPCSTR a4)
{
    _PrintEnter("WritePrivateProfileStructA(%hs,%hs,%p,%p,%hs)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WritePrivateProfileStructA(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WritePrivateProfileStructA(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WritePrivateProfileStructW(LPCWSTR a0,
    LPCWSTR a1,
    LPVOID a2,
    UINT a3,
    LPCWSTR a4)
{
    _PrintEnter("WritePrivateProfileStructW(%ls,%ls,%p,%p,%ls)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WritePrivateProfileStructW(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("WritePrivateProfileStructW(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteProcessMemory(HANDLE a0,
    LPVOID lpBase,
    LPVOID lpBuf,
    DWORD_PTR nSize,
    PDWORD_PTR a4)
{
    _PrintEnter("WriteProcessMemory(%p,@%p..%p,%p,%p)\n",
        a0, lpBase,
        (PBYTE)lpBase + ((nSize > 0) ? nSize - 1 : 0),
        lpBuf, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteProcessMemory(a0, lpBase, lpBuf, nSize, a4);
    }
    __finally {
        _PrintExit("WriteProcessMemory(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteProfileSectionA(LPCSTR a0,
    LPCSTR a1)
{
    _PrintEnter("WriteProfileSectionA(%hs,%hs)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_WriteProfileSectionA(a0, a1);
    }
    __finally {
        _PrintExit("WriteProfileSectionA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteProfileSectionW(LPCWSTR a0,
    LPCWSTR a1)
{
    _PrintEnter("WriteProfileSectionW(%ls,%ls)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_WriteProfileSectionW(a0, a1);
    }
    __finally {
        _PrintExit("WriteProfileSectionW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteProfileStringA(LPCSTR a0,
    LPCSTR a1,
    LPCSTR a2)
{
    _PrintEnter("WriteProfileStringA(%hs,%hs,%hs)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_WriteProfileStringA(a0, a1, a2);
    }
    __finally {
        _PrintExit("WriteProfileStringA(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL __stdcall Mine_WriteProfileStringW(LPCWSTR a0,
    LPCWSTR a1,
    LPCWSTR a2)
{
    _PrintEnter("WriteProfileStringW(%ls,%ls,%ls)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_WriteProfileStringW(a0, a1, a2);
    }
    __finally {
        _PrintExit("WriteProfileStringW(,,) -> %p\n", rv);
    };
    return rv;
}

DWORD __stdcall Mine_WriteTapemark(HANDLE a0,
    DWORD a1,
    DWORD a2,
    BOOL a3)
{
    _PrintEnter("WriteTapemark(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    DWORD rv = 0;
    __try {
        rv = Real_WriteTapemark(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("WriteTapemark(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine___WSAFDIsSet(SOCKET a0,
    fd_set* a1)
{
    _PrintEnter("__WSAFDIsSet(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real___WSAFDIsSet(a0, a1);
    }
    __finally {
        _PrintExit("__WSAFDIsSet(,) -> %p\n", rv);
    };
    return rv;
}

long __stdcall Mine__hread(HFILE a0,
    LPVOID a1,
    long a2)
{
    _PrintEnter("_hread(%p,%p,%p)\n", a0, a1, a2);

    long rv = 0;
    __try {
        rv = Real__hread(a0, a1, a2);
    }
    __finally {
        _PrintExit("_hread(,,) -> %p\n", rv);
    };
    return rv;
}

long __stdcall Mine__hwrite(HFILE a0,
    LPCSTR a1,
    long a2)
{
    _PrintEnter("_hwrite(%p,%hs,%p)\n", a0, a1, a2);

    long rv = 0;
    __try {
        rv = Real__hwrite(a0, a1, a2);
    }
    __finally {
        _PrintExit("_hwrite(,,) -> %p\n", rv);
    };
    return rv;
}

HFILE __stdcall Mine__lclose(HFILE a0)
{
    _PrintEnter("_lclose(%p)\n", a0);

    HFILE rv = 0;
    __try {
        rv = Real__lclose(a0);
    }
    __finally {
        _PrintExit("_lclose() -> %p\n", rv);
    };
    return rv;
}

HFILE __stdcall Mine__lcreat(LPCSTR a0,
    int a1)
{
    _PrintEnter("_lcreat(%hs,%p)\n", a0, a1);

    HFILE rv = 0;
    __try {
        rv = Real__lcreat(a0, a1);
    }
    __finally {
        _PrintExit("_lcreat(,) -> %p\n", rv);
    };
    return rv;
}

LONG __stdcall Mine__llseek(HFILE a0,
    LONG a1,
    int a2)
{
    _PrintEnter("_llseek(%p,%p,%p)\n", a0, a1, a2);

    LONG rv = 0;
    __try {
        rv = Real__llseek(a0, a1, a2);
    }
    __finally {
        _PrintExit("_llseek(,,) -> %p\n", rv);
    };
    return rv;
}

HFILE __stdcall Mine__lopen(LPCSTR a0,
    int a1)
{
    _PrintEnter("_lopen(%hs,%p)\n", a0, a1);

    HFILE rv = 0;
    __try {
        rv = Real__lopen(a0, a1);
    }
    __finally {
        _PrintExit("_lopen(,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine__lread(HFILE a0,
    LPVOID a1,
    UINT a2)
{
    _PrintEnter("_lread(%p,%p,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real__lread(a0, a1, a2);
    }
    __finally {
        _PrintExit("_lread(,,) -> %p\n", rv);
    };
    return rv;
}

UINT __stdcall Mine__lwrite(HFILE a0,
    LPCSTR a1,
    UINT a2)
{
    _PrintEnter("_lwrite(%p,%hs,%p)\n", a0, a1, a2);

    UINT rv = 0;
    __try {
        rv = Real__lwrite(a0, a1, a2);
    }
    __finally {
        _PrintExit("_lwrite(,,) -> %p\n", rv);
    };
    return rv;
}

SOCKET __stdcall Mine_accept(SOCKET a0,
    sockaddr* a1,
    int* a2)
{
    _PrintEnter("accept(%p,%p,%p)\n", a0, a1, a2);

    SOCKET rv = 0;
    __try {
        rv = Real_accept(a0, a1, a2);
    }
    __finally {
        _PrintExit("accept(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_bind(SOCKET a0,
    sockaddr* a1,
    int a2)
{
    _PrintEnter("bind(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_bind(a0, a1, a2);
    }
    __finally {
        _PrintExit("bind(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_closesocket(SOCKET a0)
{
    _PrintEnter("closesocket(%p)\n", a0);

    int rv = 0;
    __try {
        rv = Real_closesocket(a0);
    }
    __finally {
        _PrintExit("closesocket() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_connect(SOCKET a0,
    sockaddr* a1,
    int a2)
{
    _PrintEnter("connect(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_connect(a0, a1, a2);
    }
    __finally {
        _PrintExit("connect(,,) -> %p\n", rv);
    };
    return rv;
}

hostent* __stdcall Mine_gethostbyaddr(char* a0,
    int a1,
    int a2)
{
    _PrintEnter("gethostbyaddr(%p,%p,%p)\n", a0, a1, a2);

    hostent* rv = 0;
    __try {
        rv = Real_gethostbyaddr(a0, a1, a2);
    }
    __finally {
        _PrintExit("gethostbyaddr(,,) -> %p\n", rv);
    };
    return rv;
}

hostent* __stdcall Mine_gethostbyname(char* a0)
{
    _PrintEnter("gethostbyname(%p)\n", a0);

    hostent* rv = 0;
    __try {
        rv = Real_gethostbyname(a0);
    }
    __finally {
        _PrintExit("gethostbyname() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_gethostname(char* a0,
    int a1)
{
    _PrintEnter("gethostname(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_gethostname(a0, a1);
    }
    __finally {
        _PrintExit("gethostname(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_getpeername(SOCKET a0,
    sockaddr* a1,
    int* a2)
{
    _PrintEnter("getpeername(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_getpeername(a0, a1, a2);
    }
    __finally {
        _PrintExit("getpeername(,,) -> %p\n", rv);
    };
    return rv;
}

protoent* __stdcall Mine_getprotobyname(char* a0)
{
    _PrintEnter("getprotobyname(%p)\n", a0);

    protoent* rv = 0;
    __try {
        rv = Real_getprotobyname(a0);
    }
    __finally {
        _PrintExit("getprotobyname() -> %p\n", rv);
    };
    return rv;
}

protoent* __stdcall Mine_getprotobynumber(int a0)
{
    _PrintEnter("getprotobynumber(%p)\n", a0);

    protoent* rv = 0;
    __try {
        rv = Real_getprotobynumber(a0);
    }
    __finally {
        _PrintExit("getprotobynumber() -> %p\n", rv);
    };
    return rv;
}

servent* __stdcall Mine_getservbyname(char* a0,
    char* a1)
{
    _PrintEnter("getservbyname(%p,%p)\n", a0, a1);

    servent* rv = 0;
    __try {
        rv = Real_getservbyname(a0, a1);
    }
    __finally {
        _PrintExit("getservbyname(,) -> %p\n", rv);
    };
    return rv;
}

servent* __stdcall Mine_getservbyport(int a0,
    char* a1)
{
    _PrintEnter("getservbyport(%p,%p)\n", a0, a1);

    servent* rv = 0;
    __try {
        rv = Real_getservbyport(a0, a1);
    }
    __finally {
        _PrintExit("getservbyport(,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_getsockname(SOCKET a0,
    sockaddr* a1,
    int* a2)
{
    _PrintEnter("getsockname(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_getsockname(a0, a1, a2);
    }
    __finally {
        _PrintExit("getsockname(,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_getsockopt(SOCKET a0,
    int a1,
    int a2,
    char* a3,
    int* a4)
{
    _PrintEnter("getsockopt(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_getsockopt(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("getsockopt(,,,,) -> %p\n", rv);
    };
    return rv;
}

u_long __stdcall Mine_htonl(u_long a0)
{
    _PrintEnter("htonl(%p)\n", a0);

    u_long rv = 0;
    __try {
        rv = Real_htonl(a0);
    }
    __finally {
        _PrintExit("htonl() -> %p\n", rv);
    };
    return rv;
}

u_short __stdcall Mine_htons(u_short a0)
{
    _PrintEnter("htons(%p)\n", a0);

    u_short rv = 0;
    __try {
        rv = Real_htons(a0);
    }
    __finally {
        _PrintExit("htons() -> %p\n", rv);
    };
    return rv;
}

unsigned long __stdcall Mine_inet_addr(char* a0)
{
    _PrintEnter("inet_addr(%p)\n", a0);

    unsigned long rv = 0;
    __try {
        rv = Real_inet_addr(a0);
    }
    __finally {
        _PrintExit("inet_addr() -> %p\n", rv);
    };
    return rv;
}

char* __stdcall Mine_inet_ntoa(in_addr a0)
{
    _PrintEnter("inet_ntoa(%p)\n", a0);

    char* rv = 0;
    __try {
        rv = Real_inet_ntoa(a0);
    }
    __finally {
        _PrintExit("inet_ntoa() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_ioctlsocket(SOCKET a0,
    long a1,
    u_long* a2)
{
    _PrintEnter("ioctlsocket(%p,%p,%p)\n", a0, a1, a2);

    int rv = 0;
    __try {
        rv = Real_ioctlsocket(a0, a1, a2);
    }
    __finally {
        _PrintExit("ioctlsocket(,,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_keybd_event(BYTE a0,
    BYTE a1,
    DWORD a2,
    ULONG_PTR a3)
{
    _PrintEnter("keybd_event(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    __try {
        Real_keybd_event(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("keybd_event(,,,) ->\n");
    };
}

int __stdcall Mine_listen(SOCKET a0,
    int a1)
{
    _PrintEnter("listen(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_listen(a0, a1);
    }
    __finally {
        _PrintExit("listen(,) -> %p\n", rv);
    };
    return rv;
}

void __stdcall Mine_mouse_event(DWORD a0,
    DWORD a1,
    DWORD a2,
    DWORD a3,
    ULONG_PTR a4)
{
    _PrintEnter("mouse_event(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    __try {
        Real_mouse_event(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("mouse_event(,,,,) ->\n");
    };
}

u_long __stdcall Mine_ntohl(u_long a0)
{
    _PrintEnter("ntohl(%p)\n", a0);

    u_long rv = 0;
    __try {
        rv = Real_ntohl(a0);
    }
    __finally {
        _PrintExit("ntohl() -> %p\n", rv);
    };
    return rv;
}

u_short __stdcall Mine_ntohs(u_short a0)
{
    _PrintEnter("ntohs(%p)\n", a0);

    u_short rv = 0;
    __try {
        rv = Real_ntohs(a0);
    }
    __finally {
        _PrintExit("ntohs() -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_recv(SOCKET a0,
    char* a1,
    int a2,
    int a3)
{
    _PrintEnter("recv(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_recv(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("recv(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_recvfrom(SOCKET a0,
    char* a1,
    int a2,
    int a3,
    sockaddr* a4,
    int* a5)
{
    _PrintEnter("recvfrom(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_recvfrom(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("recvfrom(,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_select(int a0,
    fd_set* a1,
    fd_set* a2,
    fd_set* a3,
    timeval* a4)
{
    _PrintEnter("select(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_select(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("select(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_send(SOCKET a0,
    char* a1,
    int a2,
    int a3)
{
    _PrintEnter("send(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    int rv = 0;
    __try {
        rv = Real_send(a0, a1, a2, a3);
    }
    __finally {
        _PrintExit("send(,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_sendto(SOCKET a0,
    char* a1,
    int a2,
    int a3,
    sockaddr* a4,
    int a5)
{
    _PrintEnter("sendto(%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5);

    int rv = 0;
    __try {
        rv = Real_sendto(a0, a1, a2, a3, a4, a5);
    }
    __finally {
        _PrintExit("sendto(,,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_setsockopt(SOCKET a0,
    int a1,
    int a2,
    char* a3,
    int a4)
{
    _PrintEnter("setsockopt(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    int rv = 0;
    __try {
        rv = Real_setsockopt(a0, a1, a2, a3, a4);
    }
    __finally {
        _PrintExit("setsockopt(,,,,) -> %p\n", rv);
    };
    return rv;
}

int __stdcall Mine_shutdown(SOCKET a0,
    int a1)
{
    _PrintEnter("shutdown(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_shutdown(a0, a1);
    }
    __finally {
        _PrintExit("shutdown(,) -> %p\n", rv);
    };
    return rv;
}

SOCKET __stdcall Mine_socket(int a0,
    int a1,
    int a2)
{
    _PrintEnter("socket(%x,%x,%x)\n", a0, a1, a2);

    SOCKET rv = 0;
    __try {
        rv = Real_socket(a0, a1, a2);
    }
    __finally {
        _PrintExit("socket(,,) -> %p\n", rv);
    };
    return rv;
}

//
///////////////////////////////////////////////////////////////// End of File.
