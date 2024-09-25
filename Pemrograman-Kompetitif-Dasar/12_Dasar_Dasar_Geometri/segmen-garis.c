#include<stdio.h>
#include<math.h>


int in_range(double x, double a, double b, int lim_a, int lim_b){
    int min_lim = (lim_a < lim_b ? lim_a:lim_b);
    int max_lim = (lim_a > lim_b ? lim_a:lim_b);

    return (a>b ? (b<=x)&&(x<=a) : (a<=x)&&(x<=b)) && (min_lim<=x) && (x<=max_lim);
}

int main(){
    int x[4], y[4], N;
    double m, c, Rx[2], Ry[2], x_min, y_min, x_max, y_max;
   
    scanf("%d", &N);
    while(N--){
        int ans = 0;

        for(int i=0; i<4; i++){
            scanf("%d %d", &x[i], &y[i]);
        }

        x_min = (x[0]<x[1] ? x[0]:x[1]);
        x_max = (x[0]>x[1] ? x[0]:x[1]);
        y_min = (y[0]<y[1] ? y[0]:y[1]);
        y_max = (y[0]>y[1] ? y[0]:y[1]);

        m = (double)(y[3]-y[2])/(double)(x[3]-x[2]);
        c = -m*x[3] + y[3];
            
            /*Check All Side*/
        Rx[0] = m*x_min+c;
        Rx[1] = m*x_max+c;
        Ry[0] = (y_min-c)/m;
        Ry[1] = (y_max-c)/m;

        ans |= in_range(Rx[0], y_min, y_max, x[2], x[3]);
        ans |= in_range(Rx[1], y_min, y_max, x[2], x[3]);    
        ans |= in_range(Ry[0], x_min, x_max, y[2], y[3]);
        ans |= in_range(Ry[1], x_min, x_max, y[2], y[3]);

        (ans == 0 ? printf("TIDAK\n"): printf("YA\n"));

    }    

    return 0;
}