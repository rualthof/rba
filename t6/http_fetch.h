#ifndef __HTTP_FETCH_H__
#define __HTTP_FETCH_H__
#include <string>
class HttpFetch {
public:
    virtual ~HttpFetch() {}
    virtual std::string GetUriAsString(const std::string & uri) const 
    {
        // TODO(cboumenot): implement
        return std::string();
    }
};
#endif // __HTTP_FETCH_H__
