#include "net/serversocket.cpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "Header.h"



double calcParse(string msg) {
    string num1,op;
    double x, y, num[100], sum = 0; //num array for the last calculation
    int n = 0, o = 0;//n counter for num and o for op
    char ch;//op array for the symbol operation
    while (true) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~CALCULATOR~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "     between each operator ('+','-','*','/') enter space" << endl;
        cout << "factorial= !(x) || power= p(x,y)  || cosine= c(x) || sine= s(x)" << endl;
        cout << "             for result enter space + '='" << endl;
        cout << "            e.g. f(x)= 5 * !(2) + 4 - p(2,4) = " << endl << endl;
        
        
        clr(num);
        cout << "f(x)= "+msg;
        istringstream istr(msg);
        istr >> num1 >> ch;
        x = detec(num1);
        num[n] = x; n++;
        while (ch != '=') {
            
            istr >> num1;
            y = detec(num1);
            if (ch == '*' || ch == '/') {
                
                num[n - 1] = operation(ch, x, y);
                x = num[n - 1];
                //n++;
            }
            else if (ch == '-' || ch == '+') {
                num[n] = y; n++;  x = y;
                op += ch;
            }
            //x=num[n];
            istr >> ch;
        }
        
        op += ch;
        o = 0; n = 0;
        sum = num[0];
        
        //sum rest of the numbers
        while (op[o] != '=') {
            sum = operation(op[o], sum, num[n + 1]);
            //cout << sum << endl;
            ++o; ++n;
        }
        return sum;
        cout <<"f(x)= " << sum << endl;
        cout << "again? Y/N: ";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
            return 0;
        else
            clear();
        
    }
    system("pause");
    return 0;
}

int main(){
    net::serversocket* server = new net::serversocket(8080);
    int err = server->listen();
    string msg;
    
    if (err != 0) {
        cerr << strerror(err) << std::endl;
        exit(err);
    }
    
    while (true) {
        net::socket* client = server->accept();
        while (true) {
            client->read(msg);
            if (msg!=""){
                double foo = calcParse(msg);
                cout << foo << endl;
                client->send("Result = " + to_string(foo)+ '\n');
//                cout<<msg;
            }
            msg = "";
            if (!client->valid()) {
                break;
            }
        }
        delete client;
        continue;
    }
    
    return 0;
}
