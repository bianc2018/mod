//���
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
	virtual void process(const Message&msg) = 0;//����
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
	//��������
	std::shared_ptr<Shared> pshare;
protected:
	//������Ϣ
	virtual int set_message(const Message& m) final;
	virtual int try_set_message(const Message& m) final;
private:
	//-1 �Զ��˳�
	int status_code;
private:
	//��ȡ��Ϣ  ����
	virtual Message get_message(int &rs);
	//��ȡ��Ϣ ��û��ֱ�ӷ���
	virtual Message try_get_message(int &rs) final;
};

inline void CallBack(BaseMod *p)
{
	p->run();
}
#endif // !BASE_MOD_H

