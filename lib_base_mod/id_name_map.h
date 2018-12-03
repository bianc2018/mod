#ifndef ID_NAME_MAP_H//id_name_map.h
#define ID_NAME_MAP_H
#include <map>
#include <vector>
#include <string>
#include <mutex>

class IdNameMap
{
public:
	void set(const std::string &name, int id);
	void remove(int id);
	std::string get_name(int id);
	std::vector<int> get_id(const std::string &name);
private:
	static std::mutex lock;
	static std::multimap<std::string ,int> name_id;
};
#endif
