// Project2 (Creating Math Quiz Game)
#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel { Easy = 1, Medium, Hard, Mix };

enum enOperationType { Add = 1, Sub, Mult, Div, MixOp };

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enQuestionsLevel QuestionLevel;
	enOperationType OperationType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = 0;
};

struct stQuizz
{
	stQuestion QuestionsList[100];
	short NumberOfQuestions;
	enQuestionsLevel Q_Level;
	enOperationType Op_type;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool IsPass = 0;

};

int RandomNumber(int FROM, int TO)
{
	return rand() % (TO - FROM + 1) + FROM;
}

short ReadNumberOfQuestions()
{
	short NumberOfQuestions = 0;
	do
	{
		cout << "How Many Questions You Want? (1 - 50):\n";
		cin >> NumberOfQuestions;

	} while (NumberOfQuestions < 1 || NumberOfQuestions > 50);

	return NumberOfQuestions;

}

enQuestionsLevel ReadQuestionLevel()
{
	short QuestionsLevel = 0;
	do
	{
		cout << "Choose The Difficulty: [1]-Easy, [2]-Meduiem, [3]-Hard, [4]-Mix:\n";
		cin >> QuestionsLevel;

	} while (QuestionsLevel < 1 || QuestionsLevel > 4);

	return enQuestionsLevel(QuestionsLevel);
}

enOperationType ReadOperationType()
{
	short OperationType = 0;
	do
	{
		cout << "Choose The Operation Type: [1]-Add, [2]-Sub, [3]-Mult, [4]-Div, [5]-Mix:\n";
		cin >> OperationType;

	} while (OperationType < 1 || OperationType > 5);

	return enOperationType(OperationType);
}

int Calculator(int num1, int num2, enOperationType OpType)
	{
		switch (OpType)
		{
		case Add:
			return num1 + num2;
		case Sub:
			return num1 - num2;
		case Mult:
			return num1 * num2;
		case Div:
			return num1 / num2;
		default:
			return 0;

		}
	}

enOperationType GetRandomOperationType() {
	int Op = RandomNumber(1, 4); 
	return (enOperationType)Op;
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OperationType)
{
	stQuestion Question;

	if (QuestionLevel == Mix){
		QuestionLevel = enQuestionsLevel(RandomNumber(1, 3));
	}

	if (OperationType == MixOp) {
		OperationType = GetRandomOperationType();
	}
	Question.OperationType = OperationType;
	Question.QuestionLevel = QuestionLevel;

	switch (QuestionLevel)
	{
	case Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);

		return Question;


	case Medium:
		Question.Number1 = RandomNumber(11, 50);
		Question.Number2 = RandomNumber(11, 50);

		Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);

		return Question;


	case Hard:
		Question.Number1 = RandomNumber(51, 100);
		Question.Number2 = RandomNumber(51, 100);

		Question.CorrectAnswer = Calculator(Question.Number1, Question.Number2, Question.OperationType);

		return Question;
	}

	return Question;
}

void GenerateQuizzQuestions(stQuizz &quizz)
{
	for (short question = 0; question < quizz.NumberOfQuestions; question++)
	{
		quizz.QuestionsList[question] = GenerateQuestion(quizz.Q_Level, quizz.Op_type);
	}

}

char GetOperatonSymbol(enOperationType OperationType)
{
	switch (OperationType)
	{
	case Add:
		return '+';
	case Sub:
		return '-';
	case Mult:
		return '*';
	case Div:
		return '/';
	case MixOp:
		return 'M';
	default:
		return '!';
	}
}

void PrintTheQuestion(stQuizz quizz /* no need & */, short QuestionNumber)
{
	cout << "\nQuestion [" << QuestionNumber + 1 << "/" << quizz.NumberOfQuestions << "]\n\n";

	cout << quizz.QuestionsList[QuestionNumber].Number1 << " ";
	cout << GetOperatonSymbol(quizz.QuestionsList[QuestionNumber].OperationType) << " ";
	cout << quizz.QuestionsList[QuestionNumber].Number2 << " = ";
}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void ChangeScreenColor(bool result)
{
	if (result == true)
		system("color 2F");
	else {
		system("color 4F");
		cout << "\a";
	}
}

void ChackTheQuestionAnswer(stQuizz &quizz, short QuestionNumber)
{
	if (quizz.QuestionsList[QuestionNumber].PlayerAnswer != quizz.QuestionsList[QuestionNumber].CorrectAnswer)
	{
		quizz.QuestionsList[QuestionNumber].AnswerResult = false;
		quizz.NumberOfWrongAnswers++;

		cout << "\nWorng Answer :(\n";
		cout << "The Right Answer is: " << quizz.QuestionsList[QuestionNumber].CorrectAnswer << endl << endl ;
	}
	else
	{
		quizz.QuestionsList[QuestionNumber].AnswerResult = true;
		quizz.NumberOfRightAnswers++;
		cout << "\nRight Answer :)\n\n";
	}
	
	ChangeScreenColor(quizz.QuestionsList[QuestionNumber].AnswerResult);

}

void AskAndCorrectQuestionListAnswers(stQuizz &quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < quizz.NumberOfQuestions; QuestionNumber++)
	{
		// Print Question //
		PrintTheQuestion(quizz, QuestionNumber);
		
		// Read User Answer //
		quizz.QuestionsList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
		
		// Check The Answer //
		ChackTheQuestionAnswer(quizz, QuestionNumber);
	}

	quizz.IsPass = (quizz.NumberOfRightAnswers >= quizz.NumberOfWrongAnswers);
}

string GetFinalResult(bool isPass)
{
	if (isPass == true)
		return "[P A S S]";
	else
		return "[F A I L]";
}

string GetQuestionLevelText(enQuestionsLevel QuestionLevel) {
	string arrQuestionLevelText[4] = { "Easy","Med","Hard","Mix" };
	return arrQuestionLevelText[QuestionLevel - 1];
}

float GetAverage(float sum, float total)
{
	return (sum / total) * 100;
}

void PrintQuizzResults(stQuizz quizz)
{
	cout << "\n______________________________\n\n";

	cout << "Final Result is: " << GetFinalResult(quizz.IsPass);
	ChangeScreenColor(quizz.IsPass);

	cout << "\n______________________________\n\n";
	cout << "Number of Quistions     : " << quizz.NumberOfQuestions << endl;
	cout << "Question Difficulty     : " << GetQuestionLevelText(quizz.Q_Level) << endl;
	cout << "Operation Type          : " << GetOperatonSymbol(quizz.Op_type) << endl;
	cout << "Number of Right Answers : " << quizz.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answers : " << quizz.NumberOfWrongAnswers << endl;
	cout << "Percentage              : " << GetAverage(quizz.NumberOfRightAnswers, quizz.NumberOfQuestions) << "%";
	cout << "\n______________________________\n\n";
}

void PlayMathGame()
{
	stQuizz quizz;

	// Read Info From User //
	quizz.NumberOfQuestions = ReadNumberOfQuestions();
	quizz.Q_Level = ReadQuestionLevel();
	quizz.Op_type = ReadOperationType();

	GenerateQuizzQuestions(quizz);
	AskAndCorrectQuestionListAnswers(quizz);
	PrintQuizzResults(quizz);



}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		PlayMathGame();

		cout << " Do You Want To Play Again? Y/N?";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();


	return 0;
}

