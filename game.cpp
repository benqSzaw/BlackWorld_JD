#include "game.h"
#include "event.h"
#include <QFile>
#include <iostream>

#include <cstdlib>
#include <Windows.h>
using namespace std;

// Returns true if s is a number else false
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

void Game::start()
{
    cout << "1. New Game \n";
    cout << "2. Load Game \n";
    cout << "3. Settings \n";
    cout << "4. Exit \n";
    string choice;
    cin >> choice;
    if (!isNumber(choice))
    {
        system("cls");
        start();
    }

    switch (stoi(choice))
    {
    case 1:
        currentEventId = 0;
        isStarted = true;
        mainHero = heroSetup();
        run();
        break;

    case 2:
        mainHero = new Hero;
        isStarted = true;
        load();
        system("cls");
        run();
        break;

    case 3:
        options();

    case 4:
        system("cls");
        exit (EXIT_FAILURE);
        break;

    default:
        system("cls");
        start();
    }
}

void Game::showEvent(Event event)
{
    cout << event.description.toStdString() << endl;
    cout <<"1. "<< event.option1.toStdString() << endl;
    cout <<"2. "<< event.option2.toStdString() << endl;
    cout <<"3. "<< event.option3.toStdString() << endl;
}

void Game::executeEvent(QString cons)
{
    QStringList list1 = cons.split(";");
    for(int i=0;i<list1.length();i++)
    {
        QStringList list2 = list1.at(i).split(":");
        QString attr = list2.at(0);
        QString value = list2.at(1);
        if(attr == "nextE")
        {
            currentEventId = value.toInt() -1;
        }
        else
        {
            changeHeroStats(attr , value);
        }
    }
}

void Game::changeHeroStats(QString attr , QString value)
{
    if(attr == "hp")
    {
        mainHero->hp += value.toInt();
    }
    else if(attr == "stamina")
    {
        mainHero->stamina += value.toInt();
    }
    else if(attr == "food")
    {
        mainHero->food += value.toInt();
    }
    else if(attr == "gold")
    {
        mainHero->gold += value.toInt();
    }
    else if(attr == "strenght")
    {
        mainHero->strenght += value.toInt();
    }
    else if(attr == "vitality")
    {
        mainHero->vitality += value.toInt();
    }
    else if(attr == "agility")
    {
        mainHero->agility += value.toInt();
    }
}

Game::Game() : isStarted(false)
{

}

void Game::whenHeraDead() //TODO: Beniamin pomyslec nad koncecja...
{
    isHeroDead = (mainHero->hp > 0);

    if(isHeroDead == 0)
    {
        system("cls");
        cout << " YOU DIED";
        Sleep(5000);
        system("cls");
        cout << "1. New Game" << endl
             << "2. Load" << endl
             << "3. Quit" << endl;

        char sw;
        cin >>sw;
        switch(sw)
        {
        case '1' :
        {
            currentEventId = 0;
            mainHero = heroSetup();
            run();
            break;
        }
        case '2' :
        {
            load();
            break;
        }
        case '3' :
        {
            exitProgramm();
            break;
        }
        default :
        {
            system("cls");
            whenHeraDead();
            break;
        }
        }
    }
}


void Game::showStats()
{
    system("cls");
    cout << "Name:  " <<   mainHero->name
         << endl << endl

         << "Hp:  " <<  mainHero->hp << " / " << mainHero->maxHp
         << endl << endl

         << "Stamina:  " << mainHero->stamina << " / " << mainHero->maxStamina
         << endl << endl

         << "Strenght:  " << mainHero->strenght
         << endl
         << "Vitality:  " <<   mainHero->vitality
         << endl
         << "Agility:  " <<   mainHero->agility
         << endl << endl

         << "Food:  " <<   mainHero->food
         << endl
         << "Gold:  " <<   mainHero->gold
         << endl << endl

         << "1.Back to game" << endl;

    char a;
    cin >> a;
    switch (a)
    {
    case '1':
    {
        run();
        break;
    }
    default:
    {
        showStats();
        break;
    }
    }
}

void Game::exitProgramm()
{
    system("cls");
    cout << "Do you want save game?" << endl
         << "1. Yes" << endl
         << "2. No" << endl
         << endl;
    char sw;
    cin >>sw;
    if(sw == '1')
    {
        save();
        system("cls");
        exit (EXIT_FAILURE);
    }
    else if(sw == '2')
    {
        system("cls");
        exit (EXIT_FAILURE);
    }
    else
    {
        exitProgramm();
    }
}

void Game::save()
{
    ofstream myfile;
    myfile. open ("save.txt");

    myfile <<  mainHero->name << endl <<

               mainHero->hp << endl <<
               mainHero->maxHp << endl <<

               mainHero->stamina << endl <<
               mainHero->maxStamina << endl <<

               mainHero->food << endl <<
               mainHero->gold << endl <<

               mainHero->strenght << endl <<
               mainHero->vitality << endl <<
               mainHero->agility << endl <<
               currentEventId << endl

            << endl;

    myfile.close();
}

