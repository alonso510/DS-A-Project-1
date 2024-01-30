#include "type.h"
#include <iostream>
#include <cassert>
#include <fstream>  
#include <iomanip>
#include <string>
#include <algorithm>

const int MAX_SIZE = 17;

int ReadStudents(std::ifstream &gradesFile, StudentType students[]); //function prototypes 
void DisplayStudents(StudentType roster[], int);
void StudentSearch(StudentType roster[], int index);
void SortStudents(StudentType roster[], int numOfStudents);
int ValidId (StudentType roster[], int numOfStudents);

int main() {
    StudentType roster[MAX_SIZE];
    
  

    std::ifstream gradesFile("grades.dat");// create file object 
    int numOfStudents = ReadStudents(gradesFile, roster);// get number of students while storing them in array
    DisplayStudents(roster, numOfStudents);
 
    StudentSearch(roster, numOfStudents);
    SortStudents(roster, numOfStudents);
    DisplayStudents(roster, numOfStudents); 
    return 0;
}




int ReadStudents(std::ifstream &gradesFile, StudentType students[]){
    int NumofStudents = 0; // get num of students 
    gradesFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the header line of the file 
    while (gradesFile){ // loop to iterate while the file is valid
       gradesFile >>   students[NumofStudents].classId; // store data into array struct 

       gradesFile >>   students[NumofStudents].studentName;
       
       gradesFile >>   students[NumofStudents].studentCLA;
      
       gradesFile >>   students[NumofStudents].studentOLA;
       
       gradesFile >>   students[NumofStudents].studentQuiz;
            
       gradesFile >>   students[NumofStudents].studentHomework;
            
       gradesFile >>   students[NumofStudents].studentExam;
            
       
       gradesFile >>   students[NumofStudents].studentBonus;
       NumofStudents++; // increase the number of students for each student you store in array
  
    }

    return NumofStudents; 
}





void DisplayStudents(StudentType roster[], int NumofStudents){

  std::cout << std::endl << std::endl;
 std::cout << std::setw(5) << "ID" << std::setw(15) << "Name" // format header accordingly 
          << std::setw(5) << "CLA" << std::setw(5) << "OLA"
          << std::setw(5) << "Quiz" << std::setw(10) << "Homework"
          << std::setw(5) << "Exam" << std::setw(7) << "Bonus" << std::endl;
 
for (int i = 0; i <= NumofStudents; i++) { // loop through students, print data of each
  
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
  int i = ValidId(roster, numOfStudents);// call ValidID function that return index of array 

          std::cout << "Name: " << roster[i].studentName << std::endl // print out individual student 
          << "CLA: " << roster[i].studentCLA <<std::endl
           << "OLA: " << roster[i].studentOLA << std::endl
          << "Quiz: "<< roster[i].studentQuiz << std::endl 
          <<"Homework:" <<roster[i].studentHomework << std::endl
          <<"Exam: " <<roster[i].studentExam << std::endl
          <<"Bonus: " <<roster[i].studentBonus << std::endl;
          std::cout << std::endl << std::endl; 
          


        }
        
    
  
int ValidId(StudentType roster[], int numOfStudents){
  int index;
  std::string classId;// get user input for student id 
   std::cout << "Enter student Id: ";
     std::cin >> classId; // store input 
  
for(int i = 0; i <= numOfStudents; i++){
  if (roster[i].classId == classId){ // loop and check if id matches
    
    std::cout << "Information for student with ID: " << classId << std::endl; // print id if found 
    return i; // return index of array, which student ID to look for 
  }
  if (i == numOfStudents){ // if no match reset loop counter 
  std::cout << "Enter student Id: "; // prompt user input
  std::cin >> classId;// store input 
  i = 0;
  }
}

  return index; 
}



void SortStudents(StudentType roster[], int numOfStudents) {
  std::cout << "Sorting student records by name . . .  " << std::endl; 
    bool sorted = false; // indicates whether additional comparison passes are needed 
    int last = numOfStudents - 1;

    StudentType tmp;

    while (!sorted) {
        sorted = true;

        for (int i = 0; i < last; i++) {
            if (roster[i].studentName > roster[i + 1].studentName) {
                // Swap the two records
                tmp = roster[i];
                roster[i] = roster[i + 1];
                roster[i + 1] = tmp;

                // The remaining array is not sorted, need at least another pass
                // of pairwise comparison
                sorted = false;
            }
        }

        last--;
    }
}