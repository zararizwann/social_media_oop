#ifndef DATEE_h
#define DATEE_H

class datee {
	int day;
	int month;
	int year;

public:
	datee(int day, int month, int year);
	~datee();

	int getday();
	int getmonth();
	int getyear();

	void displaydate();

};





#endif