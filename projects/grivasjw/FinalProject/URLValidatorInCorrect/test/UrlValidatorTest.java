

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
//Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	  //You can use this function to implement your manual testing
	  UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      
	  assertTrue(urlValidator.isValid("http://www.google.com"));
      assertFalse(urlValidator.isValid("ftp://www.google.com"));
	  assertFalse(urlValidator.isValid("38pt://google.com")); //38pt not valid
	  assertTrue(urlValidator.isValid("https://www.google.com"));
	  assertTrue(urlValidator.isValid("http://www.go.au"));
      assertTrue(urlValidator.isValid("ftp://ftp.myexample.com"));
      assertTrue(urlValidator.isValid("http://www.oracle.org/"));
      assertFalse(urlValidator.isValid("1.1.1.1"));
	  assertFalse(urlValidator.isValid("http://1.2.3.400/")); //greater than 255 not valid
	  assertTrue(urlValidator.isValid("http://www.amazon.com/"));
      assertFalse(urlValidator.isValid("www.amazon.com/x/y/z"));
      assertTrue(urlValidator.isValid("http://www.amazon.com:80/abcde"));
      assertTrue(urlValidator.isValid("http://www.amazon.com/abcde?x=y&y=z"));
      assertTrue(urlValidator.isValid("http://www.amazon.com/abcde?x=!"));
      
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
