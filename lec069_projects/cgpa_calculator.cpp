#include <iostream>
#include <vector>

using namespace std;

struct Course {
    double grade;
    int creditHours;
};

double calculateCGPA(const vector<Course>& courses) {
    double totalGradePoints = 0.0;
    int totalCreditHours = 0;
    
    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.creditHours;
        totalCreditHours += course.creditHours;
    }

    if (totalCreditHours == 0) {
        return 0.0; // Prevent division by zero
    }

    return totalGradePoints / totalCreditHours;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter grade and credit hours for course " << (i + 1) << ": ";
        cin >> courses[i].grade >> courses[i].creditHours;
    }

    double cgpa = calculateCGPA(courses);
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}
