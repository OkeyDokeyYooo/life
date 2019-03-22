#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void life( uint8_t array[],
	     unsigned int cols,
	     unsigned int rows )
{
	for(int j = 0; j < rows; j++)
  {
		for(int i = 0; i < cols; i++)
    {
      if (array[i+j*cols] > 2)
      {

        int count_live = 0;
				int top = j - 1, bottom = j + 1, left = i - 1, right = i + 1;
				if(top == -1)
				{
					top = rows - 1;
				}
				if(bottom == rows)
				{
					bottom = 0;
				}
				if(left == -1)
				{
					left = cols - 1;
				}
				if(right == cols)
				{
					right = 0;
				}
        if(((left) >= 0) && ((top) >= 0))
        {
          if(array[(left)+(top)*cols] > 2) count_live++;
        }
        if((top) >= 0)
        {
          if(array[i+(top)*cols] > 2) count_live++;
        }
        if(((right) < cols)&&((top) >= 0))
        {
          if(array[(right)+(top)*cols] > 2) count_live++;
        }
        if((left) >= 0)
        {
          if(array[(left)+j*cols] > 2) count_live++;
        }
        if ((right) < cols)
        {
          if(array[(right)+j*cols] > 2) count_live++;
        }
        if(((left) >= 0) && ((bottom) < rows))
        {
          if(array[(left)+(bottom)*cols] > 2) count_live++;
        }
        if((bottom) < rows)
        {
          if(array[i+(bottom)*cols] > 2) count_live++;
        }
        if(((right) < cols)&&((bottom) < rows))
        {
          if(array[(right)+(bottom)*cols] > 2) count_live++;
        }

        if ((count_live < 2) || (count_live > 3))
        {
          array[i+j*cols] = 3;
        }
      }

			else if (array[i+j*cols] == 0)
			{
			  int count_died = 0;
				int top = j - 1, bottom = j + 1, left = i - 1, right = i + 1;
				if(top == -1)
				{
					top = rows - 1;
				}
				if(bottom == rows)
				{
					bottom = 0;
				}
				if(left == -1)
				{
					left = cols - 1;
				}
				if(right == cols)
				{
					right = 0;
				}
			  if(((left) >= 0) && ((top) >= 0))
			  {
			    if(array[(left)+(top)*cols] > 2) count_died++;
			  }
			  if((top) >= 0)
			  {
			    if(array[i+(top)*cols] > 2) count_died++;
			  }
			  if(((right) < cols)&&((top) >= 0))
			  {
			    if(array[(right)+(top)*cols] > 2) count_died++;
			  }
			  if((left) >= 0)
			  {
			    if(array[(left)+j*cols] > 2) count_died++;
			  }
			  if ((right) < cols)
			  {
			    if(array[(right)+j*cols] > 2) count_died++;
			  }
			  if(((left) >= 0) && ((bottom) < rows))
			  {
			    if(array[(left)+(bottom)*cols] > 2) count_died++;
			  }
			  if((bottom) < rows)
			  {
			    if(array[i+(bottom)*cols] > 2) count_died++;
			  }
			  if(((right) < cols)&&((bottom) < rows))
			  {
			    if(array[(right)+(bottom)*cols] > 2) count_died++;
			  }
				if(count_died == 3)
				{
					array[i + j*cols] = 1;
				}
    	}
  	}
	}
	for (int i = 0; i < cols*rows; i++)
	{
		if(array[i] == 1)
		{
			array[i] = 255;
		}
		if(array[i] == 3)
		{
			array[i] = 0;
		}
	}
}
