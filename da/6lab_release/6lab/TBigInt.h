#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <iomanip>

const int R = 4;//4
const int BASE = 10000;//10000

class TBigInt {
public:
    TBigInt(){};
    TBigInt(const std::string & str);
    TBigInt(int n);

    ~TBigInt(){};

    friend std::ostream& operator<< (std::ostream& stream, const TBigInt & number);

    TBigInt operator+( const TBigInt & other);
    TBigInt operator-( const TBigInt & other);
    TBigInt operator*( const TBigInt & other);
    TBigInt operator/( const TBigInt & other);
    bool operator~();
    TBigInt power( TBigInt & p);


    bool operator<( const TBigInt & other);
    bool operator>( const TBigInt & other);
    bool operator==( const TBigInt & other);
    bool operator!=( const TBigInt & other);
    size_t size() const { return m_data.size(); }
    bool empty() const { return m_data.empty(); }
    void delete_zeros();

protected:
    std::vector<int> m_data;
};