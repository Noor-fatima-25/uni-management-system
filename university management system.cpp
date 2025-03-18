#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Base class: Person
class Person {
protected:
    string name, id;
public:
    Person(string n, string i) : name(n), id(i) {}
    string getName() { return name; }
    string getID() { return id; }
};

// Student class
class Student : public Person {
private:
    vector<string> enrolledCourses;
    float feesPaid;
    float examScore;
public:
    Student(string n, string i) : Person(n, i), feesPaid(0), examScore(0) {}

    void enrollCourse(string course) {
        enrolledCourses.push_back(course);
        cout << name << " enrolled in " << course << " successfully.\n";
    }

    void payFees(float amount) {
        feesPaid += amount;
        cout << name << " has paid Rs. " << amount << ". Total Paid: Rs. " << feesPaid << endl;
    }

    void markExamScore(float score) {
        examScore = score;
        cout << name << " received " << score << " marks.\n";
    }

    void showDetails() {
        cout << "\n?? Student: " << name << " (ID: " << id << ")\n";
        cout << "Courses Enrolled: ";
        for (auto &course : enrolledCourses)
            cout << course << " ";
        cout << "\nFees Paid: Rs. " << feesPaid;
        cout << "\nExam Score: " << examScore << " marks\n";
    }
};

// Teacher class
class Teacher : public Person {
private:
    string subject;
public:
    Teacher(string n, string i, string s) : Person(n, i), subject(s) {}

    void showInfo() {
        cout << name << " (ID: " << id << ") teaches " << subject << endl;
    }
};

// University Management System
class UniversityManagementSystem {
private:
    vector<Student> students;
    vector<Teacher> teachers;
public:
    UniversityManagementSystem() {
        students.push_back(Student("Noor Fatima", "24BSSW104"));
        students.push_back(Student("Neha", "24BSSW105"));
        students.push_back(Student("Minha", "24BSSW106"));
        students.push_back(Student("Ibad Hussain", "24BSSW107"));

        teachers.push_back(Teacher("Azhar Khaskheli", "T01", "Programming Fundamentals"));
        teachers.push_back(Teacher("Dr. Adnan", "T02", "ICT"));
        teachers.push_back(Teacher("Engr. Hafsa", "T03", "Calculus"));
    }

    void registerStudent(string name, string id) {
        students.push_back(Student(name, id));
        cout << "? Student " << name << " registered successfully.\n";
    }

    void enrollStudentInCourse(string studentID, string course) {
        for (auto &s : students) {
            if (s.getID() == studentID) {
                s.enrollCourse(course);
                return;
            }
        }
        cout << "? Student ID not found.\n";
    }

    void markStudentExam(string studentID, float score) {
        for (auto &s : students) {
            if (s.getID() == studentID) {
                s.markExamScore(score);
                return;
            }
        }
        cout << "? Student ID not found.\n";
    }

    void processFeePayment(string studentID, float amount) {
        for (auto &s : students) {
            if (s.getID() == studentID) {
                s.payFees(amount);
                return;
            }
        }
        cout << "? Student ID not found.\n";
    }

    void showStudents() {
        cout << "\n?? Students List:\n";
        for (auto &s : students) {
            s.showDetails();
        }
    }

    void showTeachers() {
        cout << "\n????? Teachers List:\n";
        for (auto &t : teachers) {
            t.showInfo();
        }
    }
};

int main() {
    UniversityManagementSystem ums;
    int choice;
    string studentID, studentName, course;
    float amount, score;

    do {
        cout << "\n===========================";
        cout << "\n?? University Management System";
        cout << "\n1?? Register Student";
        cout << "\n2?? Enroll in Course";
        cout << "\n3?? Pay Fees";
        cout << "\n4?? Mark Exam Score";
        cout << "\n5?? View Students";
        cout << "\n6?? View Teachers";
        cout << "\n7?? Exit";
        cout << "\n===========================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, studentName);
                cout << "Enter Student ID: ";
                cin >> studentID;
                ums.registerStudent(studentName, studentID);
                break;

            case 2:
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, course);
                ums.enrollStudentInCourse(studentID, course);
                break;

            case 3:
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Fee Amount: ";
                cin >> amount;
                ums.processFeePayment(studentID, amount);
                break;

            case 4:
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Exam Score: ";
                cin >> score;
                ums.markStudentExam(studentID, score);
                break;

            case 5:
                ums.showStudents();
                break;

            case 6:
                ums.showTeachers();
                break;

            case 7:
                cout << "\n?? Goodbye! Have a great day!\n";
                break;

            default:
                cout << "\n? Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}