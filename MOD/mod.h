//插件
#ifndef MOD_H
#define MOD_H
#include "message.h"
#include <queue>
class MOD
{
public:
	MOD();
	virtual ~MOD();
	virtual int inti() = 0;
	virtual void run()=0;
protected:
	//消息队列
	std::queue<Message> in_msg_queue;
	std::queue<Message> out_msg_queue;
	//
	virtual Message get_message(int &rs) = 0;
	virtual int set_message(Message& m) = 0;
};
#endif // !MOD_H



