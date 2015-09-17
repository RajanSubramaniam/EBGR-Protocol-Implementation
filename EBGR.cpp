#include <iostream>
#include <cmath>
using namespace std;

class edge_node
{
public:
    float dc;
    float di;
    float df;
    float len;
    float num;
    float dem;
    float dm;
    float a;
    float b;
    float c;
    const int r=49;
    float t1;
    float t2;
    float r1;
    float r2;
    const int beacon=6;
    float rho=0.3;
    float omega=0.2;
    float lamda=0.5;
    float result;


    float distance_calculation( float x, float y, float z, float w, float a, float b);
    float length ( float l1, float l2, float l3, float l4);
    float direction_motion(float j, float m, float n);
    float link_stability(float s, float e,float v, float j, float o, float q);
    float potential_score(float l, float d , float s);

};

float edge_node::distance_calculation( float x, float y, float z, float w, float a, float b)
{

    di= sqrt(pow((a-z),2)+pow((b-w),2));
    df= sqrt(pow((a-x),2)+pow((b-y),2));
    dc=1-(di/df);
    cout<<endl;
    return dc;
}


float edge_node::length ( float l1, float l2, float l3, float l4)
{


    len= sqrt(pow((l4-l1),2)+ pow((l3-l2),2));
    return len;
}

float edge_node::direction_motion(float j, float m, float n)
{


    num = (m* j) + (n * 0);
    dem = (sqrt(pow(m,2)+pow(n,2))) * (sqrt(pow(j,2)+pow(0,2)));
    dm = num/dem;
    cout<<"================================================================================================"<<endl;
    return dm;
}

float edge_node::link_stability(float s, float e,float v, float j, float o, float q)
{

    a=pow((o-q),2);
    c=pow((s-v),2)+pow((e-j),2) - r;
    b=2*(s-v)*(o-q);
    t1=((-b)+sqrt(abs(pow(b,2)- (4*a*c))))/(2*a);
    t2=((-b)-sqrt(abs(pow(b,2)- (4*a*c))))/(2*a);
    r1=t1/beacon;
    r2=t2/beacon;
    cout<<"================================================================================================"<<endl;
    if (r1>r2)
    {
        return r1;
    }
    else
    {
        return r2;
    }

}

float edge_node::potential_score(float l, float d , float s)
{

    result= (rho*l)+(omega*d)+(lamda*s);
    cout<<"================================================================================================"<<endl;
    return result;
}

float range(int x1, int y1, int x2, int y2)
{
    float rr;
    rr=sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    return rr;
}

