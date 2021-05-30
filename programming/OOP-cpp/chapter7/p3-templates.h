#ifndef _P3_TEMPLATES_H_
#define _P3_TEMPLATES_H_

template <typename T>
T sum(T *arr, int length){
    T sum = arr[0];
    for (int i = 1; i < length; i++){
        sum += arr[i];
    }
    return sum;
};

#endif
