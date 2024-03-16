//bug - When creating a new grade or student you may have multiple
//		with the same id after deleting some students or grades
//		due to unspecified id creation behaviors
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Student.h"
#include "Grade.h"
using namespace std;

bool login();
void fillVector(vector<Student>&);
void mainMenu(vector<Student>&);
void addNewStudent(vector<Student>&);
void viewStudentList(vector<Student>&);
void dropSpecificStudent(vector<Student>&);
void viewSpecificStudent(vector<Student>&);

void studentSubMenu(vector<Student>&, int index);

void viewSpecificStudentGradeList(vector<Student>&, int index);
void addSpecificStudentGrade(vector<Student>&, int index);
void editSpecificStudentName(vector<Student>&, int index);
void editSpecificStudentGradeName(vector<Student>&, int index);
void editSpecificStudentGradeScore(vector<Student>&, int index);
void removeSpecificGradeFromSpecificStudent(vector<Student>&, int index);


int main() {
	if (login()) {

		vector<Student> myClass;
		fillVector(myClass);
		mainMenu(myClass);

	}
	else {
		cout << "\nInvalid credentials...\n";
		return 0;
	}

	cout << "\nExiting...\n";
	return 0;

}

void mainMenu(vector<Student>& mainClassVector) {
	bool exit = false;
	while (exit != true) {
		int choice;
		cout << endl << "[Enter '1'] Add new student" << endl << "[Enter '2'] View Student List" << endl;
		cout << endl << "[Enter '3'] Drop Student" << endl << "[Enter '4'] View Specific Student" << endl;
		cout << endl << "[Enter '5'] Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			//add more students
			addNewStudent(mainClassVector);
		}
		else if (choice == 2) {
			//view student list
			viewStudentList(mainClassVector);
		}
		else if (choice == 3) {
			//drop student
			dropSpecificStudent(mainClassVector);
		}
		else if (choice == 4) {
			//view specific student & actions
			viewSpecificStudent(mainClassVector);
		}
		else {
			exit = true;
		}
	}
}


void studentSubMenu(vector<Student>& studentSubClassVector, int index) {
	bool exit = false;
	while (exit != true) {
		int choice;
		cout << endl << "Sub Actions Menu for Student, " << studentSubClassVector[index].getFullName();
		cout << endl << "[Enter '1'] Add New Grade" << endl << "[Enter '2'] View Grade List" << endl;
		cout << endl << "[Enter '3'] Edit Student Name" << endl << "[Enter '4'] Remove Specific Grade" << endl;
		cout << endl << "[Enter '5'] Edit Grade Assignment Name" << endl << "[Enter '6'] Edit Grade Assignment Score" << endl;
		cout << endl << "[Enter '7'] Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			//add new grade for specific student
			addSpecificStudentGrade(studentSubClassVector, index);
		}
		else if (choice == 2) {
			//view the specific student's grade list
			viewSpecificStudentGradeList(studentSubClassVector, index);
		}
		else if (choice == 3) {
			//edit the specific student's name
			editSpecificStudentName(studentSubClassVector, index);
		}
		else if (choice == 4) {
			//remove a specific grade from the specific student
			removeSpecificGradeFromSpecificStudent(studentSubClassVector, index);
		}
		else if (choice == 5) {
			//edit a specific assignment name from the specific student
			editSpecificStudentGradeName(studentSubClassVector, index);
		}
		else if (choice == 6) {
			//edit a specific assignment score from the specific student
			editSpecificStudentGradeScore(studentSubClassVector, index);
		}
		else {
			exit = true;
		}
	}
}

void addSpecificStudentGrade(vector<Student>& studentSubClassVector, int index) {
	int input;
	cout << endl << "[Enter '1'] Confirm decision to add new grade for " << studentSubClassVector[index].getFirstName() << endl <<
		"[Enter '2'] Go back to Sub Action Menu" << endl;
	cin >> input;
	if (input == 1) {

		int x = studentSubClassVector[index].class_grades.size();
		string assignmentName;
		float assignmentScore;
		cout << endl << "S" << index << " / G" << x << ") Enter the new grade assignment score!" << endl;
		cin >> assignmentScore;
		cout << endl << "S" << index << " / G" << x << ") Enter the new grade assignment name!" << endl;
		cin.ignore(); // Use cin.ignore() to clear the newline left in the input buffer
		getline(cin, assignmentName);

		Grade newGrade(assignmentScore, assignmentName, x);
		studentSubClassVector[index].addOneGrade(newGrade);

		cout << endl << "Student " << studentSubClassVector[index].getFirstName() << " has successfully been added a new grade!" << endl;
		cout << endl;
	}
	else if (input == 2) {
		return;
	}
	else {
		cout << endl << "Invalid Response, returning..." << endl;
		return;
	}
}

