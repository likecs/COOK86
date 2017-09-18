#include <bits/stdc++.h>
using namespace std;

#define inchar			getchar//_unlocked

template<typename T> void inpos(T &x) {
	x = 0; register T c = inchar();
	while(((c < 48) || (c > 57)) && (c != '-')) c = inchar();
	bool neg = false; if (c=='-') neg = true;
	for(; c < 48 || c > 57; c = inchar()) ;
	for(; c > 47 && c < 58; c = inchar()) x = (x<<3) + (x<<1) + (c&15);
	if(neg) x = -x;
}

const int MAX = 3e5;

//Complex class: Quite faster than in-built C++ library as it uses only functions required
template<typename T> class cmplx {
private:
	T x, y;
public:
	cmplx () : x(0.0), y(0.0) {}
	cmplx (T a) : x(a), y(0.0) {}
	cmplx (T a, T b) : x(a), y(b) {}
	T get_real() { return this->x; }
	T get_img() { return this->y; }
	cmplx conj() { return cmplx(this->x, -(this->y)); }
	cmplx operator = (const cmplx& a) { this->x = a.x; this->y = a.y; return *this; }
	cmplx operator + (const cmplx& b) { return cmplx(this->x + b.x, this->y + b.y); }
	cmplx operator - (const cmplx& b) { return cmplx(this->x - b.x, this->y - b.y); }
	cmplx operator * (const T& num) { return cmplx(this->x * num, this->y * num); }
	cmplx operator / (const T& num) { return cmplx(this->x / num, this->y / num); }
	cmplx operator * (const cmplx& b) {
		return cmplx(this->x * b.x - this->y * b.y, this->y * b.x + this->x * b.y);
	}
	cmplx operator / (const cmplx& b) {
		cmplx temp(b.x, -b.y); cmplx n = (*this) * temp;
		return n / (b.x * b.x + b.y * b.y);
	}
};

//T = int/long long as per polynomial coefficients
//S = double/long double as per precision required
template<typename T, typename S> struct FFT {
	S PI;
	int n, L, *rev, last;
	cmplx<S> ONE, ZERO;
	cmplx<S> *omega_powers;

	FFT() {
		PI = acosl(-1.0);
		ONE = cmplx<S>(1.0, 0.0);
		ZERO = cmplx<S>(0.0, 0.0);
		last = -1;
		int req = 1 << (32 - __builtin_clz(MAX));
		rev = new int[req];
		omega_powers = new cmplx<S>[req];
	}

	~FFT() {
		delete rev;
		delete omega_powers;
	}

	void ReverseBits() {
		if (n != last) {
			for (int i = 1, j = 0; i < n; ++i) {
				int bit = n >> 1;
				for (; j >= bit; bit >>= 1) j -= bit;
				j += bit;
				rev[i] = j;
			}
		}
	}

	void DFT(vector<cmplx<S>> &A, bool inverse = false) {
		for(int i = 0; i < n; ++i)
			if (rev[i] > i) swap(A[i], A[rev[i]]);
		for (int s = 1; s <= L; s++) {
			int m = 1 << s, half = m / 2;
			cmplx<S> wm(cosl(2.0 * PI / m), sinl(2.0 * PI / m));
			if (inverse) wm = ONE / wm;
			omega_powers[0] = ONE;
			for(int k = 1; k < half; ++k) {
				omega_powers[k] = omega_powers[k-1] * wm;
			}
			for (int k = 0; k < n; k += m) {
				for (int j = 0; j < half; j++) {
					cmplx<S> t = omega_powers[j] * A[k + j + half];
					cmplx<S> u = A[k + j];
					A[k + j] = u + t;
					A[k + j + half] = u - t;
				}
			}
		}
		if (inverse) {
			for (int i = 0; i < n; i++) A[i] = A[i] / n;
		}
	}

	// c[k] = sum_{i=0}^k a[i] b[k-i]
	vector<T> multiply(const vector<T> &a, const vector<T> &b) {
		L = 0;
		int sa = a.size(), sb = b.size(), sc = sa + sb - 1;
		while ((1 << L) < sc) L++;
		n = 1 << L;
		ReverseBits();
		last = n;
		vector<cmplx<S>> aa(n, ZERO), bb(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = cmplx<S>(a[i], 0);
		for (int i = 0; i < sb; ++i) bb[i] = cmplx<S>(b[i], 0);
		DFT(aa, false); DFT(bb, false);
		for (int i = 0; i < n; ++i) cc.push_back(aa[i] * bb[i]);
		DFT(cc, true);
		vector<T> ans(sc);
		for (int i = 0; i < sc; ++i) ans[i] = cc[i].get_real() + 0.5;
		return ans;
	}
};

FFT<int, double> fft;

int N, M;
int row_mask[MAX];
int col_mask[MAX];
int diag_mask[MAX];

long long solve(vector<int> &row, vector<int> &col, vector<int> &diag) {
	long long R = row.size(), C = col.size();
	long long ans = (R + C) * N - R * C;
	//add contribution due to diagonals not accounted yet
	vector<int> markr(N, 0), markc(N, 0);
	for(int i = 0; i < row.size(); ++i) {
		markr[row[i]] = 1;
	}
	for(int i = 0; i < col.size(); ++i) {
		markc[col[i]] = 1;
	}
	vector<int> unmark_row, unmark_col;
	for(int i = 0; i < N; ++i) {
		unmark_row.push_back(markr[i] ^ 1);
		unmark_col.push_back(markc[i] ^ 1);
	}
	vector<int> get = fft.multiply(unmark_row, unmark_col);
	for(int i = 0; i < diag.size(); ++i) {
		ans += get[diag[i]];
	}
	return ans;
}

long long solve_color(int color, int color2 = 0) {
	vector<int> row, col, diag;
	for(int i = 0; i < N; ++i) {
		if (row_mask[i] & color) {
			row.push_back(i);
		}
		else if (row_mask[i] & color2) {
			row.push_back(i);
		}
		if (col_mask[i] & color) {
			col.push_back(i);
		}
		else if (col_mask[i] & color2) {
			col.push_back(i);
		}
	}
	for(int i = 0; i < 2 * N; ++i) {
		if (diag_mask[i] & color) {
			diag.push_back(i);
		}
		else if (diag_mask[i] & color2) {
			diag.push_back(i);
		}
	}
	return solve(row, col, diag);
}

int main() {
	int type, idx, color;
	inpos(N), inpos(M);
	/*
	mask = 0 -> no_color
	mask = 1 -> green
	mask = 2 -> red
	mask = 3 -> yellow
	*/
	for(int i = 1; i <= M; ++i) {
		inpos(type), inpos(idx), inpos(color);
		idx -= 1;
		if (type == 1) {
			row_mask[idx] |= 1 << color;
		}
		else if (type == 2) {
			col_mask[idx] |= 1 << color;
		}
		else if (type == 3) {
			idx -= 1;
			diag_mask[idx] |= 1 << color;
		}
	}
	long long green = solve_color(1);
	long long red = solve_color(2);
	long long any_color = solve_color(1, 2);
	long long yellow = red + green - any_color;

	red -= yellow;
	green -= yellow;
	long long no_color = 1LL * N * N - yellow - red - green;

	cout << no_color << " " << red << " " << green << " " << yellow << "\n";
	return 0;
}