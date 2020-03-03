class buf
{
    public:
    int **commandbuf;
    buf(unsigned int,unsigned int);//初始化构造函数
};
buf::buf(unsigned int num,unsigned int size)
{
    commandbuf = new int *[num];
    for( int i=0; i<num; i++ )
    {
        commandbuf[i]=new int [size];
    }

};