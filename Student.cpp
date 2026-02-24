// Lab 2 - Grading
// Jan. 14, 2026
// Author: Tobio Yeung, A01425663
// student class .cpp

#include "Student.h"

CStudent::CStudent()
   {
      _student_number = "0";
      _lab = "0";
      _quiz = "0";
      _midterm = "0";
      _final = "0";
   }


/////////////////////////////
// STUDENT NUMBER FUNCTIONS
std::string CStudent::get_student_number() const
   { 
      return _student_number;
   }

void CStudent::set_student_number()
   {
   std::regex valid_student_number("^([Aa]01|[Aa]00)[0-9]{6}$");

   do
      {
      std::cin >> _student_number;      

      if (std::regex_match(_student_number, valid_student_number) == false)
         {
         std::cout << "Invalid student number, please try again.\n";
         }
      } while (std::regex_match(_student_number, valid_student_number) == false);
   }

void CStudent::set_student_number(std::string student_number)
   {
   std::regex valid_student_number("^([Aa]01|[Aa]00)[0-9]{6}$");

   if (std::regex_match(student_number, valid_student_number) == false)
      {
      //reports error if invalid data is entered
      throw std::runtime_error("Invalid student number in file");
      }

   _student_number = student_number;
   }


//////////////////
// LAB FUNCTIONS
std::string CStudent::get_lab() const
   {
      return _lab;
   }

void CStudent::set_lab()
   {
   std::regex valid_grade("^(100(\\.0*)?|([0-9]{1,2}|0*)(\\.[0-9]*)?)$");

   do
      {
      std::cin >> _lab;

      if (std::regex_match(_lab, valid_grade) == false)
         {
         std::cout << "Invalid grade, please try again.\n";
         }
      } while (std::regex_match(_lab, valid_grade) == false);
   }

void CStudent::set_lab(std::string lab)
   {
   std::regex valid_grade ("^(100(\\.0*)?|([0-9]{1,2}|0*)(\\.[0-9]*)?)$");

   if (std::regex_match(lab, valid_grade) == false)
      {
      //reports error if invalid data is entered
      throw std::runtime_error("Invalid lab grade in file");
      }

   _lab = lab;
   }


////////////////////
// QUIZ FUNCTIONS
std::string CStudent::get_quiz() const
   {
      return _quiz;
   }

void CStudent::set_quiz()
   {
   std::regex valid_grade("^(100(\\.0*)?|([0-9]{1,2}|0*)(\\.[0-9]*)?)$");

   do
      {
      std::cin >> _quiz;

      if (std::regex_match(_quiz, valid_grade) == false)
         {
         std::cout << "Invalid grade, please try again.\n";
         }
      } while (std::regex_match(_quiz, valid_grade) == false);
   }

void CStudent::set_quiz(std::string quiz)
   {
   std::regex valid_grade("^(100(\\.0*)?|([0-9]{1,2}|0*)(\\.[0-9]*)?)$");

   if (std::regex_match(quiz, valid_grade) == false)
      {
      //reports error if invalid data is entered
      throw std::runtime_error("Invalid quiz grade in file");
      }

   _quiz = quiz;
   }


///////////////////////
// MIDTERM FUNCTIONS
std::string CStudent::get_midterm() const
   { 
      return _midterm;
   }

void CStudent::set_midterm()
   {
   std::regex valid_grade("^(100(\\.0*)?|([0-9]{1,2}|0*)(\\.[0-9]*)?)$");

   do
      {
      std::cin >> _midterm;

      if (std::regex_match(_midterm, valid_grade) == false)
         {
         std::cout << "Invalid grade, please try again.\n";
         }
      } while (std::regex_match(_midterm, valid_grade) == false);
   }

void CStudent::set_midterm(std::string midterm)
   {
   std::regex valid_grade("^(100(\\.0*)?|([0-9]{1,2}|0*)(\\.[0-9]*)?)$");

   if (std::regex_match(midterm, valid_grade) == false)
      {
      //reports error if invalid data is entered
      throw std::runtime_error("Invalid midterm grade in file");
      }

   _midterm = midterm;
   }


//////////////////////
// FINAL FUNCTIONS
std::string CStudent::get_final() const
   {
      return _final;
   }

void CStudent::set_final()
   { 
   std::regex valid_grade("^(100(\\.0*)?|([0-9]{1,2}|0*)(\\.[0-9]*)?)$");

   do
      {
      std::cin >> _final;

      if (std::regex_match(_final, valid_grade) == false)
         {
         std::cout << "Invalid grade, please try again.\n";
         }
      } while (std::regex_match(_final, valid_grade) == false);
   }

void CStudent::set_final(std::string final)
   {
   std::regex valid_grade("^(100(\\.0*)?|([0-9]{1,2}|0*)(\\.[0-9]*)?)$");

   if (std::regex_match(final, valid_grade) == false)
      {
      //reports error if invalid data is entered
      throw std::runtime_error("Invalid final grade in file");
      }

   _final = final;
   }


///////////////////
// JSON FUNCTIONS
//
// converts CStudent objects into json objects for saving classlist
void to_json(json& j, const CStudent& s)
   {
   j = json{ {"student_number", s.get_student_number()},
             {"lab", s.get_lab()},
             {"quiz", s.get_quiz()},
             {"midterm", s.get_midterm()},
             {"final", s.get_final()}
           };
   }


// converts json objects into CStudent objects for loading classlist
void from_json(const json& j, CStudent& s)
   {
   s.set_student_number(j.at("student_number").get<std::string>());
   s.set_lab(j.at("lab").get<std::string>());
   s.set_quiz(j.at("quiz").get<std::string>());
   s.set_midterm(j.at("midterm").get<std::string>());
   s.set_final(j.at("final").get<std::string>());
   }

