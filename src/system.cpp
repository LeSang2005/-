#include"system.h"
#include"save.h"
#include"Timestamp.h"
System& System::instance() {
	static System system_;
	return system_;
}

void System::showbooks() {
	system("cls");
	allbook.clear();
	addbook();
	if (allbook.empty()) {
		std::cout << "书架为空，过段时间再来吧！\n";
		return;

	}
	std::cout << "书籍id\t" << "书籍名称\t\n";
	for (int i = 0; i < allbook.size(); i++) {
		std::cout << allbook[i].outid() << "\t" << allbook[i].outBookName() << "\t\n";
	}
}

void System::xiuGaiName() {
	std::cout << "请输入新名字:";
	std::string name;
	std::cin >> name;
	std::string word = "update person set name=";
	word += "'";
	word += name;
	word += "' ";
	word += "where id=";
	word += std::to_string(person.outId());
	word += ";";
	std::cout << word;
	MySql::instance().update(word);
}
void System::xiuGaisex() {
	std::cout << "请输入新性别:";
	std::string sex_;
	std::cin >> sex_;
	std::string word = "update person set sex=";
	word += "'";
	word += sex_;
	word += "' ";
	word += "where id=";
	word += std::to_string(person.outId());
	word += ";";
	std::cout << word;
	MySql::instance().update(word);
}
void System::xiuGaiAddress() {
	std::cout << "请输入新地址:";
	std::string address_;
	std::cin >> address_;
	std::string word = "update person set address=";
	word += "'";
	word += address_;
	word += "' ";
	word += "where id=";
	word += std::to_string(person.outId());
	word += ";";
	std::cout << word;
	MySql::instance().update(word);
}
void System::xiuGaiPhone() {
	std::cout << "请输入新电话:";
	std::string phone_;
	std::cin >> phone_;
	std::string word = "update person set phone=";
	word += "'";
	word += phone_;
	word += "' ";
	word += "where id=";
	word += std::to_string(person.outId());
	word += ";";
	std::cout << word;
	MySql::instance().update(word);
}
void System::System::showperson() {
	system("cls");
	while (1) {
		std::cout << "账号\t" << "姓名\t" << "性别\t" << "地址\t" << "电话号码\t\n";
		std::cout << person.outId() << "\t" << person.outName() << "\t" << (person.outSex() == Person::sex::man ? "男" : "女");
		std::cout << "\t" << person.outAddRess() << "\t" << person.outPhone() << "\t\n";
		std::cout << "1.修改姓名\n";
		std::cout << "2.修改性别\n";
		std::cout << "3.修改地址\n";
		std::cout << "4.修改电话号码\n";
		std::cout << "5.返回\n";
		int n;
		std::cin >> n;
		if (n == 1) {
			xiuGaiName();
		}
		if (n == 2) {
			xiuGaisex();
		}
		if (n == 3) {
			xiuGaiAddress();
		}
		if (n == 4) {
			xiuGaiPhone();
		}
		if (n == 5) {
			break;
		}
	}
}
void System::menu() {
	while (1) {
		std::cout << "welcome to book system\n";
		std::cout << "0.退出\n";
		std::cout << "1.阅览所有书籍(可借阅)\n";
		std::cout << "2.个人信息面版\n";
		std::cout << "3.我借阅的书籍\n";
		std::cout << "4.借书\n";
		std::cout << "5.还书\n";
		int n;
		std::cin >> n;
		if (n == 0)break;
		if (n == 1) {
			showbooks();
			system("pause");
			system("cls");
		}
		else if (n == 2) {
			showperson();
			system("pause");
			system("cls");
		}
		else if (n == 3) { findmybook();
		system("pause");
		system("cls");
		}
		else if (n == 4) { borrowBook(); 
		system("pause");
		system("cls");
		}
		else if (n == 5) {
			rbook();
			system("pause");
			system("cls");
		}
		else {
			std::cout << "功能未开发" << std::endl;
		}
	}
}

bool System::zhuChe() {
	std::vector<std::string>sum_;

	std::string name;
	std::cout << "请输入姓名：";
	std::cin >> name;
	sum_.push_back(name);
	std::cout << std::endl;

	std::string sex;
	std::cout << "请输入性别：";
	std::cin >> sex;
	sum_.push_back(sex);
	std::cout << std::endl;

	std::string addRess;
	std::cout << "请输入地址：";
	std::cin >> addRess;
	sum_.push_back(addRess);
	std::cout << std::endl;

	std::string Phone;
	std::cout << "请输入电话号码:";
	std::cin >> Phone;
	sum_.push_back(Phone);
	std::string all;
	std::string zhanghao;

	std::string mima;
	std::cout << "请输入密码:";
	std::cin >> mima;



	all = "insert into person(name,sex,address,phone) values(";
	for (int i = 0; i < sum_.size(); ++i) {
		all += "'";
		all += sum_[i];
		all += "'";
		all += ",";
	}

	all.pop_back();
	all += (");");
	std::cout << all << std::endl;
	
     MySql::instance().add(all);
	unsigned long long id = mysql_insert_id(MySql::instance().outinit());
	std::cout << "务必记住给你的账号:" << id<<std::endl;
	
	zhanghao = "insert into users(id,password) values(";
	std::string id_ = std::to_string(id);
	zhanghao += id_;
	zhanghao += ",";
	zhanghao += mima;
	zhanghao += ");";
	MySql::instance().add(zhanghao);
	std::cout << zhanghao << std::endl;
	return true;
}
void System::showlogin() {
	while (1) {
		std::cout << "1.登录\n";
		std::cout << "2.注册\n";
		std::cout << "3.退出\n";
		int n;
		std::cin >> n;
		if (n == 1) {
			std::cout << "请输入账号:";
			std::string zhangHao;
			std::cin >> zhangHao;
			std::cout << "请输入密码:";
			std::string miMa;
			std::cin >> miMa;
			if (find(zhangHao, miMa)) {
				init();
				system("cls");
				menu();
			}
			else{
				std::cout << "登录失败" << std::endl;
			}
		}
		else if (n == 2) {
			if (zhuChe()) {
				std::cout << "注册成功\n";
			}
			else {
				std::cout << "注册失败\n";
			}
		}
		else if (n == 3) {
			break;
		}
		else {
			std::cout << "没有开发功能\n";
		}
	}
}
bool System::find(std::string user, std::string password) {
	std::string word = "select id,password from users where id=";
	word += user;
	word += ";";
	std::cout << word << std::endl;
	MYSQL_RES* result=MySql::instance().query(word);
	MYSQL_ROW row;
	std::string truepassword;
	while ((row = mysql_fetch_row(result))) {
		truepassword = row[1];
	}
	mysql_free_result(result);
	if (truepassword == password) {
		person.setid(std::atoi(user.c_str()));
		std::string newword = "select * from person where id=";
		newword += user;
		newword += ";";
		std::cout << newword;
		MYSQL_RES* user_ = MySql::instance().query(newword);
		while ((row = mysql_fetch_row(user_))) {
			person.setname(row[1]);
			if (std::string(row[2]) == "男") {
				person.setsex(Person::sex::man);
			}
			else {
				person.setsex(Person::sex::woman);
			}
			person.setAddRess(row[3]);
			person.setPhone(row[4]);
		}
		mysql_free_result(user_);
		return true;
	}
	return false;
}
bool System::init() {
	addbook();
	return true;
}

