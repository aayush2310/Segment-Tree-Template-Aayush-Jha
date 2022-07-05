class sgTree{
private:
    vector<int>seg;
    vector<int>arr;
public:
    sgTree(vector<int>v){
        int n=v.size();
        seg.resize(4*n);
        arr=v;
    }
    void build(int index,int low,int high){
        if(low==high){
            seg[index]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*index+1,low,mid);
        build(2*index+2,mid+1,high);
        seg[index]=min(seg[2*index+1],seg[2*index+2]);
    }
    int query(int index,int low,int high,int l,int r){
        //No Overlap//
        if(high<l || low>r)
            return(1e9);
        //Complete Overlap//
        if(low>=l && high<=r){
            return(seg[index]);
        }
        //Partial Overlap//
        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,l,r);
        int right=query(2*index+2,mid+1,high,l,r);
        return(min(left,right));
    }
    void update(int index,int low,int high,int i,int val){
       if(low==high){
            seg[index]=val;
            return;
       }
       int mid=(low+high)/2;
       if(i<=mid){
            update(2*index+1,low,mid,i,val);
       }
       else{
            update(2*index+2,mid+1,high,i,val);
       }
       seg[index]=min(seg[2*index+1],seg[2*index+2]);
    }
}
int main(){
    //Testcases//
    int t;
    cin>>t;
    while(t){
        solve();
        t--;
    }
    return(0);
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sgTree sg1(arr);
    sg1.build(0,0,n-1);
    int l,r;
    cin>>l>>r;
    cout<<sg1.query(0,0,n-1,l,r)<<endl;
    int i,val;
    cin>>i>>val;
    sg1.update(0,0,n-1,i,val);
    return;
}
