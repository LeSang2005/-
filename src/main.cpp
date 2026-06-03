#include"save.h"
#include"system.h"
#include<Timestamp.h>
int main() {
	MySql::instance();
	System::instance().showlogin();
	return 0;
}