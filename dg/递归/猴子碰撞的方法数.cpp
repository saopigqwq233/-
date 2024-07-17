class Solution {
public:
    long long _myPow(int x, int n){
        if(n==0)
            return 1;

        long long halfnum = _myPow(x,n/2);
        return n%2==0?halfnum*halfnum:halfnum*halfnum*x;
    }
    int myPow(long long x, int n) {
        if (n < 0)
            return 1.0 / _myPow(x, -n);
        else
            return _myPow(x, n);
    }
    int monkeyMove(int n) {
        return myPow(2,n)-2;
    }
};