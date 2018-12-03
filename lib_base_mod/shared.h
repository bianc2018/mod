#ifndef SHARED_H
#define SHARED_H
#include "log.h"
#include "message_queue.h"
#include "id_name_map.h"
class Shared
{
public:
	Shared(string log_path);
public:
	GLOG glog;
	MessageQueue mq;
	IdNameMap name_id;
};
#endif

