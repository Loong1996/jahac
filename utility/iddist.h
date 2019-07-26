#ifndef JAHAC_UTILITY_IDDIST_H
#define JAHAC_UTILITY_IDDIST_H


#include <algorithm>
#include <limits>

namespace jahac {
namespace iddist {

// id range: [1,T::max]
// Malloc error return 0
// support only integer
template<typename T>
class CIdDist
{
    CIdDist(const CIdDist&) = delete;
    CIdDist& operator=(CIdDist&) = delete;
    CIdDist(const CIdDist&&) = delete;
    CIdDist& operator=(CIdDist&&) = delete;
public:
    CIdDist() : id_(0) {}
    ~CIdDist() {}

    void RegisterId(const T id) { id > id_ ? id_ = id : 0; }
    T    MallocId()             { return id_ == std::numeric_limits<T>::max()? 0 : ++id_; }
    void ResetId(const T id)    { id_ = id; }
    T    GetCurId()             { return id_; }

private:
    T id_;

};


}}

#endif // JAHAC_UTILITY_IDDIST_H
