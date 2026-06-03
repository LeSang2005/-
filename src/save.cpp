#include"save.h"
#include<iostream>
MySql& MySql::instance() {
	static MySql sql;
	return sql;
}
MySql::MySql() {
    init = mysql_init(NULL);
    if (mysql_real_connect(init,
        "localhost",
        "root",
        "123456",
        "systembook",
        3306,
        nullptr,
        0)) {
        std::cout << "连接成功\n";
    }
    mysql_query(init, "SET NAMES gbk");
}

MySql::~MySql() {
    mysql_close(init);
}

bool MySql::add(std::string words) {
    if (init == nullptr) {
        std::cout << __FUNCTION__ << "出错：没有初始化\n";
        return false;
    }
    int num_=mysql_query(
        init,       // 连接句柄
        words.c_str()       // SQL 字符串（INSERT ...）
    );
    if (num_ == 0) {
        std::cout << "插入成功\n";
        return true;
    }
    else {
        std::cout << "插入失败！SQL语句：" << words << std::endl;
        std::cout << "MySQL 错误原因：" << mysql_error(init) << std::endl;
        return false;
    }
}

MYSQL_RES* MySql::query(std::string words) {
    if (init == nullptr) {
        std::cout << __FUNCTION__ << "出错：没有初始化\n";
        return nullptr;
    }
    int num_ = mysql_query(init,words.c_str());
    if (num_ == 0) {
        std::cout << "查询成功\n";
        MYSQL_RES* result = mysql_store_result(init);
        return result;
    }
    else {
        std::cout << "查询失败\n";
        std::cout << "MySQL 错误原因：" << mysql_error(init) << std::endl;
        return nullptr;
    }
}

bool MySql::update(std::string words) {
    if (init == nullptr) {
        std::cout << __FUNCTION__ << "出错：没有初始化\n";
        return nullptr;
    }
    int n = mysql_query(init,words.c_str());
    if (n == 0) {
        std::cout << "更新成功\n";
        return false;
    }
    else {
        std::cout << "更新失败\n";
        std::cout << "MySQL 错误原因：" << mysql_error(init) << std::endl;
        return false;
    }
}