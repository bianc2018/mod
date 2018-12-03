#include "stdafx.h"

#include "message.h"




int Message::add_data(const string & key, std::shared_ptr<void> value)
{
	msg[key] = value;
	return 0;
}

Message::~Message()
{
}
