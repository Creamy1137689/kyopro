#include <iostream>
using namespace std;

const int MAX_NAME = 16;

class Student{
public:
    char name[MAX_NAME + 1];
    int scoreJapanese;
    int scoreMath;
    int scoreEnglish;

    void Show();
};

void Student::Show(){
    cout << "Name : " << name << endl
        << "Japanese : " << scoreJapanese << ",  Math : " << scoreMath << ",  English : " << scoreEnglish << endl;
}

int main(){
    Student students[] = {
        { "Alice", 42, 100, 98, },
        { "Blian", 87, 18, 90,  },
        { "Candy", 11, 35, 12,  },
    };
    int size = sizeof students / sizeof *students;
    for (int i = 0; i < size; ++i){
        (students+i)->Show();
        //students[i].Show();
    }
}