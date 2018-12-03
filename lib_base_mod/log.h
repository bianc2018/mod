#ifndef BASE_MOD_LOG
#define BASE_MOD_LOG


#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <mutex>

#include "define.h"
#include "message.h"
#define ERROR 0
#define WARN  1
#define INFO  2
#define DEBUG 1
using std::string;
static std::mutex lock;
static int i = 0;
class GLOG
{
public:
	GLOG(string log_path,int status = DEBUG);

	//GLOG& print(int lv,const char*fmt, ...);
	
	template<typename ...Types>
	GLOG& print(int lv, Types  ... args)
	{
		lock.lock();
		printf("[%s][%s] %s\n", get_now_time().c_str(), log_lv[lv].c_str(), format(args ...).c_str());
		
		log_file << "[" << get_now_time() << "]"\
			<< "[" << log_lv[lv] << "] "\
			<< format(args ...) << std::endl;
		lock.unlock();

		return *this;
	}

	template<typename ...Types>
	GLOG& printd(int lv, Types  ... args)
	{
		if (isdebug)
		{
			lock.lock();

			std::cout << "[" << get_now_time() << "]"\
				<< "[" << log_lv[lv] << "] "\
				<< format(args ...) << std::endl;

			lock.unlock();
		}
		return *this;
	}

	template<typename T,typename ...Types>
	string format(T first, Types ... args)
	{
		return data_to_string(first) +" "+ format(args ...);
	}
	string format()
	{
		return "";
	}
	~GLOG();
private:
	std::fstream log_file;
	string log_lv[3];
	int isdebug;
	
private:
	string get_now_time();

	string data_to_string(const int in);
	string data_to_string(const string in);
	string data_to_string(const double in);
	string data_to_string(const char* in);
	string data_to_string(const float in);
};

#endif // !BASE_MOD_LOG



