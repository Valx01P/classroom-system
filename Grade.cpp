#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Grade.h"
using namespace std;

Grade::Grade(float score, string a_name, int g_id) {
	score_out_of_a_hundred = score;
	assignment_name = a_name;
	grade_id = g_id;
};

int Grade::getId() {
	return grade_id;
}

float Grade::getScore() {
	return score_out_of_a_hundred;
}

string Grade::getAssignmentName() {
	return assignment_name;
}

char Grade::getLetterGrade() {
	float s = score_out_of_a_hundred;
	char grade = (s > 90) ? 'A' :
		(s > 80) ? 'B' :
		(s > 70) ? 'C' :
		(s > 60) ? 'D' :
		(s < 60) ? 'F' : 'U';
	assignment_letter_grade = grade;
	return assignment_letter_grade;
}

void Grade::setScore(float new_score) {
	score_out_of_a_hundred = new_score;
}

void Grade::setAssignmentName(string new_name) {
	assignment_name = new_name;
}