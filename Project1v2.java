import java.util.Scanner; 
public class Project1v2 
{

	public static void main(String[] args) 
	{
		//Create your scanner object
		Scanner scan = new Scanner(System.in);
		
		/*
		 Create your card variable and the array 
		 variable that will be used to call your function
		 */
		long card;
		long array[] = new long[16];
		
		//Create the variables that will hold your added values
		long firstAdd;
		long secondAdd;
		long sum;
		
		//Prompt the user to enter the card they would like
		System.out.println("Please enter the card you would like to verify: ");
		
		// Use the scanner to get the value of card
		card = scan.nextLong();
		
		System.out.println("Validating your card");
		System.out.println("Please wait...");
		
		//Now create the array of card that will be held, call it with the long card you made
		array = cardArray(card);
				
		//Call the two add methods with the array you made
		//Set the methods equal to a first add method and then a second add
		firstAdd = addEveryTwo(array);
		secondAdd = addEveryFirst(array);
		
		//Add the two numbers you now have
		sum = firstAdd + secondAdd;
		
		//Call your verify method to check if the card is divisable by 10
		verify(sum);
		
		//Close the scanner to prevent memory leak
		scan.close();
	}
	
	public static long[] cardArray(long card)
	{
		//Create a new array object that can be a size of 16
		long cArray[] = new long[16];
		
		/*
		 * I used the size 16 because even if the variable is less than 16
		 * then the rest of values would just be 0 and that will add no affect
		 * to the sum in the end since adding 0 does not add any other value
		 */
		
		//Use a for loop to set all the values in the array, it will be backwards and easier
		//to use since you can just go forwards in the array
		for(int i = 0; i < 16; i++)
		{
			//Use the mod method (%) to get the value of the next value
			cArray[i] = card % 10;
			
			//Divide by 10 to then make the number one digit shorter
			//e.g. 1234 = 123 after the division
			card = card / 10;
		}
		
		//Return the array
		return cArray;
	}
	
	public static long addEveryTwo(long cArray[])
	{
		//Create two variable, one for a placeHolder of the value you want to use
		//Make your added variable to 0 to invoke the variable
		long added = 0;
		long placeHolder;
		
		//Use a for loop to now go through your created array
		//Make sure to make i go by twos (i+=2)
		//Start i at 1 to skip the first value
		for(int i = 1; i < 16; i+=2)
		{
			//Set your placeholder to the value you can now access
			placeHolder = cArray[i];
			
			//Double your placeHolder
			placeHolder  *= 2;
			
			//Check to see if the value doubled is greater or equal to 10
			if(placeHolder >= 10)
			{
				//Since we have a base 10 digit system you can just subtract the number by 9
				//e.g. 10 - 9 = 1
				//In which 1 + 0 = 1
				placeHolder -= 9;
			}
			
			/*Each time you pass through make sure you add the new placeHolder value
			 * to your sum variable to keep a running total
			 */
			added += placeHolder;
		}
		
		//Return your sum variable
		return added;
	}
	public static long addEveryFirst(long cArray[])
	{
		//Create a placeHolder and a sum variable
		long added = 0;
		long placeHolder;
		
		//Use a for loop to go through the array and get the values you need
		//Make sure to go by 2s (i+=2)
		//Start at 0 this time
		for(int i = 0; i < 16; i+=2)
		{
			//Set you placeHolder to the array value that you can access
			placeHolder = cArray[i];
			
			//Add together the sum variable and the placeHolder 
			//To keep a running total
			added += placeHolder;
		}
		
		//Return your sum value
		return added;
	}
	
	public static void verify(long num)
	{
		//Use an if statement with the mod function to check if the two values are divisable by 10
		if((num % 10) == 0)
		{
			System.out.println("The card is valid");
		}
		else
		{
			System.out.println("The card is invalid");
		}
		
		//No return statement
	}
}

