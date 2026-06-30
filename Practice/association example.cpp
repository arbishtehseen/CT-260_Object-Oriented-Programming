#include<iostream>
#include<string>
using namespace std;



class Student {
    char* name;
    int rollNo;
public:
    Student(const char* n, int r) {
        int size = strlen(n);
        name = new char[size + 1];
        memcpy(name, n, size + 1);
        rollNo = r;
    }
    const char* getName() const { return name; }
    ~Student() { delete[] name; }
};

class Teacher {
    char* name;
public:
    Teacher(const char* n) {
        int size = strlen(n);
        name = new char[size + 1];
        memcpy(name, n, size + 1);
    }

    void teach(Student& s) {
        cout << name << " is teaching " << s.getName() << endl;
    }

    void grade(Student& s, int marks) {
        cout << name << " gave " << marks
             << " marks to " << s.getName() << endl;
    }

    ~Teacher() { delete[] name; }
};

int main() {
    Student s1("Sara", 1);
    Student s2("Ahmed", 2);
    Teacher t("Sir Khalid");

    t.teach(s1);
    t.teach(s2);
    t.grade(s1, 90);
    t.grade(s2, 85);

    // Teacher gone — students still exist ✅
    // Students gone — teacher still exists ✅
}