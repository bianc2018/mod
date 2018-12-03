

#include "stdafx.h"

#include "log.h"

#include <ctime>

#include <stdarg.h>


GLOG::GLOG(string log_path,int status)
{
	std::cout << "GLOG 初始化\n";
	log_file.open(log_path, std::ios::out);
	if (!log_file)
	{
		print(ERROR, "无法打开文件:", log_path.c_str());
	}
	log_lv[ERROR] = "ERROR";
	log_lv[WARN] = "WARN";
	log_lv[INFO] = "INFO";
	isdebug = status;
}


//GLOG & GLOG::print(int lv,const char*fmt, ...)
//{
//	LOCK
//
//	char *buff = new char[1000];
//	memset(buff, 0, sizeof(buff));
//
//	//__crt_va_start(ap, fmt); //获得可变参数列表,分析fmt，得出各个参数的类型，也是分析参数中类似”%d%s“的字符串
//	//sprintf(buff,fmt, ap);
//	//__crt_va_end(ap); //释放资源,必须与va_start成对调用
//
//	va_list args;
//	va_start(args, fmt);
//	char *p = va_arg(args, char*);
//	_vsnprintf(buff, sizeof(buff), fmt, args);
//	va_end(args);
//
//	std::cout << "[" << get_now_time() << "]"\
//		<< "[" << log_lv[lv] << "]"\
//		<<buff<<std::endl;
//
//	UNLOCK
//
//	delete[]buff;
//	return *this;
//}

GLOG::~GLOG()
{
	log_file.close();
}

string GLOG::get_now_time()
{
	time_t t = ::time(0);
	char ch[64];
	::strftime(ch, sizeof(ch), "%Y-%m-%d %H-%M-%S", ::localtime(&t)); //年-月-日 时-分-秒
	return string(ch);
}

string GLOG::data_to_string(const int in)
{
	return std::to_string(in);
}

string GLOG::data_to_string(const string in)
{
	return in;
}

string GLOG::data_to_string(const double in)
{
	return std::to_string(in);
}

string GLOG::data_to_string(const char * in)
{
	std::shared_ptr<char> buff(new char[1000]);
	sprintf(buff.get(), "%s", in);
	string str(buff.get());
	return str;
}

string GLOG::data_to_string(const float in)
{
	return std::to_string(in);
}
