//Spencer Neveux
// CECS 282 (Project MyDate)
// September 26, 2018

#include "myDate.h"
#include <string>
#include <iostream>

using namespace std;

int Greg2Julian(int month, int day, int year) {
	int JD = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367
		* (month - 2 - (month - 14) / 12 * 12) / 12 - 3
		* ((year + 4900 + (month - 14) / 12) / 100) / 4;
	return JD;
}

void Julian2Greg(int JD, int & month, int & day, int & year) {
	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	int I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	int J = 80 * L / 2447;
	int K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}

myDate::myDate() {
	this->month = 5;
	this->day = 11;
	this->year = 1959;
}

myDate::myDate(int M, int D, int Y) {
	int jd = Greg2Julian(M, D, Y);
	int m1, d1, y1;
	Julian2Greg(jd, m1, d1, y1);
	if (M == m1 && D == d1 && Y == y1) {
		this->month = M;
		this->day = D;
		this->year = Y;
	}
	else {
		this->month = 5;
		this->day = 11;
		this->year = 1959;
	}
}


void myDate::display() {
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	cout << months[month - 1] << " " << day << ", " << year;
}


void myDate::increaseDate(int n) {
	int jd = Greg2Julian(month, day, year);
	jd += n;
	Julian2Greg(jd, month, day, year);
}

void myDate::decreaseDate(int n) {
	int jd = Greg2Julian(month, day, year);
	jd -= n;
	Julian2Greg(jd, month, day, year);
}

int myDate::daysBetween(myDate D) {
	int thisJD = Greg2Julian(month, day, year);
	int thatJD = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
	int difference = thatJD - thisJD;
	return difference;
}

int myDate::dayOfYear() {
	int baseJD = Greg2Julian(1, 1, year);
	int thisJD = Greg2Julian(month, day, year);
	int difference = thisJD - baseJD;
	return difference + 1;
}


string myDate::dayName() {
	string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int jd = Greg2Julian(month, day, year);
	int day = jd % 7;
	string result = days[day + 1];
	return result;
}

string myDate::printDate() {
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	string result = months[month - 1] + " " + std::to_string(day) + ", " + std::to_string(year);
	return result;
}