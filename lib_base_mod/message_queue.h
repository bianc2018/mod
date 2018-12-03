#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H
#include "message.h"
#include <mutex>
#include <vector>
#include <utility>

class MessageQueue
{
public:
	//发送信息
	int set_message(const Message& m);
	int try_set_message(const Message& m);
	//获取消息  阻塞
	Message get_message(int &rs,int id);
	//获取消息 ，没有直接返回
	Message try_get_message(int &rs,int id) ;
private:
	//消息队列,全局静态变量
	static std::mutex msg_lock;
	static std::vector<Message> msg_queue;
};
#endif
