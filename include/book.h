#pragma once;
#include<string>

class book {
public:
	book();
	~book();
	void setid(int id);
	void setname(std::string name);
	int outid();
	std::string outBookName();
private:
	std::string bookName;
	int id;
};