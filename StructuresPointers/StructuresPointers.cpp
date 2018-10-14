#include "pch.h"
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include "myDate.h"

using namespace std;

struct Student
{
	char name[20];
	int id;
	char grade;
	myDate bday;
	string hometown;
};

void menu();
void populate(Student arr[]);
void display(Student arr[]);
void display(Student *ptr[]);
void sortByName(Student *ptr[]);
void sortById(Student *ptr[]);
void sortByGrade(Student *ptr[]);
void sortByBday(Student *ptr[]);
void sortByHometown(Student *ptr[]);


int main()
{
	Student myClass[10];
	populate(myClass);
	Student *namePtr[10];
	Student *idPtr[10];
	Student *gradePtr[10];
	Student *bdayPtr[10];
	Student *hmeTwnPtr[10];
	for (int i = 0; i < 10; i++) {
		namePtr[i] = &myClass[i];
		idPtr[i] = &myClass[i];
		gradePtr[i] = &myClass[i];
		bdayPtr[i] = &myClass[i];
		hmeTwnPtr[i] = &myClass[i];
	}

	int menuChoice;
	do {
		menu();
		cin >> menuChoice;
		switch (menuChoice) {
		case 0: cout << "Original list" << endl << endl; display(myClass); break;
		case 1: cout << "Sorted by Name" << endl << endl; sortByName(namePtr); display(namePtr); break;
		case 2: cout << "Sorted by Student ID" << endl << endl; sortById(idPtr); display(idPtr); break;
		case 3: cout << "Sorted by Grade" << endl << endl; sortByGrade(gradePtr); display(gradePtr); break;
		case 4: cout << "Sorted by Birthday" << endl << endl; sortByBday(bdayPtr); display(bdayPtr); break;
		case 5: cout << "Sorted by Home Town" << endl << endl; sortByHometown(hmeTwnPtr); display(hmeTwnPtr); break;
		case 6: cout << "Exiting" << endl;  break;
		}
	} while (menuChoice != 6);

	/*
	// Testing sort by Name
	cout << endl;
	cout << "Unsorted Names" << endl;
	cout << endl;
	display(ptr);
	sortByName(ptr);
	cout << endl;
	cout << "Sorted names " << endl;
	cout << endl;
	display(ptr);

	// Testing sorting method for ID's
	cout << endl;
	cout << "Unsorted ID's" << endl;
	cout << endl;
	display(ptr);
	sortById(ptr);
	cout << endl;
	cout << "Sorted Ids" << endl;
	cout << endl;
	display(ptr);

	// Testing sort by grade
	cout << endl;
	cout << "Unsorted Grades" << endl << endl;
	cout << endl;
	display(ptr);
	sortByGrade(ptr);
	cout << endl;
	cout << "Sorted Grades" << endl;
	cout << endl;
	display(ptr);

	// Testing sort by age
	cout << endl;
	cout << "Unsorted Bdays" << endl;
	cout << endl;
	display(ptr);
	sortByBday(ptr);
	cout << endl;
	cout << "Sorted Bdays" << endl;
	cout << endl;
	display(ptr);

	// Testing sort by hometown
	cout << endl;
	cout << "Unsorted hometowns" << endl;
	cout << endl;
	display(ptr);
	sortByHometown(ptr);
	cout << endl;
	cout << "Sorted hometowns" << endl;
	cout << endl;
	display(ptr);
	*/
}

void menu() {
	cout << endl;
	cout << "0) Display original list" << endl;
	cout << "1) Display list sorted by Name" << endl;
	cout << "2) Display list sorted by Student ID " << endl;
	cout << "3) Display list sorted by Grade" << endl;
	cout << "4) Display list sorted by Birthday" << endl;
	cout << "5) Display list sorted by Home Town" << endl;
	cout << "6) Exit" << endl;
	cout << endl;
}

