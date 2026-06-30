#pragma once

#ifndef BYTE
typedef char BYTE;
#endif

#ifndef WORD
typedef int WORD;
#endif

#ifndef DWORD
typedef long DWORD;
#endif

#ifndef QWORD
typedef long long QWORD;
#endif

typedef char _QS_BYTE;
typedef int _QS_WORD;
typedef long _QS_DWORD;
typedef long long _QS_QWORD;
typedef float _QS_FLOAT;
typedef double _QS_DOUBLE;

#ifdef __cplusplus
typedef bool _QS_BOOL;
#define _QS_TRUE true
#define _QS_FALSE false
#else
typedef int _QS_BOOL;
#define _QS_TRUE 1
#define _QS_FALSE 0
#endif
