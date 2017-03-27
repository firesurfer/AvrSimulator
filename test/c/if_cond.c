int main(void)
{
    volatile int i = 0;
    i = i + 10;
    volatile int k = 0;
    if(i > 10)
    {
        k++;
    }
    if(i < 10)
    {
        k++;
    }
    if(i == 0)
    {
        k++;
    }
    return 0;
}
