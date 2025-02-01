#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
float reci(float n)
{
    return (1 / n);
}
class Data2
{
public:
    vector<float> resinpar2;
};
class Data3
{
public:
    vector<float> current23;
};
class Data4
{
public:
    vector<float> pds12;
};
class Data5
{
public:
    vector<float> power1234;
};
class Data
{
public:
    int no;
    float temp;
    Data()
    {

        fstream file("temp.txt", ios::app);
        cout << "Enter no of resistors (positive) in parallel:\t";
        do
        {
            cin >> no;
        } while (no <= 0);
        for (int i = 0; i < no; i++)
        {
            if (i < no - 1)
            {
                cout << "Enter resistance for resistor(p) " << i + 1 << "\t";
                cin >> temp;
                file << temp << ",";
                resinpar.push_back(temp);
            }
            if (i == no - 1)
            {
                cout << "Enter resistance for resistor(p) " << i + 1 << "\t";
                cin >> temp;
                file << temp << endl;
                resinpar.push_back(temp);
                file.close();
            }
        }
        cout << "Net resistance of given resistors in parallel is:" << endl;
        cout << calcnetres(no) << endl;
    }
    vector<float> resinpar;
    float calcnetres(int count)
    {
        float sum = 0;
        for (int i = 0; i < count; i++)
        {
            sum += reci(resinpar[i]);
        }
        return (reci(sum));
    }
};
int main()
{
    system("cls");
    int con;
    float netres = 0.0;
    vector<Data2> resinser;
    cout << "Enter total no of resistors in series:\t";
    cin >> con;
    ofstream file("temp.txt");
    file << con << endl;
    file.close();
    for (int i = 0; i < con; i++)
    {
        Data obj;
        netres += obj.calcnetres(obj.no);
    }
    cout << "\nTotal resistance is:\t" << netres;
    fstream file1("temp.txt", ios::in);
    string word, line;
    getline(file1, line);
    const int con1 = stoi(line);
    int con2;
    vector<int> parcount;
    for (int i = 0; i < con1; i++)
    {
        Data2 data;
        con2 = 0;
        getline(file1, line);
        stringstream obj2(line);
        while (getline(obj2, word, ','))
        {

            data.resinpar2.push_back(stof(word));
            con2++;
        }
        parcount.push_back(con2);
        resinser.push_back(data);
    }
    float voltage;
    cout << "\nEnter voltage:\t";
    cin >> voltage;
    float netcurr = voltage / netres;
    vector<Data3> currents;
    for (int i = 0; i < con1; i++)
    {
        Data3 data3;
        float tempsum = 0.0;
        for (int j = 0; j < parcount[i]; j++)
        {
            tempsum += reci(resinser[i].resinpar2[j]);
        }
        for (int k = 0; k < parcount[i]; k++)
        {
            float temp2 = (netcurr * reci(tempsum)) / (resinser[i].resinpar2[k]);
            data3.current23.push_back(temp2);
        }
        currents.push_back(data3);
    }
    vector<Data4> pds;
    vector<Data5> powers;
    for (int i = 0; i < con1; i++)
    {
        Data4 data4;
        Data5 data5;
        for (int j = 0; j < parcount[i]; j++)
        {
            float temp = (resinser[i].resinpar2[j]) * (currents[i].current23[j]);
            data4.pds12.push_back(temp);
            temp *= (currents[i].current23[j]);
            data5.power1234.push_back(temp);
        }
        pds.push_back(data4);
        powers.push_back(data5);
    }
    int totnum = 0;
    for (int i = 0; i < con1; i++)
    {
        totnum+=parcount[i];
    }
    fflush(stdout);
    system("cls");
    system("cls");
    system("cls");
    int abc=0;
    for (int i = 0; i < con1; i++)
    {

        for (int j = 0; j < parcount[i]; j++)
        {
            cout << "Resistor: " << abc+1 << " details\n";
            cout << "Resistance: " << resinser[i].resinpar2[j] << endl;
            cout << "Current through it: " << currents[i].current23[j] << endl;
            cout << "Potential difference across it: " << pds[i].pds12[j] << endl;
            cout << "Power consumed by it: " << powers[i].power1234[j] << endl;
            abc++;
        }
    }
    float netpower = (netcurr*netcurr)*netres;
    cout << "Net Resistance: " << netres << endl;
    cout << "Net Current: " << netcurr << endl;
    cout << "Net Voltage: " << voltage << endl;
    cout << "Net Power consumed: " << netpower << endl;
    return 0;
}