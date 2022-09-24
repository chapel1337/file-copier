#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // for running batch file
#include <windows.h> // for Sleep();

using std::cout; using std::string; using std::cin;

// written by chapel1337
// made on 9/24/2022
// 
// somewhat messy code
// didn't add any invalid file handlers, so if the user inputs a non-existing file, it'll just output the batch file error

std::string read()
{
    // credit to ROMAHKAO
    std::string s{};
    std::getline(std::cin >> std::ws, s);
    return s;
}

std::ofstream output{};

string file{};

void menu();

void clear()
{
    system("cls");
}

void done()
{
    cout << "\ndone\n";
    Sleep(1000);

    clear();
    menu();
}

void invalidInput()
{
    cout << "invalid input \n";
    Sleep(1000);

    clear();
    menu();
}

void runFile()
{
    std::system("copy.bat");
    std::system("del copy.bat");
}

void copyFile()
{
    string fileName{ file.substr(0, file.find('.')) };
    string fileExtension{ file.substr(file.find('.') + 1, file.length()) };

    string copy{ "copy " + file + ' ' + fileName + "_copy" + '.' + fileExtension };

    clear();

    output.open("copy.bat", std::ios_base::app | std::ios_base::out);

    if (!output)
    {
        cout << "file was unable to be opened\n";
        std::system("del copy.bat");
    }

    // just realized i probably could've just done std::system(), but it's too late and this was great practice
    output << copy;
    output.close();

    runFile();

    done();
}

/*
void copyTimes() // didn't know what to call function
{
    if (!times || times == 0)
    {
        invalidInput();
    }

    for (int i{ 0 }; i <= times; i++)
    {
        copyFile();
        clear();
    }

    cout << "\ndone\n";
    system("pause");
}
*/

void menu()
{
    cout << "enter file name and extension: \n";
    file = read();

    /*
    cout << "\n";
    
    cout << "how many times would you like to copy this file?\n";
    cin >> times;
    */
        
    copyFile();
}

int main()
{
    menu();
}