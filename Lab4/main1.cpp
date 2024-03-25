#include "CNumpy.h"
#include "Solution_Checker.h"
#include "Random_Matrix_Generator.h"
#include <unistd.h>

#define PRO_BAR_LENGTH 100

void update_bar(int percent_done){
	int num_char = percent_done * PRO_BAR_LENGTH / 100;
	printf("\rTest for hidden case: [");
	for(int i = 0; i < num_char; i++){
		printf("#");
	}
	for(int i = 0; i < PRO_BAR_LENGTH - num_char; i++){
		printf(" ");
	}
	printf("] %d%% Done", percent_done);
	fflush(stdout);
}

int main() {

    Solution_Checker checker("matrix_testcase/Q1.matrix");
    Random_Matrix_Generator rmg;

    // Part1
    // Create a CNumpy object using a file
    CNumpy m1("matrix_testcase/Q1.matrix");
    int **m1_matrix = m1.getMatrix();
    int m1_row = m1.getRow();
    int m1_col = m1.getCol();
    bool Part1_Sample_Flag = checker.Part1_Checker(m1_row, m1_col, m1_matrix);

    // Part2
    int m1_min = m1.min();
    int m1_max = m1.max();
    int minIdx1, minIdx2, maxIdx1, maxIdx2;
    m1.argmin(&minIdx1, &minIdx2);
    m1.argmax(&maxIdx1, &maxIdx2);
    bool Part2_Sample_Flag = checker.Part2_Checker(m1_min, m1_max, minIdx1, minIdx2, maxIdx1, maxIdx2);

    if(!Part1_Sample_Flag){
        cout << "Part1 Sample Fail!!!" << endl;
        return EXIT_FAILURE;
    }
    if(!Part2_Sample_Flag){
        cout << "Part2 Sample Fail!!!" << endl;
        return EXIT_FAILURE;
    }
    if(Part1_Sample_Flag && Part2_Sample_Flag){
        cout << "Sample case pass!!!" << endl;
    }

    // Check if hardcode
    int count = 0;
    vector<string> incorrect_matrix;

    for(int i = 1; i <= 100; i++){
        update_bar(i);
        string hidden_case_filename("matrix_testcase/Hidden_Matrix"+to_string(i+1)+".matrix");
        rmg.generateRandomMatrixFile(hidden_case_filename.c_str());
        Solution_Checker checker(hidden_case_filename.c_str());
        CNumpy obj(hidden_case_filename.c_str());
        bool Part1_Flag = checker.Part1_Checker(obj.getRow(), obj.getCol(), obj.getMatrix());
        int minIdx1, minIdx2, maxIdx1, maxIdx2;
        obj.argmin(&minIdx1, &minIdx2);
        obj.argmax(&maxIdx1, &maxIdx2);
        bool Part2_Flag = checker.Part2_Checker(obj.min(), obj.max(), minIdx1, minIdx2, maxIdx1, maxIdx2);
        if(Part1_Flag && Part2_Flag){
            count++;
        }
        else{
            incorrect_matrix.push_back(hidden_case_filename);
        }
        usleep(50000);
    }

    cout << endl;
    cout << "##################" << endl;
    cout << "# Grade: " << count << "/100 #" << endl;
    cout << "##################" << endl;

    if(count != 100){
        cout << "Incorrect Matrix Info: " << endl;
        for(const auto &hidden_case : incorrect_matrix){
            cout << "\t" << hidden_case << endl;
        }
        cout << "Please check matrix_testcase folder for debuging!" << endl;
    }
    return 0;
}
