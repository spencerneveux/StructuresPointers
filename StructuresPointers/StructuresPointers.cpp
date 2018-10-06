// StructuresPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

void sortyById(Student *ptr) {
}

int main()
{
	Student myClass[10];
	populate(myClass);
	display(myClass);

}





