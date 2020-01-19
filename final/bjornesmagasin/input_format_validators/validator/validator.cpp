#include "validator.h"
#include <set>
using namespace std;

const int monthDays[12] = {
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31,
};

void run() {
	int numBears = Int(1, Arg("nMax"));
	Space();
	Int(1, Arg("dMax"));
	Endl();

	int yearDays = 0;
	for (int j = 0; j < 12; j++)
		yearDays += monthDays[j];
	assert(yearDays == 365);

	for (int i = 0; i < numBears; i++) {
		char a = Char();
		char b = Char();
		char c = Char();
		char d = Char();
		char e = Char();
		Endl();
		assert(c == '/');
		assert('0' <= a && a <= '9');
		assert('0' <= b && b <= '9');
		assert('0' <= d && d <= '9');
		assert('0' <= e && e <= '9');
		int day = (a - '0') * 10 + (b - '0');
		int month = (d - '0') * 10 + (e - '0');
		assert(1 <= month && month <= 12);
		assert(1 <= day && day <= monthDays[month - 1]);
	}
}
