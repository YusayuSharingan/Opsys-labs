int GCF(int A, int B){
    if (B == 0){
        return A;
    } else {
        return GCF(B, A % B);
    }
}

int Naive(int A, int B){
    int n, ans = 1;
    if(A >= B){
        n = B;
    } else {
        n = A;
    }
    for(int i=2; i<n; i++){
        if(n % i == 0){
            ans = i;
        }
    }
    return ans;
}