void populate(Student arr[]) {
	srand(time(NULL));
	//Generate names
	char names[10][30] = { "John Do", "Jane Do", "Abraham Lincoln", "Mother Teresa", "Nelson Mandela", "Bill Gates", "Steve Jobs", "Albert Einstein", "Thomas Edison", "George Orwell" };
	for (int n = 0; n < 10; n++) {
		strcpy_s(arr[n].name, names[n]);
	}

	//Generate random id numbers
	int generatedID[10];
	for (int i = 0; i < 10; i++) {
		generatedID[i] = rand() % (9999 - 1000) + 1000;
		// Check if id already created
		// If so then generate new rand num
		for (int j = i + 1; j < 10; j++) {
			if (generatedID[j] == generatedID[i])
				generatedID[j] = rand() % (9999 - 1000) + 1000;
		}
	}

	// Assign id's to students id list
	for (int z = 0; z < 10; z++) {
		arr[z].id = generatedID[z];
	}

	//Generate random bdays
	for (int k = 0; k < 10; k++) {
		arr[k].bday = myDate(rand() % (12 - 1) + 1, rand() % (31 - 1) + 1, rand() % (2000 - 1995) + 1995);
	}

	//Generate random grades
	char grades[5] = { 'A', 'B', 'C', 'D', 'F' };
	for (int g = 0; g < 10; g++) {
		arr[g].grade = grades[rand() % 5];
	}

	//Assign hometowns to students
	string hometowns[10] = { "Hermosa Beach", "Redondo Beach", "Long Beach", "Torrance", "Gardena", "Manhattan", "Inglewood", "Compton", "Watts", "Mars" };
	for (int h = 0; h < 10; h++) {
		arr[h].hometown = hometowns[h];
	}

}

void display(Student arr[]) {
	cout << left << setw(20) << "Name" << setw(20) << "Student ID" << setw(20) << "Grade" << setw(20) << "Birthday" << setw(20) << "Home Town" << endl;
	cout << left << setw(20) << "_____" << setw(20) << "__________" << setw(20) << "_____" << setw(20) << "________" << setw(20) << "__________" << endl;
	for (int i = 0; i < 10; i++) {
		cout << left << setw(20) << arr[i].name << setw(20) << arr[i].id << setw(20) << arr[i].grade << setw(20) << arr[i].bday.printDate() << setw(20) << arr[i].hometown << endl;
	}
}

void display(Student *ptr[]) {
	cout << left << setw(20) << "Name" << setw(20) << "Student ID" << setw(20) << "Grade" << setw(20) << "Birthday" << setw(20) << "Home Town" << endl;
	cout << left << setw(20) << "_____" << setw(20) << "__________" << setw(20) << "_____" << setw(20) << "________" << setw(20) << "__________" << endl;
	for (int i = 0; i < 10; i++) {
		cout << left << setw(20) << ptr[i]->name << setw(20) << ptr[i]->id << setw(20) << ptr[i]->grade << setw(20) << ptr[i]->bday.printDate() << setw(20) << ptr[i]->hometown << endl;
	}
}

void sortByName(Student * ptr[]) {
	Student *temp;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (strcmp(ptr[i]->name, ptr[j]->name) > 0) {
				temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;
			}
		}
	}
}

void sortById(Student * ptr[]) {
	Student *temp;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (ptr[j]->id < ptr[i]->id) {
				temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;

			}
		}
	}
}

void sortByGrade(Student * ptr[]) {
	Student *temp;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (ptr[j]->grade < ptr[i]->grade) {
				temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;
			}
		}
	}
}

void sortByBday(Student * ptr[]) {
	Student *temp;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (ptr[j]->bday.daysBetween(ptr[i]->bday) < 0) {
				temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;
			}
		}
	}
}

void sortByHometown(Student * ptr[]) {
	Student *temp;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (ptr[j]->hometown < ptr[i]->hometown) {
				temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;
			}
		}
	}
}
