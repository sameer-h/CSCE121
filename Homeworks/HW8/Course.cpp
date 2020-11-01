#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;

Course::Course(string id, string title, Date startTime, Date endTime) : 
  id(id), title(title), startTime(startTime), endTime(endTime) {

  this->id = id;
  this->title = title;
  this->startTime = startTime;
  this->endTime = endTime;

}

string Course::getID() {
  return id;
}

string Course::getTitle() {
  return title;
}

Date Course::getStartTime() {
  return startTime;
}

Date Course::getEndTime() {
  return endTime;
}

void Course::addAttendanceRecord(AttendanceRecord ar) {
  attendanceRecords.push_back(ar);
}



// no student id
void Course::outputAttendance() {
  
	bool valid = false;

  if (attendanceRecords.size() == 0) {
    cout << "No Records\n";
  } else {
    for (unsigned int i = 0; i < attendanceRecords.size(); ++i) {
      cout << attendanceRecords.at(i).getDate().getDateTime() << ",";
      cout << attendanceRecords.at(i).getCourseID() << ",";
      cout << attendanceRecords.at(i).getStudentID() << "\n";
      valid = true;
    }
    if (!valid) {
  		cout << "No Records\n";
  	}
  }
}

void Course::outputAttendance(string student_id) {
  
	bool valid = false;

  if (attendanceRecords.size() == 0) {
    cout << "No Records\n";
  } else {
    for (unsigned int i = 0; i < attendanceRecords.size(); ++i) {
      if (attendanceRecords.at(i).getStudentID() == student_id) {
        cout << attendanceRecords.at(i).getDate().getDateTime() << ",";
        cout << attendanceRecords.at(i).getCourseID() << ",";
        cout << attendanceRecords.at(i).getStudentID() << "\n";
        valid = true;
      }
    }
    if (!valid) {
  		cout << "No Records\n";
  	}
  }
}


