#include "type.h"
#include <iostream>
#include <cassert>
#include <fstream>  
#include <iomanip>
#include <string>

const int MAX_SIZE = 20;

int ReadStudents(std::ifstream &gradesFile, StudentType students[]);
void DisplayStudents(StudentType roster[], int);
void StudentSearch(StudentType roster[], int numOfItems, std::string itemToLookfor);
void SortMovies(StudentType roster[], int);
int ValidId (StudentType roster[], std::string);
int main() {
    StudentType roster[MAX_SIZE];
    std::string studentId; 
  

    std::ifstream gradesFile("grades.dat");// create file object 
    int numofstudents = ReadStudents(gradesFile, roster);// get number of students while storing them in array
    DisplayStudents(roster, numofstudents);
 
    StudentSearch(roster, numofstudents, studentId);
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


  void StudentSearch(StudentType roster[], int numOfItems, std::string itemToLookfor){
    int count = -1;
     std::cout << "Enter student Id: ";
   std::cin >> itemToLookfor;
  std::cout << itemToLookfor; 

    for(int i = 0; i < numOfItems; i++){  // initialize loop to iterate through array and find student with class id 
    
   
        if(roster[i].classId == itemToLookfor){  // once student is found, print student grades
         int count = i; 
          std::cout << "Name: " << roster[i].studentName << std::endl 
          << "CLA: " << roster[i].studentCLA <<std::endl
           <<  "OLA: " << roster[i].studentOLA << std::endl
          << "Quiz: "<< roster[i].studentQuiz << std::endl 
          <<"Homework:" <<roster[i].studentHomework << std::endl
          <<"Exam: " <<roster[i].studentExam << std::endl
          <<"Bonus: " <<roster[i].studentBonus << std::endl;

        }
        
    }   
    
    for(int i = 0; i < numOfItems; i++){

      if(roster[i].classId == itemToLookfor){
        ; 
      }
      if 

    }
  
   

  }