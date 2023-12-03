#include <iostream>
#include "draw.h"
#include <string>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

string word, guessed = "";
char choice;
int remainingLifes = 6;
vector<char> lettersUsed;

void selectWord() {
    vector<string> words;
    string word;
    ifstream file("options.txt");
    while (getline(file, word)) {
        words.push_back(word);
    }
    srand(time(NULL));
    int random = (rand() % words.size());
    word = words.at(random);
}

void showUsed() {
    if (find(lettersUsed.begin(), lettersUsed.end(), choice) == lettersUsed.end()) {
        lettersUsed.push_back(choice);
    }
    cout << "Letters:";
    for (int i = 0; i < lettersUsed.size(); i++) {
        cout << lettersUsed[i] << " ";
    }
    cout << endl;
}

void display() {
    for (int i = 0; i < word.length(); i++) {
        guessed = guessed + "_";
    }
    for (int i = 0; i < guessed.size(); i++) {
        cout << guessed[i] << " ";
    }
    cout << endl;
}

void chooseWord() {
    draw(remainingLifes);
    bool found = false;
    cout << endl;
    showUsed();
    cout << "Next guess => ";
    cin >> choice;
    system("cls");
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == choice) {
            guessed[i] = choice;
            found = true;
        }
    }
    if (guessed == word) {
        cout << endl
             << "You Won"
             << endl;
        draw(remainingLifes);
        cout << endl
             << "The word to guess was: " << word;
        exit(1);
    }
    if (found == false) {
        remainingLifes--;
    }
    for (int i = 0; i < guessed.size(); i++) {
        cout << guessed[i] << " ";
    }

    cout << endl;
}

void start() {
    cout << "Press enter to start";
    getchar();
    system("cls");
    selectWord();
    display();
    while (remainingLifes != 0) {
        chooseWord();
    }
    if (remainingLifes == 0) {
        system("cls");
        cout << endl
             << "You lost" << endl;
        draw(0);
        cout << endl
             << "The word to guess was: " << word;
    }
}

int main() {
    cout << "Hangman";

    start();

    return 0;
}
