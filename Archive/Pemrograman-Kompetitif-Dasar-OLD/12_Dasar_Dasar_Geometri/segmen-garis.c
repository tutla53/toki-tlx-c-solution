#include<stdio.h>
#include<math.h>

typedef struct{
    double x;
    double y;
}point_t;

double m, c;

int check_point_on_the_line(double x, double y, point_t p1, point_t p2){
    double xmin = (p1.x<p2.x ? p1.x:p2.x);
    double xmax = (p1.x>p2.x ? p1.x:p2.x);
    double ymin = (p1.y<p2.y ? p1.y:p2.y);
    double ymax = (p1.y>p2.y ? p1.y:p2.y);

    int in_x, in_y;

    in_x = (xmin<=x) && (x<=xmax);
    in_y = (ymin<=y) && (y<=ymax);

    return in_x && in_y;
}

int check_horizontal(double xmin, double xmax, double y, point_t start_point, point_t end_point){
    /*same y coordinate*/
    double x_horizontal = (y - c)/ m;

    int result = (xmin<=x_horizontal) && (x_horizontal<=xmax) && check_point_on_the_line(x_horizontal, y, start_point, end_point);

    return result;
}

int check_vertical(double ymin, double ymax, double x, point_t start_point, point_t end_point){
    /*same x coordinate*/
    double y_vertical = x*m + c;

    int result = (ymin<=y_vertical) && (y_vertical<=ymax) && check_point_on_the_line(x, y_vertical, start_point, end_point);

    return result;
}

int check_intersection(double ps1, double ps2, double pl1, double pl2){
    double pl_min = (pl1 < pl2 ? pl1:pl2);
    double pl_max = (pl1 > pl2 ? pl1:pl2);

    int case1, case2, case3, case4, ret;

    case1 = (ps1<=pl_max) && (pl_max<=ps2);
    case2 = (ps1<=pl_min) && (pl_min<=ps2);
    case3 = (pl_min<=ps1) && (ps1<=pl_max);
    case4 = (pl_min<=ps2) && (ps2<=pl_max);

    ret = case1||case2||case3||case4;

    return ret;
}

int check_intersection_2(double ps1, double ps2, double pl1, double pl2){
    double pl_min = (pl1 < pl2 ? pl1:pl2);
    double pl_max = (pl1 > pl2 ? pl1:pl2);

    int case1, case2, ret;

    case1 = pl_max >= ps2;
    case2 = pl_min <= ps1;
    
    ret = case1||case2;

    return ret;
}

int main(){
    int N;
    double x1, y1, x2, y2;
    double x_min, y_min, x_max, y_max;
    point_t start, end;
    
    scanf("%d", &N);
    while(N--){
        int ans = 0;

        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &start.x, &start.y, &end.x, &end.y);

        x_min = (x1<x2 ? x1:x2);
        x_max = (x1>x2 ? x1:x2);
        y_min = (y1<y2 ? y1:y2);
        y_max = (y1>y2 ? y1:y2);

        /*Divide case by m*/
        if(start.x == end.x){
            /*Infinite Gradient --> Only check at vertical line*/
            ans = 0;
            if((start.x == x_min)||(start.x == x_max)){
                ans = check_intersection(y_min, y_max, start.y, end.y);
            }
            
            else if ((x_min<start.x) && (start.x<x_max)){
                ans = check_intersection_2(y_min, y_max, start.y, end.y);
            }
        }
        else if(start.y == end.y){
            /*Zero Gradient --> Only check at horizontal line*/
            ans = 0;
            if((start.y == y_min)||(start.y == y_max)){ 
                ans = check_intersection(x_min, x_max, start.x, end.x);
            }

            else if ((y_min<start.y) && (start.y<y_max)){
                ans = check_intersection_2(x_min, x_max, start.x, end.x);
            }
        }
        else{
            ans = 0;
            m = (end.y-start.y)/(end.x-start.x);
            c = end.y-m*end.x;

            ans |= check_horizontal(x_min, x_max, y_min, start, end);
            ans |= check_horizontal(x_min, x_max, y_max, start, end);
            ans |= check_vertical(y_min, y_max, x_min, start, end);
            ans |= check_vertical(y_min, y_max, x_max, start, end);
        }

        (ans == 0 ? printf("TIDAK\n"): printf("YA\n"));

    }    

    return 0;
}