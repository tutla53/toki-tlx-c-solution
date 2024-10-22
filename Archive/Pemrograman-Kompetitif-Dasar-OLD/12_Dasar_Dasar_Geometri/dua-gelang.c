#include<stdio.h>
#include<math.h>

int main(){
    int x1, y1, r1, x2, y2, r2;
    double d, max_radii, min_radii;

    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

    max_radii = ((r1>r2) ? r1:r2);
    min_radii = ((r1<r2) ? r1:r2);

    d = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    
    if((((max_radii-min_radii)<=d) && (d<=(max_radii+min_radii)))){
        printf("bersentuhan\n");
    }
    else{
        printf("tidak bersentuhan\n");
    }
    
    return 0;
}