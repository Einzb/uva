// [uVa] 10994 - Simple Addition
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1935
//
// code by Jason Huang aka Einz
// github: https://github.com/Einzb
// website: https://einzmind.blogspot.tw
// discord: https://discord.gg/G4jEeDC
// email: jason199786109@gmail.com

#include <iostream>
using namespace std;

int f(int n); // function F(n), which is defined in problem
long long int sum(int from, int to); // get the sum of an arithmetic progression
long long int f_sum(int from, int to); // get the sum of sequence F(n)


int main(){
    int s, q;
    while(cin>>s>>q){
        if(s<0 && q<0) break;

        cout<<f_sum(s, q)<<endl;
    }
}


int f(int n)
{
    if(n%10) return n%10;
    else if(!n) return 0;
    else return n/10;
}


long long int sum(int from, int to)
{
    // count the elements between from(var) and to(var)
    int count = to - from + 1;

    // formula of arithmetic series
    return (from+to) * count / 2;
}


long long int f_sum(int from, int to)
{
    long long ans(0);

    // take every 10 number as an interval, start from 0
    // case of from(var) and to(var) in the same interval
    if((from/10) == (to/10)){
        ans += sum(f(from), f(to));
    }
    else{
        // sum of the numbers which doesn't make a complete interval
        if(from%10){
            ans += sum(f(from), 9);
            from += (10-from%10);
        }
        if(to%10){
            ans += sum(1, f(to));
            to -= to%10;
        }

        //  sum of the numbers which the last digit is not 0
        ans += (sum(1, 9) * (to/10 - from/10));
        // sum of the numbers which the last digit is 0
        // if last digit is 0, then F(num) = F(num/10)
        ans += f_sum(from/10, to/10);
    }

    return ans;
}

