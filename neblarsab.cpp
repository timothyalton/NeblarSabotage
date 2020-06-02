// My first attempt at c++
#include <iostream>
#include <ctime>
#include <windows.h>
// #include <mmsystem.h>

// #pragma comment(lib, "winmm.lib")

void PrintIntroduction(int Difficulty) {
     // Intro messages printed to terminal
    std::cout << "\n\nYou are a captain of the intergalatic space fleet of the sector Neblar. Your ship has been sabotaged and is counting down to self destruct!\n";
    std::cout << "You need to enter the correct codes, at incrementing levels, to cancel the self destruct and save your crew...\n";
    std::cout << "Current self-destruct level: " << Difficulty << std::endl << std::endl;
}

bool PlayGame(int Difficulty) {
   
    // PrintIntroArt();
    PrintIntroduction(Difficulty);
    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to: " << CodeProduct;
    std::cout << "\n(write out each code value with spaces in between)\n";
    std::cout << "(ex: 0 0 0)\n";
    std::cout << "\nEnter Code Values: \n";

    int GuessA, GuessB, GuessC;

    // Store player guess
    std::cin >> GuessA >> GuessB >> GuessC;
     

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the Players guess is correct or not
    if (GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\n\n*** Correct! ***\n";
        return true;
    } 
    else {
        std::cout << "*** Incorrect! Time is running out. Try again... ***\n";
        return false;
    }
}

int main() {

    // PlaySound(("space.mp3"), NULL, SND_FILENAME | SND_ASYNC);
    // PlaySound("space.mp3", NULL, SND_SYNC);

    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) { // Loop the game until all levels are completed 
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "*** You're a true leader! You saved your crew and your ship! ***";

    return 0; // exits program without error
}

