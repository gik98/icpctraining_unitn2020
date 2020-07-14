#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

struct Point {
	double x, y;
};

struct Line{
	double a, b, c;

	Line(Point u, Point v) {
		if (abs(u.x - v.x) < EPS) {
			// Vertical line
			a = 1;
			b = 0;
			c = -u.x;
		} else {
			b = 1;
			a = (v.y - u.y) / (u.x - v.x);
			c = - a * u.x - u.y;
		}

	}


};

int main() {
	Point ta, tb, tc;
	int n, trees = 0;
	cin >> ta.x >> ta.y >> tb.x >> tb.y >> tc.x >> tc.y;
	cin >> n;
	
	Line la(ta, tb), lb(tb, tc), lc(ta, tc);
	double side_la = la.a * tc.x + la.b * tc.y + la.c;
	double side_lb = lb.a * ta.x + lb.b * ta.y + lb.c;
	double side_lc = lc.a * tb.x + lc.b * tb.y + lc.c;

	double area = abs(ta.x * (tb.y - tc.y) + tb.x * (tc.y - ta.y) + tc.x * (ta.y - tb.y)) / 2;
	
	for (int i = 0; i<n; i++) {
		Point tree;
		cin >> tree.x >> tree.y;

		if ((side_la * (la.a * tree.x + la.b * tree.y + la.c)) >= -EPS
			&& (side_lb * (lb.a * tree.x + lb.b * tree.y + lb.c)) >= -EPS
			&& (side_lc * (lc.a * tree.x + lc.b * tree.y + lc.c)) >= -EPS) {
			trees++;
		}
	}
	cout << fixed << setprecision(1) << area << endl << (int) trees << endl;
}
