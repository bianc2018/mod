#include "stdafx.h"
#include "test_mod.h"
using namespace  mod_flag;

void TestMod::process(const Message & msg)
{
	switch (msg.code)
	{
	case msg_code::LOAD:
		break;

	case msg_code::UPDATA:
		pshare->glog.print(INFO,name, "is updata");
		break;
	default:
		//printf("Non msg code:%d\n", msg.code);
		break;
	}
	return;
}

void TestMod::init()
{
	pshare->glog.print(INFO, name," is load");
}
