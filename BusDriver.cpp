#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int Partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;\

    for(int j = p; j <= r - 1; j++)
    {
        if(a[j] <= x){
            i = i+1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);

    return i+1;
}

void QuickSort(int a[], int p, int r)
{
    int q;

    if(p < r)
    {
        q = Partition(a, p, r);
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);
    }
}

int main()
{
    int n, morning[MAX], evening[MAX];
    int d, r;

    while(cin>>n>>d>>r){
        if(!n && !d && !r)
            break;

        for(int i = 0; i < n; i++){
            cin>>morning[i];
        }
        for(int i = 0; i < n; i++){
            cin>>evening[i];
        }

        QuickSort(morning, 0, n - 1);
        QuickSort(evening, 0, n - 1);

//        sort(morning, morning + n);
//        sort(evening, evening + n);

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(morning[i] + evening[n-i-1] > d){
                ans += ((morning[i] + evening[n-i-1]) - d) * r;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
