/*
    ****Be Unstoppable, Until Your Dream Comes True***
    ****Success is not a destination, it's an endless journey***
    ****There is no creator without ALLAH, & He is the ultimate PLANNER***

    ***Author:-      Abdullah Nazmus-Sakib 
    ***Institution:-     Jahangirnagar University
    ***Department:-     CSE
*/

#include <bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef unsigned long long int ull;
typedef long long int ll;
typedef double db;
typedef float ft;
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll,ll>
#define vl vector<ll>
#define B begin()
#define E end()
#define _sort(v) sort(v.begin(),v.end())
#define _rsort(v) sort(v.rbegin(),v.rend())
const int MX=10000007;
const ll inf=1e9;
const ll mod=1e9+7;

ll ara[MX];
vector<int> primes;

ll ar[MX],prime[MX];

void seive()
{
    ll i,j,k=1;
    for(i=4;i<=MX;i+=2)
        ar[i]=1;
    for(i=3;i*i<=MX;i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*2;j<=MX;j+=i)
            {
                ar[j]=1;
            }
        }
    }
    for(i=2;i<=MX;i++)
    {
        if(ar[i]==0)
            prime[k++]=i;
    }
}

vl araa,tree;

void tree_build(ll node, ll st, ll ed)
{
    if(st == ed)
    {
        tree[node] = araa[st];
        return;
    }
    ll mid = (st + ed) / 2;
    tree_build(2 * node, st, mid);
    tree_build(2 * node + 1, mid + 1, ed);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

ll query(ll node, ll st, ll ed, ll l, ll r)
{
    if(l > ed or r < st)
    {
        return LLONG_MAX;
    }
    else if(l <= st and r >= ed)
    {
        return tree[node];
    }
    ll mid = (st + ed) / 2;
    ll leftNode = query(2 * node, st, mid, l, r);
    ll rightNode = query(2 * node + 1, mid + 1, ed, l, r);
    return min(leftNode, rightNode);
}

int main() {
    FasterIO;
    //seive();
    ll tc;
    tc = 1;
    cin>>tc;
    for(ll j = 1; j <= tc; j++)
    {
        ll n, q;
        cin >> n >> q;
        araa.assign(n + 10, 0);
        tree.assign(4 * n + 10, 0);
        for(ll i = 1; i <= n; i++) cin >> araa[i];

        tree_build(1, 1, n);
        cout << "Case " << j << ":" << endl;
        while(q--)
        {
            ll l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}
