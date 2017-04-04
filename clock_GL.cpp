#include <QCoreApplication>
#include <iostream>
#include <string>


int arr_dig[10]={ 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }; // numbers of segment in one digit



using namespace std;


//Functions of maximum and minimum energy consumption by segments

void h(int *arr, int *hours_max, int *hour_min);
void m(int *arr, int *minutes_max, int *minutes_min);
void s(int *arr, int *seconds_max, int *seconds_min);

//An improvised graph on which it is immediately clear  algorithm solution of the task. (d - digits, n - numbers)
void plot();


//That's the way the solution was offered "in the forehead". I'm sure that it can be different somehow. But in the head was this decision.
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int hours_max[2] = {0,0};
    int minutes_max[2] = {0,0};
    int seconds_max[2] = {0,0};

    int hours_min[2] = {0,0};
    int minutes_min[2] = {0,0};
    int seconds_min[2] = {0,0};



    h(arr_dig, hours_max, hours_min);
    m(arr_dig, minutes_max, minutes_min);
    s(arr_dig, seconds_max, seconds_min);
    cout<<"Max energy: "<<hours_max[0]<<hours_max[1]<<":"<<minutes_max[0]<<minutes_max[1]<<":"<<seconds_max[0]<<seconds_max[1]<<endl;
    cout<<"Min energy: "<<hours_min[0]<<hours_min[1]<<":"<<minutes_min[0]<<minutes_min[1]<<":"<<seconds_min[0]<<seconds_min[1];
    plot();

    cin.get();



    return a.exec();
}

void h(int *arr, int *hours_max, int *hours_min)
{

    for(int i = 0; i<2; i++)
    {
        if(arr[hours_max[0]] < arr[i])
            hours_max[0] = i;
        if(arr[hours_min[0]] > arr[i])
            hours_min[0] = i;
    }

    for(int i = 0; i < 10; i++)
    {
        if(arr[hours_max[1]] < arr[i])
            hours_max[1] = i;
        if(arr[hours_min[1]] > arr[i])
            hours_min[1] = i;
    }
}

void m(int *arr,int *minutes_max, int *minutes_min)
{
    for(int i = 0; i<5; i++)
    {
        if(arr[minutes_max[0]] < arr[i])
            minutes_max[0] = i;
        if(arr[minutes_min[0]] > arr[i])
            minutes_min[0] = i;
    }

    for(int i = 0; i < 10; i++)
    {
        if(arr[minutes_max[1]] < arr[i])
            minutes_max[1] = i;
        if(arr[minutes_min[1]] > arr[i])
            minutes_min[1] = i;

    }
}

void s(int *arr, int *seconds_max, int *seconds_min)
{
    for(int i = 0; i < 5; i++)
    {
        if(arr[seconds_max[0]] < arr[i])
            seconds_max[0] = i;
        if(arr[seconds_min[0]] > arr[i])
            seconds_min[0] = i;

    }
    for(int i = 0; i < 10; i++)
    {
        if(arr[seconds_max[1]] < arr[i])
            seconds_max[1] = i;
        if(arr[seconds_min[1]] > arr[i])
            seconds_min[1] = i;

    }

}

void plot()
{
    cout<<endl<<endl;
    string *web = new string[10];
    for(int i = 0; i < 10; i++)
        web[i] = ". . . . . . . . . .";
    int j = 0;
    for(int i = 0; i < 20; i+=2)
    {
        web[10 - arr_dig[j]][i] = 'O';
        j++;
    }
    cout<<endl;
    for(int i = 0; i < 10; i++)
        cout<< 9-i <<"  "<<web[i]<<endl;
    cout<<endl;
    cout<<"n/d0 1 2 3 4 5 6 7 8 9"<<endl;

    delete[]web;
}




