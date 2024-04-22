#include <iostream>
#include <fstream>

using namespace std;

// Базовый класс
class FileProcessor {
public:
    virtual void Display(const char* path) {
        ifstream file(path);
        if (file.is_open()) {
            string content((istreambuf_iterator<char>(file)),
                istreambuf_iterator<char>());
            cout << "File content: " << content << endl;
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
};

// Первый класс потомок
class ASCIIFileProcessor : public FileProcessor {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                cout << static_cast<int>(ch) << " ";
            }
            cout << endl;
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
};

// Второй класс потомок
class BinaryFileProcessor : public FileProcessor {
public:
    void Display(const char* path) override {
        ifstream file(path, ios::binary);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                for (int i = 7; i >= 0; --i) {
                    cout << ((ch >> i) & 1);
                }
                cout << " ";
            }
            cout << endl;
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
};

int main() {
    const char* filePath = "test.txt";

    FileProcessor fileProcessor;
    fileProcessor.Display(filePath);

    ASCIIFileProcessor asciiFileProcessor;
    asciiFileProcessor.Display(filePath);

    BinaryFileProcessor binaryFileProcessor;
    binaryFileProcessor.Display(filePath);

    return 0;
}