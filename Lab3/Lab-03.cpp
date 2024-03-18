# include <iostream>
# include <fstream>
# include <vector>
# include <queue>
using namespace std;

int main(int argc, char* argv[]){
    
    ifstream infile;
    infile.open(argv[1],ios::in);
    int **maze = new int*[5];
    for (int i =0; i < 5 ; i++){
        maze[i] = new int[5];
    }
    for (int i =0 ;i<5 ;i++){
        for (int j=0; j <5 ;j++){
            infile >> maze[i][j];
        }
    }
    int **mos_inf = new int*[25];
    for (int i =0; i < 25 ; i++){
        mos_inf[i] = new int[2];
    }
    for (int i =0 ;i<25 ;i++){
        for (int j=0; j <2 ;j++){
            infile >> mos_inf[i][j];
        }
    }
    // for (int i =0 ;i<5 ;i++){
    //     for (int j=0; j <5 ;j++){
    //         cout << maze[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for (int i =0 ;i<25 ;i++){
    //     for (int j=0; j <2 ;j++){
    //         cout << mos_inf[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    queue <char> move;
    char xx;
     while(infile>>xx){
        move.push(xx);
    }
   
    // while (!move.empty()){
    //     cout << move.front()<<" ";
    //     move.pop();
    // }

    int hp =100;
    int exp = 0;
    int level =1;
    int step =0;
    int get_inf=0;
    int x=0;
    int y=0;

    while (1){
        step++;
        if (move.front() == 'U'){
            move.pop();
            x--;
            get_inf=maze[x][y];
            hp=hp-mos_inf[get_inf][0];
            if(hp<=0) {
                cout << "DEAD";
                break;
            }
            exp=exp+mos_inf[get_inf][1];
        }
        else if (move.front() == 'D'){
            move.pop();
            x++;
            get_inf=maze[x][y];
            hp=hp-mos_inf[get_inf][0];
            if(hp<=0) {
                cout << "DEAD";
                break;
            }
            exp=exp+mos_inf[get_inf][1];
        }
        else if (move.front() == 'L'){
            move.pop();
            y--;
            get_inf=maze[x][y];
            hp=hp-mos_inf[get_inf][0];
            if(hp<=0) {
                cout << "DEAD";
                break;
            }
            exp=exp+mos_inf[get_inf][1];
        }
        else if (move.front() == 'R'){
            move.pop();
            y++;
            get_inf=maze[x][y];
            hp=hp-mos_inf[get_inf][0];
            if(hp<=0) {
                cout << "DEAD";
                break;
            }
            exp=exp+mos_inf[get_inf][1];
        }
        
        if(exp>=100){
            level++;
            hp=100;
            exp=0;
        }
        
        if(hp<=0)
            break;
        
        cout<<"step "<<step<<":"<<endl;
        cout<<"level:"<<level<<" hp:"<<hp<<" exp:"<<exp<<endl;
        if(move.empty())
            break;
    }
    
    

    for (int i = 0; i <5; i++){
        delete [] maze[i];
    }
    delete [] maze;
    for (int i = 0; i <2; i++){
        delete [] mos_inf[i];
    }
    delete [] mos_inf;
    
}