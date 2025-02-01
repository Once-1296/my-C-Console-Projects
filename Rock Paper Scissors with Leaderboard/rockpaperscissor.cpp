#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;
class Data
{
public:
    vector<string> rowData;
};
class Accounts
{
public:
    int pssn;
    string fn;
    void updateacc(string filename, string pss)
    {
        fn = filename;
        ifstream inputFile(fn);
        vector<Data> dataVec;
        // Read data from file
        string line, word;
        getline(inputFile, line);
        int counter = 0;
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            counter++;
        }
        vector<string> columnme;
        inputFile.seekg(0, ios::beg);
        getline(inputFile, line);
        stringstream obj2(line);
        counter = 0;
        while (getline(obj2, word, ','))
        {
            columnme.push_back(word);
            counter++;
        }
        while (getline(inputFile, line))
        {
            Data data;
            // Parse line into columns
            stringstream obj(line);
            while (getline(obj, word, ','))
            {
                data.rowData.push_back(word);
            }
            dataVec.push_back(data);
        }
        int i = 1, j = 0;
        int rentry = check_username(pss);
        string passw;
        int cn = 7;
        string tempw, templ, tempt, tempcc;
        float tempaw, tempal, tempat, tempacc;
        tempw = dataVec[rentry - 1].rowData[cn - 5];
        templ = dataVec[rentry - 1].rowData[cn - 4];
        tempt = dataVec[rentry - 1].rowData[cn - 3];
        tempaw = stof(tempw);
        tempal = stof(templ);
        tempat = stof(tempt);
        tempacc = ((tempaw) / (tempal + tempat + tempaw)) * 100;
        tempcc = to_string(tempacc);
        dataVec[rentry - 1].rowData[cn - 1] = tempcc;
        int cc = countcol(fn);
        int rr = countline(fn);
        ofstream filewrite(fn);
        for (int i = 0; i < cc; i++)
        {
            if (i == cc - 1)
            {
                filewrite << columnme[i] << endl;
                break;
            }
            filewrite << columnme[i] << ",";
        }

        for (int i = 0; i < rr; i++)
        {
            for (int j = 0; j < cc; j++)
            {
                if (j == cc - 1)
                {
                    filewrite << dataVec[i].rowData[j] << endl;
                    break;
                }
                filewrite << dataVec[i].rowData[j] << ",";
            }
        }

