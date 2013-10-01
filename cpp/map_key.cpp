/*!
    map key requrements:
                            copyable        MUST
                            assignable      MUST
                            less than       Option (if no comp class MUST)
 */
#include <stdio.h>
#include <map>

struct Key {
    int x;
    int y;
    
    Key(int xin,int yin):x(xin),y(yin){}
    /*
    bool operator < (const Key& rhs) const {
            printf("this.x:%d < operator rhs.x%d \n", this->x,rhs.x);
            return this->x < rhs.x;
    }*/

private:
    Key(){}
};

struct KeyComp{

    bool operator() (const Key& lhr, const Key& rhs ) const 
    {
            return lhr.x < rhs.x;
    }


};

int main(){
    
    Key a(1,2);
    std::map<Key,int,KeyComp> m;

    m.insert(std::pair<Key,int>(Key(1,1),1));
    m.insert(std::pair<Key,int>(Key(2,2),2));
    m[Key(3,3)]=3;
    printf("m.size:%d\n",m.size());

} 
