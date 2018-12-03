// mod_test.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "test_mod.h"

extern "C"
{
	__declspec(dllexport) BaseMod* LOAD();
}

BaseMod * LOAD()
{
	string name = "test";
	return new TestMod(name);
}
