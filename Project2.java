public class Project2
{
    public static void main(String [] args)
    {
    	//Create two arrays
    	
    	//One for your totals and the employee number
        int totalArray[][] = new int[8][2];
        
        //One array for the values of the array
        int employees[][] = new int[][]{
                {4,2,5,3,4,5,8},
                {1,7,8,4,3,3,4},
                {2,3,3,4,3,3,2},
                {3,3,3,7,3,4,1},
                {1,3,2,4,3,6,3},
                {5,3,4,4,6,3,4},
                {8,3,7,4,8,3,8},
                {2,6,3,5,9,2,7}};
                
                //Call your function to print off the schedule
                schedule(employees);
                
                //Do one system println just to make a free space
                System.out.println();

        //Do a for loop that will call the getTotalHours
        for(int i = 0; i < 8; i++)
        {
        	//Use i to also tell which employee is being used
            totalArray[i][1] = getTotalHours(employees, i);
        }
        for(int i = 0; i < 8; i++)
        {
        	//Set the first column of the totalArray to the i value
        	//This will allocate the numbers for each employee
        	totalArray[i][0] = i;
        }
        
        //Now sort the array
        sortArray(totalArray);
        
        for(int i = 0; i < totalArray.length; i++)
        {
        	//After sorting the array print off the new employee number in column one and the total hours they have
        	System.out.println("Employee_" + totalArray[i][0]	+ " total hours were: " + totalArray[i][1]);
        }



    }
    
    public static void schedule(int [][] array1)
    {
    	System.out.println("\t   S M T W T F S");
    	
    	//Use the for loops to print off the normal schedule before sorting
    	for(int i = 0; i < 8; i ++)
    	{
    		for(int j = 0; j < 7; j++)
    		{
    			if(j == 0)
    			{
    				//i can just be the normal employee numbers
    				System.out.print("Employee_" + i + " ");
    			}
    			System.out.print(array1[i][j] + " ");
    			if(j == 6)
    			{
    				//if the row == 6 then enter down
    				System.out.println();
    			}
    		}
    	}
    }

    public static int getTotalHours(int[][] array1, int t)
    {
        int totalHours = 0;
        for(int i = 0; i < 7; i++)
        {
        	//The total is called each time a new row is put through
        	//use t as the new column call
            totalHours += array1[t][i];
        }
        return totalHours;
    }
    public static int[][] sortArray(int[][] array1)
    {
    	//Create a tempArray with 8 rows and 2 columns
    	int tempArray[][] = new int[8][2];
    	
    	//Create a boolean to false
    	boolean swap = false;
    	
    	//Use a while loop that will go until swap == true
    	while(swap == false)
    	{
    		//Set swap to true before the for statement
    		swap = true;
    		for(int i = 0; i < 7; i++)
    		{
    			//Use a nested if statement to test the variables in the second column
    			//These are the totals for each employee
    			if(array1[i][1] < array1[i+1][1])
    			{
    				//Now set swap to false if the condition of the if statement is true
    				swap = false;
    				
    				//Go through and set the tempArray of the total hours
    				//Also set the employee number into the tempArray
    				tempArray[i][0] = array1[i+1][1];
    				tempArray[i][1] = array1[i+1][0];
    				
    				
    				//Now set the value of the next element into the first element that is lower value
    				//Do this for both values (totalHours and employeeNumber)
    				array1[i+1][1] = array1[i][1];
    				array1[i+1][0] = array1[i][0];
    				
    				//Set the value of the last element that you took the value of
    				//Use the tempArray to set it back into the spot
    				array1[i][1] = tempArray[i][0];
    				array1[i][0] = tempArray[i][1];
    			}
    		}
    	}
    	
    	//Now return this newly sorted array
        return array1;
    }
}
