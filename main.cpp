#include<iostream>
using namespace std;
#include <windows.h>
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
class ColordBox {
private:
    char **Array;
    char ch;
    int length;
    int width;
    int color;
    static int BiggestArea;

public:
    // constructors___

    // constructor to allocate dynamic array
    ColordBox(int rows, int cols) {
        length = rows;
        width = cols;
        Array = new char *[rows];
        for (int i = 0; i < rows; i++) {
            Array[i] = new char[cols];
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                Array[i][j]='#';
            }

        }
    }
    ColordBox(int rows, int cols,int w,char c) {
        length = rows;
        width = cols;

        color=w;
        Array = new char *[rows];
        for (int i = 0; i < rows; i++) {
            Array[i] = new char[cols];
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {

                SetColor(color);
                Array[i][j]=c;
            }

        }
    }



    // function to display box
    void PrintBox() {
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                SetColor(15);
                cout << Array[i][j]<<" ";
            }
            cout << endl;
        }

    }
    // function to display box transposed
    void TransBox(){
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < length; ++j) {
                SetColor(color);
                cout <<Array[j][i]<<" ";
                SetColor(15);
            }
            cout<<endl;
        }

    }
    void DisplayWider(){
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                SetColor(color);
                cout << Array[i][j]<<"  ";
                SetColor(15);
            }
            cout << endl;
        }

    }
    void displayChess(int c){
        int flag=1;

        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; j++) {
                if(flag%2==0)
                    SetColor(c);
                else
                    SetColor(color);
                cout<<Array[i][j]<<" ";
                flag++;

            }
            cout << endl;
            if(width%2==0)
                flag++;
        }
        SetColor(15);
    }
    // member function to get Area
    int GetArea(){
        int area=length*width;
        return area;

    }
    // static member function thet returns static member variable

    int getMaxArea(){
        int Max=GetArea();
        if(Max>BiggestArea){
            BiggestArea=Max;
            return BiggestArea;
            cout<<endl;
        }
    }

    //member function to set color


    // setters and getters
    void const SetCharater(char n){
        ch=n;

    }
    void const setColor(int c){
        color=c;

    }
    char GetCharacter(){
        return ch;
    }
    int GetColor(){
        return color;
    }

    // destructor

    ~ColordBox() {
        for (int i = 0; i < length; ++i) {
            delete[] Array[i];
            delete[] Array;
        }
    }

};


int ColordBox ::BiggestArea=0.0;
int main(){
    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len>>wid;
    ColordBox* cb1;
    cb1 = new ColordBox(len,wid);
    cb1->PrintBox();
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    cout<<"Displaying Transposed: "<<endl;
    cb1->TransBox();
    cout<<"Displaying Wider: "<<endl;
    cb1->DisplayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area="<<cb1->GetArea();
    cout<<endl<<"Max Area="<<cb1->getMaxArea();
    delete cb1;

    cout<<"Enter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColordBox* cb2;
    cb2 = new ColordBox(len,wid,col,boxChar);
    cb2->PrintBox();
    cout<<"Displaying Transposed: "<<endl;
    cb2->TransBox();
    cout<<"Displaying Wider: "<<endl;
    cb2->DisplayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb2->displayChess(col2);
    cout<<"Displaying original again:"<<endl;
    cb2->PrintBox();
    cout<<endl<<"Area="<<cb2->GetArea();
    cout<<endl<<"Max Area="<<cb2->getMaxArea();
    delete cb2;

    return 0;
}

