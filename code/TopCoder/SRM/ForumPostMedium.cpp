#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class ForumPostMedium{
    public:
        int get_time_seconds(string &tim){
            int len = tim.length();

            for(int i = 0 ; i < len ; i++){
                tim[i] -= '0';
            }
            
            int sec = tim[len - 1] + (tim[len - 2]) * 10;
            int min = tim[len - 4] + tim[len - 5] * 10;
            int hour = tim[len - 7] + tim[len - 8] * 10;

            return sec + min * 60 + hour * 60 * 60;
        }

        string getShownPostTime(string currentTime, string exactPostTime){
            int t1 = get_time_seconds(currentTime);
            int t2 = get_time_seconds(exactPostTime);
            int ch = 60 * 60, cm = 60;
            int diff = 0;

            if(t1 <= t2){
                diff = 24 * 60 * 60 - t2 + t1;
            }else{
                diff = t1 - t2;
            }

            if(diff >= ch){
                int hour = diff / ch;

                return to_string(hour) + " hours ago";
            }else if(diff >= cm){
                int mn = diff / cm;

                return to_string(mn) + " minutes ago";
            }else{
                return "few seconds ago";
            }
        }
};