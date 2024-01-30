#include "type.h"
#include <iostream>
#include <cassert>
#include <fstream>  
#include <iomanip>
#include <string>

const int MAX_SIZE = 20;

int ReadStudents(std::ifstream &gradesFile, StudentType students[]); //
void DisplayStudents(StudentType roster[], int);
void StudentSearch(StudentType roster[], int index);
void SortMovies(StudentType roster[], int);
int ValidId (StudentType roster[], int numOfStudents);
int main() {
    StudentType roster[MAX_SIZE];
    
  

    std::ifstream gradesFile("grades.dat");// create file object 
    int numOfStudents = ReadStudents(gradesFile, roster);// get number of students while storing them in array
    DisplayStudents(roster, numOfStudents);
 
    StudentSearch(roster, numOfStudents);
    return 0;
}




int ReadStudents(std::ifstream &gradesFile, StudentType students[]){
    int NumofStudents = 0; // get num of students 
    gradesFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the header line of the file 
    while (NumofStudents < MAX_SIZE && gradesFile){
       gradesFile >>   students[NumofStudents].classId;

       gradesFile >>   students[NumofStudents].studentName;
       
       gradesFile >>   students[NumofStudents].studentCLA;
      
       gradesFile >>   students[NumofStudents].studentOLA;
       
       gradesFile >>   students[NumofStudents].studentQuiz;
            
       gradesFile >>   students[NumofStudents].studentHomework;
            
       gradesFile >>   students[NumofStudents].studentExam;
            
       
       gradesFile >>   students[NumofStudents].studentBonus;
       NumofStudents++; 
  
    }

    return NumofStudents;
}





void DisplayStudents(StudentType roster[], int NumofStudents){
 std::cout << std::setw(5) << "ID" << std::setw(15) << "Name"
          << std::setw(5) << "CLA" << std::setw(5) << "OLA"
          << std::setw(5) << "Quiz" << std::setw(10) << "Homework"
          << std::setw(5) << "Exam" << std::setw(7) << "Bonus" << std::endl;
 
for (int i = 0; i < NumofStudents; i++) {
  
    std::cout << std::setw(5) << roster[i].classId
              << std::setw(15) << roster[i].studentName
              << std::setw(5) << roster[i].studentCLA
              << std::setw(5) << roster[i].studentOLA
              << std::setw(5) << roster[i].studentQuiz
              << std::setw(10) << roster[i].studentHomework
              << std::setw(5) << roster[i].studentExam
              << std::setw(7) << roster[i].studentBonus << std::endl;
}
 return; 
  }


void StudentSearch(StudentType roster[], int numOfStudents){
  //call ValidID function. 
  int i = ValidId(roster, numOfStudents);

          std::cout << "Name: " << roster[i].studentName << std::endl 
          << "CLA: " << roster[i].studentCLA <<std::endl
           << "OLA: " << roster[i].studentOLA << std::endl
          << "Quiz: "<< roster[i].studentQuiz << std::endl 
          <<"Homework:" <<roster[i].studentHomework << std::endl
          <<"Exam: " <<roster[i].studentExam << std::endl
          <<"Bonus: " <<roster[i].studentBonus << std::endl;


        }
        
    
  
int ValidId(StudentType roster[], int numOfStudents){
  int index;
  std::string classId;// get user input for student id 
   std::cout << "Enter student Id: ";
     std::cin >> classId; // store input 
  
for(int i = 0; i <= numOfStudents; i++){
  if (roster[i].classId == classId){ // loop and check if id matches
    std::cout << roster[i].studentName << std::endl;
    std::cout << "Information for student with ID: " << classId << std::endl; // print id if found 
    return i;
  }
  if (i == numOfStudents){ // if no match reset loop counter and prompt input 
  std::cout << "Enter student Id: "; 
  std::cin >> classId;
  i = 0;
  }
}

  return index; 
}