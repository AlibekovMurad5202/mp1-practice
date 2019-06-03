#include "ToDoList.h"

ToDoList::ToDoList()
{
    tasks = nullptr;
    count = 0;
}

ToDoList::ToDoList(UINT _count)
{
    count = _count;
    tasks = new Task * [count];
}

ToDoList::~ToDoList()
{
    for (UINT i = 0; i < count; i++)
        if (tasks[i] != nullptr)
            delete tasks[i];
    if (tasks != nullptr)
        delete[] tasks;
    count = 0;
}

void ToDoList::Print(TaskDate _date) const
{
    _date.Print();
    bool smthIs = false;
    std::cout << std::endl;
    for (UINT i = 0; i < count; i++)
    {
        if (tasks[i]->date == _date)
        {
            tasks[i]->PrintTask();
            smthIs = true;
        }
    }
    if (!smthIs)
        std::cout << "You have not tasks for this date! Relax! :)" << std::endl;
}

void ToDoList::Read(const std::string _fileName)
{
    using namespace std;

    ifstream toDoFile;
    toDoFile.open(_fileName);
    if (!toDoFile.is_open())
    {
        toDoFile.close();
        throw ExceptionFileIsNotOpen(__LINE__, __FILE__);
    }

    // char str[255];
     //toDoFile.getline(str, 255);
    std::string str;
    getline(toDoFile, str);
    if (toDoFile) cout << str << endl;

    ios::pos_type currentPos = toDoFile.tellg();

    getline(toDoFile, str, ':');
    UINT _countOfTasks;
    toDoFile >> _countOfTasks;

    toDoFile.seekg(currentPos);

    getline(toDoFile, str);
    cout << str << endl;
    getline(toDoFile, str);
    cout << str << endl;

    count = _countOfTasks;
    tasks = new Task * [count];

    for (UINT i = 0; i < count; i++)
    {
        ios::pos_type startPos = toDoFile.tellg();
        getline(toDoFile, str, '.');
        char s;
        toDoFile.get(s);
        if (s == '\n')
            tasks[i] = new TaskForDay();
        else
            tasks[i] = new TaskForTime();
        toDoFile.seekg(startPos);

        startPos = toDoFile.tellg();
        getline(toDoFile, str, ':');
        tasks[i]->toDo = str;

        //toDoFile.ignore(1); 
        char next_symbol;
        do
        {
            toDoFile >> next_symbol;
        } while ((next_symbol == ' ') || (next_symbol == ':'));
        toDoFile.putback(next_symbol);

        std::string _monthName;
        getline(toDoFile, _monthName, ' ');
        toDoFile >> _monthName;
        tasks[i]->date.setMonth(_monthName);


        int _day;
        toDoFile >> _day;
        tasks[i]->date.setDay(_day);


        do
        {
            toDoFile >> next_symbol;
        } while ((next_symbol == ' ') || (next_symbol == ','));
        toDoFile.putback(next_symbol);


        int _year;
        toDoFile >> _year;
        char next;
        toDoFile >> next;
        if ((next != '.') && (s == '\n'))
        {
            _year *= -1;
            //toDoFile.ignore(2);
        }
        tasks[i]->date.setYear(_year);


        if (s != '\n')
        {
            bool charIsNumber = false;

            do
            {
                toDoFile >> next_symbol;
                if (isdigit(next_symbol))
                    charIsNumber = true;
            } while (!charIsNumber);
            toDoFile.putback(next_symbol);
            charIsNumber = false;


            int _hours;
            toDoFile >> _hours;
            tasks[i]->_time.setHours(_hours);
            toDoFile.ignore(1);
            int _minutes;
            toDoFile >> _minutes;
            tasks[i]->_time.setMinutes(_minutes);


            do
            {
                toDoFile >> next_symbol;
                if (isdigit(next_symbol))
                    charIsNumber = true;
            } while (!charIsNumber);
            toDoFile.putback(next_symbol);
            charIsNumber = false;


            int _duration;
            toDoFile >> _duration;
            tasks[i]->duration = _duration;

            getline(toDoFile, str, '.');
        }

        //toDoFile.ignore(1);

    }

    for (UINT i = 0; i < count; i++)
        tasks[i]->PrintTask();

    char next_symbol;
    do
    {
        toDoFile >> next_symbol;
    } while ((next_symbol == '.') || (next_symbol != '|'));
    toDoFile.putback(next_symbol);

    getline(toDoFile, str);
    cout << str << endl;
    toDoFile.close();
}