void Game::load()
{
    QFile inputFile("save.txt");
    string name;
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&inputFile);

        mainHero->name = in.readLine().toStdString();

        mainHero->hp = in.readLine().toInt();
        mainHero->maxHp = in.readLine().toInt();

        mainHero->stamina = in.readLine().toInt();
        mainHero->maxStamina = in.readLine().toInt();

        mainHero-> food = in.readLine().toInt();
        mainHero->gold = in.readLine().toInt();

        mainHero->strenght = in.readLine().toInt();
        mainHero->vitality = in.readLine().toInt();
        mainHero->agility = in.readLine().toInt();
        currentEventId = in.readLine().toInt();

        inputFile.close();
    }
}

void Game::run()
{
    QList<Event> eventList = readEvents();
    char choice;
    if(eventList.empty())
    {
        cout <<"error occured because of list of events is empty"<<endl;
        return;
    }

    while(currentEventId < eventList.size())   // main game loop
    {
        system("cls");
        Event currentEvent = eventList.at(currentEventId);
        showEvent(currentEvent);
        bottomText();
        whenHeraDead();
        cin >>choice;
        switch(choice)
        {
        case '1':
        {
            //TO DO: Showing 1st consequence
            executeEvent(currentEvent.cons1);
            currentEventId++;
            break;
        }
        case '2':
        {
            //TO DO: Showing 2nd consequence
            executeEvent(currentEvent.cons2);
            currentEventId++;
            break;
        }
        case '3':
        {
            //TO DO: Showing 3rd consequence
            executeEvent(currentEvent.cons3);
            currentEventId++;
            break;
        }
        case 'E':
        case 'e':
        {
            inGameMenu();
            break;
        }
        case 'S':
        case 's':
        {
            showStats();
            break;
        }
        default:
        {
            break;
        }
        }
    }
}

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }

}

void Game::bottomText()
{
    COORD currentCORD = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    COORD coord;
    coord.X = 0;
    coord.Y = rows - 1;

    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord);

    cout << "[E]scape  [S]tats";

    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), currentCORD);
}

void Game::startLogo()
{
    cout <<
            " _   _   _   _+       |                                 " << endl <<
            "/_`-'_`-'_`-'_|  \\+/  |                       /-|      " << endl <<
            "\\_`M'_`D'_`C'_| _<=>_ |                     ___  \\    " << endl <<
            "  `-' `-' `-' 0/ \\ / o=o     ______________|  /|--]    " << endl <<
            "              \\/\\ ^ /`0                    | / |__|   " << endl <<
            "              | /_^_\\                       \\ /.\\ |  " << endl <<
            "              | || ||                        '|| ||     " << endl <<
            "            __|_d|_|b__                      <_'<_'     " << endl;

    cout << endl << endl<< "Press any key to start...";
    _getch();
    system("cls");
}

Hero *Game::heroSetup()
{
    system("cls");

    cout << "Creating hero...\n";
    cout << "Your name: ";

    string nameHero;
    cin >> nameHero;

    int strenght = 0;
    int vitality = 0;
    int agility = 0;
    int number = 0;

    while(number < 10)
    {
        system("cls");

        cout << "Distribute 10 skill point\n\n";
        cout << " 1. Strenght: " << strenght <<
                "\n 2. Vitality: " << vitality <<
                "\n 3. Agility: " << agility <<
                "\n\n";

        string choice;
        cin >> choice;
        if (!isNumber(choice))
        {
            continue;
        }

        switch (stoi(choice))
        {
        case 1:
            strenght++;
            break;
        case 2:
            vitality++;
            break;
        case 3:
            agility++;
            break;
        default:
            number--;
        }
        number++;
    }
    system("cls");

    cout << "Your hero\n\n";
    cout << "Name: " << nameHero << "\n\n";
    cout << "Skills: \n\n";
    cout << " Strenght;" << strenght << "\n Vitality;" << vitality << "\n Agility:" << agility << "\n\n";

    Hero *mainHero = new Hero(nameHero, strenght, agility, vitality);

    cout << "Press any key to start your adventure";
    _getch();
    return mainHero;
}
void Game::inGameMenu()
{
    system("cls");
    cout << "1. Resume" << endl
         << "2. Load" << endl
         << "3. Save" << endl
         << "4. Options" << endl
         << "5. Exit" << endl;

    char sw;
    cin >>sw;
    switch(sw)
    {
    case '1' :
    {
        run();
        break;
    }
    case '2' :
    {
        load();
        break;
    }
    case '3' :
    {
        save();
        break;
    }
    case '4' :
    {
        options();
        break;
    }
    case '5' :
    {
        exitProgramm();
        break;
    }
    default:
    {
        inGameMenu();
        break;
    }
    }
}

