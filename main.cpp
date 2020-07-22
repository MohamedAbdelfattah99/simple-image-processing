/// FCI – Programming 1 – 2018 - Assignment 3
/// Program Name: Group Task
/// Last Modification Date: 27/3/2017
/// Author1 and ID and Group: Muhammad Bakr Abdel Hafez
/// Author2 and ID and Group: Muhammad Ashraf badwy Moussa
/// Author3 and ID and Group: Muhammad Abdel Fattah
/// Teaching Assistant: Eng. Khadiga Khaled and Eng. Omar Khaled
/// Purpose:..........
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    while (true)
    {
        cout<<"Ahlan ya user ya hbibi.\n"
            <<"What do you like to do today?\n"
            <<"1-Load an existing file.\n"
            <<"2-Create a new file.\n"
            <<"3-Display file content.\n"
            <<"4-Save the loaded text to the same file again or different one.\n"
            <<"5-End.\n";
        fstream dataFile;
        char fileName[80];
        int n;
        cout<<">>> ";
        cin>>n;
        if (n==1 || n==3 || n==4)
        {
            string name;
            if(n==1)
            {
                cout<<"Enter the existing file name : ";
                cin.ignore();
                cin.getline(fileName,80);
                dataFile.open(fileName);
                if (dataFile.fail())
                {
                    cout<<"The file can not open.\n";
                    return 0;
                }
                cout << "The file " << fileName << " was loaded.\n";
                cout<<"The file content : ";
                while (!dataFile.eof() && !dataFile.fail())
                {
                    dataFile >> name;
                    cout<<name<<" ";
                }
            }
            else if (n==3)
            {
                dataFile.open(fileName);
                if (dataFile.fail())
                {
                    cout<<"The file can not open.\n";
                    return 0;
                }
                cout<<"The file content : ";
                while (!dataFile.eof() && !dataFile.fail())
                {
                    dataFile >> name;
                    cout<<name<<" ";
                }
            }
            else if (n==4)
            {
                int num;
                cout<<"1-Save the loaded text to the same file again.\n"
                    <<"2-Save the loaded text to different one.\n";
                cin>>num;
                if(num==2)
                {
                    char word[80];
                    fstream dataFile2;
                    cout<<"Enter the new file name : ";
                    cin>>word;
                    dataFile2.open(word,ios::app);
                    dataFile.open(fileName);
                    while (!dataFile.eof())
                    {
                        dataFile >> name;
                        dataFile2 << name;
                        dataFile2 << " ";
                    }
                }
            }
            cout<<endl;
            cout << "Now closing the file.\n";
            dataFile.close();
        }
        else if (n==2)
        {
            cout<<"Enter a new file : ";
            cin.ignore();
            cin.getline(fileName,80);
            dataFile.open(fileName);
            if (dataFile.fail())
            {
                cout<<"The file can not open.\n";
                return 0;
            }
            cout<<"The file "<<fileName<<" was created.\n";
            cout << "Now closing the file.\n";
            dataFile.close();
        }
        else if (n==5)
            break;
        else
            cout<<"Please enter a right number "<<endl;
        cout<<endl;
    }
    return 0;
}
