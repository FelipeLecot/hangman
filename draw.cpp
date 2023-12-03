#include <iostream>
#include <string>
#include "draw.h"

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