void Game::options()
{
    system("cls");
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
    int consoleWindowWidth=r.right-r.left;
    int consoleWindowHeight=r.bottom-r.top;
    //cout<<"top: "<< r.top << "left: " << r.left << "right: " << r.right << "bottom: " << r.bottom << "\n";
    cout << "Settings"  "\n";

    cout <<"---------------------------------\n\n";
    cout << "Screen scale:             " <<consoleWindowWidth<<"x"<<consoleWindowHeight<< "\n\n";
    cout << "Font size:                "<<lpConsoleCurrentFontEx->dwFontSize.X<< "\n\n\n";
    cout << "1.Change screen scale " << "\n";
    cout << "2.Change font scale" << "\n";
    cout << "3.Back to main menu" << "\n"           ;
    char choice;
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case '1':
    {
        char choosenResolution;

        cout<<"Now you are changing screen resolution\n";
        cout<<"Choose between 1-10 \n ";
        cin>>choosenResolution;
        changeScreenResolution(choosenResolution);
        break;
    }
    case '2':
    {
        char choosenFontScale;

        cout<<"Now you are changing font scale\n";
        cout<<"choose between 1-5 \n";
        cin>>choosenFontScale;
        changeFontScale(choosenFontScale);
        break;
    }
    case '3':
    {
        if(!isStarted)
        {
            start();
        }
        run();
        break;
    }
    default:
    {
        options();
    }
    }
    options();
}


void Game::changeScreenResolution(char choosenResolution)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    switch(choosenResolution)
    {
    case '1':
    {
        MoveWindow(console, r.left, r.top, 800, 600, TRUE);
        break;
    }

    case '2':
    {
        MoveWindow (console,r.left,r.top,1280,720,TRUE);
        break;
    }
    case '3':
    {
        MoveWindow (console,r.left,r.top,1000,800,TRUE);
        break;
    }
    case '4':
    {

        MoveWindow (console,r.left,r.top,1100,900,TRUE);
        break;
    }
    case '5':
    {
        MoveWindow (console,r.left,r.top,1366,768,TRUE);
        break;
    }
    case '6':
    {

        MoveWindow (console,r.left,r.top,1400,800,TRUE);
        break;
    }
    case '7':
    {
        MoveWindow (console,r.left,r.top,1920,1080,TRUE);
        break;
    }
    case '8':
    {
        MoveWindow (console,r.left,r.top,1600,900,TRUE);
        break;
    }
    case '9':
    {
        MoveWindow (console,r.left,r.top,800,500,TRUE);
        break;
    }
    case '0':
    {
        MoveWindow (console,r.left,r.top,640,480,TRUE);
        break;
    }
    default:
    {
        return;
    }

    }
}
void Game::changeFontScale(char choosenFontScale)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    int consoleWindowWidth=r.right-r.left;
    int consoleWindowHeight=r.bottom-r.top;
    switch (choosenFontScale)
    {
    case '1':
    {
        lpConsoleCurrentFontEx->dwFontSize.X = 15;
        lpConsoleCurrentFontEx->dwFontSize.Y = 15;
        SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);

        MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
        break;
    }
    case '2':
    {
        lpConsoleCurrentFontEx->dwFontSize.X = 20;
        lpConsoleCurrentFontEx->dwFontSize.Y = 20;
        SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
        MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
        break;
    }
    case '3':
    {
        lpConsoleCurrentFontEx->dwFontSize.X = 25;
        lpConsoleCurrentFontEx->dwFontSize.Y = 25;
        SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
        MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
        break;
    }
    case '4':
    {
        lpConsoleCurrentFontEx->dwFontSize.X = 30;
        lpConsoleCurrentFontEx->dwFontSize.Y = 30;
        SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
        MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
        break;
    }
    case '5':
    {
        lpConsoleCurrentFontEx->dwFontSize.X = 35;
        lpConsoleCurrentFontEx->dwFontSize.Y = 35;
        SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
        MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
        break;
    }
    default:
    {
        return;
    }
    }
}



QList<Event> Game::readEvents()
{
    QList<Event> eventlist;
    QFile inputFile("events.txt");
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            Event e;

            e.id = in.readLine().toInt();
            e.type = in.readLine().toInt();
            e.description = in.readLine();
            e.option1 = in.readLine();
            e.option2 = in.readLine();
            e.option3 = in.readLine();
            e.cons1 = in.readLine();
            e.cons2 = in.readLine();
            e.cons3 = in.readLine();
            in.readLine();

            eventlist.append(e);
        }
        inputFile.close();
    }
    return eventlist;
}
