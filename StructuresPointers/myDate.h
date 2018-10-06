
#ifndef myDate_h
#define myDate_h

#include <string>
class myDate {
private:
	int year;
	int month;
	int day;
public:
	myDate();
	myDate(int m, int d, int y);
	void display();
	void increaseDate(int n);
	void decreaseDate(int n);
	int daysBetween(myDate D);
	int getMonth() { return month; }
	int getDay() { return day; }
	int getYear() { return year; }
	int dayOfYear();
	std::string dayName();
	std::string printDate();
};
#endif