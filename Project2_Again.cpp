// Creating Project2 Again (Math Quiz Game)
#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionDifficulty { Easy = 1, Medium = 2, Hard = 3, ExtremelyHard = 4, Mix = 5 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, Pow = 5, MixOp = 6 };

struct stQuestion
{
    int FirstNumber = 0;
    int SecondNumber = 0;
    enQuestionDifficulty Q_Difficulty;
    enOperationType Q_Operation;
    int PlayerAnswer = 0;
    int CorrectAnswer = 0;
    bool Result = true;

};

struct stQuizz
{
    stQuestion QuestionsList[100];
    short NumberOfQuestions = 0;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    enQuestionDifficulty Difficulty;
    enOperationType Operation;
    float Percentage = 0.0;
    bool IsPass = true;

};

int RandomNumber(int FROM, int TO)
{
    return rand() % (TO - FROM + 1) + FROM;
}

void ClearScreen()
{
    system("cls");
    system("color 0F");
}

short ReadNumberOfQuestions()
{
    short num = 0;

    do
    {
        cout << "Enter Number Of Questions (1 - 100): \n";
        cin >> num;

    } while (num < 1 || num > 100);

    return num;
}

enQuestionDifficulty ReadQuestionsDifficulty()
{
    short Difficulty = 0;
    do
    {
        cout << "Choose The Difficulty: [1]-Easy, [2]-Meduiem, [3]-Hard, [4]-Extremely Hard, [5]-Mix:\n";
        cin >> Difficulty;

    } while (Difficulty < 1 || Difficulty > 5);

    return enQuestionDifficulty(Difficulty);
}

enOperationType ReadOperationType()
{
    short OperationType = 0;
    do
    {
        cout << "Choose The Operation Type: [1]-Add, [2]-Sub, [3]-Mult, [4]-Div, [5]-Power, [6]-Mix:\n";
        cin >> OperationType;

    } while (OperationType < 1 || OperationType > 6);

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
    case Pow:
        return pow(num1, num2);
    default:
        return 0;

    }
}

stQuestion GenerateQuestion(enQuestionDifficulty Difficulty, enOperationType Operation)
{
    stQuestion Question;

    if (Difficulty == Mix)
        Difficulty = enQuestionDifficulty(RandomNumber(1, 4));

    if (Operation == MixOp)
        Operation = enOperationType(RandomNumber(1, 5));

    Question.Q_Difficulty = Difficulty;
    Question.Q_Operation = Operation;

    switch (Difficulty)
    {
    case Easy:
        Question.FirstNumber = RandomNumber(1, 10);
        Question.SecondNumber = RandomNumber(1, 10);

        Question.CorrectAnswer = Calculator(Question.FirstNumber, Question.SecondNumber, Question.Q_Operation);
        return Question;

    case Medium:
        Question.FirstNumber = RandomNumber(11, 50);
        Question.SecondNumber = RandomNumber(11, 50);

        Question.CorrectAnswer = Calculator(Question.FirstNumber, Question.SecondNumber, Question.Q_Operation);
        return Question;

    case Hard:
        Question.FirstNumber = RandomNumber(51, 100);
        Question.SecondNumber = RandomNumber(51, 100);

        Question.CorrectAnswer = Calculator(Question.FirstNumber, Question.SecondNumber, Question.Q_Operation);
        return Question;

    case ExtremelyHard:
        Question.FirstNumber = RandomNumber(101, 1000);
        Question.SecondNumber = RandomNumber(101, 1000);

        Question.CorrectAnswer = Calculator(Question.FirstNumber, Question.SecondNumber, Question.Q_Operation);
        return Question;

    default:
        cout << "Calculation Erorr!";
        return Question;
    }
    return Question;
}

void GenerateQuizzQuestions(stQuizz &Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        Quizz.QuestionsList[QuestionNumber] = GenerateQuestion(Quizz.Difficulty, Quizz.Operation);
    }
}

char GetOperatonSymbol(enOperationType OperationNumber)
{
    switch (OperationNumber)
    {
    case Add:
        return '+';
    case Sub:
        return '-';
    case Mult:
        return '*';
    case Div:
        return '/';
    case Pow:
        return '^';
    case MixOp:
        return 'M';
    default:
        return '!';
    }
}

