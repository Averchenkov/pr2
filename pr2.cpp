#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef pair<int,int> Tochka;

struct Circle
{
    Tochka centr;
    float radius;
};

struct Triangle
{
    Tochka a;
    Tochka b;
    Tochka c;
};

struct Quadrangle
{
    Tochka a;
    Tochka b;
    Tochka c;
    Tochka d;
};

float otrezok(Tochka t1,Tochka t2)
{
    return sqrt(pow((t1.first-t2.first),2)+pow((t1.second-t2.second),2));
}

void raspologenie(Tochka t,Circle k,int *in,int *out,int *touch)
{
    if(otrezok(t,k.centr)>k.radius) *out=*out+1;
    else if(otrezok(t,k.centr)==k.radius) *touch=*touch+1;
    else if(otrezok(t,k.centr)<k.radius) *in=*in+1;   
}


int proverka(Circle k,Triangle t)
{
   int in=0;
   int out=0;
   int touch=0;
   raspologenie(t.a,k,&in,&out,&touch);
   raspologenie(t.b,k,&in,&out,&touch);
   raspologenie(t.c,k,&in,&out,&touch);
   if(out>0) return 1;
   else if(touch==3) return 2;
   else return 3;
}

int proverka(Circle k,Quadrangle r)
{
   int in=0;
   int out=0;
   int touch=0;
   raspologenie(r.a,k,&in,&out,&touch);
   raspologenie(r.b,k,&in,&out,&touch);
   raspologenie(r.c,k,&in,&out,&touch);
   raspologenie(r.d,k,&in,&out,&touch);
   if(out>0) return 1;
   else if(touch==4) return 2;
   else return 3;
}

int main()
{
    Circle k;
    string s;
    
    cout << "Vvedite:" << endl << endl;
    cout << "Figuru(triangle/quadrangle): ";
    cin >> s;
    cout << "radius kruga: ";
    cin >> k.radius;
    cout << "x y centra kruga: ";
    cin >> k.centr.first >> k.centr.second;
    cout << endl;
    
    if (s=="triangle")
    {
        Triangle t;
        
        cout << "tochka a: ";
        cin >> t.a.first >> t.a.second;
        cout << "tochka b: ";
        cin >> t.b.first >> t.b.second;
        cout << "tochka c: ";
        cin >> t.c.first >> t.c.second;
        cout << endl;
        
        switch (proverka(k,t))
        {
            case 1:
                cout << "OUTSIDE" << endl;
                break;
            case 2:
                cout << "TOUCH" << endl;
                break;
            case 3:
                cout << "INSIDE" << endl;
                break;
            default:
                cout << "ERROR" << endl;
        }
    }
    else if (s=="quadrangle")
    {
        Quadrangle r;
        
        cout << "tochka a: ";
        cin >> r.a.first >> r.a.second;
        cout << "tochka b: ";
        cin >> r.b.first >> r.b.second;
        cout << "tochka c: ";
        cin >> r.c.first >> r.c.second;
        cout << "tochka d: ";
        cin >> r.d.first >> r.d.second;
        cout << endl;
        
        switch (proverka(k,r))
        {
            case 1:
                cout << "OUTSIDE" << endl;
                break;
            case 2:
                cout << "TOUCH" << endl;
                break;
            case 3:
                cout << "INSIDE" << endl;
                break;
            default:
                cout << "ERROR" << endl;
        }
    }
    return 0;
}
    
