#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Grade.h"
using namespace std;

class Student {
private:
	string first_name, last_name, full_name;
	char overall_letter_grade;
	float gpa;
	bool is_passing;
	int student_id;

public:
	vector<Grade> class_grades;
	Student(string first_name, string last_name, int s_id);
	void setFirstName(string fn);
	void setLastName(string ln);
	void addOneGrade(Grade& newGrade);
	void removeGrade(int id);
	void editAssignmentName(int id, string new_name);
	void editAssignmentScore(int id, float new_score);
	void grade_calculations();

	string getFullName();
	string getFirstName();
	char getLetterGrade();
	float getGpa();
	string getPassStatus();
	void printGrades();
	int getStudentId();
};

#endif