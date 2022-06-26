#ifndef __CACHEMANAGER_HPP__
#define __CACHEMANAGET_HPP__

#include "LRUCache.hpp"
#include "Timerfd.hpp"
#include "TimerThread.hpp"

#include <vector>

using std::vector;

class LRUCache;

class CacheManager
{
public:
    friend class KeyRecommander;
    CacheManager();
    void init();
    LRUCache &getCache(int idx);
    void updateCache();

    void showCache(int idx);

private:
    TimerThread _timer;
    vector<LRUCache> _caches;
};

#endif