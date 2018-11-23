#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H
#include <map>
#include <string>
#include <memory>
using std::string;
class Message
{
public:
	string from_id;
	string to_id;
	int code;
	std::map<string,std::shared_ptr<void> > msg; //key&value
	
public:
	Message()=delete;
	virtual ~Message();
private:
	std::map<string, string> arp; //name : id
};
#endif // !MESSAGE_H



