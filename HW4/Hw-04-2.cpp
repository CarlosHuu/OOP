#include<iostream>
using namespace std;

class courseGrade{
    
    public :
        double quiz1=0, quiz2=0, finalExam=0, midterm=0, Ave=0 ;
        char grade;
        void Average();
        void GradeLetter();
};

int main(){

        courseGrade student;
        cout << "Quiz 1 score (0-10), Quiz 2 score (0-10), Midterm score (0-100), Final score (0-100)" << endl;
        cin >> student.quiz1 >> student.quiz2 >> student.midterm >> student.finalExam;
        cout << endl;
        cout << "Student Record:" << endl;
        cout << "Quiz 1 score: " << student.quiz1 << endl;
        cout << "Quiz 2 score: " << student.quiz2 << endl;
        cout << "Midterm score: " << student.midterm << endl;
        cout << "Final score: " << student.finalExam << endl;
        student.Average();
        cout << "Average Score: " << student.Ave << endl;
        student.GradeLetter();
        cout << "Grade: " << student.grade << endl;
    
    return 0;
};

void courseGrade::Average(){
            Ave = (10*(quiz1+quiz2)/8+midterm/4+finalExam/2);
        };
void courseGrade::GradeLetter(){
            
            double finalGrade (10*(quiz1+quiz2)/8+midterm/4+finalExam/2);
            if((finalGrade>=90)) grade='A';
            else if((finalGrade>=80))  grade='B';
            else if((finalGrade>=70))  grade='C';
            else if((finalGrade>=60))  grade='D';
            else  grade='F';
        };