namespace samples
{
    // 클래스의 템플릿화하는 방법
    template <typename T>
    class MyArray{
    public:
        MyArray();

        // T가 개체일 수 있어서 const T&를 사용  
        bool Add(const T& data);
        size_t GetSize() const;

    private:
        enum { MAX = 3 };

        size_t mSize;
        T mArray[MAX];
    };

    template <typename T>
    MyArray<T>::MyArray()
    : mSize(0){
    }

    template <typename T>
    size_t MyArray<T>::GetSize() const{
        return mSize;
    }

    template <typename T>
    bool MyArray<T>::Add(const &T data){
        if (mSize >= MAX)
        {
            return false;
        } 

        mArray[mSize++] = data;

        return true;
        
    }

} // namespace samples