        filewrite.close();
    }
    void update(string filename, string pss, int con, int impr)
    {
        fn = filename;
        ifstream inputFile(fn);
        vector<Data> dataVec;
        // Read data from file
        string line, word;
        getline(inputFile, line);
        int counter = 0;
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            counter++;
        }
        vector<string> columnme;
        inputFile.seekg(0, ios::beg);
        getline(inputFile, line);
        stringstream obj2(line);
        counter = 0;
        while (getline(obj2, word, ','))
        {
            columnme.push_back(word);
            counter++;
        }
        while (getline(inputFile, line))
        {
            Data data;
            // Parse line into columns
            stringstream obj(line);
            while (getline(obj, word, ','))
            {
                data.rowData.push_back(word);
            }
            dataVec.push_back(data);
        }
        int i = 1, j = 0;
        int rentry = check_username(pss);
        string passw;
        int cn = con;
        string temp;
        int tempa;
        temp = dataVec[rentry - 1].rowData[cn - 1];
        tempa = stoi(temp);
        tempa += impr;
        temp = to_string(tempa);
        dataVec[rentry - 1].rowData[cn - 1] = temp;
        int cc = countcol(fn);
        int rr = countline(fn);
        ofstream filewrite(fn);
        for (int i = 0; i < cc; i++)
        {
            if (i == cc - 1)
            {
                filewrite << columnme[i] << endl;
                break;
            }
            filewrite << columnme[i] << ",";
        }

        for (int i = 0; i < rr; i++)
        {
            for (int j = 0; j < cc; j++)
            {
                if (j == cc - 1)
                {
                    filewrite << dataVec[i].rowData[j] << endl;
                    break;
                }
                filewrite << dataVec[i].rowData[j] << ",";
            }
        }

        filewrite.close();
    }
    int countline(string fn)
    {
        ifstream file1(fn);
        string line, word;
        int counter = 0, count2 = 0;
        while (getline(file1, line))
        {
            counter++;
        }
        counter--;
        file1.close();
        return counter;
    }
    int countcol(string fn)
    {
        int counter = 0;
        string word, line;
        fstream file(fn, ios::in);
        getline(file, line);
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            counter++;
        }
        file.close();
        return counter;
    }
    int check_pass(string pass)
    {
        int j = 0;
        string word, line;
        vector<string> cnames;
        fstream file("users.txt", ios::in);
        getline(file, line);
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            cnames.push_back(word);
            j++;
        }
        int passnum;
        for (int i = 0; i < countcol("users.txt"); i++)
        {
            if (cnames[i] == "pass")
            {
                passnum = i;
            }
        }
        fflush(stdout);
        int count = 0;
        while (getline(file, line))
        {
            stringstream obj2(line);
            count = 0;
            while (getline(obj2, word, ','))
            {
                if (count == passnum)
                {
                    if (pass == word)
                    {
                        return 1;
                    }
                }
                count++;
            }
        }
        return 0;
    }
    int check_username(string username)
    {
        int j = 0, linenum = 0;
        string word, line;
        vector<string> cnames;
        fstream file("users.txt", ios::in);
        getline(file, line);
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            cnames.push_back(word);
            j++;
        }
        int usernamenum;
        for (int i = 0; i < countcol("users.txt"); i++)
        {
            if (cnames[i] == "username")
            {
                usernamenum = i;
            }
        }
        fflush(stdout);
        int count = 0;
        while (getline(file, line))
        {
            linenum++;
            stringstream obj2(line);
            count = 0;
            while (getline(obj2, word, ','))
            {
                if (count == usernamenum)
                {
                    if (username == word)
                    {
                        return linenum;
                    }
                }
                count++;
            }
        }
        return 0;
    }
    void signup()
    {
        system("cls");
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "\t\t\tSIGNUP PAGE\t\t\t" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        vector<string> userdet;
        bool signup = false;
        int j = 0;
        string word, line;
        vector<string> cnames;
        fstream file("users.txt", ios::in);
        getline(file, line);
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            cnames.push_back(word);
            if (cnames[j] == "pass")
            {
                pssn = j;
            }
            j++;
        }
        file.close();
        char c = 'n';
        string temp;
        do
        {
            c = 'n';
            for (int i = 0; i < countcol("users.txt"); i++)
            {
                if (i <= pssn)
                {
                    std::cout << "Enter your " << cnames[i] << " : ";
                    std::cin >> temp;
                    userdet.push_back(temp);
                }
                else
                {
                    userdet.push_back("0");
                }
            }
            int passnum, usernamenum;
            for (int i = 0; i < countcol("users.txt"); i++)
            {
                if (cnames[i] == "pass")
                {
                    passnum = i;
                }
            }
            for (int i = 0; i < countcol("users.txt"); i++)
            {
                if (cnames[i] == "username")
                {
                    usernamenum = i;
                }
            }
            if (check_pass(userdet[passnum]) || check_username(userdet[usernamenum]))
            {
                std::cout << "Password/username is already in use. Would you like to try again? [y/n]";
                std::cin >> c;
                int tmp = userdet.size();
                for (int k = 0; k < tmp; k++)
                {
                    userdet.pop_back();
                }
            }
            else
            {
                fstream file2("users.txt", ios::app);
                for (int i = 0; i < countcol("users.txt"); i++)
                {
                    if (i == countcol("users.txt") - 1)
                    {
                        file2 << userdet[i] << endl;
                        break;
                    }
                    file2 << userdet[i] << ",";
                }
                signup = true;
            }
        } while (c == 'y' || c == 'Y');
        if (signup)
        {
            char cha = 'n';
            std::cout << "Would you like to login?[y/n]";
            std::cin >> cha;
            if (cha == 'y' || cha == 'Y')
            {
                login();
            }
            else
            {
                welcomepage();
            }
            
        }
    }
    string password, username;
    void login()
    {
        system("cls");
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "\t\t\tLOGIN PAGE\t\t\t" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        char c = 'n';
        bool dashboard = false;
        do
        {
            c = 'n';
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            if (check_pass(password) && check_username(username))
            {
                std::cout << "Login successful!Press any character key and enter to continue.";
                dashboard = true;
            }
            else
            {
                std::cout << "Login fail! Try again [t] or got to signup page[s] or none.";
                std::cin >> c;
            }
            if (c == 's' || c == 'S')
            {
                signup();
            }
        } while (c == 't' || c == 'T');
        if (dashboard)
        {
            char ch;
            std::cin >> ch;
            Dashboard();
        }
        else
        {
            welcomepage();
        }
        
    }
    void Dashboard()
    {
        int num;
        do
        {
            system("cls");
            std::cout << "--------------------------------------------------------------------------------------------" << endl;
            std::cout << "--------------------------------------------------------------------------------------------" << endl;
            std::cout << "\t\t\tDASHBOARD\t\t\t" << endl;
            std::cout << "--------------------------------------------------------------------------------------------" << endl;
            std::cout << "--------------------------------------------------------------------------------------------" << endl;
            cout << "1.play game\n2.see stats\n3.sign out";
            cin >> num;
        } while (num != 1 && num != 2 && num != 3);
        switch (num)
        {
        case 1:
            game();
            break;
        case 2:
            showdet();
            break;
        case 3:
            welcomepage();
            break;
        }
    }
    void showdet()
    {
        char c;
        do
        {
            system("cls");
            std::cout << "--------------------------------------------------------------------------------------------" << endl;
            std::cout << "--------------------------------------------------------------------------------------------" << endl;
            std::cout << "\t\t\tSHOWING DETAILS\t\t\t" << endl;
            std::cout << "--------------------------------------------------------------------------------------------" << endl;
            std::cout << "--------------------------------------------------------------------------------------------" << endl;
            int lnum = check_username(username);
            string word, line;
            vector<string> cnames;
            fstream file("users.txt", ios::in);
            getline(file, line);
            stringstream obj(line);
            int count = 0;
            while (getline(obj, word, ','))
            {
                cnames.push_back(word);
                count++;
            }
            count = 0;
            int ij = 0;
            while (getline(file, line))
            {
                stringstream obj2(line);
                count++;
                if (count == lnum)
                {
                    while (getline(obj2, word, ','))
                    {
                        cout << cnames[ij] << " : " << word << endl;
                        ij++;
                    }
                }
            }
            cout << "would you like to go back[y/n]?";
            cin >> c;
        } while (c != 'y' && c != 'Y');
        Dashboard();
    }
    void game()
    {
        int win = 0, lose = 0, tie = 0;
        srand(time(NULL));
        char rsp[3];
        rsp[0] = 'r';
        rsp[1] = 'p';
        rsp[2] = 's';
        char userchoice;
        char compchoice;
        bool again = true;
        char c;
        do
        {
            do
            {
                system("cls");
                std::cout << "--------------------------------------------------------------------------------------------" << endl;
                std::cout << "--------------------------------------------------------------------------------------------" << endl;
                std::cout << "\t\t\tGAME PAGE\t\t\t" << endl;
                std::cout << "--------------------------------------------------------------------------------------------" << endl;
                std::cout << "--------------------------------------------------------------------------------------------" << endl;
                cout << "Rock: r \t Scissors: s \t Paper: p" << endl;
                cout << "Enter your choice correctly";
                cin >> userchoice;
            } while (userchoice != 'r' && userchoice != 's' && userchoice != 'p' && userchoice != 'R' && userchoice != 'S' && userchoice != 'P');
            int i = (rand() % 3);
            compchoice = rsp[i];
            if ((userchoice == 'r' || userchoice == 'R') && (compchoice == 'r' || compchoice == 'R'))
            {
                cout << "Both chose rock.\n";
                cout << "It is a tie.\n";
                tie++;
            }
            if ((userchoice == 's' || userchoice == 'S') && (compchoice == 's' || compchoice == 'S'))
            {
                cout << "Both chose scissors.\n";
                cout << "It is a tie.\n";
                tie++;
            }
            if ((userchoice == 'p' || userchoice == 'P') && (compchoice == 'p' || compchoice == 'P'))
            {
                cout << "Both chose paper.\n";
                cout << "It is a tie.\n";
                tie++;
            }
            if ((userchoice == 'r' || userchoice == 'R') && (compchoice == 's' || compchoice == 'S'))
            {
                cout << "You chose rock. Computer chose scissors.";
                cout << "You win. Congratulations!\n";
                win++;
            }
            if ((userchoice == 'r' || userchoice == 'R') && (compchoice == 'p' || compchoice == 'P'))
            {
                cout << "You chose rock. Computer chose paper.";
                cout << "You lose.Try again.\n";
                lose++;
            }
            if ((userchoice == 'p' || userchoice == 'P') && (compchoice == 's' || compchoice == 'S'))
            {
                cout << "You chose paper. Computer chose scissors.";
                cout << "You lose.Try again.\n";
                lose++;
            }
            if ((userchoice == 'p' || userchoice == 'P') && (compchoice == 'r' || compchoice == 'R'))
            {
                cout << "You chose paper. Computer chose rock.";
                cout << "You win. Congratulations!\n";
                win++;
            }
            if ((userchoice == 's' || userchoice == 'S') && (compchoice == 'r' || compchoice == 'R'))
            {
                cout << "You chose scissors. Computer chose rock.";
                cout << "You lose.Try again.\n";
                lose++;
            }
            if ((userchoice == 's' || userchoice == 'S') && (compchoice == 'p' || compchoice == 'P'))
            {
                cout << "You chose scissors. Computer chose paper.";
                cout << "You win. Congratulations!\n";
                win++;
            }
            cout << "Would you like to play again?[y/n]\n";
            cin >> c;
            if (c != 'y' && c != 'Y')
            {
                again = false;
            }

        } while (again);
        int points = win - lose;

        update("users.txt", username, 3, win);
        update("users.txt", username, 4, lose);
        update("users.txt", username, 5, tie);
        update("users.txt", username, 6, points);
        updateacc("users.txt", username);
        Dashboard();
    }
    void welcomepage()
    {
        password = "", username = "";
        system("cls");
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "\t\t\tWELCOME PAGE\t\t\t" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        int num;
        std::cout << "Enter 1 for login and 2 for signup:";
        std::cin >> num;
        switch (num)
        {
        case 1:
            login();
            break;
        case 2:
            signup();
            break;
        default:
            std::cout << "Bye! Come again sometime.Happy playing.";
            exit(0);
            break;
        }
    }
};
int main()
{
    Accounts obj;
    obj.welcomepage();
    return 0;
}
