#include <stdio.h>

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    double w[n], v[n], ratio[n], cap, val = 0;
    printf("Enter weight and value of items:\n");
    for(int i=0;i<n;i++) {
        scanf("%lf %lf", &w[i], &v[i]);
        ratio[i] = v[i]/w[i];
    }

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(ratio[j] < ratio[j+1]) {
                double t=ratio[j]; ratio[j]=ratio[j+1]; ratio[j+1]=t;
                t=w[j]; w[j]=w[j+1]; w[j+1]=t;
                t=v[j]; v[j]=v[j+1]; v[j+1]=t;
            }

    printf("Enter capacity: ");
    scanf("%lf",&cap);

    for(int i=0;i<n;i++) {
        if(cap==0) break;
        if(w[i] <= cap) {
            cap -= w[i];
            val += v[i];
        } else {
            val += ratio[i]*cap;
            cap = 0;
        }
    }

    printf("Max value = %.2lf\n", val);
    return 0;
}
