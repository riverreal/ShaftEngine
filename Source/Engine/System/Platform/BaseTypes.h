#pragma once

#include <stdint.h>

namespace Shaft
{
	struct BaseTypes
	{
		typedef unsigned char		uint8;
		typedef unsigned short int	uint16;
		typedef unsigned int		uint32;
		typedef unsigned long long	uint64;

		//Fast uint8 for calculations, can be bigger than 8-bits
		typedef uint_fast8_t		uint8f;
		//Fast uint8 for calculations, can be bigger than 16-bits
		typedef uint_fast16_t		uint16f;
		//Fast uint8 for calculations, can be bigger than 32-bits
		typedef uint_fast32_t		uint32f;
		//Fast uint8 for calculations, can be bigger than 64-bits
		typedef uint_fast64_t		uint64f;

		typedef signed char			int8;
		typedef signed short int	int16;
		typedef signed int			int32;
		typedef signed long long	int64;

		//Fast uint8 for calculations, can be bigger than 8-bits
		typedef int_fast8_t			int8f;
		//Fast uint8 for calculations, can be bigger than 16-bits
		typedef int_fast16_t		int16f;
		//Fast uint8 for calculations, can be bigger than 32-bits
		typedef int_fast32_t		int32f;
		//Fast uint8 for calculations, can be bigger than 64-bits
		typedef int_fast64_t		int64f;

		typedef char				ansiChar;
		typedef wchar_t				wideChar;
		typedef uint8				char8;
		typedef char16_t			char16;
		typedef char32_t			char32;
	};
}
