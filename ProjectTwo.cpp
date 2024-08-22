#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

// load data from file into the data structure
void loadDataStructure(vector<string>& courses, const string & fileName) {
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        string course;
        while (getline(inputFile, course)) {
            courses.push_back(course);
        }
        inputFile.close();
        cout << "Data loaded successfully.\n";
    } else {
        cout << "Error opening file. Please check the file name and try again.\n";
    }
}

// print the course list in alphanumeric order
void printCourseList(const vector<string>& courses) {
    vector<string> sortedCourses = courses;
    sort(sortedCourses.begin(), sortedCourses.end());
    
    cout << "Alphanumeric Course List:\n";
    for (const string& course : sortedCourses) {
        cout << course << endl;
    }
}

// print information about a specific course
void printCourseInfo(const vector<string>& courses, const string& courseCode) {
    cout << "Course Information for " << courseCode << ":\n";
    auto it = find_if(courses.begin(), courses.end(),
                      [courseCode](const string& course) {
                          return course.find(courseCode) != string::npos;
                      });

    if (it != courses.end()) {
        cout << *it << endl;
    } else {
        cout << "Course not found.\n";
    }
}

int main() {
    cout << "Welcome to the course Planner\n";

    vector<string> courses;

    string fileName;
    cout << "Enter the file name containing course data: ";
    getline(cin, fileName);

    while (true) {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. Load Data Structure\n";
        cout << "2. Print Course List\n";
        cout << "3. Print Course Information\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); 

        switch (choice) {
            case 1:
                loadDataStructure(courses, fileName);
                break;
            case 2:
                printCourseList(courses);
                break;
            case 3:
                {
                    string courseCode;
                    cout << "Enter the course code: ";
                    cin >> courseCode;
                    transform(courseCode.begin(), courseCode.end(), courseCode.begin(), ::toupper);
                    printCourseInfo(courses, courseCode);
                }
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
