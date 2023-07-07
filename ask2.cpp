#include <iostream>
using namespace std;


// error() simply disguises throws:
inline void error(const string& s)
{
    throw runtime_error(s);
}

class car{
    private:         //privet members

        short int ProblemTires;
        short int PaintPercentage;
        short int ProblemLights;

    public:

        car(){               //new car constractor
            ProblemTires = 0;
            PaintPercentage = 0;
            ProblemLights = 0;
        }

        car(short int Tires, short int Paint, short int Lights){      //old car constractor
            try{   //check is valid for each value
                ProblemTires = Tires;
                if ( Tires < 0 || Tires > 4 ) throw Tires;
            }catch( short int Tires){
                cerr << "\nIncorect imput for tires you gave " << Tires << endl;
                error("Incorect imput for tires");
            }

            try{
                PaintPercentage = Paint;
                if ( Tires < 0 || Tires > 100) throw Paint;
            }catch( short int Paint){
                cerr << "\nIncorect imput for Paint you gave " << Paint << endl;
                error("Incorect imput for paint");
            }

            try{
                ProblemLights = Lights;
                if ( Tires < 0 || Tires > 8) throw Lights;
            }catch( short int Lights){
                cerr << "\nIncorect imput for tires you gave " << Lights << endl;
                error("Incorect imput for litghts");
            }
        }


        void PrintCarStatus(){    //print the status of a mumber car
            cout << "The car status is:\nThere are " << ProblemTires << " Problematic tyres\nThe paint persentage is at " << PaintPercentage << "%\nThere are " << ProblemLights << " problematic lights\n";
        }


        //calculates the repair cost and takes the cost per damage
        float CalculateRepairCosts(float TireCost, float PaintCost, float LightsCost){ 

            float paint;

            try{   //checks all the prices
                if ( TireCost < 0 ) throw TireCost;
            }catch( float TireCost){
                cerr << "\nIncorect imput for cost. Must be grater than zero\nYou gave " << TireCost << endl;
                error("Incorect imput for cost");
            }

            try{
                if ( PaintCost < 0 ) throw PaintCost;
            }catch( float PaintCost){
                cerr << "\nIncorect imput for cost. Must be grater than zero\nYou gave " << PaintCost << endl;
                error("Incorect imput for cost");
            }

            try{
                if ( LightsCost < 0 ) throw LightsCost;
            }catch( float LightsCost){
                cerr << "\nIncorect imput for cost. Must be grater than zero\nYou gave " << LightsCost << endl;
                error("Incorect imput for cost");
            }

            if (PaintPercentage > 30) paint = PaintCost;    //checks if it need repaint
            else paint = 0;

            return (TireCost * ProblemTires ) + (LightsCost * ProblemLights) + paint;  //returns the cost
        }


        short int get_ProblemTires(){  //geter for tires
            return ProblemTires;
        }

        short int get_PaintPercentage(){ //geter for paint
            return PaintPercentage;
        }

        short int get_ProblemLights(){ //geter for lights
            return ProblemLights;
        }


        void set_ProblemTires(short int T){  //seter for tires
            try{ //ches valus
                ProblemTires = T;
                if ( T < 0 || T > 4 ) throw T;
            }catch( short int T){
                cerr << "\nIncorect imput for tires you gave " << T << endl;
                error("Incorect imput for tires");
            }
        }

        void set_PaintPresentage(short int P){ //seter for paint 
            try{ //checks for paint
                PaintPercentage = P;
                if ( P < 0 || P > 100 ) throw P;
            }catch( short int P){
                cerr << "\nIncorect imput for Paint you gave " << P << endl;
                error("Incorect imput for paint");
            }
        }

        void set_ProblemLitghts(short int L){ //seter for lights
            try{ //check value
                ProblemLights = L;
                if ( L < 0 || L > 8 ) throw L;
            }catch( short int L){
                cerr << "\nIncorect imput for Litghts you gave " << L << endl;
                error("Incorect imput for litghts");
            }
        }

};


//getting prices 
//and takes the pointes to re variables in wich the values will be returned
void ask_prices( float &tyre_cost, float &paint_cost, float &light_cost ){
    //check each value and it changes the value in the memory

    try{ 
        cout << "What is the cost per tyre?\n>";
        cin >> tyre_cost;
        if (cin.fail()) throw tyre_cost;
    }catch(float tyre_cost){
        cerr << "\ninvalid input not number\nYou gave " << tyre_cost;
        error("invalid input not number");
    }

    try{
        cout << "What is the cost of the paintjob?\n>";
        cin >> paint_cost;
        if (cin.fail()) throw paint_cost;
    }catch(float paint_cost){
        cerr << "\ninvalid input not number\nYou gave " << paint_cost;
        error("invalid input not number");
    }

    try{
        cout << "What is the cost per light?\n>";
        cin >> light_cost;
        if (cin.fail()) throw light_cost;
    }catch(float light_cost){
        cerr << "\ninvalid input not number\nYou gave " << light_cost;
        error("invalid input not number");
    }
}


//creates a new and a old car 
//creates problems on the new
//prints the strures and the costs
int main(){
    float tyre_cost, paint_cost, light_cost;

    class car new_car = car();      //create new car
    new_car.set_PaintPresentage(20); //create problems
    new_car.set_ProblemLitghts(2);
    new_car.set_ProblemTires(1);

    class car used_car = car(4, 100, 8); //create old car

    ask_prices(tyre_cost, paint_cost, light_cost); //get costs per fix


    cout << "\nStatus of the new car:\n\n"; //print the statutes and costes
    new_car.PrintCarStatus();
    cout << "\nThe repair cost of the new car is " << new_car.CalculateRepairCosts(tyre_cost, paint_cost, light_cost) << "$\n";

    cout << "\nStatus of the used car:\n\n";
    used_car.PrintCarStatus();
    cout << "\nThe repair cost of the used car is " << used_car.CalculateRepairCosts(tyre_cost, paint_cost, light_cost) << "$\n";
    
    //system("pause");
    return 0;
}
