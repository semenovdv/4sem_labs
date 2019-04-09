#include "TBigInt.h"


TBigInt::TBigInt( const std::string & str ) {
    std::string text = str;
    int move = 0;
    // чистка нулей 
    while (text[move] == '0') move++;

    if(text.size() == 0) text = "0";

    for (int i = text.size() - 1; i >= move; i -= R) {
        // отрезок длиной R или меньше
        int start = i - R + 1;
        int len = R;
        if (start < 0){
            len += start;
            start = 0;
        } 
        std::string st = text.substr(start, len);
        
        int sum = 0;
        for (int j = 0; j < st.size(); j++) {
            sum *= 10;
            sum += st[j] - '0';
        }
        
        m_data.push_back(sum);

    }
    if (m_data.size() == 0) m_data.push_back(0);
    
}


TBigInt::TBigInt(int n){
    if (n < BASE)
        m_data.push_back(n);
    else 
        while(n){
            m_data.push_back(n % BASE);
            n/=BASE;
        }
}

// удаляет лидирующие нули после вычитания
void TBigInt::delete_zeros() {
    while( m_data.size() > 1 && m_data.back() == 0 ) { m_data.pop_back(); }
}

// вывод числа в консоль
std::ostream &operator<<( std::ostream &stream, const TBigInt & num ) {
    int n = num.m_data.size();
    if (n == 0)
        return stream;
    stream << num.m_data[n - 1];
    for (int i = n - 2; i >= 0; --i)
        stream << std::setfill('0') << std::setw(R) << num.m_data[i];
    
    return stream;

}


TBigInt TBigInt::operator+( const TBigInt & other ){
    size_t n = std::max( this->size(), other.size());
    TBigInt res;

    int r = 0; // остаток
    int k = 0;
    for( size_t i = 0; i < n; ++i){

        if( m_data.size() <= i ) k = other.m_data[i]; // если правый больше по размеру
        
        else if( other.size() <= i ) k = m_data[i]; // если наш больше 
        
        else k = m_data[i] + other.m_data[i]; // оба подходят

        k += r;
        res.m_data.push_back( k % BASE );
        r = k / BASE;        
    }
    if (r) res.m_data.push_back(r);
    res.delete_zeros();
    return res;

}

TBigInt TBigInt::operator-( const TBigInt & other ){
    size_t n = this->size();
    TBigInt result;
    int r = 0; 
    int k = 0;
    for (size_t i = 0; i < n; ++i) {

        int res = 0;
        if (other.size() <= i) {
            res = m_data[i] + k;
        }
        else {
            res = m_data[i] - other.m_data[i] + k;
        }
        k = 0;

        if( res < 0 ) {
            res += BASE;
            k = -1;
        }
        r = res % BASE; // ???
        
        result.m_data.push_back( r );
    }
    result.delete_zeros();
    return result;
}


TBigInt TBigInt::operator*( const TBigInt & other ){
    TBigInt result;
    result.m_data.resize(m_data.size() + other.m_data.size());

    int k = 0;
    int r = 0;

    for (int i = 0; i < m_data.size(); ++i) {
        //int carry = 0;
        for (int j = 0; j < other.m_data.size(); ++j) {
            k = other.m_data[j] * this->m_data[i] + result.m_data[i+j];
            r = k / BASE;
            result.m_data[i+j+1] = result.m_data[i+j+1] + r;
            result.m_data[i+j] = k % BASE;
        }
    }
    result.delete_zeros();
    return result;
}

// TODO fix this
TBigInt TBigInt::operator/(const TBigInt & other ){
    TBigInt result = TBigInt(0);
    TBigInt cv = TBigInt(0);

    result.m_data.resize(m_data.size());
    for (int i = m_data.size() - 1; i >= 0; --i){
        cv.m_data.insert(cv.m_data.begin(), m_data[i]);
        if (!cv.m_data.back())
            cv.m_data.pop_back();
        int x = 0, l = 0, r = BASE;
        while (l <= r) {
            int m = (l + r) / 2;
            TBigInt cur = TBigInt(m) * other;
            if (cur < cv || cur == cv) {
                x = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        result.m_data[i] = x;
        cv = cv - TBigInt(x) * other;
    }
    result.delete_zeros();
    return result;
}


TBigInt TBigInt::power( TBigInt & r){
    if (TBigInt(0) == (*this)) return TBigInt(0);
    if ((*this) == TBigInt(1)) return TBigInt(1);
    if (r == TBigInt(0)) return TBigInt(1);
    if (r == TBigInt(1)) return (*this);

    TBigInt res(1);
    while (r != TBigInt(0)) {
        if (~r){
            res = res * (*this);
        }
        (*this) = (*this) * (*this);
        r = r/2;
    }
    return res;
}

// проверка %2
bool TBigInt::operator~(){
    if (this->m_data[0]%2) return true;
    return false;
}

bool  TBigInt::operator<( const TBigInt & other){
    if (this->size() != other.size()) return (this->size() < other.size() ? true : false);
    else {
        for (int i = other.size()-1; i >= 0; i--) {
            if( other.m_data[i] != this->m_data[i] )
                {
                    return this->m_data[i] < other.m_data[i];
                }
    
        }
    }
    return false;
    
}


bool TBigInt::operator>( const TBigInt & other){
    if (this->size() != other.size()) return (this->size() > other.size() ? true : false);
    else {
        for (int i = other.size()-1; i >= 0; i--) {
            if( other.m_data[i] != this->m_data[i] )
                {
                    return this->m_data[i] > other.m_data[i];
                }
    
        }
    }
    return false;
}


bool TBigInt::operator==( const TBigInt & other){
    if (this->size() != other.size()) return false;
    else {
        for (int i = other.size()-1; i >= 0; i--) {
            if( other.m_data[i] != this->m_data[i] )
                {
                    return false;
                }
    
        }
    }
    return true;
}

bool TBigInt::operator!=( const TBigInt & other){
    if (this->size() != other.size()) return true;
    else {
        for (int i = other.size()-1; i >= 0; i--) {
            if( other.m_data[i] != this->m_data[i] )
                {
                    return true;
                }
    
        }
    }
    return false;
}

