int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int max = 0,count = 0;
    for (int i = 0;i < numsSize;i++)
    {
        if (nums[i] & 1)
        {
            count++;
            max = count > max ? count : max;
        }
        else
            count = 0;
    }
    return max;
}
