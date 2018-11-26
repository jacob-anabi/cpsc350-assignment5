/**
 * @author Jacob Anabi
 * @date 2018-11-22
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 5 - Registrar Office Database
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Database.h"

int main(int argc, char** argv)
{
    srand(static_cast<unsigned>(time(nullptr)));
    Database* database = new Database();
    database->deserilialize();
    std::string input;

    while (true)
    {
        std::cout << "Enter command (type 'help' for list of commands): ";
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        if (input == "ps")
        {
            database->printStudents();
        }
        else if (input == "pf")
        {
            database->printFaculty();
        }
        else if (input == "s")
        {
            int id = 0;
            bool id_good = false;
            while (!id_good)
            {
                std::cout << "\nEnter student id: ";
                std::cin >> id;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid student id" << std::endl;
                }
                else
                {
                    id_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            database->displayStudent(id);
        }
        else if (input == "f")
        {
            int id = 0;
            bool id_good = false;
            while (!id_good)
            {
                std::cout << "\nEnter faculty id: ";
                std::cin >> id;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid faculty id" << std::endl;
                }
                else
                {
                    id_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            database->displayFaculty(id);
        }
        else if (input == "sa")
        {
            database->printStudents();
            int id = 0;
            bool id_good = false;
            while (!id_good)
            {
                std::cout << "\nEnter student id: ";
                std::cin >> id;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid student id" << std::endl;
                }
                else
                {
                    id_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            database->printAdviser(id);
        }
        else if (input == "fa")
        {
            database->printFaculty();
            int id = 0;
            bool id_good = false;
            while (!id_good)
            {
                std::cout << "\nEnter faculty id: ";
                std::cin >> id;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid faculty id" << std::endl;
                }
                else
                {
                    id_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            database->printAdvisees(id);
        }
        else if (input == "as")
        {
            database->printFaculty();
            database->addStudent();
        }
        else if (input == "ds")
        {
            database->printStudents();
            int id = 0;
            bool id_good = false;
            while (!id_good)
            {
                std::cout << "\nEnter student id: ";
                std::cin >> id;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid student id" << std::endl;
                }
                else
                {
                    id_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            database->removeStudent(id);
        }
        else if (input == "af")
        {
            database->addFaculty();
        }
        else if (input == "df")
        {
            database->printFaculty();
            int id = 0;
            bool id_good = false;
            while (!id_good)
            {
                std::cout << "\nEnter faculty id: ";
                std::cin >> id;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid faculty id" << std::endl;
                }
                else
                {
                    id_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            database->removeFaculty(id);
        }
        else if (input == "csa")
        {
            database->printStudents();
            database->printFaculty();
            int sId = 0;
            bool sId_good = false;
            while (!sId_good)
            {
                std::cout << "\nEnter student id: ";
                std::cin >> sId;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid student id" << std::endl;
                }
                else
                {
                    sId_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            int aId = 0;
            bool aId_good = false;
            while (!aId_good)
            {
                std::cout << "\nEnter faculty id: ";
                std::cin >> aId;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid faculty id" << std::endl;
                }
                else
                {
                    aId_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            database->changeAdviser(sId, aId);
        }
        else if (input == "raf")
        {
            database->printFaculty();
            database->printStudents();
            int aId = 0;
            bool aId_good = false;
            while (!aId_good)
            {
                std::cout << "\nEnter faculty id: ";
                std::cin >> aId;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid faculty id" << std::endl;
                }
                else
                {
                    aId_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            int sId = 0;
            bool sId_good = false;
            while (!sId_good)
            {
                std::cout << "\nEnter student id: ";
                std::cin >> sId;
                if (std::cin.fail())
                {
                    std::cout << "\nInvalid student id" << std::endl;
                }
                else
                {
                    sId_good = true;
                }
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            database->removeAdvisee(sId, aId);
        }
        else if (input == "rb")
        {
            database->rollback();
        }
        else if (input == "q")
        {
            database->exit();
            break;
        }
        else if (input == "help")
        {
            std::cout << "-------------------------------------------------------------------------" << '\n'
            << "ps - print student information" << '\n'
            << "pf - print faculty information" << '\n'
            << "s - print specific student information given student id" << '\n'
            << "f - print specific faculty information given faculty id" << '\n'
            << "sa - print specific student adviser given student id" << '\n'
            << "fa - print specific faculty advisees given faculty id" << '\n'
            << "as - add student" << '\n'
            << "ds - delete student" << '\n'
            << "af - add faculty member" << '\n'
            << "df - delete faculty member" << '\n'
            << "csa - change student adviser given student id and new adviser id" << '\n'
            << "raf - remove an advisee from faculty member given faculty memeber id and advisee id" << '\n'
            << "rb - rollback" << '\n'
            << "q - exit" << '\n'
            << "-------------------------------------------------------------------------" << std::endl;
        }
        else
        {
            std::cout << "Not a valid option" << std::endl;
        }
    }
}