void viewSpecificStudentGradeList(vector<Student>& studentSubClassVector, int index) {
	cout << endl << endl << "Printing out " << studentSubClassVector[index].getFirstName() << "'s Grade List..." << endl;
	cout << "Assignment Name       Grade       Score" << endl << endl;
	for (int i = 0; i < studentSubClassVector[index].class_grades.size(); i++) {
		cout << studentSubClassVector[index].class_grades[i].getAssignmentName() << setw(16) <<
			studentSubClassVector[index].class_grades[i].getLetterGrade() << setw(16) <<
			studentSubClassVector[index].class_grades[i].getScore() << endl;
	}
	cout << endl << studentSubClassVector[index].getFirstName() << "'s Grade List Printed Successfully! Returning to Sub Action Menu..." << endl;
}

void editSpecificStudentName(vector<Student>& studentSubClassVector, int index) {
	int input;
	cout << endl << "[Enter '1'] Confirm decision to edit name for Student " << studentSubClassVector[index].getFullName() << endl <<
		"[Enter '2'] Go back to Sub Action Menu" << endl;
	cin >> input;
	if (input == 1) {
		string new_first_name, new_last_name;
		cout << endl << "Enter the new first name for Student " << studentSubClassVector[index].getFullName() << ", ID " <<
			studentSubClassVector[index].getStudentId() << endl;
		cin >> new_first_name;
		studentSubClassVector[index].setFirstName(new_first_name);
		cout << endl << "Enter the new last name for Student " << studentSubClassVector[index].getFullName() << ", ID " <<
			studentSubClassVector[index].getStudentId() << endl;
		cin >> new_last_name;
		studentSubClassVector[index].setLastName(new_last_name);
		cout << endl << endl << "Student " << studentSubClassVector[index].getStudentId() << "'s name has been successfully updated to " <<
			studentSubClassVector[index].getFullName() << "!" << endl;
	}
	else if (input == 2) {
		return;
	}
	else {
		cout << endl << "Invalid Response, returning..." << endl;
		return;
	}
}

void removeSpecificGradeFromSpecificStudent(vector<Student>& studentSubClassVector, int index) {
	int input;
	cout << endl << "[Enter '1'] Confirm decision to remove grade from student " << studentSubClassVector[index].getFirstName()
		<< endl << "[Enter '2'] Go back to Main Menu" << endl;
	cin >> input;
	if (input == 1) {
		cout << endl << endl << "Take a moment to view the grade list" << endl;
		cout << "Printing out " << studentSubClassVector[index].getFirstName() << "'s Grades List..." << endl;
		cout << "ID      Name           Score" << endl << endl;
		for (int i = 0; i < studentSubClassVector[index].class_grades.size(); i++) {
			cout << studentSubClassVector[index].class_grades[i].getId() << setw(14) << studentSubClassVector[index].class_grades[i].getAssignmentName()
				<< setw(12) << studentSubClassVector[index].class_grades[i].getScore() << endl;
		}
		cout << endl << "Now input the ID of the grade you wish to remove from " << studentSubClassVector[index].getFirstName() << "'s grade list..." << endl;
		cin.ignore();
		int dropGradeId;
		cin >> dropGradeId;
		studentSubClassVector[index].removeGrade(dropGradeId);
		cout << endl << "Grade " << dropGradeId << " has been successfully removed! Returning to Sub Action Menu..." << endl;
		return;
	}
	else if (input == 2) {
		return;
	}
	else {
		cout << endl << "Invalid Response, returning..." << endl;
		return;
	}
}
//TODO
void editSpecificStudentGradeName(vector<Student>& studentSubClassVector, int index) {

}

void editSpecificStudentGradeScore(vector<Student>& studentSubClassVector, int index) {

}


void viewSpecificStudent(vector<Student>& subClassVector) {
	int input;
	cout << endl << "[Enter '1'] Confirm decision to find a specific student" << endl << "[Enter '2'] Go back to Main Menu" << endl;
	cin >> input;
	if (input == 1) {
		cout << endl << endl << "Take a moment to view the student list" << endl;
		cout << "Printing out Student List..." << endl;
		cout << "ID      Name" << endl << endl;
		for (int i = 0; i < subClassVector.size(); i++) {
			cout << subClassVector[i].getStudentId() << setw(14) << subClassVector[i].getFirstName() << endl;
		}
		cout << endl << "Now input the ID of the student you want to view specifically" << endl;
		int s_Id, i;
		cin >> s_Id;
		for (i = 0; i < subClassVector.size(); i++) {
			if (s_Id == subClassVector[i].getStudentId()) {
				break;
			}
		}
		cout << endl << "Student " << subClassVector[i].getFirstName() << " Found!" << endl;
		cout << "Now Entering Student " << subClassVector[i].getFirstName() << "'s Sub Actions Menu" << endl;
		studentSubMenu(subClassVector, i);
	}
	else if (input == 2) {
		return;
	}
	else {
		cout << endl << "Invalid Response, returning..." << endl;
		return;
	}
}


