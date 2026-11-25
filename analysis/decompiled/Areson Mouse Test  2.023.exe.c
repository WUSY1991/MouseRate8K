/* ==== FUN_00401010 @ 00401010 ==== */

void FUN_00401010(void)

{
  CMap<>(&DAT_00419e78,10);
  return;
}



/* ==== FUN_00401020 @ 00401020 ==== */

void FUN_00401020(void)

{
  FUN_00413906((_onexit_t)&LAB_00401030);
  return;
}



/* ==== FUN_00401050 @ 00401050 ==== */

void FUN_00401050(void)

{
  FUN_00402bb0(&DAT_00419e58,10);
  return;
}



/* ==== FUN_00401060 @ 00401060 ==== */

void FUN_00401060(void)

{
  FUN_00413906((_onexit_t)&LAB_00401070);
  return;
}



/* ==== FUN_00401080 @ 00401080 ==== */

undefined4 * __fastcall FUN_00401080(undefined4 *param_1)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00413dde;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00413a0c(param_1 + 1,4,0x14,CString::CString);
  local_4 = 0;
  FUN_00413a0c(param_1 + 0xb6,4,0x14,CString::CString);
  local_4._0_1_ = 1;
  FUN_00413a0c(param_1 + 0xca,4,0x14,CString::CString);
  local_4._0_1_ = 2;
  FUN_00413a0c(param_1 + 0xde,4,0x14,CString::CString);
  local_4 = CONCAT31(local_4._1_3_,3);
  *param_1 = &PTR_FUN_00415498;
  FUN_00401840(param_1);
  ExceptionList = local_c;
  return param_1;
}



/* ==== FUN_00401140 @ 00401140 ==== */

undefined4 * __thiscall FUN_00401140(void *this,byte param_1)

{
  FUN_00401160((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



/* ==== FUN_00401160 @ 00401160 ==== */

void __fastcall FUN_00401160(undefined4 *param_1)

{
  void *local_c;
  undefined *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00413e36;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_00415498;
  local_4 = 2;
  FUN_00413918(param_1 + 0xde,4,0x14,CString::~CString);
  local_4._0_1_ = 1;
  FUN_00413918(param_1 + 0xca,4,0x14,CString::~CString);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00413918(param_1 + 0xb6,4,0x14,CString::~CString);
  local_4 = 0xffffffff;
  FUN_00413918(param_1 + 1,4,0x14,CString::~CString);
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00401200 @ 00401200 ==== */

undefined4 __thiscall FUN_00401200(void *this,int param_1)

{
  return *(undefined4 *)((int)this + param_1 * 4 + 0x1e8);
}



/* ==== FUN_00401210 @ 00401210 ==== */

DWORD __thiscall FUN_00401210(void *this,int param_1,int param_2,undefined param_3)

{
  HANDLE pvVar1;
  DWORD DVar2;
  DWORD DVar3;
  undefined uStack_18;
  undefined uStack_17;
  undefined uStack_16;
  undefined uStack_15;
  undefined uStack_14;
  undefined uStack_13;
  undefined uStack_12;
  undefined uStack_11;
  undefined uStack_10;
  undefined uStack_f;
  _SECURITY_ATTRIBUTES local_c;
  
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  local_c.bInheritHandle = 1;
  local_c.nLength = 0xc;
  pvVar1 = CreateFileA(*(LPCSTR *)((int)this + param_1 * 4 + 4),0xc0000000,3,&local_c,3,0x40000000,
                       (HANDLE)0x0);
  *(HANDLE *)((int)this + param_1 * 4 + 0x288) = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    return 0;
  }
  uStack_18 = 2;
  uStack_17 = 0x96;
  uStack_16 = (undefined)param_2;
  uStack_13 = 0;
  uStack_12 = 0;
  uStack_11 = 0;
  uStack_10 = 0;
  uStack_f = 0;
  uStack_14 = (undefined)(param_2 + (param_2 >> 0x1f & 0xffU) >> 8);
  uStack_15 = param_3;
  DVar2 = FUN_00401640(pvVar1,&uStack_18,*(DWORD *)((int)this + param_1 * 4 + 0x238));
  DVar3 = GetLastError();
  if (DVar3 == 0x48f) {
    CString::Empty((CString *)((int)this + param_1 * 4 + 4));
  }
  CloseHandle(*(HANDLE *)((int)this + param_1 * 4 + 0x288));
  *(undefined4 *)((int)this + param_1 * 4 + 0x288) = 0;
  return DVar2;
}



/* ==== FUN_00401310 @ 00401310 ==== */

undefined4 __thiscall FUN_00401310(void *this,int param_1,int param_2,LPVOID param_3)

{
  HANDLE hFile;
  DWORD DVar1;
  int iVar2;
  undefined uStack_18;
  undefined uStack_17;
  undefined uStack_16;
  undefined uStack_15;
  undefined uStack_14;
  undefined uStack_13;
  undefined uStack_12;
  undefined uStack_11;
  undefined uStack_10;
  undefined uStack_f;
  _SECURITY_ATTRIBUTES local_c;
  
  iVar2 = 0;
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  local_c.bInheritHandle = 1;
  local_c.nLength = 0xc;
  hFile = CreateFileA(*(LPCSTR *)((int)this + param_1 * 4 + 4),0xc0000000,3,&local_c,3,0x40000000,
                      (HANDLE)0x0);
  *(HANDLE *)((int)this + param_1 * 4 + 0x288) = hFile;
  if (hFile == (HANDLE)0x0) {
    return 0;
  }
  CancelIo(hFile);
  uStack_18 = 2;
  uStack_16 = 2;
  uStack_17 = 0x9a;
  uStack_13 = 0;
  uStack_12 = 0;
  uStack_14 = (undefined)param_2;
  uStack_11 = 0;
  uStack_10 = 0;
  uStack_f = 0;
  uStack_15 = (undefined)(param_2 + (param_2 >> 0x1f & 0xffU) >> 8);
  FUN_00401640(*(HANDLE *)((int)this + param_1 * 4 + 0x288),&uStack_18,
               *(DWORD *)((int)this + param_1 * 4 + 0x238));
  while( true ) {
    FUN_00401740(*(HANDLE *)((int)this + param_1 * 4 + 0x288),param_3,
                 *(DWORD *)((int)this + param_1 * 4 + 0x238));
    DVar1 = GetLastError();
    if (DVar1 != 0x3e4) break;
    *(undefined *)((int)param_3 + 1) = 0;
    CancelIo(*(HANDLE *)((int)this + param_1 * 4 + 0x288));
    if (10 < iVar2) goto LAB_0040144c;
    iVar2 = iVar2 + 1;
    FUN_00401640(*(HANDLE *)((int)this + param_1 * 4 + 0x288),&uStack_18,
                 *(DWORD *)((int)this + param_1 * 4 + 0x238));
  }
  if (DVar1 == 0x48f) {
    CString::Empty((CString *)((int)this + param_1 * 4 + 4));
  }
LAB_0040144c:
  CloseHandle(*(HANDLE *)((int)this + param_1 * 4 + 0x288));
  *(undefined4 *)((int)this + param_1 * 4 + 0x288) = 0;
  return 0;
}



/* ==== FUN_00401480 @ 00401480 ==== */

DWORD __thiscall
FUN_00401480(void *this,int param_1,undefined param_2,undefined param_3,LPVOID param_4)

{
  HANDLE pvVar1;
  DWORD DVar2;
  DWORD DVar3;
  int iVar4;
  undefined uStack_18;
  undefined uStack_17;
  undefined uStack_16;
  undefined uStack_15;
  undefined uStack_14;
  undefined uStack_13;
  undefined uStack_12;
  undefined uStack_11;
  undefined uStack_10;
  undefined uStack_f;
  _SECURITY_ATTRIBUTES local_c;
  
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  local_c.bInheritHandle = 1;
  local_c.nLength = 0xc;
  pvVar1 = CreateFileA(*(LPCSTR *)((int)this + param_1 * 4 + 4),0xc0000000,3,&local_c,3,0x40000000,
                       (HANDLE)0x0);
  *(HANDLE *)((int)this + param_1 * 4 + 0x288) = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    return 0;
  }
  iVar4 = *(int *)((int)this + param_1 * 4 + 0x418);
  if (iVar4 == 3) {
    iVar4 = 1;
  }
  uStack_18 = (undefined)iVar4;
  uStack_17 = param_2;
  uStack_16 = param_3;
  uStack_15 = 0;
  uStack_14 = 0;
  uStack_13 = 0;
  uStack_12 = 0;
  uStack_11 = 0;
  uStack_10 = 0;
  uStack_f = 0;
  FUN_00401640(pvVar1,&uStack_18,*(DWORD *)((int)this + param_1 * 4 + 0x238));
  _param_2 = 0;
  while( true ) {
    DVar2 = FUN_00401740(*(HANDLE *)((int)this + param_1 * 4 + 0x288),param_4,
                         *(DWORD *)((int)this + param_1 * 4 + 0x238));
    DVar3 = GetLastError();
    if (DVar3 != 0x3e4) break;
    *(undefined *)((int)param_4 + 1) = 0;
    CancelIo(*(HANDLE *)((int)this + param_1 * 4 + 0x288));
    if (10 < _param_2) goto LAB_004015ae;
    _param_2 = _param_2 + 1;
    FUN_00401640(*(HANDLE *)((int)this + param_1 * 4 + 0x288),&uStack_18,
                 *(DWORD *)((int)this + param_1 * 4 + 0x238));
  }
  if (DVar3 == 0x48f) {
    CString::Empty((CString *)((int)this + param_1 * 4 + 4));
  }
LAB_004015ae:
  CloseHandle(*(HANDLE *)((int)this + param_1 * 4 + 0x288));
  *(undefined4 *)((int)this + param_1 * 4 + 0x288) = 0;
  return DVar2;
}



/* ==== FUN_004015e0 @ 004015e0 ==== */

undefined4 __thiscall FUN_004015e0(void *this,int param_1)

{
  return *(undefined4 *)((int)this + param_1 * 4 + 0xf8);
}



/* ==== FUN_004015f0 @ 004015f0 ==== */

undefined4 __thiscall FUN_004015f0(void *this,int param_1)

{
  return *(undefined4 *)((int)this + param_1 * 4 + 0x148);
}



/* ==== FUN_00401600 @ 00401600 ==== */

undefined4 __thiscall FUN_00401600(void *this,int param_1)

{
  return *(undefined4 *)((int)this + param_1 * 4 + 0x198);
}



/* ==== FUN_00401610 @ 00401610 ==== */

CString * __thiscall FUN_00401610(void *this,CString *param_1,int param_2)

{
  CString::CString(param_1,(CString *)((int)this + param_2 * 4 + 0x2d8));
  return param_1;
}



/* ==== FUN_00401640 @ 00401640 ==== */

DWORD FUN_00401640(HANDLE param_1,LPCVOID param_2,DWORD param_3)

{
  HANDLE hFile;
  DWORD DVar1;
  HANDLE hEvent;
  HANDLE hObject;
  DWORD dwErrCode;
  _SECURITY_ATTRIBUTES local_20;
  _OVERLAPPED _Stack_14;
  
  hFile = param_1;
  if (param_1 == (HANDLE)0x0) {
    return 0;
  }
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  local_20.bInheritHandle = 1;
  local_20.nLength = 0xc;
  hEvent = CreateEventA(&local_20,1,1,(LPCSTR)0x0);
  _Stack_14.u.s.Offset = 0;
  _Stack_14.u.s.OffsetHigh = 0;
  param_1 = (HANDLE)0x0;
  _Stack_14.hEvent = hEvent;
  hObject = CreateWaitableTimerA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
  ResetEvent(hEvent);
  DVar1 = param_3;
  param_3 = WriteFile(hFile,param_2,param_3,(LPDWORD)&param_1,&_Stack_14);
  WaitForSingleObject(hEvent,8);
  dwErrCode = GetLastError();
  if (param_3 == 0) {
    do {
      if (dwErrCode != 0x3e5) break;
      GetOverlappedResult(hFile,&_Stack_14,(LPDWORD)&param_1,0);
      Sleep(1);
      dwErrCode = GetLastError();
    } while (param_1 != (HANDLE)DVar1);
  }
  CloseHandle(hObject);
  CancelIo(hFile);
  CloseHandle(hEvent);
  SetLastError(dwErrCode);
  return (DWORD)param_1;
}



/* ==== FUN_00401740 @ 00401740 ==== */

DWORD FUN_00401740(HANDLE param_1,LPVOID param_2,DWORD param_3)

{
  HANDLE hFile;
  DWORD DVar1;
  HANDLE hEvent;
  HANDLE hObject;
  DWORD dwErrCode;
  _SECURITY_ATTRIBUTES local_20;
  _OVERLAPPED _Stack_14;
  
  hFile = param_1;
  if (param_1 == (HANDLE)0x0) {
    return 0;
  }
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  local_20.bInheritHandle = 1;
  local_20.nLength = 0xc;
  hEvent = CreateEventA(&local_20,1,1,(LPCSTR)0x0);
  _Stack_14.u.s.Offset = 0;
  _Stack_14.u.s.OffsetHigh = 0;
  _Stack_14.hEvent = hEvent;
  ResetEvent(hEvent);
  hObject = CreateWaitableTimerA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
  DVar1 = param_3;
  param_1 = (HANDLE)0x0;
  param_3 = ReadFile(hFile,param_2,param_3,(LPDWORD)&param_1,&_Stack_14);
  WaitForSingleObject(hEvent,0x14);
  dwErrCode = GetLastError();
  if (param_3 == 0) {
    do {
      if (dwErrCode != 0x3e5) break;
      GetOverlappedResult(hFile,&_Stack_14,(LPDWORD)&param_1,0);
      Sleep(1);
      dwErrCode = GetLastError();
    } while (param_1 != (HANDLE)DVar1);
  }
  CloseHandle(hObject);
  CancelIo(hFile);
  CloseHandle(hEvent);
  SetLastError(dwErrCode);
  return (DWORD)param_1;
}



/* ==== FUN_00401840 @ 00401840 ==== */

/* WARNING: Removing unreachable block (ram,0x004019f3) */

int __fastcall FUN_00401840(void *param_1)

{
  CString *this;
  HDEVINFO DeviceInfoSet;
  DWORD DVar1;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_A DeviceInterfaceDetailData;
  HANDLE hFile;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  DWORD dwLanguageId;
  HLOCAL *lpBuffer;
  DWORD nSize;
  va_list *Arguments;
  ushort local_434 [256];
  char local_234;
  char local_233;
  undefined local_232;
  uint uStack_229;
  undefined local_16c;
  undefined local_16b;
  undefined local_16a;
  undefined local_169;
  undefined local_168;
  undefined local_167;
  undefined local_166;
  undefined local_165;
  undefined local_164;
  undefined4 local_163;
  _SP_DEVICE_INTERFACE_DATA local_108;
  _SECURITY_ATTRIBUTES local_ec;
  short local_e0;
  short sStack_de;
  ushort uStack_dc;
  ushort uStack_da;
  BOOL local_a0;
  CString local_9c [4];
  HDEVINFO local_98;
  HLOCAL local_94;
  void *local_90;
  short local_88;
  ushort uStack_86;
  GUID local_80;
  CString *local_6c;
  CString *local_68;
  CString local_64 [4];
  CString local_60 [4];
  DWORD local_5c;
  undefined4 local_58;
  undefined local_54;
  undefined local_53;
  undefined local_52;
  undefined local_51;
  undefined local_50;
  undefined local_4f;
  undefined local_4e;
  undefined local_4d;
  undefined local_4c;
  undefined local_4b;
  undefined local_48;
  undefined local_47;
  undefined local_46;
  undefined local_45;
  undefined local_44;
  undefined local_43;
  undefined local_42;
  undefined local_41;
  undefined local_40;
  undefined local_3c;
  undefined local_3b;
  undefined local_3a;
  undefined local_39;
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_A local_30;
  int local_2c;
  int local_28;
  uchar *local_24;
  undefined local_20;
  char local_1f;
  undefined local_1e;
  undefined uStack_1d;
  undefined uStack_1c;
  undefined uStack_1b;
  undefined uStack_1a;
  undefined uStack_19;
  undefined uStack_18;
  undefined uStack_17;
  undefined *local_14;
  void *local_10;
  undefined *puStack_c;
  HDEVINFO local_8;
  
  local_8 = (HDEVINFO)0xffffffff;
  puStack_c = &LAB_00413e73;
  local_10 = ExceptionList;
  local_14 = &stack0xfffff3c0;
  puVar3 = (undefined4 *)((int)param_1 + 0x58);
  local_28 = 0x14;
  ExceptionList = &local_10;
  local_90 = param_1;
  do {
    puVar3[0xf0] = 0;
    *puVar3 = 0;
    puVar3[0x14] = 0;
    puVar3[0x28] = 0;
    puVar3[0x3c] = 0;
    puVar3[0x50] = 0;
    puVar3[0x78] = 0;
    puVar3[100] = 0;
    puVar3[0x8c] = 0;
    CString::operator=((CString *)(puVar3 + 0xa0),&DAT_00419e94);
    CString::Empty((CString *)(puVar3 + -0x15));
    puVar3[0x8c] = 0;
    puVar3 = puVar3 + 1;
    local_28 = local_28 + -1;
  } while (local_28 != 0);
  *(undefined4 *)((int)param_1 + 0x54) = 0;
  CString::CString((CString *)&local_24);
  local_8 = (HDEVINFO)0x0;
  HidD_GetHidGuid(&local_80);
  sprintf(&stack0xfffff3cc,&DAT_0041812c,local_80.Data1,local_80.Data2,
          CONCAT12(local_80.Data4[0],local_80.Data3) & 0xffff,
          CONCAT12(local_80.Data4[2],CONCAT11(local_80.Data4[1],local_80.Data4[0])) & 0xff,
          CONCAT12(local_80.Data4[3],CONCAT11(local_80.Data4[2],local_80.Data4[1])) & 0xff,
          CONCAT12(local_80.Data4[4],CONCAT11(local_80.Data4[3],local_80.Data4[2])) & 0xff,
          CONCAT12(local_80.Data4[5],CONCAT11(local_80.Data4[4],local_80.Data4[3])) & 0xff,
          CONCAT12(local_80.Data4[6],CONCAT11(local_80.Data4[5],local_80.Data4[4])) & 0xff,
          CONCAT12(local_80.Data4[7],CONCAT11(local_80.Data4[6],local_80.Data4[5])) & 0xff,
          CONCAT11(local_80.Data4[7],local_80.Data4[6]) & 0xff,local_80.Data4[7]);
  DeviceInfoSet = SetupDiGetClassDevsA(&local_80,(PCSTR)0x0,(HWND)0x0,0x12);
  local_98 = DeviceInfoSet;
  if (DeviceInfoSet == (HDEVINFO)0xffffffff) {
    local_8 = DeviceInfoSet;
    CString::~CString((CString *)&local_24);
    ExceptionList = local_10;
    return 0;
  }
  local_28 = 0;
  local_108.cbSize = 0x1c;
  local_a0 = SetupDiEnumDeviceInterfaces(DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,&local_80,0,&local_108)
  ;
  if ((local_a0 == 0) && (DVar1 = GetLastError(), DVar1 == 0x103)) {
    sprintf(&stack0xfffff3cc,&DAT_00418114);
    SetupDiDestroyDeviceInfoList(DeviceInfoSet);
    iVar2 = *(int *)((int)param_1 + 0x54);
    DVar1 = 0;
    if (0 < iVar2) {
      piVar4 = (int *)((int)param_1 + 4);
      do {
        if (*(int *)(*piVar4 + -8) != 0) {
          FUN_00402520(param_1,DVar1);
        }
        iVar2 = *(int *)((int)param_1 + 0x54);
        DVar1 = DVar1 + 1;
        piVar4 = piVar4 + 1;
      } while ((int)DVar1 < iVar2);
    }
    local_8 = (HDEVINFO)0xffffffff;
    CString::~CString((CString *)&local_24);
    ExceptionList = local_10;
    return iVar2;
  }
  sprintf(&stack0xfffff3cc,&DAT_004180f4);
  local_5c = 0;
  SetupDiGetDeviceInterfaceDetailA
            (DeviceInfoSet,&local_108,(PSP_DEVICE_INTERFACE_DETAIL_DATA_A)0x0,0,&local_5c,
             (PSP_DEVINFO_DATA)0x0);
  DeviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)malloc(local_5c);
  DeviceInterfaceDetailData->cbSize = 5;
  local_30 = DeviceInterfaceDetailData;
  SetupDiGetDeviceInterfaceDetailA
            (DeviceInfoSet,&local_108,DeviceInterfaceDetailData,local_5c,(PDWORD)0x0,
             (PSP_DEVINFO_DATA)0x0);
  local_8._0_1_ = 1;
  local_ec.lpSecurityDescriptor = (LPVOID)0x0;
  local_ec.bInheritHandle = 1;
  local_ec.nLength = 0xc;
  hFile = CreateFileA(DeviceInterfaceDetailData->DevicePath,0xc0000000,3,&local_ec,3,0x40000000,
                      (HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    Arguments = (va_list *)0x0;
    lpBuffer = &local_94;
    nSize = 0;
    dwLanguageId = 0x400;
    DVar1 = GetLastError();
    FormatMessageA(0x1100,(LPCVOID)0x0,DVar1,dwLanguageId,(LPSTR)lpBuffer,nSize,Arguments);
    LocalFree(local_94);
    iVar2 = FUN_004024bc();
    return iVar2;
  }
  local_58 = 0;
  HidD_GetPreparsedData(hFile,&local_58);
  HidP_GetCaps(local_58,&local_e0);
  HidD_FreePreparsedData(local_58);
  CString::Format((CString *)&local_24,(char *)&local_24);
  if (uStack_da < 6) goto LAB_004024a0;
  if (local_e0 == 0x80) {
    if (sStack_de != 1) {
      CancelIo(hFile);
      CloseHandle(hFile);
      iVar2 = FUN_004024bc();
      return iVar2;
    }
  }
  else if ((local_e0 != 1) ||
          ((((sStack_de != -0xe7 && (sStack_de != -0xee)) && (sStack_de != -0xed)) &&
           ((sStack_de != -0xde && (sStack_de != -0xdd)))))) goto LAB_004024a0;
  HidD_GetAttributes(hFile);
  sprintf(&stack0xfffff3cc,s_VID__0X_04X_004180d8);
  sprintf(&stack0xfffff3cc,s_PID__0X_04X_004180c8);
  sprintf(&stack0xfffff3cc,s_ver__0X_04X_004180b8);
  HidD_GetManufacturerString(hFile,local_434);
  HidD_GetSerialNumberString(hFile,local_434);
  CString::CString(local_9c,local_434);
  local_8 = (HDEVINFO)CONCAT31(local_8._1_3_,2);
  HidD_GetSerialNumberString(hFile,local_434);
  local_20 = 2;
  local_1f = -0x66;
  local_1e = 0;
  uStack_1d = 0;
  uStack_1c = 0;
  uStack_1b = 0;
  uStack_1a = 0;
  uStack_19 = 0;
  uStack_18 = 0;
  uStack_17 = 0;
  FUN_00401640(hFile,&local_20,(uint)uStack_da);
  local_2c = 0;
  if (((6 < uStack_dc) && (local_88 == -0x40)) &&
     (((uStack_86 & 0xff) == 0x1e || ((uStack_86 & 0xff) == 0x1f)))) {
    iVar2 = 0;
    while( true ) {
      Sleep(1);
      FUN_00401740(hFile,&local_20,(uint)uStack_dc);
      DVar1 = GetLastError();
      if ((DVar1 != 0x3e4) || (CancelIo(hFile), 10 < iVar2)) break;
      iVar2 = iVar2 + 1;
      local_3c = 2;
      local_3b = 0x9a;
      local_3a = 0;
      local_39 = 0;
      local_38 = 0;
      local_37 = 0;
      local_36 = 0;
      local_35 = 0;
      local_34 = 0;
      FUN_00401640(hFile,&local_3c,(uint)uStack_da);
    }
  }
  CancelIo(hFile);
  CString::CString(local_64,(ushort *)u__c_c_c_c_004180a4);
  local_8 = (HDEVINFO)CONCAT31(local_8._1_3_,3);
  CString::Format((CString *)(CONCAT12(uStack_1c,CONCAT11(uStack_1d,local_1e)) & 0xff),
                  (char *)&local_24);
  this = (CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x328);
  CString::Format(this,(char *)this);
  iVar2 = _mbscmp(local_24,&DAT_00418088);
  if ((iVar2 == 0) || (iVar2 = _mbscmp(local_24,&DAT_00418080), iVar2 == 0)) {
    CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x2d8),
                       (CString *)&local_24);
    *(uint *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x238) = (uint)uStack_da;
    *(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x418) = 2;
    CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 4),
                       local_30->DevicePath);
    HidD_GetProductString();
    CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x378),
                       local_434);
    *(int *)((int)param_1 + 0x54) = *(int *)((int)param_1 + 0x54) + 1;
  }
  else if (local_e0 == 1) {
    if (sStack_de == -0xed) {
      local_20 = 1;
      local_1f = '\0';
      local_1e = 0;
      FUN_00401640(hFile,&local_20,(uint)uStack_da);
      iVar2 = 0;
      if (6 < uStack_dc) {
        while( true ) {
          Sleep(1);
          local_1f = '\x02';
          FUN_00401740(hFile,&local_20,(uint)uStack_dc);
          DVar1 = GetLastError();
          if ((DVar1 != 0x3e4) || (CancelIo(hFile), 10 < iVar2)) break;
          iVar2 = iVar2 + 1;
          local_54 = 1;
          local_53 = 0x12;
          local_52 = 0;
          local_51 = 0;
          local_50 = 0;
          local_4f = 0;
          local_4e = 0;
          local_4d = 0;
          local_4c = 0;
          local_4b = 0;
          FUN_00401640(hFile,&local_54,(uint)uStack_da);
        }
      }
      CancelIo(hFile);
      CString::CString((CString *)&local_68,(ushort *)u__c_c_c_c_c_c_00418064);
      local_8 = (HDEVINFO)CONCAT31(local_8._1_3_,4);
      CString::Format(local_68,(char *)&local_24);
      if (local_1f == '\x12') {
        CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x2d8),
                           (CString *)&local_24);
        *(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x418) = 3;
        *(HANDLE *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x288) = hFile;
        *(uint *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x238) = (uint)uStack_da;
        CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 4),
                           local_30->DevicePath);
        HidD_GetProductString();
        CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x378),
                           local_434);
        *(int *)((int)param_1 + 0x54) = *(int *)((int)param_1 + 0x54) + 1;
      }
      local_8 = (HDEVINFO)CONCAT31(local_8._1_3_,3);
      CString::~CString((CString *)&local_68);
    }
    else {
      if (sStack_de != -0xde) goto LAB_00402268;
      local_234 = '\0';
      local_233 = '\0';
      local_232 = 0;
      FUN_00401640(hFile,&local_234,(uint)uStack_da);
      local_2c = 0;
      if (7 < uStack_dc) {
        while( true ) {
          Sleep(1);
          local_234 = '\x02';
          local_233 = '\x02';
          FUN_00401740(hFile,&local_234,(uint)uStack_dc);
          DVar1 = GetLastError();
          if ((DVar1 != 0x3e4) || (CancelIo(hFile), 5 < local_2c)) break;
          local_16c = 0;
          local_16b = 0;
          local_16a = 0;
          local_169 = 0;
          local_168 = 0;
          local_167 = 0;
          local_166 = 0;
          local_165 = 0;
          local_164 = 0;
          puVar3 = &local_163;
          for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar3 = 0;
            puVar3 = puVar3 + 1;
          }
          *(undefined2 *)puVar3 = 0;
          *(undefined *)((int)puVar3 + 2) = 0;
          local_2c = local_2c + 1;
          FUN_00401640(hFile,&local_16c,(uint)uStack_da);
        }
      }
      CancelIo(hFile);
      CString::CString(local_60,(ushort *)u__c_c_c_c_c_c_00418064);
      local_8 = (HDEVINFO)CONCAT31(local_8._1_3_,5);
      CString::Format(local_232,(char *)&local_24);
      if ((local_234 == '\0') && (local_233 == '\0')) {
        CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x2d8),
                           s_Nova_231G_00418058);
        *(HANDLE *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x288) = hFile;
        *(uint *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x238) = (uint)uStack_da;
        *(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x418) = 4;
        *(uint *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x148) = uStack_229 >> 8 & 0xff
        ;
        CString::Format((CString *)&local_24,(char *)&local_24);
        HidD_GetProductString();
        CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x378),
                           local_434);
        CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 4),
                           local_30->DevicePath);
        *(int *)((int)param_1 + 0x54) = *(int *)((int)param_1 + 0x54) + 1;
      }
      local_8 = (HDEVINFO)CONCAT31(local_8._1_3_,3);
      CString::~CString(local_60);
    }
  }
  else {
LAB_00402268:
    local_20 = 1;
    local_1f = '\0';
    local_1e = 0;
    FUN_00401640(hFile,&local_20,(uint)uStack_da);
    iVar2 = 0;
    if (uStack_dc == 8) {
      while( true ) {
        Sleep(1);
        local_1f = '\x02';
        FUN_00401740(hFile,&local_20,(uint)uStack_dc);
        DVar1 = GetLastError();
        if ((DVar1 != 0x3e4) || (CancelIo(hFile), 10 < iVar2)) break;
        iVar2 = iVar2 + 1;
        local_48 = 1;
        local_47 = 0;
        local_46 = 0;
        local_45 = 0;
        local_44 = 0;
        local_43 = 0;
        local_42 = 0;
        local_41 = 0;
        local_40 = 0;
        FUN_00401640(hFile,&local_48,(uint)uStack_da);
      }
    }
    CancelIo(hFile);
    CString::CString((CString *)&local_6c,(ushort *)u__c_c_c_c_c_c_00418064);
    local_8 = (HDEVINFO)CONCAT31(local_8._1_3_,6);
    CString::Format(local_6c,(char *)&local_24);
    if ((local_1f == '\x01') || (local_1f == '1')) {
      CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x2d8),
                         (CString *)&local_24);
      *(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x418) = 1;
      *(HANDLE *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x288) = hFile;
      *(uint *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x238) = (uint)uStack_da;
      HidD_GetProductString();
      CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 0x378),
                         local_434);
      CString::operator=((CString *)((int)param_1 + *(int *)((int)param_1 + 0x54) * 4 + 4),
                         local_30->DevicePath);
      *(int *)((int)param_1 + 0x54) = *(int *)((int)param_1 + 0x54) + 1;
    }
    local_8 = (HDEVINFO)CONCAT31(local_8._1_3_,3);
    CString::~CString((CString *)&local_6c);
  }
  local_8._0_1_ = 2;
  CString::~CString(local_64);
  local_8._0_1_ = 1;
  CString::~CString(local_9c);
LAB_004024a0:
  CancelIo(hFile);
  CloseHandle(hFile);
  iVar2 = FUN_004024bc();
  return iVar2;
}



/* ==== Catch@004024b0 @ 004024b0 ==== */

undefined * Catch_004024b0(void)

{
  return &DAT_004024b6;
}



/* ==== FUN_004024bc @ 004024bc ==== */

void FUN_004024bc(void)

{
  CString *this;
  HDEVINFO DeviceInfoSet;
  short sVar1;
  BOOL BVar2;
  DWORD DVar3;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_A DeviceInterfaceDetailData;
  HANDLE hFile;
  int iVar4;
  int *piVar5;
  int unaff_EBP;
  void *unaff_ESI;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  DWORD DVar9;
  LPSTR lpBuffer;
  DWORD nSize;
  char *_Format;
  va_list *Arguments;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
  if (*(int *)(unaff_EBP + -0x9c) == 0) {
LAB_004024d8:
    DVar9 = 0;
    if (0 < *(int *)((int)unaff_ESI + 0x54)) {
      piVar5 = (int *)((int)unaff_ESI + 4);
      do {
        if (*(int *)(*piVar5 + -8) != 0) {
          FUN_00402520(unaff_ESI,DVar9);
        }
        DVar9 = DVar9 + 1;
        piVar5 = piVar5 + 1;
      } while ((int)DVar9 < *(int *)((int)unaff_ESI + 0x54));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    CString::~CString((CString *)(unaff_EBP + -0x20));
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;
  }
  DVar9 = *(DWORD *)(unaff_EBP + -0x24);
  DeviceInfoSet = *(HDEVINFO *)(unaff_EBP + -0x94);
  BVar2 = SetupDiEnumDeviceInterfaces
                    (DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,(GUID *)(unaff_EBP + -0x7c),DVar9,
                     (PSP_DEVICE_INTERFACE_DATA)(unaff_EBP + -0x104));
  *(BOOL *)(unaff_EBP + -0x9c) = BVar2;
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    if (DVar3 == 0x103) {
      if (DVar9 == 0) {
        _Format = &DAT_00418114;
      }
      else {
        _Format = &DAT_00418100;
      }
      sprintf((char *)(unaff_EBP + -0xc30),_Format);
      SetupDiDestroyDeviceInfoList(DeviceInfoSet);
      goto LAB_004024d8;
    }
  }
  sprintf((char *)(unaff_EBP + -0xc30),&DAT_004180f4);
  *(undefined4 *)(unaff_EBP + -0x58) = 0;
  SetupDiGetDeviceInterfaceDetailA
            (DeviceInfoSet,(PSP_DEVICE_INTERFACE_DATA)(unaff_EBP + -0x104),
             (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)0x0,0,(PDWORD)(unaff_EBP + -0x58),
             (PSP_DEVINFO_DATA)0x0);
  DeviceInterfaceDetailData =
       (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)malloc(*(size_t *)(unaff_EBP + -0x58));
  *(PSP_DEVICE_INTERFACE_DETAIL_DATA_A *)(unaff_EBP + -0x2c) = DeviceInterfaceDetailData;
  DeviceInterfaceDetailData->cbSize = 5;
  SetupDiGetDeviceInterfaceDetailA
            (DeviceInfoSet,(PSP_DEVICE_INTERFACE_DATA)(unaff_EBP + -0x104),DeviceInterfaceDetailData
             ,*(DWORD *)(unaff_EBP + -0x58),(PDWORD)0x0,(PSP_DEVINFO_DATA)0x0);
  *(undefined *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0xe4) = 0;
  *(undefined4 *)(unaff_EBP + -0xe0) = 1;
  *(undefined4 *)(unaff_EBP + -0xe8) = 0xc;
  hFile = CreateFileA(DeviceInterfaceDetailData->DevicePath,0xc0000000,3,
                      (LPSECURITY_ATTRIBUTES)(unaff_EBP + -0xe8),3,0x40000000,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    Arguments = (va_list *)0x0;
    lpBuffer = (LPSTR)(unaff_EBP + -0x90);
    nSize = 0;
    DVar3 = 0x400;
    DVar9 = GetLastError();
    FormatMessageA(0x1100,(LPCVOID)0x0,DVar9,DVar3,lpBuffer,nSize,Arguments);
    LocalFree(*(HLOCAL *)(unaff_EBP + -0x90));
    FUN_004024bc();
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x54) = 0;
  HidD_GetPreparsedData(hFile,unaff_EBP + -0x54);
  HidP_GetCaps(*(undefined4 *)(unaff_EBP + -0x54),unaff_EBP + -0xdc);
  HidD_FreePreparsedData(*(undefined4 *)(unaff_EBP + -0x54));
  CString::Format((CString *)(unaff_EBP + -0x20),(char *)(unaff_EBP + -0x20));
  if (*(ushort *)(unaff_EBP + -0xd6) < 6) goto LAB_004024a0;
  sVar1 = (short)*(undefined4 *)(unaff_EBP + -0xdc);
  if (sVar1 == 0x80) {
    if (*(short *)(unaff_EBP + -0xda) != 1) {
      CancelIo(hFile);
      CloseHandle(hFile);
      FUN_004024bc();
      return;
    }
  }
  else if ((sVar1 != 1) ||
          ((((sVar1 = (short)*(undefined4 *)(unaff_EBP + -0xda), sVar1 != -0xe7 && (sVar1 != -0xee))
            && (sVar1 != -0xed)) && ((sVar1 != -0xde && (sVar1 != -0xdd)))))) goto LAB_004024a0;
  HidD_GetAttributes(hFile);
  sprintf((char *)(unaff_EBP + -0xc30),s_VID__0X_04X_004180d8);
  sprintf((char *)(unaff_EBP + -0xc30),s_PID__0X_04X_004180c8);
  sprintf((char *)(unaff_EBP + -0xc30),s_ver__0X_04X_004180b8);
  HidD_GetManufacturerString(hFile,unaff_EBP + -0x430);
  HidD_GetSerialNumberString(hFile,unaff_EBP + -0x430);
  CString::CString((CString *)(unaff_EBP + -0x98),(ushort *)(unaff_EBP + -0x430));
  *(undefined *)(unaff_EBP + -4) = 2;
  uVar6 = *(uint *)(unaff_EBP + -0x82) & 0xff;
  HidD_GetSerialNumberString(hFile,unaff_EBP + -0x430);
  *(undefined *)(unaff_EBP + -0x1c) = 2;
  *(undefined *)(unaff_EBP + -0x1b) = 0x9a;
  *(undefined *)(unaff_EBP + -0x1a) = 0;
  *(undefined *)(unaff_EBP + -0x19) = 0;
  *(undefined *)(unaff_EBP + -0x18) = 0;
  *(undefined *)(unaff_EBP + -0x17) = 0;
  *(undefined *)(unaff_EBP + -0x16) = 0;
  *(undefined *)(unaff_EBP + -0x15) = 0;
  *(undefined *)(unaff_EBP + -0x14) = 0;
  *(undefined *)(unaff_EBP + -0x13) = 0;
  FUN_00401640(hFile,(LPCVOID)(unaff_EBP + -0x1c),*(uint *)(unaff_EBP + -0xd6) & 0xffff);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  if (((6 < *(ushort *)(unaff_EBP + -0xd8)) && (*(short *)(unaff_EBP + -0x84) == -0x40)) &&
     ((uVar6 == 0x1e || (uVar6 == 0x1f)))) {
    iVar7 = *(int *)(unaff_EBP + -0x28);
    while( true ) {
      Sleep(1);
      FUN_00401740(hFile,(LPVOID)(unaff_EBP + -0x1c),*(uint *)(unaff_EBP + -0xd8) & 0xffff);
      DVar9 = GetLastError();
      if (DVar9 != 0x3e4) break;
      CancelIo(hFile);
      if (10 < iVar7) break;
      iVar7 = iVar7 + 1;
      *(undefined *)(unaff_EBP + -0x38) = 2;
      *(undefined *)(unaff_EBP + -0x37) = 0x9a;
      *(undefined *)(unaff_EBP + -0x36) = 0;
      *(undefined *)(unaff_EBP + -0x35) = 0;
      *(undefined *)(unaff_EBP + -0x34) = 0;
      *(undefined *)(unaff_EBP + -0x33) = 0;
      *(undefined *)(unaff_EBP + -0x32) = 0;
      *(undefined *)(unaff_EBP + -0x31) = 0;
      *(undefined *)(unaff_EBP + -0x30) = 0;
      FUN_00401640(hFile,(LPCVOID)(unaff_EBP + -0x38),*(uint *)(unaff_EBP + -0xd6) & 0xffff);
    }
  }
  CancelIo(hFile);
  CString::CString((CString *)(unaff_EBP + -0x60),(ushort *)u__c_c_c_c_004180a4);
  *(undefined *)(unaff_EBP + -4) = 3;
  CString::Format((CString *)(*(uint *)(unaff_EBP + -0x1a) & 0xff),(char *)(unaff_EBP + -0x20));
  this = (CString *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x328);
  CString::Format(this,(char *)this);
  iVar7 = _mbscmp(*(uchar **)(unaff_EBP + -0x20),&DAT_00418088);
  if (iVar7 == 0) {
LAB_00402410:
    CString::operator=((CString *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x2d8),
                       (CString *)(unaff_EBP + -0x20));
    *(uint *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x238) =
         *(uint *)(unaff_EBP + -0xd6) & 0xffff;
    iVar7 = *(int *)(unaff_EBP + -0x2c);
    *(undefined4 *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x418) = 2;
    CString::operator=((CString *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 4),
                       (char *)(iVar7 + 4));
    HidD_GetProductString();
    CString::operator=((CString *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x378),
                       (ushort *)(unaff_EBP + -0x430));
    *(int *)((int)unaff_ESI + 0x54) = *(int *)((int)unaff_ESI + 0x54) + 1;
  }
  else {
    iVar7 = _mbscmp(*(uchar **)(unaff_EBP + -0x20),&DAT_00418080);
    if (iVar7 == 0) goto LAB_00402410;
    if (*(short *)(unaff_EBP + -0xdc) == 1) {
      sVar1 = (short)*(undefined4 *)(unaff_EBP + -0xda);
      if (sVar1 == -0xed) {
        *(undefined *)(unaff_EBP + -0x1c) = 1;
        *(undefined *)(unaff_EBP + -0x1b) = 0;
        *(undefined *)(unaff_EBP + -0x1a) = 0;
        FUN_00401640(hFile,(LPCVOID)(unaff_EBP + -0x1c),*(uint *)(unaff_EBP + -0xd6) & 0xffff);
        iVar7 = 0;
        if (6 < *(ushort *)(unaff_EBP + -0xd8)) {
          while( true ) {
            Sleep(1);
            *(undefined *)(unaff_EBP + -0x1b) = 2;
            FUN_00401740(hFile,(LPVOID)(unaff_EBP + -0x1c),*(uint *)(unaff_EBP + -0xd8) & 0xffff);
            DVar9 = GetLastError();
            if (DVar9 != 0x3e4) break;
            CancelIo(hFile);
            if (10 < iVar7) break;
            iVar7 = iVar7 + 1;
            *(undefined *)(unaff_EBP + -0x50) = 1;
            *(undefined *)(unaff_EBP + -0x4f) = 0x12;
            *(undefined *)(unaff_EBP + -0x4e) = 0;
            *(undefined *)(unaff_EBP + -0x4d) = 0;
            *(undefined *)(unaff_EBP + -0x4c) = 0;
            *(undefined *)(unaff_EBP + -0x4b) = 0;
            *(undefined *)(unaff_EBP + -0x4a) = 0;
            *(undefined *)(unaff_EBP + -0x49) = 0;
            *(undefined *)(unaff_EBP + -0x48) = 0;
            *(undefined *)(unaff_EBP + -0x47) = 0;
            FUN_00401640(hFile,(LPCVOID)(unaff_EBP + -0x50),*(uint *)(unaff_EBP + -0xd6) & 0xffff);
          }
        }
        CancelIo(hFile);
        CString::CString((CString *)(unaff_EBP + -100),(ushort *)u__c_c_c_c_c_c_00418064);
        *(undefined *)(unaff_EBP + -4) = 4;
        CString::Format(*(CString **)(unaff_EBP + -100),(char *)(unaff_EBP + -0x20));
        if (*(char *)(unaff_EBP + -0x1b) == '\x12') {
          CString::operator=((CString *)
                             ((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x2d8),
                             (CString *)(unaff_EBP + -0x20));
          *(undefined4 *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x418) = 3;
          *(HANDLE *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x288) = hFile;
          iVar7 = *(int *)(unaff_EBP + -0x2c);
          *(uint *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x238) =
               *(uint *)(unaff_EBP + -0xd6) & 0xffff;
          CString::operator=((CString *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 4),
                             (char *)(iVar7 + 4));
          HidD_GetProductString();
          CString::operator=((CString *)
                             ((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x378),
                             (ushort *)(unaff_EBP + -0x430));
          *(int *)((int)unaff_ESI + 0x54) = *(int *)((int)unaff_ESI + 0x54) + 1;
        }
        *(undefined *)(unaff_EBP + -4) = 3;
        CString::~CString((CString *)(unaff_EBP + -100));
      }
      else {
        if (sVar1 != -0xde) goto LAB_00402268;
        *(undefined *)(unaff_EBP + -0x230) = 0;
        *(undefined *)(unaff_EBP + -0x22f) = 0;
        *(undefined *)(unaff_EBP + -0x22e) = 0;
        FUN_00401640(hFile,(LPCVOID)(unaff_EBP + -0x230),*(uint *)(unaff_EBP + -0xd6) & 0xffff);
        *(undefined4 *)(unaff_EBP + -0x28) = 0;
        if (7 < *(ushort *)(unaff_EBP + -0xd8)) {
          while( true ) {
            Sleep(1);
            *(undefined *)(unaff_EBP + -0x230) = 2;
            *(undefined *)(unaff_EBP + -0x22f) = 2;
            FUN_00401740(hFile,(LPVOID)(unaff_EBP + -0x230),*(uint *)(unaff_EBP + -0xd8) & 0xffff);
            DVar9 = GetLastError();
            if (DVar9 != 0x3e4) break;
            CancelIo(hFile);
            iVar7 = *(int *)(unaff_EBP + -0x28);
            if (5 < iVar7) break;
            *(undefined *)(unaff_EBP + -0x168) = 0;
            *(undefined *)(unaff_EBP + -0x167) = 0;
            *(undefined *)(unaff_EBP + -0x166) = 0;
            *(undefined *)(unaff_EBP + -0x165) = 0;
            *(undefined *)(unaff_EBP + -0x164) = 0;
            *(undefined *)(unaff_EBP + -0x163) = 0;
            *(undefined *)(unaff_EBP + -0x162) = 0;
            *(undefined *)(unaff_EBP + -0x161) = 0;
            *(undefined *)(unaff_EBP + -0x160) = 0;
            puVar8 = (undefined4 *)(unaff_EBP + -0x15f);
            for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar8 = 0;
              puVar8 = puVar8 + 1;
            }
            *(undefined2 *)puVar8 = 0;
            *(undefined *)((int)puVar8 + 2) = 0;
            *(int *)(unaff_EBP + -0x28) = iVar7 + 1;
            FUN_00401640(hFile,(LPCVOID)(unaff_EBP + -0x168),*(uint *)(unaff_EBP + -0xd6) & 0xffff);
          }
        }
        CancelIo(hFile);
        CString::CString((CString *)(unaff_EBP + -0x5c),(ushort *)u__c_c_c_c_c_c_00418064);
        *(undefined *)(unaff_EBP + -4) = 5;
        CString::Format((CString *)(*(uint *)(unaff_EBP + -0x22e) & 0xff),
                        (char *)(unaff_EBP + -0x20));
        if ((*(char *)(unaff_EBP + -0x230) == '\0') && (*(char *)(unaff_EBP + -0x22f) == '\0')) {
          CString::operator=((CString *)
                             ((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x2d8),
                             s_Nova_231G_00418058);
          *(HANDLE *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x288) = hFile;
          *(uint *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x238) =
               *(uint *)(unaff_EBP + -0xd6) & 0xffff;
          *(undefined4 *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x418) = 4;
          *(uint *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x148) =
               *(uint *)(unaff_EBP + -0x224) & 0xff;
          CString::Format((CString *)(unaff_EBP + -0x20),(char *)(unaff_EBP + -0x20));
          HidD_GetProductString();
          CString::operator=((CString *)
                             ((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x378),
                             (ushort *)(unaff_EBP + -0x430));
          CString::operator=((CString *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 4),
                             (char *)(*(int *)(unaff_EBP + -0x2c) + 4));
          *(int *)((int)unaff_ESI + 0x54) = *(int *)((int)unaff_ESI + 0x54) + 1;
        }
        *(undefined *)(unaff_EBP + -4) = 3;
        CString::~CString((CString *)(unaff_EBP + -0x5c));
      }
    }
    else {
LAB_00402268:
      *(undefined *)(unaff_EBP + -0x1c) = 1;
      *(undefined *)(unaff_EBP + -0x1b) = 0;
      *(undefined *)(unaff_EBP + -0x1a) = 0;
      FUN_00401640(hFile,(LPCVOID)(unaff_EBP + -0x1c),*(uint *)(unaff_EBP + -0xd6) & 0xffff);
      iVar7 = 0;
      if (*(short *)(unaff_EBP + -0xd8) == 8) {
        while( true ) {
          Sleep(1);
          *(undefined *)(unaff_EBP + -0x1b) = 2;
          FUN_00401740(hFile,(LPVOID)(unaff_EBP + -0x1c),*(uint *)(unaff_EBP + -0xd8) & 0xffff);
          DVar9 = GetLastError();
          if (DVar9 != 0x3e4) break;
          CancelIo(hFile);
          if (10 < iVar7) break;
          iVar7 = iVar7 + 1;
          *(undefined *)(unaff_EBP + -0x44) = 1;
          *(undefined *)(unaff_EBP + -0x43) = 0;
          *(undefined *)(unaff_EBP + -0x42) = 0;
          *(undefined *)(unaff_EBP + -0x41) = 0;
          *(undefined *)(unaff_EBP + -0x40) = 0;
          *(undefined *)(unaff_EBP + -0x3f) = 0;
          *(undefined *)(unaff_EBP + -0x3e) = 0;
          *(undefined *)(unaff_EBP + -0x3d) = 0;
          *(undefined *)(unaff_EBP + -0x3c) = 0;
          FUN_00401640(hFile,(LPCVOID)(unaff_EBP + -0x44),*(uint *)(unaff_EBP + -0xd6) & 0xffff);
        }
      }
      CancelIo(hFile);
      CString::CString((CString *)(unaff_EBP + -0x68),(ushort *)u__c_c_c_c_c_c_00418064);
      *(undefined *)(unaff_EBP + -4) = 6;
      CString::Format(*(CString **)(unaff_EBP + -0x68),(char *)(unaff_EBP + -0x20));
      if ((*(char *)(unaff_EBP + -0x1b) == '\x01') || (*(char *)(unaff_EBP + -0x1b) == '1')) {
        CString::operator=((CString *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x2d8)
                           ,(CString *)(unaff_EBP + -0x20));
        *(undefined4 *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x418) = 1;
        *(HANDLE *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x288) = hFile;
        *(uint *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x238) =
             *(uint *)(unaff_EBP + -0xd6) & 0xffff;
        HidD_GetProductString();
        CString::operator=((CString *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 0x378)
                           ,(ushort *)(unaff_EBP + -0x430));
        CString::operator=((CString *)((int)unaff_ESI + *(int *)((int)unaff_ESI + 0x54) * 4 + 4),
                           (char *)(*(int *)(unaff_EBP + -0x2c) + 4));
        *(int *)((int)unaff_ESI + 0x54) = *(int *)((int)unaff_ESI + 0x54) + 1;
      }
      *(undefined *)(unaff_EBP + -4) = 3;
      CString::~CString((CString *)(unaff_EBP + -0x68));
    }
  }
  *(undefined *)(unaff_EBP + -4) = 2;
  CString::~CString((CString *)(unaff_EBP + -0x60));
  *(undefined *)(unaff_EBP + -4) = 1;
  CString::~CString((CString *)(unaff_EBP + -0x98));
LAB_004024a0:
  CancelIo(hFile);
  CloseHandle(hFile);
  FUN_004024bc();
  return;
}



/* ==== FUN_00402520 @ 00402520 ==== */

void __thiscall FUN_00402520(void *this,DWORD param_1)

{
  int iVar1;
  CString local_28 [4];
  CString local_24 [4];
  undefined local_20;
  char local_1f;
  undefined uStack_1e;
  undefined uStack_1d;
  undefined uStack_1c;
  undefined uStack_1b;
  undefined uStack_1a;
  undefined uStack_19;
  undefined uStack_18;
  undefined uStack_17;
  undefined local_14;
  undefined4 local_13;
  undefined4 local_f;
  undefined local_b;
  undefined2 uStack_a;
  undefined *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00413e88;
  local_f._3_1_ = SUB41(ExceptionList,0);
  local_b = (undefined)((uint)ExceptionList >> 8);
  uStack_a = (undefined2)((uint)ExceptionList >> 0x10);
  ExceptionList = (void *)((int)&local_f + 3);
  CString::CString(local_28);
  local_4 = 0;
  CString::Format(local_28,(char *)local_28);
  iVar1 = *(int *)((int)this + param_1 * 4 + 0x418);
  if (iVar1 == 2) {
    local_20 = 2;
    local_1f = -0x66;
    uStack_1e = 0;
    uStack_1d = 0;
    uStack_1c = 0;
    uStack_1b = 0;
    uStack_1a = 0;
    uStack_19 = 0;
    uStack_18 = 0;
    uStack_17 = 0;
    FUN_00401480(this,param_1,0x9a,1,&local_20);
    if (local_1f == '\x12') {
      *(uint *)((int)this + param_1 * 4 + 0xf8) =
           CONCAT12(uStack_1c,CONCAT11(uStack_1d,uStack_1e)) & 0xff;
      *(uint *)((int)this + param_1 * 4 + 0x148) =
           CONCAT12(uStack_1b,CONCAT11(uStack_1c,uStack_1d)) & 0xff;
      *(uint *)((int)this + param_1 * 4 + 0x198) =
           CONCAT12(uStack_1a,CONCAT11(uStack_1b,uStack_1c)) & 0xff;
      *(uint *)((int)this + param_1 * 4 + 0x3c8) =
           CONCAT12(uStack_19,CONCAT11(uStack_1a,uStack_1b)) & 0xff;
      *(uint *)((int)this + param_1 * 4 + 0x1e8) =
           CONCAT12(uStack_18,CONCAT11(uStack_19,uStack_1a)) & 0xff;
    }
  }
  else if (iVar1 == 1) {
    local_14 = 1;
    local_f = 0;
    local_13 = 1;
    local_b = 0;
    local_1f = '\0';
    uStack_1e = 0;
    uStack_1d = 0;
    uStack_1c = 0;
    uStack_1b = 0;
    uStack_1a = 0;
    uStack_19 = 0;
    uStack_18 = 0;
    local_20 = 0;
    uStack_17 = 0;
    FUN_004026f0(this,param_1,&local_14,&local_20,5);
    CString::CString((CString *)&stack0x00000008);
    *(uint *)((int)this + param_1 * 4 + 0xf8) =
         (CONCAT12(uStack_1b,CONCAT11(uStack_1c,uStack_1d)) & 0xff) * 0x100 +
         (CONCAT12(uStack_1c,CONCAT11(uStack_1d,uStack_1e)) & 0xff);
    *(uint *)((int)this + param_1 * 4 + 0x148) =
         (CONCAT12(uStack_19,CONCAT11(uStack_1a,uStack_1b)) & 0xff) * 0x100 +
         (CONCAT12(uStack_1a,CONCAT11(uStack_1b,uStack_1c)) & 0xff);
    CString::~CString((CString *)&stack0x00000008);
  }
  CString::~CString(local_24);
  ExceptionList = local_8;
  return;
}



/* ==== FUN_004026e0 @ 004026e0 ==== */

undefined4 __fastcall FUN_004026e0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x54);
}



/* ==== FUN_004026f0 @ 004026f0 ==== */

DWORD __thiscall FUN_004026f0(void *this,DWORD param_1,LPCVOID param_2,LPVOID param_3,int param_4)

{
  DWORD DVar1;
  HANDLE pvVar2;
  DWORD DVar3;
  DWORD DVar4;
  int iVar5;
  _SECURITY_ATTRIBUTES local_c;
  
  DVar1 = param_1;
  iVar5 = 0;
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  local_c.bInheritHandle = 1;
  local_c.nLength = 0xc;
  pvVar2 = CreateFileA(*(LPCSTR *)((int)this + param_1 * 4 + 4),0xc0000000,3,&local_c,3,0x40000000,
                       (HANDLE)0x0);
  *(HANDLE *)((int)this + param_1 * 4 + 0x288) = pvVar2;
  if (pvVar2 == (HANDLE)0x0) {
    return 0;
  }
  if (*(int *)((int)this + param_1 * 4 + 0x418) == 3) {
    *(byte *)((int)param_2 + 8) =
         *(byte *)((int)param_2 + 7) ^ *(byte *)((int)param_2 + 6) ^ *(byte *)((int)param_2 + 5) ^
         *(byte *)((int)param_2 + 4) ^ *(byte *)((int)param_2 + 3);
  }
  DVar3 = FUN_00401640(*(HANDLE *)((int)this + param_1 * 4 + 0x288),param_2,
                       *(DWORD *)((int)this + param_1 * 4 + 0x238));
  if (param_4 != 0) {
    while( true ) {
      DVar3 = FUN_00401740(*(HANDLE *)((int)this + param_1 * 4 + 0x288),param_3,
                           *(DWORD *)((int)this + param_1 * 4 + 0x238));
      DVar4 = GetLastError();
      if (DVar4 != 0x3e4) break;
      *(undefined *)((int)param_3 + 1) = 0;
      CancelIo(*(HANDLE *)((int)this + param_1 * 4 + 0x288));
      if (10 < iVar5) goto LAB_00402809;
      iVar5 = iVar5 + 1;
      FUN_00401640(*(HANDLE *)((int)this + param_1 * 4 + 0x288),param_2,
                   *(DWORD *)((int)this + param_1 * 4 + 0x238));
    }
    if (DVar4 == 0x48f) {
      CString::Empty((CString *)((int)this + param_1 * 4 + 4));
    }
  }
LAB_00402809:
  param_1 = DVar3;
  CloseHandle(*(HANDLE *)((int)this + DVar1 * 4 + 0x288));
  *(undefined4 *)((int)this + DVar1 * 4 + 0x288) = 0;
  return param_1;
}



/* ==== CMap<> @ 00402830 ==== */

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall CMap<void *,void *,void *,void *>::CMap<void *,void *,void *,void *>(int)
    public: __thiscall CMap<class ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class
   ATL::ChTraitsOS<wchar_t> > >,wchar_t const *,void *,void *>::CMap<class
   ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsOS<wchar_t> > >,wchar_t const
   *,void *,void *>(int)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __thiscall CMap<>(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined ***)this = &PTR_LAB_0041549c;
  *(undefined4 *)((int)this + 8) = 0x11;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return;
}



/* ==== FUN_00402860 @ 00402860 ==== */

void __fastcall FUN_00402860(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00413ea8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_0041549c;
  local_4 = 0;
  if ((param_1[1] != 0) && (uVar2 = 0, param_1[2] != 0)) {
    do {
      for (puVar1 = *(undefined4 **)(param_1[1] + uVar2 * 4); puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        DestructElements((CString *)(puVar1 + 3),1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)param_1[2]);
  }
  operator_delete((void *)param_1[1]);
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  CPlex::FreeDataChain((CPlex *)param_1[5]);
  param_1[5] = 0;
  *param_1 = &PTR_LAB_004154b0;
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00402bb0 @ 00402bb0 ==== */

void __thiscall FUN_00402bb0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined ***)this = &PTR_LAB_004154c4;
  *(undefined4 *)((int)this + 8) = 0x11;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return;
}



/* ==== FUN_00402be0 @ 00402be0 ==== */

void __fastcall FUN_00402be0(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00413ee8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_004154c4;
  local_4 = 0;
  if ((param_1[1] != 0) && (uVar2 = 0, param_1[2] != 0)) {
    do {
      for (puVar1 = *(undefined4 **)(param_1[1] + uVar2 * 4); puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        DestructElements((CString *)(puVar1 + 3),1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)param_1[2]);
  }
  operator_delete((void *)param_1[1]);
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  CPlex::FreeDataChain((CPlex *)param_1[5]);
  param_1[5] = 0;
  *param_1 = &PTR_LAB_004154b0;
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00402ca0 @ 00402ca0 ==== */

void __fastcall FUN_00402ca0(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_004154b0;
  return;
}



/* ==== FUN_00402cb0 @ 00402cb0 ==== */

void __thiscall FUN_00402cb0(void *this,CArchive *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  CPlex *pCVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint *local_20;
  uint local_1c;
  void *local_18;
  uint local_14;
  ulong local_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00413f08;
  local_c = ExceptionList;
  local_18 = this;
  if ((~*(uint *)(param_1 + 0x14) & 1) == 0) {
    ExceptionList = &local_c;
    for (local_10 = CArchive::ReadCount(param_1); local_10 != 0; local_10 = local_10 - 1) {
      CString::CString((CString *)&local_14);
      local_4 = 0;
      uVar8 = 1;
      if ((~*(uint *)(param_1 + 0x14) & 1) == 0) {
        local_20 = &local_1c;
        do {
          uVar6 = uVar8;
          if (0x1ffffffe < uVar8) {
            uVar6 = 0x1fffffff;
          }
          CArchive::Read(param_1,local_20,uVar6 * 4);
          uVar8 = uVar8 - uVar6;
          local_20 = local_20 + uVar6;
        } while (uVar8 != 0);
      }
      else {
        local_20 = &local_1c;
        do {
          uVar6 = uVar8;
          if (0x1ffffffe < uVar8) {
            uVar6 = 0x1fffffff;
          }
          CArchive::Write(param_1,local_20,uVar6 * 4);
          uVar8 = uVar8 - uVar6;
          local_20 = local_20 + uVar6;
        } while (uVar8 != 0);
      }
      SerializeElements(param_1,(CString *)&local_14,1);
      uVar8 = *(uint *)((int)this + 8);
      uVar6 = (local_1c >> 4) % uVar8;
      iVar5 = *(int *)((int)this + 4);
      if (iVar5 == 0) {
LAB_00402ec8:
        puVar2 = (undefined4 *)operator_new(uVar8 * 4);
        *(undefined4 **)((int)this + 4) = puVar2;
        for (uVar4 = uVar8 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined *)puVar2 = 0;
          puVar2 = (undefined4 *)((int)puVar2 + 1);
        }
        *(uint *)((int)this + 8) = uVar8;
      }
      else {
        for (puVar2 = *(undefined4 **)(iVar5 + uVar6 * 4); puVar2 != (undefined4 *)0x0;
            puVar2 = (undefined4 *)*puVar2) {
          if (puVar2[2] == local_1c) {
            if (puVar2 != (undefined4 *)0x0) goto LAB_00402f6b;
            break;
          }
        }
        if (iVar5 == 0) goto LAB_00402ec8;
      }
      if (*(int *)((int)this + 0x10) == 0) {
        pCVar3 = CPlex::Create((CPlex **)((int)this + 0x14),*(uint *)((int)this + 0x18),0x10);
        iVar5 = *(int *)((int)this + 0x18);
        pCVar3 = pCVar3 + iVar5 * 0x10 + -0xc;
        if (-1 < iVar5 + -1) {
          do {
            *(undefined4 *)pCVar3 = *(undefined4 *)((int)this + 0x10);
            *(CPlex **)((int)this + 0x10) = pCVar3;
            pCVar3 = pCVar3 + -0x10;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
      pvVar1 = local_18;
      puVar2 = *(undefined4 **)((int)this + 0x10);
      *(undefined4 *)((int)local_18 + 0x10) = *puVar2;
      *(int *)((int)local_18 + 0xc) = *(int *)((int)local_18 + 0xc) + 1;
      puVar2[2] = 0;
      ConstructElements((CString *)(puVar2 + 3),1);
      puVar2[1] = uVar6;
      puVar2[2] = local_1c;
      *puVar2 = *(undefined4 *)(*(int *)((int)pvVar1 + 4) + uVar6 * 4);
      *(undefined4 **)(*(int *)((int)pvVar1 + 4) + uVar6 * 4) = puVar2;
      this = pvVar1;
LAB_00402f6b:
      CString::operator=((CString *)(puVar2 + 3),(CString *)&local_14);
      local_4 = 0xffffffff;
      CString::~CString((CString *)&local_14);
    }
  }
  else {
    ExceptionList = &local_c;
    CArchive::WriteCount(param_1,*(ulong *)((int)this + 0xc));
    if ((*(int *)((int)this + 0xc) != 0) && (local_14 = 0, *(int *)((int)this + 8) != 0)) {
      do {
        for (puVar2 = *(undefined4 **)(*(int *)((int)this + 4) + local_14 * 4);
            puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
          puVar7 = puVar2 + 2;
          uVar8 = 1;
          if ((~*(uint *)(param_1 + 0x14) & 1) == 0) {
            do {
              uVar6 = uVar8;
              if (0x1ffffffe < uVar8) {
                uVar6 = 0x1fffffff;
              }
              CArchive::Read(param_1,puVar7,uVar6 * 4);
              uVar8 = uVar8 - uVar6;
              puVar7 = puVar7 + uVar6;
            } while (uVar8 != 0);
          }
          else {
            do {
              uVar6 = uVar8;
              if (0x1ffffffe < uVar8) {
                uVar6 = 0x1fffffff;
              }
              CArchive::Write(param_1,puVar7,uVar6 * 4);
              uVar8 = uVar8 - uVar6;
              puVar7 = puVar7 + uVar6;
            } while (uVar8 != 0);
          }
          SerializeElements(param_1,(CString *)(puVar2 + 3),1);
          this = local_18;
        }
        local_14 = local_14 + 1;
      } while (local_14 < *(uint *)((int)this + 8));
    }
  }
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00402fc0 @ 00402fc0 ==== */

undefined4 * __thiscall FUN_00402fc0(void *this,byte param_1)

{
  FUN_00402860((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



/* ==== FUN_00402fe0 @ 00402fe0 ==== */

undefined4 * __thiscall FUN_00402fe0(void *this,byte param_1)

{
  FUN_00402be0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



/* ==== FUN_00403000 @ 00403000 ==== */

undefined4 * __fastcall FUN_00403000(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00413f7e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00413a0c(param_1 + 1,4,0x14,CString::CString);
  local_4 = 0;
  FUN_00413a0c(param_1 + 0xf7,4,0x14,CString::CString);
  local_4._0_1_ = 1;
  FUN_00413a0c(param_1 + 0x10b,4,0x14,CString::CString);
  local_4._0_1_ = 2;
  FUN_00413a0c(param_1 + 0x139,4,0x14,CString::CString);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_00413a0c(param_1 + 0x14d,4,0x14,CString::CString);
  *param_1 = &PTR_FUN_004154d8;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  param_1[0x15] = 0;
  puVar2 = param_1 + 0x124;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x138] = 0;
  ExceptionList = pvStack_c;
  return param_1;
}



/* ==== FUN_00403100 @ 00403100 ==== */

undefined4 * __thiscall FUN_00403100(void *this,byte param_1)

{
  FUN_00403120((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



/* ==== FUN_00403120 @ 00403120 ==== */

void __fastcall FUN_00403120(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  void *local_c;
  undefined *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00413fee;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_004154d8;
  local_4 = 3;
  puVar2 = param_1 + 0xcf;
  iVar1 = 0x14;
  do {
    if ((HANDLE)puVar2[0x55] != (HANDLE)0x0) {
      CloseHandle((HANDLE)puVar2[0x55]);
    }
    if ((HANDLE)*puVar2 != (HANDLE)0x0) {
      CloseHandle((HANDLE)*puVar2);
    }
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00413918(param_1 + 0x14d,4,0x14,CString::~CString);
  local_4._0_1_ = 2;
  FUN_00413918(param_1 + 0x139,4,0x14,CString::~CString);
  local_4._0_1_ = 1;
  FUN_00413918(param_1 + 0x10b,4,0x14,CString::~CString);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00413918(param_1 + 0xf7,4,0x14,CString::~CString);
  local_4 = 0xffffffff;
  FUN_00413918(param_1 + 1,4,0x14,CString::~CString);
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00403210 @ 00403210 ==== */

undefined4 __fastcall FUN_00403210(int param_1)

{
  char cVar1;
  HDEVINFO DeviceInfoSet;
  DWORD DVar2;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_A DeviceInterfaceDetailData;
  HANDLE hFile;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  DWORD dwLanguageId;
  char **lpBuffer;
  DWORD nSize;
  va_list *Arguments;
  char local_c68 [2048];
  ushort local_468 [256];
  undefined local_268 [2];
  char local_266 [4];
  undefined2 uStack_262;
  byte local_260;
  undefined local_1a0;
  undefined local_19f;
  undefined local_19e;
  char local_19d;
  _SP_DEVICE_INTERFACE_DATA local_d8;
  short local_bc;
  short local_ba;
  uint local_b8;
  uint local_b4;
  undefined local_7c [4];
  undefined2 uStack_78;
  _SECURITY_ATTRIBUTES local_70;
  char local_64 [8];
  CHAR *local_5c;
  CString local_58 [4];
  PSP_DEVICE_INTERFACE_DETAIL_DATA_A local_54;
  CString local_50 [4];
  BOOL local_4c;
  int local_48;
  GUID local_44;
  char *local_30;
  HDEVINFO local_2c;
  uchar *local_28;
  undefined4 local_24;
  CString local_20 [4];
  undefined4 local_1c;
  DWORD local_18;
  undefined *local_14;
  void *pvStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00414010;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xfffff38c;
  ExceptionList = &pvStack_10;
  local_48 = param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  puVar5 = (undefined4 *)(param_1 + 0x58);
  local_18 = 0;
  do {
    puVar5[0x200] = 0;
    *puVar5 = 0;
    puVar5[0x14] = 0;
    puVar5[0x28] = 0;
    puVar5[0x3c] = 0;
    puVar5[0x50] = 0;
    puVar5[0xa0] = 0;
    puVar5[0x78] = 0;
    puVar5[0x8c] = 0;
    puVar5[100] = 0;
    puVar5[0xb9] = 0;
    CString::operator=((CString *)(puVar5 + 0xf5),&DAT_00419e94);
    CString::Empty((CString *)(puVar5 + -0x15));
    CString::Empty((CString *)(puVar5 + 0xe1));
    puVar5[0xb9] = 0;
    *(undefined *)(param_1 + 0x328 + local_18) = 0;
    if ((HANDLE)puVar5[0x10e] != (HANDLE)0x0) {
      ResetEvent((HANDLE)puVar5[0x10e]);
      CloseHandle((HANDLE)puVar5[0x10e]);
    }
    puVar5[0x10e] = 0;
    puVar5[0xcd] = 0;
    local_18 = local_18 + 1;
    puVar5 = puVar5 + 1;
  } while ((int)local_18 < 0x14);
  *(undefined4 *)(param_1 + 0x584) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  CString::CString(local_20);
  local_8 = 0;
  HidD_GetHidGuid(&local_44);
  sprintf(local_c68,&DAT_0041812c,local_44.Data1,local_44.Data2,
          CONCAT12(local_44.Data4[0],local_44.Data3) & 0xffff,
          CONCAT12(local_44.Data4[2],CONCAT11(local_44.Data4[1],local_44.Data4[0])) & 0xff,
          CONCAT12(local_44.Data4[3],CONCAT11(local_44.Data4[2],local_44.Data4[1])) & 0xff,
          CONCAT12(local_44.Data4[4],CONCAT11(local_44.Data4[3],local_44.Data4[2])) & 0xff,
          CONCAT12(local_44.Data4[5],CONCAT11(local_44.Data4[4],local_44.Data4[3])) & 0xff,
          CONCAT12(local_44.Data4[6],CONCAT11(local_44.Data4[5],local_44.Data4[4])) & 0xff,
          CONCAT12(local_44.Data4[7],CONCAT11(local_44.Data4[6],local_44.Data4[5])) & 0xff,
          CONCAT11(local_44.Data4[7],local_44.Data4[6]) & 0xff,local_44.Data4[7]);
  DeviceInfoSet = SetupDiGetClassDevsA(&local_44,(PCSTR)0x0,(HWND)0x0,0x12);
  local_2c = DeviceInfoSet;
  if (DeviceInfoSet == (HDEVINFO)0xffffffff) {
LAB_0040386b:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
    local_8 = 0xffffffff;
    CString::~CString(local_20);
    ExceptionList = pvStack_10;
    return 0;
  }
  local_1c = 0;
  local_d8.cbSize = 0x1c;
  local_4c = SetupDiEnumDeviceInterfaces(DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,&local_44,0,&local_d8);
  if ((local_4c == 0) && (DVar2 = GetLastError(), DVar2 == 0x103)) {
    SetupDiDestroyDeviceInfoList(DeviceInfoSet);
    goto LAB_0040386b;
  }
  local_18 = 0;
  SetupDiGetDeviceInterfaceDetailA
            (DeviceInfoSet,&local_d8,(PSP_DEVICE_INTERFACE_DETAIL_DATA_A)0x0,0,&local_18,
             (PSP_DEVINFO_DATA)0x0);
  DeviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)malloc(local_18);
  DeviceInterfaceDetailData->cbSize = 5;
  local_54 = DeviceInterfaceDetailData;
  SetupDiGetDeviceInterfaceDetailA
            (local_2c,&local_d8,DeviceInterfaceDetailData,local_18,(PDWORD)0x0,(PSP_DEVINFO_DATA)0x0
            );
  local_5c = DeviceInterfaceDetailData->DevicePath;
  local_8._0_1_ = 1;
  local_70.lpSecurityDescriptor = (LPVOID)0x0;
  local_70.bInheritHandle = 1;
  local_70.nLength = 0xc;
  hFile = CreateFileA(local_5c,0,3,&local_70,3,0x40000000,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    Arguments = (va_list *)0x0;
    lpBuffer = &local_30;
    nSize = 0;
    dwLanguageId = 0x400;
    DVar2 = GetLastError();
    FormatMessageA(0x1100,(LPCVOID)0x0,DVar2,dwLanguageId,(LPSTR)lpBuffer,nSize,Arguments);
    CString::operator=(local_20,local_30);
    LocalFree(local_30);
    uVar3 = FUN_00403856();
    return uVar3;
  }
  local_24 = 0;
  HidD_GetPreparsedData(hFile,&local_24);
  HidP_GetCaps(local_24,&local_bc);
  HidD_FreePreparsedData(local_24);
  CString::CString((CString *)&local_28);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((local_bc == 1) && (((local_ba == -0xfd || (local_ba == -0xee)) && ((short)local_b8 == 8)))) {
    CString::operator=((CString *)(param_1 + 0x3dc + *(int *)(param_1 + 0x584) * 4),local_5c);
    *(uint *)(param_1 + 0x288 + *(int *)(param_1 + 0x584) * 4) = local_b8 & 0xffff;
    CString::CString(local_50);
    *(int *)(param_1 + 0x584) = *(int *)(param_1 + 0x584) + 1;
    CancelIo(hFile);
    CloseHandle(hFile);
    CString::~CString(local_50);
  }
  else if ((short)local_b4 == 9) {
    HidD_GetAttributes(hFile,local_7c);
    cVar1 = HidD_GetIndexedString(hFile,0xfa,local_468,0x200);
    if (cVar1 != '\0') {
      CString::operator=((CString *)&local_28,local_468);
      iVar4 = _mbscmp(local_28,(uchar *)s_Areson_00418510);
      if (iVar4 == 0) {
        HidD_GetIndexedString(hFile,0x32,local_468,0x200);
      }
    }
    local_1a0 = 0;
    local_19f = 0;
    local_19e = 0;
    iVar4 = FUN_00403960(hFile,&local_1a0,local_268,local_b4 & 0xffff,2);
    if (((iVar4 == 1) && (local_266[0] == '\f')) && (local_266[1] == '\x12')) {
      CString::CString(local_58);
      CString::~CString(local_58);
      *(uint *)(param_1 + 0xf8 + *(int *)(param_1 + 0x54) * 4) =
           CONCAT11(local_266[3],local_266[2]) & 0xff;
      *(uint *)(param_1 + 0x148 + *(int *)(param_1 + 0x54) * 4) =
           (CONCAT12(local_260,uStack_262) & 0xff) * 0x100 +
           (CONCAT21(uStack_262,local_266[3]) & 0xff);
      *(uint *)(param_1 + 0x808 + *(int *)(param_1 + 0x54) * 4) = (uint)local_260;
      local_1a0 = 0;
      local_19f = 0;
      local_19e = 1;
      FUN_00403960(hFile,&local_1a0,local_268,local_b4 & 0xffff,8);
      for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
        local_64[iVar4] = local_266[iVar4];
      }
      local_64[6] = 0;
      CString::operator=((CString *)(param_1 + 0x42c + *(int *)(param_1 + 0x54) * 4),local_64);
      *(char *)(*(int *)(param_1 + 0x54) + 0x47c + param_1) = DAT_0041816c;
      local_19d = DAT_0041816c;
      local_1a0 = 0;
      local_19f = 0;
      local_19e = 2;
      FUN_00403960(hFile,&local_1a0,local_268,local_b4 & 0xffff,8);
      DAT_0041816c = DAT_0041816c + '\x01';
      *(HANDLE *)(param_1 + 0x33c + *(int *)(param_1 + 0x54) * 4) = hFile;
      *(uint *)(param_1 + 0x238 + *(int *)(param_1 + 0x54) * 4) = local_b4 & 0xffff;
      *(uint *)(param_1 + 0x2d8 + *(int *)(param_1 + 0x54) * 4) = local_b4 & 0xffff;
      *(undefined4 *)(param_1 + 0x858 + *(int *)(param_1 + 0x54) * 4) = 1;
      CString::operator=((CString *)(param_1 + 4 + *(int *)(param_1 + 0x54) * 4),
                         local_54->DevicePath);
      HidD_GetProductString(hFile,local_468,0x200);
      CString::operator=((CString *)(param_1 + 0x534 + *(int *)(param_1 + 0x54) * 4),local_468);
      CString::Format(uStack_78,(char *)(param_1 + 0x4e4 + *(int *)(param_1 + 0x54) * 4));
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
      goto LAB_00403833;
    }
    Sleep(10);
  }
  CancelIo(hFile);
  CloseHandle(hFile);
LAB_00403833:
  local_8 = CONCAT31(local_8._1_3_,1);
  CString::~CString((CString *)&local_28);
  uVar3 = FUN_00403856();
  return uVar3;
}



/* ==== Catch@0040384b @ 0040384b ==== */

undefined * Catch_0040384b(void)

{
  return &DAT_00403851;
}



/* ==== FUN_00403856 @ 00403856 ==== */

undefined4 FUN_00403856(void)

{
  HDEVINFO pvVar1;
  char cVar2;
  PSP_DEVINFO_DATA p_Var3;
  DWORD DVar4;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_A DeviceInterfaceDetailData;
  HANDLE hFile;
  undefined4 uVar5;
  int iVar6;
  undefined uVar7;
  PSP_DEVINFO_DATA unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  DWORD dwLanguageId;
  LPSTR lpBuffer;
  PSP_DEVINFO_DATA Arguments;
  
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -4) = unaff_EBX;
  *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
  if (*(PSP_DEVINFO_DATA *)(unaff_EBP + -0x48) == unaff_EBX) {
LAB_0040386b:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    CString::~CString((CString *)(unaff_EBP + -0x1c));
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0;
  }
  pvVar1 = *(HDEVINFO *)(unaff_EBP + -0x28);
  p_Var3 = (PSP_DEVINFO_DATA)
           SetupDiEnumDeviceInterfaces
                     (pvVar1,unaff_EBX,(GUID *)(unaff_EBP + -0x40),*(DWORD *)(unaff_EBP + -0x18),
                      (PSP_DEVICE_INTERFACE_DATA)(unaff_EBP + -0xd4));
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -0x48) = p_Var3;
  if (p_Var3 == unaff_EBX) {
    DVar4 = GetLastError();
    if (DVar4 == 0x103) {
      SetupDiDestroyDeviceInfoList(pvVar1);
      goto LAB_0040386b;
    }
  }
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -0x14) = unaff_EBX;
  SetupDiGetDeviceInterfaceDetailA
            (pvVar1,(PSP_DEVICE_INTERFACE_DATA)(unaff_EBP + -0xd4),
             (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)unaff_EBX,(DWORD)unaff_EBX,
             (PDWORD)(unaff_EBP + -0x14),unaff_EBX);
  DeviceInterfaceDetailData =
       (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)malloc(*(size_t *)(unaff_EBP + -0x14));
  pvVar1 = *(HDEVINFO *)(unaff_EBP + -0x28);
  DeviceInterfaceDetailData->cbSize = 5;
  *(PSP_DEVICE_INTERFACE_DETAIL_DATA_A *)(unaff_EBP + -0x50) = DeviceInterfaceDetailData;
  SetupDiGetDeviceInterfaceDetailA
            (pvVar1,(PSP_DEVICE_INTERFACE_DATA)(unaff_EBP + -0xd4),DeviceInterfaceDetailData,
             *(DWORD *)(unaff_EBP + -0x14),&unaff_EBX->cbSize,unaff_EBX);
  *(undefined *)(unaff_EBP + -4) = 1;
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -0x68) = unaff_EBX;
  *(undefined4 *)(unaff_EBP + -100) = 1;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0xc;
  *(CHAR **)(unaff_EBP + -0x58) = DeviceInterfaceDetailData->DevicePath;
  hFile = CreateFileA(DeviceInterfaceDetailData->DevicePath,(DWORD)unaff_EBX,3,
                      (LPSECURITY_ATTRIBUTES)(unaff_EBP + -0x6c),3,0x40000000,unaff_EBX);
  if (hFile == (HANDLE)0xffffffff) {
    lpBuffer = (LPSTR)(unaff_EBP + -0x2c);
    dwLanguageId = 0x400;
    p_Var3 = unaff_EBX;
    Arguments = unaff_EBX;
    DVar4 = GetLastError();
    FormatMessageA(0x1100,unaff_EBX,DVar4,dwLanguageId,lpBuffer,(DWORD)p_Var3,(va_list *)Arguments);
    CString::operator=((CString *)(unaff_EBP + -0x1c),*(char **)(unaff_EBP + -0x2c));
    LocalFree(*(HLOCAL *)(unaff_EBP + -0x2c));
    uVar5 = FUN_00403856();
    return uVar5;
  }
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -0x20) = unaff_EBX;
  HidD_GetPreparsedData(hFile,unaff_EBP + -0x20);
  HidP_GetCaps(*(undefined4 *)(unaff_EBP + -0x20),unaff_EBP + -0xb8);
  HidD_FreePreparsedData(*(undefined4 *)(unaff_EBP + -0x20));
  CString::CString((CString *)(unaff_EBP + -0x24));
  *(undefined *)(unaff_EBP + -4) = 2;
  if (*(short *)(unaff_EBP + -0xb8) == 1) {
    if (*(short *)(unaff_EBP + -0xb6) != -0xfd) {
      if ((*(short *)(unaff_EBP + -0xb6) == -0xee) && (*(short *)(unaff_EBP + -0xb4) == 8))
      goto LAB_00403695;
      goto LAB_00403506;
    }
    if (*(short *)(unaff_EBP + -0xb4) != 8) goto LAB_00403506;
LAB_00403695:
    CString::operator=((CString *)(unaff_ESI + 0x3dc + *(int *)(unaff_ESI + 0x584) * 4),
                       *(char **)(unaff_EBP + -0x58));
    *(uint *)(unaff_ESI + 0x288 + *(int *)(unaff_ESI + 0x584) * 4) =
         *(uint *)(unaff_EBP + -0xb4) & 0xffff;
    CString::CString((CString *)(unaff_EBP + -0x4c));
    *(int *)(unaff_ESI + 0x584) = *(int *)(unaff_ESI + 0x584) + 1;
    CancelIo(hFile);
    CloseHandle(hFile);
    CString::~CString((CString *)(unaff_EBP + -0x4c));
  }
  else {
LAB_00403506:
    if (*(short *)(unaff_EBP + -0xb0) == 9) {
      HidD_GetAttributes(hFile,unaff_EBP + -0x78);
      cVar2 = HidD_GetIndexedString(hFile,0xfa,unaff_EBP + -0x464,0x200);
      if (cVar2 != '\0') {
        CString::operator=((CString *)(unaff_EBP + -0x24),(ushort *)(unaff_EBP + -0x464));
        iVar6 = _mbscmp(*(uchar **)(unaff_EBP + -0x24),(uchar *)s_Areson_00418510);
        if (iVar6 == 0) {
          HidD_GetIndexedString(hFile,0x32,unaff_EBP + -0x464,0x200);
        }
      }
      uVar7 = SUB41(unaff_EBX,0);
      *(undefined *)(unaff_EBP + -0x19c) = uVar7;
      *(undefined *)(unaff_EBP + -0x19b) = uVar7;
      *(undefined *)(unaff_EBP + -0x19a) = uVar7;
      iVar6 = FUN_00403960(hFile,(undefined *)(unaff_EBP + -0x19c),(undefined *)(unaff_EBP + -0x264)
                           ,*(uint *)(unaff_EBP + -0xb0) & 0xffff,2);
      if (((iVar6 == 1) && (*(char *)(unaff_EBP + -0x262) == '\f')) &&
         (*(char *)(unaff_EBP + -0x261) == '\x12')) {
        CString::CString((CString *)(unaff_EBP + -0x54));
        CString::~CString((CString *)(unaff_EBP + -0x54));
        *(uint *)(unaff_ESI + 0xf8 + *(int *)(unaff_ESI + 0x54) * 4) =
             *(uint *)(unaff_EBP + -0x260) & 0xff;
        *(uint *)(unaff_ESI + 0x148 + *(int *)(unaff_ESI + 0x54) * 4) =
             (*(uint *)(unaff_EBP + -0x25e) & 0xff) * 0x100 + (*(uint *)(unaff_EBP + -0x25f) & 0xff)
        ;
        *(uint *)(unaff_ESI + 0x808 + *(int *)(unaff_ESI + 0x54) * 4) =
             *(uint *)(unaff_EBP + -0x25c) & 0xff;
        *(undefined *)(unaff_EBP + -0x19c) = uVar7;
        *(undefined *)(unaff_EBP + -0x19b) = uVar7;
        *(undefined *)(unaff_EBP + -0x19a) = 1;
        FUN_00403960(hFile,(undefined *)(unaff_EBP + -0x19c),(undefined *)(unaff_EBP + -0x264),
                     *(uint *)(unaff_EBP + -0xb0) & 0xffff,8);
        for (iVar6 = 0; iVar6 < 6; iVar6 = iVar6 + 1) {
          *(undefined *)(unaff_EBP + -0x60 + iVar6) = *(undefined *)(unaff_EBP + -0x262 + iVar6);
        }
        iVar6 = *(int *)(unaff_ESI + 0x54);
        *(undefined *)(unaff_EBP + -0x5a) = uVar7;
        CString::operator=((CString *)(unaff_ESI + 0x42c + iVar6 * 4),(char *)(unaff_EBP + -0x60));
        *(char *)(*(int *)(unaff_ESI + 0x54) + 0x47c + unaff_ESI) = DAT_0041816c;
        *(char *)(unaff_EBP + -0x199) = DAT_0041816c;
        *(undefined *)(unaff_EBP + -0x19c) = uVar7;
        *(undefined *)(unaff_EBP + -0x19b) = uVar7;
        *(undefined *)(unaff_EBP + -0x19a) = 2;
        FUN_00403960(hFile,(undefined *)(unaff_EBP + -0x19c),(undefined *)(unaff_EBP + -0x264),
                     *(uint *)(unaff_EBP + -0xb0) & 0xffff,8);
        DAT_0041816c = DAT_0041816c + '\x01';
        *(HANDLE *)(unaff_ESI + 0x33c + *(int *)(unaff_ESI + 0x54) * 4) = hFile;
        *(uint *)(unaff_ESI + 0x238 + *(int *)(unaff_ESI + 0x54) * 4) =
             *(uint *)(unaff_EBP + -0xb0) & 0xffff;
        *(uint *)(unaff_ESI + 0x2d8 + *(int *)(unaff_ESI + 0x54) * 4) =
             *(uint *)(unaff_EBP + -0xb0) & 0xffff;
        iVar6 = *(int *)(unaff_EBP + -0x50);
        *(undefined4 *)(unaff_ESI + 0x858 + *(int *)(unaff_ESI + 0x54) * 4) = 1;
        CString::operator=((CString *)(unaff_ESI + 4 + *(int *)(unaff_ESI + 0x54) * 4),
                           (char *)(iVar6 + 4));
        HidD_GetProductString(hFile,unaff_EBP + -0x464,0x200);
        CString::operator=((CString *)(unaff_ESI + 0x534 + *(int *)(unaff_ESI + 0x54) * 4),
                           (ushort *)(unaff_EBP + -0x464));
        CString::Format((CString *)(*(uint *)(unaff_EBP + -0x74) & 0xffff),
                        (char *)(unaff_ESI + 0x4e4 + *(int *)(unaff_ESI + 0x54) * 4));
        *(int *)(unaff_ESI + 0x54) = *(int *)(unaff_ESI + 0x54) + 1;
        if (unaff_EBX != (PSP_DEVINFO_DATA)0x1) goto LAB_00403833;
      }
      else {
        Sleep(10);
      }
    }
  }
  CancelIo(hFile);
  CloseHandle(hFile);
LAB_00403833:
  *(undefined *)(unaff_EBP + -4) = 1;
  CString::~CString((CString *)(unaff_EBP + -0x24));
  uVar5 = FUN_00403856();
  return uVar5;
}



/* ==== FUN_004038a0 @ 004038a0 ==== */

void __thiscall
FUN_004038a0(void *this,int param_1,undefined *param_2,undefined *param_3,DWORD param_4)

{
  FUN_00403960(*(undefined4 *)((int)this + param_1 * 4 + 0x33c),param_2,param_3,
               *(undefined4 *)((int)this + param_1 * 4 + 0x238),param_4);
  return;
}



/* ==== FUN_004038d0 @ 004038d0 ==== */

void __fastcall FUN_004038d0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  iVar2 = 0;
  puVar1 = (undefined4 *)(param_1 + 0x58);
  do {
    puVar1[0x200] = 0;
    *puVar1 = 0;
    puVar1[0x14] = 0;
    puVar1[0x28] = 0;
    puVar1[0x3c] = 0;
    puVar1[0x50] = 0;
    puVar1[0xa0] = 0;
    puVar1[0x78] = 0;
    puVar1[100] = 0;
    puVar1[0xb9] = 0;
    CString::operator=((CString *)(puVar1 + 0xf5),&DAT_00419e94);
    CString::Empty((CString *)(puVar1 + -0x15));
    puVar1[0xb9] = 0;
    *(undefined *)(iVar2 + 0x328 + param_1) = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 0x14);
  *(undefined4 *)(param_1 + 0x54) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  return;
}



/* ==== FUN_00403960 @ 00403960 ==== */

undefined4
FUN_00403960(undefined4 param_1,undefined *param_2,undefined *param_3,undefined4 param_4,
            DWORD param_5)

{
  char cVar1;
  int iVar2;
  undefined uStack_c8;
  byte bStack_c7;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  iVar2 = 0;
  while( true ) {
    uStack_c8 = 0;
    cVar1 = HidD_GetFeature(param_1,&uStack_c8,param_4);
    if ((cVar1 != '\0') && ((bStack_c7 & 0x80) == 0)) break;
    iVar2 = iVar2 + 1;
    if (0x14 < iVar2) goto LAB_00403a19;
    Sleep(4);
  }
  if (4 < (int)param_5) {
    Sleep(1);
  }
  *param_2 = 0;
  HidD_SetFeature(param_1,param_2,param_4);
  if (0 < (int)param_5) {
    Sleep(param_5);
  }
  iVar2 = 0;
  while( true ) {
    *param_3 = 0;
    cVar1 = HidD_GetFeature(param_1,param_3,param_4);
    if ((cVar1 != '\0') && ((param_3[1] & 0x40) == 0x40)) {
      param_3[1] = param_3[1] & 0x3f;
      if (4 < (int)param_5) {
        Sleep(1);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
      return 1;
    }
    iVar2 = iVar2 + 1;
    if (200 < iVar2) break;
    Sleep(4);
  }
LAB_00403a19:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  return 0;
}



/* ==== FUN_00403a70 @ 00403a70 ==== */

undefined4 __thiscall FUN_00403a70(void *this,int param_1)

{
  char cVar1;
  int iVar2;
  undefined uStack_258;
  undefined uStack_257;
  undefined uStack_256;
  undefined uStack_255;
  undefined uStack_250;
  undefined uStack_190;
  byte bStack_18f;
  undefined uStack_c8;
  byte bStack_c7;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  iVar2 = 0;
  while( true ) {
    uStack_190 = 0;
    cVar1 = HidD_GetFeature(*(undefined4 *)((int)this + param_1 * 4 + 0x33c),&uStack_190,
                            *(undefined4 *)((int)this + param_1 * 4 + 0x238));
    if ((cVar1 != '\0') && ((bStack_18f & 0x80) == 0)) break;
    iVar2 = iVar2 + 1;
    if (10 < iVar2) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
      return 0;
    }
    Sleep(4);
  }
  Sleep(1);
  uStack_258 = 0;
  uStack_257 = 1;
  uStack_256 = 2;
  uStack_255 = 0;
  uStack_250 = 0x12;
  HidD_SetFeature(*(undefined4 *)((int)this + param_1 * 4 + 0x33c),&uStack_258,
                  *(undefined4 *)((int)this + param_1 * 4 + 0x238));
  Sleep(100);
  iVar2 = 0;
  while( true ) {
    uStack_c8 = 0;
    cVar1 = HidD_GetFeature(*(undefined4 *)((int)this + param_1 * 4 + 0x33c),&uStack_c8,
                            *(undefined4 *)((int)this + param_1 * 4 + 0x238));
    if ((cVar1 != '\0') && ((bStack_c7 & 0x40) == 0x40)) break;
    iVar2 = iVar2 + 1;
    if (10 < iVar2) {
      return 0;
    }
    Sleep(4);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  return 1;
}



/* ==== FUN_00403b90 @ 00403b90 ==== */

undefined4 __thiscall FUN_00403b90(void *this,int param_1)

{
  char cVar1;
  int iVar2;
  undefined uStack_258;
  undefined uStack_257;
  undefined uStack_256;
  undefined uStack_255;
  undefined uStack_254;
  undefined uStack_190;
  byte bStack_18f;
  undefined uStack_c8;
  byte bStack_c7;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  iVar2 = 0;
  while( true ) {
    uStack_190 = 0;
    cVar1 = HidD_GetFeature(*(undefined4 *)((int)this + param_1 * 4 + 0x33c),&uStack_190,
                            *(undefined4 *)((int)this + param_1 * 4 + 0x238));
    if ((cVar1 != '\0') && ((bStack_18f & 0x80) == 0)) break;
    iVar2 = iVar2 + 1;
    if (10 < iVar2) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
      return 0;
    }
    Sleep(4);
  }
  Sleep(1);
  uStack_258 = 0;
  uStack_257 = 3;
  uStack_256 = 2;
  uStack_255 = 0xc;
  uStack_254 = 0x12;
  HidD_SetFeature(*(undefined4 *)((int)this + param_1 * 4 + 0x33c),&uStack_258,
                  *(undefined4 *)((int)this + param_1 * 4 + 0x238));
  Sleep(100);
  iVar2 = 0;
  while( true ) {
    uStack_c8 = 0;
    cVar1 = HidD_GetFeature(*(undefined4 *)((int)this + param_1 * 4 + 0x33c),&uStack_c8,
                            *(undefined4 *)((int)this + param_1 * 4 + 0x238));
    if ((cVar1 != '\0') && ((bStack_c7 & 0x40) == 0x40)) break;
    iVar2 = iVar2 + 1;
    if (10 < iVar2) {
      return 0;
    }
    Sleep(4);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419e98);
  return 1;
}



/* ==== FUN_00403cb0 @ 00403cb0 ==== */

undefined4 * __fastcall FUN_00403cb0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00414036;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00413a0c(param_1 + 1,4,0x14,CString::CString);
  local_4 = 0;
  FUN_00413a0c(param_1 + 0x2a,4,0x14,CString::CString);
  *param_1 = &PTR_FUN_004154dc;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00419eb0);
  param_1[0x15] = 0;
  ExceptionList = pvStack_c;
  return param_1;
}



/* ==== FUN_00403d30 @ 00403d30 ==== */

undefined4 * __thiscall FUN_00403d30(void *this,byte param_1)

{
  FUN_00403d50((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



/* ==== FUN_00403d50 @ 00403d50 ==== */

void __fastcall FUN_00403d50(undefined4 *param_1)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00414056;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_004154dc;
  local_4 = 0;
  FUN_00413918(param_1 + 0x2a,4,0x14,CString::~CString);
  local_4 = 0xffffffff;
  FUN_00413918(param_1 + 1,4,0x14,CString::~CString);
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00403dc0 @ 00403dc0 ==== */

undefined4 __fastcall FUN_00403dc0(int param_1)

{
  char cVar1;
  HDEVINFO DeviceInfoSet;
  DWORD DVar2;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_A DeviceInterfaceDetailData;
  HANDLE hFile;
  undefined4 uVar3;
  int iVar4;
  DWORD dwLanguageId;
  char **lpBuffer;
  DWORD nSize;
  va_list *Arguments;
  char local_ac0 [2048];
  ushort local_2c0 [7];
  uint local_2b2;
  short local_c0;
  short local_be;
  short local_ba;
  _SP_DEVICE_INTERFACE_DATA local_80;
  undefined local_64 [12];
  _SECURITY_ATTRIBUTES local_58;
  BOOL local_4c;
  HDEVINFO local_48;
  GUID local_44;
  char *local_30;
  DWORD local_2c [2];
  CString local_24 [4];
  undefined4 local_20;
  uchar *local_1c;
  int local_18;
  undefined *local_14;
  void *pvStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00414070;
  pvStack_10 = ExceptionList;
  local_14 = &stack0xfffff534;
  ExceptionList = &pvStack_10;
  local_18 = param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00419eb0);
  *(undefined4 *)(param_1 + 0x54) = 0;
  CString::CString(local_24);
  local_8 = 0;
  HidD_GetHidGuid(&local_44);
  sprintf(local_ac0,&DAT_0041812c,local_44.Data1,local_44.Data2,
          CONCAT12(local_44.Data4[0],local_44.Data3) & 0xffff,
          CONCAT12(local_44.Data4[2],CONCAT11(local_44.Data4[1],local_44.Data4[0])) & 0xff,
          CONCAT12(local_44.Data4[3],CONCAT11(local_44.Data4[2],local_44.Data4[1])) & 0xff,
          CONCAT12(local_44.Data4[4],CONCAT11(local_44.Data4[3],local_44.Data4[2])) & 0xff,
          CONCAT12(local_44.Data4[5],CONCAT11(local_44.Data4[4],local_44.Data4[3])) & 0xff,
          CONCAT12(local_44.Data4[6],CONCAT11(local_44.Data4[5],local_44.Data4[4])) & 0xff,
          CONCAT12(local_44.Data4[7],CONCAT11(local_44.Data4[6],local_44.Data4[5])) & 0xff,
          CONCAT11(local_44.Data4[7],local_44.Data4[6]) & 0xff,local_44.Data4[7]);
  DeviceInfoSet = SetupDiGetClassDevsA(&local_44,(PCSTR)0x0,(HWND)0x0,0x12);
  local_48 = DeviceInfoSet;
  if (DeviceInfoSet == (HDEVINFO)0xffffffff) {
LAB_00404102:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419eb0);
    local_8 = 0xffffffff;
    CString::~CString(local_24);
    ExceptionList = pvStack_10;
    return 0;
  }
  local_2c[1] = 0;
  local_80.cbSize = 0x1c;
  local_4c = SetupDiEnumDeviceInterfaces(DeviceInfoSet,(PSP_DEVINFO_DATA)0x0,&local_44,0,&local_80);
  if (local_4c == 0) {
    DVar2 = GetLastError();
    if (DVar2 == 0x103) {
      SetupDiDestroyDeviceInfoList(DeviceInfoSet);
      goto LAB_00404102;
    }
  }
  local_2c[0] = 0;
  SetupDiGetDeviceInterfaceDetailA
            (DeviceInfoSet,&local_80,(PSP_DEVICE_INTERFACE_DETAIL_DATA_A)0x0,0,local_2c,
             (PSP_DEVINFO_DATA)0x0);
  DeviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)malloc(local_2c[0]);
  DeviceInterfaceDetailData->cbSize = 5;
  SetupDiGetDeviceInterfaceDetailA
            (DeviceInfoSet,&local_80,DeviceInterfaceDetailData,local_2c[0],(PDWORD)0x0,
             (PSP_DEVINFO_DATA)0x0);
  local_8._0_1_ = 1;
  local_58.lpSecurityDescriptor = (LPVOID)0x0;
  local_58.bInheritHandle = 1;
  local_58.nLength = 0xc;
  hFile = CreateFileA(DeviceInterfaceDetailData->DevicePath,0xc0000000,3,&local_58,3,0,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    Arguments = (va_list *)0x0;
    lpBuffer = &local_30;
    nSize = 0;
    dwLanguageId = 0x400;
    DVar2 = GetLastError();
    FormatMessageA(0x1100,(LPCVOID)0x0,DVar2,dwLanguageId,(LPSTR)lpBuffer,nSize,Arguments);
    CString::operator=(local_24,local_30);
    LocalFree(local_30);
    uVar3 = FUN_004040ed();
    return uVar3;
  }
  local_20 = 0;
  HidD_GetPreparsedData(hFile,&local_20);
  HidP_GetCaps(local_20,&local_c0);
  HidD_FreePreparsedData(local_20);
  CString::CString((CString *)&local_1c);
  local_8._0_1_ = 2;
  if (((local_c0 == 1) && (local_be == -0xdd)) && (local_ba == 9)) {
    HidD_GetAttributes(hFile,local_64);
    CString::Format(*(CString **)(local_18 + 0x54),
                    (char *)(local_18 + 0xa8 + (int)*(CString **)(local_18 + 0x54) * 4));
    cVar1 = HidD_GetIndexedString(hFile,0xfa,local_2c0);
    if (cVar1 != '\0') {
      CString::operator=((CString *)&local_1c,local_2c0);
      iVar4 = _mbscmp(local_1c,(uchar *)s_Areson_00418510);
      if (iVar4 == 0) {
        CString::Format((CString *)&local_1c,(char *)&local_1c);
        *(uint *)(local_18 + 0x58 + *(int *)(local_18 + 0x54) * 4) = local_2b2 & 0xff;
        HidD_GetProductString(hFile);
        CString::operator=((CString *)(local_18 + 4 + *(int *)(local_18 + 0x54) * 4),local_2c0);
        *(int *)(local_18 + 0x54) = *(int *)(local_18 + 0x54) + 1;
      }
    }
  }
  CancelIo(hFile);
  CloseHandle(hFile);
  local_8 = CONCAT31(local_8._1_3_,1);
  CString::~CString((CString *)&local_1c);
  uVar3 = FUN_004040ed();
  return uVar3;
}



/* ==== Catch@004040e2 @ 004040e2 ==== */

undefined * Catch_004040e2(void)

{
  return &DAT_004040e8;
}



/* ==== FUN_004040ed @ 004040ed ==== */

undefined4 FUN_004040ed(void)

{
  int *piVar1;
  CString *this;
  char cVar2;
  PSP_DEVINFO_DATA p_Var3;
  DWORD DVar4;
  PSP_DEVICE_INTERFACE_DETAIL_DATA_A DeviceInterfaceDetailData;
  HANDLE hFile;
  undefined4 uVar5;
  int iVar6;
  PSP_DEVINFO_DATA unaff_EBX;
  int unaff_EBP;
  HDEVINFO unaff_EDI;
  DWORD dwLanguageId;
  LPSTR lpBuffer;
  PSP_DEVINFO_DATA Arguments;
  
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -4) = unaff_EBX;
  *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
  if (*(PSP_DEVINFO_DATA *)(unaff_EBP + -0x48) == unaff_EBX) {
LAB_00404102:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00419eb0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    CString::~CString((CString *)(unaff_EBP + -0x20));
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0;
  }
  p_Var3 = (PSP_DEVINFO_DATA)
           SetupDiEnumDeviceInterfaces
                     (unaff_EDI,unaff_EBX,(GUID *)(unaff_EBP + -0x40),*(DWORD *)(unaff_EBP + -0x24),
                      (PSP_DEVICE_INTERFACE_DATA)(unaff_EBP + -0x7c));
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -0x48) = p_Var3;
  if (p_Var3 == unaff_EBX) {
    DVar4 = GetLastError();
    if (DVar4 == 0x103) {
      SetupDiDestroyDeviceInfoList(unaff_EDI);
      goto LAB_00404102;
    }
  }
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -0x28) = unaff_EBX;
  SetupDiGetDeviceInterfaceDetailA
            (unaff_EDI,(PSP_DEVICE_INTERFACE_DATA)(unaff_EBP + -0x7c),
             (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)unaff_EBX,(DWORD)unaff_EBX,
             (PDWORD)(unaff_EBP + -0x28),unaff_EBX);
  DeviceInterfaceDetailData =
       (PSP_DEVICE_INTERFACE_DETAIL_DATA_A)malloc(*(size_t *)(unaff_EBP + -0x28));
  DeviceInterfaceDetailData->cbSize = 5;
  SetupDiGetDeviceInterfaceDetailA
            (unaff_EDI,(PSP_DEVICE_INTERFACE_DATA)(unaff_EBP + -0x7c),DeviceInterfaceDetailData,
             *(DWORD *)(unaff_EBP + -0x28),&unaff_EBX->cbSize,unaff_EBX);
  *(undefined *)(unaff_EBP + -4) = 1;
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -0x50) = unaff_EBX;
  *(undefined4 *)(unaff_EBP + -0x4c) = 1;
  *(undefined4 *)(unaff_EBP + -0x54) = 0xc;
  hFile = CreateFileA(DeviceInterfaceDetailData->DevicePath,0xc0000000,3,
                      (LPSECURITY_ATTRIBUTES)(unaff_EBP + -0x54),3,(DWORD)unaff_EBX,unaff_EBX);
  if (hFile == (HANDLE)0xffffffff) {
    lpBuffer = (LPSTR)(unaff_EBP + -0x2c);
    dwLanguageId = 0x400;
    p_Var3 = unaff_EBX;
    Arguments = unaff_EBX;
    DVar4 = GetLastError();
    FormatMessageA(0x1100,unaff_EBX,DVar4,dwLanguageId,lpBuffer,(DWORD)p_Var3,(va_list *)Arguments);
    CString::operator=((CString *)(unaff_EBP + -0x20),*(char **)(unaff_EBP + -0x2c));
    LocalFree(*(HLOCAL *)(unaff_EBP + -0x2c));
    uVar5 = FUN_004040ed();
    return uVar5;
  }
  *(PSP_DEVINFO_DATA *)(unaff_EBP + -0x1c) = unaff_EBX;
  HidD_GetPreparsedData(hFile,unaff_EBP + -0x1c);
  HidP_GetCaps(*(undefined4 *)(unaff_EBP + -0x1c),unaff_EBP + -0xbc);
  HidD_FreePreparsedData(*(undefined4 *)(unaff_EBP + -0x1c));
  CString::CString((CString *)(unaff_EBP + -0x18));
  *(undefined *)(unaff_EBP + -4) = 2;
  if (((*(short *)(unaff_EBP + -0xbc) == 1) && (*(short *)(unaff_EBP + -0xba) == -0xdd)) &&
     (*(short *)(unaff_EBP + -0xb6) == 9)) {
    HidD_GetAttributes(hFile,unaff_EBP + -0x60);
    this = *(CString **)(*(int *)(unaff_EBP + -0x14) + 0x54);
    CString::Format(this,(char *)(*(int *)(unaff_EBP + -0x14) + 0xa8 + (int)this * 4));
    cVar2 = HidD_GetIndexedString(hFile,0xfa,unaff_EBP + -700);
    if (cVar2 != '\0') {
      CString::operator=((CString *)(unaff_EBP + -0x18),(ushort *)(unaff_EBP + -700));
      iVar6 = _mbscmp(*(uchar **)(unaff_EBP + -0x18),(uchar *)s_Areson_00418510);
      if (iVar6 == 0) {
        CString::Format((CString *)(unaff_EBP + -0x18),(char *)(unaff_EBP + -0x18));
        *(uint *)(*(int *)(unaff_EBP + -0x14) + 0x58 +
                 *(int *)(*(int *)(unaff_EBP + -0x14) + 0x54) * 4) =
             *(uint *)(unaff_EBP + -0x2ae) & 0xff;
        HidD_GetProductString(hFile);
        CString::operator=((CString *)
                           (*(int *)(unaff_EBP + -0x14) + 4 +
                           *(int *)(*(int *)(unaff_EBP + -0x14) + 0x54) * 4),
                           (ushort *)(unaff_EBP + -700));
        piVar1 = (int *)(*(int *)(unaff_EBP + -0x14) + 0x54);
        *piVar1 = *piVar1 + 1;
      }
    }
  }
  CancelIo(hFile);
  CloseHandle(hFile);
  *(undefined *)(unaff_EBP + -4) = 1;
  CString::~CString((CString *)(unaff_EBP + -0x18));
  uVar5 = FUN_004040ed();
  return uVar5;
}



/* ==== FUN_00404130 @ 00404130 ==== */

CDialog * __thiscall FUN_00404130(void *this,CWnd *param_1)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00414088;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CDialog::CDialog((CDialog *)this,0x68,param_1);
  local_4 = 0;
  CString::CString((CString *)((int)this + 0x60));
  *(undefined ***)this = &PTR_LAB_00415500;
  ExceptionList = local_c;
  return (CDialog *)this;
}



/* ==== FUN_00404190 @ 00404190 ==== */

CDialog * __thiscall FUN_00404190(void *this,byte param_1)

{
  FUN_004041b0((CDialog *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CDialog *)this;
}



/* ==== FUN_004041b0 @ 004041b0 ==== */

void __fastcall FUN_004041b0(CDialog *param_1)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004140a8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  CString::~CString((CString *)(param_1 + 0x60));
  local_4 = 0xffffffff;
  CDialog::~CDialog(param_1);
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00404220 @ 00404220 ==== */

void __fastcall FUN_00404220(CWnd *param_1)

{
  CWnd::GetDlgItemTextA(param_1,0x405,(CString *)(param_1 + 0x60));
  CDialog::OnOK((CDialog *)param_1);
  return;
}



/* ==== FUN_00404240 @ 00404240 ==== */

undefined4 __fastcall FUN_00404240(CDialog *param_1)

{
  CDialog::OnInitDialog(param_1);
  CWnd::SetDlgItemTextA((CWnd *)param_1,0x405,*(char **)(param_1 + 0x60));
  return 1;
}



/* ==== FUN_004042a0 @ 004042a0 ==== */

CWinApp * __fastcall FUN_004042a0(CWinApp *param_1)

{
  CWinApp::CWinApp(param_1,(char *)0x0);
  *(undefined ***)param_1 = &PTR_LAB_00415610;
  return param_1;
}



/* ==== FUN_004042c0 @ 004042c0 ==== */

CWinApp * __thiscall FUN_004042c0(void *this,byte param_1)

{
  CWinApp::~CWinApp((CWinApp *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CWinApp *)this;
}



/* ==== ~CWinApp @ 004042e0 ==== */

void __thiscall CWinApp::~CWinApp(CWinApp *this)

{
                    /* WARNING: Could not recover jumptable at 0x00413766. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CWinApp(this);
  return;
}



/* ==== FUN_00404300 @ 00404300 ==== */

void FUN_00404300(void)

{
  FUN_004042a0((CWinApp *)&DAT_00419ec8);
  return;
}



/* ==== FUN_00404310 @ 00404310 ==== */

void FUN_00404310(void)

{
  FUN_00413906((_onexit_t)&LAB_00404320);
  return;
}



/* ==== FUN_00404330 @ 00404330 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00404330(CWinApp *param_1)

{
  DWORD DVar1;
  _SECURITY_ATTRIBUTES local_fc;
  CDialog aCStack_f0 [96];
  CButton aCStack_90 [64];
  CComboBox aCStack_50 [68];
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004140e1;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  AfxEnableControlContainer((COccManager *)0x0);
  local_fc.bInheritHandle = 0;
  local_fc.nLength = 0xc;
  local_fc.lpSecurityDescriptor = (LPVOID)0x0;
  _DAT_00419f8c = CreateMutexA(&local_fc,1,s_Mouse_Test_2008_0041851c);
  DVar1 = GetLastError();
  if (DVar1 == 0xb7) {
    FUN_00404480();
  }
  else {
    CWinApp::Enable3dControls(param_1);
    FUN_004049d0(aCStack_f0,(CWnd *)0x0);
    uStack_4 = 0;
    *(CDialog **)(param_1 + 0x20) = aCStack_f0;
    CDialog::DoModal(aCStack_f0);
    uStack_4 = 2;
    CComboBox::~CComboBox(aCStack_50);
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    CButton::~CButton(aCStack_90);
    uStack_4 = 0xffffffff;
    CDialog::~CDialog(aCStack_f0);
  }
  ExceptionList = pvStack_c;
  return 0;
}



/* ==== FUN_00404420 @ 00404420 ==== */

void __fastcall FUN_00404420(CDialog *param_1)

{
  void *local_c;
  undefined *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00414103;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  CComboBox::~CComboBox((CComboBox *)(param_1 + 0xa0));
  local_4 = local_4 & 0xffffff00;
  CButton::~CButton((CButton *)(param_1 + 0x60));
  local_4 = 0xffffffff;
  CDialog::~CDialog(param_1);
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00404480 @ 00404480 ==== */

void FUN_00404480(void)

{
  HWND pHVar1;
  int iVar2;
  UINT uCmd;
  CHAR aCStack_100 [256];
  
  uCmd = 0;
  pHVar1 = GetForegroundWindow();
  pHVar1 = GetWindow(pHVar1,uCmd);
  pHVar1 = GetWindow(pHVar1,2);
  if (pHVar1 != (HWND)0x0) {
    if (pHVar1 == (HWND)0x0) goto LAB_004044df;
    do {
      iVar2 = GetWindowTextA(pHVar1,aCStack_100,0xff);
      aCStack_100[iVar2] = '\0';
      PostMessageA(pHVar1,0x4bd,0,0);
      if (0 < iVar2) {
        IsWindowVisible(pHVar1);
      }
LAB_004044df:
      pHVar1 = GetWindow(pHVar1,2);
    } while (pHVar1 != (HWND)0x0);
  }
  return;
}



/* ==== FUN_00404510 @ 00404510 ==== */

void FUN_00404510(void)

{
  FUN_00403cb0((undefined4 *)&DAT_0041eeb8);
  return;
}



/* ==== FUN_00404520 @ 00404520 ==== */

void FUN_00404520(void)

{
  FUN_00413906((_onexit_t)&LAB_00404530);
  return;
}



/* ==== FUN_00404550 @ 00404550 ==== */

void FUN_00404550(void)

{
  CString::CString((CString *)&DAT_0041eeb4);
  CString::CString((CString *)&DAT_0041eeb0);
  return;
}



/* ==== FUN_00404570 @ 00404570 ==== */

void FUN_00404570(void)

{
  FUN_00413906((_onexit_t)&LAB_00404580);
  return;
}



/* ==== FUN_004045b0 @ 004045b0 ==== */

void FUN_004045b0(void)

{
  CString::CString((CString *)&DAT_0041ee7c);
  return;
}



/* ==== FUN_004045c0 @ 004045c0 ==== */

void FUN_004045c0(void)

{
  FUN_00413906((_onexit_t)&LAB_004045d0);
  return;
}



/* ==== FUN_004045f0 @ 004045f0 ==== */

void FUN_004045f0(void)

{
  FUN_00413a0c(&DAT_0041ebd0,0x1c,0x14,FUN_00404610);
  return;
}



/* ==== FUN_00404610 @ 00404610 ==== */

undefined4 * __fastcall FUN_00404610(undefined4 *param_1)

{
  CString::CString((CString *)(param_1 + 2));
  param_1[6] = 0;
  *param_1 = 1;
  param_1[1] = 0xf0f0f;
  param_1[3] = 0xffffff;
  return param_1;
}



/* ==== FUN_00404640 @ 00404640 ==== */

void FUN_00404640(void)

{
  FUN_00413906((_onexit_t)&LAB_00404650);
  return;
}



/* ==== FUN_00404690 @ 00404690 ==== */

void FUN_00404690(void)

{
  FUN_00413a0c(&DAT_0041d5f0,0x38,100,FUN_004046b0);
  return;
}



/* ==== FUN_004046b0 @ 004046b0 ==== */

undefined4 * __fastcall FUN_004046b0(undefined4 *param_1)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0041411b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CString::CString((CString *)(param_1 + 3));
  local_4 = 0;
  CString::CString((CString *)(param_1 + 4));
  param_1[1] = 0xffffffff;
  param_1[10] = 0xffffffff;
  param_1[9] = 0xffffffff;
  param_1[0xb] = 1;
  param_1[8] = 0;
  *param_1 = 1;
  param_1[2] = 0xf0f0f;
  param_1[5] = 0xffffff;
  ExceptionList = local_c;
  return param_1;
}



/* ==== FUN_00404730 @ 00404730 ==== */

void FUN_00404730(void)

{
  FUN_00413906((_onexit_t)&LAB_00404740);
  return;
}



/* ==== FUN_00404760 @ 00404760 ==== */

void __fastcall FUN_00404760(int param_1)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0041413b;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  CString::~CString((CString *)(param_1 + 0x10));
  local_4 = 0xffffffff;
  CString::~CString((CString *)(param_1 + 0xc));
  ExceptionList = local_c;
  return;
}



/* ==== FUN_004047c0 @ 004047c0 ==== */

void FUN_004047c0(void)

{
  FUN_00401080((undefined4 *)&DAT_0041d180);
  return;
}



/* ==== FUN_004047d0 @ 004047d0 ==== */

void FUN_004047d0(void)

{
  FUN_00413906((_onexit_t)&LAB_004047e0);
  return;
}



/* ==== FUN_00404800 @ 00404800 ==== */

void FUN_00404800(void)

{
  FUN_004131f0(&DAT_0041a1f0,10);
  return;
}



/* ==== FUN_00404810 @ 00404810 ==== */

void FUN_00404810(void)

{
  FUN_00413906((_onexit_t)&LAB_00404820);
  return;
}



/* ==== FUN_00404840 @ 00404840 ==== */

void FUN_00404840(void)

{
  CString::CString((CString *)&DAT_0041a1b0);
  return;
}



/* ==== FUN_00404850 @ 00404850 ==== */

void FUN_00404850(void)

{
  FUN_00413906((_onexit_t)&LAB_00404860);
  return;
}



/* ==== FUN_00404980 @ 00404980 ==== */

CDialog * __thiscall FUN_00404980(void *this,byte param_1)

{
  CDialog::~CDialog((CDialog *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CDialog *)this;
}



/* ==== ~CDialog @ 004049a0 ==== */

void __thiscall CDialog::~CDialog(CDialog *this)

{
  ~CDialog(this);
  return;
}



/* ==== FUN_004049d0 @ 004049d0 ==== */

CDialog * __thiscall FUN_004049d0(void *this,CWnd *param_1)

{
  HINSTANCE__ *hInstance;
  HICON pHVar1;
  LPCSTR lpIconName;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00414171;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  CDialog::CDialog((CDialog *)this,0x66,param_1);
  local_4 = 0;
  CWnd::CWnd((CWnd *)((int)this + 0x60));
  *(undefined ***)((int)this + 0x60) = &PTR_LAB_00415a50;
  local_4._0_1_ = 1;
  CWnd::CWnd((CWnd *)((int)this + 0xa0));
  *(undefined ***)((int)this + 0xa0) = &PTR_LAB_00415980;
  local_4 = CONCAT31(local_4._1_3_,2);
  *(undefined ***)this = &PTR_LAB_004158a8;
  AfxGetModuleState();
  lpIconName = (LPCSTR)0x80;
  hInstance = AfxFindResourceHandle((char *)0x80,(char *)0xe);
  pHVar1 = LoadIconA(hInstance,lpIconName);
  *(HICON *)((int)this + 0xe0) = pHVar1;
  ExceptionList = pvStack_c;
  return (CDialog *)this;
}



/* ==== FUN_00404a70 @ 00404a70 ==== */

CDialog * __thiscall FUN_00404a70(void *this,byte param_1)

{
  FUN_00404420((CDialog *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CDialog *)this;
}



/* ==== FUN_00404a90 @ 00404a90 ==== */

void __thiscall FUN_00404a90(void *this,CDataExchange *param_1)

{
  DDX_Control(param_1,0x408,(CWnd *)((int)this + 0x60));
  DDX_Control(param_1,0x407,(CWnd *)((int)this + 0xa0));
  return;
}



/* ==== FUN_00404fa0 @ 00404fa0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00404fa0(CWnd *param_1)

{
  int *piVar1;
  char cVar2;
  CString *pCVar3;
  WPARAM WVar4;
  HDC pHVar5;
  CDC *pCVar6;
  AFX_MODULE_STATE *pAVar7;
  HDC hdc;
  undefined4 *puVar8;
  int iVar9;
  CString *this;
  CString *this_00;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  HPEN *ppHVar13;
  HFONT *ppHVar14;
  char *pcVar15;
  time_t tVar16;
  undefined4 unaff_retaddr;
  CString local_84 [4];
  LPCSTR pCStack_80;
  LPCSTR pCStack_7c;
  char *pcStack_78;
  HGDIOBJ pvStack_74;
  HGDIOBJ apvStack_70 [2];
  HPEN pHStack_68;
  CDC *pCStack_64;
  int iStack_60;
  undefined auStack_5c [4];
  tagRECT tStack_58;
  tagRECT tStack_48;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004141fb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  CString::CString(local_84);
  local_4 = 0;
  tVar16 = time((time_t *)0x0);
  srand((uint)tVar16);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0041a198);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0041a180);
  DAT_0041a220 = GetSystemMetrics(0);
  DAT_0041a224 = (CString *)GetSystemMetrics(1);
  DAT_0041a218 = GetSystemMetrics(0);
  DAT_0041a21c = GetSystemMetrics(1);
  CWnd::SetWindowPos(param_1,(CWnd *)0x0,0,0,DAT_0041a220,(int)DAT_0041a224,4);
  GetClientRect(*(HWND *)(param_1 + 0x20),&tStack_48);
  ShowScrollBar(*(HWND *)(param_1 + 0x20),3,1);
  GetClientRect(*(HWND *)(param_1 + 0x20),(LPRECT)(auStack_5c + 4));
  DAT_0041a220 = (tStack_58.right - tStack_58.left) + (tStack_48.right - tStack_58.right);
  DAT_0041a224 = (CString *)
                 ((tStack_58.bottom - tStack_58.top) + (tStack_48.bottom - tStack_58.bottom));
  CString::CString((CString *)apvStack_70);
  local_4 = CONCAT31(local_4._1_3_,1);
  CString::Format(DAT_0041a224,(char *)apvStack_70);
  CWnd::SetWindowPos(param_1,(CWnd *)0x0,0,0,DAT_0041a220 + (tStack_48.right - tStack_58.right),
                     (int)(DAT_0041a224 + (tStack_48.bottom - tStack_58.bottom)),4);
  SendMessageA(*(HWND *)(param_1 + 0xc0),0x14b,0,0);
  WVar4 = SendMessageA(*(HWND *)(param_1 + 0xc0),0x143,0,0x418970);
  SendMessageA(*(HWND *)(param_1 + 0xc0),0x151,WVar4,1);
  WVar4 = SendMessageA(*(HWND *)(param_1 + 0xc0),0x143,0,0x418964);
  SendMessageA(*(HWND *)(param_1 + 0xc0),0x151,WVar4,2);
  WVar4 = SendMessageA(*(HWND *)(param_1 + 0xc0),0x143,0,0x418958);
  SendMessageA(*(HWND *)(param_1 + 0xc0),0x151,WVar4,0);
  SendMessageA(*(HWND *)(param_1 + 0xc0),0x14e,WVar4,0);
  CWnd::SetWindowPos(param_1 + 0xa0,(CWnd *)0x0,400,0x39,0,0,5);
  pHVar5 = GetDC(*(HWND *)(param_1 + 0x20));
  pCVar6 = CDC::FromHandle(pHVar5);
  pCStack_64 = pCVar6;
  pHVar5 = CreateCompatibleDC(*(HDC *)(pCVar6 + 4));
  DAT_0041f044 = CreateCompatibleBitmap(*(HDC *)(pCVar6 + 4),DAT_0041a218,DAT_0041a21c);
  DAT_0041f048 = CreateCompatibleBitmap(*(HDC *)(pCVar6 + 4),DAT_0041a218,DAT_0041a21c);
  DAT_0041d118 = CreateCompatibleBitmap(*(HDC *)(pCVar6 + 4),DAT_0041a218,DAT_0041a21c);
  pAVar7 = AfxGetModuleState();
  DAT_0041d120 = LoadImageA(*(HINSTANCE *)(*(int *)(pAVar7 + 4) + 0x6c),(LPCSTR)0x8c,0,0,0,0);
  pAVar7 = AfxGetModuleState();
  DAT_0041d11c = LoadImageA(*(HINSTANCE *)(*(int *)(pAVar7 + 4) + 0x6c),(LPCSTR)0x85,0,0,0,0);
  pAVar7 = AfxGetModuleState();
  DAT_0041d124 = LoadImageA(*(HINSTANCE *)(*(int *)(pAVar7 + 4) + 0x6c),(LPCSTR)0x8e,1,0x49,0x49,0);
  pAVar7 = AfxGetModuleState();
  _DAT_0041ee8c = LoadImageA(*(HINSTANCE *)(*(int *)(pAVar7 + 4) + 0x6c),(LPCSTR)0x91,1,0x10,0x10,0)
  ;
  SelectObject(pHVar5,DAT_0041f044);
  pHStack_68 = CreatePen(2,1,0x303030);
  pcStack_78 = (char *)SelectObject(pHVar5,pHStack_68);
  SetBkMode(pHVar5,1);
  ppHVar13 = &DAT_0041a1b4;
  for (iVar9 = 0xe; iVar9 != 0; iVar9 = iVar9 + -1) {
    *ppHVar13 = (HPEN)0x0;
    ppHVar13 = ppHVar13 + 1;
  }
  ppHVar14 = &DAT_0041d130;
  for (iVar9 = 0xe; iVar9 != 0; iVar9 = iVar9 + -1) {
    *ppHVar14 = (HFONT)0x0;
    ppHVar14 = ppHVar14 + 1;
  }
  DAT_0041d130 = CreateFontA(0x32,0x12,0,0,0,0,0,0,1,0,0,4,0,s_Arial_Black_0041894c);
  DAT_0041d134 = CreateFontA(0x48,0x1c,0,0,0,0,0,0,1,0,0,4,0,s_Arial_Black_0041894c);
  _DAT_0041d138 = CreateFontA(0x1f,0xb,0,0,0,0,0,0,1,0,0,4,0,s_Arial_00418944);
  DAT_0041d13c = CreateFontA(0x18,0xc,0,0,0,0,0,0,1,0,0,4,0,s_Courier_New_00418938);
  DAT_0041d140 = CreateFontA(0x16,8,0,0,0,0,0,0,1,0,0,4,0,s_Arial_00418944);
  DAT_0041d144 = CreateFontA(0x10,8,0,0,0,0,0,0,1,0,0,4,0,s_Arial_00418944);
  _DAT_0041d148 = CreateFontA(0xc,6,0,0,0,0,0,0,1,0,0,4,0,s_Arial_00418944);
  DAT_0041d14c = CreateFontA(0x32,0x12,0,0,0,0,0,0,1,0,0,0,0,s_Arial_Black_0041894c);
  _DAT_0041d150 = CreateFontA(0x14,10,0,0,0,0,0,0,1,0,0,4,0,s_Courier_New_00418938);
  DAT_0041d154 = CreateFontA(0x60,0,0,0,0,0,0,0,1,0,0,4,0,s_Arial_Black_0041894c);
  DAT_0041a1b4 = CreatePen(0,2,0xff00);
  DAT_0041a1b8 = CreatePen(0,2,0xff);
  _DAT_0041a1bc = CreatePen(0,2,0xffff);
  _DAT_0041a1c0 = CreatePen(0,2,0xff00ff);
  _DAT_0041a1c4 = CreatePen(0,2,0xffff00);
  _DAT_0041a1c8 = CreatePen(0,2,0xff0000);
  _DAT_0041a1cc = CreatePen(0,2,0xffffff);
  iVar9 = 0x31;
  if (0x31 < DAT_0041a220) {
    do {
      MoveToEx(pHVar5,iVar9,0,(LPPOINT)0x0);
      LineTo(pHVar5,iVar9,(int)DAT_0041a224);
      iVar9 = iVar9 + 0x32;
    } while (iVar9 < DAT_0041a220);
  }
  iVar9 = 0x31;
  if (0x31 < (int)DAT_0041a224) {
    do {
      MoveToEx(pHVar5,0,iVar9,(LPPOINT)0x0);
      LineTo(pHVar5,DAT_0041a220,iVar9);
      iVar9 = iVar9 + 0x32;
    } while (iVar9 < (int)DAT_0041a224);
  }
  CString::operator=((CString *)&pCStack_80,(ushort *)&DAT_00418934);
  CString::CString((CString *)&pvStack_74,(ushort *)&DAT_00418930);
  CString::operator+=((CString *)&pCStack_80,(CString *)&pvStack_74);
  CString::~CString((CString *)&pvStack_74);
  CString::CString((CString *)&pvStack_74,(ushort *)&DAT_0041892c);
  CString::operator+=((CString *)&pCStack_80,(CString *)&pvStack_74);
  CString::~CString((CString *)&pvStack_74);
  CString::CString((CString *)&pvStack_74,(ushort *)&DAT_00418928);
  CString::operator+=((CString *)&pCStack_80,(CString *)&pvStack_74);
  CString::~CString((CString *)&pvStack_74);
  CString::CString((CString *)&pvStack_74,(ushort *)&DAT_00418924);
  CString::operator+=((CString *)&pCStack_80,(CString *)&pvStack_74);
  CString::~CString((CString *)&pvStack_74);
  CString::CString((CString *)apvStack_70,(ushort *)&DAT_00418920);
  CString::operator+=((CString *)&pCStack_80,(CString *)apvStack_70);
  CString::~CString((CString *)apvStack_70);
  SelectObject(pHVar5,DAT_0041d130);
  GetTextExtentPointA(pHVar5,pCStack_80,*(int *)(pCStack_80 + -8),(LPSIZE)auStack_5c);
  SetTextColor(pHVar5,0x80808);
  TextOutA(pHVar5,(DAT_0041a220 - (int)auStack_5c) + -4,(int)(DAT_0041a224 + (-4 - tStack_58.left)),
           pCStack_80,*(int *)(pCStack_80 + -8));
  TextOutA(pHVar5,(DAT_0041a220 - (int)auStack_5c) + -4,(int)(DAT_0041a224 + (-5 - tStack_58.left)),
           pCStack_80,*(int *)(pCStack_80 + -8));
  TextOutA(pHVar5,(DAT_0041a220 - (int)auStack_5c) + -5,(int)(DAT_0041a224 + (-4 - tStack_58.left)),
           pCStack_80,*(int *)(pCStack_80 + -8));
  SetTextColor(pHVar5,0x181818);
  TextOutA(pHVar5,(DAT_0041a220 - (int)auStack_5c) + -5,(int)(DAT_0041a224 + (-5 - tStack_58.left)),
           pCStack_80,*(int *)(pCStack_80 + -8));
  CString::Format(this,(char *)&pCStack_80);
  GetTextExtentPointA(pHVar5,pCStack_7c,*(int *)(pCStack_7c + -8),(LPSIZE)(auStack_5c + 4));
  iVar9 = (int)DAT_0041a224 - (tStack_58.top * 2 + 2);
  SetTextColor(pHVar5,0x80808);
  TextOutA(pHVar5,DAT_0041a220 - tStack_58.left,iVar9,pCStack_7c,*(int *)(pCStack_7c + -8));
  TextOutA(pHVar5,(DAT_0041a220 - tStack_58.left) + -1,iVar9,pCStack_7c,*(int *)(pCStack_7c + -8));
  TextOutA(pHVar5,(DAT_0041a220 - tStack_58.left) + -1,iVar9 + 1,pCStack_7c,
           *(int *)(pCStack_7c + -8));
  SetTextColor(pHVar5,0x181818);
  TextOutA(pHVar5,(DAT_0041a220 - tStack_58.left) + -1,iVar9,pCStack_7c,*(int *)(pCStack_7c + -8));
  _DAT_0041eea8 = DAT_0041a220 + -8;
  _DAT_0041eea0 = (DAT_0041a220 - tStack_58.left) + -8;
  _DAT_0041eea4 = iVar9 + -8;
  _DAT_0041eeac = DAT_0041a224 + -8;
  _DAT_0041ee90 = (DAT_0041a220 - tStack_58.left) + 8;
  _DAT_0041ee94 = iVar9 + 0x18;
  _DAT_0041ee98 = _DAT_0041ee90;
  _DAT_0041ee9c = _DAT_0041ee94;
  SelectObject(pHVar5,DAT_0041d140);
  CString::operator=((CString *)&pCStack_7c,&DAT_0041890c);
  CString::operator+=((CString *)&pCStack_7c,&DAT_00418908);
  CString::operator+=((CString *)&pCStack_7c,&DAT_00418904);
  CString::operator+=((CString *)&pCStack_7c,&DAT_00418900);
  GetTextExtentPointA(pHVar5,pCStack_7c,*(int *)(pCStack_7c + -8),(LPSIZE)(auStack_5c + 4));
  SetTextColor(pHVar5,0x40404);
  TextOutA(pHVar5,DAT_0041a220 - tStack_58.left,0,pCStack_7c,*(int *)(pCStack_7c + -8));
  TextOutA(pHVar5,(DAT_0041a220 - tStack_58.left) + -1,0,pCStack_7c,*(int *)(pCStack_7c + -8));
  TextOutA(pHVar5,(DAT_0041a220 - tStack_58.left) + -1,1,pCStack_7c,*(int *)(pCStack_7c + -8));
  SetTextColor(pHVar5,0xc0c0c);
  TextOutA(pHVar5,(DAT_0041a220 - tStack_58.left) + -1,0,pCStack_7c,*(int *)(pCStack_7c + -8));
  hdc = CreateCompatibleDC((HDC)0x0);
  iStack_18 = 0;
  uStack_1c = 0;
  iStack_14 = 0;
  uStack_10 = 0;
  pvStack_c = (void *)0x0;
  puStack_8 = (undefined *)0x0;
  GetObjectA(DAT_0041d120,0x18,&uStack_1c);
  _DAT_0041d110 = iStack_18;
  _DAT_0041d114 = iStack_14;
  apvStack_70[0] = SelectObject(hdc,DAT_0041d11c);
  BitBlt(pHVar5,0,100,iStack_18,iStack_14,hdc,0,0,0x8800c6);
  SelectObject(hdc,DAT_0041d120);
  BitBlt(pHVar5,0,100,iStack_18,iStack_14,hdc,0,0,0xee0086);
  SelectObject(hdc,apvStack_70[0]);
  DeleteObject(DAT_0041d120);
  DeleteObject(DAT_0041d11c);
  DeleteDC(hdc);
  SelectObject(pHVar5,pvStack_74);
  SelectObject(pHVar5,DAT_0041d144);
  CString::operator=((CString *)&DAT_0041d5fc,s_Quit_004188f8);
  CString::operator=((CString *)&DAT_0041d634,s_Hide_004188f0);
  CString::operator=((CString *)&DAT_0041d66c,(ushort *)&DAT_004188d8);
  CString::operator=((CString *)&DAT_0041d6a4,s_Wheel_Icon_004188c8);
  CString::operator=((CString *)&DAT_0041d6dc,s_Auto_Plot_004188bc);
  CString::operator=((CString *)&DAT_0041d714,(ushort *)&DAT_004188a8);
  CString::operator=((CString *)&DAT_0041d74c,(ushort *)u_Start_Test_0041888c);
  CString::operator=((CString *)&DAT_0041dc8c,s_Pwr__10_00418880);
  CString::operator=((CString *)&DAT_0041dcc4,s_Pwr__10_00418874);
  CString::operator=((CString *)&DAT_0041dcfc,s_Range_0041886c);
  CString::operator=((CString *)&DAT_0041dd34,s_Calibrate_00418860);
  CString::operator=((CString *)&DAT_0041dd6c,s_Default_Mode_00418850);
  CString::operator=((CString *)&DAT_0041d784,s___Free_Run_00418840);
  DAT_0041d79c = 5;
  CString::operator=((CString *)&DAT_0041d7bc,s___Gaming_Test__Standard__00418824);
  DAT_0041d7d4 = 5;
  CString::operator=((CString *)&DAT_0041d7f4,s___Gaming_Test__1000_report_rate__00418800);
  _DAT_0041d80c = 5;
  CString::operator=((CString *)&DAT_0041d82c,s___Gaming_Test__MSI__004187e8);
  _DAT_0041d844 = 5;
  CString::operator=((CString *)&DAT_0041d864,s___Gaming_Test__Trust__004187d0);
  _DAT_0041d87c = 5;
  CString::operator=((CString *)&DAT_0041d89c,s___RF_Test__2_4GHz__004187b8);
  _DAT_0041d8b4 = 5;
  CString::operator=((CString *)&DAT_0041d8d4,s___P01_Test__Portuguese__0041879c);
  CString::operator=((CString *)&DAT_0041d90c,s___DPI_Test_0041878c);
  _DAT_0041d924 = 5;
  CString::operator=((CString *)&DAT_0041d944,s___Surface_Test_00418778);
  _DAT_0041d95c = 5;
  CString::operator=((CString *)&DAT_0041d97c,s___Gaming_Test__QE__00418764);
  _DAT_0041d994 = 5;
  CString::operator=((CString *)&DAT_0041d9b4,s___Misc_Mode_00418754);
  _DAT_0041d9cc = 5;
  CString::operator=((CString *)&DAT_0041d9ec,s___Gaming_III_00418744);
  _DAT_0041da04 = 5;
  CString::operator=((CString *)&DAT_0041da24,s___FD8_Pro_for_KN_00418730);
  _DAT_0041da3c = 5;
  CString::operator=((CString *)&DAT_0041da5c,(ushort *)u___Get_all_device_info__004186fc);
  CString::operator=((CString *)&DAT_0041da94,(ushort *)u___Connect_tool_for_2_4G__>_004186c0);
  CString::operator=((CString *)&DAT_0041dacc,(ushort *)u___Upgrade_tool_for_Gaming__>_00418680);
  CString::operator=((CString *)&DAT_0041db04,(ushort *)u___Get_Nordic_24L01_register_valu_00418630)
  ;
  CString::operator=((CString *)&DAT_0041db3c,(ushort *)u___Gaming_set_tool__>_00418600);
  CString::operator=((CString *)&DAT_0041db74,(ushort *)u___Connect_disconnect_power_meter_004185b8)
  ;
  puVar8 = &DAT_0041d610;
  do {
    *puVar8 = 5;
    puVar8 = puVar8 + 0xe;
  } while ((int)puVar8 < 0x41ded0);
  _DAT_0041d740 = 1;
  DAT_0041d760 = 3;
  DAT_0041d758 = 5;
  DAT_0041d75c = 0x5a;
  _DAT_0041d748 = 0x121212;
  _DAT_0041d754 = 0xffffff;
  pcStack_78 = (char *)0x0;
  puVar8 = &DAT_0041d5fc;
  do {
    GetTextExtentPointA(pHVar5,(LPCSTR)*puVar8,*(int *)((LPCSTR)*puVar8 + -8),
                        (LPSIZE)(auStack_5c + 4));
    pCVar3 = DAT_0041a224;
    puVar8[-3] = 0;
    puVar8[5] = 5;
    puVar8[3] = pcStack_78;
    puVar8[4] = pCVar3 + (-6 - tStack_58.top);
    puVar8[-1] = 0x121212;
    puVar8[2] = 0xffffff;
    piVar1 = puVar8 + 3;
    puVar8 = puVar8 + 0xe;
    pcStack_78 = (char *)(*piVar1 + 10 + tStack_58.left);
  } while ((int)puVar8 < 0x41d74c);
  pcStack_78 = (char *)DAT_0041d720;
  pvStack_74 = (HGDIOBJ)DAT_0041d724;
  apvStack_70[0] = (HGDIOBJ)0x7;
  puVar8 = &DAT_0041d784;
  do {
    if (puVar8[6] == 5) {
      GetTextExtentPointA(pHVar5,(LPCSTR)*puVar8,*(int *)((LPCSTR)*puVar8 + -8),
                          (LPSIZE)(auStack_5c + 4));
      puVar8[5] = 5;
      puVar8[3] = pcStack_78;
      puVar8[4] = ((int)pvStack_74 - tStack_58.top) + -8;
      puVar8[-1] = 0x121212;
      puVar8[2] = 0xffffff;
      puVar8[9] = tStack_58.left;
      puVar8[10] = tStack_58.top;
      pvStack_74 = (HGDIOBJ)puVar8[4];
      puVar8[7] = (int)apvStack_70[0] + -7;
    }
    puVar8 = puVar8 + 0xe;
    apvStack_70[0] = (HGDIOBJ)((int)apvStack_70[0] + 1);
  } while ((int)puVar8 < 0x41da5c);
  pcStack_78 = DAT_0041d678;
  pvStack_74 = (HGDIOBJ)DAT_0041d67c;
  puVar8 = &DAT_0041da5c;
  do {
    GetTextExtentPointA(pHVar5,(LPCSTR)*puVar8,*(int *)((LPCSTR)*puVar8 + -8),
                        (LPSIZE)(auStack_5c + 4));
    puVar8[6] = 2;
    puVar8[5] = 5;
    puVar8[3] = pcStack_78;
    puVar8[4] = ((int)pvStack_74 - tStack_58.top) + -8;
    puVar8[-1] = 0x121212;
    puVar8[2] = 0xffffff;
    puVar8[9] = tStack_58.left;
    puVar8[10] = tStack_58.top;
    pvStack_74 = (HGDIOBJ)puVar8[4];
    puVar8 = puVar8 + 0xe;
  } while ((int)puVar8 < 0x41dbac);
  puVar8 = &DAT_0041d5fc;
  do {
    SelectObject(pHVar5,(&DAT_0041d130)[puVar8[5]]);
    GetTextExtentPointA(pHVar5,(LPCSTR)*puVar8,*(int *)((LPCSTR)*puVar8 + -8),
                        (LPSIZE)(auStack_5c + 4));
    puVar8[9] = tStack_58.left;
    puVar8[10] = tStack_58.top;
    puVar8 = puVar8 + 0xe;
  } while ((int)puVar8 < 0x41debc);
  DeleteObject(pCStack_64);
  DeleteDC(pHVar5);
  ReleaseDC(*(HWND *)(param_1 + 0x20),*(HDC *)(iStack_60 + 4));
  FUN_00406dc0((LPCSTR)param_1);
  SetTimer(*(HWND *)(param_1 + 0x20),1,100,(TIMERPROC)0x0);
  SetTimer(*(HWND *)(param_1 + 0x20),3,1,(TIMERPROC)0x0);
  SetTimer(*(HWND *)(param_1 + 0x20),4,0x41,(TIMERPROC)0x0);
  SetTimer(*(HWND *)(param_1 + 0x20),2,100,(TIMERPROC)0x0);
  SetTimer(*(HWND *)(param_1 + 0x20),5,600,(TIMERPROC)0x0);
  SetTimer(*(HWND *)(param_1 + 0x20),6,100,(TIMERPROC)0x0);
  SetTimer(*(HWND *)(param_1 + 0x20),7,0x50,(TIMERPROC)0x0);
  _DAT_00419f90 = 0x1e8;
  pAVar7 = AfxGetModuleState();
  _DAT_00419fa4 = LoadImageA(*(HINSTANCE *)(*(int *)(pAVar7 + 4) + 0x6c),(LPCSTR)0x80,1,0x10,0x10,0)
  ;
  _DAT_00419f94 = *(undefined4 *)(param_1 + 0x20);
  _DAT_00419f98 = 0x4bb;
  _DAT_00419f9c = 7;
  _DAT_00419fa0 = 0x8b2;
  CString::Format(this_00,(char *)&pCStack_7c);
  uVar10 = 0xffffffff;
  pcVar12 = pcStack_78;
  do {
    pcVar15 = pcVar12;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar15 = pcVar12 + 1;
    cVar2 = *pcVar12;
    pcVar12 = pcVar15;
  } while (cVar2 != '\0');
  uVar10 = ~uVar10;
  pcVar12 = pcVar15 + -uVar10;
  pcVar15 = &DAT_00419fa8;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar15 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar15 = pcVar15 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar15 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar15 = pcVar15 + 1;
  }
  Shell_NotifyIconA(0,(PNOTIFYICONDATAA)&DAT_00419f90);
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_2c = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  SystemParametersInfoA(4,0,&uStack_2c,0);
  SystemParametersInfoA(0x71,10,(PVOID)0xa,0);
  SystemParametersInfoA(0x5d,0,(PVOID)0x0,0);
  CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_00404950,param_1,0,
               (LPDWORD)(auStack_5c + 4));
  CString::~CString((CString *)&pCStack_64);
  CString::~CString((CString *)&pcStack_78);
  ExceptionList = (void *)CONCAT31((int3)((uint)unaff_retaddr >> 8),1);
  return;
}



/* ==== FUN_00406000 @ 00406000 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00406000(void *this,tagMSG *param_1)

{
  short sVar1;
  HRAWINPUT pHVar2;
  POINT pt;
  int iVar3;
  tagMSG *ptVar4;
  CPlex *pCVar5;
  CPlex *pCVar6;
  BOOL BVar7;
  int iVar8;
  CString *this_00;
  CString *this_01;
  uint uVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  CPlex *pCVar13;
  longlong lVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  CString local_48 [4];
  void *local_44;
  LARGE_INTEGER local_40;
  LARGE_INTEGER LStack_38;
  undefined auStack_2c [16];
  int iStack_1c;
  LONG LStack_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00414220;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_44 = this;
  CString::CString(local_48);
  local_4 = 0;
  local_40.s.LowPart = 0;
  local_40.s.HighPart = 0;
  QueryPerformanceCounter(&local_40);
  QueryPerformanceFrequency(&LStack_38);
  lVar14 = __allmul(local_40.s.LowPart,local_40.s.HighPart,1000,0);
  uVar16 = 0x406075;
  uVar15 = __alldiv((uint)lVar14,(uint)((ulonglong)lVar14 >> 0x20),LStack_38.s.LowPart,
                    LStack_38.s.HighPart);
  ptVar4 = param_1;
  iVar3 = DAT_0041f014;
  iVar8 = DAT_0041f010;
  LStack_18 = (LONG)uVar15;
  uVar9 = *(uint *)(param_1 + 4);
  if (uVar9 < 0x115) {
    if (uVar9 == 0x114) {
      sVar1 = *(short *)(param_1 + 8);
      if (sVar1 == 1) {
        DAT_0041f014 = 1;
      }
      else if (sVar1 == 0) {
        DAT_0041f014 = -1;
      }
      else if (sVar1 == 8) {
        DAT_0041d178 = DAT_0041d178 + DAT_0041f014;
        DAT_0041f014 = 0;
        DAT_0041d170 = DAT_0041d170 + iVar3 * 10;
        FUN_00409100((LPCSTR)this);
      }
    }
    else {
      switch(uVar9) {
      case 0xff:
        pHVar2 = *(HRAWINPUT *)(param_1 + 0xc);
        puVar10 = (undefined4 *)(auStack_2c + 0xc);
        puVar12 = (undefined4 *)&stack0xffffff94;
        for (iVar8 = 5; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar12 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar12 = puVar12 + 1;
        }
        FUN_004125b0(this,pHVar2,uVar16,(int)lVar14,(int)((ulonglong)lVar14 >> 0x20));
        break;
      case 0x100:
      case 0x104:
        if ((DAT_0041f008 == 10) && (*(int *)(param_1 + 8) == 0xd)) {
          iVar8 = _mbsicmp((uchar *)DAT_0041eeb0,DAT_0041eeb4);
          if (iVar8 == 0) {
            CString::Format(this_00,&DAT_0041ec10);
            _DAT_0041ec14 = 0xff00;
          }
          else {
            CString::Format(DAT_0041eeb0,&DAT_0041ec10);
            _DAT_0041ec14 = 0xff;
          }
          _DAT_0041ec18 = 10;
          _DAT_0041ec1c = 0xa0;
          _DAT_0041ec20 = 2;
          DAT_0041ec08 = 0;
          DAT_0041effc = 1;
          CString::operator=((CString *)&DAT_0041eeb0,&DAT_00419e94);
        }
        FUN_00409530(this,*(undefined4 *)(ptVar4 + 4),*(int *)(ptVar4 + 8),*(LONG *)(ptVar4 + 0xc));
        break;
      case 0x101:
      case 0x105:
        iVar8 = *(int *)(param_1 + 8);
        if (iVar8 == 0x20) {
          FUN_00406dc0((LPCSTR)this);
        }
        else {
          if ((DAT_0041efb4 == 0) &&
             (((DAT_0041f008 == 7 || (DAT_0041f008 == 9)) && (iVar8 == 0x4c)))) {
            DAT_0041efe4 = DAT_0041efe4 ^ 1;
LAB_00406872:
            local_4 = 0xffffffff;
            CString::~CString(local_48);
            ExceptionList = puStack_8;
            return 1;
          }
          if (iVar8 == 0x42) {
            _DAT_0041efc4 = _DAT_0041efc4 ^ 1;
          }
          else if (iVar8 == 0x54) {
            DAT_0041efe0 = DAT_0041efe0 ^ 1;
          }
          else if ((DAT_0041f008 == 5) && (iVar8 == 0x50)) {
            FUN_004108c0();
            goto LAB_00406872;
          }
        }
        break;
      case 0x102:
        if (DAT_0041f008 == 10) {
          CString::CString((CString *)&param_1);
          local_4 = CONCAT31(local_4._1_3_,1);
          CString::Format(this_01,(char *)&param_1);
          CString::operator+=((CString *)&DAT_0041eeb0,(CString *)&stack0x00000008);
          CString::~CString((CString *)&stack0x00000008);
        }
      }
    }
    goto switchD_0040609f_caseD_103;
  }
  if (uVar9 < 0x20c) {
    if (uVar9 == 0x20b) {
LAB_004063fd:
      if ((*(uint *)(param_1 + 8) & 0x20000) == 0) {
        if ((*(uint *)(param_1 + 8) & 0x10000) != 0) {
          _DAT_0041f060 = _DAT_0041f060 + 1;
        }
      }
      else {
        _DAT_0041f05c = _DAT_0041f05c + 1;
      }
      goto LAB_0040641c;
    }
    switch(uVar9) {
    case 0x115:
      sVar1 = *(short *)(param_1 + 8);
      if (sVar1 == 1) {
        DAT_0041f010 = -1;
      }
      else if (sVar1 == 0) {
        DAT_0041f010 = 1;
      }
      else if (sVar1 == 8) {
        DAT_0041d17c = DAT_0041d17c + DAT_0041f010;
        DAT_0041f010 = 0;
        DAT_0041d174 = DAT_0041d174 + iVar8 * -10;
        FUN_00409100((LPCSTR)this);
      }
      break;
    case 0x200:
      goto switchD_00406301_caseD_200;
    case 0x201:
    case 0x202:
    case 0x203:
    case 0x204:
    case 0x205:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
      goto switchD_00406301_caseD_201;
    case 0x20a:
      DAT_0041d17c = DAT_0041d17c + (int)(short)((uint)*(undefined4 *)(param_1 + 8) >> 0x10) / 0x78;
      iVar8 = (int)(short)((uint)*(undefined4 *)(param_1 + 8) >> 0x10);
      iVar8 = (int)((ulonglong)((longlong)iVar8 * 0x77777777) >> 0x20) - iVar8;
      DAT_0041d174 = DAT_0041d174 + ((iVar8 >> 6) - (iVar8 >> 0x1f)) * 10;
      FUN_00409100((LPCSTR)this);
    }
    goto switchD_0040609f_caseD_103;
  }
  if (0x20e < uVar9) {
    if (uVar9 == 0x4bd) {
      CWnd::ShowWindow((CWnd *)this,9);
      SetForegroundWindow(*(HWND *)((int)this + 0x20));
      BringWindowToTop(*(HWND *)((int)this + 0x20));
      goto LAB_00406872;
    }
    goto switchD_0040609f_caseD_103;
  }
  if (uVar9 == 0x20e) {
    iVar8 = (int)(short)((uint)*(undefined4 *)(param_1 + 8) >> 0x10);
    iVar8 = (int)((ulonglong)((longlong)iVar8 * 0x77777777) >> 0x20) - iVar8;
    DAT_0041d178 = DAT_0041d178 + ((iVar8 >> 6) - (iVar8 >> 0x1f));
    DAT_0041d170 = DAT_0041d170 +
                   ((int)(short)((uint)*(undefined4 *)(param_1 + 8) >> 0x10) / 0x78) * 10;
    FUN_00409100((LPCSTR)this);
    goto switchD_0040609f_caseD_103;
  }
  if (uVar9 != 0x20c) {
    if (uVar9 != 0x20d) goto switchD_0040609f_caseD_103;
    goto LAB_004063fd;
  }
LAB_0040641c:
  if (*(int *)(param_1 + 4) == 0x20c) {
    if ((*(uint *)(param_1 + 8) & 0x20000) == 0) {
      if ((*(uint *)(param_1 + 8) & 0x10000) != 0) {
        _DAT_0041f074 = _DAT_0041f074 + 1;
      }
    }
    else {
      _DAT_0041f070 = _DAT_0041f070 + 1;
    }
  }
switchD_00406301_caseD_201:
  _DAT_00418540 = 1;
  if (*(int *)(param_1 + 4) == 0x203) {
    DAT_0041f050 = DAT_0041f050 + 1;
  }
  if (*(int *)(param_1 + 4) == 0x206) {
    _DAT_0041f054 = _DAT_0041f054 + 1;
  }
  if (*(int *)(param_1 + 4) == 0x209) {
    _DAT_0041f058 = _DAT_0041f058 + 1;
  }
  if (*(int *)(param_1 + 4) == 0x201) {
    DAT_0041f050 = DAT_0041f050 + 1;
  }
  if (*(int *)(param_1 + 4) == 0x202) {
    DAT_0041f064 = DAT_0041f064 + 1;
    FUN_00409ae0((CWnd *)this);
  }
  if (*(int *)(ptVar4 + 4) == 0x204) {
    _DAT_0041f054 = _DAT_0041f054 + 1;
  }
  if (*(int *)(ptVar4 + 4) == 0x205) {
    _DAT_0041f068 = _DAT_0041f068 + 1;
  }
  if (*(int *)(ptVar4 + 4) == 0x207) {
    _DAT_0041f058 = _DAT_0041f058 + 1;
  }
  if (*(int *)(ptVar4 + 4) == 0x208) {
    _DAT_0041f06c = _DAT_0041f06c + 1;
  }
  FUN_004075a0((int)this);
switchD_00406301_caseD_200:
  _DAT_0041f030 = *(undefined4 *)(ptVar4 + 8);
  if (((byte)*(undefined4 *)(ptVar4 + 8) & 3) == 3) {
    DAT_0041f02c = 1;
LAB_00406509:
    if (((byte)ptVar4[8] & 0x73) == 0) {
      FUN_00406dc0((LPCSTR)this);
      DAT_0041f02c = 0;
    }
  }
  else if (DAT_0041f02c == 1) goto LAB_00406509;
  auStack_2c._12_4_ = *(undefined4 *)(ptVar4 + 0x14);
  iStack_1c = *(int *)(ptVar4 + 0x18);
  ScreenToClient(*(HWND *)((int)this + 0x20),(LPPOINT)(auStack_2c + 0xc));
  DAT_0041d128 = (CString *)auStack_2c._12_4_;
  DAT_0041d12c = iStack_1c;
  if ((*(int *)(ptVar4 + 4) == 0x200) && (_DAT_0041efe8 = 1, DAT_0041efb4 == 0)) {
    *(LONG *)(&DAT_0041a228 + DAT_0041f03c * 4) = LStack_18;
    DAT_0041f03c = (DAT_0041f03c + 1) % 2000;
    _DAT_0041f038 = LStack_18;
    if ((DAT_0041f008 == 7) || (this = (void *)local_40.s.LowPart, DAT_0041f008 == 9)) {
      iVar8 = auStack_2c._12_4_ - (int)DAT_0041ee08;
      DAT_0041ee08 = (CString *)auStack_2c._12_4_;
      DAT_0041ee10 = DAT_0041ee10 + iVar8;
      DAT_0041ee14 = DAT_0041ee14 + (iStack_1c - DAT_0041ee0c);
      DAT_0041ee0c = iStack_1c;
      CString::Format((CString *)auStack_2c._12_4_,&DAT_0041ec10);
      DAT_0041effc = 1;
      this = (void *)local_40.s.LowPart;
    }
  }
  if ((DAT_0041f00c == 1) && (DAT_0041f020 != 1)) {
    uStack_10 = 1;
    pvStack_c = (void *)0x6;
  }
  else {
    uStack_10 = 0;
  }
  if (((byte)ptVar4[8] & 0x73) != 0) {
    if (DAT_0041f020 == 1) {
      DAT_0041f020 = 0;
      FUN_00409060((int)this);
      DAT_0041effc = 1;
    }
    uVar9 = *(uint *)(ptVar4 + 8);
    pvStack_c = (void *)0x0;
    if ((uVar9 & 1) == 0) {
      if ((uVar9 & 2) == 0) {
        if ((uVar9 & 0x10) == 0) {
          if ((uVar9 & 0x40) == 0) {
            if ((uVar9 & 0x20) != 0) {
              pvStack_c = (void *)0x4;
            }
          }
          else {
            pvStack_c = (void *)0x3;
          }
        }
        else {
          pvStack_c = (void *)0x2;
        }
      }
      else {
        pvStack_c = (void *)0x1;
      }
    }
    else {
      pvStack_c = (void *)0x0;
    }
    uStack_10 = 1;
  }
  pCVar13 = DAT_0041a1f8;
  pCVar6 = DAT_0041a200;
  if (DAT_0041a200 == (CPlex *)0x0) {
    pCVar5 = CPlex::Create((CPlex **)&DAT_0041a204,DAT_0041a208,0x1c);
    pCVar6 = DAT_0041a200;
    pCVar5 = pCVar5 + DAT_0041a208 * 0x1c + -0x18;
    uVar9 = DAT_0041a208;
    if (-1 < (int)(DAT_0041a208 - 1)) {
      do {
        pCVar6 = pCVar5;
        *(CPlex **)pCVar6 = DAT_0041a200;
        uVar9 = uVar9 - 1;
        DAT_0041a200 = pCVar6;
        pCVar5 = pCVar6 + -0x1c;
      } while (uVar9 != 0);
    }
  }
  DAT_0041a200 = *(CPlex **)pCVar6;
  *(CPlex **)(pCVar6 + 4) = pCVar13;
  *(undefined4 *)pCVar6 = 0;
  DAT_0041a1fc = DAT_0041a1fc + 1;
  *(undefined4 *)(pCVar6 + 8) = 0;
  *(undefined4 *)(pCVar6 + 0xc) = 0;
  *(undefined4 *)(pCVar6 + 0x10) = 0;
  *(undefined4 *)(pCVar6 + 0x14) = 0;
  *(undefined4 *)(pCVar6 + 0x18) = 0;
  piVar11 = &iStack_1c;
  pCVar13 = pCVar6 + 8;
  for (iVar8 = 5; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(int *)pCVar13 = *piVar11;
    piVar11 = piVar11 + 1;
    pCVar13 = pCVar13 + 4;
  }
  pCVar13 = pCVar6;
  if (DAT_0041a1f8 != (CPlex *)0x0) {
    *(CPlex **)DAT_0041a1f8 = pCVar6;
    pCVar13 = DAT_0041a1f4;
  }
  DAT_0041a1f4 = pCVar13;
  DAT_0041a1f8 = pCVar6;
  FUN_00407040((int)this);
  if (*(int *)(ptVar4 + 4) == 0x201) {
    GetWindowRect(*(HWND *)((int)this + 0xc0),(LPRECT)auStack_2c);
    pt.y = LStack_18;
    pt.x = iStack_1c;
    BVar7 = PtInRect((RECT *)auStack_2c,pt);
    if (BVar7 != 0) {
      CWnd::EnableWindow((CWnd *)((int)this + 0xa0),1);
    }
    FUN_0040a440(iStack_1c,LStack_18);
  }
  _DAT_0041853c = 1;
  _DAT_0041efd8 = 1;
  if (DAT_0041effc == 0) {
    _DAT_0041f000 = 1;
  }
  _DAT_0041ee00 = iStack_1c;
  _DAT_0041ee04 = LStack_18;
switchD_0040609f_caseD_103:
  iVar8 = CDialog::PreTranslateMessage((CDialog *)this,ptVar4);
  CString::~CString((CString *)&local_44);
  ExceptionList = puStack_8;
  return iVar8;
}



/* ==== FUN_004069d0 @ 004069d0 ==== */

void __fastcall FUN_004069d0(CWnd *param_1)

{
  DAT_0041f088 = 1;
  DAT_00418580 = 0;
  FUN_00406a00();
  CWnd::Default(param_1);
  return;
}



/* ==== FUN_00406a00 @ 00406a00 ==== */

void FUN_00406a00(void)

{
  return;
}



/* ==== FUN_00406dc0 @ 00406dc0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00406dc0(LPCSTR param_1)

{
  undefined4 *puVar1;
  HDC pHVar2;
  CDC *pCVar3;
  HDC hdc;
  CString *this;
  int *piVar4;
  LPCSTR local_10;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00414258;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_10 = param_1;
  CString::CString((CString *)&local_10);
  local_4 = 0;
  if (DAT_0041efdc == 1) {
    DAT_0041efdc = 0;
    puVar1 = &DAT_0041ebd0;
    do {
      *puVar1 = 1;
      puVar1 = puVar1 + 7;
    } while ((int)puVar1 < 0x41ee00);
  }
  piVar4 = &DAT_0041ee18;
  do {
    InvalidateRect(*(HWND *)(*piVar4 + 0x20),(RECT *)0x0,1);
    piVar4 = piVar4 + 1;
  } while ((int)piVar4 < 0x41ee6c);
  InvalidateRect(*(HWND *)(param_1 + 0xc0),(RECT *)0x0,1);
  DAT_0041ee10 = 0;
  DAT_0041ee14 = 0;
  DAT_0041ee08 = 0;
  DAT_0041ee0c = 0;
  if (DAT_0041f008 != 0xb) {
    CString::Format(this,&DAT_0041ec10);
  }
  if (DAT_0041efe4 == 1) {
    SetCursorPos(DAT_0041a220 / 2,DAT_0041a224 / 2);
    DAT_0041ee08 = DAT_0041a220 / 2;
    DAT_0041ee0c = DAT_0041a224 / 2;
  }
  DAT_0041d178 = 0;
  DAT_0041d17c = 0;
  DAT_0041d170 = DAT_0041a220 / 2 + -0x24;
  DAT_0041d174 = DAT_0041a224 / 2 + -0x24;
  DAT_0041d168 = DAT_0041a220 / 2 + -0x23;
  DAT_0041d16c = DAT_0041a224 / 2 + -0x25;
  DAT_0041f064 = 0;
  DAT_0041f050 = 0;
  _DAT_0041f068 = 0;
  _DAT_0041f054 = 0;
  _DAT_0041f06c = 0;
  _DAT_0041f058 = 0;
  DAT_0041f01c = DAT_0041f01c | 0x80;
  _DAT_0041f070 = 0;
  _DAT_0041f05c = 0;
  DAT_00418560 = 0xffffffff;
  _DAT_0041f074 = 0;
  _DAT_0041f060 = 0;
  pHVar2 = GetDC(*(HWND *)(param_1 + 0x20));
  pCVar3 = CDC::FromHandle(pHVar2);
  pHVar2 = CreateCompatibleDC((HDC)0x0);
  hdc = CreateCompatibleDC((HDC)0x0);
  SelectObject(pHVar2,DAT_0041f044);
  SelectObject(hdc,DAT_0041f048);
  BitBlt(hdc,0,0,DAT_0041a220,DAT_0041a224,pHVar2,0,0,0xcc0020);
  BitBlt(*(HDC *)(pCVar3 + 4),0,0,DAT_0041a220,DAT_0041a224,pHVar2,0,0,0xcc0020);
  DeleteDC(pHVar2);
  DeleteDC(hdc);
  ReleaseDC(*(HWND *)(param_1 + 0x20),*(HDC *)(pCVar3 + 4));
  FUN_00409100(param_1);
  FUN_00407040((int)param_1);
  FUN_00409770();
  DAT_0041effc = 1;
  local_4 = 0xffffffff;
  CString::~CString((CString *)&local_10);
  ExceptionList = pvStack_c;
  return;
}



/* ==== FUN_00407040 @ 00407040 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00407040(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  HDC pHVar3;
  CDC *this;
  HPEN h;
  HDC hdc;
  int iVar4;
  int unaff_EBX;
  undefined4 *puVar5;
  int *piVar6;
  LPCSTR unaff_EDI;
  int *piVar7;
  code *pcVar8;
  COLORREF color;
  tagSIZE tStack_40;
  int local_34;
  undefined auStack_2c [8];
  int aiStack_24 [2];
  void *pvStack_1c;
  int iStack_18;
  int iStack_14;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puVar5 = DAT_0041a1f4;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00414278;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_34 = param_1;
  pHVar3 = GetDC(*(HWND *)(param_1 + 0x20));
  this = CDC::FromHandle(pHVar3);
  CDC::MoveTo(this,&tStack_40.cy,DAT_0041a1e8);
  pHVar3 = CreateCompatibleDC((HDC)0x0);
  pcVar8 = SelectObject_exref;
  SelectObject(pHVar3,DAT_0041f048);
  MoveToEx(pHVar3,DAT_0041a1e8,DAT_0041a1ec,(LPPOINT)0x0);
  if (puVar5 != (undefined4 *)0x0) {
    do {
      puVar1 = DAT_0041a1f4;
      tStack_40.cx = *puVar5;
      piVar6 = puVar5 + 2;
      piVar7 = aiStack_24;
      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
      DAT_0041a1f4 = (undefined4 *)*DAT_0041a1f4;
      if (DAT_0041a1f4 == (undefined4 *)0x0) {
        DAT_0041a1f8 = 0;
      }
      else {
        DAT_0041a1f4[1] = 0;
      }
      *puVar1 = DAT_0041a200;
      DAT_0041a200 = puVar1;
      DAT_0041a1fc = DAT_0041a1fc + -1;
      if (DAT_0041a1fc == 0) {
        FUN_004134c0(0x41a1f0);
      }
      iVar2 = iStack_14;
      iVar4 = aiStack_24[0];
      if (iStack_18 == 1) {
        if (iStack_14 < 7) {
          SelectObject(*(HDC *)(this + 4),(&DAT_0041a1b4)[iStack_14]);
          SelectObject(pHVar3,(&DAT_0041a1b4)[iVar2]);
        }
        iVar4 = aiStack_24[0];
        if (DAT_0041f028 == 0) {
          CDC::MoveTo(this,auStack_2c,aiStack_24[0]);
          MoveToEx(pHVar3,iVar4,aiStack_24[0],(LPPOINT)0x0);
        }
        CDC::LineTo(this,iVar4,aiStack_24[1]);
        LineTo(pHVar3,iVar4,aiStack_24[1]);
        if (DAT_0041efe0 != 0) {
          if (iStack_14 == 6) {
            color = 0xff;
          }
          else {
            color = 0xff0000;
          }
          h = CreatePen(0,4,color);
          SelectObject(pHVar3,h);
          SelectObject(*(HDC *)(this + 4),h);
          MoveToEx(pHVar3,DAT_0041a1e8,DAT_0041a1ec,(LPPOINT)0x0);
          LineTo(pHVar3,DAT_0041a1e8,DAT_0041a1ec);
          MoveToEx(*(HDC *)(this + 4),DAT_0041a1e8,DAT_0041a1ec,(LPPOINT)0x0);
          LineTo(*(HDC *)(this + 4),DAT_0041a1e8,DAT_0041a1ec);
          SelectObject(pHVar3,DAT_0041a1b4);
          SelectObject(*(HDC *)(this + 4),DAT_0041a1b4);
          DeleteObject(h);
          iVar4 = aiStack_24[0];
        }
      }
      DAT_0041a1ec = aiStack_24[1];
      DAT_0041f028 = iStack_18;
      puVar5 = (undefined4 *)tStack_40.cx;
      pcVar8 = SelectObject_exref;
      DAT_0041a1e8 = iVar4;
    } while ((undefined4 *)tStack_40.cx != (undefined4 *)0x0);
  }
  CString::CString((CString *)&stack0xffffffbc);
  puStack_8 = (undefined *)0x0;
  CString::Format((CString *)&stack0xffffffbc,(char *)&stack0xffffffbc);
  hdc = CreateCompatibleDC((HDC)0x0);
  (*pcVar8)(hdc,DAT_0041d118);
  (*pcVar8)(hdc,DAT_0041d13c);
  GetTextExtentPointA(hdc,unaff_EDI,*(int *)(unaff_EDI + -8),&tStack_40);
  _DAT_0041d10c = tStack_40.cy;
  DAT_0041d108 = (undefined4 *)tStack_40.cx;
  BitBlt(hdc,0,0,tStack_40.cx + 3,tStack_40.cy + 3,pHVar3,0,0x3a,0xcc0020);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xa0a0a);
  TextOutA(hdc,0,0,unaff_EDI,*(int *)(unaff_EDI + -8));
  TextOutA(hdc,1,0,unaff_EDI,*(int *)(unaff_EDI + -8));
  TextOutA(hdc,0,1,unaff_EDI,*(int *)(unaff_EDI + -8));
  TextOutA(hdc,0,2,unaff_EDI,*(int *)(unaff_EDI + -8));
  TextOutA(hdc,2,0,unaff_EDI,*(int *)(unaff_EDI + -8));
  TextOutA(hdc,2,2,unaff_EDI,*(int *)(unaff_EDI + -8));
  SetTextColor(hdc,0x9b9b9b);
  TextOutA(hdc,1,1,unaff_EDI,*(int *)(unaff_EDI + -8));
  BitBlt(*(HDC *)(this + 4),0,0x3a,tStack_40.cx + 3,tStack_40.cy + 3,hdc,0,0,0xcc0020);
  DeleteDC(hdc);
  DeleteDC(pHVar3);
  ReleaseDC(*(HWND *)(unaff_EBX + 0x20),*(HDC *)(this + 4));
  iStack_14 = 0xffffffff;
  CString::~CString((CString *)&stack0xffffffb0);
  ExceptionList = pvStack_1c;
  return;
}



/* ==== FUN_00407500 @ 00407500 ==== */

void __fastcall FUN_00407500(CWnd *param_1)

{
  undefined4 *puVar1;
  
  DAT_0041f07c = 0;
  FUN_0040ff50((LPCSTR)param_1);
  DAT_0041f078 = 0;
  DeleteObject(DAT_0041f044);
  DeleteObject(DAT_0041f048);
  DeleteObject(DAT_0041d118);
  puVar1 = &DAT_0041a1b4;
  do {
    if ((HGDIOBJ)*puVar1 != (HGDIOBJ)0x0) {
      DeleteObject((HGDIOBJ)*puVar1);
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x41a1e4);
  puVar1 = &DAT_0041d130;
  do {
    if ((HGDIOBJ)*puVar1 != (HGDIOBJ)0x0) {
      DeleteObject((HGDIOBJ)*puVar1);
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x41d160);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0041a198);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0041a180);
  Shell_NotifyIconA(2,(PNOTIFYICONDATAA)&DAT_00419f90);
  CWnd::DestroyWindow(param_1);
  return;
}



/* ==== FUN_004075a0 @ 004075a0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004075a0(int param_1)

{
  HDC pHVar1;
  CDC *this;
  undefined4 uVar2;
  CString *this_00;
  LPCSTR extraout_ECX;
  LPCSTR extraout_ECX_00;
  int *piVar3;
  int unaff_EBP;
  LPCSTR unaff_ESI;
  int iVar4;
  int unaff_EDI;
  COLORREF CVar5;
  int iVar6;
  int iVar7;
  int iStack_a8;
  undefined *this_01;
  int iStack_94;
  LPCSTR pCVar8;
  int iVar9;
  int iStack_80;
  LPCSTR pCVar10;
  int iStack_6c;
  LPCSTR pCStack_68;
  LONG LStack_64;
  int local_44 [5];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004142e8;
  local_c = ExceptionList;
  if (DAT_0041eff4 == _DAT_0041f030) {
    return 0;
  }
  DAT_0041eff4 = _DAT_0041f030;
  ExceptionList = &local_c;
  local_44[0] = param_1;
  pHVar1 = GetDC(*(HWND *)(param_1 + 0x20));
  this = CDC::FromHandle(pHVar1);
  LStack_64 = 0x40760c;
  SelectObject(*(HDC *)(this + 4),DAT_0041d14c);
  CDC::SetBkMode(this,1);
  if ((_DAT_0041f030 & 1) == 0) {
    (**(code **)(*(int *)this + 0x38))();
    LStack_64 = 0x40767c;
    CString::CString((CString *)local_44,&DAT_00418a90);
    puStack_8 = (undefined *)0x1;
    LStack_64 = local_44[0];
    pCStack_68 = (LPCSTR)0x0;
    iStack_6c = 2;
    (**(code **)(*(int *)this + 100))();
  }
  else {
    (**(code **)(*(int *)this + 0x38))();
    LStack_64 = 0x40763b;
    CString::CString((CString *)local_44,&DAT_00418a90);
    puStack_8 = (undefined *)0x0;
    LStack_64 = local_44[0];
    pCStack_68 = (LPCSTR)0x0;
    iStack_6c = 2;
    (**(code **)(*(int *)this + 100))();
  }
  uStack_18 = 0xffffffff;
  CString::~CString((CString *)&stack0xffffffac);
  CString::CString((CString *)&stack0xffffffac,&DAT_00418a90);
  iStack_80 = 0x4076cc;
  GetTextExtentPoint32A
            (*(HDC *)(this + 8),unaff_ESI,*(int *)(unaff_ESI + -8),(LPSIZE)&stack0xffffffb0);
  CString::~CString((CString *)&stack0xffffffac);
  if ((_DAT_0041f030 & 0x10) == 0) {
    (**(code **)(*(int *)this + 0x38))();
    CString::CString((CString *)&stack0xffffffa8,&DAT_00418a8c);
    uStack_1c = 3;
    pCVar10 = (LPCSTR)0x0;
    iStack_80 = unaff_EBP + 0x24;
    (**(code **)(*(int *)this + 100))();
  }
  else {
    (**(code **)(*(int *)this + 0x38))();
    CString::CString((CString *)&stack0xffffffa8,&DAT_00418a8c);
    uStack_1c = 2;
    pCVar10 = (LPCSTR)0x0;
    iStack_80 = unaff_EBP + 0x24;
    (**(code **)(*(int *)this + 100))();
  }
  uStack_2c = 0xffffffff;
  CString::~CString((CString *)&pCStack_68);
  CString::CString((CString *)&pCStack_68,&DAT_00418a8c);
  iStack_94 = 0x40778c;
  GetTextExtentPoint32A(*(HDC *)(this + 8),pCStack_68,*(int *)(pCStack_68 + -8),(LPSIZE)&LStack_64);
  CString::~CString((CString *)&pCStack_68);
  iVar4 = unaff_EBP + 0x46 + LStack_64;
  if ((_DAT_0041f030 & 2) == 0) {
    (**(code **)(*(int *)this + 0x38))();
    CString::CString((CString *)&iStack_6c,&DAT_00418a88);
    uStack_30 = 5;
    pCVar8 = (LPCSTR)0x0;
    iStack_94 = iVar4;
    iVar9 = iStack_6c;
    (**(code **)(*(int *)this + 100))();
  }
  else {
    (**(code **)(*(int *)this + 0x38))();
    CString::CString((CString *)&iStack_6c,&DAT_00418a88);
    uStack_30 = 4;
    pCVar8 = (LPCSTR)0x0;
    iStack_94 = iVar4;
    iVar9 = iStack_6c;
    (**(code **)(*(int *)this + 100))();
  }
  local_44[1] = 0xffffffff;
  CString::~CString((CString *)&stack0xffffff84);
  CString::CString((CString *)&stack0xffffff84,&DAT_00418a88);
  iStack_a8 = 0x40784d;
  GetTextExtentPoint32A(*(HDC *)(this + 8),pCVar10,*(int *)(pCVar10 + -8),(LPSIZE)&stack0xffffff88);
  CString::~CString((CString *)&stack0xffffff84);
  unaff_EDI = iVar4 + 0x22 + unaff_EDI;
  pCStack_68 = (LPCSTR)unaff_EDI;
  if ((_DAT_0041f030 & 0x40) == 0) {
    (**(code **)(*(int *)this + 0x38))();
    CString::CString((CString *)&iStack_80,&DAT_00418a84);
    local_44[0] = 7;
    pCVar10 = (LPCSTR)0x0;
    iStack_a8 = unaff_EDI;
    (**(code **)(*(int *)this + 100))();
  }
  else {
    (**(code **)(*(int *)this + 0x38))();
    CString::CString((CString *)&iStack_80,&DAT_00418a84);
    local_44[0] = 6;
    pCVar10 = (LPCSTR)0x0;
    iStack_a8 = unaff_EDI;
    (**(code **)(*(int *)this + 100))();
  }
  CString::~CString((CString *)&stack0xffffff70);
  CString::CString((CString *)&stack0xffffff70,&DAT_00418a84);
  GetTextExtentPoint32A(*(HDC *)(this + 8),pCVar8,*(int *)(pCVar8 + -8),(LPSIZE)&stack0xffffff74);
  CString::~CString((CString *)&stack0xffffff70);
  iStack_6c = unaff_EDI + 0x22 + iVar9;
  if ((_DAT_0041f030 & 0x20) == 0) {
    (**(code **)(*(int *)this + 0x38))();
    CString::CString((CString *)&iStack_94,&DAT_00418a80);
    (**(code **)(*(int *)this + 100))();
  }
  else {
    (**(code **)(*(int *)this + 0x38))();
    CString::CString((CString *)&iStack_94,&DAT_00418a80);
    (**(code **)(*(int *)this + 100))();
  }
  pCStack_68 = (LPCSTR)0xffffffff;
  CString::~CString((CString *)&stack0xffffff5c);
  CString::CString((CString *)&stack0xffffff5c,&DAT_00418a84);
  GetTextExtentPoint32A(*(HDC *)(this + 8),pCVar10,*(int *)(pCVar10 + -8),(LPSIZE)&stack0xffffff60);
  CString::~CString((CString *)&stack0xffffff5c);
  ReleaseDC(*(HWND *)(iStack_a8 + 0x20),*(HDC *)(this + 4));
  piVar3 = (int *)&stack0xffffff68;
  iVar4 = 0;
  do {
    CString::CString((CString *)&stack0xffffff54);
    pCStack_68 = (LPCSTR)0xa;
    CString::Format(this_00,&stack0xffffff54);
    iVar7 = 0;
    iVar6 = 6;
    CVar5 = 0x7d7d7d;
    this_01 = &stack0xffffff38;
    pCVar8 = extraout_ECX;
    CString::CString((CString *)&stack0xffffff38,(CString *)&iStack_a8);
    iVar9 = *piVar3;
    FUN_00407cf0(pCVar10,iVar9 + -0x1f,0xc,pCVar8,CVar5,iVar6,iVar7);
    CString::Format((CString *)&iStack_a8,(char *)&iStack_a8);
    iVar7 = 0;
    iVar6 = 6;
    CVar5 = 0x7d7d7d;
    pCVar8 = extraout_ECX_00;
    CString::CString((CString *)&stack0xffffff3c,(CString *)&stack0xffffff5c);
    uVar2 = FUN_00407cf0(this_01,iVar9 + -0x1f,0x1a,pCVar8,CVar5,iVar6,iVar7);
    CString::~CString((CString *)&stack0xffffff5c);
    iVar4 = iVar4 + 4;
    piVar3 = piVar3 + 2;
  } while (iVar4 < 0x14);
  ExceptionList = pCStack_68;
  return uVar2;
}



/* ==== FUN_00407ac0 @ 00407ac0 ==== */

void __fastcall FUN_00407ac0(LPCSTR param_1)

{
  HDC pHVar1;
  CDC *pCVar2;
  HDC hdc;
  CString *this;
  CString aCStack_1c [4];
  LPCSTR local_18;
  int iStack_14;
  tagSIZE tStack_10;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00414308;
  tStack_10.cy = (LONG)ExceptionList;
  if (DAT_0041f034 != DAT_00418560) {
    ExceptionList = &tStack_10.cy;
    local_18 = param_1;
    pHVar1 = GetDC(*(HWND *)(param_1 + 0x20));
    pCVar2 = CDC::FromHandle(pHVar1);
    pHVar1 = CreateCompatibleDC((HDC)0x0);
    hdc = CreateCompatibleDC((HDC)0x0);
    SelectObject(pHVar1,DAT_0041f048);
    SelectObject(hdc,DAT_0041d118);
    SelectObject(hdc,DAT_0041d130);
    CString::CString(aCStack_1c);
    uStack_4 = 0;
    CString::Format(this,(char *)aCStack_1c);
    GetTextExtentPointA(hdc,local_18,*(int *)(local_18 + -8),&tStack_10);
    BitBlt(hdc,300,0,tStack_10.cx + 3,tStack_10.cy + 3,pHVar1,300,0,0xcc0020);
    SetBkMode(hdc,1);
    SetTextColor(hdc,0x7d7d);
    SetTextColor(hdc,0x2323);
    TextOutA(hdc,0x12d,1,local_18,*(int *)(local_18 + -8));
    SetTextColor(hdc,0xf0f);
    SetTextColor(hdc,0xffff);
    TextOutA(hdc,300,0,local_18,*(int *)(local_18 + -8));
    BitBlt(*(HDC *)(pCVar2 + 4),300,0,tStack_10.cx + 3,tStack_10.cy + 3,hdc,300,0,0xcc0020);
    DAT_00418560 = DAT_0041f034;
    DeleteDC(pHVar1);
    DeleteDC(hdc);
    ReleaseDC(*(HWND *)(iStack_14 + 0x20),*(HDC *)(pCVar2 + 4));
    CString::~CString((CString *)&local_18);
  }
  ExceptionList = puStack_8;
  return;
}



/* ==== FUN_00407c80 @ 00407c80 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407c80(void)

{
  float10 fVar1;
  
  if (DAT_00418580 != 0) {
    do {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0041a198);
      if ((DAT_0041f07c != 0) && (DAT_0041f008 == 0)) {
        fVar1 = FUN_0040ff00();
        _DAT_0041f080 = (double)(fVar1 * (float10)_DAT_00415b30);
      }
      Sleep(0x96);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0041a198);
    } while (DAT_00418580 != 0);
  }
  return;
}



/* ==== FUN_00407cf0 @ 00407cf0 ==== */

void __thiscall
FUN_00407cf0(void *this,int param_1,int param_2,LPCSTR param_3,COLORREF param_4,int param_5,
            int param_6)

{
  HDC pHVar1;
  CDC *pCVar2;
  HDC hdc;
  int iVar3;
  tagSIZE tStack_34;
  tagRECT tStack_2c;
  CDC aCStack_1c [16];
  void *pvStack_c;
  undefined *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00414330;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  pHVar1 = GetDC(*(HWND *)((int)this + 0x20));
  pCVar2 = CDC::FromHandle(pHVar1);
  iVar3 = param_5;
  if (9 < param_5) {
    iVar3 = 9;
  }
  pHVar1 = CreateCompatibleDC((HDC)0x0);
  hdc = CreateCompatibleDC((HDC)0x0);
  SelectObject(pHVar1,DAT_0041f048);
  SelectObject(hdc,DAT_0041d118);
  SelectObject(hdc,(HGDIOBJ)(&DAT_0041d130)[iVar3]);
  GetTextExtentPointA(hdc,param_3,*(int *)(param_3 + -8),&tStack_34);
  BitBlt(hdc,param_1,param_2,tStack_34.cx + 5,tStack_34.cy + 5,pHVar1,param_1,param_2,0xcc0020);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xa0a0a);
  tStack_2c.left = param_1;
  tStack_2c.top = param_2;
  tStack_2c.right = tStack_34.cx + 5 + param_1;
  tStack_2c.bottom = tStack_34.cy + 5 + param_2;
  if (param_6 == 1) {
    CDC::CDC(aCStack_1c);
    local_4._0_1_ = 1;
    CDC::Attach(aCStack_1c,hdc);
    CDC::FillSolidRect(aCStack_1c,&tStack_2c,0x191919);
    CDC::Detach(aCStack_1c);
    local_4 = (uint)local_4._1_3_ << 8;
    CDC::~CDC(aCStack_1c);
  }
  TextOutA(hdc,param_1 + 1,param_2 + 1,param_3,*(int *)(param_3 + -8));
  TextOutA(hdc,param_1 + 1,param_2 + 1,param_3,*(int *)(param_3 + -8));
  param_5 = *(int *)(param_3 + -8);
  TextOutA(hdc,param_1 + 2,param_2 + 2,param_3,param_5);
  param_5 = *(int *)(param_3 + -8);
  TextOutA(hdc,param_1 + 3,param_2 + 3,param_3,param_5);
  TextOutA(hdc,param_1 + 3,param_2 + 2,param_3,*(int *)(param_3 + -8));
  TextOutA(hdc,param_1 + 2,param_2 + 3,param_3,*(int *)(param_3 + -8));
  SetTextColor(hdc,param_4);
  TextOutA(hdc,param_1 + 2,param_2 + 2,param_3,*(int *)(param_3 + -8));
  BitBlt(*(HDC *)(pCVar2 + 4),param_1,param_2,tStack_34.cx + 5,tStack_34.cy + 5,hdc,param_1,param_2,
         0xcc0020);
  DeleteDC(pHVar1);
  DeleteDC(hdc);
  ReleaseDC(*(HWND *)((int)this + 0x20),*(HDC *)(pCVar2 + 4));
  local_4 = 0xffffffff;
  CString::~CString((CString *)&param_3);
  ExceptionList = pvStack_c;
  return;
}



/* ==== FUN_00407f60 @ 00407f60 ==== */

void __fastcall FUN_00407f60(CString *param_1)

{
  void *pvVar1;
  int iVar2;
  CString *pCVar3;
  int iVar4;
  CString *this;
  LPCSTR extraout_ECX;
  CString *this_00;
  LPCSTR extraout_ECX_00;
  LPCSTR extraout_ECX_01;
  LPCSTR extraout_ECX_02;
  LPCSTR extraout_ECX_03;
  LPCSTR extraout_ECX_04;
  CString *this_01;
  LPCSTR extraout_ECX_05;
  LPCSTR pCVar5;
  LPCSTR extraout_ECX_06;
  LPCSTR extraout_ECX_07;
  LPCSTR extraout_ECX_08;
  CString *pCVar6;
  int iVar7;
  uint uVar8;
  COLORREF CVar9;
  wchar_t *pwVar10;
  int iVar11;
  char *pcStack_a18;
  CString aCStack_a14 [4];
  CString *pCStack_a10;
  int iStack_a0c;
  COLORREF CStack_a08;
  int iStack_a04;
  CString aCStack_a00 [4];
  CString *pCStack_9fc;
  undefined4 uStack_9f8;
  undefined *puStack_9f4;
  CString *local_9f0;
  void *pvStack_9ec;
  int iStack_9e8;
  void *pvStack_9e4;
  CString aCStack_9e0 [4];
  int iStack_9dc;
  CString aCStack_9d8 [4];
  CString aCStack_9d4 [4];
  CString aCStack_9d0 [4];
  CString aCStack_9cc [4];
  undefined *puStack_9c8;
  undefined *puStack_9c4;
  undefined2 uStack_9c0;
  undefined uStack_9be;
  char cStack_9bd;
  CString CStack_9bc;
  char cStack_9bb;
  undefined uStack_9ba;
  undefined uStack_9b9;
  CString aCStack_9b8 [4];
  CString aCStack_9b4 [4];
  CString aCStack_9b0 [4];
  CString aCStack_9ac [4];
  CString aCStack_9a8 [4];
  CString aCStack_9a4 [4];
  CString CStack_9a0;
  undefined uStack_99f;
  undefined uStack_99e;
  undefined uStack_99d;
  CString aCStack_99c [4];
  CString aCStack_998 [12];
  CString aCStack_98c [4];
  CString aCStack_988 [4];
  CString aCStack_984 [4];
  CString aCStack_980 [4];
  CString aCStack_97c [4];
  CString aCStack_978 [4];
  CString aCStack_974 [4];
  CString aCStack_970 [4];
  int aiStack_96c [3];
  int iStack_960;
  undefined auStack_95c [2];
  undefined uStack_95a;
  undefined auStack_958 [2];
  undefined uStack_956;
  undefined uStack_955;
  undefined uStack_954;
  undefined uStack_900;
  undefined uStack_8ff;
  undefined uStack_8fe;
  undefined uStack_8fd;
  undefined auStack_8e0 [32];
  undefined auStack_8c0 [8];
  undefined4 auStack_8b8 [333];
  CString aCStack_384 [888];
  void *pvStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_0041452f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_9f0 = param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0041a180);
  iStack_960 = DAT_0041a224 + -0x28;
  aiStack_96c[0] = 10;
  aiStack_96c[1] = 0x78;
  aiStack_96c[2] = DAT_0041a220;
  FUN_004094b0(param_1,aiStack_96c);
  CString::CString(aCStack_98c,s_PixArt_3601_00418e30);
  iVar7 = 0;
  iStack_4 = 0;
  CString::CString(aCStack_988,s_Avago_3080_00418e24);
  iStack_4._0_1_ = 1;
  CString::CString(aCStack_984,s_Avago_6010_00418e18);
  iStack_4._0_1_ = 2;
  CString::CString(aCStack_980,s_Avago_7010_00418e0c);
  iStack_4._0_1_ = 3;
  CString::CString(aCStack_97c,s_Avago_6090_00418e00);
  iStack_4._0_1_ = 4;
  CString::CString(aCStack_978,s_Philips_PLN2030_00418df0);
  iStack_4._0_1_ = 5;
  CString::CString(aCStack_974,s_Avago_9500_00418de4);
  iStack_4._0_1_ = 6;
  CString::CString((CString *)&pcStack_a18);
  iStack_4._0_1_ = 7;
  CString::CString(aCStack_a14);
  iStack_4._0_1_ = 8;
  CString::CString((CString *)&pCStack_a10,(ushort *)u___d_Model___s___Ver___d__d___Sen_00418d94);
  iStack_4 = CONCAT31(iStack_4._1_3_,9);
  CStack_a08 = 0xffffff;
  iVar2 = FUN_004026e0(0x41d180);
  if (0 < iVar2) {
    pCVar6 = (CString *)&DAT_0041d598;
    iStack_9e8 = 0x91;
    pCStack_9fc = (CString *)&DAT_0041d598;
    do {
      iVar2 = *(int *)pCVar6;
      if (iVar2 == 2) {
        CStack_a08 = 0xffffff;
        CString::operator=((CString *)&pCStack_a10,
                           (ushort *)u____2d_Gaming___s___Ver___d__d___S_00418d34);
        iVar2 = FUN_004015f0(&DAT_0041d180,iVar7);
        if (iVar2 == 0xe) {
          pwVar10 = u_B115G_00418d28;
        }
        else {
          iVar2 = FUN_004015f0(&DAT_0041d180,iVar7);
          if (iVar2 == 0xf) {
            pwVar10 = u_B189G___Sonix_00418d0c;
          }
          else {
            iVar2 = FUN_004015f0(&DAT_0041d180,iVar7);
            if (iVar2 == 0x10) {
              pwVar10 = u_L189G_00418d00;
            }
            else {
              iVar2 = FUN_004015f0(&DAT_0041d180,iVar7);
              if (iVar2 == 0x11) {
                pwVar10 = u_LFD1_00418cf4;
              }
              else {
                iVar2 = FUN_004015f0(&DAT_0041d180,iVar7);
                if (iVar2 == 0x12) {
                  pwVar10 = u_L191G_00418ce8;
                }
                else {
                  pwVar10 = u_Unknow_00418cd8;
                }
              }
            }
          }
        }
        CString::operator=((CString *)&pcStack_a18,(ushort *)pwVar10);
        iVar2 = *(int *)(pCVar6 + -0x50);
        pCVar3 = FUN_00401610(&DAT_0041d180,aCStack_970,iVar7);
        iVar4 = _mbscmp(*(uchar **)pCVar3,&DAT_00418080);
        uStack_9f8 = (void *)CONCAT13(iVar4 == 0,(undefined3)uStack_9f8);
        CString::~CString(aCStack_970);
        if (uStack_9f8._3_1_ != '\0') {
          CString::operator=((CString *)&pcStack_a18,(ushort *)u_LFD5_00418ccc);
        }
        if (5 < iVar2) {
          iVar2 = 5;
        }
        if (((0 < *(int *)(pcStack_a18 + -8)) && (*pcStack_a18 == 'L')) && (iVar2 == 1)) {
          CString::SetAt((CString *)&pcStack_a18,0,'B');
        }
        pCStack_9fc = pCStack_a10;
        FUN_00401600(&DAT_0041d180,iVar7);
        FUN_00401200(&DAT_0041d180,iVar7);
        CString::Format(pCStack_9fc,(char *)aCStack_a14);
        CString::CString((CString *)&iStack_9e8);
        CString::Format(this,(char *)&iStack_9e8);
        pCVar3 = (CString *)&pvStack_9e4;
LAB_00408712:
        CString::~CString(pCVar3);
        pCVar5 = extraout_ECX_01;
      }
      else if (iVar2 == 1) {
        CStack_a08 = 0x37ffff;
        CString::CString((CString *)&iStack_a04);
        iStack_4 = CONCAT31(iStack_4._1_3_,0xb);
        CString::operator=((CString *)&pCStack_a10,
                           (ushort *)u____2d_2_4G_RX_TX____s____s___Ver_00418c50);
        FUN_00401480(&DAT_0041d180,iVar7,3,0x8c,auStack_95c);
        iVar2 = FUN_004015e0(&DAT_0041d180,iVar7);
        if ((iVar2 == 9) || (iVar2 = FUN_004015f0(&DAT_0041d180,iVar7), 0x15 < iVar2)) {
          CString::Format(uStack_95a,(char *)&iStack_a04);
        }
        else {
          CString::Format((CString *)&iStack_a04,(char *)&iStack_a04);
        }
        uStack_956 = 0;
        uStack_955 = 5;
        uStack_954 = 8;
        FUN_00401480(&DAT_0041d180,iVar7,5,0,auStack_958);
        FUN_00401480(&DAT_0041d180,iVar7,4,0x8c,auStack_958);
        uVar8 = (CONCAT11(uStack_954,uStack_955) & 0xff) * 0x100 +
                (CONCAT12(uStack_954,CONCAT11(uStack_955,uStack_956)) & 0xff);
        uStack_956 = 0;
        uStack_955 = 5;
        uStack_954 = 8;
        FUN_00401480(&DAT_0041d180,iVar7,2,0,auStack_958);
        CString::CString(&CStack_9bc,s_unknow_00418c08);
        CString::CString(aCStack_9b8,s_Mouse_00418c00);
        CString::CString(aCStack_9b4,&DAT_00418bfc);
        CString::CString(aCStack_9b0,&DAT_00418bf8);
        CString::CString(aCStack_9ac,s_Full_Speed_Mouse__500_report__00418bd8);
        CString::CString(aCStack_9a8,s_Longlife_Mouse_00418bc8);
        CString::CString(aCStack_9a4,s_Gaming_00418bc0);
        CString::CString(&CStack_9a0,s_Multimedia_Mouse_00418bac);
        CString::CString((CString *)&CStack_a08);
        if (uVar8 < 8) {
          CString::operator=((CString *)&CStack_a08,&CStack_9bc + uVar8 * 4);
        }
        else {
          CString::operator=((CString *)&CStack_a08,s_Unknow_00418ba4);
        }
        CString::CString((CString *)&pCStack_9fc);
        CString::Format((CString *)(CONCAT12(uStack_954,CONCAT11(uStack_955,uStack_956)) & 0xff),
                        (char *)&pCStack_9fc);
        FUN_00401610(&DAT_0041d180,&CStack_9bc,iVar7);
        uStack_9c0 = (undefined2)CStack_a08;
        uStack_9be = (undefined)(CStack_a08 >> 0x10);
        cStack_9bd = (char)(CStack_a08 >> 0x18);
        FUN_004015f0(&DAT_0041d180,iVar7);
        CString::Format((CString *)&iStack_a0c,(char *)&iStack_a0c);
        CString::~CString(aCStack_9b8);
        CString::~CString((CString *)&puStack_9f4);
        CString::~CString(aCStack_a00);
        CString::~CString(aCStack_998);
        CString::~CString(aCStack_99c);
        CString::~CString(&CStack_9a0);
        CString::~CString(aCStack_9a4);
        CString::~CString(aCStack_9a8);
        CString::~CString(aCStack_9ac);
        CString::~CString(aCStack_9b0);
        CString::~CString(aCStack_9b4);
        CString::~CString((CString *)&uStack_9f8);
        pCVar5 = extraout_ECX;
        pCVar6 = local_9f0;
      }
      else {
        if (iVar2 != 4) {
          pCVar3 = FUN_00401610(&DAT_0041d180,(CString *)&puStack_9f4,iVar7);
          iStack_4 = CONCAT31(iStack_4._1_3_,0x17);
          CString::Format(*(CString **)pCVar3,(char *)aCStack_a14);
          pCVar3 = (CString *)&local_9f0;
          goto LAB_00408712;
        }
        FUN_004015f0(&DAT_0041d180,iVar7);
        CString::Format(this_00,(char *)aCStack_a14);
        pCVar5 = extraout_ECX_00;
      }
      iVar7 = iVar7 + 1;
      iVar11 = 1;
      iVar4 = 8;
      CStack_9bc = SUB41(&stack0xfffff5d4,0);
      cStack_9bb = (char)((uint)&stack0xfffff5d4 >> 8);
      uStack_9ba = (undefined)((uint)&stack0xfffff5d4 >> 0x10);
      uStack_9b9 = (undefined)((uint)&stack0xfffff5d4 >> 0x18);
      pCVar3 = pCStack_9fc;
      CString::CString((CString *)&stack0xfffff5d4,(CString *)&CStack_a08);
      iVar2 = iStack_9dc;
      pvVar1 = pvStack_9e4;
      FUN_00407cf0(pvStack_9e4,5,iStack_9dc + -0x19,pCVar5,(COLORREF)pCVar3,iVar4,iVar11);
      operator+();
      operator+();
      pCVar3 = (CString *)operator+();
      iStack_4._0_1_ = 0x1a;
      CString::operator=(aCStack_a14,pCVar3);
      iStack_4._0_1_ = 0x19;
      CString::~CString((CString *)&pvStack_9e4);
      iStack_4._0_1_ = 0x18;
      CString::~CString(aCStack_9e0);
      iStack_4 = CONCAT31(iStack_4._1_3_,9);
      CString::~CString((CString *)&iStack_9dc);
      iVar11 = 1;
      iVar4 = 8;
      puStack_9c8 = &stack0xfffff5c8;
      pCVar5 = extraout_ECX_02;
      CVar9 = CStack_a08;
      CString::CString((CString *)&stack0xfffff5c8,aCStack_a14);
      FUN_00407cf0(pvVar1,5,iVar2,pCVar5,CVar9,iVar4,iVar11);
      pCVar6 = pCVar6 + 4;
      iStack_9e8 = iVar2 + 0x37;
      pCStack_9fc = pCVar6;
      iVar2 = FUN_004026e0(0x41d180);
    } while (iVar7 < iVar2);
  }
  FUN_00403000(auStack_8b8);
  iStack_4 = CONCAT31(iStack_4._1_3_,0x1b);
  FUN_00403210((int)auStack_8b8);
  FUN_00403dc0(0x41eeb8);
  iVar4 = 0;
  iStack_a0c = iVar7;
  iVar2 = FUN_004026e0((int)auStack_8b8);
  if (0 < iVar2) {
    pCVar6 = aCStack_384;
    pvStack_9ec = (void *)(iVar7 * 0x37);
    pCStack_9fc = pCVar6;
    do {
      iStack_a0c = iVar4 + iVar7;
      CString::operator=((CString *)&pCStack_a10,
                         (ushort *)u____2d_Gaming___s___Ver___d__d___S_00418d34);
      iVar2 = FUN_004015e0(auStack_8b8,iVar4);
      if (iVar2 == 1) {
        pwVar10 = u_229G_00418b28;
      }
      else {
        iVar2 = FUN_004015e0(auStack_8b8,iVar4);
        if (iVar2 == 2) {
          pwVar10 = (wchar_t *)&DAT_00418b20;
        }
        else {
          iVar2 = FUN_004015e0(auStack_8b8,iVar4);
          if (iVar2 == 5) {
            pwVar10 = u_FD3_B_00418b14;
          }
          else {
            iVar2 = FUN_004015e0(auStack_8b8,iVar4);
            if (iVar2 == 4) {
              pwVar10 = u_FD1_Innovation_00418af4;
            }
            else {
              pwVar10 = (wchar_t *)&DAT_00418aec;
            }
          }
        }
      }
      CString::operator=((CString *)&pcStack_a18,(ushort *)pwVar10);
      iStack_9e8 = *(int *)(pCVar6 + 0x2d4);
      if (3 < iStack_9e8) {
        iStack_9e8 = 3;
      }
      CString::CString(aCStack_9d8,s_Avago_6090_00418e00);
      iStack_4._0_1_ = 0x1c;
      CString::CString(aCStack_9d4,s_Avago_9500_00418de4);
      iStack_4._0_1_ = 0x1d;
      CString::CString(aCStack_9d0,s_Avago_7010_00418e0c);
      iStack_4._0_1_ = 0x1e;
      CString::CString(aCStack_9cc,s_Avago_3080_00418e24);
      iStack_4._0_1_ = 0x1f;
      FUN_00401600(auStack_8b8,iVar4);
      FUN_004015f0(auStack_8b8,iVar4);
      CString::Format(aCStack_a14,(char *)aCStack_a14);
      iVar11 = 1;
      iVar2 = 8;
      CVar9 = 0xffffff;
      uStack_9c0 = SUB42(&stack0xfffff5cc,0);
      uStack_9be = (undefined)((uint)&stack0xfffff5cc >> 0x10);
      cStack_9bd = (char)((uint)&stack0xfffff5cc >> 0x18);
      pCVar5 = extraout_ECX_03;
      CString::CString((CString *)&stack0xfffff5cc,(CString *)&pCStack_a10);
      FUN_00407cf0(pvStack_9ec,5,iStack_9e8 + 0x78,pCVar5,CVar9,iVar2,iVar11);
      operator+();
      iStack_4 = CONCAT31(iStack_4._1_3_,0x20);
      operator+();
      puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,0x21);
      pCVar3 = (CString *)operator+();
      pvStack_c._0_1_ = 0x22;
      CString::operator=((CString *)&stack0xfffff5e4,pCVar3);
      pvStack_c._0_1_ = 0x21;
      CString::~CString((CString *)&pvStack_9e4);
      pvStack_c._0_1_ = 0x20;
      CString::~CString((CString *)&iStack_9e8);
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,0x1f);
      CString::~CString((CString *)&pvStack_9ec);
      iVar2 = FUN_004015f0(auStack_8c0,iVar4);
      pCVar5 = extraout_ECX_04;
      if (iVar2 < 100) {
        uStack_900 = 0;
        uStack_8ff = 7;
        uStack_8fe = 1;
        uStack_8fd = 1;
        FUN_004038a0(auStack_8c0,iVar4,&uStack_900,auStack_8e0,8);
        Sleep(8);
        CString::CString((CString *)&iStack_a0c);
        pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,0x23);
        pCStack_a10 = (CString *)0x0;
        do {
          CStack_9a0 = (CString)0x0;
          uStack_99f = 1;
          uStack_99e = 3;
          uStack_99d = 0;
          aCStack_99c[0] = CStack_a08._0_1_;
          FUN_004038a0(auStack_8b8,iVar4,&CStack_9a0,(undefined *)&uStack_9c0,2);
          CStack_9a0 = (CString)0x0;
          uStack_99f = 1;
          uStack_99e = 4;
          uStack_99d = 0;
          aCStack_99c[0] = CStack_a08._0_1_;
          FUN_004038a0(auStack_8b8,iVar4,&CStack_9a0,(undefined *)&uStack_9c0,2);
          if (cStack_9bb == '\0') {
            cStack_9bb = '\x01';
          }
          if (cStack_9bd == '\0') {
            cStack_9bd = '\x01';
          }
          CString::CString(aCStack_a00);
          iStack_4 = CONCAT31(iStack_4._1_3_,0x24);
          CString::Format(this_01,(char *)aCStack_a00);
          CString::operator+=(aCStack_a00,(CString *)&pCStack_9fc);
          iVar2 = iStack_a04;
          if (iStack_a04 != 3) {
            CString::operator+=(aCStack_a00,&DAT_00418ae8);
          }
          CString::~CString((CString *)&pCStack_9fc);
          iStack_a04 = iVar2 + 1;
        } while (iStack_a04 < 4);
        pCVar6 = (CString *)operator+();
        iStack_4._0_1_ = 0x25;
        CString::operator+=(aCStack_a14,pCVar6);
        iStack_4._0_1_ = 0x23;
        CString::~CString((CString *)&puStack_9f4);
        iStack_4 = CONCAT31(iStack_4._1_3_,0x1f);
        CString::~CString((CString *)&iStack_a04);
        pCVar5 = extraout_ECX_05;
        pCVar6 = pCStack_9fc;
      }
      iVar11 = 1;
      iVar2 = 8;
      CVar9 = 0xffffff;
      puStack_9c4 = &stack0xfffff5c8;
      CString::CString((CString *)&stack0xfffff5c8,aCStack_a14);
      pvVar1 = pvStack_9ec;
      FUN_00407cf0(local_9f0,5,(int)pvStack_9ec + 0x91,pCVar5,CVar9,iVar2,iVar11);
      iStack_4._0_1_ = 0x1e;
      CString::~CString(aCStack_9cc);
      iStack_4._0_1_ = 0x1d;
      CString::~CString(aCStack_9d0);
      iStack_4._0_1_ = 0x1c;
      CString::~CString(aCStack_9d4);
      iStack_4 = CONCAT31(iStack_4._1_3_,0x1b);
      CString::~CString(aCStack_9d8);
      pvStack_9ec = (void *)((int)pvVar1 + 0x37);
      pCVar6 = pCVar6 + 4;
      iVar4 = iVar4 + 1;
      pCStack_9fc = pCVar6;
      iVar2 = FUN_004026e0((int)auStack_8b8);
    } while (iVar4 < iVar2);
  }
  iVar2 = 0;
  if (0 < DAT_0041ef0c) {
    iVar7 = iStack_a0c * 0x37 + 0x91;
    do {
      CString::operator=((CString *)&pCStack_a10,
                         (ushort *)u____2d_Gaming___s___Ver___d__d___S_00418d34);
      CString::operator=((CString *)&pcStack_a18,(ushort *)u_231G_00418ad4);
      CString::CString(aCStack_9d8,s_Avago_6090_00418e00);
      iStack_4._0_1_ = 0x26;
      CString::CString(aCStack_9d4,s_Avago_9500_00418de4);
      iStack_4._0_1_ = 0x27;
      CString::CString(aCStack_9d0,s_Avago_7010_00418e0c);
      iStack_4._0_1_ = 0x28;
      CString::CString(aCStack_9cc,s_Avago_3080_00418e24);
      iStack_4._0_1_ = 0x29;
      CString::Format(pCStack_a10,(char *)aCStack_a14);
      iVar11 = 1;
      iVar4 = 8;
      CVar9 = 0xffffff;
      local_9f0 = (CString *)&stack0xfffff5cc;
      pCVar5 = extraout_ECX_06;
      CString::CString((CString *)&stack0xfffff5cc,(CString *)&pCStack_a10);
      FUN_00407cf0(pvStack_9ec,5,iVar7 + -0x19,pCVar5,CVar9,iVar4,iVar11);
      operator+();
      iStack_4 = CONCAT31(iStack_4._1_3_,0x2a);
      operator+();
      puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,0x2b);
      pCVar6 = (CString *)operator+();
      pvStack_c._0_1_ = 0x2c;
      CString::operator=((CString *)&stack0xfffff5e4,pCVar6);
      pvStack_c._0_1_ = 0x2b;
      CString::~CString((CString *)&pvStack_9e4);
      pvStack_c._0_1_ = 0x2a;
      CString::~CString((CString *)&iStack_9e8);
      pvStack_c._0_1_ = 0x29;
      CString::~CString((CString *)&pvStack_9ec);
      iVar11 = 1;
      iVar4 = 8;
      CVar9 = 0xffffff;
      pCStack_9fc = (CString *)&stack0xfffff5c0;
      pCVar5 = extraout_ECX_07;
      CString::CString((CString *)&stack0xfffff5c0,(CString *)&stack0xfffff5e4);
      FUN_00407cf0(uStack_9f8,5,iVar7,pCVar5,CVar9,iVar4,iVar11);
      pvStack_c._0_1_ = 0x28;
      CString::~CString(aCStack_9d4);
      pvStack_c._0_1_ = 0x27;
      CString::~CString(aCStack_9d8);
      pvStack_c._0_1_ = 0x26;
      CString::~CString((CString *)&iStack_9dc);
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,0x1b);
      CString::~CString(aCStack_9e0);
      iVar2 = iVar2 + 1;
      iVar7 = iVar7 + 0x37;
    } while (iVar2 < DAT_0041ef0c);
  }
  iVar2 = FUN_004026e0(0x41d180);
  if (((iVar2 == 0) && (iVar2 = FUN_004026e0((int)auStack_8b8), iVar2 == 0)) && (DAT_0041ef0c == 0))
  {
    iVar7 = 1;
    iVar2 = 4;
    CVar9 = 0xff;
    puStack_9f4 = &stack0xfffff5c8;
    pCVar5 = extraout_ECX_08;
    CString::CString((CString *)&stack0xfffff5c8,s_Can_t_get_any_information___00418aac);
    FUN_00407cf0(local_9f0,0x14,0x78,pCVar5,CVar9,iVar2,iVar7);
  }
  FUN_004038d0((int)auStack_8b8);
  DAT_0041f020 = 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0041a180);
  iStack_4._0_1_ = 9;
  FUN_00403120(auStack_8b8);
  iStack_4._0_1_ = 8;
  CString::~CString((CString *)&pCStack_a10);
  iStack_4._0_1_ = 7;
  CString::~CString(aCStack_a14);
  iStack_4._0_1_ = 6;
  CString::~CString((CString *)&pcStack_a18);
  iStack_4._0_1_ = 5;
  CString::~CString(aCStack_974);
  iStack_4._0_1_ = 4;
  CString::~CString(aCStack_978);
  iStack_4._0_1_ = 3;
  CString::~CString(aCStack_97c);
  iStack_4._0_1_ = 2;
  CString::~CString(aCStack_980);
  iStack_4._0_1_ = 1;
  CString::~CString(aCStack_984);
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  CString::~CString(aCStack_988);
  iStack_4 = 0xffffffff;
  CString::~CString(aCStack_98c);
  ExceptionList = pvStack_c;
  return;
}



/* ==== FUN_00409060 @ 00409060 ==== */

void __fastcall FUN_00409060(int param_1)

{
  HDC pHVar1;
  CDC *pCVar2;
  int *piVar3;
  
  pHVar1 = GetDC(*(HWND *)(param_1 + 0x20));
  pCVar2 = CDC::FromHandle(pHVar1);
  pHVar1 = CreateCompatibleDC((HDC)0x0);
  SelectObject(pHVar1,DAT_0041f048);
  BitBlt(*(HDC *)(pCVar2 + 4),0,0,DAT_0041a220,DAT_0041a224,pHVar1,0,0,0xcc0020);
  DeleteDC(pHVar1);
  ReleaseDC(*(HWND *)(param_1 + 0x20),*(HDC *)(pCVar2 + 4));
  piVar3 = &DAT_0041ee18;
  do {
    InvalidateRect(*(HWND *)(*piVar3 + 0x20),(RECT *)0x0,1);
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0x41ee6c);
  InvalidateRect(*(HWND *)(param_1 + 0xc0),(RECT *)0x0,1);
  return;
}



/* ==== FUN_00409100 @ 00409100 ==== */

void __fastcall FUN_00409100(LPCSTR param_1)

{
  int x1;
  HDC pHVar1;
  HDC hdc;
  int *piVar2;
  CString aCStack_20 [4];
  LPCSTR local_1c;
  CDC *pCStack_18;
  int iStack_14;
  tagSIZE tStack_10;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00414548;
  tStack_10.cy = (LONG)ExceptionList;
  if (DAT_0041d174 < 0) {
    DAT_0041d174 = DAT_0041a224 + -0x49;
  }
  else if (DAT_0041a224 < DAT_0041d174 + 0x49) {
    DAT_0041d174 = 0;
  }
  if (DAT_0041d170 < 0) {
    DAT_0041d170 = DAT_0041a220 + -0x49;
  }
  else if (DAT_0041a220 < DAT_0041d170 + 0x49) {
    DAT_0041d170 = 0;
  }
  ExceptionList = &tStack_10.cy;
  local_1c = param_1;
  pHVar1 = GetDC(*(HWND *)(param_1 + 0x20));
  pCStack_18 = CDC::FromHandle(pHVar1);
  CString::CString(aCStack_20);
  uStack_4 = 0;
  CString::Format(DAT_0041d178,(char *)aCStack_20);
  pHVar1 = CreateCompatibleDC((HDC)0x0);
  hdc = CreateCompatibleDC((HDC)0x0);
  SelectObject(pHVar1,DAT_0041f048);
  SelectObject(hdc,DAT_0041d118);
  SelectObject(hdc,DAT_0041d13c);
  GetTextExtentPointA(hdc,local_1c,*(int *)(local_1c + -8),&tStack_10);
  x1 = DAT_0041d108 + 2;
  BitBlt(hdc,0,0,tStack_10.cx + 3,tStack_10.cy + 3,pHVar1,x1,0x3a,0xcc0020);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xa0a0a);
  TextOutA(hdc,0,0,local_1c,*(int *)(local_1c + -8));
  TextOutA(hdc,1,0,local_1c,*(int *)(local_1c + -8));
  TextOutA(hdc,0,1,local_1c,*(int *)(local_1c + -8));
  TextOutA(hdc,0,2,local_1c,*(int *)(local_1c + -8));
  TextOutA(hdc,2,0,local_1c,*(int *)(local_1c + -8));
  TextOutA(hdc,2,2,local_1c,*(int *)(local_1c + -8));
  SetTextColor(hdc,0x9b9b9b);
  TextOutA(hdc,1,1,local_1c,*(int *)(local_1c + -8));
  BitBlt(*(HDC *)(iStack_14 + 4),x1,0x3a,tStack_10.cx + 3,tStack_10.cy + 3,hdc,0,0,0xcc0020);
  if (((DAT_0041f01c & 0x80) != 0) ||
     (((DAT_0041f01c & 1) != 0 && ((DAT_0041d16c != DAT_0041d174 || (DAT_0041d168 != DAT_0041d170)))
      ))) {
    DAT_0041f01c = DAT_0041f01c & 0xffffff7f;
    BitBlt(hdc,0,0,0x49,0x49,pHVar1,DAT_0041d170,DAT_0041d174,0xcc0020);
    if ((DAT_0041f01c & 1) != 0) {
      DrawIconEx(hdc,0,0,DAT_0041d124,0x49,0x49,0,(HBRUSH)0x0,3);
    }
    BitBlt(*(HDC *)(iStack_14 + 4),DAT_0041d168,DAT_0041d16c,0x49,0x49,pHVar1,DAT_0041d168,
           DAT_0041d16c,0xcc0020);
    BitBlt(*(HDC *)(iStack_14 + 4),DAT_0041d170,DAT_0041d174,0x49,0x49,hdc,0,0,0xcc0020);
    piVar2 = &DAT_0041ee18;
    do {
      InvalidateRect(*(HWND *)(*piVar2 + 0x20),(RECT *)0x0,1);
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x41ee6c);
    InvalidateRect(*(HWND *)(pCStack_18 + 0xc0),(RECT *)0x0,1);
    DAT_0041effc = 1;
  }
  DAT_0041d168 = DAT_0041d170;
  DAT_0041d16c = DAT_0041d174;
  DeleteDC(hdc);
  DeleteDC(pHVar1);
  ReleaseDC(*(HWND *)(pCStack_18 + 0x20),*(HDC *)(iStack_14 + 4));
  CString::~CString((CString *)&local_1c);
  ExceptionList = puStack_8;
  return;
}



/* ==== FUN_004094b0 @ 004094b0 ==== */

void __thiscall FUN_004094b0(void *this,int *param_1)

{
  int y;
  int x;
  HDC pHVar1;
  CDC *pCVar2;
  
  pHVar1 = GetDC(*(HWND *)((int)this + 0x20));
  pCVar2 = CDC::FromHandle(pHVar1);
  pHVar1 = CreateCompatibleDC((HDC)0x0);
  SelectObject(pHVar1,DAT_0041f048);
  y = param_1[1];
  x = *param_1;
  BitBlt(*(HDC *)(pCVar2 + 4),x,y,(param_1[2] - x) + 1,(param_1[3] - y) + 1,pHVar1,x,y,0xcc0020);
  DeleteDC(pHVar1);
  ReleaseDC(*(HWND *)((int)this + 0x20),*(HDC *)(pCVar2 + 4));
  return;
}



/* ==== FUN_00409530 @ 00409530 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00409530(void *this,undefined4 param_1,int param_2,LONG param_3)

{
  LPCSTR extraout_ECX;
  undefined4 uVar1;
  LPCSTR pCVar2;
  COLORREF CVar3;
  int iVar4;
  int iVar5;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  undefined *local_98;
  CHAR local_94 [136];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0041456b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CString::CString((CString *)&local_ac,&DAT_00419e94);
  local_4 = 0;
  uVar1 = 0x14;
  if (param_2 == 0xb0) {
    CString::operator=((CString *)&local_ac,&DAT_00418ea4);
  }
  else if (param_2 == 0xb1) {
    CString::operator=((CString *)&local_ac,&DAT_00418e9c);
  }
  else if (param_2 == 0xaf) {
    CString::operator=((CString *)&local_ac,s_Vol___00418e94);
  }
  else if (param_2 == 0xae) {
    CString::operator=((CString *)&local_ac,s_Vol___00418e8c);
  }
  else if (param_2 == 0xb2) {
    CString::operator=((CString *)&local_ac,&DAT_00418e84);
  }
  else if (param_2 == 0xb3) {
    CString::operator=((CString *)&local_ac,s_Play_Pause_00418e78);
  }
  else if (param_2 == 0xac) {
    CString::operator=((CString *)&local_ac,s_WWW_Home_00418e6c);
  }
  else if (param_2 == 0xb4) {
    CString::operator=((CString *)&local_ac,s_E_mail_00418e64);
  }
  else if (param_2 == 0xa6) {
    CString::operator=((CString *)&local_ac,&DAT_00418e5c);
  }
  else if (param_2 == 0xa7) {
    CString::operator=((CString *)&local_ac,s_Forward_00418e54);
  }
  else {
    iVar4 = GetKeyNameTextA(param_3,local_94,0x84);
    if (0x84 < iVar4) {
      iVar4 = 0x84;
    }
    local_94[iVar4] = '\0';
    local_94[iVar4 + 1] = '\0';
    CString::operator=((CString *)&local_ac,local_94);
    uVar1 = 10;
  }
  if (*(int *)(local_ac + -8) != 0) {
    local_a0 = DAT_0041a220;
    local_a8 = DAT_0041a220 / 2 + -0x78;
    local_a4 = DAT_0041a224 / 2 + -0x28;
    local_9c = DAT_0041a224 / 2 + 0x50;
    FUN_004094b0(this,&local_a8);
    iVar5 = 0;
    iVar4 = 1;
    CVar3 = 0xff00;
    local_98 = &stack0xffffff3c;
    pCVar2 = extraout_ECX;
    CString::CString((CString *)&stack0xffffff3c,(CString *)&local_ac);
    FUN_00407cf0(this,DAT_0041a220 / 2 + -0x78,DAT_0041a224 / 2 + -0x28,pCVar2,CVar3,iVar4,iVar5);
    _DAT_0041f024 = uVar1;
  }
  local_4 = 0xffffffff;
  CString::~CString((CString *)&local_ac);
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00409770 @ 00409770 ==== */

undefined4 FUN_00409770(void)

{
  return 0;
}



/* ==== FUN_00409780 @ 00409780 ==== */

void __thiscall FUN_00409780(void *this,int param_1,int param_2)

{
  int iVar1;
  HDC pHVar2;
  HDC hdc;
  HGDIOBJ pvVar3;
  HCURSOR dwNewLong;
  int *piVar4;
  HWND hWnd;
  LPCSTR pCStack_3c;
  int iStack_38;
  void *local_34;
  int iStack_30;
  HDC pHStack_2c;
  CDC *pCStack_28;
  tagSIZE tStack_24;
  CDC aCStack_1c [4];
  HDC pHStack_18;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00414588;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_34 = this;
  pHVar2 = GetDC(*(HWND *)((int)this + 0x20));
  pCStack_28 = CDC::FromHandle(pHVar2);
  CDC::CDC(aCStack_1c);
  uStack_4 = 0;
  pHVar2 = CreateCompatibleDC((HDC)0x0);
  pHStack_2c = pHVar2;
  hdc = CreateCompatibleDC((HDC)0x0);
  SelectObject(pHVar2,DAT_0041f048);
  SelectObject(hdc,DAT_0041d118);
  SetBkMode(hdc,1);
  iStack_30 = 0;
  DAT_00418550 = -1;
  CDC::Attach(aCStack_1c,hdc);
  iStack_38 = 0;
  piVar4 = &DAT_0041d61c;
  do {
    if ((piVar4[-0xb] != 1) && (*piVar4 != 0)) {
      CString::CString((CString *)&pCStack_3c,(CString *)(piVar4 + -8));
      SelectObject(hdc,(HGDIOBJ)(&DAT_0041d130)[piVar4[-3]]);
      GetTextExtentPointA(hdc,pCStack_3c,*(int *)(pCStack_3c + -8),&tStack_24);
      SetTextColor(hdc,0x121212);
      BitBlt(hdc,0,0,tStack_24.cx + 5,tStack_24.cy + 5,pHStack_2c,piVar4[-5],piVar4[-4],0xcc0020);
      TextOutA(hdc,3,2,pCStack_3c,*(int *)(pCStack_3c + -8));
      TextOutA(hdc,2,3,pCStack_3c,*(int *)(pCStack_3c + -8));
      TextOutA(hdc,3,3,pCStack_3c,*(int *)(pCStack_3c + -8));
      iVar1 = DAT_0041f008;
      piVar4[1] = tStack_24.cx;
      piVar4[2] = tStack_24.cy;
      if ((iStack_38 == iVar1 + 7) || (iStack_38 == DAT_00418548)) {
LAB_00409971:
        if ((piVar4[-5] < param_1) && (param_1 < piVar4[-5] + 4 + tStack_24.cx)) {
          if ((piVar4[-4] < param_2) && (param_2 < piVar4[-4] + 4 + tStack_24.cy)) {
            iStack_30 = 1;
            DAT_00418550 = iStack_38;
          }
        }
        pvVar3 = GetStockObject(0);
        SelectObject(hdc,pvVar3);
        pvVar3 = GetStockObject(7);
        SelectObject(hdc,pvVar3);
        RoundRect(pHStack_18,0,0,tStack_24.cx + 5,tStack_24.cy + 5,8,8);
        SetTextColor(hdc,piVar4[-9]);
      }
      else {
        if ((((piVar4[-5] < param_1) && (param_1 < piVar4[-5] + 4 + tStack_24.cx)) &&
            (piVar4[-4] < param_2)) && (param_2 < piVar4[-4] + 4 + tStack_24.cy)) goto LAB_00409971;
        SetTextColor(hdc,piVar4[-6]);
        pvVar3 = GetStockObject(3);
        SelectObject(hdc,pvVar3);
        pvVar3 = GetStockObject(6);
        SelectObject(hdc,pvVar3);
        RoundRect(pHStack_18,0,0,tStack_24.cx + 5,tStack_24.cy + 5,8,8);
      }
      TextOutA(hdc,2,2,pCStack_3c,*(int *)(pCStack_3c + -8));
      BitBlt(*(HDC *)(pCStack_28 + 4),piVar4[-5],piVar4[-4],tStack_24.cx + 5,tStack_24.cy + 5,hdc,0,
             0,0xcc0020);
      CString::~CString((CString *)&pCStack_3c);
    }
    piVar4 = piVar4 + 0xe;
    iStack_38 = iStack_38 + 1;
    if (0x41e10b < (int)piVar4) {
      if (iStack_30 == 0) {
        dwNewLong = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
        hWnd = *(HWND *)((int)local_34 + 0x20);
      }
      else {
        dwNewLong = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f89);
        hWnd = *(HWND *)((int)local_34 + 0x20);
      }
      SetClassLongA(hWnd,-0xc,(LONG)dwNewLong);
      DeleteDC(pHStack_2c);
      DeleteDC(hdc);
      ReleaseDC(*(HWND *)((int)local_34 + 0x20),*(HDC *)(pCStack_28 + 4));
      uStack_4 = 0xffffffff;
      CDC::~CDC(aCStack_1c);
      ExceptionList = pvStack_c;
      return;
    }
  } while( true );
}



/* ==== FUN_00409ae0 @ 00409ae0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CString * __fastcall FUN_00409ae0(CWnd *param_1)

{
  uint uVar1;
  double dVar2;
  int iVar3;
  undefined4 *puVar4;
  CString *pCVar5;
  CString *pCVar6;
  CString *this;
  CString *extraout_ECX;
  CString *this_00;
  CString *extraout_ECX_00;
  undefined extraout_DL;
  byte bVar7;
  undefined4 unaff_EDI;
  DWORD local_80;
  DWORD local_7c;
  CDialog local_78 [4];
  CDialog local_74 [92];
  CString local_18 [4];
  void *local_14;
  undefined *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  local_10 = &LAB_004145b0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_0040a510(param_1,-1);
  if (DAT_00418550 != DAT_0041854c) {
    ExceptionList = local_14;
    return (CString *)0x0;
  }
  pCVar5 = DAT_00418550;
  if (DAT_00418550 < (CString *)0x32) {
    pCVar6 = (CString *)(uint)(byte)DAT_00418550[0x40a40c];
    switch(DAT_00418550) {
    case (CString *)0x0:
      pCVar5 = (CString *)PostMessageA(*(HWND *)(param_1 + 0x20),0x10,0,0);
      ExceptionList = local_14;
      return pCVar5;
    case (CString *)0x1:
      pCVar5 = (CString *)CWnd::ShowWindow(param_1,6);
      ExceptionList = local_14;
      return pCVar5;
    case (CString *)0x2:
      pCVar5 = (CString *)FUN_0040a510(param_1,2);
      ExceptionList = local_14;
      return pCVar5;
    case (CString *)0x3:
      uVar1 = DAT_0041f01c ^ 1;
      DAT_0041f01c = uVar1 | 0x80;
      if ((uVar1 & 1) != 0) {
        _DAT_0041d6a0 = 0x37ff;
        _DAT_0041d6ac = 0xffff;
        pCVar5 = (CString *)FUN_00409100((LPCSTR)param_1);
        ExceptionList = local_14;
        return pCVar5;
      }
      _DAT_0041d6a0 = 0x121212;
      _DAT_0041d6ac = 0xffffff;
      pCVar5 = (CString *)FUN_00409100((LPCSTR)param_1);
      ExceptionList = local_14;
      return pCVar5;
    case (CString *)0x4:
      pCVar5 = DAT_0041f00c;
      if (DAT_0041f00c == (CString *)0x0) {
        DAT_0041f00c = (CString *)0x1;
        _DAT_0041d6d8 = 0x37ff;
        _DAT_0041d6e4 = 0xffff;
        ExceptionList = local_14;
        return (CString *)0x0;
      }
      DAT_0041f00c = (CString *)0x0;
      _DAT_0041d6d8 = 0x121212;
      _DAT_0041d6e4 = 0xffffff;
      ExceptionList = local_14;
      return pCVar5;
    case (CString *)0x5:
      if (DAT_0041eff8 != (CString *)0x1) {
        pCVar5 = (CString *)FUN_0040a510(param_1,5);
        ExceptionList = local_14;
        return pCVar5;
      }
      break;
    case (CString *)0x6:
      if (DAT_0041efd4 != 1) {
        pCVar5 = (CString *)FUN_0040fb20(param_1,DAT_0041efd0);
        ExceptionList = local_14;
        return pCVar5;
      }
      if (DAT_0041f008 == 9) {
        pCVar5 = (CString *)FUN_00412310(param_1);
        ExceptionList = local_14;
        return pCVar5;
      }
      if (DAT_0041f008 == 10) {
        FUN_00404130(local_78,(CWnd *)0x0);
        local_c = 0;
        CString::operator=(local_18,(CString *)&DAT_0041eeb4);
        pCVar5 = (CString *)CDialog::DoModal(local_78);
        if (pCVar5 == (CString *)0x1) {
          pCVar5 = CString::operator=((CString *)&DAT_0041eeb4,local_18);
          CString::Format(DAT_0041eeb4,&DAT_0041ebd8);
          DAT_0041effc = 1;
          DAT_00418550 = (CString *)0xffffffff;
        }
        local_8 = 1;
        CString::~CString((CString *)&local_14);
        local_8 = 0xffffffff;
        CDialog::~CDialog(local_74);
        ExceptionList = local_10;
        return pCVar5;
      }
      pCVar5 = (CString *)FUN_0040afe0(param_1);
      ExceptionList = local_14;
      return pCVar5;
    default:
      pCVar5 = (CString *)
               FUN_0040a610(param_1,*(int *)((int)DAT_00418550 * 0x38 + 0x41d618),unaff_EDI);
      ExceptionList = local_14;
      return pCVar5;
    case (CString *)0x14:
      pCVar5 = DAT_0041eff8;
      if (DAT_0041eff8 == (CString *)0x0) {
        pCVar5 = (CString *)FUN_00407f60((CString *)param_1);
        ExceptionList = local_14;
        return pCVar5;
      }
      break;
    case (CString *)0x15:
      if (DAT_0041eff8 != (CString *)0x1) {
        DAT_00418544 = 0x15;
LAB_00409e69:
        FUN_0040d5d0();
        pCVar5 = (CString *)FUN_0040a510(param_1,0x15);
        ExceptionList = local_14;
        return pCVar5;
      }
      break;
    case (CString *)0x16:
      if (DAT_0041eff8 != (CString *)0x1) {
        DAT_00418544 = 0x16;
        FUN_0040e010();
        pCVar5 = (CString *)FUN_0040a510(param_1,0x16);
        ExceptionList = local_14;
        return pCVar5;
      }
      break;
    case (CString *)0x17:
      if (DAT_0041eff8 != (CString *)0x1) {
        DAT_00418544 = 0x17;
        goto LAB_00409e69;
      }
      break;
    case (CString *)0x18:
      if (DAT_0041eff8 != (CString *)0x1) {
        DAT_00418544 = 0x18;
        FUN_0040f1b0();
        pCVar5 = (CString *)FUN_0040a510(param_1,0x18);
        ExceptionList = local_14;
        return pCVar5;
      }
      break;
    case (CString *)0x19:
      pCVar5 = DAT_0041eff8;
      if (DAT_0041eff8 != (CString *)0x1) {
        DAT_0041efdc = 1;
        FUN_00406dc0((LPCSTR)param_1);
        DAT_00418544 = 0x19;
        FUN_0040a610(param_1,0,unaff_EDI);
        if (DAT_0041f078 == 0) {
          pCVar5 = (CString *)FUN_00410030(param_1,extraout_DL,unaff_EDI);
          ExceptionList = local_14;
          return pCVar5;
        }
        pCVar5 = (CString *)FUN_0040ff50((LPCSTR)param_1);
        ExceptionList = local_14;
        return pCVar5;
      }
      break;
    case (CString *)0x1a:
    case (CString *)0x1b:
    case (CString *)0x1c:
    case (CString *)0x1d:
    case (CString *)0x23:
    case (CString *)0x24:
    case (CString *)0x25:
    case (CString *)0x26:
    case (CString *)0x27:
      break;
    case (CString *)0x1e:
      iVar3 = DAT_0041f008;
      if (DAT_0041f008 == 9) {
        iVar3 = FUN_00411050(1);
        CString::Format(this,&DAT_0041ebd8);
        pCVar6 = extraout_ECX;
      }
      if (DAT_0041f008 == 10) {
        bVar7 = (char)DAT_00418530 + 1;
        DAT_00418530 = CONCAT31(DAT_00418530._1_3_,bVar7);
        pCVar5 = (CString *)(uint)bVar7;
        CString::Format(pCVar6,&DAT_0041ebf4);
        DAT_0041effc = 1;
        ExceptionList = local_10;
        return pCVar5;
      }
      pCVar5 = (CString *)
               CONCAT22((short)((uint)iVar3 >> 0x10),
                        (ushort)(_DAT_00418568 < _DAT_00415b50) << 8 |
                        (ushort)(NAN(_DAT_00418568) || NAN(_DAT_00415b50)) << 10 |
                        (ushort)(_DAT_00418568 == _DAT_00415b50) << 0xe);
      if ((_DAT_00418568 < _DAT_00415b50 || (_DAT_00418568 == _DAT_00415b50) != 0) &&
         (pCVar5 = _DAT_0041f004, _DAT_0041f004 == (CString *)0x0)) {
        dVar2 = _DAT_00418568 + _DAT_00415b48;
        DAT_0041856c = (CString *)((ulonglong)dVar2 >> 0x20);
        DAT_00418568 = SUB84(dVar2,0);
        pCVar5 = DAT_0041856c;
        pCVar6 = DAT_00418568;
        _DAT_00418568 = dVar2;
        CString::Format(pCVar6,&DAT_0041ebd8);
        DAT_0041effc = 1;
        ExceptionList = local_10;
        return pCVar5;
      }
      break;
    case (CString *)0x1f:
      if (DAT_0041f008 == 9) {
        pCVar5 = (CString *)FUN_00411050(2);
        CString::Format(this_00,&DAT_0041ebd8);
        pCVar6 = extraout_ECX_00;
      }
      if (DAT_0041f008 == 10) {
        bVar7 = (char)DAT_00418530 - 1;
        DAT_00418530 = CONCAT31(DAT_00418530._1_3_,bVar7);
        pCVar5 = (CString *)(uint)bVar7;
        CString::Format(pCVar6,&DAT_0041ebf4);
        DAT_0041ebec = 0;
        DAT_0041effc = 1;
        ExceptionList = local_10;
        return pCVar5;
      }
      pCVar5 = (CString *)
               CONCAT22((short)((uint)pCVar5 >> 0x10),
                        (ushort)(_DAT_00418568 < _DAT_00415b48) << 8 |
                        (ushort)(NAN(_DAT_00418568) || NAN(_DAT_00415b48)) << 10 |
                        (ushort)(_DAT_00418568 == _DAT_00415b48) << 0xe);
      if ((_DAT_00418568 >= _DAT_00415b48) &&
         (pCVar5 = _DAT_0041f004, _DAT_0041f004 == (CString *)0x0)) {
        _DAT_00418568 = _DAT_00418568 - _DAT_00415b48;
        dVar2 = _DAT_00418568;
LAB_0040a185:
        pCVar5 = (CString *)((ulonglong)dVar2 >> 0x20);
        CString::Format(SUB84(dVar2,0),&DAT_0041ebd8);
        DAT_0041effc = 1;
        ExceptionList = local_10;
        return pCVar5;
      }
      break;
    case (CString *)0x20:
      pCVar5 = _DAT_0041f004;
      if (_DAT_0041f004 == (CString *)0x0) {
        if (DAT_0041f008 == 9) {
          pCVar5 = (CString *)FUN_00412260(0);
          ExceptionList = local_14;
          return pCVar5;
        }
        _DAT_00418578 = _DAT_00418578 + _DAT_00415b40;
        if (_DAT_00415b38 < _DAT_00418578) {
          _DAT_00418578 = 5.0;
        }
        dVar2 = (double)CONCAT44(DAT_00418568,DAT_0041ee7c);
        goto LAB_0040a185;
      }
      break;
    case (CString *)0x21:
      pCVar5 = _DAT_0041f004;
      if (_DAT_0041f004 == (CString *)0x0) {
        if (DAT_0041f008 == 9) {
          pCVar5 = (CString *)FUN_00412260(1);
          ExceptionList = local_14;
          return pCVar5;
        }
        puVar4 = &DAT_0041ebec;
        _DAT_0041f004 = (CString *)0x1;
        do {
          *puVar4 = 1;
          puVar4 = puVar4 + 7;
        } while ((int)puVar4 < 0x41ee00);
        FUN_00406dc0((LPCSTR)param_1);
        pCVar5 = (CString *)
                 CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_004048c0,
                              (LPVOID)0x0,0,&local_80);
        ExceptionList = local_14;
        return pCVar5;
      }
      break;
    case (CString *)0x22:
      pCVar5 = _DAT_0041f004;
      if (_DAT_0041f004 == (CString *)0x0) {
        if (DAT_0041f008 == 9) {
          pCVar5 = (CString *)FUN_00412260(2);
          ExceptionList = local_14;
          return pCVar5;
        }
        puVar4 = &DAT_0041ebec;
        _DAT_0041f004 = (CString *)0x1;
        do {
          *puVar4 = 1;
          puVar4 = puVar4 + 7;
        } while ((int)puVar4 < 0x41ee00);
        FUN_00406dc0((LPCSTR)param_1);
        pCVar5 = (CString *)
                 CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_004048d0,
                              (LPVOID)0x0,0,&local_80);
        ExceptionList = local_14;
        return pCVar5;
      }
      break;
    case (CString *)0x28:
    case (CString *)0x29:
    case (CString *)0x2a:
    case (CString *)0x2b:
    case (CString *)0x2c:
    case (CString *)0x2d:
    case (CString *)0x2e:
    case (CString *)0x2f:
    case (CString *)0x30:
    case (CString *)0x31:
      if (DAT_0041eff8 != (CString *)0x1) {
        if (DAT_00418544 == 0x15) {
          pCVar5 = (CString *)FUN_0040d590(*(DWORD *)((int)DAT_00418550 * 0x38 + 0x41d5f4));
          ExceptionList = local_14;
          return pCVar5;
        }
        if (DAT_00418544 == 0x16) {
          if (DAT_0041eff8 == (CString *)0x0) {
            FUN_0040a610(param_1,0,unaff_EDI);
            DAT_0041eff8 = (CString *)0x1;
            pCVar5 = (CString *)
                     CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_00404930
                                  ,*(LPVOID *)((int)DAT_00418550 * 0x38 + 0x41d5f4),0,&local_7c);
            ExceptionList = local_14;
            return pCVar5;
          }
        }
        else {
          if (DAT_00418544 == 0x17) {
            pCVar5 = (CString *)FUN_0040eff0(param_1,*(int *)((int)DAT_00418550 * 0x38 + 0x41d5f4));
            ExceptionList = local_14;
            return pCVar5;
          }
          if (DAT_00418544 == 0x18) {
            FUN_0040a610(param_1,0,unaff_EDI);
            pCVar5 = (CString *)FUN_0040f570(*(DWORD *)((int)DAT_00418550 * 0x38 + 0x41d5f4));
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return pCVar5;
}



/* ==== FUN_0040a440 @ 0040a440 ==== */

int * FUN_0040a440(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  DAT_0041854c = 0xfffffffe;
  iVar2 = 0;
  piVar1 = &DAT_0041d608;
  while ((((piVar1[-6] == 1 || (param_1 <= *piVar1)) || (*piVar1 + 4 + piVar1[6] <= param_1)) ||
         ((param_2 <= piVar1[1] || (piVar1[1] + 4 + piVar1[7] <= param_2))))) {
    piVar1 = piVar1 + 0xe;
    iVar2 = iVar2 + 1;
    if (0x41e0f7 < (int)piVar1) {
      return piVar1;
    }
  }
  DAT_0041854c = iVar2;
  return (int *)0x0;
}



/* ==== FUN_0040a510 @ 0040a510 ==== */

void __thiscall FUN_0040a510(void *this,int param_1)

{
  HDC pHVar1;
  CDC *pCVar2;
  undefined4 *puVar3;
  tagSIZE tStack_18;
  CDC aCStack_10 [16];
  
  DAT_00418548 = param_1;
  pHVar1 = GetDC(*(HWND *)((int)this + 0x20));
  pCVar2 = CDC::FromHandle(pHVar1);
  CDC::CDC(aCStack_10);
  pHVar1 = CreateCompatibleDC((HDC)0x0);
  SelectObject(pHVar1,DAT_0041f048);
  puVar3 = &DAT_0041d5fc;
  do {
    if (param_1 == -1) {
      if ((puVar3[6] != -1) && (puVar3[-3] == 0)) {
        puVar3[-3] = 1;
        SelectObject(pHVar1,(HGDIOBJ)(&DAT_0041d130)[puVar3[5]]);
        GetTextExtentPointA(pHVar1,(LPCSTR)*puVar3,*(int *)((LPCSTR)*puVar3 + -8),&tStack_18);
        BitBlt(*(HDC *)(pCVar2 + 4),puVar3[3],puVar3[4],tStack_18.cx + 5,tStack_18.cy + 5,pHVar1,
               puVar3[3],puVar3[4],0xcc0020);
      }
    }
    else if (puVar3[6] == param_1) {
      puVar3[-3] = 0;
    }
    puVar3 = puVar3 + 0xe;
  } while ((int)puVar3 < 0x41e0ec);
  DeleteDC(pHVar1);
  ReleaseDC(*(HWND *)((int)this + 0x20),*(HDC *)(pCVar2 + 4));
  CDC::~CDC(aCStack_10);
  return;
}



/* ==== FUN_0040a610 @ 0040a610 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040a610(void *this,int param_1,undefined4 param_2)

{
  CWnd *this_00;
  undefined4 *puVar1;
  HDC pHVar2;
  CDC *pCVar3;
  WPARAM wParam;
  LRESULT LVar4;
  CString *pCVar5;
  CString *this_01;
  CString *this_02;
  CString *this_03;
  CString *this_04;
  int iVar6;
  int *piVar7;
  uint uVar8;
  char *pcVar9;
  CString aCStack_34 [4];
  CString aCStack_30 [4];
  CDC *pCStack_2c;
  CString aCStack_28 [4];
  tagSIZE tStack_24;
  CDC aCStack_1c [4];
  CDC aCStack_18 [12];
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004145e0;
  local_c = ExceptionList;
  if (DAT_0041f008 == param_1) {
    return 0;
  }
  puVar1 = &DAT_0041ebec;
  ExceptionList = &local_c;
  do {
    *puVar1 = 1;
    puVar1 = puVar1 + 7;
  } while ((int)puVar1 < 0x41ee00);
  if (param_1 == 0) {
    DAT_0041efdc = 1;
  }
  DAT_0041efd4 = 1;
  _DAT_0041d740 = 1;
  CString::operator=((CString *)&DAT_0041dc8c,s_Pwr__10_00418880);
  CString::operator=((CString *)&DAT_0041dcc4,s_Pwr__10_00418874);
  _DAT_0041dc80 = 1;
  _DAT_0041dcb8 = 1;
  _DAT_0041dcf0 = 1;
  _DAT_0041dd28 = 1;
  _DAT_0041dd60 = 1;
  CString::operator=((CString *)&DAT_0041d74c,s_Start_Test_0041921c);
  if (param_1 == 9) {
    CString::operator=((CString *)&DAT_0041d74c,s_Test_EEPROM_0041920c);
    CString::operator=((CString *)&DAT_0041dc8c,s_DPI__100_00419200);
    CString::operator=((CString *)&DAT_0041dcc4,s_DPI__100_004191f4);
    CString::operator=((CString *)&DAT_0041dcfc,s_Mode_1_004191e8);
    CString::operator=((CString *)&DAT_0041dd34,s_Mode_2_004191dc);
    pcVar9 = s_Mode_3_004191d0;
  }
  else if (param_1 == 10) {
    CString::operator=((CString *)&DAT_0041d74c,s_Set_Bar_Code_004191c0);
    CString::operator=((CString *)&DAT_0041dc8c,s_Power___004191b4);
    CString::operator=((CString *)&DAT_0041dcc4,s_Power___004191a8);
    CString::operator=((CString *)&DAT_0041dcfc,s_Mode_1_004191e8);
    CString::operator=((CString *)&DAT_0041dd34,s_Mode_2_004191dc);
    pcVar9 = s_Mode_3_004191d0;
  }
  else {
    CString::operator=((CString *)&DAT_0041dc8c,s_Pwr__10_00418880);
    CString::operator=((CString *)&DAT_0041dcc4,s_Pwr__10_00418874);
    CString::operator=((CString *)&DAT_0041dcfc,s_Range_0041886c);
    CString::operator=((CString *)&DAT_0041dd34,s_Calibrate_00418860);
    pcVar9 = s_Default_Mode_00418850;
  }
  CString::operator=((CString *)&DAT_0041dd6c,pcVar9);
  FUN_00406dc0((LPCSTR)this);
  pHVar2 = GetDC(*(HWND *)((int)this + 0x20));
  pCVar3 = CDC::FromHandle(pHVar2);
  pCStack_2c = pCVar3;
  CDC::CDC(aCStack_1c);
  uStack_4 = 0;
  pHVar2 = CreateCompatibleDC((HDC)0x0);
  SelectObject(pHVar2,DAT_0041f048);
  puVar1 = &DAT_0041ee18;
  do {
    CWnd::ShowWindow((CWnd *)*puVar1,0);
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x41ee6c);
  this_00 = (CWnd *)((int)this + 0xa0);
  CWnd::ShowWindow(this_00,0);
  SelectObject(pHVar2,(HGDIOBJ)(&DAT_0041d130)[DAT_0041d760]);
  GetTextExtentPointA(pHVar2,DAT_0041d74c,*(int *)(DAT_0041d74c + -8),&tStack_24);
  BitBlt(*(HDC *)(pCVar3 + 4),DAT_0041d758,DAT_0041d75c,tStack_24.cx + 5,tStack_24.cy + 5,pHVar2,
         DAT_0041d758,DAT_0041d75c,0xcc0020);
  puVar1 = &DAT_0041dc8c;
  do {
    SelectObject(pHVar2,(HGDIOBJ)(&DAT_0041d130)[puVar1[5]]);
    GetTextExtentPointA(pHVar2,(LPCSTR)*puVar1,*(int *)((LPCSTR)*puVar1 + -8),(LPSIZE)(puVar1 + 9));
    puVar1 = puVar1 + 0xe;
  } while ((int)puVar1 < 0x41debc);
  DeleteDC(pHVar2);
  ReleaseDC(*(HWND *)((int)this + 0x20),*(HDC *)(pCStack_2c + 4));
  DAT_0041ebe8 = 2;
  DAT_0041ebd0 = 0;
  DAT_0041ebe0 = 5;
  DAT_0041ebe4 = 0x78;
  _DAT_0041d740 = 0;
  if ((DAT_0041f078 != 0) && (((0 < param_1 && (param_1 < 5)) || (param_1 == 0xb)))) {
    _DAT_0041dc80 = 0;
    _DAT_0041dcb8 = 0;
    _DAT_0041dcf0 = 0;
    _DAT_0041dd28 = 0;
  }
  if ((0 < param_1) && (param_1 < 5)) {
    _DAT_0041dd60 = 0;
  }
  _DAT_0041dc98 = DAT_0041d770 + 0x32 + DAT_0041d758;
  _DAT_0041dc9c = DAT_0041d75c;
  _DAT_0041dcd4 = DAT_0041d75c;
  _DAT_0041dd0c = DAT_0041d75c;
  _DAT_0041dd44 = DAT_0041d75c;
  _DAT_0041dd7c = DAT_0041d75c;
  _DAT_0041dcd0 = DAT_0041dcb0 + 10 + _DAT_0041dc98;
  _DAT_0041dd08 = DAT_0041dce8 + 10 + _DAT_0041dcd0;
  _DAT_0041dd40 = DAT_0041dd20 + 10 + _DAT_0041dd08;
  if (param_1 == 9) {
    _DAT_0041dd78 = DAT_0041dd58 + 10;
  }
  else {
    _DAT_0041dd78 = DAT_0041dd58 + 0x1e;
  }
  _DAT_0041dd78 = _DAT_0041dd78 + _DAT_0041dd40;
  CString::CString(aCStack_34);
  uStack_4._0_1_ = 1;
  CString::CString(aCStack_30);
  uStack_4 = CONCAT31(uStack_4._1_3_,2);
  CString::Format(aCStack_34,(char *)aCStack_34);
  switch(param_2) {
  case 0:
    goto LAB_0040aee5;
  case 1:
    wParam = SendMessageA(*(HWND *)((int)this + 0xc0),0x147,0,0);
    DAT_0041efc8 = SendMessageA(*(HWND *)((int)this + 0xc0),0x150,wParam,0);
    LVar4 = SendMessageA(*(HWND *)((int)this + 0xc0),0x147,0,0);
    CComboBox::GetLBText((CComboBox *)this_00,LVar4,aCStack_28);
    pCVar5 = (CString *)operator+(&tStack_24.cy,s_Gaming_Test_Mode___00419170);
    CString::operator=((CString *)&DAT_0041ebd8,pCVar5);
    CString::~CString((CString *)&tStack_24);
    DAT_0041effc = 1;
    CString::operator=((CString *)&DAT_0041ee7c,&DAT_00419130);
    CWnd::ShowWindow(this_00,1);
    CWnd::EnableWindow(this_00,0);
    if (DAT_0041f078 != 0) {
      CString::operator+=((CString *)&DAT_0041ebd8,aCStack_30);
    }
    break;
  case 2:
    CString::operator=((CString *)&DAT_0041ebd8,s_Gaming_Test_Mode___1000_report_r_0041910c);
    CString::operator=((CString *)&DAT_0041ee7c,&DAT_004190c4);
    if (DAT_0041f078 != 0) {
      CString::operator+=((CString *)&DAT_0041ebd8,aCStack_30);
    }
    break;
  case 3:
    CString::operator=((CString *)&DAT_0041ebd8,s_Gaming_Test_Mode___MSI_004190ac);
    pcVar9 = &DAT_00419070;
    goto LAB_0040ae81;
  case 4:
    CString::operator=((CString *)&DAT_0041ebd8,s_Gaming_Test_Mode___TRUST_00419054);
    CString::operator=((CString *)&DAT_0041ee7c,&DAT_00419014);
    if (DAT_0041f078 != 0) {
      CString::operator+=((CString *)&DAT_0041ebd8,aCStack_30);
    }
    break;
  case 5:
    CString::operator=((CString *)&DAT_0041ebd8,s_RF_Test_Mode___2_4GHz_00418ffc);
    uVar8 = 1;
    iVar6 = 0;
    piVar7 = &DAT_0041ee18;
    do {
      CWnd::SetWindowPos((CWnd *)*piVar7,(CWnd *)0x0,DAT_0041d770 + 0x46 + iVar6,0x66,0,0,5);
      CWnd::ShowWindow((CWnd *)*piVar7,1);
      SendMessageA(*(HWND *)(*piVar7 + 0x20),0xf1,_DAT_00418538 & uVar8,0);
      piVar7 = piVar7 + 1;
      iVar6 = iVar6 + 0x3c;
      uVar8 = uVar8 << 1;
    } while ((int)piVar7 < 0x41ee38);
    break;
  case 6:
    CString::operator=((CString *)&DAT_0041ebd8,s_P01_Test_Mode___Portuguese_00418fe0);
    _DAT_0041d740 = 1;
    break;
  case 7:
    CString::operator=((CString *)&DAT_0041ebd8,s_DPI_Test_Mode_00418fd0);
    _DAT_0041d740 = 1;
    _DAT_0041dc80 = 1;
    _DAT_0041dcb8 = 1;
    _DAT_0041ec04 = 4;
    _DAT_0041ebf8 = 0xffff;
    DAT_0041ebec = DAT_0041efb4;
    _DAT_0041ebfc = 5;
    _DAT_0041ec00 = 0xbe;
    CString::operator=((CString *)&DAT_0041ebf4,s_Press__L__to_lock___release_the_c_00418fa8);
    _DAT_0041ec20 = 3;
    _DAT_0041ec14 = 0xffff;
    DAT_0041ec08 = 0;
    _DAT_0041ec18 = 5;
    _DAT_0041ec1c = 0xf0;
    CString::Format(this_01,&DAT_0041ec10);
    break;
  default:
LAB_0040aee5:
    DAT_0041ebd0 = 1;
    _DAT_0041d740 = 1;
    _DAT_0041dc80 = 1;
    _DAT_0041dcb8 = 1;
    break;
  case 9:
    FUN_00411050(0);
    CString::operator=((CString *)&DAT_0041ebd8,s_Gaming_Test_Mode_QE____DPI_400_00418f64);
    CString::operator=((CString *)&DAT_0041ee7c,s_Gaming_Test_Mode_QE____DPI___4d_00418f40);
    DAT_0041ebec = DAT_0041efb4;
    _DAT_0041d740 = 0;
    _DAT_0041ec04 = 4;
    _DAT_0041ebf8 = 0xffff;
    _DAT_0041ebfc = 5;
    _DAT_0041ec00 = 0xbe;
    CString::operator=((CString *)&DAT_0041ebf4,s_Press__L__to_lock___release_the_c_00418fa8);
    _DAT_0041ec20 = 3;
    _DAT_0041ec14 = 0xffff;
    DAT_0041ec08 = 0;
    _DAT_0041ec18 = 5;
    _DAT_0041ec1c = 0xf0;
    CString::Format(this_02,&DAT_0041ec10);
    CString::operator=((CString *)&DAT_0041dc8c,s_DPI__100_00419200);
    CString::operator=((CString *)&DAT_0041dcc4,s_DPI__100_004191f4);
    _DAT_0041dc80 = 0;
    _DAT_0041dcb8 = 0;
    CString::operator=((CString *)&DAT_0041dcfc,s_Mode_1_004191e8);
    CString::operator=((CString *)&DAT_0041dd34,s_Mode_2_004191dc);
    CString::operator=((CString *)&DAT_0041dd6c,s_Mode_3_004191d0);
    _DAT_0041dcf0 = 0;
    _DAT_0041dd28 = 0;
    _DAT_0041dd60 = 0;
    break;
  case 10:
    FUN_00411050(0);
    CString::Format(this_03,&DAT_0041ebd8);
    CString::operator=((CString *)&DAT_0041ee7c,s_Misc_Mode__bar_code_____20s_00418f04);
    _DAT_0041d740 = 0;
    _DAT_0041dc80 = 0;
    _DAT_0041dcb8 = 0;
    _DAT_0041ec04 = 2;
    DAT_0041ebec = 0;
    _DAT_0041ebf0 = 0xffff;
    _DAT_0041ebfc = 0x78;
    _DAT_0041ec00 = 0x140;
    CString::Format(this_04,&DAT_0041ebf4);
    break;
  case 0xb:
    CString::operator=((CString *)&DAT_0041ebd8,s_Gaming_3_Test_Mode_00418ef0);
    pcVar9 = &DAT_00418eb8;
LAB_0040ae81:
    CString::operator=((CString *)&DAT_0041ee7c,pcVar9);
    if (DAT_0041f078 != 0) {
      CString::operator+=((CString *)&DAT_0041ebd8,aCStack_30);
    }
    break;
  case 0xc:
    CString::operator=((CString *)&DAT_0041ebd8,s_FD8_Pro_KN_00418eac);
    if (DAT_0041f078 != 0) {
      CString::operator+=((CString *)&DAT_0041ebd8,aCStack_30);
    }
    _DAT_0041d740 = 1;
  }
  DAT_0041f008 = param_2;
  DAT_0041effc = 1;
  CString::~CString((CString *)&pCStack_2c);
  CString::~CString(aCStack_30);
  CDC::~CDC(aCStack_18);
  ExceptionList = puStack_8;
  return param_2;
}



/* ==== FUN_0040afe0 @ 0040afe0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040afe0(void *param_1)

{
  undefined4 *puVar1;
  DWORD local_14 [4];
  int local_4;
  
  if (_DAT_0041f004 != 0) {
    CString::operator=((CString *)&DAT_0041d74c,s_Start_Test_0041921c);
    _DAT_0041f004 = _DAT_0041f004 | 0x80;
    return;
  }
  local_14[3] = DAT_0041a220 + -10;
  local_4 = DAT_0041a224 + -0xa0;
  local_14[1] = 10;
  local_14[2] = 0xa0;
  puVar1 = &DAT_0041ebec;
  do {
    *puVar1 = 1;
    puVar1 = puVar1 + 7;
  } while ((int)puVar1 < 0x41ee00);
  FUN_004094b0(param_1,(int *)(local_14 + 1));
  CString::operator=((CString *)&DAT_0041d74c,s_Stop_Test_0041922c);
  _DAT_0041f004 = 1;
  CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_004048a0,param_1,0,local_14
              );
  return;
}



/* ==== FUN_0040b0a0 @ 0040b0a0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b0a0(void)

{
  if (DAT_0041f008 < 1 || 4 < DAT_0041f008) {
    if (DAT_0041f008 == 5) {
      FUN_0040d790();
    }
    else if (DAT_0041f008 == 0xb) {
      FUN_00412cf0();
    }
  }
  else {
    FUN_0040b100();
  }
  _DAT_0041f004 = 0;
  CString::operator=((CString *)&DAT_0041d74c,s_Start_Test_0041921c);
  return;
}



/* ==== FUN_0040b100 @ 0040b100 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b100(void)

{
  char *pcVar1;
  CString *pCVar2;
  int iVar3;
  CString *this;
  CString *this_00;
  CString *extraout_ECX;
  CString *extraout_ECX_00;
  int iVar4;
  DWORD DVar5;
  undefined4 *puVar6;
  DWORD DVar7;
  wchar_t *pwVar8;
  int iStack_bc;
  CString CStack_b8;
  undefined uStack_b7;
  undefined uStack_b6;
  undefined uStack_b5;
  undefined uStack_b4;
  undefined uStack_b3;
  undefined uStack_b2;
  undefined uStack_b1;
  CString local_b0;
  undefined uStack_af;
  undefined uStack_ae;
  undefined uStack_ad;
  uint local_ac;
  int local_a8;
  undefined4 uStack_a4;
  int *local_a0;
  int local_9c;
  int local_94;
  CString local_90 [4];
  CString local_8c [4];
  CString local_88 [4];
  CString local_84 [4];
  CString local_80 [4];
  CString local_7c [4];
  CString local_78;
  undefined4 local_77;
  undefined uStack_73;
  undefined uStack_72;
  undefined uStack_71;
  undefined uStack_70;
  undefined uStack_6f;
  CString CStack_6e;
  CString CStack_6d;
  undefined uStack_6c;
  void *local_14;
  undefined *puStack_10;
  undefined4 local_c;
  int iStack_8;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00414647;
  local_14 = ExceptionList;
  local_78 = (CString)0x0;
  puVar6 = &local_77;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  iVar4 = 0;
  DVar5 = 0;
  local_ac = 0;
  *(undefined *)((int)puVar6 + 2) = 0;
  ExceptionList = &local_14;
  CString::CString(local_90,s_PixArt_3601_00418e30);
  local_c = 0;
  CString::CString(local_8c,s_Avago_3080_00418e24);
  local_c._0_1_ = 1;
  CString::CString(local_88,s_Avago_6010_00418e18);
  local_c._0_1_ = 2;
  CString::CString(local_84,s_Avago_7010_00418e0c);
  local_c._0_1_ = 3;
  CString::CString(local_80,s_Avago_6090_00418e00);
  local_c._0_1_ = 4;
  CString::CString(local_7c,s_Philips_PLN2030_00418df0);
  local_c._0_1_ = 5;
  CString::CString(&local_b0);
  local_c._0_1_ = 6;
  CString::CString((CString *)&local_94);
  local_c._0_1_ = 7;
  CString::CString((CString *)&local_a8,(ushort *)u__d__Model___s___Ver___d__d___Sen_00419544);
  local_c = CONCAT31(local_c._1_3_,8);
  DVar7 = 0;
  iVar3 = FUN_004026e0(0x41d180);
  if (0 < iVar3) {
    local_a0 = &DAT_0041d598;
    do {
      if (*local_a0 == 2) {
        iVar4 = iVar4 + 1;
        DVar5 = DVar7;
      }
      local_a0 = local_a0 + 1;
      DVar7 = DVar7 + 1;
      iVar3 = FUN_004026e0(0x41d180);
    } while ((int)DVar7 < iVar3);
  }
  _DAT_0041ebfc = 10;
  _DAT_0041ec00 = 0xa0;
  _DAT_0041ec04 = 4;
  DAT_0041effc = 1;
  DAT_0041ebec = 0;
  if (1 < iVar4) {
    CString::operator=((CString *)&DAT_0041ebf4,s_error___found_more_than_two_gami_00419514);
    _DAT_0041ebf8 = 0xff;
    goto LAB_0040ba42;
  }
  if (iVar4 == 0) {
    CString::operator=((CString *)&DAT_0041ebf4,s_error___didn_t_find_any_gaming_d_004194e8);
    _DAT_0041ebf8 = 0xff;
    goto LAB_0040ba42;
  }
  iVar3 = (&DAT_0041d548)[DVar5];
  _DAT_0041ebf8 = 0xffff;
  CString::operator=((CString *)&local_a8,(ushort *)u_Model___s___Ver___d__d___Sensor__00419480);
  iVar4 = FUN_004015f0(&DAT_0041d180,DVar5);
  if (iVar4 == 0xe) {
    pwVar8 = u_B115G_00418d28;
LAB_0040b345:
    CString::operator=(&local_b0,(ushort *)pwVar8);
  }
  else {
    iVar4 = FUN_004015f0(&DAT_0041d180,DVar5);
    if (iVar4 == 0xf) {
      pwVar8 = u_B189G___Sonix_00418d0c;
      goto LAB_0040b345;
    }
    iVar4 = FUN_004015f0(&DAT_0041d180,DVar5);
    if (iVar4 == 0x10) {
      pwVar8 = u_L189G_00418d00;
      goto LAB_0040b345;
    }
    iVar4 = FUN_004015f0(&DAT_0041d180,DVar5);
    if (iVar4 != 0x11) {
      pwVar8 = u_Unknow_00418cd8;
      goto LAB_0040b345;
    }
    CString::operator=(&local_b0,(ushort *)u_LFD1_00418cf4);
    if (DAT_0041f008 == 3) {
      pwVar8 = u_L191G_00418ce8;
      goto LAB_0040b345;
    }
  }
  iVar4 = FUN_00401200(&DAT_0041d180,DVar5);
  if (iVar4 == 1) {
    CString::operator=(&local_b0,(ushort *)u_Innovation_FD1_00419460);
  }
  pCVar2 = FUN_00401610(&DAT_0041d180,(CString *)&local_a0,DVar5);
  iVar4 = _mbscmp(*(uchar **)pCVar2,&DAT_00418080);
  uStack_a4 = (CString *)CONCAT13(iVar4 == 0,(undefined3)uStack_a4);
  CString::~CString((CString *)&local_a0);
  if (uStack_a4._3_1_ != '\0') {
    CString::operator=(&local_b0,(ushort *)u_LFD5_00418ccc);
  }
  if (5 < iVar3) {
    iVar3 = 5;
  }
  pcVar1 = (char *)CONCAT13(uStack_ad,CONCAT12(uStack_ae,CONCAT11(uStack_af,local_b0)));
  if (((0 < *(int *)(pcVar1 + -8)) && (*pcVar1 == 'L')) && (iVar3 == 1)) {
    CString::SetAt(&local_b0,0,'B');
  }
  FUN_00401600(&DAT_0041d180,DVar5);
  FUN_00401200(&DAT_0041d180,DVar5);
  CString::Format(this,&DAT_0041ebf4);
  CString::operator=((CString *)&uStack_a4,(ushort *)u_Testing_External_EEPROM__0_2f___00419418);
  _DAT_0041ec18 = 10;
  _DAT_0041ec1c = 0xbe;
  _DAT_0041ec20 = 4;
  DAT_0041ec08 = 0;
  _DAT_0041ec14 = 0xffff;
  iVar3 = FUN_00401200(&DAT_0041d180,DVar5);
  if (iVar3 == 0) {
    iVar3 = 0;
    do {
      if ((DAT_0041f004 & 0x80) != 0) break;
      CString::Format(uStack_a4,&DAT_0041ec10);
      DAT_0041effc = 1;
      FUN_00401210(&DAT_0041d180,DVar5,iVar3,0xf);
      Sleep(1);
      FUN_00401310(&DAT_0041d180,DVar5,iVar3,&uStack_70);
      if (CStack_6e != (CString)0xf) {
        uStack_a4 = uStack_a4 + 1;
        iVar3 = iVar3 + -0x100;
        CStack_b8 = (CString)0x0;
        uStack_b7 = (undefined)((uint)iVar3 >> 8);
        uStack_b6 = (undefined)((uint)iVar3 >> 0x10);
        uStack_b5 = (undefined)((uint)iVar3 >> 0x18);
      }
      if (8 < (int)uStack_a4) goto LAB_0040b517;
      Sleep(1);
      iVar3 = iVar3 + 0x100;
      CStack_b8 = (CString)0x0;
      uStack_b7 = (undefined)((uint)iVar3 >> 8);
      uStack_b6 = (undefined)((uint)iVar3 >> 0x10);
      uStack_b5 = (undefined)((uint)iVar3 >> 0x18);
    } while (iVar3 < 0x2000);
    if ((local_a8 < 9) && (0x1fff < iVar3)) goto LAB_0040b52a;
LAB_0040b517:
    iVar3 = FUN_00401200(&DAT_0041d180,DVar5);
    if (iVar3 == 0) goto LAB_0040b52a;
    CString::Format(this_00,&DAT_0041ec10);
    _DAT_0041ec14 = 0xff;
    CString::operator=((CString *)&DAT_0041ec2c,(ushort *)u_Stop_Test___Fail_0041923c);
    DAT_0041ec30 = 0xff;
  }
  else {
LAB_0040b52a:
    iVar3 = FUN_00401200(&DAT_0041d180,DVar5);
    if (iVar3 == 0) {
      pwVar8 = u_Testing_External_EEPROM_100_00____004193c8;
    }
    else {
      pwVar8 = u_Testing_External_EEPROM_100_00____00419350;
    }
    CString::operator=((CString *)&DAT_0041ec10,(ushort *)pwVar8);
    _DAT_0041ec14 = 0xff00;
    DAT_0041effc = 1;
    iStack_bc = 0;
    local_94 = 0;
    iVar3 = FUN_00401600(&DAT_0041d180,DVar5);
    if (iVar3 < 0x29) {
LAB_0040b749:
      iVar3 = iStack_bc * 0x1c;
      CString::operator=((CString *)(&DAT_0041ec2c + iVar3),
                         (ushort *)u_Writing_Mouse_Setting____00419278);
      (&DAT_0041ec30)[iStack_bc * 7] = 0xffff;
      *(undefined4 *)(&DAT_0041ec3c + iVar3) = 4;
      *(undefined4 *)(&DAT_0041ec24 + iVar3) = 0;
      *(undefined4 *)(&DAT_0041ec34 + iVar3) = 10;
      DAT_0041effc = 1;
      *(int *)(&DAT_0041ec38 + iVar3) = iStack_bc * 0x1e + 0xdc;
      iVar3 = FUN_004015f0(&DAT_0041d180,DVar5);
      if (0xf < iVar3) {
        FUN_0040cfa0(DVar5);
        iVar3 = FUN_00401200(&DAT_0041d180,DVar5);
        if (iVar3 == 0) {
          FUN_0040cb70(DVar5);
        }
      }
      if (DAT_0041f008 == 1) {
        uStack_71 = (undefined)DAT_0041efc8;
        local_77._3_1_ = 2;
        uStack_73 = 0x97;
        uStack_72 = 0x7e;
        uStack_70 = 0;
        FUN_004026f0(&DAT_0041d180,DVar5,(LPCVOID)((int)&local_77 + 3),(LPVOID)((int)&local_77 + 3),
                     8);
        Sleep(10);
        CStack_b8 = (CString)0x2;
        uStack_b7 = 0x9a;
        uStack_b6 = 3;
        uStack_b5 = 0;
        uStack_b4 = 0x7e;
        uStack_b3 = 0;
        uStack_b2 = 0;
        uStack_b1 = 0;
        local_b0 = (CString)0x0;
        uStack_af = 0;
        FUN_004026f0(&DAT_0041d180,DVar5,&CStack_b8,&CStack_b8,8);
        Sleep(10);
        if ((CONCAT12(uStack_b4,CONCAT11(uStack_b5,uStack_b6)) & 0xff) != DAT_0041efc8) {
          do {
            uStack_71 = (undefined)DAT_0041efc8;
            local_77._3_1_ = 2;
            uStack_73 = 0x97;
            uStack_72 = 0x7e;
            uStack_70 = 0;
            FUN_004026f0(&DAT_0041d180,DVar5,(LPCVOID)((int)&local_77 + 3),
                         (LPVOID)((int)&local_77 + 3),8);
            Sleep(10);
            CStack_b8 = (CString)0x2;
            uStack_b7 = 0x9a;
            uStack_b6 = 3;
            uStack_b5 = 0;
            uStack_b4 = 0x7e;
            uStack_b3 = 0;
            uStack_b2 = 0;
            uStack_b1 = 0;
            local_b0 = (CString)0x0;
            uStack_af = 0;
            FUN_004026f0(&DAT_0041d180,DVar5,&CStack_b8,&CStack_b8,8);
            Sleep(10);
          } while ((CONCAT12(uStack_b4,CONCAT11(uStack_b5,uStack_b6)) & 0xff) != DAT_0041efc8);
        }
      }
      iVar3 = FUN_00401200(&DAT_0041d180,DVar5);
      if (iVar3 == 0) {
        if ((DAT_0041f008 == 1) || (DAT_0041f008 == 2)) {
          FUN_0040c450(DVar5);
        }
        else if (DAT_0041f008 == 3) {
          FUN_0040bb00(DVar5);
        }
        else if (DAT_0041f008 == 4) {
          FUN_0040bb10(DVar5);
        }
      }
      (&DAT_0041ec30)[iStack_bc * 7] = 0xff00;
      DAT_0041effc = 1;
    }
    else {
      CString::operator=((CString *)&uStack_a4,(ushort *)u_Testing_Internal_EEPROM__0_2f___00419308)
      ;
      _DAT_0041ec34 = 10;
      _DAT_0041ec38 = 0xdc;
      _DAT_0041ec3c = 4;
      _DAT_0041ec24 = 0;
      DAT_0041ec30 = 0xffff;
      Sleep(10);
      iStack_bc = 0x80;
      local_9c = 0;
      pCVar2 = extraout_ECX;
      do {
        iVar3 = local_9c;
        if ((DAT_0041f004 & 0x80) != 0) break;
        CString::Format(pCVar2,&DAT_0041ec2c);
        DAT_0041effc = 1;
        uStack_70 = 2;
        uStack_6f = 0x97;
        CStack_6e = CStack_b8;
        CStack_6d = CStack_b8;
        uStack_6c = 0;
        FUN_004026f0(&DAT_0041d180,DVar5,&uStack_70,&uStack_70,8);
        Sleep(10);
        uStack_b4 = 2;
        uStack_b3 = 0x9a;
        uStack_b2 = 3;
        uStack_b1 = 0;
        local_b0 = CStack_b8;
        uStack_af = 0;
        uStack_ae = 0;
        uStack_ad = 0;
        local_ac = local_ac & 0xffff0000;
        FUN_004026f0(&DAT_0041d180,DVar5,&uStack_b4,&uStack_b4,8);
        pCVar2 = (CString *)(CONCAT12(local_b0,CONCAT11(uStack_b1,uStack_b2)) & 0xff);
        if (pCVar2 != (CString *)(CONCAT12(uStack_b6,CONCAT11(uStack_b7,CStack_b8)) & 0xff)) {
          uStack_a4 = uStack_a4 + 1;
          CString::Format(pCVar2,(char *)local_8c);
          iVar4 = CONCAT13(uStack_b1,CONCAT12(uStack_b2,CONCAT11(uStack_b3,uStack_b4))) + -0x40;
          iVar3 = iVar3 + -0x40;
          uStack_b4 = (undefined)iVar4;
          uStack_b3 = (undefined)((uint)iVar4 >> 8);
          uStack_b2 = (undefined)((uint)iVar4 >> 0x10);
          uStack_b1 = (undefined)((uint)iVar4 >> 0x18);
        }
        if (3 < local_a8) break;
        Sleep(1);
        local_9c = iVar3 + 0x40;
        iStack_bc = iStack_bc + 0x40;
        pCVar2 = extraout_ECX_00;
      } while (local_9c < 0x80);
      if ((local_a8 < 9) && (0xff < iStack_bc)) {
        CString::operator=((CString *)&DAT_0041ec2c,
                           (ushort *)u_Testing_Internal_EEPROM_100_00____004192ac);
        DAT_0041ec30 = 0xff00;
      }
      else {
        DAT_0041ec30 = 0xff;
        local_94 = 1;
      }
      iStack_bc = 1;
      if (local_94 == 0) goto LAB_0040b749;
      iStack_bc = 0;
    }
    (&DAT_0041ec50)[iStack_bc * 7] = 10;
    (&DAT_0041ec54)[iStack_bc * 7] = iStack_bc * 0x1e + 0xfa;
    (&DAT_0041ec58)[iStack_bc * 7] = 4;
    (&DAT_0041ec40)[iStack_bc * 7] = 0;
    (&DAT_0041ec4c)[iStack_bc * 7] = 0xff00;
    if (local_94 == 1) {
      (&DAT_0041ec4c)[iStack_bc * 7] = 0xff;
      CString::operator=((CString *)(&DAT_0041ec48 + iStack_bc * 0x1c),(ushort *)u_Fail_00419260);
    }
    else {
      CString::operator=((CString *)(&DAT_0041ec48 + iStack_bc * 0x1c),(ushort *)u_Pass_0041926c);
    }
  }
  DAT_0041effc = 1;
LAB_0040ba42:
  iStack_8._0_1_ = 7;
  CString::~CString((CString *)&uStack_a4);
  iStack_8._0_1_ = 6;
  CString::~CString(local_90);
  iStack_8._0_1_ = 5;
  CString::~CString((CString *)&local_ac);
  iStack_8._0_1_ = 4;
  CString::~CString(&local_78);
  iStack_8._0_1_ = 3;
  CString::~CString(local_7c);
  iStack_8._0_1_ = 2;
  CString::~CString(local_80);
  iStack_8._0_1_ = 1;
  CString::~CString(local_84);
  iStack_8 = (uint)iStack_8._1_3_ << 8;
  CString::~CString(local_88);
  iStack_8 = 0xffffffff;
  CString::~CString(local_8c);
  ExceptionList = puStack_10;
  return;
}



/* ==== FUN_0040bb00 @ 0040bb00 ==== */

void FUN_0040bb00(int param_1)

{
  FUN_0040c450(param_1);
  return;
}



/* ==== FUN_0040bb10 @ 0040bb10 ==== */

void FUN_0040bb10(DWORD param_1)

{
  int iVar1;
  int iVar2;
  undefined local_134;
  undefined4 local_133;
  undefined4 local_12f;
  undefined local_12b;
  undefined local_12a;
  int local_128;
  undefined local_124;
  undefined local_123;
  undefined local_122;
  undefined local_121;
  undefined local_120;
  undefined local_11f;
  undefined local_11e;
  undefined local_11d;
  undefined local_11c;
  undefined local_11b;
  undefined local_11a;
  byte *local_118;
  uint local_114;
  int local_110;
  byte local_10c [192];
  int local_4c;
  byte local_48;
  undefined3 uStack_47;
  byte local_44;
  undefined3 uStack_43;
  uint local_40;
  byte local_3c;
  undefined3 uStack_3b;
  byte local_38;
  undefined3 uStack_37;
  undefined local_34 [2];
  char local_32;
  
  local_10c[1] = 0xb4;
  local_10c[4] = 0xb4;
  local_10c[0x11] = 0xb4;
  local_10c[0x14] = 0xb4;
  local_10c[0] = 7;
  local_10c[2] = 0x25;
  local_10c[3] = 2;
  local_10c[5] = 0;
  local_10c[6] = 0;
  local_10c[7] = 0xf;
  local_10c[8] = 0;
  local_10c[9] = 0;
  local_10c[10] = 0;
  local_10c[0xb] = 0;
  local_10c[0xc] = 0;
  local_10c[0xd] = 0;
  local_10c[0xe] = 0;
  local_10c[0xf] = 0;
  local_10c[0x10] = 7;
  local_10c[0x12] = 0x24;
  local_10c[0x13] = 2;
  local_10c[0x15] = 0;
  local_10c[0x16] = 0;
  local_10c[0x17] = 0xf;
  local_10c[0x18] = 0;
  local_10c[0x19] = 0;
  local_10c[0x1a] = 0;
  local_10c[0x1b] = 0;
  local_10c[0x1c] = 0;
  local_10c[0x1d] = 0;
  local_10c[0x1e] = 0;
  local_10c[0x1f] = 0;
  local_10c[0x20] = 0;
  local_10c[0x21] = 0x41;
  local_10c[0x22] = 0xb;
  local_10c[0x23] = 0x40;
  local_10c[0x24] = 0xb;
  local_10c[0x25] = 0xf;
  local_10c[0x26] = 1;
  local_10c[0x27] = 0xd;
  local_10c[0x28] = 10;
  local_10c[0x29] = 0;
  local_10c[0x2a] = 0;
  local_10c[0x2b] = 0;
  local_10c[0x2c] = 0;
  local_10c[0x2d] = 0;
  local_10c[0x2e] = 0;
  local_10c[0x2f] = 0;
  local_10c[0x30] = 0;
  local_10c[0x31] = 0x41;
  local_10c[0x32] = 0xc;
  local_10c[0x33] = 0x70;
  local_10c[0x34] = 0;
  local_10c[0x35] = 0x14;
  local_10c[0x36] = 0x40;
  local_10c[0x37] = 0xc;
  local_10c[0x38] = 1;
  local_10c[0x39] = 0xd;
  local_10c[0x3a] = 10;
  local_10c[0x3b] = 0;
  local_10c[0x3c] = 0;
  local_10c[0x3d] = 0;
  local_10c[0x3e] = 0;
  local_10c[0x3f] = 0;
  local_10c[0x40] = 0xb;
  local_10c[0x41] = 0x41;
  local_10c[0x42] = 0xb;
  local_10c[0x43] = 0x70;
  local_10c[0x44] = 0;
  local_10c[0x45] = 0x14;
  local_10c[0x46] = 0x40;
  local_10c[0x47] = 0xb;
  local_10c[0x48] = 0xf;
  local_10c[0x49] = 1;
  local_10c[0x4a] = 0xd;
  local_10c[0x4b] = 10;
  local_10c[0x4c] = 0;
  local_10c[0x4d] = 0;
  local_10c[0x4e] = 0;
  local_10c[0x4f] = 0;
  local_10c[0x50] = 0xb;
  local_10c[0x51] = 0x41;
  local_10c[0x52] = 0xc;
  local_10c[0x53] = 0x70;
  local_10c[0x54] = 0;
  local_10c[0x55] = 0x14;
  local_10c[0x56] = 0x40;
  local_10c[0x57] = 0xc;
  local_10c[0x58] = 0xf;
  local_10c[0x59] = 1;
  local_10c[0x5a] = 0xd;
  local_10c[0x5b] = 10;
  local_10c[0x5c] = 0;
  local_10c[0x5d] = 0;
  local_10c[0x5e] = 0;
  local_10c[0x5f] = 0;
  local_10c[0x60] = 0xb;
  local_10c[0x61] = 0x41;
  local_10c[0x62] = 0xd;
  local_10c[99] = 0x70;
  local_10c[100] = 0;
  local_10c[0x65] = 0x28;
  local_10c[0x66] = 0x40;
  local_10c[0x67] = 0xd;
  local_10c[0x68] = 0x70;
  local_10c[0x69] = 0;
  local_10c[0x6a] = 0x28;
  local_10c[0x6b] = 0xf;
  local_10c[0x6c] = 0;
  local_10c[0x6d] = 0;
  local_10c[0x6e] = 0;
  local_10c[0x6f] = 0;
  local_10c[0x70] = 0xb;
  local_10c[0x71] = 0x41;
  local_10c[0x72] = 0x18;
  local_10c[0x73] = 0x70;
  local_10c[0x74] = 0;
  local_10c[0x75] = 0x28;
  local_10c[0x76] = 0x40;
  local_10c[0x77] = 0x18;
  local_10c[0x78] = 0x70;
  local_10c[0x79] = 0;
  local_10c[0x7a] = 0x28;
  local_10c[0x7b] = 0xf;
  local_10c[0x7c] = 0;
  local_10c[0x7d] = 0;
  local_10c[0x7e] = 0;
  local_10c[0x7f] = 0;
  local_10c[0x80] = 0xb;
  local_10c[0x81] = 0x41;
  local_10c[0x82] = 0x37;
  local_10c[0x83] = 0x70;
  local_10c[0x84] = 0;
  local_10c[0x85] = 0x14;
  local_10c[0x86] = 0x40;
  local_10c[0x87] = 0x37;
  local_10c[0x88] = 0xf;
  local_10c[0x89] = 1;
  local_10c[0x8a] = 0xd;
  local_10c[0x8b] = 10;
  local_10c[0x8c] = 0;
  local_10c[0x8d] = 0;
  local_10c[0x8e] = 0;
  local_10c[0x8f] = 0;
  local_10c[0x90] = 0xb;
  local_10c[0x91] = 0x41;
  local_10c[0x92] = 0x36;
  local_10c[0x93] = 0x70;
  local_10c[0x94] = 0;
  local_10c[0x95] = 0x14;
  local_10c[0x96] = 0x40;
  local_10c[0x97] = 0x36;
  local_10c[0x98] = 0xf;
  local_10c[0xa0] = 0xb;
  local_10c[0xb0] = 0xb;
  local_10c[0xb2] = 0x30;
  local_10c[0xb7] = 0x30;
  local_10c[0xa3] = 0x70;
  local_10c[0xb3] = 0x70;
  local_10c[0x99] = 1;
  local_10c[0x9a] = 0xd;
  local_10c[0x9b] = 10;
  local_10c[0x9c] = 0;
  local_10c[0x9d] = 0;
  local_10c[0x9e] = 0;
  local_10c[0x9f] = 0;
  local_10c[0xa1] = 0x41;
  local_10c[0xa2] = 0x2f;
  local_10c[0xa4] = 0;
  local_10c[0xa5] = 0x14;
  local_10c[0xa6] = 0x40;
  local_10c[0xa7] = 0x2f;
  local_10c[0xa8] = 0xb1;
  local_10c[0xa9] = 0x80;
  local_10c[0xaa] = 0;
  local_10c[0xab] = 0xd;
  local_10c[0xac] = 10;
  local_10c[0xad] = 0;
  local_10c[0xae] = 0;
  local_10c[0xaf] = 0;
  local_10c[0xb1] = 0x41;
  local_10c[0xb4] = 0;
  local_10c[0xb5] = 0x14;
  local_10c[0xb6] = 0x40;
  local_10c[0xb8] = 0xb1;
  local_10c[0xb9] = 0x80;
  local_10c[0xba] = 0;
  local_10c[0xbb] = 0xd;
  local_10c[0xbc] = 10;
  local_10c[0xbd] = 0;
  local_10c[0xbe] = 0;
  local_10c[0xbf] = 0;
  local_134 = 2;
  local_133 = 0x105129a;
  local_12f = 0x8618;
  local_12b = 0;
  local_12a = 0;
  FUN_004026f0(&DAT_0041d180,param_1,&local_134,&local_134,5);
  local_124 = 2;
  local_123 = 0x9a;
  local_122 = 0x12;
  local_121 = 7;
  local_120 = 1;
  local_11f = 0x18;
  local_11e = 0;
  local_11d = 0;
  local_11c = 0;
  local_11b = 0;
  local_11a = 0;
  FUN_004026f0(&DAT_0041d180,param_1,&local_124,&local_124,5);
  local_124 = 2;
  local_123 = 0x9a;
  local_122 = 0x12;
  local_121 = 5;
  local_120 = 2;
  local_11f = 0x18;
  local_11e = 0x86;
  local_11d = 0;
  local_11c = 0;
  local_11b = 0;
  local_11a = 0;
  FUN_004026f0(&DAT_0041d180,param_1,&local_124,&local_124,5);
  local_134 = 2;
  local_133 = 0x207129a;
  local_12f = 0x18;
  local_12b = 0;
  local_12a = 0;
  FUN_004026f0(&DAT_0041d180,param_1,&local_134,&local_134,5);
  iVar1 = 0x1600;
  do {
    local_133 = 0;
    local_134 = 0;
    local_12f = 0;
    local_12b = 0;
    Sleep(2);
    FUN_00401210(&DAT_0041d180,param_1,iVar1,0xf);
    Sleep(2);
    FUN_00401310(&DAT_0041d180,param_1,iVar1,&local_134);
    if (local_133._1_1_ != '\x0f') {
      iVar1 = iVar1 + -0x200;
    }
    iVar1 = iVar1 + 0x200;
  } while (iVar1 < 0x1a00);
  iVar1 = 0x1c00;
  do {
    local_133 = 0;
    local_134 = 0;
    local_12f = 0;
    local_12b = 0;
    Sleep(2);
    FUN_00401210(&DAT_0041d180,param_1,iVar1,0xf);
    Sleep(2);
    FUN_00401310(&DAT_0041d180,param_1,iVar1,&local_134);
    if (local_133._1_1_ != '\x0f') {
      iVar1 = iVar1 + -0x100;
    }
    iVar1 = iVar1 + 0x100;
  } while (iVar1 < 0x1e00);
  local_110 = 0;
  do {
    local_4c = 0;
    if (local_110 == 1) {
      local_4c = 4;
    }
    else if (local_110 == 2) {
      local_4c = 8;
    }
    iVar2 = 0;
    local_4c = local_4c * 0x10;
    local_118 = local_10c + local_4c + 0x11;
    local_40 = (uint)local_10c[local_4c];
    iVar1 = local_110;
    do {
      if (iVar2 < (int)local_40) {
        local_128 = iVar1 * 0xa00 + 0x200 + iVar2;
        _local_38 = CONCAT31(uStack_37,local_118[-0x10]);
        do {
          Sleep(3);
          FUN_00401210(&DAT_0041d180,param_1,local_128,(char)_local_38);
          Sleep(3);
          FUN_00401310(&DAT_0041d180,param_1,local_128,local_34);
          iVar1 = local_110;
          if (local_32 == local_38) break;
        } while (iVar2 < (int)local_40);
      }
      local_114 = (uint)local_10c[local_4c + 0x10];
      if (iVar2 < (int)local_114) {
        local_128 = iVar1 * 0xa00 + 0x400 + iVar2;
        _local_48 = CONCAT31(uStack_47,*local_118);
        do {
          Sleep(3);
          FUN_00401210(&DAT_0041d180,param_1,local_128,(char)_local_48);
          Sleep(3);
          FUN_00401310(&DAT_0041d180,param_1,local_128,local_34);
          iVar1 = local_110;
          if (local_32 == local_48) break;
        } while (iVar2 < (int)local_114);
      }
      local_114 = (uint)local_10c[local_4c + 0x20];
      if (iVar2 < (int)local_114) {
        local_128 = iVar1 * 0xa00 + 0x800 + iVar2;
        _local_44 = CONCAT31(uStack_43,local_118[0x10]);
        do {
          Sleep(3);
          FUN_00401210(&DAT_0041d180,param_1,local_128,(char)_local_44);
          Sleep(3);
          FUN_00401310(&DAT_0041d180,param_1,local_128,local_34);
          iVar1 = local_110;
          if (local_32 == local_44) break;
        } while (iVar2 < (int)local_114);
      }
      local_114 = (uint)local_10c[local_4c + 0x30];
      if (iVar2 < (int)local_114) {
        local_128 = iVar1 * 0xa00 + 0x900 + iVar2;
        _local_3c = CONCAT31(uStack_3b,local_118[0x20]);
        do {
          Sleep(3);
          FUN_00401210(&DAT_0041d180,param_1,local_128,(char)_local_3c);
          Sleep(3);
          FUN_00401310(&DAT_0041d180,param_1,local_128,local_34);
          iVar1 = local_110;
          if (local_32 == local_3c) break;
        } while (iVar2 < (int)local_114);
      }
      iVar2 = iVar2 + 1;
      local_118 = local_118 + 1;
    } while (iVar2 < 0xf);
    local_110 = iVar1 + 1;
    if (2 < local_110) {
      return;
    }
  } while( true );
}



/* ==== FUN_0040c450 @ 0040c450 ==== */

void FUN_0040c450(int param_1)

{
  int iVar1;
  int local_11c;
  int local_118;
  undefined local_114;
  undefined4 local_113;
  undefined4 local_10f;
  undefined local_10b;
  undefined local_108;
  char local_107 [195];
  char local_44;
  undefined3 uStack_43;
  char local_40;
  undefined3 uStack_3f;
  char local_3c;
  undefined3 uStack_3b;
  char *local_38;
  undefined local_34 [2];
  char local_32;
  
  local_107[0] = -0x4c;
  local_107[3] = 0xb4;
  local_107[0x10] = 0xb4;
  local_107[0x13] = 0xb4;
  local_108 = 7;
  local_107[1] = 0x25;
  local_107[2] = 2;
  local_107[4] = 0;
  local_107[5] = 0;
  local_107[6] = 0xf;
  local_107[7] = 0;
  local_107[8] = 0;
  local_107[9] = 0;
  local_107[10] = 0;
  local_107[0xb] = 0;
  local_107[0xc] = 0;
  local_107[0xd] = 0;
  local_107[0xe] = 0;
  local_107[0xf] = 7;
  local_107[0x11] = 0x24;
  local_107[0x12] = 2;
  local_107[0x14] = 0;
  local_107[0x15] = 0;
  local_107[0x16] = 0xf;
  local_107[0x17] = 0;
  local_107[0x18] = 0;
  local_107[0x19] = 0;
  local_107[0x1a] = 0;
  local_107[0x1b] = 0;
  local_107[0x1c] = 0;
  local_107[0x1d] = 0;
  local_107[0x1e] = 0;
  local_107[0x1f] = 0;
  local_107[0x20] = 0x41;
  local_107[0x21] = 0xb;
  local_107[0x22] = 0x40;
  local_107[0x23] = 0xb;
  local_107[0x24] = 0xf;
  local_107[0x25] = 1;
  local_107[0x26] = 0xd;
  local_107[0x27] = 10;
  local_107[0x28] = 0;
  local_107[0x29] = 0;
  local_107[0x2a] = 0;
  local_107[0x2b] = 0;
  local_107[0x2c] = 0;
  local_107[0x2d] = 0;
  local_107[0x2e] = 0;
  local_107[0x2f] = 0;
  local_107[0x30] = 0x41;
  local_107[0x31] = 0xc;
  local_107[0x32] = 0x70;
  local_107[0x33] = 0;
  local_107[0x34] = 0x14;
  local_107[0x35] = 0x40;
  local_107[0x36] = 0xc;
  local_107[0x37] = 1;
  local_107[0x38] = 0xd;
  local_107[0x39] = 10;
  local_107[0x3a] = 0;
  local_107[0x3b] = 0;
  local_107[0x3c] = 0;
  local_107[0x3d] = 0;
  local_107[0x3e] = 0;
  local_107[0x3f] = 0xb;
  local_107[0x40] = 0x41;
  local_107[0x41] = 0xb;
  local_107[0x42] = 0x70;
  local_107[0x43] = 0;
  local_107[0x44] = 0x14;
  local_107[0x45] = 0x40;
  local_107[0x46] = 0xb;
  local_107[0x47] = 0xf;
  local_107[0x48] = 1;
  local_107[0x49] = 0xd;
  local_107[0x4a] = 10;
  local_107[0x4b] = 0;
  local_107[0x4c] = 0;
  local_107[0x4d] = 0;
  local_107[0x4e] = 0;
  local_107[0x4f] = 0xb;
  local_107[0x50] = 0x41;
  local_107[0x51] = 0xc;
  local_107[0x52] = 0x70;
  local_107[0x53] = 0;
  local_107[0x54] = 0x14;
  local_107[0x55] = 0x40;
  local_107[0x56] = 0xc;
  local_107[0x57] = 0xf;
  local_107[0x58] = 1;
  local_107[0x59] = 0xd;
  local_107[0x5a] = 10;
  local_107[0x5b] = 0;
  local_107[0x5c] = 0;
  local_107[0x5d] = 0;
  local_107[0x5e] = 0;
  local_107[0x5f] = 0xb;
  local_107[0x60] = 0x41;
  local_107[0x61] = 0xd;
  local_107[0x62] = 0x70;
  local_107[99] = 0;
  local_107[100] = 0x28;
  local_107[0x65] = 0x40;
  local_107[0x66] = 0xd;
  local_107[0x67] = 0x70;
  local_107[0x68] = 0;
  local_107[0x69] = 0x28;
  local_107[0x6a] = 0xf;
  local_107[0x6b] = 0;
  local_107[0x6c] = 0;
  local_107[0x6d] = 0;
  local_107[0x6e] = 0;
  local_107[0x6f] = 0xb;
  local_107[0x70] = 0x41;
  local_107[0x71] = 0x18;
  local_107[0x72] = 0x70;
  local_107[0x73] = 0;
  local_107[0x74] = 0x28;
  local_107[0x75] = 0x40;
  local_107[0x76] = 0x18;
  local_107[0x77] = 0x70;
  local_107[0x78] = 0;
  local_107[0x79] = 0x28;
  local_107[0x7a] = 0xf;
  local_107[0x7b] = 0;
  local_107[0x7c] = 0;
  local_107[0x7d] = 0;
  local_107[0x7e] = 0;
  local_107[0x7f] = 0xb;
  local_107[0x80] = 0x41;
  local_107[0x81] = 0x37;
  local_107[0x82] = 0x70;
  local_107[0x83] = 0;
  local_107[0x84] = 0x14;
  local_107[0x85] = 0x40;
  local_107[0x86] = 0x37;
  local_107[0x87] = 0xf;
  local_107[0x88] = 1;
  local_107[0x89] = 0xd;
  local_107[0x8a] = 10;
  local_107[0x8b] = 0;
  local_107[0x8c] = 0;
  local_107[0x8d] = 0;
  local_107[0x8e] = 0;
  local_107[0x8f] = 0xb;
  local_107[0x90] = 0x41;
  local_107[0x91] = 0x36;
  local_107[0x92] = 0x70;
  local_107[0x93] = 0;
  local_107[0x94] = 0x14;
  local_107[0x95] = 0x40;
  local_107[0x96] = 0x36;
  local_107[0x97] = 0xf;
  local_107[0x9f] = 0xb;
  local_107[0xaf] = 0xb;
  local_107[0x98] = 1;
  local_107[0x99] = 0xd;
  local_107[0x9a] = 10;
  local_107[0x9b] = 0;
  local_107[0x9c] = 0;
  local_107[0x9d] = 0;
  local_107[0x9e] = 0;
  local_107[0xa0] = 0x41;
  local_107[0xa1] = 0x2f;
  local_107[0xa2] = 0x70;
  local_107[0xa3] = 0;
  local_107[0xa4] = 0x14;
  local_107[0xa5] = 0x40;
  local_107[0xa6] = 0x2f;
  local_107[0xa7] = 0xb1;
  local_107[0xa8] = 0x80;
  local_107[0xa9] = 0;
  local_107[0xaa] = 0xd;
  local_107[0xab] = 10;
  local_107[0xac] = 0;
  local_107[0xad] = 0;
  local_107[0xae] = 0;
  local_107[0xb0] = 0x41;
  local_107[0xb1] = 0x30;
  local_107[0xb2] = 0x70;
  local_107[0xb3] = 0;
  local_107[0xb4] = 0x14;
  local_107[0xb5] = 0x40;
  local_107[0xb6] = 0x30;
  local_107[0xb7] = 0xb1;
  local_107[0xb8] = 0x80;
  local_107[0xb9] = 0;
  local_107[0xba] = 0xd;
  local_107[0xbb] = 10;
  local_107[0xbc] = 0;
  local_107[0xbd] = 0;
  local_107[0xbe] = 0;
  iVar1 = 0x1600;
  do {
    local_113 = 0;
    local_114 = 0;
    local_10f = 0;
    local_10b = 0;
    Sleep(2);
    FUN_00401210(&DAT_0041d180,param_1,iVar1,0xf);
    Sleep(2);
    FUN_00401310(&DAT_0041d180,param_1,iVar1,&local_114);
    if (local_113._1_1_ != '\x0f') {
      iVar1 = iVar1 + -0x200;
    }
    iVar1 = iVar1 + 0x200;
  } while (iVar1 < 0x1a00);
  iVar1 = 0x1c00;
  do {
    local_113 = 0;
    local_114 = 0;
    local_10f = 0;
    local_10b = 0;
    Sleep(2);
    FUN_00401210(&DAT_0041d180,param_1,iVar1,0xf);
    Sleep(2);
    FUN_00401310(&DAT_0041d180,param_1,iVar1,&local_114);
    if (local_113._1_1_ != '\x0f') {
      iVar1 = iVar1 + -0x100;
    }
    iVar1 = iVar1 + 0x100;
  } while (iVar1 < 0x1e00);
  local_118 = 0;
  do {
    local_11c = 0;
    do {
      if (local_11c < 7) {
        iVar1 = local_11c + 0x200 + local_118;
        local_38 = local_107 + local_11c + 0x10;
        _local_3c = CONCAT31(uStack_3b,local_107[local_11c]);
        do {
          Sleep(3);
          FUN_00401210(&DAT_0041d180,param_1,iVar1,(char)_local_3c);
          Sleep(3);
          FUN_00401310(&DAT_0041d180,param_1,iVar1,local_34);
        } while (local_32 != local_3c);
        iVar1 = local_11c + 0x400 + local_118;
        _local_44 = CONCAT31(uStack_43,*local_38);
        do {
          Sleep(3);
          FUN_00401210(&DAT_0041d180,param_1,iVar1,(char)_local_44);
          Sleep(3);
          FUN_00401310(&DAT_0041d180,param_1,iVar1,local_34);
        } while (local_32 != local_44);
      }
      if (local_11c < 0) {
        iVar1 = local_11c + 0x800 + local_118;
        local_107[0xbf] = local_107[local_11c + 0x20];
        do {
          Sleep(3);
          FUN_00401210(&DAT_0041d180,param_1,iVar1,(char)local_107._191_4_);
          Sleep(3);
          FUN_00401310(&DAT_0041d180,param_1,iVar1,local_34);
        } while (local_32 != local_107[0xbf]);
        iVar1 = local_11c + 0x900 + local_118;
        _local_40 = CONCAT31(uStack_3f,local_107[local_11c + 0x30]);
        do {
          Sleep(3);
          FUN_00401210(&DAT_0041d180,param_1,iVar1,(char)_local_40);
          Sleep(3);
          FUN_00401310(&DAT_0041d180,param_1,iVar1,local_34);
        } while (local_32 != local_40);
      }
      local_11c = local_11c + 1;
    } while (local_11c < 0xf);
    local_118 = local_118 + 0xa00;
  } while (local_118 < 0x1e00);
  return;
}



/* ==== FUN_0040cb70 @ 0040cb70 ==== */

void FUN_0040cb70(DWORD param_1)

{
  CString *pCVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  CString local_1c [4];
  undefined local_18;
  undefined local_17;
  undefined local_16;
  undefined local_15;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined local_11;
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_c;
  undefined local_b;
  undefined local_a;
  undefined local_9;
  undefined local_8;
  undefined local_7;
  undefined local_6;
  undefined local_5;
  undefined local_4;
  undefined local_3;
  undefined local_2;
  
  pCVar1 = FUN_00401610(&DAT_0041d180,local_1c,param_1);
  iVar2 = _mbscmp(*(uchar **)pCVar1,&DAT_00418080);
  CString::~CString(local_1c);
  if (iVar2 == 0) {
    local_18 = 2;
    local_17 = 0x9a;
    local_16 = 0x12;
    local_15 = 5;
    local_14 = 0;
    local_13 = 0;
    local_12 = 0xfe;
    local_11 = 0;
    local_10 = 0;
    local_f = 0;
    local_e = 0;
    FUN_004026f0(&DAT_0041d180,param_1,&local_18,&local_18,3);
    puVar4 = &local_c;
    puVar3 = &local_c;
    local_c = 2;
    local_b = 0x9a;
    local_a = 0x12;
    local_9 = 7;
    local_8 = 0;
    local_7 = 0;
    local_6 = 0;
    local_5 = 0;
    local_4 = 0;
    local_3 = 0;
    local_2 = 0;
  }
  else {
    local_c = 2;
    local_b = 0x9a;
    local_a = 0x12;
    local_9 = 5;
    local_8 = 0;
    local_7 = 0;
    local_6 = 0xe6;
    local_5 = 0;
    local_4 = 0;
    local_3 = 0;
    local_2 = 0;
    FUN_004026f0(&DAT_0041d180,param_1,&local_c,&local_c,3);
    puVar4 = &local_18;
    puVar3 = &local_18;
    local_18 = 2;
    local_17 = 0x9a;
    local_16 = 0x12;
    local_15 = 7;
    local_14 = 0;
    local_13 = 0;
    local_12 = 0;
    local_11 = 0;
    local_10 = 0;
    local_f = 0;
    local_e = 0;
  }
  FUN_004026f0(&DAT_0041d180,param_1,puVar3,puVar4,3);
  pCVar1 = FUN_00401610(&DAT_0041d180,local_1c,param_1);
  iVar2 = _mbscmp(*(uchar **)pCVar1,&DAT_00418080);
  CString::~CString(local_1c);
  if (iVar2 == 0) {
    local_c = 2;
    local_b = 0x9a;
    local_a = 0x12;
    local_9 = 5;
    local_8 = 1;
    local_7 = 0;
    local_6 = 0xfe;
    local_5 = 0;
    local_4 = 0;
    local_3 = 0;
    local_2 = 0;
    FUN_004026f0(&DAT_0041d180,param_1,&local_c,&local_c,3);
  }
  else {
    local_c = 2;
    local_b = 0x9a;
    local_a = 0x12;
    local_9 = 5;
    local_8 = 1;
    local_7 = 0;
    local_6 = 0xe6;
    local_5 = 0;
    local_4 = 0;
    local_3 = 0;
    local_2 = 0;
    FUN_004026f0(&DAT_0041d180,param_1,&local_c,&local_c,3);
  }
  local_e = 0;
  local_f = 0;
  local_10 = 0;
  local_11 = 0;
  local_12 = 0;
  local_13 = 0;
  local_14 = 1;
  local_15 = 7;
  local_16 = 0x12;
  local_17 = 0x9a;
  local_18 = 2;
  FUN_004026f0(&DAT_0041d180,param_1,&local_18,&local_18,3);
  pCVar1 = FUN_00401610(&DAT_0041d180,local_1c,param_1);
  iVar2 = _mbscmp(*(uchar **)pCVar1,&DAT_00418080);
  CString::~CString(local_1c);
  if (iVar2 == 0) {
    local_c = 2;
    local_b = 0x9a;
    local_a = 0x12;
    local_9 = 5;
    local_8 = 2;
    local_7 = 0;
    local_6 = 0xfe;
    local_5 = 0;
    local_4 = 0;
    local_3 = 0;
    local_2 = 0;
    FUN_004026f0(&DAT_0041d180,param_1,&local_c,&local_c,3);
    local_18 = 2;
    local_17 = 0x9a;
    local_16 = 0x12;
    local_15 = 7;
    local_14 = 2;
    local_13 = 0;
    local_12 = 0;
    local_11 = 0;
    local_10 = 0;
    local_f = 0;
    local_e = 0;
    FUN_004026f0(&DAT_0041d180,param_1,&local_18,&local_18,3);
    return;
  }
  local_c = 2;
  local_b = 0x9a;
  local_a = 0x12;
  local_9 = 5;
  local_8 = 2;
  local_7 = 0;
  local_6 = 0xe6;
  local_5 = 0;
  local_4 = 0;
  local_3 = 0;
  local_2 = 0;
  FUN_004026f0(&DAT_0041d180,param_1,&local_c,&local_c,3);
  local_18 = 2;
  local_17 = 0x9a;
  local_16 = 0x12;
  local_15 = 7;
  local_14 = 2;
  local_13 = 0;
  local_12 = 0;
  local_11 = 0;
  local_10 = 0;
  local_f = 0;
  local_e = 0;
  FUN_004026f0(&DAT_0041d180,param_1,&local_18,&local_18,3);
  return;
}



/* ==== FUN_0040cfa0 @ 0040cfa0 ==== */

void FUN_0040cfa0(DWORD param_1)

{
  int iVar1;
  CString *pCVar2;
  undefined uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined local_104;
  undefined local_103;
  undefined local_102;
  undefined local_101;
  undefined local_100;
  undefined local_ff;
  undefined local_fe;
  undefined local_fd;
  undefined local_fc;
  undefined local_fb;
  char cStack_f9;
  int local_f8;
  int local_f4;
  int local_f0;
  undefined local_ec;
  undefined local_eb;
  undefined local_ea;
  undefined local_e9;
  undefined local_e8;
  undefined local_e7;
  undefined local_e6;
  undefined local_e5;
  undefined local_e4;
  undefined local_e0;
  undefined local_df;
  undefined local_de;
  undefined local_dd;
  undefined local_dc;
  undefined local_db;
  undefined local_da;
  undefined local_d9;
  undefined local_d8;
  undefined local_d4;
  undefined local_d3;
  undefined local_d2;
  undefined local_d1;
  undefined local_d0;
  undefined local_cf;
  undefined local_ce;
  undefined local_cd;
  undefined local_cc;
  undefined local_c8;
  undefined local_c7;
  undefined local_c6;
  undefined local_c5;
  undefined local_c4;
  undefined local_c3;
  undefined local_c2;
  undefined local_c1;
  undefined local_c0;
  undefined local_bc;
  undefined local_bb;
  undefined local_ba;
  undefined local_b9;
  undefined local_b8;
  undefined local_b7;
  undefined local_b6;
  undefined local_b5;
  undefined local_b4;
  undefined local_b0;
  undefined local_af;
  undefined local_ae;
  undefined local_ad;
  undefined local_ac;
  undefined local_ab;
  undefined local_aa;
  undefined local_a9;
  undefined local_a8;
  CString local_a4 [4];
  int local_a0 [40];
  
  iVar4 = 0;
  do {
    if (((iVar4 == 3) && (DAT_0041f008 == 3)) && ((&DAT_0041d548)[param_1] == 2)) {
      local_b8 = 3;
      local_bc = 2;
      local_bb = 0x9a;
      local_ba = 0x12;
      local_b9 = 1;
      local_b7 = 6;
      local_b6 = 5;
      local_b5 = 0x10;
      local_b4 = 0;
      FUN_004026f0(&DAT_0041d180,param_1,&local_bc,&local_bc,8);
      Sleep(0xc);
      local_b0 = 2;
      local_af = 0x9a;
      local_ae = 0x12;
      local_ad = 2;
      local_ac = 3;
      local_ab = 6;
      local_aa = 5;
      local_a9 = 0x10;
      local_a8 = 0;
      FUN_004026f0(&DAT_0041d180,param_1,&local_b0,&local_b0,8);
      Sleep(0xc);
      puVar6 = &local_c8;
      puVar5 = &local_c8;
      local_c8 = 2;
      local_c7 = 0x9a;
      local_c6 = 0x12;
      local_c5 = 0;
      local_c4 = 3;
      local_c3 = 7;
      local_c2 = 0;
      local_c1 = 0x10;
      local_c0 = 0;
    }
    else {
      local_f8 = 1;
      local_f4 = 1;
      local_f0 = iVar4;
      if ((&DAT_0041d548)[param_1] == 5) {
        local_a0[8] = 8;
        local_a0[9] = 0x10;
        local_a0[10] = 0x18;
        local_a0[0xb] = 0x20;
        local_f8 = local_a0[iVar4 + 8];
      }
      else if ((&DAT_0041d548)[param_1] == 1) {
        local_a0[0] = 1;
        local_a0[1] = 1;
        local_a0[2] = 3;
        local_a0[3] = 1;
        local_a0[0x18] = 1;
        local_a0[0x19] = 2;
        local_a0[0x1a] = 4;
        local_a0[0x1b] = 1;
        local_f4 = local_a0[iVar4 + 0x18];
        local_a0[0x10] = 0;
        local_a0[0x11] = 7;
        local_a0[0x12] = 7;
        local_a0[0x13] = 3;
        local_f8 = local_a0[iVar4];
        local_f0 = local_a0[iVar4 + 0x10];
      }
      else {
        pCVar2 = FUN_00401610(&DAT_0041d180,local_a4,param_1);
        iVar1 = _mbscmp(*(uchar **)pCVar2,&DAT_00418080);
        cStack_f9 = iVar1 == 0;
        CString::~CString(local_a4);
        if (cStack_f9 == '\0') {
          iVar1 = _mbscmp((uchar *)(&DAT_0041d4f8)[param_1],(uchar *)s_DRTCM03_004195a4);
          if (iVar1 == 0) {
            local_a0[0x14] = 1;
            local_a0[0x15] = 1;
            local_a0[0x16] = 1;
            local_a0[0x17] = 1;
            local_f8 = local_a0[iVar4 + 0x14];
            local_a0[0x1c] = 2;
            local_a0[0x1d] = 1;
            local_a0[0x1e] = 1;
            local_a0[0x1f] = 1;
            local_a0[0x27] = 2;
            local_f4 = local_a0[iVar4 + 0x1c];
            local_a0[0x24] = 4;
            local_a0[0x25] = 0;
            local_a0[0x26] = 1;
            local_f0 = local_a0[iVar4 + 0x24];
          }
        }
        else {
          local_a0[0x20] = 1;
          local_a0[0x21] = 1;
          local_a0[0x22] = 0x10;
          local_a0[0x23] = 4;
          local_f8 = local_a0[iVar4 + 0x20];
          local_a0[4] = 1;
          local_a0[5] = 1;
          local_a0[6] = 0xf;
          local_a0[7] = 3;
          local_a0[0xe] = 7;
          local_a0[0xf] = 7;
          local_f4 = local_a0[iVar4 + 4];
          local_a0[0xc] = 0;
          local_a0[0xd] = 1;
          local_f0 = local_a0[iVar4 + 0xc];
        }
      }
      local_db = (undefined)local_f8;
      local_e0 = 2;
      local_df = 0x9a;
      local_de = 0x12;
      local_dd = 1;
      uVar3 = (undefined)iVar4;
      local_da = (undefined)local_f4;
      local_d9 = 0x10;
      local_d8 = 0;
      local_dc = uVar3;
      FUN_004026f0(&DAT_0041d180,param_1,&local_e0,&local_e0,8);
      Sleep(0xc);
      local_cf = (undefined)local_f8;
      local_ce = (undefined)local_f4;
      local_d4 = 2;
      local_d3 = 0x9a;
      local_d2 = 0x12;
      local_d1 = 2;
      local_cd = 0x10;
      local_cc = 0;
      local_d0 = uVar3;
      FUN_004026f0(&DAT_0041d180,param_1,&local_d4,&local_d4,8);
      Sleep(0xc);
      puVar6 = &local_ec;
      puVar5 = &local_ec;
      local_ec = 2;
      local_eb = 0x9a;
      local_ea = 0x12;
      local_e9 = 0;
      local_e7 = (undefined)local_f0;
      local_e6 = 0;
      local_e5 = 0x10;
      local_e4 = 0;
      local_e8 = uVar3;
    }
    FUN_004026f0(&DAT_0041d180,param_1,puVar5,puVar6,8);
    Sleep(0xc);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  local_100 = 2;
  if (DAT_0041f008 == 2) {
    local_100 = 1;
  }
  local_104 = 2;
  local_103 = 0x9a;
  local_102 = 0x11;
  local_101 = 1;
  local_ff = 0;
  local_fe = 0;
  local_fd = 0;
  local_fc = 0;
  local_fb = 0;
  FUN_004026f0(&DAT_0041d180,param_1,&local_104,&local_104,3);
  iVar4 = FUN_00401600(&DAT_0041d180,param_1);
  if (0x28 < iVar4) {
    local_104 = 2;
    local_103 = 0x97;
    local_102 = 0xb;
    local_101 = 2;
    iVar4 = FUN_00401200(&DAT_0041d180,param_1);
    if (iVar4 == 1) {
      local_101 = 3;
    }
    else {
      pCVar2 = FUN_00401610(&DAT_0041d180,local_a4,param_1);
      iVar4 = _mbscmp(*(uchar **)pCVar2,&DAT_00418080);
      CString::~CString(local_a4);
      if ((iVar4 == 0) || ((&DAT_0041d548)[param_1] == 4)) {
        local_101 = 1;
      }
    }
    iVar4 = _mbscmp((uchar *)(&DAT_0041d4f8)[param_1],(uchar *)s_DRTCM03_004195a4);
    if (iVar4 == 0) {
      local_101 = 2;
    }
    FUN_004026f0(&DAT_0041d180,param_1,&local_104,&local_104,3);
    Sleep(10);
    local_104 = 2;
    local_103 = 0x97;
    local_102 = 0xc;
    local_101 = 0;
    FUN_004026f0(&DAT_0041d180,param_1,&local_104,&local_104,3);
    Sleep(10);
    local_104 = 2;
    local_103 = 0x97;
    local_102 = 0x32;
    local_101 = 0x1e;
    FUN_004026f0(&DAT_0041d180,param_1,&local_104,&local_104,3);
    Sleep(10);
    local_104 = 2;
    local_103 = 0x97;
    local_102 = 0x33;
    local_101 = 0x12;
    FUN_004026f0(&DAT_0041d180,param_1,&local_104,&local_104,3);
  }
  return;
}



/* ==== FUN_0040d590 @ 0040d590 ==== */

void FUN_0040d590(DWORD param_1)

{
  undefined local_18;
  undefined local_17;
  undefined local_16;
  undefined local_15;
  undefined local_c [12];
  
  local_16 = 0xfa;
  local_15 = 0xfa;
  local_18 = 1;
  local_17 = 7;
  FUN_004026f0(&DAT_0041d180,param_1,&local_18,local_c,10);
  return;
}



/* ==== FUN_0040d5d0 @ 0040d5d0 ==== */

void FUN_0040d5d0(void)

{
  undefined4 *puVar1;
  HDC hdc;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char *hdc_00;
  CString aCStack_2c [4];
  int *piStack_28;
  int iStack_24;
  HDC pHStack_20;
  LPCSTR pCStack_1c;
  int aiStack_18 [2];
  int iStack_10;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00414670;
  pvStack_c = ExceptionList;
  puVar1 = &DAT_0041deb0;
  ExceptionList = &pvStack_c;
  do {
    *puVar1 = 1;
    puVar1 = puVar1 + 0xe;
  } while ((int)puVar1 < 0x41e0e0);
  iVar5 = 0;
  hdc = CreateCompatibleDC((HDC)0x0);
  pHStack_20 = hdc;
  SelectObject(hdc,DAT_0041f048);
  iVar3 = *(int *)(DAT_00418544 * 0x38 + 0x41d5d4);
  aiStack_18[0] = (&DAT_0041d608)[DAT_00418544 * 0xe] + 0x14;
  CString::CString(aCStack_2c);
  uStack_4 = 0;
  iVar2 = FUN_004026e0(0x41d180);
  if (0 < iVar2) {
    iStack_24 = 1;
    piVar4 = &DAT_0041ded4;
    piStack_28 = &DAT_0041d598;
    do {
      if (*piStack_28 == 1) {
        FUN_00401610(&DAT_0041d180,(CString *)&pCStack_1c,iVar5);
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
        FUN_004015f0(&DAT_0041d180,iVar5);
        iVar2 = iStack_24;
        hdc_00 = s_____d_Model___s___Ver___d__click_004195ac;
        CString::Format(aCStack_2c,(char *)aCStack_2c);
        CString::~CString((CString *)aiStack_18);
        GetTextExtentPointA((HDC)hdc_00,pCStack_1c,(int)piStack_28,(LPSIZE)piStack_28[-2]);
        CString::operator=((CString *)(piVar4 + -6),aCStack_2c);
        *piVar4 = DAT_00418544;
        piVar4[-1] = 5;
        piVar4[-3] = aiStack_18[0];
        piVar4[-9] = 0;
        piVar4[-8] = iVar5;
        piVar4[-2] = (iVar3 - iStack_10) + -4;
        piVar4[-7] = 0x121212;
        piVar4[-4] = 0xffffff;
        iVar3 = piVar4[-2];
        iStack_24 = iVar2 + 1;
        piVar4 = piVar4 + 0xe;
      }
      piStack_28 = piStack_28 + 1;
      iVar5 = iVar5 + 1;
      iVar2 = FUN_004026e0(0x41d180);
      hdc = pHStack_20;
    } while (iVar5 < iVar2);
  }
  DeleteDC(hdc);
  uStack_4 = 0xffffffff;
  CString::~CString(aCStack_2c);
  ExceptionList = pvStack_c;
  return;
}



/* ==== FUN_0040d790 @ 0040d790 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CString * FUN_0040d790(void)

{
  int iVar1;
  CString *pCVar2;
  LRESULT LVar3;
  CString *this;
  int iVar4;
  DWORD DVar5;
  uint uVar6;
  int *piVar7;
  DWORD DVar8;
  undefined *puVar9;
  char *pcVar10;
  uint local_48;
  CString local_44 [4];
  int *local_40;
  int local_3c;
  CString aCStack_38 [4];
  CString local_34 [4];
  undefined2 local_30;
  ushort uStack_2e;
  undefined local_2c [2];
  byte bStack_2a;
  uint uStack_28;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  char local_1d;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined local_11;
  CString local_10;
  undefined local_f;
  undefined local_e;
  undefined local_d;
  void *local_c;
  undefined *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004146b8;
  local_c = ExceptionList;
  iVar4 = 0;
  DVar8 = 0;
  ExceptionList = &local_c;
  CString::CString((CString *)&local_3c);
  local_4 = 0;
  CString::CString((CString *)&local_48);
  local_4 = CONCAT31(local_4._1_3_,1);
  DVar5 = 0;
  iVar1 = FUN_004026e0(0x41d180);
  if (0 < iVar1) {
    local_40 = &DAT_0041d598;
    do {
      if (*local_40 == 1) {
        iVar4 = iVar4 + 1;
        DVar8 = DVar5;
      }
      local_40 = local_40 + 1;
      DVar5 = DVar5 + 1;
      iVar1 = FUN_004026e0(0x41d180);
    } while ((int)DVar5 < iVar1);
  }
  _DAT_0041ebfc = 10;
  _DAT_0041ec00 = 0xa0;
  _DAT_0041ec04 = 4;
  DAT_0041ebec = 0;
  if (1 < iVar4) {
    CString::operator=((CString *)&DAT_0041ebf4,s_error___found_more_than_two_gami_00419514);
    _DAT_0041ebf8 = 0xff;
    DAT_0041effc = 1;
    local_4 = local_4 & 0xffffff00;
    CString::~CString((CString *)&local_48);
    local_4 = 0xffffffff;
    CString::~CString((CString *)&local_3c);
    ExceptionList = local_c;
    return (CString *)0x0;
  }
  if (iVar4 == 0) {
    CString::operator=((CString *)&DAT_0041ebf4,s_error___didn_t_find_any_gaming_d_004194e8);
    _DAT_0041ebf8 = 0xff;
    DAT_0041effc = 1;
    local_4 = local_4 & 0xffffff00;
    CString::~CString((CString *)&local_48);
    local_4 = 0xffffffff;
    CString::~CString((CString *)&local_3c);
    ExceptionList = local_c;
    return (CString *)0x0;
  }
  DAT_0041effc = 1;
  _DAT_0041ebf8 = 0xffff;
  CString::operator=((CString *)&local_48,(ushort *)u_Model___s___Ver___d_00419700);
  pCVar2 = FUN_00401610(&DAT_0041d180,(CString *)&local_40,DVar8);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_004015f0(&DAT_0041d180,DVar8);
  CString::Format(*(CString **)pCVar2,&DAT_0041ebf4);
  CString::~CString((CString *)&local_3c);
  _DAT_0041ec18 = 10;
  _DAT_0041ec1c = 0xbe;
  _DAT_0041ec20 = 4;
  DAT_0041ec08 = 0;
  _DAT_0041ec14 = 0xffff;
  CString::operator=((CString *)&DAT_0041ec10,s_Testing____004196f4);
  local_48 = CONCAT13(local_48._3_1_,0x4f2302);
  iVar1 = FUN_004015e0(&DAT_0041d180,DVar8);
  if (iVar1 == 9) {
    local_3c = 1;
    CString::CString((CString *)&local_30);
    CString::CString(local_34);
    local_40 = (int *)0x2f7c5c2d;
    iVar1 = 0;
    do {
      local_10 = local_44[iVar1 + -4];
      uVar6 = 0;
      local_14 = 1;
      local_13 = 0xc;
      local_12 = 1;
      local_11 = 1;
      local_f = 0xfa;
      local_e = 0;
      local_d = 0;
      local_c = (void *)0x0;
      FUN_004026f0(&DAT_0041d180,DVar8,&local_14,&local_20,5);
      local_1e = 0;
      if ((DAT_0041f004 & 0x80) == 0) {
        while( true ) {
          puVar9 = &local_20;
          local_14 = 1;
          local_1f = 0xc;
          local_12 = 0;
          FUN_004026f0(&DAT_0041d180,DVar8,&local_14,puVar9,3);
          if (local_1d == -6) break;
          Sleep((DWORD)puVar9);
          uVar6 = uVar6 + 1;
          pCVar2 = (CString *)(uVar6 & 0x80000003);
          if ((int)pCVar2 < 0) {
            pCVar2 = (CString *)(((uint)(pCVar2 + -1) | 0xfffffffc) + 1);
          }
          CString::Format(pCVar2,&DAT_0041ec10);
          DAT_0041effc = 1;
          if (0x1e < (int)uVar6) {
            local_3c = 0;
            break;
          }
          if ((local_3c == 0) || ((DAT_0041f004 & 0x80) != 0)) break;
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
    CString::operator=((CString *)&DAT_0041ec10,s_Testing___done_004196d4);
    uVar6 = 1;
    _DAT_00418538 = 0;
    piVar7 = &DAT_0041ee18;
    do {
      LVar3 = SendMessageA(*(HWND *)(*piVar7 + 0x20),0xf0,0,0);
      if (LVar3 != 0) {
        _DAT_00418538 = _DAT_00418538 | uVar6;
      }
      piVar7 = piVar7 + 1;
      uVar6 = uVar6 << 1;
    } while ((int)piVar7 < 0x41ee38);
    _DAT_0041ec34 = 10;
    _DAT_0041ec38 = 0xdc;
    _DAT_0041ec3c = 4;
    _DAT_0041ec24 = 0;
    if (local_3c == 0) {
      pcVar10 = &DAT_004196c4;
      _DAT_0041ec14 = 0xff;
      DAT_0041ec30 = 0xff;
    }
    else {
      pcVar10 = &DAT_004196cc;
      _DAT_0041ec14 = 0xff00;
      DAT_0041ec30 = 0xff00;
    }
    pCVar2 = CString::operator=((CString *)&DAT_0041ec2c,pcVar10);
    _DAT_0041ec3c = 9;
    DAT_0041effc = 1;
    CString::~CString(local_34);
    this = (CString *)&local_30;
  }
  else {
    pCVar2 = (CString *)FUN_004015f0(&DAT_0041d180,DVar8);
    if ((int)pCVar2 < 0x29) goto LAB_0040dfde;
    local_14 = 1;
    local_13 = 0xe;
    local_12 = 0x18;
    local_11 = 0x12;
    local_10 = (CString)0x23;
    local_f = 0;
    local_e = 0;
    local_d = 0;
    local_c = (void *)0x0;
    FUN_004026f0(&DAT_0041d180,DVar8,&local_14,local_2c,5);
    CString::CString((CString *)&local_3c);
    CString::CString(local_34);
    iVar1 = 0;
    bStack_2a = 0;
    local_40 = (int *)0x2f7c5c2d;
    if ((DAT_0041f004 & 0x80) == 0) {
      while ((bStack_2a & 2) == 0) {
        puVar9 = local_2c;
        local_13 = 0xf;
        bStack_2a = 0xff;
        FUN_004026f0(&DAT_0041d180,DVar8,&local_14,puVar9,5);
        Sleep((DWORD)puVar9);
        iVar1 = iVar1 + 1;
        CString::Format((CString *)(uStack_2e & 0xff),&DAT_0041ec10);
        DAT_0041effc = 1;
        if ((0x1e < iVar1) || ((DAT_0041f004 & 0x80) != 0)) break;
      }
    }
    CString::operator=((CString *)&DAT_0041ec10,s_Testing___done_004196d4);
    local_30 = 0;
    uStack_2e = 0;
    local_48 = 0;
    uVar6 = 1;
    _DAT_00418538 = 0;
    piVar7 = &DAT_0041ee18;
    do {
      LVar3 = SendMessageA(*(HWND *)(*piVar7 + 0x20),0xf0,0,0);
      if (LVar3 != 0) {
        _DAT_00418538 = _DAT_00418538 | uVar6;
      }
      piVar7 = piVar7 + 1;
      uVar6 = uVar6 << 1;
    } while ((int)piVar7 < 0x41ee38);
    iVar1 = FUN_004015f0(&DAT_0041d180,DVar8);
    if (iVar1 < 0x33) {
      iVar1 = CONCAT22(uStack_2e,local_30);
    }
    else {
      local_48 = uStack_28 & 0xff & _DAT_00418538;
      iVar1 = 1;
      _DAT_0041ec34 = 10;
      _DAT_0041ec38 = 0xdc;
      _DAT_0041ec3c = 4;
      _DAT_0041ec24 = 0;
      CString::operator=((CString *)&DAT_0041ec2c,s_Button_s_______004196a4);
      if ((_DAT_00418538 & 1) != 0) {
        if ((local_48 & 1) == 0) {
          pcVar10 = s_Button_s___L_O__00419684;
        }
        else {
          pcVar10 = s_Button_s___L_X__00419694;
        }
        CString::operator=((CString *)&DAT_0041ec2c,pcVar10);
      }
      if ((_DAT_00418538 & 2) == 0) {
        pcVar10 = s_______0041966c;
      }
      else if ((local_48 & 2) == 0) {
        pcVar10 = s___R_O__00419674;
      }
      else {
        pcVar10 = s___R_X__0041967c;
      }
      CString::operator+=((CString *)&DAT_0041ec2c,pcVar10);
      if ((_DAT_00418538 & 4) == 0) {
        pcVar10 = s_______0041966c;
      }
      else if ((local_48 & 4) == 0) {
        pcVar10 = s___M_O__0041965c;
      }
      else {
        pcVar10 = s___M_X__00419664;
      }
      CString::operator+=((CString *)&DAT_0041ec2c,pcVar10);
      if ((_DAT_00418538 & 8) == 0) {
        pcVar10 = s_______0041966c;
      }
      else if ((local_48 & 8) == 0) {
        pcVar10 = s___4_O__0041964c;
      }
      else {
        pcVar10 = s___4_X__00419654;
      }
      CString::operator+=((CString *)&DAT_0041ec2c,pcVar10);
      if ((_DAT_00418538 & 0x10) == 0) {
        pcVar10 = s_______0041966c;
      }
      else if ((local_48 & 0x10) == 0) {
        pcVar10 = s___5_O__0041963c;
      }
      else {
        pcVar10 = s___5_X__00419644;
      }
      CString::operator+=((CString *)&DAT_0041ec2c,pcVar10);
      if ((_DAT_00418538 & 0x20) == 0) {
        pcVar10 = s_______0041966c;
      }
      else if ((local_48 & 0x20) == 0) {
        pcVar10 = s___TL_O__00419624;
      }
      else {
        pcVar10 = s___TL_X__00419630;
      }
      CString::operator+=((CString *)&DAT_0041ec2c,pcVar10);
      if ((_DAT_00418538 & 0x40) == 0) {
        pcVar10 = s_______0041966c;
      }
      else if ((local_48 & 0x40) == 0) {
        pcVar10 = s___TR_O__0041960c;
      }
      else {
        pcVar10 = s___TR_X__00419618;
      }
      CString::operator+=((CString *)&DAT_0041ec2c,pcVar10);
      if ((_DAT_00418538 & 0x80) == 0) {
        CString::operator+=((CString *)&DAT_0041ec2c,s_______0041966c);
      }
      else if ((local_48 & 0x80) == 0) {
        CString::operator+=((CString *)&DAT_0041ec2c,s___DPI_O__004195f4);
      }
      else {
        CString::operator+=((CString *)&DAT_0041ec2c,s___DPI_X__00419600);
      }
    }
    iVar4 = iVar1 * 0x1c;
    *(undefined4 *)(&DAT_0041ec34 + iVar4) = 10;
    *(int *)(&DAT_0041ec38 + iVar4) = iVar1 * 0x1e + 0xdc;
    *(undefined4 *)(&DAT_0041ec3c + iVar4) = 4;
    *(undefined4 *)(&DAT_0041ec24 + iVar4) = 0;
    if (local_48 == 0) {
      *(undefined4 *)(&DAT_0041ec14 + iVar4) = 0xff00;
    }
    else {
      *(undefined4 *)(&DAT_0041ec14 + iVar4) = 0xff;
    }
    if (((bStack_2a & 2) == 0) || (local_48 != 0)) {
      _DAT_0041ec14 = 0xff;
      (&DAT_0041ec30)[iVar1 * 7] = 0xff;
      pcVar10 = &DAT_004196c4;
    }
    else {
      _DAT_0041ec14 = 0xff00;
      (&DAT_0041ec30)[iVar1 * 7] = 0xff00;
      pcVar10 = &DAT_004196cc;
    }
    CString::operator=((CString *)(&DAT_0041ec2c + iVar4),pcVar10);
    *(undefined4 *)(&DAT_0041ec3c + iVar4) = 9;
    local_13 = 0xe;
    local_12 = 0x16;
    pCVar2 = (CString *)FUN_004026f0(&DAT_0041d180,DVar8,&local_14,local_2c,5);
    DAT_0041effc = 1;
    CString::~CString(local_34);
    this = (CString *)&local_3c;
  }
  CString::~CString(this);
LAB_0040dfde:
  CString::~CString(local_44);
  CString::~CString(aCStack_38);
  ExceptionList = puStack_8;
  return pCVar2;
}



/* ==== FUN_0040e010 @ 0040e010 ==== */

BOOL FUN_0040e010(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  HDC hdc;
  int iVar3;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  char *hdc_00;
  CString aCStack_28 [4];
  int *piStack_24;
  HDC pHStack_20;
  LPCSTR pCStack_1c;
  int aiStack_18 [2];
  int iStack_10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  pvVar1 = ExceptionList;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004146e0;
  local_c = ExceptionList;
  puVar2 = &DAT_0041deb0;
  ExceptionList = &local_c;
  do {
    *puVar2 = 1;
    puVar2 = puVar2 + 0xe;
  } while ((int)puVar2 < 0x41e0e0);
  iVar6 = 0;
  if (DAT_0041eff8 == 0) {
    hdc = CreateCompatibleDC((HDC)0x0);
    pHStack_20 = hdc;
    SelectObject(hdc,DAT_0041f048);
    iVar5 = *(int *)(DAT_00418544 * 0x38 + 0x41d5d4);
    aiStack_18[0] = (&DAT_0041d608)[DAT_00418544 * 0xe] + 0x14;
    CString::CString(aCStack_28);
    uStack_4 = 0;
    iVar3 = FUN_004026e0(0x41d180);
    if (0 < iVar3) {
      puVar2 = &DAT_0041ded4;
      piStack_24 = &DAT_0041d598;
      do {
        if (*piStack_24 == 3) {
          FUN_00401610(&DAT_0041d180,(CString *)&pCStack_1c,iVar6);
          uStack_4 = CONCAT31(uStack_4._1_3_,1);
          FUN_004015f0(&DAT_0041d180,iVar6);
          hdc_00 = s___Upgrade_able_Device___d__click_0041972c;
          CString::Format(aCStack_28,(char *)aCStack_28);
          CString::~CString((CString *)aiStack_18);
          GetTextExtentPointA((HDC)hdc_00,pCStack_1c,(int)piStack_24,(LPSIZE)piStack_24[-2]);
          CString::operator=((CString *)(puVar2 + -6),aCStack_28);
          *puVar2 = 0x15;
          puVar2[-1] = 5;
          puVar2[-3] = aiStack_18[0];
          puVar2[-9] = 0;
          puVar2[-8] = iVar6;
          puVar2[-2] = (iVar5 - iStack_10) + -8;
          puVar2[-7] = 0x121212;
          puVar2[-4] = 0xffffff;
          iVar5 = puVar2[-2];
          puVar2 = puVar2 + 0xe;
        }
        piStack_24 = piStack_24 + 1;
        iVar6 = iVar6 + 1;
        iVar3 = FUN_004026e0(0x41d180);
        hdc = pHStack_20;
      } while (iVar6 < iVar3);
    }
    BVar4 = DeleteDC(hdc);
    uStack_4 = 0xffffffff;
    CString::~CString(aCStack_28);
    ExceptionList = local_c;
    return BVar4;
  }
  ExceptionList = pvVar1;
  return 0;
}



/* ==== FUN_0040e05b @ 0040e05b ==== */

void __cdecl
FUN_0040e05b(undefined4 param_1,int *param_2,HDC param_3,LPCSTR param_4,int param_5,
            undefined4 param_6,int param_7,void *param_8)

{
  HDC hdc;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  HDC unaff_EDI;
  char *hdc_00;
  
  hdc = CreateCompatibleDC(unaff_EDI);
  param_3 = hdc;
  SelectObject(hdc,DAT_0041f048);
  iVar2 = *(int *)(DAT_00418544 * 0x38 + 0x41d5d4);
  param_5 = (&DAT_0041d608)[DAT_00418544 * 0xe] + 0x14;
  CString::CString((CString *)&param_1);
  iVar1 = FUN_004026e0(0x41d180);
  if (0 < iVar1) {
    puVar3 = &DAT_0041ded4;
    param_2 = &DAT_0041d598;
    do {
      if (*param_2 == 3) {
        FUN_00401610(&DAT_0041d180,(CString *)&param_4,(int)unaff_EDI);
        FUN_004015f0(&DAT_0041d180,(int)unaff_EDI);
        hdc_00 = s___Upgrade_able_Device___d__click_0041972c;
        CString::Format((CString *)&param_1,(char *)&param_1);
        CString::~CString((CString *)&param_5);
        GetTextExtentPointA((HDC)hdc_00,param_4,(int)param_2,(LPSIZE)param_2[-2]);
        CString::operator=((CString *)(puVar3 + -6),(CString *)&param_1);
        *puVar3 = 0x15;
        puVar3[-1] = 5;
        puVar3[-3] = param_5;
        puVar3[-9] = 0;
        puVar3[-8] = unaff_EDI;
        puVar3[-2] = (iVar2 - param_7) + -8;
        puVar3[-7] = 0x121212;
        puVar3[-4] = 0xffffff;
        iVar2 = puVar3[-2];
        puVar3 = puVar3 + 0xe;
      }
      param_2 = param_2 + 1;
      unaff_EDI = (HDC)((int)&unaff_EDI->unused + 1);
      iVar1 = FUN_004026e0(0x41d180);
      hdc = param_3;
    } while ((int)unaff_EDI < iVar1);
  }
  DeleteDC(hdc);
  CString::~CString((CString *)&param_1);
  ExceptionList = param_8;
  return;
}



/* ==== FUN_0040e1d0 @ 0040e1d0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040e1d0(DWORD param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  ulong uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  CString *this;
  CString *this_00;
  tagOFNA *ptVar8;
  int iVar9;
  DWORD dwMilliseconds;
  undefined *puVar10;
  undefined uStack_584;
  undefined uStack_583;
  undefined uStack_582;
  undefined uStack_581;
  CString CStack_580;
  undefined4 uStack_57c;
  undefined uStack_578;
  char cStack_575;
  undefined4 uStack_574;
  undefined4 uStack_570;
  int iStack_56c;
  undefined4 uStack_568;
  undefined auStack_564 [2];
  char cStack_562;
  undefined uStack_561;
  undefined auStack_558 [4];
  char cStack_554;
  char cStack_553;
  char cStack_552;
  CString aCStack_550 [4];
  CString CStack_54c;
  undefined uStack_54b;
  int iStack_548;
  CString aCStack_544 [4];
  uint uStack_540;
  CString aCStack_53c [4];
  CString aCStack_538 [4];
  CString CStack_534;
  undefined uStack_533;
  undefined uStack_532;
  undefined uStack_531;
  CString CStack_530;
  byte bStack_52f;
  byte bStack_52e;
  byte bStack_52d;
  CFile aCStack_528 [16];
  char *local_518;
  char *local_514;
  CString local_510 [4];
  CWnd *local_50c;
  double dStack_508;
  char *local_500;
  char *local_4fc;
  CString local_4f8 [4];
  CString local_4f4 [4];
  undefined **appuStack_4f0 [2];
  undefined4 uStack_4e8;
  undefined4 uStack_4e4;
  CString aCStack_4e0 [4];
  CString local_4dc [4];
  CString local_4d8 [4];
  CString local_4d4 [4];
  CString local_4d0 [4];
  CString local_4cc [4];
  CString local_4c8 [4];
  undefined auStack_4c4 [3];
  uint uStack_4c1;
  undefined uStack_4b8;
  undefined uStack_4b7;
  undefined uStack_4b6;
  int iStack_4ac;
  undefined4 uStack_4a8;
  tagOFNA local_4a4;
  undefined auStack_44c [12];
  CString aCStack_440 [52];
  char local_40c;
  undefined4 local_40b;
  void *pvStack_c;
  undefined *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00414824;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  CString::CString(local_4dc,s_Erase_00419948);
  local_4 = 0;
  CString::CString(local_4c8,s_Programming_0041993c);
  local_4._0_1_ = 1;
  CString::CString(local_4d0,s_Completed____0041992c);
  local_4._0_1_ = 2;
  CString::CString((CString *)&local_518,s_Upgrade_Tool_0041991c);
  local_4._0_1_ = 3;
  CString::CString(local_4d4,s_device_not_found_____Please_pres_004198d0);
  local_4._0_1_ = 4;
  CString::CString(local_4cc,s_Upgrade_004198c8);
  local_4._0_1_ = 5;
  CString::CString(local_4d8,&DAT_004198c0);
  local_4._0_1_ = 6;
  CString::CString(local_510,s_Name____s_004198b4);
  local_4._0_1_ = 7;
  CString::CString(local_4f4,s_Ver___v_d__d_004198a4);
  local_4._0_1_ = 8;
  CString::CString(local_4f8,(ushort *)u_Current_Ver___v_d__d_00419878);
  local_4._0_1_ = 9;
  CString::CString((CString *)&local_500,s_Bad_format____00419868);
  local_4._0_1_ = 10;
  CString::CString((CString *)&local_514,s_Completed____Please_re_plugin_th_00419840);
  local_4 = CONCAT31(local_4._1_3_,0xb);
  CString::CString((CString *)&local_4fc,s_Upgrade_error__00419830);
  local_40c = '\0';
  puVar3 = &local_40b;
  for (iVar7 = 0xff; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined *)((int)puVar3 + 2) = 0;
  local_4._0_1_ = 0xc;
  ptVar8 = &local_4a4;
  for (iVar7 = 0x16; iVar7 != 0; iVar7 = iVar7 + -1) {
    ptVar8->lStructSize = 0;
    ptVar8 = (tagOFNA *)&ptVar8->hwndOwner;
  }
  local_4a4.lpstrFile = &local_40c;
  local_4a4.lStructSize = 0x58;
  local_4a4.hwndOwner = (HWND)0x0;
  local_4a4.nMaxFile = 0x3fe;
  local_4a4.lpstrFilter = s_Firmware____bin__00419818;
  local_4a4.nFilterIndex = 1;
  local_4a4.lpstrFileTitle = (LPSTR)0x0;
  local_4a4.nMaxFileTitle = 0;
  local_4a4.lpstrInitialDir = (LPCSTR)0x0;
  local_4a4.Flags = 0x801802;
  BVar1 = GetOpenFileNameA(&local_4a4);
  if (BVar1 == 1) {
    CFile::CFile(aCStack_528);
    local_4._0_1_ = 0xd;
    CException::CException((CException *)appuStack_4f0);
    local_4._0_1_ = 0xe;
    CString::CString(aCStack_4e0);
    local_4._0_1_ = 0xf;
    appuStack_4f0[0] = &PTR_LAB_00415b70;
    uStack_4e8 = 0;
    uStack_4e4 = 0xffffffff;
    CString::operator=(aCStack_4e0,(char *)0x0);
    local_4._0_1_ = 0x10;
    iVar7 = CFile::Open(aCStack_528,local_4a4.lpstrFile,0x8000,(CFileException *)appuStack_4f0);
    if (iVar7 != 0) {
      iStack_548 = 0;
      CFile::Read(aCStack_528,&cStack_554,3);
      if (((cStack_554 == 'A') && (cStack_553 == 'R')) && (cStack_552 == 'E')) {
        CFile::Read(aCStack_528,aCStack_440,0x31);
        CFile::Read(aCStack_528,(void *)((int)&uStack_57c + 2),1);
        CFile::Read(aCStack_528,auStack_558,3);
        CString::CString(aCStack_544);
        local_4._0_1_ = 0x11;
        CString::CString(&CStack_54c);
        local_4._0_1_ = 0x12;
        uStack_578 = 0;
        uStack_570 = uStack_570 & 0xffffff00;
        uStack_57c = uStack_57c & 0xffffff;
        uStack_584 = 1;
        uStack_583 = 0x12;
        uStack_582 = 7;
        uStack_581 = 1;
        FUN_004026f0(&DAT_0041d180,param_1,&uStack_584,auStack_564,10);
        uStack_584 = 1;
        uStack_583 = 0x12;
        uStack_582 = 7;
        uStack_581 = 2;
        FUN_004026f0(&DAT_0041d180,param_1,&uStack_584,auStack_564,10);
        if (cStack_562 == '\x10') {
          uStack_570 = CONCAT31(uStack_570._1_3_,uStack_561);
        }
        uStack_584 = 1;
        uStack_583 = 0x12;
        uStack_582 = 7;
        uStack_581 = 3;
        FUN_004026f0(&DAT_0041d180,param_1,&uStack_584,auStack_564,10);
        if (cStack_562 == '\x10') {
          uStack_57c = CONCAT13(uStack_561,(undefined3)uStack_57c);
        }
        uStack_584 = 1;
        uStack_583 = 0x12;
        uStack_582 = 7;
        uStack_581 = 4;
        FUN_004026f0(&DAT_0041d180,param_1,&uStack_584,auStack_564,10);
        if (cStack_562 == '\x10') {
          uStack_578 = uStack_561;
        }
        CString::CString(aCStack_550);
        local_4._0_1_ = 0x13;
        CString::Format(aCStack_440,(char *)aCStack_544);
        if ((char)uStack_574 == -1) {
          uStack_574 = uStack_574 & 0xffffff00;
        }
        CString::Format((CString *)&iStack_548,(char *)&iStack_548);
        CString::Format(this,(char *)&iStack_548);
        uStack_568._0_3_ = CONCAT12(CStack_54c,(undefined2)uStack_568);
        auStack_564[0] = uStack_54b;
        iStack_56c = CONCAT31(iStack_56c._1_3_,uStack_570._2_1_);
        operator+(&local_4fc,aCStack_538);
        uVar2 = operator+();
        puVar10 = &DAT_0041980c;
        uVar2 = operator+(&uStack_568,uVar2);
        local_4 = CONCAT31(local_4._1_3_,0x16);
        puVar3 = (undefined4 *)operator+(&uStack_568,uVar2);
        puStack_8._0_1_ = 0x17;
        iVar7 = AfxMessageBox((char *)*puVar3,4,0);
        cStack_575 = iVar7 == 6;
        puStack_8._0_1_ = 0x16;
        CString::~CString((CString *)&iStack_56c);
        puStack_8._0_1_ = 0x15;
        CString::~CString((CString *)&uStack_570);
        puStack_8._0_1_ = 0x14;
        CString::~CString(aCStack_53c);
        puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,0x13);
        CString::~CString((CString *)&local_50c);
        if (cStack_575 != '\0') {
          DAT_0041ebe0 = 10;
          DAT_0041ebe4 = 0xa0;
          DAT_0041ebdc = 0xffff;
          DAT_0041ebe8 = 4;
          DAT_0041ebd0 = 0;
          CString::Format((CString *)(uStack_57c & 0xff),&DAT_0041ebd8);
          DAT_0041effc = 1;
          _DAT_0041ebfc = 10;
          _DAT_0041ec00 = 0xbe;
          _DAT_0041ebf8 = 0xffff;
          _DAT_0041ec04 = 4;
          DAT_0041ebec = 0;
          CString::operator=((CString *)&DAT_0041ebf4,&DAT_00419e94);
          iVar7 = FUN_0040eea0(param_1,(int)puVar10);
          if (iVar7 == 1) {
            CString::operator=((CString *)&DAT_0041ebf4,s_Erase_device___100_00____done_004197c0);
            _DAT_0041ebf8 = 0xff00;
          }
          else {
            CString::operator+=((CString *)&DAT_0041ebf4,s____fail_004197b8);
            _DAT_0041ebf8 = 0xff;
          }
          DAT_0041effc = 1;
          if (iVar7 == 1) {
            _DAT_0041ec18 = 10;
            _DAT_0041ec1c = 0xdc;
            _DAT_0041ec14 = 0xffff;
            _DAT_0041ec20 = 4;
            DAT_0041ec08 = 0;
            CString::operator=((CString *)&DAT_0041ec10,s_Writing___0_00__004197a8);
            uVar4 = CFile::GetLength(aCStack_528);
            DAT_0041effc = 1;
            iVar7 = uVar4 - 0x38;
            if (0x3000 < iVar7) {
              iVar7 = 0x3000;
            }
            iStack_56c = 0;
            if (0 < iVar7) {
              do {
                iVar9 = 0;
                CFile::Read(aCStack_528,&uStack_540,2);
                dStack_508 = (double)CONCAT44(dStack_508._4_4_,iStack_548 >> 8);
                iVar5 = iStack_548 >> 8;
                while( true ) {
                  uStack_531 = (undefined)iVar5;
                  CStack_530 = iStack_548._0_1_;
                  bStack_52e = (byte)(uStack_540 >> 8);
                  bStack_52f = (byte)uStack_540;
                  bStack_52d = bStack_52e ^ bStack_52f;
                  CStack_534 = (CString)0x1;
                  uStack_533 = 0x12;
                  uStack_532 = 0x88;
                  FUN_004026f0(&DAT_0041d180,param_1,&CStack_534,auStack_4c4,0x14);
                  if (((char)uStack_4c1 == (char)(uStack_540 >> 8)) &&
                     ((char)(uStack_4c1 >> 8) == (char)uStack_540)) break;
                  CString::CString((CString *)&uStack_568);
                  dwMilliseconds = uStack_540 >> 8 & 0xff;
                  local_4._0_1_ = 0x18;
                  CString::Format((CString *)(uStack_4c1 & 0xff),(char *)&uStack_568);
                  Sleep(dwMilliseconds);
                  iVar9 = iVar9 + 1;
                  if (10 < iVar9) {
                    CFile::Close(aCStack_528);
                    CWnd::MessageBoxA(local_50c,local_4fc,local_518,0);
                    local_4._0_1_ = 0x13;
                    CString::~CString((CString *)&uStack_568);
                    local_4._0_1_ = 0x12;
                    CString::~CString(aCStack_550);
                    local_4._0_1_ = 0x11;
                    CString::~CString(&CStack_54c);
                    local_4._0_1_ = 0x10;
                    CString::~CString(aCStack_544);
                    appuStack_4f0[0] = &PTR_LAB_00415b70;
                    local_4._0_1_ = 0x19;
                    CString::~CString(aCStack_4e0);
                    appuStack_4f0[0] = &PTR_LAB_004154b0;
                    local_4._0_1_ = 0xc;
                    CFile::~CFile(aCStack_528);
                    goto LAB_0040ecc0;
                  }
                  local_4 = CONCAT31(local_4._1_3_,0x13);
                  CString::~CString((CString *)&uStack_568);
                  iVar5 = dStack_508._0_4_;
                }
                iStack_548 = iStack_548 + 2;
                CString::CString(aCStack_538);
                dStack_508 = (double)iStack_56c;
                local_4 = CONCAT31(local_4._1_3_,0x1a);
                uVar4 = CFile::GetLength(aCStack_528);
                iStack_4ac = uVar4 - 2;
                uStack_4a8 = 0;
                CString::Format(this_00,&DAT_0041ec10);
                DAT_0041effc = 1;
                CString::~CString(&CStack_534);
                uStack_568 = uStack_568 + 2;
              } while (uStack_568 < iVar7);
            }
            CString::operator=((CString *)&DAT_0041ec10,s_Writing___100_00____done_00419760);
            _DAT_0041ec14 = 0xff00;
            DAT_0041effc = 1;
            uStack_584 = 1;
            uStack_583 = 0x12;
            uStack_582 = 0x87;
            uStack_581 = 1;
            CStack_580 = (CString)uStack_574._2_1_;
            FUN_004026f0(&DAT_0041d180,param_1,&uStack_584,auStack_564,10);
            uStack_584 = 1;
            uStack_583 = 0x12;
            uStack_582 = 0x87;
            uStack_581 = 2;
            CStack_580 = uStack_570._0_1_;
            FUN_004026f0(&DAT_0041d180,param_1,&uStack_584,auStack_564,10);
            uStack_584 = 1;
            uStack_583 = 0x12;
            uStack_582 = 0x87;
            uStack_581 = 3;
            CStack_580 = (CString)uStack_57c._3_1_;
            FUN_004026f0(&DAT_0041d180,param_1,&uStack_584,auStack_564,10);
            uStack_584 = 1;
            uStack_583 = 0x12;
            uStack_582 = 0x87;
            uStack_581 = 4;
            CStack_580 = (CString)uStack_578;
            FUN_004026f0(&DAT_0041d180,param_1,&uStack_584,auStack_564,10);
            uStack_4b8 = 1;
            uStack_4b7 = 0x12;
            uStack_4b6 = 6;
            FUN_004026f0(&DAT_0041d180,param_1,&uStack_4b8,auStack_44c,5);
            AfxMessageBox(local_514,0,0);
          }
        }
        local_4._0_1_ = 0x12;
        CString::~CString(aCStack_550);
        local_4._0_1_ = 0x11;
        CString::~CString(&CStack_54c);
        local_4._0_1_ = 0x10;
        CString::~CString(aCStack_544);
      }
      else {
        AfxMessageBox(local_500,0,0);
      }
      CFile::Close(aCStack_528);
    }
    appuStack_4f0[0] = &PTR_LAB_00415b70;
    local_4._0_1_ = 0x1b;
    CString::~CString(aCStack_4e0);
    appuStack_4f0[0] = &PTR_LAB_004154b0;
    local_4._0_1_ = 0xc;
    CFile::~CFile(aCStack_528);
  }
LAB_0040ecc0:
  piVar6 = &DAT_0041ebd0;
  do {
    if (*piVar6 == 0) {
      *piVar6 = 1;
    }
    piVar6 = piVar6 + 7;
  } while ((int)piVar6 < 0x41ee00);
  DAT_0041effc = 1;
  local_4._0_1_ = 0xb;
  CString::~CString((CString *)&local_4fc);
  local_4._0_1_ = 10;
  CString::~CString((CString *)&local_514);
  local_4._0_1_ = 9;
  CString::~CString((CString *)&local_500);
  local_4._0_1_ = 8;
  CString::~CString(local_4f8);
  local_4._0_1_ = 7;
  CString::~CString(local_4f4);
  local_4._0_1_ = 6;
  CString::~CString(local_510);
  local_4._0_1_ = 5;
  CString::~CString(local_4d8);
  local_4._0_1_ = 4;
  CString::~CString(local_4cc);
  local_4._0_1_ = 3;
  CString::~CString(local_4d4);
  local_4._0_1_ = 2;
  CString::~CString((CString *)&local_518);
  local_4._0_1_ = 1;
  CString::~CString(local_4d0);
  local_4 = (uint)local_4._1_3_ << 8;
  CString::~CString(local_4c8);
  local_4 = 0xffffffff;
  CString::~CString(local_4dc);
  ExceptionList = pvStack_c;
  return;
}



/* ==== FUN_0040ee00 @ 0040ee00 ==== */

undefined4 * __thiscall FUN_0040ee00(void *this,byte param_1)

{
  FUN_0040ee20((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



/* ==== FUN_0040ee20 @ 0040ee20 ==== */

void __fastcall FUN_0040ee20(undefined4 *param_1)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00414838;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_00415b70;
  local_4 = 0;
  CString::~CString((CString *)(param_1 + 4));
  *param_1 = &PTR_LAB_004154b0;
  ExceptionList = local_c;
  return;
}



/* ==== FUN_0040ee80 @ 0040ee80 ==== */

CButton * __thiscall FUN_0040ee80(void *this,byte param_1)

{
  CButton::~CButton((CButton *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CButton *)this;
}



/* ==== FUN_0040eea0 @ 0040eea0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040eea0(DWORD param_1,int param_2)

{
  char cVar1;
  CString *extraout_ECX;
  CString *this;
  CString *extraout_ECX_00;
  CString *extraout_ECX_01;
  int iVar2;
  undefined local_24;
  undefined uStack_23;
  undefined uStack_22;
  undefined uStack_21;
  undefined local_20 [3];
  undefined local_1d;
  undefined local_1c [3];
  undefined local_19;
  undefined local_18;
  undefined local_14 [2];
  char local_12;
  undefined local_10 [2];
  char local_e;
  undefined local_c [12];
  
  local_24 = 1;
  uStack_23 = 0x12;
  uStack_22 = 0x87;
  uStack_21 = 0;
  local_20[0] = 0x18;
  FUN_004026f0(&DAT_0041d180,param_1,&local_24,local_c,4);
  uStack_23 = 0x12;
  iVar2 = 0;
  local_24 = 1;
  uStack_22 = 9;
  this = extraout_ECX;
  do {
    CString::Format(this,&DAT_0041ebf4);
    local_1d = (undefined)((uint)iVar2 >> 8);
    DAT_0041effc = 1;
    local_1c[0] = (char)iVar2;
    FUN_004026f0(&DAT_0041d180,param_1,local_20,local_14,4);
    this = extraout_ECX_00;
    cVar1 = local_12;
    while (cVar1 != '\x10') {
      param_2 = param_2 + 1;
      if (6 < param_2) {
        return 0;
      }
      CString::Format(this,&DAT_0041ebf4);
      local_19 = local_24;
      DAT_0041effc = 1;
      local_18 = (char)iVar2;
      FUN_004026f0(&DAT_0041d180,param_1,local_1c,local_10,4);
      this = extraout_ECX_01;
      cVar1 = local_e;
    }
    iVar2 = iVar2 + 0x80;
  } while (iVar2 < 0x3000);
  return 1;
}



/* ==== FUN_0040eff0 @ 0040eff0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0040eff0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  CString local_48 [4];
  int local_44 [3];
  int local_38;
  undefined local_34 [20];
  undefined local_20;
  undefined local_1f;
  uint local_1e;
  undefined4 local_1a;
  undefined4 local_16;
  undefined4 local_12;
  undefined2 local_e;
  void *pvStack_c;
  undefined *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00414858;
  pvStack_c = ExceptionList;
  local_44[2] = DAT_0041a220;
  iVar1 = 0;
  local_38 = DAT_0041a224 + -0x28;
  _DAT_0041d740 = 1;
  local_44[0] = 0;
  local_44[1] = 0x5a;
  ExceptionList = &pvStack_c;
  FUN_004094b0(this,local_44);
  puVar2 = &DAT_0041ee18;
  do {
    CWnd::ShowWindow((CWnd *)*puVar2,0);
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x41ee6c);
  local_20 = 0;
  local_1a = 0;
  local_1f = 0;
  local_16 = 0;
  local_12 = 0;
  local_e = 0;
  local_1e = 0x121802;
  CString::CString(local_48);
  local_4 = 0;
  local_34[0] = 0;
  local_34[1] = 1;
  local_34[2] = 2;
  local_34[3] = 3;
  local_34[4] = 4;
  local_34[5] = 5;
  local_34[6] = 6;
  local_34[7] = 7;
  local_34[8] = 8;
  local_34[9] = 9;
  local_34[10] = 0x11;
  local_34[0xb] = 0x12;
  local_34[0xc] = 0x13;
  local_34[0xd] = 0x14;
  local_34[0xe] = 0x15;
  local_34[0xf] = 0x16;
  local_34[0x10] = 0x17;
  uVar3 = 0x78;
  puVar2 = &DAT_0041ebe0;
  do {
    FUN_00401480(&DAT_0041d180,param_1,6,local_34[iVar1],&local_20);
    CString::Format((CString *)(local_1e & 0xff),(char *)local_48);
    CString::operator=((CString *)(puVar2 + -2),(CString *)local_44);
    *puVar2 = 10;
    puVar2[1] = uVar3;
    puVar2[-1] = 0xffff;
    puVar2[2] = 5;
    puVar2[-4] = 0;
    uVar3 = uVar3 + 0x16;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 7;
    DAT_0041effc = 1;
  } while (uVar3 < 0x1ee);
  DAT_0041efdc = 1;
  CString::~CString((CString *)local_44);
  ExceptionList = local_8;
  return;
}



/* ==== FUN_0040f1b0 @ 0040f1b0 ==== */

BOOL FUN_0040f1b0(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  HDC hdc;
  int iVar3;
  CString *pCVar4;
  BOOL BVar5;
  HDC pHVar6;
  int *piVar7;
  int iVar8;
  wchar_t *pwVar9;
  CString *pCStack_4c;
  CString aCStack_48 [4];
  LPCSTR pCStack_44;
  undefined4 uStack_40;
  HDC pHStack_3c;
  HDC pHStack_38;
  HDC pHStack_34;
  int iStack_30;
  int iStack_2c;
  undefined8 uStack_28;
  CString aCStack_20 [4];
  CString aCStack_1c [4];
  CString aCStack_18 [4];
  CString aCStack_14 [4];
  CString aCStack_10 [4];
  void *local_c;
  undefined *puStack_8;
  int iStack_4;
  
  pvVar1 = ExceptionList;
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_004148b8;
  local_c = ExceptionList;
  puVar2 = &DAT_0041deb0;
  ExceptionList = &local_c;
  do {
    *puVar2 = 1;
    puVar2 = puVar2 + 0xe;
  } while ((int)puVar2 < 0x41e0e0);
  iVar8 = 0;
  if (DAT_0041eff8 == 0) {
    hdc = CreateCompatibleDC((HDC)0x0);
    pHStack_38 = hdc;
    SelectObject(hdc,DAT_0041f048);
    iStack_30 = (&DAT_0041d608)[DAT_00418544 * 0xe] + 0x14;
    uStack_40 = *(undefined4 *)(DAT_00418544 * 0x38 + 0x41d5d4);
    CString::CString((CString *)((int)&uStack_28 + 4),s_PixArt_3601_00418e30);
    iStack_4 = 0;
    CString::CString(aCStack_20,s_Avago_3080_00418e24);
    iStack_4._0_1_ = 1;
    CString::CString(aCStack_1c,s_Avago_6010_00418e18);
    iStack_4._0_1_ = 2;
    CString::CString(aCStack_18,s_Avago_7010_00418e0c);
    iStack_4._0_1_ = 3;
    CString::CString(aCStack_14,s_Avago_6090_00418e00);
    iStack_4._0_1_ = 4;
    CString::CString(aCStack_10,s_Philips_PLN2030_00418df0);
    iStack_4._0_1_ = 5;
    CString::CString((CString *)&pCStack_4c);
    iStack_4._0_1_ = 6;
    CString::CString(aCStack_48);
    iStack_4._0_1_ = 7;
    CString::CString((CString *)&pCStack_44,(ushort *)u___d_Model___s___Ver___d__d___Sen_00418d94);
    iStack_4 = CONCAT31(iStack_4._1_3_,8);
    iVar3 = FUN_004026e0(0x41d180);
    if (0 < iVar3) {
      pHVar6 = (HDC)&DAT_0041d548;
      piVar7 = &DAT_0041ded4;
      pHStack_3c = (HDC)&DAT_0041d548;
      do {
        if (pHVar6[0x14].unused == 2) {
          CString::operator=((CString *)&pCStack_44,
                             (ushort *)u____2d_Gaming___s___Ver___d__d___S_004199a8);
          iVar3 = FUN_004015f0(&DAT_0041d180,iVar8);
          if (iVar3 == 0xe) {
            pwVar9 = u_B115G_00418d28;
          }
          else {
            iVar3 = FUN_004015f0(&DAT_0041d180,iVar8);
            if (iVar3 == 0xf) {
              pwVar9 = u_FD3B___Sonix_0041998c;
            }
            else {
              iVar3 = FUN_004015f0(&DAT_0041d180,iVar8);
              if (iVar3 == 0x10) {
                pwVar9 = (wchar_t *)&DAT_00419984;
              }
              else {
                iVar3 = FUN_004015f0(&DAT_0041d180,iVar8);
                if (iVar3 == 0x11) {
                  pwVar9 = (wchar_t *)&DAT_0041997c;
                }
                else {
                  iVar3 = FUN_004015f0(&DAT_0041d180,iVar8);
                  if (iVar3 == 0x12) {
                    pwVar9 = u_L191G_00418ce8;
                  }
                  else {
                    pwVar9 = u_Unknow_00418cd8;
                  }
                }
              }
            }
          }
          CString::operator=((CString *)&pCStack_4c,(ushort *)pwVar9);
          pCVar4 = FUN_00401610(&DAT_0041d180,(CString *)&pHStack_34,iVar8);
          iVar3 = _mbscmp(*(uchar **)pCVar4,&DAT_00418080);
          CString::~CString((CString *)&pHStack_34);
          if (iVar3 == 0) {
            CString::operator=((CString *)&pCStack_4c,(ushort *)&DAT_00418b20);
          }
          iVar3 = pHVar6->unused;
          if (5 < iVar3) {
            iVar3 = 5;
          }
          if (((0 < *(int *)(pCStack_4c + -8)) && (*pCStack_4c == (CString)0x4c)) && (iVar3 == 1)) {
            CString::SetAt((CString *)&pCStack_4c,0,'B');
          }
          FUN_00401600(&DAT_0041d180,iVar8);
          FUN_00401200(&DAT_0041d180,iVar8);
          CString::Format(pCStack_4c,(char *)aCStack_48);
          GetTextExtentPointA(pHStack_34,pCStack_44,*(int *)(pCStack_44 + -8),(LPSIZE)&uStack_28);
          CString::operator=((CString *)(piVar7 + -6),(CString *)&pCStack_44);
          *piVar7 = DAT_00418544;
          piVar7[-1] = 5;
          piVar7[-3] = iStack_2c;
          piVar7[-9] = 0;
          piVar7[-8] = iVar8;
          piVar7[-2] = (int)pHStack_3c + (-8 - uStack_28._4_4_);
          piVar7[-7] = 0x121212;
          piVar7[-4] = 0xffffff;
          piVar7 = piVar7 + 0xe;
          pHVar6 = pHStack_38;
        }
        pHVar6 = pHVar6 + 1;
        iVar8 = iVar8 + 1;
        pHStack_3c = pHVar6;
        iVar3 = FUN_004026e0(0x41d180);
        hdc = pHStack_38;
      } while (iVar8 < iVar3);
    }
    BVar5 = DeleteDC(hdc);
    iStack_4._0_1_ = 7;
    CString::~CString((CString *)&pCStack_44);
    iStack_4._0_1_ = 6;
    CString::~CString(aCStack_48);
    iStack_4._0_1_ = 5;
    CString::~CString((CString *)&pCStack_4c);
    iStack_4._0_1_ = 4;
    CString::~CString(aCStack_10);
    iStack_4._0_1_ = 3;
    CString::~CString(aCStack_14);
    iStack_4._0_1_ = 2;
    CString::~CString(aCStack_18);
    iStack_4._0_1_ = 1;
    CString::~CString(aCStack_1c);
    iStack_4 = (uint)iStack_4._1_3_ << 8;
    CString::~CString(aCStack_20);
    iStack_4 = 0xffffffff;
    CString::~CString((CString *)((int)&uStack_28 + 4));
    ExceptionList = local_c;
    return BVar5;
  }
  ExceptionList = pvVar1;
  return 0;
}



/* ==== FUN_0040f570 @ 0040f570 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_0040f570(DWORD param_1)

{
  int iVar1;
  CString *pCVar2;
  LRESULT LVar3;
  CString *this;
  CString *this_00;
  CString *this_01;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  char cStack00000008;
  uint uStack0000000c;
  wchar_t *pwVar7;
  CString aCStack_38 [4];
  CString aCStack_34 [4];
  CString aCStack_30 [4];
  CString aCStack_2c [4];
  uint uStack_28;
  CString aCStack_24 [4];
  undefined auStack_20 [4];
  uint uStack_1c;
  byte abStack_18 [8];
  undefined uStack_10;
  undefined uStack_f;
  undefined uStack_e;
  byte bStack_d;
  undefined local_c;
  undefined uStack_b;
  undefined uStack_a;
  undefined uStack_9;
  undefined *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_004148f0;
  local_c = SUB41(ExceptionList,0);
  uStack_b = (undefined)((uint)ExceptionList >> 8);
  uStack_a = (undefined)((uint)ExceptionList >> 0x10);
  uStack_9 = (undefined)((uint)ExceptionList >> 0x18);
  if ((int)param_1 < 0) {
    return 0;
  }
  ExceptionList = &local_c;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0041a198);
  DAT_0041f008 = 0xfffffc19;
  CString::CString(aCStack_2c,(ushort *)u__s___Ver___d__d_00419a9c);
  pvStack_4 = (void *)0x0;
  CString::CString(aCStack_38);
  pvStack_4._0_1_ = 1;
  CString::CString(aCStack_34);
  pvStack_4 = (void *)CONCAT31(pvStack_4._1_3_,2);
  CString::Format(this,(char *)aCStack_34);
  iVar1 = FUN_004015f0(&DAT_0041d180,param_1);
  if (iVar1 == 0xe) {
    pwVar7 = u_B115G_00418d28;
  }
  else {
    iVar1 = FUN_004015f0(&DAT_0041d180,param_1);
    if (iVar1 == 0xf) {
      pwVar7 = u_FD3B___Sonix_0041998c;
    }
    else {
      iVar1 = FUN_004015f0(&DAT_0041d180,param_1);
      if (iVar1 == 0x10) {
        pwVar7 = (wchar_t *)&DAT_00419984;
      }
      else {
        iVar1 = FUN_004015f0(&DAT_0041d180,param_1);
        if (iVar1 == 0x11) {
          pwVar7 = (wchar_t *)&DAT_0041997c;
        }
        else {
          iVar1 = FUN_004015f0(&DAT_0041d180,param_1);
          if (iVar1 == 0x12) {
            pwVar7 = u_L191G_00418ce8;
          }
          else {
            pwVar7 = u_Unknow_00418cd8;
          }
        }
      }
    }
  }
  CString::operator=(aCStack_34,(ushort *)pwVar7);
  pCVar2 = FUN_00401610(&DAT_0041d180,aCStack_2c,param_1);
  iVar1 = _mbscmp(*(uchar **)pCVar2,&DAT_00418080);
  cStack00000008 = iVar1 == 0;
  CString::~CString(aCStack_2c);
  if (cStack00000008 != '\0') {
    CString::operator=(aCStack_34,(ushort *)&DAT_00418b20);
  }
  FUN_00401600(&DAT_0041d180,param_1);
  FUN_00401200(&DAT_0041d180,param_1);
  CString::Format(this_00,(char *)aCStack_30);
  uVar4 = 0xff00;
  uStack0000000c = 0x9bff;
  uStack_28 = 0xff;
  iVar1 = FUN_004015f0(&DAT_0041d180,param_1);
  if (iVar1 == 0x11) {
    uVar4 = 0xff;
    uStack0000000c = 0xff00;
    uStack_28 = 0xff0000;
  }
  DAT_0041efd0 = param_1;
  DAT_0041efd4 = 0;
  CString::operator=((CString *)&DAT_0041d74c,s_Update_00419a90);
  _DAT_0041d740 = 0;
  DAT_0041ebdc = 0xffff;
  pCVar2 = (CString *)operator+(auStack_20,s_Gaming_Set_Tool___00419a7c);
  CString::operator=((CString *)&DAT_0041ebd8,pCVar2);
  CString::~CString(aCStack_24);
  DAT_0041ebe0 = 10;
  DAT_0041ebe4 = 0x82;
  DAT_0041ebe8 = 2;
  DAT_0041ebd0 = 0;
  _DAT_0041ebf8 = 0xffff;
  _DAT_0041ec04 = 3;
  CString::Format(this_01,&DAT_0041ebf4);
  _DAT_0041ebfc = 100;
  _DAT_0041ec00 = 0xbe;
  DAT_0041ebec = 0;
  _DAT_0041ec20 = 3;
  _DAT_0041ec14 = uVar4;
  CString::operator=((CString *)&DAT_0041ec10,s_Mode_1_00419a1c);
  _DAT_0041ec18 = 10;
  _DAT_0041ec1c = 0xe6;
  DAT_0041ec08 = 0;
  DAT_0041ec30 = uStack0000000c;
  _DAT_0041ec3c = 3;
  CString::operator=((CString *)&DAT_0041ec2c,s_Mode_2_00419a14);
  DAT_0041ec4c = uStack_28;
  _DAT_0041ec34 = 10;
  _DAT_0041ec38 = 0x104;
  _DAT_0041ec24 = 0;
  DAT_0041ec58 = 3;
  CString::operator=((CString *)&DAT_0041ec48,s_Mode_3_00419a0c);
  DAT_0041ec50 = 10;
  DAT_0041ec54 = 0x122;
  DAT_0041ec40 = 0;
  DAT_0041effc = 1;
  _DAT_0041853c = 1;
  uStack_10 = 2;
  uStack_f = 0x9a;
  uStack_e = 0x12;
  bStack_d = 4;
  local_c = 0;
  uStack_b = 0;
  uStack_a = 0;
  uStack_9 = 0;
  puStack_8 = (undefined *)((uint)puStack_8 & 0xff000000);
  FUN_004026f0(&DAT_0041d180,param_1,&uStack_10,&uStack_10,8);
  abStack_18[0] = bStack_d;
  uStack_10 = 2;
  uStack_f = 0x9a;
  uStack_e = 0x12;
  bStack_d = 4;
  local_c = 1;
  FUN_004026f0(&DAT_0041d180,param_1,&uStack_10,&uStack_10,8);
  abStack_18[1] = bStack_d;
  uStack_10 = 2;
  uStack_f = 0x9a;
  uStack_e = 0x12;
  bStack_d = 4;
  local_c = 2;
  FUN_004026f0(&DAT_0041d180,param_1,&uStack_10,&uStack_10,8);
  uVar5 = 4;
  abStack_18[2] = bStack_d;
  uStack0000000c = CONCAT12(bStack_d,CONCAT11(abStack_18[1],abStack_18[0])) & 0xff;
  iVar1 = 0x69;
  uStack_28 = CONCAT11(bStack_d,abStack_18[1]) & 0xff;
  piVar6 = &DAT_0041ee34;
  uStack_1c = CONCAT12(uStack_b,CONCAT11(local_c,bStack_d)) & 0xff;
  do {
    CWnd::SetWindowPos((CWnd *)piVar6[-7],(CWnd *)0x0,iVar1,0xe9,0,0,5);
    CWnd::ShowWindow((CWnd *)piVar6[-7],1);
    SendMessageA(*(HWND *)(piVar6[-7] + 0x20),0xf1,(uint)((uStack0000000c & uVar5) == 0),0);
    CWnd::SetWindowPos((CWnd *)*piVar6,(CWnd *)0x0,iVar1,0x107,0,0,5);
    CWnd::ShowWindow((CWnd *)*piVar6,1);
    SendMessageA(*(HWND *)(*piVar6 + 0x20),0xf1,(uint)((uStack_28 & uVar5) == 0),0);
    CWnd::SetWindowPos((CWnd *)piVar6[7],(CWnd *)0x0,iVar1,0x125,0,0,5);
    CWnd::ShowWindow((CWnd *)piVar6[7],1);
    SendMessageA(*(HWND *)(piVar6[7] + 0x20),0xf1,(uint)((uStack_1c & uVar5) == 0),0);
    iVar1 = iVar1 + 100;
    piVar6 = piVar6 + 1;
    uVar5 = uVar5 << 1;
  } while (iVar1 < 0x325);
  iVar1 = 0;
  piVar6 = &DAT_0041ee30;
  do {
    LVar3 = SendMessageA(*(HWND *)(*piVar6 + 0x20),0xf1,abStack_18[iVar1] & 1,0);
    piVar6 = piVar6 + 7;
    iVar1 = iVar1 + 1;
  } while ((int)piVar6 < 0x41ee84);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0041a198);
  CString::~CString(aCStack_2c);
  CString::~CString(aCStack_30);
  CString::~CString(aCStack_24);
  ExceptionList = pvStack_4;
  return LVar3;
}



/* ==== FUN_0040fb00 @ 0040fb00 ==== */

CComboBox * __thiscall FUN_0040fb00(void *this,byte param_1)

{
  CComboBox::~CComboBox((CComboBox *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CComboBox *)this;
}



/* ==== FUN_0040fb20 @ 0040fb20 ==== */

void __thiscall FUN_0040fb20(void *this,DWORD param_1)

{
  LRESULT LVar1;
  char cVar2;
  int *piVar3;
  undefined local_18;
  undefined local_17;
  undefined local_16;
  undefined local_15;
  char local_14;
  undefined local_13;
  byte local_12;
  undefined local_11;
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_c;
  undefined local_b;
  undefined local_a;
  byte local_9;
  char local_8;
  undefined local_7;
  undefined local_6;
  undefined local_5;
  undefined local_4;
  undefined local_3;
  undefined local_2;
  
  cVar2 = '\0';
  piVar3 = &DAT_0041ee1c;
  do {
    local_c = 2;
    local_b = 0x9a;
    local_a = 0x12;
    local_9 = 4;
    local_7 = 0;
    local_6 = 0;
    local_5 = 0;
    local_4 = 0;
    local_3 = 0;
    local_2 = 0;
    local_8 = cVar2;
    FUN_004026f0(&DAT_0041d180,param_1,&local_c,&local_c,8);
    local_18 = 2;
    local_17 = 0x9a;
    local_16 = 0x12;
    local_15 = 5;
    local_11 = 0;
    local_10 = 0;
    local_f = 0;
    local_e = 0;
    local_13 = local_a;
    local_12 = local_9;
    local_14 = cVar2;
    LVar1 = SendMessageA(*(HWND *)(piVar3[-1] + 0x20),0xf0,0,0);
    if (LVar1 == 0) {
      local_12 = local_12 | 4;
    }
    else {
      local_12 = local_12 & 0xfb;
    }
    LVar1 = SendMessageA(*(HWND *)(*piVar3 + 0x20),0xf0,0,0);
    if (LVar1 == 0) {
      local_12 = local_12 | 8;
    }
    else {
      local_12 = local_12 & 0xf7;
    }
    LVar1 = SendMessageA(*(HWND *)(piVar3[1] + 0x20),0xf0,0,0);
    if (LVar1 == 0) {
      local_12 = local_12 | 0x10;
    }
    else {
      local_12 = local_12 & 0xef;
    }
    LVar1 = SendMessageA(*(HWND *)(piVar3[2] + 0x20),0xf0,0,0);
    if (LVar1 == 0) {
      local_12 = local_12 | 0x20;
    }
    else {
      local_12 = local_12 & 0xdf;
    }
    LVar1 = SendMessageA(*(HWND *)(piVar3[3] + 0x20),0xf0,0,0);
    if (LVar1 == 0) {
      local_12 = local_12 | 0x40;
    }
    else {
      local_12 = local_12 & 0xbf;
    }
    LVar1 = SendMessageA(*(HWND *)(piVar3[4] + 0x20),0xf0,0,0);
    if (LVar1 == 0) {
      local_12 = local_12 | 0x80;
    }
    else {
      local_12 = local_12 & 0x7f;
    }
    LVar1 = SendMessageA(*(HWND *)(piVar3[5] + 0x20),0xf0,0,0);
    if (LVar1 == 0) {
      local_12 = local_12 & 0xfe;
    }
    else {
      local_12 = local_12 | 1;
    }
    FUN_004026f0(&DAT_0041d180,param_1,&local_18,&local_18,8);
    piVar3 = piVar3 + 7;
    cVar2 = cVar2 + '\x01';
  } while ((int)piVar3 < 0x41ee70);
  CWnd::MessageBoxA((CWnd *)this,&DAT_00419ac0,(char *)0x0,0);
  return;
}



/* ==== FUN_0040fd00 @ 0040fd00 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040fd00(void *this,LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  _DCB _Stack_3cc;
  _COMMTIMEOUTS _Stack_3b0;
  char cStack_39c;
  undefined4 uStack_39b;
  char cStack_2d4;
  undefined4 uStack_2d3;
  char acStack_20c [512];
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00414908;
  pvStack_c = ExceptionList;
  local_4 = 0;
  DAT_0041f07c = 0;
  _DAT_0041ee84 = 0;
  _DAT_0041ee88 = 1;
  _DAT_0041ee80 = 0xc;
  ExceptionList = &pvStack_c;
  DAT_0041f078 = CreateFileA(param_1,0xc0000000,3,(LPSECURITY_ATTRIBUTES)&DAT_0041ee80,3,0x40000000,
                             (HANDLE)0x0);
  if (DAT_0041f078 == (HANDLE)0xffffffff) {
    DAT_0041f078 = (HANDLE)0x0;
  }
  else {
    GetCommTimeouts(DAT_0041f078,&_Stack_3b0);
    _Stack_3b0.ReadTotalTimeoutConstant = 1000;
    SetCommTimeouts(DAT_0041f078,&_Stack_3b0);
    GetCommState(DAT_0041f078,&_Stack_3cc);
    _Stack_3cc._8_4_ = _Stack_3cc._8_4_ & 0xffffefe9 | 0x6021;
    _Stack_3cc.BaudRate = 0x1c200;
    _Stack_3cc.ByteSize = '\b';
    _Stack_3cc.Parity = '\0';
    _Stack_3cc.StopBits = '\0';
    SetCommState(DAT_0041f078,&_Stack_3cc);
    FUN_004101f0(s__IDN__00419aec);
    cStack_2d4 = DAT_00419e94;
    cStack_39c = DAT_00419e94;
    puVar2 = &uStack_2d3;
    for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    *(undefined2 *)puVar2 = 0;
    *(undefined *)((int)puVar2 + 2) = 0;
    puVar2 = &uStack_39b;
    for (iVar1 = 0x31; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    *(undefined2 *)puVar2 = 0;
    *(undefined *)((int)puVar2 + 2) = 0;
    FUN_00410180(acStack_20c,500);
    sscanf(acStack_20c,s______________________________00419acc,&cStack_2d4,&cStack_39c);
    CString::operator=((CString *)&DAT_0041a1b0,&cStack_39c);
    iVar1 = _mbscmp(DAT_0041a1b0,(uchar *)s_PM100_00419ac4);
    if (iVar1 == 0) {
      FUN_00410140(850.0);
      DAT_0041f07c = 1;
      local_4 = 0xffffffff;
      CString::~CString((CString *)&param_1);
      ExceptionList = pvStack_c;
      return 1;
    }
    FUN_0040ff50((LPCSTR)this);
  }
  local_4 = 0xffffffff;
  CString::~CString((CString *)&param_1);
  ExceptionList = pvStack_c;
  return 0;
}



/* ==== FUN_0040ff00 @ 0040ff00 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0040ff00(void)

{
  int iVar1;
  double dVar2;
  char local_68 [104];
  
  if (DAT_0041f078 != 0) {
    FUN_004101f0(s__POWER__00419af4);
    iVar1 = FUN_00410180(local_68,100);
    if (iVar1 == 1) {
      dVar2 = atof(local_68);
      return (float10)dVar2;
    }
  }
  return (float10)_DAT_00415b98;
}



/* ==== FUN_0040ff50 @ 0040ff50 ==== */

void __fastcall FUN_0040ff50(LPCSTR param_1)

{
  LPCSTR extraout_ECX;
  LPCSTR pCVar1;
  COLORREF CVar2;
  int iVar3;
  int iVar4;
  undefined *local_14;
  undefined *puStack_10;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00414928;
  pvStack_c = ExceptionList;
  iVar4 = 0;
  iVar3 = 0;
  CVar2 = 0x9bff;
  local_14 = &stack0xffffffd8;
  ExceptionList = &pvStack_c;
  pCVar1 = param_1;
  CString::CString((CString *)&stack0xffffffd8,s_disconnecting_PM100___wait_00419b1c);
  FUN_00407cf0(param_1,0x14,400,pCVar1,CVar2,iVar3,iVar4);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0041a198);
  DAT_0041f07c = 0;
  if (DAT_0041f078 != (HANDLE)0x0) {
    CloseHandle(DAT_0041f078);
  }
  DAT_0041f078 = (HANDLE)0x0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0041a198);
  CString::CString((CString *)&local_14);
  iVar4 = 0;
  iVar3 = 0;
  CVar2 = 0xff;
  puStack_10 = &stack0xffffffd8;
  uStack_4 = 0;
  pCVar1 = extraout_ECX;
  CString::CString((CString *)&stack0xffffffd8,s_disconnecting_PM100___ok_00419b00);
  FUN_00407cf0(param_1,0x14,400,pCVar1,CVar2,iVar3,iVar4);
  uStack_4 = 0xffffffff;
  CString::~CString((CString *)&local_14);
  ExceptionList = pvStack_c;
  return;
}



/* ==== FUN_00410030 @ 00410030 ==== */

void __fastcall FUN_00410030(void *param_1,undefined param_2,undefined4 param_3)

{
  CString *extraout_ECX;
  CString *pCVar1;
  LPCSTR extraout_ECX_00;
  CString *this;
  CString *extraout_ECX_01;
  LPCSTR unaff_ESI;
  int iVar2;
  LPCSTR pCVar3;
  char *pcVar4;
  COLORREF CVar5;
  int iVar6;
  int iVar7;
  CString local_14 [4];
  CString local_10 [4];
  undefined *local_c;
  CString *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = (CString *)&LAB_00414948;
  local_c = (undefined *)ExceptionList;
  ExceptionList = &local_c;
  CString::CString(local_14);
  local_4 = (void *)0x0;
  iVar2 = 1;
  pCVar1 = extraout_ECX;
  do {
    CString::Format(pCVar1,(char *)local_14);
    iVar7 = 0;
    iVar6 = 0;
    CVar5 = 0x9bff;
    local_c = &stack0xffffffd8;
    pCVar3 = extraout_ECX_00;
    CString::CString((CString *)&stack0xffffffd8,local_10);
    FUN_00407cf0(param_1,0x14,400,pCVar3,CVar5,iVar6,iVar7);
    CString::Format(this,(char *)local_10);
    local_8 = (CString *)&stack0xffffffe8;
    CString::CString((CString *)&stack0xffffffe8,(CString *)&local_c);
    iVar6 = FUN_0040fd00(param_1,unaff_ESI);
    if (iVar6 == 1) {
      CVar5 = 0xff00;
      pcVar4 = s_found_PM100____00419b38;
      goto LAB_004100e7;
    }
    iVar2 = iVar2 + 1;
    pCVar1 = extraout_ECX_01;
  } while (iVar2 < 0xf);
  CVar5 = 0xff;
  pcVar4 = s_cann_t_find_PM100_00419b54;
LAB_004100e7:
  iVar6 = 0;
  iVar2 = 0;
  local_8 = (CString *)&stack0xffffffdc;
  pCVar1 = extraout_ECX_01;
  CString::CString(local_8,pcVar4);
  FUN_00407cf0(param_1,0x14,400,(LPCSTR)pCVar1,CVar5,iVar2,iVar6);
  CString::~CString((CString *)&local_c);
  ExceptionList = local_4;
  return;
}



/* ==== FUN_00410140 @ 00410140 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00410140(double param_1)

{
  char local_64 [100];
  
  sprintf(local_64,s__WAVELENGTH__E_00419ba0,param_1 * _DAT_00415ba0);
  FUN_004101f0(local_64);
  return;
}



/* ==== FUN_00410180 @ 00410180 ==== */

undefined4 FUN_00410180(undefined *param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = param_1;
  iVar3 = 0;
  *param_1 = 0;
  iVar4 = 0;
  do {
    iVar2 = FUN_00410320((undefined *)&param_1);
    if (iVar2 == 0) {
      return 0;
    }
    puVar1[iVar3] = (char)param_1;
    if ((char)param_1 == '\n') {
      puVar1[iVar3 + 1] = 0;
      return 1;
    }
    iVar3 = iVar3 + 1;
    if (param_2 < iVar3) {
      return 0;
    }
    Sleep(1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x1f5);
  return 0;
}



/* ==== FUN_004101f0 @ 004101f0 ==== */

DWORD FUN_004101f0(char *param_1)

{
  char cVar1;
  char *lpBuffer;
  HANDLE hEvent;
  HANDLE hObject;
  BOOL BVar2;
  DWORD dwErrCode;
  uint uVar3;
  char *pcVar4;
  int iStack_28;
  _SECURITY_ATTRIBUTES local_20;
  _OVERLAPPED _Stack_14;
  
  lpBuffer = param_1;
  if (DAT_0041f078 == (HANDLE)0x0) {
    return 0;
  }
  uVar3 = 0xffffffff;
  pcVar4 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  local_20.bInheritHandle = 1;
  local_20.nLength = 0xc;
  hEvent = CreateEventA(&local_20,1,1,(LPCSTR)0x0);
  _Stack_14.u.s.Offset = 0;
  _Stack_14.u.s.OffsetHigh = 0;
  param_1 = (char *)0x0;
  _Stack_14.hEvent = hEvent;
  hObject = CreateWaitableTimerA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
  ResetEvent(hEvent);
  BVar2 = WriteFile(DAT_0041f078,lpBuffer,(DWORD)(~uVar3 - 1),(LPDWORD)&param_1,&_Stack_14);
  WaitForSingleObject(hEvent,3000);
  dwErrCode = GetLastError();
  iStack_28 = 0;
  if (BVar2 == 0) {
    do {
      if (dwErrCode == 0x3e5) {
        GetOverlappedResult(DAT_0041f078,&_Stack_14,(LPDWORD)&param_1,0);
      }
      else if (dwErrCode == 0x1f) break;
      Sleep(1);
      dwErrCode = GetLastError();
      if ((param_1 == (char *)(~uVar3 - 1)) || (iStack_28 = iStack_28 + 1, 3000 < iStack_28)) break;
    } while( true );
  }
  CloseHandle(hObject);
  CloseHandle(hEvent);
  SetLastError(dwErrCode);
  Sleep(100);
  return (DWORD)param_1;
}



/* ==== FUN_00410320 @ 00410320 ==== */

int FUN_00410320(undefined *param_1)

{
  HANDLE hEvent;
  BOOL BVar1;
  DWORD dwErrCode;
  DWORD DStack_90;
  int iStack_8c;
  HANDLE pvStack_88;
  _SECURITY_ATTRIBUTES _Stack_84;
  _OVERLAPPED _Stack_78;
  undefined auStack_64 [100];
  
  *param_1 = 0;
  if (DAT_0041f078 == (HANDLE)0x0) {
    return 0;
  }
  _Stack_84.lpSecurityDescriptor = (LPVOID)0x0;
  _Stack_84.bInheritHandle = 1;
  _Stack_84.nLength = 0xc;
  hEvent = CreateEventA(&_Stack_84,1,1,(LPCSTR)0x0);
  _Stack_78.u.s.Offset = 0;
  _Stack_78.u.s.OffsetHigh = 0;
  _Stack_78.hEvent = hEvent;
  ResetEvent(hEvent);
  pvStack_88 = CreateWaitableTimerA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)0x0);
  DStack_90 = 0;
  BVar1 = ReadFile(DAT_0041f078,auStack_64,1,&DStack_90,&_Stack_78);
  WaitForSingleObject(hEvent,3000);
  dwErrCode = GetLastError();
  iStack_8c = 0;
  if (BVar1 == 0) {
    while (dwErrCode == 0x3e5) {
      GetOverlappedResult(DAT_0041f078,&_Stack_78,&DStack_90,0);
      Sleep(1);
      dwErrCode = GetLastError();
      if ((DStack_90 == 1) || (iStack_8c = iStack_8c + 1, 3000 < iStack_8c)) break;
    }
  }
  *param_1 = auStack_64[0];
  CloseHandle(pvStack_88);
  CloseHandle(hEvent);
  SetLastError(dwErrCode);
  return DStack_90;
}



/* ==== FUN_00410345 @ 00410345 ==== */

/* WARNING: Variable defined which should be unmapped: param_5 */
/* WARNING: Variable defined which should be unmapped: param_1 */

LPSECURITY_ATTRIBUTES
FUN_00410345(LPSECURITY_ATTRIBUTES param_1,undefined param_2,undefined param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  HANDLE hEvent;
  BOOL BVar1;
  DWORD dwErrCode;
  LPSECURITY_ATTRIBUTES unaff_EDI;
  undefined3 in_stack_00000009;
  undefined3 in_stack_0000000d;
  HANDLE pvStack0000002c;
  undefined in_stack_00000030;
  undefined *in_stack_00000098;
  
  param_6 = 1;
  param_4 = 0xc;
  hEvent = CreateEventA((LPSECURITY_ATTRIBUTES)&param_4,1,1,(LPCSTR)unaff_EDI);
  pvStack0000002c = hEvent;
  ResetEvent(hEvent);
  _param_3 = CreateWaitableTimerA(unaff_EDI,(BOOL)unaff_EDI,(LPCSTR)unaff_EDI);
  param_1 = unaff_EDI;
  BVar1 = ReadFile(DAT_0041f078,&stack0x00000030,1,(LPDWORD)&param_1,(LPOVERLAPPED)&stack0x0000001c)
  ;
  WaitForSingleObject(hEvent,3000);
  dwErrCode = GetLastError();
  _param_2 = 0;
  if (BVar1 == 0) {
    while (dwErrCode == 0x3e5) {
      GetOverlappedResult(DAT_0041f078,(LPOVERLAPPED)&stack0x0000001c,(LPDWORD)&param_1,0);
      Sleep(1);
      dwErrCode = GetLastError();
      if ((param_1 == (LPSECURITY_ATTRIBUTES)0x1) || (_param_2 = _param_2 + 1, 3000 < _param_2))
      break;
    }
  }
  *in_stack_00000098 = in_stack_00000030;
  CloseHandle(_param_3);
  CloseHandle(hEvent);
  SetLastError(dwErrCode);
  return param_1;
}



/* ==== FUN_00410460 @ 00410460 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00410460(DWORD param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  CString *this;
  CString *extraout_ECX;
  CString *extraout_ECX_00;
  CString *this_00;
  uint uVar4;
  float10 fVar5;
  undefined local_45;
  int local_40;
  uint local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined local_28;
  undefined uStack_27;
  undefined uStack_26;
  undefined uStack_25;
  undefined uStack_24;
  undefined uStack_23;
  undefined uStack_22;
  undefined uStack_21;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  undefined local_1d;
  undefined local_1c;
  void *pvStack_14;
  undefined *puStack_10;
  void *local_c;
  
  local_c = (void *)0xffffffff;
  puStack_10 = &LAB_00414968;
  pvStack_14 = ExceptionList;
  puVar3 = &DAT_0041ebec;
  ExceptionList = &pvStack_14;
  do {
    *puVar3 = 1;
    puVar3 = puVar3 + 7;
  } while ((int)puVar3 < 0x41ee00);
  if (DAT_0041f078 != 0) {
    _DAT_0041ebfc = 10;
    _DAT_0041ec00 = 0xbe;
    _DAT_0041ec04 = 4;
    DAT_0041ebec = 0;
    _DAT_0041ebf8 = 0xffff;
    CString::operator=((CString *)&DAT_0041ebf4,(ushort *)&DAT_00419c4c);
    local_28 = 2;
    uStack_27 = 0x9a;
    uStack_26 = 0x10;
    uStack_25 = 2;
    FUN_004026f0(&DAT_0041d180,param_1,&local_28,&local_28,8);
    local_40 = CONCAT31(local_40._1_3_,0x7f);
    bVar1 = 0;
    CString::CString((CString *)&local_38);
    local_c = (void *)0x0;
    while( true ) {
      fVar5 = FUN_0040ff00();
      local_30 = (double)fVar5;
      if (fVar5 != (float10)_DAT_00415b98) {
        local_30 = local_30 * _DAT_00415b30;
      }
      CString::Format(this,&DAT_0041ebf4);
      DAT_0041effc = 1;
      if ((_DAT_00418568 - _DAT_00418578 <=
           (double)CONCAT17(uStack_25,
                            CONCAT16(uStack_26,CONCAT15(uStack_27,CONCAT14(local_28,local_30._4_4_))
                                    ))) &&
         ((double)CONCAT17(uStack_25,
                           CONCAT16(uStack_26,CONCAT15(uStack_27,CONCAT14(local_28,local_30._4_4_)))
                          ) <= _DAT_00418578 + _DAT_00418568)) break;
      if (local_40 == 0) {
        if (bVar1 < 0x7f) goto LAB_00410612;
        bVar1 = 0x26;
        local_45 = 0x26;
        uStack_24 = 2;
        uStack_23 = 0x9a;
        uStack_22 = 0x10;
        uStack_21 = 0;
        local_20 = 0x26;
        FUN_004026f0(&DAT_0041d180,param_1,&uStack_24,&uStack_24,8);
      }
      else {
        if (0x10 < local_40) goto LAB_00410756;
LAB_00410612:
        if ((double)CONCAT17(uStack_25,
                             CONCAT16(uStack_26,
                                      CONCAT15(uStack_27,CONCAT14(local_28,local_30._4_4_)))) !=
            _DAT_00415b98) {
          uVar4 = local_38 & 0xff;
          CString::Format((CString *)
                          CONCAT13(uStack_25,CONCAT12(uStack_26,CONCAT11(uStack_27,local_28))),
                          (char *)&local_34);
          if (_DAT_00418568 - _DAT_00418578 <=
              (double)CONCAT17(uStack_21,
                               CONCAT16(uStack_22,
                                        CONCAT15(uStack_23,
                                                 CONCAT14(uStack_24,
                                                          CONCAT13(uStack_25,
                                                                   CONCAT12(uStack_26,
                                                                            CONCAT11(uStack_27,
                                                                                     local_28)))))))
             ) {
            if (_DAT_00418578 + _DAT_00418568 <
                (double)CONCAT17(uStack_21,
                                 CONCAT16(uStack_22,
                                          CONCAT15(uStack_23,
                                                   CONCAT14(uStack_24,
                                                            CONCAT13(uStack_25,
                                                                     CONCAT12(uStack_26,
                                                                              CONCAT11(uStack_27,
                                                                                       local_28)))))
                                         ))) {
              local_34 = CONCAT31(local_34._1_3_,(undefined)local_40);
              cVar2 = bVar1 / 2 + 1;
              goto LAB_004106b6;
            }
          }
          else {
            local_38 = CONCAT31(local_38._1_3_,(undefined)local_40);
            cVar2 = (char)((bVar1 + uVar4) / 2);
LAB_004106b6:
            local_40 = CONCAT31(local_40._1_3_,cVar2);
          }
          local_1c = (undefined)local_40;
          local_20 = 2;
          local_1f = 0x9a;
          local_1e = 0x10;
          local_1d = 0;
          FUN_004026f0(&DAT_0041d180,param_1,&local_20,&local_20,8);
        }
      }
      Sleep(0x15e);
      bVar1 = bVar1 + 1;
    }
    if ((double)CONCAT17(uStack_25,
                         CONCAT16(uStack_26,CONCAT15(uStack_27,CONCAT14(local_28,local_30._4_4_))))
        != _DAT_00415b98) {
      _DAT_0041ebf8 = 0xff00;
      uStack_24 = 2;
      uStack_23 = 0x9a;
      uStack_22 = 0x10;
      uStack_21 = 1;
      FUN_004026f0(&DAT_0041d180,param_1,&uStack_24,&uStack_24,8);
      this_00 = extraout_ECX;
      goto LAB_0041079a;
    }
LAB_00410756:
    uStack_24 = 2;
    uStack_23 = 0x9a;
    uStack_22 = 0x10;
    uStack_21 = 0;
    local_20 = local_45;
    FUN_004026f0(&DAT_0041d180,param_1,&uStack_24,&uStack_24,8);
    _DAT_0041ebf8 = 0xff;
    this_00 = extraout_ECX_00;
LAB_0041079a:
    CString::Format(this_00,&DAT_0041ebf4);
    DAT_0041effc = 1;
    CString::~CString((CString *)&local_30);
  }
  ExceptionList = local_c;
  return;
}



/* ==== FUN_004107e0 @ 004107e0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004107e0(void)

{
  int iVar1;
  DWORD DVar2;
  int *piVar3;
  undefined4 local_8b8 [555];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_0041498b;
  local_c = ExceptionList;
  _DAT_0041f004 = 1;
  if (DAT_0041f008 == 0xb) {
    ExceptionList = &local_c;
    FUN_00403000(local_8b8);
    local_4 = 0;
    FUN_00403210((int)local_8b8);
    iVar1 = FUN_004026e0((int)local_8b8);
    if (0 < iVar1) {
      FUN_00412900(0,local_8b8);
    }
    local_4 = 0xffffffff;
    FUN_00403120(local_8b8);
  }
  else {
    DVar2 = 0;
    ExceptionList = &local_c;
    iVar1 = FUN_004026e0(0x41d180);
    if (0 < iVar1) {
      piVar3 = &DAT_0041d598;
      do {
        if (*piVar3 == 2) {
          if (DVar2 == 0xffffffff) {
            _DAT_0041f004 = 0;
            ExceptionList = local_c;
            return;
          }
          FUN_00410460(DVar2);
          _DAT_0041f004 = 0;
          ExceptionList = local_c;
          return;
        }
        DVar2 = DVar2 + 1;
        piVar3 = piVar3 + 1;
        iVar1 = FUN_004026e0(0x41d180);
      } while ((int)DVar2 < iVar1);
    }
  }
  _DAT_0041f004 = 0;
  ExceptionList = local_c;
  return;
}



/* ==== FUN_004108c0 @ 004108c0 ==== */

void FUN_004108c0(void)

{
  int iVar1;
  DWORD DVar2;
  DWORD DVar3;
  int *piVar4;
  CString local_14 [4];
  CString local_10 [4];
  void *local_c;
  undefined *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004149b0;
  local_c = ExceptionList;
  DVar3 = 0;
  ExceptionList = &local_c;
  CString::CString(local_10);
  local_4 = 0;
  CString::CString(local_14);
  local_4 = CONCAT31(local_4._1_3_,1);
  iVar1 = FUN_004026e0(0x41d180);
  DVar2 = 0;
  if (0 < iVar1) {
    piVar4 = &DAT_0041d598;
    do {
      DVar2 = DVar3;
      if (*piVar4 == 1) break;
      DVar3 = DVar3 + 1;
      piVar4 = piVar4 + 1;
      iVar1 = FUN_004026e0(0x41d180);
      DVar2 = 0;
    } while ((int)DVar3 < iVar1);
  }
  FUN_0040d590(DVar2);
  local_4 = local_4 & 0xffffff00;
  CString::~CString(local_14);
  local_4 = 0xffffffff;
  CString::~CString(local_10);
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00410c10 @ 00410c10 ==== */

void FUN_00410c10(DWORD param_1)

{
  int iVar1;
  CString *pCVar2;
  undefined uVar3;
  CString aCStack_6c [4];
  undefined uStack_68;
  undefined uStack_67;
  undefined uStack_66;
  undefined uStack_65;
  undefined uStack_64;
  undefined uStack_63;
  undefined uStack_62;
  undefined uStack_61;
  undefined uStack_60;
  undefined uStack_5c;
  undefined uStack_5b;
  undefined uStack_5a;
  undefined uStack_59;
  undefined uStack_58;
  undefined uStack_57;
  undefined uStack_56;
  undefined uStack_55;
  undefined uStack_54;
  undefined uStack_50;
  undefined uStack_4f;
  undefined uStack_4e;
  undefined uStack_4d;
  undefined uStack_4c;
  undefined uStack_4b;
  undefined uStack_4a;
  undefined uStack_49;
  undefined uStack_48;
  undefined4 auStack_44 [8];
  undefined4 auStack_24 [4];
  undefined uStack_14;
  undefined uStack_13;
  undefined uStack_12;
  undefined uStack_11;
  
  iVar1 = FUN_00401600(&DAT_0041d180,param_1);
  if (0x28 < iVar1) {
    iVar1 = _mbscmp((uchar *)(&DAT_0041d4f8)[param_1],(uchar *)s_DRTCM03_004195a4);
    if (iVar1 == 0) {
      iVar1 = 0;
      auStack_44[0] = 1;
      auStack_44[1] = 1;
      auStack_44[2] = 1;
      auStack_44[3] = 1;
      auStack_44[4] = 2;
      auStack_44[5] = 1;
      auStack_44[6] = 1;
      auStack_44[7] = 1;
      auStack_24[0] = 4;
      auStack_24[1] = 0;
      auStack_24[2] = 1;
      auStack_24[3] = 2;
      do {
        uStack_63 = (undefined)auStack_44[iVar1];
        uStack_62 = (undefined)auStack_44[iVar1 + 4];
        uStack_68 = 2;
        uStack_67 = 0x9a;
        uStack_66 = 0x12;
        uStack_65 = 1;
        uVar3 = (undefined)iVar1;
        uStack_61 = 0x10;
        uStack_60 = 0;
        uStack_64 = uVar3;
        FUN_004026f0(&DAT_0041d180,param_1,&uStack_68,&uStack_68,8);
        Sleep(0xc);
        uStack_57 = (undefined)auStack_44[iVar1];
        uStack_56 = (undefined)auStack_44[iVar1 + 4];
        uStack_5c = 2;
        uStack_5b = 0x9a;
        uStack_5a = 0x12;
        uStack_59 = 2;
        uStack_55 = 0x10;
        uStack_54 = 0;
        uStack_58 = uVar3;
        FUN_004026f0(&DAT_0041d180,param_1,&uStack_5c,&uStack_5c,8);
        Sleep(0xc);
        uStack_4b = *(undefined *)(auStack_24 + iVar1);
        uStack_50 = 2;
        uStack_4f = 0x9a;
        uStack_4e = 0x12;
        uStack_4d = 0;
        uStack_4a = 0;
        uStack_49 = 0x10;
        uStack_48 = 0;
        uStack_4c = uVar3;
        FUN_004026f0(&DAT_0041d180,param_1,&uStack_50,&uStack_50,8);
        Sleep(0xc);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 4);
    }
    uStack_14 = 2;
    uStack_13 = 0x97;
    uStack_12 = 0xb;
    uStack_11 = 2;
    iVar1 = FUN_00401200(&DAT_0041d180,param_1);
    if (iVar1 == 1) {
      uStack_11 = 3;
    }
    else {
      pCVar2 = FUN_00401610(&DAT_0041d180,aCStack_6c,param_1);
      iVar1 = _mbscmp(*(uchar **)pCVar2,&DAT_00418080);
      CString::~CString(aCStack_6c);
      if ((iVar1 == 0) || ((&DAT_0041d548)[param_1] == 4)) {
        uStack_11 = 1;
      }
    }
    iVar1 = _mbscmp((uchar *)(&DAT_0041d4f8)[param_1],(uchar *)s_DRTCM03_004195a4);
    if (iVar1 == 0) {
      uStack_11 = 2;
    }
    FUN_004026f0(&DAT_0041d180,param_1,&uStack_14,&uStack_14,3);
    Sleep(10);
    uStack_14 = 2;
    uStack_13 = 0x97;
    uStack_12 = 0xc;
    uStack_11 = 0;
    FUN_004026f0(&DAT_0041d180,param_1,&uStack_14,&uStack_14,3);
    Sleep(10);
    uStack_14 = 2;
    uStack_13 = 0x97;
    uStack_12 = 0x32;
    uStack_11 = 0x1e;
    FUN_004026f0(&DAT_0041d180,param_1,&uStack_14,&uStack_14,3);
    Sleep(10);
    uStack_14 = 2;
    uStack_13 = 0x97;
    uStack_12 = 0x33;
    uStack_11 = 0x12;
    FUN_004026f0(&DAT_0041d180,param_1,&uStack_14,&uStack_14,3);
    Sleep(10);
    uStack_14 = 2;
    uStack_13 = 0x97;
    uStack_12 = 0x34;
    uStack_11 = 3;
    FUN_004026f0(&DAT_0041d180,param_1,&uStack_14,&uStack_14,3);
    Sleep(10);
  }
  return;
}



/* ==== FUN_00410f00 @ 00410f00 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00410f00(void)

{
  int iVar1;
  DWORD DVar2;
  int *piVar3;
  
  _DAT_0041f004 = 1;
  DVar2 = 0;
  iVar1 = FUN_004026e0(0x41d180);
  if (0 < iVar1) {
    piVar3 = &DAT_0041d598;
    do {
      if ((*piVar3 == 2) && (iVar1 = FUN_00401600(&DAT_0041d180,DVar2), 0x28 < iVar1)) {
        if (DVar2 != 0xffffffff) {
          _DAT_0041ebfc = 10;
          _DAT_0041ec00 = 0xa0;
          _DAT_0041ec04 = 4;
          CString::operator=((CString *)&DAT_0041ebf4,s_Wait____00419cc0);
          _DAT_0041ebf8 = 0xffff;
          DAT_0041ebec = 0;
          DAT_0041effc = 1;
          FUN_00410c10(DVar2);
          _DAT_0041ebfc = 10;
          _DAT_0041ec00 = 0xa0;
          _DAT_0041ec04 = 4;
          CString::operator=((CString *)&DAT_0041ebf4,s_Pass____00419cb4);
          _DAT_0041ebf8 = 0xff00;
          DAT_0041ebec = 0;
          DAT_0041effc = 1;
          _DAT_0041f004 = 0;
          return;
        }
        break;
      }
      DVar2 = DVar2 + 1;
      piVar3 = piVar3 + 1;
      iVar1 = FUN_004026e0(0x41d180);
    } while ((int)DVar2 < iVar1);
  }
  _DAT_0041ebfc = 10;
  _DAT_0041ec00 = 0xa0;
  _DAT_0041ec04 = 4;
  CString::operator=((CString *)&DAT_0041ebf4,s_Error____00419cc8);
  _DAT_0041ebf8 = 0xff;
  DAT_0041ebec = 0;
  DAT_0041effc = 1;
  return;
}



/* ==== FUN_00411050 @ 00411050 ==== */

int FUN_00411050(int param_1)

{
  undefined uVar1;
  undefined uVar2;
  int iVar3;
  DWORD DVar4;
  int *piVar5;
  undefined local_26c;
  undefined local_26b;
  undefined local_26a;
  undefined local_269;
  undefined local_268;
  undefined local_267;
  undefined local_266;
  undefined local_265;
  undefined local_264;
  undefined local_260;
  undefined local_25f;
  undefined local_25e;
  undefined local_25d;
  undefined local_25c;
  undefined local_25b;
  undefined local_25a;
  undefined local_259;
  undefined local_258;
  undefined local_254;
  undefined local_253;
  undefined local_252;
  undefined local_251;
  undefined local_250;
  undefined local_24f;
  undefined local_24e;
  undefined local_24d;
  undefined local_24c;
  undefined local_248 [560];
  int local_18 [6];
  
  if (param_1 == 0) {
    DAT_00418534 = 400;
  }
  else if (param_1 == 1) {
    if (0xc7f < DAT_00418534) {
      return DAT_00418534;
    }
    DAT_00418534 = DAT_00418534 + 100;
  }
  else if (param_1 == 2) {
    if (DAT_00418534 < 0x65) {
      return DAT_00418534;
    }
    DAT_00418534 = DAT_00418534 + -100;
  }
  DVar4 = 0;
  iVar3 = FUN_004026e0(0x41d180);
  if (0 < iVar3) {
    piVar5 = &DAT_0041d598;
    while (*piVar5 != 2) {
      DVar4 = DVar4 + 1;
      piVar5 = piVar5 + 1;
      iVar3 = FUN_004026e0(0x41d180);
      if (iVar3 <= (int)DVar4) {
        return 0;
      }
    }
    if (DVar4 != 0xffffffff) {
      local_248[0x118] = 1;
      local_248[0x119] = 1;
      local_248[0x11a] = 3;
      local_248[0x11b] = 1;
      local_248[0x11c] = 5;
      local_248[0x11d] = 3;
      local_248[0x11e] = 7;
      local_248[0x11f] = 2;
      local_248[0x120] = 9;
      local_248[0x121] = 5;
      local_248[0x122] = 0xb;
      local_248[0x123] = 3;
      local_248[0x124] = 0xd;
      local_248[0x125] = 7;
      local_248[0x126] = 0xf;
      local_248[0x127] = 4;
      local_248[0x128] = 0x11;
      local_248[0x129] = 9;
      local_248[0x12a] = 0x13;
      local_248[299] = 5;
      local_248[300] = 0x15;
      local_248[0x12d] = 0xb;
      local_248[0x12e] = 0x17;
      local_248[0x12f] = 6;
      local_248[0x130] = 0x19;
      local_248[0x131] = 0xd;
      local_248[0x132] = 0x1b;
      local_248[0x133] = 7;
      local_248[0x134] = 0x1d;
      local_248[0x135] = 0xf;
      local_248[0x136] = 0x1f;
      local_248[0x137] = 8;
      local_248[0x138] = 0x21;
      local_248[0x139] = 0x11;
      local_248[0x13a] = 0x23;
      local_248[0x13b] = 9;
      local_248[0x13c] = 0x25;
      local_248[0x13d] = 0x13;
      local_248[0x13e] = 0x27;
      local_248[0x13f] = 10;
      local_248[0x140] = 1;
      local_248[0x141] = 1;
      local_248[0x142] = 3;
      local_248[0x143] = 1;
      local_248[0x144] = 5;
      local_248[0x145] = 3;
      local_248[0x146] = 7;
      local_248[0x147] = 1;
      local_248[0x148] = 9;
      local_248[0x149] = 5;
      local_248[0x14a] = 0xb;
      local_248[0x14b] = 3;
      local_248[0x14c] = 0xd;
      local_248[0x14d] = 7;
      local_248[0x14e] = 0xf;
      local_248[0x14f] = 2;
      local_248[0x150] = 0x11;
      local_248[0x151] = 9;
      local_248[0x152] = 0x13;
      local_248[0x153] = 5;
      local_248[0x154] = 0x15;
      local_248[0x155] = 0xb;
      local_248[0x156] = 0x17;
      local_248[0x157] = 3;
      local_248[0x158] = 0x19;
      local_248[0x159] = 0xd;
      local_248[0x15a] = 0x1b;
      local_248[0x15b] = 7;
      local_248[0x15c] = 0x1d;
      local_248[0x15d] = 0xf;
      local_248[0x15e] = 0x1f;
      local_248[0x15f] = 4;
      local_248[0x160] = 0x21;
      local_248[0x161] = 0x11;
      local_248[0x162] = 0x23;
      local_248[0x163] = 9;
      local_248[0x164] = 0x25;
      local_248[0x165] = 0x13;
      local_248[0x166] = 0x27;
      local_248[0x167] = 5;
      local_248[0x168] = 1;
      local_248[0x169] = 1;
      local_248[0x16a] = 3;
      local_248[0x16b] = 1;
      local_248[0x16c] = 5;
      local_248[0x16d] = 3;
      local_248[0x16e] = 7;
      local_248[0x16f] = 1;
      local_248[0x170] = 9;
      local_248[0x171] = 5;
      local_248[0x172] = 0xb;
      local_248[0x173] = 3;
      local_248[0x174] = 0xd;
      local_248[0x175] = 7;
      local_248[0x176] = 0xf;
      local_248[0x177] = 1;
      local_248[0x178] = 0x11;
      local_248[0x179] = 9;
      local_248[0x17a] = 0x13;
      local_248[0x17b] = 5;
      local_248[0x17c] = 0x15;
      local_248[0x17d] = 0xb;
      local_248[0x17e] = 0x17;
      local_248[0x17f] = 3;
      local_248[0x180] = 0x19;
      local_248[0x181] = 0xd;
      local_248[0x182] = 0x1b;
      local_248[0x183] = 7;
      local_248[0x184] = 0x1d;
      local_248[0x185] = 0xf;
      local_248[0x186] = 0x1f;
      local_248[0x187] = 2;
      local_248[0x188] = 0x21;
      local_248[0x189] = 0x11;
      local_248[0x18a] = 0x23;
      local_248[0x18b] = 9;
      local_248[0x18c] = 0x25;
      local_248[0x18d] = 0x13;
      local_248[0x18e] = 0x27;
      local_248[399] = 5;
      local_248[400] = 1;
      local_248[0x191] = 1;
      local_248[0x192] = 3;
      local_248[0x193] = 1;
      local_248[0x194] = 1;
      local_248[0x195] = 3;
      local_248[0x196] = 7;
      local_248[0x197] = 2;
      local_248[0x198] = 9;
      local_248[0x199] = 1;
      local_248[0x19a] = 0xb;
      local_248[0x19b] = 3;
      local_248[0x19c] = 0xd;
      local_248[0x19d] = 7;
      local_248[0x19e] = 0xf;
      local_248[0x19f] = 4;
      local_248[0x1a0] = 0x11;
      local_248[0x1a1] = 9;
      local_248[0x1a2] = 0x13;
      local_248[0x1a3] = 1;
      local_248[0x1a4] = 0x15;
      local_248[0x1a5] = 0xb;
      local_248[0x1a6] = 0x17;
      local_248[0x1a7] = 6;
      local_248[0x1a8] = 5;
      local_248[0x1a9] = 0xd;
      local_248[0x1aa] = 0x1b;
      local_248[0x1ab] = 7;
      local_248[0x1ac] = 0x1d;
      local_248[0x1ad] = 6;
      local_248[0x1ae] = 0x1f;
      local_248[0x1af] = 8;
      local_248[0x1b0] = 0x21;
      local_248[0x1b1] = 0x11;
      local_248[0x1b2] = 7;
      local_248[0x1b3] = 9;
      local_248[0x1b4] = 0x25;
      local_248[0x1b5] = 0x13;
      local_248[0x1b6] = 0x27;
      local_248[0x1b7] = 2;
      local_248[0x1b8] = 1;
      local_248[0x1b9] = 1;
      local_248[0x1ba] = 1;
      local_248[0x1bb] = 1;
      local_248[0x1bc] = 5;
      local_248[0x1bd] = 1;
      local_248[0x1be] = 7;
      local_248[0x1bf] = 2;
      local_248[0x1c0] = 3;
      local_248[0x1c1] = 5;
      local_248[0x1c2] = 0xb;
      local_248[0x1c3] = 1;
      local_248[0x1c4] = 0xd;
      local_248[0x1c5] = 7;
      local_248[0x1c6] = 5;
      local_248[0x1c7] = 4;
      local_248[0x1c8] = 0x11;
      local_248[0x1c9] = 6;
      local_248[0x1ca] = 0x13;
      local_248[0x1cb] = 5;
      local_248[0x1cc] = 7;
      local_248[0x1cd] = 0xb;
      local_248[0x1ce] = 0x17;
      local_248[0x1cf] = 6;
      local_248[0x1d0] = 0x19;
      local_248[0x1d1] = 0xd;
      local_248[0x1d2] = 9;
      local_248[0x1d3] = 7;
      local_248[0x1d4] = 0x1d;
      local_248[0x1d5] = 5;
      local_248[0x1d6] = 0x1f;
      local_248[0x1d7] = 8;
      local_248[0x1d8] = 0xb;
      local_248[0x1d9] = 0x11;
      local_248[0x1da] = 0x23;
      local_248[0x1db] = 3;
      local_248[0x1dc] = 0x25;
      local_248[0x1dd] = 0x13;
      local_248[0x1de] = 0x27;
      local_248[0x1df] = 10;
      local_248[0x1e0] = 1;
      local_248[0x1e1] = 1;
      local_248[0x1e2] = 1;
      local_248[0x1e3] = 2;
      local_248[0x1e4] = 1;
      local_248[0x1e5] = 1;
      local_248[0x1e6] = 7;
      local_248[0x1e7] = 4;
      local_248[0x1e8] = 3;
      local_248[0x1e9] = 1;
      local_248[0x1ea] = 0xb;
      local_248[0x1eb] = 2;
      local_248[0x1ec] = 0xd;
      local_248[0x1ed] = 7;
      local_248[0x1ee] = 1;
      local_248[0x1ef] = 8;
      local_248[0x1f0] = 0x11;
      local_248[0x1f1] = 3;
      local_248[0x1f2] = 0x13;
      local_248[499] = 2;
      local_248[500] = 7;
      local_248[0x1f5] = 0xb;
      local_248[0x1f6] = 0x17;
      local_248[0x1f7] = 4;
      local_248[0x1f8] = 5;
      local_248[0x1f9] = 0xd;
      local_248[0x1fa] = 9;
      local_248[0x1fb] = 0xe;
      local_248[0x1fc] = 0x1d;
      local_248[0x1fd] = 1;
      local_248[0x1fe] = 0x1f;
      local_248[0x1ff] = 0x10;
      local_248[0x200] = 0xb;
      local_248[0x201] = 0x11;
      local_248[0x202] = 7;
      local_248[0x203] = 6;
      local_248[0x204] = 0x25;
      local_248[0x205] = 0x13;
      local_248[0x206] = 0xd;
      local_248[0x207] = 4;
      local_248[0x208] = 1;
      local_248[0x209] = 2;
      local_248[0x20a] = 3;
      local_248[0x20b] = 4;
      local_248[0x20c] = 5;
      local_248[0x20d] = 6;
      local_248[0x20e] = 7;
      local_248[0x20f] = 8;
      local_248[0x210] = 9;
      local_248[0x211] = 10;
      local_248[0x212] = 0xb;
      local_248[0x213] = 0xc;
      local_248[0x214] = 0xd;
      local_248[0x215] = 0xe;
      local_248[0x216] = 0xf;
      local_248[0x217] = 0x10;
      local_248[0x218] = 0x11;
      local_248[0x219] = 0x12;
      local_248[0x21a] = 0x13;
      local_248[0x21b] = 0x14;
      local_248[0x21c] = 0x15;
      local_248[0x21d] = 0x16;
      local_248[0x21e] = 0x17;
      local_248[0x21f] = 0x18;
      local_248[0x220] = 0x19;
      local_248[0x221] = 0x1a;
      local_248[0x222] = 0x1b;
      local_248[0x223] = 0x1c;
      local_248[0x224] = 0x1d;
      local_248[0x225] = 0x1e;
      local_248[0x226] = 0x1f;
      local_248[0x227] = 0x20;
      local_248[0x228] = 0x21;
      local_248[0x229] = 0x22;
      local_248[0x22a] = 0x23;
      local_248[0x22b] = 0x24;
      local_248[0x22c] = 0x25;
      local_248[0x22d] = 0x26;
      local_248[0x22e] = 0x27;
      local_248[0x22f] = 0x28;
      local_248[0] = 4;
      local_248[1] = 2;
      local_248[2] = 4;
      local_248[3] = 1;
      local_248[4] = 4;
      local_248[5] = 2;
      local_248[6] = 4;
      local_248[7] = 1;
      local_248[8] = 4;
      local_248[9] = 2;
      local_248[10] = 4;
      local_248[0xb] = 1;
      local_248[0xc] = 4;
      local_248[0xd] = 2;
      local_248[0xe] = 4;
      local_248[0xf] = 1;
      local_248[0x10] = 4;
      local_248[0x11] = 2;
      local_248[0x12] = 4;
      local_248[0x13] = 1;
      local_248[0x14] = 4;
      local_248[0x15] = 2;
      local_248[0x16] = 4;
      local_248[0x17] = 1;
      local_248[0x18] = 4;
      local_248[0x19] = 2;
      local_248[0x1a] = 4;
      local_248[0x1b] = 1;
      local_248[0x1c] = 4;
      local_248[0x1d] = 2;
      local_248[0x1e] = 4;
      local_248[0x1f] = 1;
      local_248[0x20] = 4;
      local_248[0x21] = 2;
      local_248[0x22] = 4;
      local_248[0x23] = 1;
      local_248[0x24] = 4;
      local_248[0x25] = 2;
      local_248[0x26] = 4;
      local_248[0x27] = 1;
      local_248[0x28] = 8;
      local_248[0x29] = 4;
      local_248[0x2a] = 8;
      local_248[0x2b] = 2;
      local_248[0x2c] = 8;
      local_248[0x2d] = 4;
      local_248[0x2e] = 8;
      local_248[0x2f] = 1;
      local_248[0x30] = 8;
      local_248[0x31] = 4;
      local_248[0x32] = 8;
      local_248[0x33] = 2;
      local_248[0x34] = 8;
      local_248[0x35] = 2;
      local_248[0x36] = 8;
      local_248[0x37] = 1;
      local_248[0x38] = 8;
      local_248[0x39] = 4;
      local_248[0x3a] = 8;
      local_248[0x3b] = 2;
      local_248[0x3c] = 8;
      local_248[0x3d] = 4;
      local_248[0x3e] = 8;
      local_248[0x3f] = 1;
      local_248[0x40] = 8;
      local_248[0x41] = 4;
      local_248[0x42] = 8;
      local_248[0x43] = 2;
      local_248[0x44] = 8;
      local_248[0x45] = 4;
      local_248[0x46] = 8;
      local_248[0x47] = 1;
      local_248[0x48] = 8;
      local_248[0x49] = 4;
      local_248[0x4a] = 8;
      local_248[0x4b] = 2;
      local_248[0x4c] = 8;
      local_248[0x4d] = 4;
      local_248[0x4e] = 8;
      local_248[0x4f] = 1;
      local_248[0x50] = 0x10;
      local_248[0x51] = 8;
      local_248[0x52] = 0x10;
      local_248[0x53] = 4;
      local_248[0x54] = 0x10;
      local_248[0x55] = 8;
      local_248[0x56] = 0x10;
      local_248[0x57] = 2;
      local_248[0x58] = 0x10;
      local_248[0x59] = 8;
      local_248[0x5a] = 0x10;
      local_248[0x5b] = 4;
      local_248[0x5c] = 0x10;
      local_248[0x5d] = 8;
      local_248[0x5e] = 0x10;
      local_248[0x5f] = 1;
      local_248[0x60] = 0x10;
      local_248[0x61] = 8;
      local_248[0x62] = 0x10;
      local_248[99] = 4;
      local_248[100] = 0x10;
      local_248[0x65] = 8;
      local_248[0x66] = 0x10;
      local_248[0x67] = 2;
      local_248[0x68] = 0x10;
      local_248[0x69] = 8;
      local_248[0x6a] = 0x10;
      local_248[0x6b] = 4;
      local_248[0x6c] = 0x10;
      local_248[0x6d] = 8;
      local_248[0x6e] = 0x10;
      local_248[0x6f] = 1;
      local_248[0x70] = 0x10;
      local_248[0x71] = 8;
      local_248[0x72] = 0x10;
      local_248[0x73] = 4;
      local_248[0x74] = 0x10;
      local_248[0x75] = 8;
      local_248[0x76] = 0x10;
      local_248[0x77] = 2;
      local_248[0x78] = 0x14;
      local_248[0x79] = 10;
      local_248[0x7a] = 0x14;
      local_248[0x7b] = 5;
      local_248[0x7c] = 4;
      local_248[0x7d] = 10;
      local_248[0x7e] = 0x14;
      local_248[0x7f] = 5;
      local_248[0x80] = 0x14;
      local_248[0x81] = 2;
      local_248[0x82] = 0x14;
      local_248[0x83] = 5;
      local_248[0x84] = 0x14;
      local_248[0x85] = 10;
      local_248[0x86] = 0x14;
      local_248[0x87] = 5;
      local_248[0x88] = 0x14;
      local_248[0x89] = 10;
      local_248[0x8a] = 0x14;
      local_248[0x8b] = 1;
      local_248[0x8c] = 0x14;
      local_248[0x8d] = 10;
      local_248[0x8e] = 0x14;
      local_248[0x8f] = 5;
      local_248[0x90] = 4;
      local_248[0x91] = 10;
      local_248[0x92] = 0x14;
      local_248[0x93] = 5;
      local_248[0x94] = 0x14;
      local_248[0x95] = 4;
      local_248[0x96] = 0x14;
      local_248[0x97] = 5;
      local_248[0x98] = 0x14;
      local_248[0x99] = 10;
      local_248[0x9a] = 4;
      local_248[0x9b] = 5;
      local_248[0x9c] = 0x14;
      local_248[0x9d] = 10;
      local_248[0x9e] = 0x14;
      local_248[0x9f] = 1;
      local_248[0xa0] = 0xc;
      local_248[0xa1] = 6;
      local_248[0xa2] = 4;
      local_248[0xa3] = 3;
      local_248[0xa4] = 0xc;
      local_248[0xa5] = 2;
      local_248[0xa6] = 0xc;
      local_248[0xa7] = 3;
      local_248[0xa8] = 4;
      local_248[0xa9] = 6;
      local_248[0xaa] = 0xc;
      local_248[0xab] = 1;
      local_248[0xac] = 0xc;
      local_248[0xad] = 6;
      local_248[0xae] = 4;
      local_248[0xaf] = 3;
      local_248[0xb0] = 0xc;
      local_248[0xb1] = 4;
      local_248[0xb2] = 0xc;
      local_248[0xb3] = 3;
      local_248[0xb4] = 4;
      local_248[0xb5] = 6;
      local_248[0xb6] = 0xc;
      local_248[0xb7] = 3;
      local_248[0xb8] = 0xc;
      local_248[0xb9] = 6;
      local_248[0xba] = 4;
      local_248[0xbb] = 3;
      local_248[0xbc] = 0xc;
      local_248[0xbd] = 2;
      local_248[0xbe] = 0xc;
      local_248[0xbf] = 3;
      local_248[0xc0] = 4;
      local_248[0xc1] = 6;
      local_248[0xc2] = 0xc;
      local_248[0xc3] = 1;
      local_248[0xc4] = 0xc;
      local_248[0xc5] = 6;
      local_248[0xc6] = 0xc;
      local_248[199] = 3;
      local_248[200] = 0x1e;
      local_248[0xc9] = 0xf;
      local_248[0xca] = 10;
      local_248[0xcb] = 0xf;
      local_248[0xcf] = 0xf;
      local_248[0xd5] = 0xf;
      local_248[0xd7] = 0xf;
      local_248[0xdd] = 0xf;
      local_248[0xe1] = 0xf;
      local_248[0xe3] = 0xf;
      local_248[0xe7] = 0xf;
      local_248[0xe9] = 0xf;
      local_248[0xed] = 0xf;
      iVar3 = (&DAT_0041d548)[DVar4];
      local_248[0xcc] = 6;
      local_248[0xcd] = 5;
      local_248[0xce] = 0x1e;
      local_248[0xd0] = 10;
      local_248[0xd1] = 3;
      local_248[0xd2] = 0x1e;
      local_248[0xd3] = 5;
      local_248[0xd4] = 0x1e;
      local_248[0xd6] = 2;
      local_248[0xd8] = 0x1e;
      local_248[0xd9] = 5;
      local_248[0xda] = 0x1e;
      local_248[0xdb] = 3;
      local_248[0xdc] = 10;
      local_248[0xde] = 0x1e;
      local_248[0xdf] = 5;
      local_248[0xe0] = 6;
      local_248[0xe2] = 10;
      local_248[0xe4] = 0x1e;
      local_248[0xe5] = 1;
      local_248[0xe6] = 0x1e;
      local_248[0xe8] = 10;
      local_248[0xea] = 6;
      local_248[0xeb] = 5;
      local_248[0xec] = 0x1e;
      local_248[0xee] = 10;
      local_248[0xef] = 3;
      local_248[0xf0] = 1;
      local_248[0xf1] = 1;
      local_248[0xf2] = 1;
      local_248[0xf3] = 1;
      local_248[0xf4] = 1;
      local_248[0xf5] = 1;
      local_248[0xf6] = 1;
      local_248[0xf7] = 1;
      local_248[0xf8] = 1;
      local_248[0xf9] = 1;
      local_248[0xfa] = 1;
      local_248[0xfb] = 1;
      local_248[0xfc] = 1;
      local_248[0xfd] = 1;
      local_248[0xfe] = 1;
      local_248[0xff] = 1;
      local_248[0x100] = 1;
      local_248[0x101] = 1;
      local_248[0x102] = 1;
      local_248[0x103] = 1;
      local_248[0x104] = 1;
      local_248[0x105] = 1;
      local_248[0x106] = 1;
      local_248[0x107] = 1;
      local_248[0x108] = 1;
      local_248[0x109] = 1;
      local_248[0x10a] = 1;
      local_248[0x10b] = 1;
      local_248[0x10c] = 1;
      local_248[0x10d] = 1;
      local_248[0x10e] = 1;
      local_248[0x10f] = 1;
      local_248[0x110] = 1;
      local_248[0x111] = 1;
      local_248[0x112] = 1;
      local_248[0x113] = 1;
      local_248[0x114] = 1;
      local_248[0x115] = 1;
      local_248[0x116] = 1;
      local_248[0x117] = 1;
      if (5 < iVar3) {
        iVar3 = 5;
      }
      local_18[0] = 2;
      local_18[1] = 2;
      local_18[2] = 3;
      local_18[3] = 2;
      local_18[4] = 5;
      local_18[5] = 2;
      local_25d = 1;
      local_260 = 2;
      local_25f = 0x9a;
      iVar3 = DAT_00418534 / 100 + local_18[iVar3] * 0x28;
      uVar1 = local_248[iVar3 + 0x118];
      uVar2 = local_248[iVar3];
      local_25e = 0x12;
      local_25c = 0;
      local_259 = 0x10;
      local_258 = 0;
      local_25b = uVar1;
      local_25a = uVar2;
      FUN_004026f0(&DAT_0041d180,DVar4,&local_260,&local_260,8);
      Sleep(0xc);
      local_254 = 2;
      local_253 = 0x9a;
      local_252 = 0x12;
      local_251 = 2;
      local_250 = 0;
      local_24d = 0x10;
      local_24c = 0;
      local_24f = uVar1;
      local_24e = uVar2;
      FUN_004026f0(&DAT_0041d180,DVar4,&local_254,&local_254,8);
      Sleep(0xc);
      local_26c = 2;
      local_26b = 0x9a;
      local_26a = 0x12;
      local_269 = 0;
      local_268 = 0;
      local_267 = 7;
      local_266 = 0;
      local_265 = 0x10;
      local_264 = 0;
      FUN_004026f0(&DAT_0041d180,DVar4,&local_26c,&local_26c,8);
      Sleep(0xc);
      return DAT_00418534;
    }
  }
  return 0;
}



/* ==== FUN_00412260 @ 00412260 ==== */

void FUN_00412260(int param_1)

{
  int iVar1;
  DWORD DVar2;
  DWORD DVar3;
  int *piVar4;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined local_11;
  
  DVar3 = 0;
  iVar1 = FUN_004026e0(0x41d180);
  DVar2 = 0xffffffff;
  if (0 < iVar1) {
    piVar4 = &DAT_0041d598;
    do {
      if ((*piVar4 == 2) && (iVar1 = FUN_00401600(&DAT_0041d180,DVar3), DVar2 = DVar3, 0x28 < iVar1)
         ) break;
      DVar3 = DVar3 + 1;
      piVar4 = piVar4 + 1;
      iVar1 = FUN_004026e0(0x41d180);
      DVar2 = 0xffffffff;
    } while ((int)DVar3 < iVar1);
  }
  iVar1 = FUN_00401600(&DAT_0041d180,DVar2);
  if (0x28 < iVar1) {
    if (2 < param_1) {
      param_1 = 2;
    }
    local_11 = (undefined)param_1;
    local_14 = 2;
    local_13 = 0x97;
    local_12 = 0xc;
    FUN_004026f0(&DAT_0041d180,DVar2,&local_14,&local_14,3);
    Sleep(10);
  }
  return;
}



/* ==== FUN_00412310 @ 00412310 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00412310(LPVOID param_1)

{
  undefined4 *puVar1;
  LPVOID local_4;
  
  local_4 = param_1;
  if (_DAT_0041f004 != 0) {
    CString::operator=((CString *)&DAT_0041d74c,s_Test_EEPROM_0041920c);
    _DAT_0041f004 = _DAT_0041f004 | 0x80;
    return;
  }
  puVar1 = &DAT_0041ec5c;
  do {
    *puVar1 = 1;
    puVar1 = puVar1 + 7;
  } while ((int)puVar1 < 0x41ee00);
  CString::operator=((CString *)&DAT_0041d74c,s_Stop_Test_00419cd4);
  _DAT_0041f004 = 1;
  CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_004048b0,param_1,0,
               (LPDWORD)&local_4);
  return;
}



/* ==== FUN_00412390 @ 00412390 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CString * FUN_00412390(void)

{
  CString *pCVar1;
  CString *extraout_EAX;
  CString *extraout_ECX;
  CString *extraout_ECX_00;
  CString *extraout_ECX_01;
  CString *extraout_ECX_02;
  CString *extraout_ECX_03;
  CString *this;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  CString *pCStack_14;
  undefined auStack_10 [2];
  uint uStack_e;
  
  _DAT_0041ec6c = 10;
  _DAT_0041ec70 = 0x186;
  iVar5 = 0;
  _DAT_0041ec74 = 4;
  DAT_0041ec5c = 0;
  _DAT_0041ec68 = 0xffff;
  pCVar1 = (CString *)FUN_004026e0(0x41d180);
  this = extraout_ECX;
  iVar2 = -1;
  if (0 < (int)pCVar1) {
    piVar3 = &DAT_0041d598;
    do {
      if ((*piVar3 == 2) &&
         (pCVar1 = (CString *)FUN_00401600(&DAT_0041d180,iVar5), this = extraout_ECX_00,
         iVar2 = iVar5, 0x28 < (int)pCVar1)) break;
      iVar5 = iVar5 + 1;
      piVar3 = piVar3 + 1;
      pCVar1 = (CString *)FUN_004026e0(0x41d180);
      this = extraout_ECX_01;
      iVar2 = -1;
    } while (iVar5 < (int)pCVar1);
  }
  _DAT_0041ec88 = 10;
  _DAT_0041ec8c = 0x1b8;
  if (iVar2 == -1) {
    CString::operator=((CString *)&DAT_0041ec80,s_error___00419d10);
    _DAT_0041ec90 = 4;
    DAT_0041ec78 = 0;
    _DAT_0041ec84 = 0xff;
    DAT_0041effc = 1;
    return (CString *)0x0;
  }
  iVar5 = 0;
  do {
    if ((DAT_0041f004 & 0x80) != 0) {
      DAT_0041effc = 1;
      return pCVar1;
    }
    iVar4 = 0;
    do {
      CString::Format(this,&DAT_0041ec64);
      DAT_0041effc = 1;
      FUN_00401210(&DAT_0041d180,iVar2,iVar4,(char)(iVar5 % 0xff));
      Sleep(1);
      FUN_00401310(&DAT_0041d180,iVar2,iVar4,auStack_10);
      if ((uStack_e & 0xff) == iVar5 % 0xff) {
        pCStack_14 = (CString *)0x0;
        Sleep(1);
        pCVar1 = extraout_EAX;
        this = extraout_ECX_03;
      }
      else {
        iVar5 = iVar5 + -1;
        pCVar1 = pCStack_14 + 1;
        this = extraout_ECX_02;
        pCStack_14 = pCVar1;
        if (2 < (int)pCVar1) {
          pCVar1 = CString::operator=((CString *)&DAT_0041ec80,s_error___00419d10);
          DAT_0041ec78 = 0;
          _DAT_0041ec84 = 0xff;
          _DAT_0041ec90 = 4;
          DAT_0041effc = 1;
          return pCVar1;
        }
      }
      iVar4 = iVar4 + 0x80;
    } while (iVar4 < 0x800);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 100000);
  DAT_0041effc = 1;
  return pCVar1;
}



/* ==== FUN_00412560 @ 00412560 ==== */

void __fastcall FUN_00412560(void *param_1)

{
  undefined4 unaff_ESI;
  
  CWnd::SetFocus((CWnd *)((int)param_1 + 0x60));
  DAT_0041f008 = 0;
  FUN_0040a610(param_1,1,unaff_ESI);
  return;
}



/* ==== FUN_004125b0 @ 004125b0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004125b0(void *this,HRAWINPUT param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  UINT UVar1;
  LPCSTR extraout_ECX;
  uint uVar2;
  LPCSTR pCVar3;
  COLORREF CVar4;
  int iVar5;
  int iVar6;
  CString local_40c [4];
  CString local_408 [4];
  uint local_404;
  CString local_400 [4];
  CString local_3fc [4];
  CString local_3f8 [4];
  undefined *local_3f4 [4];
  int local_3e4;
  char local_3db;
  char local_3d9;
  uint local_3d8;
  int iStack_3d4;
  void *local_c;
  undefined *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00414a17;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CString::CString(local_408,&DAT_00418904);
  local_4 = 0;
  GetRawInputData(param_1,0x10000003,(LPVOID)0x0,&local_404,0x10);
  if ((local_404 < 1000) &&
     (UVar1 = GetRawInputData(param_1,0x10000003,local_3f4,&local_404,0x10), UVar1 == local_404)) {
    CString::operator=(local_408,&DAT_00419e94);
    if (local_3f4[0] == (undefined *)0x2) {
      if (local_3e4 == 8) {
        if (local_3d9 == '\x03') {
          DAT_0041d178 = DAT_0041d178 + (char)local_3d8;
          DAT_0041d170 = DAT_0041d170 + (char)local_3d8 * 10;
          FUN_00409100((LPCSTR)this);
        }
        else if (local_3db == '\n') {
          DAT_0041d178 = DAT_0041d178 - local_3d9;
          DAT_0041d170 = DAT_0041d170 + local_3d9 * 10;
          FUN_00409100((LPCSTR)this);
          uVar2 = (local_3d8 >> 8 & 0xff) << 8;
          CString::CString(local_3fc);
          local_4._0_1_ = 1;
          CString::CString(local_40c);
          local_4._0_1_ = 2;
          CString::CString(local_400);
          local_4 = CONCAT31(local_4._1_3_,3);
          if ((uVar2 & 0x400) != 0) {
            CString::operator=(local_40c,&DAT_00419d98);
          }
          if ((uVar2 & 0x800) != 0) {
            CString::operator=(local_40c,&DAT_00419d90);
          }
          if ((uVar2 & 0x8000) != 0) {
            CString::operator=(local_40c,&DAT_00419d88);
          }
          CString::Format(local_408,(char *)local_408);
          iVar6 = 1;
          iVar5 = 2;
          CVar4 = 0xffff;
          local_3f4[0] = &stack0xfffffbd8;
          pCVar3 = extraout_ECX;
          CString::CString((CString *)&stack0xfffffbd8,(CString *)&local_404);
          FUN_00407cf0(this,5,0xfa,pCVar3,CVar4,iVar5,iVar6);
          CString::~CString(local_3fc);
          CString::~CString(local_408);
          CString::~CString(local_3f8);
        }
      }
    }
    else if (local_3f4[0] == (undefined *)0x0) {
      if ((local_3d8 != 0) || (iStack_3d4 != 0)) {
        *(undefined4 *)(&DAT_0041a228 + DAT_0041f03c * 4) = param_4;
        DAT_0041f03c = (DAT_0041f03c + 1) % 2000;
        _DAT_0041f038 = param_4;
      }
      if ((DAT_0041f008 == 7) || (DAT_0041f008 == 9)) {
        DAT_0041ee14 = DAT_0041ee14 + iStack_3d4;
        DAT_0041ee10 = DAT_0041ee10 + local_3d8;
        CString::Format(DAT_0041ee14,&DAT_0041ec10);
        DAT_0041effc = 1;
      }
    }
    else {
      uVar2 = 0;
      if (local_404 != 0) {
        do {
          CString::CString((CString *)&stack0xfffffbf0);
          puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,4);
          CString::Format((CString *)&stack0xfffffbf0,(char *)&stack0xfffffbf0);
          CString::operator+=(local_408,local_40c);
          local_4 = local_4 & 0xffffff00;
          CString::~CString(local_40c);
          uVar2 = uVar2 + 1;
        } while (uVar2 < local_404);
      }
      CString::operator+=(local_408,s__00419d18);
    }
  }
  local_4 = 0xffffffff;
  CString::~CString(local_408);
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00412900 @ 00412900 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00412900(undefined4 param_1,void *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  float10 fVar5;
  int local_60;
  byte local_5c;
  uint local_54;
  undefined4 local_50;
  CString local_4c [4];
  undefined8 local_48;
  CString *local_40;
  undefined uStack_3c;
  undefined uStack_3b;
  undefined uStack_3a;
  undefined uStack_39;
  undefined local_38;
  undefined local_37;
  undefined local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  undefined local_32;
  byte local_31;
  byte local_30;
  undefined local_28 [2];
  byte local_26;
  undefined local_24 [4];
  undefined local_20 [12];
  void *pvStack_14;
  undefined *puStack_10;
  void *local_c;
  
  local_c = (void *)0xffffffff;
  puStack_10 = &LAB_00414a38;
  pvStack_14 = ExceptionList;
  puVar3 = &DAT_0041ebec;
  ExceptionList = &pvStack_14;
  do {
    *puVar3 = 1;
    puVar3 = puVar3 + 7;
  } while ((int)puVar3 < 0x41ee00);
  if (DAT_0041f078 != 0) {
    _DAT_0041ebfc = 10;
    _DAT_0041ec00 = 0xbe;
    _DAT_0041ec04 = 4;
    DAT_0041ebec = 0;
    _DAT_0041ebf8 = 0xffff;
    CString::operator=((CString *)&DAT_0041ebf4,(ushort *)&DAT_00419c4c);
    uStack_3c = 0;
    uStack_3b = 3;
    uStack_3a = 0;
    FUN_004038a0(param_2,0,&uStack_3c,local_28,8);
    local_5c = 0;
    local_60 = CONCAT31(local_60._1_3_,local_26);
    CString::CString((CString *)&local_54);
    local_c = (void *)0x0;
    bVar1 = local_26;
    while( true ) {
      fVar5 = FUN_0040ff00();
      local_48 = (double)fVar5;
      if (fVar5 != (float10)_DAT_00415b98) {
        local_48 = local_48 * _DAT_00415b30;
      }
      CString::Format((CString *)local_48,&DAT_0041ebf4);
      DAT_0041effc = 1;
      if ((_DAT_00418568 - _DAT_00418578 <= (double)CONCAT44(local_40,local_48._4_4_)) &&
         ((double)CONCAT44(local_40,local_48._4_4_) <= _DAT_00418578 + _DAT_00418568)) break;
      if (local_60 == 0) {
        if (bVar1 < 0x7f) goto LAB_00412aba;
        local_38 = 0;
        bVar1 = 0x26;
        local_5c = 0x26;
        local_37 = 3;
        local_36 = 1;
        local_35 = 0x26;
        local_34 = 0xd9;
        FUN_004038a0(param_2,0,&local_38,local_24,10);
      }
      else {
        if (0x10 < local_60) goto LAB_00412c61;
LAB_00412aba:
        if ((double)CONCAT44(local_40,local_48._4_4_) != _DAT_00415b98) {
          uVar4 = local_54 & 0xff;
          local_48._0_4_ = (CString *)0x7f;
          CString::Format(local_40,(char *)&local_50);
          if (_DAT_00418568 - _DAT_00418578 <=
              (double)CONCAT17(uStack_39,
                               CONCAT16(uStack_3a,CONCAT15(uStack_3b,CONCAT14(uStack_3c,local_40))))
             ) {
            if (_DAT_00418578 + _DAT_00418568 <
                (double)CONCAT17(uStack_39,
                                 CONCAT16(uStack_3a,CONCAT15(uStack_3b,CONCAT14(uStack_3c,local_40))
                                         ))) {
              local_50 = CONCAT31(local_50._1_3_,bVar1);
              uVar4 = (uint)local_48._4_4_;
              goto LAB_00412b47;
            }
          }
          else {
            local_54 = CONCAT31(local_54._1_3_,bVar1);
LAB_00412b47:
            bVar1 = (byte)((int)(uVar4 + local_26) / 2);
            local_60 = CONCAT31(local_60._1_3_,bVar1);
          }
          local_30 = ~bVar1;
          local_34 = 0;
          local_33 = 3;
          local_32 = 1;
          local_31 = bVar1;
          FUN_004038a0(param_2,0,&local_34,local_20,10);
        }
      }
      Sleep(0x17c);
    }
    if ((double)CONCAT44(local_40,local_48._4_4_) != _DAT_00415b98) {
      _DAT_0041ebf8 = 0xff00;
      uVar2 = _ftol();
      local_48._0_4_ = (CString *)CONCAT31(local_48._1_3_,(char)uVar2);
      Sleep(10);
      local_34 = (byte)local_48;
      local_33 = ~(byte)local_48;
      local_38 = 0;
      local_37 = 9;
      local_36 = 1;
      local_35 = 0x19;
      FUN_004038a0(param_2,0,&local_38,local_24,10);
      Sleep(8);
      local_34 = (byte)((ushort)uVar2 >> 8);
      local_33 = ~local_34;
      local_38 = 0;
      local_37 = 9;
      local_36 = 1;
      local_35 = 0x1a;
      FUN_004038a0(param_2,0,&local_38,local_24,10);
      Sleep(8);
      FUN_00403b90(param_2,0);
      local_40 = local_48._4_4_;
      goto LAB_00412cac;
    }
LAB_00412c61:
    local_35 = local_5c;
    local_34 = ~local_5c;
    local_38 = 0;
    local_37 = 3;
    local_36 = 1;
    FUN_004038a0(param_2,0,&local_38,local_24,0);
    _DAT_0041ebf8 = 0xff;
LAB_00412cac:
    CString::Format(local_40,&DAT_0041ebf4);
    DAT_0041effc = 1;
    CString::~CString(local_4c);
  }
  ExceptionList = local_c;
  return;
}



/* ==== FUN_00412cf0 @ 00412cf0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00412cf0(void)

{
  int iVar1;
  undefined4 uVar2;
  CString *extraout_ECX;
  CString *extraout_ECX_00;
  CString *extraout_ECX_01;
  CString *extraout_ECX_02;
  CString *extraout_ECX_03;
  CString *extraout_ECX_04;
  CString *extraout_ECX_05;
  CString *extraout_ECX_06;
  CString *extraout_ECX_07;
  CString *extraout_ECX_08;
  CString *extraout_ECX_09;
  CString *extraout_ECX_10;
  CString *this;
  CString aCStack_8e8 [4];
  CString CStack_8e4;
  undefined uStack_8e3;
  undefined uStack_8e2;
  byte bStack_8e1;
  byte bStack_8e0;
  undefined uStack_8df;
  undefined uStack_8dc;
  undefined auStack_8d0 [2];
  byte bStack_8ce;
  byte bStack_8cd;
  char cStack_8ca;
  byte bStack_8c9;
  undefined4 uStack_8bc;
  undefined4 local_8b8;
  undefined auStack_8b4 [2052];
  int iStack_b0;
  void *pvStack_c;
  undefined *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00414a66;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00403000(&local_8b8);
  local_4 = 0;
  FUN_00403210((int)&local_8b8);
  iVar1 = FUN_004026e0((int)&local_8b8);
  if (iVar1 == 0) {
    local_4 = 0xffffffff;
    FUN_00403120(&local_8b8);
    ExceptionList = pvStack_c;
    return 0;
  }
  DAT_0041efec = 0;
  CString::Empty((CString *)&DAT_0041ebf4);
  _DAT_0041ebfc = 10;
  _DAT_0041ec00 = 0xa0;
  _DAT_0041ec04 = 4;
  DAT_0041ebec = 0;
  CStack_8e4 = (CString)0x0;
  uStack_8e3 = 10;
  uStack_8e2 = 0;
  bStack_8e1 = 0;
  uStack_8dc = 0x12;
  FUN_004038a0(&local_8b8,0,&CStack_8e4,auStack_8d0,8);
  Sleep(10);
  bStack_8e1 = bStack_8ce;
  bStack_8e0 = bStack_8cd | 0x40;
  CStack_8e4 = (CString)0x0;
  uStack_8e3 = 10;
  uStack_8e2 = 1;
  uStack_8dc = 0x12;
  FUN_004038a0(&local_8b8,0,&CStack_8e4,auStack_8d0,4);
  Sleep(10);
  CStack_8e4 = (CString)0x0;
  uStack_8e3 = 9;
  uStack_8e2 = 1;
  bStack_8e1 = 5;
  bStack_8e0 = 0x16;
  uStack_8df = 0xe9;
  Sleep(10);
  CStack_8e4 = (CString)0x0;
  uStack_8e3 = 9;
  uStack_8e2 = 0;
  bStack_8e1 = 4;
  bStack_8e0 = 0x16;
  uStack_8dc = 0xf3;
  Sleep(100);
  do {
    if ((DAT_0041f004 & 0x80) != 0) {
LAB_00413061:
      CString::operator=((CString *)&DAT_0041ec10,&DAT_00418e84);
      _DAT_0041ec18 = 10;
      _DAT_0041ec1c = 200;
      _DAT_0041ec20 = 4;
      DAT_0041ec08 = 0;
      _DAT_0041ec14 = 0xff;
      if (DAT_0041efec == 1) {
        CString::operator=((CString *)&DAT_0041ec10,&DAT_004196cc);
        _DAT_0041ec14 = 0xff00;
        CStack_8e4 = (CString)0x0;
        uStack_8e3 = 10;
        uStack_8e2 = 1;
        bStack_8e1 = 0xff;
        bStack_8e0 = 0x8c;
        uStack_8dc = 0x12;
        FUN_004038a0(&local_8b8,0,&CStack_8e4,auStack_8d0,4);
        uStack_8bc = 2;
        if (iStack_b0 == 2) {
          uStack_8bc = 3;
        }
        Sleep(2);
        bStack_8e1 = (undefined)uStack_8bc;
        CStack_8e4 = (CString)0x0;
        uStack_8e3 = 1;
        uStack_8e2 = 0x87;
        uStack_8dc = 0x12;
        FUN_004038a0(&local_8b8,0,&CStack_8e4,auStack_8d0,8);
        CStack_8e4 = (CString)0x0;
        uStack_8e3 = 1;
        uStack_8e2 = 0x88;
        bStack_8e1 = 0;
        uStack_8dc = 0x12;
        FUN_004038a0(&local_8b8,0,&CStack_8e4,auStack_8d0,8);
        FUN_00403a70(&local_8b8,0);
      }
      DAT_0041effc = 1;
      local_4 = 0xffffffff;
      uVar2 = FUN_00403120(&local_8b8);
      ExceptionList = pvStack_c;
      return uVar2;
    }
    CStack_8e4 = (CString)0x0;
    uStack_8e3 = 10;
    uStack_8e2 = 0;
    bStack_8e1 = 0;
    uStack_8dc = 0x12;
    FUN_004038a0(&local_8b8,0,&CStack_8e4,auStack_8d0,8);
    CString::CString(aCStack_8e8);
    local_4 = CONCAT31(local_4._1_3_,1);
    this = extraout_ECX;
    if ((bStack_8ce & 1) != 0) {
      CString::operator=(aCStack_8e8,s_Left_00419e3c);
      this = extraout_ECX_00;
    }
    if ((bStack_8ce & 2) != 0) {
      CString::operator+=(aCStack_8e8,s_Right_00419e34);
      this = extraout_ECX_01;
    }
    if ((bStack_8ce & 4) != 0) {
      CString::operator+=(aCStack_8e8,s_Middle_00419e28);
      this = extraout_ECX_02;
    }
    if ((bStack_8ce & 8) != 0) {
      CString::operator+=(aCStack_8e8,&DAT_00419e20);
      this = extraout_ECX_03;
    }
    if ((bStack_8ce & 0x10) != 0) {
      CString::operator+=(aCStack_8e8,&DAT_00419e18);
      this = extraout_ECX_04;
    }
    if ((bStack_8ce & 0x20) != 0) {
      CString::operator+=(aCStack_8e8,s_Adjust_Lift_00419e08);
      this = extraout_ECX_05;
    }
    if ((bStack_8ce & 0x40) != 0) {
      CString::operator+=(aCStack_8e8,s_Tilt_Left_00419dfc);
      this = extraout_ECX_06;
    }
    if ((bStack_8ce & 0x80) != 0) {
      CString::operator+=(aCStack_8e8,s_Tilt_Right_00419dec);
      this = extraout_ECX_07;
    }
    if ((bStack_8cd & 0x80) != 0) {
      CString::operator+=(aCStack_8e8,s_Mode_00419de4);
      this = extraout_ECX_08;
    }
    if ((bStack_8cd & 4) != 0) {
      CString::operator+=(aCStack_8e8,s_DPI__00419ddc);
      this = extraout_ECX_09;
    }
    if ((bStack_8cd & 8) != 0) {
      CString::operator+=(aCStack_8e8,s_DPI__00419dd4);
      this = extraout_ECX_10;
    }
    CString::Format(this,&DAT_0041ebf4);
    _DAT_0041ebf8 = 0xff;
    DAT_0041effc = 1;
    iVar1 = FUN_004015e0(auStack_8b4,0);
    if (((iVar1 == 0) && (cStack_8ca == -1)) && ((bStack_8c9 & 0x8c) == 0x8c)) {
LAB_0041303d:
      _DAT_0041ebf8 = 0xff00;
      DAT_0041efec = 1;
      CString::~CString(&CStack_8e4);
      goto LAB_00413061;
    }
    iVar1 = FUN_004015e0(auStack_8b4,0);
    if (iVar1 == 5) {
LAB_00412fe5:
      if ((cStack_8ca == -0x21) && ((bStack_8c9 & 0x8c) == 0x8c)) goto LAB_0041303d;
    }
    else {
      iVar1 = FUN_004015e0(auStack_8b4,0);
      if (iVar1 == 2) goto LAB_00412fe5;
    }
    iVar1 = FUN_004015e0(auStack_8b4,0);
    if (iVar1 == 1) {
LAB_00413016:
      if ((cStack_8ca == -0x21) && (bStack_8c9 == 0xc4)) goto LAB_0041303d;
    }
    else {
      iVar1 = FUN_004015e0(auStack_8b4,0);
      if (iVar1 == 4) goto LAB_00413016;
    }
    Sleep(10);
    local_4 = local_4 & 0xffffff00;
    CString::~CString(aCStack_8e8);
  } while( true );
}



/* ==== FUN_004131c0 @ 004131c0 ==== */

undefined4 FUN_004131c0(void)

{
  return 0;
}



/* ==== FUN_004131f0 @ 004131f0 ==== */

void __thiscall FUN_004131f0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined ***)this = &PTR_LAB_00415ba8;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return;
}



/* ==== FUN_00413220 @ 00413220 ==== */

void __fastcall FUN_00413220(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00414a88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_00415ba8;
  puVar1 = (undefined4 *)param_1[1];
  local_4 = 0;
  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
  }
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  CPlex::FreeDataChain((CPlex *)param_1[5]);
  param_1[5] = 0;
  *param_1 = &PTR_LAB_004154b0;
  ExceptionList = local_c;
  return;
}



/* ==== FUN_004134a0 @ 004134a0 ==== */

undefined4 * __thiscall FUN_004134a0(void *this,byte param_1)

{
  FUN_00413220((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



/* ==== FUN_004134c0 @ 004134c0 ==== */

void __fastcall FUN_004134c0(int param_1)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  CPlex::FreeDataChain(*(CPlex **)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* ==== HidD_GetProductString @ 004134f0 ==== */

void HidD_GetProductString(void)

{
                    /* WARNING: Could not recover jumptable at 0x004134f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_GetProductString();
  return;
}



/* ==== HidD_GetSerialNumberString @ 004134f6 ==== */

void HidD_GetSerialNumberString(void)

{
                    /* WARNING: Could not recover jumptable at 0x004134f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_GetSerialNumberString();
  return;
}



/* ==== HidD_GetManufacturerString @ 004134fc ==== */

void HidD_GetManufacturerString(void)

{
                    /* WARNING: Could not recover jumptable at 0x004134fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_GetManufacturerString();
  return;
}



/* ==== HidD_GetAttributes @ 00413502 ==== */

void HidD_GetAttributes(void)

{
                    /* WARNING: Could not recover jumptable at 0x00413502. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_GetAttributes();
  return;
}



/* ==== HidD_FreePreparsedData @ 00413508 ==== */

void HidD_FreePreparsedData(void)

{
                    /* WARNING: Could not recover jumptable at 0x00413508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_FreePreparsedData();
  return;
}



/* ==== HidP_GetCaps @ 0041350e ==== */

void HidP_GetCaps(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041350e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidP_GetCaps();
  return;
}



/* ==== HidD_GetPreparsedData @ 00413514 ==== */

void HidD_GetPreparsedData(void)

{
                    /* WARNING: Could not recover jumptable at 0x00413514. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_GetPreparsedData();
  return;
}



/* ==== HidD_GetHidGuid @ 0041351a ==== */

void HidD_GetHidGuid(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041351a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_GetHidGuid();
  return;
}



/* ==== HidD_GetIndexedString @ 00413520 ==== */

void HidD_GetIndexedString(void)

{
                    /* WARNING: Could not recover jumptable at 0x00413520. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_GetIndexedString();
  return;
}



/* ==== HidD_SetFeature @ 00413526 ==== */

void HidD_SetFeature(void)

{
                    /* WARNING: Could not recover jumptable at 0x00413526. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_SetFeature();
  return;
}



/* ==== HidD_GetFeature @ 0041352c ==== */

void HidD_GetFeature(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041352c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HidD_GetFeature();
  return;
}



/* ==== CString @ 00413532 ==== */

void __thiscall CString::CString(CString *this)

{
                    /* WARNING: Could not recover jumptable at 0x00413532. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CString(this);
  return;
}



/* ==== ~CString @ 00413538 ==== */

void __thiscall CString::~CString(CString *this)

{
                    /* WARNING: Could not recover jumptable at 0x00413538. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CString(this);
  return;
}



/* ==== operator_delete @ 0041353e ==== */

void __cdecl operator_delete(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0041353e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator_delete(param_1);
  return;
}



/* ==== Empty @ 00413544 ==== */

void __thiscall CString::Empty(CString *this)

{
                    /* WARNING: Could not recover jumptable at 0x00413544. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Empty(this);
  return;
}



/* ==== CString @ 0041354a ==== */

void __thiscall CString::CString(CString *this,CString *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0041354a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CString(this,param_1);
  return;
}



/* ==== operator= @ 00413550 ==== */

CString * __thiscall CString::operator=(CString *this,ushort *param_1)

{
  CString *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = operator=(this,param_1);
  return pCVar1;
}



/* ==== operator= @ 00413556 ==== */

CString * __thiscall CString::operator=(CString *this,CString *param_1)

{
  CString *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413556. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = operator=(this,param_1);
  return pCVar1;
}



/* ==== CString @ 0041355c ==== */

void __thiscall CString::CString(CString *this,ushort *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0041355c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CString(this,param_1);
  return;
}



/* ==== Format @ 00413562 ==== */

void __thiscall CString::Format(CString *this,char *param_1,...)

{
                    /* WARNING: Could not recover jumptable at 0x00413562. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Format(this,param_1);
  return;
}



/* ==== operator= @ 00413568 ==== */

CString * __thiscall CString::operator=(CString *this,char *param_1)

{
  CString *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413568. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = operator=(this,param_1);
  return pCVar1;
}



/* ==== FreeDataChain @ 00413574 ==== */

void __thiscall CPlex::FreeDataChain(CPlex *this)

{
                    /* WARNING: Could not recover jumptable at 0x00413574. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FreeDataChain(this);
  return;
}



/* ==== DestructElements @ 0041357a ==== */

void DestructElements(CString *param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0041357a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DestructElements(param_1,param_2);
  return;
}



/* ==== ConstructElements @ 00413580 ==== */

void ConstructElements(CString *param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00413580. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ConstructElements(param_1,param_2);
  return;
}



/* ==== Create @ 00413586 ==== */

CPlex * CPlex::Create(CPlex **param_1,uint param_2,uint param_3)

{
  CPlex *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413586. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = Create(param_1,param_2,param_3);
  return pCVar1;
}



/* ==== operator_new @ 0041358c ==== */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041358c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



/* ==== ReadCount @ 00413592 ==== */

ulong __thiscall CArchive::ReadCount(CArchive *this)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413592. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = ReadCount(this);
  return uVar1;
}



/* ==== SerializeElements @ 00413598 ==== */

void SerializeElements(CArchive *param_1,CString *param_2,int param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00413598. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SerializeElements(param_1,param_2,param_3);
  return;
}



/* ==== Read @ 0041359e ==== */

uint __thiscall CArchive::Read(CArchive *this,void *param_1,uint param_2)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041359e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = Read(this,param_1,param_2);
  return uVar1;
}



/* ==== Write @ 004135a4 ==== */

void __thiscall CArchive::Write(CArchive *this,void *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x004135a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Write(this,param_1,param_2);
  return;
}



/* ==== WriteCount @ 004135aa ==== */

void __thiscall CArchive::WriteCount(CArchive *this,ulong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x004135aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WriteCount(this,param_1);
  return;
}



/* ==== DoModal @ 004135c2 ==== */

int __thiscall CDialog::DoModal(CDialog *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004135c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = DoModal(this);
  return iVar1;
}



/* ==== DefWindowProcA @ 004135e6 ==== */

long __thiscall CWnd::DefWindowProcA(CWnd *this,uint param_1,uint param_2,long param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004135e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = DefWindowProcA(this,param_1,param_2,param_3);
  return lVar1;
}



/* ==== WindowProc @ 004135f2 ==== */

long __thiscall CWnd::WindowProc(CWnd *this,uint param_1,uint param_2,long param_3)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004135f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = WindowProc(this,param_1,param_2,param_3);
  return lVar1;
}



/* ==== PreTranslateMessage @ 004135fe ==== */

int __thiscall CDialog::PreTranslateMessage(CDialog *this,tagMSG *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004135fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = PreTranslateMessage(this,param_1);
  return iVar1;
}



/* ==== OnNotify @ 0041360a ==== */

int __thiscall CWnd::OnNotify(CWnd *this,uint param_1,long param_2,long *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041360a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnNotify(this,param_1,param_2,param_3);
  return iVar1;
}



/* ==== DestroyWindow @ 00413640 ==== */

int __thiscall CWnd::DestroyWindow(CWnd *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413640. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = DestroyWindow(this);
  return iVar1;
}



/* ==== ~CDialog @ 004136b8 ==== */

void __thiscall CDialog::~CDialog(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x004136b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CDialog(this);
  return;
}



/* ==== CDialog @ 004136be ==== */

void __thiscall CDialog::CDialog(CDialog *this,uint param_1,CWnd *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x004136be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDialog(this,param_1,param_2);
  return;
}



/* ==== OnOK @ 004136c4 ==== */

void __thiscall CDialog::OnOK(CDialog *this)

{
                    /* WARNING: Could not recover jumptable at 0x004136c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OnOK(this);
  return;
}



/* ==== GetDlgItemTextA @ 004136ca ==== */

int __thiscall CWnd::GetDlgItemTextA(CWnd *this,int param_1,CString *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004136ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetDlgItemTextA(this,param_1,param_2);
  return iVar1;
}



/* ==== SetDlgItemTextA @ 004136d0 ==== */

void __thiscall CWnd::SetDlgItemTextA(CWnd *this,int param_1,char *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x004136d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetDlgItemTextA(this,param_1,param_2);
  return;
}



/* ==== OnInitDialog @ 004136d6 ==== */

int __thiscall CDialog::OnInitDialog(CDialog *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004136d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = OnInitDialog(this);
  return iVar1;
}



/* ==== CWinApp @ 00413760 ==== */

void __thiscall CWinApp::CWinApp(CWinApp *this,char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00413760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWinApp(this,param_1);
  return;
}



/* ==== ~CWinApp @ 00413766 ==== */

void __thiscall CWinApp::~CWinApp(CWinApp *this)

{
                    /* WARNING: Could not recover jumptable at 0x00413766. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CWinApp(this);
  return;
}



/* ==== ~CButton @ 0041376c ==== */

void __thiscall CButton::~CButton(CButton *this)

{
                    /* WARNING: Could not recover jumptable at 0x0041376c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CButton(this);
  return;
}



/* ==== ~CComboBox @ 00413772 ==== */

void __thiscall CComboBox::~CComboBox(CComboBox *this)

{
                    /* WARNING: Could not recover jumptable at 0x00413772. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CComboBox(this);
  return;
}



/* ==== Enable3dControls @ 00413778 ==== */

int __thiscall CWinApp::Enable3dControls(CWinApp *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413778. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Enable3dControls(this);
  return iVar1;
}



/* ==== AfxEnableControlContainer @ 0041377e ==== */

void __cdecl AfxEnableControlContainer(COccManager *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0041377e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  AfxEnableControlContainer(param_1);
  return;
}



/* ==== AfxFindResourceHandle @ 004137d2 ==== */

HINSTANCE__ * AfxFindResourceHandle(char *param_1,char *param_2)

{
  HINSTANCE__ *pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004137d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = AfxFindResourceHandle(param_1,param_2);
  return pHVar1;
}



/* ==== AfxGetModuleState @ 004137d8 ==== */

AFX_MODULE_STATE * AfxGetModuleState(void)

{
  AFX_MODULE_STATE *pAVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004137d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar1 = AfxGetModuleState();
  return pAVar1;
}



/* ==== CWnd @ 004137de ==== */

void __thiscall CWnd::CWnd(CWnd *this)

{
                    /* WARNING: Could not recover jumptable at 0x004137de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CWnd(this);
  return;
}



/* ==== DDX_Control @ 004137e4 ==== */

void DDX_Control(CDataExchange *param_1,int param_2,CWnd *param_3)

{
                    /* WARNING: Could not recover jumptable at 0x004137e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DDX_Control(param_1,param_2,param_3);
  return;
}



/* ==== SetWindowTextA @ 004137ea ==== */

void __thiscall CWnd::SetWindowTextA(CWnd *this,char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x004137ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetWindowTextA(this,param_1);
  return;
}



/* ==== GetDlgItem @ 004137f0 ==== */

CWnd * __thiscall CWnd::GetDlgItem(CWnd *this,int param_1)

{
  CWnd *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004137f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = GetDlgItem(this,param_1);
  return pCVar1;
}



/* ==== LoadStringA @ 004137f6 ==== */

int __thiscall CString::LoadStringA(CString *this,uint param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004137f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = LoadStringA(this,param_1);
  return iVar1;
}



/* ==== FromHandle @ 004137fc ==== */

CMenu * CMenu::FromHandle(HMENU__ *param_1)

{
  CMenu *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004137fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = FromHandle(param_1);
  return pCVar1;
}



/* ==== Default @ 00413802 ==== */

long __thiscall CWnd::Default(CWnd *this)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413802. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = Default(this);
  return lVar1;
}



/* ==== FromHandle @ 00413808 ==== */

CDC * CDC::FromHandle(HDC__ *param_1)

{
  CDC *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413808. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = FromHandle(param_1);
  return pCVar1;
}



/* ==== operator+= @ 0041381a ==== */

CString * __thiscall CString::operator+=(CString *this,char *param_1)

{
  CString *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041381a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = operator+=(this,param_1);
  return pCVar1;
}



/* ==== operator+= @ 00413820 ==== */

CString * __thiscall CString::operator+=(CString *this,CString *param_1)

{
  CString *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = operator+=(this,param_1);
  return pCVar1;
}



/* ==== SetWindowPos @ 00413826 ==== */

int __thiscall
CWnd::SetWindowPos(CWnd *this,CWnd *param_1,int param_2,int param_3,int param_4,int param_5,
                  uint param_6)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413826. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetWindowPos(this,param_1,param_2,param_3,param_4,param_5,param_6);
  return iVar1;
}



/* ==== ShowWindow @ 0041382c ==== */

int __thiscall CWnd::ShowWindow(CWnd *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041382c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ShowWindow(this,param_1);
  return iVar1;
}



/* ==== EnableWindow @ 00413832 ==== */

int __thiscall CWnd::EnableWindow(CWnd *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413832. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = EnableWindow(this,param_1);
  return iVar1;
}



/* ==== LineTo @ 00413838 ==== */

int __thiscall CDC::LineTo(CDC *this,int param_1,int param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413838. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = LineTo(this,param_1,param_2);
  return iVar1;
}



/* ==== MoveTo @ 0041383e ==== */

void __thiscall CDC::MoveTo(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041383e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MoveTo();
  return;
}



/* ==== CString @ 00413844 ==== */

void __thiscall CString::CString(CString *this,char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00413844. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CString(this,param_1);
  return;
}



/* ==== SetBkMode @ 0041384a ==== */

int __thiscall CDC::SetBkMode(CDC *this,int param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041384a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SetBkMode(this,param_1);
  return iVar1;
}



/* ==== ~CDC @ 00413850 ==== */

void __thiscall CDC::~CDC(CDC *this)

{
                    /* WARNING: Could not recover jumptable at 0x00413850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CDC(this);
  return;
}



/* ==== Detach @ 00413856 ==== */

HDC__ * __thiscall CDC::Detach(CDC *this)

{
  HDC__ *pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413856. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = Detach(this);
  return pHVar1;
}



/* ==== FillSolidRect @ 0041385c ==== */

void __thiscall CDC::FillSolidRect(CDC *this,tagRECT *param_1,ulong param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0041385c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FillSolidRect(this,param_1,param_2);
  return;
}



/* ==== Attach @ 00413862 ==== */

int __thiscall CDC::Attach(CDC *this,HDC__ *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413862. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Attach(this,param_1);
  return iVar1;
}



/* ==== CDC @ 00413868 ==== */

void __thiscall CDC::CDC(CDC *this)

{
                    /* WARNING: Could not recover jumptable at 0x00413868. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CDC(this);
  return;
}



/* ==== operator+ @ 0041386e ==== */

void operator+(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041386e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator+();
  return;
}



/* ==== operator+ @ 00413874 ==== */

void operator+(void)

{
                    /* WARNING: Could not recover jumptable at 0x00413874. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator+();
  return;
}



/* ==== operator+ @ 0041387a ==== */

void operator+(void)

{
                    /* WARNING: Could not recover jumptable at 0x0041387a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  operator+();
  return;
}



/* ==== SetAt @ 00413880 ==== */

void __thiscall CString::SetAt(CString *this,int param_1,char param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00413880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetAt(this,param_1,param_2);
  return;
}



/* ==== GetLBText @ 00413886 ==== */

void __thiscall CComboBox::GetLBText(CComboBox *this,int param_1,CString *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00413886. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetLBText(this,param_1,param_2);
  return;
}



/* ==== MessageBoxA @ 0041388c ==== */

int __thiscall CWnd::MessageBoxA(CWnd *this,char *param_1,char *param_2,uint param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0041388c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = MessageBoxA(this,param_1,param_2,param_3);
  return iVar1;
}



/* ==== ~CFile @ 004138a4 ==== */

void __thiscall CFile::~CFile(CFile *this)

{
                    /* WARNING: Could not recover jumptable at 0x004138a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~CFile(this);
  return;
}



/* ==== Close @ 004138aa ==== */

void __thiscall CFile::Close(CFile *this)

{
                    /* WARNING: Could not recover jumptable at 0x004138aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  Close(this);
  return;
}



/* ==== GetLength @ 004138b0 ==== */

ulong __thiscall CFile::GetLength(CFile *this)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004138b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = GetLength(this);
  return uVar1;
}



/* ==== AfxMessageBox @ 004138b6 ==== */

int AfxMessageBox(char *param_1,uint param_2,uint param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004138b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxMessageBox(param_1,param_2,param_3);
  return iVar1;
}



/* ==== Read @ 004138bc ==== */

uint __thiscall CFile::Read(CFile *this,void *param_1,uint param_2)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004138bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = Read(this,param_1,param_2);
  return uVar1;
}



/* ==== Open @ 004138c2 ==== */

int __thiscall CFile::Open(CFile *this,char *param_1,uint param_2,CFileException *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004138c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = Open(this,param_1,param_2,param_3);
  return iVar1;
}



/* ==== CException @ 004138c8 ==== */

void __thiscall CException::CException(CException *this)

{
                    /* WARNING: Could not recover jumptable at 0x004138c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CException(this);
  return;
}



/* ==== CFile @ 004138ce ==== */

void __thiscall CFile::CFile(CFile *this)

{
                    /* WARNING: Could not recover jumptable at 0x004138ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CFile(this);
  return;
}



/* ==== SetFocus @ 004138d4 ==== */

CWnd * __thiscall CWnd::SetFocus(CWnd *this)

{
  CWnd *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004138d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = SetFocus(this);
  return pCVar1;
}



/* ==== FUN_004138da @ 004138da ==== */

void __cdecl FUN_004138da(_onexit_t param_1)

{
  if (DAT_0041f0b4 == -1) {
    _onexit(param_1);
    return;
  }
  __dllonexit(param_1,&DAT_0041f0b4,&DAT_0041f0b0);
  return;
}



/* ==== FUN_00413906 @ 00413906 ==== */

int __cdecl FUN_00413906(_onexit_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_004138da(param_1);
  return (iVar1 != 0) - 1;
}



/* ==== FUN_00413918 @ 00413918 ==== */

void FUN_00413918(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00415bc0;
  puStack_10 = &DAT_00413cee;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*(code *)param_4)();
  }
  local_8 = 0xffffffff;
  FUN_00413980();
  ExceptionList = local_14;
  return;
}



/* ==== FUN_00413980 @ 00413980 ==== */

void FUN_00413980(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    FUN_00413998(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                 *(int *)(unaff_EBP + 0x10),*(undefined **)(unaff_EBP + 0x14));
  }
  return;
}



/* ==== FUN_00413998 @ 00413998 ==== */

void FUN_00413998(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00415bd0;
  puStack_10 = &DAT_00413cee;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*(code *)param_4)();
  }
  ExceptionList = local_14;
  return;
}



/* ==== FUN_00413a0c @ 00413a0c ==== */

void FUN_00413a0c(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  int local_20;
  void *local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00415be0;
  puStack_10 = &DAT_00413cee;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  for (local_20 = 0; local_20 < param_3; local_20 = local_20 + 1) {
    (*(code *)param_4)();
  }
  local_8 = 0xffffffff;
  FUN_00413a76();
  ExceptionList = local_14;
  return;
}



/* ==== FUN_00413a76 @ 00413a76 ==== */

void FUN_00413a76(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    FUN_00413998(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                 *(int *)(unaff_EBP + -0x1c),*(undefined **)(unaff_EBP + 0x18));
  }
  return;
}



/* ==== __alldiv @ 00413aa0 ==== */

/* Library Function - Single Match
    __alldiv
   
   Library: Visual Studio */

undefined8 __alldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;
  
  cVar11 = (int)param_2 < 0;
  if ((bool)cVar11) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar10 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar10 - param_4;
  }
  uVar3 = param_1;
  uVar5 = param_3;
  uVar6 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar5 = uVar5 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar6 = uVar7;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar5;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar5)) ||
       ((param_2 <= uVar5 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT44(uVar3,iVar4);
}



/* ==== __allmul @ 00413b50 ==== */

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



/* ==== _ftol @ 00413b84 ==== */

void _ftol(void)

{
                    /* WARNING: Could not recover jumptable at 0x00413b84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _ftol();
  return;
}



/* ==== entry @ 00413b8a ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  undefined4 *puVar1;
  uint uVar2;
  HMODULE pHVar3;
  byte *pbVar4;
  HINSTANCE__ *pHVar5;
  char **local_74;
  _startupinfo local_70;
  int local_6c;
  char **local_68;
  int local_64;
  _STARTUPINFOA local_60;
  undefined *local_1c;
  void *pvStack_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00415bf0;
  puStack_10 = &DAT_00413cee;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffff78;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  __set_app_type(2);
  _DAT_0041f0b0 = 0xffffffff;
  DAT_0041f0b4 = 0xffffffff;
  puVar1 = (undefined4 *)__p__fmode();
  *puVar1 = DAT_0041f0a4;
  puVar1 = (undefined4 *)__p__commode();
  *puVar1 = DAT_0041f0a0;
  _DAT_0041f0ac = *(undefined4 *)_adjust_fdiv_exref;
  FUN_00413d1b();
  if (DAT_00419e50 == 0) {
    __setusermatherr(&LAB_00413d18);
  }
  FUN_00413d06();
  _initterm(&DAT_0041803c,&DAT_00418040);
  local_70.newmode = DAT_0041f09c;
  __getmainargs(&local_64,&local_74,&local_68,DAT_0041f098,&local_70);
  _initterm(&DAT_00418000,&DAT_00418038);
  pbVar4 = *(byte **)_acmdln_exref;
  if (*pbVar4 != 0x22) {
    do {
      if (*pbVar4 < 0x21) goto LAB_00413c7d;
      pbVar4 = pbVar4 + 1;
    } while( true );
  }
  do {
    pbVar4 = pbVar4 + 1;
    if (*pbVar4 == 0) break;
  } while (*pbVar4 != 0x22);
  if (*pbVar4 != 0x22) goto LAB_00413c7d;
  do {
    pbVar4 = pbVar4 + 1;
LAB_00413c7d:
  } while ((*pbVar4 != 0) && (*pbVar4 < 0x21));
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  if ((local_60.dwFlags & 1) == 0) {
    uVar2 = 10;
  }
  else {
    uVar2 = (uint)local_60.wShowWindow;
  }
  pHVar5 = (HINSTANCE__ *)0x0;
  pHVar3 = GetModuleHandleA((LPCSTR)0x0);
  local_6c = FUN_00413d22(pHVar3,pHVar5,(char *)pbVar4,uVar2);
                    /* WARNING: Subroutine does not return */
  exit(local_6c);
}



/* ==== __dllonexit @ 00413ce8 ==== */

void __dllonexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00413ce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __dllonexit();
  return;
}



/* ==== _XcptFilter @ 00413cfa ==== */

int __cdecl _XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413cfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _XcptFilter(_ExceptionNum,_ExceptionPtr);
  return iVar1;
}



/* ==== _initterm @ 00413d00 ==== */

void _initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00413d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _initterm();
  return;
}



/* ==== FUN_00413d06 @ 00413d06 ==== */

void FUN_00413d06(void)

{
  _controlfp(0x10000,0x30000);
  return;
}



/* ==== FUN_00413d1b @ 00413d1b ==== */

void FUN_00413d1b(void)

{
  return;
}



/* ==== _controlfp @ 00413d1c ==== */

uint __cdecl _controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413d1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = _controlfp(_NewValue,_Mask);
  return uVar1;
}



/* ==== FUN_00413d22 @ 00413d22 ==== */

void FUN_00413d22(HINSTANCE__ *param_1,HINSTANCE__ *param_2,char *param_3,int param_4)

{
  AfxWinMain(param_1,param_2,param_3,param_4);
  return;
}



/* ==== FUN_00413d3a @ 00413d3a ==== */

undefined4 FUN_00413d3a(int param_1,undefined4 param_2)

{
  AFX_MODULE_STATE *pAVar1;
  
  pAVar1 = AfxGetModuleState();
  pAVar1[0x14] = SUB41(param_1,0);
  *(undefined4 *)(pAVar1 + 0x1040) = param_2;
  if (param_1 == 0) {
    _setmbcp(-3);
  }
  return 1;
}



/* ==== AfxWinMain @ 00413d7a ==== */

int AfxWinMain(HINSTANCE__ *param_1,HINSTANCE__ *param_2,char *param_3,int param_4)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00413d7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = AfxWinMain(param_1,param_2,param_3,param_4);
  return iVar1;
}



/* ==== Unwind@00413d80 @ 00413d80 ==== */

void Unwind_00413d80(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 4,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413d96 @ 00413d96 ==== */

void Unwind_00413d96(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x2d8,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413dae @ 00413dae ==== */

void Unwind_00413dae(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x328,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413dc6 @ 00413dc6 ==== */

void Unwind_00413dc6(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x378,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413df0 @ 00413df0 ==== */

void Unwind_00413df0(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 4,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413e06 @ 00413e06 ==== */

void Unwind_00413e06(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x2d8,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413e1e @ 00413e1e ==== */

void Unwind_00413e1e(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x328,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413e40 @ 00413e40 ==== */

void Unwind_00413e40(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x20));
  return;
}



/* ==== Unwind@00413e48 @ 00413e48 ==== */

void Unwind_00413e48(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x98));
  return;
}



/* ==== Unwind@00413e53 @ 00413e53 ==== */

void Unwind_00413e53(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x60));
  return;
}



/* ==== Unwind@00413e5b @ 00413e5b ==== */

void Unwind_00413e5b(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -100));
  return;
}



/* ==== Unwind@00413e63 @ 00413e63 ==== */

void Unwind_00413e63(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x5c));
  return;
}



/* ==== Unwind@00413e6b @ 00413e6b ==== */

void Unwind_00413e6b(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x68));
  return;
}



/* ==== Unwind@00413e80 @ 00413e80 ==== */

void Unwind_00413e80(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x28));
  return;
}



/* ==== Unwind@00413ea0 @ 00413ea0 ==== */

void Unwind_00413ea0(void)

{
  int unaff_EBP;
  
  FUN_00402ca0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@00413ec0 @ 00413ec0 ==== */

void Unwind_00413ec0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x14));
  return;
}



/* ==== Unwind@00413ee0 @ 00413ee0 ==== */

void Unwind_00413ee0(void)

{
  int unaff_EBP;
  
  FUN_00402ca0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@00413f00 @ 00413f00 ==== */

void Unwind_00413f00(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x14));
  return;
}



/* ==== Unwind@00413f20 @ 00413f20 ==== */

void Unwind_00413f20(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 4,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413f36 @ 00413f36 ==== */

void Unwind_00413f36(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x3dc,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413f4e @ 00413f4e ==== */

void Unwind_00413f4e(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x42c,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413f66 @ 00413f66 ==== */

void Unwind_00413f66(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x4e4,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413f90 @ 00413f90 ==== */

void Unwind_00413f90(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 4,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413fa6 @ 00413fa6 ==== */

void Unwind_00413fa6(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x3dc,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413fbe @ 00413fbe ==== */

void Unwind_00413fbe(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x42c,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00413fd6 @ 00413fd6 ==== */

void Unwind_00413fd6(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 0x4e4,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00414000 @ 00414000 ==== */

void Unwind_00414000(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x1c));
  return;
}



/* ==== Unwind@00414008 @ 00414008 ==== */

void Unwind_00414008(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x24));
  return;
}



/* ==== Unwind@00414020 @ 00414020 ==== */

void Unwind_00414020(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 4,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00414040 @ 00414040 ==== */

void Unwind_00414040(void)

{
  int unaff_EBP;
  
  FUN_00413918(*(int *)(unaff_EBP + -0x10) + 4,4,0x14,CString::~CString);
  return;
}



/* ==== Unwind@00414060 @ 00414060 ==== */

void Unwind_00414060(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x20));
  return;
}



/* ==== Unwind@00414068 @ 00414068 ==== */

void Unwind_00414068(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x18));
  return;
}



/* ==== Unwind@00414080 @ 00414080 ==== */

void Unwind_00414080(void)

{
  int unaff_EBP;
  
  CDialog::~CDialog(*(CDialog **)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@004140a0 @ 004140a0 ==== */

void Unwind_004140a0(void)

{
  int unaff_EBP;
  
  CDialog::~CDialog(*(CDialog **)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@004140c0 @ 004140c0 ==== */

void Unwind_004140c0(void)

{
  int unaff_EBP;
  
  FUN_00404420((CDialog *)(unaff_EBP + -0xf0));
  return;
}



/* ==== Unwind@004140cb @ 004140cb ==== */

void Unwind_004140cb(void)

{
  int unaff_EBP;
  
  CDialog::~CDialog((CDialog *)(unaff_EBP + -0xf0));
  return;
}



/* ==== Unwind@004140d6 @ 004140d6 ==== */

void Unwind_004140d6(void)

{
  int unaff_EBP;
  
  CButton::~CButton((CButton *)(unaff_EBP + -0x90));
  return;
}



/* ==== Unwind@004140f0 @ 004140f0 ==== */

void Unwind_004140f0(void)

{
  int unaff_EBP;
  
  CDialog::~CDialog(*(CDialog **)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@004140f8 @ 004140f8 ==== */

void Unwind_004140f8(void)

{
  int unaff_EBP;
  
  CButton::~CButton((CButton *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



/* ==== Unwind@00414110 @ 00414110 ==== */

void Unwind_00414110(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



/* ==== Unwind@00414130 @ 00414130 ==== */

void Unwind_00414130(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



/* ==== Unwind@00414150 @ 00414150 ==== */

void Unwind_00414150(void)

{
  int unaff_EBP;
  
  CDialog::~CDialog(*(CDialog **)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@00414158 @ 00414158 ==== */

void Unwind_00414158(void)

{
  int unaff_EBP;
  
  CButton::~CButton((CButton *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



/* ==== Unwind@00414163 @ 00414163 ==== */

void Unwind_00414163(void)

{
  int unaff_EBP;
  
  CComboBox::~CComboBox((CComboBox *)(*(int *)(unaff_EBP + -0x10) + 0xa0));
  return;
}



/* ==== Unwind@00414180 @ 00414180 ==== */

void Unwind_00414180(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x28));
  return;
}



/* ==== Unwind@004141a0 @ 004141a0 ==== */

void Unwind_004141a0(void)

{
  int unaff_EBP;
  
  CDialog::~CDialog((CDialog *)(unaff_EBP + -0x6c));
  return;
}



/* ==== Unwind@004141c0 @ 004141c0 ==== */

void Unwind_004141c0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x84));
  return;
}



/* ==== Unwind@004141cb @ 004141cb ==== */

void Unwind_004141cb(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x70));
  return;
}



/* ==== Unwind@004141d3 @ 004141d3 ==== */

void Unwind_004141d3(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x78));
  return;
}



/* ==== Unwind@004141db @ 004141db ==== */

void Unwind_004141db(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x78));
  return;
}



/* ==== Unwind@004141e3 @ 004141e3 ==== */

void Unwind_004141e3(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x78));
  return;
}



/* ==== Unwind@004141eb @ 004141eb ==== */

void Unwind_004141eb(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x78));
  return;
}



/* ==== Unwind@004141f3 @ 004141f3 ==== */

void Unwind_004141f3(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x74));
  return;
}



/* ==== Unwind@00414210 @ 00414210 ==== */

void Unwind_00414210(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x48));
  return;
}



/* ==== Unwind@00414218 @ 00414218 ==== */

void Unwind_00414218(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + 4));
  return;
}



/* ==== Unwind@00414230 @ 00414230 ==== */

void Unwind_00414230(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + 4));
  return;
}



/* ==== Unwind@00414238 @ 00414238 ==== */

void Unwind_00414238(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x24));
  return;
}



/* ==== Unwind@00414250 @ 00414250 ==== */

void Unwind_00414250(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@00414270 @ 00414270 ==== */

void Unwind_00414270(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@00414290 @ 00414290 ==== */

void Unwind_00414290(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@00414298 @ 00414298 ==== */

void Unwind_00414298(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004142a0 @ 004142a0 ==== */

void Unwind_004142a0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004142a8 @ 004142a8 ==== */

void Unwind_004142a8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004142b0 @ 004142b0 ==== */

void Unwind_004142b0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004142b8 @ 004142b8 ==== */

void Unwind_004142b8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004142c0 @ 004142c0 ==== */

void Unwind_004142c0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004142c8 @ 004142c8 ==== */

void Unwind_004142c8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004142d0 @ 004142d0 ==== */

void Unwind_004142d0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004142d8 @ 004142d8 ==== */

void Unwind_004142d8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004142e0 @ 004142e0 ==== */

void Unwind_004142e0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x48));
  return;
}



/* ==== Unwind@00414300 @ 00414300 ==== */

void Unwind_00414300(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x1c));
  return;
}



/* ==== Unwind@00414320 @ 00414320 ==== */

void Unwind_00414320(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + 0xc));
  return;
}



/* ==== Unwind@00414328 @ 00414328 ==== */

void Unwind_00414328(void)

{
  int unaff_EBP;
  
  CDC::~CDC((CDC *)(unaff_EBP + -0x1c));
  return;
}



/* ==== Unwind@00414340 @ 00414340 ==== */

void Unwind_00414340(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x98c));
  return;
}



/* ==== Unwind@0041434b @ 0041434b ==== */

void Unwind_0041434b(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x988));
  return;
}



/* ==== Unwind@00414356 @ 00414356 ==== */

void Unwind_00414356(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x984));
  return;
}



/* ==== Unwind@00414361 @ 00414361 ==== */

void Unwind_00414361(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x980));
  return;
}



/* ==== Unwind@0041436c @ 0041436c ==== */

void Unwind_0041436c(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x97c));
  return;
}



/* ==== Unwind@00414377 @ 00414377 ==== */

void Unwind_00414377(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x978));
  return;
}



/* ==== Unwind@00414382 @ 00414382 ==== */

void Unwind_00414382(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x974));
  return;
}



/* ==== Unwind@0041438d @ 0041438d ==== */

void Unwind_0041438d(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa18));
  return;
}



/* ==== Unwind@00414398 @ 00414398 ==== */

void Unwind_00414398(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa14));
  return;
}



/* ==== Unwind@004143a3 @ 004143a3 ==== */

void Unwind_004143a3(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa10));
  return;
}



/* ==== Unwind@004143ae @ 004143ae ==== */

void Unwind_004143ae(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9ec));
  return;
}



/* ==== Unwind@004143b9 @ 004143b9 ==== */

void Unwind_004143b9(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa04));
  return;
}



/* ==== Unwind@004143c4 @ 004143c4 ==== */

void Unwind_004143c4(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9c0));
  return;
}



/* ==== Unwind@004143cf @ 004143cf ==== */

void Unwind_004143cf(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9bc));
  return;
}



/* ==== Unwind@004143da @ 004143da ==== */

void Unwind_004143da(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9b8));
  return;
}



/* ==== Unwind@004143e5 @ 004143e5 ==== */

void Unwind_004143e5(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9b4));
  return;
}



/* ==== Unwind@004143f0 @ 004143f0 ==== */

void Unwind_004143f0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9b0));
  return;
}



/* ==== Unwind@004143fb @ 004143fb ==== */

void Unwind_004143fb(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9ac));
  return;
}



/* ==== Unwind@00414406 @ 00414406 ==== */

void Unwind_00414406(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9a8));
  return;
}



/* ==== Unwind@00414411 @ 00414411 ==== */

void Unwind_00414411(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9a4));
  return;
}



/* ==== Unwind@0041441c @ 0041441c ==== */

void Unwind_0041441c(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa0c));
  return;
}



/* ==== Unwind@00414427 @ 00414427 ==== */

void Unwind_00414427(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa00));
  return;
}



/* ==== Unwind@00414432 @ 00414432 ==== */

void Unwind_00414432(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9c4));
  return;
}



/* ==== Unwind@0041443d @ 0041443d ==== */

void Unwind_0041443d(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9f4));
  return;
}



/* ==== Unwind@00414448 @ 00414448 ==== */

void Unwind_00414448(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9dc));
  return;
}



/* ==== Unwind@00414453 @ 00414453 ==== */

void Unwind_00414453(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9e0));
  return;
}



/* ==== Unwind@0041445e @ 0041445e ==== */

void Unwind_0041445e(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9e4));
  return;
}



/* ==== Unwind@00414469 @ 00414469 ==== */

void Unwind_00414469(void)

{
  int unaff_EBP;
  
  FUN_00403120((undefined4 *)(unaff_EBP + -0x8b8));
  return;
}



/* ==== Unwind@00414474 @ 00414474 ==== */

void Unwind_00414474(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9d8));
  return;
}



/* ==== Unwind@0041447f @ 0041447f ==== */

void Unwind_0041447f(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9d4));
  return;
}



/* ==== Unwind@0041448a @ 0041448a ==== */

void Unwind_0041448a(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9d0));
  return;
}



/* ==== Unwind@00414495 @ 00414495 ==== */

void Unwind_00414495(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9cc));
  return;
}



/* ==== Unwind@004144a0 @ 004144a0 ==== */

void Unwind_004144a0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9e4));
  return;
}



/* ==== Unwind@004144ab @ 004144ab ==== */

void Unwind_004144ab(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9e0));
  return;
}



/* ==== Unwind@004144b6 @ 004144b6 ==== */

void Unwind_004144b6(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9dc));
  return;
}



/* ==== Unwind@004144c1 @ 004144c1 ==== */

void Unwind_004144c1(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa04));
  return;
}



/* ==== Unwind@004144cc @ 004144cc ==== */

void Unwind_004144cc(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa00));
  return;
}



/* ==== Unwind@004144d7 @ 004144d7 ==== */

void Unwind_004144d7(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9f4));
  return;
}



/* ==== Unwind@004144e2 @ 004144e2 ==== */

void Unwind_004144e2(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9d8));
  return;
}



/* ==== Unwind@004144ed @ 004144ed ==== */

void Unwind_004144ed(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9d4));
  return;
}



/* ==== Unwind@004144f8 @ 004144f8 ==== */

void Unwind_004144f8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9d0));
  return;
}



/* ==== Unwind@00414503 @ 00414503 ==== */

void Unwind_00414503(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9cc));
  return;
}



/* ==== Unwind@0041450e @ 0041450e ==== */

void Unwind_0041450e(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9e4));
  return;
}



/* ==== Unwind@00414519 @ 00414519 ==== */

void Unwind_00414519(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9e0));
  return;
}



/* ==== Unwind@00414524 @ 00414524 ==== */

void Unwind_00414524(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x9dc));
  return;
}



/* ==== Unwind@00414540 @ 00414540 ==== */

void Unwind_00414540(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x20));
  return;
}



/* ==== Unwind@00414560 @ 00414560 ==== */

void Unwind_00414560(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xac));
  return;
}



/* ==== Unwind@00414580 @ 00414580 ==== */

void Unwind_00414580(void)

{
  int unaff_EBP;
  
  CDC::~CDC((CDC *)(unaff_EBP + -0x1c));
  return;
}



/* ==== Unwind@004145a0 @ 004145a0 ==== */

void Unwind_004145a0(void)

{
  int unaff_EBP;
  
  FUN_004041b0((CDialog *)(unaff_EBP + -0x70));
  return;
}



/* ==== Unwind@004145a8 @ 004145a8 ==== */

void Unwind_004145a8(void)

{
  int unaff_EBP;
  
  CDialog::~CDialog((CDialog *)(unaff_EBP + -0x70));
  return;
}



/* ==== Unwind@004145c0 @ 004145c0 ==== */

void Unwind_004145c0(void)

{
  int unaff_EBP;
  
  CDC::~CDC((CDC *)(unaff_EBP + -0x1c));
  return;
}



/* ==== Unwind@004145c8 @ 004145c8 ==== */

void Unwind_004145c8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x34));
  return;
}



/* ==== Unwind@004145d0 @ 004145d0 ==== */

void Unwind_004145d0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x30));
  return;
}



/* ==== Unwind@004145d8 @ 004145d8 ==== */

void Unwind_004145d8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x28));
  return;
}



/* ==== Unwind@004145f0 @ 004145f0 ==== */

void Unwind_004145f0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x88));
  return;
}



/* ==== Unwind@004145fb @ 004145fb ==== */

void Unwind_004145fb(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x84));
  return;
}



/* ==== Unwind@00414606 @ 00414606 ==== */

void Unwind_00414606(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x80));
  return;
}



/* ==== Unwind@0041460e @ 0041460e ==== */

void Unwind_0041460e(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x7c));
  return;
}



/* ==== Unwind@00414616 @ 00414616 ==== */

void Unwind_00414616(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x78));
  return;
}



/* ==== Unwind@0041461e @ 0041461e ==== */

void Unwind_0041461e(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x74));
  return;
}



/* ==== Unwind@00414626 @ 00414626 ==== */

void Unwind_00414626(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa8));
  return;
}



/* ==== Unwind@00414631 @ 00414631 ==== */

void Unwind_00414631(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x8c));
  return;
}



/* ==== Unwind@0041463c @ 0041463c ==== */

void Unwind_0041463c(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0xa0));
  return;
}



/* ==== Unwind@00414660 @ 00414660 ==== */

void Unwind_00414660(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x2c));
  return;
}



/* ==== Unwind@00414668 @ 00414668 ==== */

void Unwind_00414668(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x1c));
  return;
}



/* ==== Unwind@00414680 @ 00414680 ==== */

void Unwind_00414680(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x3c));
  return;
}



/* ==== Unwind@00414688 @ 00414688 ==== */

void Unwind_00414688(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x48));
  return;
}



/* ==== Unwind@00414690 @ 00414690 ==== */

void Unwind_00414690(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@00414698 @ 00414698 ==== */

void Unwind_00414698(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x34));
  return;
}



/* ==== Unwind@004146a0 @ 004146a0 ==== */

void Unwind_004146a0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x38));
  return;
}



/* ==== Unwind@004146a8 @ 004146a8 ==== */

void Unwind_004146a8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40));
  return;
}



/* ==== Unwind@004146b0 @ 004146b0 ==== */

void Unwind_004146b0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x38));
  return;
}



/* ==== Unwind@004146d0 @ 004146d0 ==== */

void Unwind_004146d0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x28));
  return;
}



/* ==== Unwind@004146d8 @ 004146d8 ==== */

void Unwind_004146d8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x1c));
  return;
}



/* ==== Unwind@004146f0 @ 004146f0 ==== */

void Unwind_004146f0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4dc));
  return;
}



/* ==== Unwind@004146fb @ 004146fb ==== */

void Unwind_004146fb(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4c8));
  return;
}



/* ==== Unwind@00414706 @ 00414706 ==== */

void Unwind_00414706(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4d0));
  return;
}



/* ==== Unwind@00414711 @ 00414711 ==== */

void Unwind_00414711(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x518));
  return;
}



/* ==== Unwind@0041471c @ 0041471c ==== */

void Unwind_0041471c(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4d4));
  return;
}



/* ==== Unwind@00414727 @ 00414727 ==== */

void Unwind_00414727(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4cc));
  return;
}



/* ==== Unwind@00414732 @ 00414732 ==== */

void Unwind_00414732(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4d8));
  return;
}



/* ==== Unwind@0041473d @ 0041473d ==== */

void Unwind_0041473d(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x510));
  return;
}



/* ==== Unwind@00414748 @ 00414748 ==== */

void Unwind_00414748(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4f4));
  return;
}



/* ==== Unwind@00414753 @ 00414753 ==== */

void Unwind_00414753(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4f8));
  return;
}



/* ==== Unwind@0041475e @ 0041475e ==== */

void Unwind_0041475e(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x500));
  return;
}



/* ==== Unwind@00414769 @ 00414769 ==== */

void Unwind_00414769(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x514));
  return;
}



/* ==== Unwind@00414774 @ 00414774 ==== */

void Unwind_00414774(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4fc));
  return;
}



/* ==== Unwind@0041477f @ 0041477f ==== */

void Unwind_0041477f(void)

{
  int unaff_EBP;
  
  CFile::~CFile((CFile *)(unaff_EBP + -0x528));
  return;
}



/* ==== Unwind@0041478a @ 0041478a ==== */

void Unwind_0041478a(void)

{
  int unaff_EBP;
  
  FUN_00402ca0((undefined4 *)(unaff_EBP + -0x4f0));
  return;
}



/* ==== Unwind@00414795 @ 00414795 ==== */

void Unwind_00414795(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4e0));
  return;
}



/* ==== Unwind@004147a0 @ 004147a0 ==== */

void Unwind_004147a0(void)

{
  int unaff_EBP;
  
  FUN_0040ee20((undefined4 *)(unaff_EBP + -0x4f0));
  return;
}



/* ==== Unwind@004147ab @ 004147ab ==== */

void Unwind_004147ab(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x544));
  return;
}



/* ==== Unwind@004147b6 @ 004147b6 ==== */

void Unwind_004147b6(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x54c));
  return;
}



/* ==== Unwind@004147c1 @ 004147c1 ==== */

void Unwind_004147c1(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x550));
  return;
}



/* ==== Unwind@004147cc @ 004147cc ==== */

void Unwind_004147cc(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x508));
  return;
}



/* ==== Unwind@004147d7 @ 004147d7 ==== */

void Unwind_004147d7(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x538));
  return;
}



/* ==== Unwind@004147e2 @ 004147e2 ==== */

void Unwind_004147e2(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x56c));
  return;
}



/* ==== Unwind@004147ed @ 004147ed ==== */

void Unwind_004147ed(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x568));
  return;
}



/* ==== Unwind@004147f8 @ 004147f8 ==== */

void Unwind_004147f8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x568));
  return;
}



/* ==== Unwind@00414803 @ 00414803 ==== */

void Unwind_00414803(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x538));
  return;
}



/* ==== Unwind@0041480e @ 0041480e ==== */

void Unwind_0041480e(void)

{
  int unaff_EBP;
  
  FUN_00402ca0((undefined4 *)(unaff_EBP + -0x4f0));
  return;
}



/* ==== Unwind@00414819 @ 00414819 ==== */

void Unwind_00414819(void)

{
  int unaff_EBP;
  
  FUN_00402ca0((undefined4 *)(unaff_EBP + -0x4f0));
  return;
}



/* ==== Unwind@00414830 @ 00414830 ==== */

void Unwind_00414830(void)

{
  int unaff_EBP;
  
  FUN_00402ca0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@00414850 @ 00414850 ==== */

void Unwind_00414850(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x48));
  return;
}



/* ==== Unwind@00414870 @ 00414870 ==== */

void Unwind_00414870(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x24));
  return;
}



/* ==== Unwind@00414878 @ 00414878 ==== */

void Unwind_00414878(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x20));
  return;
}



/* ==== Unwind@00414880 @ 00414880 ==== */

void Unwind_00414880(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x1c));
  return;
}



/* ==== Unwind@00414888 @ 00414888 ==== */

void Unwind_00414888(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x18));
  return;
}



/* ==== Unwind@00414890 @ 00414890 ==== */

void Unwind_00414890(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x14));
  return;
}



/* ==== Unwind@00414898 @ 00414898 ==== */

void Unwind_00414898(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@004148a0 @ 004148a0 ==== */

void Unwind_004148a0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4c));
  return;
}



/* ==== Unwind@004148a8 @ 004148a8 ==== */

void Unwind_004148a8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x48));
  return;
}



/* ==== Unwind@004148b0 @ 004148b0 ==== */

void Unwind_004148b0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x44));
  return;
}



/* ==== Unwind@004148d0 @ 004148d0 ==== */

void Unwind_004148d0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x2c));
  return;
}



/* ==== Unwind@004148d8 @ 004148d8 ==== */

void Unwind_004148d8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x38));
  return;
}



/* ==== Unwind@004148e0 @ 004148e0 ==== */

void Unwind_004148e0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x34));
  return;
}



/* ==== Unwind@004148e8 @ 004148e8 ==== */

void Unwind_004148e8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x28));
  return;
}



/* ==== Unwind@00414900 @ 00414900 ==== */

void Unwind_00414900(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + 4));
  return;
}



/* ==== Unwind@00414920 @ 00414920 ==== */

void Unwind_00414920(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x14));
  return;
}



/* ==== Unwind@00414940 @ 00414940 ==== */

void Unwind_00414940(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x14));
  return;
}



/* ==== Unwind@00414960 @ 00414960 ==== */

void Unwind_00414960(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x30));
  return;
}



/* ==== Unwind@00414980 @ 00414980 ==== */

void Unwind_00414980(void)

{
  int unaff_EBP;
  
  FUN_00403120((undefined4 *)(unaff_EBP + -0x8b8));
  return;
}



/* ==== Unwind@004149a0 @ 004149a0 ==== */

void Unwind_004149a0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x10));
  return;
}



/* ==== Unwind@004149a8 @ 004149a8 ==== */

void Unwind_004149a8(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x14));
  return;
}



/* ==== Unwind@004149c0 @ 004149c0 ==== */

void Unwind_004149c0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x2c));
  return;
}



/* ==== Unwind@004149e0 @ 004149e0 ==== */

void Unwind_004149e0(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x408));
  return;
}



/* ==== Unwind@004149eb @ 004149eb ==== */

void Unwind_004149eb(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x3fc));
  return;
}



/* ==== Unwind@004149f6 @ 004149f6 ==== */

void Unwind_004149f6(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40c));
  return;
}



/* ==== Unwind@00414a01 @ 00414a01 ==== */

void Unwind_00414a01(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x400));
  return;
}



/* ==== Unwind@00414a0c @ 00414a0c ==== */

void Unwind_00414a0c(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x40c));
  return;
}



/* ==== Unwind@00414a30 @ 00414a30 ==== */

void Unwind_00414a30(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x4c));
  return;
}



/* ==== Unwind@00414a50 @ 00414a50 ==== */

void Unwind_00414a50(void)

{
  int unaff_EBP;
  
  FUN_00403120((undefined4 *)(unaff_EBP + -0x8b8));
  return;
}



/* ==== Unwind@00414a5b @ 00414a5b ==== */

void Unwind_00414a5b(void)

{
  int unaff_EBP;
  
  CString::~CString((CString *)(unaff_EBP + -0x8e8));
  return;
}



/* ==== Unwind@00414a80 @ 00414a80 ==== */

void Unwind_00414a80(void)

{
  int unaff_EBP;
  
  FUN_00402ca0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



