namespace geometry{
    class Point{
        public :
            double x, y;

            Point(){
                x = 0; y = 0;
            }
            Point(double initx, double inity){
                x = initx, y = inity;
            }

            void showp(){
                printf("[x, y] -> [%f, %f]\n", x, y);
            }

            void scaling(double x_scale, double y_scale){
                x *= x_scale; y*= y_scale;
            }

            void transration(double dx, double dy){
                x += dy; y += dy;
            }
            void transration(Point base_p){
                x += base_p.x; y += base_p.y;
            }

            void rotation(double theta){
                Point res;
                res.x = x*cos(theta) - y*sin(theta);
                res.y = x*sin(theta) + y*cos(theta);
                x = res.x; y = res.y;
            }

            Point operator + (Point a){return Point(x+a.x, y+a.y);}
            Point operator - (Point a){return Point(x-a.x, y-a.y);}
            Point operator - (){return Point(-x, -y);}
    };
    istream& operator>>(istream& is, Point& a) { return is >> a.x >> a.y;}
    ostream& operator<<(ostream& os, Point& a) { return os << fixed << setprecision(10) << a.x << ' ' << a.y;}

    Point point_at_infinite(2525252, 2525241);

    double sgn(double a){
        double eps = 1e-8;
        if(a > eps)return 1;
        else if(a < -eps)return -1;
        return 0;
    }

    double cross(Point a, Point b){
        return a.x*b.y - a.y*b.x;
    }

    double dot(Point a, Point b){
        return a.x*b.x + a.y*b.y;
    }

    class Segment{
        public:
            Point s, t;

            Segment(){
                s = Point(); t = Point();
            }
            Segment(Point x, Point y){
                s = x; t = y;
            }

            //vector
            Point vect(){
                return t - s;
            }

            FP nor(){
                FP res;
                res.first = (t.y-s.y)/(t.x-s.x);
                res.second = s.y - res.first*s.x;
                return res;
            }
    };
    istream& operator>>(istream& is, Segment& a) { return is >> a.s >> a.t;}
    ostream& operator<<(ostream& os, Segment& a) { return os << a.s << ' ' << a.t;}

    //over -> 1, below -> -1, abc -> 2, cab -> -2, acb -> 0
    int isp(Point a, Point b, Point c){
        double cp = cross(b-a, c-a);
        if(cp)return sgn(cp);
        if(sgn(dot(a-b, c-b)) < 0)return 2;
        if(sgn(dot(b-a, c-a)) < 0)return -2;
        return 0;
    }

    //p1->p2への正射影
    Point projection(Point p1, Point p2, Point p){
        p2.transration(-p1);
        p.transration(-p1);
        double theta = atan(p2.y / p2.x);
        p.rotation(-theta);
        Point res(p.x, 0);
        res.rotation(theta);
        res.transration(p1);
        return res;
    }
    Point projection(Segment l, Point p){
        return projection(l.s, l.t, p);
    }

    //p1->p2と線対称な点
    Point reflection(Point p1, Point p2, Point p){
        p2.transration(-p1);
        p.transration(-p1);
        double theta = atan(p2.y / p2.x);
        p.rotation(-theta);
        Point res(p.x, -p.y);
        res.rotation(theta);
        res.transration(p1);
        return res;
    }

    //平行
    bool is_para(Segment l1, Segment l2){
        return cross(l1.vect(), l2.vect()) == 0;
    }

    //垂直
    bool is_orth(Segment l1, Segment l2){
        return dot(l1.vect(), l2.vect()) == 0;
    }

    //交差判定
    bool is_cross(Segment l1, Segment l2){
        return (isp(l1.s, l1.t, l2.s) * isp(l1.s, l1.t, l2.t) <= 0 &&
            isp(l2.s, l2.t, l1.s) * isp(l2.s, l2.t, l1.t) <= 0);
    }

