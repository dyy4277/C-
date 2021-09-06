#include "hello3.h"

void Cube::seth(int H) {
	if (H <= 0) {
		cout << "高设置得不合理" << endl;
	}
	h = H;
};
void Cube::setl(int L) {
	if (L <= 0) {
		cout << "长设置得不合理" << endl;
	}
	l = L;
};
void Cube::setw(int W) {
	if (W <= 0) {
		cout << "宽设置得不合理" << endl;
	}
	w = W;
};
int Cube::getS() {
	return (l * w + w * h + l * h) * 2;
};
int Cube::getV() {
	return l * w * h;
};

bool Cube::isSame(Cube A) {
	return (A.h == h & A.l == l & A.w == w);
};

void Point::getxy(int X, int Y) {
	x = X;
	y = Y;
};

int Point::getppl(Point p) {
	return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

void Circle::setr(int R) {
	r = R;
};
void Circle::getP(Point P) {
	p = P;
};

int Circle::getS() {
	return 
};