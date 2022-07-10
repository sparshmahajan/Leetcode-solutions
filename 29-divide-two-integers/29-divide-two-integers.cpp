class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
            long long int quotient = (long int) dividend / divisor;
            if (quotient > INT_MAX)
            {
                return INT_MAX;
            }
            if (quotient < INT_MIN)
            {
                return INT_MIN;
            }
            return quotient;
        }
};