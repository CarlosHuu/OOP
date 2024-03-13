#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

struct Block {
    string name;
    int width=0;
    int height=0;
    char judge=' ';
    bool soft;
};
void softblock(int mutip,double lower, double upper,ofstream& op);
bool compareBlocks(const Block& b1, const Block& b2) {
    return b1.name < b2.name;
}

int main(int argc, char* argv[]) {
    
    ifstream infile;
    ofstream oup;
    infile.open(argv[1],ios::in);
    oup.open(argv[2],ios::out);
    
    double minAspectRatio, maxAspectRatio;
    infile >> minAspectRatio >> maxAspectRatio;
    
    vector<Block> blocks;
    string line;
    int i=0;
    while (getline(infile, line)) {
        i++;
        if (i==1)
            continue;
        istringstream iss(line);
        Block block;
        iss >> block.name >> block.width >> block.height >> block.judge;
        
        if (block.judge == 'S') {
            block.soft = true;
        } else {
            block.soft = false;
        }
        blocks.push_back(block);
    }

    sort(blocks.begin(), blocks.end(), compareBlocks);
    
    for (const auto& block : blocks) {
        oup << block.name << " ";
        if (block.soft) {
            softblock(block.width * block.height,minAspectRatio ,maxAspectRatio,oup);
        } 
        else {
            if(block.width<block.height){
                oup << "{" << block.width << "," << block.height << "} ";
                oup << "{" << block.height << "," << block.width << "} ";
            }
            if(block.width>block.height){
                oup << "{" << block.height << "," << block.width << "} ";
                oup << "{" << block.height << "," << block.width << "} ";
            }
            if(block.width==block.height)
                oup << "{" << block.height << "," << block.width << "} ";
            
        }
        oup << endl;
        
    }
    infile.close();
    oup.close();

}
void softblock(int mutip,double lower, double upper,ofstream& op){
    int i=1;
    int j=0;
    
    while(1){
        if(mutip%i==0){
            j=mutip/i;
            double ratio= static_cast<double>(i)/j;
            if((ratio >= lower) && (ratio <= upper))
                op<<"{"<<i<<","<<j<<"}"<<" ";
            else if(ratio>upper)
                break;
        }
        i++;
    }

}