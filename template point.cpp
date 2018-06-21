template<typename T>
struct point{
	T x,y;
	point(T x= 0, T y = 0):x(x),y(y){}
};

template<typename T>
point<T> operator + (const point<T>& A, const point<T>& B){
	return point<T>(A.x+B.x,A.y+B.y);
}

template<typename T>
ostream& operator << (ostream& out, const point<T>& p){
	out<<"("<<p.x<<","<<p.y<<")";
	return out;
}
