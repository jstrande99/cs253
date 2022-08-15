#ifndef RANGE_H_INCLUDED
#define RANGE_H_INCLUDED

#include <iostream>
#include <stdexcept>

template <typename T>
class Range{
    T l_range, h_range; 
    public:
        Range();
        Range(T data) : l_range(data), h_range(data) {}
        Range(const T l, const T h) : l_range(l), h_range(h) {}
        Range( T& rhs): l_range(rhs.l_range), h_range(rhs.h_range) {}
        Range<T> assign(const T l, const T h); 
        T min() const {return l_range;}
        T max() const {return h_range;}
        Range<T> operator+=(const Range<T>&);
        Range<T> operator-=(const Range<T>&);
        Range<T> operator*=(const Range<T>&);
        Range<T> operator/=(const Range<T>&);
        
        Range<T> operator+(const Range<T>&);
        Range<T> operator-(const Range<T>&);
        Range<T> operator*(const Range<T>&);
        Range<T> operator/(const Range<T>&) const;
        bool operator==(const Range<T>&);
        bool operator!=(const Range<T>&);

        friend std::istream &operator>>(std::istream &is, Range<T> &rhs){
            std::string x, y; 
            while(is >> x && x != "]"){
                y+=x;
            }
            bool flag = true; 
            x = "";
            for(auto z: y){
                if(isdigit(z) && flag){
                    x+=z;
                    rhs.l_range = stoi(x);
                }
                if(isdigit(z) && !flag){
                    x+=z;
                    rhs.h_range = stoi(x);
                }
                if(z == ','){
                    flag = false;
                    x="";
                }
            }
            flag = false;
            
            return is;
        }

};
template <typename T>
Range<T> Range<T>::assign(const T l, const T h) {
    if(l > h){
        std::string s = "[" + std::to_string(l) + ", " + std::to_string(h) + "]";
        throw std::runtime_error(s);
    }
    else{
        l_range = l; 
        h_range = h; 
    }
    return *this;
}

template <typename T>
Range<T> Range<T>::operator+=(const Range<T> &rhs){
    Range<T> x(*this);
    x.l_range = l_range + rhs.l_range; 
    if(x.l_range > l_range + rhs.h_range){
        x.l_range = l_range + rhs.h_range;
    }
    x.h_range = h_range + rhs.h_range;
    if(x.h_range < h_range + rhs.l_range){
        x.h_range = h_range + rhs.l_range;
    }
    l_range = x.l_range;
    h_range = x.h_range;
    return *this;
}
template <typename T>
Range<T> Range<T>::operator-=(const Range<T> &rhs){
    Range<T> x(*this);
    x.l_range = l_range - rhs.l_range;
    if(x.l_range > l_range - rhs.h_range){
        x.l_range = l_range - rhs.h_range;
    }
    x.h_range = h_range - rhs.h_range;
    if(x.h_range < h_range  - rhs.l_range){
        x.h_range = h_range - rhs.l_range;
    }
    l_range = x.l_range;
    h_range = x.h_range;
    return *this;
}
template <typename T>
Range<T> Range<T>::operator*=(const Range<T> &rhs){ 
    Range<T> x(*this);
    if(l_range * rhs.l_range > h_range * rhs.l_range){
        x.l_range = h_range * rhs.l_range;
    }else{
        x.l_range = l_range * rhs.l_range;
    }
    
    if(h_range * rhs.h_range < l_range * rhs.h_range){
        x.h_range = l_range * rhs.h_range;
    }else{
        x.h_range = h_range * rhs.h_range;
    }
    l_range = x.l_range;
    h_range = x.h_range;
    return *this;
}
template <typename T>
Range<T> Range<T>::operator/=(const Range<T> &rhs){
    Range<T> x(*this);
    if(rhs.h_range >= 0 && rhs.l_range <= 0){
        // std::string s = "Zero in second range (" + rhs.l_range + "," + rhs.h_range + "), cannot divide (" + l_range + "," + h_range +")\n";
        std::string s = "[" + std::to_string(l_range) + ", " + std::to_string(h_range) + "] / [" + std::to_string(rhs.l_range) + ", " + std::to_string(rhs.h_range) + "]";
        throw std::runtime_error(s);
    }else{
        x.l_range = l_range / rhs.l_range;
        if(x.l_range > l_range/ rhs.h_range){
            x.l_range = l_range / rhs.h_range;
        }
        x.h_range = h_range / rhs.h_range;
        if(x.h_range < h_range / rhs.l_range){
            x.h_range = h_range / rhs.l_range;
        }
        l_range = x.l_range;
        h_range = x.h_range;
        return *this;
    }
}

template <typename T>
Range<T> Range<T>::operator+(const Range<T> &rhs){
    Range<T> x(*this);
    x.l_range = l_range + rhs.l_range;
    if(x.l_range > l_range + rhs.h_range){
        x.l_range = l_range + rhs.l_range;
    }
    x.h_range = h_range + rhs.h_range;
    if(x.h_range < h_range + rhs.l_range){
        x.h_range = h_range + rhs.l_range;
    }
    return x;
}
template <typename T>
Range<T> Range<T>::operator-(const Range<T> &rhs){
    Range<T> x(*this);
    x.l_range = l_range - rhs.l_range;
    if(x.l_range > l_range - rhs.h_range){
        x.l_range = l_range - rhs.h_range;
    }
    x.h_range = h_range - rhs.h_range;
    if(x.h_range < h_range - rhs.l_range){
        x.h_range = h_range - rhs.l_range; 
    }
    return x;
}
template <typename T>
Range<T> Range<T>::operator*(const Range<T> &rhs){
    Range<T> x(*this);
    x.l_range = l_range * rhs.l_range;
    if(x.l_range > l_range * rhs.h_range){
        x.l_range = l_range * rhs.h_range;
    }
    x.h_range = h_range * rhs.h_range;
    if(x.h_range < h_range * rhs.l_range){
        x.h_range = h_range * rhs.l_range;
    }
    return x;
}
template <typename T>
Range<T> Range<T>::operator/(const Range<T> &rhs) const{
    Range<T> x(*this);
    if(rhs.l_range == 0 || rhs.h_range == 0){
        std::string s = "[" + std::to_string(rhs.l_range) + ", " + std::to_string(rhs.h_range) + "]\n";
        throw std::runtime_error(s);
    }
    else{
        x.l_range = l_range / rhs.l_range;
        if(x.l_range > l_range / rhs.h_range){
            x.l_range = l_range / rhs.h_range;
        }
        x.h_range = h_range / rhs.h_range;
        if(x.h_range < h_range / rhs.l_range){
            x.h_range = h_range / rhs.l_range;
        }
        return x;
    }
}

template <typename T>
bool Range<T>::operator==(const Range<T> &rhs){
    if(l_range == rhs.l_range && h_range == rhs.h_range){
        return true;
    }
    else{
        return false; 
    }
}
template <typename T>
bool Range<T>::operator!=(const Range<T> &rhs){
    if(l_range == rhs.l_range && h_range == rhs.h_range){
        return false; 
    }
    else{
        return true;
    }
}

template <typename T>
std::ostream & operator<<(std::ostream &os, const Range<T> &rhs){
    os << "[" << rhs.min() << ", " << rhs.max() << "]";
    return os;
}


#endif /*RANGE_H_INCLUDED*/