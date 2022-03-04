#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};

/*
 * makepoint: make a point from x and y components
 * 将两个点数据 放到一起
 */
struct point makepoint(int x, int y) {
	struct point temp;
	
	temp.x = x;
	temp.y = y;
	return temp;
}

/*
 * ptinrect: return 1 if p in r, 0 if not
 */

int ptinrect (struct point p, struct rect r) {
	return p.x >= r.pt1.x && p.x < r.pt2.x
	    && p.y >= r.pt1.y && p.y < r.pt2.y; 
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/*
 * canonrect : canonicalize corrdinates of rectangle
 */

struct rect canonrect (struct rect r)
{
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}

#define XMAX 100
#define YMAX 100

void main() {
	// cal two points dist
	double dist;
	struct point pt = {100, 100};
	dist = sqrt( (double)pt.x * pt.x + (double)pt.y * pt.y);
	printf("cal dist between (0,0) and (100,100) is : %f\n", dist);

	// cal middle point
	struct rect screen;
	struct point middle;
	struct point makepoint(int, int);

	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(XMAX, YMAX);
	middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
			   (screen.pt1.y + screen.pt2.y) / 2);
	printf("cal middle between (0,0) and (100,100) is: (%f, %f)\n", (double)middle.x , (double)middle.y);

	// ptinrect : check if point in rect
	struct point pt_2 = {50 , 50};
	printf("test if (50, 50) in screen or not: %d\n", ptinrect(pt_2, screen));

	// test canonrect
	int x1,y1,x2,y2;
	x1 = canonrect(screen).pt1.x;
	y1 = canonrect(screen).pt1.y;
	x2 = canonrect(screen).pt2.x;
	y2 = canonrect(screen).pt2.y;
	printf("test canonrect: rect pt1(%d,%d), pt2(%d,%d)\n", x1, y1, x2, y2);

	// if the struct function is too big, use pointer is better
	struct point *pp;
	pp = &pt_2;
	printf("test point pointer is (%d,%d)\n", (*pp).x, (*pp).y);
	// if the pointer point to a struct, we could use '->'
	printf("test point pointer is (%d,%d)\n", pp -> x, pp -> y);
	
}

