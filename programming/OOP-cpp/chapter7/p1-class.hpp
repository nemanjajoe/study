#ifndef _P1_CLASS_H_
#define _P1_CLASS_H_

template <typename T>
T min(T &a, T &b){
    if(a > b) return b;
    return a;
};

template <typename T>
T max(T &a, T &b){
    if(a > b) return a;
    return b;
};

#endif
