#ifndef HSET_ITER_H_INCLUDED
#define HSET_ITER_H_INCLUDED

#include <list>
#include <vector>
#include <iterator>	// for advance()

// Each hset_iter contains a reference to its associated hash,
// and an int indicating progress within the hash.

template <typename T>
class hset_iter {
  private:
    using table_t = typename std::vector<std::list<T>>;
    const table_t &parent;  // reference to the hash table we’re iterating over
    int vector_index; 
    int list_index; 

  public:
    hset_iter(table_t &table, int v, int l) : parent(table), vector_index(v), list_index(l) { }

    bool operator==(const hset_iter &rhs) const {
    if(vector_index == rhs.list_index && list_index == rhs.list_index){
        return true; 
    }
    else{
        return false;
    }
    }

    bool operator!=(const hset_iter &rhs) const {
	return !(*this == rhs);
    }

    // Return a pointer to the num'th element,
    // where num==0 is the first element.

    T operator*() const {
        unsigned int vi; 
        unsigned int remaining; 
        for(vi = vector_index; vi < parent.size(); vi++){
            if(parent[vi].size() == 0)
                remaining = vi;
        }
        auto it = parent[remaining].begin();
        advance(it, list_index);
        return *it;
    }

    // Pre-increment
    void operator++() {
        list_index += 1;
        if(list_index >= (int) parent[vector_index].size()){
            vector_index += 1; 
            list_index = 0;
        }

        if(parent[vector_index].size() == 0){
            if(parent[vector_index++].size() != 0){
                vector_index += 1;
                list_index =0;
            }
            else{
                vector_index = 0;
                list_index = 0;
            }
        }
    }
};

#endif /* HSET_ITER_H_INCLUDED */
