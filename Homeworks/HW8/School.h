#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"
#include <fstream>
#include <sstream>
#include <iostream>

using std::cout, std::endl, std::string, std::ifstream, std::vector, std::stringstream,std::getline, std::stoi;

class School {
  
  std::vector<Course> courses;
  std::vector<Student> students;
  
public:
  void addCourses(std::string filename);
  void addStudents(std::string filename);
  void addAttendanceData(std::string filename);
  void listCourses();
  void listStudents();
  void outputCourseAttendance(std::string course_id);
  void outputStudentAttendance(std::string student_id, std::string course_id);

private:
	bool containsVal(std::vector<std::string> v, std::string val);
};

#endif