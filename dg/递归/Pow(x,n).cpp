//
// Created by Administrator on 24-7-11.
//

class Solution {
public:
    double _myPow(double x, int n){
        if(n==0)
            return 1;

        double halfnum = _myPow(x,n/2);
        return n%2==0?halfnum*halfnum:halfnum*halfnum*x;
    }
    double myPow(double x, int n) {
        if(n<0)
            return 1.0/_myPow(x,-n);
        else
            return _myPow(x,n);


//        if(n==0)
//            return 1;
//        else if(n==1)
//            return x;
//        else if(n==-1)
//            return 1/x;
//        else if(n==2)
//            return x*x;
//        else if(n==-2)
//            return 1/(x*x);
//        else if(n==3)
//            return x*x*x;
//        else if(n==-3)
//            return 1/(x*x*x);
//        else if(n==4)
//            return x*x*x*x;
//        else if(n==-4)
//            return 1/(x*x*x*x);
//        else if(n==5)
//            return x*x*x*x*x;
//        else if(n==-5)
//            return 1/(x*x*x*x*x);
//        else if(n==6)
//            return x*x*x*x*x*x;
//        else if(n==-6)
//            return 1/(x*x*x*x*x*x);
//        else if(n==7)
//            return x*x*x*x*x*x*x;
//        else if(n==-7)
//            return 1/(x*x*x*x*x*x*x);
//
//        else
//            return myPow(x,n/8)* myPow(x,n/8)* myPow(x,n/8)* myPow(x,n-n/8)*
//                    myPow(x,n/8)* myPow(x,n/8)* myPow(x,n/8)* myPow(x,n-n/8*7);
    }
};














