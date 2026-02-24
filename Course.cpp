// Lab 2 - Grading
// Jan. 14, 2026
// Author: Tobio Yeung, A01425663
// course class .cpp

#include "Course.h"

CCourse::CCourse() {}

void CCourse::edit_student(std::string student_string)
   {
   int student;

   std::regex valid_student("^\\d+$");

   while (true)
      {
      if (std::regex_match(student_string, valid_student) == false)
         {
         std::cout << "Input must be a number, please try again\n";
         }
      else
         {
         student = std::stoi(student_string);
         if (student <= 0 || student > _class_list.size())
            {
            std::cout << "Invalid student index, please try again\n";
            }
         else
            break;
         }
      std::cout << "\nStudent to edit: ";
      std::cin >> student_string;
      }

   int student_index = student - 1;

   std::cout << "\nStudent Number: ";
   _class_list.at(student_index).set_student_number();

   std::cout << "\nLab Grade: ";
   _class_list.at(student_index).set_lab();

   std::cout << "\nQuiz Grade: ";
   _class_list.at(student_index).set_quiz();

   std::cout << "\nMidterm Grade: ";
   _class_list.at(student_index).set_midterm();

   std::cout << "\nFinal Exam Grade: ";
   _class_list.at(student_index).set_final();
   }


void CCourse::add_student()
   {
   std::cout << "\nAdding Student";
   _class_list.emplace_back();
   std::string student = std::to_string(_class_list.size());
   edit_student(student);
   }


void CCourse::print_menu()
   {
   std::cout << "\n****************************************\n";
   std::cout << "\nELEX4618 Grade System, by Tobio Yeung\n";
   std::cout << "\n****************************************\n";
   std::cout << "\n(A)dd student\n";
   std::cout << "\n(E)dit student\n";
   std::cout << "\n(P)rint grades\n";
   std::cout << "\n(D)elete student\n";
   std::cout << "\n(S)ave class\n";
   std::cout << "\n(L)oad class\n";
   std::cout << "\n(Q)uit\n";
   std::cout << "\nCMD> ";
   }


void CCourse::print_grades()
   {
   std::ostringstream grade_table;

   grade_table << std::left
      << "\n"
      << std::setw(5) << "#"
      << std::setw(15) << "Student"
      << std::setw(10) << "Lab"
      << std::setw(10) << "Quiz"
      << std::setw(10) << "Midterm"
      << std::setw(15) << "Final Exam"
      << std::setw(15) << "Final Grade"
      << "\n"
      << std::string(90, '-')
      << "\n";

   std::cout << grade_table.str();
   grade_table.str("");
   grade_table.clear();

   for (int student_index = 0; student_index < _class_list.size(); student_index++)
      {
      // turn student grades from strings into floats to calculate final grade
      float lab, quiz, midterm, final, final_grade;

      std::stringstream lab_stream(_class_list.at(student_index).get_lab());
      lab_stream >> lab;

      std::stringstream quiz_stream(_class_list.at(student_index).get_quiz());
      quiz_stream >> quiz;

      std::stringstream midterm_stream(_class_list.at(student_index).get_midterm());
      midterm_stream >> midterm;

      std::stringstream final_stream(_class_list.at(student_index).get_final());
      final_stream >> final;

      final_grade =  lab * 0.4 +
                     quiz * 0.1 +
                     midterm * 0.2 +
                     final * 0.3;

      grade_table << std::left
         << std::setw(5) << student_index + 1 
         << std::setw(15) << _class_list.at(student_index).get_student_number()
         << std::setw(10) << std::fixed << std::setprecision(1) << lab
         << std::setw(10) << std::fixed << std::setprecision(1) << quiz
         << std::setw(10) << std::fixed << std::setprecision(1) << midterm
         << std::setw(15) << std::fixed << std::setprecision(1) << final
         << std::setw(15) << std::fixed << std::setprecision(2) << final_grade
         << "\n";

      std::cout << grade_table.str();
      grade_table.str("");
      grade_table.clear();
      }
   }


void CCourse::delete_student()
   {
   std::string student_string;
   int student;

   std::regex valid_student("^\\d+$");

   while (true)
      {
      std::cout << "\nStudent to delete: ";
      std::cin >> student_string;

      if (std::regex_match(student_string, valid_student) == false)
         {
         std::cout << "Input must be a number, please try again\n";
         }
      else
         {
         student = std::stoi(student_string);
         if (student <= 0 || student > _class_list.size())
            {
            std::cout << "Invalid student index, please try again\n";
            }
         else
            break;
         }
      }

   int student_index = student - 1;

   _class_list.erase(_class_list.begin() + student_index);
   std::cout << "\nStudent deleted!";
   }


void CCourse::save_class() 
   {
   json class_list = _class_list;

   std::string file_name;
   std::cout << "\Name of save file: ";
   std::cin >> file_name;

   std::ofstream saved_class(file_name);
   saved_class << std::setw(4) << class_list;

   std::cout << "\nFile saved!\n";
   }


void CCourse::load_class()
   {
   std::string file_name;
   std::ifstream loaded_file;
   do
      {
      std::cout << "\nName of load file: ";
      std::cin >> file_name; 

      loaded_file.open(file_name); 

      if (!loaded_file)
         {
         std::cout << "\nFile does not exist, please try again.";
         }
      } while (!loaded_file);

   json file_data = json::parse(loaded_file);
   _class_list = file_data.get<std::vector<CStudent>>();

   std::cout << "\nFile loaded!\n";
   }