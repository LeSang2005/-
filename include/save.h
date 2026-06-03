#pragma once
#include<mysql.h>
#include<string>
class MySql {
public:
	static MySql& instance();
	~MySql();
	bool add(std::string words);
	bool update(std::string words);
	MYSQL_RES* query(std::string sql);
	MYSQL* outinit() { return init; }
private:
	MySql();
	MYSQL* init;
};