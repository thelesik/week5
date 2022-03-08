

#include <string>
#include <iostream>
#include "Header.h"

using namespace std;

class List {

private:
    string* elements = nullptr;
    int size;

public:
    enum { MAX_SIZE = 1000 };

    void AddBook(string value);
    int GetSize();
    void GetName();
    void Display();
    void Delete();
    void Clear();
    void Resizem();
    void Resize(long numValues);
    void Input();
    string GetValue(long pos);
    void SetValue(string value, long pos);
    List();
    ~List();
    string at(int index) {
        if (index < size) {
            return elements[index];
        }
    }

};
void List::SetValue(string value, long pos)
{
    if (pos < 0 || pos >= size) {
        throw "Error! Invalid position in list specified.";
    }
    elements[pos] = value;
}
string List::GetValue(long pos)
{
    if (pos < 0 || pos >= size) {
        throw "Error! Invalid position in list specified.";
    }
    return elements[pos];
}

void List::Resize(long numValues) // modified
{
    if (elements == nullptr) {
        try {
            if (numValues < 1 || numValues > MAX_SIZE) {
                throw "Error! Invalid list size specified.";
            }
            Clear();
            elements = new string[numValues];
            if (elements == nullptr) {
                throw "Error! Could not allocate memory for list.";
            }
            size = numValues;
        }
        catch (std::exception& e) {
            throw "Error! Could not allocate memory for list.";
        }

    }

    else {
        int newv = 0;
        cout << "Please anter the size of new array ";
        cin >> newv;
        string* arr = new string[newv];
        for (int i = 0; i < newv; ++i) {
            if (i >= 0 || i < size)
            {
                arr[i] = elements[i];
            }
            if (i >= size)
            {
                arr[i] = "";
            }
        }
        try {
            if (newv < 1 || newv > MAX_SIZE) {
                throw "Error! Invalid list size specified.";
            }
            Clear();
            elements = new string[newv];
            if (elements == nullptr) {
                throw "Error! Could not allocate memory for list.";
            }
            size = newv;
        }
        catch (std::exception& e) {
            throw "Error! Could not allocate memory for list.";
        }

        for (int i = 0; i < size; ++i) {
            elements[i] = arr[i];
        }
        Display();

    }
}






void List::Clear()
{
    if (size > 0) {
        delete[] elements;
        size = 0;
        elements = nullptr;
    }
}
void List::GetName() {
    double count = ReadValue<double>("Please input the name of books "); // th size is beoing increased after we add each member of the class
    for (int i = 0; i <= count -1; i++) {
        string tempbook = "";
        cout << "Book - ";
        cin >> tempbook;
        AddBook(tempbook);
    }

}
void List::Display() {
    for (int i = 0; i < size; i++) {
        cout << at(i) << endl;
    }
}
void List::Delete() {
    cout << "What element to Delete - ";
    string bookd = "";
    cin >> bookd;
    int position = -1;
    for (int i = 0; i < size; i++) {
        if (bookd == elements[i]) {
            position = i;
        }

    }
    for (int i = position; i < size-1; i++) {
        elements[i] = elements[i + 1];
    }
    if (position >= 0) {
        size = size-1;
    }
}


int List::GetSize() {
    return size;
}

