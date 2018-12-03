//插件
#ifndef BASE_MOD_H
#define BASE_MOD_H

#include<Windows.h>

#include "shared.h"

//ms
#define UPDATA_DELY  500

class BaseMod
{
public:
	BaseMod(const string &name);
	virtual ~BaseMod();
	virtual void process(const Message&msg) = 0;//处理
	virtual void init()
	{}
	virtual void uninit()
	{}
	void kill();
	void run();

	void set_shared_data(std::shared_ptr<Shared> ps);
public:
	std::shared_ptr<std::thread> this_thread;
	HMODULE hmondule;
	string name;
	int id;
protected:
	//公共数据
	std::shared_ptr<Shared> pshare;
protected:
	//发送信息
	virtual int set_message(const Message& m) final;
	virtual int try_set_message(const Message& m) final;
private:
	//-1 自动退出
	int status_code;
private:
	//获取消息  阻塞
	virtual Message get_message(int &rs);
	//获取消息 ，没有直接返回
	virtual Message try_get_message(int &rs) final;
};

inline void CallBack(BaseMod *p)
{
	p->run();
}
#endif // !BASE_MOD_H

