// [uVa] 10994 - Simple Addition
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1935
//
// code by Jason Huang aka Einz
// github: https://github.com/PM25
// website: https://pm25.github.io
// discord: https://discord.gg/G4jEeDC
// email: jason199786109@gmail.com

#include <iostream>
using namespace std;

int f(int n);
long long int sum(int from, int to);
long long int f_sum(int from, int to);


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
    int count = to - from + 1;

    return (from+to) * count / 2;
}


long long int f_sum(int from, int to)
{
    long long ans(0);

    if((from/10) == (to/10)){
        ans += sum(f(from), f(to));
    }
    else{
        if(from%10){
            ans += sum(f(from), 9);
            from += (10-from%10);
        }
        if(to%10){
            ans += sum(1, f(to));
            to -= to%10;
        }

        ans += (sum(1, 9) * (to/10 - from/10));
        ans += f_sum(from/10, to/10);
    }

    return ans;
}

