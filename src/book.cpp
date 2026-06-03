#include"book.h"
#include<iostream>
book::book() = default;
book::~book() = default;
void book::setname(std::string name) {
	this->bookName = name;
}
void book::setid(int id) {
	this->id = id;
}

int book::outid() {
	return id;
}
std::string book::outBookName() {
	return bookName;
}