    //交点の座標
    Point cross_point(Segment l1, Segment l2){
        double s = ((l2.t.y - l2.s.y)*(l2.t.x - l1.t.x) + (l2.s.x - l2.t.x)*(l2.t.y - l1.t.y))
                        / ((l1.s.x - l1.t.x)*(l2.t.y - l2.s.y) - (l2.t.x - l2.s.x)*(l1.s.y - l1.t.y));
        return Point(l1.s.x*s + (1-s)*(l1.t.x), l1.s.y*s + (1-s)*(l1.t.y));
    }

    //距離
    double dist(Point p, Point q){
        return sqrt((p-q).x*(p-q).x + (p-q).y*(p-q).y);
    }
    double dist(Segment l, Point p){
        if(sgn(dot(l.s-l.t, p-l.t)) < 0)return dist(l.t, p);
        if(sgn(dot(l.t-l.s, p-l.s)) < 0)return dist(l.s, p);
        return dist(p, projection(l, p));
    }
    double dist(Segment l1, Segment l2){
        if(is_cross(l1, l2))return 0;
        return min({dist(l1, l2.s), dist(l1, l2.t), dist(l2, l1.s), dist(l2, l1.t)});
    }

    bool compxf(const Point& p, const Point& q){
        if(p.x != q.x)return p.x < q.x;
        return p.y < q.y;
    }

    class Polygon{
        private :
            int v;
        public :
            vector<Point> p;
            Polygon(int N){
                p.resize(N); v = N;
            }
            Polygon(vector<Point> ps){
                p = ps; v = ps.size();
            }

            int size(){
                return v;
            }

            Point operator [](int i){return p[i];}

            bool is_convex(){
                int ov = 0;
                for(int i = 0; i < v; ++i)ov += sgn(cross(p[(i+1)%v]-p[i], p[(i+2)%v]-p[i]) >= 0);
                return ov == p.size() || ov == 0;
            }

            double area(){
                double res = 0;
                for(int i = 0; i < p.size()-1; ++i)res += cross(p[i], p[i+1]);
                res += cross(p[p.size()-1], p[0]);
                return abs(res)/2;
            }

            int containment(Point a){
                rep(i,v)if(isp(p[i], p[(i+1)%v], a) == 0)return 1;
                int th = 0;
                rep(i,v)if(is_cross(Segment(p[i], p[(i+1)%v]), Segment(point_at_infinite, a))){++th;}
                if(th % 2)return 2;
                return 0;
            }

            double convex_diameter(){
                if(size() == 2)return dist(p[0], p[1]);
                int i = 0, j = 0;
                rep(k, size()){
                    if(!compxf(p[i], p[k]))i = k;
                    if(compxf(p[j], p[k]))j = k;
                }
                double res = 0;
                int si = i, sj = j;
                while(i != sj || j != si){
                    res = max(res, dist(p[i], p[j]));
                    if(cross(p[(i+1)%size()] - p[i], p[(j+1)%size()] - p[j]) < 0){
                        i = (i + 1) % size();
                    }else{
                        j = (j + 1) % size();
                    }
                }
                return res;
            }
    };
    istream& operator>>(istream& is, Polygon& a) { rep(i,a.size()){is >> a.p[i];} return is; }

    //頂点で囲まれた領域の面積
    double area(Point a, Point b, Point c){
        return abs(cross(b-a, c-a))/2;
    }

    //辺上の点を含む
    //含まない場合には外積の評価を <= 0とする
    Polygon convex_hull(vector<Point> p){
        sort(all(p), compxf);
        int k = 0;
        vector<Point> q(p.size() * 2);
        for(int i = 0; i < p.size(); ++i){
            while(k > 1 && cross(q[k-1]-q[k-2], p[i]-q[k-1]) < 0) --k;
            q[k++] = p[i];
        }
        for(int i = p.size()-2, t = k; i >= 0; --i){
            while(k > t && cross(q[k-1]-q[k-2], p[i]-q[k-1]) < 0) --k;
            q[k++] = p[i];
        }
        q.resize(k-1);
        return Polygon(q);
    }
    Polygon convex_hull(Polygon pl){return convex_hull(pl.p);}

}
