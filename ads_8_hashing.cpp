#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define max 10

class record
{
    int rollno, marks;
    char name[20];
    friend class student;
};

class hashing
{
    int rollno, pos;
    public:
        hashing()
        {
            rollno = -1;
            pos = -1;
        }
    friend class student;
};

class student
{
    hashing h[10];
    record rec;
    int s, relt;
    public:
        student();
        void lp_without();
        void search();
        void display();
        void displayHashTable();
        void displayall();
        void lp_with();
};

student::student()
{
    s = sizeof(record);
    for(int i = 0; i < 10; i++)
    {
        h[i].rollno = -1;
        h[i].pos = -1;
    }
    relt = 0;
}

void student::lp_without()
{
    int i = 0;
    char c;
    fstream f;
    f.open("student.txt", ios::binary|ios::out);
    int loc = 0;
    do
    {
        cout << "Enter the details of students:\n";
        cout << "Roll number:";
        cin >> rec.rollno;
        cout << "Name:";
        cin >> rec.name;
        cout << "Marks:";
        cin >> rec.marks;
        loc = rec.rollno % 10;
        if(h[loc].rollno == -1)
        {
            h[loc].rollno = rec.rollno;
            h[loc].pos = relt;
            f.write((char*)&rec, s);
            relt = relt + 1;
        }
        else
        {
            for (int i = 1; i < 10; i++)
            {
                loc = (loc + 1) % 10;
                if (h[loc].rollno == -1)
                {
                    h[loc].rollno = rec.rollno;
                    h[loc].pos = relt;
                    f.write((char *)&rec, s);
                    relt = relt + 1;
                    break;
                }
            }
            if(i >= 10)
            {
                cout << "Hashtable is full" << endl;
            }
        }
        cout << "Do you want to add more details(y/n):";
        cin >> c;
    }
    while(c == 'y');
    f.close();
}

void student::search()
{
    fstream f;
    f.open("student.txt", ios::binary | ios::in);
    cout << "Enter the roll number to search: ";
    cin >> rec.rollno;
    int loc = rec.rollno % 10;
    int i;
    for(int i=1;i<=10;i++)
    {
        if(h[loc].rollno == rec.rollno)
        {
            cout << "Key found\n";
            int p = h[loc].pos * s;
            f.seekg(p, ios::beg);
            f.read((char *)&rec, s);
            display();
            break;
        }
        else
        {
            loc=(loc+1)%10;
        }
    }
    if(i > 10)
        cout << "Key not found";
    f.close();
}

void student::display()
{
    cout << rec.rollno << "\t" << rec.name << "\t" << rec.marks << endl;
}

void student::displayHashTable()
{
    cout << "Display Hash Table:\n";
    cout << "\nRollno.\tPosn\n";
    for (int i = 0; i < 10; i++)
    {
        cout << h[i].rollno << "\t" << h[i].pos << endl;
    }
}

void student::displayall()
{

    cout << "Display Hash Table:\n";
    cout << "\nRollno.\tPosn\n";
    for (int i = 0; i < 10; i++)
    {
        cout << h[i].rollno << "\t" << h[i].pos << endl;
    }
    cout << "Roll No\tName\tMarks" << endl;
    fstream f;
    f.open("student.txt", ios::binary | ios::in);
    for (int i = 0; i < 10; i++)
    {
        if (h[i].rollno != -1)
        {
            int p = h[i].pos * s;
            f.seekg(p, ios::beg);
            f.read((char *)&rec, s);
            display();
        }
    }
    f.close();
}

void student::lp_with()
{
    char a;
    int loc,i;
    hashing temp;
    fstream f;
    f.open("student.txt", ios::binary|ios::out);
    do
    {
        cout << "Enter the details of students:\n";
        cout << "Roll number:";
        cin >> rec.rollno;
        cout << "Name:";
        cin >> rec.name;
        cout << "Marks:";
        cin >> rec.marks;
        loc = rec.rollno % 10;
        if(h[loc].rollno == -1)
        {
            h[loc].rollno = rec.rollno;
            h[loc].pos = relt;
            f.write((char*)&rec, s);
            relt = relt + 1;
        }
        else
        {
            temp.rollno = rec.rollno;
            temp.pos = relt;
            f.write((char *)&rec, s);
            relt = relt + 1;
            if (loc != (h[loc].rollno) % 10)
            {
                temp.rollno = rec.rollno;
                temp.pos = h[loc].pos;
                h[loc].rollno = rec.rollno;
                h[loc].pos = relt - 1;
            }
            i = (loc + 1) % 10;
            while (i != loc)
            {
                if(h[i].rollno == -1)
                {
                    h[i].rollno = rec.rollno;
                    h[i].pos = temp.pos;
                    break;
                }
                i = (i + 1) % 10;
            }
            if(i >= 10)
            {
                cout << "Hashtable is full" << endl;
            }
        }
        cout << "Do you want to add more details(y/n):";
        cin >> a;
    }
    while(a == 'y');
    f.close();
}

int main()
{
    student s;
    int x;
    while(1)
    {
        cout << "\nMENU:\n1.Linear probing(without replacement) \n2.Linear probing(with replacement) \n3.Display \n4.Search \n5.Exit" << endl;
        cout << "\nChoose the operation you want to perform:";
        cin >> x;
        switch(x)
        {
            case 1:
                cout << "Linear probing(without replacement):\n";
                s.lp_without();
                cout << endl;
                break;
            case 2:
                cout << "Linear probing(with replacement):\n";
                s.lp_with();
                cout << endl;
                break;
            case 3:
                cout << "Details of students:\n";
                s.displayall();
                cout << endl;
                break;
            case 4:
                cout << "Search:\n";
                s.search();
                cout << endl;
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}