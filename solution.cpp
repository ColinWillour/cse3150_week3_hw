
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes


// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
        if (size >= capacity) {
                throw "List full";
        }

        int len = std::strlen(name);
        names[size] = new char[len + 1];
        std::strcpy(names[size], name);

        gpas[size] = gpa;
        size++;
}


// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa) {
        if (gpaPtr != nullptr) {
                *gpaPtr = newGpa;
        }
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa) {
        std::cout << name << " - GPA: " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size) {
        if (size == 0) {
                throw "No students";
        }
        double average = 0;
        double sum = 0;
        for (int i = 0; i < size; i++) {
                sum += gpas[i];
        }
        average = sum / size;
        return average;
}


int main(int argc, char* argv[]) {
        if (argc < 2) {
                std::cout << "Usage: ./program <capacity>" << std::endl;
                return 1;
        }

        // VLAs, not covered
        //char* names[capacity];
        //double gpas[capacity];
        int capacity = std::stoi(argv[1]);

        char** names = new char*[capacity];
        double* gpas = new double[capacity];
        int size = 0;

        int choice;
        do {
                std::cout << "Menu:\n";
                std::cout << "1. Add student\n";
                std::cout << "2. Update GPA\n";
                std::cout << "3. Print all students\n";
                std::cout << "4. Compute average GPA\n";
                std::cout << "5. Quit\n";
                std::cout << "Enter choice: ";
                std::cin >> choice;

                switch (choice) {
                        case 1: {
                                // TODO: implement menu logic
                                char name[25];
                                double gpa;
                                std::cout << "Enter name: ";
                                std::cin >> name;
                                std::cout << "Enter GPA: ";
                                std::cin >> gpa;

                                try {
                                        addStudent(name, gpa, names, gpas, size, capacity);
                                }
                                catch (const char* err) {
                                        std::cout << err << std::endl;
                                }
                                break;
                        }

                        case 2: {
                                // TODO: implement menu logic
                                int idx;
                                double newGpa;
                                std::cout << "Enter student index: ";
                                std::cin >> idx;
                                if (idx < 0 || idx >= size) {
                                        std::cout << "Invalid index" << std::endl;
                                }
                                else {
                                        std::cout << "Enter new GPA: ";
                                        std::cin >> newGpa;
                                        updateGPA(&gpas[idx], newGpa);
                                }
                                break;
                        }

                        case 3: {
                                // TODO: implement menu logic
                                for (int i = 0; i < size; i++) {
                                        printStudent(names[i], gpas[i]);
                                }
                                break;
                        }

                        case 4: {
                                // TODO: implement menu logic
                                try {
                                        double average = averageGPA(gpas, size);
                                        std::cout << "Average GPA: " << average << " (rounded: " << static_cast<int>(average) << ")" << std::endl;
                                }
                                catch (const char* err) {
                                        std::cout << err << std::endl;
                                }
                                break;
                        }

                        case 5: {
                                std::cout << "Goodbye!" << std::endl;
                                break;
                        }

                        default: {
                                std::cout << "Invalid choice" << std::endl;
                        }
                }
        } while (choice != 5);

        // TODO: free memory
        for (int i = 0 ; i < size; i++) {
                delete[] names[i];
        }
        delete[] names;
        delete[] gpas;
        return 0;
}
