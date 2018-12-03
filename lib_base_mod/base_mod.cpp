#include "stdafx.h"

#include "base_mod.h"
#include "define.h"

BaseMod::BaseMod(const string & _name)
{
	name = _name;
	status_code = 0;
	this_thread = nullptr;
	hmondule = nullptr;
	pshare = nullptr;
}

BaseMod::~BaseMod()
{

}

void BaseMod::kill()
{
	status_code = -1;
}

void BaseMod::run()
{
	init();
	while (true)
	{
		//-1 Ö÷¶¯ÍË³ö
		if (status_code<0)
		{
			break;
		}
		int rs = 0;
		Message i_msg =  try_get_message(rs);
		if (rs < 0)
		{
			i_msg.code = mod_flag::msg_code::UPDATA;
			i_msg.from_id = mod_flag::SYSTEM_CALL;
			i_msg.to_id = id;
			Sleep(UPDATA_DELY);
		}
		process(i_msg);
	}
	uninit();
	return;
}

void BaseMod::set_shared_data(std::shared_ptr<Shared>ps)
{
	pshare = ps;
}

Message BaseMod::get_message(int & rs)
{
	return pshare->mq.get_message(rs, id);
}

Message BaseMod::try_get_message(int & rs)
{
	return pshare->mq.try_get_message(rs, id);
}

int BaseMod::set_message(const Message & m)
{
	return pshare->mq.set_message(m);
}

int BaseMod::try_set_message(const Message & m)
{
	return pshare->mq.try_set_message(m);
}
