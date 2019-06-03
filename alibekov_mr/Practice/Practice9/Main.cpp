#include "ToDoList.h"

int main()
{
    try
    {
        std::ofstream newToDoFile("example.txt");
        newToDoFile << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TO DO LIST ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
        newToDoFile << " Number of tasks: 4\n";
        newToDoFile << "|---------------------------- TASKS -------------------------------------------|\n";
        newToDoFile << " Buy a movie ticket#1! : April 21, 2019.\n";
        newToDoFile << " Buy a movie ticket#2! : April 21, 2019.\n";
        newToDoFile << " Go to the movie! : May 1, 2019. Begins at 17:45. Duration is 185 minutes.\n";
        newToDoFile << " To do smth in the past! : June 11, 3011 BC.\n";
        newToDoFile << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|";
        newToDoFile.close();
    }
    catch (ExceptionFileIsNotOpen const& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Reason: " << e.why() << std::endl;
        std::cout << "errorLine: " << e.errorLine() << std::endl;
        std::cout << "errorFile:" << e.errorFile() << std::endl;
    }
    do
    {
        bool wantToSeeExample = true;
        try
        {
            std::cout << "Do you want to see the example?  1 - Yes.  0 - No.\n";
            std::cin >> wantToSeeExample;
            if (wantToSeeExample)
            {
                ToDoList td_example;
                td_example.Read("example.txt");
                std::cout << std::endl;
                td_example.Print(TaskDate(21, 4, 2019));
                std::cout << std::endl;
                td_example.Print(TaskDate(1, 5, 2019));
            }
            else
            {
                std::cout << "Enter file's name: ";
                std::string fileName;
                std::cin >> fileName;
                ToDoList td;
                td.Read(fileName);
                bool wantToSeeTasksForDate = false;

                std::cout << "Do you want to see tasks for a certain date?  1 - Yes.  0 - No.\n";
                std::cin >> wantToSeeTasksForDate;
                while (wantToSeeTasksForDate)
                {
                    std::cout << std::endl << "Enter date :";
                    int d, m, y;
                    std::cin >> d >> m >> y;
                    td.Print(TaskDate(d, m, y));
                    std::cout << "\nDo you want to see tasks for an another date?  1 - Yes.  0 - No.\n";
                    std::cin >> wantToSeeTasksForDate;
                }
            }
        }
        catch (ExceptionOutOfRange const& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Reason: " << e.why() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile:" << e.errorFile() << std::endl;

            std::cout << "\nAn error has occurred! ";
        }
        catch (ExceptionFileIsNotOpen const& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Reason: " << e.why() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile:" << e.errorFile() << std::endl;

            std::cout << "\nAn error has occurred! ";
        }
        catch (Exception404 const& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Reason: " << e.why() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile:" << e.errorFile() << std::endl;

            std::cout << "\nAn error has occurred! ";
        }
        catch (ExceptionTaskUndefined const& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Reason: " << e.why() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile:" << e.errorFile() << std::endl;

            std::cout << "\nAn error has occurred! ";
        }
        catch (ExceptionTaskDateUndefined const& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Reason: " << e.why() << std::endl;
            std::cout << "errorLine: " << e.errorLine() << std::endl;
            std::cout << "errorFile:" << e.errorFile() << std::endl;

            std::cout << "\nAn error has occurred! ";
        }
        catch (...)
        {
            std::cout << std::endl << "I don't know what was happened. I'm scared. \
      I cann't fix it. I'm just a computer. :(" << std::endl;

            std::cout << "\nAn error has occurred! ";
        }

        std::cout << "Do you want to exit the program?  1 - Yes.  0 - No.\n";
        bool wantToExit = true;
        std::cin >> wantToExit;
        if (wantToExit)
            break;
    } while (1);

    system("pause");
    return 0;
}