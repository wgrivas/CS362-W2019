

import junit.framework.TestCase;

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.Serializable;
//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {

	public static final String URL_REGEX =
            "^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\\?([^#]*))?(#(.*))?";
    //        12            3  4          5       6   7        8 9
   	public static final Pattern URL_PATTERN = Pattern.compile(URL_REGEX);

   	    
   	public static final int PARSE_URL_SCHEME = 2;
    
    public static final int PARSE_URL_AUTHORITY = 4;

    public static final int PARSE_URL_PATH = 5;

    public static final int PARSE_URL_QUERY = 7;


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public static void testManualTest()
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
   
   public static void testIsValid()
   {
	   //You can use this function for programming based testing
   		
	   //Test parameters used for the unit tests
  		String[] unittestparam = {
  	   			null,
  	   			"htyy",
  	   			"https://1.2.3.4.5",
  	   			"file://0.0.0.0/to/file",
  	   			"http://www.google.com/..",
  	   			"http://www.google.com/test1/sie09~~osnfi?????????##$$&&",
  	   			"http://www.bing.com/news"


  	   		};
  		
  		//Create a new URL object to call the isValid() function
   		UrlValidator url = new UrlValidator();
   		
		//Check 1: Tests the null functionality of the isValid() function
   		//Input: null URL
   		//Expected output: indication of a false URL
		if(unittestparam[0] == null){
			if(url.isValid(unittestparam[0]) == false)
				System.out.println("NULL TEST CASE PASSED!");
			else
				System.out.println("NULL TEST CASE FAILED!");
		}

		//Check 2: Tests isValidScheme functionality of isValid() function
   		//Input: Invalid Scheme URL
   		//Expected output: indication of a false URL
		Matcher urlMatcherScheme = URL_PATTERN.matcher(unittestparam[1]);
		urlMatcherScheme.matches();
		String scheme = urlMatcherScheme.group(PARSE_URL_SCHEME);
		if(url.isValidScheme(scheme) == url.isValid(unittestparam[1])){
			System.out.println("VALID SCHEME CASE PASSED!");
		}
		else
			System.out.println("VALID SCHEME CASE FAILED!");

		//Check 3: Tests isValidAuthority functionality of isValid() function
   		//Input: Invalid Authority URL
   		//Expected output: indication of a false URL
		Matcher urlMatcherAuthority = URL_PATTERN.matcher(unittestparam[2]);
		urlMatcherAuthority.matches();
		String authority = urlMatcherAuthority.group(PARSE_URL_SCHEME);
		if(url.isValidAuthority(authority) == url.isValid(unittestparam[2])){
			System.out.println("VALID AUTHORITY CASE PASSED!");

		}
		else
			System.out.println("VALID AUTHORITY CASE FAILED!");

		//Check 4: Tests isValidAuthrity functionality for a file URL of isValid() function
   		//Input: Valid Authority File URL
   		//Expected output: indication of a True URL
		Matcher urlMatcherAuthorityFile = URL_PATTERN.matcher(unittestparam[3]);
		urlMatcherAuthorityFile.matches();
		String authorityFile = urlMatcherAuthorityFile.group(PARSE_URL_SCHEME);
		if(url.isValidAuthority(authorityFile) == url.isValid(unittestparam[3])){
			System.out.println("VALID FILE AUTHORITY CASE PASSED!");
		}
		else
			System.out.println("VALID FILE AUTHORITY CASE FAILED!");

		//Check 5: Tests isValidPath functionality of isValid() function
   		//Input: Invalid Path URL
   		//Expected output: indication of a false URL
		Matcher urlMatcherPath = URL_PATTERN.matcher(unittestparam[4]);
		urlMatcherPath.matches();
		String path = urlMatcherPath.group(PARSE_URL_PATH);
		if(url.isValidPath(path) == url.isValid(unittestparam[4])){
			System.out.println("VALID PATH CASE PASSED!");
		}
		else
			System.out.println("VALID PATH CASE FAILED!");

		//Check 6: Tests isValidQuery functionality of isValid() function
   		//Input: Invalid Query URL
   		//Expected output: indication of a false URL
		Matcher urlMatcherQuery = URL_PATTERN.matcher(unittestparam[5]);
		urlMatcherQuery.matches();
		String query = urlMatcherQuery.group(PARSE_URL_QUERY);
		if(url.isValidPath(query) == url.isValid(unittestparam[5])){
			System.out.println("VALID QUERY CASE PASSED!");
		}
		else
			System.out.println("VALID QUERY CASE FAILED!");

		//Check 7: Tests all functionality of isValid() function
   		//Input: Valid URL
   		//Expected output: indication of a true URL
		Matcher urlMatcherAll = URL_PATTERN.matcher(unittestparam[6]);
		urlMatcherAll.matches();
		String queryAll = urlMatcherAll.group(PARSE_URL_QUERY);
		String pathAll = urlMatcherAll.group(PARSE_URL_PATH);
		String authorityAll = urlMatcherAll.group(PARSE_URL_AUTHORITY);
		String schemeAll = urlMatcherAll.group(PARSE_URL_SCHEME);
		if(url.isValidScheme(schemeAll)){
			System.out.println("Scheme for " +unittestparam[6]+ " GOOD!");
			if(url.isValidAuthority(authorityAll)){
				System.out.println("authority for " +unittestparam[6]+ " GOOD!");
				if(url.isValidPath(pathAll)){
					System.out.println("path for "+unittestparam[6]+ " GOOD!");
					if(url.isValidQuery(queryAll)){
						System.out.println("query for " +unittestparam[6]+ " GOOD!");
						if(url.isValid(unittestparam[6])){
							System.out.println("URL VALID! TEST PASSED!");
						}
						else{
							System.out.println("URL INVALID!");
						}
					}
					else{
						System.out.println("QUERY INVALID!");
					}
				}
				else{
					System.out.println("PATH INVALID!");
				}
			}
			else{
				System.out.println("AUTHORITY INVALID!");
			}
		}
		else{
			System.out.println("SCHEME INVALID!");
		}



   }
   
   public static void main(String[] args){

		testManualTest();
		testIsValid();



	}
   


}