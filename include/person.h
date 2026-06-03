#pragma once
#include<vector>
#include<string>
#include<book.h>
class book;
class Person {
public:
	enum sex;
	void setname(std::string);
	void setsex(Person::sex sex);
	void setAddRess(std::string addRess_);
	void setid(int id);
	std::string outName();
	Person::sex outSex();
	int outId();
	std::string outAddRess();
	std::string outPhone();
	void setPhone(std::string Phone);
	void clearbook();
	void addP_Book(book b,long long time);
	void look_Books();
	bool find_Books(std::string bname,int bid);
	bool has_books();
    enum sex {
		man = 0,
		woman
	};
	
private:
	
	std::string name_;
	sex sex_;
	std::string addRess_;
	std::vector<std::pair<book,long long>>jieYueBooks;
	std::string Phone;
	int id;

};