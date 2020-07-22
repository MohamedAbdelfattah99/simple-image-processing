/// FCI – Programming 1 – 2018 - Assignment 3
/// Program Name: Text Processor
/// Last Modification Date: 3/4/2017
/// Author1 and ID and Group: Muhammad Bakr Abdel Hafez
/// Author2 and ID and Group: Muhammad Ashraf badwy Moussa
/// Author3 and ID and Group: Muhammad Abdel Fattah
/// Teaching Assistant: Eng. Khadiga Khaled and Eng. Omar Khaled
/// Purpose:..........
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void Search (char []);

void Count (char []);

void Clear (char []);

void Add_word (char []);

void Replace (char []);

void Upper_case (char []);

void Lower_case (char []);

void Add_file (char []);

void Encrypt (char []);

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
            <<"5-Count the words and the characters in the file.\n"
            <<"6-Search for a word in a file.\n"
            <<"7-Empty file content.\n"
            <<"8-Add more content to the end of the file.\n"
            <<"9-Replace a word in the file with another word.\n"
            <<"10-Turn all the content file to upper case.\n"
            <<"11-Turn all the content file to lower case.\n"
            <<"12-Add another file to the end of the current file.\n"
            <<"13-Encrypt and decrypt the file.\n"
            <<"14-End.\n";
        fstream dataFile;
        char fileName[80];
        int num;
        cout<<">>> ";
        cin>>num;
        if (num==1 || num==3 || num==4 || num==5 || num==6 || num==7 || num==8 || num==9 || num==10 || num==11 || num==12 || num==13)
        {
            string name;
            if(num==1)
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
            else if (num==3)
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
            else if (num==4)
            {
                fstream dataFile2;
                int num;
                cout<<"1-Save the loaded text to the same file again.\n"
                    <<"2-Save the loaded text to different one.\n";
                cin>>num;
                if(num==2)
                {
                    char word[80];
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
                cout<<"File saved.\n"
                    <<"Now closing the file.\n";
                dataFile.close();
                dataFile2.close();
            }
            else if (num==5)
            {
                Count(fileName);
            }
            else if (num==6)
            {
                Search(fileName);
            }
            else if (num==7)
            {
                Clear(fileName);
            }
            else if (num==8)
            {
                Add_word(fileName);
            }
            else if (num==9)
            {
                Replace(fileName);
            }
            else if (num==10)
            {
                Upper_case(fileName);
            }

            else if (num==11)
            {
                Lower_case(fileName);
            }
            else if (num==12)
            {
                Add_file(fileName);
            }
            else if (num==13)
            {
                Encrypt(fileName);
            }
            cout<<endl;
        }
        else if (num==2)
        {
            cout<<"Enter a new file : ";
            cin.ignore();
            cin.getline(fileName,80);
            dataFile.open(fileName, ios::out);
            if (dataFile.fail())
            {
                cout<<"The file can not open.\n";
                return 0;
            }
            cout<<"The file "<<fileName<<" was created.\n"<<"Now closing the file.\n";
            dataFile.close();
            cout<<"Done.\n";
        }
        else if (num==14)
            break;
        else
            cout<<"Please enter a right number "<<endl;
        cout<<endl;
    }
    return 0;
}




void Count (char fileName[])
{
    int sum=0;
    ifstream damn;
    damn.open(fileName , ios::in);
    string word;
    int words=0;
    while(damn>>word)
    {
        ++words;
        sum+=word.size();
    }
    cout<<"The number of words is :"<<words<<endl;
    cout<<"The number of char is  : "<<sum<<endl;
    cout <<"Now closing the file.\n";
    damn.close();
}




void Search (char fileName[])
{
    int x=0;
    string word;
    ifstream damn;
    damn.open(fileName);
    if(!damn.is_open())
    {
        cout<<"The file can not open.\n";
    }
    else
        cout<<"The file opened.\n";
    cout<<"Enter your word : ";
    string line;
    cin>>word;
    while(!damn.fail() && !damn.eof())
    {
        damn >> line;
        if(line==word)
            x=1;
    }
    if(x)
        cout<<"Word is found in the file :) "<<endl;
    else
        cout<<"Word is not found in the file :(";
    cout<<"Now closing the file.\n";
    damn.close();
    cout<<"Done.\n";
}




void Clear (char fileName[])
{
    fstream datafile;
    datafile.open(fileName , ios::out);
    if(datafile.fail())
        cout<<"The file can not open.\n";
    else
    {
        cout<<"The file opened.\n"<<"Now emptying the file.\n"<<"Now closing the file.\n";
    }
    datafile.close();
    cout<<"Done.\n";
}




void Add_word (char fileName[])
{
    ofstream dataFile;
    string name;
    dataFile.open(fileName,ios::app);
    if (dataFile.fail())
    {
        cout<<"The file can not open.\n";
    }
    else
    {
        cout<<"The file opened.\n"<<"Enter the file content : "<<endl;
        cout<<"If you want to exit press 1\n";
        while ( cin >> name)
        {
            if(name=="1")
            {
                break;
            }
            dataFile << " ";
            dataFile << name;
        }
        cout<<"Now closing the file.\n";
        dataFile.close();
        cout<<"Done.\n";
    }
}




