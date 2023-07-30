# simple_SQL

This C++ program (`simple_SQL.cpp`) demonstrates basic SQL-like operations using file I/O to manage a table of "persons." It provides functionalities to create, update, and delete records in a text-based table stored in a file named "output.txt."

## Class Definition: `Person`

The program defines a class `Person` to represent individual records in the "persons" table. Each person has an ID (auto-incremented), a name, and an age. The `Person` class has getter functions to access the private data members.

## Function Details

### `void create(const Person& person)`

This function inserts a new person into the "output.txt" file. It takes a `Person` object as input and appends the person's information to the end of the file. The function opens the file in "append" mode and writes the person's ID, name, and age in the following format: `<ID>  | <Name>        | <Age>`

### `void change(std::size_t searchId, const std::string& newName, int newAge)`

This function searches for a person with the specified `searchId` in the "output.txt" file and updates their name and age with the provided values `newName` and `newAge`, respectively. The function creates a temporary file named "temp.txt" to store the modified content. It reads each line from the original file, checks if the ID matches the `searchId`, and writes the updated information into the temporary file. Finally, the original "output.txt" file is replaced with the content from "temp.txt," effectively applying the changes.

### `void deletePerson(std::size_t searchId)`

This function searches for a person with the specified `searchId` in the "output.txt" file and deletes their record if found. It works similarly to the `change()` function, creating a temporary file to store the modified content. The function reads each line from the original file, skips the line with the specified ID, and writes the rest into the temporary file. If the person with the given `searchId` is found, the original "output.txt" file is replaced with the content from "temp.txt," effectively deleting the record.

## Usage in `main()`

The program demonstrates the functionalities by calling the `create()` function to insert three persons into the "output.txt" file. Then, it uses the `change()` function to update the person with ID 5 to have the name "Alice" and age 25. After that, it calls the `deletePerson()` function to delete the person with ID 1 from the file.

Please ensure that the program has read and write permissions for the directory where the file "output.txt" is located. Before running the program, ensure that the file "output.txt" does not contain important data as it may be modified during the execution of the program.

To execute the program, compile it using a C++ compiler, and run the resulting executable. The program will perform the specified SQL-like operations and provide appropriate feedback on the console.
