/*
    CWID: 885191064
    Environment Requirement: g++ compiler to compile code in c++ language
    Commands to run:
    Open the terminal in the folder where file is present.
    In terminal enter following commands: 
    --> g++ CPSC485_hardik_bhawsar.cpp
    --> ./a.out
    Enter the first word: word1
    Enter the second word: word2
*/

#include <iostream>
using namespace std;

int ed_matrix[100][100];

//Function to calculate and return minimum value from two values
int minimum_value(int value_1,int value_2)
{
    int res;
    if(value_1 > value_2)
        res = value_2;
    else
        res = value_1;
    return res;
}

//Function to calculate and print edit distance matrix
void edit_distance_calculation(string string1,string  string2)
{
    int length_1, length_2;
    length_1=string1.size(),
    length_2=string2.size();

    //Calculating the edit distance matrix
    for(int i=0;i<=length_1;i++){
        for(int j=0;j<=length_2;j++){
           if(i==0)
               ed_matrix[i][j]=j;
           else if(j==0)
               ed_matrix[i][j]=i;
           else if(string1[i-1]==string2[j-1])
               ed_matrix[i][j]=ed_matrix[i-1][j-1];
           else
               ed_matrix[i][j]= minimum_value(ed_matrix[i-1][j], minimum_value(ed_matrix[i][j-1],ed_matrix[i-1][j-1])) + 1;
       }
    }

    //Priting the edit distance matrix
    cout<<"The matrix: "<<endl<<endl;
    cout<<"     ";
    for(int j=0; j<=length_2;j++){
        cout<<j<<"   ";
    }
    cout<<endl<<"    ";
    for(int j =0; j<=length_2;j++){
        cout<<"----";
    }
    cout<<endl;

    for(int i=0;i<=length_1;i++){
        cout<<i<<" |  ";
        for(int j=0;j<=length_2;j++){
           cout<<ed_matrix[i][j]<<" : ";
        }
        cout<<endl<<"   ";
        for(int j =0; j<=length_2;j++){
            cout<<"----";
        }
        cout<<endl;
    }

    //Calculating the alignment
    string alignment_result[2];
    int i = length_1, j = length_2;
    while(i > 0 || j > 0) {
        if(i > 0 && j > 0 && string1[i-1] == string2[j-1]) {
            alignment_result[0] = string1[i-1] + alignment_result[0];
            alignment_result[1] = string2[j-1] + alignment_result[1];
            i--;
            j--;
        } else {
            if(i > 0 && ed_matrix[i][j] == ed_matrix[i-1][j] + 1) {
                alignment_result[0] = string1[i-1] + alignment_result[0];
                alignment_result[1] = "_" + alignment_result[1];
                i--;
            } else if(j > 0 && ed_matrix[i][j] == ed_matrix[i][j-1] + 1) {
                alignment_result[0] = "_" + alignment_result[0];
                alignment_result[1] = string2[j-1] + alignment_result[1];
                j--;
            } else {
                alignment_result[0] = string1[i-1] + alignment_result[0];
                alignment_result[1] = string2[j-1] + alignment_result[1];
                i--;
                j--;
            }
        }
    }
    
    //Printing the edit distance and alignment string
    cout<<endl<<"The edit distance is "<<ed_matrix[length_1][length_2]<<endl<<endl;
    cout << "Alignment is:" << endl;
    cout << alignment_result[0] << endl << alignment_result[1];
}

int main()
{
    string word1,word2;
    //Accepting first and second word
    cout<<"Enter the first word: ";
    cin>>word1;
    cout<<"Enter the second word: ";
    cin>>word2;
    
    //Function call to calculation edit distance
    //Passing word1 and word2 as  arguments
    edit_distance_calculation(word1, word2);
return 0;
}

