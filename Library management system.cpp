#include <iostream>
#include <string>
using namespace std;
#define bookLIMIT 100
int count = 0;


class Library
{

public:

    string bookName[bookLIMIT];
    
    int id[bookLIMIT];

    int sizeofarray()
    {
        int n = sizeof(bookName) / sizeof(bookName[0]);
        cout << n << endl;
        cout << sizeof(bookName) << endl;
        cout << sizeof(bookName[0]) << endl;
        return n;
    }

    void addBook()
    {

        cout << "Enter the name of book" << endl;
        cin >> bookName[count];

        count++;
    }
    void deleteBook()
    {

        string rbn;
        cin >> rbn;
        for (int i = 0; i < count; i++)
        {
            if (bookName[i] == rbn)
            {
                
                for (int j = i; j < count; j++)
                {
                    bookName[j] = bookName[j + 1];
                    
                }
                
                break;
            }
        
            else{
                cout<<"not found"<<endl;
                
                
            }
        
        }
        
        
    }
    void displayBook()
    {
        cout << "books are" << endl;
        for (int i = 0; i < count; i++)
        {

            cout << bookName[i] << endl;
            cout << count << endl;
        }
    }
};

int main()
{
    Library c1;
    c1.addBook();
    c1.addBook();
    c1.addBook();

    c1.displayBook();
    c1.deleteBook();
    c1.displayBook();

    return 0;
}