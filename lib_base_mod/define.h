#ifndef DEFINE_H
#define DEFINE_H
namespace mod_flag
{

	const static int SYSTEM_CALL(0);
	namespace msg_code
	{
		//��ʼ��
		const static int INIT(0);
		const static int UNINIT(1);
		//�����ӽ���
		const static int LOAD(2);
		const static int UNLOAD(3);
		//updata
		const static int UPDATA(4);

		const static int KILL(4);
	}
}
#endif // !DEFINE_H

