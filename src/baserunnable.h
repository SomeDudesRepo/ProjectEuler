#ifndef BASERUNNABLE_H
#define BASERUNNABLE_H

#include <cstdint>

class BaseRunnable
{
public:
    BaseRunnable(const uint64_t& result)
        :   mResult(result) {}
    virtual ~BaseRunnable() {}
    uint64_t GetResult() const { return mResult; }

protected:
    uint64_t mResult;
};

#endif // BASERUNNABLE_H
