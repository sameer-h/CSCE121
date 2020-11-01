#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

#include "grade_calculator.h"

////////////////////////////////////////////////////////////////////////////////
// TODO(student): implement these methods

double GradeCalculator::exam_average() const {
    // TODO(student)
	double grade = 0;
	int countGrades = 0;
	double average;
	
	
	for (size_t i = 0; i < exam_grades.size(); ++i) {
		grade += exam_grades.at(i);
		countGrades++;
	}
	

	grade += final_exam;	
	countGrades++;
	double examAvg = grade / countGrades;
	

	if (final_exam > examAvg) {
		return final_exam;
	}
	

	average = grade / countGrades;	
	return average;
} 

double GradeCalculator::zybook_average() const {
    // TODO(student)	
	double grade = 0;
	int countGrades = 0;
	double average;
	

	for (size_t i = 0; i < zybook_participation_grades.size(); ++i) {
		grade += zybook_participation_grades.at(i);
		countGrades++;
	}


	for (size_t i = 0; i < zybook_challenge_grades.size(); ++i) {
		grade += zybook_challenge_grades.at(i);
		countGrades++;
	}
	
	double zybookAvg = grade / countGrades;
	if (zybookAvg >= 85) {
		return 100;
	} 
	

	average = zybookAvg + 15;
	return average;
}

double GradeCalculator::hw_average() const {
    // TODO(student)
	double grade = 0; 
	int countGrades = 0;
	double average;
	

	for (size_t i = 0; i < hw_grades.size(); ++i) {
		if (hw_redemption_grades.size() > i) {

			if (hw_redemption_grades.at(i) > hw_grades.at(i)) {
				grade += (hw_redemption_grades.at(i) - hw_grades.at(i)) / 2;
			}
		}
		grade += hw_grades.at(i);
		countGrades++;
	}
	

	average = grade / countGrades;
    return average;
}

double GradeCalculator::lw_average() const {
    // TODO(student)
	double grade = 0;
	int countGrades = 0;
	double average;
	
	for (size_t i = 0; i < lw_grades.size(); ++i) {
		grade += lw_grades.at(i);
		countGrades++;
	}
	

	average = 100 * (grade / countGrades);
    return average;
}


double GradeCalculator::final_grade_numeric() const {
    // TODO(student)
	double grade = exam_average() * (0.5) +
					zybook_average() * (0.07) +
					hw_average() * (0.35) +
					lw_average() * (0.08);
    return grade;
}


char GradeCalculator::final_grade_letter() const {
    // TODO(student)

	double course_avg = final_grade_numeric();
	

	if (!has_syllabus_ack || course_avg < 60) {  // no syllabus acknowledgement
		return 'F';
	} else if (exam_average() < 60 || course_avg < 70) {
		return 'D';
	} else if (course_avg < 80) {
		return 'C';
	} else if (course_avg < 90) {
		return 'B';
	} else {
		return 'A';
	}
}

////////////////////////////////////////////////////////////////////////////////

void GradeCalculator::read_final_exam(std::ifstream& fin) {
    has_final_exam = true;
    fin >> final_exam;
    if (fin.fail()) {
        throw std::runtime_error("failed to read final exam grade");
    }
}

void GradeCalculator::read_exam_hw_redemption_zybook(std::ifstream& fin, const std::string& category) {
    unsigned number;
    fin >> number;
    if (fin.fail()) {
        throw std::runtime_error("failed to read " + category + " number");
    }

    std::vector<double>* vec;
    if (category == "exam") {
        vec = &exam_grades;
    } else if (category == "hw") {
        vec = &hw_grades;
    } else if (category == "hw-redemption") {
        vec = &hw_redemption_grades;
    } else if (category == "zybook") {
        char type;
        fin >> type;
        if (fin.fail()) {
            // HOW TO REACH THIS?
            throw std::runtime_error("failed to read " + category + " type");
        }
        switch (type) {
            case 'p': vec = &zybook_participation_grades; break;
            case 'c': vec = &zybook_challenge_grades; break;
            default: throw std::runtime_error("unrecognized zybook assignment type: " + type);
        }
    } else {
        throw std::runtime_error("unrecognized category: " + category);
    }
    
    double grade;
    fin >> grade;
    if (fin.fail()) {
        throw std::runtime_error("failed to read "+category+" grade");
    }

    while (number > vec->size()) {
        vec->push_back(0);
    }

    vec->at(number-1) = grade;
}

void GradeCalculator::read_lw(std::ifstream& fin) {
    unsigned number;
    fin >> number;
    if (fin.fail()) {
        throw std::runtime_error("failed to read lw number");
    }

    std::string str;
    fin >> str;
    if (fin.fail()) {
        // HOW TO REACH THIS?
        throw std::runtime_error("failed to read lw grade");
    }

    while (number > lw_grades.size()) {
        lw_grades.push_back(false);
    }

    if (str == "0" || str == "false") {
        lw_grades.at(number-1) = false;
    } else if (str == "1" || str == "true") {
        lw_grades.at(number-1) = true;
    } else {
        throw std::runtime_error("invalid lw grade value: " + str);
    }
}

void GradeCalculator::read_syllabus_ack(std::ifstream& fin) {
    std::string str;
    fin >> str;
    if (fin.fail()) {
        // HOW TO REACH THIS?
        throw std::runtime_error("failed to read syllabus-ack type");
    }
    if (str == "0" || str == "false") {
        has_syllabus_ack = false;
    } else if (str == "1" || str == "true") {
        has_syllabus_ack = true;
    } else {
        throw std::runtime_error("invalid syllabus-ack grade value: " + str);
    }
}

void GradeCalculator::load_grades(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        throw std::runtime_error("could not open file");
    }
    while (!fin.eof()) {
        std::string category;
        fin >> category;
        if (fin.fail()) {
            if (fin.eof()) {
                continue;
            } 
            // HOW TO REACH THIS?
            throw std::runtime_error("failed to read category");
        }
        if (category == "final-exam") {
            read_final_exam(fin);
        } else if (category == "exam" || category == "hw" || category == "hw-redemption" || category == "zybook") {
            read_exam_hw_redemption_zybook(fin, category);
        } else if (category == "lw") {
            read_lw(fin);
        } else if (category == "syllabus-ack") {
            read_syllabus_ack(fin);
        } else {
            throw std::runtime_error("invalid category: " + category);
        }
    }
}