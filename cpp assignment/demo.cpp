#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <getopt.h>


using namespace std;


string getSubstring(string data, int pos, int size){
    return data.substr(pos,size);
}

void printDetails(vector<string> vect){
    
    for (string x : vect)
        cout << x << "\n";
}

// void commandlineArgs(int argc, char **argv){
//     const char* const short_opts = "i:o:nmut";
//      const option long_opts[] = {
//             {"input_file", required_argument, nullptr, 'i'},
//             {"output_file", required_argument, nullptr, 'o'},
//             {"nickname", no_argument, nullptr, 'n'},
//             {"matchcode", no_argument, nullptr, 'm'},
//             {"uppercase", no_argument, nullptr, 'u'},
//             {"titlecase", no_argument, nullptr, 't'},            
//             {nullptr, no_argument, nullptr, 0}
//     };
// }

string trimString(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;

}

string addWhiteSpaces(int count){
    string temp_str;
    for(int i=0; i<count;i++){
        temp_str = temp_str +  ' '; 
    }
    return temp_str;
}

vector<string>stringFormat(vector<string> vect){

    vector<string> result;
    for (int i=0;i<vect.size(); i=i + 9) {
        

        string lstr = trimString(vect[i]); 
        int lwhiteSpaceLength = 15 - lstr.size();

        string fstr = trimString(vect[i+1]); 
        int fwhiteSpaceLength = 15 - fstr.size();
        
        
        string name, address1, address2;


        name = fstr + ' ' + lstr + addWhiteSpaces(lwhiteSpaceLength + fwhiteSpaceLength);

        cout << name <<'\n';
        string houseStr = trimString(vect[i+4]);
        int housewhiteSpaceLength = 5 - houseStr.size();

        string streetStr = trimString(vect[i+5]);
        int streetwhiteSpaceLength = 20 - streetStr.size();

        address1 = houseStr + ' ' + streetStr + addWhiteSpaces(housewhiteSpaceLength + streetwhiteSpaceLength);

        cout << address1<< "\n";

        string cityStr  = trimString(vect[i+6]);
        int citywhiteSpaceLength = 15 - streetStr.size();

        string stateStr  = trimString(vect[i+7]);
        int statewhiteSpaceLength = 15 - stateStr.size();

        string zipStr  = trimString(vect[i+8]);
        int zipwhiteSpaceLength = 6 - zipStr.size();
        address2 = cityStr + ", " + stateStr + ' ' + zipStr + addWhiteSpaces(citywhiteSpaceLength + statewhiteSpaceLength + zipwhiteSpaceLength);


        cout << address2<< "\n";
        result.push_back(name);
        result.push_back(address1); 
        result.push_back(address2); 

    }
    return result;
}



void envelopeFormat(string name, string address1, string address2){
    cout << name + "\n" + address1 + "\n" + address2 << "\n";
}

void fixedFormat(string name, string address1, string address2){
    cout << name  + address1  + address2 << "\n";
}

void fixedFormatCSV(string name, string address1, string address2){
    cout << "\"" + trimString(name) +"\"," + "\""  + trimString(address1)  +"\"," +  "\"" + trimString(address2)  +"\""<< "\n";
}

int main(int argc, char **argv)
{
    
    string fileName = argv[1], content;
    fstream inputFile;
    inputFile.open(fileName);
    vector<string> allDetails;

    // commandlineArgs(argc, argv);

    if(inputFile.is_open())
    {
        while(getline(inputFile, content)){ 

            allDetails.push_back(getSubstring(content, 0, 15)); //lm
            allDetails.push_back(getSubstring(content, 15, 15));
            allDetails.push_back(getSubstring(content, 30, 15));
            allDetails.push_back(getSubstring(content, 45, 10));
            allDetails.push_back(getSubstring(content, 55, 5));
            allDetails.push_back(getSubstring(content, 60, 20));
            allDetails.push_back(getSubstring(content, 80, 15));
            allDetails.push_back(getSubstring(content, 95, 15));
            allDetails.push_back(getSubstring(content, 110, 6));
        }
    }
    else{
        cout << "Unable to open file";
    }
    // printDetails(allDetails);

    vector<string> result = stringFormat(allDetails);

    // Envelope method
    for (int i=0;i<result.size(); i=i + 3) {
        envelopeFormat(result[i], result[i+1], result[i+2]);
    }

    // Fixed method
    for (int i=0;i<result.size(); i=i + 3) {
        fixedFormat(result[i], result[i+1], result[i+2]);
    }

    // Fixed format with csv
    for (int i=0;i<result.size(); i=i + 3) {
        fixedFormatCSV(result[i], result[i+1], result[i+2]);
    }


    return 0;
}