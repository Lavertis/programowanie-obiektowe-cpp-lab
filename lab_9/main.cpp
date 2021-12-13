#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void task_1();

int main() {
    task_1();
}

void task_1() {
    string path = "../lab_9/kod.txt";
    ifstream file;
    file.exceptions(std::ifstream::failbit);

    try {
        file.open(path);
        string str;
        getline(file, str, '\0');
        long pos = 0;
        while ((pos = (long) str.find("//", pos)) != std::string::npos) {
            string::iterator newLine = std::find(str.begin() + pos, str.end(), '\n');
            str.erase(str.begin() + pos, newLine);
        }
        cout << str;
        file.close();
    } catch (std::ifstream::failure &e) {
        std::cerr << "The file could not be opened" << endl;
        std::cerr << e.what() << endl;
    }

    cout << endl << endl;

    try {
        file.open(path);
        stringstream ss;
        string contents;
        while (file.peek() != -1) {
            char tmp = (char) file.get();
            if (tmp == '/' && file.peek() == '/') {
                while (file.peek() != '\n')
                    file.ignore();
                continue;
            }
            ss << tmp;
        }
        contents = ss.str();
        cout << contents;
        file.close();
    } catch (std::fstream::failure &e) {
        std::cerr << "The file could not be opened" << endl;
        std::cerr << e.what() << endl;
    }
}