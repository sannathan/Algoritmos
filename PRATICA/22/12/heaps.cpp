#include <iostream>

using namespace std;

void HeapBottomUp(int *H){
    for(int i = n/2; i > 0; i--){
        int k = i;
        int v =  H[k];
        bool heap = false;

        while(!heap && 2*k <= n){
            int j = 2*K;

            if(j < n){
                if(H[j] < H[j+1]){
                    j += 1;
                }
            }
            if(v >= H[j]){
                heap = true;
            }
            else{
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}
int main(void){
    
}