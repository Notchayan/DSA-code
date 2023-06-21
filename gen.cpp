#include <iostream>
#include <bits/stdc++.h>
#include "testlib.h" 
using namespace std;

int main(int argc, char* argv[]){

    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int L = atoi(argv[2]);
    L = max(L,  n);
    assert(n <= L);
    printf("%d %d\n", n, L);
    vector<int> positions;
    while (true)
    {
        positions.clear(); 
        for(int i = 0; i< 2 * n ;i++)
        {
            positions.push_back(rnd.next(0, L)); 
        }
        sort(positions.begin(), positions.end());
        bool ok = true;
        for(int i = 0; i<n ;i++)
        {
            if(positions[2*i] == positions[2*i+1]){ 
                ok = false;
                break;
            }
        }
        if(ok)
        {
            break;
        }
    }
    for(int i = 0; i<n ;i++)
    {
        int start = positions[2*i];
        int end = positions[2*i+1];
        double speed = rnd.next((double) 0.0, (double) 2.0);
        printf("%d %d %.9lf\n", start, end, speed);
    }
    

    return 0;
}
