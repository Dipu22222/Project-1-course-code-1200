//---------------------------------------------------------------------------

#include <fmx.h>
#include <queue>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
class question{
public:
	char* Text;
	char* Answer1;
	char* Answer2;
	char* Answer3;
	int CorrectAnswer;

	question(){}
	question(char* text, char* ans1, char* ans2, char* ans3, int correctAns) {
		 Text = text;
		 Answer1 = ans1;
		 Answer2 = ans2;
		 Answer3 = ans3;
		 CorrectAnswer = correctAns;

	}


};
std::queue<question> LoadQuestions() {

   question q1 = question("Which color does not appear in Olympic rings?", "Black", "Orange", "Green", 2);
   question q2 = question("What is the chemical formula of table salt?", "NaCl", "NaCl1", "NaCl2", 1);
   question q3 = question("What is the longest river in the world?", "Nile", "Mississippi", "Amazon", 1);
   question q4 = question("Which planet is known as the Red Planet?", "Venus", "Mars", "Jupiter", 2);
   question q5 = question("Who wrote the play 'Romeo and Juliet'?", "William Shakespeare", "Charles Dickens", "Mark Twain", 1);
   question q6 = question("What gas do plants absorb from the atmosphere?", "Oxygen", "Carbon Dioxide", "Nitrogen", 2);
   question q7 = question("Which is the smallest continent in the world?", "Australia", "Europe", "Antarctica", 1);
   question q8 = question("Which organ in the human body purifies blood?", "Heart", "Lungs", "Kidneys", 3);
   question q9 = question("In which country were the Olympic Games invented?", "Greece", "Italy", "France", 1);
   question q10 = question("What is the hardest natural substance on Earth?", "Iron", "Diamond", "Gold", 2);

   std::queue<question> questions;
   questions.push(q1);
   questions.push(q2);
   questions.push(q3);
   questions.push(q4);
   questions.push(q5);
   questions.push(q6);
   questions.push(q7);
   questions.push(q8);
   questions.push(q9);
   questions.push(q10);

   return questions;


}

std::queue<question> questions;
question currentQuestion;
int selectedAnswer;
int Points = 0;


TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
questions = LoadQuestions();
	currentQuestion = questions.front();

	QuestionLabel->Text = currentQuestion.Text;
	Answer1RadioButton->Text = currentQuestion.Answer1;
	Answer2RadioButton->Text = currentQuestion.Answer2;
	Answer3RadioButton->Text = currentQuestion.Answer3;

	questions.pop();
	PointsLabel->Text = 0;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer1RadioButtonChange(TObject *Sender)
{
	  selectedAnswer = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer2RadioButtonChange(TObject *Sender)
{
	  selectedAnswer = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Answer3RadioButtonChange(TObject *Sender)
{
      selectedAnswer = 3;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ConfirmButtonClick(TObject *Sender)
{
 if(selectedAnswer == currentQuestion.CorrectAnswer) {
	  Points++;
	  PointsLabel->Text = Points;
   }

   if(!questions.empty()) {
   currentQuestion = questions.front();

	QuestionLabel->Text = currentQuestion.Text;
	Answer1RadioButton->Text = currentQuestion.Answer1;
	Answer2RadioButton->Text = currentQuestion.Answer2;
	Answer3RadioButton->Text = currentQuestion.Answer3;

	questions.pop();

	Answer1RadioButton->IsChecked = false;
	Answer2RadioButton->IsChecked = false;
	Answer3RadioButton->IsChecked = false;
	}
	else {
	ConfirmButton->Enabled = false;
	ConfirmButton->Text = "The End";
    }

}
//---------------------------------------------------------------------------
