/** @file student_management.cpp
@author Lastname:Firstname:A00123456:cscxxxxx
@version Revision 1.0
@brief Illustrates a simple student management system.
@details This file contains a class to manage student records and perform operations like adding, removing, and searching for students.
@date Wednesday, January 29, 2025
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @class Student
 * @brief Represents a student with basic information.
 */
class Student {
private:
    string name;
    int id;
    double gpa;

public:
    /**
     * @brief Constructs a Student object.
     * @param name The student's name.
     * @param id The student's ID.
     * @param gpa The student's GPA.
     */
    Student(string name, int id, double gpa) : name(name), id(id), gpa(gpa) {}

    /**
     * @brief Gets the student's name.
     * @return The student's name.
     */
    string getName() const { return name; }

    /**
     * @brief Gets the student's ID.
     * @return The student's ID.
     */
    int getId() const { return id; }

    /**
     * @brief Gets the student's GPA.
     * @return The student's GPA.
     */
    double getGPA() const { return gpa; }

    /**
     * @brief Sets the student's GPA.
     * @param gpa The new GPA.
     */
    void setGPA(double gpa) { this->gpa = gpa; }
};

/**
 * @class StudentManager
 * @brief Manages a collection of students.
 */
class StudentManager {
private:
    vector<Student> students;

public:
    /**
     * @brief Adds a new student to the collection.
     * @param student The student to add.
     */
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    /**
     * @brief Removes a student by ID.
     * @param id The ID of the student to remove.
     * @return True if the student was found and removed, false otherwise.
     */
    bool removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Searches for a student by ID.
     * @param id The ID of the student to search for.
     * @return A pointer to the student if found, nullptr otherwise.
     */
    Student* findStudent(int id) {
        for (auto& student : students) {
            if (student.getId() == id) {
                return &student;
            }
        }
        return nullptr;
    }

    /**
     * @brief Displays all students.
     */
    void displayStudents() const {
        for (const auto& student : students) {
            cout << "Name: " << student.getName() << ", ID: " << student.getId()
                 << ", GPA: " << student.getGPA() << endl;
        }
    }
};

int main() {
    StudentManager manager;
    manager.addStudent(Student("Alice", 1, 3.5));
    manager.addStudent(Student("Bob", 2, 3.7));
    manager.addStudent(Student("Charlie", 3, 3.9));

    cout << "All students:" << endl;
    manager.displayStudents();

    cout << "\nSearching for student with ID 2:" << endl;
    Student* student = manager.findStudent(2);
    if (student) {
        cout << "Name: " << student->getName() << ", GPA: " << student->getGPA() << endl;
    } else {
        cout << "Student not found." << endl;
    }

    cout << "\nRemoving student with ID 2:" << endl;
    if (manager.removeStudent(2)) {
        cout << "Student removed." << endl;
    } else {
        cout << "Student not found." << endl;
    }

    cout << "\nAll students after removal:" << endl;
    manager.displayStudents();

    return 0;
}