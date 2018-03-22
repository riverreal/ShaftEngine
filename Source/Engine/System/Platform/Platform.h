#pragma once

#ifndef PLATFORM_WINDOWS
	#define PLATFORM_WINDOWS 0
#endif
#ifndef PLATFORM_MACOS
	#define PLATFORM_MACOS 0
#endif
#ifndef PLATFORM_IOS
	#define PLATFORM_IOS 0
#endif
#ifndef PLATFORM_LINUX
	#define PLATFORM_LINUX 0
#endif
#ifndef PLATFORM_ANDROID
	#define PLATFORM_ANDROID 0
#endif

#if	PLATFORM_WINDOWS
	#include "WindowsTypes.h"
#elif	PLATFORM_MACOS
#elif	PLATFORM_IOS
#elif	PLATFORM_LINUX
#elif	PLATFORM_ANDROID
#endif

//Transfer types and make global

typedef Shaft::PlatformTypes::uint8		uint8;
typedef Shaft::PlatformTypes::uint16	uint16;
typedef Shaft::PlatformTypes::uint32	uint32;
typedef Shaft::PlatformTypes::uint64	uint64;

typedef Shaft::PlatformTypes::uint8f	uin8f;
typedef Shaft::PlatformTypes::uint16f	uint16f;
typedef Shaft::PlatformTypes::uint32f	uint32f;
typedef Shaft::PlatformTypes::uint64f	uint64f;

typedef Shaft::PlatformTypes::int8		int8;
typedef Shaft::PlatformTypes::int16		int16;
typedef Shaft::PlatformTypes::int32		int32;
typedef Shaft::PlatformTypes::int64		int64;

typedef Shaft::PlatformTypes::int8f		int8f;
typedef Shaft::PlatformTypes::int16f	int16f;
typedef Shaft::PlatformTypes::int32f	int32f;
typedef Shaft::PlatformTypes::int64f	int64f;

typedef Shaft::PlatformTypes::ansiChar	asiChar;
typedef Shaft::PlatformTypes::wideChar	wideChar;
typedef Shaft::PlatformTypes::char8		char8;
typedef Shaft::PlatformTypes::char16	char16;
typedef Shaft::PlatformTypes::char32	char32;