#include <iostream>
#include <ctime>

using namespace std;

const int NUM_CHOICES = 3;
const char* CHOICES[NUM_CHOICES] = { "R", "P", "S" };

// Function to convert a string to uppercase.
string to_uppercase(string input) {
  for (int i = 0; i < input.length(); i++) {
    input[i] = toupper(input[i]);
  }
  return input;
}

// Function to get the name of the choice.
string get_choice_name(string choice) {
  if (choice == "R") {
    return "Rock";
  } else if (choice == "P") {
    return "Paper";
  } else {
    return "Scissors";
  }
}

// Function to determine the winner and update the scorecard.
void determine_winner_and_update_scorecard(
    string player_choice,
    const char* computer_choice,
    int& player_score,
    int& computer_score) {
  if (player_choice == computer_choice) {
    cout << "Draw!" << endl;
    player_score += 1;
    computer_score += 1;
  } else if (
      (player_choice == "R" && computer_choice == "S") ||
      (player_choice == "P" && computer_choice == "R") ||
      (player_choice == "S" && computer_choice == "P")) {
    cout << "You win!" << endl;
    player_score += 2;
  } else {
    cout << "Computer wins!" << endl;
    computer_score += 2;
  }
}

int main() {
  // Seed the random number generator.
  srand(time(NULL));

  int player_score = 0;
  int computer_score = 0;

  bool play_again = true;
  cout << "Welcome to the classic ROCK, PAPERS, SCISSORS !!";
  cout << "Enter choices [R], [P], [S] to play.\nPress [0] to EXIT.";
  cout << "\nLet's Enjoy!\n\n";
  while (play_again) {
    // Get the player's choice.
    string player_choice;
    cout << "\nEnter your choice (Rock[R], Paper[P], Scissors[S]): ";
    cin >> player_choice;

    // Convert the player's choice to uppercase.
    player_choice = to_uppercase(player_choice);

    // Check if the player wants to exit the game.
    if (player_choice == "0") {
      play_again = false;
      cout << "Game Ended!\nFinal ";
    } else {
      // Get the computer's choice.
      int computer_choice_number = rand() % NUM_CHOICES;
      const char* computer_choice = CHOICES[computer_choice_number];

      // Display the choices.
      cout << "You chose: " << get_choice_name(player_choice) << endl;
      cout << "Computer chose: " << get_choice_name(computer_choice) << endl;

      // Determine the winner and update the scorecard.
      determine_winner_and_update_scorecard(
          player_choice, computer_choice, player_score, computer_score);
    }

    // Display the scorecard.
    cout << "Score: \n|| Player " << player_score << " || Computer: " << computer_score << " ||"
         << endl;
  }

  return 0;
}
