/*	simple_SQL.cpp	*/

#include <iostream>
#include <string>

#include <fstream>
#include <sstream>

class Person {
private:
    static inline std::size_t s_id {};
    std::size_t id;
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {
        id = ++s_id;
    }
    
	std::size_t getId() const {
        return id;
    }
    
	std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

void create(const Person& person) {
    std::ofstream outputFile("output.txt", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << person.getId() << "  | " << person.getName() << "        | " << person.getAge() << '\n';
        outputFile.close();
        std::cout << "Person added to 'output.txt' file.\n";
    } else {
        std::cerr << "Unable to open the file for writing.\n";
    }
}


void change(std::size_t searchId, const std::string& newName, int newAge) {
    std::ifstream inputFile("output.txt");
    std::ofstream tempFile("temp.txt");
    if (inputFile.is_open() && tempFile.is_open()) {
        std::string line;
        while (getline(inputFile, line)) {
            if (!line.empty()) {
                std::stringstream ss(line);
                std::size_t id;
                ss >> id;
                if (id == searchId) {
                    tempFile << searchId << "  | " << newName << "        | " << newAge << '\n';
                } else {
                    tempFile << line << '\n';
                }
            }
        }
        inputFile.close();
        tempFile.close();
        remove("output.txt");
        rename("temp.txt", "output.txt");
        std::cout << "Person with ID " << searchId << " updated.\n";
    } else {
        std::cerr << "Error: Unable to open files for reading or writing.\n";
    }
}

void deletePerson(std::size_t searchId) {
    std::ifstream inputFile("output.txt");
    std::ofstream tempFile("temp.txt");
    if (inputFile.is_open() && tempFile.is_open()) {
        std::string line;
		bool found {false};
        while (getline(inputFile, line)) {
            if (!line.empty()) {
                std::stringstream ss(line);
                std::size_t id;
                ss >> id;
                if (id != searchId) {
                    tempFile << line << '\n';
                } else {
                    found = true;
                }
            }
        }
        inputFile.close();
        tempFile.close();
        if (found) {
            remove("output.txt");
            rename("temp.txt", "output.txt");
            std::cout << "Person with ID " << searchId << " deleted.\n";
        } else {
            std::cout << "Person with ID " << searchId << " not found.\n";
            remove("temp.txt");
        }
    } else {
        std::cerr << "Error: Unable to open files for reading or writing.\n";
    }
}


int main() {
    create(Person("John Doe", 20));
    create(Person("Jane Smith", 22));
    create(Person("Michael Johnson", 19));

	change(5, "Alice", 25);
	deletePerson(1);

    return 0;
}