void PrintQuestion(stQuizz Quizz, short QuestionNumber)
{
    cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";

    cout << Quizz.QuestionsList[QuestionNumber].FirstNumber << " ";
    cout << GetOperatonSymbol(Quizz.QuestionsList[QuestionNumber].Q_Operation) << " ";
    cout << Quizz.QuestionsList[QuestionNumber].SecondNumber << " = ";
}

int GetPlayerAnswer()
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

float GetPercentage(float sum, float total)
{
    return (sum / total) * 100;
}

void CheckTheQuestionAnswer(stQuizz& quizz, short QuestionNumber)
{
    if (quizz.QuestionsList[QuestionNumber].PlayerAnswer != quizz.QuestionsList[QuestionNumber].CorrectAnswer)
    {
        quizz.QuestionsList[QuestionNumber].Result = false;
        quizz.NumberOfWrongAnswers++;

        cout << "\nWorng Answer :(\n";
        cout << "The Right Answer is: " << quizz.QuestionsList[QuestionNumber].CorrectAnswer << endl << endl;
    }
    else
    {
        quizz.QuestionsList[QuestionNumber].Result = true;
        quizz.NumberOfRightAnswers++;
        cout << "\nRight Answer :)\n\n";
    }

    ChangeScreenColor(quizz.QuestionsList[QuestionNumber].Result);

}

void AskAndCorrectQuestionListAnswers(stQuizz& quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < quizz.NumberOfQuestions; QuestionNumber++)
    {
        // Print Question //
        PrintQuestion(quizz, QuestionNumber);

        // Read User Answer //
        quizz.QuestionsList[QuestionNumber].PlayerAnswer = GetPlayerAnswer();

        // Check The Answer //
        CheckTheQuestionAnswer(quizz, QuestionNumber);
    }

    quizz.IsPass = (quizz.NumberOfRightAnswers >= quizz.NumberOfWrongAnswers);
}


string GetFinalResultText(bool IsPass)
{
    if (IsPass == true)
        return "*PASS*";
    else
        return "*FAIL*";
}

string GetQuestionDifficultyText(enQuestionDifficulty Difficulty)
{
    switch (Difficulty)
    {
    case Easy:
        return "Easy";
    case Medium:
        return "Medium";
    case Hard:
        return "Hard";
    case ExtremelyHard:
        return "Extremely Hard";
    case Mix:
        return "Mix";
    default:
        return "!erorr!";
    }
}

void PrintQuizzResults(stQuizz Quizz)
{
    cout << "\n______________________________\n\n";

    cout << "Final Result is: " << GetFinalResultText(Quizz.IsPass);
    ChangeScreenColor(Quizz.IsPass);

    cout << "\n______________________________\n\n";
    cout << "Number of Quistions     : " << Quizz.NumberOfQuestions << endl;
    cout << "Question Difficulty     : " << GetQuestionDifficultyText(Quizz.Difficulty) << endl;
    cout << "Operation Type          : " << GetOperatonSymbol(Quizz.Operation) << endl;
    cout << "Number of Right Answers : " << Quizz.NumberOfRightAnswers << endl;
    cout << "Number of Wrong Answers : " << Quizz.NumberOfWrongAnswers << endl;
    cout << "Percentage              : " << Quizz.Percentage << "%" << endl;
    cout << "______________________________\n\n";
}

void PlayMathGame()
{
    stQuizz Quizz;

    Quizz.NumberOfQuestions = ReadNumberOfQuestions();
    Quizz.Difficulty = ReadQuestionsDifficulty();
    Quizz.Operation = ReadOperationType();

   
    GenerateQuizzQuestions(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzResults(Quizz);
}

char AskToPlayAgain()
{
    char PlayAgain;

    cout << " Do You Want To Play Again? Y/N?";
    cin >> PlayAgain;

    return PlayAgain;
}

void StartGame()
{
    char PlayAgain = 'N';

    do
    {
        ClearScreen();
        PlayMathGame();
        PlayAgain = AskToPlayAgain();


    } while (PlayAgain == 'Y' || PlayAgain == 'y');
    
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}


