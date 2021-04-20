/**
 * @file recursiveStairs.cc
 * @brief Recursive Function to count the number of ways to walk up N stairs
 *        if you can take steps of 1,2,3,4 at a time
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

int countSteps(int n, int w)
{
    int count = 0;

    if (1 >= n)
    {
        return n;
    }

    for (int i = 1; i <= n && i <= w; i++)
    {
        // only count n-i up to the number of steps that can be taken at once
        count += countSteps(n-i, w);
    }

    return count;
}
