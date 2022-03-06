#include<string>
#include<list>
#include<iostream>
#include<cstdio>
using namespace std;

list<string> wordSequenceToLine(string inputstr, int width)
{

    int curpos = 0;
    int nextpos = 0;

    list<string> lineList;
    string substr = inputstr.substr(curpos, width + 1);

    while (substr.length() == width + 1 && (nextpos = substr.rfind(' ')) != inputstr.npos) {
        lineList.push_back(inputstr.substr(curpos, nextpos));
        curpos += nextpos + 1;
        substr = inputstr.substr(curpos, width + 1);
    }

    if (curpos != inputstr.length())
        lineList.push_back(inputstr.substr(curpos, inputstr.npos));

    return lineList;
}



int main(int argc, char *argv[])
{
    //input string is given below
    string input = "The India is great country . we are proud on it .";

    cout<<"**************************input string**********************************"<<endl;
    cout<<input<<endl<<endl;
    cout<<"************************************************************************"<<endl<<endl;
    /*wordSequenceToLine(line,lineLength)
     * line --- input string
     * lineLength -- max no. of character in a line
     */
     int lineLength=10;  //here 10 is character width in a single line
    list<string> l = wordSequenceToLine(input, lineLength);
        cout<<"length of single line is "<<lineLength<<"   characters"<<endl;
        cout<<"**************************output string**********************************"<<endl;

    for (auto i = l.begin(); i != l.end(); ++i)
        cout << *i << endl;
    return 0;
}
