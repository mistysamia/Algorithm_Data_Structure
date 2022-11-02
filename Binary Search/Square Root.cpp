///Will return the square root
double squareRoot(double n) {
    double low = 0, high = 1e4;
    for(int i=0; i<100; i++) {
        double mid = (low+high)/2.0;
        if(mid*mid>n) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    return low;
}
