#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to write data (overwrites file)
void writeToFile(const string& filename) {
    ofstream file(filename); // opens in trunc mode by default
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    string data;
    cout << "Enter text to write to the file (end input with a single line 'END'):\n";
    while (true) {
        getline(cin, data);
        if (data == "END") break;
        file << data << endl;
    }

    file.close();
    cout << "Data written successfully.\n";
}

// Function to append data to a file
void appendToFile(const string& filename) {
    ofstream file(filename, ios::app); // append mode
    if (!file) {
        cerr << "Error opening file for appending!" << endl;
        return;
    }

    string data;
    cout << "Enter text to append to the file (end input with a single line 'END'):\n";
    while (true) {
        getline(cin, data);
        if (data == "END") break;
        file << data << endl;
    }

    file.close();
    cout << "Data appended successfully.\n";
}

// Function to read and display file contents
void readFromFile(const string& filename) {
    ifstream file(filename); // input mode
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    cout << "\nContents of the file:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {
    string filename = "data.txt";
    int choice;

    do {
        cout << "\n--- File Handling Menu ---\n";
        cout << "1. Write to file (overwrite)\n";
        cout << "2. Append to file\n";
        cout << "3. Read from file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore(); // clear newline character from buffer

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
