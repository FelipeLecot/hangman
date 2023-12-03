#include <iostream>
#include <string>
#include "draw_hangman.h"

using namespace std;

void draw(int status) {
  string hangman_ascii[7] = {
  R"""(
  +---+
    |   |
    O   |
   /|\  |
   / \  |
        |
  =========)""",
  R"""(
  +---+
    |   |
    O   |
   /|\  |
   /    |
        |
  =========)""",
  R"""(
  +---+
    |   |
    O   |
   /|\  |
        |
        |
  =========)""",
  R"""(
  +---+
    |   |
    O   |
  /|   |
        |
        |
  =========)""",
  R"""(
  +---+
    |   |
    O   |
    |   |
        |
        |
  =========)""",
  R"""(
  +---+
    |   |
    O   |
        |
        |
        |
  =========)""",
  R"""(
  +---+
    |   |
        |
        |
        |
        |
  =========)""",
  };
  cout << hangman_ascii[status];
}