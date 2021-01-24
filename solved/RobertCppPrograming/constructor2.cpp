#include <iostream>
using namespace std;

class Integer{
public:
    int m_value;

    Integer();
    Integer(int num);
    //that means...
    //Integer(int num = 0)
    void Show();
};

Integer::Integer(){
    m_value = 0;
}
Integer::Integer(int num){
    m_value = num;
}

void Integer::Show(){
    cout << m_value << endl;
}

int main(){
    Integer a,b(19),c(100);

    Integer array[4] = {
        Integer(1),
        Integer(4),
        Integer(20),
    };

    a.Show();
    b.Show();
    c.Show();

    cout << endl;

    int size = sizeof array / sizeof *array;
    for(int i = 0; i < size; ++i){
        (array+i)->Show();
    }
}