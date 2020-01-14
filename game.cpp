#include "game.h"
#include <cstdlib>
#include <windows.h>
// Returns true if s is a number else false
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

Game::Game() : isStarted(false)
{

}

void Game::start()
{
    cout << "1. New Game \n";
    cout << "2. Load Game \n";
    cout << "3. Exit \n";
    isStarted = true;

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
        run();

        break;

    case 2:
        load();

        break;

    case 3:
        quit();

        break;
    case 4:
        settings ();

    default:
        system("cls");
        start();
    }
}

void Game::save()
{

}

void Game::load()
{

}

void Game::run()
{

    Hero *mainHero = heroSetup();
    QList<Event> eventList = readEvents();
    while (true)
    {

        quit();
    }
}

void Game::quit()
{
    cout<<"would you like to save the game?.1-YES,2-NO";


    exit(0);
}

Hero* Game::heroSetup()
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
        cout << " 1. Strenght;" << strenght <<
                "\n 2. Vitality;" << vitality <<
                "\n 3. Agility:" << agility <<
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

    return mainHero;
}
void Game:: settings()
{
    bool number1=true;
    while(number1)
    {

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
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:

        {
            int choosenResolution;

            cout<<"Now you are changing screen resolution\n";
            cout<<"Choose between 1-10 \n ";
            cin>>choosenResolution;
            changeScreenResolution(choosenResolution);
            break;


        }

        case 2:
        {
            int choosenFontScale;
            cout<<"Now you are changing font scale\n";
            cout<<"choose between 1-5 \n";
            cin>>choosenFontScale;
            changeFontScale(choosenFontScale);
            break;
        }

        case 3:
        {
            number1=false;
            break;
        }









        }
    }

}
void Game::changeScreenResolution(int choosenResolution)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    switch(choosenResolution)
    {
    case 1:
    {

        MoveWindow(console, r.left, r.top, 800, 600, TRUE);
        break;
    }

    case 2:
    {

        MoveWindow (console,r.left,r.top,1280,720,TRUE);
        break;
    }
    case 3:
    {

        MoveWindow (console,r.left,r.top,1000,800,TRUE);
        break;
    }
    case 4:
    {

        MoveWindow (console,r.left,r.top,1100,900,TRUE);
        break;
    }
    case 5:
    {

        MoveWindow (console,r.left,r.top,1366,768,TRUE);
        break;
    }
    case 6:
    {

        MoveWindow (console,r.left,r.top,1400,800,TRUE);
        break;
    }
    case 7:
    {
        MoveWindow (console,r.left,r.top,1920,1080,TRUE);
        break;
    }
    case 8:
    {

        MoveWindow (console,r.left,r.top,1600,900,TRUE);
        break;
    }
    case 9:
    {

        MoveWindow (console,r.left,r.top,800,500,TRUE);
        break;
    }
    case 0:
    {

        MoveWindow (console,r.left,r.top,640,480,TRUE);
        break;
    }


    }
}
void Game::changeFontScale(int choosenFontScale)
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
    switch (choosenFontScale){
    case 1:
    {
        lpConsoleCurrentFontEx->dwFontSize.X = 15;
        lpConsoleCurrentFontEx->dwFontSize.Y = 15;
        SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);

        MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
        break;
    }

    case 2:
    {
      lpConsoleCurrentFontEx->dwFontSize.X = 20;
      lpConsoleCurrentFontEx->dwFontSize.Y = 20;
      SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
      MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
      break;
        }
    case 3:
    {
      lpConsoleCurrentFontEx->dwFontSize.X = 25;
      lpConsoleCurrentFontEx->dwFontSize.Y = 25;
      SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
      MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
      break;
    }
    case 4:
    {
      lpConsoleCurrentFontEx->dwFontSize.X = 30;
      lpConsoleCurrentFontEx->dwFontSize.Y = 30;
      SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
      MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
      break;
    }
    case 5:
    {
      lpConsoleCurrentFontEx->dwFontSize.X = 35;
      lpConsoleCurrentFontEx->dwFontSize.Y = 35;
      SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
      MoveWindow (console,r.left,r.top,consoleWindowWidth,consoleWindowHeight,TRUE);
      break;
    }
     }
    }



QList<Event> Game::readEvents()
{
    QList<Event> eventlist;
    QString line;

    QFile eventFile("C:/Users/Adam/Desktop/events.txt");

    QTextStream in(&eventFile);
    while(!in.atEnd())
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
    eventFile.close();

    return eventlist;
}
