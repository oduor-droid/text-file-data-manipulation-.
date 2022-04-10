
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
string Data;

class Cars
{
    private:
        string VIN;
        string Make;
        string Model;
        int Year;
        int Price;
    public:
        Cars()
        {
            VIN = " ";
            Make =" ";
            Model= " ";
            Year = 0;
            Price = 0;
        }
        Cars(string newVIN, string newMake, string newModel, int newYear, int newPrice)
        {
            VIN = newVIN;
            Make = newMake;
            Model = newModel;
            Year = newYear;
            Price = newPrice;
        }
        void setVIN(string newVIN)
        {
            VIN = newVIN;
        }
        string getVIN()
        {
            return VIN;
        }
        void setMake(string newMake)
        {
            Make = newMake;
        }
        string getMake()
        {
            return Make;
        }
        void setModel(string newModel)
        {
            Model = newModel;
        }
        string getModel()
        {
            return Model;
        }
        void setPrice(int newPrice)
        {
            Price = newPrice;
        }
        int  getPrice()
        {
            return Price;
        }
        void setYear(int newYear)
        {
            Year = newYear;
        }
        int getYear()
        {
            return Year;
        }
        void Print()
        {
            cout<<VIN<<" "<<Make<<" "<<Model<<" "<<Year<<" "<<Price;
        }

};

void readfile(void){ // reads the whole textfile
    fstream myfile;
    myfile.open(Data, ios::in);
    if (myfile.is_open()){
        string contents;
        while(getline(myfile, contents)){
            cout << contents << "\n";
        }
        myfile.close();
    }
}

void Process(void)
{
    string docSize;
    ifstream stream(Data);
    getline(stream, docSize);//reaqding the first line to get number of elements
    int len = stoi(docSize);// converting string to int

    string VIN [len];
    string Make [len];
    string Model [len];
    int Year [len];
    double Price [len];

    //will be used for sorting Car Prices
    double PriceCopy[len];

    while(!stream.eof())
    {
        for(int i =0; i < len; i++)
        {
            stream >> VIN[i] >>Make[i] >> Model[i] >> Year[i] >> Price[i];
            //cout<<Make[i]<<"\n";
            PriceCopy[i] =Price[i];
        }
    }
        for(int i =0; i < len; i++)
        {
            if(Make[i] == "Toyota")//getting all toyota make
            {
                cout<<Make[i]<<" "<<Model[i]<<"\n";
            }
        }
        cout<<"\n";
        sort(PriceCopy,PriceCopy+len);//sorting in accending order
        cout<<"\nThe 5 least Expensive Cars are:";
        for(int i =0; i< len; i++) //Printing the 5 Least Expensive cars
        {
        if(Price[i] == PriceCopy[0])
        cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
        if(Price[i] == PriceCopy[1])
        cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
        if(Price[i] == PriceCopy[2])
        cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
        if(Price[i] == PriceCopy[3])
        cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
        if(Price[i] == PriceCopy[4])
        cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
        }

        cout<<"\n\n";
        sort(PriceCopy, PriceCopy+len, greater<int>());//sorting in deccending order
        cout<<"The 5 most Expensive Cars:";
        for(int i = 0; i < len; i++)
        {
            if(Price[i] == PriceCopy[0])
            cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
            if(Price[i] == PriceCopy[1])
            cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
            if(Price[i] == PriceCopy[2])
            cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
            if(Price[i] == PriceCopy[3])
            cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
            if(Price[i] == PriceCopy[4])
            cout<<"\n"<<Make[i]<<" "<<Model[i]<<" "<<Year[i]<<" "<<Price[i];
        }
        cout<<"\n";


}

int main(){
    int choice;
    cout<<"\t\t\t !!!!Welcome to the dealership!!!!! "<<endl;
    cout<<"\n1. Display Available Data;\n2. Add new Data: \n";
    cout<<"choose One option (press 1 or 2): ";
    cin>>choice;
    cout<<"\n\n";

    if(choice == 1)
    {
        cout<<"Enter flename to proccess(include the .txt): ";
        cin>>Data;
        void readfile(); readfile();
        void Process(); Process();
    }
    else if(choice==2)
    {
        Cars car;
        Cars car1;
        string VIN, Make, Model;
        int Year, Price;

        cout<<"\nEnter new car VIN: ";
        cin>>VIN;
        cout<<"Enter new car Make: ";
        cin>>Make;
        cout<<"Enter new car Model: ";
        cin>>Model;
        cout<<"Enter new car Year of Manufacture: ";
        cin>>Year;
        cout<<"Enter new car Price: ";
        cin>>Price;

        car1.setVIN(VIN);
        car1.setMake(Make);
        car1.setModel(Model);
        car1.setYear(Year);
        car1.setPrice(Price);

        cout<<car1.getVIN()<<" "<<car1.getMake()<<" "<<car1.getModel()<<" "<<car1.getYear()<<" "<<car1.getPrice();
        cout<<"\n";
        int des;
        cout<<"\nDo you wish to append the new car details to the main fail(1 to append 0 to quit): ";
        cin>>des;
        if(des ==1)
        {
            ofstream myFile;
            myFile.open("New.txt", ios::app);
            myFile.write((char*)&car1, sizeof(car1));
        }
        else if(des ==0)
        {
            exit(10);
        }
        else
            cout<<"Invalid choice";
    }
    else
        cout<<"\nInvalid choice try again!!";


}


