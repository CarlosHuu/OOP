#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BasicTicket
{
public:
    BasicTicket();
    BasicTicket(string theName, string DepCity, string ArrCity, int FlightNum, double price);
    // void setName(string newName);
    // void setDepCity(string newDepCity);
    // void setArrCity(string newArrCity);
    // void setFlightNum(int newFlightNum);
    // void setPrice(double newPrice);
    // string getName();
    // string getDepCity();
    // string getArrCity();
    // int getFlightNum();
    double getPrice() const;

private:
    string passenger_name;
    string departure_city;
    string arrival_city;
    int flight_number;
    double ticket_price;

};
BasicTicket::BasicTicket() : passenger_name("None"), departure_city("None"), arrival_city("None"), 
                            flight_number(0), ticket_price(0)
{}
BasicTicket::BasicTicket(string theName, string DepCity, string ArrCity, int FlightNum, double price) 
{ 
    passenger_name = theName;
    departure_city = DepCity;
    arrival_city = ArrCity;
    flight_number = FlightNum;
    ticket_price = price;
}
// void BasicTicket::setName(string newName){
//     passenger_name = newName;
// }
// void BasicTicket::setDepCity(string newDepCity){
//     departure_city = newDepCity;
// }
// void BasicTicket::setArrCity(string newArrCity){
//     arrival_city = newArrCity;
// }
// void BasicTicket::setFlightNum(int newFlightNum){
//     flight_number = newFlightNum;
// }
// void BasicTicket::setPrice(double newPrice){
//     ticket_price = newPrice;
// }
double BasicTicket::getPrice() const { 
    return ticket_price;
}

class PremiumTicket : public BasicTicket
{
    public:
        PremiumTicket();
        PremiumTicket(string theName, string DepCity, string ArrCity, int FlightNum, double price, int seatNum);
        double getPrice() const;
        
    private:
        int seat_number;
};

PremiumTicket :: PremiumTicket():BasicTicket(), seat_number(0){}
PremiumTicket :: PremiumTicket(string theName, string DepCity, string ArrCity, int FlightNum, double price, int seatNum):
BasicTicket(theName, DepCity, ArrCity, FlightNum, price),seat_number(seatNum){}
double PremiumTicket::getPrice() const { 
    return (BasicTicket::getPrice()*1.1);
}


int main(){
    int numberOfPassenger;
    vector<int> cost;
    int totalCost = 0;
    string name;
    string DepCity;
    string ArrCity;
    int FlightNum;
    double price;
    int seatNum;
    cout << "number of passenger" << endl;
    cin >> numberOfPassenger;
    for (int i = 0 ; i <numberOfPassenger ; ++i){
        cout << "information" << endl;
        cin >> name;
        cin >> DepCity;
        cin >> ArrCity;
        cin >> FlightNum;
        cin >> price;
        cin >> seatNum;
        if (seatNum==0){
            BasicTicket ticket(name, DepCity, ArrCity, FlightNum, price);
            cost.push_back(ticket.getPrice());
        }
        else {
            PremiumTicket ticket(name, DepCity, ArrCity, FlightNum, price, seatNum);
            cost.push_back(ticket.getPrice());
        }   
    }
    cout << "Price of both tickets :" << endl;
    for (unsigned  i = 0; i < cost.size(); ++i){
        cout << cost[i] << endl;
        totalCost += cost[i];
    }
    cout << "Total cost of all tickets: " << totalCost;
}
