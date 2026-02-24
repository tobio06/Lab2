// Lab 2 - Grading
// Jan. 14, 2026
// Author: Tobio Yeung, A01425663
// student class .h

#pragma once

#include <iostream>
#include <string>
#include <regex>
// library below shared on BEng Discord server
#include "json.hpp"

class CStudent
   {
   public:
      CStudent();

      std::string get_student_number() const;
      void set_student_number();
      void set_student_number(std::string); // overloaded only for json conversion

      std::string get_lab() const;
      void set_lab();
      void set_lab(std::string); // overloaded only for json conversion

      std::string get_quiz() const;
      void set_quiz();
      void set_quiz(std::string); // overloaded only for json conversion

      std::string get_midterm() const;
      void set_midterm();
      void set_midterm(std::string); // overloaded only for json conversion

      std::string get_final() const;
      void set_final();
      void set_final(std::string); // overloaded only for json conversion

   private:
      std::string _student_number;
      std::string _lab;
      std::string _quiz;
      std::string _midterm;
      std::string _final;
   };


using json = nlohmann::json;
// json-CStudent conversion functions
void to_json(json& j, const CStudent& s);
void from_json(const json& j, CStudent& s);