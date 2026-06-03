#include"Timestamp.h"
#include<math.h>
Timestamp::Timestamp() {}
Timestamp::~Timestamp() {}
std::tm Timestamp::now() {
    auto now_point = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(now_point);
    return transfromTime(tt);
}

std::tm Timestamp::transfromTime(std::time_t time) {
	std::tm ptm = *std::localtime(&time);
	return ptm;
}

long long Timestamp::getNowTimeCuo() {
    return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

int Timestamp::jishuanDay(long long day1, long long day2) {
    const long long oneday = 24 * 60 * 60;
    return std::abs(day1 - day2) / oneday;
}

long long Timestamp::addDay(long long day1, int day) {
    const long long oneday = 24 * 60 * 60;
    return day1 + oneday * day;
}

