#include "p2-class.h"

using namespace std;

// input -> float
// purpose: get no-negative rainfall value
float getRainfall(){
    float rainfall;
    cin>>rainfall;
    while(rainfall < 0){
        cout<<"invalid rainfall value! input again: "<<endl;
        cin>>rainfall;
    }
    return rainfall;
}

// initailizing the rainfall of a year
void RainData::init(){
    // get rainfall from input stream
    for(int i = 0; i < MONTH; i++){
         data[i].month = i;
         data[i].rainfall = getRainfall();
    }
    // sorting rainfall value from minimun to maximun. bubble sorting
    typedef data_t *temp;
    for(int i = MONTH; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(data[j].rainfall > data[j + 1].rainfall){
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
// get the maximun rainfall months
void RainData::getMax(){
    int index = MONTH - 1;
    typedef data_t *current;
    current = data[index];
    cout<<"the maximun rainfall month of this year:"<<endl;
    while(current.rainfall == data[index].rainfall){
        index--;
        cout<<"     month: "<<current->month<<"     "<<"rainfall: "<<current->rainfall<<endl;
        current = data[index];
    }
}

// the minimun rainfall months
void RainData::getMin(){
    int index = 0;
    typedef data_t *current;
    current = data[index];
    cout<<"the minimun rainfall month of this year:"<<endl;
    while(current->rainfall == data[index].rainfall){
        index++;
        cout<<"     month: "<<current->month<<"     "<<"rainfall: "<<current->rainfall<<endl;
        current = data[index];
    }
}

// get the average rainfall of this year
void RainData::getAverage(){
    float average = 0;
    for(int i = 0; i < MONTH; i++){
        average += data[i].rainfall;
    }
    average /= MONTH;
    cout<<"the average rainfall of this year is: "<<average<<endl;
}

// get total rainfall of this year
void getTotal(){
    float total = 0;
    for(int i = 0; i < MONTH; i++){
        total += data[i].rainfall;
    }
    cout<<"the total rainfall of this year is: "<<total<<endl;
}
