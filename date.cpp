#include "datee.h"
#include <iostream>
using namespace std;


	datee::datee(int day1, int month1, int year1) {
	day = day1;
	    month = month1;
		year = year1;

	}

	datee:: ~datee() {}
	int datee:: getday() {
		return day;
	}
	int datee::getmonth() {
		return month;
	}
	int datee :: getyear() {
		return year;
	}
		


	void datee ::displaydate() {
		cout << day << "/" << month << "/" << year << endl;
	}
