//�������ϵͳ
#ifndef MOD_MANAGER_H
#define MOD_MANAGER_H
#include <queue>
#include <string>
using std::string;

#include "mod.h"

class ModManager:public MOD //����Ҳ��һ�����
{
	//�������
	std::queue<MOD*> mod_queue;
	//��Ϣ����
	std::queue<Message> msg_queue;
public:
	int load(string&mod_name); //����һ�����
	int unload(string&id);	   //ж��һ�����
	int init();
	void run();
	ModManager();
	virtual ~ModManager();
private:
	//
private:
};
#endif // !MOD_MANAGER_H



