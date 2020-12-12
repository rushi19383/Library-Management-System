//This is code for library management system//
#include <iostream>
#include <string>
using namespace std;
#define bookLIMIT 100
int count = 0;
int countid = 0;

class Library
{

public:
    string bookName[bookLIMIT];
    int flag = 0;
    int id[bookLIMIT];

    void adddata()
    {

        cout << "Enter the name of book" << endl;
        cin.get();
        getline(cin, bookName[count]);

        count++;
        cout << "Enter the id of book" << endl;
        cin >> id[countid];

        countid++;
    }
    void deletedata()
    {
        cout << "Enter the book to delete :" << endl;
        string rbn;
        cin.get();
        getline(cin,rbn);
        for (int i = 0; i < count; i++)
        {
            if (bookName[i] == rbn)
            {

                for (int j = i; j < count; j++)
                {
                    bookName[j] = bookName[j + 1];
                }

                for (int j = i; j < countid; j++)
                {
                    id[j] = id[j + 1];
                }
                flag = 1;
                count--;
                countid--;
            }
        }

        if (flag == 0)
        {
            cout << "not found" << endl;
        }
    }
    void displaydata()
    {
        cout << "books are" << endl;
        for (int i = 0; i < count; i++)
        {

            cout << bookName[i] << endl;
            cout << "id are" << endl;
            cout << id[i] << endl;
        }
    }
    //for id//

    void show_Options()
    {
        cout << "\n1) Add Book\n";
        cout << "2) Delet Book\n";
        cout << "3) Display Books\n";
        cout << "4) Exit\n";
        cout << "\nEnter your choice: ";
    }
};

int main()
{
    Library c1;
    while (2 < 3)
    {
        int choice;
        c1.show_Options();

        cin >> choice;
        if (choice == 4)
        {
            cout << "\nsuccessfully exited!!\n\n";
            break;
        }
        else
        {
            switch (choice)

            {
            case 1:
                c1.adddata();
                break;
            case 2:
                c1.deletedata();
                break;
            case 3:
                c1.displaydata();
                break;
            default:
                cout << "enter valid choice\n";
                break;
            }
        }

        /* code */
    }

    return 0;
}
