// Project 1 (Stone-Paper-Scissor Game)
#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice {Stone = 1, Paper = 2, Scissor = 3};
enum enWinner {Player1 = 1, Computer = 2, Draw = 3};

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

int RandomNumber(int FROM, int TO)
{
	return rand() % (TO - FROM + 1) + FROM;
}

void ResetScreen()
{
	system("cls"); //clear the text on screen
	system("color 0F"); // black screen color
}

short ReadHowManyRounds()
{
	short GameRounds = 1;

	do
	{
		cout << "How Many Rounds You Want To Play?\n";
		cin >> GameRounds;
	} while (GameRounds < 1);

	return GameRounds;

}

enGameChoice ReadPlayer1Choice()
{
	short choice;

	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissor ?";
		cin >> choice;
	} while (choice < 1 || choice > 3);

	return (enGameChoice)choice;

}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
		return Draw;

	switch (RoundInfo.Player1Choice)
	{

	case Stone:
		if (RoundInfo.ComputerChoice == Paper)
			return Computer;
		break; // no need to use "break;" because we use return
	case Paper:
		if (RoundInfo.ComputerChoice == Scissor)
			return Computer;
		break;
	case Scissor:
		if (RoundInfo.ComputerChoice == Stone)
			return Computer;
		break;
	}
	// if we reach here then the player1 is the winner
	return Player1;

}

string WinnerName(enWinner winner)
{
	string arrWinnerName[3] = {"Player1", "Computer", "No Winner"};
	return arrWinnerName[winner - 1];// (winner - 1) because array base 0;
}

string ChoiceName(enGameChoice choice)
{
	string arrChoice[3] = { "Stone","Paper","Scissor" };

	return arrChoice[choice - 1]; // (choice - 1) because array base 0;
}

void SetWinnerScreenColor(enWinner winner)
{
	switch (winner)
	{
	case Player1:
		system("color 2f"); // turn screen color to Green 
		break;
	case Computer:
		system("color 4f"); // turn screen color to Red
		break;
	case Draw:
		system("color 6f"); // turn screen color to Yellow
		break;
	}
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	// The Results //
	cout << "\n ---------------Round [" << RoundInfo.RoundNumber << "]---------------\n\n";
	cout << "PLayer1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner: [" << RoundInfo.WinnerName << "] \n";
	cout << "---------------------------------------------\n";

	// Change Screen Color //
	SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(stGameResults GameResults)
{
	if (GameResults.Player1WinTimes > GameResults.ComputerWinTimes)
		return Player1;
	else if (GameResults.ComputerWinTimes > GameResults.Player1WinTimes)
		return Computer;
	else
		return Draw;
}

stGameResults FillGameReuslts(short GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(GameResults);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;


}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short Round = 1; Round <= HowManyRounds; Round++)
	{
		cout << "\nRound [" << Round << "] Begins:\n";

		// Playing the Round and Decide the Winner //
		RoundInfo.RoundNumber = Round;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		// Increase Win and Draw Counters //
		if (RoundInfo.Winner == Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		// Print The Round Results //
		PrintRoundResults(RoundInfo);

	}// end of loop //


	// using function to return all information --> stGameResult
	return FillGameReuslts(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);

}

string Tabs(int NumberOfTabs)
{
	// Tab = 4 spaces //
	string t = "";

	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}

	return t;
		
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "_____________________________________________________\n\n";
	cout << Tabs(2) << "                   +++Game Over+++\n";
	cout << Tabs(2) << "_____________________________________________________\n\n";

}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "---------------[Game Results]---------------\n";
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 Win Times  : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer Win Times : " << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw Times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;
	cout << Tabs(2) << "--------------------------------------------";

	SetWinnerScreenColor(GameResults.GameWinner);

}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << endl << "Do You Want to Play Again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();


	return 0;
}


