#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    string surname;
    int age;
    string group;
};

void writeToFile(const string& filename, const Student& student) {
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << student.name << ',' << student.surname << ',' << student.age << ',' << student.group << endl;
        outFile.close();
        cout << "Data written to file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

void readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            Student student;
            size_t pos = line.find(',');
            student.name = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            student.surname = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            student.age = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            student.group = line;
            cout << "Name: " << student.name << "\nSurname: " << student.surname
                 << "\nAge: " << student.age << "\nGroup: " << student.group << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    string filename = "students.txt";
    Student student;
    student.name = "John";
    student.surname = "Doe";
    student.age = 20;
    student.group = "CS101";
    writeToFile(filename, student);

    student.name = "Jane";
    student.surname = "Smith";
    student.age = 22;
    student.group = "CS102";
    writeToFile(filename, student);

    readFromFile(filename);
    return 0;
}
