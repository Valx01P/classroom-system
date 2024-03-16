#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Student.h"
#include "Grade.h"
using namespace std;

Student::Student(string first_n, string last_n, int s_id) {
	first_name = first_n;
	last_name = last_n;
	full_name = first_name + " " + last_name;
	student_id = s_id;
}

void Student::setFirstName(string fn) {
	first_name = fn;
	full_name = first_name + " " + last_name;
}

void Student::setLastName(string ln) {
	last_name = ln;
	full_name = first_name + " " + last_name;
}

void Student::grade_calculations() {
	float accumulator = 0;
	for (int i = 0; i < class_grades.size(); i++) {
		accumulator = class_grades[i].getScore() + accumulator;
	}
	float avg = accumulator / class_grades.size();
	overall_letter_grade = (avg > 90) ? 'A' :
		(avg > 80) ? 'B' :
		(avg > 70) ? 'C' :
		(avg > 60) ? 'D' :
		(avg < 60) ? 'F' : 'U';
	if (overall_letter_grade == 'A' || overall_letter_grade == 'B' || overall_letter_grade == 'C') {
		is_passing = true;
	}
	else {
		is_passing = false;
	}
	gpa = avg;
}

void Student::addOneGrade(Grade& newGrade) {
	class_grades.push_back(newGrade);
	grade_calculations();
}

void Student::removeGrade(int id) {
	for (auto it = class_grades.begin(); it != class_grades.end(); it++) {
		if (it->grade_id == id) {
			it = class_grades.erase(it);
			grade_calculations();
			return;
		}
	}
}

void Student::editAssignmentName(int id, string new_name) {
	if (class_grades.size() == 0) {
		return;
	}
	else {
		for (int i = 0; i < class_grades.size(); i++) {
			if (id == class_grades[i].grade_id) {
				class_grades[i].setAssignmentName(new_name);
			}
		}
	}
}


void Student::editAssignmentScore(int id, float new_score) {
	if (class_grades.size() == 0) {
		return;
	}
	else {
		for (int i = 0; i < class_grades.size(); i++) {
			if (id == class_grades[i].grade_id) {
				class_grades[i].setScore(new_score);
			}
		}
	}
}


string Student::getFullName() {
	return full_name;
}

string Student::getFirstName() {
	return first_name;
}

char Student::getLetterGrade() {
	return overall_letter_grade;
}

float Student::getGpa() {
	return gpa;
}

string Student::getPassStatus() {
	if (is_passing == true) {
		return "true";
	}
	else {
		return "false";
	}
}

int Student::getStudentId() {
	return student_id;
}

void Student::printGrades() {
	for (int i = 0; i < class_grades.size(); i++) {
		cout << class_grades[i].getLetterGrade() << " ";
	}
}