void dropSpecificStudent(vector<Student>& subClassVector) {
	int input;
	cout << endl << "[Enter '1'] Confirm decision to drop student" << endl << "[Enter '2'] Go back to Main Menu" << endl;
	cin >> input;
	if (input == 1) {
		cout << endl << endl << "Take a moment to view the student list" << endl;
		cout << "Printing out Student List..." << endl;
		cout << "ID      Name           Passing?" << endl << endl;
		for (int i = 0; i < subClassVector.size(); i++) {
			cout << subClassVector[i].getStudentId() << setw(14) << subClassVector[i].getFirstName() << setw(12) <<
				subClassVector[i].getPassStatus() << endl;
		}
		cout << endl << "Now input the ID of the student you wish to drop" << endl;
		cin.ignore();
		int dropId;
		cin >> dropId;
		for (auto it = subClassVector.begin(); it != subClassVector.end(); it++) {
			if (it->getStudentId() == dropId) {
				it = subClassVector.erase(it);
				cout << endl << "Student " << dropId << " has been successfully dropped! Returning to Main Menu..." << endl;
				return; //return to end the function / loop and prevent the iterator from moving past the end of the vector
			}
		}
	}
	else if (input == 2) {
		return;
	}
	else {
		cout << endl << "Invalid Response, returning..." << endl;
		return;
	}
}


void viewStudentList(vector<Student>& subClassVector) {
	cout << endl << endl << "Printing out Student List..." << endl;
	cout << "Name           Class Grade       GPA       Passing?" << endl << endl;
	for (int i = 0; i < subClassVector.size(); i++) {
		cout << subClassVector[i].getFirstName() << setw(16) << subClassVector[i].getLetterGrade() << setw(16) <<
			subClassVector[i].getGpa() << setw(12) << subClassVector[i].getPassStatus() << endl;
	}
	cout << endl << "Student List Printed Successfully! Returning to Main Menu..." << endl;
}

void addNewStudent(vector<Student>& subClassVector) {
	int input;
	cout << endl << "[Enter '1'] Confirm Add new student" << endl << "[Enter '2'] Go back to Main Menu" << endl;
	cin >> input;
	if (input == 1) {
		int index = subClassVector.size();
		string firstName, lastName;
		cout << endl << "S" << index << ") What is student " << index << "'s first name?" << endl;
		cin >> firstName;
		cout << endl << "S" << index << ") What is student " << index << "'s last name?" << endl;
		cin >> lastName;

		Student newStudent(firstName, lastName, index);
		subClassVector.push_back(newStudent);

		cout << endl << "How many grades does student " << firstName << " have?" << endl;
		int gradesAmount;
		cin >> gradesAmount;

		for (int x = 0; x < gradesAmount; x++) {
			string assignmentName;
			float assignmentScore;
			cout << endl << "S" << index << " / G" << x << ") For grade " << x << ", what was the score?" << endl;
			cin >> assignmentScore;
			cout << endl << "S" << index << " / G" << x << ") For grade " << x << ", what was the assignment name?" << endl;
			cin.ignore(); // Use cin.ignore() to clear the newline left in the input buffer
			getline(cin, assignmentName);

			Grade newGrade(assignmentScore, assignmentName, x);
			subClassVector[index].addOneGrade(newGrade);
		}
		cout << endl << "Student " << firstName << " has grades: " << endl;
		subClassVector[index].printGrades();
		cout << endl;
	}
	else if (input == 2) {
		return;
	}
	else {
		cout << endl << "Invalid Response, returning..." << endl;
		return;
	}
}


void fillVector(vector<Student>& newMyClass) {
	int classSize;
	cout << endl << "Loading Preliminary Setup..." << endl;
	cout << endl << "How many students are in your classroom?" << endl;
	cin >> classSize;

	for (int i = 0; i < classSize; i++) {
		string firstName, lastName;
		cout << endl << "S" << i << ") What is student " << i << "'s first name?" << endl;
		cin >> firstName;
		cout << endl << "S" << i << ") What is student " << i << "'s last name?" << endl;
		cin >> lastName;

		Student newStudent(firstName, lastName, i);
		newMyClass.push_back(newStudent);

		cout << endl << "How many grades does student " << firstName << " have?" << endl;
		int gradesAmount;
		cin >> gradesAmount;

		for (int x = 0; x < gradesAmount; x++) {
			string assignmentName;
			float assignmentScore;
			cout << endl << "S" << i << " / G" << x << ") For grade " << x << ", what was the score?" << endl;
			cin >> assignmentScore;
			cout << endl << "S" << i << " / G" << x << ") For grade " << x << ", what was the assignment name?" << endl;
			cin.ignore(); // Use cin.ignore() to clear the newline left in the input buffer
			getline(cin, assignmentName);

			Grade newGrade(assignmentScore, assignmentName, x);
			newMyClass[i].addOneGrade(newGrade);
		}
		cout << endl << "Student " << firstName << " has grades: " << endl;
		newMyClass[i].printGrades();
		cout << endl;
	}
}

bool login() {
	string pass = "password",
		user = "username",
		inputUser,
		inputPass;
	cout << "Login with your credentials below \n======================================\n";
	cout << "Username: \n";
	cin >> inputUser;
	cout << "\nPassword: \n";
	cin >> inputPass;
	if (inputUser == user && inputPass == pass) {
		return true;
	}
	else {
		return false;
	}
}
