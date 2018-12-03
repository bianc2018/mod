#pragma once
#ifndef TEST_MOD_H
#define TEST_MOD_H
#include "base_mod.h"
#include "define.h"
class TestMod :
	public BaseMod
{
public:
	using BaseMod::BaseMod;
	virtual void process(const Message&msg);//¥¶¿Ì
	virtual void init();
};
#endif // !TEST_MOD_H



