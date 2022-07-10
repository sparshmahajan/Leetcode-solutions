class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
           	//divide zero over anything->0
            if (dividend == 0)
            {
                return 0;
            }

           	//divide the most minimum number over -1 ->return maximum number, else return the min one
            if (dividend == INT_MIN && divisor == 1)
            {
                return INT_MIN;
            }
            if (dividend == INT_MIN && divisor == -1)
            {
                return INT_MAX;
            }

           	//initialize new variables of the absolute values of the current ones
            unsigned long int abs_dividend = abs(dividend);
            unsigned long int abs_divisor = abs(divisor);
           	//initialize a sum variable with initial value of the divisor value
            unsigned long int sum = abs_divisor;
            unsigned long int counter = 0;

           	//repeat the same steps until the summition value is smaller than or equal to the dividend
            while (sum <= abs_dividend)
            {
               	//add a step to the counter &add the value of the sum by the divisor
                counter++;
                sum += abs_divisor;
            }
           	//after that, if one of them has a negative sign-> multiply the counter by negative
            if (divisor < 0 && dividend > 0)
            {
                counter *= -1;
            }
            if (dividend < 0 && divisor > 0)
            {
                counter *= -1;
            }
            return counter;
        }
};