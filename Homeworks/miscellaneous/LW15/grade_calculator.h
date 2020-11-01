#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <vector>
#include <string>
#include <fstream>

class GradeCalculator {
    bool has_final_exam;
    double final_exam;
    bool has_syllabus_ack;
    std::vector<double> exam_grades;
    std::vector<double> zybook_participation_grades;
    std::vector<double> zybook_challenge_grades;
    std::vector<double> hw_grades;
    std::vector<double> hw_redemption_grades;
    std::vector<bool> lw_grades;

    void read_final_exam(std::ifstream& fin);
    void read_exam_hw_redemption_zybook(std::ifstream& fin, const std::string& category);
    void read_lw(std::ifstream& fin);
    void read_syllabus_ack(std::ifstream& fin);

 public:
    GradeCalculator() : has_final_exam(false), final_exam(0), has_syllabus_ack(false) {} 
    GradeCalculator(std::string filename) : GradeCalculator() { load_grades(filename); }

    double get_final_exam() const { return final_exam; }
    bool get_has_final_exam() const { return has_final_exam; }
    bool get_has_syllabus_ack() const { return has_syllabus_ack; }

    void load_grades(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // TODO(student): implement these methods

    double exam_average() const; 
    double zybook_average() const;
    double hw_average() const;
    double lw_average() const;
    // does not apply modifiers
    double final_grade_numeric() const;
    // includes application of modifiers
    char final_grade_letter() const;
    
    ////////////////////////////////////////////////////////////////////////////////

    // FOR TESTING ONLY
    const std::vector<double>& get_exam_grades() const { return exam_grades; }
    // FOR TESTING ONLY
    const std::vector<double>& get_zybook_participation_grades() const  { return zybook_participation_grades; }
    // FOR TESTING ONLY
    const std::vector<double>& get_zybook_challenge_grades() const  { return zybook_challenge_grades; }
    // FOR TESTING ONLY
    const std::vector<double>& get_hw_grades() const  { return hw_grades; }
    // FOR TESTING ONLY
    const std::vector<double>& get_hw_redemption_grades() const { return hw_redemption_grades; }
    // FOR TESTING ONLY
    const std::vector<bool>& get_lw_grades() const  { return lw_grades; }
};

#endif  // GRADE_CALCULATOR_H