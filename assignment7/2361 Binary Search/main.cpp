#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 10000
int ans[MAXN];
int num,L,anscnt;
//vector <int> ansv;
int judge(int x)
{
    int p = 0, q = x - 1, cnt = 0;
    while (p <= q) {
        int mid = (p + q) / 2;
        cnt++;
        if (cnt > L) return 0;
        if (mid == num && cnt == L) return 1;
        if (mid < num)
            p = mid + 1;
        else q = mid - 1;

    }
    return 0;
}
int main()
{
   while(cin >> num >> L)
   {
       anscnt = 0;
       memset(ans,0,sizeof(ans));
       vector <int> ansv;
       for(int i=1; i<=MAXN;i++)
       {
           int re = judge(i);
           if(re)
              ans[anscnt++] = i;
       }
      for(int j=0; j<anscnt;j++)
       {
           ansv.push_back(ans[j]);
           while(ans[j+1] - ans[j] ==1)
           {
               j++;
           }
           ansv.push_back(ans[j]);
       }
       cout << ansv.size()/2 << endl;
       for(int i=0; i<ansv.size();i+=2){
            cout << ansv[i] << " " << ansv[i+1] << endl;
       }
   }
    return 0;
}
/*#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 10000;
vector<int> ns;
struct node{
    int l,r;
    node(int _l=0, int _r=0):l(_l),r(_r){}
};
vector<node> interv;
bool Binary_Seach(int n, int idx, int L){
    int l = 0, r = n-1;
    int mid;
    //cout << "n: " << n << " ";
    for(int i=1; i<L; i++){
        //cout << l << " " << r << " ";
        mid = (l+r)/2;
        if(l>r)
            return false;
        if(idx < mid)
            r = mid-1;
        else if(idx > mid)
            l = mid+1;
        else
            return false;
    }
    //cout << endl;
    return idx == (l+r)/2;
}
int main()
{
    int idx, L;
    while(cin>>idx>>L){
        ns.clear();
        interv.clear();
        for(int i=1; i<=MAXN; i++){
            if(Binary_Seach(i,idx,L))
                ns.push_back(i);
        }
        int l,r;
        for(int i=0; i<ns.size(); i++){
            l = ns[i];
            while(ns[i+1]-ns[i] == 1){
                i++;
            }
            r = ns[i];
            interv.push_back(node(l,r));
        }
        cout << interv.size() << endl;
        for(int i=0; i<interv.size(); i++){
            cout << interv[i].l << " " << interv[i].r << endl;
        }

    }
    return 0;
}*/
