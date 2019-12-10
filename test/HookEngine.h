#pragma once
/*
Author:��� QQ:471194425 Ⱥ�ţ�1026716399
*/
#include <iostream>
#include <map>
#include <Windows.h>
enum HookType
{
	//CallHeadHook,
	JmpHeadHook,
	//CallNotHeadHook,
	JmpNotHeadHook,
};

class Hook;

class HookEngine
{
public:
	virtual ~HookEngine();
	static HookEngine * GetInstance();
	static void  DistoryInstance();
	bool AddHook(ULONG oldFunc, ULONG newFunc, HookType type = HookType::JmpHeadHook);
	Hook * FindHookByNewFuncAddr(ULONG newFunc);
	Hook * FindHookByOldFuncAddr(ULONG oldFunc);
private:
	HookEngine();
private:
	static HookEngine * hookEngine;
	std::map<ULONG, Hook*> hookMaps;
};

