#pragma once
#include<iostream>
#include<book.h>
#include"person.h"
#include<string>
#include<vector>
#include<unordered_map>
#include<book.h>
#include<person.h>
class System {
public:

	static System& instance();
	void showlogin();
	void menu();
	bool zhuChe();
	bool find(std::string user,std::string password);
	void showbooks();
	void showperson();
	void borrowBook();
	void findmybook();
	void rbook();
	void fuZhu();
private:
	std::string nowperson;
	System() {
		
	}
	bool init();
	void addbook();
	void xiuGaiName();
	void xiuGaisex();
	void xiuGaiAddress();
	void xiuGaiPhone();
	Person person;
	std::vector<book>allbook;
};
