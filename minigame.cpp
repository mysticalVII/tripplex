#include<iostream>
#include<ctime>
//using namespace std;

//Function PrintIntroduction
void PrintIntroduction(int Difficulty){

   //Expression Statement
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
  
}

//Fuction PlayGame
bool PlayGame(int Difficulty){

    PrintIntroduction(Difficulty); //calling a function and passed a value into the parameters 
    //Declaration Statement
    const int CodeA = rand() % Difficulty + Difficulty, CodeB = rand() % Difficulty + Difficulty, CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct= CodeA * CodeB * CodeC;
    //--

    std::cout << std::endl << "->There are 3 numbers in the code" << std::endl;
    std::cout << "->The sum of these 3 numbers are: " << CodeSum << std::endl;
    std::cout << "->The product of these 3 numbers are: " << CodeProduct << std::endl << std::endl; 

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << std::endl;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "The sum of the guesses: " << GuessSum << std::endl;
    std::cout << "The product of the guesses: " << GuessProduct << std::endl;

    //Check if the player has made the correct guess
    if (GuessSum == CodeSum && GuessProduct == CodeProduct){

        std::cout << "\nNice job! we have to go to the next level.";
        return true;
    
    }
    else{
    
        std::cout << "\nOh no, we messed up! try it again.";
        return false;

    }
    
}

int main(){

    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevel = 3; 

    while (LevelDifficulty <= MaxLevel){

       
        bool bLevelCompelete = PlayGame(LevelDifficulty); //UE standards to write a variable

        std::cin.clear(); //clears any error
        std::cin.ignore(); //Discards any buffer

        if(bLevelCompelete){
            //increase the difficulty
            ++LevelDifficulty;
        }
    }

    std::cout << "\nYou did it! you have accomplished the mission, well done.\n";
    return 0;
}
