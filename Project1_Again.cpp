// Doing Project1 Again 

#include <iostream>
#include <cstdlib>
using namespace std;

enum enChoice {Stone = 1, Paper, Scissor};
enum enWinner {Player = 1, Computer, Draw};

struct stRoundInfo
{
	short Round;
	enChoice PlayerChoice;
	enChoice ComputerChoice;
	enWinner RoundWinner;
	string RoundWinnerName = "";
};

struct stGameResults
{
	short GameRounds;
	short PlayerWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string GameWinnerName = "";
};

int RandomNumber(int FROM, int TO)
{
	return rand() % (TO - FROM + 1) + FROM;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

short ReadHowManyRounds()
{

	int rounds = 1;
	do
	{
		cout << "How Many Rounds You Want To Play?\n";
		cin >> rounds;
	} while (rounds < 0);


	return rounds;
}

enChoice ReadPlayerChoice()
{
	short PlayerChoice;

	do
	{
		cout << "Choose [1]-Stone [2]-Paper [3]-Scissor:\n";
		cin >> PlayerChoice;

	} while (PlayerChoice < 1 || PlayerChoice > 3);

	return enChoice(PlayerChoice);
}

enChoice GetComputerChoice()
{
	return enChoice(RandomNumber(1, 3));
}

enWinner WhoWonTheRound(enChoice PlayerChoice, enChoice ComputerChoice)
{
	if (ComputerChoice == PlayerChoice)
		return Draw;

	switch (ComputerChoice)
	{
	case Stone:
		if (PlayerChoice == Paper)
			return Player;
	
	case Paper:
		if (PlayerChoice == Scissor)
			return Player;
	
	case Scissor:
		if (PlayerChoice == Stone)
			return Player;
	default:
		return Computer;
	
	}
}

string GetWinnerName(enWinner Winner)
{
	string WinnerName[3] = { "Player","Computer","Draw" };

	return WinnerName[int(Winner) - 1];

}

string GetChoiceName(enChoice Choice)
{
	string ChoiceName[3] = { "Stone","Paper","Scissor" };

	return ChoiceName[short(Choice) - 1];
}

void ChangeScreenColor(enWinner winner)
{
	if (winner == Player)
		system("color 2F");
	else if (winner == Computer)
		system("color 4F");
	else
		system("color 6F");
}

void PrintRoundResults(stRoundInfo RI)
{
	cout << "\n---------------------------------------------\n";
	cout << "Round " << RI.Round << " Results:\n";

	cout << "Player Choice  : " << GetChoiceName(RI.PlayerChoice) << endl;
	cout << "Computer Choice: " << GetChoiceName(RI.ComputerChoice) << endl;
	cout << "The Winner is  : " << RI.RoundWinnerName << endl;
	cout << "---------------------------------------------\n";

	ChangeScreenColor(RI.RoundWinner);
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
	if (PlayerWinTimes > ComputerWinTimes)
		return Player;
	else if (ComputerWinTimes > PlayerWinTimes)
		return Computer;
	else
		return Draw;
}

stGameResults FillGameResults(short GameRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GR;

	GR.GameRounds = GameRounds;
	GR.PlayerWinTimes = PlayerWinTimes;
	GR.ComputerWinTimes = ComputerWinTimes;
	GR.DrawTimes = DrawTimes;
	GR.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
	GR.GameWinnerName = GetWinnerName(GR.GameWinner);
	
	return GR;
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RI;

	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short CurrentRound = 1; CurrentRound <= HowManyRounds; CurrentRound++)
	{
		cout << "\n\nRound " << CurrentRound << " Begins !!!\n\n";

		RI.Round = CurrentRound;
		RI.PlayerChoice = ReadPlayerChoice();
		RI.ComputerChoice = GetComputerChoice();
		RI.RoundWinner = WhoWonTheRound(RI.PlayerChoice,RI.ComputerChoice);
		RI.RoundWinnerName = GetWinnerName(RI.RoundWinner);

		if (RI.RoundWinner == Player)
			PlayerWinTimes++;
		else if (RI.RoundWinner == Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RI);

	}

	return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);


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
	cout << Tabs(2) << "Player1 Win Times  : " << GameResults.PlayerWinTimes << endl;
	cout << Tabs(2) << "Computer Win Times : " << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw Times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << GameResults.GameWinnerName << endl;
	cout << Tabs(2) << "--------------------------------------------\n\n";

	ChangeScreenColor(GameResults.GameWinner);

}

void StartGame()
{
	char PlayAgain = 'N';

	do
	{
		ResetScreen();
		stGameResults GR = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GR);

		cout << "Do You Want to Play Again? Y/N?";
		cin >> PlayAgain;


	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}


