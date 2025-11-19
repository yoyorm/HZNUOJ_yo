#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct student
{
    string name;
    int age;
    double grade;
};

int main()
{
    int n;
    cin >> n;
    vector<student> students(n);
    for (int i = 0; i < n; i++)
    {
        cin >> students[i].name >> students[i].age >> students[i].grade;
    }
    for (auto &s : students)
    {
        s.age++;
        s.grade *= 1.2;
        if (s.grade > 600)
        {
            s.grade = 600;
        }
    }
    for (auto &s : students)
    {
       cout<<s.name<<" "<<s.age<<" "<<s.grade<<endl;
    }
    
}