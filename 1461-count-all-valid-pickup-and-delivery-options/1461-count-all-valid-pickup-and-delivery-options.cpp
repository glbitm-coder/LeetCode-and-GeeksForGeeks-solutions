class Solution {
public:
    int countOrders(int n) {
        long long ans = 1, mod = 1e9 + 7;
        // for placing pickup like for n =3 -> 3!
        // P1 P2 P3    // P1 P3 P2
        // P2 P3 P1    // P2 P1 P3
        // P3 P1 P2    // P3 P2 P1
        for(int i = 1; i <= n; ++i){
            ans = (ans * i ) % mod;
        }

        //now placing delivery n = 3 -> 2n -1 (for n = 1 to 3)

        // slots for placing D3, only 1 (considering any of the above pickup placing, it may vary)
        // -> P1 P2 P3 D3 (only 1 option in P1 P2 P3 to plce after P3)

        // for D2, 3 slots
        // -> P1 P2 D2 P3 D3     P1 P2 P3 D2 D3        P1 P2 P3 D3 D2


        // for D1 , 5 slots (considering P1 P2 D2 P3 D3)
        // -> P1 D1 P2 D2 P3 D3        -> P1 P2 D1 D2 P3 D3           -> P1 P2 D2 D1 P3 D3
        // -> P1 P2 D2 P3 D1 D3                           -> P1 P2 D2 P3 D3 D1

        // we will multiply all because above we are considering for 1 instance
        for(int i = 1; i < 2 * n; i = i + 2){
            ans = (ans * i) % mod;
        }
        return ans;
    }
};