#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H
#include "message.h"
#include <mutex>
#include <vector>
#include <utility>

class MessageQueue
{
public:
	//������Ϣ
	int set_message(const Message& m);
	int try_set_message(const Message& m);
	//��ȡ��Ϣ  ����
	Message get_message(int &rs,int id);
	//��ȡ��Ϣ ��û��ֱ�ӷ���
	Message try_get_message(int &rs,int id) ;
private:
	//��Ϣ����,ȫ�־�̬����
	static std::mutex msg_lock;
	static std::vector<Message> msg_queue;
};
#endif
