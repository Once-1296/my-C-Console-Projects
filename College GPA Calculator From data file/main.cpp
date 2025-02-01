#include"headers.h"
using namespace std;
class gpa
{
    public:
    float value,weight;
    gpa();
    gpa(float x,float y);
    friend gpa operator+(gpa&a,gpa&b);
};
gpa::gpa()
{
    this->value=0.f;
    this->weight=0.f;
}

gpa::gpa(float x, float y)
{
    this->value=x;
    this->weight=y;
}

gpa operator+(gpa &a, gpa &b)
{
    float new_gpa =((a.value*a.weight)+(b.value*b.weight))/(a.weight+b.weight);
    return gpa(new_gpa,a.weight+b.weight);
}
class user
{
    protected:
    std::string id_num;
    std::vector<std::string> subjects;
    std::vector<float> credits;
    public:
    user();
    virtual void init(std::string s)=0;
    virtual void display()=0;
    std::string ret_grade(float gpa);
};
class student:public virtual user
{
    private:
    std::string fname,lname;
    std::vector<float>gpas;
    std::vector<gpa> gpa_by_wt;
    gpa total;
    float tot_cred=0.f;
    public:
    student(std::string s);
    void init(std::string s);
    void display();
    void display(int n,std::vector<int>&arr);
};
user::user()
{
    std::fstream file("student.txt",std::ios::in);
    std::string line,word;
    getline(file,line);
    std::stringstream obj(line);
            getline(obj,word,',');
            getline(obj,word,',');
            getline(obj,word,',');
            while(getline(obj,word,','))
            {
                    this->subjects.push_back(word);
            }
    getline(file,line);
    std::stringstream obj2(line);
            getline(obj2,word,',');
            getline(obj2,word,',');
            getline(obj2,word,',');
            while(getline(obj2,word,','))
            {
                    float f = std::stof(word);
                    this->credits.push_back(f);
            }
    file.close();
}

std:: string user::ret_grade(float gpa)
{
    if(gpa<4.0f)return "FF";
    else if(gpa<6.0f)return "CD";
    else if(gpa<7.0f)return "CC";
    else if(gpa<8.0f)return "BC";
    else if(gpa<9.0f)return "BB";
    else if(gpa<9.5f)return "AB";
    return "AA";
}
student::student(std::string s)
{
    this->init(s);
}

void student::init(std::string s)
{
        
        this->id_num=s;
        std::fstream file("student.txt",std::ios::in);
        std::string line,word;
        getline(file,line);
        getline(file,line);
        while(getline(file,line))
        {
            std::stringstream obj(line);
            getline(obj,word,',');
            this->fname=word;
            getline(obj,word,',');
            this->lname=word;
            getline(obj,word,',');
            if(word==this->id_num)
            {
                while(getline(obj,word,','))
                {
                    float f = std::stof(word);
                    this->gpas.push_back(f);
                }
                break;
            }
        }
        file.close();
        this->display();
}
void student::display()
{
    int n;
    bool b = false;
    std::vector<int> v;
    do
    {
        b=false;
        v.clear();
    do
    {
        system("cls");
    std::cout<<"Student: "<<this->fname<<" "<<this->lname<<std::endl;
    std::cout<<"ID number: "<<this->id_num<<std::endl;
    std::cout<<"GPAs:\n";
    for(int i =0;i<6;i++)
    {
        std::cout<<i+1<<".\t"; 
        std::cout<<this->subjects[i]<<": "<<this->gpas[i];
        std::cout<<" Grade: "<<this->ret_grade(this->gpas[i]);
        std::cout<<" Credits: ";
        if(this->ret_grade(this->gpas[i])!="FF")
        {
            std::cout<<this->credits[i]<<"/"<<this->credits[i]<<std::endl;
            this->tot_cred += this->credits[i];
        }
        else
        {
            std::cout<<0<<"/"<<this->credits[i]<<std::endl;
        }
        gpa subj_(this->gpas[i],this->credits[i]);
        this->gpa_by_wt.push_back(subj_);
    }
    this->total=gpa(0.f,0.f);
    for (int i = 0; i < 6; i++)
    {
      this->total=this->total+this->gpa_by_wt[i];
    }
    std::cout<<"Total GPA: "<<this->total.value;
    std::cout<<" Total Grade: "<<this->ret_grade(this->total.value);
    std::cout<<" Total Credits: "<<this->tot_cred<<"/"<<this->total.weight<<std::endl;
    std::cout<<"Enter number of subjects you want to see:(b/w 2 and 5,inclusive)\n Enter -1 to exit\n";
    cin>>n;
    }while((n<2||n>5)&&n!=-1);
    if(n==-1)break;
    std::cout<<"Enter serial number of subjects:(1 to 6):\n";
    v.reserve(n);
    std::unordered_set<int>st;
    for (int i = 0; i < n; i++)
    {
       std::cin>>v[i];
       if(v[i]<1||v[i]>6)b=true;
        st.insert(v[i]);
    }
    if(st.size()<n)b=true;
    }while(b);
    if(n!=-1)this->display(n,v);
}
void student::display(int n,std::vector<int>&arr)
{
    system("cls");
    std::cout<<"Student: "<<this->fname<<" "<<this->lname<<std::endl;
    std::cout<<"ID number: "<<this->id_num<<std::endl;
    std::cout<<"GPAs:\n";
    std::vector<gpa> custom_gpa;
    float custom_cred=0.f;
    for(int i =0;i<n;i++)
    {
        std::cout<<i+1<<".\t"; 
        std::cout<<this->subjects[arr[i]-1]<<": "<<this->gpas[arr[i]-1];
        std::cout<<" Grade: "<<this->ret_grade(this->gpas[arr[i]-1]);
        std::cout<<" Credits: ";
        if(this->ret_grade(this->gpas[arr[i]-1])!="FF")
        {
            std::cout<<this->credits[arr[i]-1]<<"/"<<this->credits[arr[i]-1]<<std::endl;
            custom_cred += this->credits[arr[i]-1];
        }
        else
        {
            std::cout<<0<<"/"<<this->credits[arr[i]-1]<<std::endl;
        }
        gpa subj_(this->gpas[arr[i]-1],this->credits[arr[i]-1]);
        custom_gpa.push_back(subj_);
    }
    gpa custom_total;
    for (int i = 0; i < n; i++)
    {
      custom_total=custom_total+custom_gpa[i];
    }
    std::cout<<"Total GPA: "<<custom_total.value;
    std::cout<<" Total Grade: "<<this->ret_grade(custom_total.value);
    std::cout<<" Total Credits: "<<custom_cred<<"/"<<custom_total.weight<<std::endl;
    char c;
    std::cout<<"Enter y to continue ";
    cin>>c;
    this->display();
}
bool check_id(string s)
{
    std::fstream file("student.txt",std::ios::in);
        std::string line,word;
        getline(file,line);
        getline(file,line);
        while(getline(file,line))
        {
            std::stringstream obj(line);
            getline(obj,word,',');
            getline(obj,word,',');
            getline(obj,word,',');
            if(word==s)
            {
                return true;
            }
        }
        return false;
}
int main()
{
    string id;
    char c;
    do
    {
        do
    { 
    system("cls");
    cout<<"Welcome to VJTI FY BTECH IT results portal\n";
    cout<<"Enter Your valid ID number\n";
    cin>>id;
    }while(!check_id(id));
    student Student(id);
    system("cls");
    cout<<"Do you want to go back to log in[y/n]?";
    cin>>c;
    } while (c=='y'||c=='Y');
    return 0;
}