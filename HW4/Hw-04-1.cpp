#include<iostream>
using namespace std;

struct courseGrade{
    double quiz1=0, quiz2=0, finalExam=0, midterm=0, Ave=0 ;
    char grade;
};
double Average(courseGrade& student);
char GradeLetter(courseGrade& student);

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
        cout << "Average Score: " << Average(student) << endl;
        student.grade = GradeLetter(student);
        cout << "Grade: " << student.grade << endl;
    
    return 0;
};

double Average(courseGrade& student){
            return (10*(student.quiz1+student.quiz2)/8+student.midterm/4+student.finalExam/2);
        };
char GradeLetter(courseGrade& student){
               
            double finalGrade (10*(student.quiz1+student.quiz2)/8+student.midterm/4+student.finalExam/2);
            if((finalGrade>=90)) return 'A';
            if((finalGrade>=80)) return 'B';
            if((finalGrade>=70)) return 'C';
            if((finalGrade>=60)) return 'D';
            return 'F';
        };