void Replace (char fileName[])
{
    fstream dataFile;
    string name , word , new_word;
    vector<string> test;
    dataFile.open(fileName);
    if(dataFile.fail())
    {
        cout<<"The file can not open.\n";
    }
    else
    {
        cout<<"File opened.\n"<<"Please enter the existing word : ";
        cin>>word;
        cout<<"Please enter the new word : ";
        cin >> new_word;
        cout<<"Now replacing the existing word.\n";
        while (!dataFile.fail() && !dataFile.eof())
        {
            dataFile >> name;
            test.push_back(name);
        }
        dataFile.close();
        dataFile.open(fileName,ios::out);
        for(int i=0 ; i<test.size() ; i++)
        {
            if (test[i]==word)
                test[i]=new_word;
        }
        for(int i=0 ; i<test.size()-1 ; i++)
        {
            dataFile << test[i];
            dataFile << " ";
        }
        cout<<"Now closing file.\n";
        dataFile.close();
        cout<<"Done.\n";
    }

}




void Upper_case (char fileName[])
{
    fstream dataFile;
    string name;
    vector<string> test;
    dataFile.open(fileName);
    if(dataFile.fail())
    {
        cout<<"The file can not open.\n";
    }
    else
    {
        cout<<"The file opened.\n"<<"Now turning all the file content to upper case.\n";
        while (!dataFile.fail() && !dataFile.eof())
        {
            dataFile >> name;
            test.push_back(name);
        }
        dataFile.close();
        dataFile.open(fileName,ios::out);
        for(int i=0 ; i<test.size() ; i++)
        {
            for(int j=0 ; j<test[i].size() ; j++)
            {
                if(test[i][j]>=97)
                    test[i][j]-=32;
            }
        }
        for(int i=0 ; i<test.size()-1 ; i++)
        {
            dataFile << " ";
            dataFile << test[i];
        }
        cout<<"Now closing file.\n";
        dataFile.close();
        cout<<"Done.\n";
    }
}




void Lower_case (char fileName[])
{
    fstream datafile;
    vector<string> name;
    string word;
    datafile.open(fileName);
    if (datafile.fail())
    {
        cout<<"The file can not open.\n";
    }
    else
    {
        cout<<"The file opened.\n"<<"Now turning all content to lower case.\n";
        while (!datafile.fail() && !datafile.eof())
        {
            datafile >> word;
            name.push_back(word);
        }
        for(int i=0 ; i<name.size() ; i++)
        {
            for(int j=0; j<name[i].size() ; j++)
            {
                if(name[i][j]<97)
                    name[i][j]+=32;
            }
        }
        datafile.close();
        datafile.open(fileName, ios::out);
        for(int i=0 ; i<name.size() ; i++)
        {
            datafile << name[i];
            datafile << " ";
        }
        cout<<"Now closing the file.\n";
        datafile.close();
        cout<<"Done.\n";
    }
}




void Add_file(char fileName[])
{
    char File1[80] , File2[80] , ch ;
    ofstream dataFile2 ;
    ifstream dataFile1 ;
    cout<<"Enter file 1 name : ";
    cin>>File1;
    cout<<"Enter file 2 name : ";
    cin>>File2;
    dataFile1.open(File1);
    dataFile2.open(File2 , ios::app);
    if (dataFile1.fail() || dataFile2.fail())
        cout<<"One of the file can not open.\n";
    else
    {
        cout<<"Both files are opened.\n"<<"Now copying file 1 content to file 2 .\n";
        while (!dataFile1.eof())
        {
            dataFile1.get(ch);
            dataFile2 << ch;
        }
        cout<<"Now closing the files.\n";
        dataFile1.close();
        dataFile2.close();
        cout<<"Done.\n";
    }
}




void Encrypt (char fileName[])
{
    int num;
    fstream datafile1;
    vector<string>data;
    string data2;
    datafile1.open(fileName,ios::in);
    if  (datafile1.fail())
    {
        cout<<"The file can not open.\n";
    }
    else
    {
        cout<<"The file opened.\n"<<"1-Encrypt.\n"<<"2-Decrypt.\n"<<">>> ";
        cin>>num;
        if(num==1)
            cout<<"Now encrypt the file content.\n";
        else
            cout<<"Now decrypt the file content.\n";
        while (!datafile1.fail() && !datafile1.eof())
        {
            datafile1>>data2;
            data.push_back(data2);

        }
        for (int r=0; r<data.size(); r++)
        {
            for (int s=0; s<data[r].size(); s++)
            {

                if (data[r][s] >= 'A' && data[r][s] <= 'M')
                {
                    data[r][s] =data[r][s] + 13;
                }
                else if (data[r][s]>='N'&& data[r][s]<='Z')
                {
                    data[r][s]=data[r][s]-13;
                }
                else if (data[r][s] >= 'a' && data[r][s] <= 'm')
                {
                    data[r][s] =data[r][s] + 13;

                }
                else if (data[r][s]>='n'&& data[r][s]<='z')
                {
                    data[r][s]=data[r][s]-13;
                }
            }
        }
        datafile1.close();
        datafile1.open(fileName,ios::out);
        for(int k=0 ; k<data.size()-1 ; k++)
        {
            datafile1 << data[k];
            datafile1 << " ";
        }
        cout<<"Now closing the file.\n";
        datafile1.close();
        cout<<"Done.\n";
    }
}
