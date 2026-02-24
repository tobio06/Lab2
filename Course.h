// Lab 2 - Grading
// Jan. 14, 2026
// Author: Tobio Yeung, A01425663
// course class .h

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Student.h"
#include <fstream>

class CCourse
   {
   public:
      CCourse();

      void edit_student(std::string);

      void add_student();

      void print_menu();

      void print_grades();

      void delete_student();

      void save_class();

      void load_class();

   private:
      std::vector<CStudent> _class_list;
   };