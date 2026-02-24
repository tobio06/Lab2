// Lab 2 - Grading
// Jan. 14, 2026
// Author: Tobio Yeung, A01425663
// main

#include <iostream>
#include "Student.h"
#include "Course.h"


int main()
{
   CCourse my_course;

   std::string command;

   while (command != "Q" && command != "q")
      {
      my_course.print_menu();
      std::cin >> command;

      if (command == "A" || command == "a")
         {
         my_course.add_student();
         }
      else if (command == "P" || command == "p")
         {
         my_course.print_grades();
         }
      else if (command == "E" || command == "e")
         {
         std::string student;
         std::cout << "\nStudent to edit: ";
         std::cin >> student;
         my_course.edit_student(student);
         }
      else if (command == "D" || command == "d")
         {
         my_course.delete_student();
         }
      else if (command == "S" || command == "s")
         {
         my_course.save_class();
         }
      else if (command == "L" || command == "l")
         {
         my_course.load_class();
         }
      }
}
