#include <stdio.h>
/*
Name : Abhinav A
Date : 10 - 10 - 24
Description : Baremetal Assesment
Sample input :
Sample Output :
 */


//Creating datatype vector with members i , j, k specifying the vector quantities

typedef struct
{
    double i,j,k;
}vector;
//function for creating vector 
vector create_v(double x,double y,double z)
{
    vector v;
    v.i = x;
    v.j = y;
    v.k = z;
    return v;
}
 
// required Vector operations functions 
double dot(vector v1,vector v2)
{
    return ((v1.i * v2.i) + (v1.j * v2.j) + (v1.k * v2.k));
}

vector cross(vector v1,vector v2)
{
    vector V = create_v(v1.j*v2.k - v1.k * v2.j,v1.k*v2.i -v1.i * v2.k,v1.i * v2.j - v1.j*v2.i);
    return V;
}
 

//Creating the Quaternion by including the vector 
typedef struct 
{
    double scalar;
    vector v;
}Quaternion;

//Function to initialise the quaternion
Quaternion quat(double s, double x,double y,double z)
{
    Quaternion q;
    q.scalar = s;
    q.v = create_v(x,y,z);
    return q;
}
//Function for complementing 
Quaternion complement(Quaternion q)
{
    q.v.i = -q.v.i;
    q.v.j = -q.v.j;
    q.v.k = -q.v.k;
    return q;

}

//function for dot operation 
double dot_quat(Quaternion q1,Quaternion q2)
{
    double dotproduct = dot(q1.v,q2.v);
    return (q1.scalar * q2.scalar + dotproduct);
}

//Quaternion Multiplication(formula used qmul = s1 x v2 + s2 x v1 + v1 cross v2)
Quaternion mul(Quaternion q1,Quaternion q2)
{
    double dotproduct = dot(q1.v,q2.v);
    vector crosspro = cross(q1.v,q2.v);
    double scalar = q1.scalar * q2.scalar - dotproduct;
    vector v_new = create_v(q1.scalar * q2.v.i + q2.scalar*q1.v.i + crosspro.i,
	    q1.scalar * q2.v.j + q2.scalar * q1.v.j + crosspro.j,
	    q1.scalar * q2.v.k + q2.scalar * q1.v.k + crosspro.k);
    return quat(scalar,v_new.i,v_new.j,v_new.k);
}

int main()
{
    Quaternion q,q_bar,a;
    double b;
    q = quat(0,1,1,1);     //Function call for creating the quaternion
    printf("Quaternion: (%g,%g,%g,%g)\n",q.scalar,q.v.i,q.v.j,q.v.k);
    q_bar = complement(q); //Complementing
    printf("Q_bar: (%g,%g,%g,%g)\n",q_bar.scalar,q_bar.v.i,q_bar.v.j,q_bar.v.k);
    a = mul(q,q_bar);  //FUnction call on Quaterion multiplication
    printf("Q_mul: (%g,%g,%g,%g)\n",a.scalar,a.v.i,a.v.j,a.v.k);
    b = dot_quat(q,q_bar); //Dot operation function call
    printf("q . q_bar = %g\n",b);
    return 0;
}

