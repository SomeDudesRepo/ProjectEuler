#ifndef BASERUNNABLE_H
#define BASERUNNABLE_H

#include <cstdint>

#include "log.h"

class BaseRunnable
{
public:
    BaseRunnable(const uint64_t& result)
        :   mResult(result)
    {
        Log("Problem start");
    }
    virtual ~BaseRunnable() { Log("Problem end"); }
    uint64_t GetResult() const { return mResult; }

protected:
    uint64_t mResult;
};

#endif // BASERUNNABLE_H
