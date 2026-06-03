#pragma once
#include<chrono>
#include<iostream>
#include<string>
class Timestamp {
public:
	Timestamp();
	~Timestamp();
	std::tm now();
	static long long getNowTimeCuo();
	std::tm transfromTime(std::time_t time);
	
	std::string print(const std::tm& t) {
		std::string printday;
		printday += std::to_string(t.tm_year+1900);
		printday += "-";
		printday += std::to_string(t.tm_mon + 1);
		printday += "-";
		printday += std::to_string(t.tm_mday);
		printday += "-";
		printday += std::to_string(t.tm_hour);
		printday += ":";
		printday += std::to_string(t.tm_min);
		printday += ":";
		printday += std::to_string(t.tm_sec);
		return printday;
	}
	int jishuanDay(long long day1, long long day2);
	long long addDay(long long time,int day);
private:

};