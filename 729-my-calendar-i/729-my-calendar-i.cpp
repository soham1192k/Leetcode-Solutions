class MyCalendar {
public:
    set<pair<int,int>>s;
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        if(s.empty()) {s.insert({start,end});return true;}
        auto itr=s.upper_bound({start,start});
        if(itr==s.end()) itr--;
        while(true){
            if(start>=itr->first&&start<=itr->second-1) return false;
            if(end-1>=itr->first&&end-1<=itr->second-1) return false;
            if(itr->first>=start&&itr->first<=end-1) return false;
            if(itr->second-1>=start&&itr->second-1<=end-1) return false;
            if(itr==s.begin()) break;
            itr--;
            if(itr->second<=start) break;
        }
        s.insert({start,end});
        return true;
    }
};