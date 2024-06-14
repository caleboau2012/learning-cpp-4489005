// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int getGradeValue(char g){
    int grade;
    switch(g){
        case 'A':
            grade = 4;
            break;
        case 'B':
            grade = 3;
            break;
        case 'C':
            grade = 2;
            break;
        default:
            grade = 0;
    }
    return grade;
}

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    // Write your code here

    std::cout << "The ID is " << id << std::endl;
    std::cout << "The size is " << students.size() << std::endl;

    // Get the student with the ID.
    Student *student = nullptr;
    for (int i = 0; i < students.size(); i++){
        if (students[i].get_id() == id){
            std::cout << "students[i].get_id() = " << students[i].get_id() << ", id = " << id << std::endl;
            student = &students[i];
            break;
        }
    }

    // for (auto s : students) {
    //     if (s.get_id() == id){
    //         std::cout << "s.get_id() = " << s.get_id() << ", id = " << id << std::endl;
    //         std::cout << "s.get_name() = " << s.get_name() << std::endl;
    //         student = &s;
    //         break;
    //     }
    // }

    if (student == nullptr){
        std::cout << "Student 404 😀" << std::endl;
        return 1;
    }

    std::cout << "Student is " << student->get_name() << std::endl;

    // Calculate GPA for the student
    float totalPoints = 0;
    int totalCredits = 0;
    for (auto g : grades){
        if (g.get_student_id() == id){
            totalPoints += (getGradeValue(g.get_grade()) * 
                courses[g.get_course_id() - 1].get_credits());
            totalCredits += courses[g.get_course_id() - 1].get_credits();
        }
    }

    GPA = totalPoints / totalCredits;

    std::string student_str;
    student_str = student->get_name(); // Change this to the selected student's name

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
