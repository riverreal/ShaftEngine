#pragma once

#ifdef RTTT_ENABLED

#include "rttr/registration_friend.h"
#include "rttr/rttr_enable.h"

#define RTTR_REGISTRATION_FRIEND_NON_INTRUSIVE(cls) \
	template<typename T> \
	friend void rttr_auto_register_reflection_function_t(); \
	RTTR_REGISTRATION_FRIEND

#define EXPAND(x) x
#define REFLECTABLE_VIRTUAL_IMP(cls, ...) \
	RTTR_REGISTRATION_FRIEND_NON_INTRUSIVE(cls) \
	RTTR_ENABLE(__VA_ARGS__) \
	public:

#define REFLECTABLE(cls) RTTR_REGISTRATION_FRIEND_NON_INTRUSIVE(cls)
#define REFLECTABLEV(...) EXPAND(REFLECTABLE_VIRTUAL_IMPL(__VA_ARGS__))

#else
#define RTTR_REGISTRATION_FRIEND_NON_INTRUSIVE
#define REFLECTABLE_VIRTUAL_IMP
#define REFLECTABLE(cls)
#define RELFECTABLEV(...)
#endif