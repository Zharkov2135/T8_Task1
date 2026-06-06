#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

class Student {
public:
    string name;
    string group;
    int marks[5];

    double average() const {
        int sum = 0;
        for (int i = 0; i < 5; i++) sum += marks[i];
        return sum / 5.0;
    }

    bool only45() const {
        for (int i = 0; i < 5; i++) {
            if (marks[i] != 4 && marks[i] != 5) return false;
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Number of students: ";
    cin >> n;

    // очистити буфер після cin >> n, щоб getline працював коректно
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << "\n";

        cout << "Name (surname + initials): ";
        getline(cin, students[i].name);

        cout << "Group: ";
        getline(cin, students[i].group);

        cout << "Enter 5 marks (2..5): ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].marks[j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            if (a.average() != b.average()) return a.average() < b.average();
            return a.name < b.name;
        });

    cout << "\nSorted by average:\n";
    for (const auto& s : students) {
        cout << s.name << " (group " << s.group << ") avg=" << s.average() << "\n";
    }

    cout << "\nStudents with only 4 and 5:\n";
    bool any = false;
    for (const auto& s : students) {
        if (s.only45()) {
            cout << s.name << ", group " << s.group << "\n";
            any = true;
        }
    }
    if (!any) cout << "None.\n";

    return 0;
}
