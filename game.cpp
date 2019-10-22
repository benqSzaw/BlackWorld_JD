#include "game.h"

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

}

void Game::load()
{

}

void Game::run()
{
    heroSetup();
    Hero *mainHero = heroSetup();
    QList<Event> eventList = readEvents();
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