void System::addbook() {
	std::string word = "select * from book;";
	MYSQL_RES* books = MySql::instance().query(word);
	MYSQL_ROW row;
	while ((row=mysql_fetch_row(books))) {
		book book_temp;
		book_temp.setid(atoi(row[0]));
		book_temp.setname(row[1]);
		allbook.push_back(book_temp);
	}
}

void System::borrowBook() {
	allbook.clear();
	addbook();
	system("cls");
	showbooks();
	if (allbook.empty()) {
		std::cout << "书架为空,过段时间再来吧\n";
		return;
	}
	while (1) {
		std::cout << "请输入你要借阅的书籍\n";
		std::string book;
		std::cin >> book;
		bool one = true;
		for (int i = 0; i < allbook.size(); i++) {
			if (allbook[i].outBookName() == book) {
				one = false;
				break;
			}
		}
		if (one) {
			std::cout << "没有该书籍" << std::endl;
			continue;
		}
		std::cout << "请输入书籍编号：";
		int n;
		std::cin >> n;
		bool two = true;
		for (int i = 0; i < allbook.size(); i++) {
			if (allbook[i].outid() == n && allbook[i].outBookName() == book) {
				two = false;
			}
		}
		if (two) {
			std::cout << "没有该书籍\n";
			continue;
		}
		int day;
		std::cout << "请输入借阅的天数（不超过7天）\n";
		std::cin >> day;
		if (day > 7||day<0) {
			std::cout << "违法行为\n";
			break;
		}
		Timestamp now;
		long long nowtime = now.getNowTimeCuo();
		long long nexttime = now.addDay(nowtime,day);
		std::string word1 = "insert into borrowlist(id,bid,dueday,bookname) values(";
		word1 = word1 + std::to_string(person.outId())+","+std::to_string(n)+","+std::to_string(nexttime)+","+"'"+book+"'"+");";
		MySql::instance().add(word1);
		std::string word2 = "delete from book where bid=";
		word2 = word2 + std::to_string(n) + ";";
		MySql::instance().update(word2);
		break;
	}
}

void System::findmybook() {
	system("cls");
	person.clearbook();
	std::string word = "select bid,bookname,dueday from borrowlist where id=";
	word =word+ std::to_string(person.outId())+";";
	MYSQL_RES* result = MySql::instance().query(word);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
		book b;
		b.setid ( atoi(std::string(row[0]).c_str()));
		b.setname(std::string(row[1]));
		long long time = atol(std::string(row[2]).c_str());
		person.addP_Book(b,time);
	}
	person.look_Books();
	mysql_free_result(result);
	if (person.has_books()) {
		std::cout << "您当前没有借书记录\n";
		return;
	}
}

void System::rbook() {
	person.clearbook();
	std::string word = "select bid,bookname,dueday from borrowlist where id=";
	word = word + std::to_string(person.outId()) + ";";
	MYSQL_RES* result = MySql::instance().query(word);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
		book b;
		b.setid(atoi(std::string(row[0]).c_str()));
		b.setname(std::string(row[1]));
		long long time = atol(std::string(row[2]).c_str());
		person.addP_Book(b, time);
	}
	person.look_Books();
	mysql_free_result(result);
	if (person.has_books()) {
		std::cout << "您当前没有借书记录\n";
		return;
	}
	std::cout << "请输入需要还书的名字:";
	std::string b_name;
	std::cin >> b_name;
	std::cout << "请输入需要还书的编号:";
	int m;
	std::cin >> m;
	if (!person.find_Books(b_name, m)) {
		std::cout << "还书失败，不存在这本书\n";
		return;
	}
	std::string word2 = "insert into book(bid,name) values(";
	word2 = word2 + std::to_string(m) + ",'" + b_name+"');";
	MySql::instance().add(word2);
	std::string word3 = "delete from borrowlist where id=";
	word3 = word3 + std::to_string(person.outId())+" and "+"bid="+std::to_string(m) + ";";
	MySql::instance().update(word3);
}