//插件管理系统
#ifndef MOD_MANAGER_H
#define MOD_MANAGER_H
#include <queue>
#include <string>
using std::string;

#include "mod.h"

class ModManager:public MOD //本身也是一个插件
{
	//插件队列
	std::queue<MOD*> mod_queue;
	//信息队列
	std::queue<Message> msg_queue;
public:
	int load(string&mod_name); //加载一个插件
	int unload(string&id);	   //卸载一个插件
	int init();
	void run();
	ModManager();
	virtual ~ModManager();
private:
	//
private:
};
#endif // !MOD_MANAGER_H



