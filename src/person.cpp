#include"person.h"
#include"Timestamp.h"
void Person::setAddRess(std::string addrRess) {
	this->addRess_ = addrRess;
}

void Person::setid(int id) {
	this->id = id;
}

void Person::setname(std::string name) {
	this->name_ = name;
}
std::string Person::outAddRess() {
	return addRess_;
}
void Person::setsex(Person::sex sex) {
	this->sex_ = sex;
}
std::string Person::outName() {
	return name_;
}
Person::sex Person::outSex() {
	return sex_;
}
int Person::outId() {
	return id;
}
std::string Person::outPhone() {
	return Phone;
}
void Person::setPhone(std::string Phone) {
	this->Phone = Phone;
}

void Person::clearbook() {
	jieYueBooks.clear();
}
void Person::addP_Book(book b, long long time) {
	jieYueBooks.push_back({b,time});
}
void Person::look_Books() {
	Timestamp time;
	std::cout << "书籍名\t\t" << "书籍编号\t" << "还书期限\n";
	for (int i = 0; i < jieYueBooks.size(); i++) {
		std::string t = time.print(time.transfromTime(jieYueBooks[i].second));
		std::cout << jieYueBooks[i].first.outBookName() << "\t" << jieYueBooks[i].first.outid() << "\t" << t;
		std::cout << std::endl;
	}
}

bool Person::find_Books(std::string bname,int id) {
	for (int i = 0; i < jieYueBooks.size(); i++) {
		auto it = jieYueBooks[i];
		if (it.first.outBookName() == bname && it.first.outid() == id) {
			return true;
		}
	}
	return false;
}

bool Person::has_books() {
	return jieYueBooks.empty();
}