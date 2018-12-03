
#ifndef MESSAGE_H
#define MESSAGE_H
#include <map>
#include <string>
#include <memory>
using std::string;
//register;

class Message
{
public:
	int from_id;
	int to_id;
	int code;
	std::map<string,std::shared_ptr<void> > msg; //key&value
	
public:
	Message()=delete;
	Message(int _code, int _to, int _from) :from_id(_from), to_id(_to), code(_code)
	{}
	int add_data(const string &key, std::shared_ptr<void> value);
	virtual ~Message();
};
#endif // !MESSAGE_H



