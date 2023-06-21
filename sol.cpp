#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Car{
    int start,end;
    double speed;
    void read() {
        scanf("%d%d%lf", &start, &end, &speed);
    }
    int len() const {
        return end-start;
    } 
    bool is_zero() const{
        return speed < 1e-11;
    }
    double max_saved() const{
        if(is_zero()){
            return 0;
        }
        else{
            return len()/ speed;
        }
    }
    double max_used() const {
         return len() / (speed + 2);
    }
};

int main()
{
    int n,L;
    scanf("%d%d", &n,&L);
    vector<Car> Cars;
    int last_end = 0;
    for(int i =0; i<n ; ++i)
    {
        Car nxt;
        nxt.read();
        assert(last_end <= nxt.start);
        if(last_end < nxt.start)
        {
            Cars.push_back(Car{last_end,nxt.start,0});
        }
        Cars.push_back(nxt);
        last_end = nxt.end;
    }
    if(last_end < L)
    {
        Cars.push_back(Car{last_end,L,0});
    }
    n = Cars.size();
    vector<double> delta(n);
    for(int i = 0; i<n ;i++)
    {
        delta[i] = Cars[i].max_saved();
    }

    //sort by speed
    vector<pair<double, int>> indices;
    for(int i = 0; i<n ;i++)
    {
        indices.emplace_back(Cars[i].speed, i);
    }
    sort(indices.begin(), indices.end());
    double answer = 0;
    for(pair<double, int> pp :  indices){
        int me = pp.second ;
        double pref = 0;
        for(int i =0; i<me; ++i)
        {
            pref += delta[i];
        }
        assert(pref >= -1e-9); // non-negative
        double min_pref = pref;
        for(int i = me +1; i<n; ++i)
        {
            pref += delta[i];
            min_pref = min(min_pref, pref);
        }

        double wanna_spend = min(min_pref, Cars[me].max_used());
        delta[me] = -wanna_spend;

        double X = Cars[me].speed;  
        
        double s = (X+1) / (1 - wanna_spend/ Cars[me].len())-X;
        assert(-1e-12 <= s && s <= 2+1e-12);
        double t = Cars[me].len() / (s+X);
        answer += t;
    }
    
    printf("%.12lf\n", answer);
    double pref = 0;
    for(int i = 0; i<n ;i++)
    {
        pref += delta[i];
        assert(pref >= -1e-9);
    }

    return 0;
}
