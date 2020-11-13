class SegTree{
    public :
    vector<long long> d,t;
    void init(int sz){
        d.assign(4*(sz+3),0);
        t.assign(4*(sz+3),0);
    }
    void push(int v,int l,int r){
        if(d[v]){
            t[v] = d[v];
            if(l != r){
                d[2*v] = d[v];
                d[2*v+1] = d[v];
            }
            d[v] = 0;
        }
    }
    void upd(int v,int l,int r,int a,int b,long long val){
        push(v,l,r);
        if(l > b || r < a || l > r){
            return;
        }
        if(l >= a && r <= b){
            d[v] = val;
            push(v,l,r);
            return ;
        }
        int mid = (l+r)/2;
        upd(2*v,l,mid,a,b,val);
        upd(2*v+1,mid+1,r,a,b,val);
        t[v] = t[2*v]|t[2*v+1];
    }
    long long query(int v,int l,int r,int a,int b){
        push(v,l,r);
        if(l > b || r < a || l > r){
            return 0;
        }
        if(l >= a && r <= b){
            return t[v];
        }
        int mid = (l+r)/2;
        long long val = 0;
        val |= query(2*v,l,mid,a,b);
        val |= query(2*v+1,mid+1,r,a,b);
        return val;
    }
};
