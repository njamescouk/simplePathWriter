// SimpleLength.h
#ifndef have_SimpleLength
#define have_SimpleLength

class SimpleLength
{
    long m_length;

public:
    SimpleLength();
    SimpleLength(long l) : m_length(l){};
    virtual ~SimpleLength();

    long getLength()
    {
        return m_length;
    }
};



#endif // have_SimpleLength