int main()
{
    edge_node ed1;
    edge_node ed2;
    edge_node ed3;
    edge_node ed4;
    edge_node ed5;
    edge_node ed6;
    edge_node ed7;
    edge_node ed8;
    edge_node ed9;
    edge_node ed10;
    edge_node ed11;


    int no;
    const int mtr=600;
    const int l1tr=500;
    const int l2tr=400;
    const int l3tr=300;
    const int l4tr=200;
    const int l5tr=100;
    const int l6tr=50;


    cout<<"Welcome to vanet simulation "<<"\n";
    cout<<"Enter the total number of nodes : ";
    cin>>no;
    cout<<"The total number of participation nodes : "<<no<<endl;
    cout<<endl;
    for (int i=1; i<= no; i++)
        cout<<""<<"{"<<i<<"}"<<endl;

    cout<<endl;
    float a[14][2]={};
    for(int i= 1; i<=14; i++)
    {
        for(int j=1; j<=2; j++)
        {

            cout<<"Enter the x-axis and y-axis : ";
            cin>>a[i][j];
        }
    }
    cout<<endl;
    for (int i=1; i<=14; i++)
    {
        for(int j=1; j<=2; j++)
        {
            cout<<"a["<<i<<"]"<<"["<<j<<"]== ";
            cout<<a[i][j]<<endl;
        }
    }

    cout<<endl;
    float d12,d13,d14,d15,d16,d17,d18,d19,d110,d111,d112,d113,d114;

    d12=range(a[1][1],a[1][2],a[2][1],a[2][2]);
    cout<<endl;
    cout<<"Neighbor Node Calculation :"<<endl;
    cout<<"D12 == "<<d12<<endl;

    d13=range(a[1][1],a[1][2],a[3][1],a[3][2]);
    cout<<"D13 == "<<d13<<endl;

    d14=range(a[1][1],a[1][2],a[4][1],a[4][2]);
    cout<<"D14 == "<<d14<<endl;

    d15=range(a[1][1],a[1][2],a[5][1],a[5][2]);
    cout<<"D15 == "<<d15<<endl;

    d16=range(a[1][1],a[1][2],a[6][1],a[6][2]);
    cout<<"D16 == "<<d16<<endl;

    d17=range(a[1][1],a[1][2],a[7][1],a[7][2]);
    cout<<"D17 == "<<d17<<endl;

    d18=range(a[1][1],a[1][2],a[8][1],a[8][2]);
    cout<<"D18 == "<<d18<<endl;

    d19=range(a[1][1],a[1][2],a[9][1],a[9][2]);
    cout<<"D19 == "<<d19<<endl;

    d110=range(a[1][1],a[1][2],a[10][1],a[10][2]);
    cout<<"D110 == "<<d110<<endl;

    d111=range(a[1][1],a[1][2],a[11][1],a[11][2]);
    cout<<"D111 == "<<d111<<endl;

    d112=range(a[1][1],a[1][2],a[12][1],a[12][2]);
    cout<<"D112 == "<<d112<<endl;

    d113=range(a[1][1],a[1][2],a[13][1],a[13][2]);
    cout<<"D113 == "<<d113<<endl;

    d114=range(a[1][1],a[1][2],a[14][1],a[14][2]);
    cout<<"D114 == "<<d114<<endl;

    cout<<endl;
    float dn[13]={d12,d13,d14,d15,d16,d17,d18,d19,d110,d111,d112,d113,d114};

    for (int i=0; i<13; i++)
    {
        if(dn[i]<mtr && dn[i]>l1tr)
        {
            cout<<"Transmission range from 500 to 600 "<<endl;
            cout<<dn[i]<<endl;
        }
        else if(dn[i]<l1tr && dn[i]>l2tr)
        {
            cout<<"Transmission range from 400 to 500 "<<endl;
            cout<<dn[i]<<endl;
        }
        else if(dn[i]<l2tr && dn[i]>l3tr)
        {
            cout<<"Transmission range from 300 to 400 "<<endl;
            cout<<dn[i]<<endl;
        }
        else if(dn[i]<l3tr && dn[i]>l4tr)
        {
            cout<<"Transmission range from 200 to 300 "<<endl;
            cout<<dn[i]<<endl;
        }
        else if(dn[i]<l4tr && dn[i]>l5tr)
        {
            cout<<"Transmission range from 100 to 200 "<<endl;
            cout<<dn[i]<<endl;
        }
        else if(dn[i]<l5tr && dn[i]>l6tr)
        {
            cout<<"Transmission range from 50 to 100 "<<endl;
            cout<<dn[i]<<endl;
        }
        else
        {
            cout<<"Transmission range below 50 "<<endl;
            cout<<dn[i]<<endl;
        }
    }

    cout<<endl;
    float v[14]={};

    for ( int i=1; i<=14; i++)
    {
        cout<<"Enter the velocity of node "<<i<<" -";
        cin>>v[i];
        cout<<endl;

    }
    for (int i=1; i<=14; i++)
    {
        cout<<"V["<<i<<"]--"<<v[i]<<endl;
    }


    cout<<endl;
    cout<<"Nodes in between 50 to 100 : "<<endl;
    cout<<"Source:N1"<<endl;
    cout<<"N2:"<<endl;

    float dc1;
    dc1=ed1.distance_calculation(a[1][1],a[1][2],a[2][1],a[2][2],a[14][1],a[14][2]);
    cout<<"Dc== "<<dc1<<endl;
    float le1;
    le1=ed1.length(a[2][1],a[2][2],a[14][1],a[14][2]);
    float dm1;
    dm1=ed1.direction_motion(le1,v[2],v[14]);
    cout<<"direction of motion== "<<dm1<<endl;
    float rls1;
    rls1=ed1.link_stability(a[1][1],a[1][2],a[2][1],a[2][2],v[1],v[2]);
    cout<<"Reckoning Link State== "<<rls1 <<endl;
    float ps1;
    ps1=ed1.potential_score(dc1,dm1,rls1);
    cout<<"Potential Score== "<<ps1<<endl;

    cout<<endl;
    cout<<"N3:"<<endl;
    float dc2;
    dc2=ed2.distance_calculation(a[1][1],a[1][2],a[3][1],a[3][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc2<<endl;
    float le2;
    le2=ed2.length(a[3][1],a[3][2],a[14][1],a[14][2]);
    float dm2;
    dm2=ed2.direction_motion(le2,v[3],v[14]);
    cout<<"direction of motion== "<<dm2<<endl;
    float rls2;
    rls2=ed2.link_stability(a[1][1],a[1][2],a[3][1],a[3][2],v[1],v[3]);
    cout<<"Reckoning Link State== "<<rls2 <<endl;
    float ps2;
    ps2=ed2.potential_score(dc2,dm2,rls2);
    cout<<"Potential Score== "<<ps2<<endl;

    cout<<endl;
    cout<<"N4:"<<endl;
    float dc3;
    dc3=ed3.distance_calculation(a[1][1],a[1][2],a[4][1],a[4][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc3<<endl;
    float le3;
    le3=ed3.length(a[4][1],a[4][2],a[14][1],a[14][2]);
    float dm3;
    dm3=ed3.direction_motion(le3,v[4],v[14]);
    cout<<"direction of motion== "<<dm3<<endl;
    float rls3;
    rls3=ed3.link_stability(a[1][1],a[1][2],a[4][1],a[4][2],v[1],v[4]);
    cout<<"Reckoning Link State== "<<rls3 <<endl;
    float ps3;
    ps3=ed3.potential_score(dc3,dm3,rls3);
    cout<<"Potential Score== "<<ps3<<endl;
    cout<<endl;

    if(ps1>ps2 && ps1>ps3)
    {
        cout<<"Edge Node = N2"<<endl;
    }
    else if (ps2>ps3 && ps2>ps1)
    {
        cout<<"Edge Node = N3"<<endl;
    }
    else
    {
        cout<<"Edge Node = N4"<<endl;
        cout<<endl;
        cout<<"Transmission Route :"<<endl;
        cout<<"N1--N4"<<endl;
        cout<<endl;
    }



    cout<<"Nodes in between 100 to 200 : "<<endl;
    cout<<"Source:N4 "<<endl;

    cout<<endl;
    cout<<"N5:"<<endl;
    float dc4;
    dc4=ed4.distance_calculation(a[4][1],a[4][2],a[5][1],a[5][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc4<<endl;
    float le4;
    le4=ed4.length(a[5][1],a[5][2],a[14][1],a[14][2]);
    float dm4;
    dm4=ed4.direction_motion(le4,v[5],v[14]);
    cout<<"direction of motion== "<<dm4<<endl;
    float rls4;
    rls4=ed4.link_stability(a[4][1],a[4][2],a[5][1],a[5][2],v[4],v[5]);
    cout<<"Reckoning Link State== "<<rls4 <<endl;
    float ps4;
    ps4=ed4.potential_score(dc4,dm4,rls4);
    cout<<"Potential Score== "<<ps4<<endl;
    cout<<endl;

    cout<<endl;
    cout<<"N6:"<<endl;
    float dc5;
    dc5=ed5.distance_calculation(a[4][1],a[4][2],a[6][1],a[6][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc5<<endl;
    float le5;
    le5=ed5.length(a[6][1],a[6][2],a[14][1],a[14][2]);
    float dm5;
    dm5=ed5.direction_motion(le5,v[6],v[14]);
    cout<<"direction of motion== "<<dm5<<endl;
    float rls5;
    rls5=ed5.link_stability(a[4][1],a[4][2],a[6][1],a[6][2],v[4],v[6]);
    cout<<"Reckoning Link State== "<<rls5 <<endl;
    float ps5;
    ps5=ed5.potential_score(dc5,dm5,rls5);
    cout<<"Potential Score== "<<ps5<<endl;
    cout<<endl;

    if (ps4>ps5)
    {
        cout<<"Edge Node:N5 "<<endl;
    }
    else
    {
        cout<<"Edge Node:N6 "<<endl;
        cout<<"Transmission Route :"<<endl;
        cout<<"N1--N4--N6"<<endl;
    }



    cout<<endl;
    cout<<"Nodes in between 200 to 300 :"<<endl;
    cout<<"Source:N6 "<<endl;

    cout<<endl;
    cout<<"N8:"<<endl;
    float dc6;
    dc6=ed6.distance_calculation(a[6][1],a[6][2],a[8][1],a[8][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc6<<endl;
    float le6;
    le6=ed6.length(a[8][1],a[8][2],a[14][1],a[14][2]);
    float dm6;
    dm6=ed6.direction_motion(le6,v[8],v[14]);
    cout<<"direction of motion== "<<dm6<<endl;
    float rls6;
    rls6=ed6.link_stability(a[6][1],a[6][2],a[8][1],a[8][2],v[6],v[8]);
    cout<<"Reckoning Link State== "<<rls6 <<endl;
    float ps6;
    ps6=ed6.potential_score(dc6,dm6,rls6);
    cout<<"Potential Score== "<<ps6<<endl;
    cout<<endl;

    cout<<endl;
    cout<<"N10:"<<endl;
    float dc7;
    dc7=ed7.distance_calculation(a[6][1],a[6][2],a[10][1],a[10][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc7<<endl;
    float le7;
    le7=ed7.length(a[10][1],a[10][2],a[14][1],a[14][2]);
    float dm7;
    dm7=ed7.direction_motion(le7,v[10],v[14]);
    cout<<"direction of motion== "<<dm7<<endl;
    float rls7;
    rls7=ed7.link_stability(a[6][1],a[6][2],a[10][1],a[10][2],v[6],v[10]);
    cout<<"Reckoning Link State== "<<rls7 <<endl;
    float ps7;
    ps7=ed7.potential_score(dc7,dm7,rls7);
    cout<<"Potential Score== "<<ps7<<endl;
    cout<<endl;

    if(ps6>ps7)
    {
        cout<<"Edge Node:N8"<<endl;
        cout<<endl;
        cout<<"Transmission Route :"<<endl;
        cout<<"N1--N4--N6--N8"<<endl;
    }
    else
    {
        cout<<"Edge Node:N10"<<endl;
    }



    cout<<endl;
    cout<<"Nodes in between 300 to 400 :"<<endl;
    cout<<"Source:N8"<<endl;

    cout<<endl;
    cout<<"N7:"<<endl;
    float dc8;
    dc8=ed8.distance_calculation(a[8][1],a[8][2],a[7][1],a[7][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc8<<endl;
    float le8;
    le8=ed8.length(a[7][1],a[7][2],a[14][1],a[14][2]);
    float dm8;
    dm8=ed8.direction_motion(le8,v[7],v[14]);
    cout<<"direction of motion== "<<dm8<<endl;
    float rls8;
    rls8=ed8.link_stability(a[8][1],a[8][2],a[7][1],a[7][2],v[8],v[7]);
    cout<<"Reckoning Link State== "<<rls8 <<endl;
    float ps8;
    ps8=ed8.potential_score(dc8,dm8,rls8);
    cout<<"Potential Score== "<<ps8<<endl;
    cout<<endl;

    cout<<endl;
    cout<<"N9:"<<endl;
    float dc9;
    dc9=ed9.distance_calculation(a[8][1],a[8][2],a[9][1],a[9][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc9<<endl;
    float le9;
    le9=ed9.length(a[9][1],a[9][2],a[14][1],a[14][2]);
    float dm9;
    dm9=ed9.direction_motion(le9,v[9],v[14]);
    cout<<"direction of motion== "<<dm9<<endl;
    float rls9;
    rls9=ed9.link_stability(a[8][1],a[8][2],a[9][1],a[9][2],v[8],v[9]);
    cout<<"Reckoning Link State== "<<rls9 <<endl;
    float ps9;
    ps9=ed9.potential_score(dc9,dm9,rls9);
    cout<<"Potential Score== "<<ps9<<endl;

    cout<<endl;
    cout<<"N12:"<<endl;
    float dc10;
    dc10=ed10.distance_calculation(a[8][1],a[8][2],a[12][1],a[12][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc10<<endl;
    float le10;
    le10=ed10.length(a[12][1],a[12][2],a[14][1],a[14][2]);
    float dm10;
    dm10=ed10.direction_motion(le10,v[12],v[14]);
    cout<<"direction of motion== "<<dm10<<endl;
    float rls10;
    rls10=ed10.link_stability(a[8][1],a[8][2],a[12][1],a[12][2],v[8],v[12]);
    cout<<"Reckoning Link State== "<<rls10 <<endl;
    float ps10;
    ps10=ed10.potential_score(dc10,dm10,rls10);
    cout<<"Potential Score== "<<ps10<<endl;

    if (ps8>ps9 && ps8>ps10)
    {
        cout<<"Edge Node:N7"<<endl;
        cout<<"Transmission Route: "<<endl;
        cout<<"N1--N4--N6--N8--N7"<<endl;
    }
    else if (ps9>ps10 && ps9>ps8)
    {
        cout<<"Edge Node:N9"<<endl;
    }
    else
    {
        cout<<"Edge Node:N10"<<endl;
    }

    cout<<endl;
    cout<<"Nodes in between 400 to 500 : "<<endl;
    cout<<"Source:N7"<<endl;

    cout<<endl;
    cout<<"N11:"<<endl;
    float dc11;
    dc11=ed11.distance_calculation(a[7][1],a[7][2],a[11][1],a[11][2],a[14][1],a[14][2]);
    cout<<"DC== "<<dc11<<endl;
    float le11;
    le11=ed11.length(a[11][1],a[11][2],a[14][1],a[14][2]);
    float dm11;
    dm11=ed11.direction_motion(le11,v[11],v[14]);
    cout<<"direction of motion== "<<dm11<<endl;
    float rls11;
    rls11=ed11.link_stability(a[7][1],a[7][2],a[11][1],a[11][2],v[7],v[11]);
    cout<<"Reckoning Link State== "<<rls11 <<endl;
    float ps11;
    ps11=ed11.potential_score(dc11,dm11,rls11);
    cout<<"Potential Score== "<<ps11<<endl;
    cout<<"Edge Node:N11"<<endl;
    cout<<endl;
    cout<<"Transmission Route :"<<endl;
    cout<<"N1--N4--N6--N8--N7--N11--N14"<<endl;
    cout<<endl;
    cout<<"Original Source: N1"<<endl;
    cout<<"Desired Destination : N14"<<endl;


    return 0;

}
