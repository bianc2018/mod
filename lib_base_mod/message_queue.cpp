#include "stdafx.h"
#include "message_queue.h"
std::mutex MessageQueue::msg_lock;
std::vector<Message> MessageQueue::msg_queue;

int MessageQueue::set_message(const Message & m)
{
	while (0 == msg_queue.size());

	msg_lock.lock();

	msg_queue.push_back(m);

	msg_lock.unlock();
	return 0;
}

int MessageQueue::try_set_message(const Message & m)
{
	if (0 == msg_queue.size())
		return -1;
	if (msg_lock.try_lock() == false)
		return -2;

	msg_queue.push_back(m);

	msg_lock.unlock();
	return 0;
}

Message MessageQueue::get_message(int & rs,int id)
{
	rs = 0;
	while (0 == msg_queue.size());

	while (true)
	{
		msg_lock.lock();

		size_t size = msg_queue.size();
		int pos = 0;
		for (pos = 0; pos < size; pos++)
		{
			if (msg_queue[pos].to_id == id)
				break;
		}
		if (pos != size)
		{
			Message msg = msg_queue[pos];
			msg_queue.erase(msg_queue.begin() + pos);
			msg_lock.unlock();
			return msg;
		}

		msg_lock.unlock();
	}
}

Message MessageQueue::try_get_message(int & rs,int id)
{
	rs = 0;
	if (0 == msg_queue.size())
	{
		rs = -1;
		return Message(-1, -1, -1);
	}
	if (msg_lock.try_lock() == false)
	{
		rs = -2;
		return Message(-2, -2, -2);
	}

	size_t size = msg_queue.size();
	int pos = 0;
	for (pos = 0; pos < size; pos++)
	{
		if (msg_queue[pos].to_id == id)
			break;
	}

	Message msg(-3, -3, -3);
	if (pos != size)
	{
		msg = msg_queue[pos];
		msg_queue.erase(msg_queue.begin() + pos);
		rs = 0;
	}
	else
		rs = -3;

	msg_lock.unlock();

	return msg;
}
