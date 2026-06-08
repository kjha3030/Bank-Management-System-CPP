#include <iostream>
#include <string>
#include<fstream>
#include <cstdio>

using namespace std;

int main()
{
    cout << "===== BANK MANAGEMENT SYSTEM =====";

    cout << "\n1. Create Account";
cout << "\n2. Deposit Money";
cout << "\n3. Withdraw Money";
cout << "\n4. Check Balance";
cout << "\n5. View All Accounts";
cout << "\n6. Search Account";
cout << "\n7. Delete Account";
cout << "\n8. Exit";

int accNo;
string name;
float balance;

int choice;

cout << "\nEnter Choice: ";
cin >> choice;

 if(choice == 1)
    {
        cout << "Enter Account Number: ";
        cin >> accNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        ofstream file("account.txt", ios::app);

file << accNo << " "
     << name << " "
     << balance << endl;

file.close();
        cout << "\nAccount Created Successfully!";
    }
    
if(choice == 2)
{
    int searchAcc;
    float deposit;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> searchAcc;

    cout << "Enter Deposit Amount: ";
    cin >> deposit;

    ifstream file("account.txt");
    ofstream temp("temp.txt");

    while(file >> accNo >> name >> balance)
    {
        if(accNo == searchAcc)
        {
            balance += deposit;
            found = true;
        }

        temp << accNo << " "
             << name << " "
             << balance << endl;
    }

    file.close();
    temp.close();

    remove("account.txt");
    rename("temp.txt","account.txt");

    if(found)
    {
        cout << "\nMoney Deposited Successfully!";
    }
    else
    {
        cout << "\nAccount Not Found!";
    }
}
if(choice == 3)
{
    int searchAcc;
    float withdraw;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> searchAcc;

    cout << "Enter Withdraw Amount: ";
    cin >> withdraw;

    ifstream file("account.txt");
    ofstream temp("temp.txt");

    while(file >> accNo >> name >> balance)
    {
        if(accNo == searchAcc)
        {
            found = true;

            if(withdraw > balance)
            {
                cout << "\nInsufficient Balance!";
            }
            else
            {
                balance -= withdraw;
                cout << "\nMoney Withdrawn Successfully!";
            }
        }

        temp << accNo << " "
             << name << " "
             << balance << endl;
    }

    file.close();
    temp.close();

    remove("account.txt");
    rename("temp.txt","account.txt");

    if(!found)
    {
        cout << "\nAccount Not Found!";
    }
}
if(choice == 4)
{
    ifstream file("account.txt");

    file >> accNo >> name >> balance;

    cout << "\nAccount Number: " << accNo;
    cout << "\nName: " << name;
    cout << "\nBalance: " << balance;

    file.close();
}
if(choice == 5)
{
    ifstream file("account.txt");

    cout << "\n===== ALL ACCOUNTS =====\n";

    while(file >> accNo >> name >> balance)
    {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance;
        cout << "\n-------------------\n";
    }

    file.close();
}
if(choice == 6)
{
    int searchAcc;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> searchAcc;

    ifstream file("account.txt");

    while(file >> accNo >> name >> balance)
    {
        if(accNo == searchAcc)
        {
            cout << "\n===== ACCOUNT FOUND =====";
            cout << "\nAccount No: " << accNo;
            cout << "\nName: " << name;
            cout << "\nBalance: " << balance;

            found = true;
            break;
        }
    }

    file.close();

    if(!found)
    {
        cout << "\nAccount Not Found!";
    }
}
if(choice == 7)
{
    int deleteAcc;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> deleteAcc;

    ifstream file("account.txt");
    ofstream temp("temp.txt");

    while(file >> accNo >> name >> balance)
    {
        if(accNo == deleteAcc)
        {
            found = true;
            continue;
        }

        temp << accNo << " "
             << name << " "
             << balance << endl;
    }

    file.close();
    temp.close();

    remove("account.txt");
    rename("temp.txt","account.txt");

    if(found)
    {
        cout << "\nAccount Deleted Successfully!";
    }
    else
    {
        cout << "\nAccount Not Found!";
    }
}
if(choice == 8)
{
    cout << "\nThank You For Using Bank Management System!";
}
    return 0;
}