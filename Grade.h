#pragma once
#ifndef GRADE_H
#define GRADE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Grade {
private:
	string assignment_name;
	char assignment_letter_grade;
	float score_out_of_a_hundred;

public:
	int grade_id;
	Grade(float score, string a_name, int g_id);
	void setAssignmentName(string new_name);
	void setScore(float new_score);
	string getAssignmentName();
	char getLetterGrade();
	float getScore();
	int getId();


};

#endif