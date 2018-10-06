#include "pch.h"
#include <iostream>
#include <ctime>
#include <string>
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


void populate(Student arr[]) {
	srand(time(NULL));
	//Generate names
	string names[] = { "John Do", "Jane Do", "Abraham Lincoln", "Mother Teresa", "Nelson Mandela", "Bill Gates", "Steve Jobs", "Albert Einstein", "Thomas Edison", "George Orwell" };
	for (int n = 0; n < 10; n++) {
		strcpy_s(arr[n].name, "John");
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
	for (int i = 0; i < 10; i++) {
		cout << arr[i].name << " " << arr[i].id << " " << arr[i].grade << " " << arr[i].bday.printDate() << " " << arr[i].hometown << endl;
	}
}

void display(Student *ptr[]) {
	for (int i = 0; i < 10; i++) {
		cout << ptr[i]->id  << " " << ptr[i]->grade << " " << ptr[i]->bday.printDate() << endl;
	}
}

void sortyById(Student * ptr[]) {
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

int main()
{
	// Testing populate/display 
	Student myClass[10];
	populate(myClass);
	display(myClass);

	// Assigning array of pointers to student array
	Student * ptr[10];
	for (int i = 0; i < 10; i++) {
		ptr[i] = &myClass[i];
	}

	// Testing sorting method for ID's
	cout << "Unsorted ID's" << endl;
	display(ptr);
	sortyById(ptr);
	cout << "Sorted Ids" << endl;
	display(ptr);

	// Testing sort by grade
	cout << "Unsorted Grades" << endl;
	display(ptr);
	sortByGrade(ptr);
	cout << "Sorted Grades" << endl;
	display(ptr);

	// Testing sort by age
	cout << "Unsorted Bdays" << endl;
	display(ptr);
	sortByBday(ptr);
	cout << "Sorted Bdays" << endl;
	display(ptr);

	// Testing sort by hometown
	cout << "Unsorted hometowns" << endl;
	display(ptr);
	sortByHometown(ptr);
	cout << "Sorted hometowns" << endl;
	display(ptr);
}




