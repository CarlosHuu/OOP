#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include<iomanip>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile;
    infile.open(argv[1],ios::in);

    map<string, pair<int, int>> movie;
    string line;
    int line_count = 0;
    int n = 0;
    string movie_name;
    int review;

    if (getline(infile,line)) n = stoi(line);

    while (n--){
        if (getline(infile, line)) movie_name = line;
        if (getline(infile, line)) review = stoi(line);
        if (movie.find(movie_name) == movie.end()) movie[movie_name] = make_pair(review, 1);
        else {
            movie[movie_name].first += review;
            movie[movie_name].second += 1;
        }
    }

    for (auto it = movie.begin(); it!=movie.end(); it++){
        cout << it->first << ": ";
        if(it->second.second!=1)
        cout << it->second.second << " reviews, average of ";
        else
        cout << it->second.second << " review, average of ";
        if(it->second.first % (it->second.second)!=0)
        cout << fixed << setprecision(1) << it->second.first / (it->second.second * 1.0);
        else
        cout << it->second.first / (it->second.second);
        cout << " / 5"<< endl;
    }
    infile.close();

    return 0;
}