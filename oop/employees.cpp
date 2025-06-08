#include<iostream>
using namespace std;

class AbtractEmployee{
    virtual void AskForPromotion() = 0;
    virtual void Work() = 0;
};

class employee:AbtractEmployee{
protected: 
    string name;
private: 
    string job;
    int age;
public:
    void setName(string Name){
        name = Name;
    }
    string getName(){
        return name;
    }

    void setJob(string Job){
        job = Job;
    }
    string getJob(){
        return job;
    }

    void setAge(int Age){
        age = Age;
    }
    int getAge(){
        return age;
    }

    void Introduce(){
        cout << "Name - " << name << endl;
        cout << "Job - " << job << endl;
        cout << "Age - " << age << endl;
    }
    employee(string Name, string Job, int Age){
        name = Name;
        job = Job;
        age = Age;
    }
    void AskForPromotion() {

        if ( age >= 20){
            cout << name << " got promoted!" << endl;
        }
        else 
            cout << name << ", sorry NO promotion! " << endl;
    }
    void Work(){
        cout << name << " is checking mail, doing tasks,..." << endl;
    }
};

class Developer: public employee{
    public: 
        string FavProgrammingLanguage;
        Developer(string Name, string Job, int Age, string favProgrammingLanguage)
            :employee(Name, Job, Age)
        {
         FavProgrammingLanguage = favProgrammingLanguage;
        }
    void FixBug(){
        cout << getName() << " fixed bug using " << FavProgrammingLanguage << endl;
    }
    void Work(){
        cout << name << " is fixing bug, writing " << FavProgrammingLanguage << " code" << endl;
    }
};

class Teacher: public employee{
public: 
    string Subject;
    void PrepareLesson(){
        cout << name << " is preparing " << Subject << " lesson" << endl;
    }
    Teacher(string Name, string Job, int Age, string subject)
        :employee(Name, Job, Age)
    {
        Subject = subject;
    }
    void Work(){
        cout << name << " is teaching " << Subject << endl;
    }
};

int main(){
    employee employee1 ("Lương Nhất Khôi", "Programmer", 20);
    employee1.Introduce();
    
    employee employee2 ("Hiền Nguyên", "Student", 17);
    employee2.Introduce();

    employee1.setAge(20);
    cout << employee1.getName() << " is " << employee1.getAge() << " years old" << endl;
    employee1.AskForPromotion(); employee2.AskForPromotion();
    Developer d = Developer("Khoi", "IT", 20, "C++"); 
    d.FixBug();
    d.AskForPromotion();
    d.Work();
    Teacher t = Teacher( "Bin", "Teacher", 18, "IT");
    t.PrepareLesson();
    t.AskForPromotion();
    t.Work();
    employee *e1 = &d;
    employee *e2 = &t;

    e1 -> Work();
    e2 -> Work();
    return 0; 
}