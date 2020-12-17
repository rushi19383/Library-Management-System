#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Book
{
private:
	string name;
	string authorname;
	string category;
	int count;

public:
	bool operator==(const Book &b4)
	{
		if (authorname == b4.authorname)
		{
			return 1;
		}
		else if (name == b4.name)
		{
			return 1;
		}
		else if (category == b4.category)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int inputdata();
	void search();
	void view();
	int getcount();
};

vector<Book> v;
vector<string> c;

int Book::inputdata()
{
	string genre;
	Book b, bq;
	int n;
	cin.ignore();
	cout << "\nEnter name of book: ";
	getline(cin, b.name);
	vector<Book>::iterator p;

	p = find(v.begin(), v.end(), b);

	if (p == v.end())
	{
		name = b.name;
		cout << "Enter book author's name: ";
		getline(cin, authorname);
		cout << "Enter category of book: ";
		getline(cin, genre);
		category = genre;
		vector<string>::iterator pq;

		pq = find(c.begin(), c.end(), genre);

		if (pq == c.end())
		{
			c.push_back(genre);
		}
		cout << "Enter the no. of copies of the book to add (at least 1): ";
		cin >> count;
		return 0;
	}
	else
	{
		cout << "Book already exists" << endl;
		cout << "Enter no. of copies to add: ";
		cin >> n;

		if (n >= 0)
		{
			p->count += n;
		}
		else if (n < 0)
		{
			cout << "Wrong input" << endl;
		}
		return 1;
	}
}

void Book::search()
{
	Book b;
	bool fnd;
	bool write = false;
	int abcount;
	cin.ignore();
	cout << "\nEnter book author's name: ";
	getline(cin, b.authorname);
	vector<Book>::iterator p = v.begin();

	while ((p = find(p, v.end(), b)) != v.end())
	{
		fnd = true;

		if (!write)
		{
			cout << "\nBooks by author found: " << endl;
			cout << "\n"
				 << setw(25) << "Book Name" << setw(25) << "Category" << setw(15) << "Copies" << endl;
			write = true;
		}
		cout << setw(25) << p->name << setw(25) << p->category << setw(15) << p->count << endl;
		p++;
	}
	if (!fnd)
	{
		cout << "No books found" << endl;
	}
}

void Book::view()
{
	int sCount;

	for (int i = 0; i < c.size(); i++)
	{
		sCount = 0;
		cout << "\nCategory:" << c[i] << endl;
		cout << "\n"
			 << setw(25) << "Book Name" << setw(25) << "Author Name" << setw(15) << "Copies" << endl;

		for (int j = 0; j < v.size(); j++)
		{
			if (v[j].category == c[i])
			{
				cout << setw(25) << v[j].name << setw(25) << v[j].authorname << setw(15) << v[j].count << endl;
				sCount += v[j].count;
			}
		}
		cout << setw(61) << "Total: " << setw(4) << sCount << endl;
	}
	cout << setw(60) << "Total Books In Library: " << setw(5) << getcount() << endl;
}

int Book::getcount()
{
	int stockCount = 0;
	for (int i = 0; i < v.size(); i++)
	{
		stockCount += v[i].count;
	}
	return stockCount;
}

int main()
{
	int choice;
	int present;
	int totalCount = 0;
	Book b1;
	do
	{
		cout << "\n1.Add book    2.Search    3.View by category    4.Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			present = b1.inputdata();
			if (!present)
			{
				v.push_back(b1);
			}
			break;
		case 2:
			b1.search();
			break;
		case 3:
			b1.view();
			break;
		case 4:
			break;
		}
	} while (choice != 4);
	return 0;
}
