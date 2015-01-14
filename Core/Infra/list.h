#ifndef LIST_H
#define LIST_H

#include "preinfra.h"

template<class T>
class List
{
public:
    class Iterator
    {
    public:
        Iterator()
        {
            ;
        }

        Iterator(const typename std::list<T>::iterator itr)
        {
            mIterator = itr;
        }

        bool operator==(const Iterator &itr)
        {
            return itr.mIterator == mIterator;
        }

        bool operator!=(const Iterator &itr)
        {
            return !(*this == itr);
        }

        Iterator operator++()
        {
            Iterator itr = *this;
            ++mIterator;
            return itr;
        }

        Iterator &operator++(int)
        {
            ++mIterator;
            return *this;
        }

        T &operator*()
        {
            return *mIterator;
        }

    private:
        typename std::list<T>::iterator mIterator;
    };

public:
    List()
    {
        ;
    }

    ~List()
    {
        ;
    }

    Iterator begin(void)
    {
        return mList.begin();
    }

    Iterator end(void)
    {
        return mList.end();
    }

    void push_back(const T& data)
    {
        std::lock_guard<std::mutex> lock(mListOperation);
        mList.push_back(data);
    }

    void remove(const T& data)
    {
        std::lock_guard<std::mutex> lock(mListOperation);
        if (mList.end() != std::find(mList.begin(), mList.end(), data))
        {
            mList.remove(data);
        }
    }

    T back(void)
    {
        std::lock_guard<std::mutex> lock(mListOperation);
        return mList.back();
    }

    // remove element from list and return this element.
    T give_back(bool &exist)
    {
        std::lock_guard<std::mutex> lock(mListOperation);

        exist = false;

        T ret;
        if (0 != mList.size())
        {
            exist = true;
            ret = mList.back();
            mList.remove(ret);
        }
        return ret;
    }

    unsigned int size(void)
    {
        std::lock_guard<std::mutex> lock(mListOperation);
        return mList.size();
    }

    bool exist(const T &data)
    {
        std::lock_guard<std::mutex> lock(mListOperation);
        return (mList.end() != std::find(mList.begin(), mList.end(), data));
    }

    void lock(void)
    {
        mListOperation.lock();
    }

    void unlock(void)
    {
        mListOperation.unlock();
    }

private:
    std::list<T> mList;
    std::mutex mListOperation;
};

#endif // LIST_H
