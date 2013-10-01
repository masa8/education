/*! 
    DataType:
                POD
                Non-POD with implicitly default constructor
                Non-POD with explicitly default constructor

    NOTE*
    What's POD?
        POD ==> scalor type
                or
                pod class
                            no user-defined copy-assignment ope
                            no user-defined destructor
                            no non static memeber which is non POD
                            must be aggregate

        Aggregate           
                            1. no base class
                            2. no user-defined constructor
                            3. no virtual funciton
                            4. no private/protected non static mmember
 */
struct POD {
    int m;
};

struct NON_PODi {
    int m;
    ~NON_PODi(){}
};

struct NON_PODe {
    int m;
    NON_PODe():m(){}
    ~NON_PODe(){}
};


/*!
    Initialize type:

    zero initialize         C++98   C++03 
    default initialize      C++98   C++03
    value initialize                C++03

*/


int main (){ /*     +  C++11
                  + C++03                         
                  | uninit          value init(z)
                  | d init(un)      value init(z)
                  | d init(Dctor)   value init(Dtor)     
    

                + C++98
                =TYPE         TYPE()
        POD     | uninit        zero init
        NonPODi | d init(un)    d init(un) 
        NonPODe | d init(z)     d init(z)

    */
                                //C++98
    POD *x = new POD;           //indeterminate value
    NON_PODi *ix = new NON_PODi;    //default init (m is uninitialized)
    NON_PODe *ex = new NON_PODe;    //default init (m is zero-initialized)
    delete x;
    delete ix;
    delete ex;
                                //C++03
    POD *y = new POD;           //indeterminate value
    NON_PODi *iy = new NON_PODi;    //default init (m is uninitialized)
    NON_PODe *ey = new NON_PODe;    //default init (* DCtor called*)
    delete y;
    delete iy;
    delete ey;

                                    //C++98
    POD *p = new POD();             //* zero-init *
    NON_PODi *ip = new NON_PODi();  //defalut init (m is uninitialzed)
    NON_PODe *ep = new NON_PODe();  //default init (m is zero-initialized)
    delete p;
    delete ip;
    delete ep;
                                    //C++03
    POD *pp = new POD();            //value init (m is zero init'd)
    NON_PODi *ipp = new NON_PODi(); //value init (m is zero init'd)
    NON_PODe *epp = new NON_PODe(); //value init (DCtor called)
    delete pp;
    delete ipp;
    delete epp;

    

}
