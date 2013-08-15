#ifndef	ROCOBJECT_
#define RCOBJECT_

class RCObject
{
  public:
    void addRef() { ++refCount; }
    void removeRef()
      { if (--refCount <= 0) delete this; }

  protected:
    RCObject() : refCount(0) {}
    virtual ~RCObject() {}
  private:
    int refCount;
};

#endif

