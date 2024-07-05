#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
  string name;
  int credits;
  char grade;
};

float calculateGradePoints(char grade) {
  switch (grade) {
    case 'A':
      return 4.0;
    case 'B':
      return 3.0;
    case 'C':
      return 2.0;
    case 'D':
      return 1.0;
    case 'F':
      return 0.0;
    default:
      return 0.0; // Handle invalid grades
  }
}

int main() {
  int numCourses;
  float totalCredits = 0.0;
  float totalGradePoints = 0.0;
  vector<Course> courses;

  cout << "Enter the number of courses taken: ";
  cin >> numCourses;

  // Input course details
  for (int i = 0; i < numCourses; i++) {
    Course course;
    cout << "Enter course name for course " << i + 1 << ": ";
    cin.ignore(); // Clear input buffer
    getline(cin, course.name);
    cout << "Enter credits for course " << i + 1 << ": ";
    cin >> course.credits;
    cout << "Enter grade (A, B, C, D, or F) for course " << i + 1 << ": ";
    cin >> course.grade;

    courses.push_back(course);
    totalCredits += course.credits;
    totalGradePoints += course.credits * calculateGradePoints(course.grade);
  }

  // Calculate and display results
  float cgpa = totalGradePoints / totalCredits;

  cout << "\nCourse | Credits | Grade | Grade Points\n";
  cout << "-------|---------|--------|--------------\n";
  for (Course course : courses) {
    cout << left << setw(15) << course.name << " | "
         << right << setw(7) << course.credits << " | "
         << right << setw(7) << course.grade << " | "
         << right << setw(13) << fixed << setprecision(2) << course.credits * calculateGradePoints(course.grade) << endl;
  }
  cout << "-------|---------|--------|--------------\n";
  cout << left << setw(30) << "Total" << " | "
       << right << setw(7) << totalCredits << " | " << endl;
  cout << left << setw(30) << "CGPA" << " | "
       << right << setw(13) << fixed << setprecision(2) << cgpa << endl;

  return 0;
}
