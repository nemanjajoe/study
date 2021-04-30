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

// sorting by the rainfall of month;
void RainData::sort(){
    data_t temp;
    for(int i = MONTH - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(data[j].rainfall > data[j + 1].rainfall){
                temp.month = data[j].month;
                temp.rainfall = data[j].rainfall;
                data[j] = data[j + 1];
                data[j + 1].month = temp.month;
                data[j + 1].rainfall = temp.rainfall;
            }
        }
    }
}

// purpose: initailizing the rainfall of a year
void RainData::init(){
    // get rainfall from input stream
    for(int i = 0; i < MONTH; i++){
        cout<<"please input month "<<i + 1<<" rainfall: "<<endl;
        data[i].month = i + 1;
        data[i].rainfall = getRainfall();
    }
    sort();
}

// purpose: get the maximun rainfall months
void RainData::getMax(){
    int index = MONTH - 1;
    data_t *current;
    current = &data[index];
    cout<<"the maximun rainfall month of this year:"<<endl;
    cout<<"     month: "<<current->month<<"     "<<"rainfall: "<<current->rainfall<<endl;
    while(current->rainfall == data[--index].rainfall){
        cout<<"     month: "<<current->month<<"     "<<"rainfall: "<<current->rainfall<<endl;
        current = &data[index];
    }
}

// purpose: the minimun rainfall months
void RainData::getMin(){
    int index = 0;
    data_t *current;
    current = &data[index];
    cout<<"the minimun rainfall month of this year:"<<endl;
    cout<<"     month: "<<current->month<<"     "<<"rainfall: "<<current->rainfall<<endl;
    while(current->rainfall == data[++index].rainfall){
        cout<<"     month: "<<current->month<<"     "<<"rainfall: "<<current->rainfall<<endl;
        current = &data[index];
    }
}

// purpose: get the average rainfall of this year
void RainData::getAverage(){
    float average = 0;
    for(int i = 0; i < MONTH; i++){
        average += data[i].rainfall;
    }
    average /= MONTH;
    cout<<"the average rainfall of this year is: "<<average<<endl;
}

// purpose: get total rainfall of this year
void RainData::getTotal(){
    float total = 0;
    for(int i = 0; i < MONTH; i++){
        total += data[i].rainfall;
    }
    cout<<"the total rainfall of this year is: "<<total<<endl;
}

// purpose: testing object's functionality
void RainData::test(){
     cout<<"testing ..."<<endl;
     char blank[] = "     ";
     float testData[] = {
         23.3 ,32.4,42.5,524.4,
         524.2,23.4,42.4,23   ,
         42.5 ,65.5,23.4,42.5};
     float expectMaxMonth = 4, expectMinMonth = 8,
           expectTotal = 1409.5, expectAverage;
     expectAverage = expectTotal/12;
     cout<<"test data:"<<endl;
     for(int i = 0; i < MONTH; i++){
        cout<<"month: "<< i + 1<<blank<<"rainfall: "<<testData[i]<<endl;
        data[i].month = i + 1;
        data[i].rainfall = testData[i];
     }
     cout<<"expect max rainfall month: "<<expectMaxMonth<<endl;
     cout<<"expect min rainfall month: "<<expectMinMonth<<endl;
     cout<<"expect total rainfall of a year: "<<expectTotal<<endl;
     cout<<"expect average rainfall each month: "<<expectAverage<<endl;
     cout<<endl<<"result: "<<endl;
     this->sort();
     this->getMax();
     this->getMin();
     this->getTotal();
     this->getAverage();
     cout<<endl<<"testing OK"<<endl;
}
