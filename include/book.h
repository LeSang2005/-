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
	void setZWriter(std::string writer) { this->zWriter = writer; }
	std::string outWriter() { return zWriter; }
private:
	std::string bookName;
	std::string zWriter;
	int id;
};