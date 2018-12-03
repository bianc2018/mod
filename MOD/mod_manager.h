//�������ϵͳ
#ifndef MOD_MANAGER_H
#define MOD_MANAGER_H
#include <map>
#include <string>
#include <thread>
using std::string;

#include "base_mod.h"

typedef BaseMod*(*Load)();

class ModManager:public BaseMod //����Ҳ��һ�����
{
	//�������
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
	int load(string&mod_name); //����һ�����
	int unload(int id);	   //ж��һ�����
	//�㲥��Ϣ
	int broadcast(const Message &msg);

	
};
#endif // !MOD_MANAGER_H



