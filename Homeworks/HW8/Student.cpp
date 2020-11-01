#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(string student_id, string student_name) {
	id = student_id;
	name = student_name;
}

string Student::get_id() {
	return id;
}

string Student::get_name() {
	return name;
}

void Student::addCourse(string course_id) {
	
	bool valid = false;

	for (size_t i = 0; i < course_ids.size(); i++) {

		if (course_id == course_ids.at(i)) {
			valid = true;
		}
	}

	if (!valid) {
		course_ids.push_back(course_id);  // adding id to vector
	}
}

void Student::listCourses() {

	if (course_ids.size() == 0) {
		cout << "No Records\n";
	}
	else {

		cout << "Courses for " << id << "\n";
        
		for (size_t i = 0; i < course_ids.size(); i++) {

			cout << course_ids.at(i) << "\n";
		}
	}
}

