#ifndef DETOURSEXT_H
#define DETOURSEXT_H

#include "detours.h"

template <typename RET_TYPE, typename CLASS, typename...ARGs>
void* castToVoidPtr(RET_TYPE (CLASS::*&&pOriginalFunction)(ARGs ...))
{
	PVOID iter1 = reinterpret_cast<PVOID>(&pOriginalFunction);
	PVOID voidPtr = reinterpret_cast<PVOID>(*(PVOID *)iter1);
	static_assert(sizeof(&pOriginalFunction) == sizeof(voidPtr),
		"Cannot cast this member function pointer to a void*.  Not the same size.");
	return voidPtr;
}

//
// // Cast a member function pointer to a void*&
// template <typename RET_TYPE, typename CLASS, typename...ARGs>
// void*& castToVoidPtr(RET_TYPE(CLASS::*&pOriginalFunction)(ARGs...))
// {
// 	
// 	auto voidPtr = reinterpret_cast<void*&>(&pOriginalFunction);
// 	static_assert(sizeof(&pOriginalFunction) == sizeof(voidPtr), "Cannot cast this member function pointer to a void*.  Not the same size.");
// 	return voidPtr;
// }

//#define DetourMemberFunction(target, detour) DetourAttach(&(PVOID&)target, (PVOID)(&(PVOID&)detour));
#define DetourFunction(target, detour) DetourAttach(&(PVOID&)target, (PVOID)detour);
#define DetourMemberFunction(target, detour) DetourAttach(&(PVOID&)target, castToVoidPtr(&detour));

#define DetourMemberStaticFunction(target, detour) DetourAttach(&(PVOID&)target, &(PVOID&)detour);
#endif //DETOURSEXT_H
