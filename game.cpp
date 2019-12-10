#include "game.h"
#include "event.h"



// Returns true if s is a number else false
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

void Game::showEvent(Event event)
{
    cout << event.description.toStdString() << endl;
    cout <<"1. "<< event.option1.toStdString() << endl;
    cout <<"2. "<< event.option2.toStdString() << endl;
    cout <<"3. "<< event.option3.toStdString() << endl;


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
        currentEventId = 0;
        mainHero = heroSetup();
        run();
        break;

    case 2:
        mainHero = new Hero;
        load();
        system("cls");
        run();
        break;

    case 3:
        exit();
        break;

    default:
        system("cls");
        start();
    }
}

void Game::exit()
{

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
        currentEventId = in.readLine().toInt() -1;

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

    while(currentEventId <= eventList.last().id)   // main game loop
    {
        showEvent(eventList.at(currentEventId));
        currentEventId++;

        options();

        cin >>choice;
        switch(choice)
        {
        case '1':
        {
            //TO DO: Showing 1st consequence
            break;
        }
        case '2':
        {
            //TO DO: Showing 2nd consequence
            break;
        }
        case '3':
        {
            //TO DO: Showing 3rd consequence
            break;
        }
        case 's':
        {
            save(); //TO DO: Saving game
        }
        case 'l':
        {
            //TO DO: Loading a save
        }
        case 'q':
        {
            //TO DO: Quiting from a game
        }
        case 'o':
        {
            //TO DO: Showing options
        }
        default:
        {
            system("cls");
            cout<<"wrong choice"<<endl;
            currentEventId--;
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

void Game::options()
{
    COORD lol = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    COORD coord;
    coord.X = 0;
    coord.Y = rows -1;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord);
    cout << "Esc to show options";
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), lol);
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

    return mainHero;
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
