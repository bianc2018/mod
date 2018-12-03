#include "mod_manager.h"

#include <stdio.h>

#include "define.h"

using namespace mod_flag;
std::shared_ptr<ModManager> ModManager::instance;

int ModManager::register_mod(BaseMod * mod)
{
	while (0!=mods.count(count))
	{
		++count;
	}
	mod->id = count;
	++count;
	//注册
	pshare->glog.print(INFO, "注册：", mod->name," ", mod->id);

	mods[mod->id].reset(mod);
	++mod_size;
	//名字与代码映射
	
	return 0;
}

int ModManager::unregister_mod(BaseMod * mod)
{
	pshare->glog.print(INFO, "注销：", mod->name.c_str()," ",mod->id);
	mod->kill();
	if (mod->this_thread != NULL)
		mod->this_thread->join();
	return 0;
}

int ModManager::load(string & mod_name)
{
	HMODULE hm= LoadLibraryA(mod_name.c_str());
	if (NULL == hm)
	{
		FreeLibrary(hm);
		return -1;
	}
	Load pload = (Load)GetProcAddress(hm, "LOAD");
	if (NULL == pload)
	{
		FreeLibrary(hm);
		return -2;
	}
	BaseMod * pmod = pload();
	if (NULL == pmod)
	{
		FreeLibrary(hm);
		return -3;
	}
	pmod->hmondule = hm;
	pmod->set_shared_data(pshare);
	pmod->this_thread = std::shared_ptr<std::thread>(new std::thread(CallBack,pmod));
	
	return register_mod(pmod);
}

int ModManager::unload(int id)
{
	auto finded = mods.find(id);
	if (mods.end() != finded)
	{
		if (unregister_mod(mods[id].get()) >= 0)
		{
			if(mods[id]->hmondule!=nullptr)
				FreeLibrary(mods[id]->hmondule);
			mods.erase(finded);
			return 0;
		}

	}
	return -1;
}

int ModManager::broadcast(const Message & msg)
{
	return 0;
}

ModManager::ModManager(const string & name) :mod_size(0), count(0), BaseMod(name)
{
	///load
	pshare = std::make_shared<Shared>("./glog.txt");
	add_mod_path("C:/Users/Administrator/source/repos/MOD/Debug/mod_test.dll");
}

std::shared_ptr<ModManager> ModManager::Instance()
{
	if (instance == nullptr)
		instance.reset(new ModManager("SYS"));
	return instance;
}

ModManager::~ModManager()
{
	for (int i=0;i<count;i++)
	{
		unload(i);
	}
}

void ModManager::process(const Message & msg)
{
	static int i = 0;
	switch (msg.code)
	{
	case msg_code::LOAD:
		break;

	case msg_code::UPDATA:
		i++;
		if (10 == i)
			kill();
		pshare->glog.print(INFO, "updata：", name," ", i);;
		break;
	default:
		//printf("Non msg code:%d\n", msg.code);
		break;
	}
	return ;
}

void ModManager::init()
{
	instance->id = count;
	++count;
	//注册
	pshare->glog.print(INFO, "初始化系统");

	mods[instance->id] = instance;
	++mod_size;
	//名字与代码映射
	pshare->name_id.set(instance->name, instance->id);


	//加载
	for (auto path : mod_paths)
		load(path);
}

void ModManager::add_mod_path(const string & abs_path)
{
	mod_paths.push_back(abs_path);
}
