int main(void)
{
    volatile int i = 0;
    i = i + 10;
    if(i > 10)
    {
        return 1;
    }
    if(i < 10)
    {
        return 2;
    }
    if(i == 0)
    {
        return 3;
    }
    return 0;
}
