# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>
# include <cctype>

using namespace std;

int main(){
    ifstream input;
    ofstream output;
    string filename_input, filename_output;
    string word;

    cout << "Please enter the filename: ";
    cin >> filename_input;

    input.open(filename_input);
    if(input.fail()){
        cout<< "File \"" << filename_input <<"\" does not exist.";
        exit(1);
    }

    cout << "Please enter the output filename: ";
    cin >> filename_output;


    int count = 0;
    while(input>>word){
        count++;
    }
    input.close();

    int chracters = 0 , nonwhitespace = 0, letters = 0;
    char next;
    input.open(filename_input);
    while(input.get(next)){
        if(!isspace(next))
            nonwhitespace++;
        if(isalpha(next))
            letters++;
        chracters++;
    }
    cout << "Total number of words: " << count << endl;
    cout << "Total number of characters: " << chracters << endl;
    cout << "Total number of non-whitespace characters: " << nonwhitespace << endl;
    cout << "Total number of letters: " << letters << endl;

    output.open(filename_output);
    output << "Total number of words: " << count << endl;
    output << "Total number of characters: " << chracters << endl;
    output << "Total number of non-whitespace characters: " << nonwhitespace << endl;
    output << "Total number of letters: " << letters << endl;

    input.close();
    output.close();
    return 0;
}