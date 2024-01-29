// Declare the student type in this header file
// Include this file in your main program file


#ifndef TYPE_H
#define TYPE_H
#include <string> 

class Pet {
private:
  std::string species;
  std::string breed;
  std::string name;
  char gender;
  int age;

public:
  // inline accessor functions
  std::string GetName() const { return name; }
  std::string GetBreed() const { return breed; }

public:
  // inline mutator functions
  void SetSpecies(std::string sp) { species = sp; }
  void SetBreed(std::string br) { breed = br; }
  void SetName(std::string n) { name = n; }
  void SetGender(char g) { gender = g; }
  void SetAge(int a) { age = a; }
  // Other Member Functions
  void PrintPet() const; // Outputs the pet information
  void PrintPets() const;
  Pet();
  Pet(std::string, std::string, std::string, char, int); // value constructor
  void SavePets(std::ofstream &);
};

#endif