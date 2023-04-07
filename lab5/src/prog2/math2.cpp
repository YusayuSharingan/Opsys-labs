extern "C" double Pi1(int n);
extern "C" double Pi2(int n);

double Pi1(int n){
    double result = 0.0;
    double sign = -1;
    for(int k = 0; k < n; k++){
        sign = -sign;
        result += 4*sign/(2*k + 1);
    }
    return result;
}

double Pi2(int n){
    double result = 2.0;
    for(int k = 1; k < n; k++){
        result *= 4*k*k/((4*k*k-1));
    }
    return result;
}