#ifndef __NOCOPY_HH__
#define __NOCOPY_HH__

class NoCopy {
  protected:
    NoCopy() {}
    ~NoCopy() {}
    NoCopy(const NoCopy &rhs) = delete;
    NoCopy &operator=(const NoCopy &rhs) = delete;
};
#endif
