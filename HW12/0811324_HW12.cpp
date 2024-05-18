#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]) {
    stack<double> rpnStack;
    ifstream infile;
    infile.open(argv[1],ios::in);
    string input;
    double operand1, operand2, result;

    while (infile >> input) {
        if (input == "q") {
            if (rpnStack.empty()) {
                cout << "Error!!!" << endl;
            } 
            else {
                cout << "The top of the stack is: " << rpnStack.top() << endl;
            }
            break;
        } 
        else if (isdigit(input[0]) || (input[0] == '-' && input.length() > 1)) {
            rpnStack.push(stod(input));
        } 
        else {
            if (rpnStack.size() < 2) {
                cout << "Error!!!" << endl;
                rpnStack = stack<double>();
                break;
            }

            operand2 = rpnStack.top();
            rpnStack.pop();
            operand1 = rpnStack.top();
            rpnStack.pop();

            switch (input[0]) {
                case '+':
                    result = operand1 + operand2;
                    rpnStack.push(result);
                    break;
                case '-':
                    result = operand1 - operand2;
                    rpnStack.push(result);
                    break;
                case '*':
                    result = operand1 * operand2;
                    rpnStack.push(result);
                    break;
                case '/':
                    if (operand2 == 0) {
                        cout << "Error!!!" << endl;
                        rpnStack = stack<double>();
                        break;
                    }
                    result = operand1 / operand2;
                    rpnStack.push(result);
                    break;
                default:
                    cout << "Error!!!" << endl;
                    rpnStack = stack<double>();
                    break;
            }
        }
    }
    infile.close();

    return 0;
}