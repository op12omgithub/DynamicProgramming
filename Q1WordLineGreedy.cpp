
#include<string>
#include<list>
#include<iostream>
#include<cstdio>
using namespace std;

list<string> wordSequenceToLine(string inputstr, size_t width)
{

    size_t current = 0;
    size_t nextloc = 0;

    list<string> lines;
    string substr = inputstr.substr(current, width + 1);

    while (substr.length() == width + 1 && (nextloc = substr.rfind(' ')) != inputstr.npos) {
        lines.push_back(inputstr.substr(current, nextloc));
        current += nextloc + 1;
        substr = inputstr.substr(current, width + 1);
    }

    if (current != inputstr.length())
        lines.push_back(inputstr.substr(current, inputstr.npos));

    return lines;
}



int main(int argc, char *argv[])
{
    //input string is given below
    string input = "This is the input string the string with more values";
    printf("*******************INPUT strings****************************************\n");
    cout<<input<<endl;
    printf("\n");
    printf("*******************OUTPUT strings ****************************************\n");
    /*wordSequenceToLine(arg1,arg2)
     * arg1 --- input string
     * arg2 -- max no. of character in a line
     */
     int lineLength=10;
     printf("Single line length is %d\n",lineLength);
         printf("\n");
    list<string> lstr = wordSequenceToLine(input, lineLength);//here 10 is character width in single line

    for (auto i = lstr.begin(); i != lstr.end(); ++i)
        cout << *i << endl;
    return 0;
}
