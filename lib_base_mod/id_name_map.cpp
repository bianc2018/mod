#include "stdafx.h"
#include "id_name_map.h"
std::mutex  IdNameMap::lock;
std::multimap<std::string, int> IdNameMap::name_id;
void IdNameMap::set(const std::string & name, int id)
{
	name_id.insert({ name, id });
}

void IdNameMap::remove(int id)
{
	name_id.erase(get_name(id));
	
}

std::string IdNameMap::get_name(int id)
{
	for (auto in : name_id)
	{
		if (in.second == id)
			return in.first;
	}
	return std::string();
}

std::vector<int> IdNameMap::get_id(const std::string & name)
{
	std::vector<int> rs;
	for (auto in : name_id)
	{
		if (in.first == name)
			rs.push_back(in.second);
	}
	return rs;
}
