#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class SHOPPAGE
{
public:
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
            if (cnames[i] == "password")
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
    int check_email(string email)
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
        int emailnum;
        for (int i = 0; i < countcol("users.txt"); i++)
        {
            if (cnames[i] == "email")
            {
                emailnum = i;
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
                if (count == emailnum)
                {
                    if (email == word)
                    {
                        return 1;
                    }
                }
                count++;
            }
        }
        return 0;
    }
    int check_contact(string contact)
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
        int contactnum;
        for (int i = 0; i < countcol("users.txt"); i++)
        {
            if (cnames[i] == "contact")
            {
                contactnum = i;
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
                if (count == contactnum)
                {
                    if (contact == word)
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
    int check_id(string id)
    {
        int j = 0, linenum = 0;
        string word, line;
        vector<string> cnames;
        fstream file("products.csv", ios::in);
        getline(file, line);
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            cnames.push_back(word);
            j++;
        }
        int idnum;
        for (int i = 0; i < countcol("products.csv"); i++)
        {
            if (cnames[i] == "id num")
            {
                idnum = i;
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
                if (count == idnum)
                {
                    if (id == word)
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
                std::cout << "Enter your " << cnames[i] << " : ";
                std::cin >> temp;
                userdet.push_back(temp);
            }
            int passnum, emailnum, contactnum, usernamenum;
            for (int i = 0; i < countcol("users.txt"); i++)
            {
                if (cnames[i] == "password")
                {
                    passnum = i;
                }
            }
            for (int i = 0; i < countcol("users.txt"); i++)
            {
                if (cnames[i] == "email")
                {
                    emailnum = i;
                }
            }
            for (int i = 0; i < countcol("users.txt"); i++)
            {
                if (cnames[i] == "contact")
                {
                    contactnum = i;
                }
            }
            for (int i = 0; i < countcol("users.txt"); i++)
            {
                if (cnames[i] == "username")
                {
                    usernamenum = i;
                }
            }
            if (check_pass(userdet[passnum]) || check_contact(userdet[contactnum]) || check_email(userdet[emailnum]) || check_username(userdet[usernamenum]))
            {
                std::cout << "Password/contact/email/username is already in use. Would you like to try again? [y/n]";
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
    }
    void Dashboard()
    {
        int num;
        system("cls");
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "\t\t\tDASHBOARD\t\t\t" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "Enter \n 1 for seeing all products \n 2 for buying products \n 3 for printing bill \n 4 for purchase history \n 5 for logout \n 6 for exit";
        std::cin >> num;
        switch (num)
        {
        case 1:
            show_products();
            break;
        case 2:
            buy_products();
            break;
        case 3:
            printbill();
            break;
        case 4:
            show_history();
            break;
        case 5:
            std::cout << "Bye! Come again sometime.Happy shopping.";
            welcomepage();
            break;
        case 6:
            std::cout << "Bye! Come again sometime.Happy shopping.";
            exit(0);
            break;
        default:
            std::cout << "Bye! Come again sometime.Happy shopping.";
            exit(0);
            break;
        }
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
            std::cout << "Bye! Come again sometime.Happy shopping.";
            exit(0);
            break;
        }
    }
    void show_products()
    {
        system("cls");
        ifstream file("products.csv");
        int colcount = 0, linecount = 0;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "\t\t\t AVAILABLE PRODUCTS\t\t\t" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        string line, word;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        getline(file, line);
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            colcount++;
            if (colcount == countcol("products.csv"))
            {
                std::cout << "\t" << word << endl;
                break;
            }
            std::cout << "\t" << word << "\t    ";
        }
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        while (getline(file, line))
        {
            linecount++;
            stringstream obj2(line);
            colcount = 0;
            std::cout << linecount << ". ";
            while (getline(obj2, word, ','))
            {
                colcount++;
                if (colcount == countcol("products.csv"))
                {
                    std::cout << "\t" << word << endl;
                    break;
                }
                std::cout << "\t" << word << "\t";
            }
        }
        file.close();
        char c;
        while (c = std::cin.get())
        {
            std::cout << "Do you want to go back?[y/n]";
            std::cin >> c;
            if (c == 'y' || c == 'Y')
            {
                break;
            }
        }
        Dashboard();
    }
    vector<string> ids;
    vector<int> qty;
    void buy_products()
    {
        string inp;
        char c = 'n', ch = 'n';
        bool id_check = false;
        int product_num;
        system("cls");
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "\t\t\tBUYING PAGE\t\t\t" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        do
        {
            product_num = 0;
            id_check = false;
            ch = 'n';
            do
            {
                c = 'n';
                std::cout << " Enter product id no :";
                std::cin >> inp;
                if (check_id(inp))
                {
                }
                else
                {
                    std::cout << "The id number you entered doesn't exist. Would you like to try again[y] or end buying[n]";
                    std::cin >> c;
                    if (!(c == 'y' || c == 'Y'))
                    {
                        Dashboard();
                    }
                }
            } while (c == 'y' || c == 'Y');
            for (int i = 0; i < ids.size(); i++)
            {
                if (inp == ids[i])
                {
                    id_check = true;
                    product_num = i;
                    break;
                }
            }
            if (id_check)
            {
                std::cout << "You have already bought that product. It's old quantity is: " << qty[product_num] << endl;
                std::cout << "Please enter new quantity.";
                std::cin >> qty[product_num];
                if (qty[product_num] == 0)
                {
                    ids.erase(ids.begin() + product_num);
                    qty.erase(qty.begin() + product_num);
                }
            }
            if (!id_check)
            {
                int qt_num;
                ids.push_back(inp);
                std::cout << "Please enter quantity of product.";
                std::cin >> qt_num;
                while (qt_num <= 0)
                {
                    std::cout << "\n The quantity you entered is invalid. Please enter a valid quantity(greater than zero):";
                    std::cin >> qt_num;
                }
                qty.push_back(qt_num);
            }
            std::cout << "Would you like to buy another product?[y/n]";
            std::cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        int billnum = 0;
        string line, word, name;
        vector<int> prices;
        long double amount = 0.0;
        ifstream file0("bill.txt");
        while (getline(file0, line))
        {
            billnum++;
        }
        file0.close();
        int linecheck = check_username(username), counter = 0, cnum = 0, ccounter = 0;
        for (int i = 0; i < ids.size(); i++)
        {
            int linenum = check_id(ids[i]);
            ifstream file("users.txt");
            getline(file, line);
            stringstream obj(line);
            while (getline(obj, word, ','))
            {
                cnum++;
                if (word == "name")
                    ;
                {
                    break;
                }
            }
            while (getline(file, line))
            {
                counter++;
                if (counter == linecheck)
                {
                    stringstream obj2(line);
                    while (getline(obj2, word, ','))
                    {
                        ccounter++;
                        if (ccounter == cnum)
                        {
                            name = word;
                            break;
                        }
                    }
                }
                if (counter > linecheck)
                {
                    break;
                }
            }
            file.close();
        }
        for (int i = 0; i < ids.size(); i++)
        {
            linecheck = check_id(ids[i]);
            ifstream file("products.csv");
            getline(file, line);
            stringstream obj(line);
            cnum = 0, counter = 0, ccounter = 0;
            while (getline(obj, word, ','))
            {
                cnum++;
                if (word == "price")
                {
                    break;
                }
            }
            while (getline(file, line))
            {
                counter++;
                if (counter == linecheck)
                {
                    stringstream obj2(line);
                    while (getline(obj2, word, ','))
                    {
                        ccounter++;
                        if (ccounter == cnum)
                        {
                            prices.push_back(stoi(word));
                            amount += prices[i] * qty[i];
                            break;
                        }
                    }
                }
            }
            file.close();
        }
        fstream filew("bill.txt", ios::app);
        filew << name << "," << billnum << "," << __DATE__ << "," << __TIME__ << "," << amount << ",";
        for (int i = 0; i < ids.size(); i++)
        {
            if (i == ids.size() - 1)
            {
                filew << "product" << i + 1 << ":" << prices[i] << ":" << qty[i] << endl;
                break;
            }
            filew << "product" << i + 1 << ":" << prices[i] << ":" << qty[i] << ".";
        }
        std::cout << "Purchase successful!";
        std::cout << "Your bill number is : " << billnum << endl;
        std::cout << "Press any character key and enter to continue.";
        std::cin >> ch;
        ids.clear();
        qty.clear();
        Dashboard();
    }
    void printbill()
    {
        system("cls");
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "\t\t\tBILL\t\t\t" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        string bnum;
        int linenum = check_username(username), j = 0;
        string name;
        ifstream file("users.txt");
        string word, line;
        vector<string> cnames;
        getline(file, line);
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            cnames.push_back(word);
            j++;
        }
        int namenum;
        for (int i = 0; i < countcol("users.txt"); i++)
        {
            if (cnames[i] == "name")
            {
                namenum = i;
            }
        }
        fflush(stdout);
        int count = 0, count2 = 0;
        while (getline(file, line))
        {
            count++;
            count2 = 0;
            if (count == linenum)
            {
                stringstream obj2(line);
                while (getline(obj2, word, ','))
                {
                    if (count2 == namenum)
                    {
                        name = word;
                    }
                    count2++;
                }
            }
        }
        file.close();
        int ln = 0;
        bool one = false, two = false, three = false;
        do
        {
            three = false, one = false, two = false;
            ln = 0;
            std::cout << "Please enter your bill number.";
            std::cin >> bnum;
            ifstream file1("bill.txt");
            getline(file1, line);
            while (getline(file1, line))
            {
                stringstream obj0(line);
                one = false, two = false;
                ln++;
                while (getline(obj0, word, ','))
                {
                    if (name == word)
                    {
                        one = true;
                    }
                    if (bnum == word)
                    {
                        two = true;
                    }
                    if (one && two)
                    {
                        three = true;
                    }
                    if (three)
                    {
                        break;
                    }
                }
                if (three)
                {
                    break;
                }
            }
            file1.close();
            if (!three)
            {
                std::cout << "The bill number you entered either doesn't exist or it is not matched to your name. Please enter it again.";
            }
        } while (!three);
        system("cls");
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "\t\t\tPRINTING BILL\t\t\t" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        ifstream filewr("bill.txt");
        vector<string> clnames;
        string word1, word2;
        int ijk = 0, lmn = 0, xyz = 0;
        getline(filewr, line);
        stringstream obj3(line);
        while (getline(obj3, word, ','))
        {
            clnames.push_back(word);
            ijk++;
        }
        while (getline(filewr, line))
        {
            lmn++;
            xyz = 0;
            stringstream obj4(line);
            if (lmn == ln)
            {
                while (getline(obj4, word, ','))
                {
                    if (xyz == 5)
                    {
                        std::cout << "--------------------------------------------------------------------------------------------" << endl;
                        std::cout << "\tproduct no\t\tprice\t\tquantity\t" << endl;
                        std::cout << "--------------------------------------------------------------------------------------------" << endl;
                        stringstream obj5(word);
                        while (getline(obj5, word1, '.'))
                        {
                            stringstream obj6(word1);
                            while (getline(obj6, word2, ':'))
                            {
                                std::cout << "\t" << word2 << "\t";
                            }
                            std::cout << endl;
                        }
                        xyz++;
                    }
                    if (xyz < 5)
                    {
                        std::cout << clnames[xyz] << " : " << word << endl;
                        xyz++;
                    }
                    if (xyz > 5)
                    {
                        break;
                    }
                }
            }
            if (lmn > ln)
            {
                break;
            }
        }
        std::cout << "Press any character key and enter to continue.";
        char as;
        std::cin >> as;
        Dashboard();
    }
    void show_history()
    {
        system("cls");
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "\t\t\tSHOWING PURCHASE HISTORY\t\t\t" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        std::cout << "--------------------------------------------------------------------------------------------" << endl;
        int linenum = check_username(username), j = 0;
        string name;
        ifstream file("users.txt");
        string word, line;
        vector<string> cnames;
        getline(file, line);
        stringstream obj(line);
        while (getline(obj, word, ','))
        {
            cnames.push_back(word);
            j++;
        }
        int namenum;
        for (int i = 0; i < countcol("users.txt"); i++)
        {
            if (cnames[i] == "name")
            {
                namenum = i;
            }
        }
        fflush(stdout);
        int count = 0, count2 = 0;
        while (getline(file, line))
        {
            count++;
            count2 = 0;
            if (count == linenum)
            {
                stringstream obj2(line);
                while (getline(obj2, word, ','))
                {
                    if (count2 == namenum)
                    {
                        name = word;
                    }
                    count2++;
                }
            }
        }
        file.close();
        ifstream file1("bill.txt");
        getline(file1, line);
        while (getline(file1, line))
        {
            stringstream obj1(line);
            while (getline(obj1, word, ','))
            {
                if (name == word)
                {
                    std::cout << line << endl;
                }
            }
        }
        char cha;
        std::cout << "Press any character key to continue.";
        std::cin >> cha;
        Dashboard();
    }
};
int main()
{
    SHOPPAGE obj;
    obj.welcomepage();
    return 0;
}