# 🎲 Number Guessing Game in C++

This is a simple terminal-based Number Guessing Game written in C++. The player selects a difficulty level, and then tries to guess the randomly generated number within a specified range.

## 🚀 Features

- Difficulty levels:
  - Easy: 0 to 20
  - Medium: 0 to 50
  - Hard: 0 to 100
- Feedback on whether the guessed number is too high or too low
- User-friendly terminal interaction
- Random number generation using current time

## 🧠 How It Works

1. The user selects whether to play or exit.
2. If playing, the user chooses a difficulty level.
3. The program generates a random number based on the selected level.
4. The user continues guessing until the correct number is found, with hints provided after each guess.

## 🛠 Technologies Used

- C++
- Standard Library (iostream, cstdlib, ctime)

## 📦 How to Compile and Run

### Using g++:

bash
g++ -o NumberGuess Number_Guessing_Game.cpp
./NumberGuess


### Or with any C++ compiler of your choice.

## 📸 Preview

bash
Enter : - 
 1 - for play : 
 0 - for exit : 
 :- 1
Select level : 
  Easy - 1 : 
  Medium - 2 : 
  Hard - 3 : 
Enter : - 2
Range is - 0 - 50 
Guess the number  :  : 25
Your number is lesser

Enter again : 37
Your number is greater

Enter again : 32
Congratulations !!! you got it :


## 📃 License

This project is open source and available under the [MIT License](LICENSE).

---

Made with 💻 and ☕
