#include <iostream>
#include <fstream>
#include <climits>
#include "dictionary.hpp"
int main() {

    ifstream infile;
    infile.open("../dictionary.txt");
    dictionary d(infile);
    infile.close();
    ofstream outfile;
    string word;


    int choice;
    bool menuOn = true;
    while (menuOn){
        cout << " 1 - Print map.\n";
        cout << " 2 - Find word-definition.\n";
        cout << " 3 - Enter new word and definition.\n";
        cout << " 4 - Exit.\n";
        cout << " Enter your choice and press return: ";
        cin >> choice;

        switch (choice) {
            case 1:
                d.printMap();
                break;
            case 2:
                cout << "Enter a word: ";
                cin >> word;
                d.findWord(word);
                break;
            case 3:
                outfile.open("../dictionary.txt", ios_base::app);
                d.insertWordAndDef(outfile);
                outfile.close();
                break;
            case 4:
                cout << "End of Program.\n";
                menuOn = false;
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                cin.clear();
                cin.ignore(INT_MAX);
                break;
        }

    }
    return 0;
}