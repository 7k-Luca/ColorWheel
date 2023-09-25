/*
Luca Marinelli
02/19/2023
colorWheel.cpp

IPO Chart
  Input:
   - Takes input from the user in the form of a menu choice for displaying colors.
  Processing:
    - The program reads from a binary file containing color values and displays the selected colors based on teh user's input.
  Output:
    - The program outputs the selected colors to the console.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function Prototypes
void printMenu();
void printPrimaryColors(fstream& file);
void printSecondaryColors(fstream& file);
void printTertiaryColors(fstream& file);
void printColorWheel(fstream& file);

int main() {
    // Opens the file
    fstream colorWheel("wheel.dat", ios::in | ios::binary);
    //validate if the file has opened correctly
    if (colorWheel.fail()) {
        cout << "Failed to Open file!";
        return -1;
    }
    //runs the menu until the user chooses to exit
    bool exit = false;
    while (!exit) {
        printMenu();
        //operates the menu, validates user input
        int userInput = 0;
        cout << "Option: ";
        cin >> userInput;
        //validates and makes choices based on user's input
        switch (userInput) {
        case 1:
            printPrimaryColors(colorWheel);
            break;
        case 2:
            printSecondaryColors(colorWheel);
            break;
        case 3:
            printTertiaryColors(colorWheel);
            break;
        case 4:
            printColorWheel(colorWheel);
            break;
        case 5:
            exit = true;
            cout << "\n\n\nGood Bye...";
            break;
        default:
            // If they input a value other than 1-5
            cout << endl << "Error Invalid Input\n";
            exit = false;
            break;
        }
    }
    colorWheel.close(); // closes the file
    return 0;
}

// Function that displays the menu-based options. 
void printMenu() {
    cout << "Choose one of the following options:\n ";
    cout << "\t1. Primary Colors. \n\t2. Secondary Colors. \n\t3. Tertiary Colors. \n\t4. Color Wheel. \n\t5. Quit";
    cout << endl;
}

// Function that only prints the primary colors. 
void printPrimaryColors(fstream& file) {
    cout << "\n\nPrimary Colors\n";
    cout << "------------------------------------" << endl;
    char colors[16];
    for (int j = 0; j < 12; j += 4) {
        file.seekg((j * 16), ios::beg);
        for (int i = 0; i < 16; i++) {
            file.read((char*)&colors[i], sizeof(char));
        }
        colors[15] = '\0';
        cout << colors << "\t";
    }
    cout << endl << endl;
}

// Function that only prints the secondary colors.
void printSecondaryColors(fstream& file) {
    cout << "\n\nSecondary Colors\n";
    cout << "------------------------------------" << endl;
    char colors[16];
    for (int j = 2; j < 12; j += 4) {
        file.seekg((j * 16), ios::beg);
        for (int i = 0; i < 16; i++) {
            file.read((char*)&colors[i], sizeof(char));
        }
        colors[15] = '\0';
        cout << colors << "\t";
    }
    cout << endl << endl;
}

// Function that prints only the tertiary colors. 
void printTertiaryColors(fstream& file) {
    cout << "\n\nTertiary Colors\n";
    cout << "------------------------------------" << endl;
    char colors[16];
    for (int j = 1; j < 12; j += 2) {
        file.seekg((j * 16), ios::beg);
        for (int i = 0; i < 16; i++) {
            file.read((char*)&colors[i], sizeof(char));
        }
        colors[15] = '\0';
        cout << colors << "\t";
    }
    cout << endl << endl;
}

// Function that prints the full color wheel colors.
void printColorWheel(fstream& file) {
    char colors[16];
    cout << "\n\nColor Wheel\n";
    cout << "------------------------------------" << endl;
    for (int j = 0; j < 12; j++) {
        file.seekg((j * 16), ios::beg);
        for (int i = 0; i < 16; i++) {
            file.read((char*)&colors[i], sizeof(char));
        }
        colors[15] = '\0';
        cout << colors << "\t";
        if ((j + 1) % 3 == 0)
            cout << endl;
    }
    cout << endl;
}
