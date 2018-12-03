//插件管理系统
#ifndef MOD_MANAGER_H
#define MOD_MANAGER_H
#include <map>
#include <string>
#include <thread>
using std::string;

#include "base_mod.h"

typedef BaseMod*(*Load)();

class ModManager:public BaseMod //本身也是一个插件
{
	//插件队列
	std::map<int,std::shared_ptr<BaseMod>> mods;
public:
	static std::shared_ptr<ModManager> Instance();

	virtual ~ModManager();
	virtual void process(const Message&msg)override;
	virtual void init()override;

	void add_mod_path(const string&abs_path);
private:
	int mod_size;
	int count;
	std::vector<string> mod_paths;

	static std::shared_ptr<ModManager> instance;

private:
	ModManager(const string&name);

	int register_mod(BaseMod*mod);
	int unregister_mod(BaseMod*mod);
	int load(string&mod_name); //加载一个插件
	int unload(int id);	   //卸载一个插件
	//广播信息
	int broadcast(const Message &msg);

	
};
#endif // !MOD_MANAGER_H