void List::Resizem() ////
{
    int newv = 0;
    cout << "Please anter the size of new array ";
    cin >> newv;
    string* tmpElementsArray = new string[newv];

    for (int i = 0; i < newv; i++) {
        if (i >= 0 || i < size) {
            tmpElementsArray[i] = elements[i];
            cout << "check1" << endl;
        }
        if (i > size) {
            tmpElementsArray[i] = "";
            cout << "check2" << endl;

        }
        
    }
    for (int i = 0; i < newv; i++) {
        cout << tmpElementsArray[i] << endl;
    }
    //delete[] elements;
    //elements = tmpElementsArray;
   
 //   for (int i = 0; i < size; ++i) {
  //      elements[i] = arr[i];
  //  }
 //   Display();

}
void List::AddBook(string value) {
    string* tmpElementsArray = new string[size + 1];

    for (int i = 0; i < size; i++) {
        tmpElementsArray[i] = elements[i];
    }

    delete[] elements;
    elements = tmpElementsArray;
    elements[size] = value;
    size++;
}
List::~List() {
    delete[]elements;
}
List::List() {
    elements = nullptr;
    size = 0;
}
int main()
{
    List s;
    s.GetName();
    s.Delete();
    s.Display();
    s.Resize(2);
    s.Display();
}
/*Create a C++ program that will keep a list of books.  Your program must meet the following criteria:
The program will provide the user with a menu to add names to the list, delete a name from the list (searching by title), display the list in it's entirety
The list of books will be stored as a dynamically allocated array of strings.  The strings can be either STL strings or C style strings
The list must be stored in a class
There must be an operator overload created for the stream extraction operator that will handle the output of the list
You must provide a copy constructor for the class that will allow the programmer to set one class object equal to another
There must be a function to allow the list size to be increased without losing data that has been previously stored in the list.*/
/*// book list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*           //elements[i] = elements[i + 1];
            for (int j = i; j <= size-1; j++) {
                //cout << endl;
               // cout << elements[j];
                elements[j] = elements[j + 1];
            }*/
/*    if (elements == nullptr) {
        try {
            if (numValues < 1 || numValues > MAX_SIZE) {
                throw "Error! Invalid list size specified.";
            }
            Clear();
            elements = new string[numValues];
            if (elements == nullptr) {
                throw "Error! Could not allocate memory for list.";
            }
            size = numValues;
        }
        catch (std::exception& e) {
            throw "Error! Could not allocate memory for list.";
        }

    }

    else {
        int newv = 0;
        cout << "Please anter the size of new array ";
        cin >> newv;
        string* arr = new string[newv];
        for (int i = 0; i < newv; ++i) {
            if (i >= 0 || i < size)
            {
                arr[i] = elements[i];
            }
            if (i >= size)
            {
                arr[i] = "";
            }
        }
        try {
            if (newv < 1 || newv > MAX_SIZE) {
                throw "Error! Invalid list size specified.";
            }
            Clear();
            elements = new string[newv];
            if (elements == nullptr) {
                throw "Error! Could not allocate memory for list.";
            }
            size = newv;
        }
        catch (std::exception& e) {
            throw "Error! Could not allocate memory for list.";
        }

        for (int i = 0; i < size; ++i) {
            elements[i] = arr[i];
        }
        Display();

    }

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class List {
private:
    vector<string> *books;
    long size;
public:
    void SetValue();
    string GetValue();
    void Display();
    void Resize(long g);
};

void List::Resize(long size) {
    books = new vector<string>[size];
}
void List::SetValue() {
    books[0]  "123qwe";
}
void List::Display() {
  //  for (int i = 0; i <= 1; i++) {
   //     cout << books[i];
  //  }
    cout << books;
}
*/
/*// book list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class List {
private:
    vector<string>* books;
    long size;
public:
    void SetValue();
    string GetValue();
    void Display();
    void Resize(long g);
    void Clear();
    List();
    ~List();
};

void List::Resize(long size) {
    books = new vector<string>[size];
}
void List::SetValue() {
    books->push_back("123123123");
}
void List::Display() {
    //  for (int i = 0; i <= 1; i++) {
     //     cout << books[i];
    //  }
    for (auto i = books->begin(); i != books->end(); i++)
        cout << books << endl;
}
List::List()
{
    books = nullptr;
    size = 0;
}

List::~List()
{
    Clear();
}
void List::Clear()
{
    if (size > 0) {
        delete[] books;
        size = 0;
        books = nullptr;
    }
}

int main()
{
    List* l = nullptr;
    l = new List;
    l->Resize(6);
    l->SetValue();
    cout << "\n";
    l->Display();
    //std::cout << "Hello World!\n";
}*/