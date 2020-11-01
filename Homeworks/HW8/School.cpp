#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"

using namespace std;

/* Sameer Hussain - CSCE 121 - Attendance */

// need a helper function for validity that a value exists within vector

bool School::containsVal(vector<string> v, string val) {
    
  for (size_t i = 0; i < v.size(); i++) {
    if (val == v.at(i)) {
      return true;
    } 
  }

  return false;
}



void School::addStudents(string filename) {

  ifstream ifs(filename);

  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
    }

  string line, stuID, stName;

  vector<string> studentIDs;

  while (!ifs.eof()) {
    getline(ifs, line);
    stringstream ss(line);

    if (line == "" && ifs.eof()) {
      break;
    }
    getline(ss, stuID, ',');
    if (containsVal(studentIDs, stuID)) {
      continue;
    }
    getline(ss, stName);
    Student stu(stuID, stName);


    students.push_back(stu); // adding to vector
  studentIDs.push_back(stuID); 

  }

  ifs.close();

}

void School::listStudents() {
  
  if (students.size() == 0) {
    cout << "No Students\n";
  }
  else {
    for (size_t i = 0; i < students.size(); ++i)
    {
      cout << students.at(i).get_id() << "," << students.at(i).get_name() << "\n";
    }
  }
}

void School::addCourses(string filename) {

  ifstream ifs(filename);

  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
    }

  string line, stuID, titleT, hour, min, endHr, endMin;

  vector<string> courseIDs;

  while (!ifs.eof()) {

    getline(ifs, line);
    stringstream ss(line);

    if (line == "" && ifs.eof()) {
      break;
    }

    getline(ss, stuID, ',');
    
    if (containsVal(courseIDs, stuID)) {
      continue;
    }

    getline(ss, hour, ':');
    getline(ss, min, ',');
    getline(ss, endHr,  ':');
    getline(ss, endMin, ',');
    getline(ss, titleT);

    Date tempStart(stoi(hour), stoi(min));  // string to int
    Date tempEnd(stoi(endHr), stoi(endMin));

    Course tcourse(stuID, titleT, tempStart, tempEnd);  //add to courses

    courses.push_back(tcourse);

    courseIDs.push_back(stuID);

  }

  ifs.close();

}

void School::listCourses() {
  
  if (courses.size() == 0) {
    cout << "No Courses\n";
  }
  else {
    for (size_t i = 0; i < courses.size(); i++) {
      cout << courses.at(i).getID() << "," << courses.at(i).getStartTime().getTime(false) << ",";
      cout << courses.at(i).getEndTime().getTime(false) << "," << courses.at(i).getTitle() << "\n";
    }
  }
}

void School::addAttendanceData(string filename) {

  ifstream ifs(filename);

  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
    }

  string line, yr, month, day, tempHr, tMin, secs, tcourse, stuID;



  while (!ifs.eof()) {

    getline(ifs, line);
    stringstream ss(line);
    if (line == "" && ifs.eof()) {
      break;
    }

    getline(ss, yr, '-');
    getline(ss, month, '-');
    getline(ss, day, ' ');
    getline(ss, tempHr,  ':');
    getline(ss, tMin, ':');
    getline(ss, secs, ',');
    getline(ss, tcourse, ',');
    getline(ss, stuID);

    Date swipeT(stoi(yr), stoi(month), stoi(day), stoi(tempHr), stoi(tMin), stoi(secs));

    for (size_t i = 0; i < courses.size(); i++) {
      if (courses.at(i).getID() == tcourse) {

        if (swipeT >= courses.at(i).getStartTime() && swipeT <= courses.at(i).getEndTime()) {

          AttendanceRecord tempRecord(tcourse, stuID, swipeT); // adding to attendance record
          courses.at(i).addAttendanceRecord(tempRecord);
        } else {
          cout << "did not save this record.\n";
        }
        break;
      }
    }
  }

  ifs.close();

}

void School::outputCourseAttendance (string course_id) {

  bool valid = false;

  for (size_t i = 0; i < courses.size(); i++) {

    if (courses.at(i).getID() == course_id) {

      courses.at(i).outputAttendance();
      valid = true;
      break;
    }
  }

  if (!valid) {
  cout << "No Records\n";
  }
}

void School::outputStudentAttendance(string student_id, string course_id) {

  bool valid = false;

  for (size_t i = 0; i < courses.size(); i++) {
    if (courses.at(i).getID() == course_id) {
      courses.at(i).outputAttendance(student_id);
      valid = true;
      break;
    }
  }

  if (!valid) {
  cout << "No Records\n";
  }
}






